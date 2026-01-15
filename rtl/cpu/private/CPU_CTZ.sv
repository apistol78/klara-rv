/*
 Klara-RV
 Copyright (c) 2026 Anders Pistol.

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at https://mozilla.org/MPL/2.0/.
*/
`include "CPU_Defines.sv"

`timescale 1ns/1ns
`default_nettype none

module CPU_CTZ(
	input wire [31:0] i_value,
	output bit [5:0] o_result_czt,
	output bit [5:0] o_result_czl,
	output bit [5:0] o_result_cpop
);

	always_comb begin
		o_result_czt =
			i_value[0] ? 0 :
			i_value[1] ? 1 :
			i_value[2] ? 2 :
			i_value[3] ? 3 :
			i_value[4] ? 4 :
			i_value[5] ? 5 :
			i_value[6] ? 6 :
			i_value[7] ? 7 :
			i_value[8] ? 8 :
			i_value[9] ? 9 :
			i_value[10] ? 10 :
			i_value[11] ? 11 :
			i_value[12] ? 12 :
			i_value[13] ? 13 :
			i_value[14] ? 14 :
			i_value[15] ? 15 :
			i_value[16] ? 16 :
			i_value[17] ? 17 :
			i_value[18] ? 18 :
			i_value[19] ? 19 :
			i_value[20] ? 20 :
			i_value[21] ? 21 :
			i_value[22] ? 22 :
			i_value[23] ? 23 :
			i_value[24] ? 24 :
			i_value[25] ? 25 :
			i_value[26] ? 26 :
			i_value[27] ? 27 :
			i_value[28] ? 28 :
			i_value[29] ? 29 :
			i_value[30] ? 30 :
			i_value[31] ? 31:
			32;
	end

	always_comb begin
		o_result_czl =
			i_value[31] ? 0 :
			i_value[30] ? 1 :
			i_value[29] ? 2 :
			i_value[28] ? 3 :
			i_value[27] ? 4 :
			i_value[26] ? 5 :
			i_value[25] ? 6 :
			i_value[24] ? 7 :
			i_value[23] ? 8 :
			i_value[22] ? 9 :
			i_value[21] ? 10 :
			i_value[20] ? 11 :
			i_value[19] ? 12 :
			i_value[18] ? 13 :
			i_value[17] ? 14 :
			i_value[16] ? 15 :
			i_value[15] ? 16 :
			i_value[14] ? 17 :
			i_value[13] ? 18 :
			i_value[12] ? 19 :
			i_value[11] ? 20 :
			i_value[10] ? 21 :
			i_value[9] ? 22 :
			i_value[8] ? 23 :
			i_value[7] ? 24 :
			i_value[6] ? 25 :
			i_value[5] ? 26 :
			i_value[4] ? 27 :
			i_value[3] ? 28 :
			i_value[2] ? 29 :
			i_value[1] ? 30 :
			i_value[0] ? 31:
			32;
	end

	always_comb begin
		o_result_cpop =
			i_value[0] +
			i_value[1] +
			i_value[2] +
			i_value[3] +
			i_value[4] +
			i_value[5] +
			i_value[6] +
			i_value[7] +
			i_value[8] +
			i_value[9] +
			i_value[10] +
			i_value[11] +
			i_value[12] +
			i_value[13] +
			i_value[14] +
			i_value[15] +
			i_value[16] +
			i_value[17] +
			i_value[18] +
			i_value[19] +
			i_value[20] +
			i_value[21] +
			i_value[22] +
			i_value[23] +
			i_value[24] +
			i_value[25] +
			i_value[26] +
			i_value[27] +
			i_value[28] +
			i_value[29] +
			i_value[30] +
			i_value[31];
	end

endmodule
