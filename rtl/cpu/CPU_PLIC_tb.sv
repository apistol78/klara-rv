

`timescale 1ns/1ns
`default_nettype none

module CPU_PLIC_tb();

	bit clk = 1'b0;

	bit plic_interrupt_0 = 1'b0;
	bit plic_interrupt_1 = 1'b0;
	bit plic_interrupt_2 = 1'b0;
	bit plic_interrupt_3 = 1'b0;

	wire plic_interrupt;

	bit plic_request = 1'b0;
	bit plic_rw = 1'b0;
	bit [23:0] plic_address = 24'h0;
	bit [31:0] plic_wdata = 32'h0;
	wire [31:0] plic_rdata;
	wire plic_ready;

	CPU_PLIC plic (
		.i_reset(1'b0),
		.i_clock(clk),

		.i_interrupt_0(plic_interrupt_0),
		.i_interrupt_1(plic_interrupt_1),
		.i_interrupt_2(plic_interrupt_2),
		.i_interrupt_3(plic_interrupt_3),

		.o_interrupt(plic_interrupt),

		.i_request(plic_request),
		.i_rw(plic_rw),
		.i_address(plic_address),
		.i_wdata(plic_wdata),
		.o_rdata(plic_rdata),
		.o_ready(plic_ready)
	);

	initial begin
		forever clk = #5 ~clk;        
	end

	initial begin
		$dumpfile("build/test/CPU_PLIC_tb.vcd");
		$dumpvars(0, CPU_PLIC_tb);

		repeat (10) @(posedge clk);

		// Enable all PLIC interrupts.
		assert(!plic_ready);
		plic_request <= 1'b1;
		plic_rw <= 1'b1;
		plic_address <= 24'h002000;
		plic_wdata <= { 4'b1111, 1'b0 };
		while (!plic_ready) @(posedge clk);
		plic_request <= 1'b0;

		repeat (10) @(posedge clk);

		// Issue interrupt.
		plic_interrupt_1 <= 1'b1;
		@(posedge clk);
		plic_interrupt_1 <= 1'b0;
		plic_interrupt_0 <= 1'b1;
		@(posedge clk);
		//plic_interrupt_0 <= 1'b0;

		repeat (10) @(posedge clk);
		assert(plic_interrupt);

		// Claim interrupt.
		assert(!plic_ready);
		plic_request <= 1'b1;
		plic_rw <= 1'b0;
		plic_address <= 24'h200004;
		while (!plic_ready) @(posedge clk);
		plic_request <= 1'b0;

		repeat (10) @(posedge clk);

		plic_interrupt_0 <= 1'b0;

		plic_interrupt_2 <= 1'b1;
		repeat (4) @(posedge clk);
		plic_interrupt_2 <= 1'b0;

		repeat (10) @(posedge clk);

		// Complete interrupt.
		assert(!plic_ready);
		plic_request <= 1'b1;
		plic_rw <= 1'b1;
		plic_address <= 24'h200004;
		plic_wdata <= 1;
		while (!plic_ready) @(posedge clk);
		plic_request <= 1'b0;


		repeat (10) @(posedge clk);
		assert(plic_interrupt);

		// Claim interrupt.
		assert(!plic_ready);
		plic_request <= 1'b1;
		plic_rw <= 1'b0;
		plic_address <= 24'h200004;
		while (!plic_ready) @(posedge clk);
		assert(plic_ready);
		plic_request <= 1'b0;

		repeat (10) @(posedge clk);

		// Complete interrupt.
		assert(!plic_ready);
		plic_request <= 1'b1;
		plic_rw <= 1'b1;
		plic_address <= 24'h200004;
		plic_wdata <= 1;
		while (!plic_ready) @(posedge clk);
		assert(plic_ready);
		plic_request <= 1'b0;


		repeat (10) @(posedge clk);
		assert(plic_interrupt);

		// Claim interrupt.
		assert(!plic_ready);
		plic_request <= 1'b1;
		plic_rw <= 1'b0;
		plic_address <= 24'h200004;
		while (!plic_ready) @(posedge clk);
		assert(plic_ready);
		plic_request <= 1'b0;

		repeat (10) @(posedge clk);

		// Complete interrupt.
		assert(!plic_ready);
		plic_request <= 1'b1;
		plic_rw <= 1'b1;
		plic_address <= 24'h200004;
		plic_wdata <= 1;
		while (!plic_ready) @(posedge clk);
		assert(plic_ready);
		plic_request <= 1'b0;

		assert(!plic_interrupt);


		//===================================
		repeat (100) @ (posedge clk);
		//===================================

		$finish;
	end

endmodule