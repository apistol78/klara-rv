module CPU_Fetch (
	i_reset,
	i_clock,
	i_jump,
	i_jump_pc,
	i_irq_pending,
	i_irq_pc,
	o_irq_dispatched,
	o_irq_epc,
	o_bus_request,
	i_bus_ready,
	o_bus_address,
	i_bus_rdata,
	i_busy,
	o_data,
	o_icache_hit,
	o_icache_miss
);
	parameter RESET_VECTOR = 0;
	parameter ICACHE_SIZE = 0;
	parameter ICACHE_REGISTERED = 0;
	input i_reset;
	input i_clock;
	input i_jump;
	input [31:0] i_jump_pc;
	input i_irq_pending;
	input [31:0] i_irq_pc;
	output reg o_irq_dispatched;
	output reg [31:0] o_irq_epc;
	output wire o_bus_request;
	input i_bus_ready;
	output wire [31:0] o_bus_address;
	input [31:0] i_bus_rdata;
	input i_busy;
	output wire [120:0] o_data;
	output wire [31:0] o_icache_hit;
	output wire [31:0] o_icache_miss;
	reg [1:0] state = 2'd0;
	reg [31:0] pc = RESET_VECTOR;
	reg [120:0] data = 0;
	reg [31:0] starve = 0;
	wire [31:0] icache_rdata;
	wire icache_ready;
	generate
		if ((ICACHE_SIZE > 0) && (ICACHE_REGISTERED != 0)) begin : genblk1
			CPU_ICache_Reg #(.SIZE(ICACHE_SIZE)) icache(
				.i_reset(i_reset),
				.i_clock(i_clock),
				.i_input_pc(pc),
				.o_rdata(icache_rdata),
				.o_ready(icache_ready),
				.o_bus_request(o_bus_request),
				.i_bus_ready(i_bus_ready),
				.o_bus_address(o_bus_address),
				.i_bus_rdata(i_bus_rdata),
				.o_hit(o_icache_hit),
				.o_miss(o_icache_miss)
			);
		end
		if ((ICACHE_SIZE > 0) && (ICACHE_REGISTERED == 0)) begin : genblk2
			CPU_ICache_Comb #(.SIZE(ICACHE_SIZE)) icache(
				.i_reset(i_reset),
				.i_clock(i_clock),
				.i_input_pc(pc),
				.o_rdata(icache_rdata),
				.o_ready(icache_ready),
				.i_stall(),
				.o_bus_request(o_bus_request),
				.i_bus_ready(i_bus_ready),
				.o_bus_address(o_bus_address),
				.i_bus_rdata(i_bus_rdata),
				.o_hit(o_icache_hit),
				.o_miss(o_icache_miss)
			);
		end
		if (ICACHE_SIZE == 0) begin : genblk3
			CPU_ICache_None icache(
				.i_reset(i_reset),
				.i_clock(i_clock),
				.i_input_pc(pc),
				.o_rdata(icache_rdata),
				.o_ready(icache_ready),
				.i_stall(),
				.o_bus_request(o_bus_request),
				.i_bus_ready(i_bus_ready),
				.o_bus_address(o_bus_address),
				.i_bus_rdata(i_bus_rdata),
				.o_hit(o_icache_hit),
				.o_miss(o_icache_miss)
			);
		end
	endgenerate
	wire is_ADD = (icache_rdata[31:0] & 32'hfe00707f) == 32'h00000033;
	wire is_ADDI = (icache_rdata[15:0] & 16'h707f) == 16'h0013;
	wire is_AND = (icache_rdata[31:0] & 32'hfe00707f) == 32'h00007033;
	wire is_ANDI = (icache_rdata[15:0] & 16'h707f) == 16'h7013;
	wire is_AUIPC = (icache_rdata[7:0] & 8'h7f) == 8'h17;
	wire is_BEQ = (icache_rdata[15:0] & 16'h707f) == 16'h0063;
	wire is_BGE = (icache_rdata[15:0] & 16'h707f) == 16'h5063;
	wire is_BGEU = (icache_rdata[15:0] & 16'h707f) == 16'h7063;
	wire is_BLT = (icache_rdata[15:0] & 16'h707f) == 16'h4063;
	wire is_BLTU = (icache_rdata[15:0] & 16'h707f) == 16'h6063;
	wire is_BNE = (icache_rdata[15:0] & 16'h707f) == 16'h1063;
	wire is_CSRRC = (icache_rdata[15:0] & 16'h707f) == 16'h3073;
	wire is_CSRRS = (icache_rdata[15:0] & 16'h707f) == 16'h2073;
	wire is_CSRRW = (icache_rdata[15:0] & 16'h707f) == 16'h1073;
	wire is_DIV = (icache_rdata[31:0] & 32'hfe00707f) == 32'h02004033;
	wire is_DIVU = (icache_rdata[31:0] & 32'hfe00707f) == 32'h02005033;
	wire is_EBREAK = (icache_rdata[31:0] & 32'hffffffff) == 32'h00100073;
	wire is_ECALL = (icache_rdata[31:0] & 32'hffffffff) == 32'h00000073;
	wire is_FADD = (icache_rdata[31:0] & 32'hfe00007f) == 32'h00000053;
	wire is_FCVT_W_S = (icache_rdata[31:0] & 32'hfff0007f) == 32'hc0000053;
	wire is_FCVT_WU_S = (icache_rdata[31:0] & 32'hfff0007f) == 32'hc0100053;
	wire is_FCVT_S_W = (icache_rdata[31:0] & 32'hfff0007f) == 32'hd0000053;
	wire is_FCVT_S_WU = (icache_rdata[31:0] & 32'hfff0007f) == 32'hd0100053;
	wire is_FDIV = (icache_rdata[31:0] & 32'hfe00007f) == 32'h18000053;
	wire is_FENCE = (icache_rdata[15:0] & 16'h707f) == 16'h000f;
	wire is_FEQ = (icache_rdata[31:0] & 32'hfe00707f) == 32'ha0002053;
	wire is_FLE = (icache_rdata[31:0] & 32'hfe00707f) == 32'ha0000053;
	wire is_FLT = (icache_rdata[31:0] & 32'hfe00707f) == 32'ha0001053;
	wire is_FLW = (icache_rdata[15:0] & 16'h707f) == 16'h2007;
	wire is_FMADD = (icache_rdata[31:0] & 32'h0600007f) == 32'h00000043;
	wire is_FMSUB = (icache_rdata[31:0] & 32'h0600007f) == 32'h00000047;
	wire is_FNMADD = (icache_rdata[31:0] & 32'h0600007f) == 32'h0000004f;
	wire is_FNMSUB = (icache_rdata[31:0] & 32'h0600007f) == 32'h0000004b;
	wire is_FMIN = (icache_rdata[31:0] & 32'hfe00707f) == 32'h28000053;
	wire is_FMAX = (icache_rdata[31:0] & 32'hfe00707f) == 32'h28001053;
	wire is_FMUL = (icache_rdata[31:0] & 32'hfe00007f) == 32'h10000053;
	wire is_FMV_X_W = (icache_rdata[31:0] & 32'hfff0707f) == 32'he0000053;
	wire is_FMV_W_X = (icache_rdata[31:0] & 32'hfff0707f) == 32'hf0000053;
	wire is_FSGNJ = (icache_rdata[31:0] & 32'hfe00707f) == 32'h20000053;
	wire is_FSGNJN = (icache_rdata[31:0] & 32'hfe00707f) == 32'h20001053;
	wire is_FSGNJX = (icache_rdata[31:0] & 32'hfe00707f) == 32'h20002053;
	wire is_FSUB = (icache_rdata[31:0] & 32'hfe00007f) == 32'h08000053;
	wire is_FSW = (icache_rdata[15:0] & 16'h707f) == 16'h2027;
	wire is_JAL = (icache_rdata[7:0] & 8'h7f) == 8'h6f;
	wire is_JALR = (icache_rdata[15:0] & 16'h707f) == 16'h0067;
	wire is_LB = (icache_rdata[15:0] & 16'h707f) == 16'h0003;
	wire is_LBU = (icache_rdata[15:0] & 16'h707f) == 16'h4003;
	wire is_LH = (icache_rdata[15:0] & 16'h707f) == 16'h1003;
	wire is_LHU = (icache_rdata[15:0] & 16'h707f) == 16'h5003;
	wire is_LUI = (icache_rdata[7:0] & 8'h7f) == 8'h37;
	wire is_LW = (icache_rdata[15:0] & 16'h707f) == 16'h2003;
	wire is_MUL = (icache_rdata[31:0] & 32'hfe00707f) == 32'h02000033;
	wire is_MULH = (icache_rdata[31:0] & 32'hfe00707f) == 32'h02001033;
	wire is_MULHU = (icache_rdata[31:0] & 32'hfe00707f) == 32'h02003033;
	wire is_MRET = (icache_rdata[31:0] & 32'hffffffff) == 32'h30200073;
	wire is_OR = (icache_rdata[31:0] & 32'hfe00707f) == 32'h00006033;
	wire is_ORI = (icache_rdata[15:0] & 16'h707f) == 16'h6013;
	wire is_REM = (icache_rdata[31:0] & 32'hfe00707f) == 32'h02006033;
	wire is_REMU = (icache_rdata[31:0] & 32'hfe00707f) == 32'h02007033;
	wire is_SB = (icache_rdata[15:0] & 16'h707f) == 16'h0023;
	wire is_SH = (icache_rdata[15:0] & 16'h707f) == 16'h1023;
	wire is_SLL = (icache_rdata[31:0] & 32'hfe00707f) == 32'h00001033;
	wire is_SLLI = (icache_rdata[31:0] & 32'hfc00707f) == 32'h00001013;
	wire is_SLT = (icache_rdata[31:0] & 32'hfe00707f) == 32'h00002033;
	wire is_SLTI = (icache_rdata[15:0] & 16'h707f) == 16'h2013;
	wire is_SLTIU = (icache_rdata[15:0] & 16'h707f) == 16'h3013;
	wire is_SLTU = (icache_rdata[31:0] & 32'hfe00707f) == 32'h00003033;
	wire is_SRA = (icache_rdata[31:0] & 32'hfe00707f) == 32'h40005033;
	wire is_SRAI = (icache_rdata[31:0] & 32'hfc00707f) == 32'h40005013;
	wire is_SRL = (icache_rdata[31:0] & 32'hfe00707f) == 32'h00005033;
	wire is_SRLI = (icache_rdata[31:0] & 32'hfc00707f) == 32'h00005013;
	wire is_SUB = (icache_rdata[31:0] & 32'hfe00707f) == 32'h40000033;
	wire is_SW = (icache_rdata[15:0] & 16'h707f) == 16'h2023;
	wire is_WFI = (icache_rdata[31:0] & 32'hffffffff) == 32'h10500073;
	wire is_XOR = (icache_rdata[31:0] & 32'hfe00707f) == 32'h00004033;
	wire is_XORI = (icache_rdata[15:0] & 16'h707f) == 16'h4013;
	wire is_B = ((((is_BEQ | is_BGE) | is_BGEU) | is_BLT) | is_BLTU) | is_BNE;
	wire is_I = ((((((((((((is_ADDI | is_ANDI) | is_FENCE) | is_FLW) | is_JALR) | is_LB) | is_LBU) | is_LH) | is_LHU) | is_LW) | is_ORI) | is_SLTI) | is_SLTIU) | is_XORI;
	wire is_J = is_JAL;
	wire is_R = ((((((((((((((((((((((((((((((((((((is_ADD | is_AND) | is_DIV) | is_DIVU) | is_FADD) | is_FCVT_W_S) | is_FCVT_WU_S) | is_FCVT_S_W) | is_FCVT_S_WU) | is_FDIV) | is_FEQ) | is_FLE) | is_FLT) | is_FMIN) | is_FMAX) | is_FMUL) | is_FMV_X_W) | is_FMV_W_X) | is_FSGNJ) | is_FSGNJN) | is_FSGNJX) | is_FSUB) | is_MUL) | is_MULH) | is_MULHU) | is_OR) | is_REM) | is_REMU) | is_SLL) | is_SLLI) | is_SLT) | is_SLTU) | is_SRA) | is_SRAI) | is_SRL) | is_SRLI) | is_SUB) | is_XOR;
	wire is_R4 = ((is_FMADD | is_FMSUB) | is_FNMADD) | is_FNMSUB;
	wire is_S = ((is_FSW | is_SB) | is_SH) | is_SW;
	wire is_U = is_AUIPC | is_LUI;
	wire is_CSR = ((is_CSRRC | is_CSRRS) | is_CSRRW) | is_MRET;
	wire is_ARITHMETIC = (((((((((is_ADD | is_ADDI) | is_AND) | is_ANDI) | is_AUIPC) | is_LUI) | is_OR) | is_ORI) | is_SUB) | is_XOR) | is_XORI;
	wire is_SHIFT = ((((is_SLL | is_SLLI) | is_SRA) | is_SRAI) | is_SRL) | is_SRLI;
	wire is_COMPARE = ((is_SLT | is_SLTI) | is_SLTIU) | is_SLTU;
	wire is_COMPLEX = (((((((((((((is_CSRRC | is_CSRRS) | is_CSRRW) | is_DIV) | is_DIVU) | is_EBREAK) | is_ECALL) | is_FENCE) | is_MUL) | is_MULH) | is_MULHU) | is_MRET) | is_REM) | is_REMU) | is_WFI;
	wire is_JUMP = is_JAL | is_JALR;
	wire is_JUMP_CONDITIONAL = ((((is_BEQ | is_BGE) | is_BGEU) | is_BLT) | is_BLTU) | is_BNE;
	wire is_MEMORY = ((((((is_LB | is_LBU) | is_LH) | is_LHU) | is_LW) | is_SB) | is_SH) | is_SW;
	wire is_FPU = ((((((((((((((((((((is_FADD | is_FCVT_W_S) | is_FCVT_WU_S) | is_FCVT_S_W) | is_FCVT_S_WU) | is_FDIV) | is_FEQ) | is_FLE) | is_FLT) | is_FMADD) | is_FMSUB) | is_FNMADD) | is_FNMSUB) | is_FMIN) | is_FMAX) | is_FMUL) | is_FMV_X_W) | is_FMV_W_X) | is_FSGNJ) | is_FSGNJN) | is_FSGNJX) | is_FSUB;
	wire is_FPU_MEMORY = is_FLW | is_FSW;
	wire RD_bank = (is_FADD ? 1'd1 : (is_FCVT_S_W ? 1'd1 : (is_FCVT_S_WU ? 1'd1 : (is_FDIV ? 1'd1 : (is_FLW ? 1'd1 : (is_FMADD ? 1'd1 : (is_FMSUB ? 1'd1 : (is_FNMADD ? 1'd1 : (is_FNMSUB ? 1'd1 : (is_FMIN ? 1'd1 : (is_FMAX ? 1'd1 : (is_FMUL ? 1'd1 : (is_FMV_W_X ? 1'd1 : (is_FSGNJ ? 1'd1 : (is_FSGNJN ? 1'd1 : (is_FSGNJX ? 1'd1 : (is_FSUB ? 1'd1 : 1'b0)))))))))))))))));
	wire RS1_bank = (is_FADD ? 1'd1 : (is_FCVT_W_S ? 1'd1 : (is_FCVT_WU_S ? 1'd1 : (is_FDIV ? 1'd1 : (is_FEQ ? 1'd1 : (is_FLE ? 1'd1 : (is_FLT ? 1'd1 : (is_FMADD ? 1'd1 : (is_FMSUB ? 1'd1 : (is_FNMADD ? 1'd1 : (is_FNMSUB ? 1'd1 : (is_FMIN ? 1'd1 : (is_FMAX ? 1'd1 : (is_FMUL ? 1'd1 : (is_FMV_X_W ? 1'd1 : (is_FSGNJ ? 1'd1 : (is_FSGNJN ? 1'd1 : (is_FSGNJX ? 1'd1 : (is_FSUB ? 1'd1 : 1'b0)))))))))))))))))));
	wire RS2_bank = (is_FADD ? 1'd1 : (is_FDIV ? 1'd1 : (is_FEQ ? 1'd1 : (is_FLE ? 1'd1 : (is_FLT ? 1'd1 : (is_FMADD ? 1'd1 : (is_FMSUB ? 1'd1 : (is_FNMADD ? 1'd1 : (is_FNMSUB ? 1'd1 : (is_FMIN ? 1'd1 : (is_FMAX ? 1'd1 : (is_FMUL ? 1'd1 : (is_FSGNJ ? 1'd1 : (is_FSGNJN ? 1'd1 : (is_FSGNJX ? 1'd1 : (is_FSUB ? 1'd1 : (is_FSW ? 1'd1 : 1'b0)))))))))))))))));
	wire RS3_bank = (is_FMADD ? 1'd1 : (is_FMSUB ? 1'd1 : (is_FNMADD ? 1'd1 : (is_FNMSUB ? 1'd1 : 1'b0))));
	wire have_RS1 = ((((is_B | is_I) | is_R) | is_S) | is_CSR) | is_R4;
	wire have_RS2 = ((is_B | is_R) | is_S) | is_R4;
	wire have_RS3 = is_R4;
	wire have_RD = ((((is_I | is_J) | is_R) | is_U) | is_CSR) | is_R4;
	assign o_data = data;
	reg irq_pending_r = 1'b0;
	function automatic [5:0] sv2v_cast_6;
		input reg [5:0] inp;
		sv2v_cast_6 = inp;
	endfunction
	always @(posedge i_clock)
		if (i_reset) begin
			state <= 2'd0;
			pc <= RESET_VECTOR;
			data <= 0;
			irq_pending_r <= 1'b0;
		end
		else begin
			o_irq_dispatched <= 1'b0;
			case (state)
				2'd0: begin
					irq_pending_r <= i_irq_pending;
					if ({irq_pending_r, i_irq_pending} == 2'b01) begin
						o_irq_dispatched <= 1'b1;
						o_irq_epc <= pc;
						pc <= i_irq_pc;
					end
					else if (!i_busy && icache_ready) begin
						data[120] <= ~data[120];
						data[119-:32] <= icache_rdata;
						data[87-:32] <= pc;
						data[55-:6] <= sv2v_cast_6((have_RS1 ? {RS1_bank, icache_rdata[19:15]} : 0));
						data[49-:6] <= sv2v_cast_6((have_RS2 ? {RS2_bank, icache_rdata[24:20]} : 0));
						data[43-:6] <= sv2v_cast_6((have_RS3 ? {RS3_bank, icache_rdata[31:27]} : 0));
						data[37-:6] <= sv2v_cast_6((have_RD ? {RD_bank, icache_rdata[11:7]} : 0));
						if ((is_JUMP || is_JUMP_CONDITIONAL) || is_MRET)
							state <= 2'd1;
						else if (is_ECALL || is_WFI)
							state <= 2'd2;
						pc <= pc + 4;
					end
				end
				2'd1:
					if (i_jump) begin
						pc <= i_jump_pc;
						state <= 2'd0;
					end
				2'd2: begin
					irq_pending_r <= i_irq_pending;
					if ({irq_pending_r, i_irq_pending} == 2'b01) begin
						o_irq_dispatched <= 1'b1;
						o_irq_epc <= pc;
						pc <= i_irq_pc;
						state <= 2'd0;
					end
				end
				default: state <= 2'd0;
			endcase
		end
endmodule