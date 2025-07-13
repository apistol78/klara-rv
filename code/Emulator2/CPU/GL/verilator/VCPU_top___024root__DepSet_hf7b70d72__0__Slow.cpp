// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VCPU_top.h for the primary calling header

#include "VCPU_top__pch.h"
#include "VCPU_top___024root.h"

VL_ATTR_COLD void VCPU_top___024root___eval_static__TOP(VCPU_top___024root* vlSelf);
VL_ATTR_COLD void VCPU_top___024root____Vm_traceActivitySetAll(VCPU_top___024root* vlSelf);

VL_ATTR_COLD void VCPU_top___024root___eval_static(VCPU_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCPU_top___024root___eval_static\n"); );
    VCPU_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    VCPU_top___024root___eval_static__TOP(vlSelf);
    VCPU_top___024root____Vm_traceActivitySetAll(vlSelf);
    vlSelfRef.__Vtrigprevexpr___TOP__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__quotient__0 
        = vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__quotient;
    vlSelfRef.__Vtrigprevexpr___TOP__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend__0 
        = vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend;
    vlSelfRef.__Vtrigprevexpr___TOP__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor__0 
        = vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor;
    vlSelfRef.__Vtrigprevexpr___TOP__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__ready__0 
        = vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__ready;
    vlSelfRef.__Vtrigprevexpr___TOP__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__quotient__1 
        = vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__quotient;
    vlSelfRef.__Vtrigprevexpr___TOP__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend__1 
        = vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend;
    vlSelfRef.__Vtrigprevexpr___TOP__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor__1 
        = vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor;
    vlSelfRef.__Vtrigprevexpr___TOP__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__ready__1 
        = vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__ready;
    vlSelfRef.__Vtrigprevexpr___TOP__clock__0 = vlSelfRef.clock;
    vlSelfRef.__Vtrigprevexpr___TOP__reset__0 = vlSelfRef.reset;
    vlSelfRef.__Vtrigprevexpr___TOP__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT____Vcellinp__df__rst__0 
        = vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT____Vcellinp__df__rst;
}

VL_ATTR_COLD void VCPU_top___024root___eval_static__TOP(VCPU_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCPU_top___024root___eval_static__TOP\n"); );
    VCPU_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.CPU_top__DOT__bus__DOT__state = 0U;
    vlSelfRef.CPU_top__DOT__cpu__DOT__csr__DOT__mstatus_mpie = 0U;
    vlSelfRef.CPU_top__DOT__cpu__DOT__csr__DOT__mstatus_mie = 0U;
    vlSelfRef.CPU_top__DOT__cpu__DOT__csr__DOT__mie_meie = 0U;
    vlSelfRef.CPU_top__DOT__cpu__DOT__csr__DOT__mie_mtie = 0U;
    vlSelfRef.CPU_top__DOT__cpu__DOT__csr__DOT__mie_msie = 0U;
    vlSelfRef.CPU_top__DOT__cpu__DOT__csr__DOT__mtvec = 0U;
    vlSelfRef.CPU_top__DOT__cpu__DOT__csr__DOT__mepc = 0U;
    vlSelfRef.CPU_top__DOT__cpu__DOT__csr__DOT__mcause = 0U;
    vlSelfRef.CPU_top__DOT__cpu__DOT__csr__DOT__mip_meip = 0U;
    vlSelfRef.CPU_top__DOT__cpu__DOT__csr__DOT__mip_mtip = 0U;
    vlSelfRef.CPU_top__DOT__cpu__DOT__csr__DOT__mip_msip = 0U;
    vlSelfRef.CPU_top__DOT__cpu__DOT__csr__DOT__mscratch = 0U;
    vlSelfRef.CPU_top__DOT__cpu__DOT__csr__DOT__cycle = 0ULL;
    vlSelfRef.CPU_top__DOT__cpu__DOT__csr__DOT__wtime = 0ULL;
    vlSelfRef.CPU_top__DOT__cpu__DOT__csr__DOT__prescale = 0U;
    vlSelfRef.CPU_top__DOT__cpu__DOT__csr__DOT__issued = 0U;
    vlSelfRef.CPU_top__DOT__cpu__DOT__registers__DOT__last_write_strobe = 0U;
    vlSelfRef.CPU_top__DOT__cpu__DOT__registers__DOT__rs1 = 0U;
    vlSelfRef.CPU_top__DOT__cpu__DOT__registers__DOT__rs2 = 0U;
    vlSelfRef.CPU_top__DOT__cpu__DOT__registers__DOT__rs3 = 0U;
    vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__state = 0U;
    vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__pc = 0U;
    vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__data[0U] = 0U;
    vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__data[1U] = 0U;
    vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__data[2U] = 0U;
    vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__data[3U] = 0U;
    vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__irq_pending_r = 0U;
    vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT__initialized = 0U;
    vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT__clear_set = 0U;
    vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT__cache_wr_request = 0U;
    vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT__set_r = 0xfffU;
    vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_skid__DOT__r_data[0U] = 0U;
    vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_skid__DOT__r_data[1U] = 0U;
    vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_skid__DOT__r_data[2U] = 0U;
    vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_skid__DOT__r_data[3U] = 0U;
    vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[0U] = 0U;
    vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[1U] = 0U;
    vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[2U] = 0U;
    vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[3U] = 0U;
    vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__last_strobe = 0U;
    vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__data[0U] = 0U;
    vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__data[1U] = 0U;
    vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__data[2U] = 0U;
    vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__data[3U] = 0U;
    vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__ack = 0U;
    vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__llth = 0U;
    vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__dcache_rw = 0U;
    vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__dcache_request = 0U;
    vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__dcache_flush = 0U;
    vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__dcache_wdata = 0U;
    vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__data[0U] = 0U;
    vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__data[1U] = 0U;
    vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__data[2U] = 0U;
    vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__state = 0U;
    vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__rmw_rdata = 0U;
    vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__last_strobe = 0U;
    vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__genblk1__DOT__dcache__DOT__state = 0xbU;
    vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__genblk1__DOT__dcache__DOT__flush_address = 0U;
    vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__genblk1__DOT__dcache__DOT__wb_rw = 0U;
    vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__genblk1__DOT__dcache__DOT__wb_request = 0U;
    vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__genblk1__DOT__dcache__DOT__wb_address = 0U;
    vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__genblk1__DOT__dcache__DOT__wb_wdata = 0U;
    vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__genblk1__DOT__dcache__DOT__cache_rw = 0U;
    vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__genblk1__DOT__dcache__DOT__cache_address = 0U;
    vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__genblk1__DOT__dcache__DOT__wb__DOT__wb_dirty = 0U;
    vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__genblk1__DOT__dcache__DOT__wb__DOT__wb_address = 0U;
    vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__genblk1__DOT__dcache__DOT__wb__DOT__wb_data = 0U;
    vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__genblk1__DOT__dcache__DOT__wb__DOT__next_wb_dirty = 0U;
    vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__genblk1__DOT__dcache__DOT__wb__DOT__next_wb_address = 0U;
    vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__genblk1__DOT__dcache__DOT__wb__DOT__next_wb_data = 0U;
    vlSelfRef.CPU_top__DOT__cpu__DOT__writeback__DOT__data = 0ULL;
    vlSelfRef.CPU_top__DOT__cpu__DOT__writeback__DOT__last_strobe = 0U;
    vlSelfRef.CPU_top__DOT__cpu__DOT__writeback__DOT__retired = 0ULL;
    vlSelfRef.CPU_top__DOT__cpu__DOT__writeback__DOT__last_pc = 0U;
}

VL_ATTR_COLD void VCPU_top___024root___eval_initial__TOP(VCPU_top___024root* vlSelf);

VL_ATTR_COLD void VCPU_top___024root___eval_initial(VCPU_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCPU_top___024root___eval_initial\n"); );
    VCPU_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    VCPU_top___024root___eval_initial__TOP(vlSelf);
    VCPU_top___024root____Vm_traceActivitySetAll(vlSelf);
}

VL_ATTR_COLD void VCPU_top___024root___eval_initial__TOP(VCPU_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCPU_top___024root___eval_initial__TOP\n"); );
    VCPU_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__quotient[0U] = 0U;
    vlSelfRef.CPU_top__DOT__cpu__DOT__registers__DOT__r[0U] = 0U;
    vlSelfRef.CPU_top__DOT__cpu__DOT__registers__DOT__r[1U] = 0U;
    vlSelfRef.CPU_top__DOT__cpu__DOT__registers__DOT__r[2U] = 0U;
    vlSelfRef.CPU_top__DOT__cpu__DOT__registers__DOT__r[3U] = 0U;
    vlSelfRef.CPU_top__DOT__cpu__DOT__registers__DOT__r[4U] = 0U;
    vlSelfRef.CPU_top__DOT__cpu__DOT__registers__DOT__r[5U] = 0U;
    vlSelfRef.CPU_top__DOT__cpu__DOT__registers__DOT__r[6U] = 0U;
    vlSelfRef.CPU_top__DOT__cpu__DOT__registers__DOT__r[7U] = 0U;
    vlSelfRef.CPU_top__DOT__cpu__DOT__registers__DOT__r[8U] = 0U;
    vlSelfRef.CPU_top__DOT__cpu__DOT__registers__DOT__r[9U] = 0U;
    vlSelfRef.CPU_top__DOT__cpu__DOT__registers__DOT__r[0xaU] = 0U;
    vlSelfRef.CPU_top__DOT__cpu__DOT__registers__DOT__r[0xbU] = 0U;
    vlSelfRef.CPU_top__DOT__cpu__DOT__registers__DOT__r[0xcU] = 0U;
    vlSelfRef.CPU_top__DOT__cpu__DOT__registers__DOT__r[0xdU] = 0U;
    vlSelfRef.CPU_top__DOT__cpu__DOT__registers__DOT__r[0xeU] = 0U;
    vlSelfRef.CPU_top__DOT__cpu__DOT__registers__DOT__r[0xfU] = 0U;
    vlSelfRef.CPU_top__DOT__cpu__DOT__registers__DOT__r[0x10U] = 0U;
    vlSelfRef.CPU_top__DOT__cpu__DOT__registers__DOT__r[0x11U] = 0U;
    vlSelfRef.CPU_top__DOT__cpu__DOT__registers__DOT__r[0x12U] = 0U;
    vlSelfRef.CPU_top__DOT__cpu__DOT__registers__DOT__r[0x13U] = 0U;
    vlSelfRef.CPU_top__DOT__cpu__DOT__registers__DOT__r[0x14U] = 0U;
    vlSelfRef.CPU_top__DOT__cpu__DOT__registers__DOT__r[0x15U] = 0U;
    vlSelfRef.CPU_top__DOT__cpu__DOT__registers__DOT__r[0x16U] = 0U;
    vlSelfRef.CPU_top__DOT__cpu__DOT__registers__DOT__r[0x17U] = 0U;
    vlSelfRef.CPU_top__DOT__cpu__DOT__registers__DOT__r[0x18U] = 0U;
    vlSelfRef.CPU_top__DOT__cpu__DOT__registers__DOT__r[0x19U] = 0U;
    vlSelfRef.CPU_top__DOT__cpu__DOT__registers__DOT__r[0x1aU] = 0U;
    vlSelfRef.CPU_top__DOT__cpu__DOT__registers__DOT__r[0x1bU] = 0U;
    vlSelfRef.CPU_top__DOT__cpu__DOT__registers__DOT__r[0x1cU] = 0U;
    vlSelfRef.CPU_top__DOT__cpu__DOT__registers__DOT__r[0x1dU] = 0U;
    vlSelfRef.CPU_top__DOT__cpu__DOT__registers__DOT__r[0x1eU] = 0U;
    vlSelfRef.CPU_top__DOT__cpu__DOT__registers__DOT__r[0x1fU] = 0U;
    vlSelfRef.CPU_top__DOT__cpu__DOT__registers__DOT__I = 0x20U;
    vlSelfRef.CPU_top__DOT__cpu__DOT__registers__DOT__r[2U] = 0x10000400U;
    vlSelfRef.CPU_top__DOT__cpu_ibus_request = 0U;
    vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT__cache__DOT__o_pa_ready = 0U;
    vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT__cache__DOT__o_pb_ready = 0U;
    vlSelfRef.CPU_top__DOT__cpu__DOT__decode_fault = 0U;
    vlSelfRef.CPU_top__DOT__cpu__DOT__csr_wdata_wr = 0U;
    vlSelfRef.CPU_top__DOT__cpu__DOT__csr_wdata = 0U;
    vlSelfRef.CPU_top__DOT__cpu__DOT__execute_jump = 0U;
    vlSelfRef.CPU_top__DOT__cpu__DOT__execute_jump_pc = 0U;
    vlSelfRef.CPU_top__DOT__cpu__DOT__execute_mret = 0U;
    vlSelfRef.CPU_top__DOT__cpu__DOT__execute_ecall = 0U;
    vlSelfRef.CPU_top__DOT__cpu__DOT__execute_fault = 0U;
    vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__genblk1__DOT__dcache__DOT__cache__DOT__o_ready = 0U;
    vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__genblk1__DOT__dcache__DOT__cache__DOT__o_valid = 1U;
}

VL_ATTR_COLD void VCPU_top___024root___eval_final(VCPU_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCPU_top___024root___eval_final\n"); );
    VCPU_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VCPU_top___024root___dump_triggers__stl(VCPU_top___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD bool VCPU_top___024root___eval_phase__stl(VCPU_top___024root* vlSelf);

VL_ATTR_COLD void VCPU_top___024root___eval_settle(VCPU_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCPU_top___024root___eval_settle\n"); );
    VCPU_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __VstlIterCount;
    CData/*0:0*/ __VstlContinue;
    // Body
    __VstlIterCount = 0U;
    vlSelfRef.__VstlFirstIteration = 1U;
    __VstlContinue = 1U;
    while (__VstlContinue) {
        if (VL_UNLIKELY(((0x64U < __VstlIterCount)))) {
#ifdef VL_DEBUG
            VCPU_top___024root___dump_triggers__stl(vlSelf);
#endif
            VL_FATAL_MT("rtl/cpu/CPU_top.sv", 14, "", "Settle region did not converge.");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        __VstlContinue = 0U;
        if (VCPU_top___024root___eval_phase__stl(vlSelf)) {
            __VstlContinue = 1U;
        }
        vlSelfRef.__VstlFirstIteration = 0U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VCPU_top___024root___dump_triggers__stl(VCPU_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCPU_top___024root___dump_triggers__stl\n"); );
    VCPU_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VstlTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
    if ((2ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 1 is active: @([hybrid] CPU_top.cpu.execute.divide.df.quotient)\n");
    }
    if ((4ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 2 is active: @([hybrid] CPU_top.cpu.execute.divide.df.dividend)\n");
    }
    if ((8ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 3 is active: @([hybrid] CPU_top.cpu.execute.divide.df.divisor)\n");
    }
    if ((0x10ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 4 is active: @([hybrid] CPU_top.cpu.execute.divide.df.ready)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void VCPU_top___024root___stl_sequent__TOP__0(VCPU_top___024root* vlSelf);
VL_ATTR_COLD void VCPU_top___024root___stl_sequent__TOP__1(VCPU_top___024root* vlSelf);
void VCPU_top___024root___act_sequent__TOP__1(VCPU_top___024root* vlSelf);
VL_ATTR_COLD void VCPU_top___024root___stl_sequent__TOP__3(VCPU_top___024root* vlSelf);
VL_ATTR_COLD void VCPU_top___024root___stl_comb__TOP__0(VCPU_top___024root* vlSelf);
void VCPU_top___024root___act_comb__TOP__0(VCPU_top___024root* vlSelf);
VL_ATTR_COLD void VCPU_top___024root___stl_comb__TOP__2(VCPU_top___024root* vlSelf);

VL_ATTR_COLD void VCPU_top___024root___eval_stl(VCPU_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCPU_top___024root___eval_stl\n"); );
    VCPU_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        VCPU_top___024root___stl_sequent__TOP__0(vlSelf);
        VCPU_top___024root____Vm_traceActivitySetAll(vlSelf);
    }
    if ((0x10ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        VCPU_top___024root___stl_sequent__TOP__1(vlSelf);
    }
    if ((8ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        VCPU_top___024root___act_sequent__TOP__1(vlSelf);
        VCPU_top___024root____Vm_traceActivitySetAll(vlSelf);
    }
    if ((0xcULL & vlSelfRef.__VstlTriggered.word(0U))) {
        VCPU_top___024root___stl_sequent__TOP__3(vlSelf);
        VCPU_top___024root____Vm_traceActivitySetAll(vlSelf);
    }
    if ((0x11ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        VCPU_top___024root___stl_comb__TOP__0(vlSelf);
    }
    if ((0xfULL & vlSelfRef.__VstlTriggered.word(0U))) {
        VCPU_top___024root___act_comb__TOP__0(vlSelf);
    }
    if ((0xdULL & vlSelfRef.__VstlTriggered.word(0U))) {
        VCPU_top___024root___stl_comb__TOP__2(vlSelf);
        VCPU_top___024root____Vm_traceActivitySetAll(vlSelf);
    }
}

VL_ATTR_COLD void VCPU_top___024root___stl_sequent__TOP__0(VCPU_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCPU_top___024root___stl_sequent__TOP__0\n"); );
    VCPU_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ CPU_top__DOT__cpu__DOT__fetch__DOT____VdfgRegularize_hef2daed4_0_9;
    CPU_top__DOT__cpu__DOT__fetch__DOT____VdfgRegularize_hef2daed4_0_9 = 0;
    CData/*0:0*/ CPU_top__DOT__cpu__DOT__fetch__DOT____VdfgRegularize_hef2daed4_0_10;
    CPU_top__DOT__cpu__DOT__fetch__DOT____VdfgRegularize_hef2daed4_0_10 = 0;
    CData/*0:0*/ CPU_top__DOT__cpu__DOT__fetch__DOT____VdfgRegularize_hef2daed4_0_11;
    CPU_top__DOT__cpu__DOT__fetch__DOT____VdfgRegularize_hef2daed4_0_11 = 0;
    CData/*0:0*/ CPU_top__DOT__cpu__DOT__fetch__DOT____VdfgRegularize_hef2daed4_0_12;
    CPU_top__DOT__cpu__DOT__fetch__DOT____VdfgRegularize_hef2daed4_0_12 = 0;
    CData/*0:0*/ CPU_top__DOT__cpu__DOT__fetch__DOT____VdfgRegularize_hef2daed4_0_15;
    CPU_top__DOT__cpu__DOT__fetch__DOT____VdfgRegularize_hef2daed4_0_15 = 0;
    CData/*0:0*/ CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____VdfgExtracted_h350f2d95__0;
    CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____VdfgExtracted_h350f2d95__0 = 0;
    CData/*0:0*/ CPU_top__DOT__cpu__DOT__decode__DOT____VdfgRegularize_h2cfc3394_0_10;
    CPU_top__DOT__cpu__DOT__decode__DOT____VdfgRegularize_h2cfc3394_0_10 = 0;
    CData/*0:0*/ CPU_top__DOT__cpu__DOT__decode__DOT____VdfgRegularize_h2cfc3394_0_11;
    CPU_top__DOT__cpu__DOT__decode__DOT____VdfgRegularize_h2cfc3394_0_11 = 0;
    CData/*0:0*/ CPU_top__DOT__cpu__DOT__decode__DOT____VdfgRegularize_h2cfc3394_0_12;
    CPU_top__DOT__cpu__DOT__decode__DOT____VdfgRegularize_h2cfc3394_0_12 = 0;
    CData/*0:0*/ CPU_top__DOT__cpu__DOT__decode__DOT____VdfgRegularize_h2cfc3394_0_13;
    CPU_top__DOT__cpu__DOT__decode__DOT____VdfgRegularize_h2cfc3394_0_13 = 0;
    CData/*0:0*/ CPU_top__DOT__cpu__DOT__decode__DOT____VdfgRegularize_h2cfc3394_0_21;
    CPU_top__DOT__cpu__DOT__decode__DOT____VdfgRegularize_h2cfc3394_0_21 = 0;
    // Body
    vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__is_JUMP_CONDITIONAL 
        = ((0x63U == (0x707fU & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata))) 
           | ((0x5063U == (0x707fU & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata))) 
              | ((0x7063U == (0x707fU & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata))) 
                 | ((0x4063U == (0x707fU & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata))) 
                    | ((0x6063U == (0x707fU & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata))) 
                       | (0x1063U == (0x707fU & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata))))))));
    vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__is_I 
        = ((0x13U == (0x707fU & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata))) 
           | ((0x7013U == (0x707fU & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata))) 
              | ((0xfU == (0x707fU & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata))) 
                 | ((0x2007U == (0x707fU & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata))) 
                    | ((0x67U == (0x707fU & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata))) 
                       | ((3U == (0x707fU & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata))) 
                          | ((0x4003U == (0x707fU & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata))) 
                             | ((0x1003U == (0x707fU 
                                             & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata))) 
                                | ((0x5003U == (0x707fU 
                                                & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata))) 
                                   | ((0x2003U == (0x707fU 
                                                   & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata))) 
                                      | ((0x6013U == 
                                          (0x707fU 
                                           & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata))) 
                                         | ((0x2013U 
                                             == (0x707fU 
                                                 & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata))) 
                                            | ((0x3013U 
                                                == 
                                                (0x707fU 
                                                 & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata))) 
                                               | (0x4013U 
                                                  == 
                                                  (0x707fU 
                                                   & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata))))))))))))))));
    vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__RS2_bank 
        = ((0x53U == (0xfe00007fU & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata))) 
           | ((0x18000053U == (0xfe00007fU & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata))) 
              | ((0xa0002053U == (0xfe00707fU & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata))) 
                 | ((0xa0000053U == (0xfe00707fU & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata))) 
                    | ((0xa0001053U == (0xfe00707fU 
                                        & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata))) 
                       | ((0x43U == (0x600007fU & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata))) 
                          | ((0x47U == (0x600007fU 
                                        & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata))) 
                             | ((0x4fU == (0x600007fU 
                                           & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata))) 
                                | ((0x4bU == (0x600007fU 
                                              & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata))) 
                                   | ((0x28000053U 
                                       == (0xfe00707fU 
                                           & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata))) 
                                      | ((0x28001053U 
                                          == (0xfe00707fU 
                                              & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata))) 
                                         | ((0x10000053U 
                                             == (0xfe00007fU 
                                                 & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata))) 
                                            | ((0x20000053U 
                                                == 
                                                (0xfe00707fU 
                                                 & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata))) 
                                               | ((0x20001053U 
                                                   == 
                                                   (0xfe00707fU 
                                                    & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata))) 
                                                  | ((0x20002053U 
                                                      == 
                                                      (0xfe00707fU 
                                                       & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata))) 
                                                     | ((0x8000053U 
                                                         == 
                                                         (0xfe00007fU 
                                                          & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata))) 
                                                        | (0x2027U 
                                                           == 
                                                           (0x707fU 
                                                            & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)))))))))))))))))));
    vlSelfRef.cpu_fault = ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__decode_fault) 
                           | (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute_fault));
    vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT____VdfgRegularize_h9eb5ee7c_0_0 
        = VL_SHIFTR_III(32,32,32, vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__dcache_rdata, 
                        VL_SHIFTL_III(32,32,32, (3U 
                                                 & (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__data[0U] 
                                                    >> 5U)), 3U));
    vlSelfRef.CPU_top__DOT__cpu_ibus_ready = ((IData)(vlSelfRef.CPU_top__DOT__cpu_ibus_request) 
                                              & ((1U 
                                                  == (IData)(vlSelfRef.CPU_top__DOT__bus__DOT__state)) 
                                                 & (IData)(vlSelfRef.bus_ready)));
    vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__genblk1__DOT__dcache__DOT__cache_address 
        = (0xfffU & (((1U == (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__genblk1__DOT__dcache__DOT__state)) 
                      | ((2U == (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__genblk1__DOT__dcache__DOT__state)) 
                         | ((3U == (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__genblk1__DOT__dcache__DOT__state)) 
                            | (0xbU == (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__genblk1__DOT__dcache__DOT__state)))))
                      ? (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__genblk1__DOT__dcache__DOT__flush_address)
                      : ((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__data[0U] 
                          << 0x19U) | (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__data[0U] 
                                       >> 7U))));
    vlSelfRef.CPU_top__DOT__cpu__DOT__forward__DOT__rs3 = 0U;
    if ((0x100000U & vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[2U])) {
        vlSelfRef.CPU_top__DOT__cpu__DOT__forward__DOT__rs3 
            = (((0x1fU & (vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[2U] 
                          >> 3U)) == (0x1fU & (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__data[2U] 
                                               >> 0xbU)))
                ? ((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__data[2U] 
                    << 0x15U) | (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__data[1U] 
                                 >> 0xbU)) : (((0x1fU 
                                                & (vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[2U] 
                                                   >> 3U)) 
                                               == (0x1fU 
                                                   & vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__data[1U]))
                                               ? vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__data[0U]
                                               : ((
                                                   (0x1fU 
                                                    & (vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[2U] 
                                                       >> 3U)) 
                                                   == 
                                                   (0x1fU 
                                                    & (IData)(
                                                              (vlSelfRef.CPU_top__DOT__cpu__DOT__writeback__DOT__data 
                                                               >> 0x20U))))
                                                   ? (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__writeback__DOT__data)
                                                   : vlSelfRef.CPU_top__DOT__cpu__DOT__registers__DOT__rs3)));
    }
    vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__genblk1__DOT__dcache__DOT__wb__DOT__next_wb_address 
        = vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__genblk1__DOT__dcache__DOT__wb__DOT__wb_address;
    vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__genblk1__DOT__dcache__DOT__wb__DOT__next_wb_data 
        = vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__genblk1__DOT__dcache__DOT__wb__DOT__wb_data;
    vlSelfRef.__VdfgRegularize_hd87f99a1_8_0 = ((0x23U 
                                                 == 
                                                 (0x707fU 
                                                  & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata))) 
                                                | ((0x1023U 
                                                    == 
                                                    (0x707fU 
                                                     & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata))) 
                                                   | (0x2023U 
                                                      == 
                                                      (0x707fU 
                                                       & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)))));
    vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__have_RS3 
        = ((0x43U == (0x600007fU & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata))) 
           | ((0x47U == (0x600007fU & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata))) 
              | ((0x4fU == (0x600007fU & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata))) 
                 | (0x4bU == (0x600007fU & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata))))));
    vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT____VdfgRegularize_hef2daed4_0_20 
        = ((0x3073U == (0x707fU & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata))) 
           | ((0x2073U == (0x707fU & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata))) 
              | (0x1073U == (0x707fU & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)))));
    vlSelfRef.CPU_top__DOT__cpu_dbus_rw = 0U;
    vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__mul_signed 
        = ((9U == (0x1fU & vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[0U])) 
           | (0xaU == (0x1fU & vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[0U])));
    vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__div_signed 
        = ((4U == (0x1fU & vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[0U])) 
           | (0xdU == (0x1fU & vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[0U])));
    vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT____VdfgRegularize_hef2daed4_0_17 
        = ((0x2004033U == (0xfe00707fU & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata))) 
           | (0x2005033U == (0xfe00707fU & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata))));
    vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT____VdfgRegularize_hef2daed4_0_8 
        = ((0x1033U == (0xfe00707fU & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata))) 
           | (0x1013U == (0xfc00707fU & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata))));
    vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT____VdfgRegularize_hef2daed4_0_19 
        = ((0x40005033U == (0xfe00707fU & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata))) 
           | (0x40005013U == (0xfc00707fU & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata))));
    vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT____VdfgRegularize_hef2daed4_0_18 
        = ((0x5033U == (0xfe00707fU & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata))) 
           | (0x5013U == (0xfc00707fU & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata))));
    vlSelfRef.CPU_top__DOT__cpu_dbus_address = 0U;
    vlSelfRef.CPU_top__DOT__cpu__DOT__csr_rdata = 0U;
    if ((0x300U == (0xfffU & ((vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[1U] 
                               << 2U) | (vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[0U] 
                                         >> 0x1eU))))) {
        vlSelfRef.CPU_top__DOT__cpu__DOT__csr_rdata 
            = (((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__csr__DOT__mstatus_mpie) 
                << 4U) | ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__csr__DOT__mstatus_mie) 
                          << 3U));
    } else if ((0x304U == (0xfffU & ((vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[1U] 
                                      << 2U) | (vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[0U] 
                                                >> 0x1eU))))) {
        vlSelfRef.CPU_top__DOT__cpu__DOT__csr_rdata 
            = (((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__csr__DOT__mie_meie) 
                << 0xbU) | (((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__csr__DOT__mie_mtie) 
                             << 7U) | ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__csr__DOT__mie_msie) 
                                       << 3U)));
    } else if ((0x305U == (0xfffU & ((vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[1U] 
                                      << 2U) | (vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[0U] 
                                                >> 0x1eU))))) {
        vlSelfRef.CPU_top__DOT__cpu__DOT__csr_rdata 
            = vlSelfRef.CPU_top__DOT__cpu__DOT__csr__DOT__mtvec;
    } else if ((0x340U == (0xfffU & ((vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[1U] 
                                      << 2U) | (vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[0U] 
                                                >> 0x1eU))))) {
        vlSelfRef.CPU_top__DOT__cpu__DOT__csr_rdata 
            = vlSelfRef.CPU_top__DOT__cpu__DOT__csr__DOT__mscratch;
    } else if ((0x341U == (0xfffU & ((vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[1U] 
                                      << 2U) | (vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[0U] 
                                                >> 0x1eU))))) {
        vlSelfRef.CPU_top__DOT__cpu__DOT__csr_rdata 
            = vlSelfRef.CPU_top__DOT__cpu__DOT__csr__DOT__mepc;
    } else if ((0x342U == (0xfffU & ((vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[1U] 
                                      << 2U) | (vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[0U] 
                                                >> 0x1eU))))) {
        vlSelfRef.CPU_top__DOT__cpu__DOT__csr_rdata 
            = vlSelfRef.CPU_top__DOT__cpu__DOT__csr__DOT__mcause;
    } else if ((0x344U == (0xfffU & ((vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[1U] 
                                      << 2U) | (vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[0U] 
                                                >> 0x1eU))))) {
        vlSelfRef.CPU_top__DOT__cpu__DOT__csr_rdata 
            = (((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__csr__DOT__mip_meip) 
                << 0xbU) | (((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__csr__DOT__mip_mtip) 
                             << 7U) | ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__csr__DOT__mip_msip) 
                                       << 3U)));
    } else if ((0xc00U == (0xfffU & ((vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[1U] 
                                      << 2U) | (vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[0U] 
                                                >> 0x1eU))))) {
        vlSelfRef.CPU_top__DOT__cpu__DOT__csr_rdata 
            = (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__csr__DOT__cycle);
    } else if ((0xc80U == (0xfffU & ((vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[1U] 
                                      << 2U) | (vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[0U] 
                                                >> 0x1eU))))) {
        vlSelfRef.CPU_top__DOT__cpu__DOT__csr_rdata 
            = (IData)((vlSelfRef.CPU_top__DOT__cpu__DOT__csr__DOT__cycle 
                       >> 0x20U));
    } else if ((0xc01U == (0xfffU & ((vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[1U] 
                                      << 2U) | (vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[0U] 
                                                >> 0x1eU))))) {
        vlSelfRef.CPU_top__DOT__cpu__DOT__csr_rdata 
            = (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__csr__DOT__wtime);
    } else if ((0xc81U == (0xfffU & ((vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[1U] 
                                      << 2U) | (vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[0U] 
                                                >> 0x1eU))))) {
        vlSelfRef.CPU_top__DOT__cpu__DOT__csr_rdata 
            = (IData)((vlSelfRef.CPU_top__DOT__cpu__DOT__csr__DOT__wtime 
                       >> 0x20U));
    } else if ((0xc02U == (0xfffU & ((vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[1U] 
                                      << 2U) | (vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[0U] 
                                                >> 0x1eU))))) {
        vlSelfRef.CPU_top__DOT__cpu__DOT__csr_rdata 
            = (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__writeback__DOT__retired);
    } else if ((0xc82U == (0xfffU & ((vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[1U] 
                                      << 2U) | (vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[0U] 
                                                >> 0x1eU))))) {
        vlSelfRef.CPU_top__DOT__cpu__DOT__csr_rdata 
            = (IData)((vlSelfRef.CPU_top__DOT__cpu__DOT__writeback__DOT__retired 
                       >> 0x20U));
    } else if ((0xf11U == (0xfffU & ((vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[1U] 
                                      << 2U) | (vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[0U] 
                                                >> 0x1eU))))) {
        vlSelfRef.CPU_top__DOT__cpu__DOT__csr_rdata = 0U;
    } else if ((0xf12U == (0xfffU & ((vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[1U] 
                                      << 2U) | (vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[0U] 
                                                >> 0x1eU))))) {
        vlSelfRef.CPU_top__DOT__cpu__DOT__csr_rdata = 0U;
    } else if ((0xf13U == (0xfffU & ((vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[1U] 
                                      << 2U) | (vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[0U] 
                                                >> 0x1eU))))) {
        vlSelfRef.CPU_top__DOT__cpu__DOT__csr_rdata = 0U;
    } else if ((0xf14U == (0xfffU & ((vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[1U] 
                                      << 2U) | (vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[0U] 
                                                >> 0x1eU))))) {
        vlSelfRef.CPU_top__DOT__cpu__DOT__csr_rdata = 0U;
    }
    CPU_top__DOT__cpu__DOT__fetch__DOT____VdfgRegularize_hef2daed4_0_9 
        = ((0x53U == (0xfe00007fU & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata))) 
           | (0xc0000053U == (0xfff0007fU & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata))));
    CPU_top__DOT__cpu__DOT__fetch__DOT____VdfgRegularize_hef2daed4_0_15 
        = ((0xc0100053U == (0xfff0007fU & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata))) 
           | (0xd0000053U == (0xfff0007fU & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata))));
    CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____VdfgExtracted_h350f2d95__0 
        = ((IData)((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata 
                    >> 0x32U)) & ((0x3ffffU & (IData)(
                                                      (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata 
                                                       >> 0x20U))) 
                                  == (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__pc 
                                      >> 0xeU)));
    vlSelfRef.CPU_top__DOT__cpu__DOT__forward__DOT__rs1 = 0U;
    if ((0x40000U & vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[2U])) {
        vlSelfRef.CPU_top__DOT__cpu__DOT__forward__DOT__rs1 
            = (((0x1fU & (vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[2U] 
                          >> 0xdU)) == (0x1fU & (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__data[2U] 
                                                 >> 0xbU)))
                ? ((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__data[2U] 
                    << 0x15U) | (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__data[1U] 
                                 >> 0xbU)) : (((0x1fU 
                                                & (vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[2U] 
                                                   >> 0xdU)) 
                                               == (0x1fU 
                                                   & vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__data[1U]))
                                               ? vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__data[0U]
                                               : ((
                                                   (0x1fU 
                                                    & (vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[2U] 
                                                       >> 0xdU)) 
                                                   == 
                                                   (0x1fU 
                                                    & (IData)(
                                                              (vlSelfRef.CPU_top__DOT__cpu__DOT__writeback__DOT__data 
                                                               >> 0x20U))))
                                                   ? (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__writeback__DOT__data)
                                                   : vlSelfRef.CPU_top__DOT__cpu__DOT__registers__DOT__rs1)));
    }
    vlSelfRef.CPU_top__DOT__cpu__DOT__forward__DOT__rs2 = 0U;
    if ((0x80000U & vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[2U])) {
        vlSelfRef.CPU_top__DOT__cpu__DOT__forward__DOT__rs2 
            = (((0x1fU & (vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[2U] 
                          >> 8U)) == (0x1fU & (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__data[2U] 
                                               >> 0xbU)))
                ? ((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__data[2U] 
                    << 0x15U) | (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__data[1U] 
                                 >> 0xbU)) : (((0x1fU 
                                                & (vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[2U] 
                                                   >> 8U)) 
                                               == (0x1fU 
                                                   & vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__data[1U]))
                                               ? vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__data[0U]
                                               : ((
                                                   (0x1fU 
                                                    & (vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[2U] 
                                                       >> 8U)) 
                                                   == 
                                                   (0x1fU 
                                                    & (IData)(
                                                              (vlSelfRef.CPU_top__DOT__cpu__DOT__writeback__DOT__data 
                                                               >> 0x20U))))
                                                   ? (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__writeback__DOT__data)
                                                   : vlSelfRef.CPU_top__DOT__cpu__DOT__registers__DOT__rs2)));
    }
    CPU_top__DOT__cpu__DOT__fetch__DOT____VdfgRegularize_hef2daed4_0_10 
        = ((0x20002053U == (0xfe00707fU & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata))) 
           | (0x8000053U == (0xfe00007fU & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata))));
    vlSelfRef.CPU_top__DOT__cpu_dbus_request = 0U;
    vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor[0U] 
        = vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__udenominator;
    vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend[0U] 
        = vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__unumerator;
    vlSelfRef.CPU_top__DOT__cpu__DOT__memory_busy = 
        (((1U & (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__data[3U] 
                 >> 0x10U)) != (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__last_strobe)) 
         & (IData)((0U != (0x700U & vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__data[1U]))));
    vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT____VdfgRegularize_h9a67d98d_0_0 
        = ((1U & (vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[3U] 
                  >> 0x15U)) != (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__last_strobe));
    vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__is_S 
        = ((0x2027U == (0x707fU & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata))) 
           | (IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_8_0));
    vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT____VdfgRegularize_hef2daed4_0_14 
        = (((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT____VdfgRegularize_hef2daed4_0_20) 
            | (0x30200073U == (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata))) 
           | (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__have_RS3));
    vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__icache_ready = 0U;
    vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT__cache_rd_set = 0U;
    vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT__cache_invalid = 0U;
    if (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT__initialized) {
        vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT__cache_rd_set 
            = (0xfffU & (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__pc 
                         >> 2U));
        if (((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT__set_r) 
             == (0xfffU & (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__pc 
                           >> 2U)))) {
            if (CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____VdfgExtracted_h350f2d95__0) {
                vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__icache_ready = 1U;
                vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT__cache_rd_set 
                    = (0xfffU & ((IData)(1U) + (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__pc 
                                                >> 2U)));
            }
            if ((1U & (~ (IData)(CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____VdfgExtracted_h350f2d95__0)))) {
                vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT__cache_invalid = 1U;
            }
        }
    }
    vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__alu_operand1 = 0U;
    if ((0x8000U & vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[0U])) {
        vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__alu_operand1 = 0U;
    } else if ((0x10000U & vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[0U])) {
        vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__alu_operand1 
            = vlSelfRef.CPU_top__DOT__cpu__DOT__forward__DOT__rs1;
    } else if ((0x20000U & vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[0U])) {
        vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__alu_operand1 
            = vlSelfRef.CPU_top__DOT__cpu__DOT__forward__DOT__rs2;
    } else if ((0x40000U & vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[0U])) {
        vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__alu_operand1 
            = ((vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[3U] 
                << 0xbU) | (vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[2U] 
                            >> 0x15U));
    } else if ((0x80000U & vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[0U])) {
        vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__alu_operand1 
            = ((vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[1U] 
                << 2U) | (vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[0U] 
                          >> 0x1eU));
    }
    vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__alu_operand2 = 0U;
    if ((0x400U & vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[0U])) {
        vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__alu_operand2 = 0U;
    } else if ((0x800U & vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[0U])) {
        vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__alu_operand2 
            = vlSelfRef.CPU_top__DOT__cpu__DOT__forward__DOT__rs1;
    } else if ((0x1000U & vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[0U])) {
        vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__alu_operand2 
            = vlSelfRef.CPU_top__DOT__cpu__DOT__forward__DOT__rs2;
    } else if ((0x2000U & vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[0U])) {
        vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__alu_operand2 
            = ((vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[3U] 
                << 0xbU) | (vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[2U] 
                            >> 0x15U));
    } else if ((0x4000U & vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[0U])) {
        vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__alu_operand2 
            = ((vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[1U] 
                << 2U) | (vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[0U] 
                          >> 0x1eU));
    }
    vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__is_R 
        = ((0x33U == (0xfe00707fU & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata))) 
           | ((0x7033U == (0xfe00707fU & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata))) 
              | ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT____VdfgRegularize_hef2daed4_0_17) 
                 | ((IData)(CPU_top__DOT__cpu__DOT__fetch__DOT____VdfgRegularize_hef2daed4_0_9) 
                    | ((IData)(CPU_top__DOT__cpu__DOT__fetch__DOT____VdfgRegularize_hef2daed4_0_15) 
                       | ((0xd0100053U == (0xfff0007fU 
                                           & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata))) 
                          | ((0x18000053U == (0xfe00007fU 
                                              & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata))) 
                             | ((0xa0002053U == (0xfe00707fU 
                                                 & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata))) 
                                | ((0xa0000053U == 
                                    (0xfe00707fU & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata))) 
                                   | ((0xa0001053U 
                                       == (0xfe00707fU 
                                           & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata))) 
                                      | ((0x28000053U 
                                          == (0xfe00707fU 
                                              & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata))) 
                                         | ((0x28001053U 
                                             == (0xfe00707fU 
                                                 & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata))) 
                                            | ((0x10000053U 
                                                == 
                                                (0xfe00007fU 
                                                 & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata))) 
                                               | ((0xe0000053U 
                                                   == 
                                                   (0xfff0707fU 
                                                    & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata))) 
                                                  | ((0xf0000053U 
                                                      == 
                                                      (0xfff0707fU 
                                                       & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata))) 
                                                     | ((0x20000053U 
                                                         == 
                                                         (0xfe00707fU 
                                                          & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata))) 
                                                        | ((0x20001053U 
                                                            == 
                                                            (0xfe00707fU 
                                                             & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata))) 
                                                           | ((IData)(CPU_top__DOT__cpu__DOT__fetch__DOT____VdfgRegularize_hef2daed4_0_10) 
                                                              | ((0x2000033U 
                                                                  == 
                                                                  (0xfe00707fU 
                                                                   & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata))) 
                                                                 | ((0x2001033U 
                                                                     == 
                                                                     (0xfe00707fU 
                                                                      & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata))) 
                                                                    | ((0x2003033U 
                                                                        == 
                                                                        (0xfe00707fU 
                                                                         & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata))) 
                                                                       | ((0x6033U 
                                                                           == 
                                                                           (0xfe00707fU 
                                                                            & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata))) 
                                                                          | ((0x2006033U 
                                                                              == 
                                                                              (0xfe00707fU 
                                                                               & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata))) 
                                                                             | ((0x2007033U 
                                                                                == 
                                                                                (0xfe00707fU 
                                                                                & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata))) 
                                                                                | ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT____VdfgRegularize_hef2daed4_0_8) 
                                                                                | ((0x2033U 
                                                                                == 
                                                                                (0xfe00707fU 
                                                                                & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata))) 
                                                                                | ((0x3033U 
                                                                                == 
                                                                                (0xfe00707fU 
                                                                                & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata))) 
                                                                                | ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT____VdfgRegularize_hef2daed4_0_19) 
                                                                                | ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT____VdfgRegularize_hef2daed4_0_18) 
                                                                                | ((0x40000033U 
                                                                                == 
                                                                                (0xfe00707fU 
                                                                                & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata))) 
                                                                                | (0x4033U 
                                                                                == 
                                                                                (0xfe00707fU 
                                                                                & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)))))))))))))))))))))))))))))))));
    CPU_top__DOT__cpu__DOT__fetch__DOT____VdfgRegularize_hef2daed4_0_11 
        = ((0x20000053U == (0xfe00707fU & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata))) 
           | ((0x20001053U == (0xfe00707fU & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata))) 
              | (IData)(CPU_top__DOT__cpu__DOT__fetch__DOT____VdfgRegularize_hef2daed4_0_10)));
    vlSelfRef.bus_request = 0U;
    if (vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__genblk1__DOT__dcache__DOT__wb__DOT__wb_dirty) {
        vlSelfRef.CPU_top__DOT__cpu_dbus_rw = 1U;
        vlSelfRef.CPU_top__DOT__cpu_dbus_address = vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__genblk1__DOT__dcache__DOT__wb__DOT__wb_address;
        vlSelfRef.CPU_top__DOT__cpu_dbus_request = 1U;
    } else if (vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__genblk1__DOT__dcache__DOT__wb_request) {
        if ((1U & (~ (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__genblk1__DOT__dcache__DOT__wb_rw)))) {
            vlSelfRef.CPU_top__DOT__cpu_dbus_rw = 0U;
            vlSelfRef.CPU_top__DOT__cpu_dbus_address 
                = vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__genblk1__DOT__dcache__DOT__wb_address;
            vlSelfRef.CPU_top__DOT__cpu_dbus_request = 1U;
        }
    }
    if ((0U != (IData)(vlSelfRef.CPU_top__DOT__bus__DOT__state))) {
        if ((1U == (IData)(vlSelfRef.CPU_top__DOT__bus__DOT__state))) {
            vlSelfRef.bus_request = vlSelfRef.CPU_top__DOT__cpu_ibus_request;
        } else if ((2U == (IData)(vlSelfRef.CPU_top__DOT__bus__DOT__state))) {
            vlSelfRef.bus_request = vlSelfRef.CPU_top__DOT__cpu_dbus_request;
        }
    }
    vlSelfRef.bus_wdata = 0U;
    vlSelfRef.CPU_top__DOT__bus__DOT__next_state = vlSelfRef.CPU_top__DOT__bus__DOT__state;
    vlSelfRef.bus_rw = 0U;
    vlSelfRef.bus_address = 0U;
    if ((0U == (IData)(vlSelfRef.CPU_top__DOT__bus__DOT__state))) {
        if (vlSelfRef.CPU_top__DOT__cpu_dbus_request) {
            vlSelfRef.bus_wdata = vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__genblk1__DOT__dcache__DOT__wb__DOT__wb_data;
            vlSelfRef.CPU_top__DOT__bus__DOT__next_state = 2U;
            vlSelfRef.bus_rw = vlSelfRef.CPU_top__DOT__cpu_dbus_rw;
            vlSelfRef.bus_address = vlSelfRef.CPU_top__DOT__cpu_dbus_address;
        } else if (vlSelfRef.CPU_top__DOT__cpu_ibus_request) {
            vlSelfRef.CPU_top__DOT__bus__DOT__next_state = 1U;
            vlSelfRef.bus_rw = 0U;
            vlSelfRef.bus_address = vlSelfRef.CPU_top__DOT__cpu_ibus_address;
        }
    } else {
        if ((1U != (IData)(vlSelfRef.CPU_top__DOT__bus__DOT__state))) {
            if ((2U == (IData)(vlSelfRef.CPU_top__DOT__bus__DOT__state))) {
                vlSelfRef.bus_wdata = vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__genblk1__DOT__dcache__DOT__wb__DOT__wb_data;
                vlSelfRef.bus_rw = vlSelfRef.CPU_top__DOT__cpu_dbus_rw;
            }
        }
        if ((1U == (IData)(vlSelfRef.CPU_top__DOT__bus__DOT__state))) {
            if (vlSelfRef.bus_ready) {
                vlSelfRef.CPU_top__DOT__bus__DOT__next_state = 0U;
            }
            vlSelfRef.bus_address = vlSelfRef.CPU_top__DOT__cpu_ibus_address;
        } else if ((2U == (IData)(vlSelfRef.CPU_top__DOT__bus__DOT__state))) {
            if (vlSelfRef.bus_ready) {
                vlSelfRef.CPU_top__DOT__bus__DOT__next_state = 0U;
            }
            vlSelfRef.bus_address = vlSelfRef.CPU_top__DOT__cpu_dbus_address;
        } else {
            vlSelfRef.CPU_top__DOT__bus__DOT__next_state = 0U;
        }
    }
    vlSelfRef.CPU_top__DOT__cpu_dbus_ready = ((IData)(vlSelfRef.CPU_top__DOT__cpu_dbus_request) 
                                              & ((2U 
                                                  == (IData)(vlSelfRef.CPU_top__DOT__bus__DOT__state)) 
                                                 & (IData)(vlSelfRef.bus_ready)));
    vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__mul_request 
        = ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT____VdfgRegularize_h9a67d98d_0_0) 
           & ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__mul_signed) 
              | (0xbU == (0x1fU & vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[0U]))));
    vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__div_request 
        = ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT____VdfgRegularize_h9a67d98d_0_0) 
           & ((4U == (0x1fU & vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[0U])) 
              | ((5U == (0x1fU & vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[0U])) 
                 | ((0xdU == (0x1fU & vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[0U])) 
                    | (0xeU == (0x1fU & vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[0U]))))));
    vlSelfRef.CPU_top__DOT__cpu__DOT____Vcellinp__fetch__i_busy 
        = (((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT____VdfgRegularize_h9a67d98d_0_0) 
            & (vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[0U] 
               >> 0x1aU)) | (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__memory_busy));
    vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__alu_signed_sum_result 
        = (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__alu_operand1 
           + vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__alu_operand2);
    vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__alu_compare_result 
        = ((9U == (0xfU & (vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[0U] 
                           >> 0x14U))) ? VL_LTS_III(32, vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__alu_operand1, vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__alu_operand2)
            : ((0xaU == (0xfU & (vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[0U] 
                                 >> 0x14U))) ? (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__alu_operand1 
                                                < vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__alu_operand2)
                : ((0xbU == (0xfU & (vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[0U] 
                                     >> 0x14U))) ? 
                   (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__alu_operand1 
                    == vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__alu_operand2)
                    : ((0xcU == (0xfU & (vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[0U] 
                                         >> 0x14U)))
                        ? (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__alu_operand1 
                           != vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__alu_operand2)
                        : ((0xdU == (0xfU & (vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[0U] 
                                             >> 0x14U)))
                            ? VL_GTES_III(32, vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__alu_operand1, vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__alu_operand2)
                            : (IData)(((0xe00000U == 
                                        (0xf00000U 
                                         & vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[0U])) 
                                       & (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__alu_operand1 
                                          >= vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__alu_operand2))))))));
    vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__RS1_bank 
        = ((0x53U == (0xfe00007fU & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata))) 
           | ((0xc0000053U == (0xfff0007fU & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata))) 
              | ((0xc0100053U == (0xfff0007fU & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata))) 
                 | ((0x18000053U == (0xfe00007fU & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata))) 
                    | ((0xa0002053U == (0xfe00707fU 
                                        & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata))) 
                       | ((0xa0000053U == (0xfe00707fU 
                                           & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata))) 
                          | ((0xa0001053U == (0xfe00707fU 
                                              & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata))) 
                             | ((0x43U == (0x600007fU 
                                           & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata))) 
                                | ((0x47U == (0x600007fU 
                                              & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata))) 
                                   | ((0x4fU == (0x600007fU 
                                                 & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata))) 
                                      | ((0x4bU == 
                                          (0x600007fU 
                                           & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata))) 
                                         | ((0x28000053U 
                                             == (0xfe00707fU 
                                                 & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata))) 
                                            | ((0x28001053U 
                                                == 
                                                (0xfe00707fU 
                                                 & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata))) 
                                               | ((0x10000053U 
                                                   == 
                                                   (0xfe00007fU 
                                                    & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata))) 
                                                  | ((0xe0000053U 
                                                      == 
                                                      (0xfff0707fU 
                                                       & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata))) 
                                                     | (IData)(CPU_top__DOT__cpu__DOT__fetch__DOT____VdfgRegularize_hef2daed4_0_11))))))))))))))));
    CPU_top__DOT__cpu__DOT__fetch__DOT____VdfgRegularize_hef2daed4_0_12 
        = ((0xf0000053U == (0xfff0707fU & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata))) 
           | (IData)(CPU_top__DOT__cpu__DOT__fetch__DOT____VdfgRegularize_hef2daed4_0_11));
    if (vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__genblk1__DOT__dcache__DOT__wb__DOT__wb_dirty) {
        vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__genblk1__DOT__dcache__DOT__wb__DOT__next_wb_dirty = 1U;
        if (vlSelfRef.CPU_top__DOT__cpu_dbus_ready) {
            vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__genblk1__DOT__dcache__DOT__wb__DOT__next_wb_dirty = 0U;
        }
    } else {
        vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__genblk1__DOT__dcache__DOT__wb__DOT__next_wb_dirty = 0U;
        if (vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__genblk1__DOT__dcache__DOT__wb_request) {
            if (vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__genblk1__DOT__dcache__DOT__wb_rw) {
                vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__genblk1__DOT__dcache__DOT__wb__DOT__next_wb_dirty = 1U;
            }
        }
    }
    vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__genblk1__DOT__dcache__DOT__wb_ready = 0U;
    if ((1U & (~ (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__genblk1__DOT__dcache__DOT__wb__DOT__wb_dirty)))) {
        if (vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__genblk1__DOT__dcache__DOT__wb_request) {
            if (vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__genblk1__DOT__dcache__DOT__wb_rw) {
                vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__genblk1__DOT__dcache__DOT__wb__DOT__next_wb_address 
                    = vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__genblk1__DOT__dcache__DOT__wb_address;
                vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__genblk1__DOT__dcache__DOT__wb__DOT__next_wb_data 
                    = vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__genblk1__DOT__dcache__DOT__wb_wdata;
            }
            vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__genblk1__DOT__dcache__DOT__wb_ready 
                = ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__genblk1__DOT__dcache__DOT__wb_rw) 
                   || (IData)(vlSelfRef.CPU_top__DOT__cpu_dbus_ready));
        }
    }
    vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__mul_ready 
        = ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__mul_request) 
           & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__multiply__DOT__r2_request));
    vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT____Vcellinp__df__rst 
        = (1U & (~ (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__div_request)));
    vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__ready[0U] 
        = ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__div_request) 
           & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__llth));
    if (vlSelfRef.CPU_top__DOT__cpu__DOT____Vcellinp__fetch__i_busy) {
        vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[0U] 
            = vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_skid__DOT__r_data[0U];
        vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[1U] 
            = vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_skid__DOT__r_data[1U];
        vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
            = vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_skid__DOT__r_data[2U];
        vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
            = vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_skid__DOT__r_data[3U];
    } else {
        vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[0U] 
            = vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__data[0U];
        vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[1U] 
            = vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__data[1U];
        vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
            = vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__data[2U];
        vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
            = vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__data[3U];
    }
    vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__RD_bank 
        = ((0x53U == (0xfe00007fU & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata))) 
           | ((0xd0000053U == (0xfff0007fU & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata))) 
              | ((0xd0100053U == (0xfff0007fU & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata))) 
                 | ((0x18000053U == (0xfe00007fU & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata))) 
                    | ((0x2007U == (0x707fU & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata))) 
                       | ((0x43U == (0x600007fU & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata))) 
                          | ((0x47U == (0x600007fU 
                                        & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata))) 
                             | ((0x4fU == (0x600007fU 
                                           & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata))) 
                                | ((0x4bU == (0x600007fU 
                                              & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata))) 
                                   | ((0x28000053U 
                                       == (0xfe00707fU 
                                           & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata))) 
                                      | ((0x28001053U 
                                          == (0xfe00707fU 
                                              & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata))) 
                                         | ((0x10000053U 
                                             == (0xfe00007fU 
                                                 & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata))) 
                                            | (IData)(CPU_top__DOT__cpu__DOT__fetch__DOT____VdfgRegularize_hef2daed4_0_12)))))))))))));
    vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__is_FPU 
        = ((IData)(CPU_top__DOT__cpu__DOT__fetch__DOT____VdfgRegularize_hef2daed4_0_9) 
           | ((IData)(CPU_top__DOT__cpu__DOT__fetch__DOT____VdfgRegularize_hef2daed4_0_15) 
              | ((0xd0100053U == (0xfff0007fU & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata))) 
                 | ((0x18000053U == (0xfe00007fU & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata))) 
                    | ((0xa0002053U == (0xfe00707fU 
                                        & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata))) 
                       | ((0xa0000053U == (0xfe00707fU 
                                           & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata))) 
                          | ((0xa0001053U == (0xfe00707fU 
                                              & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata))) 
                             | ((0x43U == (0x600007fU 
                                           & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata))) 
                                | ((0x47U == (0x600007fU 
                                              & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata))) 
                                   | ((0x4fU == (0x600007fU 
                                                 & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata))) 
                                      | ((0x4bU == 
                                          (0x600007fU 
                                           & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata))) 
                                         | ((0x28000053U 
                                             == (0xfe00707fU 
                                                 & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata))) 
                                            | ((0x28001053U 
                                                == 
                                                (0xfe00707fU 
                                                 & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata))) 
                                               | ((0x10000053U 
                                                   == 
                                                   (0xfe00007fU 
                                                    & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata))) 
                                                  | ((0xe0000053U 
                                                      == 
                                                      (0xfff0707fU 
                                                       & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata))) 
                                                     | (IData)(CPU_top__DOT__cpu__DOT__fetch__DOT____VdfgRegularize_hef2daed4_0_12))))))))))))))));
    vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__is_B 
        = ((0x63U == (0x707fU & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                  << 0xcU) | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                              >> 0x14U)))) 
           | ((0x5063U == (0x707fU & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                       << 0xcU) | (
                                                   vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                   >> 0x14U)))) 
              | ((0x7063U == (0x707fU & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                          << 0xcU) 
                                         | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                            >> 0x14U)))) 
                 | ((0x4063U == (0x707fU & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                             << 0xcU) 
                                            | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                               >> 0x14U)))) 
                    | ((0x6063U == (0x707fU & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                << 0xcU) 
                                               | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                  >> 0x14U)))) 
                       | (0x1063U == (0x707fU & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                  << 0xcU) 
                                                 | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                    >> 0x14U)))))))));
    vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__is_U 
        = ((0x17U == (0x7fU & (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                               >> 0x14U))) | (0x37U 
                                              == (0x7fU 
                                                  & (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                     >> 0x14U))));
    vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__alu_operation 
        = ((0x33U == (0xfe00707fU & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                      << 0xcU) | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                  >> 0x14U))))
            ? 0U : ((0x13U == (0x707fU & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                           << 0xcU) 
                                          | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                             >> 0x14U))))
                     ? 0U : ((0x7033U == (0xfe00707fU 
                                          & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                              << 0xcU) 
                                             | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                >> 0x14U))))
                              ? 3U : ((0x7013U == (0x707fU 
                                                   & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                       << 0xcU) 
                                                      | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                         >> 0x14U))))
                                       ? 3U : ((0x17U 
                                                == 
                                                (0x7fU 
                                                 & (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                    >> 0x14U)))
                                                ? 0U
                                                : (
                                                   (0x63U 
                                                    == 
                                                    (0x707fU 
                                                     & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                         << 0xcU) 
                                                        | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                           >> 0x14U))))
                                                    ? 0xbU
                                                    : 
                                                   ((0x5063U 
                                                     == 
                                                     (0x707fU 
                                                      & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                          << 0xcU) 
                                                         | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                            >> 0x14U))))
                                                     ? 0xdU
                                                     : 
                                                    ((0x7063U 
                                                      == 
                                                      (0x707fU 
                                                       & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                           << 0xcU) 
                                                          | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                             >> 0x14U))))
                                                      ? 0xeU
                                                      : 
                                                     ((0x4063U 
                                                       == 
                                                       (0x707fU 
                                                        & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                            << 0xcU) 
                                                           | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                              >> 0x14U))))
                                                       ? 9U
                                                       : 
                                                      ((0x6063U 
                                                        == 
                                                        (0x707fU 
                                                         & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                             << 0xcU) 
                                                            | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                               >> 0x14U))))
                                                        ? 0xaU
                                                        : 
                                                       ((0x1063U 
                                                         == 
                                                         (0x707fU 
                                                          & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                              << 0xcU) 
                                                             | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                                >> 0x14U))))
                                                         ? 0xcU
                                                         : 
                                                        ((0x2007U 
                                                          == 
                                                          (0x707fU 
                                                           & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                               << 0xcU) 
                                                              | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                                 >> 0x14U))))
                                                          ? 0U
                                                          : 
                                                         ((0x2027U 
                                                           == 
                                                           (0x707fU 
                                                            & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                                << 0xcU) 
                                                               | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                                  >> 0x14U))))
                                                           ? 0U
                                                           : 
                                                          ((0x6fU 
                                                            == 
                                                            (0x7fU 
                                                             & (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                                >> 0x14U)))
                                                            ? 0U
                                                            : 
                                                           ((0x67U 
                                                             == 
                                                             (0x707fU 
                                                              & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                                  << 0xcU) 
                                                                 | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                                    >> 0x14U))))
                                                             ? 0U
                                                             : 
                                                            ((3U 
                                                              == 
                                                              (0x707fU 
                                                               & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                                   << 0xcU) 
                                                                  | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                                     >> 0x14U))))
                                                              ? 0U
                                                              : 
                                                             ((0x4003U 
                                                               == 
                                                               (0x707fU 
                                                                & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                                    << 0xcU) 
                                                                   | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                                      >> 0x14U))))
                                                               ? 0U
                                                               : 
                                                              ((0x1003U 
                                                                == 
                                                                (0x707fU 
                                                                 & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                                     << 0xcU) 
                                                                    | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                                       >> 0x14U))))
                                                                ? 0U
                                                                : 
                                                               ((0x5003U 
                                                                 == 
                                                                 (0x707fU 
                                                                  & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                                      << 0xcU) 
                                                                     | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                                        >> 0x14U))))
                                                                 ? 0U
                                                                 : 
                                                                ((0x37U 
                                                                  == 
                                                                  (0x7fU 
                                                                   & (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                                      >> 0x14U)))
                                                                  ? 1U
                                                                  : 
                                                                 ((0x2003U 
                                                                   == 
                                                                   (0x707fU 
                                                                    & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                                        << 0xcU) 
                                                                       | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                                          >> 0x14U))))
                                                                   ? 0U
                                                                   : 
                                                                  ((0x6033U 
                                                                    == 
                                                                    (0xfe00707fU 
                                                                     & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                                         << 0xcU) 
                                                                        | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                                           >> 0x14U))))
                                                                    ? 4U
                                                                    : 
                                                                   ((0x6013U 
                                                                     == 
                                                                     (0x707fU 
                                                                      & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                                          << 0xcU) 
                                                                         | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                                            >> 0x14U))))
                                                                     ? 4U
                                                                     : 
                                                                    ((0x23U 
                                                                      == 
                                                                      (0x707fU 
                                                                       & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                                           << 0xcU) 
                                                                          | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                                             >> 0x14U))))
                                                                      ? 0U
                                                                      : 
                                                                     ((0x1023U 
                                                                       == 
                                                                       (0x707fU 
                                                                        & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                                            << 0xcU) 
                                                                           | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                                              >> 0x14U))))
                                                                       ? 0U
                                                                       : 
                                                                      ((0x1033U 
                                                                        == 
                                                                        (0xfe00707fU 
                                                                         & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                                             << 0xcU) 
                                                                            | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                                               >> 0x14U))))
                                                                        ? 6U
                                                                        : 
                                                                       ((0x1013U 
                                                                         == 
                                                                         (0xfc00707fU 
                                                                          & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                                              << 0xcU) 
                                                                             | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                                                >> 0x14U))))
                                                                         ? 6U
                                                                         : 
                                                                        ((0x2033U 
                                                                          == 
                                                                          (0xfe00707fU 
                                                                           & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                                               << 0xcU) 
                                                                              | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                                                >> 0x14U))))
                                                                          ? 9U
                                                                          : 
                                                                         ((0x2013U 
                                                                           == 
                                                                           (0x707fU 
                                                                            & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                                                << 0xcU) 
                                                                               | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                                                >> 0x14U))))
                                                                           ? 9U
                                                                           : 
                                                                          ((0x3013U 
                                                                            == 
                                                                            (0x707fU 
                                                                             & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                                                << 0xcU) 
                                                                                | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                                                >> 0x14U))))
                                                                            ? 0xaU
                                                                            : 
                                                                           ((0x3033U 
                                                                             == 
                                                                             (0xfe00707fU 
                                                                              & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                                                << 0xcU) 
                                                                                | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                                                >> 0x14U))))
                                                                             ? 0xaU
                                                                             : 
                                                                            ((0x40005033U 
                                                                              == 
                                                                              (0xfe00707fU 
                                                                               & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                                                << 0xcU) 
                                                                                | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                                                >> 0x14U))))
                                                                              ? 8U
                                                                              : 
                                                                             ((0x40005013U 
                                                                               == 
                                                                               (0xfc00707fU 
                                                                                & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                                                << 0xcU) 
                                                                                | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                                                >> 0x14U))))
                                                                               ? 8U
                                                                               : 
                                                                              ((0x5033U 
                                                                                == 
                                                                                (0xfe00707fU 
                                                                                & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                                                << 0xcU) 
                                                                                | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                                                >> 0x14U))))
                                                                                ? 7U
                                                                                : 
                                                                               ((0x5013U 
                                                                                == 
                                                                                (0xfc00707fU 
                                                                                & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                                                << 0xcU) 
                                                                                | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                                                >> 0x14U))))
                                                                                 ? 7U
                                                                                 : 
                                                                                ((0x40000033U 
                                                                                == 
                                                                                (0xfe00707fU 
                                                                                & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                                                << 0xcU) 
                                                                                | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                                                >> 0x14U))))
                                                                                 ? 2U
                                                                                 : 
                                                                                ((0x2023U 
                                                                                == 
                                                                                (0x707fU 
                                                                                & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                                                << 0xcU) 
                                                                                | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                                                >> 0x14U))))
                                                                                 ? 0U
                                                                                 : 
                                                                                ((0x4033U 
                                                                                == 
                                                                                (0xfe00707fU 
                                                                                & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                                                << 0xcU) 
                                                                                | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                                                >> 0x14U))))
                                                                                 ? 5U
                                                                                 : 
                                                                                ((0x4013U 
                                                                                == 
                                                                                (0x707fU 
                                                                                & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                                                << 0xcU) 
                                                                                | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                                                >> 0x14U))))
                                                                                 ? 5U
                                                                                 : 0U)))))))))))))))))))))))))))))))))))))));
    vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__alu_operand2 
        = ((0x13U == (0x707fU & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                  << 0xcU) | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                              >> 0x14U))))
            ? 0x10U : ((0x7013U == (0x707fU & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                << 0xcU) 
                                               | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                  >> 0x14U))))
                        ? 0x10U : ((0x17U == (0x7fU 
                                              & (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                 >> 0x14U)))
                                    ? 0x10U : ((0x2007U 
                                                == 
                                                (0x707fU 
                                                 & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                     << 0xcU) 
                                                    | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                       >> 0x14U))))
                                                ? 0x10U
                                                : (
                                                   (0x2027U 
                                                    == 
                                                    (0x707fU 
                                                     & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                         << 0xcU) 
                                                        | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                           >> 0x14U))))
                                                    ? 0x10U
                                                    : 
                                                   ((0x6fU 
                                                     == 
                                                     (0x7fU 
                                                      & (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                         >> 0x14U)))
                                                     ? 0x10U
                                                     : 
                                                    ((0x67U 
                                                      == 
                                                      (0x707fU 
                                                       & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                           << 0xcU) 
                                                          | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                             >> 0x14U))))
                                                      ? 0x10U
                                                      : 
                                                     ((3U 
                                                       == 
                                                       (0x707fU 
                                                        & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                            << 0xcU) 
                                                           | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                              >> 0x14U))))
                                                       ? 0x10U
                                                       : 
                                                      ((0x4003U 
                                                        == 
                                                        (0x707fU 
                                                         & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                             << 0xcU) 
                                                            | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                               >> 0x14U))))
                                                        ? 0x10U
                                                        : 
                                                       ((0x1003U 
                                                         == 
                                                         (0x707fU 
                                                          & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                              << 0xcU) 
                                                             | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                                >> 0x14U))))
                                                         ? 0x10U
                                                         : 
                                                        ((0x5003U 
                                                          == 
                                                          (0x707fU 
                                                           & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                               << 0xcU) 
                                                              | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                                 >> 0x14U))))
                                                          ? 0x10U
                                                          : 
                                                         ((0x37U 
                                                           == 
                                                           (0x7fU 
                                                            & (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                               >> 0x14U)))
                                                           ? 1U
                                                           : 
                                                          ((0x2003U 
                                                            == 
                                                            (0x707fU 
                                                             & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                                 << 0xcU) 
                                                                | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                                   >> 0x14U))))
                                                            ? 0x10U
                                                            : 
                                                           ((0x6013U 
                                                             == 
                                                             (0x707fU 
                                                              & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                                  << 0xcU) 
                                                                 | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                                    >> 0x14U))))
                                                             ? 0x10U
                                                             : 
                                                            ((0x23U 
                                                              == 
                                                              (0x707fU 
                                                               & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                                   << 0xcU) 
                                                                  | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                                     >> 0x14U))))
                                                              ? 0x10U
                                                              : 
                                                             ((0x1023U 
                                                               == 
                                                               (0x707fU 
                                                                & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                                    << 0xcU) 
                                                                   | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                                      >> 0x14U))))
                                                               ? 0x10U
                                                               : 
                                                              ((0x1013U 
                                                                == 
                                                                (0xfc00707fU 
                                                                 & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                                     << 0xcU) 
                                                                    | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                                       >> 0x14U))))
                                                                ? 0x10U
                                                                : 
                                                               ((0x2013U 
                                                                 == 
                                                                 (0x707fU 
                                                                  & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                                      << 0xcU) 
                                                                     | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                                        >> 0x14U))))
                                                                 ? 0x10U
                                                                 : 
                                                                ((0x3013U 
                                                                  == 
                                                                  (0x707fU 
                                                                   & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                                       << 0xcU) 
                                                                      | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                                         >> 0x14U))))
                                                                  ? 0x10U
                                                                  : 
                                                                 ((0x40005013U 
                                                                   == 
                                                                   (0xfc00707fU 
                                                                    & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                                        << 0xcU) 
                                                                       | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                                          >> 0x14U))))
                                                                   ? 0x10U
                                                                   : 
                                                                  ((0x5013U 
                                                                    == 
                                                                    (0xfc00707fU 
                                                                     & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                                         << 0xcU) 
                                                                        | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                                           >> 0x14U))))
                                                                    ? 0x10U
                                                                    : 
                                                                   ((0x2023U 
                                                                     == 
                                                                     (0x707fU 
                                                                      & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                                          << 0xcU) 
                                                                         | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                                            >> 0x14U))))
                                                                     ? 0x10U
                                                                     : 
                                                                    ((0x4013U 
                                                                      == 
                                                                      (0x707fU 
                                                                       & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                                           << 0xcU) 
                                                                          | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                                             >> 0x14U))))
                                                                      ? 0x10U
                                                                      : 4U)))))))))))))))))))))));
    vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__memory_width 
        = ((0x2007U == (0x707fU & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                    << 0xcU) | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                >> 0x14U))))
            ? 2U : ((0x2027U == (0x707fU & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                             << 0xcU) 
                                            | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                               >> 0x14U))))
                     ? 2U : ((3U == (0x707fU & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                 << 0xcU) 
                                                | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                   >> 0x14U))))
                              ? 0U : ((0x4003U == (0x707fU 
                                                   & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                       << 0xcU) 
                                                      | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                         >> 0x14U))))
                                       ? 0U : ((0x1003U 
                                                == 
                                                (0x707fU 
                                                 & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                     << 0xcU) 
                                                    | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                       >> 0x14U))))
                                                ? 1U
                                                : (
                                                   (0x5003U 
                                                    == 
                                                    (0x707fU 
                                                     & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                         << 0xcU) 
                                                        | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                           >> 0x14U))))
                                                    ? 1U
                                                    : 
                                                   ((0x2003U 
                                                     == 
                                                     (0x707fU 
                                                      & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                          << 0xcU) 
                                                         | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                            >> 0x14U))))
                                                     ? 2U
                                                     : 
                                                    ((0x23U 
                                                      == 
                                                      (0x707fU 
                                                       & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                           << 0xcU) 
                                                          | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                             >> 0x14U))))
                                                      ? 0U
                                                      : 
                                                     ((0x1023U 
                                                       == 
                                                       (0x707fU 
                                                        & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                            << 0xcU) 
                                                           | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                              >> 0x14U))))
                                                       ? 1U
                                                       : 
                                                      ((0x2023U 
                                                        == 
                                                        (0x707fU 
                                                         & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                             << 0xcU) 
                                                            | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                               >> 0x14U))))
                                                        ? 2U
                                                        : 0U))))))))));
    vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__RS2_bank 
        = ((0x53U == (0xfe00007fU & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                      << 0xcU) | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                  >> 0x14U)))) 
           | ((0x18000053U == (0xfe00007fU & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                               << 0xcU) 
                                              | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                 >> 0x14U)))) 
              | ((0xa0002053U == (0xfe00707fU & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                  << 0xcU) 
                                                 | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                    >> 0x14U)))) 
                 | ((0xa0000053U == (0xfe00707fU & 
                                     ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                       << 0xcU) | (
                                                   vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                   >> 0x14U)))) 
                    | ((0xa0001053U == (0xfe00707fU 
                                        & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                            << 0xcU) 
                                           | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                              >> 0x14U)))) 
                       | ((0x43U == (0x600007fU & (
                                                   (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                    << 0xcU) 
                                                   | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                      >> 0x14U)))) 
                          | ((0x47U == (0x600007fU 
                                        & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                            << 0xcU) 
                                           | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                              >> 0x14U)))) 
                             | ((0x4fU == (0x600007fU 
                                           & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                               << 0xcU) 
                                              | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                 >> 0x14U)))) 
                                | ((0x4bU == (0x600007fU 
                                              & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                  << 0xcU) 
                                                 | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                    >> 0x14U)))) 
                                   | ((0x28000053U 
                                       == (0xfe00707fU 
                                           & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                               << 0xcU) 
                                              | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                 >> 0x14U)))) 
                                      | ((0x28001053U 
                                          == (0xfe00707fU 
                                              & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                  << 0xcU) 
                                                 | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                    >> 0x14U)))) 
                                         | ((0x10000053U 
                                             == (0xfe00007fU 
                                                 & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                     << 0xcU) 
                                                    | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                       >> 0x14U)))) 
                                            | ((0x20000053U 
                                                == 
                                                (0xfe00707fU 
                                                 & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                     << 0xcU) 
                                                    | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                       >> 0x14U)))) 
                                               | ((0x20001053U 
                                                   == 
                                                   (0xfe00707fU 
                                                    & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                        << 0xcU) 
                                                       | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                          >> 0x14U)))) 
                                                  | ((0x20002053U 
                                                      == 
                                                      (0xfe00707fU 
                                                       & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                           << 0xcU) 
                                                          | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                             >> 0x14U)))) 
                                                     | ((0x8000053U 
                                                         == 
                                                         (0xfe00007fU 
                                                          & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                              << 0xcU) 
                                                             | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                                >> 0x14U)))) 
                                                        | (0x2027U 
                                                           == 
                                                           (0x707fU 
                                                            & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                                << 0xcU) 
                                                               | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                                  >> 0x14U))))))))))))))))))));
    vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__have_RS3 
        = ((0x43U == (0x600007fU & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                     << 0xcU) | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                 >> 0x14U)))) 
           | ((0x47U == (0x600007fU & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                        << 0xcU) | 
                                       (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                        >> 0x14U)))) 
              | ((0x4fU == (0x600007fU & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                           << 0xcU) 
                                          | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                             >> 0x14U)))) 
                 | (0x4bU == (0x600007fU & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                             << 0xcU) 
                                            | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                               >> 0x14U)))))));
    vlSelfRef.__VdfgRegularize_hd87f99a1_3_0 = ((0x23U 
                                                 == 
                                                 (0x707fU 
                                                  & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                      << 0xcU) 
                                                     | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                        >> 0x14U)))) 
                                                | ((0x1023U 
                                                    == 
                                                    (0x707fU 
                                                     & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                         << 0xcU) 
                                                        | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                           >> 0x14U)))) 
                                                   | (0x2023U 
                                                      == 
                                                      (0x707fU 
                                                       & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                           << 0xcU) 
                                                          | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                             >> 0x14U))))));
    vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT____VdfgRegularize_h2cfc3394_0_20 
        = ((0x4003U == (0x707fU & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                    << 0xcU) | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                >> 0x14U)))) 
           | (0x1003U == (0x707fU & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                      << 0xcU) | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                  >> 0x14U)))));
    vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT____VdfgRegularize_h2cfc3394_0_19 
        = ((0x5003U == (0x707fU & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                    << 0xcU) | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                >> 0x14U)))) 
           | (0x2003U == (0x707fU & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                      << 0xcU) | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                  >> 0x14U)))));
    vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT____VdfgRegularize_h2cfc3394_0_26 
        = ((0x3073U == (0x707fU & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                    << 0xcU) | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                >> 0x14U)))) 
           | ((0x2073U == (0x707fU & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                       << 0xcU) | (
                                                   vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                   >> 0x14U)))) 
              | (0x1073U == (0x707fU & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                         << 0xcU) | 
                                        (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                         >> 0x14U))))));
    vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT____VdfgRegularize_h2cfc3394_0_23 
        = ((0x2004033U == (0xfe00707fU & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                           << 0xcU) 
                                          | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                             >> 0x14U)))) 
           | (0x2005033U == (0xfe00707fU & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                             << 0xcU) 
                                            | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                               >> 0x14U)))));
    vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT____VdfgRegularize_h2cfc3394_0_9 
        = ((0x1033U == (0xfe00707fU & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                        << 0xcU) | 
                                       (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                        >> 0x14U)))) 
           | (0x1013U == (0xfc00707fU & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                          << 0xcU) 
                                         | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                            >> 0x14U)))));
    vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT____VdfgRegularize_h2cfc3394_0_25 
        = ((0x40005033U == (0xfe00707fU & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                            << 0xcU) 
                                           | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                              >> 0x14U)))) 
           | (0x40005013U == (0xfc00707fU & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                              << 0xcU) 
                                             | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                >> 0x14U)))));
    vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT____VdfgRegularize_h2cfc3394_0_24 
        = ((0x5033U == (0xfe00707fU & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                        << 0xcU) | 
                                       (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                        >> 0x14U)))) 
           | (0x5013U == (0xfc00707fU & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                          << 0xcU) 
                                         | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                            >> 0x14U)))));
    CPU_top__DOT__cpu__DOT__decode__DOT____VdfgRegularize_h2cfc3394_0_10 
        = ((0x53U == (0xfe00007fU & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                      << 0xcU) | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                  >> 0x14U)))) 
           | (0xc0000053U == (0xfff0007fU & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                              << 0xcU) 
                                             | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                >> 0x14U)))));
    CPU_top__DOT__cpu__DOT__decode__DOT____VdfgRegularize_h2cfc3394_0_21 
        = ((0xc0100053U == (0xfff0007fU & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                            << 0xcU) 
                                           | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                              >> 0x14U)))) 
           | (0xd0000053U == (0xfff0007fU & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                              << 0xcU) 
                                             | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                >> 0x14U)))));
    CPU_top__DOT__cpu__DOT__decode__DOT____VdfgRegularize_h2cfc3394_0_11 
        = ((0x20002053U == (0xfe00707fU & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                            << 0xcU) 
                                           | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                              >> 0x14U)))) 
           | (0x8000053U == (0xfe00007fU & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                             << 0xcU) 
                                            | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                               >> 0x14U)))));
    vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__is_S 
        = ((0x2027U == (0x707fU & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                    << 0xcU) | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                >> 0x14U)))) 
           | (IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_3_0));
    vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__is_I 
        = ((0x13U == (0x707fU & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                  << 0xcU) | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                              >> 0x14U)))) 
           | ((0x7013U == (0x707fU & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                       << 0xcU) | (
                                                   vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                   >> 0x14U)))) 
              | ((0xfU == (0x707fU & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                       << 0xcU) | (
                                                   vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                   >> 0x14U)))) 
                 | ((0x2007U == (0x707fU & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                             << 0xcU) 
                                            | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                               >> 0x14U)))) 
                    | ((0x67U == (0x707fU & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                              << 0xcU) 
                                             | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                >> 0x14U)))) 
                       | ((3U == (0x707fU & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                              << 0xcU) 
                                             | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                >> 0x14U)))) 
                          | ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT____VdfgRegularize_h2cfc3394_0_20) 
                             | ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT____VdfgRegularize_h2cfc3394_0_19) 
                                | ((0x6013U == (0x707fU 
                                                & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                    << 0xcU) 
                                                   | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                      >> 0x14U)))) 
                                   | ((0x2013U == (0x707fU 
                                                   & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                       << 0xcU) 
                                                      | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                         >> 0x14U)))) 
                                      | ((0x3013U == 
                                          (0x707fU 
                                           & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                               << 0xcU) 
                                              | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                 >> 0x14U)))) 
                                         | (0x4013U 
                                            == (0x707fU 
                                                & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                    << 0xcU) 
                                                   | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                      >> 0x14U)))))))))))))));
    vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__is_CSR 
        = ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT____VdfgRegularize_h2cfc3394_0_26) 
           | (0x30200073U == ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                               << 0xcU) | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                           >> 0x14U))));
    vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__is_R 
        = ((0x33U == (0xfe00707fU & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                      << 0xcU) | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                  >> 0x14U)))) 
           | ((0x7033U == (0xfe00707fU & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                           << 0xcU) 
                                          | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                             >> 0x14U)))) 
              | ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT____VdfgRegularize_h2cfc3394_0_23) 
                 | ((IData)(CPU_top__DOT__cpu__DOT__decode__DOT____VdfgRegularize_h2cfc3394_0_10) 
                    | ((IData)(CPU_top__DOT__cpu__DOT__decode__DOT____VdfgRegularize_h2cfc3394_0_21) 
                       | ((0xd0100053U == (0xfff0007fU 
                                           & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                               << 0xcU) 
                                              | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                 >> 0x14U)))) 
                          | ((0x18000053U == (0xfe00007fU 
                                              & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                  << 0xcU) 
                                                 | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                    >> 0x14U)))) 
                             | ((0xa0002053U == (0xfe00707fU 
                                                 & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                     << 0xcU) 
                                                    | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                       >> 0x14U)))) 
                                | ((0xa0000053U == 
                                    (0xfe00707fU & 
                                     ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                       << 0xcU) | (
                                                   vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                   >> 0x14U)))) 
                                   | ((0xa0001053U 
                                       == (0xfe00707fU 
                                           & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                               << 0xcU) 
                                              | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                 >> 0x14U)))) 
                                      | ((0x28000053U 
                                          == (0xfe00707fU 
                                              & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                  << 0xcU) 
                                                 | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                    >> 0x14U)))) 
                                         | ((0x28001053U 
                                             == (0xfe00707fU 
                                                 & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                     << 0xcU) 
                                                    | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                       >> 0x14U)))) 
                                            | ((0x10000053U 
                                                == 
                                                (0xfe00007fU 
                                                 & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                     << 0xcU) 
                                                    | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                       >> 0x14U)))) 
                                               | ((0xe0000053U 
                                                   == 
                                                   (0xfff0707fU 
                                                    & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                        << 0xcU) 
                                                       | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                          >> 0x14U)))) 
                                                  | ((0xf0000053U 
                                                      == 
                                                      (0xfff0707fU 
                                                       & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                           << 0xcU) 
                                                          | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                             >> 0x14U)))) 
                                                     | ((0x20000053U 
                                                         == 
                                                         (0xfe00707fU 
                                                          & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                              << 0xcU) 
                                                             | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                                >> 0x14U)))) 
                                                        | ((0x20001053U 
                                                            == 
                                                            (0xfe00707fU 
                                                             & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                                 << 0xcU) 
                                                                | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                                   >> 0x14U)))) 
                                                           | ((IData)(CPU_top__DOT__cpu__DOT__decode__DOT____VdfgRegularize_h2cfc3394_0_11) 
                                                              | ((0x2000033U 
                                                                  == 
                                                                  (0xfe00707fU 
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
                                                                       | ((0x6033U 
                                                                           == 
                                                                           (0xfe00707fU 
                                                                            & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                                                << 0xcU) 
                                                                               | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                                                >> 0x14U)))) 
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
                                                                                | ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT____VdfgRegularize_h2cfc3394_0_9) 
                                                                                | ((0x2033U 
                                                                                == 
                                                                                (0xfe00707fU 
                                                                                & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                                                << 0xcU) 
                                                                                | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                                                >> 0x14U)))) 
                                                                                | ((0x3033U 
                                                                                == 
                                                                                (0xfe00707fU 
                                                                                & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                                                << 0xcU) 
                                                                                | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                                                >> 0x14U)))) 
                                                                                | ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT____VdfgRegularize_h2cfc3394_0_25) 
                                                                                | ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT____VdfgRegularize_h2cfc3394_0_24) 
                                                                                | ((0x40000033U 
                                                                                == 
                                                                                (0xfe00707fU 
                                                                                & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                                                << 0xcU) 
                                                                                | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                                                >> 0x14U)))) 
                                                                                | (0x4033U 
                                                                                == 
                                                                                (0xfe00707fU 
                                                                                & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                                                << 0xcU) 
                                                                                | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                                                >> 0x14U))))))))))))))))))))))))))))))))));
    CPU_top__DOT__cpu__DOT__decode__DOT____VdfgRegularize_h2cfc3394_0_12 
        = ((0x20000053U == (0xfe00707fU & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                            << 0xcU) 
                                           | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                              >> 0x14U)))) 
           | ((0x20001053U == (0xfe00707fU & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                               << 0xcU) 
                                              | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                 >> 0x14U)))) 
              | (IData)(CPU_top__DOT__cpu__DOT__decode__DOT____VdfgRegularize_h2cfc3394_0_11)));
    vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT____VdfgRegularize_h2cfc3394_0_18 
        = ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__is_CSR) 
           | (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__have_RS3));
    vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__RS1_bank 
        = ((0x53U == (0xfe00007fU & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                      << 0xcU) | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                  >> 0x14U)))) 
           | ((0xc0000053U == (0xfff0007fU & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                               << 0xcU) 
                                              | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                 >> 0x14U)))) 
              | ((0xc0100053U == (0xfff0007fU & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                  << 0xcU) 
                                                 | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                    >> 0x14U)))) 
                 | ((0x18000053U == (0xfe00007fU & 
                                     ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                       << 0xcU) | (
                                                   vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                   >> 0x14U)))) 
                    | ((0xa0002053U == (0xfe00707fU 
                                        & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                            << 0xcU) 
                                           | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                              >> 0x14U)))) 
                       | ((0xa0000053U == (0xfe00707fU 
                                           & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                               << 0xcU) 
                                              | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                 >> 0x14U)))) 
                          | ((0xa0001053U == (0xfe00707fU 
                                              & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                  << 0xcU) 
                                                 | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                    >> 0x14U)))) 
                             | ((0x43U == (0x600007fU 
                                           & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                               << 0xcU) 
                                              | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                 >> 0x14U)))) 
                                | ((0x47U == (0x600007fU 
                                              & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                  << 0xcU) 
                                                 | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                    >> 0x14U)))) 
                                   | ((0x4fU == (0x600007fU 
                                                 & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                     << 0xcU) 
                                                    | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                       >> 0x14U)))) 
                                      | ((0x4bU == 
                                          (0x600007fU 
                                           & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                               << 0xcU) 
                                              | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                 >> 0x14U)))) 
                                         | ((0x28000053U 
                                             == (0xfe00707fU 
                                                 & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                     << 0xcU) 
                                                    | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                       >> 0x14U)))) 
                                            | ((0x28001053U 
                                                == 
                                                (0xfe00707fU 
                                                 & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                     << 0xcU) 
                                                    | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                       >> 0x14U)))) 
                                               | ((0x10000053U 
                                                   == 
                                                   (0xfe00007fU 
                                                    & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                        << 0xcU) 
                                                       | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                          >> 0x14U)))) 
                                                  | ((0xe0000053U 
                                                      == 
                                                      (0xfff0707fU 
                                                       & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                           << 0xcU) 
                                                          | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                             >> 0x14U)))) 
                                                     | (IData)(CPU_top__DOT__cpu__DOT__decode__DOT____VdfgRegularize_h2cfc3394_0_12))))))))))))))));
    CPU_top__DOT__cpu__DOT__decode__DOT____VdfgRegularize_h2cfc3394_0_13 
        = ((0xf0000053U == (0xfff0707fU & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                            << 0xcU) 
                                           | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                              >> 0x14U)))) 
           | (IData)(CPU_top__DOT__cpu__DOT__decode__DOT____VdfgRegularize_h2cfc3394_0_12));
    vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__RD_bank 
        = ((0x53U == (0xfe00007fU & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                      << 0xcU) | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                  >> 0x14U)))) 
           | ((0xd0000053U == (0xfff0007fU & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                               << 0xcU) 
                                              | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                 >> 0x14U)))) 
              | ((0xd0100053U == (0xfff0007fU & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                  << 0xcU) 
                                                 | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                    >> 0x14U)))) 
                 | ((0x18000053U == (0xfe00007fU & 
                                     ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                       << 0xcU) | (
                                                   vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                   >> 0x14U)))) 
                    | ((0x2007U == (0x707fU & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                << 0xcU) 
                                               | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                  >> 0x14U)))) 
                       | ((0x43U == (0x600007fU & (
                                                   (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                    << 0xcU) 
                                                   | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                      >> 0x14U)))) 
                          | ((0x47U == (0x600007fU 
                                        & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                            << 0xcU) 
                                           | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                              >> 0x14U)))) 
                             | ((0x4fU == (0x600007fU 
                                           & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                               << 0xcU) 
                                              | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                 >> 0x14U)))) 
                                | ((0x4bU == (0x600007fU 
                                              & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                  << 0xcU) 
                                                 | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                    >> 0x14U)))) 
                                   | ((0x28000053U 
                                       == (0xfe00707fU 
                                           & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                               << 0xcU) 
                                              | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                 >> 0x14U)))) 
                                      | ((0x28001053U 
                                          == (0xfe00707fU 
                                              & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                  << 0xcU) 
                                                 | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                    >> 0x14U)))) 
                                         | ((0x10000053U 
                                             == (0xfe00007fU 
                                                 & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                     << 0xcU) 
                                                    | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                       >> 0x14U)))) 
                                            | (IData)(CPU_top__DOT__cpu__DOT__decode__DOT____VdfgRegularize_h2cfc3394_0_13)))))))))))));
    vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__is_FPU 
        = ((IData)(CPU_top__DOT__cpu__DOT__decode__DOT____VdfgRegularize_h2cfc3394_0_10) 
           | ((IData)(CPU_top__DOT__cpu__DOT__decode__DOT____VdfgRegularize_h2cfc3394_0_21) 
              | ((0xd0100053U == (0xfff0007fU & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                  << 0xcU) 
                                                 | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                    >> 0x14U)))) 
                 | ((0x18000053U == (0xfe00007fU & 
                                     ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                       << 0xcU) | (
                                                   vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                   >> 0x14U)))) 
                    | ((0xa0002053U == (0xfe00707fU 
                                        & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                            << 0xcU) 
                                           | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                              >> 0x14U)))) 
                       | ((0xa0000053U == (0xfe00707fU 
                                           & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                               << 0xcU) 
                                              | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                 >> 0x14U)))) 
                          | ((0xa0001053U == (0xfe00707fU 
                                              & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                  << 0xcU) 
                                                 | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                    >> 0x14U)))) 
                             | ((0x43U == (0x600007fU 
                                           & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                               << 0xcU) 
                                              | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                 >> 0x14U)))) 
                                | ((0x47U == (0x600007fU 
                                              & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                  << 0xcU) 
                                                 | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                    >> 0x14U)))) 
                                   | ((0x4fU == (0x600007fU 
                                                 & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                     << 0xcU) 
                                                    | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                       >> 0x14U)))) 
                                      | ((0x4bU == 
                                          (0x600007fU 
                                           & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                               << 0xcU) 
                                              | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                 >> 0x14U)))) 
                                         | ((0x28000053U 
                                             == (0xfe00707fU 
                                                 & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                     << 0xcU) 
                                                    | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                       >> 0x14U)))) 
                                            | ((0x28001053U 
                                                == 
                                                (0xfe00707fU 
                                                 & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                     << 0xcU) 
                                                    | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                       >> 0x14U)))) 
                                               | ((0x10000053U 
                                                   == 
                                                   (0xfe00007fU 
                                                    & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                        << 0xcU) 
                                                       | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                          >> 0x14U)))) 
                                                  | ((0xe0000053U 
                                                      == 
                                                      (0xfff0707fU 
                                                       & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                           << 0xcU) 
                                                          | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                             >> 0x14U)))) 
                                                     | (IData)(CPU_top__DOT__cpu__DOT__decode__DOT____VdfgRegularize_h2cfc3394_0_13))))))))))))))));
}

VL_ATTR_COLD void VCPU_top___024root___stl_sequent__TOP__1(VCPU_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCPU_top___024root___stl_sequent__TOP__1\n"); );
    VCPU_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__ready[2U] 
        = vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__ready
        [1U];
    vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__ready[4U] 
        = vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__ready
        [3U];
    vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__ready[5U] 
        = vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__ready
        [4U];
    vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__ready[6U] 
        = vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__ready
        [5U];
    vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__ready[8U] 
        = vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__ready
        [7U];
    vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__ready[9U] 
        = vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__ready
        [8U];
    vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__ready[0xaU] 
        = vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__ready
        [9U];
    vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__ready[0xcU] 
        = vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__ready
        [0xbU];
    vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__ready[0xdU] 
        = vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__ready
        [0xcU];
    vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__ready[0xeU] 
        = vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__ready
        [0xdU];
    vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__ready[0x10U] 
        = vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__ready
        [0xfU];
    vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__ready[0x11U] 
        = vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__ready
        [0x10U];
    vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__ready[0x12U] 
        = vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__ready
        [0x11U];
    vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__ready[0x14U] 
        = vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__ready
        [0x13U];
    vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__ready[0x15U] 
        = vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__ready
        [0x14U];
    vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__ready[0x16U] 
        = vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__ready
        [0x15U];
    vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__ready[0x18U] 
        = vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__ready
        [0x17U];
    vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__ready[0x19U] 
        = vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__ready
        [0x18U];
    vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__ready[0x1aU] 
        = vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__ready
        [0x19U];
    vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__ready[0x1cU] 
        = vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__ready
        [0x1bU];
    vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__ready[0x1dU] 
        = vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__ready
        [0x1cU];
    vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__ready[0x1fU] 
        = vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__ready
        [0x1eU];
}

VL_ATTR_COLD void VCPU_top___024root___stl_sequent__TOP__3(VCPU_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCPU_top___024root___stl_sequent__TOP__3\n"); );
    VCPU_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__1__KET____DOT__q 
        = ((~ (IData)((0U != VL_SHIFTR_III(32,32,32, 
                                           vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                           [1U], 2U)))) 
           & ((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
               [1U] >> 0x1eU) >= (3U & vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                  [1U])));
    vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__3__KET____DOT__q 
        = ((~ (IData)((0U != VL_SHIFTR_III(32,32,32, 
                                           vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                           [3U], 4U)))) 
           & ((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
               [3U] >> 0x1cU) >= (0xfU & vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                  [3U])));
    vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__4__KET____DOT__q 
        = ((~ (IData)((0U != VL_SHIFTR_III(32,32,32, 
                                           vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                           [4U], 5U)))) 
           & ((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
               [4U] >> 0x1bU) >= (0x1fU & vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                  [4U])));
    vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__5__KET____DOT__q 
        = ((~ (IData)((0U != VL_SHIFTR_III(32,32,32, 
                                           vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                           [5U], 6U)))) 
           & ((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
               [5U] >> 0x1aU) >= (0x3fU & vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                  [5U])));
    vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__7__KET____DOT__q 
        = ((~ (IData)((0U != VL_SHIFTR_III(32,32,32, 
                                           vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                           [7U], 8U)))) 
           & ((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
               [7U] >> 0x18U) >= (0xffU & vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                  [7U])));
    vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__8__KET____DOT__q 
        = ((~ (IData)((0U != VL_SHIFTR_III(32,32,32, 
                                           vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                           [8U], 9U)))) 
           & ((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
               [8U] >> 0x17U) >= (0x1ffU & vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                  [8U])));
    vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__9__KET____DOT__q 
        = ((~ (IData)((0U != VL_SHIFTR_III(32,32,32, 
                                           vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                           [9U], 0xaU)))) 
           & ((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
               [9U] >> 0x16U) >= (0x3ffU & vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                  [9U])));
    vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__11__KET____DOT__q 
        = ((~ (IData)((0U != VL_SHIFTR_III(32,32,32, 
                                           vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                           [0xbU], 0xcU)))) 
           & ((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
               [0xbU] >> 0x14U) >= (0xfffU & vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                    [0xbU])));
    vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__12__KET____DOT__q 
        = ((~ (IData)((0U != VL_SHIFTR_III(32,32,32, 
                                           vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                           [0xcU], 0xdU)))) 
           & ((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
               [0xcU] >> 0x13U) >= (0x1fffU & vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                    [0xcU])));
    vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__13__KET____DOT__q 
        = ((~ (IData)((0U != VL_SHIFTR_III(32,32,32, 
                                           vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                           [0xdU], 0xeU)))) 
           & ((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
               [0xdU] >> 0x12U) >= (0x3fffU & vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                    [0xdU])));
    vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__15__KET____DOT__q 
        = ((~ (IData)((0U != VL_SHIFTR_III(32,32,32, 
                                           vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                           [0xfU], 0x10U)))) 
           & ((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
               [0xfU] >> 0x10U) >= (0xffffU & vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                    [0xfU])));
    vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__16__KET____DOT__q 
        = ((~ (IData)((0U != VL_SHIFTR_III(32,32,32, 
                                           vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                           [0x10U], 0x11U)))) 
           & ((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
               [0x10U] >> 0xfU) >= (0x1ffffU & vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                    [0x10U])));
    vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__17__KET____DOT__q 
        = ((~ (IData)((0U != VL_SHIFTR_III(32,32,32, 
                                           vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                           [0x11U], 0x12U)))) 
           & ((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
               [0x11U] >> 0xeU) >= (0x3ffffU & vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                    [0x11U])));
    vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__19__KET____DOT__q 
        = ((~ (IData)((0U != VL_SHIFTR_III(32,32,32, 
                                           vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                           [0x13U], 0x14U)))) 
           & ((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
               [0x13U] >> 0xcU) >= (0xfffffU & vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                    [0x13U])));
    vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__20__KET____DOT__q 
        = ((~ (IData)((0U != VL_SHIFTR_III(32,32,32, 
                                           vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                           [0x14U], 0x15U)))) 
           & ((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
               [0x14U] >> 0xbU) >= (0x1fffffU & vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                    [0x14U])));
    vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__21__KET____DOT__q 
        = ((~ (IData)((0U != VL_SHIFTR_III(32,32,32, 
                                           vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                           [0x15U], 0x16U)))) 
           & ((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
               [0x15U] >> 0xaU) >= (0x3fffffU & vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                    [0x15U])));
    vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__23__KET____DOT__q 
        = ((~ (IData)((0U != VL_SHIFTR_III(32,32,32, 
                                           vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                           [0x17U], 0x18U)))) 
           & ((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
               [0x17U] >> 8U) >= (0xffffffU & vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                  [0x17U])));
    vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__24__KET____DOT__q 
        = ((~ (IData)((0U != VL_SHIFTR_III(32,32,32, 
                                           vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                           [0x18U], 0x19U)))) 
           & ((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
               [0x18U] >> 7U) >= (0x1ffffffU & vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                  [0x18U])));
    vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__25__KET____DOT__q 
        = ((~ (IData)((0U != VL_SHIFTR_III(32,32,32, 
                                           vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                           [0x19U], 0x1aU)))) 
           & ((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
               [0x19U] >> 6U) >= (0x3ffffffU & vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                  [0x19U])));
    vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__27__KET____DOT__q 
        = ((~ (IData)((0U != VL_SHIFTR_III(32,32,32, 
                                           vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                           [0x1bU], 0x1cU)))) 
           & ((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
               [0x1bU] >> 4U) >= (0xfffffffU & vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                  [0x1bU])));
    vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__28__KET____DOT__q 
        = ((~ (IData)((0U != VL_SHIFTR_III(32,32,32, 
                                           vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                           [0x1cU], 0x1dU)))) 
           & ((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
               [0x1cU] >> 3U) >= (0x1fffffffU & vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                  [0x1cU])));
    vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__30__KET____DOT__q 
        = ((~ (IData)((0U != VL_SHIFTR_III(32,32,32, 
                                           vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                           [0x1eU], 0x1fU)))) 
           & ((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
               [0x1eU] >> 1U) >= (0x7fffffffU & vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                  [0x1eU])));
}

VL_ATTR_COLD void VCPU_top___024root___stl_comb__TOP__0(VCPU_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCPU_top___024root___stl_comb__TOP__0\n"); );
    VCPU_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__ack 
        = vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__ready
        [0x20U];
    vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__div_ready 
        = ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__div_request) 
           & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__ack));
}

VL_ATTR_COLD void VCPU_top___024root___stl_comb__TOP__2(VCPU_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCPU_top___024root___stl_comb__TOP__2\n"); );
    VCPU_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    QData/*33:0*/ CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__1__KET____DOT__d;
    CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__1__KET____DOT__d = 0;
    QData/*35:0*/ CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__3__KET____DOT__d;
    CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__3__KET____DOT__d = 0;
    QData/*36:0*/ CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__4__KET____DOT__d;
    CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__4__KET____DOT__d = 0;
    QData/*37:0*/ CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__5__KET____DOT__d;
    CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__5__KET____DOT__d = 0;
    QData/*39:0*/ CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__7__KET____DOT__d;
    CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__7__KET____DOT__d = 0;
    QData/*40:0*/ CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__8__KET____DOT__d;
    CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__8__KET____DOT__d = 0;
    QData/*41:0*/ CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__9__KET____DOT__d;
    CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__9__KET____DOT__d = 0;
    QData/*43:0*/ CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__11__KET____DOT__d;
    CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__11__KET____DOT__d = 0;
    QData/*44:0*/ CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__12__KET____DOT__d;
    CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__12__KET____DOT__d = 0;
    QData/*45:0*/ CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__13__KET____DOT__d;
    CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__13__KET____DOT__d = 0;
    QData/*47:0*/ CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__15__KET____DOT__d;
    CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__15__KET____DOT__d = 0;
    QData/*48:0*/ CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__16__KET____DOT__d;
    CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__16__KET____DOT__d = 0;
    QData/*49:0*/ CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__17__KET____DOT__d;
    CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__17__KET____DOT__d = 0;
    QData/*51:0*/ CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__19__KET____DOT__d;
    CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__19__KET____DOT__d = 0;
    QData/*52:0*/ CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__20__KET____DOT__d;
    CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__20__KET____DOT__d = 0;
    QData/*53:0*/ CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__21__KET____DOT__d;
    CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__21__KET____DOT__d = 0;
    QData/*55:0*/ CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__23__KET____DOT__d;
    CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__23__KET____DOT__d = 0;
    QData/*56:0*/ CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__24__KET____DOT__d;
    CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__24__KET____DOT__d = 0;
    QData/*57:0*/ CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__25__KET____DOT__d;
    CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__25__KET____DOT__d = 0;
    QData/*59:0*/ CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__27__KET____DOT__d;
    CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__27__KET____DOT__d = 0;
    QData/*60:0*/ CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__28__KET____DOT__d;
    CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__28__KET____DOT__d = 0;
    QData/*62:0*/ CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__30__KET____DOT__d;
    CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__30__KET____DOT__d = 0;
    // Body
    CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__1__KET____DOT__d 
        = (0x3ffffffffULL & VL_SHIFTR_QQI(34,34,32, 
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
                                                                           [1U], 2U)))), 2U));
    CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__3__KET____DOT__d 
        = (0xfffffffffULL & VL_SHIFTR_QQI(36,36,32, 
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
                                                                           [3U], 4U)))), 4U));
    CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__4__KET____DOT__d 
        = (0x1fffffffffULL & VL_SHIFTR_QQI(37,37,32, 
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
                                                                            [4U], 5U)))), 5U));
    CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__5__KET____DOT__d 
        = (0x3fffffffffULL & VL_SHIFTR_QQI(38,38,32, 
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
                                                                            [5U], 6U)))), 6U));
    CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__7__KET____DOT__d 
        = (0xffffffffffULL & VL_SHIFTR_QQI(40,40,32, 
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
                                                                            [7U], 8U)))), 8U));
    CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__8__KET____DOT__d 
        = (0x1ffffffffffULL & VL_SHIFTR_QQI(41,41,32, 
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
                                                                             [8U], 9U)))), 9U));
    CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__9__KET____DOT__d 
        = (0x3ffffffffffULL & VL_SHIFTR_QQI(42,42,32, 
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
                                                                             [9U], 0xaU)))), 0xaU));
    CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__11__KET____DOT__d 
        = (0xfffffffffffULL & VL_SHIFTR_QQI(44,44,32, 
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
                                                                             [0xbU], 0xcU)))), 0xcU));
    CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__12__KET____DOT__d 
        = (0x1fffffffffffULL & VL_SHIFTR_QQI(45,45,32, 
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
                                                                              [0xcU], 0xdU)))), 0xdU));
    CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__13__KET____DOT__d 
        = (0x3fffffffffffULL & VL_SHIFTR_QQI(46,46,32, 
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
                                                                              [0xdU], 0xeU)))), 0xeU));
    CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__15__KET____DOT__d 
        = (0xffffffffffffULL & VL_SHIFTR_QQI(48,48,32, 
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
                                                                              [0xfU], 0x10U)))), 0x10U));
    CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__16__KET____DOT__d 
        = (0x1ffffffffffffULL & VL_SHIFTR_QQI(49,49,32, 
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
                                                                               [0x10U], 0x11U)))), 0x11U));
    CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__17__KET____DOT__d 
        = (0x3ffffffffffffULL & VL_SHIFTR_QQI(50,50,32, 
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
                                                                               [0x11U], 0x12U)))), 0x12U));
    CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__19__KET____DOT__d 
        = (0xfffffffffffffULL & VL_SHIFTR_QQI(52,52,32, 
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
                                                                               [0x13U], 0x14U)))), 0x14U));
    CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__20__KET____DOT__d 
        = (0x1fffffffffffffULL & VL_SHIFTR_QQI(53,53,32, 
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
                                                                                [0x14U], 0x15U)))), 0x15U));
    CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__21__KET____DOT__d 
        = (0x3fffffffffffffULL & VL_SHIFTR_QQI(54,54,32, 
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
                                                                                [0x15U], 0x16U)))), 0x16U));
    CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__23__KET____DOT__d 
        = (0xffffffffffffffULL & VL_SHIFTR_QQI(56,56,32, 
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
                                                                                [0x17U], 0x18U)))), 0x18U));
    CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__24__KET____DOT__d 
        = (0x1ffffffffffffffULL & VL_SHIFTR_QQI(57,57,32, 
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
                                                                                [0x18U], 0x19U)))), 0x19U));
    CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__25__KET____DOT__d 
        = (0x3ffffffffffffffULL & VL_SHIFTR_QQI(58,58,32, 
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
                                                                                [0x19U], 0x1aU)))), 0x1aU));
    CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__27__KET____DOT__d 
        = (0xfffffffffffffffULL & VL_SHIFTR_QQI(60,60,32, 
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
                                                                                [0x1bU], 0x1cU)))), 0x1cU));
    CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__28__KET____DOT__d 
        = (0x1fffffffffffffffULL & VL_SHIFTR_QQI(61,61,32, 
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
                                                                                [0x1cU], 0x1dU)))), 0x1dU));
    CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__30__KET____DOT__d 
        = (0x7fffffffffffffffULL & VL_SHIFTR_QQI(63,63,32, 
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
                                                                                [0x1eU], 0x1fU)))), 0x1fU));
    vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend[2U] 
        = (IData)(CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__1__KET____DOT__d);
    vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend[4U] 
        = (IData)(CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__3__KET____DOT__d);
    vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend[5U] 
        = (IData)(CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__4__KET____DOT__d);
    vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend[6U] 
        = (IData)(CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__5__KET____DOT__d);
    vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend[8U] 
        = (IData)(CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__7__KET____DOT__d);
    vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend[9U] 
        = (IData)(CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__8__KET____DOT__d);
    vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend[0xaU] 
        = (IData)(CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__9__KET____DOT__d);
    vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend[0xcU] 
        = (IData)(CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__11__KET____DOT__d);
    vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend[0xdU] 
        = (IData)(CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__12__KET____DOT__d);
    vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend[0xeU] 
        = (IData)(CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__13__KET____DOT__d);
    vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend[0x10U] 
        = (IData)(CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__15__KET____DOT__d);
    vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend[0x11U] 
        = (IData)(CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__16__KET____DOT__d);
    vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend[0x12U] 
        = (IData)(CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__17__KET____DOT__d);
    vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend[0x14U] 
        = (IData)(CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__19__KET____DOT__d);
    vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend[0x15U] 
        = (IData)(CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__20__KET____DOT__d);
    vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend[0x16U] 
        = (IData)(CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__21__KET____DOT__d);
    vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend[0x18U] 
        = (IData)(CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__23__KET____DOT__d);
    vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend[0x19U] 
        = (IData)(CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__24__KET____DOT__d);
    vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend[0x1aU] 
        = (IData)(CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__25__KET____DOT__d);
    vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend[0x1cU] 
        = (IData)(CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__27__KET____DOT__d);
    vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend[0x1dU] 
        = (IData)(CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__28__KET____DOT__d);
    vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend[0x1fU] 
        = (IData)(CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__30__KET____DOT__d);
    vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__div_remainder 
        = (((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__div_signed) 
            & ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__s) 
               >> 1U)) ? (- vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                          [0x20U]) : vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
           [0x20U]);
    vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__0__KET____DOT__q 
        = ((~ (IData)((0U != VL_SHIFTR_III(32,32,32, 
                                           vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                           [0U], 1U)))) 
           & ((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
               [0U] >> 0x1fU) >= (1U & vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                  [0U])));
    vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__2__KET____DOT__q 
        = ((~ (IData)((0U != VL_SHIFTR_III(32,32,32, 
                                           vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                           [2U], 3U)))) 
           & ((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
               [2U] >> 0x1dU) >= (7U & vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                  [2U])));
    vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__6__KET____DOT__q 
        = ((~ (IData)((0U != VL_SHIFTR_III(32,32,32, 
                                           vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                           [6U], 7U)))) 
           & ((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
               [6U] >> 0x19U) >= (0x7fU & vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                  [6U])));
    vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__10__KET____DOT__q 
        = ((~ (IData)((0U != VL_SHIFTR_III(32,32,32, 
                                           vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                           [0xaU], 0xbU)))) 
           & ((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
               [0xaU] >> 0x15U) >= (0x7ffU & vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                    [0xaU])));
    vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__14__KET____DOT__q 
        = ((~ (IData)((0U != VL_SHIFTR_III(32,32,32, 
                                           vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                           [0xeU], 0xfU)))) 
           & ((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
               [0xeU] >> 0x11U) >= (0x7fffU & vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                    [0xeU])));
    vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__18__KET____DOT__q 
        = ((~ (IData)((0U != VL_SHIFTR_III(32,32,32, 
                                           vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                           [0x12U], 0x13U)))) 
           & ((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
               [0x12U] >> 0xdU) >= (0x7ffffU & vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                    [0x12U])));
    vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__22__KET____DOT__q 
        = ((~ (IData)((0U != VL_SHIFTR_III(32,32,32, 
                                           vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                           [0x16U], 0x17U)))) 
           & ((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
               [0x16U] >> 9U) >= (0x7fffffU & vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                  [0x16U])));
    vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__26__KET____DOT__q 
        = ((~ (IData)((0U != VL_SHIFTR_III(32,32,32, 
                                           vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                           [0x1aU], 0x1bU)))) 
           & ((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
               [0x1aU] >> 5U) >= (0x7ffffffU & vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                  [0x1aU])));
    vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__29__KET____DOT__q 
        = ((~ (IData)((0U != VL_SHIFTR_III(32,32,32, 
                                           vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                           [0x1dU], 0x1eU)))) 
           & ((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
               [0x1dU] >> 2U) >= (0x3fffffffU & vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                  [0x1dU])));
    vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__31__KET____DOT__q 
        = (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
           [0x1fU] >= vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
           [0x1fU]);
    vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__0__KET____DOT__d 
        = (0x1ffffffffULL & VL_SHIFTR_QQI(33,33,32, 
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
                                                                           [0U], 1U)))), 1U));
    vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__2__KET____DOT__d 
        = (0x7ffffffffULL & VL_SHIFTR_QQI(35,35,32, 
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
                                                                           [2U], 3U)))), 3U));
    vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__6__KET____DOT__d 
        = (0x7fffffffffULL & VL_SHIFTR_QQI(39,39,32, 
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
                                                                            [6U], 7U)))), 7U));
    vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__10__KET____DOT__d 
        = (0x7ffffffffffULL & VL_SHIFTR_QQI(43,43,32, 
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
                                                                             [0xaU], 0xbU)))), 0xbU));
    vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__14__KET____DOT__d 
        = (0x7fffffffffffULL & VL_SHIFTR_QQI(47,47,32, 
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
                                                                              [0xeU], 0xfU)))), 0xfU));
    vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__18__KET____DOT__d 
        = (0x7ffffffffffffULL & VL_SHIFTR_QQI(51,51,32, 
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
                                                                               [0x12U], 0x13U)))), 0x13U));
    vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__22__KET____DOT__d 
        = (0x7fffffffffffffULL & VL_SHIFTR_QQI(55,55,32, 
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
                                                                                [0x16U], 0x17U)))), 0x17U));
    vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__26__KET____DOT__d 
        = (0x7ffffffffffffffULL & VL_SHIFTR_QQI(59,59,32, 
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
                                                                                [0x1aU], 0x1bU)))), 0x1bU));
    vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__29__KET____DOT__d 
        = (0x3fffffffffffffffULL & VL_SHIFTR_QQI(62,62,32, 
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
                                                                                [0x1dU], 0x1eU)))), 0x1eU));
    vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__31__KET____DOT__t 
        = ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__31__KET____DOT__q)
            ? (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
               [0x1fU] - vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
               [0x1fU]) : vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
           [0x1fU]);
}

VL_ATTR_COLD void VCPU_top___024root___eval_triggers__stl(VCPU_top___024root* vlSelf);

VL_ATTR_COLD bool VCPU_top___024root___eval_phase__stl(VCPU_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCPU_top___024root___eval_phase__stl\n"); );
    VCPU_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VstlExecute;
    // Body
    VCPU_top___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = vlSelfRef.__VstlTriggered.any();
    if (__VstlExecute) {
        VCPU_top___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VCPU_top___024root___dump_triggers__ico(VCPU_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCPU_top___024root___dump_triggers__ico\n"); );
    VCPU_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VicoTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VicoTriggered.word(0U))) {
        VL_DBG_MSGF("         'ico' region trigger index 0 is active: Internal 'ico' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void VCPU_top___024root___dump_triggers__act(VCPU_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCPU_top___024root___dump_triggers__act\n"); );
    VCPU_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VactTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @([hybrid] CPU_top.cpu.execute.divide.df.quotient)\n");
    }
    if ((2ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 1 is active: @([hybrid] CPU_top.cpu.execute.divide.df.dividend)\n");
    }
    if ((4ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 2 is active: @([hybrid] CPU_top.cpu.execute.divide.df.divisor)\n");
    }
    if ((8ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 3 is active: @([hybrid] CPU_top.cpu.execute.divide.df.ready)\n");
    }
    if ((0x10ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 4 is active: @(posedge clock)\n");
    }
    if ((0x20ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 5 is active: @(posedge reset)\n");
    }
    if ((0x40ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 6 is active: @(posedge CPU_top.cpu.execute.divide.__Vcellinp__df__rst)\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void VCPU_top___024root___dump_triggers__nba(VCPU_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCPU_top___024root___dump_triggers__nba\n"); );
    VCPU_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VnbaTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @([hybrid] CPU_top.cpu.execute.divide.df.quotient)\n");
    }
    if ((2ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 1 is active: @([hybrid] CPU_top.cpu.execute.divide.df.dividend)\n");
    }
    if ((4ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 2 is active: @([hybrid] CPU_top.cpu.execute.divide.df.divisor)\n");
    }
    if ((8ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 3 is active: @([hybrid] CPU_top.cpu.execute.divide.df.ready)\n");
    }
    if ((0x10ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 4 is active: @(posedge clock)\n");
    }
    if ((0x20ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 5 is active: @(posedge reset)\n");
    }
    if ((0x40ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 6 is active: @(posedge CPU_top.cpu.execute.divide.__Vcellinp__df__rst)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void VCPU_top___024root____Vm_traceActivitySetAll(VCPU_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCPU_top___024root____Vm_traceActivitySetAll\n"); );
    VCPU_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vm_traceActivity[0U] = 1U;
    vlSelfRef.__Vm_traceActivity[1U] = 1U;
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.__Vm_traceActivity[3U] = 1U;
    vlSelfRef.__Vm_traceActivity[4U] = 1U;
    vlSelfRef.__Vm_traceActivity[5U] = 1U;
    vlSelfRef.__Vm_traceActivity[6U] = 1U;
    vlSelfRef.__Vm_traceActivity[7U] = 1U;
    vlSelfRef.__Vm_traceActivity[8U] = 1U;
    vlSelfRef.__Vm_traceActivity[9U] = 1U;
}

VL_ATTR_COLD void VCPU_top___024root___ctor_var_reset(VCPU_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCPU_top___024root___ctor_var_reset\n"); );
    VCPU_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelf->reset = VL_RAND_RESET_I(1);
    vlSelf->clock = VL_RAND_RESET_I(1);
    vlSelf->bus_rw = VL_RAND_RESET_I(1);
    vlSelf->bus_request = VL_RAND_RESET_I(1);
    vlSelf->bus_ready = VL_RAND_RESET_I(1);
    vlSelf->bus_address = VL_RAND_RESET_I(32);
    vlSelf->bus_rdata = VL_RAND_RESET_I(32);
    vlSelf->bus_wdata = VL_RAND_RESET_I(32);
    vlSelf->cpu_fault = VL_RAND_RESET_I(1);
    vlSelf->CPU_top__DOT__cpu_ibus_request = VL_RAND_RESET_I(1);
    vlSelf->CPU_top__DOT__cpu_ibus_ready = VL_RAND_RESET_I(1);
    vlSelf->CPU_top__DOT__cpu_ibus_address = VL_RAND_RESET_I(32);
    vlSelf->CPU_top__DOT__cpu_dbus_rw = VL_RAND_RESET_I(1);
    vlSelf->CPU_top__DOT__cpu_dbus_request = VL_RAND_RESET_I(1);
    vlSelf->CPU_top__DOT__cpu_dbus_ready = VL_RAND_RESET_I(1);
    vlSelf->CPU_top__DOT__cpu_dbus_address = VL_RAND_RESET_I(32);
    vlSelf->CPU_top__DOT__bus__DOT__state = 0;
    vlSelf->CPU_top__DOT__bus__DOT__next_state = 0;
    vlSelf->CPU_top__DOT__cpu__DOT__o_dcache_hit = VL_RAND_RESET_I(32);
    vlSelf->CPU_top__DOT__cpu__DOT__o_dcache_miss = VL_RAND_RESET_I(32);
    vlSelf->CPU_top__DOT__cpu__DOT__csr_rdata = VL_RAND_RESET_I(32);
    vlSelf->CPU_top__DOT__cpu__DOT__csr_wdata_wr = VL_RAND_RESET_I(1);
    vlSelf->CPU_top__DOT__cpu__DOT__csr_wdata = VL_RAND_RESET_I(32);
    vlSelf->CPU_top__DOT__cpu__DOT__csr_irq_pending = VL_RAND_RESET_I(1);
    vlSelf->CPU_top__DOT__cpu__DOT__csr_irq_pc = VL_RAND_RESET_I(32);
    vlSelf->CPU_top__DOT__cpu__DOT__csr_irq_dispatched = VL_RAND_RESET_I(1);
    vlSelf->CPU_top__DOT__cpu__DOT__csr_irq_epc = VL_RAND_RESET_I(32);
    vlSelf->CPU_top__DOT__cpu__DOT____Vcellinp__fetch__i_busy = VL_RAND_RESET_I(1);
    VL_ZERO_RESET_W(117, vlSelf->CPU_top__DOT__cpu__DOT__fetch_data);
    vlSelf->CPU_top__DOT__cpu__DOT__decode_fault = VL_RAND_RESET_I(1);
    vlSelf->CPU_top__DOT__cpu__DOT__execute_fault = VL_RAND_RESET_I(1);
    vlSelf->CPU_top__DOT__cpu__DOT__execute_jump = VL_RAND_RESET_I(1);
    vlSelf->CPU_top__DOT__cpu__DOT__execute_jump_pc = VL_RAND_RESET_I(32);
    vlSelf->CPU_top__DOT__cpu__DOT__execute_ecall = VL_RAND_RESET_I(1);
    vlSelf->CPU_top__DOT__cpu__DOT__execute_mret = VL_RAND_RESET_I(1);
    vlSelf->CPU_top__DOT__cpu__DOT__memory_busy = VL_RAND_RESET_I(1);
    vlSelf->CPU_top__DOT__cpu__DOT__csr__DOT__mstatus_mpie = 0;
    vlSelf->CPU_top__DOT__cpu__DOT__csr__DOT__mstatus_mie = 0;
    vlSelf->CPU_top__DOT__cpu__DOT__csr__DOT__mie_meie = 0;
    vlSelf->CPU_top__DOT__cpu__DOT__csr__DOT__mie_mtie = 0;
    vlSelf->CPU_top__DOT__cpu__DOT__csr__DOT__mie_msie = 0;
    vlSelf->CPU_top__DOT__cpu__DOT__csr__DOT__mtvec = 0;
    vlSelf->CPU_top__DOT__cpu__DOT__csr__DOT__mepc = 0;
    vlSelf->CPU_top__DOT__cpu__DOT__csr__DOT__mcause = 0;
    vlSelf->CPU_top__DOT__cpu__DOT__csr__DOT__mip_meip = 0;
    vlSelf->CPU_top__DOT__cpu__DOT__csr__DOT__mip_mtip = 0;
    vlSelf->CPU_top__DOT__cpu__DOT__csr__DOT__mip_msip = 0;
    vlSelf->CPU_top__DOT__cpu__DOT__csr__DOT__mscratch = 0;
    vlSelf->CPU_top__DOT__cpu__DOT__csr__DOT__cycle = 0;
    vlSelf->CPU_top__DOT__cpu__DOT__csr__DOT__wtime = 0;
    vlSelf->CPU_top__DOT__cpu__DOT__csr__DOT__prescale = 0;
    vlSelf->CPU_top__DOT__cpu__DOT__csr__DOT__issued = 0;
    vlSelf->CPU_top__DOT__cpu__DOT__registers__DOT__last_write_strobe = 0;
    for (int __Vi0 = 0; __Vi0 < 32; ++__Vi0) {
        vlSelf->CPU_top__DOT__cpu__DOT__registers__DOT__r[__Vi0] = 0;
    }
    vlSelf->CPU_top__DOT__cpu__DOT__registers__DOT__rs1 = 0;
    vlSelf->CPU_top__DOT__cpu__DOT__registers__DOT__rs2 = 0;
    vlSelf->CPU_top__DOT__cpu__DOT__registers__DOT__rs3 = 0;
    vlSelf->CPU_top__DOT__cpu__DOT__registers__DOT__I = VL_RAND_RESET_I(32);
    vlSelf->CPU_top__DOT__cpu__DOT__fetch__DOT__state = 0;
    vlSelf->CPU_top__DOT__cpu__DOT__fetch__DOT__pc = 0;
    VL_ZERO_RESET_W(117, vlSelf->CPU_top__DOT__cpu__DOT__fetch__DOT__data);
    vlSelf->CPU_top__DOT__cpu__DOT__fetch__DOT__icache_ready = VL_RAND_RESET_I(1);
    vlSelf->CPU_top__DOT__cpu__DOT__fetch__DOT__is_I = VL_RAND_RESET_I(1);
    vlSelf->CPU_top__DOT__cpu__DOT__fetch__DOT__is_R = VL_RAND_RESET_I(1);
    vlSelf->CPU_top__DOT__cpu__DOT__fetch__DOT__is_S = VL_RAND_RESET_I(1);
    vlSelf->CPU_top__DOT__cpu__DOT__fetch__DOT__is_JUMP_CONDITIONAL = VL_RAND_RESET_I(1);
    vlSelf->CPU_top__DOT__cpu__DOT__fetch__DOT__is_FPU = VL_RAND_RESET_I(1);
    vlSelf->CPU_top__DOT__cpu__DOT__fetch__DOT__RD_bank = VL_RAND_RESET_I(1);
    vlSelf->CPU_top__DOT__cpu__DOT__fetch__DOT__RS1_bank = VL_RAND_RESET_I(1);
    vlSelf->CPU_top__DOT__cpu__DOT__fetch__DOT__RS2_bank = VL_RAND_RESET_I(1);
    vlSelf->CPU_top__DOT__cpu__DOT__fetch__DOT__have_RS3 = VL_RAND_RESET_I(1);
    vlSelf->CPU_top__DOT__cpu__DOT__fetch__DOT__irq_pending_r = 0;
    vlSelf->CPU_top__DOT__cpu__DOT__fetch__DOT____VdfgRegularize_hef2daed4_0_8 = VL_RAND_RESET_I(1);
    vlSelf->CPU_top__DOT__cpu__DOT__fetch__DOT____VdfgRegularize_hef2daed4_0_14 = VL_RAND_RESET_I(1);
    vlSelf->CPU_top__DOT__cpu__DOT__fetch__DOT____VdfgRegularize_hef2daed4_0_17 = VL_RAND_RESET_I(1);
    vlSelf->CPU_top__DOT__cpu__DOT__fetch__DOT____VdfgRegularize_hef2daed4_0_18 = VL_RAND_RESET_I(1);
    vlSelf->CPU_top__DOT__cpu__DOT__fetch__DOT____VdfgRegularize_hef2daed4_0_19 = VL_RAND_RESET_I(1);
    vlSelf->CPU_top__DOT__cpu__DOT__fetch__DOT____VdfgRegularize_hef2daed4_0_20 = VL_RAND_RESET_I(1);
    vlSelf->CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT__initialized = 0;
    vlSelf->CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT__clear_set = 0;
    vlSelf->CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT__cache_invalid = 0;
    vlSelf->CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT__cache_rd_set = 0;
    vlSelf->CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT__cache_wr_request = 0;
    vlSelf->CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT__cache_wr_set = 0;
    vlSelf->CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT__cache_wr_wdata = 0;
    vlSelf->CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata = VL_RAND_RESET_Q(51);
    vlSelf->CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT__set_r = 0;
    vlSelf->CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT__cache__DOT__o_pa_ready = 0;
    vlSelf->CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT__cache__DOT__o_pb_ready = 0;
    for (int __Vi0 = 0; __Vi0 < 4096; ++__Vi0) {
        vlSelf->CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT__cache__DOT__data[__Vi0] = VL_RAND_RESET_Q(51);
    }
    VL_ZERO_RESET_W(117, vlSelf->CPU_top__DOT__cpu__DOT__fetch_skid__DOT__r_data);
    vlSelf->CPU_top__DOT__cpu__DOT__decode__DOT__is_B = VL_RAND_RESET_I(1);
    vlSelf->CPU_top__DOT__cpu__DOT__decode__DOT__is_I = VL_RAND_RESET_I(1);
    vlSelf->CPU_top__DOT__cpu__DOT__decode__DOT__is_R = VL_RAND_RESET_I(1);
    vlSelf->CPU_top__DOT__cpu__DOT__decode__DOT__is_S = VL_RAND_RESET_I(1);
    vlSelf->CPU_top__DOT__cpu__DOT__decode__DOT__is_U = VL_RAND_RESET_I(1);
    vlSelf->CPU_top__DOT__cpu__DOT__decode__DOT__is_CSR = VL_RAND_RESET_I(1);
    vlSelf->CPU_top__DOT__cpu__DOT__decode__DOT__is_FPU = VL_RAND_RESET_I(1);
    vlSelf->CPU_top__DOT__cpu__DOT__decode__DOT__RD_bank = VL_RAND_RESET_I(1);
    vlSelf->CPU_top__DOT__cpu__DOT__decode__DOT__RS1_bank = VL_RAND_RESET_I(1);
    vlSelf->CPU_top__DOT__cpu__DOT__decode__DOT__RS2_bank = VL_RAND_RESET_I(1);
    vlSelf->CPU_top__DOT__cpu__DOT__decode__DOT__alu_operation = VL_RAND_RESET_I(4);
    vlSelf->CPU_top__DOT__cpu__DOT__decode__DOT__alu_operand2 = VL_RAND_RESET_I(5);
    vlSelf->CPU_top__DOT__cpu__DOT__decode__DOT__memory_width = VL_RAND_RESET_I(2);
    vlSelf->CPU_top__DOT__cpu__DOT__decode__DOT__have_RS3 = VL_RAND_RESET_I(1);
    VL_ZERO_RESET_W(118, vlSelf->CPU_top__DOT__cpu__DOT__decode__DOT__data);
    vlSelf->CPU_top__DOT__cpu__DOT__decode__DOT____VdfgRegularize_h2cfc3394_0_9 = VL_RAND_RESET_I(1);
    vlSelf->CPU_top__DOT__cpu__DOT__decode__DOT____VdfgRegularize_h2cfc3394_0_18 = VL_RAND_RESET_I(1);
    vlSelf->CPU_top__DOT__cpu__DOT__decode__DOT____VdfgRegularize_h2cfc3394_0_19 = VL_RAND_RESET_I(1);
    vlSelf->CPU_top__DOT__cpu__DOT__decode__DOT____VdfgRegularize_h2cfc3394_0_20 = VL_RAND_RESET_I(1);
    vlSelf->CPU_top__DOT__cpu__DOT__decode__DOT____VdfgRegularize_h2cfc3394_0_23 = VL_RAND_RESET_I(1);
    vlSelf->CPU_top__DOT__cpu__DOT__decode__DOT____VdfgRegularize_h2cfc3394_0_24 = VL_RAND_RESET_I(1);
    vlSelf->CPU_top__DOT__cpu__DOT__decode__DOT____VdfgRegularize_h2cfc3394_0_25 = VL_RAND_RESET_I(1);
    vlSelf->CPU_top__DOT__cpu__DOT__decode__DOT____VdfgRegularize_h2cfc3394_0_26 = VL_RAND_RESET_I(1);
    vlSelf->CPU_top__DOT__cpu__DOT__forward__DOT__rs1 = 0;
    vlSelf->CPU_top__DOT__cpu__DOT__forward__DOT__rs2 = 0;
    vlSelf->CPU_top__DOT__cpu__DOT__forward__DOT__rs3 = 0;
    vlSelf->CPU_top__DOT__cpu__DOT__execute__DOT__alu_operand1 = 0;
    vlSelf->CPU_top__DOT__cpu__DOT__execute__DOT__alu_operand2 = 0;
    vlSelf->CPU_top__DOT__cpu__DOT__execute__DOT__alu_signed_sum_result = VL_RAND_RESET_I(32);
    vlSelf->CPU_top__DOT__cpu__DOT__execute__DOT__alu_compare_result = VL_RAND_RESET_I(1);
    vlSelf->CPU_top__DOT__cpu__DOT__execute__DOT__mul_request = VL_RAND_RESET_I(1);
    vlSelf->CPU_top__DOT__cpu__DOT__execute__DOT__mul_signed = VL_RAND_RESET_I(1);
    vlSelf->CPU_top__DOT__cpu__DOT__execute__DOT__mul_ready = VL_RAND_RESET_I(1);
    vlSelf->CPU_top__DOT__cpu__DOT__execute__DOT__div_request = VL_RAND_RESET_I(1);
    vlSelf->CPU_top__DOT__cpu__DOT__execute__DOT__div_signed = VL_RAND_RESET_I(1);
    vlSelf->CPU_top__DOT__cpu__DOT__execute__DOT__div_ready = VL_RAND_RESET_I(1);
    vlSelf->CPU_top__DOT__cpu__DOT__execute__DOT__div_result = VL_RAND_RESET_I(32);
    vlSelf->CPU_top__DOT__cpu__DOT__execute__DOT__div_remainder = VL_RAND_RESET_I(32);
    vlSelf->CPU_top__DOT__cpu__DOT__execute__DOT__last_strobe = 0;
    VL_ZERO_RESET_W(113, vlSelf->CPU_top__DOT__cpu__DOT__execute__DOT__data);
    vlSelf->CPU_top__DOT__cpu__DOT__execute__DOT____VdfgRegularize_h9a67d98d_0_0 = VL_RAND_RESET_I(1);
    vlSelf->CPU_top__DOT__cpu__DOT__execute__DOT__multiply__DOT__r0_request = 0;
    vlSelf->CPU_top__DOT__cpu__DOT__execute__DOT__multiply__DOT__r0_s = 0;
    vlSelf->CPU_top__DOT__cpu__DOT__execute__DOT__multiply__DOT__r0_uop1 = 0;
    vlSelf->CPU_top__DOT__cpu__DOT__execute__DOT__multiply__DOT__r0_uop2 = 0;
    vlSelf->CPU_top__DOT__cpu__DOT__execute__DOT__multiply__DOT__r1_request = 0;
    vlSelf->CPU_top__DOT__cpu__DOT__execute__DOT__multiply__DOT__r1_s = 0;
    vlSelf->CPU_top__DOT__cpu__DOT__execute__DOT__multiply__DOT__r1_intermediate = 0;
    vlSelf->CPU_top__DOT__cpu__DOT__execute__DOT__multiply__DOT__r2_request = 0;
    vlSelf->CPU_top__DOT__cpu__DOT__execute__DOT__multiply__DOT__r2_result = 0;
    vlSelf->CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__unumerator = 0;
    vlSelf->CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__udenominator = 0;
    vlSelf->CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__ack = 0;
    vlSelf->CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__s = 0;
    vlSelf->CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__llth = 0;
    vlSelf->CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT____Vcellinp__df__rst = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 33; ++__Vi0) {
        vlSelf->CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__ready[__Vi0] = VL_RAND_RESET_I(1);
    }
    for (int __Vi0 = 0; __Vi0 < 33; ++__Vi0) {
        vlSelf->CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend[__Vi0] = VL_RAND_RESET_I(32);
    }
    for (int __Vi0 = 0; __Vi0 < 33; ++__Vi0) {
        vlSelf->CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor[__Vi0] = VL_RAND_RESET_I(32);
    }
    for (int __Vi0 = 0; __Vi0 < 33; ++__Vi0) {
        vlSelf->CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__quotient[__Vi0] = VL_RAND_RESET_I(32);
    }
    vlSelf->CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__0__KET____DOT__q = VL_RAND_RESET_I(1);
    vlSelf->CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__0__KET____DOT__d = VL_RAND_RESET_Q(33);
    vlSelf->CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__1__KET____DOT__q = VL_RAND_RESET_I(1);
    vlSelf->CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__2__KET____DOT__q = VL_RAND_RESET_I(1);
    vlSelf->CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__2__KET____DOT__d = VL_RAND_RESET_Q(35);
    vlSelf->CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__3__KET____DOT__q = VL_RAND_RESET_I(1);
    vlSelf->CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__4__KET____DOT__q = VL_RAND_RESET_I(1);
    vlSelf->CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__5__KET____DOT__q = VL_RAND_RESET_I(1);
    vlSelf->CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__6__KET____DOT__q = VL_RAND_RESET_I(1);
    vlSelf->CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__6__KET____DOT__d = VL_RAND_RESET_Q(39);
    vlSelf->CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__7__KET____DOT__q = VL_RAND_RESET_I(1);
    vlSelf->CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__8__KET____DOT__q = VL_RAND_RESET_I(1);
    vlSelf->CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__9__KET____DOT__q = VL_RAND_RESET_I(1);
    vlSelf->CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__10__KET____DOT__q = VL_RAND_RESET_I(1);
    vlSelf->CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__10__KET____DOT__d = VL_RAND_RESET_Q(43);
    vlSelf->CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__11__KET____DOT__q = VL_RAND_RESET_I(1);
    vlSelf->CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__12__KET____DOT__q = VL_RAND_RESET_I(1);
    vlSelf->CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__13__KET____DOT__q = VL_RAND_RESET_I(1);
    vlSelf->CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__14__KET____DOT__q = VL_RAND_RESET_I(1);
    vlSelf->CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__14__KET____DOT__d = VL_RAND_RESET_Q(47);
    vlSelf->CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__15__KET____DOT__q = VL_RAND_RESET_I(1);
    vlSelf->CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__16__KET____DOT__q = VL_RAND_RESET_I(1);
    vlSelf->CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__17__KET____DOT__q = VL_RAND_RESET_I(1);
    vlSelf->CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__18__KET____DOT__q = VL_RAND_RESET_I(1);
    vlSelf->CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__18__KET____DOT__d = VL_RAND_RESET_Q(51);
    vlSelf->CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__19__KET____DOT__q = VL_RAND_RESET_I(1);
    vlSelf->CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__20__KET____DOT__q = VL_RAND_RESET_I(1);
    vlSelf->CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__21__KET____DOT__q = VL_RAND_RESET_I(1);
    vlSelf->CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__22__KET____DOT__q = VL_RAND_RESET_I(1);
    vlSelf->CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__22__KET____DOT__d = VL_RAND_RESET_Q(55);
    vlSelf->CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__23__KET____DOT__q = VL_RAND_RESET_I(1);
    vlSelf->CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__24__KET____DOT__q = VL_RAND_RESET_I(1);
    vlSelf->CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__25__KET____DOT__q = VL_RAND_RESET_I(1);
    vlSelf->CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__26__KET____DOT__q = VL_RAND_RESET_I(1);
    vlSelf->CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__26__KET____DOT__d = VL_RAND_RESET_Q(59);
    vlSelf->CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__27__KET____DOT__q = VL_RAND_RESET_I(1);
    vlSelf->CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__28__KET____DOT__q = VL_RAND_RESET_I(1);
    vlSelf->CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__29__KET____DOT__q = VL_RAND_RESET_I(1);
    vlSelf->CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__29__KET____DOT__d = VL_RAND_RESET_Q(62);
    vlSelf->CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__30__KET____DOT__q = VL_RAND_RESET_I(1);
    vlSelf->CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__31__KET____DOT__q = VL_RAND_RESET_I(1);
    vlSelf->CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__31__KET____DOT__t = VL_RAND_RESET_I(32);
    vlSelf->CPU_top__DOT__cpu__DOT__memory__DOT__dcache_rw = 0;
    vlSelf->CPU_top__DOT__cpu__DOT__memory__DOT__dcache_request = 0;
    vlSelf->CPU_top__DOT__cpu__DOT__memory__DOT__dcache_flush = 0;
    vlSelf->CPU_top__DOT__cpu__DOT__memory__DOT__dcache_ready = VL_RAND_RESET_I(1);
    vlSelf->CPU_top__DOT__cpu__DOT__memory__DOT__dcache_rdata = VL_RAND_RESET_I(32);
    vlSelf->CPU_top__DOT__cpu__DOT__memory__DOT__dcache_wdata = 0;
    VL_ZERO_RESET_W(70, vlSelf->CPU_top__DOT__cpu__DOT__memory__DOT__data);
    vlSelf->CPU_top__DOT__cpu__DOT__memory__DOT__state = 0;
    vlSelf->CPU_top__DOT__cpu__DOT__memory__DOT__rmw_rdata = 0;
    vlSelf->CPU_top__DOT__cpu__DOT__memory__DOT__last_strobe = 0;
    vlSelf->CPU_top__DOT__cpu__DOT__memory__DOT____VdfgRegularize_h9eb5ee7c_0_0 = VL_RAND_RESET_I(32);
    vlSelf->CPU_top__DOT__cpu__DOT__memory__DOT__genblk1__DOT__dcache__DOT__state = 0;
    vlSelf->CPU_top__DOT__cpu__DOT__memory__DOT__genblk1__DOT__dcache__DOT__flush_address = 0;
    vlSelf->CPU_top__DOT__cpu__DOT__memory__DOT__genblk1__DOT__dcache__DOT__wb_rw = 0;
    vlSelf->CPU_top__DOT__cpu__DOT__memory__DOT__genblk1__DOT__dcache__DOT__wb_request = 0;
    vlSelf->CPU_top__DOT__cpu__DOT__memory__DOT__genblk1__DOT__dcache__DOT__wb_ready = VL_RAND_RESET_I(1);
    vlSelf->CPU_top__DOT__cpu__DOT__memory__DOT__genblk1__DOT__dcache__DOT__wb_address = 0;
    vlSelf->CPU_top__DOT__cpu__DOT__memory__DOT__genblk1__DOT__dcache__DOT__wb_wdata = 0;
    vlSelf->CPU_top__DOT__cpu__DOT__memory__DOT__genblk1__DOT__dcache__DOT__cache_rw = 0;
    vlSelf->CPU_top__DOT__cpu__DOT__memory__DOT__genblk1__DOT__dcache__DOT__cache_address = 0;
    vlSelf->CPU_top__DOT__cpu__DOT__memory__DOT__genblk1__DOT__dcache__DOT__cache_wdata = 0;
    vlSelf->CPU_top__DOT__cpu__DOT__memory__DOT__genblk1__DOT__dcache__DOT__cache_rdata = VL_RAND_RESET_Q(64);
    vlSelf->CPU_top__DOT__cpu__DOT__memory__DOT__genblk1__DOT__dcache__DOT__wb__DOT__wb_dirty = 0;
    vlSelf->CPU_top__DOT__cpu__DOT__memory__DOT__genblk1__DOT__dcache__DOT__wb__DOT__wb_address = 0;
    vlSelf->CPU_top__DOT__cpu__DOT__memory__DOT__genblk1__DOT__dcache__DOT__wb__DOT__wb_data = 0;
    vlSelf->CPU_top__DOT__cpu__DOT__memory__DOT__genblk1__DOT__dcache__DOT__wb__DOT__next_wb_dirty = 0;
    vlSelf->CPU_top__DOT__cpu__DOT__memory__DOT__genblk1__DOT__dcache__DOT__wb__DOT__next_wb_address = 0;
    vlSelf->CPU_top__DOT__cpu__DOT__memory__DOT__genblk1__DOT__dcache__DOT__wb__DOT__next_wb_data = 0;
    vlSelf->CPU_top__DOT__cpu__DOT__memory__DOT__genblk1__DOT__dcache__DOT__cache__DOT__o_ready = 0;
    vlSelf->CPU_top__DOT__cpu__DOT__memory__DOT__genblk1__DOT__dcache__DOT__cache__DOT__o_valid = 0;
    for (int __Vi0 = 0; __Vi0 < 4096; ++__Vi0) {
        vlSelf->CPU_top__DOT__cpu__DOT__memory__DOT__genblk1__DOT__dcache__DOT__cache__DOT__data[__Vi0] = VL_RAND_RESET_Q(64);
    }
    vlSelf->CPU_top__DOT__cpu__DOT__writeback__DOT__data = 0;
    vlSelf->CPU_top__DOT__cpu__DOT__writeback__DOT__last_strobe = 0;
    vlSelf->CPU_top__DOT__cpu__DOT__writeback__DOT__retired = 0;
    vlSelf->CPU_top__DOT__cpu__DOT__writeback__DOT__last_pc = 0;
    vlSelf->__VdfgRegularize_hd87f99a1_3_0 = VL_RAND_RESET_I(1);
    vlSelf->__VdfgRegularize_hd87f99a1_8_0 = VL_RAND_RESET_I(1);
    VL_ZERO_RESET_W(70, vlSelf->__Vdly__CPU_top__DOT__cpu__DOT__memory__DOT__data);
    for (int __Vi0 = 0; __Vi0 < 33; ++__Vi0) {
        vlSelf->__Vtrigprevexpr___TOP__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__quotient__0[__Vi0] = VL_RAND_RESET_I(32);
    }
    for (int __Vi0 = 0; __Vi0 < 33; ++__Vi0) {
        vlSelf->__Vtrigprevexpr___TOP__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend__0[__Vi0] = VL_RAND_RESET_I(32);
    }
    for (int __Vi0 = 0; __Vi0 < 33; ++__Vi0) {
        vlSelf->__Vtrigprevexpr___TOP__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor__0[__Vi0] = VL_RAND_RESET_I(32);
    }
    for (int __Vi0 = 0; __Vi0 < 33; ++__Vi0) {
        vlSelf->__Vtrigprevexpr___TOP__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__ready__0[__Vi0] = VL_RAND_RESET_I(1);
    }
    vlSelf->__VstlDidInit = 0;
    for (int __Vi0 = 0; __Vi0 < 33; ++__Vi0) {
        vlSelf->__Vtrigprevexpr___TOP__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__quotient__1[__Vi0] = VL_RAND_RESET_I(32);
    }
    for (int __Vi0 = 0; __Vi0 < 33; ++__Vi0) {
        vlSelf->__Vtrigprevexpr___TOP__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend__1[__Vi0] = VL_RAND_RESET_I(32);
    }
    for (int __Vi0 = 0; __Vi0 < 33; ++__Vi0) {
        vlSelf->__Vtrigprevexpr___TOP__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor__1[__Vi0] = VL_RAND_RESET_I(32);
    }
    for (int __Vi0 = 0; __Vi0 < 33; ++__Vi0) {
        vlSelf->__Vtrigprevexpr___TOP__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__ready__1[__Vi0] = VL_RAND_RESET_I(1);
    }
    vlSelf->__Vtrigprevexpr___TOP__clock__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__reset__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT____Vcellinp__df__rst__0 = VL_RAND_RESET_I(1);
    vlSelf->__VactDidInit = 0;
    for (int __Vi0 = 0; __Vi0 < 10; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}
