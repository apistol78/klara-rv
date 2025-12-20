/*
 Klara-RTL
 Copyright (c) 2025 Anders Pistol.

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at https://mozilla.org/MPL/2.0/.
*/

`timescale 1ns/1ns
`default_nettype none

`define DLY_NEXT(ns) begin; dly_next_state <= ns; state <= WAIT_DELAY; end

// CPOL = 0, CPHA = 1
module SPI #(
	parameter DELAY = 0
)(
	input i_reset,
	input i_clock,
	input i_request,
	input i_rw,
	input [1:0] i_address,
	input [31:0] i_wdata,
	output bit [31:0] o_rdata,
	output bit o_ready,

	output SPI_SS_n,
	output SPI_SCLK,
	output SPI_MOSI,
	input SPI_MISO
);

	typedef enum bit [5:0]
	{
		IDLE,
		READ_TX,
		READ_TX_1,
		S_PULSE_MSB,
		S_PULSE_MSB_1,
		S_PULSE_END_MSB,
		S_BEGIN_WRITE,
		S_END_WRITE,
		WAIT_DELAY,
		WAIT_DELAY_I
	}
	state_t;

	// Transmit data queue.
	wire tx_queue_empty;
	wire tx_queue_full;
	bit tx_queue_write = 0;
	bit tx_queue_read = 0;
	bit [7:0] tx_queue_wdata;
	wire [7:0] tx_queue_rdata;
	FIFO_BRAM #(
		.DEPTH(1024),
		.WIDTH(8)
	) tx_queue(
		.i_reset(i_reset),
		.i_clock(i_clock),
		.o_empty(tx_queue_empty),
		.o_almost_full(tx_queue_full),
		.i_write(tx_queue_write),
		.i_wdata(tx_queue_wdata),
		.i_read(tx_queue_read),
		.o_rdata(tx_queue_rdata),
		.o_queued()
	);

	// Receive data queue.
	wire rx_queue_empty;
	wire rx_queue_full;
	bit rx_queue_write = 0;
	bit rx_queue_read = 0;
	bit [7:0] rx_queue_wdata;
	wire [7:0] rx_queue_rdata;
	FIFO_BRAM #(
		.DEPTH(1024),
		.WIDTH(8)
	) rx_queue(
		.i_reset(i_reset),
		.i_clock(i_clock),
		.o_empty(rx_queue_empty),
		.o_almost_full(rx_queue_full),
		.i_write(rx_queue_write),
		.i_wdata(rx_queue_wdata),
		.i_read(rx_queue_read),
		.o_rdata(rx_queue_rdata),
		.o_queued()
	);

	bit spi_ss = 1'b0;
	bit spi_sclk = 1'b0;
	bit spi_mosi = 1'b0;

	assign SPI_SS_n = ~spi_ss;
	assign SPI_SCLK = spi_sclk;
	assign SPI_MOSI = spi_mosi;

	state_t dly_next_state;
	bit [23:0] dly_count;

	state_t state = IDLE;
	bit [2:0] read_state = 0;

	bit [3:0] counter = 4'd0;
	bit [7:0] tx_word = 8'h0;
	bit [7:0] rx_word = 8'h0;

	bit spi_rx_enable = 1'b1;

	always_ff @(posedge i_clock) begin

		rx_queue_read <= 1'b0;
		tx_queue_write <= 1'b0;

		if (i_request && !o_ready) begin
			if (!i_rw) begin
				if (i_address == 2'd0) begin
					case (read_state)
						0: begin
							if (!rx_queue_empty) begin
								rx_queue_read <= 1'b1;
								read_state <= 1;
							end
						end
						1: begin
							rx_queue_read <= 1'b0;
							read_state <= 2;
						end
						2: begin
							o_rdata <= rx_queue_rdata;
							o_ready <= 1'b1;
						end
					endcase
				end
				else if (i_address == 2'd1) begin
					o_rdata <= 
					{
						27'b0,
						rx_queue_empty,
						rx_queue_full,
						tx_queue_empty,
						tx_queue_full,
						(state == IDLE && tx_queue_empty)
					};
					o_ready <= 1'b1;
				end
			end
			else begin
				if (i_address == 2'd0) begin
					tx_queue_wdata <= i_wdata[7:0];
					if (!tx_queue_full) begin
						tx_queue_write <= 1'b1;
						o_ready <= 1'b1;
					end
				end
				else if (i_address == 2'd1) begin
					spi_ss <= i_wdata[0];
					spi_rx_enable <= i_wdata[1];
					o_ready <= 1'b1;
				end
			end
		end
		else if (!i_request) begin
			o_ready <= 1'b0;
			read_state <= 0;
		end
	end

	always_ff @(posedge i_clock) begin
		case (state)

			IDLE: begin
				if (!tx_queue_empty) begin
					tx_queue_read <= 1'b1;
					state <= READ_TX;
				end
			end

			READ_TX: begin
				tx_queue_read <= 1'b0;
				state <= READ_TX_1;
			end

			READ_TX_1: begin
				tx_word <= tx_queue_rdata;
				rx_word <= 8'h0;
				spi_sclk <= 1'b0;
				counter <= 0;
				`DLY_NEXT(S_PULSE_MSB);
			end

			S_PULSE_MSB: begin
				spi_mosi <= tx_word[7];
				`DLY_NEXT(S_PULSE_MSB_1);
			end

			S_PULSE_MSB_1: begin
				spi_sclk <= 1'b1;
				tx_word <= { tx_word[6:0], 1'b0 };
				`DLY_NEXT(S_PULSE_END_MSB);
			end

			S_PULSE_END_MSB: begin
				spi_sclk <= 1'b0;
				rx_word <= { rx_word[6:0], SPI_MISO };
				counter <= counter + 4'd1;
				if (counter < 4'd7) begin
					`DLY_NEXT(S_PULSE_MSB);
				end
				else begin
					if (spi_rx_enable)
						state <= S_BEGIN_WRITE;
					else begin
						`DLY_NEXT(IDLE);
					end
				end
			end

			S_BEGIN_WRITE: begin
				rx_queue_wdata <= rx_word;
				rx_queue_write <= 1'b1;
				state <= S_END_WRITE;
			end

			S_END_WRITE: begin
				rx_queue_write <= 1'b0;
				`DLY_NEXT(IDLE);
			end

			// Delay states.

			WAIT_DELAY: begin
				if (DELAY > 0) begin
					dly_count <= 0;
					state <= WAIT_DELAY_I;
				end
				else begin
					state <= dly_next_state;
				end
			end

			WAIT_DELAY_I: begin
				dly_count <= dly_count + 1;
				if (dly_count >= DELAY)
					state <= dly_next_state;
			end
		endcase

	end

endmodule;
