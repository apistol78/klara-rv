/*
 Klara-RV
 Copyright (c) 2025 Anders Pistol.

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at https://mozilla.org/MPL/2.0/.
*/

// Since we're using DSP to implement multiplication
// we need to pipeline result so we can meet timing.

`timescale 1ns/1ns

module CPU_Multiply(
	input i_clock,
	input i_latch,
	input i_signed,
	input [31:0] i_op1,
	input [31:0] i_op2,
	output [63:0] o_result
);

	wire s1 = i_op1[31];
	wire s2 = i_op2[31];

	wire [31:0] uop1 = (i_signed && s1) ? -$signed(i_op1) : i_op1;
	wire [31:0] uop2 = (i_signed && s2) ? -$signed(i_op2) : i_op2;

	bit [1:0] s;
	always_ff @(posedge i_clock) begin
		if (i_latch)
			s <= { s1, s2 };
	end

`ifdef USE_MULTIPLY_IP

	wire [63:0] umul_result;
	IP_UnsignedMultiply ip_unsigned_multiply(
		.clock(i_clock),
		.dataa(uop1),
		.datab(uop2),
		.result(umul_result)
	);

	always_comb begin
		if (i_signed) begin
			if (s[0] != s[1])
				o_result = -$signed(umul_result);
			else
				o_result = umul_result;
		end
		else
			o_result = umul_result;       
	end

`else

	bit [63:0] p1;
	bit [63:0] p2;
	bit [63:0] p3;
	
	assign o_result = p3;

	always_ff @(posedge i_clock)
	begin
		p1 <= { 32'b0, uop1 } * { 32'b0, uop2 };
		p2 <= p1;
		p3 <= (i_signed && s[0] != s[1]) ? -$signed(p2) : p2;
	end

`endif

endmodule
