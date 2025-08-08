

`timescale 1ns/1ns

module XBAR_2_2_tb();

	bit clk;


	wire slv0_request;
	wire slv0_rw;
	wire [31:0] slv0_address;
	wire [31:0] slv0_wdata;
	wire [31:0] slv0_rdata;
	wire slv0_ready;

	BRAM slv0(
		.i_clock(clk),
		.i_request(slv0_request),
		.i_rw(slv0_rw),
		.i_address({ 4'b0, slv0_address[27:0] }),
		.i_wdata(slv0_wdata),
		.o_rdata(slv0_rdata),
		.o_ready(slv0_ready),
		.o_valid()
	);


	wire slv1_request;
	wire slv1_rw;
	wire [31:0] slv1_address;
	wire [31:0] slv1_wdata;
	wire [31:0] slv1_rdata;
	wire slv1_ready;

	BRAM slv1(
		.i_clock(clk),
		.i_request(slv1_request),
		.i_rw(slv1_rw),
		.i_address({ 4'b0, slv1_address[27:0] }),
		.i_wdata(slv1_wdata),
		.o_rdata(slv1_rdata),
		.o_ready(slv1_ready),
		.o_valid()
	);

	bit m0_request = 1'b0;
	bit m0_rw = 1'b0;
	bit [31:0] m0_address = 32'b0;
	bit [31:0] m0_wdata = 32'b0;
	wire [31:0] m0_rdata;
	wire m0_ready;

	bit m1_request = 1'b0;
	bit m1_rw = 1'b0;
	bit [31:0] m1_address = 32'b0;
	bit [31:0] m1_wdata = 32'b0;
	wire [31:0] m1_rdata;
	wire m1_ready;

	XBAR_2_2 xbar(
		.i_reset(1'b0),
		.i_clock(clk),

		.i_m0_rw(m0_rw),
		.i_m0_request(m0_request),
		.o_m0_ready(m0_ready),
		.i_m0_address(m0_address),
		.o_m0_rdata(m0_rdata),
		.i_m0_wdata(m0_wdata),

		.i_m1_rw(m1_rw),
		.i_m1_request(m1_request),
		.o_m1_ready(m1_ready),
		.i_m1_address(m1_address),
		.o_m1_rdata(m1_rdata),
		.i_m1_wdata(m1_wdata),

		.o_s0_rw(slv0_rw),
		.o_s0_request(slv0_request),
		.i_s0_ready(slv0_ready),
		.o_s0_address(slv0_address),
		.i_s0_rdata(slv0_rdata),
		.o_s0_wdata(slv0_wdata),

		.o_s1_rw(slv1_rw),
		.o_s1_request(slv1_request),
		.i_s1_ready(slv1_ready),
		.o_s1_address(slv1_address),
		.i_s1_rdata(slv1_rdata),
		.o_s1_wdata(slv1_wdata)
	);

	initial begin
		clk = 0;
		#1;
		forever clk = #5 ~clk;        
	end

	always_ff @(posedge clk) begin
		if (m0_request && m0_ready)
			m0_request <= 0;
	end 

	always_ff @(posedge clk) begin
		if (m1_request && m1_ready)
			m1_request <= 0;
	end 

	initial begin
		$dumpfile("build/test/XBAR_2_2_tb.vcd");
		$dumpvars(0, XBAR_2_2_tb);

		repeat (100) @ (posedge clk);

		m0_rw = 1'b1;
		m0_request = 1'b1;
		m0_address = 32'h0000_0001;

		// m1_rw = 1'b1;
		// m1_request = 1'b1;
		// m1_address = 32'h0000_0002;

		while (!m0_ready) @(posedge clk);
		@(posedge clk);
		assert(m0_request == 1'b0);

		m0_rw = 1'b1;
		m0_request = 1'b1;
		m0_address = 32'h1000_0003;


		// while (!m1_ready) @(posedge clk);
		// @(posedge clk);
		// assert(m1_request == 1'b0);

		//@(posedge clk);
		@(posedge clk);

		m1_rw = 1'b1;
		m1_request = 1'b1;
		m1_address = 32'h0000_0004;


		repeat (200000) @ (posedge clk);

		$finish;
	end

endmodule