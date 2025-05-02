module CPU_SkidBuffer (
	i_reset,
	i_clock,
	i_busy,
	i_data,
	o_data
);
	reg _sv2v_0;
	parameter DW = 0;
	input i_reset;
	input i_clock;
	input i_busy;
	input [DW - 1:0] i_data;
	output reg [DW - 1:0] o_data;
	reg [DW - 1:0] r_data = 0;
	always @(*) begin
		if (_sv2v_0)
			;
		o_data = (!i_busy ? i_data : r_data);
	end
	always @(posedge i_clock)
		if (!i_busy)
			r_data <= i_data;
	initial _sv2v_0 = 0;
endmodule