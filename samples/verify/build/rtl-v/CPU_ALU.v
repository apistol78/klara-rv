module CPU_ALU (
	i_op,
	i_op1,
	i_op2,
	o_result,
	o_shift_result,
	o_signed_sum_result,
	o_compare_result
);
	input [3:0] i_op;
	input [31:0] i_op1;
	input [31:0] i_op2;
	output wire [31:0] o_result;
	output wire [31:0] o_shift_result;
	output wire [31:0] o_signed_sum_result;
	output wire o_compare_result;
	wire [31:0] signed_sum = $signed(i_op1) + $signed(i_op2);
	wire [31:0] unsigned_sum = i_op1 + i_op2;
	wire [31:0] signed_diff = $signed(i_op1) - $signed(i_op2);
	wire [31:0] and_result = i_op1 & i_op2;
	wire [31:0] or_result = i_op1 | i_op2;
	wire [31:0] xor_result = i_op1 ^ i_op2;
	wire [31:0] shl_result = i_op1 << i_op2[4:0];
	wire [31:0] shr_result = i_op1 >> i_op2[4:0];
	wire [31:0] ashr_result = $signed(i_op1) >>> i_op2[4:0];
	wire signed_lt_result = ($signed(i_op1) < $signed(i_op2) ? 1'b1 : 1'b0);
	wire unsigned_lt_result = (i_op1 < i_op2 ? 1'b1 : 1'b0);
	wire equal_result = (i_op1 == i_op2 ? 1'b1 : 1'b0);
	wire not_equal_result = (i_op1 != i_op2 ? 1'b1 : 1'b0);
	wire signed_get_result = ($signed(i_op1) >= $signed(i_op2) ? 1'b1 : 1'b0);
	wire unsigned_get_result = (i_op1 >= i_op2 ? 1'b1 : 1'b0);
	assign o_result = (i_op == 0 ? signed_sum : (i_op == 1 ? unsigned_sum : (i_op == 2 ? signed_diff : (i_op == 3 ? and_result : (i_op == 4 ? or_result : (i_op == 5 ? xor_result : 32'd0))))));
	assign o_shift_result = (i_op == 6 ? shl_result : (i_op == 7 ? shr_result : (i_op == 8 ? ashr_result : 32'd0)));
	assign o_signed_sum_result = signed_sum;
	assign o_compare_result = (i_op == 9 ? signed_lt_result : (i_op == 10 ? unsigned_lt_result : (i_op == 11 ? equal_result : (i_op == 12 ? not_equal_result : (i_op == 13 ? signed_get_result : (i_op == 14 ? unsigned_get_result : 1'b0))))));
endmodule