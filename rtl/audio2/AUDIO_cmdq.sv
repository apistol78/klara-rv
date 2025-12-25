/*
 Klara-RTL
 Copyright (c) 2025 Anders Pistol.

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at https://mozilla.org/MPL/2.0/.
*/

`timescale 1ns/1ns
`default_nettype none

module AUDIO_cmdq(
	input wire i_reset,
	input wire i_clock,

	input wire i_setup_request,
	input wire i_setup_append_or_replace,
	input wire i_setup_mono_or_stereo,
	input wire [31:0] i_setup_address,
	input wire [23:0] i_setup_count,

	input wire i_next_ready,
	output bit o_next_have,
	output bit o_next_mono_or_stereo,
	output bit [31:0] o_next_address,
	output bit [23:0] o_next_count,

	output bit o_next_queued
);

	initial o_next_have = 1'b0;

	bit next_mono_or_stereo = 1'b0;
	bit [31:0] next_address = 32'h0;
	bit [23:0] next_count = 24'h0;
	bit next_pending = 1'b0;

	always_comb begin
		o_next_queued = next_pending;
	end

	always_ff @(posedge i_clock) begin

		o_next_have <= 1'b0;

		if (i_next_ready && next_pending) begin
			o_next_mono_or_stereo <= next_mono_or_stereo;
			o_next_address <= next_address;
			o_next_count <= next_count;
			o_next_have <= 1'b1;
			next_pending <= 1'b0;
		end

		if (i_setup_request) begin
			if (i_setup_append_or_replace == 1'b0) begin
				// Append as next.
				next_mono_or_stereo <= i_setup_mono_or_stereo;
				next_address <= i_setup_address;
				next_count <= i_setup_count;
				next_pending <= 1'b1;
			end
			else begin
				// Replace current.
				o_next_mono_or_stereo <= i_setup_mono_or_stereo;
				o_next_address <= i_setup_address;
				o_next_count <= i_setup_count;
				o_next_have <= 1'b1;
				next_pending <= 1'b0;
			end
		end
	end

endmodule
