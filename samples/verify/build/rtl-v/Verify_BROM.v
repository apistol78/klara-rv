module Verify_BROM (
	i_clock,
	i_request,
	i_address,
	o_rdata,
	o_ready
);
	input i_clock;
	input i_request;
	input [31:0] i_address;
	output reg [31:0] o_rdata;
	output reg o_ready;
	reg [31:0] data [0:3];
	initial o_ready = 0;
	initial $readmemh("Verify.vmem", data);
	always @(posedge i_clock)
		if (i_request)
			o_rdata <= data[i_address >> 2];
		else
			o_rdata <= 32'hxxxxxxxx;
	always @(posedge i_clock) o_ready <= i_request;
endmodule