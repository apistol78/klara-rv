module CPU_ICache_Reg (
	i_reset,
	i_clock,
	i_input_pc,
	o_rdata,
	o_ready,
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
	output reg o_bus_request;
	input i_bus_ready;
	output reg [31:0] o_bus_address;
	input [31:0] i_bus_rdata;
	output wire [31:0] o_hit;
	output wire [31:0] o_miss;
	localparam RANGE = 1 << SIZE;
	localparam SET_BITS = SIZE;
	localparam TAG_BITS = 30 - SIZE;
	assign o_hit = 0;
	assign o_miss = 0;
	reg initialized = 1'b0;
	reg [31:0] clear_set = 0;
	reg cache_invalid = 0;
	wire [SET_BITS - 1:0] i_set = i_input_pc[SET_BITS + 1:2];
	wire [TAG_BITS - 1:0] i_tag = i_input_pc[((TAG_BITS - 1) + SET_BITS) + 2:SET_BITS + 2];
	reg [SET_BITS - 1:0] cache_rd_set;
	wire [(1 + TAG_BITS) + 31:0] cache_rd_rdata;
	reg cache_wr_request = 1'b0;
	reg [SET_BITS - 1:0] cache_wr_set;
	reg [(1 + TAG_BITS) + 31:0] cache_wr_wdata;
	CPU_BRAM_1r1w #(
		.WIDTH((((1 + TAG_BITS) + 31) >= 0 ? (1 + TAG_BITS) + 32 : 1 - ((1 + TAG_BITS) + 31))),
		.SIZE(RANGE),
		.ADDR_LSH(0)
	) cache(
		.i_clock(i_clock),
		.i_pa_request(1'b1),
		.i_pa_address(cache_rd_set),
		.o_pa_rdata(cache_rd_rdata),
		.o_pa_ready(),
		.i_pb_request(cache_wr_request),
		.i_pb_address(cache_wr_set),
		.i_pb_wdata(cache_wr_wdata),
		.o_pb_ready()
	);
	initial o_bus_request = 0;
	reg [SET_BITS - 1:0] set_r = ~0;
	always @(posedge i_clock) set_r <= cache_rd_set;
	always @(*) begin
		if (_sv2v_0)
			;
		o_ready = 0;
		o_rdata = 0;
		cache_rd_set = 0;
		cache_invalid = 1'b0;
		if (initialized) begin
			cache_rd_set = i_set;
			if (set_r == i_set) begin
				if (cache_rd_rdata[1 + (TAG_BITS + 31)] && (cache_rd_rdata[TAG_BITS + 31-:((TAG_BITS + 31) >= 32 ? TAG_BITS + 0 : 33 - (TAG_BITS + 31))] == i_tag)) begin
					o_ready = 1;
					o_rdata = cache_rd_rdata[31-:32];
					cache_rd_set = i_set + 1;
				end
				else
					cache_invalid = 1'b1;
			end
		end
	end
	always @(posedge i_clock) begin
		cache_wr_request <= 1'b0;
		if (initialized) begin
			if ((o_bus_request == 1'b0) && cache_invalid) begin
				cache_wr_set <= i_set;
				cache_wr_wdata[1 + (TAG_BITS + 31)] <= 1'b1;
				cache_wr_wdata[TAG_BITS + 31-:((TAG_BITS + 31) >= 32 ? TAG_BITS + 0 : 33 - (TAG_BITS + 31))] <= i_tag;
				o_bus_request <= 1'b1;
				o_bus_address <= i_input_pc;
			end
			if ((o_bus_request == 1'b1) && i_bus_ready) begin
				cache_wr_request <= 1'b1;
				cache_wr_wdata[31-:32] <= i_bus_rdata;
				o_bus_request <= 1'b0;
			end
		end
		if (!initialized) begin
			if (clear_set < RANGE) begin
				cache_wr_request <= 1'b1;
				cache_wr_set <= clear_set;
				cache_wr_wdata[1 + (TAG_BITS + 31)] <= 1'b0;
				cache_wr_wdata[TAG_BITS + 31-:((TAG_BITS + 31) >= 32 ? TAG_BITS + 0 : 33 - (TAG_BITS + 31))] <= 0;
				cache_wr_wdata[31-:32] <= 0;
				clear_set <= clear_set + 1;
			end
			else
				initialized <= 1'b1;
		end
		if (i_reset) begin
			initialized <= 1'b0;
			clear_set <= 0;
		end
	end
	initial _sv2v_0 = 0;
endmodule