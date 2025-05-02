module CPU_Writeback (
	i_reset,
	i_clock,
	i_data,
	o_data,
	o_retired
);
	input i_reset;
	input i_clock;
	input wire [38:0] i_data;
	output wire [37:0] o_data;
	output wire [63:0] o_retired;
	reg [37:0] data = 0;
	assign o_data = data;
	reg [63:0] retired = 0;
	assign o_retired = retired;
	reg last_strobe = 0;
	always @(posedge i_clock)
		if (i_reset) begin
			data <= 0;
			retired <= 0;
		end
		else begin
			data[37-:6] <= i_data[37-:6];
			data[31-:32] <= i_data[31-:32];
			if (i_data[38] != last_strobe)
				retired <= retired + 1;
			last_strobe <= i_data[38];
		end
endmodule