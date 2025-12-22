/*
 Klara-RTL
 Copyright (c) 2025 Anders Pistol.

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at https://mozilla.org/MPL/2.0/.
*/

`timescale 1ns/1ns
`default_nettype none

/*!
AUDIO controller which basically holds the audio
configuration registers and also a small FIFO to
queue samples to the output AUDIO device.
The queue is kept small as the basic idea is to have
a DMA channel kept busy to feed to the audio stream.
*/
module AUDIO_channel #(
	parameter BUFFER_SIZE = 4
)(
	input wire i_reset,
	input wire i_clock,

	// DMA setup
	input wire i_dma_setup_request,
	input wire [31:0] i_dma_setup_count,
	input wire [31:0] i_dma_setup_address,

	// DMA bus master
	output bit o_dma_request,
	output bit [31:0] o_dma_address,
	input wire i_dma_ready,
	input wire [31:0] i_dma_rdata,

	// Audio output stream
	input wire i_output_sample_clock,
	output bit [15:0] o_output_sample_left,
	output bit [15:0] o_output_sample_right
);
	// Sample FIFO.
	wire fifo_empty;
	wire fifo_full;
	bit fifo_wr = 0;
	bit fifo_rd = 0;
	wire [31:0] fifo_rdata;
	FIFO #(
		.DEPTH(BUFFER_SIZE),
		.WIDTH(32)
	) fifo(
		.i_reset(i_reset),
		.i_clock(i_clock),
		.o_empty(fifo_empty),
		.o_almost_full(fifo_full),
		.i_write(fifo_wr),
		.i_wdata(i_dma_rdata),
		.i_read(fifo_rd),
		.o_rdata(fifo_rdata),
		.o_queued()
	);

	bit [31:0] dma_address;
	bit [31:0] dma_count = 0;

	initial begin
		o_dma_request = 0;
		o_output_sample_left = 0;
		o_output_sample_right = 0;
	end

	// Process DMA setup.
	always_ff @(posedge i_clock) begin
		if (i_dma_setup_request) begin
			dma_count <= i_dma_setup_count;
			dma_address <= i_dma_setup_address;
		end
	end

	// Process DMA read samples into FIFO.
	always_ff @(posedge i_clock) begin
		o_dma_request <= 1'b0;
		fifo_wr <= 1'b0;
		if (!fifo_full && |dma_count) begin
			o_dma_request <= 1'b1;
			o_dma_address <= dma_address;
			if (i_dma_ready) begin
				fifo_wr <= 1'b1;
				o_dma_request <= 1'b0;
				dma_count <= dma_count - 1;
				dma_address <= dma_address + 4;
			end
		end
	end

	// Read new sample from FIFO whenever sample clock change.
	bit last_sample_clock = 1'b0;
	bit last_fifo_rd = 1'b0;

	always_ff @(posedge i_clock) begin

		last_sample_clock <= i_output_sample_clock;
		last_fifo_rd <= fifo_rd;

		fifo_rd <= 1'b0;

		if (i_output_sample_clock != last_sample_clock) begin
			if (!fifo_empty)
				fifo_rd <= 1'b1;
			else begin
				o_output_sample_left <= 0;
				o_output_sample_right <= 0;
			end
		end

		if (last_fifo_rd) begin
			o_output_sample_left <= fifo_rdata[31:16];
			o_output_sample_right <= fifo_rdata[15:0];
		end
	end

endmodule
