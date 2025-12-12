/*
 Klara-RTL
 Copyright (c) 2025 Anders Pistol.

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at https://mozilla.org/MPL/2.0/.
*/

`timescale 1ns/1ns
`default_nettype none

module DMA #(
	parameter QUEUE_DEPTH = 4
) (
	input wire i_reset,
	input wire i_clock,

	input wire i_request,
	input wire i_rw,
	input wire [27:0] i_address,
	input wire [31:0] i_wdata,
	output bit [31:0] o_rdata,
	output bit o_ready,

	// Bus
	output bit o_bus_rw,				// Data read/write
	output bit o_bus_request,			// IO request.
	input wire i_bus_ready,				// IO request ready.
	output bit [31:0] o_bus_address,	// Address
	input wire [31:0] i_bus_rdata,		// Read data
	output bit [31:0] o_bus_wdata		// Write data,
);

	wire dma_ch0_request = (i_address[27:24] == 4'h0 && i_request);
	wire dma_ch1_request = (i_address[27:24] == 4'h1 && i_request);
	wire dma_ch2_request = (i_address[27:24] == 4'h2 && i_request);

	wire dma_ch0_ready;
	wire dma_ch1_ready;
	wire dma_ch2_ready;

	wire [31:0] dma_ch0_rdata;
	wire [31:0] dma_ch1_rdata;
	wire [31:0] dma_ch2_rdata;

	always_comb begin
		o_ready = 
			(dma_ch0_request && dma_ch0_ready) ||
			(dma_ch1_request && dma_ch1_ready) ||
			(dma_ch2_request && dma_ch2_ready);

		o_rdata =
			dma_ch0_request ? dma_ch0_rdata :
			dma_ch1_request ? dma_ch1_rdata :
			dma_ch2_request ? dma_ch2_rdata :
			0;
	end

	wire dma_ch0_bus_rw;
	wire dma_ch0_bus_request;
	wire dma_ch0_bus_ready;
	wire [31:0] dma_ch0_bus_address;
	wire [31:0] dma_ch0_bus_rdata;
	wire [31:0] dma_ch0_bus_wdata;

	DMA_channel #(
		.QUEUE_DEPTH(QUEUE_DEPTH)
	) dma_ch0 (
		.i_reset(i_reset),
		.i_clock(i_clock),

		.i_request(dma_ch0_request),
		.i_rw(i_rw),
		.i_address(i_address[3:2]),
		.i_wdata(i_wdata),
		.o_rdata(dma_ch0_rdata),
		.o_ready(dma_ch0_ready),

		.o_bus_rw(dma_ch0_bus_rw),
		.o_bus_request(dma_ch0_bus_request),
		.i_bus_ready(dma_ch0_bus_ready),
		.o_bus_address(dma_ch0_bus_address),
		.i_bus_rdata(dma_ch0_bus_rdata),
		.o_bus_wdata(dma_ch0_bus_wdata)
	);

	wire dma_ch1_bus_rw;
	wire dma_ch1_bus_request;
	wire dma_ch1_bus_ready;
	wire [31:0] dma_ch1_bus_address;
	wire [31:0] dma_ch1_bus_rdata;
	wire [31:0] dma_ch1_bus_wdata;

	DMA_channel #(
		.QUEUE_DEPTH(QUEUE_DEPTH)
	) dma_ch1 (
		.i_reset(i_reset),
		.i_clock(i_clock),

		.i_request(dma_ch1_request),
		.i_rw(i_rw),
		.i_address(i_address[3:2]),
		.i_wdata(i_wdata),
		.o_rdata(dma_ch1_rdata),
		.o_ready(dma_ch1_ready),

		.o_bus_rw(dma_ch1_bus_rw),
		.o_bus_request(dma_ch1_bus_request),
		.i_bus_ready(dma_ch1_bus_ready),
		.o_bus_address(dma_ch1_bus_address),
		.i_bus_rdata(dma_ch1_bus_rdata),
		.o_bus_wdata(dma_ch1_bus_wdata)
	);

	wire dma_ch2_bus_rw;
	wire dma_ch2_bus_request;
	wire dma_ch2_bus_ready;
	wire [31:0] dma_ch2_bus_address;
	wire [31:0] dma_ch2_bus_rdata;
	wire [31:0] dma_ch2_bus_wdata;

	DMA_channel #(
		.QUEUE_DEPTH(QUEUE_DEPTH)
	) dma_ch2 (
		.i_reset(i_reset),
		.i_clock(i_clock),

		.i_request(dma_ch2_request),
		.i_rw(i_rw),
		.i_address(i_address[3:2]),
		.i_wdata(i_wdata),
		.o_rdata(dma_ch2_rdata),
		.o_ready(dma_ch2_ready),

		.o_bus_rw(dma_ch2_bus_rw),
		.o_bus_request(dma_ch2_bus_request),
		.i_bus_ready(dma_ch2_bus_ready),
		.o_bus_address(dma_ch2_bus_address),
		.i_bus_rdata(dma_ch2_bus_rdata),
		.o_bus_wdata(dma_ch2_bus_wdata)
	);

	DualPort dp(
		.i_reset(i_reset),
		.i_clock(i_clock),

		.o_bus_rw(o_bus_rw),
		.o_bus_request(o_bus_request),
		.i_bus_ready(i_bus_ready),
		.o_bus_address(o_bus_address),
		.i_bus_rdata(i_bus_rdata),
		.o_bus_wdata(o_bus_wdata),
		.o_bus_wmask(),

		.i_pa_rw(dma_ch0_bus_rw),
		.i_pa_request(dma_ch0_bus_request),
		.o_pa_ready(dma_ch0_bus_ready),
		.i_pa_address(dma_ch0_bus_address),
		.o_pa_rdata(dma_ch0_bus_rdata),
		.i_pa_wdata(dma_ch0_bus_wdata),
		.i_pa_wmask(4'b1111),

		.i_pb_rw(dma_ch1_bus_rw),
		.i_pb_request(dma_ch1_bus_request),
		.o_pb_ready(dma_ch1_bus_ready),
		.i_pb_address(dma_ch1_bus_address),
		.o_pb_rdata(dma_ch1_bus_rdata),
		.i_pb_wdata(dma_ch1_bus_wdata),
		.i_pb_wmask(4'b1111),

		.i_pc_rw(dma_ch2_bus_rw),
		.i_pc_request(dma_ch2_bus_request),
		.o_pc_ready(dma_ch2_bus_ready),
		.i_pc_address(dma_ch2_bus_address),
		.o_pc_rdata(dma_ch2_bus_rdata),
		.i_pc_wdata(dma_ch2_bus_wdata),
		.i_pc_wmask(4'b1111)
	);

endmodule
