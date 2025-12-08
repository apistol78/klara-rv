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

module CPU_ALU(
	input wire [4:0] i_op,

	input wire [31:0] i_op1,
	input wire [31:0] i_op2,

	output wire [31:0] o_result,
	output wire [31:0] o_shift_result,
	output wire [31:0] o_signed_sum_result,
	output wire o_compare_result
);

	wire [31:0] signed_sum = $signed(i_op1) + $signed(i_op2);
	wire [31:0] unsigned_sum = i_op1 + i_op2;
	wire [31:0] signed_diff = $signed(i_op1) - $signed(i_op2);
	wire [31:0] and_result = i_op1 & i_op2;
	wire [31:0] or_result = i_op1 | i_op2;
	wire [31:0] xor_result = i_op1 ^ i_op2;
	wire [31:0] shl_result = i_op1 << i_op2[4:0];
	wire [31:0] shr_result = i_op1 >> i_op2[4:0];
	wire [31:0] ashr_result = $signed(i_op1) >>> i_op2[4:0];

	wire [31:0] signed_lt_result = ($signed(i_op1) < $signed(i_op2)) ? 1'b1 : 1'b0;
	wire [31:0] unsigned_lt_result = (i_op1 < i_op2) ? 1'b1 : 1'b0;
	wire [31:0] equal_result = (i_op1 == i_op2) ? 1'b1 : 1'b0;
	wire [31:0] not_equal_result = (i_op1 != i_op2) ? 1'b1 : 1'b0;
	wire [31:0] signed_get_result = ($signed(i_op1) >= $signed(i_op2)) ? 1'b1 : 1'b0;
	wire [31:0] unsigned_get_result = (i_op1 >= i_op2) ? 1'b1 : 1'b0;
	
// Zba
	wire [31:0] signed_sum_sh1 = ($signed(i_op1) << 1) + $signed(i_op2);
	wire [31:0] unsigned_sum_sh1 = (i_op1 << 1) + i_op2;
	wire [31:0] signed_sum_sh2 = ($signed(i_op1) << 2) + $signed(i_op2);
	wire [31:0] unsigned_sum_sh2 = (i_op1 << 2) + i_op2;
	wire [31:0] signed_sum_sh3 = ($signed(i_op1) << 3) + $signed(i_op2);
	wire [31:0] unsigned_sum_sh3 = (i_op1 << 3) + i_op2;
	wire [31:0] unsigned_shl_result = i_op1 << i_op2[4:0];

	assign o_result =
		i_op == `OP_SIGNED_ADD ? signed_sum :
		i_op == `OP_UNSIGNED_ADD ? unsigned_sum :
		i_op == `OP_SIGNED_SUB ? signed_diff :
		i_op == `OP_AND ? and_result :
		i_op == `OP_OR ? or_result :
		i_op == `OP_XOR ? xor_result :
// Zba
		i_op == `OP_SIGNED_ADD_SH1 ? signed_sum_sh1 :
		i_op == `OP_UNSIGNED_ADD_SH1 ? unsigned_sum_sh1 :
		i_op == `OP_SIGNED_ADD_SH2 ? signed_sum_sh2 :
		i_op == `OP_UNSIGNED_ADD_SH2 ? unsigned_sum_sh2 :
		i_op == `OP_SIGNED_ADD_SH3 ? signed_sum_sh3 :
		i_op == `OP_UNSIGNED_ADD_SH3 ? unsigned_sum_sh3 :
		32'd0;

	assign o_shift_result =
		i_op == `OP_SHIFT_LEFT ? shl_result :
		i_op == `OP_SHIFT_RIGHT ? shr_result :
		i_op == `OP_ARITHMETIC_SHIFT_RIGHT ? ashr_result :
// Zba
		i_op == `OP_UNSIGNED_SHIFT_LEFT ? unsigned_shl_result :
		32'd0;
		
	assign o_signed_sum_result = signed_sum;

	assign o_compare_result =
		i_op == `OP_SIGNED_LESS_THAN ? signed_lt_result :
		i_op == `OP_UNSIGNED_LESS_THAN ? unsigned_lt_result :
		i_op == `OP_EQUAL ? equal_result :
		i_op == `OP_NOT_EQUAL ? not_equal_result :
		i_op == `OP_SIGNED_GREATER_EQUAL ? signed_get_result :
		i_op == `OP_UNSIGNED_GREATER_EQUAL ? unsigned_get_result :
		1'b0;
		
endmodule
