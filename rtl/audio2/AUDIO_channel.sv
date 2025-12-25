/*
 Klara-RTL
 Copyright (c) 2025 Anders Pistol.

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at https://mozilla.org/MPL/2.0/.
*/

`timescale 1ns/1ns
`default_nettype none

module AUDIO_channel(
	input wire i_reset,
	input wire i_clock,

	// DMA setup
	input wire i_dma_setup_request,
	input wire i_dma_setup_append_or_replace,
	input wire i_dma_setup_mono_or_stereo,
	input wire [31:0] i_dma_setup_address,
	input wire [23:0] i_dma_setup_count,

	// DMA bus master
	output bit o_dma_request,
	output bit [31:0] o_dma_address,
	input wire i_dma_ready,
	input wire [31:0] i_dma_rdata,

	// Status
	output bit o_busy,

	// Parameters.
	input wire [3:0] i_volume,

	// Audio output stream
	input wire i_output_sample_clock,
	output bit [15:0] o_output_sample_left,
	output bit [15:0] o_output_sample_right
);
	bit dma_mono_or_stereo = 1'b0;
	bit [31:0] dma_address;
	bit [23:0] dma_count = 24'h0;

	// DMA command queue.
	wire cmdq_next_have;
	wire cmdq_next_mono_or_stereo;
	wire [31:0] cmdq_next_address;
	wire [23:0] cmdq_next_count;
	wire cmdq_next_queued;

	AUDIO_cmdq cmdq(
		.i_reset(i_reset),
		.i_clock(i_clock),

		.i_setup_request(i_dma_setup_request),
		.i_setup_append_or_replace(i_dma_setup_append_or_replace),
		.i_setup_mono_or_stereo(i_dma_setup_mono_or_stereo),
		.i_setup_address(i_dma_setup_address),
		.i_setup_count(i_dma_setup_count),

		.i_next_ready(~|dma_count),
		.o_next_have(cmdq_next_have),
		.o_next_mono_or_stereo(cmdq_next_mono_or_stereo),
		.o_next_address(cmdq_next_address),
		.o_next_count(cmdq_next_count),

		.o_next_queued(cmdq_next_queued)
	);

	// Sample FIFO.
	parameter SAMPLE_FIFO_DEPTH = 4;

	bit [31:0] sample_fifo_data [SAMPLE_FIFO_DEPTH];
	bit [$clog2(SAMPLE_FIFO_DEPTH) - 1:0] sample_fifo_in = 0;
	bit [$clog2(SAMPLE_FIFO_DEPTH) - 1:0] sample_fifo_out = 0;

	wire sample_fifo_empty = (sample_fifo_in == sample_fifo_out) ? 1'b1 : 1'b0;
	wire sample_fifo_full = (((sample_fifo_in + 1) & (SAMPLE_FIFO_DEPTH - 1)) == sample_fifo_out) ? 1'b1 : 1'b0;
	wire sample_fifo_almost_full = (((sample_fifo_in + 2) & (SAMPLE_FIFO_DEPTH - 1)) == sample_fifo_out) ? 1'b1 : sample_fifo_full;

	initial begin
		o_dma_request = 1'b0;
		o_busy = 1'b0;
		o_output_sample_left = 0;
		o_output_sample_right = 0;
	end

	// Channel is only busy when DMA command queue have any pending.
	always_comb begin
		o_busy = cmdq_next_queued;
	end

	// Process DMA setup and read samples into FIFO.
	always_ff @(posedge i_clock) begin
		o_dma_request <= 1'b0;

		// Get next DMA command from queue.
		if (cmdq_next_have) begin
			dma_mono_or_stereo <= cmdq_next_mono_or_stereo;
			dma_address <= cmdq_next_address;
			dma_count <= cmdq_next_count;
		end

		// Process DMA command; ie reading samples from BUS and inserting into sample FIFO.
		if (!sample_fifo_almost_full && |dma_count) begin
			o_dma_request <= 1'b1;
			o_dma_address <= dma_address;
			if (i_dma_ready && o_dma_request) begin
				if (dma_mono_or_stereo == 1'b0) begin // mono
					if (dma_count >= 2) begin
						sample_fifo_data[sample_fifo_in + 0] <= { i_dma_rdata[15:0], i_dma_rdata[15:0] };
						sample_fifo_data[sample_fifo_in + 1] <= { i_dma_rdata[31:16], i_dma_rdata[31:16] };
						sample_fifo_in <= (sample_fifo_in + 2) & (SAMPLE_FIFO_DEPTH - 1);
						dma_count <= dma_count - 2;
					end
					else if (dma_count == 1) begin	// last word
						sample_fifo_data[sample_fifo_in] <= { i_dma_rdata[15:0], i_dma_rdata[15:0] };
						sample_fifo_in <= (sample_fifo_in + 1) & (SAMPLE_FIFO_DEPTH - 1);
						dma_count <= 0;
					end
				end
				else begin // stereo
					sample_fifo_data[sample_fifo_in] <= i_dma_rdata;
					sample_fifo_in <= (sample_fifo_in + 1) & (SAMPLE_FIFO_DEPTH - 1);
					dma_count <= dma_count - 1;
				end
				o_dma_request <= 1'b0;
				dma_address <= dma_address + 4;
			end
		end
	end

	// Read new sample from FIFO whenever sample clock change.
	bit last_sample_clock = 1'b0;

	bit [19:0] sample_left_0;
	bit [19:0] sample_right_0;
	bit [19:0] sample_left_1;
	bit [19:0] sample_right_1;

	always_ff @(posedge i_clock) begin
		last_sample_clock <= i_output_sample_clock;
		if (i_output_sample_clock != last_sample_clock) begin
			if (!sample_fifo_empty) begin
				sample_left_0 <= $signed(sample_fifo_data[sample_fifo_out][31:16]) * i_volume;
				sample_right_0 <= $signed(sample_fifo_data[sample_fifo_out][15:0]) * i_volume;
				sample_fifo_out <= (sample_fifo_out + 1) & (SAMPLE_FIFO_DEPTH - 1);
			end
			else begin
				sample_left_0 <= 0;
				sample_right_0 <= 0;
			end
		end
		
		sample_left_1 <= sample_left_0;
		sample_right_1 <= sample_right_0;

		o_output_sample_left <= sample_left_1[19:4];
		o_output_sample_right <= sample_right_1[19:4];
	end

endmodule
