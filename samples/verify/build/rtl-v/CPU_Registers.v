module CPU_Registers (
	i_reset,
	i_clock,
	i_fetch_data,
	o_rs1,
	o_rs2,
	o_rs3,
	i_memory_data
);
	parameter STACK_POINTER = 0;
	input i_reset;
	input i_clock;
	input wire [120:0] i_fetch_data;
	output wire [31:0] o_rs1;
	output wire [31:0] o_rs2;
	output wire [31:0] o_rs3;
	input wire [38:0] i_memory_data;
	reg [31:0] rs1 = 0;
	assign o_rs1 = rs1;
	reg [31:0] rs2 = 0;
	assign o_rs2 = rs2;
	reg [31:0] rs3 = 0;
	assign o_rs3 = rs3;
	reg last_write_strobe = 1'b0;
	reg [31:0] r [63:0];
	integer I;
	initial begin
		for (I = 0; I < 32; I = I + 1)
			r[I] = 32'h00000000;
		for (I = 32; I < 64; I = I + 1)
			r[I] = 32'h00000000;
		r[2] = STACK_POINTER;
	end
	always @(posedge i_clock or posedge i_reset)
		if (i_reset) begin
			rs1 <= 0;
			rs2 <= 0;
			rs3 <= 0;
			last_write_strobe <= 1'b0;
			for (I = 0; I < 32; I = I + 1)
				r[I] = 32'h00000000;
			for (I = 32; I < 64; I = I + 1)
				r[I] = 32'h00000000;
			r[2] = STACK_POINTER;
		end
		else begin
			rs1 <= (i_fetch_data[55-:6] != 0 ? r[i_fetch_data[55-:6]] : 32'h00000000);
			rs2 <= (i_fetch_data[49-:6] != 0 ? r[i_fetch_data[49-:6]] : 32'h00000000);
			rs3 <= (i_fetch_data[43-:6] != 0 ? r[i_fetch_data[43-:6]] : 32'h00000000);
			if (i_memory_data[38] != last_write_strobe) begin
				if (|i_memory_data[37-:6])
					r[i_memory_data[37-:6]] <= i_memory_data[31-:32];
				last_write_strobe <= i_memory_data[38];
			end
		end
endmodule