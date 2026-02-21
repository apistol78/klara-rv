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

module CPU_BranchPrediction (
	input wire i_reset,
	input wire i_clock,
	input wire [31:0] i_pc,

	input wire i_is_jal,
	input wire i_is_jump_conditional,
	input wire [31:0] i_inst_B_imm,
	input wire [31:0] i_inst_J_imm,

	input wire [31:0] i_pc_launch,
	output bit [31:0] o_pc_hint,

	input wire i_jump,
	input wire [31:0] i_jump_pc,

	output bit [31:0] o_debug_bp_hit,
	output bit [31:0] o_debug_bp_miss
);
	bit [26:0] from_pc [8];
	bit [31:0] target_pc [8];

	wire [2:0] i_pc_tag = i_pc[4:2];
	wire [26:0] i_pc_rest = i_pc[31:5];

	wire [2:0] i_pc_launch_tag = i_pc_launch[4:2];
	wire [26:0] i_pc_launch_rest = i_pc_launch[31:5];

	initial begin
		o_pc_hint = 0;
		o_debug_bp_hit = 0;
		o_debug_bp_miss = 0;
	end

	always_ff @(posedge i_clock) begin
		if (i_reset) begin
			o_pc_hint <= 0;
		end
		else begin
			o_pc_hint <= i_pc;
			if (from_pc[i_pc_tag] == i_pc_rest)
				o_pc_hint <= target_pc[i_pc_tag];
			else if (i_is_jal)
				o_pc_hint <= i_pc + i_inst_J_imm;
			else if (i_is_jump_conditional)
				o_pc_hint <= i_pc + i_inst_B_imm;
		end
	end

	always_ff @(posedge i_clock) begin
		if (i_reset) begin
			for (integer i = 0; i < 8; i = i + 1) begin
				from_pc[i] <= 0;
				target_pc[i] <= 0;
			end
			o_debug_bp_hit <= 0;
			o_debug_bp_miss <= 0;
		end
		else begin
			if (i_jump) begin
				if (i_jump_pc != i_pc) begin
					from_pc[i_pc_launch_tag] <= i_pc_launch_rest;
					target_pc[i_pc_launch_tag] <= i_jump_pc;
					o_debug_bp_hit <= o_debug_bp_hit + 1;
				end
				else
					o_debug_bp_miss <= o_debug_bp_miss + 1;
			end
		end
	end

endmodule
