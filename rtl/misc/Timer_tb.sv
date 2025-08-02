

`timescale 1ns/1ns

module Timer_tb();

	bit clk;

	bit tmr_request = 1'b0;
    bit tmr_rw = 1'b0;
    bit [3:0] tmr_address = 4'b0;
	bit [31:0] tmr_wdata = 32'b0;
    wire [31:0] tmr_rdata;
	wire tmr_ready;

	Timer #(
		.FREQUENCY(100000000)
    ) tmr(
		.i_reset(1'b0),
		.i_clock(clk),
		.i_request(tmr_request),
        .i_rw(tmr_rw),
        .i_address(tmr_address),
		.i_wdata(tmr_wdata),
        .o_rdata(tmr_rdata),
		.o_ready(tmr_ready)
	);

	initial begin
		clk = 0;
		#1;
		forever clk = #5 ~clk;        
	end

    initial begin
        $dumpfile("Timer_tb.vcd");
        $dumpvars(0, Timer_tb);

        // Count down
		repeat (100) @ (posedge clk);

		tmr_request <= 1'b1;
        tmr_address <= 4'h5;
        tmr_rw <= 1'b1;
		tmr_wdata <= 100;

		while (!tmr_ready) begin
			@(posedge clk);
		end

		tmr_request <= 1'b0;
		while (tmr_ready) begin
			@(posedge clk);
		end


        // Compare to
		repeat (500) @ (posedge clk);

		tmr_request <= 1'b1;
        tmr_address <= 4'h3;
        tmr_rw <= 1'b1;
		tmr_wdata <= 1200;

		while (!tmr_ready) begin
			@(posedge clk);
		end

		tmr_request <= 1'b0;
		while (tmr_ready) begin
			@(posedge clk);
		end

        @(posedge clk);

		tmr_request <= 1'b1;
        tmr_address <= 4'h4;
        tmr_rw <= 1'b1;
		tmr_wdata <= 0;

		while (!tmr_ready) begin
			@(posedge clk);
		end

		tmr_request <= 1'b0;
		while (tmr_ready) begin
			@(posedge clk);
		end


		repeat (200000) @ (posedge clk);

		$finish;
	end

endmodule