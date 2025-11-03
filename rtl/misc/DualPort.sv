/*
 Klara-RTL
 Copyright (c) 2025 Anders Pistol.

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at https://mozilla.org/MPL/2.0/.
*/

`timescale 1ns/1ns
`default_nettype none

module DualPort(
	input wire i_reset,
	input wire i_clock,

	// Bus
	output bit o_bus_rw,				// Data read/write
	output bit o_bus_request,			// IO request.
	input wire i_bus_ready,				// IO request ready.
	output bit [31:0] o_bus_address,	// Address
	input wire [31:0] i_bus_rdata,		// Read data
	output bit [31:0] o_bus_wdata,		// Write data
	output bit [3:0] o_bus_wmask,		// Write mask

	// Port A
	input wire i_pa_rw,
	input wire i_pa_request,
	output bit o_pa_ready,
	input wire [31:0] i_pa_address,
	output bit [31:0] o_pa_rdata,
	input wire [31:0] i_pa_wdata,
	input wire [3:0] i_pa_wmask,

	// Port B
	input wire i_pb_rw,
	input wire i_pb_request,
	output bit o_pb_ready,
	input wire [31:0] i_pb_address,
	output bit [31:0] o_pb_rdata,
	input wire [31:0] i_pb_wdata,
	input wire [3:0] i_pb_wmask,

	// Port C
	input wire i_pc_rw,
	input wire i_pc_request,
	output bit o_pc_ready,
	input wire [31:0] i_pc_address,
	output bit [31:0] o_pc_rdata,
	input wire [31:0] i_pc_wdata,
	input wire [3:0] i_pc_wmask
);

	bit [2:0] state = 0;
	bit [2:0] next_state;

	assign o_pa_ready = i_pa_request && (state == 3'd1) ? i_bus_ready : 1'b0;
	assign o_pb_ready = i_pb_request && (state == 3'd2) ? i_bus_ready : 1'b0;
	assign o_pc_ready = i_pc_request && (state == 3'd3) ? i_bus_ready : 1'b0;

	assign o_pa_rdata = i_bus_rdata;
	assign o_pb_rdata = i_bus_rdata;
	assign o_pc_rdata = i_bus_rdata;

	always_ff @(posedge i_clock) begin
		state <= next_state;
	end

	always_comb begin

		next_state = state;

		o_bus_request = 1'b0;
		o_bus_rw = 1'b0;
		o_bus_address = 0;
		o_bus_wdata = 0;
		o_bus_wmask = 4'b0000;
		
		unique case (state)

			// Wait for any request.
			3'd0: begin
				if (i_pa_request) begin
					o_bus_rw = i_pa_rw;
					o_bus_address = i_pa_address;
					o_bus_wdata = i_pa_wdata;
					o_bus_wmask = i_pa_wmask;
					next_state = 3'd1;
				end
				else if (i_pb_request) begin
					o_bus_rw = i_pb_rw;
					o_bus_address = i_pb_address;
					o_bus_wdata = i_pb_wdata;
					o_bus_wmask = i_pb_wmask;
					next_state = 3'd2;
				end
				else if (i_pc_request) begin
					o_bus_rw = i_pc_rw;
					o_bus_address = i_pc_address;
					o_bus_wdata = i_pc_wdata;
					o_bus_wmask = i_pc_wmask;
					next_state = 3'd3;
				end					
			end

			// Wait until request has been processed.
			3'd1: begin
				o_bus_request = i_pa_request;
				o_bus_rw = i_pa_rw;
				o_bus_address = i_pa_address;
				o_bus_wdata = i_pa_wdata;
				o_bus_wmask = i_pa_wmask;
				if (i_bus_ready) begin
					next_state = 3'd0;
				end
			end
			3'd2: begin
				o_bus_request = i_pb_request;
				o_bus_rw = i_pb_rw;
				o_bus_address = i_pb_address;
				o_bus_wdata = i_pb_wdata;
				o_bus_wmask = i_pb_wmask;
				if (i_bus_ready) begin
					next_state = 3'd0;
				end
			end
			3'd3: begin
				o_bus_request = i_pc_request;
				o_bus_rw = i_pc_rw;
				o_bus_address = i_pc_address;
				o_bus_wdata = i_pc_wdata;
				o_bus_wmask = i_pc_wmask;
				if (i_bus_ready) begin
					next_state = 3'd0;
				end
			end

			default:
				next_state = 3'd0;

		endcase
	end

endmodule
