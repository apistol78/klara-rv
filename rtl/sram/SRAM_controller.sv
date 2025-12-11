/*
 Klara-RTL
 Copyright (c) 2025 Anders Pistol.

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at https://mozilla.org/MPL/2.0/.
*/

`timescale 1ns/1ns
`default_nettype none

module SRAM_controller #(
	parameter FREQUENCY = 100_000_000,
	parameter SRAM_ADDRESS_WIDTH = 18
)(
	input wire i_reset,
	input wire i_clock,
	input wire i_request,
	input wire i_rw,
	input wire [31:0] i_address,
	output bit [31:0] o_rdata,
	input wire [31:0] i_wdata,
	input wire [3:0] i_wmask,
	output bit o_ready,

	output bit [SRAM_ADDRESS_WIDTH-1:0] SRAM_A,
	output bit [15:0] SRAM_D_w,
	input wire [15:0] SRAM_D_r,
	output bit SRAM_D_rw,
	output wire SRAM_CE_n,
	output bit SRAM_OE_n,
	output bit SRAM_WE_n,
	output wire SRAM_LB_n,
	output wire SRAM_UB_n
);

	// Number of cycles for entire transaction.
	localparam CYCLES = (4 * FREQUENCY) / 100_000_000;
	localparam READ_OFFSET = 1;
	localparam WRITE_OFFSET = 1;

	bit [7:0] count;
	bit [15:0] wdata;
	bit [1:0] wmask;
	
	initial begin
		count = 0;
	end

	assign SRAM_CE_n = 1'b0;
	
	// Output 
	assign SRAM_D_rw = i_request && i_rw;
	assign SRAM_D_w = wdata;
	assign { SRAM_UB_n, SRAM_LB_n } = ~wmask;

	always_comb begin
		SRAM_OE_n = ~(i_request && !i_rw);

		SRAM_WE_n = 1'b1;
		if (i_request && i_rw) begin
			if (count == WRITE_OFFSET)
				SRAM_WE_n = 1'b0;
			else if (count == CYCLES / 2 + WRITE_OFFSET)
				SRAM_WE_n = 1'b0;		
		end

		if (count < CYCLES / 2) begin
			SRAM_A = { i_address[SRAM_ADDRESS_WIDTH:2], 1'b0 };
		end
		else begin
			SRAM_A = { i_address[SRAM_ADDRESS_WIDTH:2], 1'b1 };
		end

		if (count < CYCLES / 2) begin
			wdata = i_wdata[15:0];
			wmask = i_rw ? i_wmask[1:0] : 2'b11;
		end
		else begin
			wdata = i_wdata[31:16];
			wmask = i_rw ? i_wmask[3:2] : 2'b11;
		end

		o_ready = (i_request && count >= CYCLES) ? 1'b1 : 1'b0;
	end

	// Increment counter, store data read from SRAM.
	always_ff @(posedge i_clock) begin
		if (i_reset) begin
			count <= 0;
		end
		else begin
			if (i_request) begin
				if (!i_rw) begin
					if (count == READ_OFFSET)
						o_rdata[15:0] <= SRAM_D_r;
					else if (count == CYCLES / 2 + READ_OFFSET)
						o_rdata[31:16] <= SRAM_D_r;
				end
			 	count <= count + 1;
			end
			else begin
				count <= 0;
			end
		end
	end

endmodule