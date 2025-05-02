module CPU_FPU_Compare (
	i_reset,
	i_clock,
	i_request,
	i_op1,
	i_op2,
	o_ready,
	o_less,
	o_equal,
	o_min,
	o_max
);
	input i_reset;
	input i_clock;
	input i_request;
	input [31:0] i_op1;
	input [31:0] i_op2;
	output wire o_ready;
	output wire o_less;
	output wire o_equal;
	output wire [31:0] o_min;
	output wire [31:0] o_max;
	reg s_output_ready = 0;
	reg [0:0] state = 1'd0;
	reg [31:0] a;
	reg [22:0] a_m;
	reg [9:0] a_e;
	reg a_s;
	reg [31:0] b;
	reg [22:0] b_m;
	reg [9:0] b_e;
	reg b_s;
	reg less = 0;
	reg equal = 0;
	assign o_ready = s_output_ready;
	assign o_less = less;
	assign o_equal = equal;
	assign o_min = (less ? a : b);
	assign o_max = (less ? b : a);
	always @(posedge i_clock) begin
		case (state)
			1'd0: begin
				s_output_ready <= 0;
				if (i_request) begin
					a <= i_op1;
					a_m <= {i_op1[22:0]};
					a_e <= {i_op1[30:23]};
					a_s <= i_op1[31];
					b <= i_op2;
					b_m <= {i_op2[22:0]};
					b_e <= {i_op2[30:23]};
					b_s <= i_op2[31];
					state <= 1'd1;
				end
			end
			1'd1: begin
				less <= 0;
				equal <= 0;
				if (a_s != b_s) begin
					if (!a_s)
						less <= 0;
					else
						less <= 1;
				end
				else if (a_e != b_e) begin
					if (a_e > b_e)
						less <= a_s;
					else
						less <= !a_s;
				end
				else if (a_m != b_m) begin
					if (a_m > b_m)
						less <= a_s;
					else
						less <= !a_s;
				end
				else
					equal <= 1;
				s_output_ready <= 1;
				if (!i_request) begin
					s_output_ready <= 0;
					state <= 1'd0;
				end
			end
			default: state <= 1'd0;
		endcase
		if (i_reset) begin
			s_output_ready <= 0;
			state <= 1'd0;
		end
	end
endmodule