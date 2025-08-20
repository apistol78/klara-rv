

`timescale 1ns/1ns
`default_nettype none

module UART_tb();

	bit clk;


	bit uart_tx_request;
	bit [31:0] uart_tx_wdata;
	wire uart_tx_ready;
	wire UART_TX;

	UART_TX #(
		.FREQUENCY(100000000),
		.BAUDRATE(115200)
	) uart_tx(
		.i_reset(1'b0),
		.i_clock(clk),
		.i_request(uart_tx_request),
		.i_wdata(uart_tx_wdata),
		.o_ready(uart_tx_ready),
		.UART_TX(UART_TX)
	);


	bit uart_request;
	bit uart_rw;
	bit [1:0] uart_address;
	bit [31:0] uart_wdata;
	wire [31:0] uart_rdata;
	wire uart_ready;

	UART #(
		.FREQUENCY(100000000),
		.BAUDRATE(115200),
		.RX_FIFO_DEPTH(16),
		.TX_FIFO_DEPTH(16)
	) uart(
		.i_reset(1'b0),
		.i_clock(clk),
		.i_request(uart_request),
		.i_rw(uart_rw),
		.i_address(uart_address),
		.i_wdata(uart_wdata),
		.o_rdata(uart_rdata),
		.o_ready(uart_ready),
		.o_interrupt(),
		.o_soft_reset(),
		.UART_RX(UART_TX),
		.UART_TX()
	);

	initial begin
		clk = 0;
		#1;
		forever clk = #5 ~clk;        
	end

	initial begin
		repeat (400) @ (posedge clk);

		// Transmit a character.
		uart_tx_request <= 1'b1;
		uart_tx_wdata <= 65;
		while (!uart_tx_ready) begin
			@(posedge clk);
		end
		uart_tx_request <= 1'b0;
		@(posedge clk);
		assert(!uart_tx_ready);

		repeat (12000) @ (posedge clk);

		// Transmit a character.
		uart_tx_request <= 1'b1;
		uart_tx_wdata <= 66;
		while (!uart_tx_ready) begin
			@(posedge clk);
		end
		uart_tx_request <= 1'b0;
		@(posedge clk);
		assert(!uart_tx_ready);
	end

	initial begin
		$dumpfile("build/test/UART_tb.vcd");
		$dumpvars(0, UART_tb);

		uart_request <= 1'b0;
		uart_rw <= 1'b0;

		repeat (100) @ (posedge clk);

		// Query status
		uart_request <= 1'b1;
		uart_address <= 2'h1;
		uart_rw <= 1'b0;
		while (!uart_ready) begin
			@(posedge clk);
		end
		uart_request <= 1'b0;
		assert(uart_rdata == 32'h0000_0002);
		@(posedge clk);
		assert(!uart_ready);

		repeat (10000) @ (posedge clk);

		// Query status again.
		uart_request <= 1'b1;
		uart_address <= 2'h1;
		uart_rw <= 1'b0;
		while (!uart_ready) begin
			@(posedge clk);
		end
		uart_request <= 1'b0;
		assert(uart_rdata == 32'h0000_0000);
		@(posedge clk);
		assert(!uart_ready);

		// Read character.
		uart_request <= 1'b1;
		uart_address <= 2'h0;
		uart_rw <= 1'b0;
		while (!uart_ready) begin
			@(posedge clk);
		end
		uart_request <= 1'b0;
		assert(uart_rdata == 32'd65);
		@(posedge clk);
		assert(!uart_ready);

		// Query status
		uart_request <= 1'b1;
		uart_address <= 2'h1;
		uart_rw <= 1'b0;
		while (!uart_ready) begin
			@(posedge clk);
		end
		uart_request <= 1'b0;
		assert(uart_rdata == 32'h0000_0002);
		@(posedge clk);
		assert(!uart_ready);

		repeat (5000) @ (posedge clk);

		// Read character, should block.
		uart_request <= 1'b1;
		uart_address <= 2'h0;
		uart_rw <= 1'b0;
		while (!uart_ready) begin
			@(posedge clk);
		end
		uart_request <= 1'b0;
		assert(uart_rdata == 32'd66);
		@(posedge clk);
		assert(!uart_ready);

		repeat (5000) @ (posedge clk);

		$finish;
	end

endmodule