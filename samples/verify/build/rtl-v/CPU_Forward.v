module CPU_Forward (
	i_decode_data,
	i_execute_data,
	i_memory_data,
	i_writeback_data,
	i_rs1,
	i_rs2,
	i_rs3,
	o_rs1,
	o_rs2,
	o_rs3
);
	reg _sv2v_0;
	input wire [127:0] i_decode_data;
	input wire [82:0] i_execute_data;
	input wire [38:0] i_memory_data;
	input wire [37:0] i_writeback_data;
	input [31:0] i_rs1;
	input [31:0] i_rs2;
	input [31:0] i_rs3;
	output wire [31:0] o_rs1;
	output wire [31:0] o_rs2;
	output wire [31:0] o_rs3;
	reg [31:0] rs1;
	assign o_rs1 = rs1;
	reg [31:0] rs2;
	assign o_rs2 = rs2;
	reg [31:0] rs3;
	assign o_rs3 = rs3;
	always @(*) begin
		if (_sv2v_0)
			;
		rs1 = 32'h00000000;
		if (i_decode_data[92])
			rs1 = (i_decode_data[91-:6] == i_execute_data[81-:6] ? i_execute_data[75-:32] : (i_decode_data[91-:6] == i_memory_data[37-:6] ? i_memory_data[31-:32] : (i_decode_data[91-:6] == i_writeback_data[37-:6] ? i_writeback_data[31-:32] : i_rs1)));
	end
	always @(*) begin
		if (_sv2v_0)
			;
		rs2 = 32'h00000000;
		if (i_decode_data[93])
			rs2 = (i_decode_data[85-:6] == i_execute_data[81-:6] ? i_execute_data[75-:32] : (i_decode_data[85-:6] == i_memory_data[37-:6] ? i_memory_data[31-:32] : (i_decode_data[85-:6] == i_writeback_data[37-:6] ? i_writeback_data[31-:32] : i_rs2)));
	end
	always @(*) begin
		if (_sv2v_0)
			;
		rs3 = 32'h00000000;
		if (i_decode_data[94])
			rs3 = (i_decode_data[79-:6] == i_execute_data[81-:6] ? i_execute_data[75-:32] : (i_decode_data[79-:6] == i_memory_data[37-:6] ? i_memory_data[31-:32] : (i_decode_data[79-:6] == i_writeback_data[37-:6] ? i_writeback_data[31-:32] : i_rs3)));
	end
	initial _sv2v_0 = 0;
endmodule