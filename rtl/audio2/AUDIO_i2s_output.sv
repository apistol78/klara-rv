/*
 Klara-RTL
 Copyright (c) 2025 Anders Pistol.

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at https://mozilla.org/MPL/2.0/.
*/

`timescale 1ns/1ns
`default_nettype none

module AUDIO_i2s_output #(
	parameter FREQUENCY = 100_000_000
)(
	input wire i_clock,

	output bit o_sample_clock,
	input wire [31:0] i_sample_rate,
	input wire [15:0] i_sample_left,
	input wire [15:0] i_sample_right,

	output bit o_i2s_sdout,
	output bit o_i2s_sclk,
	output bit o_i2s_lrck,
	output bit o_i2s_mclk
);
	// Number of "extra" bits to ensure word clock match the sample rate.
	localparam EXTRA = 20;

	// Generate MCLK.
	bit mclk = 1'b0;
	bit [15:0] mclk_counter = 0;

	always_ff @(posedge i_clock) begin
		mclk_counter <= mclk_counter + 1;
		// if (mclk_counter >= 3) begin
		if (mclk_counter >= 7) begin
			mclk <= ~mclk;
			mclk_counter <= 0;
		end
	end

	// Generate SCLK from MCLK.
	bit [5:0] sclk_counter = 0;
	bit lmclk = 1'b0;

	// wire sclk = sclk_counter[0];	// ~44100
	wire sclk = sclk_counter[1];	// ~22050

	always_ff @(posedge i_clock) begin
		if ({mclk, lmclk} == 2'b10) begin
			sclk_counter <= sclk_counter + 1;
		end
		lmclk <= mclk;
	end

	// Output signal.
	bit [2:0] mclk_pp = 3'b000;
	bit [2:0] sclk_pp = 3'b000;
	bit [15:0] bitcnt = 0;
	bit lrck = 0;
	bit [15:0] sample = 0;
	bit sdout = 0;
	bit [1:0] busy = 2'b00;

	assign o_i2s_mclk = mclk_pp[2];
	assign o_i2s_sclk = sclk_pp[1];
	assign o_i2s_lrck = lrck;
	assign o_i2s_sdout = sdout;
	// assign o_busy = busy[0];

	initial begin
		o_sample_clock = 1'b0;
	end

	always_ff @(posedge i_clock) begin
		// busy <= { busy[0], 1'b1 };

		mclk_pp <= { mclk_pp[1:0], mclk };
		sclk_pp <= { sclk_pp[1:0], sclk };

		if (sclk_pp[1:0] == 2'b10) begin
			sdout <= sample[15];
			sample <= { sample[14:0], 1'b0 };

			bitcnt <= bitcnt + 1;

			// Swap channel.
			if (bitcnt == 16 - 1 + EXTRA) begin
				lrck <= ~lrck;
				sample <= i_sample_right;
			end
			// End transmission.
			else if (bitcnt == 32 - 1 + EXTRA * 2) begin
				lrck <= ~lrck;
				bitcnt <= 0;
				sample <= i_sample_left;
				// busy[0] <= 1'b0;
				o_sample_clock <= ~o_sample_clock;
			end
		end
	end

endmodule
