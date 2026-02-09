`timescale 1ns/1ps

module JTAG_Simple_tb;

    // Clocks
    logic i_clock;
    logic TCK;

    // JTAG signals
    logic i_reset;
    logic TDI;
    logic TMS;
    wire  TDO;

    // Instantiate DUT
    JTAG_Simple #(
        .IDCODE_VERSION(1),
        .IDCODE_PART(16'hBABE),
        .IDCODE_MANUFACTURER(11'h001)
    ) dut (
        .i_reset(i_reset),
        .i_clock(i_clock),
		.i_usercode(32'hcafe_babe),
        .TDI(TDI),
        .TDO(TDO),
        .TCK(TCK),
        .TMS(TMS)
    );

    // -------------------------
    // Clock generation
    // -------------------------

    // System clock (not always needed by TAP, but provided)
    always #5 i_clock = ~i_clock; // 100 MHz

    // JTAG clock
    always #20 TCK = ~TCK; // 25 MHz

    // -------------------------
    // JTAG helper tasks
    // -------------------------

    task jtag_tick(input logic tms, input logic tdi);
        begin
            @(negedge TCK);
            TMS <= tms;
            TDI <= tdi;
            @(posedge TCK);
        end
    endtask

    task jtag_reset;
        begin
            // Hold TMS high for 5 TCKs to force Test-Logic-Reset
            repeat (5) jtag_tick(1'b1, 1'b0);
        end
    endtask

    task goto_run_test_idle;
        begin
            jtag_tick(1'b0, 1'b0); // Test-Logic-Reset -> Run-Test/Idle
        end
    endtask

    task goto_shift_ir;
        begin
            jtag_tick(1,0); // Select-DR-Scan
            jtag_tick(1,0); // Select-IR-Scan
            jtag_tick(0,0); // Capture-IR
            jtag_tick(0,0); // Shift-IR
        end
    endtask

    task goto_shift_dr;
        begin
            jtag_tick(1,0); // Select-DR-Scan
            jtag_tick(0,0); // Capture-DR
            jtag_tick(0,0); // Shift-DR
        end
    endtask

    task exit_shift;
        begin
            jtag_tick(1,0); // Exit1
            jtag_tick(1,0); // Update
            jtag_tick(0,0); // Run-Test/Idle
        end
    endtask

    // -------------------------
    // Test sequence
    // -------------------------

	bit [31:0] tmp;

    initial begin
        $dumpfile("build/test/JTAG_Simple_tb.vcd");
        $dumpvars(0, JTAG_Simple_tb);

        // Init signals
        i_clock = 0;
        TCK     = 0;
        TMS     = 1;
        TDI     = 0;
        i_reset = 1;

        // Global reset
        #50;
        i_reset = 0;

        // JTAG reset
        jtag_reset();
        goto_run_test_idle();

        // -------------------------
        // Shift DR test, should read IDCODE after reset.
        // -------------------------
        $display("Entering Shift-DR");
        goto_shift_dr();

        // Shift 32 bits (e.g. IDCODE)
        for (int i = 0; i < 32; i++) begin
            jtag_tick(0, 1'b0);
			tmp[i] = TDO;
        end
		$display("IDCODE = %x", tmp);

        exit_shift();

        // -------------------------
        // Shift IR test
        // -------------------------
        $display("Entering Shift-IR");
        goto_shift_ir();

        // Shift 4 bits into IR.
		tmp = 32'h0000_000c;
		for (int i = 0; i < 4; i++) begin			
            jtag_tick(0, tmp[i]);
        end

        exit_shift();

        // -------------------------
        // Shift DR test
        // -------------------------
        $display("Entering Shift-DR");
        goto_shift_dr();

        // Shift 32 bits (e.g. IDCODE)
        for (int i = 0; i < 32; i++) begin
            jtag_tick(0, 1'b0);
			tmp[i] = TDO;
        end
		$display("USERDATA = %x", tmp);

        exit_shift();

        // Done
        #200;
        $display("JTAG FSM test complete");
        $finish;
    end

endmodule
