/*
 Klara-RV
 Copyright (c) 2025 Anders Pistol.

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at https://mozilla.org/MPL/2.0/.
*/
`include "private/CPU_Types.sv"

// https://zipcpu.com/blog/2017/08/14/strategies-for-pipelining.html

`timescale 1ns/1ns
`default_nettype none

interface CPU_XCPI;
	logic [31:0] instruction;
endinterface

module CPU #(
	parameter FREQUENCY,
	parameter RESET_VECTOR = 32'h00000000,
	parameter STACK_POINTER = 32'h10000400,
	parameter VENDORID = 32'h0,
	parameter ARCHID = 32'h0,
	parameter IMPID = 32'h0,
	parameter HARTID = 32'h0,
	parameter ICACHE_SIZE = 13,
	parameter ICACHE_REGISTERED = 0,
	parameter DCACHE_SIZE = 14,
	parameter DCACHE_REGISTERED = 1,
	parameter DCACHE_WB_QUEUE = 0
)(
	input wire i_reset,
	input wire i_clock,			// CPU clock

	// Control
	input wire i_timer_interrupt,
	input wire i_external_interrupt,
	
	// Instruction bus
	output wire o_ibus_request,			// IO request.
	input wire i_ibus_ready,			// IO request ready.
	output wire [31:0] o_ibus_address,	// Address
	input wire [31:0] i_ibus_rdata,		// Read data
	
	// Data bus
	output wire o_dbus_rw,				// Data read/write
	output wire o_dbus_request,			// IO request.
	input wire i_dbus_ready,			// IO request ready.
	output wire [31:0] o_dbus_address,	// Address
	input wire [31:0] i_dbus_rdata,		// Read data
	output wire [31:0] o_dbus_wdata,	// Write data
	output wire [3:0] o_dbus_wmask,		// Write mask
	
	// Debug
	output wire o_execute_busy,
	output wire o_memory_busy,
	output wire o_fault,
	output wire [31:0] o_debug_pc,
	output wire [31:0] o_debug_registers [32],
	output wire [31:0] o_debug_epc,
	output wire [31:0] o_debug_status,
	output wire [31:0] o_debug_ie,
	output wire [31:0] o_debug_ip,
	output wire [31:0] o_debug_pc_trace [4]
);

	//====================================================
	// "Forward declarations"

	fetch_data_t fetch_data;

	wire execute_ecall;
	wire execute_mret;
	wire execute_jump;
	wire [31:0] execute_jump_pc;
	wire execute_busy;
	execute_data_t execute_data;

	wire memory_busy;
	memory_data_t memory_data;

	writeback_data_t writeback_data;

	//====================================================
	// CSR

	wire [11:0] csr_index;
	wire [31:0] csr_rdata;
	wire csr_wdata_wr;
	wire [31:0] csr_wdata;
	wire [31:0] csr_epc;
	wire [31:0] csr_status;
	wire [31:0] csr_ie;
	wire [31:0] csr_ip;
	wire [63:0] csr_retired;
	wire csr_irq_pending;
	wire [31:0] csr_irq_pc;
	wire csr_irq_dispatched;
	wire [31:0] csr_irq_epc;

	CPU_CSR #(
		.FREQUENCY(FREQUENCY),
		.VENDORID(VENDORID),
		.ARCHID(ARCHID),
		.IMPID(IMPID),
		.HARTID(HARTID)
	) csr(
		.i_reset(i_reset),
		.i_clock(i_clock),

		.i_timer_interrupt(i_timer_interrupt),
		.i_external_interrupt(i_external_interrupt),

		.i_ecall(execute_ecall),
		.i_mret(execute_mret),

		.i_index(csr_index),
		.o_rdata(csr_rdata),
		.i_wdata_wr(csr_wdata_wr),
		.i_wdata(csr_wdata),

		.o_epc(csr_epc),
		.o_status(csr_status),
		.o_ie(csr_ie),
		.o_ip(csr_ip),
		.o_scratch(),

		.i_retired(csr_retired),

		.o_irq_pending(csr_irq_pending),
		.o_irq_pc(csr_irq_pc),
		.i_irq_dispatched(csr_irq_dispatched),
		.i_irq_epc(csr_irq_epc)
	);

	//====================================================
	// REGISTERS

	wire [31:0] rs1;
	wire [31:0] rs2;
	wire [31:0] rs3;

	CPU_Registers #(
		.STACK_POINTER(STACK_POINTER)
	) registers(
		.i_reset(i_reset),
		.i_clock(i_clock),

		.i_fetch_data(fetch_data),
		.o_rs1(rs1),
		.o_rs2(rs2),
		.o_rs3(rs3),

		.i_memory_data(memory_data),

		// Debug
		.o_debug_registers(o_debug_registers)
	);

	//====================================================
	// FETCH

	fetch_data_t fetch_data_0;
	
	CPU_Fetch #(
		.RESET_VECTOR(RESET_VECTOR),
		.ICACHE_SIZE(ICACHE_SIZE),
		.ICACHE_REGISTERED(ICACHE_REGISTERED)
	) fetch(
		.i_reset(i_reset),
		.i_clock(i_clock),

		// Control
		.i_jump(execute_jump),
		.i_jump_pc(execute_jump_pc),

		// Interrupt
		.i_irq_pending(csr_irq_pending),
		.i_irq_pc(csr_irq_pc),
		.o_irq_dispatched(csr_irq_dispatched),
		.o_irq_epc(csr_irq_epc),

		// Bus
		.o_bus_request(o_ibus_request),
		.i_bus_ready(i_ibus_ready),
		.o_bus_address(o_ibus_address),
		.i_bus_rdata(i_ibus_rdata),

		// Output
		.i_busy(execute_busy | memory_busy),
		.o_data(fetch_data_0),

		// Debug
		.o_debug_pc(o_debug_pc)
	);

	CPU_SkidBuffer #(
		.DW($bits(fetch_data))
	) fetch_skid(
		.i_reset(i_reset),
		.i_clock(i_clock),

		.i_busy(execute_busy | memory_busy),
		.i_data(fetch_data_0),
		.o_data(fetch_data)
	);

	//====================================================
	// DECODE

	wire decode_fault;
	decode_data_t decode_data;

	CPU_Decode decode(
		.i_reset(i_reset),
		.i_clock(i_clock),
		.o_fault(decode_fault),

		// Input
		.i_data(fetch_data),

		// Output
		.o_data(decode_data)
	);

	//====================================================
	// HAZARD

	wire [31:0] forward_rs1;
	wire [31:0] forward_rs2;
	wire [31:0] forward_rs3;

	CPU_Forward forward(
		.i_decode_data(decode_data),
		.i_execute_data(execute_data),
		.i_memory_data(memory_data),
		.i_writeback_data(writeback_data),

		.i_rs1(rs1),
		.i_rs2(rs2),
		.i_rs3(rs3),

		.o_rs1(forward_rs1),
		.o_rs2(forward_rs2),
		.o_rs3(forward_rs3)
	);

	//====================================================
	// EXECUTE

	wire execute_fault;
	
	CPU_Execute execute(
		.i_reset(i_reset),
		.i_clock(i_clock),
		.o_fault(execute_fault),

		// CSR
		.o_csr_index(csr_index),
		.i_csr_rdata(csr_rdata),
		.o_csr_wdata_wr(csr_wdata_wr),
		.o_csr_wdata(csr_wdata),
		.i_epc(csr_epc),

		// Control
		.o_jump(execute_jump),
		.o_jump_pc(execute_jump_pc),
		.o_ecall(execute_ecall),
		.o_mret(execute_mret),

		// Input
		.o_busy(execute_busy),
		.i_data(decode_data),
		.i_rs1(forward_rs1),
		.i_rs2(forward_rs2),
		.i_rs3(forward_rs3),
	
		// Output
		.i_memory_busy(memory_busy),
		.o_data(execute_data)
	);

	//====================================================
	// MEMORY

	CPU_Memory #(
		.DCACHE_SIZE(DCACHE_SIZE),
		.DCACHE_REGISTERED(DCACHE_REGISTERED),
		.DCACHE_WB_QUEUE(DCACHE_WB_QUEUE)
	) memory(
		.i_reset(i_reset),
		.i_clock(i_clock),
	
		// Bus
		.o_bus_rw(o_dbus_rw),
		.o_bus_request(o_dbus_request),
		.i_bus_ready(i_dbus_ready),
		.o_bus_address(o_dbus_address),
		.i_bus_rdata(i_dbus_rdata),
		.o_bus_wdata(o_dbus_wdata),
		.o_bus_wmask(o_dbus_wmask),

		// Input
		.o_busy(memory_busy),
		.i_data(execute_data),

		// Output
		.o_data(memory_data)
	);

	//====================================================
	// WRITEBACK

	CPU_Writeback writeback(
		.i_reset(i_reset),
		.i_clock(i_clock),

		// Input
		.i_data(memory_data),

		// Output
		.o_data(writeback_data),
		.o_retired(csr_retired)
	);

	//====================================================
	
	assign o_execute_busy = execute_busy;
	assign o_memory_busy = memory_busy;
	assign o_fault = decode_fault || execute_fault;
	assign o_debug_epc = csr_epc;
	assign o_debug_status = csr_status;
	assign o_debug_ie = csr_ie;
	assign o_debug_ip = csr_ip;

	//====================================================

	bit [31:0] pc_trace [4];

	initial begin
		pc_trace[0] = 32'h0;
		pc_trace[1] = 32'h0;
		pc_trace[2] = 32'h0;
		pc_trace[3] = 32'h0;
	end

	always_ff @(posedge i_clock) begin
		if (!o_fault && o_debug_pc != pc_trace[0]) begin
			pc_trace[3] <= pc_trace[2];
			pc_trace[2] <= pc_trace[1];
			pc_trace[1] <= pc_trace[0];
			pc_trace[0] <= o_debug_pc;
		end
	end

	assign o_debug_pc_trace = pc_trace;

endmodule
