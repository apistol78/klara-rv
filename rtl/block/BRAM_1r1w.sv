/*
 Klara-RTL
 Copyright (c) 2025 Anders Pistol.

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at https://mozilla.org/MPL/2.0/.
*/

`timescale 1ns/1ns
`default_nettype none

module BRAM_1r1w #(
	parameter WIDTH = 32,
	parameter SIZE = 32'h400,
	parameter ADDR_LSH = 2
)(
	input wire i_clock,

    // Port A (read)
	input wire i_pa_request,
	input wire [31:0] i_pa_address,
	output bit [WIDTH - 1:0] o_pa_rdata,
	output bit o_pa_ready,

    // Port B (write)
	input wire i_pb_request,
	input wire [31:0] i_pb_address,
	input wire [WIDTH - 1:0] i_pb_wdata,
	output bit o_pb_ready
);
    (* ram_style = "block" *)
	bit [WIDTH - 1:0] data [0:SIZE - 1];

	initial begin
        o_pa_ready = 0;
		o_pa_rdata = 0;
        o_pb_ready = 0;
    end

	always_ff @(posedge i_clock) begin
		o_pa_ready <= 1'b0;
		o_pb_ready <= 1'b0;
		if (i_pa_request) begin
			o_pa_rdata <= data[i_pa_address >> ADDR_LSH];
			o_pa_ready <= 1'b1;
		end
		if (i_pb_request) begin
			data[i_pb_address >> ADDR_LSH] <= i_pb_wdata;
			o_pb_ready <= 1'b1;
		end
	end

endmodule