/*
 Klara-RV
 Copyright (c) 2025 Anders Pistol.

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at https://mozilla.org/MPL/2.0/.
*/
`ifndef _CPU_DEFINES_SV
`define _CPU_DEFINES_SV

// Configuration
//`define FPU_ENABLE					1

// Size of register index.
`ifdef FPU_ENABLE
	`define REG_ID_SIZE				6
`else
	`define REG_ID_SIZE				5
`endif

// ALU operations
`define OP_SIGNED_ADD               0
`define OP_UNSIGNED_ADD             1
`define OP_SIGNED_SUB               2
`define OP_AND                      3
`define OP_OR                       4
`define OP_XOR                      5
`define OP_SHIFT_LEFT               6
`define OP_SHIFT_RIGHT              7
`define OP_ARITHMETIC_SHIFT_RIGHT   8
`define OP_SIGNED_LESS_THAN         9
`define OP_UNSIGNED_LESS_THAN       10
`define OP_EQUAL                    11
`define OP_NOT_EQUAL                12
`define OP_SIGNED_GREATER_EQUAL     13
`define OP_UNSIGNED_GREATER_EQUAL   14

// FPU operations
`define FPU_OP_ADD			0
`define FPU_OP_SUB			1
`define FPU_OP_MUL			2
`define FPU_OP_DIV			3
`define FPU_OP_MADD			4
`define FPU_OP_MSUB			5
`define FPU_OP_NMADD		6
`define FPU_OP_NMSUB		7
`define FPU_OP_F2I			8
`define FPU_OP_F2UI			9
`define FPU_OP_I2F			10
`define FPU_OP_UI2F			11
`define FPU_OP_MOV			12
`define FPU_OP_CMP_EQUAL	13
`define FPU_OP_CMP_LESS		14
`define FPU_OP_CMP_LEQUAL	15
`define FPU_OP_SGNJ			16
`define FPU_OP_SGNJN		17
`define FPU_OP_SGNJX		18
`define FPU_OP_MIN			19
`define FPU_OP_MAX			20

// CSR registers
`define CSR_MSTATUS		12'h300
`define CSR_MIE			12'h304
`define CSR_MTVEC		12'h305
`define CSR_MSCRATCH	12'h340
`define CSR_MEPC		12'h341
`define CSR_MCAUSE		12'h342
`define CSR_MIP			12'h344
`define CSR_CYCLE		12'hc00
`define CSR_CYCLEH		12'hc80
`define CSR_TIME		12'hc01
`define CSR_TIMEH		12'hc81
`define CSR_INSTRET		12'hc02
`define CSR_INSTRETH	12'hc82
`define CSR_MVENDORID	12'hf11
`define CSR_MARCHID		12'hf12
`define CSR_MIMPID		12'hf13
`define CSR_MHARTID		12'hf14

// Memory widths
`define MEMW_1	2'b00
`define MEMW_2	2'b01
`define MEMW_4	2'b10

`endif	// _CPU_DEFINES_SV
