module CPU (
	i_reset,
	i_clock,
	i_timer_interrupt,
	i_external_interrupt,
	o_ibus_request,
	i_ibus_ready,
	o_ibus_address,
	i_ibus_rdata,
	o_dbus_rw,
	o_dbus_request,
	i_dbus_ready,
	o_dbus_address,
	i_dbus_rdata,
	o_dbus_wdata,
	o_icache_hit,
	o_icache_miss,
	o_dcache_hit,
	o_dcache_miss,
	o_execute_busy,
	o_memory_busy,
	o_fault
);
	parameter RESET_VECTOR = 32'h00000000;
	parameter STACK_POINTER = 32'h10000400;
	parameter FREQUENCY = 0;
	parameter VENDORID = 32'h00000000;
	parameter ARCHID = 32'h00000000;
	parameter IMPID = 32'h00000000;
	parameter HARTID = 32'h00000000;
	parameter ICACHE_SIZE = 13;
	parameter ICACHE_REGISTERED = 0;
	parameter DCACHE_SIZE = 14;
	parameter DCACHE_REGISTERED = 1;
	input i_reset;
	input i_clock;
	input i_timer_interrupt;
	input i_external_interrupt;
	output wire o_ibus_request;
	input i_ibus_ready;
	output wire [31:0] o_ibus_address;
	input [31:0] i_ibus_rdata;
	output wire o_dbus_rw;
	output wire o_dbus_request;
	input i_dbus_ready;
	output wire [31:0] o_dbus_address;
	input [31:0] i_dbus_rdata;
	output wire [31:0] o_dbus_wdata;
	output wire [31:0] o_icache_hit;
	output wire [31:0] o_icache_miss;
	output wire [31:0] o_dcache_hit;
	output wire [31:0] o_dcache_miss;
	output wire o_execute_busy;
	output wire o_memory_busy;
	output wire o_fault;
	wire [11:0] csr_index;
	wire [31:0] csr_rdata;
	wire csr_wdata_wr;
	wire [31:0] csr_wdata;
	wire [31:0] csr_epc;
	wire [63:0] csr_retired;
	wire csr_irq_pending;
	wire [31:0] csr_irq_pc;
	wire csr_irq_dispatched;
	wire [31:0] csr_irq_epc;
	wire execute_ecall;
	wire execute_mret;
	CPU_CSR #(
		.FREQUENCY(FREQUENCY),
		.VENDORID(VENDORID),
		.ARCHID(ARCHID),
		.IMPID(IMPID),
		.HARTID(HARTID)
	) csr(
		.i_reset(i_reset),
		.i_clock(i_clock),
		.i_timer_interrupt(i_timer_interrupt),
		.i_external_interrupt(i_external_interrupt),
		.i_ecall(execute_ecall),
		.i_mret(execute_mret),
		.i_index(csr_index),
		.o_rdata(csr_rdata),
		.i_wdata_wr(csr_wdata_wr),
		.i_wdata(csr_wdata),
		.o_epc(csr_epc),
		.i_retired(csr_retired),
		.o_irq_pending(csr_irq_pending),
		.o_irq_pc(csr_irq_pc),
		.i_irq_dispatched(csr_irq_dispatched),
		.i_irq_epc(csr_irq_epc)
	);
	wire [31:0] rs1;
	wire [31:0] rs2;
	wire [31:0] rs3;
	wire [120:0] fetch_data;
	wire [38:0] memory_data;
	CPU_Registers #(.STACK_POINTER(STACK_POINTER)) registers(
		.i_reset(i_reset),
		.i_clock(i_clock),
		.i_fetch_data(fetch_data),
		.o_rs1(rs1),
		.o_rs2(rs2),
		.o_rs3(rs3),
		.i_memory_data(memory_data)
	);
	wire [120:0] fetch_data_0;
	wire execute_busy;
	wire execute_jump;
	wire [31:0] execute_jump_pc;
	wire memory_busy;
	CPU_Fetch #(
		.RESET_VECTOR(RESET_VECTOR),
		.ICACHE_SIZE(ICACHE_SIZE),
		.ICACHE_REGISTERED(ICACHE_REGISTERED)
	) fetch(
		.i_reset(i_reset),
		.i_clock(i_clock),
		.i_jump(execute_jump),
		.i_jump_pc(execute_jump_pc),
		.i_irq_pending(csr_irq_pending),
		.i_irq_pc(csr_irq_pc),
		.o_irq_dispatched(csr_irq_dispatched),
		.o_irq_epc(csr_irq_epc),
		.o_bus_request(o_ibus_request),
		.i_bus_ready(i_ibus_ready),
		.o_bus_address(o_ibus_address),
		.i_bus_rdata(i_ibus_rdata),
		.i_busy(execute_busy | memory_busy),
		.o_data(fetch_data_0),
		.o_icache_hit(o_icache_hit),
		.o_icache_miss(o_icache_miss)
	);
	CPU_SkidBuffer #(.DW(121)) fetch_skid(
		.i_reset(i_reset),
		.i_clock(i_clock),
		.i_busy(execute_busy | memory_busy),
		.i_data(fetch_data_0),
		.o_data(fetch_data)
	);
	wire decode_fault;
	wire [127:0] decode_data;
	CPU_Decode decode(
		.i_reset(i_reset),
		.i_clock(i_clock),
		.o_fault(decode_fault),
		.i_data(fetch_data),
		.o_data(decode_data)
	);
	wire [31:0] forward_rs1;
	wire [31:0] forward_rs2;
	wire [31:0] forward_rs3;
	wire [82:0] execute_data;
	wire [37:0] writeback_data;
	CPU_Forward forward(
		.i_decode_data(decode_data),
		.i_execute_data(execute_data),
		.i_memory_data(memory_data),
		.i_writeback_data(writeback_data),
		.i_rs1(rs1),
		.i_rs2(rs2),
		.i_rs3(rs3),
		.o_rs1(forward_rs1),
		.o_rs2(forward_rs2),
		.o_rs3(forward_rs3)
	);
	wire execute_fault;
	CPU_Execute execute(
		.i_reset(i_reset),
		.i_clock(i_clock),
		.o_fault(execute_fault),
		.o_csr_index(csr_index),
		.i_csr_rdata(csr_rdata),
		.o_csr_wdata_wr(csr_wdata_wr),
		.o_csr_wdata(csr_wdata),
		.i_epc(csr_epc),
		.o_jump(execute_jump),
		.o_jump_pc(execute_jump_pc),
		.o_ecall(execute_ecall),
		.o_mret(execute_mret),
		.o_busy(execute_busy),
		.i_data(decode_data),
		.i_rs1(forward_rs1),
		.i_rs2(forward_rs2),
		.i_rs3(forward_rs3),
		.i_memory_busy(memory_busy),
		.o_data(execute_data)
	);
	CPU_Memory #(
		.DCACHE_SIZE(DCACHE_SIZE),
		.DCACHE_REGISTERED(DCACHE_REGISTERED)
	) memory(
		.i_reset(i_reset),
		.i_clock(i_clock),
		.o_bus_rw(o_dbus_rw),
		.o_bus_request(o_dbus_request),
		.i_bus_ready(i_dbus_ready),
		.o_bus_address(o_dbus_address),
		.i_bus_rdata(i_dbus_rdata),
		.o_bus_wdata(o_dbus_wdata),
		.o_busy(memory_busy),
		.i_data(execute_data),
		.o_data(memory_data),
		.o_dcache_hit(o_dcache_hit),
		.o_dcache_miss(o_dcache_miss)
	);
	CPU_Writeback writeback(
		.i_reset(i_reset),
		.i_clock(i_clock),
		.i_data(memory_data),
		.o_data(writeback_data),
		.o_retired(csr_retired)
	);
	assign o_execute_busy = execute_busy;
	assign o_memory_busy = memory_busy;
	assign o_fault = decode_fault || execute_fault;
endmodule