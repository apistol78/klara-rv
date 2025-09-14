

`timescale 1ns/1ns
`default_nettype none

module I2C_v2_tb();

	bit clk;

	bit i2c_request = 1'b0;
	bit i2c_rw = 1'b0;
	bit [1:0] i2c_address = 2'b0;
	bit [31:0] i2c_wdata = 32'b0;
	wire [31:0] i2c_rdata;
	wire i2c_ready;

	I2C_v2 #(
		.DELAY(4)
	) i2c (
		.i_reset(1'b0),
		.i_clock(clk),

		.i_request(i2c_request),
		.i_rw(i2c_rw),
		.i_address(i2c_address),
		.i_wdata(i2c_wdata),
		.o_rdata(i2c_rdata),
		.o_ready(i2c_ready),

		.I2C_SCL(),
		.I2C_SDA_direction(),
		.I2C_SDA_r(1'b0),
		.I2C_SDA_w()
	);

	initial begin
		clk = 0;
		#1;
		forever clk = #5 ~clk;        
	end

	initial begin
		$dumpfile("build/test/I2C_v2_tb.vcd");
		$dumpvars(0, I2C_v2_tb);

		repeat (100) @ (posedge clk);

		$display("sending...");
		i2c_request = 1'b1;
		i2c_rw = 1'b1;
		i2c_address = 2'd0;
		i2c_wdata =
		{
			8'd1,			// data
			8'h7f,			// control
			8'h1a,			// device
			6'b0, 2'd2
		};
		while (!i2c_ready) begin
			@(posedge clk);
		end
		i2c_request = 1'b0;

		repeat (10000) @ (posedge clk);

		$display("receiving...");
		i2c_request = 1'b1;
		i2c_rw = 1'b1;
		i2c_address = 2'd0;
		i2c_wdata =
		{
			8'd1,			// 1 byte
			8'h7f,			// control
			8'h1a,			// device
			6'b0, 2'd1
		};
		while (!i2c_ready) begin
			@(posedge clk);
		end
		i2c_request = 1'b0;

		repeat (10000) @ (posedge clk);

		$display("receiving...");
		i2c_request = 1'b1;
		i2c_rw = 1'b1;
		i2c_address = 2'd0;
		i2c_wdata =
		{
			8'd3,			// 1 byte
			8'h7f,			// control
			8'h1a,			// device
			6'b0, 2'd1
		};
		while (!i2c_ready) begin
			@(posedge clk);
		end
		i2c_request = 1'b0;

		repeat (200000) @ (posedge clk);

		$finish;
	end

endmodule