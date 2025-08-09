

`timescale 1ns/1ns
`default_nettype none

module CPU_ICache_Reg_tb();

	bit clk;

	bit [31:0] ic_pc = 32'h0;
	wire [31:0] ic_rdata;
	wire ic_ready;

	wire bus_request;
	bit bus_ready = 1'b0;
	wire [31:0] bus_address;
	wire [31:0] bus_rdata = bus_ready ? bus_address : 32'h0;

	CPU_ICache_Reg #(
		.SIZE(3)
	) ic (
		.i_reset(1'b0),
		.i_clock(clk),

		.i_input_pc(ic_pc),
		.o_rdata(ic_rdata),
		.o_ready(ic_ready),

		.o_bus_request(bus_request),
		.i_bus_ready(bus_ready),
		.o_bus_address(bus_address),
		.i_bus_rdata(bus_rdata),

		.o_hit(),
		.o_miss()
	);

	initial begin
		forever begin
			if (bus_request) begin
				repeat (4) @ (posedge clk);
				bus_ready <= 1'b1;
				@ (posedge clk);
				bus_ready <= 1'b0;
			end
			@ (posedge clk);
		end
	end

	initial begin
		clk = 0;
		#1;
		forever clk = #5 ~clk;        
	end

    initial begin
        $dumpfile("build/test/CPU_ICache_Reg_tb.vcd");
        $dumpvars(0, CPU_ICache_Reg_tb);

		repeat (10) @(posedge clk);

		ic_pc <= 4;
		@(posedge clk);
		while (!ic_ready) @(posedge clk);
		assert(ic_rdata == 4);

		ic_pc <= 8;
		@(posedge clk);
		while (!ic_ready) @(posedge clk);
		assert(ic_rdata == 8);

		ic_pc <= 12;
		@(posedge clk);
		while (!ic_ready) @(posedge clk);
		assert(ic_rdata == 12);

		ic_pc <= 16;
		@(posedge clk);
		while (!ic_ready) @(posedge clk);
		assert(ic_rdata == 16);

		ic_pc <= 4;
		@(posedge clk);
		while (!ic_ready) @(posedge clk);
		assert(ic_rdata == 4);

		ic_pc <= 8;
		@(posedge clk);
		while (!ic_ready) @(posedge clk);
		assert(ic_rdata == 8);

		ic_pc <= 12;
		@(posedge clk);
		while (!ic_ready) @(posedge clk);
		assert(ic_rdata == 12);

		ic_pc <= 16;
		@(posedge clk);
		while (!ic_ready) @(posedge clk);
		assert(ic_rdata == 16);

		//===================================
		repeat (100) @ (posedge clk);
		//===================================

		$finish;
	end

endmodule