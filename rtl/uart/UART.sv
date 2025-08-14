/*
 Klara-RTL
 Copyright (c) 2025 Anders Pistol.

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at https://mozilla.org/MPL/2.0/.
*/

`timescale 1ns/1ns
`default_nettype none

module UART #(
	parameter FREQUENCY,
	parameter BAUDRATE = 9600,
	parameter RX_FIFO_DEPTH = 16,
	parameter TX_FIFO_DEPTH = 16
)(
	input i_reset,
	input i_clock,

	input i_request,
	input i_rw,
	input [1:0] i_address,
	input [31:0] i_wdata,
	output [31:0] o_rdata,
    output o_ready,
	output o_interrupt,
	output o_soft_reset,
	
    input UART_RX,
    output UART_TX
);

	bit rx_request;
	wire rx_ready;
	UART_RX #(
		.FREQUENCY(FREQUENCY),
		.BAUDRATE(BAUDRATE),
		.FIFO_DEPTH(RX_FIFO_DEPTH)
	) rx(
		.i_reset(i_reset),
		.i_clock(i_clock),
		.i_request(rx_request),
		.i_address(i_address),
		.o_rdata(o_rdata),
		.o_ready(rx_ready),
		.o_interrupt(o_interrupt),
		.o_soft_reset(o_soft_reset),
		.UART_RX(UART_RX)
	);

	bit tx_request;
	wire tx_ready;
	UART_TX #(
		.FREQUENCY(FREQUENCY),
		.BAUDRATE(BAUDRATE),
		.FIFO_DEPTH(TX_FIFO_DEPTH)
	) tx(
		.i_reset(i_reset),
		.i_clock(i_clock),
		.i_request(tx_request),
		.i_wdata(i_wdata),
		.o_ready(tx_ready),
		.UART_TX(UART_TX)
	);
	
	always_comb begin
		rx_request = i_request && !i_rw;
		tx_request = i_request && i_rw;
	end
	
	assign o_ready = rx_ready | tx_ready;

endmodule
