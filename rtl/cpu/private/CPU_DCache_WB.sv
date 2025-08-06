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
	input [31:0] i_wdata,
	input i_cached
);

	bit wb_dirty [4];
	bit [31:0] wb_address [4];
	bit [31:0] wb_data [4];

	bit next_wb_dirty [4];
	bit [31:0] next_wb_address [4];
	bit [31:0] next_wb_data [4];

	wire debug_wb_dirty0 = wb_dirty[0];
	wire debug_wb_dirty1 = wb_dirty[1];
	wire debug_wb_dirty2 = wb_dirty[2];
	wire debug_wb_dirty3 = wb_dirty[3];

	initial begin
		integer i;
		for (i = 0; i < 4; i = i + 1) begin
			wb_dirty[i] = 1'b0;
			wb_address[i] = 32'h0;
			wb_data[i] = 32'h0;
		end
	end

	always_ff @(posedge i_clock) begin
		integer i;
		for (i = 0; i < 4; i = i + 1) begin
			wb_dirty[i] <= next_wb_dirty[i];
			wb_address[i] <= next_wb_address[i];
			wb_data[i] <= next_wb_data[i];
		end
	end

	wire all_dirty = wb_dirty[0] & wb_dirty[1] & wb_dirty[2] & wb_dirty[3];
	wire any_dirty = wb_dirty[0] | wb_dirty[1] | wb_dirty[2] | wb_dirty[3];

	always_comb begin
		integer i;
		for (i = 0; i < 4; i = i + 1) begin
			next_wb_dirty[i] = wb_dirty[i];
			next_wb_address[i] = wb_address[i];
			next_wb_data[i] = wb_data[i];
		end

		o_bus_rw = 0;
		o_bus_request = 0;
		o_bus_address = 0;
		o_bus_wdata = 0;

		o_rdata = i_bus_rdata;
		o_ready = 0;
		
		// Read request; cannot have any queued writes.
		if (i_request && !i_rw && !any_dirty) begin
			o_bus_rw = 1'b0;
			o_bus_request = 1'b1;
			o_bus_address = i_address;
			o_ready = i_bus_ready;
		end
		// Non-cached write request; cannot have any queued writes.
		else if (i_request && i_rw && !i_cached && !any_dirty) begin
			o_bus_rw = 1'b1;
			o_bus_request = 1'b1;
			o_bus_address = i_address;
			o_bus_wdata = i_wdata;
			o_ready = i_bus_ready;
		end
		// Cached write request; need to have at least one slot free.
		else if (i_request && i_rw && i_cached && !all_dirty) begin
			if (!wb_dirty[0]) begin
				next_wb_address[0] = i_address;
				next_wb_data[0] = i_wdata;
				next_wb_dirty[0] = 1'b1;
			end
			else if (!wb_dirty[1]) begin
				next_wb_address[1] = i_address;
				next_wb_data[1] = i_wdata;
				next_wb_dirty[1] = 1'b1;
			end
			else if (!wb_dirty[2]) begin
				next_wb_address[2] = i_address;
				next_wb_data[2] = i_wdata;
				next_wb_dirty[2] = 1'b1;
			end
			else if (!wb_dirty[3]) begin
				next_wb_address[3] = i_address;
				next_wb_data[3] = i_wdata;
				next_wb_dirty[3] = 1'b1;
			end
			o_ready = 1'b1;
		end
		// No request; flush queued writes.
		else if (wb_dirty[0]) begin
			o_bus_rw = 1'b1;
			o_bus_request = 1'b1;
			o_bus_address = wb_address[0];
			o_bus_wdata = wb_data[0];
			if (i_bus_ready) begin
				next_wb_dirty[0] = 1'b0;
			end
		end
		else if (wb_dirty[1]) begin
			o_bus_rw = 1'b1;
			o_bus_request = 1'b1;
			o_bus_address = wb_address[1];
			o_bus_wdata = wb_data[1];
			if (i_bus_ready) begin
				next_wb_dirty[1] = 1'b0;
			end
		end
		else if (wb_dirty[2]) begin
			o_bus_rw = 1'b1;
			o_bus_request = 1'b1;
			o_bus_address = wb_address[2];
			o_bus_wdata = wb_data[2];
			if (i_bus_ready) begin
				next_wb_dirty[2] = 1'b0;
			end
		end
		else if (wb_dirty[3]) begin
			o_bus_rw = 1'b1;
			o_bus_request = 1'b1;
			o_bus_address = wb_address[3];
			o_bus_wdata = wb_data[3];
			if (i_bus_ready) begin
				next_wb_dirty[3] = 1'b0;
			end
		end

	end

endmodule
