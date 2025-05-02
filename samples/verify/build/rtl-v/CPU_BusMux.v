module CPU_BusMux (
	i_reset,
	i_clock,
	o_bus_rw,
	o_bus_request,
	i_bus_ready,
	o_bus_address,
	i_bus_rdata,
	o_bus_wdata,
	i_pa_request,
	o_pa_ready,
	i_pa_address,
	o_pa_rdata,
	i_pb_rw,
	i_pb_request,
	o_pb_ready,
	i_pb_address,
	o_pb_rdata,
	i_pb_wdata
);
	reg _sv2v_0;
	parameter REGISTERED = 0;
	input i_reset;
	input i_clock;
	output reg o_bus_rw;
	output reg o_bus_request;
	input i_bus_ready;
	output reg [31:0] o_bus_address;
	input [31:0] i_bus_rdata;
	output reg [31:0] o_bus_wdata;
	input i_pa_request;
	output wire o_pa_ready;
	input [31:0] i_pa_address;
	output wire [31:0] o_pa_rdata;
	input i_pb_rw;
	input i_pb_request;
	output wire o_pb_ready;
	input [31:0] i_pb_address;
	output wire [31:0] o_pb_rdata;
	input [31:0] i_pb_wdata;
	reg [1:0] state = 0;
	reg [1:0] next_state = 0;
	initial begin
		o_bus_rw = 1'b0;
		o_bus_request = 1'b0;
		o_bus_address = 0;
		o_bus_wdata = 0;
	end
	generate
		if (!REGISTERED) begin : genblk1
			assign o_pa_ready = (i_pa_request && (state == 2'd1) ? i_bus_ready : 1'b0);
			assign o_pb_ready = (i_pb_request && (state == 2'd2) ? i_bus_ready : 1'b0);
			assign o_pa_rdata = i_bus_rdata;
			assign o_pb_rdata = i_bus_rdata;
			always @(posedge i_clock) state <= next_state;
			always @(*) begin
				if (_sv2v_0)
					;
				next_state = state;
				o_bus_request = 0;
				o_bus_rw = 0;
				o_bus_address = 0;
				o_bus_wdata = 0;
				case (state)
					2'd0:
						if (i_pb_request) begin
							o_bus_rw = i_pb_rw;
							o_bus_address = i_pb_address;
							o_bus_wdata = i_pb_wdata;
							next_state = 2'd2;
						end
						else if (i_pa_request) begin
							o_bus_rw = 1'b0;
							o_bus_address = i_pa_address;
							next_state = 2'd1;
						end
					2'd1: begin
						o_bus_request = i_pa_request;
						o_bus_address = i_pa_address;
						if (i_bus_ready)
							next_state = 2'd0;
					end
					2'd2: begin
						o_bus_request = i_pb_request;
						o_bus_rw = i_pb_rw;
						o_bus_address = i_pb_address;
						o_bus_wdata = i_pb_wdata;
						if (i_bus_ready)
							next_state = 2'd0;
					end
					default: next_state = 2'd0;
				endcase
			end
		end
		if (REGISTERED) begin : genblk2
			assign o_pa_ready = (i_pa_request && (state == 2'd1) ? i_bus_ready : 1'b0);
			assign o_pb_ready = (i_pb_request && (state == 2'd2) ? i_bus_ready : 1'b0);
			assign o_pa_rdata = i_bus_rdata;
			assign o_pb_rdata = i_bus_rdata;
			always @(posedge i_clock)
				if (i_reset) begin
					state <= 2'd0;
					o_bus_rw <= 1'b0;
					o_bus_request <= 1'b0;
					o_bus_address <= 0;
					o_bus_wdata <= 0;
				end
				else
					case (state)
						2'd0: begin
							o_bus_request <= 1'b0;
							if (i_pb_request) begin
								o_bus_rw <= i_pb_rw;
								o_bus_request <= 1'b1;
								o_bus_address <= i_pb_address;
								o_bus_wdata <= i_pb_wdata;
								state <= 2'd2;
							end
							else if (i_pa_request) begin
								o_bus_rw <= 1'b0;
								o_bus_request <= 1'b1;
								o_bus_address <= i_pa_address;
								state <= 2'd1;
							end
						end
						2'd1, 2'd2:
							if (i_bus_ready) begin
								o_bus_request <= 1'b0;
								state <= 2'd0;
							end
						default: state <= 2'd0;
					endcase
		end
	endgenerate
	initial _sv2v_0 = 0;
endmodule