

`timescale 1ns/1ns
`default_nettype none

module BusX_tb();

    bit reset;
	bit clk;

	bit bx_near_request = 1'b0;
    bit bx_near_rw = 1'b0;
    bit [31:0] bx_near_address = 32'b0;
	bit [31:0] bx_near_wdata = 32'b0;
    wire [31:0] bx_near_rdata;
	wire bx_near_ready;

    wire bx_far_request;
    bit bx_far_ready = 1'b0;

	BusX bx(
		.i_reset(reset),
		.i_clock(clk),
        .i_clock_far(clk),

		.i_request(bx_near_request),
        .i_rw(bx_near_rw),
        .i_address(bx_near_address),
		.i_wdata(bx_near_wdata),
        .o_rdata(bx_near_rdata),
		.o_ready(bx_near_ready),

        .o_far_request(bx_far_request),
        .o_far_rw(),
        .o_far_address(),
        .o_far_wdata(),
        .i_far_rdata(32'h0),
        .i_far_ready(bx_far_ready)
	);

    always_ff @(posedge clk) begin
        if (bx_far_request)
            bx_far_ready <= 1'b1;
        else
            bx_far_ready <= 1'b0;
    end

	initial begin
		clk = 0;
		#1;
		forever clk = #5 ~clk;        
	end

    initial begin
        $dumpfile("build/test/BusX_tb.vcd");
        $dumpvars(0, BusX_tb);

        reset = 1;
        repeat (10) @ (posedge clk);
        reset = 0;

        // Count down
		repeat (100) @ (posedge clk);

		bx_near_request <= 1'b1;
        bx_near_address <= 32'h1000_0005;
        bx_near_rw <= 1'b1;
		bx_near_wdata <= 100;

        @(posedge clk);
        //bx_near_request <= 1'b0;

		while (!bx_near_ready) begin
			@(posedge clk);
		end

        bx_near_request <= 1'b0;

		repeat (200000) @ (posedge clk);

		$finish;
	end

endmodule