module CPU_FPU_MulAdd (
	i_reset,
	i_clock,
	i_request,
	i_op1,
	i_op2,
	i_op3,
	o_ready,
	o_result
);
	input i_reset;
	input i_clock;
	input i_request;
	input [31:0] i_op1;
	input [31:0] i_op2;
	input [31:0] i_op3;
	output wire o_ready;
	output wire [31:0] o_result;
	reg s_output_ready = 0;
	reg [31:0] s_output_z = 0;
	reg [4:0] state = 5'd0;
	reg [31:0] t;
	reg [31:0] z;
	reg [23:0] a_m;
	reg [23:0] b_m;
	reg [26:0] c_m;
	reg [26:0] t_m;
	reg [23:0] z_m;
	reg [9:0] a_e;
	reg [9:0] b_e;
	reg [9:0] c_e;
	reg [9:0] t_e;
	reg [9:0] z_e;
	reg a_s;
	reg b_s;
	reg c_s;
	reg t_s;
	reg z_s;
	reg guard;
	reg round_bit;
	reg sticky;
	reg [47:0] product;
	reg [27:0] sum;
	assign o_ready = s_output_ready;
	assign o_result = s_output_z;
	always @(posedge i_clock) begin
		case (state)
			5'd0: begin
				s_output_ready <= 0;
				if (i_request) begin
					a_m <= i_op1[22:0];
					b_m <= i_op2[22:0];
					c_m <= {i_op3[22:0], 3'd0};
					a_e <= i_op1[30:23] - 127;
					b_e <= i_op2[30:23] - 127;
					c_e <= i_op3[30:23] - 127;
					a_s <= i_op1[31];
					b_s <= i_op2[31];
					c_s <= i_op3[31];
					t <= i_op3;
					state <= 5'd1;
				end
			end
			5'd1:
				if ((((a_e == 128) && (a_m != 0)) || ((b_e == 128) && (b_m != 0))) || ((c_e == 128) && (c_m != 0))) begin
					z[31] <= 1;
					z[30:23] <= 255;
					z[22] <= 1;
					z[21:0] <= 0;
					state <= 5'd17;
				end
				else if (a_e == 128) begin
					z[31] <= a_s ^ b_s;
					z[30:23] <= 255;
					z[22:0] <= 0;
					if (($signed(b_e) == -127) && (b_m == 0)) begin
						z[31] <= 1;
						z[30:23] <= 255;
						z[22] <= 1;
						z[21:0] <= 0;
					end
					state <= 5'd17;
				end
				else if (b_e == 128) begin
					z[31] <= a_s ^ b_s;
					z[30:23] <= 255;
					z[22:0] <= 0;
					if (($signed(a_e) == -127) && (a_m == 0)) begin
						z[31] <= 1;
						z[30:23] <= 255;
						z[22] <= 1;
						z[21:0] <= 0;
					end
					state <= 5'd17;
				end
				else if (c_e == 128) begin
					z[31] <= 1'b0;
					z[30:23] <= 255;
					z[22:0] <= 0;
					state <= 5'd17;
				end
				else if ((($signed(a_e) == -127) && (a_m == 0)) || (($signed(b_e) == -127) && (b_m == 0))) begin
					z <= t;
					state <= 5'd17;
				end
				else begin
					if ($signed(a_e) == -127)
						a_e <= -126;
					else
						a_m[23] <= 1;
					if ($signed(b_e) == -127)
						b_e <= -126;
					else
						b_m[23] <= 1;
					if ($signed(c_e) == -127)
						c_e <= -126;
					else
						c_m[26] <= 1;
					state <= 5'd2;
				end
			5'd2:
				if (a_m[23])
					state <= 5'd3;
				else begin
					a_m <= a_m << 1;
					a_e <= a_e - 1;
				end
			5'd3:
				if (b_m[23])
					state <= 5'd4;
				else begin
					b_m <= b_m << 1;
					b_e <= b_e - 1;
				end
			5'd4: begin
				t_s <= a_s ^ b_s;
				t_e <= (a_e + b_e) + 1;
				product <= a_m * b_m;
				state <= 5'd5;
			end
			5'd5: begin
				t_m <= product[47:24];
				guard <= product[23];
				round_bit <= product[22];
				sticky <= product[21:0] != 0;
				state <= 5'd6;
			end
			5'd6:
				if (t_m[23] == 0) begin
					t_e <= t_e - 1;
					t_m <= t_m << 1;
					t_m[0] <= guard;
					guard <= round_bit;
					round_bit <= 0;
				end
				else
					state <= 5'd7;
			5'd7:
				if ($signed(t_e) < -126) begin
					t_e <= t_e + 1;
					t_m <= t_m >> 1;
					guard <= t_m[0];
					round_bit <= guard;
					sticky <= sticky | round_bit;
				end
				else
					state <= 5'd8;
			5'd8: begin
				if (guard && ((round_bit | sticky) | t_m[0])) begin
					t_m <= t_m + 1;
					if (t_m == 24'hffffff)
						t_e <= t_e + 1;
				end
				state <= 5'd9;
			end
			5'd9: begin
				t_m <= t_m << 3;
				state <= 5'd10;
			end
			5'd10:
				if ($signed(c_e) > $signed(t_e)) begin
					t_e <= t_e + 1;
					t_m <= t_m >> 1;
					t_m[0] <= t_m[0] | t_m[1];
				end
				else if ($signed(c_e) < $signed(t_e)) begin
					c_e <= c_e + 1;
					c_m <= c_m >> 1;
					c_m[0] <= c_m[0] | c_m[1];
				end
				else
					state <= 5'd11;
			5'd11: begin
				z_e <= c_e;
				if (c_s == t_s) begin
					sum <= c_m + t_m;
					z_s <= c_s;
				end
				else if (c_m >= t_m) begin
					sum <= c_m - t_m;
					z_s <= c_s;
				end
				else begin
					sum <= t_m - c_m;
					z_s <= t_s;
				end
				state <= 5'd12;
			end
			5'd12: begin
				if (sum[27]) begin
					z_m <= sum[27:4];
					guard <= sum[3];
					round_bit <= sum[2];
					sticky <= sum[1] | sum[0];
					z_e <= z_e + 1;
				end
				else begin
					z_m <= sum[26:3];
					guard <= sum[2];
					round_bit <= sum[1];
					sticky <= sum[0];
				end
				state <= 5'd13;
			end
			5'd13:
				if ((z_m[23] == 0) && ($signed(z_e) > -126)) begin
					z_e <= z_e - 1;
					z_m <= z_m << 1;
					z_m[0] <= guard;
					guard <= round_bit;
					round_bit <= 0;
				end
				else
					state <= 5'd14;
			5'd14:
				if ($signed(z_e) < -126) begin
					z_e <= z_e + 1;
					z_m <= z_m >> 1;
					guard <= z_m[0];
					round_bit <= guard;
					sticky <= sticky | round_bit;
				end
				else
					state <= 5'd15;
			5'd15: begin
				if (guard && ((round_bit | sticky) | z_m[0])) begin
					z_m <= z_m + 1;
					if (z_m == 24'hffffff)
						z_e <= z_e + 1;
				end
				state <= 5'd16;
			end
			5'd16: begin
				z[22:0] <= z_m[22:0];
				z[30:23] <= z_e[7:0] + 127;
				z[31] <= z_s;
				if (($signed(z_e) == -126) && (z_m[23] == 0))
					z[30:23] <= 0;
				if ($signed(z_e) > 127) begin
					z[22:0] <= 0;
					z[30:23] <= 255;
					z[31] <= z_s;
				end
				state <= 5'd17;
			end
			5'd17: begin
				s_output_ready <= 1;
				s_output_z <= z;
				if (!i_request) begin
					s_output_ready <= 0;
					state <= 5'd0;
				end
			end
			default: state <= 5'd0;
		endcase
		if (i_reset) begin
			s_output_ready <= 0;
			state <= 5'd0;
		end
	end
endmodule