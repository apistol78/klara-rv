/*
 Klara-RV
 Copyright (c) 2025 Anders Pistol.

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at https://mozilla.org/MPL/2.0/.
*/
`include "CPU_Defines.sv"

`timescale 1ns/1ns

module CPU_DCache_WB(
	input i_reset,
	input i_clock,

	// Bus
	output bit o_bus_rw,
	output bit o_bus_request,
	input i_bus_ready,
	output bit [31:0] o_bus_address,
	input [31:0] i_bus_rdata,
	output bit [31:0] o_bus_wdata,

	// Input
	input i_rw,
	input i_request,
	output bit o_ready,
	input [31:0] i_address,
	output bit [31:0] o_rdata,
	input [31:0] i_wdata
);

	bit wb_dirty = 1'b0;
	bit [31:0] wb_address = 0;
	bit [31:0] wb_data = 0;

	bit next_wb_dirty = 1'b0;
	bit [31:0] next_wb_address = 0;
	bit [31:0] next_wb_data = 0;

	always_ff @(posedge i_clock) begin
		wb_dirty <= next_wb_dirty;
		wb_address <= next_wb_address;
		wb_data <= next_wb_data;
	end

	always_comb begin

		next_wb_dirty = wb_dirty;
		next_wb_address = wb_address;
		next_wb_data = wb_data;

		o_bus_rw = 0;
		o_bus_address = 0;
		o_bus_request = 0;
		o_bus_wdata = wb_data;

		o_rdata = i_bus_rdata;
		o_ready = 0;
		
		if (wb_dirty) begin
			o_bus_rw = 1'b1;
			o_bus_address = wb_address;
			o_bus_request = 1'b1;
			if (i_bus_ready) begin
				next_wb_dirty = 1'b0;
			end
		end
		else if (i_request) begin
			if (i_rw == 1'b0) begin
				o_bus_rw = 1'b0;
				o_bus_address = i_address;
				o_bus_request = 1'b1;
				o_ready = i_bus_ready;
			end
			else begin
				next_wb_address = i_address;
				next_wb_data = i_wdata;
				next_wb_dirty = 1'b1;
				o_ready = 1'b1;
			end
		end

	end

endmodule
