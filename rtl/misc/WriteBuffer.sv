/*
 Klara-RTL
 Copyright (c) 2025 Anders Pistol.

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at https://mozilla.org/MPL/2.0/.
*/

`timescale 1ns/1ns
`default_nettype none

module WriteBuffer #(
	parameter DEPTH,
	parameter ADDRESS_WIDTH,
	parameter STALL_READ	//!< If set then any read request will stall until fifo is empty.
)(
	input wire i_reset,
	input wire i_clock,

	// Control
	output bit o_empty,
	output bit o_full,
	input wire i_cached,

	// Bus
	output wire o_bus_rw,
	output wire o_bus_request,
	input wire i_bus_ready,
	output wire [ADDRESS_WIDTH - 1:0] o_bus_address,
	input wire [31:0] i_bus_rdata,
	output wire [31:0] o_bus_wdata,
	output wire [3:0] o_bus_wmask,

	// Input
	input wire i_rw,
	input wire i_request,
	output bit o_ready,
	input wire [ADDRESS_WIDTH - 1:0] i_address,
	output bit [31:0] o_rdata,
	input wire [31:0] i_wdata,
	input wire [3:0] i_wmask
);
	typedef struct packed
	{
		bit [ADDRESS_WIDTH - 1:0] address;
		bit [31:0] wdata;
		bit [3:0] wmask;
	}
	entry_t;

	wire wq_empty;
	wire wq_full;
	bit wq_write;
	entry_t wq_wdata;
	bit wq_read = 1'b0;
	entry_t wq_rdata;

	generate if (DEPTH > 16) begin
		FIFO_BRAM #(
			.DEPTH(DEPTH),
			.WIDTH($bits(entry_t))
		) wq(
			.i_reset(i_reset),
			.i_clock(i_clock),
			.o_empty(wq_empty),
			.o_full(wq_full),
			.o_almost_full(),
			.i_write(wq_write),
			.i_wdata(wq_wdata),
			.i_read(wq_read),
			.o_rdata(wq_rdata),
			.o_queued()
		);
	end endgenerate

	generate if (DEPTH <= 16) begin
		FIFO #(
			.DEPTH(DEPTH),
			.WIDTH($bits(entry_t))
		) wq(
			.i_reset(i_reset),
			.i_clock(i_clock),
			.o_empty(wq_empty),
			.o_full(wq_full),
			.o_almost_full(),
			.i_write(wq_write),
			.i_wdata(wq_wdata),
			.i_read(wq_read),
			.o_rdata(wq_rdata),
			.o_queued()
		);
	end endgenerate

	bit dp_pa_rw;
	bit dp_pa_request;
	wire dp_pa_ready;
	bit [31:0] dp_pa_address;
	wire [31:0] dp_pa_rdata;
	bit [31:0] dp_pa_wdata;
	bit [3:0] dp_pa_wmask;

	bit dp_pb_request = 1'b0;
	wire dp_pb_ready;
	bit [31:0] dp_pb_address;
	bit [31:0] dp_pb_wdata;
	bit [3:0] dp_pb_wmask;

	DualPort dp(
		.i_reset(i_reset),
		.i_clock(i_clock),

		.o_bus_rw(o_bus_rw),
		.o_bus_request(o_bus_request),
		.i_bus_ready(i_bus_ready),
		.o_bus_address(o_bus_address),
		.i_bus_rdata(i_bus_rdata),
		.o_bus_wdata(o_bus_wdata),
		.o_bus_wmask(o_bus_wmask),

		// Read (write uncached) port
		.i_pb_rw(dp_pa_rw),
		.i_pb_request(dp_pa_request),
		.o_pb_ready(dp_pa_ready),
		.i_pb_address(dp_pa_address),
		.o_pb_rdata(dp_pa_rdata),
		.i_pb_wdata(dp_pa_wdata),
		.i_pb_wmask(dp_pa_wmask),

		// Write port
		.i_pa_rw(1'b1),
		.i_pa_request(dp_pb_request),
		.o_pa_ready(dp_pb_ready),
		.i_pa_address(dp_pb_address),
		.o_pa_rdata(),
		.i_pa_wdata(dp_pb_wdata),
		.i_pa_wmask(dp_pb_wmask),

		// Unused
		.i_pc_rw(1'b0),
		.i_pc_request(1'b0),
		.o_pc_ready(),
		.i_pc_address(32'h0),
		.o_pc_rdata(),
		.i_pc_wdata(32'h0),
		.i_pc_wmask(4'h0)
	);

	always_comb begin
		dp_pb_address = wq_rdata.address;
		dp_pb_wdata = wq_rdata.wdata;
		dp_pb_wmask = wq_rdata.wmask;
	end

	// Process write queue requests.
	bit [3:0] st = 0;
	always_ff @(posedge i_clock) begin
		if (i_reset) begin
			st <= 0;
			wq_read <= 1'b0;
			dp_pb_request <= 1'b0;
		end
		else begin
			if (st == 0) begin
				if (!wq_empty) begin
					wq_read <= 1'b1;
					st <= 1;
				end
			end
			else if (st == 1) begin
				
				wq_read <= 1'b0;
				dp_pb_request <= 1'b1;

				if (dp_pb_ready) begin
					dp_pb_request <= 1'b0;
			
					if (wq_empty)
						st <= 0;
					else
						wq_read <= 1'b1;
				end
			end
		end
	end

	bit ready_r = 1'b0;
	bit next_ready_r = 1'b0;
	always_ff @(posedge i_clock) begin
		ready_r <= !i_reset && next_ready_r;
	end

	always_comb begin
	
		wq_wdata = 0;
		wq_write = 1'b0;

		dp_pa_rw = 1'b0;
		dp_pa_request = 1'b0;
		dp_pa_address = 32'h0;
		dp_pa_wdata = 32'h0;
		dp_pa_wmask = 4'h0;

		o_ready = ready_r & i_request;
		o_rdata = 32'h0;
		o_empty = wq_empty;
		o_full = wq_full;

		next_ready_r = ready_r & i_request;

		// Write uncached data (no pending writes)
		if (i_request && i_rw && !i_cached && wq_empty) begin
			dp_pa_rw = 1'b1;
			dp_pa_request = 1'b1;
			dp_pa_wdata = i_wdata;
			dp_pa_wmask = i_wmask;
			dp_pa_address = i_address;
			o_ready = dp_pa_ready;
		end
		// Read data from bus (no pending writes)
		else if (i_request && !i_rw && wq_empty) begin
			dp_pa_rw = 1'b0;
			dp_pa_request = 1'b1;
			dp_pa_address = i_address;
			o_rdata = dp_pa_rdata;
			o_ready = dp_pa_ready;
		end
		// Write cached data (queue not full)
		else if (i_request && i_rw && i_cached && !wq_full) begin
			wq_wdata.address = i_address;
			wq_wdata.wdata = i_wdata;
			wq_wdata.wmask = i_wmask;
			wq_write = 1'b1 & !next_ready_r;
			o_ready = 1'b1;
			next_ready_r = 1'b1;	// We need to keep ready high until request if finished; since wq_full will go high.
		end
	end

endmodule
