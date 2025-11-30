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
	input CLOCK,
	output LED_p,
	output wire SDRAM_CLK,
	output wire SDRAM_CKE,
	output wire SDRAM_RAS_n,
	output wire SDRAM_CAS_n,
	output wire SDRAM_WE_n,
	output wire SDRAM_CE_n,
	output wire [12:0] SDRAM_A,
	output wire [1:0] SDRAM_BA,
	inout wire [15:0] SDRAM_DQ,
	output wire [1:0] SDRAM_DQM,
	input UART_RX,
	output UART_TX
);
	wire clock;
	wire clock_sdram;
	wire reset = 1'b0;


	wire pll_locked;
	PLL_ECP5 #(
		.CLKI_DIV(1),
		.CLKFB_DIV(4),
		
		.CLKOP_DIV(4),
		.CLKOP_CPHASE(4 - 1),
		
		.CLKOS_DIV(4),
		.CLKOS_CPHASE(5),
		
		.CLKOS2_DIV(4*3),
		.CLKOS2_CPHASE(4*3 - 1)
	) pll (
		.i_clk(CLOCK),
		.o_clk1(clock),
		.o_clk2(clock_sdram),
		.o_clk3(),
		.o_clk_locked(pll_locked)
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


	//=====================================
	// SDRAM
	wire sdram_request;
	wire sdram_rw;
	wire [31:0] sdram_address;
	wire [31:0] sdram_rdata;
	wire [31:0] sdram_wdata;
	wire [3:0] sdram_wmask;
	wire sdram_ready;

	bit [15:0] it_sdram_data_r;
	wire [15:0] it_sdram_data_w;
	wire it_sdram_data_rw;

	assign SDRAM_DQ = it_sdram_data_rw ? it_sdram_data_w : 16'hz;
	assign it_sdram_data_r = SDRAM_DQ;

	SDRAM_controller #(
		.FREQUENCY(`FREQUENCY),
		.SDRAM_DATA_WIDTH(16)
	) sdram(
		.i_reset(reset),
		.i_clock(clock),
		.i_clock_sdram(clock_sdram),

		.i_request(sdram_request),
		.i_rw(sdram_rw),
		.i_address(sdram_address),
		.i_wdata(sdram_wdata),
		.i_wmask(sdram_wmask),
		.o_rdata(sdram_rdata),
		.o_ready(sdram_ready),

		.sdram_clk(SDRAM_CLK),
		.sdram_clk_en(SDRAM_CKE),
		.sdram_cas_n(SDRAM_CAS_n),
		.sdram_cs_n(SDRAM_CE_n),
		.sdram_ras_n(SDRAM_RAS_n),
		.sdram_we_n(SDRAM_WE_n),
		.sdram_dqm(SDRAM_DQM),
		.sdram_bs(SDRAM_BA),
		.sdram_addr(SDRAM_A),
		.sdram_rdata(it_sdram_data_r),
		.sdram_wdata(it_sdram_data_w),
		.sdram_data_rw(it_sdram_data_rw)
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

		// 32'h0xxx_xxxx : ROM
		.o_s0_rw(),
		.o_s0_request(rom_request),
		.i_s0_ready(rom_ready),
		.o_s0_address(rom_address),
		.i_s0_rdata(rom_rdata),
		.o_s0_wdata(),
		.o_s0_wmask(),

		// 32'h1xxx_xxxx : SDRAM
		.o_s1_rw(sdram_rw),
		.o_s1_request(sdram_request),
		.i_s1_ready(sdram_ready),
		.o_s1_address(sdram_address),
		.i_s1_rdata(sdram_rdata),
		.o_s1_wdata(sdram_wdata),
		.o_s1_wmask(sdram_wmask),

		// 32'h2xxx_xxxx : UART
		.o_s2_rw(uart_rw),
		.o_s2_request(uart_request),
		.i_s2_ready(uart_ready),
		.o_s2_address(uart_address),
		.i_s2_rdata(uart_rdata),
		.o_s2_wdata(uart_wdata),
		.o_s2_wmask(),

		.i_m0_rw(1'b0),
		.i_m0_request(cpu_ibus_request),
		.o_m0_ready(cpu_ibus_ready),
		.i_m0_address(cpu_ibus_address),
		.o_m0_rdata(cpu_ibus_rdata),
		.i_m0_wdata(32'h0),
		.i_m0_wmask(4'h0),

		.i_m1_rw(cpu_dbus_rw),
		.i_m1_request(cpu_dbus_request),
		.o_m1_ready(cpu_dbus_ready),
		.i_m1_address(cpu_dbus_address),
		.o_m1_rdata(cpu_dbus_rdata),
		.i_m1_wdata(cpu_dbus_wdata),
		.i_m1_wmask(cpu_dbus_wmask)
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

endmodule
