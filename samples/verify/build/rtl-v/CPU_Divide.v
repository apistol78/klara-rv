module CPU_Divide (
	i_clock,
	i_latch,
	i_signed,
	i_numerator,
	i_denominator,
	o_result,
	o_remainder
);
	input i_clock;
	input i_latch;
	input i_signed;
	input [31:0] i_numerator;
	input [31:0] i_denominator;
	output wire [31:0] o_result;
	output wire [31:0] o_remainder;
	wire snumerator = i_numerator[31];
	wire sdenominator = i_denominator[31];
	wire [31:0] unumerator = (i_signed && snumerator ? -$signed(i_numerator) : i_numerator);
	wire [31:0] udenominator = (i_signed && sdenominator ? -$signed(i_denominator) : i_denominator);
	reg [1:0] s;
	always @(posedge i_clock)
		if (i_latch)
			s <= {snumerator, sdenominator};
	assign o_result = 32'd0;
	assign o_remainder = 32'd0;
endmodule