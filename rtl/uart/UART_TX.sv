/*
 Klara-RTL
 Copyright (c) 2025 Anders Pistol.

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at https://mozilla.org/MPL/2.0/.
*/

`timescale 1ns/1ns
`default_nettype none

module UART_TX #(
	parameter FREQUENCY,
	parameter BAUDRATE = 9600,
	parameter FIFO_DEPTH = 16
)(
	input wire i_reset,
	input wire i_clock,
	input wire i_request,
	input wire [1:0] i_address,
	input wire [31:0] i_wdata,
	output wire o_ready,

	output bit UART_TX
);
	localparam MAX_RATE = FREQUENCY / (BAUDRATE);
	localparam CNT_WIDTH = $clog2(MAX_RATE);

	bit [2:0] state = 0;
	bit [2:0] lstate = 0;
	bit [CNT_WIDTH:0] counter = 0;
	bit [7:0] data = 0;
	bit [8:0] bidx = 0;
	bit ready = 1'b0;

	// FIFO
	bit tx_fifo_reset = 1'b0;
	wire tx_fifo_empty;
	wire tx_fifo_full;
	bit tx_fifo_write = 1'b0;
	bit tx_fifo_read = 1'b0;
	wire [7:0] tx_fifo_rdata;
	FIFO #(
		.DEPTH(FIFO_DEPTH),
		.WIDTH(8)
	) tx_fifo(
		.i_reset(i_reset || tx_fifo_reset),
		.i_clock(i_clock),
		.o_empty(tx_fifo_empty),
		.o_almost_full(tx_fifo_full),
		.i_write(tx_fifo_write),
		.i_wdata(i_wdata[7:0]),
		.i_read(tx_fifo_read),
		.o_rdata(tx_fifo_rdata),
		.o_queued()
	);

	initial begin
		UART_TX = 1'b1;
		ready = 1'b0;
	end

	assign o_ready = i_request && ready;

	// Write to FIFO.
	always_ff @(posedge i_clock) begin
		
		tx_fifo_reset <= 1'b0;
		tx_fifo_write <= 1'b0;

		ready <= 1'b0;
		if (i_request) begin
			if (i_address == 2'h0) begin
				if (!tx_fifo_full) begin
					if (!ready)
						tx_fifo_write <= 1'b1;
					ready <= 1'b1;
				end
			end
			else if (i_address == 2'h2) begin	// Reset
				tx_fifo_reset <= 1'b1;
				ready <= 1'b1;
			end
			else begin
				ready <= 1'b1;
			end
		end
	end

	// Read from FIFO and transmit each byte.
	always_ff @(posedge i_clock) begin
		if (i_reset) begin
			state <= 0;
			lstate <= 0;
			counter <= 0;
			data <= 0;
			bidx <= 0;
			tx_fifo_read <= 1'b0;
		end
		else begin
			if (counter >= MAX_RATE) begin
				counter <= 0;

				// Serial tick.
				case (state)

					// Start bit.
					1: begin
						UART_TX <= 1'b0;
						state <= 2;
					end

					// Clock data out.
					2: begin
						if (bidx < 8'd8) begin
							UART_TX <= data[0];
							data <= data >> 1;
							bidx <= bidx + 1;
						end
						else begin
							// Send stop bit.
							UART_TX <= 1'b1;
							bidx <= 8'd0;
							state <= 3;
						end
					end

					// TX done.
					3: begin
						state <= 0;
					end
				endcase
			end else begin
				counter <= counter + 1;

				// Read from fifo.
				if (state == 0) begin
					case (lstate)
						0: begin
							if (!tx_fifo_empty) begin
								tx_fifo_read <= 1'b1;
								lstate <= 1;
							end
						end
						1: begin
							tx_fifo_read <= 1'b0;
							lstate <= 2;
						end
						2: begin
							data <= tx_fifo_rdata;
							bidx <= 0;
							state <= 1;
						end
					endcase

				end
				else begin
					lstate <= 0;
				end
			end
		end
	end

endmodule
