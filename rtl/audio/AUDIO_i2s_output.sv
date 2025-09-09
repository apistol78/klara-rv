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

	output bit o_busy,
	input wire [15:0] i_sample_left,
	input wire [15:0] i_sample_right,

	output bit o_i2s_sdout,
	output bit o_i2s_sclk,
	output bit o_i2s_lrck,
	output bit o_i2s_mclk
);

	wire mclk;

	ClockDivider #(
		.CLOCK_RATE(FREQUENCY),
		.BAUD_RATE(256 * 22050 /*44100*/)
	) mclk_div(
		.i_reset(1'b0),
		.i_clock(i_clock),
		.o_clock(mclk)
	);

	wire sclk;

	ClockDivider #(
		.CLOCK_RATE(18), 
		.BAUD_RATE(3)
	) sclk_div(
		.i_reset(1'b0),
		.i_clock(mclk),
		.o_clock(sclk)
	);

	bit [1:0] sclk_pp = 2'b00;
	bit [4:0] bitcnt = 0;
	bit lrck = 0;
	bit [31:0] sample = 0;
	bit sdout = 0;
	bit [1:0] busy = 2'b00;

	assign o_i2s_mclk = mclk;
	assign o_i2s_sclk = sclk_pp[1];
	assign o_i2s_lrck = lrck;
	assign o_i2s_sdout = sdout;
	assign o_busy = busy[0];

	always_ff @(posedge i_clock) begin
		busy <= { busy[0], 1'b1 };

		sclk_pp <= { sclk_pp[0], sclk };
		if (sclk_pp == 2'b10) begin
			sdout <= sample[31];
			sample <= { sample[30:0], 1'b0 };

			bitcnt <= bitcnt + 1;

			// Swap channel.
			if (bitcnt == 16 - 1)
				lrck <= ~lrck;

			// End transmission.
			else if (bitcnt == 32 - 1) begin
				bitcnt <= 0;
				busy[0] <= 1'b0;
			end
		end

		if (busy == 2'b01)
			sample <= { i_sample_left, i_sample_right };
	end

endmodule
