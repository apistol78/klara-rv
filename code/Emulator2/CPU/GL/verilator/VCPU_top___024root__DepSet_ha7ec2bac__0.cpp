// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VCPU_top.h for the primary calling header

#include "VCPU_top__pch.h"
#include "VCPU_top__Syms.h"
#include "VCPU_top___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void VCPU_top___024root___dump_triggers__ico(VCPU_top___024root* vlSelf);
#endif  // VL_DEBUG

void VCPU_top___024root___eval_triggers__ico(VCPU_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCPU_top___024root___eval_triggers__ico\n"); );
    VCPU_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VicoTriggered.setBit(0U, (IData)(vlSelfRef.__VicoFirstIteration));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        VCPU_top___024root___dump_triggers__ico(vlSelf);
    }
#endif
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VCPU_top___024root___dump_triggers__act(VCPU_top___024root* vlSelf);
#endif  // VL_DEBUG

void VCPU_top___024root___eval_triggers__act(VCPU_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCPU_top___024root___eval_triggers__act\n"); );
    VCPU_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VactTriggered.setBit(0U, vlSelfRef.__Vtrigprevexpr___TOP__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__quotient__1.neq(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__quotient));
    vlSelfRef.__VactTriggered.setBit(1U, vlSelfRef.__Vtrigprevexpr___TOP__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend__1.neq(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend));
    vlSelfRef.__VactTriggered.setBit(2U, vlSelfRef.__Vtrigprevexpr___TOP__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor__1.neq(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor));
    vlSelfRef.__VactTriggered.setBit(3U, vlSelfRef.__Vtrigprevexpr___TOP__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__ready__1.neq(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__ready));
    vlSelfRef.__VactTriggered.setBit(4U, ((IData)(vlSelfRef.clock) 
                                          & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__clock__0))));
    vlSelfRef.__VactTriggered.setBit(5U, ((IData)(vlSelfRef.reset) 
                                          & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__reset__0))));
    vlSelfRef.__VactTriggered.setBit(6U, ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT____Vcellinp__df__rst) 
                                          & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT____Vcellinp__df__rst__0))));
    vlSelfRef.__Vtrigprevexpr___TOP__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__quotient__1.assign(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__quotient);
    vlSelfRef.__Vtrigprevexpr___TOP__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend__1.assign(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend);
    vlSelfRef.__Vtrigprevexpr___TOP__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor__1.assign(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor);
    vlSelfRef.__Vtrigprevexpr___TOP__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__ready__1.assign(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__ready);
    vlSelfRef.__Vtrigprevexpr___TOP__clock__0 = vlSelfRef.clock;
    vlSelfRef.__Vtrigprevexpr___TOP__reset__0 = vlSelfRef.reset;
    vlSelfRef.__Vtrigprevexpr___TOP__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT____Vcellinp__df__rst__0 
        = vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT____Vcellinp__df__rst;
    if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.__VactDidInit)))))) {
        vlSelfRef.__VactDidInit = 1U;
        vlSelfRef.__VactTriggered.setBit(0U, 1U);
        vlSelfRef.__VactTriggered.setBit(1U, 1U);
        vlSelfRef.__VactTriggered.setBit(2U, 1U);
        vlSelfRef.__VactTriggered.setBit(3U, 1U);
    }
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        VCPU_top___024root___dump_triggers__act(vlSelf);
    }
#endif
}
