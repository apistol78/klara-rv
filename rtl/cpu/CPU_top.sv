/*
 Klara-RV
 Copyright (c) 2025 Anders Pistol.

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at https://mozilla.org/MPL/2.0/.
*/

`timescale 1ns/1ns
`default_nettype none

`define FREQUENCY 10000000

(* top *)
module CPU_top(
	input reset,
	input clock,
	input timer_interrupt,
	input external_interrupt,
	output bus_rw,
	output bus_request,
	input bus_ready,
	output [31:0] bus_address,
	input [31:0] bus_rdata,
	output [31:0] bus_wdata,
	output cpu_fault
);

	//====================================================
	// CPU bus multiplexer
	DualPort bus(
		.i_reset(reset),
		.i_clock(clock),

		.o_bus_rw(bus_rw),
		.o_bus_request(bus_request),
		.i_bus_ready(bus_ready),
		.o_bus_address(bus_address),
		.i_bus_rdata(bus_rdata),
		.o_bus_wdata(bus_wdata),

		.i_pa_rw(1'b0),
		.i_pa_request(cpu_ibus_request),
		.o_pa_ready(cpu_ibus_ready),
		.i_pa_address(cpu_ibus_address),
		.o_pa_rdata(cpu_ibus_rdata),
		.i_pa_wdata(32'h0),

		.i_pb_rw(cpu_dbus_rw),
		.i_pb_request(cpu_dbus_request),
		.o_pb_ready(cpu_dbus_ready),
		.i_pb_address(cpu_dbus_address),
		.o_pb_rdata(cpu_dbus_rdata),
		.i_pb_wdata(cpu_dbus_wdata),

		.i_pc_rw(1'b0),
		.i_pc_request(1'b0),
		.o_pc_ready(),
		.i_pc_address(32'h0),
		.o_pc_rdata(),
		.i_pc_wdata(32'h0)
	);

	//====================================================
	// CPU
	wire cpu_ibus_request;
	wire cpu_ibus_ready;
	wire [31:0] cpu_ibus_address;
	wire [31:0] cpu_ibus_rdata;
	wire cpu_dbus_rw;
	wire cpu_dbus_request;
	wire cpu_dbus_ready;
	wire [31:0] cpu_dbus_address;
	wire [31:0] cpu_dbus_rdata;
	wire [31:0] cpu_dbus_wdata;

	CPU #(
		.FREQUENCY(`FREQUENCY),
		.DCACHE_SIZE(12),
		.DCACHE_REGISTERED(0),
		.DCACHE_WB_QUEUE(1),
		.ICACHE_SIZE(12),
		.ICACHE_REGISTERED(1)
	) cpu(
		.i_reset(reset),
		.i_clock(clock),

		// Control
		.i_timer_interrupt(timer_interrupt),
		.i_external_interrupt(external_interrupt),

		// Instruction bus
		.o_ibus_request(cpu_ibus_request),
		.i_ibus_ready(cpu_ibus_ready),
		.o_ibus_address(cpu_ibus_address),
		.i_ibus_rdata(cpu_ibus_rdata),

		// Data bus
		.o_dbus_rw(cpu_dbus_rw),
		.o_dbus_request(cpu_dbus_request),
		.i_dbus_ready(cpu_dbus_ready),
		.o_dbus_address(cpu_dbus_address),
		.i_dbus_rdata(cpu_dbus_rdata),
		.o_dbus_wdata(cpu_dbus_wdata),

		// Debug
		.o_execute_busy(),
		.o_memory_busy(),
		.o_fault(cpu_fault)
	);

endmodule;
