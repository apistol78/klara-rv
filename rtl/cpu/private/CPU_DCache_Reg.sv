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

module CPU_DCache_Reg #(
	parameter SIZE = 14
)(
	input wire i_reset,
	input wire i_clock,

	// Bus
	output bit o_bus_rw,
	output bit o_bus_request,
	input wire i_bus_ready,
	output bit [31:0] o_bus_address,
	input wire [31:0] i_bus_rdata,
	output bit [31:0] o_bus_wdata,

	// Input
	input wire i_rw,
	input wire i_request,
	input wire i_flush,
	output bit o_ready,
	input wire [31:0] i_address,
	output bit [31:0] o_rdata,
	input wire [31:0] i_wdata,
	input wire i_cacheable,

	// Debug
	output wire [31:0] o_hit,
	output wire [31:0] o_miss
);

	localparam RANGE = 1 << SIZE;

	typedef enum bit [10:0]
	{
		IDLE			= 11'b00000000001,
		PASS_THROUGH	= 11'b00000000010,
		WRITE_SETUP		= 11'b00000000100,
		WRITE_WAIT		= 11'b00000001000,
		READ_SETUP		= 11'b00000010000,
		READ_WB_WAIT	= 11'b00000100000,
		READ_BUS_WAIT	= 11'b00001000000,
		FLUSH_SETUP		= 11'b00010000000,
		FLUSH_CHECK		= 11'b00100000000,
		FLUSH_WRITE		= 11'b01000000000,
		INITIALIZE		= 11'b10000000000
	} state_t;

	state_t state = INITIALIZE;
	bit [SIZE:0] flush_address = 0;

	// Cache memory.
	bit cache_rw = 0;
	bit [SIZE - 1:0] cache_address;
	bit [63:0] cache_wdata;
	wire [63:0] cache_rdata;

	// One cycle latency, important since
	// we rely on address only.
	CPU_BRAM #(
		.ADDRESS_WIDTH(SIZE),
		.DATA_WIDTH(64),
		.SIZE(RANGE),
		.ADDR_LSH(0)
	) cache(
		.i_clock(i_clock),
		.i_request(1'b1),
		.i_rw(cache_rw),
		.i_address(cache_address),
		.i_wdata(cache_wdata),
		.o_rdata(cache_rdata),
		.o_ready(),
		.o_valid()
	);

	wire cache_entry_valid = cache_rdata[0];
	wire cache_entry_dirty = cache_rdata[1];
	wire [31:0] cache_entry_address = { cache_rdata[31:2], 2'b00 };
	wire [31:0] cache_entry_data = cache_rdata[63:32];

	always_comb begin
		if (|state[10:7])
			cache_address = flush_address[SIZE - 1:0];
		else
			cache_address = i_address[(SIZE - 1) + 2:2];
	end

	always_ff @(posedge i_clock) begin

		o_ready <= 1'b0;
		cache_rw <= 1'b0;

		unique case (1'b1)
			state[0]: begin
				if (i_request && !o_ready) begin
					if (i_flush) begin
						flush_address <= 0;
						state <= FLUSH_SETUP;
					end
					else if (i_cacheable) begin
						if (!i_rw) begin

							// Check "super hot" cache line first, since
							// RMW pattern access same address multiple times
							// it's a high probability this will be true.
							if (cache_entry_valid && cache_entry_address == i_address) begin
								o_rdata <= cache_entry_data;
								o_ready <= 1'b1;
							end
							else
								state <= READ_SETUP;

						end
						else begin

							// Check "super hot" cache line here as well,
							// see comment above.
							if (cache_entry_valid && cache_entry_address == i_address) begin
								cache_rw <= 1'b1;
								cache_wdata <= { i_wdata, i_address[31:2], 2'b11 };
								o_ready <= 1'b1;
							end
							else
								state <= WRITE_SETUP;

						end
					end
					else begin
						o_bus_rw <= i_rw;
						o_bus_address <= i_address;
						o_bus_request <= 1'b1;
						o_bus_wdata <= i_wdata;
						state <= PASS_THROUGH;
					end
				end
			end

			// ================
			// NOT INITIALIZED
			// ================

			// Cache not initialized, pass through to bus.
			state[1]: begin
				if (i_bus_ready) begin
					o_bus_request <= 1'b0;
					o_rdata <= i_bus_rdata;
					o_ready <= 1'b1;
					state <= IDLE;
				end
			end

			// ================
			// WRITE
			// ================

			// Write, write back if necessary.
			state[2]: begin
				if (cache_entry_dirty && cache_entry_address != i_address) begin
					o_bus_rw <= 1'b1;
					o_bus_address <= cache_entry_address;
					o_bus_request <= 1'b1;
					o_bus_wdata <= cache_entry_data;
					state <= WRITE_WAIT;
				end
				else begin
					cache_rw <= 1'b1;
					cache_wdata <= { i_wdata, i_address[31:2], 2'b11 };
					o_ready <= 1'b1;
					state <= IDLE;
				end
			end

			// Wait until write back finish.
			state[3]: begin
				if (i_bus_ready) begin
					cache_rw <= 1'b1;
					cache_wdata <= { i_wdata, i_address[31:2], 2'b11 };
					o_bus_request <= 1'b0;
					o_ready <= 1'b1;
					state <= IDLE;
				end
			end

			// ================
			// READ
			// ================

			// Check if cache entry valid, if not then read from bus.
			state[4]: begin
				if (cache_entry_valid && cache_entry_address == i_address) begin
					o_rdata <= cache_entry_data;
					o_ready <= 1'b1;
					state <= IDLE;
				end
				else begin
					if (/* cache_entry_valid && */ cache_entry_dirty) begin
						o_bus_rw <= 1'b1;
						o_bus_address <= cache_entry_address;
						o_bus_request <= 1'b1;
						o_bus_wdata <= cache_entry_data;
						state <= READ_WB_WAIT;
					end
					else begin
						o_bus_rw <= 1'b0;
						o_bus_address <= i_address;
						o_bus_request <= 1'b1;
						state <= READ_BUS_WAIT;
					end
				end
			end

			// Write previous entry back to bus.
			state[5]: begin
				if (i_bus_ready) begin
					o_bus_request <= 1'b0;
					state <= READ_BUS_WAIT;
				end
			end

			// Wait until new data read from bus.
			state[6]: begin
				o_bus_rw <= 1'b0;
				o_bus_address <= i_address;
				o_bus_request <= 1'b1;
				if (i_bus_ready) begin
					cache_rw <= 1'b1;
					cache_wdata <= { i_bus_rdata, i_address[31:2], 2'b01 };
					o_bus_request <= 1'b0;
					o_rdata <= i_bus_rdata;
					o_ready <= 1'b1;
					state <= IDLE;
				end
			end

			// ================
			// FLUSH
			// ================
			state[7]: begin
				if (!i_bus_ready) begin
					if (flush_address <= RANGE - 1)
						state <= FLUSH_CHECK;
					else begin
						o_ready <= 1'b1;
						state <= IDLE;
					end
				end
			end

			state[8]: begin
				if (cache_entry_dirty) begin
					o_bus_rw <= 1'b1;
					o_bus_address <= cache_entry_address;
					o_bus_request <= 1'b1;
					o_bus_wdata <= cache_entry_data;
					/*
					cache_rw <= 1'b1;
					cache_wdata <= 32'hffff_fff0; // { cache_entry_data, cache_entry_address[31:2], 2'b01 };
					*/
					state <= FLUSH_WRITE;
				end
				else begin
					flush_address <= flush_address + 1;
					state <= FLUSH_SETUP;
				end
			end

			state[9]: begin
				if (i_bus_ready) begin
					o_bus_request <= 1'b0;
					flush_address <= flush_address + 1;
					state <= FLUSH_SETUP;
				end
			end

			// ================
			// INITIALIZE
			// ================

			state[10]: begin
				if (flush_address < RANGE) begin
					cache_rw <= 1'b1;
					cache_wdata <= 32'hffff_fff0;
					flush_address <= flush_address + 1;
				end
				else begin
					flush_address <= 0;
					state <= IDLE;
				end
			end

			default: begin
				state <= IDLE;
			end
		endcase

		// Re-initialize cache at reset.
		if (i_reset) begin
			state <= INITIALIZE;
			flush_address <= 0;
		end
	end

endmodule
