module CPU_BRAM_1r1w (
	i_clock,
	i_pa_request,
	i_pa_address,
	o_pa_rdata,
	o_pa_ready,
	i_pb_request,
	i_pb_address,
	i_pb_wdata,
	o_pb_ready
);
	parameter WIDTH = 32;
	parameter SIZE = 32'h00000400;
	parameter ADDR_LSH = 2;
	input i_clock;
	input i_pa_request;
	input [31:0] i_pa_address;
	output reg [WIDTH - 1:0] o_pa_rdata;
	output reg o_pa_ready;
	input i_pb_request;
	input [31:0] i_pb_address;
	input [WIDTH - 1:0] i_pb_wdata;
	output reg o_pb_ready;
	(* ram_style = "block" *) reg [WIDTH - 1:0] data [0:SIZE - 1];
	initial begin
		o_pa_ready = 0;
		o_pb_ready = 0;
	end
	always @(posedge i_clock) begin
		o_pa_ready <= 1'b0;
		o_pb_ready <= 1'b0;
		if (i_pa_request) begin
			o_pa_rdata <= data[i_pa_address >> ADDR_LSH];
			o_pa_ready <= 1'b1;
		end
		if (i_pb_request) begin
			data[i_pb_address >> ADDR_LSH] <= i_pb_wdata;
			o_pb_ready <= 1'b1;
		end
	end
endmodule