/*
 Klara-RTL
 Copyright (c) 2025 Anders Pistol.

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at https://mozilla.org/MPL/2.0/.
*/

`timescale 1ns/1ns
`default_nettype none

module FIFO_BRAM #(
	parameter DEPTH = 128,
	parameter WIDTH = 8
)(
	input wire i_reset,
	input wire i_clock,

	output wire o_empty,
	output wire o_full,

	input wire i_write,
	input wire [WIDTH-1:0] i_wdata,

	input wire i_read,
	output wire [WIDTH-1:0] o_rdata,

	output wire [$clog2(DEPTH) - 1:0] o_queued
);
	localparam DB = $clog2(DEPTH) - 1;

	bit [DB:0] r_in = 0;
	bit [DB:0] r_out = 0;

	BRAM_1r1w #(
		.WIDTH(WIDTH),
		.SIZE(DEPTH),
		.ADDR_LSH(0)
	) bram(
		.i_clock(i_clock),

		.i_pa_request(i_read),
		.i_pa_address(r_out),
		.o_pa_rdata(o_rdata),
		.o_pa_ready(),

		.i_pb_request(i_write),
		.i_pb_address(r_in),
		.i_pb_wdata(i_wdata),
		.o_pb_ready()
	);

	assign o_empty = (r_in == r_out) ? 1'b1 : 1'b0;
	assign o_full = (((r_in + 1) & (DEPTH - 1)) == r_out) ? 1'b1 : 1'b0;
	assign o_queued = (r_in >= r_out) ? r_in - r_out : (DEPTH - r_out) + r_in;

	always_ff @ (posedge i_clock) begin
		if (!i_reset) begin
			if (i_write) begin
				r_in <= (r_in + 1) & (DEPTH - 1);
			end
			if (i_read) begin
				r_out <= (r_out + 1) & (DEPTH - 1);
			end
		end
		else begin
			r_in <= 0;
			r_out <= 0;
		end
	end

endmodule
