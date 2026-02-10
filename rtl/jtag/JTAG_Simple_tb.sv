`timescale 1ns/1ps

module JTAG_Simple_tb;

	bit [7:0] debug = 0;

    // ---------------------------------
    // Parameters
    // ---------------------------------
    localparam int IR_WIDTH = 4;
    localparam int DR_WIDTH = 32;

    // Match DUT parameters
    localparam int IDCODE_VERSION      = 1;
    localparam int IDCODE_PART          = 16'hBABE;
    localparam int IDCODE_MANUFACTURER  = 11'h001;

    // ---------------------------------
    // Signals
    // ---------------------------------
    logic i_clock = 1'b0;
    logic i_reset = 1'b1;
	logic [3:0] dut_state;
    logic TCK;
    logic TDI;
    logic TMS;
    wire  TDO;

    // ---------------------------------
    // DUT
    // ---------------------------------
    JTAG_Simple #(
        // .IDCODE_VERSION(IDCODE_VERSION),
        // .IDCODE_PART(IDCODE_PART),
        // .IDCODE_MANUFACTURER(IDCODE_MANUFACTURER)
    ) dut (
        .i_reset(i_reset),
        .i_clock(i_clock),
		.i_usercode(32'hb00b_babe),
		.o_state(dut_state),
        .TDI(TDI),
        .TDO(TDO),
        .TCK(TCK),
        .TMS(TMS)
    );

    // ---------------------------------
    // Clocks
    // ---------------------------------
    always #5  i_clock = ~i_clock; // 100 MHz system clock
    //always #20 TCK     = ~TCK;     // 25 MHz JTAG clock

	initial begin
		TCK = 0;
		#4;
		forever TCK = #17 ~TCK;
	end

    // ---------------------------------
    // Scoreboard storage
    // ---------------------------------
    logic [IR_WIDTH-1:0] ir_shifted_in;
    logic [IR_WIDTH-1:0] ir_shifted_out;

    logic [DR_WIDTH-1:0] dr_shifted_in;
    logic [DR_WIDTH-1:0] dr_shifted_out;

    logic [31:0] expected_idcode;

    // ---------------------------------
    // JTAG helper tasks
    // ---------------------------------

    task jtag_tick(
        input  logic tms,
        input  logic tdi,
        output logic tdo_sample
    );
        begin
            @(negedge TCK);
            tdo_sample = TDO;
            TMS = tms;
            TDI = tdi;
            @(posedge TCK);     // TDO valid here
        end
    endtask

    task jtag_tick_no_tdo(
        input  logic tms,
        input  logic tdi
    );
        begin
            @(negedge TCK);
            TMS = tms;
            TDI = tdi;
            @(posedge TCK);     // TDO valid here
        end
    endtask

    task jtag_reset;
        begin
            repeat (5)
                jtag_tick_no_tdo(1'b1, 1'b0);
        end
    endtask

    task goto_run_test_idle;
        begin
            jtag_tick_no_tdo(1'b0, 1'b0);
        end
    endtask

    task goto_shift_ir;
        begin
            jtag_tick_no_tdo(1,0); // Select-DR
            jtag_tick_no_tdo(1,0); // Select-IR
            jtag_tick_no_tdo(0,0); // Capture-IR
            jtag_tick_no_tdo(0,0); // Shift-IR
        end
    endtask

    task goto_shift_dr;
        begin
            jtag_tick_no_tdo(1,0); // Select-DR
            jtag_tick_no_tdo(0,0); // Capture-DR
            jtag_tick_no_tdo(0,0); // Shift-DR
        end
    endtask

    task exit_shift;
        begin
debug = 1;
            jtag_tick_no_tdo(1,0); // Exit1
debug = 2;
            jtag_tick_no_tdo(1,0); // Update
debug = 3;
            jtag_tick_no_tdo(0,0); // Run-Test/Idle
debug = 0;
        end
    endtask

    // ---------------------------------
    // Scoreboard-aware shift tasks
    // ---------------------------------

    task shift_ir(input logic [IR_WIDTH-1:0] value);
        logic tdo_bit;
        int i;

        begin
            ir_shifted_in  = '0;
            ir_shifted_out = '0;

            goto_shift_ir();

            for (i = 0; i < IR_WIDTH; i++) begin
                jtag_tick(
                    1'b0, //(i == IR_WIDTH-1), // exit on last bit
                    value[i],
                    tdo_bit
                );

                ir_shifted_in[i]  = value[i];
                ir_shifted_out[i] = tdo_bit;
            end

            exit_shift();

            $display("[IR ] Shifted in : %b", ir_shifted_in);
            $display("[IR ] Shifted out: %b", ir_shifted_out);
        end
    endtask

    task shift_dr(input logic [DR_WIDTH-1:0] value);
        logic tdo_bit;
        int i;

        begin
            dr_shifted_in  = '0;
            dr_shifted_out = '0;

            goto_shift_dr();

            for (i = 0; i < DR_WIDTH; i++) begin
                jtag_tick(
                    1'b0, //(i == DR_WIDTH-1), // exit on last bit
                    value[i],
                    tdo_bit
                );

                dr_shifted_in[i]  = value[i];
                dr_shifted_out[i] = tdo_bit;
            end

            exit_shift();

            $display("[DR ] Shifted in : %h", dr_shifted_in);
            $display("[DR ] Shifted out: %h", dr_shifted_out);
        end
    endtask

    // ---------------------------------
    // Test sequence
    // ---------------------------------

    initial begin
		$dumpfile("build/test/JTAG_Simple_tb.fst");
        $dumpvars(0, JTAG_Simple_tb);

        // Init
        i_clock = 0;
        TCK     = 0;
        TMS     = 1;
        TDI     = 0;
        i_reset = 1;

        expected_idcode = {
            IDCODE_VERSION[3:0],
            IDCODE_PART[15:0],
            IDCODE_MANUFACTURER[10:0],
            1'b1
        };

        #50;
        i_reset = 0;

        // JTAG reset sequence
        jtag_reset();
        goto_run_test_idle();

        // -----------------------------
        // IR test
        // -----------------------------
        $display("---- IR TEST 1 ----");
        shift_ir(4'b1011);

        // -----------------------------
        // DR / IDCODE test
        // -----------------------------
        $display("---- DR / IDCODE TEST ----");
        shift_dr(32'b0);

        if (dr_shifted_out !== expected_idcode) begin
            $error("IDCODE MISMATCH! Expected %h, got %h",
                   expected_idcode, dr_shifted_out);
        end else begin
            $display("IDCODE PASS: %h", dr_shifted_out);
        end

        // -----------------------------
        // IR test
        // -----------------------------
        $display("---- IR TEST 2 ----");
        shift_ir(4'b1110);

        // -----------------------------
        // DR / USERDATA test 1
        // -----------------------------
        $display("---- DR / USERDATA TEST 1 ----");
        shift_dr(32'hcafe_cafe);

        if (dr_shifted_out !== 32'hb00b_babe) begin
            $error("USERDATA MISMATCH! Expected %h, got %h",
                   32'hb00b_babe, dr_shifted_out);
        end else begin
            $display("USERDATA PASS: %h", dr_shifted_out);
        end

        // -----------------------------
        // DR / USERDATA test 2
        // -----------------------------
        $display("---- DR / USERDATA TEST 2 ----");
        shift_dr(32'b0);

        if (dr_shifted_out !== 32'hcafe_cafe) begin
            $error("USERDATA MISMATCH! Expected %h, got %h",
                   32'hcafe_cafe, dr_shifted_out);
        end else begin
            $display("USERDATA PASS: %h", dr_shifted_out);
        end

        // -----------------------------
        // Done
        // -----------------------------
        #200;
        $display("JTAG FSM + SCOREBOARD TEST COMPLETE");
        $finish;
    end

endmodule
