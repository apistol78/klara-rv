module CPU_Execute (
	i_reset,
	i_clock,
	o_fault,
	o_csr_index,
	i_csr_rdata,
	o_csr_wdata_wr,
	o_csr_wdata,
	i_epc,
	o_jump,
	o_jump_pc,
	o_ecall,
	o_mret,
	o_busy,
	i_data,
	i_rs1,
	i_rs2,
	i_rs3,
	i_memory_busy,
	o_data
);
	reg _sv2v_0;
	input i_reset;
	input i_clock;
	output reg o_fault;
	output wire [11:0] o_csr_index;
	input [31:0] i_csr_rdata;
	output reg o_csr_wdata_wr;
	output reg [31:0] o_csr_wdata;
	input [31:0] i_epc;
	output reg o_jump;
	output reg [31:0] o_jump_pc;
	output reg o_ecall;
	output reg o_mret;
	output reg o_busy;
	input wire [127:0] i_data;
	input [31:0] i_rs1;
	input [31:0] i_rs2;
	input [31:0] i_rs3;
	input i_memory_busy;
	output wire [82:0] o_data;
	localparam OP_CSRRC = 4'd1;
	localparam OP_CSRRS = 4'd2;
	localparam OP_CSRRW = 4'd3;
	localparam OP_DIV = 4'd4;
	localparam OP_DIVU = 4'd5;
	localparam OP_EBREAK = 4'd6;
	localparam OP_ECALL = 4'd7;
	localparam OP_FENCE = 4'd8;
	localparam OP_MUL = 4'd9;
	localparam OP_MULH = 4'd10;
	localparam OP_MULHU = 4'd11;
	localparam OP_MRET = 4'd12;
	localparam OP_REM = 4'd13;
	localparam OP_REMU = 4'd14;
	reg [31:0] alu_operand1;
	always @(*) begin
		if (_sv2v_0)
			;
		alu_operand1 = 0;
		(* full_case, parallel_case *)
		case (1'b1)
			i_data[21]: alu_operand1 = 0;
			i_data[22]: alu_operand1 = i_rs1;
			i_data[23]: alu_operand1 = i_rs2;
			i_data[24]: alu_operand1 = i_data[126-:32];
			i_data[25]: alu_operand1 = i_data[67-:32];
		endcase
	end
	reg [31:0] alu_operand2;
	always @(*) begin
		if (_sv2v_0)
			;
		alu_operand2 = 0;
		(* full_case, parallel_case *)
		case (1'b1)
			i_data[16]: alu_operand2 = 0;
			i_data[17]: alu_operand2 = i_rs1;
			i_data[18]: alu_operand2 = i_rs2;
			i_data[19]: alu_operand2 = i_data[126-:32];
			i_data[20]: alu_operand2 = i_data[67-:32];
		endcase
	end
	wire [31:0] alu_result;
	wire [31:0] alu_shift_result;
	wire [31:0] alu_signed_sum_result;
	wire alu_compare_result;
	CPU_ALU alu(
		.i_op(i_data[29-:4]),
		.i_op1(alu_operand1),
		.i_op2(alu_operand2),
		.o_result(alu_result),
		.o_shift_result(alu_shift_result),
		.o_signed_sum_result(alu_signed_sum_result),
		.o_compare_result(alu_compare_result)
	);
	wire mul_signed = (i_data[10-:5] == OP_MUL) || (i_data[10-:5] == OP_MULH);
	wire [63:0] mul_result;
	reg [3:0] cycle = 0;
	CPU_Multiply multiply(
		.i_clock(i_clock),
		.i_latch(cycle == 0),
		.i_signed(mul_signed),
		.i_op1(i_rs1),
		.i_op2(i_rs2),
		.o_result(mul_result)
	);
	wire div_signed = (i_data[10-:5] == OP_DIV) || (i_data[10-:5] == OP_REM);
	wire [31:0] div_result;
	wire [31:0] div_remainder;
	CPU_Divide divide(
		.i_clock(i_clock),
		.i_latch(cycle == 0),
		.i_signed(div_signed),
		.i_numerator(i_rs1),
		.i_denominator(i_rs2),
		.o_result(div_result),
		.o_remainder(div_remainder)
	);
	reg fpu_request;
	wire fpu_ready;
	wire [31:0] fpu_result;
	CPU_FPU fpu(
		.i_reset(i_reset),
		.i_clock(i_clock),
		.i_request(fpu_request),
		.i_op(i_data[4-:5]),
		.i_op1(i_rs1),
		.i_op2(i_rs2),
		.i_op3(i_rs3),
		.o_ready(fpu_ready),
		.o_result(fpu_result)
	);
	reg last_strobe = 0;
	always @(*) begin
		if (_sv2v_0)
			;
		fpu_request = (!i_memory_busy && (i_data[127] != last_strobe)) && i_data[5];
	end
	assign o_csr_index = i_data[47:36];
	reg [82:0] data = 0;
	assign o_data = data;
	initial begin
		o_csr_wdata_wr = 1'b0;
		o_csr_wdata = 0;
		o_jump = 1'b0;
		o_jump_pc = 0;
		o_mret = 1'b0;
		o_ecall = 1'b0;
		o_fault = 1'b0;
	end
	always @(*) begin
		if (_sv2v_0)
			;
		o_busy = (i_data[127] != last_strobe) && (i_data[32] || i_data[5]);
	end
	function automatic [5:0] sv2v_cast_6;
		input reg [5:0] inp;
		sv2v_cast_6 = inp;
	endfunction
	always @(posedge i_clock)
		if (i_reset) begin
			last_strobe <= 1'b0;
			cycle <= 0;
			data <= 0;
			o_csr_wdata_wr <= 1'b0;
			o_csr_wdata <= 0;
			o_jump <= 1'b0;
			o_jump_pc <= 0;
			o_mret <= 1'b0;
			o_ecall <= 1'b0;
			o_fault <= 1'b0;
		end
		else begin
			o_csr_wdata_wr <= 1'b0;
			o_jump <= 1'b0;
			o_mret <= 1'b0;
			o_ecall <= 1'b0;
			if (!i_memory_busy && (i_data[127] != last_strobe)) begin
				data[81-:6] <= sv2v_cast_6((!i_data[15] ? i_data[73-:6] : 0));
				data[43] <= i_data[15];
				data[42] <= i_data[14];
				data[41] <= 0;
				data[40-:2] <= i_data[13-:2];
				data[38] <= i_data[11];
				data[37-:32] <= alu_signed_sum_result;
				data[5-:6] <= i_data[73-:6];
				if (i_data[35]) begin
					data[75-:32] <= alu_result;
					last_strobe <= i_data[127];
					data[82] <= ~data[82];
					cycle <= 0;
				end
				else if (i_data[34]) begin
					data[75-:32] <= alu_shift_result;
					last_strobe <= i_data[127];
					data[82] <= ~data[82];
					cycle <= 0;
				end
				else if (i_data[33]) begin
					data[75-:32] <= {31'b0000000000000000000000000000000, alu_compare_result};
					last_strobe <= i_data[127];
					data[82] <= ~data[82];
					cycle <= 0;
				end
				else if (i_data[31]) begin
					data[75-:32] <= i_data[126-:32] + 4;
					o_jump <= 1'b1;
					o_jump_pc <= alu_signed_sum_result;
					last_strobe <= i_data[127];
					data[82] <= ~data[82];
					cycle <= 0;
				end
				else if (i_data[30]) begin
					if (alu_compare_result) begin
						o_jump <= 1'b1;
						o_jump_pc <= $signed(i_data[126-:32]) + $signed(i_data[67-:32]);
					end
					else begin
						o_jump <= 1'b1;
						o_jump_pc <= i_data[126-:32] + 4;
					end
					last_strobe <= i_data[127];
					data[82] <= ~data[82];
					cycle <= 0;
				end
				else if (i_data[15]) begin
					last_strobe <= i_data[127];
					data[82] <= ~data[82];
					cycle <= 0;
				end
				else if (i_data[14]) begin
					data[75-:32] <= i_rs2;
					last_strobe <= i_data[127];
					data[82] <= ~data[82];
					cycle <= 0;
				end
				else if (i_data[32]) begin
					cycle <= cycle + 1;
					case (i_data[10-:5])
						OP_CSRRC: begin
							data[75-:32] <= i_csr_rdata;
							o_csr_wdata <= i_csr_rdata & ~i_rs1;
							o_csr_wdata_wr <= 1;
							last_strobe <= i_data[127];
							data[82] <= ~data[82];
							cycle <= 0;
						end
						OP_CSRRS: begin
							data[75-:32] <= i_csr_rdata;
							o_csr_wdata <= i_csr_rdata | i_rs1;
							o_csr_wdata_wr <= 1;
							last_strobe <= i_data[127];
							data[82] <= ~data[82];
							cycle <= 0;
						end
						OP_CSRRW: begin
							data[75-:32] <= i_csr_rdata;
							o_csr_wdata <= i_rs1;
							o_csr_wdata_wr <= 1;
							last_strobe <= i_data[127];
							data[82] <= ~data[82];
							cycle <= 0;
						end
						OP_DIV:
							if (cycle == 14) begin
								data[75-:32] <= div_result[31:0];
								last_strobe <= i_data[127];
								data[82] <= ~data[82];
								cycle <= 0;
							end
						OP_DIVU:
							if (cycle == 14) begin
								data[75-:32] <= div_result[31:0];
								last_strobe <= i_data[127];
								data[82] <= ~data[82];
								cycle <= 0;
							end
						OP_EBREAK: o_fault <= 1'b1;
						OP_ECALL: begin
							o_ecall <= 1'b1;
							last_strobe <= i_data[127];
							data[82] <= ~data[82];
							cycle <= 0;
						end
						OP_FENCE: begin
							data[41] <= 1;
							last_strobe <= i_data[127];
							data[82] <= ~data[82];
							cycle <= 0;
						end
						OP_MUL:
							if (cycle == 2) begin
								data[75-:32] <= mul_result[31:0];
								last_strobe <= i_data[127];
								data[82] <= ~data[82];
								cycle <= 0;
							end
						OP_MULH:
							if (cycle == 2) begin
								data[75-:32] <= mul_result[63:32];
								last_strobe <= i_data[127];
								data[82] <= ~data[82];
								cycle <= 0;
							end
						OP_MULHU:
							if (cycle == 2) begin
								data[75-:32] <= mul_result[63:32];
								last_strobe <= i_data[127];
								data[82] <= ~data[82];
								cycle <= 0;
							end
						OP_MRET: begin
							o_jump <= 1'b1;
							o_jump_pc <= i_epc;
							o_mret <= 1'b1;
							last_strobe <= i_data[127];
							data[82] <= ~data[82];
							cycle <= 0;
						end
						OP_REM:
							if (cycle == 14) begin
								data[75-:32] <= div_remainder[31:0];
								last_strobe <= i_data[127];
								data[82] <= ~data[82];
								cycle <= 0;
							end
						OP_REMU:
							if (cycle == 14) begin
								data[75-:32] <= div_remainder[31:0];
								last_strobe <= i_data[127];
								data[82] <= ~data[82];
								cycle <= 0;
							end
						default: begin
							last_strobe <= i_data[127];
							data[82] <= ~data[82];
							cycle <= 0;
						end
					endcase
				end
				else if (i_data[5]) begin
					if (fpu_ready) begin
						data[75-:32] <= fpu_result;
						last_strobe <= i_data[127];
						data[82] <= ~data[82];
						cycle <= 0;
					end
				end
				else
					o_fault <= 1;
			end
		end
	initial _sv2v_0 = 0;
endmodule