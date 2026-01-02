/*
 Klara-RTL
 Copyright (c) 2025 Anders Pistol.

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at https://mozilla.org/MPL/2.0/.
*/

`timescale 1ns/1ns
`default_nettype none

module AUDIO_controller_2(
	input wire i_reset,
	input wire i_clock,

	// CPU interface.
	input wire i_request,
	input wire i_rw,
	input wire [7:0] i_address,
	input wire [31:0] i_wdata,
	output bit [31:0] o_rdata,
	output bit o_ready,

	// DMA bus master
	output bit o_dma_request,
	output bit [31:0] o_dma_address,
	input wire i_dma_ready,
	input wire [31:0] i_dma_rdata,

	// Audio output
	input wire i_output_sample_clock,
	output bit [31:0] o_output_sample_rate,
	output bit [15:0] o_output_sample_left,
	output bit [15:0] o_output_sample_right
);

	initial begin
		o_ready = 1'b0;
		o_dma_request = 1'b0;
		o_output_sample_rate = 100_000_000 / (256 * 22050);
		o_output_sample_left = 16'd0;
		o_output_sample_right = 16'd0;
	end

	// Channel 0
	bit ch0_dma_setup_request = 1'b0;
	bit ch0_dma_setup_append_or_replace = 1'b0;
	bit ch0_dma_setup_mono_or_stereo = 1'b0;
	bit [23:0] ch0_dma_setup_count;
	bit [31:0] ch0_dma_setup_address;

	wire ch0_dma_request;
	wire [31:0] ch0_dma_address;
	bit ch0_dma_ready;

	wire ch0_busy;

	bit [3:0] ch0_volume = 4'hf;
	bit [15:0] ch0_sample_left;
	bit [15:0] ch0_sample_right;

	AUDIO_channel ch0(
		.i_reset(i_reset),
		.i_clock(i_clock),

		.i_dma_setup_request(ch0_dma_setup_request),
		.i_dma_setup_append_or_replace(ch0_dma_setup_append_or_replace),
		.i_dma_setup_mono_or_stereo(ch0_dma_setup_mono_or_stereo),
		.i_dma_setup_count(ch0_dma_setup_count),
		.i_dma_setup_address(ch0_dma_setup_address),

		.o_dma_request(ch0_dma_request),
		.o_dma_address(ch0_dma_address),
		.i_dma_ready(ch0_dma_ready),
		.i_dma_rdata(i_dma_rdata),

		.o_busy(ch0_busy),

		.i_volume(ch0_volume),

		.i_output_sample_clock(i_output_sample_clock),
		.o_output_sample_left(ch0_sample_left),
		.o_output_sample_right(ch0_sample_right)
	);

	// Channel 1
	bit ch1_dma_setup_request = 1'b0;
	bit ch1_dma_setup_append_or_replace = 1'b0;
	bit ch1_dma_setup_mono_or_stereo = 1'b0;
	bit [23:0] ch1_dma_setup_count;
	bit [31:0] ch1_dma_setup_address;

	wire ch1_dma_request;
	wire [31:0] ch1_dma_address;
	bit ch1_dma_ready;

	wire ch1_busy;

	bit [3:0] ch1_volume = 4'hf;
	bit [15:0] ch1_sample_left;
	bit [15:0] ch1_sample_right;

	AUDIO_channel ch1(
		.i_reset(i_reset),
		.i_clock(i_clock),

		.i_dma_setup_request(ch1_dma_setup_request),
		.i_dma_setup_append_or_replace(ch1_dma_setup_append_or_replace),
		.i_dma_setup_mono_or_stereo(ch1_dma_setup_mono_or_stereo),
		.i_dma_setup_count(ch1_dma_setup_count),
		.i_dma_setup_address(ch1_dma_setup_address),

		.o_dma_request(ch1_dma_request),
		.o_dma_address(ch1_dma_address),
		.i_dma_ready(ch1_dma_ready),
		.i_dma_rdata(i_dma_rdata),

		.o_busy(ch1_busy),

		.i_volume(ch1_volume),

		.i_output_sample_clock(i_output_sample_clock),
		.o_output_sample_left(ch1_sample_left),
		.o_output_sample_right(ch1_sample_right)
	);

	// CPU register access.
	wire [31:0] channels_busy =
	{
		30'h0,
		ch1_busy,
		ch0_busy
	};

	always_ff @(posedge i_clock) begin

		ch0_dma_setup_request <= 1'b0;
		ch1_dma_setup_request <= 1'b0;

		if (i_request && !o_ready) begin
			if (!i_rw) begin
				case (i_address)
					8'h00: begin
						o_rdata <= o_output_sample_rate;
						o_ready <= 1'b1;
					end
					8'h01: begin
						o_rdata <= channels_busy;
						o_ready <= 1'b1;
					end
					default:
						o_ready <= 1'b1;
				endcase
			end
			else begin
				case (i_address)
					8'h00: begin
						ch0_dma_setup_address <= i_wdata;
						o_ready <= 1'b1;
					end
					8'h01: begin
						ch0_dma_setup_count <= i_wdata[23:0];
						ch0_dma_setup_append_or_replace <= i_wdata[28];
						ch0_dma_setup_mono_or_stereo <= i_wdata[29];
						ch0_dma_setup_request <= 1'b1;
						o_ready <= 1'b1;
					end
					8'h02: begin
						ch0_volume <= i_wdata[3:0];
						o_ready <= 1'b1;
					end
					8'h04: begin
						ch1_dma_setup_address <= i_wdata;
						o_ready <= 1'b1;
					end
					8'h05: begin
						ch1_dma_setup_count <= i_wdata[23:0];
						ch1_dma_setup_append_or_replace <= i_wdata[28];
						ch1_dma_setup_mono_or_stereo <= i_wdata[29];
						ch1_dma_setup_request <= 1'b1;
						o_ready <= 1'b1;
					end
					8'h06: begin
						ch1_volume <= i_wdata[3:0];
						o_ready <= 1'b1;
					end

					8'hf0: begin
						o_output_sample_rate <= i_wdata;
						o_ready <= 1'b1;
					end
					default:
						o_ready <= 1'b1;
				endcase
			end
		end
		else if (!i_request) begin
			o_ready <= 1'b0;
		end
	end

	// DMA round robin scheduler
	bit [3:0] sched_channel = 0;

	always_comb begin
		ch0_dma_ready = ch0_dma_request & i_dma_ready;
		ch1_dma_ready = ch1_dma_request & i_dma_ready;
	end

	always_ff @(posedge i_clock) begin
		o_dma_request <= 1'b0;

		if (sched_channel == 0) begin
			if (ch0_dma_request) begin
				o_dma_request <= 1'b1;
				o_dma_address <= ch0_dma_address;
			end
			else
				sched_channel <= (sched_channel + 1) & 1;
		end
		else if (sched_channel == 1) begin
			if (ch1_dma_request) begin
				o_dma_request <= 1'b1;
				o_dma_address <= ch1_dma_address;
			end
			else
				sched_channel <= (sched_channel + 1) & 1;
		end
	end

	// Mixer
	always_ff @(posedge i_clock) begin
		o_output_sample_left <= $signed(ch0_sample_left) + $signed(ch1_sample_left);
		o_output_sample_right <= $signed(ch0_sample_right) + $signed(ch1_sample_right);
	end

endmodule

