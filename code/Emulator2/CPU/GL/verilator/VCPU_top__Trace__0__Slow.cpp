// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_fst_c.h"
#include "VCPU_top__Syms.h"


VL_ATTR_COLD void VCPU_top___024root__trace_init_sub__TOP__0(VCPU_top___024root* vlSelf, VerilatedFst* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCPU_top___024root__trace_init_sub__TOP__0\n"); );
    VCPU_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBit(c+820,0,"reset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+821,0,"clock",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+822,0,"timer_interrupt",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+823,0,"external_interrupt",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+824,0,"bus_rw",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+825,0,"bus_request",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+826,0,"bus_ready",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+827,0,"bus_address",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+828,0,"bus_rdata",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+829,0,"bus_wdata",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+830,0,"cpu_fault",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("CPU_top", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+820,0,"reset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+821,0,"clock",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+822,0,"timer_interrupt",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+823,0,"external_interrupt",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+824,0,"bus_rw",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+825,0,"bus_request",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+826,0,"bus_ready",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+827,0,"bus_address",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+828,0,"bus_rdata",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+829,0,"bus_wdata",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+830,0,"cpu_fault",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+225,0,"cpu_ibus_request",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+831,0,"cpu_ibus_ready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+226,0,"cpu_ibus_address",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+828,0,"cpu_ibus_rdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+227,0,"cpu_dbus_rw",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+228,0,"cpu_dbus_request",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+832,0,"cpu_dbus_ready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+229,0,"cpu_dbus_address",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+828,0,"cpu_dbus_rdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+230,0,"cpu_dbus_wdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("bus", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+843,0,"REGISTERED",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+820,0,"i_reset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+821,0,"i_clock",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+824,0,"o_bus_rw",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBit(c+825,0,"o_bus_request",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBit(c+826,0,"i_bus_ready",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+827,0,"o_bus_address",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::BIT, false,-1, 31,0);
    tracep->declBus(c+828,0,"i_bus_rdata",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+829,0,"o_bus_wdata",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::BIT, false,-1, 31,0);
    tracep->declBit(c+225,0,"i_pa_request",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+831,0,"o_pa_ready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+226,0,"i_pa_address",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+828,0,"o_pa_rdata",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+227,0,"i_pb_rw",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+228,0,"i_pb_request",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+832,0,"o_pb_ready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+229,0,"i_pb_address",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+828,0,"o_pb_rdata",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+230,0,"i_pb_wdata",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+231,0,"state",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::BIT, false,-1, 1,0);
    tracep->declBus(c+833,0,"next_state",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::BIT, false,-1, 1,0);
    tracep->popPrefix();
    tracep->pushPrefix("cpu", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+844,0,"RESET_VECTOR",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+845,0,"STACK_POINTER",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+846,0,"FREQUENCY",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+844,0,"VENDORID",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+844,0,"ARCHID",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+844,0,"IMPID",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+844,0,"HARTID",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+847,0,"ICACHE_SIZE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+848,0,"ICACHE_REGISTERED",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+847,0,"DCACHE_SIZE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+848,0,"DCACHE_REGISTERED",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+820,0,"i_reset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+821,0,"i_clock",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+822,0,"i_timer_interrupt",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+823,0,"i_external_interrupt",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+225,0,"o_ibus_request",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+831,0,"i_ibus_ready",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+226,0,"o_ibus_address",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+828,0,"i_ibus_rdata",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+227,0,"o_dbus_rw",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+228,0,"o_dbus_request",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+832,0,"i_dbus_ready",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+229,0,"o_dbus_address",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+828,0,"i_dbus_rdata",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+230,0,"o_dbus_wdata",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+843,0,"o_icache_hit",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+843,0,"o_icache_miss",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+849,0,"o_dcache_hit",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+850,0,"o_dcache_miss",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+232,0,"o_execute_busy",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+233,0,"o_memory_busy",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+830,0,"o_fault",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+234,0,"csr_index",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 11,0);
    tracep->declBus(c+235,0,"csr_rdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+236,0,"csr_wdata_wr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+237,0,"csr_wdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+238,0,"csr_epc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declQuad(c+239,0,"csr_retired",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 63,0);
    tracep->declBit(c+241,0,"csr_irq_pending",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+242,0,"csr_irq_pc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+243,0,"csr_irq_dispatched",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+244,0,"csr_irq_epc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+634,0,"rs1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+635,0,"rs2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+636,0,"rs3",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("fetch_data_0", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+245,0,"strobe",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBus(c+246,0,"instruction",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::BIT, false,-1, 31,0);
    tracep->declBus(c+247,0,"pc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::BIT, false,-1, 31,0);
    tracep->declBus(c+248,0,"inst_rs1",1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::BIT, false,-1, 4,0);
    tracep->declBus(c+249,0,"inst_rs2",1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::BIT, false,-1, 4,0);
    tracep->declBus(c+250,0,"inst_rs3",1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::BIT, false,-1, 4,0);
    tracep->declBus(c+251,0,"inst_rd",1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::BIT, false,-1, 4,0);
    tracep->declBus(c+252,0,"imm",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::BIT, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("fetch_data", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+671,0,"strobe",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBus(c+672,0,"instruction",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::BIT, false,-1, 31,0);
    tracep->declBus(c+673,0,"pc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::BIT, false,-1, 31,0);
    tracep->declBus(c+674,0,"inst_rs1",1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::BIT, false,-1, 4,0);
    tracep->declBus(c+675,0,"inst_rs2",1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::BIT, false,-1, 4,0);
    tracep->declBus(c+676,0,"inst_rs3",1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::BIT, false,-1, 4,0);
    tracep->declBus(c+677,0,"inst_rd",1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::BIT, false,-1, 4,0);
    tracep->declBus(c+678,0,"imm",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::BIT, false,-1, 31,0);
    tracep->popPrefix();
    tracep->declBit(c+253,0,"decode_fault",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("decode_data", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+254,0,"strobe",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBus(c+255,0,"pc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::BIT, false,-1, 31,0);
    tracep->declBus(c+256,0,"have_rs",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::BIT, false,-1, 2,0);
    tracep->declBus(c+257,0,"inst_rs1",1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::BIT, false,-1, 4,0);
    tracep->declBus(c+258,0,"inst_rs2",1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::BIT, false,-1, 4,0);
    tracep->declBus(c+259,0,"inst_rs3",1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::BIT, false,-1, 4,0);
    tracep->declBus(c+260,0,"inst_rd",1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::BIT, false,-1, 4,0);
    tracep->declBus(c+261,0,"imm",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::BIT, false,-1, 31,0);
    tracep->declBit(c+262,0,"arithmetic",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBit(c+263,0,"shift",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBit(c+264,0,"compare",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBit(c+265,0,"complx",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBit(c+266,0,"jump",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBit(c+267,0,"jump_conditional",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBus(c+268,0,"alu_operation",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::BIT, false,-1, 3,0);
    tracep->declBus(c+269,0,"alu_operand1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::BIT, false,-1, 4,0);
    tracep->declBus(c+270,0,"alu_operand2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::BIT, false,-1, 4,0);
    tracep->declBit(c+271,0,"memory_read",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBit(c+272,0,"memory_write",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBus(c+273,0,"memory_width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::BIT, false,-1, 1,0);
    tracep->declBit(c+274,0,"memory_signed",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBus(c+275,0,"op",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::BIT, false,-1, 4,0);
    tracep->popPrefix();
    tracep->declBus(c+798,0,"forward_rs1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+799,0,"forward_rs2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+800,0,"forward_rs3",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+276,0,"execute_fault",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+277,0,"execute_jump",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+278,0,"execute_jump_pc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+279,0,"execute_ecall",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+280,0,"execute_mret",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+232,0,"execute_busy",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("execute_data", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+281,0,"strobe",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBus(c+282,0,"pc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::BIT, false,-1, 31,0);
    tracep->declBus(c+283,0,"inst_rd",1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::BIT, false,-1, 4,0);
    tracep->declBus(c+284,0,"rd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::BIT, false,-1, 31,0);
    tracep->declBit(c+285,0,"mem_read",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBit(c+286,0,"mem_write",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBit(c+287,0,"mem_flush",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBus(c+288,0,"mem_width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::BIT, false,-1, 1,0);
    tracep->declBit(c+289,0,"mem_signed",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBus(c+290,0,"mem_address",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::BIT, false,-1, 31,0);
    tracep->declBus(c+291,0,"mem_inst_rd",1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::BIT, false,-1, 4,0);
    tracep->popPrefix();
    tracep->declBit(c+233,0,"memory_busy",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("memory_data", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+679,0,"strobe",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBus(c+680,0,"pc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::BIT, false,-1, 31,0);
    tracep->declBus(c+681,0,"inst_rd",1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::BIT, false,-1, 4,0);
    tracep->declBus(c+682,0,"rd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::BIT, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("writeback_data", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+292,0,"inst_rd",1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::BIT, false,-1, 4,0);
    tracep->declBus(c+293,0,"rd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::BIT, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("csr", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+846,0,"FREQUENCY",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+844,0,"VENDORID",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+844,0,"ARCHID",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+844,0,"IMPID",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+844,0,"HARTID",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+820,0,"i_reset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+821,0,"i_clock",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+822,0,"i_timer_interrupt",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+823,0,"i_external_interrupt",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+279,0,"i_ecall",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+280,0,"i_mret",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+234,0,"i_index",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 11,0);
    tracep->declBus(c+235,0,"o_rdata",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::BIT, false,-1, 31,0);
    tracep->declBit(c+236,0,"i_wdata_wr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+237,0,"i_wdata",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+238,0,"o_epc",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+241,0,"o_irq_pending",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBus(c+242,0,"o_irq_pc",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::BIT, false,-1, 31,0);
    tracep->declBit(c+243,0,"i_irq_dispatched",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+244,0,"i_irq_epc",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declQuad(c+239,0,"i_retired",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 63,0);
    tracep->declBus(c+851,0,"PRESCALE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+852,0,"PRESCALE_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+294,0,"mstatus_mpie",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBit(c+295,0,"mstatus_mie",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBit(c+296,0,"mie_meie",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBit(c+297,0,"mie_mtie",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBit(c+298,0,"mie_msie",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBus(c+299,0,"mtvec",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::BIT, false,-1, 31,0);
    tracep->declBus(c+238,0,"mepc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::BIT, false,-1, 31,0);
    tracep->declBus(c+300,0,"mcause",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::BIT, false,-1, 31,0);
    tracep->declBit(c+301,0,"mip_meip",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBit(c+302,0,"mip_mtip",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBit(c+303,0,"mip_msip",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBus(c+304,0,"mscratch",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::BIT, false,-1, 31,0);
    tracep->declBus(c+305,0,"mstatus",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+306,0,"mie",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+307,0,"mip",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declQuad(c+308,0,"cycle",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::BIT, false,-1, 63,0);
    tracep->declQuad(c+310,0,"wtime",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::BIT, false,-1, 63,0);
    tracep->declBus(c+312,0,"prescale",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::BIT, false,-1, 13,0);
    tracep->declBus(c+313,0,"issued",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::BIT, false,-1, 2,0);
    tracep->popPrefix();
    tracep->pushPrefix("decode", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+820,0,"i_reset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+821,0,"i_clock",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+253,0,"o_fault",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::BIT, false,-1);
    tracep->pushPrefix("i_data", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+671,0,"strobe",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBus(c+672,0,"instruction",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::BIT, false,-1, 31,0);
    tracep->declBus(c+673,0,"pc",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::BIT, false,-1, 31,0);
    tracep->declBus(c+674,0,"inst_rs1",1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::BIT, false,-1, 4,0);
    tracep->declBus(c+675,0,"inst_rs2",1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::BIT, false,-1, 4,0);
    tracep->declBus(c+676,0,"inst_rs3",1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::BIT, false,-1, 4,0);
    tracep->declBus(c+677,0,"inst_rd",1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::BIT, false,-1, 4,0);
    tracep->declBus(c+678,0,"imm",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::BIT, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("o_data", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+254,0,"strobe",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBus(c+255,0,"pc",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::BIT, false,-1, 31,0);
    tracep->declBus(c+256,0,"have_rs",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::BIT, false,-1, 2,0);
    tracep->declBus(c+257,0,"inst_rs1",1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::BIT, false,-1, 4,0);
    tracep->declBus(c+258,0,"inst_rs2",1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::BIT, false,-1, 4,0);
    tracep->declBus(c+259,0,"inst_rs3",1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::BIT, false,-1, 4,0);
    tracep->declBus(c+260,0,"inst_rd",1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::BIT, false,-1, 4,0);
    tracep->declBus(c+261,0,"imm",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::BIT, false,-1, 31,0);
    tracep->declBit(c+262,0,"arithmetic",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBit(c+263,0,"shift",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBit(c+264,0,"compare",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBit(c+265,0,"complx",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBit(c+266,0,"jump",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBit(c+267,0,"jump_conditional",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBus(c+268,0,"alu_operation",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::BIT, false,-1, 3,0);
    tracep->declBus(c+269,0,"alu_operand1",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::BIT, false,-1, 4,0);
    tracep->declBus(c+270,0,"alu_operand2",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::BIT, false,-1, 4,0);
    tracep->declBit(c+271,0,"memory_read",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBit(c+272,0,"memory_write",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBus(c+273,0,"memory_width",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::BIT, false,-1, 1,0);
    tracep->declBit(c+274,0,"memory_signed",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBus(c+275,0,"op",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::BIT, false,-1, 4,0);
    tracep->popPrefix();
    tracep->declBit(c+683,0,"have_RS1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+684,0,"have_RS2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+685,0,"have_RS3",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+686,0,"have_RD",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+687,0,"inst_B_imm",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+688,0,"inst_I_imm",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+689,0,"inst_J_imm",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+690,0,"inst_S_imm",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+691,0,"inst_U_imm",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+692,0,"inst_R_imm",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+693,0,"inst_CSR_imm",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("data", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+254,0,"strobe",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBus(c+255,0,"pc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::BIT, false,-1, 31,0);
    tracep->declBus(c+256,0,"have_rs",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::BIT, false,-1, 2,0);
    tracep->declBus(c+257,0,"inst_rs1",1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::BIT, false,-1, 4,0);
    tracep->declBus(c+258,0,"inst_rs2",1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::BIT, false,-1, 4,0);
    tracep->declBus(c+259,0,"inst_rs3",1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::BIT, false,-1, 4,0);
    tracep->declBus(c+260,0,"inst_rd",1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::BIT, false,-1, 4,0);
    tracep->declBus(c+261,0,"imm",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::BIT, false,-1, 31,0);
    tracep->declBit(c+262,0,"arithmetic",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBit(c+263,0,"shift",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBit(c+264,0,"compare",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBit(c+265,0,"complx",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBit(c+266,0,"jump",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBit(c+267,0,"jump_conditional",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBus(c+268,0,"alu_operation",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::BIT, false,-1, 3,0);
    tracep->declBus(c+269,0,"alu_operand1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::BIT, false,-1, 4,0);
    tracep->declBus(c+270,0,"alu_operand2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::BIT, false,-1, 4,0);
    tracep->declBit(c+271,0,"memory_read",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBit(c+272,0,"memory_write",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBus(c+273,0,"memory_width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::BIT, false,-1, 1,0);
    tracep->declBit(c+274,0,"memory_signed",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBus(c+275,0,"op",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::BIT, false,-1, 4,0);
    tracep->popPrefix();
    tracep->declBus(c+853,0,"OP_CSRRC",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+854,0,"OP_CSRRS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+855,0,"OP_CSRRW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+856,0,"OP_DIV",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+857,0,"OP_DIVU",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+858,0,"OP_EBREAK",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+859,0,"OP_ECALL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+860,0,"OP_FENCE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+861,0,"OP_MUL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+862,0,"OP_MULH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+863,0,"OP_MULHU",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+864,0,"OP_MRET",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+865,0,"OP_REM",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+866,0,"OP_REMU",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+694,0,"is_ADD",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+695,0,"is_ADDI",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+696,0,"is_AND",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+697,0,"is_ANDI",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+698,0,"is_AUIPC",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+699,0,"is_BEQ",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+700,0,"is_BGE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+701,0,"is_BGEU",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+702,0,"is_BLT",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+703,0,"is_BLTU",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+704,0,"is_BNE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+705,0,"is_CSRRC",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+706,0,"is_CSRRS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+707,0,"is_CSRRW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+708,0,"is_DIV",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+709,0,"is_DIVU",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+710,0,"is_EBREAK",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+711,0,"is_ECALL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+712,0,"is_FADD",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+713,0,"is_FCVT_W_S",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+714,0,"is_FCVT_WU_S",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+715,0,"is_FCVT_S_W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+716,0,"is_FCVT_S_WU",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+717,0,"is_FDIV",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+718,0,"is_FENCE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+719,0,"is_FEQ",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+720,0,"is_FLE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+721,0,"is_FLT",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+722,0,"is_FLW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+723,0,"is_FMADD",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+724,0,"is_FMSUB",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+725,0,"is_FNMADD",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+726,0,"is_FNMSUB",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+727,0,"is_FMIN",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+728,0,"is_FMAX",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+729,0,"is_FMUL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+730,0,"is_FMV_X_W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+731,0,"is_FMV_W_X",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+732,0,"is_FSGNJ",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+733,0,"is_FSGNJN",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+734,0,"is_FSGNJX",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+735,0,"is_FSUB",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+736,0,"is_FSW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+737,0,"is_JAL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+738,0,"is_JALR",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+739,0,"is_LB",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+740,0,"is_LBU",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+741,0,"is_LH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+742,0,"is_LHU",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+743,0,"is_LUI",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+744,0,"is_LW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+745,0,"is_MUL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+746,0,"is_MULH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+747,0,"is_MULHU",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+748,0,"is_MRET",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+749,0,"is_OR",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+750,0,"is_ORI",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+751,0,"is_REM",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+752,0,"is_REMU",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+753,0,"is_SB",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+754,0,"is_SH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+755,0,"is_SLL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+756,0,"is_SLLI",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+757,0,"is_SLT",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+758,0,"is_SLTI",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+759,0,"is_SLTIU",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+760,0,"is_SLTU",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+761,0,"is_SRA",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+762,0,"is_SRAI",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+763,0,"is_SRL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+764,0,"is_SRLI",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+765,0,"is_SUB",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+766,0,"is_SW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+767,0,"is_WFI",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+768,0,"is_XOR",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+769,0,"is_XORI",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+770,0,"is_B",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+771,0,"is_I",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+737,0,"is_J",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+772,0,"is_R",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+685,0,"is_R4",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+773,0,"is_S",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+774,0,"is_U",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+775,0,"is_CSR",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+776,0,"is_ARITHMETIC",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+777,0,"is_SHIFT",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+778,0,"is_COMPARE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+779,0,"is_COMPLEX",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+780,0,"is_JUMP",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+770,0,"is_JUMP_CONDITIONAL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+781,0,"is_MEMORY",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+782,0,"is_FPU",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+783,0,"is_FPU_MEMORY",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+784,0,"RD_bank",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+785,0,"RS1_bank",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+786,0,"RS2_bank",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+685,0,"RS3_bank",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+787,0,"alu_operation",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+788,0,"alu_operand1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+789,0,"alu_operand2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBit(c+790,0,"memory_read",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+773,0,"memory_write",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+791,0,"memory_width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+792,0,"memory_signed",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("execute", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+853,0,"OP_CSRRC",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+854,0,"OP_CSRRS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+855,0,"OP_CSRRW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+856,0,"OP_DIV",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+857,0,"OP_DIVU",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+858,0,"OP_EBREAK",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+859,0,"OP_ECALL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+860,0,"OP_FENCE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+861,0,"OP_MUL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+862,0,"OP_MULH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+863,0,"OP_MULHU",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+864,0,"OP_MRET",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+865,0,"OP_REM",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+866,0,"OP_REMU",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+820,0,"i_reset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+821,0,"i_clock",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+276,0,"o_fault",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBus(c+234,0,"o_csr_index",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 11,0);
    tracep->declBus(c+235,0,"i_csr_rdata",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+236,0,"o_csr_wdata_wr",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBus(c+237,0,"o_csr_wdata",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::BIT, false,-1, 31,0);
    tracep->declBus(c+238,0,"i_epc",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+277,0,"o_jump",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBus(c+278,0,"o_jump_pc",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::BIT, false,-1, 31,0);
    tracep->declBit(c+279,0,"o_ecall",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBit(c+280,0,"o_mret",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBit(c+232,0,"o_busy",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::BIT, false,-1);
    tracep->pushPrefix("i_data", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+254,0,"strobe",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBus(c+255,0,"pc",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::BIT, false,-1, 31,0);
    tracep->declBus(c+256,0,"have_rs",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::BIT, false,-1, 2,0);
    tracep->declBus(c+257,0,"inst_rs1",1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::BIT, false,-1, 4,0);
    tracep->declBus(c+258,0,"inst_rs2",1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::BIT, false,-1, 4,0);
    tracep->declBus(c+259,0,"inst_rs3",1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::BIT, false,-1, 4,0);
    tracep->declBus(c+260,0,"inst_rd",1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::BIT, false,-1, 4,0);
    tracep->declBus(c+261,0,"imm",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::BIT, false,-1, 31,0);
    tracep->declBit(c+262,0,"arithmetic",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBit(c+263,0,"shift",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBit(c+264,0,"compare",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBit(c+265,0,"complx",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBit(c+266,0,"jump",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBit(c+267,0,"jump_conditional",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBus(c+268,0,"alu_operation",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::BIT, false,-1, 3,0);
    tracep->declBus(c+269,0,"alu_operand1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::BIT, false,-1, 4,0);
    tracep->declBus(c+270,0,"alu_operand2",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::BIT, false,-1, 4,0);
    tracep->declBit(c+271,0,"memory_read",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBit(c+272,0,"memory_write",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBus(c+273,0,"memory_width",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::BIT, false,-1, 1,0);
    tracep->declBit(c+274,0,"memory_signed",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBus(c+275,0,"op",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::BIT, false,-1, 4,0);
    tracep->popPrefix();
    tracep->declBus(c+798,0,"i_rs1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+799,0,"i_rs2",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+800,0,"i_rs3",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+233,0,"i_memory_busy",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("o_data", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+281,0,"strobe",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBus(c+282,0,"pc",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::BIT, false,-1, 31,0);
    tracep->declBus(c+283,0,"inst_rd",1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::BIT, false,-1, 4,0);
    tracep->declBus(c+284,0,"rd",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::BIT, false,-1, 31,0);
    tracep->declBit(c+285,0,"mem_read",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBit(c+286,0,"mem_write",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBit(c+287,0,"mem_flush",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBus(c+288,0,"mem_width",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::BIT, false,-1, 1,0);
    tracep->declBit(c+289,0,"mem_signed",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBus(c+290,0,"mem_address",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::BIT, false,-1, 31,0);
    tracep->declBus(c+291,0,"mem_inst_rd",1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::BIT, false,-1, 4,0);
    tracep->popPrefix();
    tracep->declBus(c+801,0,"alu_operand1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::BIT, false,-1, 31,0);
    tracep->declBus(c+802,0,"alu_operand2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::BIT, false,-1, 31,0);
    tracep->declBus(c+834,0,"alu_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+835,0,"alu_shift_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+803,0,"alu_signed_sum_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+804,0,"alu_compare_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+314,0,"mul_request",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+315,0,"mul_signed",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+316,0,"mul_ready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declQuad(c+317,0,"mul_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 63,0);
    tracep->declBit(c+319,0,"div_request",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+320,0,"div_signed",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+836,0,"div_ready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+837,0,"div_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+838,0,"div_remainder",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+321,0,"last_strobe",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::BIT, false,-1);
    tracep->pushPrefix("data", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+281,0,"strobe",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBus(c+282,0,"pc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::BIT, false,-1, 31,0);
    tracep->declBus(c+283,0,"inst_rd",1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::BIT, false,-1, 4,0);
    tracep->declBus(c+284,0,"rd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::BIT, false,-1, 31,0);
    tracep->declBit(c+285,0,"mem_read",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBit(c+286,0,"mem_write",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBit(c+287,0,"mem_flush",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBus(c+288,0,"mem_width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::BIT, false,-1, 1,0);
    tracep->declBit(c+289,0,"mem_signed",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBus(c+290,0,"mem_address",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::BIT, false,-1, 31,0);
    tracep->declBus(c+291,0,"mem_inst_rd",1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::BIT, false,-1, 4,0);
    tracep->popPrefix();
    tracep->pushPrefix("alu", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+322,0,"i_op",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+801,0,"i_op1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+802,0,"i_op2",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+834,0,"o_result",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+835,0,"o_shift_result",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+803,0,"o_signed_sum_result",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+804,0,"o_compare_result",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+803,0,"signed_sum",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+803,0,"unsigned_sum",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+805,0,"signed_diff",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+806,0,"and_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+807,0,"or_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+808,0,"xor_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+809,0,"shl_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+810,0,"shr_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+811,0,"ashr_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+812,0,"signed_lt_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+813,0,"unsigned_lt_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+814,0,"equal_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+815,0,"not_equal_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+816,0,"signed_get_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+817,0,"unsigned_get_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("divide", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+821,0,"i_clock",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+319,0,"i_latch",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+320,0,"i_signed",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+798,0,"i_numerator",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+799,0,"i_denominator",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+836,0,"o_ready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBus(c+837,0,"o_result",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::BIT, false,-1, 31,0);
    tracep->declBus(c+838,0,"o_remainder",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::BIT, false,-1, 31,0);
    tracep->declBit(c+818,0,"snumerator",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+819,0,"sdenominator",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+323,0,"unumerator",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::BIT, false,-1, 31,0);
    tracep->declBus(c+324,0,"udenominator",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::BIT, false,-1, 31,0);
    tracep->declBus(c+839,0,"result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::BIT, false,-1, 31,0);
    tracep->declBus(c+151,0,"remainder",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::BIT, false,-1, 31,0);
    tracep->declBit(c+840,0,"ack",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBus(c+325,0,"s",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::BIT, false,-1, 1,0);
    tracep->declBit(c+326,0,"llth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBit(c+327,0,"valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("df", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+867,0,"XLEN",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+868,0,"STAGE_LIST",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+821,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+793,0,"rst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+323,0,"a",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+324,0,"b",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+327,0,"vld",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+839,0,"quo",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+151,0,"rem",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+840,0,"ack",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("gen_div[0]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+152,0,"m",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+97,0,"n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+215,0,"q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1,0,"t",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+153,0,"u",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declQuad(c+2,0,"d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 32,0);
    tracep->popPrefix();
    tracep->pushPrefix("gen_div[10]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+154,0,"m",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 10,0);
    tracep->declBus(c+98,0,"n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 10,0);
    tracep->declBit(c+216,0,"q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+4,0,"t",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 10,0);
    tracep->declBus(c+155,0,"u",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declQuad(c+5,0,"d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 42,0);
    tracep->popPrefix();
    tracep->pushPrefix("gen_div[11]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+156,0,"m",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 11,0);
    tracep->declBus(c+99,0,"n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 11,0);
    tracep->declBit(c+129,0,"q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+31,0,"t",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 11,0);
    tracep->declBus(c+157,0,"u",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declQuad(c+32,0,"d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 43,0);
    tracep->popPrefix();
    tracep->pushPrefix("gen_div[12]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+158,0,"m",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 12,0);
    tracep->declBus(c+100,0,"n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 12,0);
    tracep->declBit(c+130,0,"q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+34,0,"t",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 12,0);
    tracep->declBus(c+159,0,"u",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declQuad(c+35,0,"d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 44,0);
    tracep->popPrefix();
    tracep->pushPrefix("gen_div[13]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+160,0,"m",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 13,0);
    tracep->declBus(c+101,0,"n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 13,0);
    tracep->declBit(c+131,0,"q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+37,0,"t",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 13,0);
    tracep->declBus(c+161,0,"u",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declQuad(c+38,0,"d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 45,0);
    tracep->popPrefix();
    tracep->pushPrefix("gen_div[14]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+162,0,"m",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 14,0);
    tracep->declBus(c+102,0,"n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 14,0);
    tracep->declBit(c+217,0,"q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+7,0,"t",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 14,0);
    tracep->declBus(c+163,0,"u",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declQuad(c+8,0,"d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 46,0);
    tracep->popPrefix();
    tracep->pushPrefix("gen_div[15]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+164,0,"m",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+103,0,"n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBit(c+132,0,"q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+40,0,"t",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+165,0,"u",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declQuad(c+41,0,"d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 47,0);
    tracep->popPrefix();
    tracep->pushPrefix("gen_div[16]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+166,0,"m",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 16,0);
    tracep->declBus(c+104,0,"n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 16,0);
    tracep->declBit(c+133,0,"q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+43,0,"t",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 16,0);
    tracep->declBus(c+167,0,"u",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declQuad(c+44,0,"d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 48,0);
    tracep->popPrefix();
    tracep->pushPrefix("gen_div[17]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+168,0,"m",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 17,0);
    tracep->declBus(c+105,0,"n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 17,0);
    tracep->declBit(c+134,0,"q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+46,0,"t",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 17,0);
    tracep->declBus(c+169,0,"u",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declQuad(c+47,0,"d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 49,0);
    tracep->popPrefix();
    tracep->pushPrefix("gen_div[18]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+170,0,"m",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 18,0);
    tracep->declBus(c+106,0,"n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 18,0);
    tracep->declBit(c+218,0,"q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+10,0,"t",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 18,0);
    tracep->declBus(c+171,0,"u",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declQuad(c+11,0,"d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 50,0);
    tracep->popPrefix();
    tracep->pushPrefix("gen_div[19]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+172,0,"m",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 19,0);
    tracep->declBus(c+107,0,"n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 19,0);
    tracep->declBit(c+135,0,"q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+49,0,"t",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 19,0);
    tracep->declBus(c+173,0,"u",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declQuad(c+50,0,"d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 51,0);
    tracep->popPrefix();
    tracep->pushPrefix("gen_div[1]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+174,0,"m",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+108,0,"n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+136,0,"q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+52,0,"t",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+175,0,"u",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declQuad(c+53,0,"d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 33,0);
    tracep->popPrefix();
    tracep->pushPrefix("gen_div[20]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+176,0,"m",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 20,0);
    tracep->declBus(c+109,0,"n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 20,0);
    tracep->declBit(c+137,0,"q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+55,0,"t",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 20,0);
    tracep->declBus(c+177,0,"u",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declQuad(c+56,0,"d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 52,0);
    tracep->popPrefix();
    tracep->pushPrefix("gen_div[21]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+178,0,"m",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 21,0);
    tracep->declBus(c+110,0,"n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 21,0);
    tracep->declBit(c+138,0,"q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+58,0,"t",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 21,0);
    tracep->declBus(c+179,0,"u",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declQuad(c+59,0,"d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 53,0);
    tracep->popPrefix();
    tracep->pushPrefix("gen_div[22]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+180,0,"m",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 22,0);
    tracep->declBus(c+111,0,"n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 22,0);
    tracep->declBit(c+219,0,"q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+13,0,"t",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 22,0);
    tracep->declBus(c+181,0,"u",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declQuad(c+14,0,"d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 54,0);
    tracep->popPrefix();
    tracep->pushPrefix("gen_div[23]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+182,0,"m",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBus(c+112,0,"n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBit(c+139,0,"q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+61,0,"t",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBus(c+183,0,"u",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declQuad(c+62,0,"d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 55,0);
    tracep->popPrefix();
    tracep->pushPrefix("gen_div[24]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+184,0,"m",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 24,0);
    tracep->declBus(c+113,0,"n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 24,0);
    tracep->declBit(c+140,0,"q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+64,0,"t",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 24,0);
    tracep->declBus(c+185,0,"u",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declQuad(c+65,0,"d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 56,0);
    tracep->popPrefix();
    tracep->pushPrefix("gen_div[25]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+186,0,"m",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+114,0,"n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBit(c+141,0,"q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+67,0,"t",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+187,0,"u",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declQuad(c+68,0,"d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 57,0);
    tracep->popPrefix();
    tracep->pushPrefix("gen_div[26]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+188,0,"m",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 26,0);
    tracep->declBus(c+115,0,"n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 26,0);
    tracep->declBit(c+220,0,"q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+16,0,"t",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 26,0);
    tracep->declBus(c+189,0,"u",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declQuad(c+17,0,"d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 58,0);
    tracep->popPrefix();
    tracep->pushPrefix("gen_div[27]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+190,0,"m",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 27,0);
    tracep->declBus(c+116,0,"n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 27,0);
    tracep->declBit(c+142,0,"q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+70,0,"t",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 27,0);
    tracep->declBus(c+191,0,"u",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declQuad(c+71,0,"d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 59,0);
    tracep->popPrefix();
    tracep->pushPrefix("gen_div[28]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+192,0,"m",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 28,0);
    tracep->declBus(c+117,0,"n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 28,0);
    tracep->declBit(c+143,0,"q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+73,0,"t",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 28,0);
    tracep->declBus(c+193,0,"u",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declQuad(c+74,0,"d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 60,0);
    tracep->popPrefix();
    tracep->pushPrefix("gen_div[29]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+194,0,"m",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 29,0);
    tracep->declBus(c+118,0,"n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 29,0);
    tracep->declBit(c+221,0,"q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+19,0,"t",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 29,0);
    tracep->declBus(c+195,0,"u",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declQuad(c+20,0,"d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 61,0);
    tracep->popPrefix();
    tracep->pushPrefix("gen_div[2]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+196,0,"m",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+119,0,"n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+222,0,"q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+22,0,"t",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+197,0,"u",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declQuad(c+23,0,"d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 34,0);
    tracep->popPrefix();
    tracep->pushPrefix("gen_div[30]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+198,0,"m",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 30,0);
    tracep->declBus(c+120,0,"n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 30,0);
    tracep->declBit(c+144,0,"q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+76,0,"t",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 30,0);
    tracep->declBus(c+199,0,"u",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declQuad(c+77,0,"d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 62,0);
    tracep->popPrefix();
    tracep->pushPrefix("gen_div[31]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+200,0,"m",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+121,0,"n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+223,0,"q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+25,0,"t",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+844,0,"u",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declQuad(c+26,0,"d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 63,0);
    tracep->popPrefix();
    tracep->pushPrefix("gen_div[3]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+201,0,"m",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+122,0,"n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+145,0,"q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+79,0,"t",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+202,0,"u",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declQuad(c+80,0,"d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 35,0);
    tracep->popPrefix();
    tracep->pushPrefix("gen_div[4]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+203,0,"m",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+123,0,"n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBit(c+146,0,"q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+82,0,"t",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+204,0,"u",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declQuad(c+83,0,"d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 36,0);
    tracep->popPrefix();
    tracep->pushPrefix("gen_div[5]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+205,0,"m",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+124,0,"n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBit(c+147,0,"q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+85,0,"t",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+206,0,"u",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declQuad(c+86,0,"d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 37,0);
    tracep->popPrefix();
    tracep->pushPrefix("gen_div[6]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+207,0,"m",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+125,0,"n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBit(c+224,0,"q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+28,0,"t",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+208,0,"u",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declQuad(c+29,0,"d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 38,0);
    tracep->popPrefix();
    tracep->pushPrefix("gen_div[7]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+209,0,"m",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+126,0,"n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+148,0,"q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+88,0,"t",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+210,0,"u",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declQuad(c+89,0,"d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 39,0);
    tracep->popPrefix();
    tracep->pushPrefix("gen_div[8]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+211,0,"m",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 8,0);
    tracep->declBus(c+127,0,"n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 8,0);
    tracep->declBit(c+149,0,"q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+91,0,"t",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 8,0);
    tracep->declBus(c+212,0,"u",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declQuad(c+92,0,"d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 40,0);
    tracep->popPrefix();
    tracep->pushPrefix("gen_div[9]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+213,0,"m",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 9,0);
    tracep->declBus(c+128,0,"n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 9,0);
    tracep->declBit(c+150,0,"q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+94,0,"t",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 9,0);
    tracep->declBus(c+214,0,"u",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declQuad(c+95,0,"d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 41,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("multiply", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+821,0,"i_clock",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+314,0,"i_latch",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+315,0,"i_signed",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+798,0,"i_op1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+799,0,"i_op2",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+316,0,"o_ready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declQuad(c+317,0,"o_result",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 63,0);
    tracep->declBit(c+818,0,"s1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+819,0,"s2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+328,0,"m_s",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::BIT, false,-1, 1,0);
    tracep->declBus(c+329,0,"m_uop1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::BIT, false,-1, 31,0);
    tracep->declBus(c+330,0,"m_uop2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::BIT, false,-1, 31,0);
    tracep->declQuad(c+331,0,"m_product",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 63,0);
    tracep->declBus(c+333,0,"state",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::BIT, false,-1, 1,0);
    tracep->declBus(c+334,0,"cnt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::BIT, false,-1, 7,0);
    tracep->declQuad(c+317,0,"result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::BIT, false,-1, 63,0);
    tracep->declBit(c+316,0,"ready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::BIT, false,-1);
    tracep->pushPrefix("m", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+821,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+869,0,"rst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+870,0,"valid_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+329,0,"a",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+330,0,"b",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+335,0,"valid_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declQuad(c+331,0,"product",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 63,0);
    tracep->pushPrefix("partial_products", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 32; ++i) {
        tracep->declQuad(c+336+i*2,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, true,(i+0), 63,0);
    }
    tracep->popPrefix();
    tracep->pushPrefix("stage1_sum", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 16; ++i) {
        tracep->declQuad(c+400+i*2,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 63,0);
    }
    tracep->popPrefix();
    tracep->declBus(c+432,0,"j",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->pushPrefix("stage2_sum", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 8; ++i) {
        tracep->declQuad(c+433+i*2,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 63,0);
    }
    tracep->popPrefix();
    tracep->pushPrefix("stage3_sum", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 4; ++i) {
        tracep->declQuad(c+449+i*2,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 63,0);
    }
    tracep->popPrefix();
    tracep->declQuad(c+457,0,"stage4_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 63,0);
    tracep->declQuad(c+459,0,"stage4_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 63,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("fetch", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+461,0,"is_ADD",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+462,0,"is_ADDI",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+463,0,"is_AND",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+464,0,"is_ANDI",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+465,0,"is_AUIPC",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+466,0,"is_BEQ",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+467,0,"is_BGE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+468,0,"is_BGEU",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+469,0,"is_BLT",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+470,0,"is_BLTU",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+471,0,"is_BNE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+472,0,"is_CSRRC",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+473,0,"is_CSRRS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+474,0,"is_CSRRW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+475,0,"is_DIV",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+476,0,"is_DIVU",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+477,0,"is_EBREAK",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+478,0,"is_ECALL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+479,0,"is_FADD",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+480,0,"is_FCVT_W_S",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+481,0,"is_FCVT_WU_S",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+482,0,"is_FCVT_S_W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+483,0,"is_FCVT_S_WU",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+484,0,"is_FDIV",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+485,0,"is_FENCE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+486,0,"is_FEQ",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+487,0,"is_FLE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+488,0,"is_FLT",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+489,0,"is_FLW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+490,0,"is_FMADD",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+491,0,"is_FMSUB",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+492,0,"is_FNMADD",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+493,0,"is_FNMSUB",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+494,0,"is_FMIN",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+495,0,"is_FMAX",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+496,0,"is_FMUL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+497,0,"is_FMV_X_W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+498,0,"is_FMV_W_X",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+499,0,"is_FSGNJ",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+500,0,"is_FSGNJN",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+501,0,"is_FSGNJX",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+502,0,"is_FSUB",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+503,0,"is_FSW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+504,0,"is_JAL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+505,0,"is_JALR",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+506,0,"is_LB",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+507,0,"is_LBU",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+508,0,"is_LH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+509,0,"is_LHU",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+510,0,"is_LUI",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+511,0,"is_LW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+512,0,"is_MUL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+513,0,"is_MULH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+514,0,"is_MULHU",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+515,0,"is_MRET",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+516,0,"is_OR",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+517,0,"is_ORI",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+518,0,"is_REM",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+519,0,"is_REMU",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+520,0,"is_SB",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+521,0,"is_SH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+522,0,"is_SLL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+523,0,"is_SLLI",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+524,0,"is_SLT",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+525,0,"is_SLTI",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+526,0,"is_SLTIU",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+527,0,"is_SLTU",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+528,0,"is_SRA",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+529,0,"is_SRAI",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+530,0,"is_SRL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+531,0,"is_SRLI",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+532,0,"is_SUB",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+533,0,"is_SW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+534,0,"is_WFI",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+535,0,"is_XOR",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+536,0,"is_XORI",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+537,0,"is_B",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+538,0,"is_I",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+504,0,"is_J",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+539,0,"is_R",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+540,0,"is_R4",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+541,0,"is_S",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+542,0,"is_U",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+543,0,"is_CSR",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+544,0,"is_ARITHMETIC",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+545,0,"is_SHIFT",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+546,0,"is_COMPARE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+547,0,"is_COMPLEX",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+548,0,"is_JUMP",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+537,0,"is_JUMP_CONDITIONAL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+549,0,"is_MEMORY",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+550,0,"is_FPU",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+551,0,"is_FPU_MEMORY",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+552,0,"RD_bank",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+553,0,"RS1_bank",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+554,0,"RS2_bank",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+540,0,"RS3_bank",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+844,0,"RESET_VECTOR",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+847,0,"ICACHE_SIZE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+848,0,"ICACHE_REGISTERED",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+820,0,"i_reset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+821,0,"i_clock",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+277,0,"i_jump",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+278,0,"i_jump_pc",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+241,0,"i_irq_pending",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+242,0,"i_irq_pc",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+243,0,"o_irq_dispatched",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBus(c+244,0,"o_irq_epc",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::BIT, false,-1, 31,0);
    tracep->declBit(c+225,0,"o_bus_request",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+831,0,"i_bus_ready",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+226,0,"o_bus_address",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+828,0,"i_bus_rdata",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+555,0,"i_busy",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("o_data", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+245,0,"strobe",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBus(c+246,0,"instruction",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::BIT, false,-1, 31,0);
    tracep->declBus(c+247,0,"pc",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::BIT, false,-1, 31,0);
    tracep->declBus(c+248,0,"inst_rs1",1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::BIT, false,-1, 4,0);
    tracep->declBus(c+249,0,"inst_rs2",1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::BIT, false,-1, 4,0);
    tracep->declBus(c+250,0,"inst_rs3",1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::BIT, false,-1, 4,0);
    tracep->declBus(c+251,0,"inst_rd",1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::BIT, false,-1, 4,0);
    tracep->declBus(c+252,0,"imm",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::BIT, false,-1, 31,0);
    tracep->popPrefix();
    tracep->declBus(c+843,0,"o_icache_hit",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+843,0,"o_icache_miss",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+556,0,"state",2, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::BIT, false,-1, 1,0);
    tracep->declBus(c+557,0,"pc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::BIT, false,-1, 31,0);
    tracep->pushPrefix("data", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+245,0,"strobe",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBus(c+246,0,"instruction",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::BIT, false,-1, 31,0);
    tracep->declBus(c+247,0,"pc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::BIT, false,-1, 31,0);
    tracep->declBus(c+248,0,"inst_rs1",1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::BIT, false,-1, 4,0);
    tracep->declBus(c+249,0,"inst_rs2",1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::BIT, false,-1, 4,0);
    tracep->declBus(c+250,0,"inst_rs3",1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::BIT, false,-1, 4,0);
    tracep->declBus(c+251,0,"inst_rd",1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::BIT, false,-1, 4,0);
    tracep->declBus(c+252,0,"imm",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::BIT, false,-1, 31,0);
    tracep->popPrefix();
    tracep->declBus(c+843,0,"starve",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::BIT, false,-1, 31,0);
    tracep->declBus(c+558,0,"icache_rdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+559,0,"icache_ready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+560,0,"have_RS1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+561,0,"have_RS2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+540,0,"have_RS3",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+562,0,"have_RD",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+563,0,"irq_pending_r",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::BIT, false,-1);
    tracep->pushPrefix("genblk1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->pushPrefix("icache", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+847,0,"SIZE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+820,0,"i_reset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+821,0,"i_clock",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+557,0,"i_input_pc",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+558,0,"o_rdata",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::BIT, false,-1, 31,0);
    tracep->declBit(c+559,0,"o_ready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBit(c+225,0,"o_bus_request",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBit(c+831,0,"i_bus_ready",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+226,0,"o_bus_address",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::BIT, false,-1, 31,0);
    tracep->declBus(c+828,0,"i_bus_rdata",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+843,0,"o_hit",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+843,0,"o_miss",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+871,0,"RANGE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+847,0,"SET_BITS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+872,0,"TAG_BITS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+564,0,"initialized",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBus(c+565,0,"clear_set",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::BIT, false,-1, 31,0);
    tracep->declBit(c+566,0,"cache_invalid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBus(c+567,0,"i_set",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 11,0);
    tracep->declBus(c+568,0,"i_tag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 17,0);
    tracep->declBus(c+569,0,"cache_rd_set",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::BIT, false,-1, 11,0);
    tracep->pushPrefix("cache_rd_rdata", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+570,0,"valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBus(c+571,0,"tag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::BIT, false,-1, 17,0);
    tracep->declBus(c+572,0,"data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::BIT, false,-1, 31,0);
    tracep->popPrefix();
    tracep->declBit(c+573,0,"cache_wr_request",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBus(c+574,0,"cache_wr_set",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::BIT, false,-1, 11,0);
    tracep->pushPrefix("cache_wr_wdata", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+575,0,"valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBus(c+576,0,"tag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::BIT, false,-1, 17,0);
    tracep->declBus(c+577,0,"data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::BIT, false,-1, 31,0);
    tracep->popPrefix();
    tracep->declBus(c+578,0,"set_r",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::BIT, false,-1, 11,0);
    tracep->pushPrefix("cache", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+873,0,"WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+871,0,"SIZE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+843,0,"ADDR_LSH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+821,0,"i_clock",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+874,0,"i_pa_request",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+579,0,"i_pa_address",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declQuad(c+580,0,"o_pa_rdata",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 50,0);
    tracep->declBit(c+582,0,"o_pa_ready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBit(c+573,0,"i_pb_request",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+583,0,"i_pb_address",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declQuad(c+584,0,"i_pb_wdata",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 50,0);
    tracep->declBit(c+586,0,"o_pb_ready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::BIT, false,-1);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("fetch_skid", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+875,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+820,0,"i_reset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+821,0,"i_clock",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+555,0,"i_busy",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declArray(c+587,0,"i_data",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 116,0);
    tracep->declArray(c+794,0,"o_data",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::BIT, false,-1, 116,0);
    tracep->declArray(c+591,0,"r_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::BIT, false,-1, 116,0);
    tracep->popPrefix();
    tracep->pushPrefix("forward", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->pushPrefix("i_decode_data", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+254,0,"strobe",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBus(c+255,0,"pc",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::BIT, false,-1, 31,0);
    tracep->declBus(c+256,0,"have_rs",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::BIT, false,-1, 2,0);
    tracep->declBus(c+257,0,"inst_rs1",1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::BIT, false,-1, 4,0);
    tracep->declBus(c+258,0,"inst_rs2",1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::BIT, false,-1, 4,0);
    tracep->declBus(c+259,0,"inst_rs3",1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::BIT, false,-1, 4,0);
    tracep->declBus(c+260,0,"inst_rd",1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::BIT, false,-1, 4,0);
    tracep->declBus(c+261,0,"imm",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::BIT, false,-1, 31,0);
    tracep->declBit(c+262,0,"arithmetic",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBit(c+263,0,"shift",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBit(c+264,0,"compare",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBit(c+265,0,"complx",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBit(c+266,0,"jump",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBit(c+267,0,"jump_conditional",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBus(c+268,0,"alu_operation",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::BIT, false,-1, 3,0);
    tracep->declBus(c+269,0,"alu_operand1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::BIT, false,-1, 4,0);
    tracep->declBus(c+270,0,"alu_operand2",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::BIT, false,-1, 4,0);
    tracep->declBit(c+271,0,"memory_read",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBit(c+272,0,"memory_write",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBus(c+273,0,"memory_width",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::BIT, false,-1, 1,0);
    tracep->declBit(c+274,0,"memory_signed",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBus(c+275,0,"op",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::BIT, false,-1, 4,0);
    tracep->popPrefix();
    tracep->pushPrefix("i_execute_data", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+281,0,"strobe",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBus(c+282,0,"pc",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::BIT, false,-1, 31,0);
    tracep->declBus(c+283,0,"inst_rd",1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::BIT, false,-1, 4,0);
    tracep->declBus(c+284,0,"rd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::BIT, false,-1, 31,0);
    tracep->declBit(c+285,0,"mem_read",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBit(c+286,0,"mem_write",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBit(c+287,0,"mem_flush",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBus(c+288,0,"mem_width",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::BIT, false,-1, 1,0);
    tracep->declBit(c+289,0,"mem_signed",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBus(c+290,0,"mem_address",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::BIT, false,-1, 31,0);
    tracep->declBus(c+291,0,"mem_inst_rd",1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::BIT, false,-1, 4,0);
    tracep->popPrefix();
    tracep->pushPrefix("i_memory_data", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+679,0,"strobe",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBus(c+680,0,"pc",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::BIT, false,-1, 31,0);
    tracep->declBus(c+681,0,"inst_rd",1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::BIT, false,-1, 4,0);
    tracep->declBus(c+682,0,"rd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::BIT, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("i_writeback_data", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+292,0,"inst_rd",1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::BIT, false,-1, 4,0);
    tracep->declBus(c+293,0,"rd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::BIT, false,-1, 31,0);
    tracep->popPrefix();
    tracep->declBus(c+634,0,"i_rs1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+635,0,"i_rs2",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+636,0,"i_rs3",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+798,0,"o_rs1",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+799,0,"o_rs2",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+800,0,"o_rs3",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+798,0,"rs1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::BIT, false,-1, 31,0);
    tracep->declBus(c+799,0,"rs2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::BIT, false,-1, 31,0);
    tracep->declBus(c+800,0,"rs3",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::BIT, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("memory", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+847,0,"DCACHE_SIZE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+848,0,"DCACHE_REGISTERED",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+820,0,"i_reset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+821,0,"i_clock",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+227,0,"o_bus_rw",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+228,0,"o_bus_request",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+832,0,"i_bus_ready",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+229,0,"o_bus_address",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+828,0,"i_bus_rdata",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+230,0,"o_bus_wdata",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+233,0,"o_busy",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::BIT, false,-1);
    tracep->pushPrefix("i_data", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+281,0,"strobe",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBus(c+282,0,"pc",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::BIT, false,-1, 31,0);
    tracep->declBus(c+283,0,"inst_rd",1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::BIT, false,-1, 4,0);
    tracep->declBus(c+284,0,"rd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::BIT, false,-1, 31,0);
    tracep->declBit(c+285,0,"mem_read",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBit(c+286,0,"mem_write",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBit(c+287,0,"mem_flush",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBus(c+288,0,"mem_width",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::BIT, false,-1, 1,0);
    tracep->declBit(c+289,0,"mem_signed",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBus(c+290,0,"mem_address",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::BIT, false,-1, 31,0);
    tracep->declBus(c+291,0,"mem_inst_rd",1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::BIT, false,-1, 4,0);
    tracep->popPrefix();
    tracep->pushPrefix("o_data", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+679,0,"strobe",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBus(c+680,0,"pc",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::BIT, false,-1, 31,0);
    tracep->declBus(c+681,0,"inst_rd",1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::BIT, false,-1, 4,0);
    tracep->declBus(c+682,0,"rd",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::BIT, false,-1, 31,0);
    tracep->popPrefix();
    tracep->declBus(c+849,0,"o_dcache_hit",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+850,0,"o_dcache_miss",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+595,0,"dcache_rw",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBit(c+596,0,"dcache_request",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBit(c+597,0,"dcache_flush",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBit(c+598,0,"dcache_ready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+599,0,"dcache_address",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+600,0,"dcache_rdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+601,0,"dcache_wdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::BIT, false,-1, 31,0);
    tracep->declBit(c+874,0,"dcache_need_flush",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+602,0,"dcache_cacheable",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+603,0,"address_byte_index",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+604,0,"bus_rdata_byte",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+605,0,"bus_rdata_half",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->pushPrefix("data", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+679,0,"strobe",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBus(c+680,0,"pc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::BIT, false,-1, 31,0);
    tracep->declBus(c+681,0,"inst_rd",1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::BIT, false,-1, 4,0);
    tracep->declBus(c+682,0,"rd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::BIT, false,-1, 31,0);
    tracep->popPrefix();
    tracep->declBus(c+606,0,"state",3, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::BIT, false,-1, 2,0);
    tracep->declBus(c+607,0,"rmw_rdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::BIT, false,-1, 31,0);
    tracep->declBit(c+608,0,"last_strobe",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::BIT, false,-1);
    tracep->pushPrefix("genblk1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->pushPrefix("dcache", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+847,0,"SIZE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+820,0,"i_reset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+821,0,"i_clock",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+227,0,"o_bus_rw",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBit(c+228,0,"o_bus_request",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBit(c+832,0,"i_bus_ready",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+229,0,"o_bus_address",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::BIT, false,-1, 31,0);
    tracep->declBus(c+828,0,"i_bus_rdata",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+230,0,"o_bus_wdata",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::BIT, false,-1, 31,0);
    tracep->declBit(c+595,0,"i_rw",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+596,0,"i_request",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+597,0,"i_flush",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+598,0,"o_ready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBus(c+599,0,"i_address",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+600,0,"o_rdata",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::BIT, false,-1, 31,0);
    tracep->declBus(c+601,0,"i_wdata",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+602,0,"i_cacheable",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+849,0,"o_hit",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+850,0,"o_miss",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+871,0,"RANGE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+609,0,"state",4, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::BIT, false,-1, 3,0);
    tracep->declBus(c+610,0,"flush_address",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::BIT, false,-1, 12,0);
    tracep->declBit(c+611,0,"wb_rw",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBit(c+612,0,"wb_request",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBit(c+841,0,"wb_ready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+613,0,"wb_address",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::BIT, false,-1, 31,0);
    tracep->declBus(c+828,0,"wb_rdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+614,0,"wb_wdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::BIT, false,-1, 31,0);
    tracep->declBit(c+615,0,"cache_rw",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBus(c+616,0,"cache_address",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::BIT, false,-1, 11,0);
    tracep->declQuad(c+617,0,"cache_wdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::BIT, false,-1, 63,0);
    tracep->declQuad(c+619,0,"cache_rdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 63,0);
    tracep->declBit(c+621,0,"cache_entry_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+622,0,"cache_entry_dirty",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+623,0,"cache_entry_address",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+624,0,"cache_entry_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("cache", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+876,0,"WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+871,0,"SIZE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+843,0,"ADDR_LSH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+821,0,"i_clock",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+874,0,"i_request",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+615,0,"i_rw",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+625,0,"i_address",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declQuad(c+617,0,"i_wdata",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 63,0);
    tracep->declQuad(c+619,0,"o_rdata",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 63,0);
    tracep->declBit(c+626,0,"o_ready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBit(c+627,0,"o_valid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::BIT, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("wb", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+820,0,"i_reset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+821,0,"i_clock",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+227,0,"o_bus_rw",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBit(c+228,0,"o_bus_request",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBit(c+832,0,"i_bus_ready",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+229,0,"o_bus_address",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::BIT, false,-1, 31,0);
    tracep->declBus(c+828,0,"i_bus_rdata",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+230,0,"o_bus_wdata",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::BIT, false,-1, 31,0);
    tracep->declBit(c+611,0,"i_rw",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+612,0,"i_request",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+841,0,"o_ready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBus(c+613,0,"i_address",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+828,0,"o_rdata",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::BIT, false,-1, 31,0);
    tracep->declBus(c+614,0,"i_wdata",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+628,0,"wb_dirty",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBus(c+629,0,"wb_address",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::BIT, false,-1, 31,0);
    tracep->declBus(c+230,0,"wb_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::BIT, false,-1, 31,0);
    tracep->declBit(c+842,0,"next_wb_dirty",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBus(c+630,0,"next_wb_address",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::BIT, false,-1, 31,0);
    tracep->declBus(c+631,0,"next_wb_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::BIT, false,-1, 31,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("registers", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+845,0,"STACK_POINTER",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+820,0,"i_reset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+821,0,"i_clock",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("i_fetch_data", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+671,0,"strobe",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBus(c+672,0,"instruction",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::BIT, false,-1, 31,0);
    tracep->declBus(c+673,0,"pc",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::BIT, false,-1, 31,0);
    tracep->declBus(c+674,0,"inst_rs1",1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::BIT, false,-1, 4,0);
    tracep->declBus(c+675,0,"inst_rs2",1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::BIT, false,-1, 4,0);
    tracep->declBus(c+676,0,"inst_rs3",1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::BIT, false,-1, 4,0);
    tracep->declBus(c+677,0,"inst_rd",1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::BIT, false,-1, 4,0);
    tracep->declBus(c+678,0,"imm",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::BIT, false,-1, 31,0);
    tracep->popPrefix();
    tracep->declBus(c+634,0,"o_rs1",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+635,0,"o_rs2",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+636,0,"o_rs3",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("i_memory_data", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+679,0,"strobe",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBus(c+680,0,"pc",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::BIT, false,-1, 31,0);
    tracep->declBus(c+681,0,"inst_rd",1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::BIT, false,-1, 4,0);
    tracep->declBus(c+682,0,"rd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::BIT, false,-1, 31,0);
    tracep->popPrefix();
    tracep->declBit(c+637,0,"last_write_strobe",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::BIT, false,-1);
    tracep->pushPrefix("r", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 32; ++i) {
        tracep->declBus(c+638+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::BIT, true,(i+0), 31,0);
    }
    tracep->popPrefix();
    tracep->declBus(c+634,0,"rs1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::BIT, false,-1, 31,0);
    tracep->declBus(c+635,0,"rs2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::BIT, false,-1, 31,0);
    tracep->declBus(c+636,0,"rs3",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::BIT, false,-1, 31,0);
    tracep->declBus(c+670,0,"I",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("writeback", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+820,0,"i_reset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+821,0,"i_clock",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("i_data", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+679,0,"strobe",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBus(c+680,0,"pc",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::BIT, false,-1, 31,0);
    tracep->declBus(c+681,0,"inst_rd",1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::BIT, false,-1, 4,0);
    tracep->declBus(c+682,0,"rd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::BIT, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("o_data", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+292,0,"inst_rd",1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::BIT, false,-1, 4,0);
    tracep->declBus(c+293,0,"rd",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::BIT, false,-1, 31,0);
    tracep->popPrefix();
    tracep->declQuad(c+239,0,"o_retired",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 63,0);
    tracep->pushPrefix("data", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+292,0,"inst_rd",1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::BIT, false,-1, 4,0);
    tracep->declBus(c+293,0,"rd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::BIT, false,-1, 31,0);
    tracep->popPrefix();
    tracep->declBit(c+632,0,"last_strobe",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::BIT, false,-1);
    tracep->declQuad(c+239,0,"retired",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::BIT, false,-1, 63,0);
    tracep->declBus(c+633,0,"last_pc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::BIT, false,-1, 31,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
}

VL_ATTR_COLD void VCPU_top___024root__trace_init_top(VCPU_top___024root* vlSelf, VerilatedFst* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCPU_top___024root__trace_init_top\n"); );
    VCPU_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    VCPU_top___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void VCPU_top___024root__trace_const_0(void* voidSelf, VerilatedFst::Buffer* bufp);
VL_ATTR_COLD void VCPU_top___024root__trace_full_0(void* voidSelf, VerilatedFst::Buffer* bufp);
void VCPU_top___024root__trace_chg_0(void* voidSelf, VerilatedFst::Buffer* bufp);
void VCPU_top___024root__trace_cleanup(void* voidSelf, VerilatedFst* /*unused*/);

VL_ATTR_COLD void VCPU_top___024root__trace_register(VCPU_top___024root* vlSelf, VerilatedFst* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCPU_top___024root__trace_register\n"); );
    VCPU_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    tracep->addConstCb(&VCPU_top___024root__trace_const_0, 0U, vlSelf);
    tracep->addFullCb(&VCPU_top___024root__trace_full_0, 0U, vlSelf);
    tracep->addChgCb(&VCPU_top___024root__trace_chg_0, 0U, vlSelf);
    tracep->addCleanupCb(&VCPU_top___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void VCPU_top___024root__trace_const_0_sub_0(VCPU_top___024root* vlSelf, VerilatedFst::Buffer* bufp);

VL_ATTR_COLD void VCPU_top___024root__trace_const_0(void* voidSelf, VerilatedFst::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCPU_top___024root__trace_const_0\n"); );
    // Init
    VCPU_top___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VCPU_top___024root*>(voidSelf);
    VCPU_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    VCPU_top___024root__trace_const_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void VCPU_top___024root__trace_const_0_sub_0(VCPU_top___024root* vlSelf, VerilatedFst::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCPU_top___024root__trace_const_0_sub_0\n"); );
    VCPU_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullIData(oldp+843,(0U),32);
    bufp->fullIData(oldp+844,(0U),32);
    bufp->fullIData(oldp+845,(0x10000400U),32);
    bufp->fullIData(oldp+846,(0x989680U),32);
    bufp->fullIData(oldp+847,(0xcU),32);
    bufp->fullIData(oldp+848,(1U),32);
    bufp->fullIData(oldp+849,(vlSelfRef.CPU_top__DOT__cpu__DOT__o_dcache_hit),32);
    bufp->fullIData(oldp+850,(vlSelfRef.CPU_top__DOT__cpu__DOT__o_dcache_miss),32);
    bufp->fullIData(oldp+851,(0x2710U),32);
    bufp->fullIData(oldp+852,(0xeU),32);
    bufp->fullCData(oldp+853,(1U),4);
    bufp->fullCData(oldp+854,(2U),4);
    bufp->fullCData(oldp+855,(3U),4);
    bufp->fullCData(oldp+856,(4U),4);
    bufp->fullCData(oldp+857,(5U),4);
    bufp->fullCData(oldp+858,(6U),4);
    bufp->fullCData(oldp+859,(7U),4);
    bufp->fullCData(oldp+860,(8U),4);
    bufp->fullCData(oldp+861,(9U),4);
    bufp->fullCData(oldp+862,(0xaU),4);
    bufp->fullCData(oldp+863,(0xbU),4);
    bufp->fullCData(oldp+864,(0xcU),4);
    bufp->fullCData(oldp+865,(0xdU),4);
    bufp->fullCData(oldp+866,(0xeU),4);
    bufp->fullIData(oldp+867,(0x20U),32);
    bufp->fullIData(oldp+868,(0xa2222225U),32);
    bufp->fullBit(oldp+869,(0U));
    bufp->fullBit(oldp+870,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__multiply__DOT__m__DOT__valid_in));
    bufp->fullIData(oldp+871,(0x1000U),32);
    bufp->fullIData(oldp+872,(0x12U),32);
    bufp->fullIData(oldp+873,(0x33U),32);
    bufp->fullBit(oldp+874,(1U));
    bufp->fullIData(oldp+875,(0x75U),32);
    bufp->fullIData(oldp+876,(0x40U),32);
}

VL_ATTR_COLD void VCPU_top___024root__trace_full_0_sub_0(VCPU_top___024root* vlSelf, VerilatedFst::Buffer* bufp);

VL_ATTR_COLD void VCPU_top___024root__trace_full_0(void* voidSelf, VerilatedFst::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCPU_top___024root__trace_full_0\n"); );
    // Init
    VCPU_top___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VCPU_top___024root*>(voidSelf);
    VCPU_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    VCPU_top___024root__trace_full_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void VCPU_top___024root__trace_full_0_sub_0(VCPU_top___024root* vlSelf, VerilatedFst::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCPU_top___024root__trace_full_0_sub_0\n"); );
    VCPU_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullBit(oldp+1,((1U & ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__0__KET____DOT__q)
                                  ? ((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                      [0U] >> 0x1fU) 
                                     - vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                     [0U]) : (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                              [0U] 
                                              >> 0x1fU)))));
    bufp->fullQData(oldp+2,((0x1ffffffffULL & VL_SHIFTR_QQI(33,33,32, 
                                                            (((QData)((IData)(
                                                                              (1U 
                                                                               & ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__0__KET____DOT__q)
                                                                                 ? 
                                                                                ((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                                                                [0U] 
                                                                                >> 0x1fU) 
                                                                                - 
                                                                                vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                                                                [0U])
                                                                                 : 
                                                                                (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                                                                [0U] 
                                                                                >> 0x1fU))))) 
                                                              << 0x20U) 
                                                             | (QData)((IData)(
                                                                               VL_SHIFTL_III(32,32,32, 
                                                                                vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                                                                [0U], 1U)))), 1U))),33);
    bufp->fullSData(oldp+4,((0x7ffU & ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__10__KET____DOT__q)
                                        ? ((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                            [0xaU] 
                                            >> 0x15U) 
                                           - vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                           [0xaU]) : 
                                       (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                        [0xaU] >> 0x15U)))),11);
    bufp->fullQData(oldp+5,((0x7ffffffffffULL & VL_SHIFTR_QQI(43,43,32, 
                                                              (((QData)((IData)(
                                                                                (0x7ffU 
                                                                                & ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__10__KET____DOT__q)
                                                                                 ? 
                                                                                ((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                                                                [0xaU] 
                                                                                >> 0x15U) 
                                                                                - 
                                                                                vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                                                                [0xaU])
                                                                                 : 
                                                                                (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                                                                [0xaU] 
                                                                                >> 0x15U))))) 
                                                                << 0x20U) 
                                                               | (QData)((IData)(
                                                                                VL_SHIFTL_III(32,32,32, 
                                                                                vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                                                                [0xaU], 0xbU)))), 0xbU))),43);
    bufp->fullSData(oldp+7,((0x7fffU & ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__14__KET____DOT__q)
                                         ? ((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                             [0xeU] 
                                             >> 0x11U) 
                                            - vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                            [0xeU])
                                         : (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                            [0xeU] 
                                            >> 0x11U)))),15);
    bufp->fullQData(oldp+8,((0x7fffffffffffULL & VL_SHIFTR_QQI(47,47,32, 
                                                               (((QData)((IData)(
                                                                                (0x7fffU 
                                                                                & ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__14__KET____DOT__q)
                                                                                 ? 
                                                                                ((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                                                                [0xeU] 
                                                                                >> 0x11U) 
                                                                                - 
                                                                                vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                                                                [0xeU])
                                                                                 : 
                                                                                (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                                                                [0xeU] 
                                                                                >> 0x11U))))) 
                                                                 << 0x20U) 
                                                                | (QData)((IData)(
                                                                                VL_SHIFTL_III(32,32,32, 
                                                                                vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                                                                [0xeU], 0xfU)))), 0xfU))),47);
    bufp->fullIData(oldp+10,((0x7ffffU & ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__18__KET____DOT__q)
                                           ? ((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                               [0x12U] 
                                               >> 0xdU) 
                                              - vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                              [0x12U])
                                           : (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                              [0x12U] 
                                              >> 0xdU)))),19);
    bufp->fullQData(oldp+11,((0x7ffffffffffffULL & 
                              VL_SHIFTR_QQI(51,51,32, 
                                            (((QData)((IData)(
                                                              (0x7ffffU 
                                                               & ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__18__KET____DOT__q)
                                                                   ? 
                                                                  ((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                                                    [0x12U] 
                                                                    >> 0xdU) 
                                                                   - 
                                                                   vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                                                   [0x12U])
                                                                   : 
                                                                  (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                                                   [0x12U] 
                                                                   >> 0xdU))))) 
                                              << 0x20U) 
                                             | (QData)((IData)(
                                                               VL_SHIFTL_III(32,32,32, 
                                                                             vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                                                             [0x12U], 0x13U)))), 0x13U))),51);
    bufp->fullIData(oldp+13,((0x7fffffU & ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__22__KET____DOT__q)
                                            ? ((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                                [0x16U] 
                                                >> 9U) 
                                               - vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                               [0x16U])
                                            : (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                               [0x16U] 
                                               >> 9U)))),23);
    bufp->fullQData(oldp+14,((0x7fffffffffffffULL & 
                              VL_SHIFTR_QQI(55,55,32, 
                                            (((QData)((IData)(
                                                              (0x7fffffU 
                                                               & ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__22__KET____DOT__q)
                                                                   ? 
                                                                  ((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                                                    [0x16U] 
                                                                    >> 9U) 
                                                                   - 
                                                                   vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                                                   [0x16U])
                                                                   : 
                                                                  (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                                                   [0x16U] 
                                                                   >> 9U))))) 
                                              << 0x20U) 
                                             | (QData)((IData)(
                                                               VL_SHIFTL_III(32,32,32, 
                                                                             vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                                                             [0x16U], 0x17U)))), 0x17U))),55);
    bufp->fullIData(oldp+16,((0x7ffffffU & ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__26__KET____DOT__q)
                                             ? ((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                                 [0x1aU] 
                                                 >> 5U) 
                                                - vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                                [0x1aU])
                                             : (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                                [0x1aU] 
                                                >> 5U)))),27);
    bufp->fullQData(oldp+17,((0x7ffffffffffffffULL 
                              & VL_SHIFTR_QQI(59,59,32, 
                                              (((QData)((IData)(
                                                                (0x7ffffffU 
                                                                 & ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__26__KET____DOT__q)
                                                                     ? 
                                                                    ((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                                                      [0x1aU] 
                                                                      >> 5U) 
                                                                     - 
                                                                     vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                                                     [0x1aU])
                                                                     : 
                                                                    (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                                                     [0x1aU] 
                                                                     >> 5U))))) 
                                                << 0x20U) 
                                               | (QData)((IData)(
                                                                 VL_SHIFTL_III(32,32,32, 
                                                                               vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                                                               [0x1aU], 0x1bU)))), 0x1bU))),59);
    bufp->fullIData(oldp+19,((0x3fffffffU & ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__29__KET____DOT__q)
                                              ? ((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                                  [0x1dU] 
                                                  >> 2U) 
                                                 - 
                                                 vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                                 [0x1dU])
                                              : (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                                 [0x1dU] 
                                                 >> 2U)))),30);
    bufp->fullQData(oldp+20,((0x3fffffffffffffffULL 
                              & VL_SHIFTR_QQI(62,62,32, 
                                              (((QData)((IData)(
                                                                (0x3fffffffU 
                                                                 & ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__29__KET____DOT__q)
                                                                     ? 
                                                                    ((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                                                      [0x1dU] 
                                                                      >> 2U) 
                                                                     - 
                                                                     vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                                                     [0x1dU])
                                                                     : 
                                                                    (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                                                     [0x1dU] 
                                                                     >> 2U))))) 
                                                << 0x20U) 
                                               | (QData)((IData)(
                                                                 VL_SHIFTL_III(32,32,32, 
                                                                               vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                                                               [0x1dU], 0x1eU)))), 0x1eU))),62);
    bufp->fullCData(oldp+22,((7U & ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__2__KET____DOT__q)
                                     ? ((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                         [2U] >> 0x1dU) 
                                        - vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                        [2U]) : (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                                 [2U] 
                                                 >> 0x1dU)))),3);
    bufp->fullQData(oldp+23,((0x7ffffffffULL & VL_SHIFTR_QQI(35,35,32, 
                                                             (((QData)((IData)(
                                                                               (7U 
                                                                                & ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__2__KET____DOT__q)
                                                                                 ? 
                                                                                ((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                                                                [2U] 
                                                                                >> 0x1dU) 
                                                                                - 
                                                                                vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                                                                [2U])
                                                                                 : 
                                                                                (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                                                                [2U] 
                                                                                >> 0x1dU))))) 
                                                               << 0x20U) 
                                                              | (QData)((IData)(
                                                                                VL_SHIFTL_III(32,32,32, 
                                                                                vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                                                                [2U], 3U)))), 3U))),35);
    bufp->fullIData(oldp+25,(((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__31__KET____DOT__q)
                               ? (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                  [0x1fU] - vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                  [0x1fU]) : vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                              [0x1fU])),32);
    bufp->fullQData(oldp+26,(VL_SHIFTR_QQI(64,64,32, 
                                           ((QData)((IData)(
                                                            ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__31__KET____DOT__q)
                                                              ? 
                                                             (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                                              [0x1fU] 
                                                              - 
                                                              vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                                              [0x1fU])
                                                              : 
                                                             vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                                             [0x1fU]))) 
                                            << 0x20U), 0x20U)),64);
    bufp->fullCData(oldp+28,((0x7fU & ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__6__KET____DOT__q)
                                        ? ((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                            [6U] >> 0x19U) 
                                           - vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                           [6U]) : 
                                       (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                        [6U] >> 0x19U)))),7);
    bufp->fullQData(oldp+29,((0x7fffffffffULL & VL_SHIFTR_QQI(39,39,32, 
                                                              (((QData)((IData)(
                                                                                (0x7fU 
                                                                                & ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__6__KET____DOT__q)
                                                                                 ? 
                                                                                ((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                                                                [6U] 
                                                                                >> 0x19U) 
                                                                                - 
                                                                                vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                                                                [6U])
                                                                                 : 
                                                                                (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                                                                [6U] 
                                                                                >> 0x19U))))) 
                                                                << 0x20U) 
                                                               | (QData)((IData)(
                                                                                VL_SHIFTL_III(32,32,32, 
                                                                                vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                                                                [6U], 7U)))), 7U))),39);
    bufp->fullSData(oldp+31,((0xfffU & ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__11__KET____DOT__q)
                                         ? ((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                             [0xbU] 
                                             >> 0x14U) 
                                            - vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                            [0xbU])
                                         : (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                            [0xbU] 
                                            >> 0x14U)))),12);
    bufp->fullQData(oldp+32,((0xfffffffffffULL & VL_SHIFTR_QQI(44,44,32, 
                                                               (((QData)((IData)(
                                                                                (0xfffU 
                                                                                & ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__11__KET____DOT__q)
                                                                                 ? 
                                                                                ((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                                                                [0xbU] 
                                                                                >> 0x14U) 
                                                                                - 
                                                                                vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                                                                [0xbU])
                                                                                 : 
                                                                                (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                                                                [0xbU] 
                                                                                >> 0x14U))))) 
                                                                 << 0x20U) 
                                                                | (QData)((IData)(
                                                                                VL_SHIFTL_III(32,32,32, 
                                                                                vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                                                                [0xbU], 0xcU)))), 0xcU))),44);
    bufp->fullSData(oldp+34,((0x1fffU & ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__12__KET____DOT__q)
                                          ? ((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                              [0xcU] 
                                              >> 0x13U) 
                                             - vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                             [0xcU])
                                          : (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                             [0xcU] 
                                             >> 0x13U)))),13);
    bufp->fullQData(oldp+35,((0x1fffffffffffULL & VL_SHIFTR_QQI(45,45,32, 
                                                                (((QData)((IData)(
                                                                                (0x1fffU 
                                                                                & ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__12__KET____DOT__q)
                                                                                 ? 
                                                                                ((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                                                                [0xcU] 
                                                                                >> 0x13U) 
                                                                                - 
                                                                                vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                                                                [0xcU])
                                                                                 : 
                                                                                (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                                                                [0xcU] 
                                                                                >> 0x13U))))) 
                                                                  << 0x20U) 
                                                                 | (QData)((IData)(
                                                                                VL_SHIFTL_III(32,32,32, 
                                                                                vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                                                                [0xcU], 0xdU)))), 0xdU))),45);
    bufp->fullSData(oldp+37,((0x3fffU & ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__13__KET____DOT__q)
                                          ? ((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                              [0xdU] 
                                              >> 0x12U) 
                                             - vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                             [0xdU])
                                          : (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                             [0xdU] 
                                             >> 0x12U)))),14);
    bufp->fullQData(oldp+38,((0x3fffffffffffULL & VL_SHIFTR_QQI(46,46,32, 
                                                                (((QData)((IData)(
                                                                                (0x3fffU 
                                                                                & ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__13__KET____DOT__q)
                                                                                 ? 
                                                                                ((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                                                                [0xdU] 
                                                                                >> 0x12U) 
                                                                                - 
                                                                                vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                                                                [0xdU])
                                                                                 : 
                                                                                (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                                                                [0xdU] 
                                                                                >> 0x12U))))) 
                                                                  << 0x20U) 
                                                                 | (QData)((IData)(
                                                                                VL_SHIFTL_III(32,32,32, 
                                                                                vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                                                                [0xdU], 0xeU)))), 0xeU))),46);
    bufp->fullSData(oldp+40,((0xffffU & ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__15__KET____DOT__q)
                                          ? ((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                              [0xfU] 
                                              >> 0x10U) 
                                             - vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                             [0xfU])
                                          : (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                             [0xfU] 
                                             >> 0x10U)))),16);
    bufp->fullQData(oldp+41,((0xffffffffffffULL & VL_SHIFTR_QQI(48,48,32, 
                                                                (((QData)((IData)(
                                                                                (0xffffU 
                                                                                & ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__15__KET____DOT__q)
                                                                                 ? 
                                                                                ((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                                                                [0xfU] 
                                                                                >> 0x10U) 
                                                                                - 
                                                                                vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                                                                [0xfU])
                                                                                 : 
                                                                                (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                                                                [0xfU] 
                                                                                >> 0x10U))))) 
                                                                  << 0x20U) 
                                                                 | (QData)((IData)(
                                                                                VL_SHIFTL_III(32,32,32, 
                                                                                vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                                                                [0xfU], 0x10U)))), 0x10U))),48);
    bufp->fullIData(oldp+43,((0x1ffffU & ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__16__KET____DOT__q)
                                           ? ((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                               [0x10U] 
                                               >> 0xfU) 
                                              - vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                              [0x10U])
                                           : (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                              [0x10U] 
                                              >> 0xfU)))),17);
    bufp->fullQData(oldp+44,((0x1ffffffffffffULL & 
                              VL_SHIFTR_QQI(49,49,32, 
                                            (((QData)((IData)(
                                                              (0x1ffffU 
                                                               & ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__16__KET____DOT__q)
                                                                   ? 
                                                                  ((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                                                    [0x10U] 
                                                                    >> 0xfU) 
                                                                   - 
                                                                   vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                                                   [0x10U])
                                                                   : 
                                                                  (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                                                   [0x10U] 
                                                                   >> 0xfU))))) 
                                              << 0x20U) 
                                             | (QData)((IData)(
                                                               VL_SHIFTL_III(32,32,32, 
                                                                             vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                                                             [0x10U], 0x11U)))), 0x11U))),49);
    bufp->fullIData(oldp+46,((0x3ffffU & ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__17__KET____DOT__q)
                                           ? ((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                               [0x11U] 
                                               >> 0xeU) 
                                              - vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                              [0x11U])
                                           : (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                              [0x11U] 
                                              >> 0xeU)))),18);
    bufp->fullQData(oldp+47,((0x3ffffffffffffULL & 
                              VL_SHIFTR_QQI(50,50,32, 
                                            (((QData)((IData)(
                                                              (0x3ffffU 
                                                               & ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__17__KET____DOT__q)
                                                                   ? 
                                                                  ((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                                                    [0x11U] 
                                                                    >> 0xeU) 
                                                                   - 
                                                                   vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                                                   [0x11U])
                                                                   : 
                                                                  (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                                                   [0x11U] 
                                                                   >> 0xeU))))) 
                                              << 0x20U) 
                                             | (QData)((IData)(
                                                               VL_SHIFTL_III(32,32,32, 
                                                                             vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                                                             [0x11U], 0x12U)))), 0x12U))),50);
    bufp->fullIData(oldp+49,((0xfffffU & ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__19__KET____DOT__q)
                                           ? ((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                               [0x13U] 
                                               >> 0xcU) 
                                              - vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                              [0x13U])
                                           : (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                              [0x13U] 
                                              >> 0xcU)))),20);
    bufp->fullQData(oldp+50,((0xfffffffffffffULL & 
                              VL_SHIFTR_QQI(52,52,32, 
                                            (((QData)((IData)(
                                                              (0xfffffU 
                                                               & ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__19__KET____DOT__q)
                                                                   ? 
                                                                  ((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                                                    [0x13U] 
                                                                    >> 0xcU) 
                                                                   - 
                                                                   vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                                                   [0x13U])
                                                                   : 
                                                                  (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                                                   [0x13U] 
                                                                   >> 0xcU))))) 
                                              << 0x20U) 
                                             | (QData)((IData)(
                                                               VL_SHIFTL_III(32,32,32, 
                                                                             vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                                                             [0x13U], 0x14U)))), 0x14U))),52);
    bufp->fullCData(oldp+52,((3U & ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__1__KET____DOT__q)
                                     ? ((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                         [1U] >> 0x1eU) 
                                        - vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                        [1U]) : (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                                 [1U] 
                                                 >> 0x1eU)))),2);
    bufp->fullQData(oldp+53,((0x3ffffffffULL & VL_SHIFTR_QQI(34,34,32, 
                                                             (((QData)((IData)(
                                                                               (3U 
                                                                                & ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__1__KET____DOT__q)
                                                                                 ? 
                                                                                ((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                                                                [1U] 
                                                                                >> 0x1eU) 
                                                                                - 
                                                                                vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                                                                [1U])
                                                                                 : 
                                                                                (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                                                                [1U] 
                                                                                >> 0x1eU))))) 
                                                               << 0x20U) 
                                                              | (QData)((IData)(
                                                                                VL_SHIFTL_III(32,32,32, 
                                                                                vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                                                                [1U], 2U)))), 2U))),34);
    bufp->fullIData(oldp+55,((0x1fffffU & ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__20__KET____DOT__q)
                                            ? ((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                                [0x14U] 
                                                >> 0xbU) 
                                               - vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                               [0x14U])
                                            : (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                               [0x14U] 
                                               >> 0xbU)))),21);
    bufp->fullQData(oldp+56,((0x1fffffffffffffULL & 
                              VL_SHIFTR_QQI(53,53,32, 
                                            (((QData)((IData)(
                                                              (0x1fffffU 
                                                               & ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__20__KET____DOT__q)
                                                                   ? 
                                                                  ((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                                                    [0x14U] 
                                                                    >> 0xbU) 
                                                                   - 
                                                                   vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                                                   [0x14U])
                                                                   : 
                                                                  (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                                                   [0x14U] 
                                                                   >> 0xbU))))) 
                                              << 0x20U) 
                                             | (QData)((IData)(
                                                               VL_SHIFTL_III(32,32,32, 
                                                                             vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                                                             [0x14U], 0x15U)))), 0x15U))),53);
    bufp->fullIData(oldp+58,((0x3fffffU & ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__21__KET____DOT__q)
                                            ? ((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                                [0x15U] 
                                                >> 0xaU) 
                                               - vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                               [0x15U])
                                            : (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                               [0x15U] 
                                               >> 0xaU)))),22);
    bufp->fullQData(oldp+59,((0x3fffffffffffffULL & 
                              VL_SHIFTR_QQI(54,54,32, 
                                            (((QData)((IData)(
                                                              (0x3fffffU 
                                                               & ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__21__KET____DOT__q)
                                                                   ? 
                                                                  ((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                                                    [0x15U] 
                                                                    >> 0xaU) 
                                                                   - 
                                                                   vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                                                   [0x15U])
                                                                   : 
                                                                  (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                                                   [0x15U] 
                                                                   >> 0xaU))))) 
                                              << 0x20U) 
                                             | (QData)((IData)(
                                                               VL_SHIFTL_III(32,32,32, 
                                                                             vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                                                             [0x15U], 0x16U)))), 0x16U))),54);
    bufp->fullIData(oldp+61,((0xffffffU & ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__23__KET____DOT__q)
                                            ? ((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                                [0x17U] 
                                                >> 8U) 
                                               - vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                               [0x17U])
                                            : (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                               [0x17U] 
                                               >> 8U)))),24);
    bufp->fullQData(oldp+62,((0xffffffffffffffULL & 
                              VL_SHIFTR_QQI(56,56,32, 
                                            (((QData)((IData)(
                                                              (0xffffffU 
                                                               & ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__23__KET____DOT__q)
                                                                   ? 
                                                                  ((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                                                    [0x17U] 
                                                                    >> 8U) 
                                                                   - 
                                                                   vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                                                   [0x17U])
                                                                   : 
                                                                  (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                                                   [0x17U] 
                                                                   >> 8U))))) 
                                              << 0x20U) 
                                             | (QData)((IData)(
                                                               VL_SHIFTL_III(32,32,32, 
                                                                             vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                                                             [0x17U], 0x18U)))), 0x18U))),56);
    bufp->fullIData(oldp+64,((0x1ffffffU & ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__24__KET____DOT__q)
                                             ? ((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                                 [0x18U] 
                                                 >> 7U) 
                                                - vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                                [0x18U])
                                             : (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                                [0x18U] 
                                                >> 7U)))),25);
    bufp->fullQData(oldp+65,((0x1ffffffffffffffULL 
                              & VL_SHIFTR_QQI(57,57,32, 
                                              (((QData)((IData)(
                                                                (0x1ffffffU 
                                                                 & ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__24__KET____DOT__q)
                                                                     ? 
                                                                    ((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                                                      [0x18U] 
                                                                      >> 7U) 
                                                                     - 
                                                                     vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                                                     [0x18U])
                                                                     : 
                                                                    (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                                                     [0x18U] 
                                                                     >> 7U))))) 
                                                << 0x20U) 
                                               | (QData)((IData)(
                                                                 VL_SHIFTL_III(32,32,32, 
                                                                               vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                                                               [0x18U], 0x19U)))), 0x19U))),57);
    bufp->fullIData(oldp+67,((0x3ffffffU & ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__25__KET____DOT__q)
                                             ? ((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                                 [0x19U] 
                                                 >> 6U) 
                                                - vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                                [0x19U])
                                             : (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                                [0x19U] 
                                                >> 6U)))),26);
    bufp->fullQData(oldp+68,((0x3ffffffffffffffULL 
                              & VL_SHIFTR_QQI(58,58,32, 
                                              (((QData)((IData)(
                                                                (0x3ffffffU 
                                                                 & ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__25__KET____DOT__q)
                                                                     ? 
                                                                    ((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                                                      [0x19U] 
                                                                      >> 6U) 
                                                                     - 
                                                                     vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                                                     [0x19U])
                                                                     : 
                                                                    (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                                                     [0x19U] 
                                                                     >> 6U))))) 
                                                << 0x20U) 
                                               | (QData)((IData)(
                                                                 VL_SHIFTL_III(32,32,32, 
                                                                               vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                                                               [0x19U], 0x1aU)))), 0x1aU))),58);
    bufp->fullIData(oldp+70,((0xfffffffU & ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__27__KET____DOT__q)
                                             ? ((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                                 [0x1bU] 
                                                 >> 4U) 
                                                - vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                                [0x1bU])
                                             : (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                                [0x1bU] 
                                                >> 4U)))),28);
    bufp->fullQData(oldp+71,((0xfffffffffffffffULL 
                              & VL_SHIFTR_QQI(60,60,32, 
                                              (((QData)((IData)(
                                                                (0xfffffffU 
                                                                 & ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__27__KET____DOT__q)
                                                                     ? 
                                                                    ((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                                                      [0x1bU] 
                                                                      >> 4U) 
                                                                     - 
                                                                     vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                                                     [0x1bU])
                                                                     : 
                                                                    (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                                                     [0x1bU] 
                                                                     >> 4U))))) 
                                                << 0x20U) 
                                               | (QData)((IData)(
                                                                 VL_SHIFTL_III(32,32,32, 
                                                                               vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                                                               [0x1bU], 0x1cU)))), 0x1cU))),60);
    bufp->fullIData(oldp+73,((0x1fffffffU & ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__28__KET____DOT__q)
                                              ? ((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                                  [0x1cU] 
                                                  >> 3U) 
                                                 - 
                                                 vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                                 [0x1cU])
                                              : (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                                 [0x1cU] 
                                                 >> 3U)))),29);
    bufp->fullQData(oldp+74,((0x1fffffffffffffffULL 
                              & VL_SHIFTR_QQI(61,61,32, 
                                              (((QData)((IData)(
                                                                (0x1fffffffU 
                                                                 & ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__28__KET____DOT__q)
                                                                     ? 
                                                                    ((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                                                      [0x1cU] 
                                                                      >> 3U) 
                                                                     - 
                                                                     vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                                                     [0x1cU])
                                                                     : 
                                                                    (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                                                     [0x1cU] 
                                                                     >> 3U))))) 
                                                << 0x20U) 
                                               | (QData)((IData)(
                                                                 VL_SHIFTL_III(32,32,32, 
                                                                               vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                                                               [0x1cU], 0x1dU)))), 0x1dU))),61);
    bufp->fullIData(oldp+76,((0x7fffffffU & ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__30__KET____DOT__q)
                                              ? ((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                                  [0x1eU] 
                                                  >> 1U) 
                                                 - 
                                                 vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                                 [0x1eU])
                                              : (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                                 [0x1eU] 
                                                 >> 1U)))),31);
    bufp->fullQData(oldp+77,((0x7fffffffffffffffULL 
                              & VL_SHIFTR_QQI(63,63,32, 
                                              (((QData)((IData)(
                                                                (0x7fffffffU 
                                                                 & ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__30__KET____DOT__q)
                                                                     ? 
                                                                    ((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                                                      [0x1eU] 
                                                                      >> 1U) 
                                                                     - 
                                                                     vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                                                     [0x1eU])
                                                                     : 
                                                                    (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                                                     [0x1eU] 
                                                                     >> 1U))))) 
                                                << 0x20U) 
                                               | (QData)((IData)(
                                                                 VL_SHIFTL_III(32,32,32, 
                                                                               vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                                                               [0x1eU], 0x1fU)))), 0x1fU))),63);
    bufp->fullCData(oldp+79,((0xfU & ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__3__KET____DOT__q)
                                       ? ((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                           [3U] >> 0x1cU) 
                                          - vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                          [3U]) : (
                                                   vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                                   [3U] 
                                                   >> 0x1cU)))),4);
    bufp->fullQData(oldp+80,((0xfffffffffULL & VL_SHIFTR_QQI(36,36,32, 
                                                             (((QData)((IData)(
                                                                               (0xfU 
                                                                                & ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__3__KET____DOT__q)
                                                                                 ? 
                                                                                ((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                                                                [3U] 
                                                                                >> 0x1cU) 
                                                                                - 
                                                                                vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                                                                [3U])
                                                                                 : 
                                                                                (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                                                                [3U] 
                                                                                >> 0x1cU))))) 
                                                               << 0x20U) 
                                                              | (QData)((IData)(
                                                                                VL_SHIFTL_III(32,32,32, 
                                                                                vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                                                                [3U], 4U)))), 4U))),36);
    bufp->fullCData(oldp+82,((0x1fU & ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__4__KET____DOT__q)
                                        ? ((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                            [4U] >> 0x1bU) 
                                           - vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                           [4U]) : 
                                       (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                        [4U] >> 0x1bU)))),5);
    bufp->fullQData(oldp+83,((0x1fffffffffULL & VL_SHIFTR_QQI(37,37,32, 
                                                              (((QData)((IData)(
                                                                                (0x1fU 
                                                                                & ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__4__KET____DOT__q)
                                                                                 ? 
                                                                                ((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                                                                [4U] 
                                                                                >> 0x1bU) 
                                                                                - 
                                                                                vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                                                                [4U])
                                                                                 : 
                                                                                (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                                                                [4U] 
                                                                                >> 0x1bU))))) 
                                                                << 0x20U) 
                                                               | (QData)((IData)(
                                                                                VL_SHIFTL_III(32,32,32, 
                                                                                vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                                                                [4U], 5U)))), 5U))),37);
    bufp->fullCData(oldp+85,((0x3fU & ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__5__KET____DOT__q)
                                        ? ((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                            [5U] >> 0x1aU) 
                                           - vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                           [5U]) : 
                                       (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                        [5U] >> 0x1aU)))),6);
    bufp->fullQData(oldp+86,((0x3fffffffffULL & VL_SHIFTR_QQI(38,38,32, 
                                                              (((QData)((IData)(
                                                                                (0x3fU 
                                                                                & ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__5__KET____DOT__q)
                                                                                 ? 
                                                                                ((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                                                                [5U] 
                                                                                >> 0x1aU) 
                                                                                - 
                                                                                vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                                                                [5U])
                                                                                 : 
                                                                                (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                                                                [5U] 
                                                                                >> 0x1aU))))) 
                                                                << 0x20U) 
                                                               | (QData)((IData)(
                                                                                VL_SHIFTL_III(32,32,32, 
                                                                                vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                                                                [5U], 6U)))), 6U))),38);
    bufp->fullCData(oldp+88,((0xffU & ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__7__KET____DOT__q)
                                        ? ((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                            [7U] >> 0x18U) 
                                           - vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                           [7U]) : 
                                       (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                        [7U] >> 0x18U)))),8);
    bufp->fullQData(oldp+89,((0xffffffffffULL & VL_SHIFTR_QQI(40,40,32, 
                                                              (((QData)((IData)(
                                                                                (0xffU 
                                                                                & ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__7__KET____DOT__q)
                                                                                 ? 
                                                                                ((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                                                                [7U] 
                                                                                >> 0x18U) 
                                                                                - 
                                                                                vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                                                                [7U])
                                                                                 : 
                                                                                (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                                                                [7U] 
                                                                                >> 0x18U))))) 
                                                                << 0x20U) 
                                                               | (QData)((IData)(
                                                                                VL_SHIFTL_III(32,32,32, 
                                                                                vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                                                                [7U], 8U)))), 8U))),40);
    bufp->fullSData(oldp+91,((0x1ffU & ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__8__KET____DOT__q)
                                         ? ((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                             [8U] >> 0x17U) 
                                            - vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                            [8U]) : 
                                        (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                         [8U] >> 0x17U)))),9);
    bufp->fullQData(oldp+92,((0x1ffffffffffULL & VL_SHIFTR_QQI(41,41,32, 
                                                               (((QData)((IData)(
                                                                                (0x1ffU 
                                                                                & ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__8__KET____DOT__q)
                                                                                 ? 
                                                                                ((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                                                                [8U] 
                                                                                >> 0x17U) 
                                                                                - 
                                                                                vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                                                                [8U])
                                                                                 : 
                                                                                (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                                                                [8U] 
                                                                                >> 0x17U))))) 
                                                                 << 0x20U) 
                                                                | (QData)((IData)(
                                                                                VL_SHIFTL_III(32,32,32, 
                                                                                vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                                                                [8U], 9U)))), 9U))),41);
    bufp->fullSData(oldp+94,((0x3ffU & ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__9__KET____DOT__q)
                                         ? ((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                             [9U] >> 0x16U) 
                                            - vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                            [9U]) : 
                                        (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                         [9U] >> 0x16U)))),10);
    bufp->fullQData(oldp+95,((0x3ffffffffffULL & VL_SHIFTR_QQI(42,42,32, 
                                                               (((QData)((IData)(
                                                                                (0x3ffU 
                                                                                & ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__9__KET____DOT__q)
                                                                                 ? 
                                                                                ((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                                                                [9U] 
                                                                                >> 0x16U) 
                                                                                - 
                                                                                vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                                                                [9U])
                                                                                 : 
                                                                                (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                                                                [9U] 
                                                                                >> 0x16U))))) 
                                                                 << 0x20U) 
                                                                | (QData)((IData)(
                                                                                VL_SHIFTL_III(32,32,32, 
                                                                                vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                                                                [9U], 0xaU)))), 0xaU))),42);
    bufp->fullBit(oldp+97,((1U & vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                            [0U])));
    bufp->fullSData(oldp+98,((0x7ffU & vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                              [0xaU])),11);
    bufp->fullSData(oldp+99,((0xfffU & vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                              [0xbU])),12);
    bufp->fullSData(oldp+100,((0x1fffU & vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                               [0xcU])),13);
    bufp->fullSData(oldp+101,((0x3fffU & vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                               [0xdU])),14);
    bufp->fullSData(oldp+102,((0x7fffU & vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                               [0xeU])),15);
    bufp->fullSData(oldp+103,((0xffffU & vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                               [0xfU])),16);
    bufp->fullIData(oldp+104,((0x1ffffU & vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                               [0x10U])),17);
    bufp->fullIData(oldp+105,((0x3ffffU & vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                               [0x11U])),18);
    bufp->fullIData(oldp+106,((0x7ffffU & vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                               [0x12U])),19);
    bufp->fullIData(oldp+107,((0xfffffU & vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                               [0x13U])),20);
    bufp->fullCData(oldp+108,((3U & vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                               [1U])),2);
    bufp->fullIData(oldp+109,((0x1fffffU & vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                               [0x14U])),21);
    bufp->fullIData(oldp+110,((0x3fffffU & vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                               [0x15U])),22);
    bufp->fullIData(oldp+111,((0x7fffffU & vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                               [0x16U])),23);
    bufp->fullIData(oldp+112,((0xffffffU & vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                               [0x17U])),24);
    bufp->fullIData(oldp+113,((0x1ffffffU & vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                               [0x18U])),25);
    bufp->fullIData(oldp+114,((0x3ffffffU & vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                               [0x19U])),26);
    bufp->fullIData(oldp+115,((0x7ffffffU & vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                               [0x1aU])),27);
    bufp->fullIData(oldp+116,((0xfffffffU & vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                               [0x1bU])),28);
    bufp->fullIData(oldp+117,((0x1fffffffU & vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                               [0x1cU])),29);
    bufp->fullIData(oldp+118,((0x3fffffffU & vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                               [0x1dU])),30);
    bufp->fullCData(oldp+119,((7U & vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                               [2U])),3);
    bufp->fullIData(oldp+120,((0x7fffffffU & vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                               [0x1eU])),31);
    bufp->fullIData(oldp+121,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                              [0x1fU]),32);
    bufp->fullCData(oldp+122,((0xfU & vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                               [3U])),4);
    bufp->fullCData(oldp+123,((0x1fU & vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                               [4U])),5);
    bufp->fullCData(oldp+124,((0x3fU & vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                               [5U])),6);
    bufp->fullCData(oldp+125,((0x7fU & vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                               [6U])),7);
    bufp->fullCData(oldp+126,((0xffU & vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                               [7U])),8);
    bufp->fullSData(oldp+127,((0x1ffU & vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                               [8U])),9);
    bufp->fullSData(oldp+128,((0x3ffU & vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                               [9U])),10);
    bufp->fullBit(oldp+129,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__11__KET____DOT__q));
    bufp->fullBit(oldp+130,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__12__KET____DOT__q));
    bufp->fullBit(oldp+131,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__13__KET____DOT__q));
    bufp->fullBit(oldp+132,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__15__KET____DOT__q));
    bufp->fullBit(oldp+133,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__16__KET____DOT__q));
    bufp->fullBit(oldp+134,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__17__KET____DOT__q));
    bufp->fullBit(oldp+135,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__19__KET____DOT__q));
    bufp->fullBit(oldp+136,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__1__KET____DOT__q));
    bufp->fullBit(oldp+137,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__20__KET____DOT__q));
    bufp->fullBit(oldp+138,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__21__KET____DOT__q));
    bufp->fullBit(oldp+139,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__23__KET____DOT__q));
    bufp->fullBit(oldp+140,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__24__KET____DOT__q));
    bufp->fullBit(oldp+141,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__25__KET____DOT__q));
    bufp->fullBit(oldp+142,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__27__KET____DOT__q));
    bufp->fullBit(oldp+143,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__28__KET____DOT__q));
    bufp->fullBit(oldp+144,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__30__KET____DOT__q));
    bufp->fullBit(oldp+145,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__3__KET____DOT__q));
    bufp->fullBit(oldp+146,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__4__KET____DOT__q));
    bufp->fullBit(oldp+147,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__5__KET____DOT__q));
    bufp->fullBit(oldp+148,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__7__KET____DOT__q));
    bufp->fullBit(oldp+149,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__8__KET____DOT__q));
    bufp->fullBit(oldp+150,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__9__KET____DOT__q));
    bufp->fullIData(oldp+151,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                              [0x20U]),32);
    bufp->fullBit(oldp+152,((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                             [0U] >> 0x1fU)));
    bufp->fullIData(oldp+153,(VL_SHIFTL_III(32,32,32, 
                                            vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                            [0U], 1U)),32);
    bufp->fullSData(oldp+154,((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                               [0xaU] >> 0x15U)),11);
    bufp->fullIData(oldp+155,(VL_SHIFTL_III(32,32,32, 
                                            vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                            [0xaU], 0xbU)),32);
    bufp->fullSData(oldp+156,((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                               [0xbU] >> 0x14U)),12);
    bufp->fullIData(oldp+157,(VL_SHIFTL_III(32,32,32, 
                                            vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                            [0xbU], 0xcU)),32);
    bufp->fullSData(oldp+158,((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                               [0xcU] >> 0x13U)),13);
    bufp->fullIData(oldp+159,(VL_SHIFTL_III(32,32,32, 
                                            vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                            [0xcU], 0xdU)),32);
    bufp->fullSData(oldp+160,((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                               [0xdU] >> 0x12U)),14);
    bufp->fullIData(oldp+161,(VL_SHIFTL_III(32,32,32, 
                                            vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                            [0xdU], 0xeU)),32);
    bufp->fullSData(oldp+162,((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                               [0xeU] >> 0x11U)),15);
    bufp->fullIData(oldp+163,(VL_SHIFTL_III(32,32,32, 
                                            vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                            [0xeU], 0xfU)),32);
    bufp->fullSData(oldp+164,((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                               [0xfU] >> 0x10U)),16);
    bufp->fullIData(oldp+165,(VL_SHIFTL_III(32,32,32, 
                                            vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                            [0xfU], 0x10U)),32);
    bufp->fullIData(oldp+166,((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                               [0x10U] >> 0xfU)),17);
    bufp->fullIData(oldp+167,(VL_SHIFTL_III(32,32,32, 
                                            vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                            [0x10U], 0x11U)),32);
    bufp->fullIData(oldp+168,((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                               [0x11U] >> 0xeU)),18);
    bufp->fullIData(oldp+169,(VL_SHIFTL_III(32,32,32, 
                                            vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                            [0x11U], 0x12U)),32);
    bufp->fullIData(oldp+170,((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                               [0x12U] >> 0xdU)),19);
    bufp->fullIData(oldp+171,(VL_SHIFTL_III(32,32,32, 
                                            vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                            [0x12U], 0x13U)),32);
    bufp->fullIData(oldp+172,((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                               [0x13U] >> 0xcU)),20);
    bufp->fullIData(oldp+173,(VL_SHIFTL_III(32,32,32, 
                                            vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                            [0x13U], 0x14U)),32);
    bufp->fullCData(oldp+174,((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                               [1U] >> 0x1eU)),2);
    bufp->fullIData(oldp+175,(VL_SHIFTL_III(32,32,32, 
                                            vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                            [1U], 2U)),32);
    bufp->fullIData(oldp+176,((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                               [0x14U] >> 0xbU)),21);
    bufp->fullIData(oldp+177,(VL_SHIFTL_III(32,32,32, 
                                            vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                            [0x14U], 0x15U)),32);
    bufp->fullIData(oldp+178,((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                               [0x15U] >> 0xaU)),22);
    bufp->fullIData(oldp+179,(VL_SHIFTL_III(32,32,32, 
                                            vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                            [0x15U], 0x16U)),32);
    bufp->fullIData(oldp+180,((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                               [0x16U] >> 9U)),23);
    bufp->fullIData(oldp+181,(VL_SHIFTL_III(32,32,32, 
                                            vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                            [0x16U], 0x17U)),32);
    bufp->fullIData(oldp+182,((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                               [0x17U] >> 8U)),24);
    bufp->fullIData(oldp+183,(VL_SHIFTL_III(32,32,32, 
                                            vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                            [0x17U], 0x18U)),32);
    bufp->fullIData(oldp+184,((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                               [0x18U] >> 7U)),25);
    bufp->fullIData(oldp+185,(VL_SHIFTL_III(32,32,32, 
                                            vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                            [0x18U], 0x19U)),32);
    bufp->fullIData(oldp+186,((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                               [0x19U] >> 6U)),26);
    bufp->fullIData(oldp+187,(VL_SHIFTL_III(32,32,32, 
                                            vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                            [0x19U], 0x1aU)),32);
    bufp->fullIData(oldp+188,((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                               [0x1aU] >> 5U)),27);
    bufp->fullIData(oldp+189,(VL_SHIFTL_III(32,32,32, 
                                            vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                            [0x1aU], 0x1bU)),32);
    bufp->fullIData(oldp+190,((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                               [0x1bU] >> 4U)),28);
    bufp->fullIData(oldp+191,(VL_SHIFTL_III(32,32,32, 
                                            vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                            [0x1bU], 0x1cU)),32);
    bufp->fullIData(oldp+192,((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                               [0x1cU] >> 3U)),29);
    bufp->fullIData(oldp+193,(VL_SHIFTL_III(32,32,32, 
                                            vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                            [0x1cU], 0x1dU)),32);
    bufp->fullIData(oldp+194,((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                               [0x1dU] >> 2U)),30);
    bufp->fullIData(oldp+195,(VL_SHIFTL_III(32,32,32, 
                                            vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                            [0x1dU], 0x1eU)),32);
    bufp->fullCData(oldp+196,((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                               [2U] >> 0x1dU)),3);
    bufp->fullIData(oldp+197,(VL_SHIFTL_III(32,32,32, 
                                            vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                            [2U], 3U)),32);
    bufp->fullIData(oldp+198,((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                               [0x1eU] >> 1U)),31);
    bufp->fullIData(oldp+199,(VL_SHIFTL_III(32,32,32, 
                                            vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                            [0x1eU], 0x1fU)),32);
    bufp->fullIData(oldp+200,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                              [0x1fU]),32);
    bufp->fullCData(oldp+201,((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                               [3U] >> 0x1cU)),4);
    bufp->fullIData(oldp+202,(VL_SHIFTL_III(32,32,32, 
                                            vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                            [3U], 4U)),32);
    bufp->fullCData(oldp+203,((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                               [4U] >> 0x1bU)),5);
    bufp->fullIData(oldp+204,(VL_SHIFTL_III(32,32,32, 
                                            vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                            [4U], 5U)),32);
    bufp->fullCData(oldp+205,((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                               [5U] >> 0x1aU)),6);
    bufp->fullIData(oldp+206,(VL_SHIFTL_III(32,32,32, 
                                            vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                            [5U], 6U)),32);
    bufp->fullCData(oldp+207,((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                               [6U] >> 0x19U)),7);
    bufp->fullIData(oldp+208,(VL_SHIFTL_III(32,32,32, 
                                            vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                            [6U], 7U)),32);
    bufp->fullCData(oldp+209,((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                               [7U] >> 0x18U)),8);
    bufp->fullIData(oldp+210,(VL_SHIFTL_III(32,32,32, 
                                            vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                            [7U], 8U)),32);
    bufp->fullSData(oldp+211,((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                               [8U] >> 0x17U)),9);
    bufp->fullIData(oldp+212,(VL_SHIFTL_III(32,32,32, 
                                            vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                            [8U], 9U)),32);
    bufp->fullSData(oldp+213,((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                               [9U] >> 0x16U)),10);
    bufp->fullIData(oldp+214,(VL_SHIFTL_III(32,32,32, 
                                            vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                            [9U], 0xaU)),32);
    bufp->fullBit(oldp+215,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__0__KET____DOT__q));
    bufp->fullBit(oldp+216,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__10__KET____DOT__q));
    bufp->fullBit(oldp+217,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__14__KET____DOT__q));
    bufp->fullBit(oldp+218,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__18__KET____DOT__q));
    bufp->fullBit(oldp+219,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__22__KET____DOT__q));
    bufp->fullBit(oldp+220,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__26__KET____DOT__q));
    bufp->fullBit(oldp+221,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__29__KET____DOT__q));
    bufp->fullBit(oldp+222,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__2__KET____DOT__q));
    bufp->fullBit(oldp+223,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__31__KET____DOT__q));
    bufp->fullBit(oldp+224,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__6__KET____DOT__q));
    bufp->fullBit(oldp+225,(vlSelfRef.CPU_top__DOT__cpu_ibus_request));
    bufp->fullIData(oldp+226,(vlSelfRef.CPU_top__DOT__cpu_ibus_address),32);
    bufp->fullBit(oldp+227,(vlSelfRef.CPU_top__DOT__cpu_dbus_rw));
    bufp->fullBit(oldp+228,(vlSelfRef.CPU_top__DOT__cpu_dbus_request));
    bufp->fullIData(oldp+229,(vlSelfRef.CPU_top__DOT__cpu_dbus_address),32);
    bufp->fullIData(oldp+230,(vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__genblk1__DOT__dcache__DOT__wb__DOT__wb_data),32);
    bufp->fullCData(oldp+231,(vlSelfRef.CPU_top__DOT__bus__DOT__state),2);
    bufp->fullBit(oldp+232,(((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT____VdfgRegularize_h9a67d98d_0_0) 
                             & (vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[0U] 
                                >> 0x1aU))));
    bufp->fullBit(oldp+233,(vlSelfRef.CPU_top__DOT__cpu__DOT__memory_busy));
    bufp->fullSData(oldp+234,((0xfffU & ((vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[1U] 
                                          << 2U) | 
                                         (vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[0U] 
                                          >> 0x1eU)))),12);
    bufp->fullIData(oldp+235,(vlSelfRef.CPU_top__DOT__cpu__DOT__csr_rdata),32);
    bufp->fullBit(oldp+236,(vlSelfRef.CPU_top__DOT__cpu__DOT__csr_wdata_wr));
    bufp->fullIData(oldp+237,(vlSelfRef.CPU_top__DOT__cpu__DOT__csr_wdata),32);
    bufp->fullIData(oldp+238,(vlSelfRef.CPU_top__DOT__cpu__DOT__csr__DOT__mepc),32);
    bufp->fullQData(oldp+239,(vlSelfRef.CPU_top__DOT__cpu__DOT__writeback__DOT__retired),64);
    bufp->fullBit(oldp+241,(vlSelfRef.CPU_top__DOT__cpu__DOT__csr_irq_pending));
    bufp->fullIData(oldp+242,(vlSelfRef.CPU_top__DOT__cpu__DOT__csr_irq_pc),32);
    bufp->fullBit(oldp+243,(vlSelfRef.CPU_top__DOT__cpu__DOT__csr_irq_dispatched));
    bufp->fullIData(oldp+244,(vlSelfRef.CPU_top__DOT__cpu__DOT__csr_irq_epc),32);
    bufp->fullBit(oldp+245,((1U & (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__data[3U] 
                                   >> 0x14U))));
    bufp->fullIData(oldp+246,(((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__data[3U] 
                                << 0xcU) | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__data[2U] 
                                            >> 0x14U))),32);
    bufp->fullIData(oldp+247,(((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__data[2U] 
                                << 0xcU) | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__data[1U] 
                                            >> 0x14U))),32);
    bufp->fullCData(oldp+248,((0x1fU & (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__data[1U] 
                                        >> 0xfU))),5);
    bufp->fullCData(oldp+249,((0x1fU & (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__data[1U] 
                                        >> 0xaU))),5);
    bufp->fullCData(oldp+250,((0x1fU & (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__data[1U] 
                                        >> 5U))),5);
    bufp->fullCData(oldp+251,((0x1fU & vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__data[1U])),5);
    bufp->fullIData(oldp+252,(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__data[0U]),32);
    bufp->fullBit(oldp+253,(vlSelfRef.CPU_top__DOT__cpu__DOT__decode_fault));
    bufp->fullBit(oldp+254,((1U & (vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[3U] 
                                   >> 0x15U))));
    bufp->fullIData(oldp+255,(((vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[3U] 
                                << 0xbU) | (vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[2U] 
                                            >> 0x15U))),32);
    bufp->fullCData(oldp+256,((7U & (vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[2U] 
                                     >> 0x12U))),3);
    bufp->fullCData(oldp+257,((0x1fU & (vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[2U] 
                                        >> 0xdU))),5);
    bufp->fullCData(oldp+258,((0x1fU & (vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[2U] 
                                        >> 8U))),5);
    bufp->fullCData(oldp+259,((0x1fU & (vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[2U] 
                                        >> 3U))),5);
    bufp->fullCData(oldp+260,((0x1fU & ((vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[2U] 
                                         << 2U) | (
                                                   vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[1U] 
                                                   >> 0x1eU)))),5);
    bufp->fullIData(oldp+261,(((vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[1U] 
                                << 2U) | (vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[0U] 
                                          >> 0x1eU))),32);
    bufp->fullBit(oldp+262,((1U & (vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[0U] 
                                   >> 0x1dU))));
    bufp->fullBit(oldp+263,((1U & (vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[0U] 
                                   >> 0x1cU))));
    bufp->fullBit(oldp+264,((1U & (vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[0U] 
                                   >> 0x1bU))));
    bufp->fullBit(oldp+265,((1U & (vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[0U] 
                                   >> 0x1aU))));
    bufp->fullBit(oldp+266,((1U & (vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[0U] 
                                   >> 0x19U))));
    bufp->fullBit(oldp+267,((1U & (vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[0U] 
                                   >> 0x18U))));
    bufp->fullCData(oldp+268,((0xfU & (vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[0U] 
                                       >> 0x14U))),4);
    bufp->fullCData(oldp+269,((0x1fU & (vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[0U] 
                                        >> 0xfU))),5);
    bufp->fullCData(oldp+270,((0x1fU & (vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[0U] 
                                        >> 0xaU))),5);
    bufp->fullBit(oldp+271,((1U & (vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[0U] 
                                   >> 9U))));
    bufp->fullBit(oldp+272,((1U & (vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[0U] 
                                   >> 8U))));
    bufp->fullCData(oldp+273,((3U & (vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[0U] 
                                     >> 6U))),2);
    bufp->fullBit(oldp+274,((1U & (vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[0U] 
                                   >> 5U))));
    bufp->fullCData(oldp+275,((0x1fU & vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[0U])),5);
    bufp->fullBit(oldp+276,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute_fault));
    bufp->fullBit(oldp+277,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute_jump));
    bufp->fullIData(oldp+278,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute_jump_pc),32);
    bufp->fullBit(oldp+279,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute_ecall));
    bufp->fullBit(oldp+280,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute_mret));
    bufp->fullBit(oldp+281,((1U & (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__data[3U] 
                                   >> 0x10U))));
    bufp->fullIData(oldp+282,(((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__data[3U] 
                                << 0x10U) | (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__data[2U] 
                                             >> 0x10U))),32);
    bufp->fullCData(oldp+283,((0x1fU & (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__data[2U] 
                                        >> 0xbU))),5);
    bufp->fullIData(oldp+284,(((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__data[2U] 
                                << 0x15U) | (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__data[1U] 
                                             >> 0xbU))),32);
    bufp->fullBit(oldp+285,((1U & (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__data[1U] 
                                   >> 0xaU))));
    bufp->fullBit(oldp+286,((1U & (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__data[1U] 
                                   >> 9U))));
    bufp->fullBit(oldp+287,((1U & (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__data[1U] 
                                   >> 8U))));
    bufp->fullCData(oldp+288,((3U & (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__data[1U] 
                                     >> 6U))),2);
    bufp->fullBit(oldp+289,((1U & (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__data[1U] 
                                   >> 5U))));
    bufp->fullIData(oldp+290,(((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__data[1U] 
                                << 0x1bU) | (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__data[0U] 
                                             >> 5U))),32);
    bufp->fullCData(oldp+291,((0x1fU & vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__data[0U])),5);
    bufp->fullCData(oldp+292,((0x1fU & (IData)((vlSelfRef.CPU_top__DOT__cpu__DOT__writeback__DOT__data 
                                                >> 0x20U)))),5);
    bufp->fullIData(oldp+293,((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__writeback__DOT__data)),32);
    bufp->fullBit(oldp+294,(vlSelfRef.CPU_top__DOT__cpu__DOT__csr__DOT__mstatus_mpie));
    bufp->fullBit(oldp+295,(vlSelfRef.CPU_top__DOT__cpu__DOT__csr__DOT__mstatus_mie));
    bufp->fullBit(oldp+296,(vlSelfRef.CPU_top__DOT__cpu__DOT__csr__DOT__mie_meie));
    bufp->fullBit(oldp+297,(vlSelfRef.CPU_top__DOT__cpu__DOT__csr__DOT__mie_mtie));
    bufp->fullBit(oldp+298,(vlSelfRef.CPU_top__DOT__cpu__DOT__csr__DOT__mie_msie));
    bufp->fullIData(oldp+299,(vlSelfRef.CPU_top__DOT__cpu__DOT__csr__DOT__mtvec),32);
    bufp->fullIData(oldp+300,(vlSelfRef.CPU_top__DOT__cpu__DOT__csr__DOT__mcause),32);
    bufp->fullBit(oldp+301,(vlSelfRef.CPU_top__DOT__cpu__DOT__csr__DOT__mip_meip));
    bufp->fullBit(oldp+302,(vlSelfRef.CPU_top__DOT__cpu__DOT__csr__DOT__mip_mtip));
    bufp->fullBit(oldp+303,(vlSelfRef.CPU_top__DOT__cpu__DOT__csr__DOT__mip_msip));
    bufp->fullIData(oldp+304,(vlSelfRef.CPU_top__DOT__cpu__DOT__csr__DOT__mscratch),32);
    bufp->fullIData(oldp+305,((((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__csr__DOT__mstatus_mpie) 
                                << 4U) | ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__csr__DOT__mstatus_mie) 
                                          << 3U))),32);
    bufp->fullIData(oldp+306,((((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__csr__DOT__mie_meie) 
                                << 0xbU) | (((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__csr__DOT__mie_mtie) 
                                             << 7U) 
                                            | ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__csr__DOT__mie_msie) 
                                               << 3U)))),32);
    bufp->fullIData(oldp+307,((((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__csr__DOT__mip_meip) 
                                << 0xbU) | (((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__csr__DOT__mip_mtip) 
                                             << 7U) 
                                            | ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__csr__DOT__mip_msip) 
                                               << 3U)))),32);
    bufp->fullQData(oldp+308,(vlSelfRef.CPU_top__DOT__cpu__DOT__csr__DOT__cycle),64);
    bufp->fullQData(oldp+310,(vlSelfRef.CPU_top__DOT__cpu__DOT__csr__DOT__wtime),64);
    bufp->fullSData(oldp+312,(vlSelfRef.CPU_top__DOT__cpu__DOT__csr__DOT__prescale),14);
    bufp->fullCData(oldp+313,(vlSelfRef.CPU_top__DOT__cpu__DOT__csr__DOT__issued),3);
    bufp->fullBit(oldp+314,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__mul_request));
    bufp->fullBit(oldp+315,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__mul_signed));
    bufp->fullBit(oldp+316,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__multiply__DOT__ready));
    bufp->fullQData(oldp+317,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__multiply__DOT__result),64);
    bufp->fullBit(oldp+319,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__div_request));
    bufp->fullBit(oldp+320,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__div_signed));
    bufp->fullBit(oldp+321,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__last_strobe));
    bufp->fullCData(oldp+322,((0xfU & (vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[0U] 
                                       >> 0x14U))),4);
    bufp->fullIData(oldp+323,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__unumerator),32);
    bufp->fullIData(oldp+324,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__udenominator),32);
    bufp->fullCData(oldp+325,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__s),2);
    bufp->fullBit(oldp+326,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__llth));
    bufp->fullBit(oldp+327,(((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__div_request) 
                             & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__llth))));
    bufp->fullCData(oldp+328,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__multiply__DOT__m_s),2);
    bufp->fullIData(oldp+329,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__multiply__DOT__m_uop1),32);
    bufp->fullIData(oldp+330,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__multiply__DOT__m_uop2),32);
    bufp->fullQData(oldp+331,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__multiply__DOT__m_product),64);
    bufp->fullCData(oldp+333,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__multiply__DOT__state),2);
    bufp->fullCData(oldp+334,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__multiply__DOT__cnt),8);
    bufp->fullBit(oldp+335,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__multiply__DOT__m__DOT__valid_out));
    bufp->fullQData(oldp+336,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__multiply__DOT__m__DOT__partial_products[0]),64);
    bufp->fullQData(oldp+338,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__multiply__DOT__m__DOT__partial_products[1]),64);
    bufp->fullQData(oldp+340,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__multiply__DOT__m__DOT__partial_products[2]),64);
    bufp->fullQData(oldp+342,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__multiply__DOT__m__DOT__partial_products[3]),64);
    bufp->fullQData(oldp+344,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__multiply__DOT__m__DOT__partial_products[4]),64);
    bufp->fullQData(oldp+346,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__multiply__DOT__m__DOT__partial_products[5]),64);
    bufp->fullQData(oldp+348,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__multiply__DOT__m__DOT__partial_products[6]),64);
    bufp->fullQData(oldp+350,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__multiply__DOT__m__DOT__partial_products[7]),64);
    bufp->fullQData(oldp+352,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__multiply__DOT__m__DOT__partial_products[8]),64);
    bufp->fullQData(oldp+354,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__multiply__DOT__m__DOT__partial_products[9]),64);
    bufp->fullQData(oldp+356,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__multiply__DOT__m__DOT__partial_products[10]),64);
    bufp->fullQData(oldp+358,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__multiply__DOT__m__DOT__partial_products[11]),64);
    bufp->fullQData(oldp+360,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__multiply__DOT__m__DOT__partial_products[12]),64);
    bufp->fullQData(oldp+362,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__multiply__DOT__m__DOT__partial_products[13]),64);
    bufp->fullQData(oldp+364,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__multiply__DOT__m__DOT__partial_products[14]),64);
    bufp->fullQData(oldp+366,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__multiply__DOT__m__DOT__partial_products[15]),64);
    bufp->fullQData(oldp+368,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__multiply__DOT__m__DOT__partial_products[16]),64);
    bufp->fullQData(oldp+370,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__multiply__DOT__m__DOT__partial_products[17]),64);
    bufp->fullQData(oldp+372,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__multiply__DOT__m__DOT__partial_products[18]),64);
    bufp->fullQData(oldp+374,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__multiply__DOT__m__DOT__partial_products[19]),64);
    bufp->fullQData(oldp+376,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__multiply__DOT__m__DOT__partial_products[20]),64);
    bufp->fullQData(oldp+378,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__multiply__DOT__m__DOT__partial_products[21]),64);
    bufp->fullQData(oldp+380,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__multiply__DOT__m__DOT__partial_products[22]),64);
    bufp->fullQData(oldp+382,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__multiply__DOT__m__DOT__partial_products[23]),64);
    bufp->fullQData(oldp+384,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__multiply__DOT__m__DOT__partial_products[24]),64);
    bufp->fullQData(oldp+386,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__multiply__DOT__m__DOT__partial_products[25]),64);
    bufp->fullQData(oldp+388,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__multiply__DOT__m__DOT__partial_products[26]),64);
    bufp->fullQData(oldp+390,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__multiply__DOT__m__DOT__partial_products[27]),64);
    bufp->fullQData(oldp+392,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__multiply__DOT__m__DOT__partial_products[28]),64);
    bufp->fullQData(oldp+394,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__multiply__DOT__m__DOT__partial_products[29]),64);
    bufp->fullQData(oldp+396,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__multiply__DOT__m__DOT__partial_products[30]),64);
    bufp->fullQData(oldp+398,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__multiply__DOT__m__DOT__partial_products[31]),64);
    bufp->fullQData(oldp+400,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__multiply__DOT__m__DOT__stage1_sum[0]),64);
    bufp->fullQData(oldp+402,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__multiply__DOT__m__DOT__stage1_sum[1]),64);
    bufp->fullQData(oldp+404,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__multiply__DOT__m__DOT__stage1_sum[2]),64);
    bufp->fullQData(oldp+406,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__multiply__DOT__m__DOT__stage1_sum[3]),64);
    bufp->fullQData(oldp+408,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__multiply__DOT__m__DOT__stage1_sum[4]),64);
    bufp->fullQData(oldp+410,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__multiply__DOT__m__DOT__stage1_sum[5]),64);
    bufp->fullQData(oldp+412,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__multiply__DOT__m__DOT__stage1_sum[6]),64);
    bufp->fullQData(oldp+414,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__multiply__DOT__m__DOT__stage1_sum[7]),64);
    bufp->fullQData(oldp+416,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__multiply__DOT__m__DOT__stage1_sum[8]),64);
    bufp->fullQData(oldp+418,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__multiply__DOT__m__DOT__stage1_sum[9]),64);
    bufp->fullQData(oldp+420,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__multiply__DOT__m__DOT__stage1_sum[10]),64);
    bufp->fullQData(oldp+422,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__multiply__DOT__m__DOT__stage1_sum[11]),64);
    bufp->fullQData(oldp+424,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__multiply__DOT__m__DOT__stage1_sum[12]),64);
    bufp->fullQData(oldp+426,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__multiply__DOT__m__DOT__stage1_sum[13]),64);
    bufp->fullQData(oldp+428,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__multiply__DOT__m__DOT__stage1_sum[14]),64);
    bufp->fullQData(oldp+430,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__multiply__DOT__m__DOT__stage1_sum[15]),64);
    bufp->fullIData(oldp+432,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__multiply__DOT__m__DOT__j),32);
    bufp->fullQData(oldp+433,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__multiply__DOT__m__DOT__stage2_sum[0]),64);
    bufp->fullQData(oldp+435,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__multiply__DOT__m__DOT__stage2_sum[1]),64);
    bufp->fullQData(oldp+437,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__multiply__DOT__m__DOT__stage2_sum[2]),64);
    bufp->fullQData(oldp+439,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__multiply__DOT__m__DOT__stage2_sum[3]),64);
    bufp->fullQData(oldp+441,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__multiply__DOT__m__DOT__stage2_sum[4]),64);
    bufp->fullQData(oldp+443,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__multiply__DOT__m__DOT__stage2_sum[5]),64);
    bufp->fullQData(oldp+445,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__multiply__DOT__m__DOT__stage2_sum[6]),64);
    bufp->fullQData(oldp+447,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__multiply__DOT__m__DOT__stage2_sum[7]),64);
    bufp->fullQData(oldp+449,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__multiply__DOT__m__DOT__stage3_sum[0]),64);
    bufp->fullQData(oldp+451,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__multiply__DOT__m__DOT__stage3_sum[1]),64);
    bufp->fullQData(oldp+453,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__multiply__DOT__m__DOT__stage3_sum[2]),64);
    bufp->fullQData(oldp+455,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__multiply__DOT__m__DOT__stage3_sum[3]),64);
    bufp->fullQData(oldp+457,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__multiply__DOT__m__DOT__stage4_a),64);
    bufp->fullQData(oldp+459,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__multiply__DOT__m__DOT__stage4_b),64);
    bufp->fullBit(oldp+461,((0x33U == (0xfe00707fU 
                                       & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)))));
    bufp->fullBit(oldp+462,((0x13U == (0x707fU & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)))));
    bufp->fullBit(oldp+463,((0x7033U == (0xfe00707fU 
                                         & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)))));
    bufp->fullBit(oldp+464,((0x7013U == (0x707fU & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)))));
    bufp->fullBit(oldp+465,((0x17U == (0x7fU & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)))));
    bufp->fullBit(oldp+466,((0x63U == (0x707fU & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)))));
    bufp->fullBit(oldp+467,((0x5063U == (0x707fU & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)))));
    bufp->fullBit(oldp+468,((0x7063U == (0x707fU & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)))));
    bufp->fullBit(oldp+469,((0x4063U == (0x707fU & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)))));
    bufp->fullBit(oldp+470,((0x6063U == (0x707fU & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)))));
    bufp->fullBit(oldp+471,((0x1063U == (0x707fU & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)))));
    bufp->fullBit(oldp+472,((0x3073U == (0x707fU & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)))));
    bufp->fullBit(oldp+473,((0x2073U == (0x707fU & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)))));
    bufp->fullBit(oldp+474,((0x1073U == (0x707fU & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)))));
    bufp->fullBit(oldp+475,((0x2004033U == (0xfe00707fU 
                                            & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)))));
    bufp->fullBit(oldp+476,((0x2005033U == (0xfe00707fU 
                                            & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)))));
    bufp->fullBit(oldp+477,((0x100073U == (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata))));
    bufp->fullBit(oldp+478,((0x73U == (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata))));
    bufp->fullBit(oldp+479,((0x53U == (0xfe00007fU 
                                       & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)))));
    bufp->fullBit(oldp+480,((0xc0000053U == (0xfff0007fU 
                                             & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)))));
    bufp->fullBit(oldp+481,((0xc0100053U == (0xfff0007fU 
                                             & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)))));
    bufp->fullBit(oldp+482,((0xd0000053U == (0xfff0007fU 
                                             & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)))));
    bufp->fullBit(oldp+483,((0xd0100053U == (0xfff0007fU 
                                             & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)))));
    bufp->fullBit(oldp+484,((0x18000053U == (0xfe00007fU 
                                             & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)))));
    bufp->fullBit(oldp+485,((0xfU == (0x707fU & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)))));
    bufp->fullBit(oldp+486,((0xa0002053U == (0xfe00707fU 
                                             & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)))));
    bufp->fullBit(oldp+487,((0xa0000053U == (0xfe00707fU 
                                             & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)))));
    bufp->fullBit(oldp+488,((0xa0001053U == (0xfe00707fU 
                                             & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)))));
    bufp->fullBit(oldp+489,((0x2007U == (0x707fU & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)))));
    bufp->fullBit(oldp+490,((0x43U == (0x600007fU & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)))));
    bufp->fullBit(oldp+491,((0x47U == (0x600007fU & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)))));
    bufp->fullBit(oldp+492,((0x4fU == (0x600007fU & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)))));
    bufp->fullBit(oldp+493,((0x4bU == (0x600007fU & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)))));
    bufp->fullBit(oldp+494,((0x28000053U == (0xfe00707fU 
                                             & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)))));
    bufp->fullBit(oldp+495,((0x28001053U == (0xfe00707fU 
                                             & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)))));
    bufp->fullBit(oldp+496,((0x10000053U == (0xfe00007fU 
                                             & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)))));
    bufp->fullBit(oldp+497,((0xe0000053U == (0xfff0707fU 
                                             & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)))));
    bufp->fullBit(oldp+498,((0xf0000053U == (0xfff0707fU 
                                             & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)))));
    bufp->fullBit(oldp+499,((0x20000053U == (0xfe00707fU 
                                             & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)))));
    bufp->fullBit(oldp+500,((0x20001053U == (0xfe00707fU 
                                             & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)))));
    bufp->fullBit(oldp+501,((0x20002053U == (0xfe00707fU 
                                             & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)))));
    bufp->fullBit(oldp+502,((0x8000053U == (0xfe00007fU 
                                            & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)))));
    bufp->fullBit(oldp+503,((0x2027U == (0x707fU & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)))));
    bufp->fullBit(oldp+504,((0x6fU == (0x7fU & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)))));
    bufp->fullBit(oldp+505,((0x67U == (0x707fU & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)))));
    bufp->fullBit(oldp+506,((3U == (0x707fU & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)))));
    bufp->fullBit(oldp+507,((0x4003U == (0x707fU & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)))));
    bufp->fullBit(oldp+508,((0x1003U == (0x707fU & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)))));
    bufp->fullBit(oldp+509,((0x5003U == (0x707fU & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)))));
    bufp->fullBit(oldp+510,((0x37U == (0x7fU & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)))));
    bufp->fullBit(oldp+511,((0x2003U == (0x707fU & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)))));
    bufp->fullBit(oldp+512,((0x2000033U == (0xfe00707fU 
                                            & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)))));
    bufp->fullBit(oldp+513,((0x2001033U == (0xfe00707fU 
                                            & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)))));
    bufp->fullBit(oldp+514,((0x2003033U == (0xfe00707fU 
                                            & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)))));
    bufp->fullBit(oldp+515,((0x30200073U == (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata))));
    bufp->fullBit(oldp+516,((0x6033U == (0xfe00707fU 
                                         & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)))));
    bufp->fullBit(oldp+517,((0x6013U == (0x707fU & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)))));
    bufp->fullBit(oldp+518,((0x2006033U == (0xfe00707fU 
                                            & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)))));
    bufp->fullBit(oldp+519,((0x2007033U == (0xfe00707fU 
                                            & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)))));
    bufp->fullBit(oldp+520,((0x23U == (0x707fU & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)))));
    bufp->fullBit(oldp+521,((0x1023U == (0x707fU & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)))));
    bufp->fullBit(oldp+522,((0x1033U == (0xfe00707fU 
                                         & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)))));
    bufp->fullBit(oldp+523,((0x1013U == (0xfc00707fU 
                                         & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)))));
    bufp->fullBit(oldp+524,((0x2033U == (0xfe00707fU 
                                         & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)))));
    bufp->fullBit(oldp+525,((0x2013U == (0x707fU & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)))));
    bufp->fullBit(oldp+526,((0x3013U == (0x707fU & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)))));
    bufp->fullBit(oldp+527,((0x3033U == (0xfe00707fU 
                                         & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)))));
    bufp->fullBit(oldp+528,((0x40005033U == (0xfe00707fU 
                                             & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)))));
    bufp->fullBit(oldp+529,((0x40005013U == (0xfc00707fU 
                                             & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)))));
    bufp->fullBit(oldp+530,((0x5033U == (0xfe00707fU 
                                         & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)))));
    bufp->fullBit(oldp+531,((0x5013U == (0xfc00707fU 
                                         & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)))));
    bufp->fullBit(oldp+532,((0x40000033U == (0xfe00707fU 
                                             & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)))));
    bufp->fullBit(oldp+533,((0x2023U == (0x707fU & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)))));
    bufp->fullBit(oldp+534,((0x10500073U == (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata))));
    bufp->fullBit(oldp+535,((0x4033U == (0xfe00707fU 
                                         & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)))));
    bufp->fullBit(oldp+536,((0x4013U == (0x707fU & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)))));
    bufp->fullBit(oldp+537,(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__is_JUMP_CONDITIONAL));
    bufp->fullBit(oldp+538,(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__is_I));
    bufp->fullBit(oldp+539,(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__is_R));
    bufp->fullBit(oldp+540,(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__have_RS3));
    bufp->fullBit(oldp+541,(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__is_S));
    bufp->fullBit(oldp+542,(((0x17U == (0x7fU & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata))) 
                             | (0x37U == (0x7fU & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata))))));
    bufp->fullBit(oldp+543,(((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT____VdfgRegularize_hef2daed4_0_20) 
                             | (0x30200073U == (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)))));
    bufp->fullBit(oldp+544,(((0x33U == (0xfe00707fU 
                                        & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata))) 
                             | ((0x13U == (0x707fU 
                                           & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata))) 
                                | ((0x7033U == (0xfe00707fU 
                                                & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata))) 
                                   | ((0x7013U == (0x707fU 
                                                   & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata))) 
                                      | ((0x17U == 
                                          (0x7fU & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata))) 
                                         | ((0x37U 
                                             == (0x7fU 
                                                 & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata))) 
                                            | ((0x6033U 
                                                == 
                                                (0xfe00707fU 
                                                 & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata))) 
                                               | ((0x6013U 
                                                   == 
                                                   (0x707fU 
                                                    & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata))) 
                                                  | ((0x40000033U 
                                                      == 
                                                      (0xfe00707fU 
                                                       & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata))) 
                                                     | ((0x4033U 
                                                         == 
                                                         (0xfe00707fU 
                                                          & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata))) 
                                                        | (0x4013U 
                                                           == 
                                                           (0x707fU 
                                                            & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)))))))))))))));
    bufp->fullBit(oldp+545,(((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT____VdfgRegularize_hef2daed4_0_8) 
                             | ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT____VdfgRegularize_hef2daed4_0_19) 
                                | (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT____VdfgRegularize_hef2daed4_0_18)))));
    bufp->fullBit(oldp+546,(((0x2033U == (0xfe00707fU 
                                          & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata))) 
                             | ((0x2013U == (0x707fU 
                                             & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata))) 
                                | ((0x3013U == (0x707fU 
                                                & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata))) 
                                   | (0x3033U == (0xfe00707fU 
                                                  & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata))))))));
    bufp->fullBit(oldp+547,(((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT____VdfgRegularize_hef2daed4_0_20) 
                             | ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT____VdfgRegularize_hef2daed4_0_17) 
                                | ((0x100073U == (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)) 
                                   | ((0x73U == (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)) 
                                      | ((0xfU == (0x707fU 
                                                   & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata))) 
                                         | ((0x2000033U 
                                             == (0xfe00707fU 
                                                 & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata))) 
                                            | ((0x2001033U 
                                                == 
                                                (0xfe00707fU 
                                                 & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata))) 
                                               | ((0x2003033U 
                                                   == 
                                                   (0xfe00707fU 
                                                    & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata))) 
                                                  | ((0x30200073U 
                                                      == (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)) 
                                                     | ((0x2006033U 
                                                         == 
                                                         (0xfe00707fU 
                                                          & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata))) 
                                                        | ((0x2007033U 
                                                            == 
                                                            (0xfe00707fU 
                                                             & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata))) 
                                                           | (0x10500073U 
                                                              == (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)))))))))))))));
    bufp->fullBit(oldp+548,(((0x6fU == (0x7fU & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata))) 
                             | (0x67U == (0x707fU & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata))))));
    bufp->fullBit(oldp+549,(((3U == (0x707fU & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata))) 
                             | ((0x4003U == (0x707fU 
                                             & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata))) 
                                | ((0x1003U == (0x707fU 
                                                & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata))) 
                                   | ((0x5003U == (0x707fU 
                                                   & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata))) 
                                      | ((0x2003U == 
                                          (0x707fU 
                                           & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata))) 
                                         | (IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_8_0))))))));
    bufp->fullBit(oldp+550,(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__is_FPU));
    bufp->fullBit(oldp+551,(((0x2007U == (0x707fU & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata))) 
                             | (0x2027U == (0x707fU 
                                            & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata))))));
    bufp->fullBit(oldp+552,(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__RD_bank));
    bufp->fullBit(oldp+553,(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__RS1_bank));
    bufp->fullBit(oldp+554,(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__RS2_bank));
    bufp->fullBit(oldp+555,(vlSelfRef.CPU_top__DOT__cpu__DOT____Vcellinp__fetch__i_busy));
    bufp->fullCData(oldp+556,(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__state),2);
    bufp->fullIData(oldp+557,(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__pc),32);
    bufp->fullIData(oldp+558,((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)),32);
    bufp->fullBit(oldp+559,(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__icache_ready));
    bufp->fullBit(oldp+560,(((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__is_JUMP_CONDITIONAL) 
                             | ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__is_I) 
                                | ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__is_R) 
                                   | ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__is_S) 
                                      | (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT____VdfgRegularize_hef2daed4_0_14)))))));
    bufp->fullBit(oldp+561,(((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__is_JUMP_CONDITIONAL) 
                             | ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__is_R) 
                                | ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__is_S) 
                                   | (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__have_RS3))))));
    bufp->fullBit(oldp+562,(((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__is_I) 
                             | ((0x6fU == (0x7fU & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata))) 
                                | ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__is_R) 
                                   | (((0x17U == (0x7fU 
                                                  & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata))) 
                                       | (0x37U == 
                                          (0x7fU & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)))) 
                                      | (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT____VdfgRegularize_hef2daed4_0_14)))))));
    bufp->fullBit(oldp+563,(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__irq_pending_r));
    bufp->fullBit(oldp+564,(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT__initialized));
    bufp->fullIData(oldp+565,(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT__clear_set),32);
    bufp->fullBit(oldp+566,(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT__cache_invalid));
    bufp->fullSData(oldp+567,((0xfffU & (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__pc 
                                         >> 2U))),12);
    bufp->fullIData(oldp+568,((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__pc 
                               >> 0xeU)),18);
    bufp->fullSData(oldp+569,(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT__cache_rd_set),12);
    bufp->fullBit(oldp+570,((1U & (IData)((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata 
                                           >> 0x32U)))));
    bufp->fullIData(oldp+571,((0x3ffffU & (IData)((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata 
                                                   >> 0x20U)))),18);
    bufp->fullIData(oldp+572,((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)),32);
    bufp->fullBit(oldp+573,(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT__cache_wr_request));
    bufp->fullSData(oldp+574,(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT__cache_wr_set),12);
    bufp->fullBit(oldp+575,((1U & (IData)((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT__cache_wr_wdata 
                                           >> 0x32U)))));
    bufp->fullIData(oldp+576,((0x3ffffU & (IData)((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT__cache_wr_wdata 
                                                   >> 0x20U)))),18);
    bufp->fullIData(oldp+577,((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT__cache_wr_wdata)),32);
    bufp->fullSData(oldp+578,(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT__set_r),12);
    bufp->fullIData(oldp+579,(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT__cache_rd_set),32);
    bufp->fullQData(oldp+580,(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata),51);
    bufp->fullBit(oldp+582,(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT__cache__DOT__o_pa_ready));
    bufp->fullIData(oldp+583,(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT__cache_wr_set),32);
    bufp->fullQData(oldp+584,(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT__cache_wr_wdata),51);
    bufp->fullBit(oldp+586,(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT__cache__DOT__o_pb_ready));
    bufp->fullWData(oldp+587,(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__data),117);
    bufp->fullWData(oldp+591,(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_skid__DOT__r_data),117);
    bufp->fullBit(oldp+595,(vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__dcache_rw));
    bufp->fullBit(oldp+596,(vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__dcache_request));
    bufp->fullBit(oldp+597,(vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__dcache_flush));
    bufp->fullBit(oldp+598,(vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__dcache_ready));
    bufp->fullIData(oldp+599,((0xfffffffcU & ((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__data[1U] 
                                               << 0x1bU) 
                                              | (0x7fffffcU 
                                                 & (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__data[0U] 
                                                    >> 5U))))),32);
    bufp->fullIData(oldp+600,(vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__dcache_rdata),32);
    bufp->fullIData(oldp+601,(vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__dcache_wdata),32);
    bufp->fullBit(oldp+602,((2U == (0xfU & (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__data[1U] 
                                            >> 1U)))));
    bufp->fullCData(oldp+603,((3U & (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__data[0U] 
                                     >> 5U))),2);
    bufp->fullCData(oldp+604,((0xffU & vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT____VdfgRegularize_h9eb5ee7c_0_0)),8);
    bufp->fullSData(oldp+605,((0xffffU & vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT____VdfgRegularize_h9eb5ee7c_0_0)),16);
    bufp->fullCData(oldp+606,(vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__state),3);
    bufp->fullIData(oldp+607,(vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__rmw_rdata),32);
    bufp->fullBit(oldp+608,(vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__last_strobe));
    bufp->fullCData(oldp+609,(vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__genblk1__DOT__dcache__DOT__state),4);
    bufp->fullSData(oldp+610,(vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__genblk1__DOT__dcache__DOT__flush_address),13);
    bufp->fullBit(oldp+611,(vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__genblk1__DOT__dcache__DOT__wb_rw));
    bufp->fullBit(oldp+612,(vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__genblk1__DOT__dcache__DOT__wb_request));
    bufp->fullIData(oldp+613,(vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__genblk1__DOT__dcache__DOT__wb_address),32);
    bufp->fullIData(oldp+614,(vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__genblk1__DOT__dcache__DOT__wb_wdata),32);
    bufp->fullBit(oldp+615,(vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__genblk1__DOT__dcache__DOT__cache_rw));
    bufp->fullSData(oldp+616,(vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__genblk1__DOT__dcache__DOT__cache_address),12);
    bufp->fullQData(oldp+617,(vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__genblk1__DOT__dcache__DOT__cache_wdata),64);
    bufp->fullQData(oldp+619,(vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__genblk1__DOT__dcache__DOT__cache_rdata),64);
    bufp->fullBit(oldp+621,((1U & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__genblk1__DOT__dcache__DOT__cache_rdata))));
    bufp->fullBit(oldp+622,((1U & (IData)((vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__genblk1__DOT__dcache__DOT__cache_rdata 
                                           >> 1U)))));
    bufp->fullIData(oldp+623,(((IData)((vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__genblk1__DOT__dcache__DOT__cache_rdata 
                                        >> 2U)) << 2U)),32);
    bufp->fullIData(oldp+624,((IData)((vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__genblk1__DOT__dcache__DOT__cache_rdata 
                                       >> 0x20U))),32);
    bufp->fullIData(oldp+625,(vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__genblk1__DOT__dcache__DOT__cache_address),32);
    bufp->fullBit(oldp+626,(vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__genblk1__DOT__dcache__DOT__cache__DOT__o_ready));
    bufp->fullBit(oldp+627,(vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__genblk1__DOT__dcache__DOT__cache__DOT__o_valid));
    bufp->fullBit(oldp+628,(vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__genblk1__DOT__dcache__DOT__wb__DOT__wb_dirty));
    bufp->fullIData(oldp+629,(vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__genblk1__DOT__dcache__DOT__wb__DOT__wb_address),32);
    bufp->fullIData(oldp+630,(vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__genblk1__DOT__dcache__DOT__wb__DOT__next_wb_address),32);
    bufp->fullIData(oldp+631,(vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__genblk1__DOT__dcache__DOT__wb__DOT__next_wb_data),32);
    bufp->fullBit(oldp+632,(vlSelfRef.CPU_top__DOT__cpu__DOT__writeback__DOT__last_strobe));
    bufp->fullIData(oldp+633,(vlSelfRef.CPU_top__DOT__cpu__DOT__writeback__DOT__last_pc),32);
    bufp->fullIData(oldp+634,(vlSelfRef.CPU_top__DOT__cpu__DOT__registers__DOT__rs1),32);
    bufp->fullIData(oldp+635,(vlSelfRef.CPU_top__DOT__cpu__DOT__registers__DOT__rs2),32);
    bufp->fullIData(oldp+636,(vlSelfRef.CPU_top__DOT__cpu__DOT__registers__DOT__rs3),32);
    bufp->fullBit(oldp+637,(vlSelfRef.CPU_top__DOT__cpu__DOT__registers__DOT__last_write_strobe));
    bufp->fullIData(oldp+638,(vlSelfRef.CPU_top__DOT__cpu__DOT__registers__DOT__r[0]),32);
    bufp->fullIData(oldp+639,(vlSelfRef.CPU_top__DOT__cpu__DOT__registers__DOT__r[1]),32);
    bufp->fullIData(oldp+640,(vlSelfRef.CPU_top__DOT__cpu__DOT__registers__DOT__r[2]),32);
    bufp->fullIData(oldp+641,(vlSelfRef.CPU_top__DOT__cpu__DOT__registers__DOT__r[3]),32);
    bufp->fullIData(oldp+642,(vlSelfRef.CPU_top__DOT__cpu__DOT__registers__DOT__r[4]),32);
    bufp->fullIData(oldp+643,(vlSelfRef.CPU_top__DOT__cpu__DOT__registers__DOT__r[5]),32);
    bufp->fullIData(oldp+644,(vlSelfRef.CPU_top__DOT__cpu__DOT__registers__DOT__r[6]),32);
    bufp->fullIData(oldp+645,(vlSelfRef.CPU_top__DOT__cpu__DOT__registers__DOT__r[7]),32);
    bufp->fullIData(oldp+646,(vlSelfRef.CPU_top__DOT__cpu__DOT__registers__DOT__r[8]),32);
    bufp->fullIData(oldp+647,(vlSelfRef.CPU_top__DOT__cpu__DOT__registers__DOT__r[9]),32);
    bufp->fullIData(oldp+648,(vlSelfRef.CPU_top__DOT__cpu__DOT__registers__DOT__r[10]),32);
    bufp->fullIData(oldp+649,(vlSelfRef.CPU_top__DOT__cpu__DOT__registers__DOT__r[11]),32);
    bufp->fullIData(oldp+650,(vlSelfRef.CPU_top__DOT__cpu__DOT__registers__DOT__r[12]),32);
    bufp->fullIData(oldp+651,(vlSelfRef.CPU_top__DOT__cpu__DOT__registers__DOT__r[13]),32);
    bufp->fullIData(oldp+652,(vlSelfRef.CPU_top__DOT__cpu__DOT__registers__DOT__r[14]),32);
    bufp->fullIData(oldp+653,(vlSelfRef.CPU_top__DOT__cpu__DOT__registers__DOT__r[15]),32);
    bufp->fullIData(oldp+654,(vlSelfRef.CPU_top__DOT__cpu__DOT__registers__DOT__r[16]),32);
    bufp->fullIData(oldp+655,(vlSelfRef.CPU_top__DOT__cpu__DOT__registers__DOT__r[17]),32);
    bufp->fullIData(oldp+656,(vlSelfRef.CPU_top__DOT__cpu__DOT__registers__DOT__r[18]),32);
    bufp->fullIData(oldp+657,(vlSelfRef.CPU_top__DOT__cpu__DOT__registers__DOT__r[19]),32);
    bufp->fullIData(oldp+658,(vlSelfRef.CPU_top__DOT__cpu__DOT__registers__DOT__r[20]),32);
    bufp->fullIData(oldp+659,(vlSelfRef.CPU_top__DOT__cpu__DOT__registers__DOT__r[21]),32);
    bufp->fullIData(oldp+660,(vlSelfRef.CPU_top__DOT__cpu__DOT__registers__DOT__r[22]),32);
    bufp->fullIData(oldp+661,(vlSelfRef.CPU_top__DOT__cpu__DOT__registers__DOT__r[23]),32);
    bufp->fullIData(oldp+662,(vlSelfRef.CPU_top__DOT__cpu__DOT__registers__DOT__r[24]),32);
    bufp->fullIData(oldp+663,(vlSelfRef.CPU_top__DOT__cpu__DOT__registers__DOT__r[25]),32);
    bufp->fullIData(oldp+664,(vlSelfRef.CPU_top__DOT__cpu__DOT__registers__DOT__r[26]),32);
    bufp->fullIData(oldp+665,(vlSelfRef.CPU_top__DOT__cpu__DOT__registers__DOT__r[27]),32);
    bufp->fullIData(oldp+666,(vlSelfRef.CPU_top__DOT__cpu__DOT__registers__DOT__r[28]),32);
    bufp->fullIData(oldp+667,(vlSelfRef.CPU_top__DOT__cpu__DOT__registers__DOT__r[29]),32);
    bufp->fullIData(oldp+668,(vlSelfRef.CPU_top__DOT__cpu__DOT__registers__DOT__r[30]),32);
    bufp->fullIData(oldp+669,(vlSelfRef.CPU_top__DOT__cpu__DOT__registers__DOT__r[31]),32);
    bufp->fullIData(oldp+670,(vlSelfRef.CPU_top__DOT__cpu__DOT__registers__DOT__I),32);
    bufp->fullBit(oldp+671,((1U & (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                   >> 0x14U))));
    bufp->fullIData(oldp+672,(((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                << 0xcU) | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                            >> 0x14U))),32);
    bufp->fullIData(oldp+673,(((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                << 0xcU) | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[1U] 
                                            >> 0x14U))),32);
    bufp->fullCData(oldp+674,((0x1fU & (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[1U] 
                                        >> 0xfU))),5);
    bufp->fullCData(oldp+675,((0x1fU & (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[1U] 
                                        >> 0xaU))),5);
    bufp->fullCData(oldp+676,((0x1fU & (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[1U] 
                                        >> 5U))),5);
    bufp->fullCData(oldp+677,((0x1fU & vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[1U])),5);
    bufp->fullIData(oldp+678,(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[0U]),32);
    bufp->fullBit(oldp+679,((1U & (vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__data[2U] 
                                   >> 5U))));
    bufp->fullIData(oldp+680,(((vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__data[2U] 
                                << 0x1bU) | (vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__data[1U] 
                                             >> 5U))),32);
    bufp->fullCData(oldp+681,((0x1fU & vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__data[1U])),5);
    bufp->fullIData(oldp+682,(vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__data[0U]),32);
    bufp->fullBit(oldp+683,(((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__is_B) 
                             | ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__is_I) 
                                | ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__is_R) 
                                   | ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__is_S) 
                                      | (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT____VdfgRegularize_h2cfc3394_0_18)))))));
    bufp->fullBit(oldp+684,(((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__is_B) 
                             | ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__is_R) 
                                | ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__is_S) 
                                   | (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__have_RS3))))));
    bufp->fullBit(oldp+685,(vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__have_RS3));
    bufp->fullBit(oldp+686,(((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__is_I) 
                             | ((0x6fU == (0x7fU & 
                                           (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                            >> 0x14U))) 
                                | ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__is_R) 
                                   | ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__is_U) 
                                      | (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT____VdfgRegularize_h2cfc3394_0_18)))))));
    bufp->fullIData(oldp+687,((((- (IData)((1U & (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                  >> 0x13U)))) 
                                << 0xcU) | ((0x800U 
                                             & (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                >> 0x10U)) 
                                            | ((0x7e0U 
                                                & (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                   >> 8U)) 
                                               | (0x1eU 
                                                  & (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                     >> 0x1bU)))))),32);
    bufp->fullIData(oldp+688,((((- (IData)((1U & (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                  >> 0x13U)))) 
                                << 0xbU) | (0x7ffU 
                                            & (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                               >> 8U)))),32);
    bufp->fullIData(oldp+689,((((- (IData)((1U & (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                  >> 0x13U)))) 
                                << 0x14U) | (((0xff000U 
                                               & (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                  << 0xcU)) 
                                              | (0x800U 
                                                 & (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                    << 3U))) 
                                             | (0x7feU 
                                                & (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                   >> 8U))))),32);
    bufp->fullIData(oldp+690,((((- (IData)((1U & (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                  >> 0x13U)))) 
                                << 0xbU) | ((0x7e0U 
                                             & (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                >> 8U)) 
                                            | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                               >> 0x1bU)))),32);
    bufp->fullIData(oldp+691,((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                               << 0xcU)),32);
    bufp->fullIData(oldp+692,((0x3fU & (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                        >> 8U))),32);
    bufp->fullIData(oldp+693,((0xfffU & (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                         >> 8U))),32);
    bufp->fullBit(oldp+694,((0x33U == (0xfe00707fU 
                                       & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                           << 0xcU) 
                                          | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                             >> 0x14U))))));
    bufp->fullBit(oldp+695,((0x13U == (0x707fU & ((
                                                   vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                   << 0xcU) 
                                                  | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                     >> 0x14U))))));
    bufp->fullBit(oldp+696,((0x7033U == (0xfe00707fU 
                                         & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                             << 0xcU) 
                                            | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                               >> 0x14U))))));
    bufp->fullBit(oldp+697,((0x7013U == (0x707fU & 
                                         ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                           << 0xcU) 
                                          | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                             >> 0x14U))))));
    bufp->fullBit(oldp+698,((0x17U == (0x7fU & (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                >> 0x14U)))));
    bufp->fullBit(oldp+699,((0x63U == (0x707fU & ((
                                                   vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                   << 0xcU) 
                                                  | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                     >> 0x14U))))));
    bufp->fullBit(oldp+700,((0x5063U == (0x707fU & 
                                         ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                           << 0xcU) 
                                          | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                             >> 0x14U))))));
    bufp->fullBit(oldp+701,((0x7063U == (0x707fU & 
                                         ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                           << 0xcU) 
                                          | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                             >> 0x14U))))));
    bufp->fullBit(oldp+702,((0x4063U == (0x707fU & 
                                         ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                           << 0xcU) 
                                          | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                             >> 0x14U))))));
    bufp->fullBit(oldp+703,((0x6063U == (0x707fU & 
                                         ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                           << 0xcU) 
                                          | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                             >> 0x14U))))));
    bufp->fullBit(oldp+704,((0x1063U == (0x707fU & 
                                         ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                           << 0xcU) 
                                          | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                             >> 0x14U))))));
    bufp->fullBit(oldp+705,((0x3073U == (0x707fU & 
                                         ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                           << 0xcU) 
                                          | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                             >> 0x14U))))));
    bufp->fullBit(oldp+706,((0x2073U == (0x707fU & 
                                         ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                           << 0xcU) 
                                          | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                             >> 0x14U))))));
    bufp->fullBit(oldp+707,((0x1073U == (0x707fU & 
                                         ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                           << 0xcU) 
                                          | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                             >> 0x14U))))));
    bufp->fullBit(oldp+708,((0x2004033U == (0xfe00707fU 
                                            & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                << 0xcU) 
                                               | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                  >> 0x14U))))));
    bufp->fullBit(oldp+709,((0x2005033U == (0xfe00707fU 
                                            & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                << 0xcU) 
                                               | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                  >> 0x14U))))));
    bufp->fullBit(oldp+710,((0x100073U == ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                            << 0xcU) 
                                           | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                              >> 0x14U)))));
    bufp->fullBit(oldp+711,((0x73U == ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                        << 0xcU) | 
                                       (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                        >> 0x14U)))));
    bufp->fullBit(oldp+712,((0x53U == (0xfe00007fU 
                                       & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                           << 0xcU) 
                                          | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                             >> 0x14U))))));
    bufp->fullBit(oldp+713,((0xc0000053U == (0xfff0007fU 
                                             & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                 << 0xcU) 
                                                | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                   >> 0x14U))))));
    bufp->fullBit(oldp+714,((0xc0100053U == (0xfff0007fU 
                                             & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                 << 0xcU) 
                                                | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                   >> 0x14U))))));
    bufp->fullBit(oldp+715,((0xd0000053U == (0xfff0007fU 
                                             & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                 << 0xcU) 
                                                | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                   >> 0x14U))))));
    bufp->fullBit(oldp+716,((0xd0100053U == (0xfff0007fU 
                                             & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                 << 0xcU) 
                                                | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                   >> 0x14U))))));
    bufp->fullBit(oldp+717,((0x18000053U == (0xfe00007fU 
                                             & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                 << 0xcU) 
                                                | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                   >> 0x14U))))));
    bufp->fullBit(oldp+718,((0xfU == (0x707fU & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                  << 0xcU) 
                                                 | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                    >> 0x14U))))));
    bufp->fullBit(oldp+719,((0xa0002053U == (0xfe00707fU 
                                             & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                 << 0xcU) 
                                                | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                   >> 0x14U))))));
    bufp->fullBit(oldp+720,((0xa0000053U == (0xfe00707fU 
                                             & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                 << 0xcU) 
                                                | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                   >> 0x14U))))));
    bufp->fullBit(oldp+721,((0xa0001053U == (0xfe00707fU 
                                             & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                 << 0xcU) 
                                                | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                   >> 0x14U))))));
    bufp->fullBit(oldp+722,((0x2007U == (0x707fU & 
                                         ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                           << 0xcU) 
                                          | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                             >> 0x14U))))));
    bufp->fullBit(oldp+723,((0x43U == (0x600007fU & 
                                       ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                         << 0xcU) | 
                                        (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                         >> 0x14U))))));
    bufp->fullBit(oldp+724,((0x47U == (0x600007fU & 
                                       ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                         << 0xcU) | 
                                        (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                         >> 0x14U))))));
    bufp->fullBit(oldp+725,((0x4fU == (0x600007fU & 
                                       ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                         << 0xcU) | 
                                        (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                         >> 0x14U))))));
    bufp->fullBit(oldp+726,((0x4bU == (0x600007fU & 
                                       ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                         << 0xcU) | 
                                        (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                         >> 0x14U))))));
    bufp->fullBit(oldp+727,((0x28000053U == (0xfe00707fU 
                                             & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                 << 0xcU) 
                                                | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                   >> 0x14U))))));
    bufp->fullBit(oldp+728,((0x28001053U == (0xfe00707fU 
                                             & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                 << 0xcU) 
                                                | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                   >> 0x14U))))));
    bufp->fullBit(oldp+729,((0x10000053U == (0xfe00007fU 
                                             & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                 << 0xcU) 
                                                | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                   >> 0x14U))))));
    bufp->fullBit(oldp+730,((0xe0000053U == (0xfff0707fU 
                                             & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                 << 0xcU) 
                                                | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                   >> 0x14U))))));
    bufp->fullBit(oldp+731,((0xf0000053U == (0xfff0707fU 
                                             & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                 << 0xcU) 
                                                | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                   >> 0x14U))))));
    bufp->fullBit(oldp+732,((0x20000053U == (0xfe00707fU 
                                             & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                 << 0xcU) 
                                                | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                   >> 0x14U))))));
    bufp->fullBit(oldp+733,((0x20001053U == (0xfe00707fU 
                                             & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                 << 0xcU) 
                                                | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                   >> 0x14U))))));
    bufp->fullBit(oldp+734,((0x20002053U == (0xfe00707fU 
                                             & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                 << 0xcU) 
                                                | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                   >> 0x14U))))));
    bufp->fullBit(oldp+735,((0x8000053U == (0xfe00007fU 
                                            & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                << 0xcU) 
                                               | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                  >> 0x14U))))));
    bufp->fullBit(oldp+736,((0x2027U == (0x707fU & 
                                         ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                           << 0xcU) 
                                          | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                             >> 0x14U))))));
    bufp->fullBit(oldp+737,((0x6fU == (0x7fU & (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                >> 0x14U)))));
    bufp->fullBit(oldp+738,((0x67U == (0x707fU & ((
                                                   vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                   << 0xcU) 
                                                  | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                     >> 0x14U))))));
    bufp->fullBit(oldp+739,((3U == (0x707fU & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                << 0xcU) 
                                               | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                  >> 0x14U))))));
    bufp->fullBit(oldp+740,((0x4003U == (0x707fU & 
                                         ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                           << 0xcU) 
                                          | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                             >> 0x14U))))));
    bufp->fullBit(oldp+741,((0x1003U == (0x707fU & 
                                         ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                           << 0xcU) 
                                          | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                             >> 0x14U))))));
    bufp->fullBit(oldp+742,((0x5003U == (0x707fU & 
                                         ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                           << 0xcU) 
                                          | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                             >> 0x14U))))));
    bufp->fullBit(oldp+743,((0x37U == (0x7fU & (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                >> 0x14U)))));
    bufp->fullBit(oldp+744,((0x2003U == (0x707fU & 
                                         ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                           << 0xcU) 
                                          | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                             >> 0x14U))))));
    bufp->fullBit(oldp+745,((0x2000033U == (0xfe00707fU 
                                            & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                << 0xcU) 
                                               | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                  >> 0x14U))))));
    bufp->fullBit(oldp+746,((0x2001033U == (0xfe00707fU 
                                            & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                << 0xcU) 
                                               | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                  >> 0x14U))))));
    bufp->fullBit(oldp+747,((0x2003033U == (0xfe00707fU 
                                            & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                << 0xcU) 
                                               | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                  >> 0x14U))))));
    bufp->fullBit(oldp+748,((0x30200073U == ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                              << 0xcU) 
                                             | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                >> 0x14U)))));
    bufp->fullBit(oldp+749,((0x6033U == (0xfe00707fU 
                                         & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                             << 0xcU) 
                                            | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                               >> 0x14U))))));
    bufp->fullBit(oldp+750,((0x6013U == (0x707fU & 
                                         ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                           << 0xcU) 
                                          | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                             >> 0x14U))))));
    bufp->fullBit(oldp+751,((0x2006033U == (0xfe00707fU 
                                            & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                << 0xcU) 
                                               | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                  >> 0x14U))))));
    bufp->fullBit(oldp+752,((0x2007033U == (0xfe00707fU 
                                            & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                << 0xcU) 
                                               | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                  >> 0x14U))))));
    bufp->fullBit(oldp+753,((0x23U == (0x707fU & ((
                                                   vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                   << 0xcU) 
                                                  | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                     >> 0x14U))))));
    bufp->fullBit(oldp+754,((0x1023U == (0x707fU & 
                                         ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                           << 0xcU) 
                                          | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                             >> 0x14U))))));
    bufp->fullBit(oldp+755,((0x1033U == (0xfe00707fU 
                                         & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                             << 0xcU) 
                                            | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                               >> 0x14U))))));
    bufp->fullBit(oldp+756,((0x1013U == (0xfc00707fU 
                                         & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                             << 0xcU) 
                                            | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                               >> 0x14U))))));
    bufp->fullBit(oldp+757,((0x2033U == (0xfe00707fU 
                                         & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                             << 0xcU) 
                                            | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                               >> 0x14U))))));
    bufp->fullBit(oldp+758,((0x2013U == (0x707fU & 
                                         ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                           << 0xcU) 
                                          | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                             >> 0x14U))))));
    bufp->fullBit(oldp+759,((0x3013U == (0x707fU & 
                                         ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                           << 0xcU) 
                                          | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                             >> 0x14U))))));
    bufp->fullBit(oldp+760,((0x3033U == (0xfe00707fU 
                                         & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                             << 0xcU) 
                                            | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                               >> 0x14U))))));
    bufp->fullBit(oldp+761,((0x40005033U == (0xfe00707fU 
                                             & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                 << 0xcU) 
                                                | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                   >> 0x14U))))));
    bufp->fullBit(oldp+762,((0x40005013U == (0xfc00707fU 
                                             & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                 << 0xcU) 
                                                | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                   >> 0x14U))))));
    bufp->fullBit(oldp+763,((0x5033U == (0xfe00707fU 
                                         & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                             << 0xcU) 
                                            | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                               >> 0x14U))))));
    bufp->fullBit(oldp+764,((0x5013U == (0xfc00707fU 
                                         & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                             << 0xcU) 
                                            | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                               >> 0x14U))))));
    bufp->fullBit(oldp+765,((0x40000033U == (0xfe00707fU 
                                             & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                 << 0xcU) 
                                                | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                   >> 0x14U))))));
    bufp->fullBit(oldp+766,((0x2023U == (0x707fU & 
                                         ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                           << 0xcU) 
                                          | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                             >> 0x14U))))));
    bufp->fullBit(oldp+767,((0x10500073U == ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                              << 0xcU) 
                                             | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                >> 0x14U)))));
    bufp->fullBit(oldp+768,((0x4033U == (0xfe00707fU 
                                         & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                             << 0xcU) 
                                            | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                               >> 0x14U))))));
    bufp->fullBit(oldp+769,((0x4013U == (0x707fU & 
                                         ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                           << 0xcU) 
                                          | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                             >> 0x14U))))));
    bufp->fullBit(oldp+770,(vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__is_B));
    bufp->fullBit(oldp+771,(vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__is_I));
    bufp->fullBit(oldp+772,(vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__is_R));
    bufp->fullBit(oldp+773,(vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__is_S));
    bufp->fullBit(oldp+774,(vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__is_U));
    bufp->fullBit(oldp+775,(vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__is_CSR));
    bufp->fullBit(oldp+776,(((0x33U == (0xfe00707fU 
                                        & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                            << 0xcU) 
                                           | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                              >> 0x14U)))) 
                             | ((0x13U == (0x707fU 
                                           & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                               << 0xcU) 
                                              | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                 >> 0x14U)))) 
                                | ((0x7033U == (0xfe00707fU 
                                                & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                    << 0xcU) 
                                                   | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                      >> 0x14U)))) 
                                   | ((0x7013U == (0x707fU 
                                                   & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                       << 0xcU) 
                                                      | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                         >> 0x14U)))) 
                                      | ((0x17U == 
                                          (0x7fU & 
                                           (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                            >> 0x14U))) 
                                         | ((0x37U 
                                             == (0x7fU 
                                                 & (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                    >> 0x14U))) 
                                            | ((0x6033U 
                                                == 
                                                (0xfe00707fU 
                                                 & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                     << 0xcU) 
                                                    | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                       >> 0x14U)))) 
                                               | ((0x6013U 
                                                   == 
                                                   (0x707fU 
                                                    & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                        << 0xcU) 
                                                       | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                          >> 0x14U)))) 
                                                  | ((0x40000033U 
                                                      == 
                                                      (0xfe00707fU 
                                                       & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                           << 0xcU) 
                                                          | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                             >> 0x14U)))) 
                                                     | ((0x4033U 
                                                         == 
                                                         (0xfe00707fU 
                                                          & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                              << 0xcU) 
                                                             | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                                >> 0x14U)))) 
                                                        | (0x4013U 
                                                           == 
                                                           (0x707fU 
                                                            & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                                << 0xcU) 
                                                               | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                                  >> 0x14U))))))))))))))));
    bufp->fullBit(oldp+777,(((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT____VdfgRegularize_h2cfc3394_0_9) 
                             | ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT____VdfgRegularize_h2cfc3394_0_25) 
                                | (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT____VdfgRegularize_h2cfc3394_0_24)))));
    bufp->fullBit(oldp+778,(((0x2033U == (0xfe00707fU 
                                          & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                              << 0xcU) 
                                             | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                >> 0x14U)))) 
                             | ((0x2013U == (0x707fU 
                                             & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                 << 0xcU) 
                                                | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                   >> 0x14U)))) 
                                | ((0x3013U == (0x707fU 
                                                & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                    << 0xcU) 
                                                   | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                      >> 0x14U)))) 
                                   | (0x3033U == (0xfe00707fU 
                                                  & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                      << 0xcU) 
                                                     | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                        >> 0x14U)))))))));
    bufp->fullBit(oldp+779,(((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT____VdfgRegularize_h2cfc3394_0_26) 
                             | ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT____VdfgRegularize_h2cfc3394_0_23) 
                                | ((0x100073U == ((
                                                   vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                   << 0xcU) 
                                                  | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                     >> 0x14U))) 
                                   | ((0x73U == ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                  << 0xcU) 
                                                 | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                    >> 0x14U))) 
                                      | ((0xfU == (0x707fU 
                                                   & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                       << 0xcU) 
                                                      | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                         >> 0x14U)))) 
                                         | ((0x2000033U 
                                             == (0xfe00707fU 
                                                 & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                     << 0xcU) 
                                                    | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                       >> 0x14U)))) 
                                            | ((0x2001033U 
                                                == 
                                                (0xfe00707fU 
                                                 & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                     << 0xcU) 
                                                    | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                       >> 0x14U)))) 
                                               | ((0x2003033U 
                                                   == 
                                                   (0xfe00707fU 
                                                    & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                        << 0xcU) 
                                                       | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                          >> 0x14U)))) 
                                                  | ((0x30200073U 
                                                      == 
                                                      ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                        << 0xcU) 
                                                       | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                          >> 0x14U))) 
                                                     | ((0x2006033U 
                                                         == 
                                                         (0xfe00707fU 
                                                          & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                              << 0xcU) 
                                                             | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                                >> 0x14U)))) 
                                                        | ((0x2007033U 
                                                            == 
                                                            (0xfe00707fU 
                                                             & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                                 << 0xcU) 
                                                                | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                                   >> 0x14U)))) 
                                                           | (0x10500073U 
                                                              == 
                                                              ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                                << 0xcU) 
                                                               | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                                  >> 0x14U))))))))))))))));
    bufp->fullBit(oldp+780,(((0x6fU == (0x7fU & (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                 >> 0x14U))) 
                             | (0x67U == (0x707fU & 
                                          ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                            << 0xcU) 
                                           | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                              >> 0x14U)))))));
    bufp->fullBit(oldp+781,(((3U == (0x707fU & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                 << 0xcU) 
                                                | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                   >> 0x14U)))) 
                             | ((0x4003U == (0x707fU 
                                             & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                 << 0xcU) 
                                                | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                   >> 0x14U)))) 
                                | ((0x1003U == (0x707fU 
                                                & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                    << 0xcU) 
                                                   | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                      >> 0x14U)))) 
                                   | ((0x5003U == (0x707fU 
                                                   & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                       << 0xcU) 
                                                      | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                         >> 0x14U)))) 
                                      | ((0x2003U == 
                                          (0x707fU 
                                           & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                               << 0xcU) 
                                              | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                 >> 0x14U)))) 
                                         | (IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_3_0))))))));
    bufp->fullBit(oldp+782,(vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__is_FPU));
    bufp->fullBit(oldp+783,(((0x2007U == (0x707fU & 
                                          ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                            << 0xcU) 
                                           | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                              >> 0x14U)))) 
                             | (0x2027U == (0x707fU 
                                            & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                << 0xcU) 
                                               | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                  >> 0x14U)))))));
    bufp->fullBit(oldp+784,(vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__RD_bank));
    bufp->fullBit(oldp+785,(vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__RS1_bank));
    bufp->fullBit(oldp+786,(vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__RS2_bank));
    bufp->fullCData(oldp+787,(vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__alu_operation),4);
    bufp->fullCData(oldp+788,(((0x17U == (0x7fU & (
                                                   vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                   >> 0x14U)))
                                ? 8U : ((0x6fU == (0x7fU 
                                                   & (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                      >> 0x14U)))
                                         ? 8U : ((0x37U 
                                                  == 
                                                  (0x7fU 
                                                   & (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                      >> 0x14U)))
                                                  ? 0x10U
                                                  : 2U)))),5);
    bufp->fullCData(oldp+789,(vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__alu_operand2),5);
    bufp->fullBit(oldp+790,(((0x2007U == (0x707fU & 
                                          ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                            << 0xcU) 
                                           | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                              >> 0x14U)))) 
                             | ((3U == (0x707fU & (
                                                   (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                    << 0xcU) 
                                                   | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                      >> 0x14U)))) 
                                | ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT____VdfgRegularize_h2cfc3394_0_20) 
                                   | (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT____VdfgRegularize_h2cfc3394_0_19))))));
    bufp->fullCData(oldp+791,(vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__memory_width),2);
    bufp->fullBit(oldp+792,(((3U == (0x707fU & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                 << 0xcU) 
                                                | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                   >> 0x14U)))) 
                             | (0x1003U == (0x707fU 
                                            & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                << 0xcU) 
                                               | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                  >> 0x14U)))))));
    bufp->fullBit(oldp+793,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT____Vcellinp__df__rst));
    bufp->fullWData(oldp+794,(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data),117);
    bufp->fullIData(oldp+798,(vlSelfRef.CPU_top__DOT__cpu__DOT__forward__DOT__rs1),32);
    bufp->fullIData(oldp+799,(vlSelfRef.CPU_top__DOT__cpu__DOT__forward__DOT__rs2),32);
    bufp->fullIData(oldp+800,(vlSelfRef.CPU_top__DOT__cpu__DOT__forward__DOT__rs3),32);
    bufp->fullIData(oldp+801,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__alu_operand1),32);
    bufp->fullIData(oldp+802,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__alu_operand2),32);
    bufp->fullIData(oldp+803,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__alu_signed_sum_result),32);
    bufp->fullBit(oldp+804,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__alu_compare_result));
    bufp->fullIData(oldp+805,((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__alu_operand1 
                               - vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__alu_operand2)),32);
    bufp->fullIData(oldp+806,((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__alu_operand1 
                               & vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__alu_operand2)),32);
    bufp->fullIData(oldp+807,((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__alu_operand1 
                               | vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__alu_operand2)),32);
    bufp->fullIData(oldp+808,((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__alu_operand1 
                               ^ vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__alu_operand2)),32);
    bufp->fullIData(oldp+809,((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__alu_operand1 
                               << (0x1fU & vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__alu_operand2))),32);
    bufp->fullIData(oldp+810,((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__alu_operand1 
                               >> (0x1fU & vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__alu_operand2))),32);
    bufp->fullIData(oldp+811,(VL_SHIFTRS_III(32,32,5, vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__alu_operand1, 
                                             (0x1fU 
                                              & vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__alu_operand2))),32);
    bufp->fullBit(oldp+812,(VL_LTS_III(32, vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__alu_operand1, vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__alu_operand2)));
    bufp->fullBit(oldp+813,((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__alu_operand1 
                             < vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__alu_operand2)));
    bufp->fullBit(oldp+814,((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__alu_operand1 
                             == vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__alu_operand2)));
    bufp->fullBit(oldp+815,((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__alu_operand1 
                             != vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__alu_operand2)));
    bufp->fullBit(oldp+816,(VL_GTES_III(32, vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__alu_operand1, vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__alu_operand2)));
    bufp->fullBit(oldp+817,((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__alu_operand1 
                             >= vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__alu_operand2)));
    bufp->fullBit(oldp+818,((vlSelfRef.CPU_top__DOT__cpu__DOT__forward__DOT__rs1 
                             >> 0x1fU)));
    bufp->fullBit(oldp+819,((vlSelfRef.CPU_top__DOT__cpu__DOT__forward__DOT__rs2 
                             >> 0x1fU)));
    bufp->fullBit(oldp+820,(vlSelfRef.reset));
    bufp->fullBit(oldp+821,(vlSelfRef.clock));
    bufp->fullBit(oldp+822,(vlSelfRef.timer_interrupt));
    bufp->fullBit(oldp+823,(vlSelfRef.external_interrupt));
    bufp->fullBit(oldp+824,(vlSelfRef.bus_rw));
    bufp->fullBit(oldp+825,(vlSelfRef.bus_request));
    bufp->fullBit(oldp+826,(vlSelfRef.bus_ready));
    bufp->fullIData(oldp+827,(vlSelfRef.bus_address),32);
    bufp->fullIData(oldp+828,(vlSelfRef.bus_rdata),32);
    bufp->fullIData(oldp+829,(vlSelfRef.bus_wdata),32);
    bufp->fullBit(oldp+830,(vlSelfRef.cpu_fault));
    bufp->fullBit(oldp+831,(((IData)(vlSelfRef.CPU_top__DOT__cpu_ibus_request) 
                             & ((1U == (IData)(vlSelfRef.CPU_top__DOT__bus__DOT__state)) 
                                & (IData)(vlSelfRef.bus_ready)))));
    bufp->fullBit(oldp+832,(vlSelfRef.CPU_top__DOT__cpu_dbus_ready));
    bufp->fullCData(oldp+833,(vlSelfRef.CPU_top__DOT__bus__DOT__next_state),2);
    bufp->fullIData(oldp+834,(((0U == (0xfU & (vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[0U] 
                                               >> 0x14U)))
                                ? vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__alu_signed_sum_result
                                : ((1U == (0xfU & (
                                                   vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[0U] 
                                                   >> 0x14U)))
                                    ? vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__alu_signed_sum_result
                                    : ((2U == (0xfU 
                                               & (vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[0U] 
                                                  >> 0x14U)))
                                        ? (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__alu_operand1 
                                           - vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__alu_operand2)
                                        : ((3U == (0xfU 
                                                   & (vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[0U] 
                                                      >> 0x14U)))
                                            ? (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__alu_operand1 
                                               & vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__alu_operand2)
                                            : ((4U 
                                                == 
                                                (0xfU 
                                                 & (vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[0U] 
                                                    >> 0x14U)))
                                                ? (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__alu_operand1 
                                                   | vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__alu_operand2)
                                                : (
                                                   (5U 
                                                    == 
                                                    (0xfU 
                                                     & (vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[0U] 
                                                        >> 0x14U)))
                                                    ? 
                                                   (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__alu_operand1 
                                                    ^ vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__alu_operand2)
                                                    : 0U))))))),32);
    bufp->fullIData(oldp+835,(((6U == (0xfU & (vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[0U] 
                                               >> 0x14U)))
                                ? (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__alu_operand1 
                                   << (0x1fU & vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__alu_operand2))
                                : ((7U == (0xfU & (
                                                   vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[0U] 
                                                   >> 0x14U)))
                                    ? (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__alu_operand1 
                                       >> (0x1fU & vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__alu_operand2))
                                    : ((8U == (0xfU 
                                               & (vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[0U] 
                                                  >> 0x14U)))
                                        ? VL_SHIFTRS_III(32,32,5, vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__alu_operand1, 
                                                         (0x1fU 
                                                          & vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__alu_operand2))
                                        : 0U)))),32);
    bufp->fullBit(oldp+836,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__div_ready));
    bufp->fullIData(oldp+837,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__div_result),32);
    bufp->fullIData(oldp+838,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__div_remainder),32);
    bufp->fullIData(oldp+839,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__quotient
                              [0x20U]),32);
    bufp->fullBit(oldp+840,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__ack));
    bufp->fullBit(oldp+841,(vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__genblk1__DOT__dcache__DOT__wb_ready));
    bufp->fullBit(oldp+842,(vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__genblk1__DOT__dcache__DOT__wb__DOT__next_wb_dirty));
}
