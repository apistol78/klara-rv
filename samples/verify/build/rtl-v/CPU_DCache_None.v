module CPU_DCache_None (
	i_reset,
	i_clock,
	o_bus_rw,
	o_bus_request,
	i_bus_ready,
	o_bus_address,
	i_bus_rdata,
	o_bus_wdata,
	i_rw,
	i_request,
	i_flush,
	o_ready,
	i_address,
	o_rdata,
	i_wdata,
	i_cacheable
);
	parameter SIZE = 14;
	input i_reset;
	input i_clock;
	output reg o_bus_rw;
	output reg o_bus_request;
	input i_bus_ready;
	output reg [31:0] o_bus_address;
	input [31:0] i_bus_rdata;
	output reg [31:0] o_bus_wdata;
	input i_rw;
	input i_request;
	input i_flush;
	output reg o_ready;
	input [31:0] i_address;
	output reg [31:0] o_rdata;
	input [31:0] i_wdata;
	input i_cacheable;
	initial begin
		o_bus_request = 0;
		o_ready = 0;
	end
	always @(posedge i_clock) begin
		o_bus_request <= i_request;
		o_bus_rw <= i_rw;
		o_bus_address <= i_address;
		o_bus_wdata <= i_wdata;
		o_rdata <= i_bus_rdata;
		o_ready <= i_bus_ready;
	end
endmodule