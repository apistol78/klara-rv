module CPU_ICache_None (
	i_reset,
	i_clock,
	i_input_pc,
	o_rdata,
	o_ready,
	i_stall,
	o_bus_request,
	i_bus_ready,
	o_bus_address,
	i_bus_rdata,
	o_hit,
	o_miss
);
	reg _sv2v_0;
	input i_reset;
	input i_clock;
	input [31:0] i_input_pc;
	output reg [31:0] o_rdata;
	output reg o_ready;
	input i_stall;
	output reg o_bus_request;
	input i_bus_ready;
	output wire [31:0] o_bus_address;
	input [31:0] i_bus_rdata;
	output wire [31:0] o_hit;
	output wire [31:0] o_miss;
	reg [1:0] next = 2'd0;
	reg [1:0] state = 2'd0;
	assign o_hit = 0;
	assign o_miss = 0;
	assign o_bus_address = i_input_pc;
	always @(*) begin
		if (_sv2v_0)
			;
		next = state;
		o_ready = 0;
		o_rdata = 32'h00000000;
		o_bus_request = 0;
		case (state)
			2'd0:
				if (!i_stall) begin
					o_bus_request = 1;
					next = 2'd1;
				end
			2'd1: begin
				o_bus_request = 1;
				if (i_bus_ready) begin
					o_ready = 1;
					o_rdata = i_bus_rdata;
					next = 2'd0;
				end
			end
		endcase
		if (i_reset)
			next = 2'd0;
	end
	initial _sv2v_0 = 0;
endmodule