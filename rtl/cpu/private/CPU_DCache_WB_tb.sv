

`timescale 1ns/1ns

module CPU_DCache_WB_tb();

	bit clk;

	wire bus_request;
	bit bus_ready = 1'b0;

	bit wb_rw = 1'b0;
	bit wb_request = 1'b0;
	wire wb_ready;
	bit [31:0] wb_address = 0;
	wire [31:0] wb_rdata;
	bit [31:0] wb_wdata = 0;
	bit wb_cached = 1'b1;

	CPU_DCache_WB wb(
		.i_reset(1'b0),
		.i_clock(clk),

		.o_bus_request(bus_request),
		.i_bus_ready(bus_ready),

		.i_rw(wb_rw),
		.i_request(wb_request),
		.o_ready(wb_ready),
		.i_address(wb_address),
		.o_rdata(wb_rdata),
		.i_wdata(wb_wdata),
		.i_cached(wb_cached)
	);

	initial begin
		forever begin
			if (bus_request) begin
				repeat (10) @ (posedge clk);
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
        $dumpfile("build/test/CPU_DCache_WB_tb.vcd");
        $dumpvars(0, CPU_DCache_WB_tb);

		repeat (10) @ (posedge clk);

		// issue a write
		wb_rw <= 1'b1;
		wb_request <= 1'b1;
		wb_address <= 32'h4;
		wb_wdata <= 32'hbeefbeef;
		while (!wb_ready) begin
			@(posedge clk);
		end
		wb_request <= 1'b0;

		// wait a while and accept bus request
		repeat (5) @ (posedge clk);


		//===================================
		repeat (100) @ (posedge clk);
		//===================================


		// issue a write
		wb_rw <= 1'b1;
		wb_request <= 1'b1;
		wb_address <= 32'h5;
		wb_wdata <= 32'hbeef1111;
		while (!wb_ready) begin
			@(posedge clk);
		end
		wb_request <= 1'b0;

		repeat (2) @ (posedge clk);

		// issue a write
		wb_rw <= 1'b1;
		wb_request <= 1'b1;
		wb_address <= 32'h6;
		wb_wdata <= 32'hbeef2222;
		while (!wb_ready) begin
			@(posedge clk);
		end
		wb_request <= 1'b0;

		// wait a while and accept bus request
		repeat (5) @ (posedge clk);


		//===================================
		repeat (100) @ (posedge clk);
		//===================================


		// issue a write
		wb_rw <= 1'b1;
		wb_request <= 1'b1;
		wb_address <= 32'h7;
		wb_wdata <= 32'hbeef3333;
		while (!wb_ready) begin
			@(posedge clk);
		end
		wb_request <= 1'b0;

		repeat (2) @ (posedge clk);

		// issue a read
		wb_rw <= 1'b0;
		wb_request <= 1'b1;
		wb_address <= 32'h8;
		while (!wb_ready) begin
			@(posedge clk);
		end
		wb_request <= 1'b0;

		// wait a while and accept bus request
		repeat (5) @ (posedge clk);


		//===================================
		repeat (100) @ (posedge clk);
		//===================================
		

		$finish;
	end

endmodule