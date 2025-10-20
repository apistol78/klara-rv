/*
 Klara-RV
 Copyright (c) 2025 Anders Pistol.

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at https://mozilla.org/MPL/2.0/.
*/
`include "CPU_Types.sv"

`timescale 1ns/1ns
`default_nettype none

module CPU_Memory #(
	parameter DCACHE_SIZE = 10,
	parameter DCACHE_REGISTERED = 1,
	parameter DCACHE_WB_QUEUE = 0
)(
	input wire i_reset,
	input wire i_clock,

	// Bus
	output wire o_bus_rw,
	output wire o_bus_request,
	input wire i_bus_ready,
	output wire [31:0] o_bus_address,
	input wire [31:0] i_bus_rdata,
	output wire [31:0] o_bus_wdata,

	// Input
	output bit o_busy,
	input execute_data_t i_data,

	// Output
	output memory_data_t o_data
);

	typedef enum bit [2:0]
	{
		IDLE,
		READ,
		WRITE_WORD,
		WRITE_RMW_0,
		WRITE_RMW_1,
		FLUSH
	} state_t;

	// ================
	// Write back queue

	bit wb_rw;
	bit wb_request;
	wire wb_ready;
	bit [31:0] wb_address;
	wire [31:0] wb_rdata;
	bit [31:0] wb_wdata;
	wire wb_cacheable = (wb_address == 4'h1);

	generate if (DCACHE_WB_QUEUE != 0) begin

	// Write queue.
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
		.i_cached(wb_cacheable)
	);

	end endgenerate
	
	generate if (DCACHE_WB_QUEUE == 0) begin

	// No write queue.
	assign o_bus_rw = wb_rw;
	assign o_bus_request = wb_request;
	assign wb_ready = i_bus_ready;
	assign o_bus_address = wb_address;
	assign wb_rdata = i_bus_rdata;
	assign o_bus_wdata = wb_wdata;

	end endgenerate

	// ================
	// DCache

	bit dcache_rw;
	bit dcache_request;
	bit dcache_flush;
	wire dcache_ready;
	wire [31:0] dcache_address;
	wire [31:0] dcache_rdata;
	bit [31:0] dcache_wdata;
	wire dcache_need_flush;
	wire dcache_cacheable = (i_data.mem_address[31:28] == 4'h1);

	generate if (DCACHE_SIZE > 0 && DCACHE_REGISTERED != 0) begin

		CPU_DCache_Reg #(
			.SIZE(DCACHE_SIZE)
		) dcache(
			.i_reset(i_reset),
			.i_clock(i_clock),

			.o_bus_rw(wb_rw),
			.o_bus_request(wb_request),
			.i_bus_ready(wb_ready),
			.o_bus_address(wb_address),
			.i_bus_rdata(wb_rdata),
			.o_bus_wdata(wb_wdata),

			.i_rw(dcache_rw),
			.i_request(dcache_request),
			.i_flush(dcache_flush),
			.o_ready(dcache_ready),
			.i_address(dcache_address),
			.o_rdata(dcache_rdata),
			.i_wdata(dcache_wdata),
			.i_cacheable(dcache_cacheable)
		);

		assign dcache_need_flush = 1'b1;

	end endgenerate

	generate if (DCACHE_SIZE > 0 && DCACHE_REGISTERED == 0) begin

		CPU_DCache_Comb #(
			.SIZE(DCACHE_SIZE)
		) dcache(
			.i_reset(i_reset),
			.i_clock(i_clock),

			.o_bus_rw(wb_rw),
			.o_bus_request(wb_request),
			.i_bus_ready(wb_ready),
			.o_bus_address(wb_address),
			.i_bus_rdata(wb_rdata),
			.o_bus_wdata(wb_wdata),

			.i_rw(dcache_rw),
			.i_request(dcache_request),
			.i_flush(dcache_flush),
			.o_ready(dcache_ready),
			.i_address(dcache_address),
			.o_rdata(dcache_rdata),
			.i_wdata(dcache_wdata),
			.i_cacheable(dcache_cacheable)
		);

		assign dcache_need_flush = 1'b1;

	end endgenerate	

	generate if (DCACHE_SIZE == 0) begin

		assign wb_rw = dcache_rw;
		assign wb_request = dcache_request;
		assign dcache_ready = wb_ready;
		assign wb_address = dcache_address;
		assign dcache_rdata = wb_rdata;
		assign wb_wdata = dcache_wdata;
		assign dcache_need_flush = 1'b0;

	end endgenerate

	assign o_data = data;
	assign dcache_address = { i_data.mem_address[31:2], 2'b00 };

	wire [1:0] address_byte_index = i_data.mem_address[1:0];
	wire [7:0] bus_rdata_byte = dcache_rdata >> (address_byte_index * 8);
	wire [15:0] bus_rdata_half = dcache_rdata >> (address_byte_index * 8);
	
	memory_data_t data = 0;
	state_t state = IDLE;
	bit [31:0] rmw_rdata = 0;
	bit last_strobe = 0;

	always_comb begin
		o_busy =
			(
				(i_data.strobe != last_strobe) &&
				(i_data.mem_read || i_data.mem_write || i_data.mem_flush)
			);
	end


	state_t next_state;
	bit next_last_strobe;
	bit next_data_strobe;
	bit [31:0] next_data_pc;
	bit [31:0] next_data_rd;
	register_t next_data_inst_rd;
	bit [31:0] next_rmw_rdata;

	always_ff @(posedge i_clock) begin
		state <= next_state;
		last_strobe <= next_last_strobe;
		data.pc <= next_data_pc;
		data.rd <= next_data_rd;
		data.inst_rd <= next_data_inst_rd;
		data.strobe <= next_data_strobe;
		rmw_rdata <= next_rmw_rdata;
	end

	always_comb begin
		next_state = state;
		next_last_strobe = last_strobe;
		next_data_pc = data.pc;
		next_data_rd = data.rd;
		next_data_inst_rd = data.inst_rd;
		next_data_strobe = data.strobe;
		next_rmw_rdata = rmw_rdata;

		dcache_request = 0;
		dcache_rw = 0;
		dcache_wdata = 0;
		dcache_flush = 0;

		unique case (state)
			IDLE: begin
				if (i_data.strobe != last_strobe) begin
					if (i_data.mem_read) begin
						dcache_request = 1;
						next_state = READ;
					end
					else if (i_data.mem_write) begin
						dcache_request = 1;
						if (i_data.mem_width == `MEMW_4) begin
							dcache_rw = 1;
							dcache_wdata = i_data.rd;
							next_state = WRITE_WORD;
						end
						else begin
							// Byte or half write, need to perform read-modify-write.
							next_state = WRITE_RMW_0;
						end
					end
					else if (i_data.mem_flush && dcache_need_flush) begin
						dcache_request = 1;
						dcache_flush = 1;
						next_state = FLUSH;
					end
					else begin
						next_data_pc = i_data.pc;
						next_data_rd = i_data.rd;
						next_data_inst_rd = i_data.inst_rd;
						next_data_strobe = ~data.strobe;
						next_last_strobe = i_data.strobe;
					end
				end
			end

			FLUSH: begin
				dcache_request = 1;
				dcache_flush = 1;

				if (dcache_ready) begin
					// dcache_request = 0;
					// dcache_flush = 0;

					next_data_pc = i_data.pc;
					next_data_rd = i_data.rd;
					next_data_inst_rd = i_data.inst_rd;				
					next_data_strobe = ~data.strobe;
					next_last_strobe = i_data.strobe;
					next_state = IDLE;
				end
			end

			READ: begin
				dcache_request = 1;
				dcache_rw = 0;

				if (dcache_ready) begin
					// dcache_request = 0;

					next_data_pc = i_data.pc;
					case (i_data.mem_width)
						`MEMW_4: next_data_rd = dcache_rdata;
						`MEMW_2: next_data_rd = { { 16{ i_data.mem_signed & bus_rdata_half[15] } }, bus_rdata_half[15:0] };
						`MEMW_1: next_data_rd = { { 24{ i_data.mem_signed & bus_rdata_byte[ 7] } }, bus_rdata_byte[ 7:0] };
						default: next_data_rd = 0;
					endcase
					next_data_inst_rd = i_data.mem_inst_rd;
					next_data_strobe = ~data.strobe;
					next_last_strobe = i_data.strobe;
					next_state = IDLE;
				end
			end

			WRITE_WORD: begin
				dcache_request = 1;
				dcache_rw = 1;
				dcache_wdata = i_data.rd;

				if (dcache_ready) begin
					// dcache_request = 0;
					// dcache_rw = 0;
					
					next_data_pc = i_data.pc;
					next_data_rd = i_data.rd;
					next_data_inst_rd = i_data.inst_rd;	
					next_data_strobe = ~data.strobe;
					next_last_strobe = i_data.strobe;
					next_state = IDLE;
				end
			end

			WRITE_RMW_0: begin
				dcache_request = 1;
				dcache_rw = 0;

				if (dcache_ready) begin
					// dcache_request = 0;

					next_rmw_rdata = dcache_rdata;
					next_state = WRITE_RMW_1;
				end
			end

			WRITE_RMW_1: begin
				dcache_request = 1;
				dcache_rw = 1;
				dcache_wdata = 0;

				if (i_data.mem_width == `MEMW_1) begin
					unique case (address_byte_index)
						2'd0: dcache_wdata = { rmw_rdata[31:24], rmw_rdata[23:16], rmw_rdata[15:8], i_data.rd[7:0] };
						2'd1: dcache_wdata = { rmw_rdata[31:24], rmw_rdata[23:16],  i_data.rd[7:0], rmw_rdata[7:0] };
						2'd2: dcache_wdata = { rmw_rdata[31:24],   i_data.rd[7:0], rmw_rdata[15:8], rmw_rdata[7:0] };
						2'd3: dcache_wdata = {   i_data.rd[7:0], rmw_rdata[23:16], rmw_rdata[15:8], rmw_rdata[7:0] };
					endcase
				end
				else begin	// width must be 2
					unique case (address_byte_index)
						2'd0: dcache_wdata = { rmw_rdata[31:16], i_data.rd[15:0] };
						2'd2: dcache_wdata = {  i_data.rd[15:0], rmw_rdata[15:0] };
						default: dcache_wdata = 0;
					endcase						
				end

				if (dcache_ready) begin
					// dcache_request = 0;
					// dcache_rw = 0;
					
					next_data_pc = i_data.pc;
					next_data_rd = i_data.rd;
					next_data_inst_rd = i_data.inst_rd;	

					next_data_strobe = ~data.strobe;
					next_last_strobe = i_data.strobe;
					next_state = IDLE;
				end					
			end

			default:
				next_state = IDLE;

		endcase
	end

endmodule
