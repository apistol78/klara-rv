/*
 Klara-RV
 Copyright (c) 2025 Anders Pistol.

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at https://mozilla.org/MPL/2.0/.
*/

`timescale 1ns/1ns
`default_nettype none

`define FREQUENCY 100_000_000

(* top *)
module SoC(
      input CLOCK_p,
      output LED_p,
	  input UART_RX,
	  output UART_TX
);
	wire clock;
	wire reset = 1'b0;


	PLL_ECP5 #(
		.CLKI_DIV(1),
		.CLKFB_DIV(4),
		.CLKOP_DIV(6),
		.CLKOP_CPHASE(0),
		.CLKOS_DIV(6),
		.CLKOS_CPHASE(5),
		.CLKOS2_DIV(6*3),
		.CLKOS2_CPHASE(0)
	) pll(
		.i_clk(CLOCK_p),
		.o_clk1(clock),
		.o_clk2(),
		.o_clk3(),
		.o_clk_locked()
	);

	//assign LED_p = cpu_dbus_request;

	//====================================================
	// ROM
	wire rom_request;
	wire [31:0] rom_address;
	wire [31:0] rom_rdata;
	wire rom_ready;

	SoC_BROM rom(
		.i_clock(clock),
		.i_request(rom_request),
		.i_address(rom_address),
		.o_rdata(rom_rdata),
		.o_ready(rom_ready)
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
		.SIZE(32'h400)
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
	// UART
	wire uart_request;
	wire uart_rw;
	wire [31:0] uart_address;
	wire [31:0] uart_wdata;
	wire [31:0] uart_rdata;
	wire uart_ready;

	UART #(
		.FREQUENCY(`FREQUENCY),
		.BAUDRATE(115200),
		.RX_FIFO_DEPTH(16),
		.TX_FIFO_DEPTH(16)
	) uart(
		.i_reset(reset),
		.i_clock(clock),
		.i_request(uart_request),
		.i_rw(uart_rw),
		.i_address(uart_address[1:0]),
		.i_wdata(uart_wdata),
		.o_rdata(uart_rdata),
		.o_ready(uart_ready),
		.o_interrupt(),
		.o_soft_reset(),
		// ---
		.UART_RX(UART_RX),
		.UART_TX(UART_TX)
	);

	//====================================================

	XBAR_2_3 bus(
		.i_reset(reset),
		.i_clock(clock),

		.o_s0_rw(),
		.o_s0_request(rom_request),
		.i_s0_ready(rom_ready),
		.o_s0_address(rom_address),
		.i_s0_rdata(rom_rdata),
		.o_s0_wdata(),

		.o_s1_rw(ram_rw),
		.o_s1_request(ram_request),
		.i_s1_ready(ram_ready),
		.o_s1_address(ram_address),
		.i_s1_rdata(ram_rdata),
		.o_s1_wdata(ram_wdata),

		.o_s2_rw(uart_rw),
		.o_s2_request(uart_request),
		.i_s2_ready(uart_ready),
		.o_s2_address(uart_address),
		.i_s2_rdata(uart_rdata),
		.o_s2_wdata(uart_wdata),

		.i_m0_rw(1'b0),
		.i_m0_request(cpu_ibus_request),
		.o_m0_ready(cpu_ibus_ready),
		.i_m0_address(cpu_ibus_address),
		.o_m0_rdata(cpu_ibus_rdata),
		.i_m0_wdata(32'h0),

		.i_m1_rw(cpu_dbus_rw),
		.i_m1_request(cpu_dbus_request),
		.o_m1_ready(cpu_dbus_ready),
		.i_m1_address(cpu_dbus_address),
		.o_m1_rdata(cpu_dbus_rdata),
		.i_m1_wdata(cpu_dbus_wdata)
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

		// Debug
		.o_icache_hit(),
		.o_icache_miss(),
		.o_dcache_hit(),
		.o_dcache_miss(),
		.o_execute_busy(),
		.o_memory_busy(),
		.o_fault(cpu_fault)
	);

endmodule
