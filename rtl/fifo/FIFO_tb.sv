

`timescale 1ns/1ns
`default_nettype none

module FIFO_tb();

	bit clk;

	bit fifo_write;
	bit [7:0] fifo_wdata;
	bit fifo_read;
	bit [7:0] fifo_rdata;

	FIFO #(
		.DEPTH(8),
		.WIDTH(8)
	) fifo(
		.i_reset(1'b0),
		.i_clock(clk),
		.o_empty(),
		.o_full(),
		.i_write(fifo_write),
		.i_wdata(fifo_wdata),
		.i_read(fifo_read),
		.o_rdata(fifo_rdata),
		.o_queued()
	);

	initial begin
		clk = 0;
		#1;
		forever clk = #5 ~clk;        
	end

	initial begin
		$dumpfile("build/test/FIFO_tb.vcd");
		$dumpvars(0, FIFO_tb);

		repeat (10) @ (posedge clk);

		fifo_wdata <= 8'ha1;
		repeat (10) begin
			fifo_write <= 1'b1;
			@(posedge clk);
			fifo_write <= 1'b0;
			@(posedge clk);
			fifo_wdata <= fifo_wdata + 1;
		end

		repeat (10) begin
			fifo_write <= 1'b1;
			@(posedge clk);
			fifo_write <= 1'b0;
			fifo_read <= 1'b1;
			@(posedge clk);
			fifo_read <= 1'b0;
			fifo_wdata <= fifo_wdata + 1;
		end

		@(posedge clk);
		repeat (20) begin
			fifo_read <= 1'b1;
			@(posedge clk);
			fifo_read <= 1'b0;
			@(posedge clk);
		end

		repeat (10000) @ (posedge clk);

		$finish;
	end

endmodule