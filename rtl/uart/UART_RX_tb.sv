

`timescale 1ns/1ns
`default_nettype none

module UART_RX_tb();

	bit clk;

	bit uart_rx_request;
    bit [1:0] uart_rx_address;
	wire [31:0] uart_rx_rdata;
	wire uart_rx_ready;

	UART_RX #(
		.FREQUENCY(100000000),
		.BAUDRATE(115200),
        .FIFO_DEPTH(16)
	) uart_rx(
		.i_reset(1'b0),
		.i_clock(clk),
		.i_request(uart_rx_request),
        .i_address(uart_rx_address),
		.o_rdata(uart_rx_rdata),
		.o_ready(uart_rx_ready),
        .o_interrupt(),
        .o_soft_reset(),
        .UART_RX(1'b0)
	);

	initial begin
		clk = 0;
		#1;
		forever clk = #5 ~clk;        
	end

    initial begin
        $dumpfile("build/test/UART_RX_tb.vcd");
        $dumpvars(0, UART_RX_tb);

		repeat (1000) @ (posedge clk);

		uart_rx_request <= 1'b1;
        uart_rx_address <= 2'h1;

		while (!uart_rx_ready) begin
			@(posedge clk);
		end

		uart_rx_request <= 1'b0;

		repeat (10000) @ (posedge clk);

		$finish;
	end

endmodule