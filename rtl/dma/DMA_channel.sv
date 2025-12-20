/*
 Klara-RTL
 Copyright (c) 2025 Anders Pistol.

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at https://mozilla.org/MPL/2.0/.
*/

`timescale 1ns/1ns
`default_nettype none

module DMA_channel #(
	parameter QUEUE_DEPTH = 4
) (
	input wire i_reset,
	input wire i_clock,
	input wire i_request,
	input wire i_rw,
	input wire [1:0] i_address,
	input wire [31:0] i_wdata,
	output bit [31:0] o_rdata,
	output bit o_ready,

	// Bus
	output bit o_bus_rw,				// Data read/write
	output bit o_bus_request,			// IO request.
	input wire i_bus_ready,			// IO request ready.
	output bit [31:0] o_bus_address,	// Address
	input wire [31:0] i_bus_rdata,	// Read data
	output bit [31:0] o_bus_wdata		// Write data,
);
	typedef enum bit [3:0]
	{
		IDLE			= 4'd0,
		READ_CMD_0		= 4'd1,
		READ_CMD		= 4'd2,

		// Write
		W_WRITE_REQ		= 4'd3,
		W_WAIT_WRITE	= 4'd4,

		// Copy
		C_READ_REQ		= 4'd5,
		C_WAIT_READ		= 4'd6,
		C_WRITE_REQ		= 4'd7,
		C_WAIT_WRITE	= 4'd8,

		// Feed
		F_READ_REQ		= 4'd9,
		F_WAIT_READ		= 4'd10,
		F_WRITE_REQ		= 4'd11,
		F_WAIT_WRITE	= 4'd12,
		F_INTERLEAVE	= 4'd13
	}
	state_t;

	typedef enum bit [1:0]
	{
		WRITE	= 2'd1,
		COPY	= 2'd2,
		FEED	= 2'd3
	}
	dma_type_t;

	typedef struct packed
	{
		dma_type_t dt;
		bit [31:0] value_or_from;
		bit [31:0] to;
		bit [31:0] count;
		bit [31:0] tag;
	}
	dma_command_t;

	dma_command_t wr_command;
	dma_command_t rd_command;
	bit [31:0] data;
	state_t state = IDLE;

	bit [31:0] queued_counter = 32'h0;
	bit [31:0] retired_counter = 32'h0;

	wire queue_empty;
	wire queue_full;
	bit queue_write = 0;
	bit queue_read = 0;
	dma_command_t queue_rdata;
	wire [15:0] queue_queued;
	FIFO #(
		.DEPTH(QUEUE_DEPTH),
		.WIDTH($bits(queue_rdata))
	) queue(
		.i_reset(i_reset),
		.i_clock(i_clock),
		.o_empty(queue_empty),
		.o_almost_full(queue_full),
		.i_write(queue_write),
		.i_wdata(wr_command),
		.i_read(queue_read),
		.o_rdata(queue_rdata),
		.o_queued(queue_queued)
	);

	initial begin
		o_ready = 0;
		o_bus_rw = 0;
		o_bus_request = 0;
		o_bus_address = 0;
		o_bus_wdata = 0;
	end

	// Receive commands and insert into queue.
	always_ff @(posedge i_clock) begin

		queue_write <= 1'b0;

		if (i_request && !o_ready) begin
			if (!i_rw) begin
				if (i_address == 2'd0) begin
					o_rdata <= queued_counter;
					o_ready <= 1'b1;
				end
				else if (i_address == 2'd1) begin
					o_rdata <= retired_counter;
					o_ready <= 1'b1;
				end
				else if (i_address == 2'd3) begin
					o_rdata <=
					{
						30'h0,
						queue_queued >= (QUEUE_DEPTH - 1), // queue_full,										// DMA full
						(!queue_empty || state != IDLE) ? 1'b1 : 1'b0	// DMA busy
					};
					o_ready <= 1'b1;
				end
			end
			else begin
				// Receive commands from CPU.
				if (i_address == 2'd0) begin
					wr_command.value_or_from <= i_wdata;
					o_ready <= 1'b1;
				end
				else if (i_address == 2'd1) begin
					wr_command.to <= i_wdata;
					o_ready <= 1'b1;
				end
				else if (i_address == 2'd2) begin
					wr_command.count <= i_wdata;
					o_ready <= 1'b1;
				end
				else if (i_address == 2'd3) begin
					wr_command.dt <= dma_type_t'(i_wdata[1:0]);
					wr_command.tag <= queued_counter + 1;
					if (!queue_full) begin
						queue_write <= 1'b1;
						queued_counter <= queued_counter + 1;
						o_ready <= 1'b1;
					end
				end
			end
		end
		else if (!i_request) begin
			o_ready <= 1'b0;
		end

	end

	// Process commands.
	always_ff @(posedge i_clock) begin
		queue_read <= 1'b0;
		unique case (state)
			IDLE: begin
				if (!queue_empty) begin
					queue_read <= 1'b1;
					state <= READ_CMD_0;
				end
			end

			READ_CMD_0: begin
				state <= READ_CMD;
			end

			READ_CMD: begin
				rd_command <= queue_rdata;
				if (queue_rdata.dt == WRITE)
					state <= W_WRITE_REQ;
				else if (queue_rdata.dt == COPY)
					state <= C_READ_REQ;
				else if (queue_rdata.dt == FEED)
					state <= F_READ_REQ;
				else begin
					retired_counter <= queue_rdata.tag;
					state <= IDLE;
				end
			end

			// Write

			W_WRITE_REQ: begin
				o_bus_request <= 1'b1;
				o_bus_rw <= 1'b1;
				o_bus_address <= rd_command.to;
				o_bus_wdata <= rd_command.value_or_from;
				state <= W_WAIT_WRITE;
			end

			W_WAIT_WRITE: begin
				if (i_bus_ready) begin
					o_bus_request <= 1'b0;
					rd_command.to <= rd_command.to + 4;
					if (rd_command.count > 0) begin
						rd_command.count <= rd_command.count - 1;
						state <= W_WRITE_REQ;
					end
					else begin
						retired_counter <= rd_command.tag;
						state <= IDLE;
					end
				end
			end

			// Copy

			C_READ_REQ: begin
				o_bus_request <= 1'b1;
				o_bus_rw <= 1'b0;
				o_bus_address <= rd_command.value_or_from;
				state <= C_WAIT_READ;
			end

			C_WAIT_READ: begin
				if (i_bus_ready) begin
					o_bus_request <= 1'b0;
					data <= i_bus_rdata;
					rd_command.value_or_from <= rd_command.value_or_from + 4;
					state <= C_WRITE_REQ;
				end
			end

			C_WRITE_REQ: begin
				o_bus_request <= 1'b1;
				o_bus_rw <= 1'b1;
				o_bus_address <= rd_command.to;
				o_bus_wdata <= data;
				state <= C_WAIT_WRITE;
			end

			C_WAIT_WRITE: begin
				if (i_bus_ready) begin
					o_bus_request <= 1'b0;
					rd_command.to <= rd_command.to + 4;
					if (rd_command.count > 0) begin
						rd_command.count <= rd_command.count - 1;
						state <= C_READ_REQ;
					end
					else begin
						retired_counter <= rd_command.tag;
						state <= IDLE;
					end
				end
			end

			// Feed

			F_READ_REQ: begin
				o_bus_request <= 1'b1;
				o_bus_rw <= 1'b0;
				o_bus_address <= rd_command.value_or_from;
				state <= F_WAIT_READ;
			end

			F_WAIT_READ: begin
				if (i_bus_ready) begin
					o_bus_request <= 1'b0;
					data <= i_bus_rdata;
					rd_command.value_or_from <= rd_command.value_or_from + 4;
					state <= F_WRITE_REQ;
				end
			end

			F_WRITE_REQ: begin
				o_bus_request <= 1'b1;
				o_bus_rw <= 1'b1;
				o_bus_address <= rd_command.to;
				o_bus_wdata <= data;
				state <= F_WAIT_WRITE;
			end

			F_WAIT_WRITE: begin
				if (i_bus_ready) begin
					o_bus_request <= 1'b0;
					if (rd_command.count > 0) begin
						rd_command.count <= rd_command.count - 1;
						state <= F_INTERLEAVE;
					end
					else begin
						retired_counter <= rd_command.tag;
						state <= IDLE;
					end
				end
			end

			F_INTERLEAVE: begin
				// Allow other bus masters to access bus.
				state <= F_READ_REQ;
			end

			default:
				state <= IDLE;
		endcase
	end

endmodule
