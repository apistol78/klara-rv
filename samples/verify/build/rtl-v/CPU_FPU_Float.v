module CPU_FPU_Float (
	i_reset,
	i_clock,
	i_request,
	i_op1,
	i_signed,
	o_ready,
	o_result
);
	input i_reset;
	input i_clock;
	input i_request;
	input [31:0] i_op1;
	input i_signed;
	output wire o_ready;
	output wire [31:0] o_result;
	reg s_output_ready = 0;
	reg [31:0] s_output_z = 0;
	reg [3:0] state = 4'd0;
	reg [31:0] z;
	reg [23:0] z_m;
	reg [7:0] z_r;
	reg [7:0] z_e;
	reg z_s;
	reg guard;
	reg round_bit;
	reg sticky;
	wire [31:0] value = (i_signed & i_op1[31] ? -i_op1 : i_op1);
	assign o_ready = s_output_ready;
	assign o_result = s_output_z;
	always @(posedge i_clock) begin
		case (state)
			4'd0: begin
				s_output_ready <= 0;
				if (i_request) begin
					if (i_op1 != 0) begin
						z_e <= 31;
						z_m <= value[31:8];
						z_r <= value[7:0];
						z_s <= i_signed & i_op1[31];
						state <= 4'd1;
					end
					else begin
						z_s <= 0;
						z_m <= 0;
						z_e <= -127;
						state <= 4'd3;
					end
				end
			end
			4'd1:
				if (!z_m[23]) begin
					z_e <= z_e - 1;
					z_m <= z_m << 1;
					z_m[0] <= z_r[7];
					z_r <= z_r << 1;
				end
				else begin
					guard <= z_r[7];
					round_bit <= z_r[6];
					sticky <= z_r[5:0] != 0;
					state <= 4'd2;
				end
			4'd2: begin
				if (guard && ((round_bit || sticky) || z_m[0])) begin
					z_m <= z_m + 1;
					if (z_m == 24'hffffff)
						z_e <= z_e + 1;
				end
				state <= 4'd3;
			end
			4'd3: begin
				z[22:0] <= z_m[22:0];
				z[30:23] <= z_e + 127;
				z[31] <= z_s;
				state <= 4'd4;
			end
			4'd4: begin
				s_output_ready <= 1;
				s_output_z <= z;
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