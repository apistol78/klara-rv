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

module CPU_DCache_WB(
	input wire i_reset,
	input wire i_clock,

	// Bus
	output bit o_bus_rw,
	output bit o_bus_request,
	input wire i_bus_ready,
	output bit [31:0] o_bus_address,
	input wire [31:0] i_bus_rdata,
	output bit [31:0] o_bus_wdata,
	output bit [3:0] o_bus_wmask,

	// Input
	input wire i_rw,
	input wire i_request,
	output bit o_ready,
	input wire [31:0] i_address,
	output bit [31:0] o_rdata,
	input wire [31:0] i_wdata,
	input wire [3:0] i_wmask,
	input wire i_cached,

	output wire o_pending
);

	WriteBuffer #(
		.DEPTH(8),
		.ADDRESS_WIDTH(32),
		.STALL_READ(1)
	) wb (
		.i_reset(i_reset),
		.i_clock(i_clock),
		
		.o_empty(),
		.o_full(),
		
		.o_bus_rw(o_bus_rw),
		.o_bus_request(o_bus_request),
		.i_bus_ready(i_bus_ready),
		.o_bus_address(o_bus_address),
		.i_bus_rdata(i_bus_rdata),
		.o_bus_wdata(o_bus_wdata),
		.o_bus_wmask(o_bus_wmask),

		.i_rw(i_rw),
		.i_request(i_request),
		.o_ready(o_ready),
		.i_address(i_address),
		.o_rdata(o_rdata),
		.i_wdata(i_wdata),
		.i_wmask(i_wmask)
	);

endmodule
