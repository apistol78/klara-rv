module CPU_BRAM (
	i_clock,
	i_request,
	i_rw,
	i_address,
	i_wdata,
	o_rdata,
	o_ready,
	o_valid
);
	parameter WIDTH = 32;
	parameter SIZE = 32'h00000400;
	parameter ADDR_LSH = 2;
	input i_clock;
	input i_request;
	input i_rw;
	input [31:0] i_address;
	input [WIDTH - 1:0] i_wdata;
	output reg [WIDTH - 1:0] o_rdata;
	output reg o_ready;
	output reg o_valid;
	(* ram_style = "block" *) reg [WIDTH - 1:0] data [0:SIZE - 1];
	initial begin
		o_ready = 0;
		o_valid = 1;
	end
	always @(posedge i_clock)
		if (i_request) begin
			o_valid <= (i_address >> ADDR_LSH) < SIZE;
			if (!i_rw)
				o_rdata <= data[i_address >> ADDR_LSH];
			else
				data[i_address >> ADDR_LSH] <= i_wdata;
		end
	always @(posedge i_clock) o_ready <= i_request;
endmodule