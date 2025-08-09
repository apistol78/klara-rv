

`timescale 1ns/1ns
`default_nettype none

module UART_TX_tb();

	bit clk;

	bit uart_tx_request;
	bit [31:0] uart_tx_wdata;
	wire uart_tx_ready;

	UART_TX #(
		.FREQUENCY(100000000),
		.BAUDRATE(115200)
	) uart_tx(
		.i_reset(1'b0),
		.i_clock(clk),
		.i_request(uart_tx_request),
		.i_wdata(uart_tx_wdata),
		.o_ready(uart_tx_ready)
	);

	initial begin
		clk = 0;
		#1;
		forever clk = #5 ~clk;        
	end

    initial begin
        $dumpfile("build/test/UART_TX_tb.vcd");
        $dumpvars(0, UART_TX_tb);

		repeat (1000) @ (posedge clk);

		uart_tx_request <= 1'b1;
		uart_tx_wdata <= 65;

		while (!uart_tx_ready) begin
			@(posedge clk);
		end

		uart_tx_request <= 1'b0;

		repeat (10000) @ (posedge clk);

		$finish;
	end

endmodule