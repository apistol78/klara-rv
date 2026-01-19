`include "CPU_Defines.sv"

`timescale 1ns/1ns
`default_nettype none

module CPU_CSR_tb();

	bit clk = 1'b0;

    bit csr_timer_interrupt = 1'b0;
    bit csr_external_interrupt = 1'b0;
    bit csr_mret = 1'b0;
    bit [11:0] csr_index = 12'h0;
    bit [31:0] csr_wdata = 32'h0;
    bit csr_wdata_wr = 1'b0;
    wire csr_irq_pending;
    bit csr_irq_dispatched = 1'b0;
    bit [31:0] csr_irq_epc = 32'hcafe_babe;

	CPU_CSR #(
        .FREQUENCY(100_000_000),
        .VENDORID(0),
        .ARCHID(0),
        .IMPID(0),
        .HARTID(0)
    ) csr (
		.i_reset(1'b0),
		.i_clock(clk),

		.i_timer_interrupt(csr_timer_interrupt),
        .i_external_interrupt(csr_external_interrupt),

        .i_ecall(1'b0),
        .i_mret(csr_mret),

        .i_index(csr_index),
        .o_rdata(),
        .i_wdata_wr(csr_wdata_wr),
        .i_wdata(csr_wdata),

        .o_epc(),
        .o_scratch(),

        .o_irq_pending(csr_irq_pending),
        .o_irq_pc(),
        .i_irq_dispatched(csr_irq_dispatched),
        .i_irq_epc(csr_irq_epc),

        .i_retired(64'h0)
	);

	initial begin
		forever clk = #5 ~clk;        
	end

	initial begin
		$dumpfile("build/test/CPU_CSR_tb.vcd");
		$dumpvars(0, CPU_CSR_tb);

	repeat (10) @(posedge clk);

        // Enable interrupts
        csr_index <= `CSR_MSTATUS;
        csr_wdata <= 32'hffff_ffff;
        csr_wdata_wr <= 1'b1;
        @(posedge clk);
        csr_wdata_wr <= 1'b0;

    repeat (10) @(posedge clk);

        // Trigger an external and timer interrupt.
        csr_timer_interrupt <= 1'b1;
        @(posedge clk);
        csr_external_interrupt <= 1'b1;
        csr_timer_interrupt <= 1'b0;
        @(posedge clk);
        csr_external_interrupt <= 1'b0;

    repeat (10) @(posedge clk);

        // CPU accept interrupt.
        assert(csr_irq_pending);
        csr_irq_dispatched <= 1'b1;
        csr_irq_epc <= 32'hcafe_babe;
        @(posedge clk);
        csr_irq_dispatched <= 1'b0;

    repeat (10) @(posedge clk);

        csr_timer_interrupt <= 1'b1;
        @(posedge clk);
        csr_timer_interrupt <= 1'b0;

    repeat (10) @(posedge clk);

        // CPU return from interrupt.
        csr_mret <= 1'b1;
        @(posedge clk);
        csr_mret <= 1'b0;

    repeat (10) @(posedge clk);

        // CPU accept interrupt.
        assert(csr_irq_pending);
        csr_irq_dispatched <= 1'b1;
        csr_irq_epc <= 32'hb00b_b00b;
        @(posedge clk);
        csr_irq_dispatched <= 1'b0;

    repeat (10) @(posedge clk);

        // CPU return from interrupt.
        csr_mret <= 1'b1;
        @(posedge clk);
        csr_mret <= 1'b0;

    repeat (10) @(posedge clk);


		//===================================
		repeat (100) @ (posedge clk);
		//===================================

		$finish;
	end

endmodule