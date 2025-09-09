/*
 Klara-RV
 Copyright (c) 2025 Anders Pistol.

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at https://mozilla.org/MPL/2.0/.
*/
`include "CPU_Defines.sv"

`timescale 1ns/1ns
`default_nettype none

module CPU_BRAM #(
	parameter ADDRESS_WIDTH = 32,
	parameter DATA_WIDTH = 32,
	parameter SIZE = 32'h400,
	parameter ADDR_LSH = 2
)(
	input wire i_clock,
	input wire i_request,
	input wire i_rw,
	input wire [ADDRESS_WIDTH - 1:0] i_address,
	input wire [DATA_WIDTH - 1:0] i_wdata,
	output bit [DATA_WIDTH - 1:0] o_rdata,
	output bit o_ready,
	output bit o_valid
);
    (* ram_style = "block" *)
	bit [DATA_WIDTH - 1:0] data [0:SIZE - 1];

	initial begin
		o_ready = 0;
		o_valid = 1;
	end

	always_ff @(posedge i_clock) begin
		if (i_request) begin
			o_valid <= (i_address >> ADDR_LSH) < SIZE;
			if (!i_rw) begin
				o_rdata <= data[i_address >> ADDR_LSH];
			end
			else begin
				data[i_address >> ADDR_LSH] <= i_wdata;
			end
		end
	end

	always_ff @(posedge i_clock)
		o_ready <= i_request;

endmodule