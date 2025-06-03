/*
 Klara-RV
 Copyright (c) 2025 Anders Pistol.

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at https://mozilla.org/MPL/2.0/.
*/

`timescale 1ns/1ns

module CPU_Multiply(
	input i_clock,
	input i_latch,
	input i_signed,
	input [31:0] i_op1,
	input [31:0] i_op2,
	output o_ready,
	output [63:0] o_result
);

	wire s1 = i_op1[31];
	wire s2 = i_op2[31];

	bit r0_request;
	bit [31:0] r0_uop1;
	bit [31:0] r0_uop2;

	bit r1_request;
	bit [63:0] r1_intermediate;

	bit r2_request;
	bit [63:0] r2_result;
	
	bit [1:0] s;
	always_ff @(posedge i_clock) begin
		if (i_latch)
			s <= { s1, s2 };

		// 1
		r0_request <= i_latch;
		r0_uop1 <= (i_signed && s1) ? -$signed(i_op1) : i_op1;
		r0_uop2 <= (i_signed && s2) ? -$signed(i_op2) : i_op2;

		// 2
		r1_request <= r0_request;
		r1_intermediate <= { 32'b0, r0_uop1 } * { 32'b0, r0_uop2 };

		// 3
		r2_request <= r1_request;
		r2_result <= (i_signed && s[0] != s[1]) ? -$signed(r1_intermediate) : r1_intermediate;
	end

	assign o_ready = r2_request;
	assign o_result = r2_result;

endmodule
