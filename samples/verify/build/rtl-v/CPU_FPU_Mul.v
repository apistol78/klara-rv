module CPU_FPU_Mul (
	i_reset,
	i_clock,
	i_request,
	i_op1,
	i_op2,
	o_ready,
	o_result
);
	input i_reset;
	input i_clock;
	input i_request;
	input [31:0] i_op1;
	input [31:0] i_op2;
	output wire o_ready;
	output wire [31:0] o_result;
	reg s_output_ready = 0;
	reg [3:0] state = 4'd0;
	reg [31:0] z;
	reg [23:0] a_m;
	reg [23:0] b_m;
	reg [23:0] z_m;
	reg [9:0] a_e;
	reg [9:0] b_e;
	reg [9:0] z_e;
	reg a_s;
	reg b_s;
	reg z_s;
	reg guard;
	reg round_bit;
	reg sticky;
	reg [47:0] product;
	assign o_ready = s_output_ready;
	assign o_result = z;
	always @(posedge i_clock) begin
		case (state)
			4'd0: begin
				s_output_ready <= 0;
				if (i_request) begin
					a_m <= i_op1[22:0];
					a_e <= i_op1[30:23] - 127;
					a_s <= i_op1[31];
					b_e <= i_op2[30:23] - 127;
					b_m <= i_op2[22:0];
					b_s <= i_op2[31];
					state <= 4'd1;
				end
			end
			4'd1:
				if (((a_e == 128) && (a_m != 0)) || ((b_e == 128) && (b_m != 0))) begin
					z[31] <= 1;
					z[30:23] <= 255;
					z[22] <= 1;
					z[21:0] <= 0;
					s_output_ready <= 1;
					state <= 4'd10;
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
					s_output_ready <= 1;
					state <= 4'd10;
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
					s_output_ready <= 1;
					state <= 4'd10;
				end
				else if (($signed(a_e) == -127) && (a_m == 0)) begin
					z[31] <= a_s ^ b_s;
					z[30:23] <= 0;
					z[22:0] <= 0;
					s_output_ready <= 1;
					state <= 4'd10;
				end
				else if (($signed(b_e) == -127) && (b_m == 0)) begin
					z[31] <= a_s ^ b_s;
					z[30:23] <= 0;
					z[22:0] <= 0;
					s_output_ready <= 1;
					state <= 4'd10;
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
					state <= 4'd2;
				end
			4'd2:
				if (a_m[23])
					state <= 4'd3;
				else begin
					a_m <= a_m << 1;
					a_e <= a_e - 1;
				end
			4'd3:
				if (b_m[23])
					state <= 4'd4;
				else begin
					b_m <= b_m << 1;
					b_e <= b_e - 1;
				end
			4'd4: begin
				z_s <= a_s ^ b_s;
				z_e <= (a_e + b_e) + 1;
				product <= a_m * b_m;
				state <= 4'd5;
			end
			4'd5: begin
				z_m <= product[47:24];
				guard <= product[23];
				round_bit <= product[22];
				sticky <= product[21:0] != 0;
				state <= 4'd6;
			end
			4'd6:
				if (z_m[23] == 0) begin
					z_e <= z_e - 1;
					z_m <= z_m << 1;
					z_m[0] <= guard;
					guard <= round_bit;
					round_bit <= 0;
				end
				else
					state <= 4'd7;
			4'd7:
				if ($signed(z_e) < -126) begin
					z_e <= z_e + 1;
					z_m <= z_m >> 1;
					guard <= z_m[0];
					round_bit <= guard;
					sticky <= sticky | round_bit;
				end
				else
					state <= 4'd8;
			4'd8: begin
				if (guard && ((round_bit | sticky) | z_m[0])) begin
					z_m <= z_m + 1;
					if (z_m == 24'hffffff)
						z_e <= z_e + 1;
				end
				state <= 4'd9;
			end
			4'd9: begin
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
				s_output_ready <= 1;
				state <= 4'd10;
			end
			4'd10: begin
				s_output_ready <= 1;
				if (!i_request) begin
					s_output_ready <= 0;
					state <= 4'd0;
				end
			end
			default: state <= 4'd0;
		endcase
		if (i_reset) begin
			s_output_ready <= 0;
			state <= 4'd0;
		end
	end
endmodule