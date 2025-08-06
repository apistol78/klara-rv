/*
 Klara-RV
 Copyright (c) 2025 Anders Pistol.

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at https://mozilla.org/MPL/2.0/.
*/
`include "CPU_Defines.sv"

`timescale 1ns/1ns

module CPU_DCache_Reg #(
	parameter SIZE = 14
)(
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
	input i_flush,
	output bit o_ready,
	input [31:0] i_address,
	output bit [31:0] o_rdata,
	input [31:0] i_wdata,
	input i_cacheable,

	// Debug
	output [31:0] o_hit,
	output [31:0] o_miss
);

	localparam RANGE = 1 << SIZE;

	typedef enum bit [3:0]
	{
		IDLE,
		FLUSH_SETUP,
		FLUSH_CHECK,
		FLUSH_WRITE,
		FLUSH_NEXT,
		PASS_THROUGH,
		WRITE_SETUP,
		WRITE_WAIT,
		READ_SETUP,
		READ_WB_WAIT,
		READ_BUS_WAIT,
		INITIALIZE
	} state_t;

	state_t state = INITIALIZE;
	bit [SIZE:0] flush_address = 0;

	// Write buffer.
	bit wb_rw = 1'b0;
	bit wb_request = 1'b0;
	wire wb_ready;
	bit [31:0] wb_address = 0;
	wire [31:0] wb_rdata;
	bit [31:0] wb_wdata = 0;
	bit wb_cached = 0;

	CPU_DCache_WB wb(
		.i_reset(i_reset),
		.i_clock(i_clock),

		.o_bus_rw(o_bus_rw),
		.o_bus_request(o_bus_request),
		.i_bus_ready(i_bus_ready),
		.o_bus_address(o_bus_address),
		.i_bus_rdata(i_bus_rdata),
		.o_bus_wdata(o_bus_wdata),

		.i_rw(wb_rw),
		.i_request(wb_request),
		.o_ready(wb_ready),
		.i_address(wb_address),
		.o_rdata(wb_rdata),
		.i_wdata(wb_wdata),
		.i_cached(wb_cached)
	);

	// Cache memory.
	bit cache_rw = 0;
	bit [SIZE - 1:0] cache_address;
	bit [63:0] cache_wdata;
	wire [63:0] cache_rdata;

	// One cycle latency, important since
	// we rely on address only.
	CPU_BRAM #(
		.WIDTH(64),
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
		if (state == FLUSH_SETUP || state == FLUSH_CHECK || state == FLUSH_WRITE || state == INITIALIZE)
			cache_address = flush_address;
		else
			cache_address = i_address[(SIZE - 1) + 2:2];
	end

	always_ff @(posedge i_clock) begin

		o_ready <= 1'b0;
		cache_rw <= 1'b0;

		case (state)
			IDLE: begin
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
						wb_rw <= i_rw;
						wb_address <= i_address;
						wb_request <= 1'b1;
						wb_wdata <= i_wdata;
						wb_cached <= 1'b0;
						state <= PASS_THROUGH;
					end
				end
			end

			// ================
			// FLUSH
			// ================
			FLUSH_SETUP: begin
				if (!wb_ready) begin
					if (flush_address < RANGE)
						state <= FLUSH_CHECK;
					else begin
						o_ready <= 1'b1;
						state <= IDLE;
					end
				end
			end

			FLUSH_CHECK: begin
				if (cache_entry_dirty) begin
					wb_rw <= 1'b1;
					wb_address <= cache_entry_address;
					wb_request <= 1'b1;
					wb_wdata <= cache_entry_data;
					wb_cached <= 1'b1;
					state <= FLUSH_WRITE;
				end
				else begin
					flush_address <= flush_address + 1;
					state <= FLUSH_SETUP;
				end
			end

			FLUSH_WRITE: begin
				if (wb_ready) begin
					cache_rw <= 1'b1;
					cache_wdata <= { cache_entry_data, cache_entry_address[31:2], 2'b01 };
					wb_request <= 1'b0;
					state <= FLUSH_NEXT;
				end
			end

			FLUSH_NEXT: begin
				flush_address <= flush_address + 1;
				state <= FLUSH_SETUP;
			end

			// ================
			// NOT INITIALIZED
			// ================

			// Cache not initialized, pass through to bus.
			PASS_THROUGH: begin
				if (wb_ready) begin
					wb_request <= 1'b0;
					o_rdata <= wb_rdata;
					o_ready <= 1'b1;
					state <= IDLE;
				end
			end

			// ================
			// WRITE
			// ================

			// Write, write back if necessary.
			WRITE_SETUP: begin
				if (cache_entry_dirty && cache_entry_address != i_address) begin
					wb_rw <= 1'b1;
					wb_address <= cache_entry_address;
					wb_request <= 1'b1;
					wb_wdata <= cache_entry_data;
					wb_cached <= 1'b1;
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
			WRITE_WAIT: begin
				if (wb_ready) begin
					cache_rw <= 1'b1;
					cache_wdata <= { i_wdata, i_address[31:2], 2'b11 };
					wb_request <= 1'b0;
					o_ready <= 1'b1;
					state <= IDLE;
				end
			end

			// ================
			// READ
			// ================

			// Check if cache entry valid, if not then read from bus.
			READ_SETUP: begin
				if (cache_entry_valid && cache_entry_address == i_address) begin
					o_rdata <= cache_entry_data;
					o_ready <= 1'b1;
					state <= IDLE;
				end
				else begin
					if (/* cache_entry_valid && */ cache_entry_dirty) begin
						wb_rw <= 1'b1;
						wb_address <= cache_entry_address;
						wb_request <= 1'b1;
						wb_wdata <= cache_entry_data;
						wb_cached <= 1'b1;
						state <= READ_WB_WAIT;
					end
					else begin
						wb_rw <= 1'b0;
						wb_address <= i_address;
						wb_request <= 1'b1;
						wb_cached <= 1'b1;
						state <= READ_BUS_WAIT;
					end
				end
			end

			// Write previous entry back to bus.
			READ_WB_WAIT: begin
				if (wb_ready) begin
					wb_request <= 1'b0;
					state <= READ_BUS_WAIT;
				end
			end

			// Wait until new data read from bus.
			READ_BUS_WAIT: begin
				wb_rw <= 1'b0;
				wb_address <= i_address;
				wb_request <= 1'b1;
				wb_cached <= 1'b1;
				if (wb_ready) begin
					cache_rw <= 1'b1;
					cache_wdata <= { wb_rdata, i_address[31:2], 2'b01 };
					wb_request <= 1'b0;
					o_rdata <= wb_rdata;
					o_ready <= 1'b1;
					state <= IDLE;
				end
			end

			// ================
			// INITIALIZE
			// ================

			INITIALIZE: begin
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
