module CPU_FPU_Add (
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
	reg [26:0] a_m;
	reg [26:0] b_m;
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
	reg [27:0] sum;
	assign o_ready = s_output_ready;
	assign o_result = z;
	always @(posedge i_clock) begin
		case (state)
			4'd0: begin
				s_output_ready <= 0;
				if (i_request) begin
					a_m <= {i_op1[22:0], 3'd0};
					a_e <= i_op1[30:23] - 127;
					a_s <= i_op1[31];
					b_m <= {i_op2[22:0], 3'd0};
					b_e <= i_op2[30:23] - 127;
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
					state <= 4'd9;
				end
				else if (a_e == 128) begin
					z[31] <= a_s;
					z[30:23] <= 255;
					z[22:0] <= 0;
					if ((b_e == 128) && (a_s != b_s)) begin
						z[31] <= b_s;
						z[30:23] <= 255;
						z[22] <= 1;
						z[21:0] <= 0;
					end
					s_output_ready <= 1;
					state <= 4'd9;
				end
				else if (b_e == 128) begin
					z[31] <= b_s;
					z[30:23] <= 255;
					z[22:0] <= 0;
					s_output_ready <= 1;
					state <= 4'd9;
				end
				else if ((($signed(a_e) == -127) && (a_m == 0)) && (($signed(b_e) == -127) && (b_m == 0))) begin
					z[31] <= a_s & b_s;
					z[30:23] <= b_e[7:0] + 127;
					z[22:0] <= b_m[26:3];
					s_output_ready <= 1;
					state <= 4'd9;
				end
				else if (($signed(a_e) == -127) && (a_m == 0)) begin
					z[31] <= b_s;
					z[30:23] <= b_e[7:0] + 127;
					z[22:0] <= b_m[26:3];
					s_output_ready <= 1;
					state <= 4'd9;
				end
				else if (($signed(b_e) == -127) && (b_m == 0)) begin
					z[31] <= a_s;
					z[30:23] <= a_e[7:0] + 127;
					z[22:0] <= a_m[26:3];
					s_output_ready <= 1;
					state <= 4'd9;
				end
				else begin
					if ($signed(a_e) == -127)
						a_e <= -126;
					else
						a_m[26] <= 1;
					if ($signed(b_e) == -127)
						b_e <= -126;
					else
						b_m[26] <= 1;
					state <= 4'd2;
				end
			4'd2:
				if ($signed(a_e) > $signed(b_e)) begin
					b_e <= b_e + 1;
					b_m <= b_m >> 1;
					b_m[0] <= b_m[0] | b_m[1];
				end
				else if ($signed(a_e) < $signed(b_e)) begin
					a_e <= a_e + 1;
					a_m <= a_m >> 1;
					a_m[0] <= a_m[0] | a_m[1];
				end
				else
					state <= 4'd3;
			4'd3: begin
				z_e <= a_e;
				if (a_s == b_s) begin
					sum <= a_m + b_m;
					z_s <= a_s;
				end
				else if (a_m >= b_m) begin
					sum <= a_m - b_m;
					z_s <= a_s;
				end
				else begin
					sum <= b_m - a_m;
					z_s <= b_s;
				end
				state <= 4'd4;
			end
			4'd4: begin
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
				state <= 4'd5;
			end
			4'd5:
				if ((z_m[23] == 0) && ($signed(z_e) > -126)) begin
					z_e <= z_e - 1;
					z_m <= z_m << 1;
					z_m[0] <= guard;
					guard <= round_bit;
					round_bit <= 0;
				end
				else
					state <= 4'd6;
			4'd6:
				if ($signed(z_e) < -126) begin
					z_e <= z_e + 1;
					z_m <= z_m >> 1;
					guard <= z_m[0];
					round_bit <= guard;
					sticky <= sticky | round_bit;
				end
				else
					state <= 4'd7;
			4'd7: begin
				if (guard && ((round_bit | sticky) | z_m[0])) begin
					z_m <= z_m + 1;
					if (z_m == 24'hffffff)
						z_e <= z_e + 1;
				end
				state <= 4'd8;
			end
			4'd8: begin
				z[22:0] <= z_m[22:0];
				z[30:23] <= z_e[7:0] + 127;
				z[31] <= z_s;
				if (($signed(z_e) == -126) && (z_m[23] == 0))
					z[30:23] <= 0;
				if (($signed(z_e) == -126) && (z_m[23:0] == 24'h000000))
					z[31] <= 1'b0;
				if ($signed(z_e) > 127) begin
					z[22:0] <= 0;
					z[30:23] <= 255;
					z[31] <= z_s;
				end
				s_output_ready <= 1;
				state <= 4'd9;
			end
			4'd9: begin
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