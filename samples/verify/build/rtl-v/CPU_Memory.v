module CPU_Memory (
	i_reset,
	i_clock,
	o_bus_rw,
	o_bus_request,
	i_bus_ready,
	o_bus_address,
	i_bus_rdata,
	o_bus_wdata,
	o_busy,
	i_data,
	o_data,
	o_dcache_hit,
	o_dcache_miss
);
	reg _sv2v_0;
	parameter DCACHE_SIZE = 0;
	parameter DCACHE_REGISTERED = 0;
	input i_reset;
	input i_clock;
	output wire o_bus_rw;
	output wire o_bus_request;
	input i_bus_ready;
	output wire [31:0] o_bus_address;
	input [31:0] i_bus_rdata;
	output wire [31:0] o_bus_wdata;
	output reg o_busy;
	input wire [82:0] i_data;
	output wire [38:0] o_data;
	output wire [31:0] o_dcache_hit;
	output wire [31:0] o_dcache_miss;
	reg dcache_rw = 0;
	reg dcache_request = 0;
	reg dcache_flush = 0;
	wire dcache_ready;
	wire [31:0] dcache_address;
	wire [31:0] dcache_rdata;
	reg [31:0] dcache_wdata = 0;
	wire dcache_need_flush;
	wire dcache_cacheable = i_data[37:34] == 4'h2;
	generate
		if ((DCACHE_SIZE > 0) && (DCACHE_REGISTERED != 0)) begin : genblk1
			CPU_DCache_Reg #(.SIZE(DCACHE_SIZE)) dcache(
				.i_reset(i_reset),
				.i_clock(i_clock),
				.o_bus_rw(o_bus_rw),
				.o_bus_request(o_bus_request),
				.i_bus_ready(i_bus_ready),
				.o_bus_address(o_bus_address),
				.i_bus_rdata(i_bus_rdata),
				.o_bus_wdata(o_bus_wdata),
				.i_rw(dcache_rw),
				.i_request(dcache_request),
				.i_flush(dcache_flush),
				.o_ready(dcache_ready),
				.i_address(dcache_address),
				.o_rdata(dcache_rdata),
				.i_wdata(dcache_wdata),
				.i_cacheable(dcache_cacheable),
				.o_hit(o_dcache_hit),
				.o_miss(o_dcache_miss)
			);
			assign dcache_need_flush = 1'b1;
		end
		if ((DCACHE_SIZE > 0) && (DCACHE_REGISTERED == 0)) begin : genblk2
			CPU_DCache_Comb #(.SIZE(DCACHE_SIZE)) dcache(
				.i_reset(i_reset),
				.i_clock(i_clock),
				.o_bus_rw(o_bus_rw),
				.o_bus_request(o_bus_request),
				.i_bus_ready(i_bus_ready),
				.o_bus_address(o_bus_address),
				.i_bus_rdata(i_bus_rdata),
				.o_bus_wdata(o_bus_wdata),
				.i_rw(dcache_rw),
				.i_request(dcache_request),
				.i_flush(dcache_flush),
				.o_ready(dcache_ready),
				.i_address(dcache_address),
				.o_rdata(dcache_rdata),
				.i_wdata(dcache_wdata),
				.i_cacheable(dcache_cacheable),
				.o_hit(o_dcache_hit),
				.o_miss(o_dcache_miss)
			);
			assign dcache_need_flush = 1'b1;
		end
		if (DCACHE_SIZE == 0) begin : genblk3
			assign o_bus_rw = dcache_rw;
			assign o_bus_request = dcache_request;
			assign dcache_ready = i_bus_ready;
			assign o_bus_address = dcache_address;
			assign dcache_rdata = i_bus_rdata;
			assign o_bus_wdata = dcache_wdata;
			assign dcache_need_flush = 1'b0;
			assign o_dcache_hit = 0;
			assign o_dcache_miss = 0;
		end
	endgenerate
	reg [38:0] data = 0;
	assign o_data = data;
	assign dcache_address = {i_data[37:8], 2'b00};
	wire [1:0] address_byte_index = i_data[7:6];
	wire [7:0] bus_rdata_byte = dcache_rdata >> (address_byte_index * 8);
	wire [15:0] bus_rdata_half = dcache_rdata >> (address_byte_index * 8);
	reg [2:0] state = 3'd0;
	reg [31:0] rmw_rdata = 0;
	reg last_strobe = 0;
	always @(*) begin
		if (_sv2v_0)
			;
		o_busy = (i_data[82] != last_strobe) && ((i_data[43] || i_data[42]) || i_data[41]);
	end
	always @(posedge i_clock)
		(* full_case, parallel_case *)
		case (state)
			3'd0: begin
				dcache_request <= 0;
				dcache_rw <= 0;
				dcache_wdata <= 0;
				dcache_flush <= 0;
				if (i_data[82] != last_strobe) begin
					if (i_data[43]) begin
						dcache_request <= 1;
						state <= 3'd1;
					end
					else if (i_data[42]) begin
						dcache_request <= 1;
						if (i_data[40-:2] == 2'b10) begin
							dcache_rw <= 1;
							dcache_wdata <= i_data[75-:32];
							state <= 3'd2;
						end
						else
							state <= 3'd3;
					end
					else if (i_data[41] && dcache_need_flush) begin
						dcache_request <= 1;
						dcache_flush <= 1;
						state <= 3'd5;
					end
					else begin
						data[31-:32] <= i_data[75-:32];
						data[37-:6] <= i_data[81-:6];
						data[38] <= ~data[38];
						last_strobe <= i_data[82];
					end
				end
			end
			3'd5:
				if (dcache_ready) begin
					dcache_request <= 0;
					dcache_flush <= 0;
					data[31-:32] <= i_data[75-:32];
					data[37-:6] <= i_data[81-:6];
					data[38] <= ~data[38];
					last_strobe <= i_data[82];
					state <= 3'd0;
				end
			3'd1:
				if (dcache_ready) begin
					dcache_request <= 0;
					case (i_data[40-:2])
						2'b10: data[31-:32] <= dcache_rdata;
						2'b01: data[31-:32] <= {{16 {i_data[38] & bus_rdata_half[15]}}, bus_rdata_half[15:0]};
						2'b00: data[31-:32] <= {{24 {i_data[38] & bus_rdata_byte[7]}}, bus_rdata_byte[7:0]};
						default: data[31-:32] <= 0;
					endcase
					data[37-:6] <= i_data[5-:6];
					data[38] <= ~data[38];
					last_strobe <= i_data[82];
					state <= 3'd0;
				end
			3'd2:
				if (dcache_ready) begin
					dcache_request <= 0;
					dcache_rw <= 0;
					data[31-:32] <= i_data[75-:32];
					data[37-:6] <= i_data[81-:6];
					data[38] <= ~data[38];
					last_strobe <= i_data[82];
					state <= 3'd0;
				end
			3'd3:
				if (dcache_ready) begin
					dcache_request <= 0;
					rmw_rdata <= dcache_rdata;
					state <= 3'd4;
				end
			3'd4: begin
				dcache_request <= 1;
				dcache_rw <= 1;
				if (i_data[40-:2] == 2'b00)
					(* full_case, parallel_case *)
					case (address_byte_index)
						2'd0: dcache_wdata <= {rmw_rdata[31:24], rmw_rdata[23:16], rmw_rdata[15:8], i_data[51:44]};
						2'd1: dcache_wdata <= {rmw_rdata[31:24], rmw_rdata[23:16], i_data[51:44], rmw_rdata[7:0]};
						2'd2: dcache_wdata <= {rmw_rdata[31:24], i_data[51:44], rmw_rdata[15:8], rmw_rdata[7:0]};
						2'd3: dcache_wdata <= {i_data[51:44], rmw_rdata[23:16], rmw_rdata[15:8], rmw_rdata[7:0]};
					endcase
				else
					(* full_case, parallel_case *)
					case (address_byte_index)
						2'd0: dcache_wdata <= {rmw_rdata[31:16], i_data[59:44]};
						2'd2: dcache_wdata <= {i_data[59:44], rmw_rdata[15:0]};
						default: dcache_wdata <= 0;
					endcase
				if (dcache_ready) begin
					dcache_request <= 0;
					dcache_rw <= 0;
					data[31-:32] <= i_data[75-:32];
					data[37-:6] <= i_data[81-:6];
					data[38] <= ~data[38];
					last_strobe <= i_data[82];
					state <= 3'd0;
				end
			end
			default: state <= 3'd0;
		endcase
	initial _sv2v_0 = 0;
endmodule