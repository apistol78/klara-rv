/*
 Klara-RV
 Copyright (c) 2025 Anders Pistol.

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at https://mozilla.org/MPL/2.0/.
*/

`timescale 1ns/1ns
`define FREQUENCY 25000000

(* top *)
module Verify(
	  input CLOCK_p
);
	wire clock = CLOCK_p;
	wire reset = 1'b0;

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
	wire [3:0] cpu_dbus_wmask;
	wire cpu_fault;

	CPU #(
		.FREQUENCY(`FREQUENCY),
		.DCACHE_SIZE(0),
		.DCACHE_REGISTERED(1),
		.ICACHE_SIZE(1),
		.ICACHE_REGISTERED(1)		
	) cpu(
		.i_reset(reset),
		.i_clock(clock),

		// Control
		.i_timer_interrupt(1'b0),
		.i_external_interrupt(1'b0),

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
		.o_dbus_wmask(cpu_dbus_wmask),

		// Debug
		.o_execute_busy(),
		.o_memory_busy(),
		.o_fault(cpu_fault)
	);

	//====================================================
	// ROM
	wire rom_request;
	wire [31:0] rom_address;
	wire [31:0] rom_rdata;
	wire rom_ready;

	BRAM rom(
		.i_clock(clock),
		.i_request(rom_request),
		.i_rw(1'b0),
		.i_address(rom_address),
		.i_wdata(0),
		.o_rdata(rom_rdata),
		.o_ready(rom_ready),
		.o_valid()
	);

	//====================================================
	// RAM
	wire ram_request;
	wire ram_rw;
	wire [31:0] ram_address;
	wire [31:0] ram_wdata;
	wire [31:0] ram_rdata;
	wire ram_ready;

	BRAM #(
		.WIDTH(32),
		.SIZE(32'h8000),
		.ADDR_LSH(2)
	) ram(
		.i_clock(clock),
		.i_request(ram_request),
		.i_rw(ram_rw),
		.i_address(ram_address),
		.i_wdata(ram_wdata),
		.o_rdata(ram_rdata),
		.o_ready(ram_ready),
		.o_valid()
	);

	//====================================================
	// XBAR

	XBAR_2_2 xbar(
		.i_reset(1'b0),
		.i_clock(clock),

		// CPU instruction bus
		.i_m0_rw(1'b0),
		.i_m0_request(cpu_ibus_request),
		.o_m0_ready(cpu_ibus_ready),
		.i_m0_address(cpu_ibus_address),
		.o_m0_rdata(cpu_ibus_rdata),
		.i_m0_wdata(32'h0),
		.i_m0_wmask(4'h0),

		// CPU data bus
		.i_m1_rw(cpu_dbus_rw),
		.i_m1_request(cpu_dbus_request),
		.o_m1_ready(cpu_dbus_ready),
		.i_m1_address(cpu_dbus_address),
		.o_m1_rdata(cpu_dbus_rdata),
		.i_m1_wdata(cpu_dbus_wdata),
		.i_m1_wmask(cpu_dbus_wmask),

		// 32'h0xxx_xxxx : ROM
		.o_s0_rw(),
		.o_s0_request(rom_request),
		.i_s0_ready(rom_ready),
		.o_s0_address(rom_address),
		.i_s0_rdata(rom_rdata),
		.o_s0_wdata(),
		.o_s0_wmask(),

		// 32'h1xxx_xxxx : RAM
		.o_s1_rw(ram_rw),
		.o_s1_request(ram_request),
		.i_s1_ready(ram_ready),
		.o_s1_address(ram_address),
		.i_s1_rdata(ram_rdata),
		.o_s1_wdata(ram_wdata),
		.o_s1_wmask()
	);


endmodule
