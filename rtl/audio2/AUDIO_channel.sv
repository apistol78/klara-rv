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
	typedef enum bit [2:0]
	{
		DS_MONO_WAIT_SAMPLE_FIFO,
		DS_MONO_ISSUE_DMA_REQUEST,
		DS_MONO_ENQUEUE_0,
		DS_MONO_ENQUEUE_1,
		DS_STEREO_WAIT_SAMPLE_FIFO,
		DS_STEREO_ISSUE_DMA_REQUEST,
		DS_STEREO_ENQUEUE_0
	}
	dma_state_t;

	bit [31:0] dma_address;
	bit [23:0] dma_count = 24'h0;
	dma_state_t dma_state = DS_MONO_WAIT_SAMPLE_FIFO;

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
	wire sample_fifo_empty;
	wire sample_fifo_full;
	bit sample_fifo_wr = 1'b0;
	bit sample_fifo_rd = 1'b0;
	bit [31:0] sample_fifo_wdata;
	wire [31:0] sample_fifo_rdata;
	
	FIFO #(
		.DEPTH(4),
		.WIDTH(32)
	) sample_fifo(
		.i_reset(i_reset),
		.i_clock(i_clock),
		.o_empty(sample_fifo_empty),
		.o_almost_full(sample_fifo_full),
		.i_write(sample_fifo_wr),
		.i_wdata(sample_fifo_wdata),
		.i_read(sample_fifo_rd),
		.o_rdata(sample_fifo_rdata),
		.o_queued()
	);

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
		o_dma_address = dma_address;

		sample_fifo_wr <= 1'b0;

		// Get next DMA command from queue.
		if (cmdq_next_have) begin
			dma_address <= cmdq_next_address;
			dma_count <= cmdq_next_count;
			dma_state <= dma_state_t'(cmdq_next_mono_or_stereo ? DS_STEREO_WAIT_SAMPLE_FIFO : DS_MONO_WAIT_SAMPLE_FIFO);
		end
		// Process DMA command.
		else begin
			case (dma_state)
			DS_MONO_WAIT_SAMPLE_FIFO: begin
				if (|dma_count && !sample_fifo_full)
					dma_state <= DS_MONO_ISSUE_DMA_REQUEST;
			end
			DS_MONO_ISSUE_DMA_REQUEST: begin
				o_dma_request <= !i_dma_ready;
				if (i_dma_ready)
					dma_state <= DS_MONO_ENQUEUE_0;
			end
			DS_MONO_ENQUEUE_0: begin
				sample_fifo_wr <= 1'b1;
				sample_fifo_wdata <= { i_dma_rdata[15:0], i_dma_rdata[15:0] };
				dma_count <= dma_count - 1;
				dma_state <= DS_MONO_ENQUEUE_1;
			end
			DS_MONO_ENQUEUE_1: begin
				sample_fifo_wr <= 1'b1;
				sample_fifo_wdata <= { i_dma_rdata[31:16], i_dma_rdata[31:16] };
				dma_address <= dma_address + 4;
				dma_count <= dma_count - 1;
				dma_state <= DS_MONO_WAIT_SAMPLE_FIFO;
			end

			DS_STEREO_WAIT_SAMPLE_FIFO: begin
				if (|dma_count && !sample_fifo_full)
					dma_state <= DS_STEREO_ISSUE_DMA_REQUEST;
			end
			DS_STEREO_ISSUE_DMA_REQUEST: begin
				o_dma_request <= !i_dma_ready;
				if (i_dma_ready)
					dma_state <= DS_STEREO_ENQUEUE_0;
			end
			DS_STEREO_ENQUEUE_0: begin
				sample_fifo_wr <= 1'b1;
				sample_fifo_wdata <= i_dma_rdata;
				dma_address <= dma_address + 4;
				dma_count <= dma_count - 1;
				dma_state <= DS_STEREO_WAIT_SAMPLE_FIFO;
			end
			endcase
		end
	end

	// Read new sample from FIFO whenever sample clock change.
	bit last_sample_clock = 1'b0;
	bit last_fifo_rd = 1'b0;

	always_ff @(posedge i_clock) begin

		last_sample_clock <= i_output_sample_clock;
		last_fifo_rd <= sample_fifo_rd;

		sample_fifo_rd <= 1'b0;

		if (i_output_sample_clock != last_sample_clock) begin
			if (!sample_fifo_empty)
				sample_fifo_rd <= 1'b1;
			else begin
				o_output_sample_left <= 0;
				o_output_sample_right <= 0;
			end
		end

		if (last_fifo_rd) begin
			o_output_sample_left <= sample_fifo_rdata[31:16];
			o_output_sample_right <= sample_fifo_rdata[15:0];
		end
	end

endmodule
