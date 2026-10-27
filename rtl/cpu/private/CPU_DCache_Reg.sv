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
	output bit [3:0] o_bus_wmask,

	// Input
	input wire i_rw,
	input wire i_request,
	input wire i_flush,
	output bit o_ready,
	input wire [31:0] i_address,
	output bit [31:0] o_rdata,
	input wire [31:0] i_wdata,
	input wire [3:0] i_wmask,
	input wire i_cacheable
);

	localparam RANGE = 1 << SIZE;

	// Index bits are implied by entry location so only
	// the remaining address bits are stored as tag.
	localparam TAG_WIDTH = 30 - SIZE;

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

	typedef struct packed
	{
		bit dirty;
		bit [TAG_WIDTH - 1:0] tag;
		bit [3:0] mask;
		bit [31:0] data;
	} cache_entry_t;

	state_t state = INITIALIZE;
	bit [SIZE:0] flush_address = 0;

	// Cache memory.
	bit cache_rw = 0;
	bit [SIZE - 1:0] cache_address;
	cache_entry_t cache_wdata;
	cache_entry_t cache_rdata;

	// One cycle latency, important since
	// we rely on address only.
	CPU_BRAM #(
		.ADDRESS_WIDTH(SIZE),
		.DATA_WIDTH($bits(cache_entry_t)),
		.SIZE(RANGE),
		.ADDR_LSH(0)
	) cache(
		.i_clock(i_clock),
		.i_request(1'b1),
		.i_rw(cache_rw),
		.i_address(cache_address),
		.i_wdata(cache_wdata),
		.o_rdata(cache_rdata),
		.o_ready()
	);

	wire [TAG_WIDTH - 1:0] i_tag = i_address[31:SIZE + 2];
	wire tag_hit = (cache_rdata.tag == i_tag);
	wire write_back = |cache_rdata.mask && cache_rdata.dirty;

	// Cache address is still the one entry was read from.
	wire [31:0] cache_entry_address = { cache_rdata.tag, cache_address, 2'b00 };
	wire [31:0] i_wmask_extended = {
		{ 8{ i_wmask[3] } },
		{ 8{ i_wmask[2] } },
		{ 8{ i_wmask[1] } },
		{ 8{ i_wmask[0] } }
	};

	always_comb begin
		if (|state[10:7])
			cache_address = flush_address[SIZE - 1:0];
		else
			cache_address = i_address[(SIZE - 1) + 2:2];
	end

	bit [31:0] rdata_r = 32'h0;
	bit ready_r = 1'b0;

	always_comb begin
		// Read data is only used when ready so select on state
		// alone, keeps tag compare out of the data path.
		o_rdata = state[4] ? cache_rdata.data : rdata_r;
		o_ready = ready_r;

		// If cache rd or wr hit then
		// acknowledge request quickly.
		if (state[2]) begin
			if (cache_rdata.mask == 0 || tag_hit) begin
				o_ready = 1'b1;
			end
		end
		else if (state[4]) begin
			if (&cache_rdata.mask && tag_hit) begin
				o_ready = 1'b1;
			end
		end
	end

	always_ff @(posedge i_clock) begin

		ready_r <= 1'b0;
		cache_rw <= 1'b0;

		unique case (1'b1)
			/* IDLE */ state[0]: begin
				// o_ready is ready_r when idle, using it directly
				// keeps tag compare out of this logic.
				if (i_request && !ready_r) begin
					if (i_flush) begin
						flush_address <= 0;
						state <= FLUSH_SETUP;
					end
					else if (i_cacheable) begin
						if (!i_rw) begin

							// Check "super hot" cache line first, since
							// RMW pattern access same address multiple times
							// it's a high probability this will be true.
							// if (&cache_rdata.mask && cache_entry_address == i_address) begin
							// 	o_rdata <= cache_rdata.data;
							// 	o_ready <= 1'b1;
							// end
							// else
								state <= READ_SETUP;

						end
						else begin

							// Check "super hot" cache line here as well,
							// see comment above.
							// if (/*|cache_rdata.mask &&*/ cache_entry_address == i_address) begin
							// 	cache_rw <= 1'b1;
							// 	cache_wdata.dirty <= 1'b1;
							// 	cache_wdata.address <= i_address[31:2];
							// 	cache_wdata.data <= (cache_rdata.data & ~i_wmask_extended) | (i_wdata & i_wmask_extended);
							// 	cache_wdata.mask <= cache_rdata.mask | i_wmask;
							// 	o_ready <= 1'b1;
							// end
							// else
								state <= WRITE_SETUP;

						end
					end
					else begin
						o_bus_rw <= i_rw;
						o_bus_address <= i_address;
						o_bus_request <= 1'b1;
						o_bus_wdata <= i_wdata;
						o_bus_wmask <= i_wmask;
						state <= PASS_THROUGH;
					end
				end
			end

			// ================
			// NOT INITIALIZED
			// ================

			// Cache not initialized, pass through to bus.
			/* PASS_THROUGH */ state[1]: begin
				if (i_bus_ready) begin
					o_bus_request <= 1'b0;
					rdata_r <= i_bus_rdata;
					ready_r <= 1'b1;
					state <= IDLE;
				end
			end

			// ================
			// WRITE
			// ================

			// Write, write back if necessary.
			/* WRITE_SETUP */ state[2]: begin

				// Bus and cache data are loaded unconditionally, only
				// request and state depend on the tag compare.
				o_bus_rw <= 1'b1;
				o_bus_address <= cache_entry_address;
				o_bus_wdata <= cache_rdata.data;
				o_bus_wmask <= cache_rdata.mask;

				// Always merge; when entry is empty the mask is
				// zero and the unmasked bytes are never used.
				cache_wdata.dirty <= 1'b1;
				cache_wdata.tag <= i_tag;
				cache_wdata.data <= (cache_rdata.data & ~i_wmask_extended) | (i_wdata & i_wmask_extended);
				cache_wdata.mask <= cache_rdata.mask | i_wmask;

				if (|cache_rdata.mask && !tag_hit) begin
					o_bus_request <= 1'b1;
					state <= WRITE_WAIT;
				end
				else begin
					cache_rw <= 1'b1;
					state <= IDLE;
				end
			end

			// Wait until write back finish.
			/* WRITE_WAIT */ state[3]: begin
				if (i_bus_ready) begin
					cache_rw <= 1'b1;
					cache_wdata.dirty <= 1'b1;
					cache_wdata.tag <= i_tag;
					cache_wdata.data <= i_wdata;
					cache_wdata.mask <= i_wmask;
					o_bus_request <= 1'b0;
					ready_r <= 1'b1;
					state <= IDLE;
				end
			end

			// ================
			// READ
			// ================

			// Check if cache entry valid, if not then read from bus.
			/* READ_SETUP */ state[4]: begin

				// Either write back entry or read from bus, loaded
				// unconditionally since request is not set on a hit.
				o_bus_rw <= write_back;
				o_bus_address <= write_back ? cache_entry_address : i_address;
				o_bus_wdata <= cache_rdata.data;
				o_bus_wmask <= cache_rdata.mask;

				if (&cache_rdata.mask && tag_hit) begin
					state <= IDLE;
				end
				else begin
					o_bus_request <= 1'b1;
					if (write_back)
						state <= READ_WB_WAIT;
					else
						state <= READ_BUS_WAIT;
				end
			end

			// Write previous entry back to bus.
			/* READ_WB_WAIT */ state[5]: begin
				if (i_bus_ready) begin
					o_bus_request <= 1'b0;
					state <= READ_BUS_WAIT;
				end
			end

			// Wait until new data read from bus.
			/* READ_BUS_WAIT */ state[6]: begin
				o_bus_rw <= 1'b0;
				o_bus_address <= i_address;
				o_bus_request <= 1'b1;
				if (i_bus_ready) begin
					cache_rw <= 1'b1;
					cache_wdata.dirty <= 1'b0;
					cache_wdata.tag <= i_tag;
					cache_wdata.data <= i_bus_rdata;
					cache_wdata.mask <= 4'b1111;
					o_bus_request <= 1'b0;
					rdata_r <= i_bus_rdata;
					ready_r <= 1'b1;
					state <= IDLE;
				end
			end

			// ================
			// FLUSH
			// ================
			/* FLUSH_SETUP */ state[7]: begin
				if (!i_bus_ready) begin
					if (flush_address <= RANGE - 1)
						state <= FLUSH_CHECK;
					else begin
						ready_r <= 1'b1;
						state <= IDLE;
					end
				end
			end

			/* FLUSH_CHECK */ state[8]: begin
				if (write_back) begin
					o_bus_rw <= 1'b1;
					o_bus_address <= cache_entry_address;
					o_bus_request <= 1'b1;
					o_bus_wdata <= cache_rdata.data;
					o_bus_wmask <= cache_rdata.mask;
					state <= FLUSH_WRITE;
				end
				else begin
					flush_address <= flush_address + 1;
					state <= FLUSH_SETUP;
				end
			end

			/* FLUSH_WRITE */ state[9]: begin
				if (i_bus_ready) begin
					o_bus_request <= 1'b0;
					flush_address <= flush_address + 1;
					state <= FLUSH_SETUP;
				end
			end

			// ================
			// INITIALIZE
			// ================

			/* INITIALIZE */ state[10]: begin
				if (flush_address < RANGE) begin
					cache_rw <= 1'b1;
					cache_wdata.dirty <= 1'b0;
					cache_wdata.tag <= 0;
					cache_wdata.data <= 32'h0;
					cache_wdata.mask <= 4'b0000;
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
			o_bus_rw <= 1'b0;
			o_bus_request <= 1'b0;
			o_bus_address <= 32'h0;
			o_bus_wdata <= 32'h0;
			o_bus_wmask <= 4'h0;
			state <= INITIALIZE;
			flush_address <= 0;
		end
	end

endmodule
