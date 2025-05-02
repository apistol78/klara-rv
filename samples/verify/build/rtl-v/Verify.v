module Verify (
	CLOCK_p,
	LED_p
);
	input CLOCK_p;
	output wire LED_p;
	wire clock = CLOCK_p;
	wire reset = 1'b0;
	wire [31:0] cpu_ibus_address;
	assign LED_p = cpu_ibus_address[20];
	wire [31:0] cpu_ibus_rdata;
	assign cpu_ibus_rdata = 32'h00000013;
	wire cpu_ibus_ready;
	reg ready = 1'b0;
	assign cpu_ibus_ready = ready;
	wire cpu_ibus_request;
	always @(posedge clock) ready <= cpu_ibus_request;
	wire cpu_dbus_rw;
	wire cpu_dbus_request;
	wire cpu_dbus_ready;
	wire [31:0] cpu_dbus_address;
	wire [31:0] cpu_dbus_rdata;
	wire [31:0] cpu_dbus_wdata;
	wire cpu_fault;
	CPU #(
		.FREQUENCY(25000000),
		.DCACHE_SIZE(0),
		.DCACHE_REGISTERED(1),
		.ICACHE_SIZE(1),
		.ICACHE_REGISTERED(1)
	) cpu(
		.i_reset(reset),
		.i_clock(clock),
		.i_timer_interrupt(1'b0),
		.i_external_interrupt(1'b0),
		.o_ibus_request(cpu_ibus_request),
		.i_ibus_ready(cpu_ibus_ready),
		.o_ibus_address(cpu_ibus_address),
		.i_ibus_rdata(cpu_ibus_rdata),
		.o_dbus_rw(cpu_dbus_rw),
		.o_dbus_request(cpu_dbus_request),
		.i_dbus_ready(cpu_dbus_ready),
		.o_dbus_address(cpu_dbus_address),
		.i_dbus_rdata(cpu_dbus_rdata),
		.o_dbus_wdata(cpu_dbus_wdata),
		.o_icache_hit(),
		.o_icache_miss(),
		.o_dcache_hit(),
		.o_dcache_miss(),
		.o_execute_busy(),
		.o_memory_busy(),
		.o_fault(cpu_fault)
	);
endmodule