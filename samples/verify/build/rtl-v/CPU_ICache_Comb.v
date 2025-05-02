module CPU_ICache_Comb (
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
	parameter SIZE = 13;
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
	localparam RANGE = 1 << SIZE;
	reg [1:0] next = 2'd3;
	reg [1:0] state = 2'd3;
	reg [SIZE:0] clear_address = 0;
	reg [SIZE:0] next_clear_address = 0;
	assign o_hit = 0;
	assign o_miss = 0;
	reg cache_rw = 0;
	reg [63:0] cache_wdata = 0;
	wire [63:0] cache_rdata;
	reg [31:0] cache_pc;
	wire [SIZE - 1:0] cache_label = cache_pc[SIZE + 1:2];
	CPU_BRAM #(
		.WIDTH(64),
		.SIZE(RANGE),
		.ADDR_LSH(0)
	) cache(
		.i_clock(i_clock),
		.i_request(1'b1),
		.i_rw(cache_rw),
		.i_address(cache_label),
		.i_wdata(cache_wdata),
		.o_rdata(cache_rdata),
		.o_ready(),
		.o_valid()
	);
	assign o_bus_address = i_input_pc;
	always @(posedge i_clock) begin
		state <= next;
		clear_address <= next_clear_address;
	end
	always @(*) begin
		if (_sv2v_0)
			;
		next = state;
		next_clear_address = clear_address;
		o_ready = 0;
		o_rdata = 32'h00000000;
		o_bus_request = 0;
		cache_rw = 0;
		cache_wdata = 0;
		cache_pc = i_input_pc;
		case (state)
			2'd0:
				if (!i_stall)
					next = 2'd1;
			2'd1:
				if (!i_stall) begin
					if (cache_rdata[31:0] == {i_input_pc[31:2], 2'b01}) begin
						o_ready = 1;
						o_rdata = cache_rdata[63:32];
						cache_pc = i_input_pc + 4;
					end
					else begin
						o_bus_request = 1;
						next = 2'd2;
					end
				end
				else
					next = 2'd0;
			2'd2: begin
				o_bus_request = 1;
				if (i_bus_ready) begin
					cache_rw = 1;
					cache_wdata = {i_bus_rdata, i_input_pc[31:2], 2'b01};
					o_ready = 1;
					o_rdata = i_bus_rdata;
					next = 2'd0;
				end
			end
			2'd3:
				if (clear_address < RANGE) begin
					cache_rw = 1;
					cache_wdata = 32'h00000000;
					cache_pc = {clear_address, 2'b00};
					next_clear_address = clear_address + 1;
				end
				else begin
					next_clear_address = 0;
					next = 2'd0;
				end
		endcase
		if (i_reset) begin
			next = 2'd3;
			next_clear_address = 0;
		end
	end
	initial _sv2v_0 = 0;
endmodule