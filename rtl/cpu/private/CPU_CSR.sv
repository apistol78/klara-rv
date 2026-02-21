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

module CPU_CSR #(
	parameter FREQUENCY,
	parameter VENDORID,
	parameter ARCHID,
	parameter IMPID,
	parameter HARTID
)(
	input wire i_reset,
	input wire i_clock,

	// External interrupt input.
	input wire i_timer_interrupt,
	input wire i_external_interrupt,

	// Software interrupt input.
	input wire i_ecall,
	input wire i_mret,

	// Instruction I/O access.
	input wire [11:0] i_index,
	output bit [31:0] o_rdata,
	input wire i_wdata_wr,
	input wire [31:0] i_wdata,

	// Direct read access.
	output wire [31:0] o_epc,
	output wire [31:0] o_status,
	output wire [31:0] o_ie,
	output wire [31:0] o_ip,
	output wire [31:0] o_scratch,

	// Pending interrupt output.
	output bit o_irq_pending,
	output bit [31:0] o_irq_pc,
	input wire i_irq_dispatched,
	input wire [31:0] i_irq_epc,

	// Retired instructions.
	input wire [63:0] i_retired
);
	localparam PRESCALE = FREQUENCY / 1000;
	localparam PRESCALE_WIDTH = $clog2(PRESCALE);

	bit mstatus_mpie = 0;
	bit mstatus_mie = 0;
	bit mie_meie = 1'b1; 
	bit mie_mtie = 1'b1;
	bit mie_msie = 1'b1;
	bit [31:0] mtvec = 0;
	bit [31:0] mepc = 0;
	bit [31:0] mcause = 0;
	bit mip_meip = 0;
	bit mip_mtip = 0;
	bit mip_msip = 0;
	bit [31:0] mscratch = 0;

	wire [31:0] mstatus = { 27'b0, mstatus_mpie, mstatus_mie, 3'b0 };
	wire [31:0] mie = { 20'b0, mie_meie, 3'b0, mie_mtie, 3'b0, mie_msie, 3'b0 };	
	wire [31:0] mip = { 20'b0, mip_meip, 3'b0, mip_mtip, 3'b0, mip_msip, 3'b0 };

	bit [63:0] cycle = 64'd0;
	bit [63:0] wtime = 64'd0;
	bit [PRESCALE_WIDTH - 1:0] prescale = 0;

	bit waiting_on_mret = 1'b0;

	assign o_epc = mepc;
	assign o_status = mstatus;
	assign o_ie = mie;
	assign o_ip = mip;
	assign o_scratch = mscratch;

	// Read CSR value by index.
	always_comb begin
		o_rdata = 0;
		if (i_index == `CSR_MSTATUS)
			o_rdata = mstatus;
		else if (i_index == `CSR_MIE)
			o_rdata = mie;
		else if (i_index == `CSR_MTVEC)
			o_rdata = mtvec;
		else if (i_index == `CSR_MSCRATCH)
			o_rdata = mscratch;
		else if (i_index == `CSR_MEPC)
			o_rdata = mepc;
		else if (i_index == `CSR_MCAUSE)
			o_rdata = mcause;
		else if (i_index == `CSR_MIP)
			o_rdata = mip;
		else if (i_index == `CSR_CYCLE)
			o_rdata = cycle[31:0];
		else if (i_index == `CSR_CYCLEH)
			o_rdata = cycle[63:32];
		else if (i_index == `CSR_TIME)
			o_rdata = wtime[31:0];
		else if (i_index == `CSR_TIMEH)
			o_rdata = wtime[63:32];
		else if (i_index == `CSR_INSTRET)
			o_rdata = i_retired[31:0];
		else if (i_index == `CSR_INSTRETH)
			o_rdata = i_retired[63:32];
		else if (i_index == `CSR_MVENDORID)
			o_rdata = VENDORID;
		else if (i_index == `CSR_MARCHID)
			o_rdata = ARCHID;
		else if (i_index == `CSR_MIMPID)
			o_rdata = IMPID;
		else if (i_index == `CSR_MHARTID)
			o_rdata = HARTID;
	end

	always_ff @(posedge i_clock) begin
		if (i_reset) begin
			mstatus_mpie <= 0;
			mstatus_mie <= 0;
			mie_meie <= 1'b1;
			mie_mtie <= 1'b1;
			mie_msie <= 1'b1;
			mtvec <= 0;
			mepc <= 0;
			mcause <= 0;
			mip_meip <= 0;
			mip_mtip <= 0;
			mip_msip <= 0;
			mscratch <= 0;
			o_irq_pending <= 1'b0;
			o_irq_pc <= 0;
			waiting_on_mret <= 1'b0;
		end
		else begin
			// Write CSR registers.
			if (i_wdata_wr) begin
				if (i_index == `CSR_MSTATUS) begin
					mstatus_mie <= i_wdata[3];
				end
				else if (i_index == `CSR_MIE) begin
					mie_meie <= i_wdata[11];
					mie_mtie <= i_wdata[7];
					mie_msie <= i_wdata[3];
				end
				else if (i_index == `CSR_MTVEC)
					mtvec <= i_wdata;
				else if (i_index == `CSR_MSCRATCH)
					mscratch <= i_wdata;
				else if (i_index == `CSR_MEPC)
					mepc <= i_wdata;
				else if (i_index == `CSR_MIP) begin
					//
					// We allow pending interrupts to be written so we
					// can yield current thread by forcing timer interrupt.
					//

					if (mie_meie)
						mip_meip <= i_wdata[11];
					
					if (mie_mtie)
						mip_mtip <= i_wdata[7];

					if (mie_msie)
						mip_msip <= i_wdata[3];
				end					
			end

			// Latch interrupts pending.
			if (i_timer_interrupt && mie_mtie) begin
				mip_mtip <= 1'b1;
			end
			if (i_external_interrupt && mie_meie) begin
				mip_meip <= 1'b1;
			end
			if (i_ecall && mie_msie) begin
				mip_msip <= 1'b1;
			end

			// Issue interrupts.
			if (!waiting_on_mret && mstatus_mie) begin

				// Handle in priority order; external interrupts have higest prio.
				if (mip_meip) begin
					mcause <= 32'h80000000 | (1 << 11);					
					mip_meip <= 1'b0;
				end
				else if (mip_mtip) begin
					mcause <= 32'h80000000 | (1 << 7);
					mip_mtip <= 1'b0;
				end
				else if (mip_msip) begin
					mcause <= 32'h00000000 | (1 << 11);					
					mip_msip <= 1'b0;
				end

				if (mip_meip || mip_mtip || mip_msip) begin
					o_irq_pending <= 1'b1;
					o_irq_pc <= mtvec;

					mstatus_mpie <= mstatus_mie;
					mstatus_mie <= 1'b0;

					waiting_on_mret <= 1'b1;
				end
			end
		
			// IRQ has been dispatched by the fetch unit;
			// save interrupt return address.
			if (i_irq_dispatched) begin
				o_irq_pending <= 1'b0;
				mepc <= i_irq_epc;
			end

			// IRQ has returned by the execution unit;
			// restore interrupt enable from "stack" and
			// make CSR ready to dispatch another interrupt.
			if (i_mret) begin
				mstatus_mie <= mstatus_mpie;
				mstatus_mpie <= 1'b0;
				waiting_on_mret <= 1'b0;
			end
		end
	end

	// Cycle and wall time counter.
	always_ff @(posedge i_clock) begin
		if (i_reset) begin
			wtime <= 64'd0;
			prescale <= PRESCALE;
			cycle <= 0;
		end
		else begin
			prescale <= prescale - 1;
			if (prescale == 0) begin
				wtime <= wtime + 64'd1;
				prescale <= PRESCALE;
			end
			cycle <= cycle + 64'd1;
		end
	end

endmodule
