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

module CPU_Fetch #(
	parameter RESET_VECTOR,
	parameter ICACHE_SIZE,
	parameter ICACHE_REGISTERED
)(
	input wire i_reset,
	input wire i_clock,

	// Control
	input wire i_jump,
	input wire [31:0] i_jump_pc,

	// Interrupt
	input wire i_irq_pending,		//!< Interrupt pending.
	input wire [31:0] i_irq_pc,	//!< Interrupt handler vector.
	output bit o_irq_dispatched,	//!< Interrupt dispatched signal.
	output bit [31:0] o_irq_epc,	//!< Interrupt return vector.

	// Bus
	output wire o_bus_request,
	input wire i_bus_ready,
	output wire [31:0] o_bus_address,
	input wire [31:0] i_bus_rdata,

	// Output
	input wire i_busy,
	output fetch_data_t o_data,

	// Debug
	output wire [31:0] o_debug_pc
);

	typedef enum bit [1:0]
	{
		WAIT_ICACHE,
		WAIT_JUMP,
		WAIT_IRQ
	} state_t;

	state_t state = WAIT_ICACHE;
	bit [31:0] pc = RESET_VECTOR;
	fetch_data_t data = 0;

	// ICache
	wire [31:0] icache_rdata;
	wire icache_ready;

	generate
		if (ICACHE_SIZE > 0 && ICACHE_REGISTERED != 0) begin : icache_registered
			CPU_ICache_Reg #(
				.SIZE(ICACHE_SIZE)
			) icache(
				.i_reset(i_reset),
				.i_clock(i_clock),

				// Input
				.i_input_pc(pc),

				// Output
				.o_rdata(icache_rdata),
				.o_ready(icache_ready),

				// Bus
				.o_bus_request(o_bus_request),
				.i_bus_ready(i_bus_ready),
				.o_bus_address(o_bus_address),
				.i_bus_rdata(i_bus_rdata)
			);
		end
	endgenerate

	generate
		if (ICACHE_SIZE > 0 && ICACHE_REGISTERED == 0) begin : icache_combinatorial
			CPU_ICache_Comb #(
				.SIZE(ICACHE_SIZE)
			) icache(
				.i_reset(i_reset),
				.i_clock(i_clock),

				// Input
				.i_input_pc(pc),

				// Output
				.o_rdata(icache_rdata),
				.o_ready(icache_ready),

				// Bus
				.o_bus_request(o_bus_request),
				.i_bus_ready(i_bus_ready),
				.o_bus_address(o_bus_address),
				.i_bus_rdata(i_bus_rdata)
			);
		end
	endgenerate

	generate
		if (ICACHE_SIZE == 0) begin : icache_none
			CPU_ICache_None icache(
				.i_reset(i_reset),
				.i_clock(i_clock),

				// Input
				.i_input_pc(pc),

				// Output
				.o_rdata(icache_rdata),
				.o_ready(icache_ready),
				.i_stall(),

				// Bus
				.o_bus_request(o_bus_request),
				.i_bus_ready(i_bus_ready),
				.o_bus_address(o_bus_address),
				.i_bus_rdata(i_bus_rdata)
			);
		end
	endgenerate

	// 
	`undef INSTRUCTION
	`define INSTRUCTION icache_rdata
	`include "private/generated/Instructions_decode.sv"

	wire [31:0] inst_B_imm = { { 20{ `INSTRUCTION[31] } }, `INSTRUCTION[7], `INSTRUCTION[30:25], `INSTRUCTION[11:8], 1'b0 };
	wire [31:0] inst_J_imm = { { 12{ `INSTRUCTION[31] } }, `INSTRUCTION[19:12], `INSTRUCTION[20], `INSTRUCTION[30:21], 1'b0 };

	wire have_RS1 = is_B | is_I | is_R | is_S | is_CSR | is_R4;
	wire have_RS2 = is_B | is_R | is_S | is_R4;
	wire have_RS3 = is_R4;
	wire have_RD  = is_I | is_J | is_R | is_U | is_CSR | is_R4;
	
	assign o_data = data;
	assign o_debug_pc = pc;

	bit irq_pending_r = 1'b0;

/*
	// Branch prediction unit.
	bit [31:0] bp_pc_launch;
	wire [31:0] bp_pc_hint;
	CPU_BranchPrediction bp(
		.i_clock(i_clock),
		.i_pc(pc),
		.i_is_jal(is_JAL),
		.i_is_jump_conditional(is_JUMP_CONDITIONAL),
		.i_inst_B_imm(inst_B_imm),
		.i_inst_J_imm(inst_J_imm),
		.i_pc_launch(bp_pc_launch),
		.o_pc_hint(bp_pc_hint),
		.i_jump(i_jump),
		.i_jump_pc(i_jump_pc)
	);
*/

	always_ff @(posedge i_clock) begin
		if (i_reset) begin
			state <= WAIT_ICACHE;
			pc <= RESET_VECTOR;
			data <= 0;
			irq_pending_r <= 1'b0;
		end
		else begin

			o_irq_dispatched <= 1'b0;

			case (state)
				WAIT_ICACHE: begin
					// Issue interrupt if pending.
					irq_pending_r <= i_irq_pending;
					if ({ irq_pending_r, i_irq_pending } == 2'b01) begin
						o_irq_dispatched <= 1'b1;
						o_irq_epc <= pc;
						pc <= i_irq_pc;
					end
					else if (!i_busy && icache_ready) begin
						data.strobe <= ~data.strobe;
						data.instruction <= icache_rdata;
						data.pc <= pc;

						// Decode register indices here since we
						// need those for fetching registers while
						// we are decoding rest of instruction.
// `ifdef FPU_ENABLE
// 						data.inst_rs1 <= register_t'(have_RS1 ? { RS1_bank, `INSTRUCTION[19:15] } : 0);
// 						data.inst_rs2 <= register_t'(have_RS2 ? { RS2_bank, `INSTRUCTION[24:20] } : 0);
// 						data.inst_rs3 <= register_t'(have_RS3 ? { RS3_bank, `INSTRUCTION[31:27] } : 0);
// 						data.inst_rd  <= register_t'(have_RD  ? {  RD_bank, `INSTRUCTION[ 11:7] } : 0);
// `else
						data.inst_rs1 <= register_t'(have_RS1 ? { `INSTRUCTION[19:15] } : 0);
						data.inst_rs2 <= register_t'(have_RS2 ? { `INSTRUCTION[24:20] } : 0);
						data.inst_rs3 <= register_t'(have_RS3 ? { `INSTRUCTION[31:27] } : 0);
						data.inst_rd  <= register_t'(have_RD  ? { `INSTRUCTION[ 11:7] } : 0);
// `endif

						if (is_JUMP || is_JUMP_CONDITIONAL || is_MRET) begin
							// Branch instruction, need to wait
							// for an explicit "goto" signal before
							// we can continue feeding the pipeline.
/*
							bp_pc_launch <= pc;
							pc <= bp_pc_hint;
*/
							state <= WAIT_JUMP;
						end
						else if (is_ECALL || is_WFI) begin
							// Software interrupt, need to wait
							// for IRQ signal before continue.
							state <= WAIT_IRQ;
						end
						else begin
							// Move PC to next instruction.
							pc <= pc + 4;
						end
					end
				end

				WAIT_JUMP: begin
					// Wait for "goto" signal.
					if (i_jump) begin
						pc <= i_jump_pc;
						state <= WAIT_ICACHE;
					end
				end

				WAIT_IRQ: begin
					// Wait for soft IRQ signal.
					irq_pending_r <= i_irq_pending;
					if ({ irq_pending_r, i_irq_pending } == 2'b01) begin
						o_irq_dispatched <= 1'b1;
						o_irq_epc <= pc;
						pc <= i_irq_pc;
						state <= WAIT_ICACHE;
					end					
				end

				default:
					state <= WAIT_ICACHE;
			endcase
		end
	end

endmodule
