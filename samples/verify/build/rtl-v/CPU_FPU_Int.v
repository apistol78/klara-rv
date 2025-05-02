module CPU_FPU_Int (
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
	reg [2:0] state = 3'd0;
	reg [31:0] a_m;
	reg [31:0] z;
	reg [8:0] a_e;
	reg a_s;
	assign o_ready = s_output_ready;
	assign o_result = s_output_z;
	always @(posedge i_clock) begin
		case (state)
			3'd0: begin
				s_output_ready <= 0;
				if (i_request) begin
					a_m[31:8] <= {1'b1, i_op1[22:0]};
					a_m[7:0] <= 0;
					a_e <= i_op1[30:23] - 127;
					a_s <= i_op1[31];
					state <= 3'd1;
				end
			end
			3'd1:
				if ($signed(a_e) == -127) begin
					z <= 0;
					state <= 3'd3;
				end
				else if ($signed(a_e) > 31) begin
					z <= 32'h80000000;
					state <= 3'd3;
				end
				else
					state <= 3'd2;
			3'd2:
				if (($signed(a_e) < 31) && a_m) begin
					a_e <= a_e + 1;
					a_m <= a_m >> 1;
				end
				else begin
					if (i_signed) begin
						if (a_m[31])
							z <= 32'h80000000;
						else
							z <= (a_s ? -a_m : a_m);
					end
					else
						z <= a_m;
					state <= 3'd3;
				end
			3'd3: begin
				s_output_ready <= 1;
				s_output_z <= z;
				if (!i_request) begin
					s_output_ready <= 0;
					state <= 3'd0;
				end
			end
			default: state <= 3'd0;
		endcase
		if (i_reset) begin
			s_output_ready <= 0;
			state <= 3'd0;
		end
	end
endmodule