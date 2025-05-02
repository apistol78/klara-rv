module CPU_DCache_Comb (
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
	i_cacheable,
	o_hit,
	o_miss
);
	reg _sv2v_0;
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
	output wire [31:0] o_hit;
	output wire [31:0] o_miss;
	localparam RANGE = 1 << SIZE;
	reg [3:0] state = 4'd11;
	reg [3:0] next = 4'd11;
	reg [SIZE:0] flush_address = 0;
	reg [SIZE:0] next_flush_address = 0;
	assign o_hit = 0;
	assign o_miss = 0;
	reg cache_rw = 0;
	reg [SIZE - 1:0] cache_address = 0;
	reg [63:0] cache_wdata;
	wire [63:0] cache_rdata;
	CPU_BRAM #(
		.WIDTH(64),
		.SIZE(RANGE),
		.ADDR_LSH(0)
	) cache(
		.i_clock(i_clock),
		.i_request(1'b1),
		.i_rw(cache_rw),
		.i_address(cache_address),
		.i_wdata(cache_wdata),
		.o_rdata(cache_rdata),
		.o_ready(),
		.o_valid()
	);
	wire cache_entry_valid = cache_rdata[0];
	wire cache_entry_dirty = cache_rdata[1];
	wire [31:0] cache_entry_address = {cache_rdata[31:2], 2'b00};
	wire [31:0] cache_entry_data = cache_rdata[63:32];
	initial begin
		o_bus_rw = 0;
		o_bus_request = 0;
		o_bus_address = 0;
		o_bus_wdata = 0;
		o_rdata = 0;
	end
	always @(posedge i_clock) begin
		state <= next;
		flush_address <= next_flush_address;
	end
	always @(*) begin
		if (_sv2v_0)
			;
		next = state;
		next_flush_address = flush_address;
		o_bus_rw = 0;
		o_bus_address = 0;
		o_bus_request = 0;
		o_bus_wdata = 0;
		o_rdata = 0;
		o_ready = 0;
		cache_rw = 0;
		cache_wdata = 0;
		cache_address = i_address[SIZE + 1:2];
		case (state)
			4'd0:
				if (i_request) begin
					if (i_flush) begin
						next_flush_address = 0;
						next = 4'd1;
					end
					else if (i_cacheable) begin
						if (!i_rw)
							next = 4'd8;
						else
							next = 4'd6;
					end
					else begin
						o_bus_rw = i_rw;
						o_bus_address = i_address;
						o_bus_request = i_request;
						o_bus_wdata = i_wdata;
						o_rdata = i_bus_rdata;
						next = 4'd5;
					end
				end
			4'd1: begin
				cache_address = flush_address;
				if (flush_address < RANGE)
					next = 4'd2;
				else begin
					o_ready = 1;
					next = 4'd0;
				end
			end
			4'd2: begin
				cache_address = flush_address;
				if (cache_entry_dirty) begin
					o_bus_rw = 1;
					o_bus_address = cache_entry_address;
					o_bus_request = 1;
					o_bus_wdata = cache_entry_data;
					next = 4'd3;
				end
				else begin
					next_flush_address = flush_address + 1;
					next = 4'd1;
				end
			end
			4'd3: begin
				cache_address = flush_address;
				o_bus_rw = 1;
				o_bus_address = cache_entry_address;
				o_bus_request = 1;
				o_bus_wdata = cache_entry_data;
				if (i_bus_ready) begin
					cache_rw = 1;
					cache_wdata = {cache_entry_data, cache_entry_address[31:2], 2'b01};
					next = 4'd4;
				end
			end
			4'd4: begin
				next_flush_address = flush_address + 1;
				next = 4'd1;
			end
			4'd5: begin
				o_bus_rw = i_rw;
				o_bus_address = i_address;
				o_bus_request = i_request;
				o_bus_wdata = i_wdata;
				o_rdata = i_bus_rdata;
				o_ready = i_bus_ready;
				if (!i_request)
					next = 4'd0;
			end
			4'd6:
				if (cache_entry_dirty && (cache_entry_address != i_address)) begin
					o_bus_rw = 1;
					o_bus_address = cache_entry_address;
					o_bus_request = 1;
					o_bus_wdata = cache_entry_data;
					next = 4'd7;
				end
				else begin
					cache_rw = 1;
					cache_wdata = {i_wdata, i_address[31:2], 2'b11};
					o_ready = 1;
					next = 4'd0;
				end
			4'd7: begin
				o_bus_rw = 1;
				o_bus_address = cache_entry_address;
				o_bus_request = 1;
				o_bus_wdata = cache_entry_data;
				if (i_bus_ready) begin
					cache_rw = 1;
					cache_wdata = {i_wdata, i_address[31:2], 2'b11};
					o_ready = 1;
					next = 4'd0;
				end
			end
			4'd8: begin
				o_rdata = cache_entry_data;
				if (cache_entry_valid && (cache_entry_address == i_address)) begin
					o_ready = 1;
					next = 4'd0;
				end
				else if (cache_entry_dirty) begin
					o_bus_rw = 1;
					o_bus_address = cache_entry_address;
					o_bus_request = 1;
					o_bus_wdata = cache_entry_data;
					next = 4'd9;
				end
				else begin
					o_bus_address = i_address;
					o_bus_request = 1;
					next = 4'd10;
				end
			end
			4'd9: begin
				o_bus_rw = 1;
				o_bus_address = cache_entry_address;
				o_bus_request = 1;
				o_bus_wdata = cache_entry_data;
				if (i_bus_ready) begin
					o_bus_rw = 0;
					o_bus_address = i_address;
					next = 4'd10;
				end
			end
			4'd10: begin
				o_bus_rw = 0;
				o_bus_address = i_address;
				o_bus_request = 1;
				o_rdata = i_bus_rdata;
				if (i_bus_ready) begin
					cache_rw = 1;
					cache_wdata = {i_bus_rdata, i_address[31:2], 2'b01};
					o_ready = 1;
					next = 4'd0;
				end
			end
			4'd11:
				if (flush_address < RANGE) begin
					cache_rw = 1'b1;
					cache_wdata = 32'hfffffff0;
					cache_address = flush_address;
					next_flush_address = flush_address + 1;
				end
				else begin
					next_flush_address = 0;
					next = 4'd0;
				end
			default: next = 4'd0;
		endcase
		if (i_reset) begin
			next = 4'd11;
			next_flush_address = 0;
		end
	end
	initial _sv2v_0 = 0;
endmodule