/*
 Klara-RTL
 Copyright (c) 2025 Anders Pistol.

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at https://mozilla.org/MPL/2.0/.
*/

`timescale 1ns/1ns
`default_nettype none

module DMA_tb();

	bit clk;

	bit dma_request = 1'b0;
	bit dma_rw = 1'b0;
	bit [1:0] dma_address;
	bit [31:0] dma_wdata;
	wire [31:0] dma_rdata;
	wire dma_ready;

	wire dma_bus_rw;
	wire dma_bus_request;
	wire dma_bus_ready;
	wire [31:0] dma_bus_address;
	wire [31:0] dma_bus_rdata = (dma_bus_request && !dma_bus_rw) ? { 32'hcafe, dma_bus_address[15:0] } : 32'h0;
	wire [31:0] dma_bus_wdata;

	BRAM #(
		.SIZE(32'h10000)
	) ram(
		.i_clock(clk),
		.i_request(dma_bus_request),
		.i_rw(dma_bus_rw),
		.i_address(dma_bus_address),
		.i_wdata(dma_bus_wdata),
		.o_rdata(),
		.o_ready(dma_bus_ready),
		.o_valid()
	);

	DMA dma(
		.i_reset(1'b0),
		.i_clock(clk),
		.i_request(dma_request),
		.i_rw(dma_rw),
		.i_address(dma_address),
		.i_wdata(dma_wdata),
		.o_rdata(dma_rdata),
		.o_ready(dma_ready),

		.o_bus_rw(dma_bus_rw),
		.o_bus_request(dma_bus_request),
		.i_bus_ready(dma_bus_ready),
		.o_bus_address(dma_bus_address),
		.i_bus_rdata(dma_bus_rdata),
		.o_bus_wdata(dma_bus_wdata)
	);

	initial begin
		clk = 0;
		#1;
		forever clk = #5 ~clk;        
	end

    initial begin
        $dumpfile("build/test/DMA_tb.vcd");
        $dumpvars(0, DMA_tb);

		repeat (100) @ (posedge clk);

		dma_rw = 1'b1;
		
		// from address
		dma_request <= 1'b1;
		dma_address <= 2'h0;
		dma_wdata <= 32'h0000_0000;
		while (!dma_ready) @(posedge clk);
		dma_request <= 1'b0;
		repeat (4) @ (posedge clk);

		// to address
		dma_request <= 1'b1;
		dma_address <= 2'h1;
		dma_wdata <= 32'h0000_0100;
		while (!dma_ready) @(posedge clk);
		dma_request <= 1'b0;
		repeat (4) @ (posedge clk);

		// count
		dma_request <= 1'b1;
		dma_address <= 2'h2;
		dma_wdata <= 32'd50;
		while (!dma_ready) @(posedge clk);
		dma_request <= 1'b0;
		repeat (4) @ (posedge clk);

		// transfer type
		dma_request <= 1'b1;
		dma_address <= 2'h3;
		//dma_wdata <= 2'd2;		// copy
		dma_wdata <= 2'd3;		// feed
		while (!dma_ready) @(posedge clk);
		dma_request <= 1'b0;
		repeat (4) @ (posedge clk);

		repeat (100) @ (posedge clk);

		// busy
		dma_rw = 1'b0;
		dma_request <= 1'b1;
		dma_address <= 2'h3;
		while (!dma_ready) @(posedge clk);
		dma_request <= 1'b0;
		assert(dma_rdata != 0);

		repeat (100) @ (posedge clk);

		// busy
		dma_rw = 1'b0;
		dma_request <= 1'b1;
		dma_address <= 2'h3;
		while (!dma_ready) @(posedge clk);
		dma_request <= 1'b0;
		assert(dma_rdata != 0);

		repeat (100) @ (posedge clk);

		// busy
		dma_rw = 1'b0;
		dma_request <= 1'b1;
		dma_address <= 2'h3;
		while (!dma_ready) @(posedge clk);
		dma_request <= 1'b0;
		assert(dma_rdata == 0);

		repeat (10000) @ (posedge clk);

		$finish;
	end

endmodule