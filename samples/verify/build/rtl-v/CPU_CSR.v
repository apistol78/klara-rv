module CPU_CSR (
	i_reset,
	i_clock,
	i_timer_interrupt,
	i_external_interrupt,
	i_ecall,
	i_mret,
	i_index,
	o_rdata,
	i_wdata_wr,
	i_wdata,
	o_epc,
	o_irq_pending,
	o_irq_pc,
	i_irq_dispatched,
	i_irq_epc,
	i_retired
);
	reg _sv2v_0;
	parameter FREQUENCY = 0;
	parameter VENDORID = 0;
	parameter ARCHID = 0;
	parameter IMPID = 0;
	parameter HARTID = 0;
	input i_reset;
	input i_clock;
	input i_timer_interrupt;
	input i_external_interrupt;
	input i_ecall;
	input i_mret;
	input [11:0] i_index;
	output reg [31:0] o_rdata;
	input i_wdata_wr;
	input [31:0] i_wdata;
	output wire [31:0] o_epc;
	output reg o_irq_pending;
	output reg [31:0] o_irq_pc;
	input i_irq_dispatched;
	input [31:0] i_irq_epc;
	input [63:0] i_retired;
	localparam PRESCALE = FREQUENCY / 1000;
	localparam PRESCALE_WIDTH = $clog2(PRESCALE);
	reg mstatus_mpie = 0;
	reg mstatus_mie = 0;
	reg mie_meie = 0;
	reg mie_mtie = 0;
	reg mie_msie = 0;
	reg [31:0] mtvec = 0;
	reg [31:0] mepc = 0;
	reg [31:0] mcause = 0;
	reg mip_meip = 0;
	reg mip_mtip = 0;
	reg mip_msip = 0;
	reg [31:0] mscratch = 0;
	wire [31:0] mstatus = {27'b000000000000000000000000000, mstatus_mpie, mstatus_mie, 3'b000};
	wire [31:0] mie = {20'b00000000000000000000, mie_meie, 3'b000, mie_mtie, 3'b000, mie_msie, 3'b000};
	wire [31:0] mip = {20'b00000000000000000000, mip_meip, 3'b000, mip_mtip, 3'b000, mip_msip, 3'b000};
	reg [63:0] cycle = 64'd0;
	reg [63:0] wtime = 64'd0;
	reg [PRESCALE_WIDTH - 1:0] prescale = 0;
	reg [2:0] issued = 0;
	assign o_epc = mepc;
	always @(*) begin
		if (_sv2v_0)
			;
		o_rdata = 0;
		if (i_index == 12'h300)
			o_rdata = mstatus;
		else if (i_index == 12'h304)
			o_rdata = mie;
		else if (i_index == 12'h305)
			o_rdata = mtvec;
		else if (i_index == 12'h340)
			o_rdata = mscratch;
		else if (i_index == 12'h341)
			o_rdata = mepc;
		else if (i_index == 12'h342)
			o_rdata = mcause;
		else if (i_index == 12'h344)
			o_rdata = mip;
		else if (i_index == 12'hc00)
			o_rdata = cycle[31:0];
		else if (i_index == 12'hc80)
			o_rdata = cycle[63:32];
		else if (i_index == 12'hc01)
			o_rdata = wtime[31:0];
		else if (i_index == 12'hc81)
			o_rdata = wtime[63:32];
		else if (i_index == 12'hc02)
			o_rdata = i_retired[31:0];
		else if (i_index == 12'hc82)
			o_rdata = i_retired[63:32];
		else if (i_index == 12'hf11)
			o_rdata = VENDORID;
		else if (i_index == 12'hf12)
			o_rdata = ARCHID;
		else if (i_index == 12'hf13)
			o_rdata = IMPID;
		else if (i_index == 12'hf14)
			o_rdata = HARTID;
	end
	always @(posedge i_clock)
		if (i_reset) begin
			mstatus_mie <= 0;
			mie_meie <= 0;
			mie_mtie <= 0;
			mie_msie <= 0;
			mtvec <= 0;
			mepc <= 0;
			mcause <= 0;
			mip_meip <= 0;
			mip_mtip <= 0;
			mip_msip <= 0;
			mscratch <= 0;
			issued <= 0;
			o_irq_pending <= 1'b0;
		end
		else begin
			if (i_wdata_wr) begin
				if (i_index == 12'h300)
					mstatus_mie <= i_wdata[3];
				else if (i_index == 12'h304) begin
					mie_meie <= i_wdata[11];
					mie_mtie <= i_wdata[7];
					mie_msie <= i_wdata[3];
				end
				else if (i_index == 12'h305)
					mtvec <= i_wdata;
				else if (i_index == 12'h340)
					mscratch <= i_wdata;
				else if (i_index == 12'h341)
					mepc <= i_wdata;
				else if (i_index == 12'h344) begin
					mip_mtip <= i_wdata[7];
					mip_msip <= i_wdata[3];
				end
			end
			if (i_timer_interrupt && mie_mtie)
				mip_mtip <= 1'b1;
			if (i_external_interrupt && mie_meie)
				mip_meip <= 1'b1;
			if (i_ecall && mie_msie)
				mip_msip <= 1'b1;
			if (!o_irq_pending && mstatus_mie) begin
				if (mip_meip) begin
					mcause <= 33'sd2147485696;
					issued <= 3'b010;
				end
				else if (mip_mtip) begin
					mcause <= 33'sd2147483776;
					issued <= 3'b001;
				end
				else if (mip_msip) begin
					mcause <= 2048;
					issued <= 3'b100;
				end
				if ((mip_mtip || mip_meip) || mip_msip) begin
					o_irq_pending <= 1'b1;
					o_irq_pc <= mtvec;
					mstatus_mpie <= mstatus_mie;
					mstatus_mie <= 1'b0;
				end
			end
			if (i_mret) begin
				if (mstatus_mie)
					$display("recursive interrupt detected, not validated");
				mstatus_mie <= mstatus_mpie;
				mstatus_mpie <= 1'b0;
			end
			if (i_irq_dispatched) begin
				mepc <= i_irq_epc;
				if (issued[0])
					mip_mtip <= 1'b0;
				if (issued[1])
					mip_meip <= 1'b0;
				if (issued[2])
					mip_msip <= 1'b0;
				o_irq_pending <= 1'b0;
				issued <= 0;
			end
		end
	always @(posedge i_clock)
		if (i_reset) begin
			wtime <= 64'd0;
			prescale <= 0;
			cycle <= 0;
		end
		else begin
			prescale <= prescale + 1;
			if (prescale >= PRESCALE) begin
				wtime <= wtime + 64'd1;
				prescale <= 0;
			end
			cycle <= cycle + 64'd1;
		end
	initial _sv2v_0 = 0;
endmodule