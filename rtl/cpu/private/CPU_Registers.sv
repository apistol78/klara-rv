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

module CPU_Registers #(
	parameter STACK_POINTER
)(
	input wire i_reset,
	input wire i_clock,

	input fetch_data_t i_fetch_data,
	output wire [31:0] o_rs1,
	output wire [31:0] o_rs2,
	output wire [31:0] o_rs3,

	input memory_data_t i_memory_data,

	// Debug
	output wire [31:0] o_debug_registers [32]
);
	bit last_write_strobe = 1'b0;

// `ifdef FPU_ENABLE
// 	bit [31:0] r[64];
// `else
	bit [31:0] r[32];
// `endif

	bit [31:0] rs1 = 0;
	bit [31:0] rs2 = 0;
	bit [31:0] rs3 = 0;

	assign o_rs1 = rs1;
	assign o_rs2 = rs2;
	assign o_rs3 = rs3;

	assign o_debug_registers = r;

	integer I;
	initial begin
		// Integer registers.
		for (I = 0; I < 32; ++I)
			r[I] = 32'h0000_0000;

// `ifdef FPU_ENABLE
// 		// Float point registers.
// 		for (I = 32; I < 64; ++I)
// 			r[I] = 32'h0000_0000;
// `endif

		r[ 2] = STACK_POINTER;
	end

	always_ff @(posedge i_clock)
	begin
		if (i_reset) begin
			rs1 <= 0;
			rs2 <= 0;
			rs3 <= 0;

			last_write_strobe <= 1'b0;

			// Integer registers.
			for (I = 0; I < 32; ++I)
				r[I] <= 32'h0000_0000;

// `ifdef FPU_ENABLE
// 			// Float point registers.
// 			for (I = 32; I < 64; ++I)
// 				r[I] <= 32'h0000_0000;
// `endif

			r[ 2] <= STACK_POINTER;
		end
		else begin

			// Read first.
			rs1 <= r[i_fetch_data.inst_rs1];
			rs2 <= r[i_fetch_data.inst_rs2];
			rs3 <= r[i_fetch_data.inst_rs3];

			// Write later.
			if (i_memory_data.strobe != last_write_strobe) begin
				// Never write to "zero" register.
				if (|i_memory_data.inst_rd) 
					r[i_memory_data.inst_rd] <= i_memory_data.rd;
				last_write_strobe <= i_memory_data.strobe;
			end
		end
	end

endmodule