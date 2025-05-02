module CPU_Multiply (
	i_clock,
	i_latch,
	i_signed,
	i_op1,
	i_op2,
	o_result
);
	input i_clock;
	input i_latch;
	input i_signed;
	input [31:0] i_op1;
	input [31:0] i_op2;
	output wire [63:0] o_result;
	wire s1 = i_op1[31];
	wire s2 = i_op2[31];
	wire [31:0] uop1 = (i_signed && s1 ? -$signed(i_op1) : i_op1);
	wire [31:0] uop2 = (i_signed && s2 ? -$signed(i_op2) : i_op2);
	reg [1:0] s;
	always @(posedge i_clock)
		if (i_latch)
			s <= {s1, s2};
	assign o_result = 32'd0;
endmodule