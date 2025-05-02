module CPU_PLIC (
	i_reset,
	i_clock,
	i_interrupt_0,
	i_interrupt_1,
	i_interrupt_2,
	i_interrupt_3,
	i_interrupt_enable,
	o_interrupt,
	i_request,
	i_rw,
	i_address,
	i_wdata,
	o_rdata,
	o_ready
);
	input i_reset;
	input i_clock;
	input i_interrupt_0;
	input i_interrupt_1;
	input i_interrupt_2;
	input i_interrupt_3;
	input i_interrupt_enable;
	output reg o_interrupt;
	input i_request;
	input i_rw;
	input [23:0] i_address;
	input [31:0] i_wdata;
	output reg [31:0] o_rdata;
	output reg o_ready;
	reg [3:0] enable = 0;
	reg [3:0] pending = 0;
	reg issued = 1'b0;
	initial begin
		o_interrupt = 1'b0;
		o_rdata = 1'b0;
		o_ready = 1'b0;
	end
	always @(posedge i_clock)
		if (i_reset) begin
			enable <= 0;
			pending <= 0;
			issued <= 1'b0;
		end
		else begin
			if (i_interrupt_enable) begin
				if (enable[0] && i_interrupt_0)
					pending[0] <= 1;
				if (enable[1] && i_interrupt_1)
					pending[1] <= 1;
				if (enable[2] && i_interrupt_2)
					pending[2] <= 1;
				if (enable[3] && i_interrupt_3)
					pending[3] <= 1;
			end
			o_interrupt <= 1'b0;
			if ((i_interrupt_enable && |pending) && !issued) begin
				o_interrupt <= 1'b1;
				issued <= 1'b1;
			end
			o_rdata <= 0;
			o_ready <= 0;
			if (i_request && !i_rw) begin
				if (i_address == 24'h200004) begin
					if (pending[0]) begin
						o_rdata <= 1;
						pending[0] <= 0;
					end
					else if (pending[1]) begin
						o_rdata <= 2;
						pending[1] <= 0;
					end
					else if (pending[2]) begin
						o_rdata <= 3;
						pending[2] <= 0;
					end
					else if (pending[3]) begin
						o_rdata <= 4;
						pending[3] <= 0;
					end
				end
			end
			if (i_request && i_rw) begin
				if (i_address == 24'h002000)
					enable <= i_wdata[4:1];
				else if (i_address == 24'h200004)
					issued <= 0;
			end
			if (i_request)
				o_ready <= 1;
		end
endmodule