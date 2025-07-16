/*
 Klara-RV
 Copyright (c) 2025 Anders Pistol.

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at https://mozilla.org/MPL/2.0/.
*/
`timescale 1ns/1ns

module CPU_Multiply_Function (
	input  wire         clk,
	input  wire         rst,
	input  wire         valid_in,
	input  wire [31:0]  a,
	input  wire [31:0]  b,
	output reg          valid_out,
	output reg  [63:0]  product
);
	// Stage 0: Generate partial products
	wire [63:0] partial_products[31:0];
	genvar i;
	generate
		for (i = 0; i < 32; i = i + 1) begin : gen_partial
			assign partial_products[i] = b[i] ? (a << i) : 64'b0;
		end
	endgenerate

	// Stage 1: Add partial products in pairs (16 results)
	reg [63:0] stage1_sum[15:0];
	integer j;
	always @(posedge clk or posedge rst) begin
		if (rst) begin
			for (j = 0; j < 16; j = j + 1)
				stage1_sum[j] <= 64'b0;
		end else begin
			for (j = 0; j < 16; j = j + 1)
				stage1_sum[j] <= partial_products[2*j] + partial_products[2*j+1];
		end
	end

	// Stage 2: Add stage1 results in pairs (8 results)
	reg [63:0] stage2_sum[7:0];
	always @(posedge clk or posedge rst) begin
		if (rst) begin
			for (j = 0; j < 8; j = j + 1)
				stage2_sum[j] <= 64'b0;
		end else begin
			for (j = 0; j < 8; j = j + 1)
				stage2_sum[j] <= stage1_sum[2*j] + stage1_sum[2*j+1];
		end
	end

	// Stage 3: Add stage2 results in pairs (4 results)
	reg [63:0] stage3_sum[3:0];
	always @(posedge clk or posedge rst) begin
		if (rst) begin
			for (j = 0; j < 4; j = j + 1)
				stage3_sum[j] <= 64'b0;
		end else begin
			for (j = 0; j < 4; j = j + 1)
				stage3_sum[j] <= stage2_sum[2*j] + stage2_sum[2*j+1];
		end
	end

	// Stage 4: Final two additions
	reg [63:0] stage4_a, stage4_b;
	always @(posedge clk or posedge rst) begin
		if (rst) begin
			stage4_a <= 64'b0;
			stage4_b <= 64'b0;
		end else begin
			stage4_a <= stage3_sum[0] + stage3_sum[1];
			stage4_b <= stage3_sum[2] + stage3_sum[3];
		end
	end

	// Final stage: Output
	always @(posedge clk or posedge rst) begin
		if (rst) begin
			product    <= 64'b0;
			valid_out  <= 1'b0;
		end else begin
			product    <= stage4_a + stage4_b;
			valid_out  <= valid_in;  // propagate valid signal
		end
	end

endmodule;

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

	bit [1:0] m_s;
	bit [31:0] m_uop1;
	bit [31:0] m_uop2;
	wire [63:0] m_product;

	CPU_Multiply_Function m(
		.clk(i_clock),
		.rst(1'b0),
		.valid_in(),
		.a(m_uop1),
		.b(m_uop2),
		.valid_out(),
		.product(m_product)
	);

	bit [1:0] state = 2'd0;
	bit [2:0] cnt = 0;
	bit [63:0] result = 64'd0;
	bit ready = 1'b0;

	always_ff @(posedge i_clock) begin

		ready <= 1'b0;

		case(state)
			2'd0: begin
				if (i_latch) begin
					m_s <= i_signed ? { s1, s2 } : 2'b00;
					m_uop1 <= (i_signed && s1) ? -$signed(i_op1) : i_op1;
					m_uop2 <= (i_signed && s2) ? -$signed(i_op2) : i_op2;
					cnt <= 0;
					state <= 1;
				end
			end

			2'd1: begin
				cnt <= cnt + 1;
				if (cnt >= 5) begin
					ready <= 1'b1;
					result <= (m_s[0] != m_s[1]) ? -$signed(m_product) : m_product;
					cnt <= 0;
					state <= 2;
				end
			end

			2'd2: begin
				if (!i_latch)
					state <= 0;
			end

			default: begin
				cnt <= 0;
				state <= 0;
			end
		endcase
	end

	assign o_ready = ready;
	assign o_result = result;

endmodule
