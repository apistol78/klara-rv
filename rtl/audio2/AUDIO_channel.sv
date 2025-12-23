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
	input wire [31:0] i_dma_setup_address,
	input wire [31:0] i_dma_setup_count,

	// DMA bus master
	output bit o_dma_request,
	output bit [31:0] o_dma_address,
	input wire i_dma_ready,
	input wire [31:0] i_dma_rdata,

	// Status
	output bit o_busy,

	// Audio output stream
	input wire i_output_sample_clock,
	output bit [15:0] o_output_sample_left,
	output bit [15:0] o_output_sample_right
);
	// DMA command FIFO.
	typedef struct packed
	{
		bit [31:0] address;
		bit [31:0] count;
	}
	dma_command_t;

    wire dma_fifo_empty;
	wire dma_fifo_full;
	bit dma_fifo_rd = 1'b0;
	dma_command_t dma_fifo_rcmd;
	FIFO #(
		.DEPTH(4),
		.WIDTH($bits(dma_command_t))
	) dma_fifo(
		.i_reset(i_reset),
        .i_clock(i_clock),
        .o_empty(dma_fifo_empty),
		.o_almost_full(dma_fifo_full),
		.i_write(i_dma_setup_request),
		.i_wdata(dma_command_t'({ i_dma_setup_address, i_dma_setup_count })),
		.i_read(dma_fifo_rd),
		.o_rdata(dma_fifo_rcmd),
		.o_queued()
	);

	// Sample FIFO.
	wire sample_fifo_empty;
	wire sample_fifo_full;
	bit sample_fifo_wr = 1'b0;
	bit sample_fifo_rd = 1'b0;
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
		.i_wdata(i_dma_rdata),
		.i_read(sample_fifo_rd),
		.o_rdata(sample_fifo_rdata),
		.o_queued()
	);

	bit [31:0] dma_address;
	bit [31:0] dma_count = 0;

	initial begin
		o_dma_request = 1'b0;
		o_busy = 1'b0;
		o_output_sample_left = 0;
		o_output_sample_right = 0;
	end

	// Channel is only busy when DMA command FIFO is full.
	always_comb begin
		o_busy = dma_fifo_full;
	end

	// Process DMA setup and read samples into FIFO.
	always_ff @(posedge i_clock) begin
		o_dma_request <= 1'b0;
		sample_fifo_wr <= 1'b0;

		// Read DMA command from DMA FIFO.
		if (dma_fifo_rd) begin
			dma_address <= dma_fifo_rcmd.address;
			dma_count <= dma_fifo_rcmd.count;
			dma_fifo_rd <= 1'b0;
		end
		else if (!|dma_count && !dma_fifo_empty) begin
			dma_fifo_rd <= 1'b1;
		end

		// Process DMA command; ie reading samples from BUS and inserting into sample FIFO.
		if (!sample_fifo_full && |dma_count) begin
			o_dma_request <= 1'b1;
			o_dma_address <= dma_address;
			if (i_dma_ready) begin
				sample_fifo_wr <= 1'b1;
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
