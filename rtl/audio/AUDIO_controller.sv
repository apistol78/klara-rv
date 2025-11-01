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
module AUDIO_controller #(
	parameter BUFFER_SIZE = 16
)(
	input wire i_reset,
	input wire i_clock,

	// CPU interface.
	input wire i_request,
	input wire i_rw,
	input wire [3:0] i_address,
	input wire [31:0] i_wdata,
	output bit [31:0] o_rdata,
	output bit o_ready,

	// Audio output
	input wire i_output_sample_clock,
	output bit [31:0] o_output_sample_rate,
	output wire [15:0] o_output_sample_left,
	output wire [15:0] o_output_sample_right
);
	// Sample FIFO.
    wire output_fifo_empty;
	wire output_fifo_full;
	bit output_fifo_wr = 0;
	bit output_fifo_rd = 0;
	wire [31:0] output_sample;
	wire [$clog2(BUFFER_SIZE)-1:0] output_fifo_queued;
	FIFO_BRAM #(
		.DEPTH(BUFFER_SIZE),
		.WIDTH(32)
	) output_fifo(
		.i_reset(i_reset),
        .i_clock(i_clock),
        .o_empty(output_fifo_empty),
		.o_full(output_fifo_full),
		.i_write(output_fifo_wr),
		.i_wdata(i_wdata),
		.i_read(output_fifo_rd),
		.o_rdata(output_sample),
		.o_queued(output_fifo_queued)
	);

	assign o_output_sample_left = output_sample[31:16];
	assign o_output_sample_right = output_sample[15:0];

    initial begin
		o_ready = 0;
		o_output_sample_rate = 100_000_000 / (256 * 22050);
	end

	always_ff @(posedge i_clock) begin
		output_fifo_wr <= 1'b0;
		if (i_request && !o_ready) begin
			if (!i_rw) begin
				case (i_address)
					4'h0: begin
						o_rdata <= output_fifo_queued;
						o_ready <= 1'b1;
					end
					4'h1: begin
						o_rdata <= o_output_sample_rate;
						o_ready <= 1'b1;
					end
					default:
						o_ready <= 1'b1;
				endcase
			end
			else begin
				case (i_address)
					4'h0: begin
						if (!output_fifo_full) begin
							output_fifo_wr <= 1;
							o_ready <= 1'b1;
						end
					end
					4'h1: begin
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

	// Read new sample from FIFO whenever sample clock change.
	bit last_sample_clock = 1'b0;
	always_ff @(posedge i_clock) begin
		output_fifo_rd <= 1'b0;
		last_sample_clock <= i_output_sample_clock;
		if (i_output_sample_clock != last_sample_clock && !output_fifo_empty) begin
			output_fifo_rd <= 1'b1;
		end
	end

endmodule
