// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VCPU_top.h for the primary calling header

#include "VCPU_top__pch.h"
#include "VCPU_top__Syms.h"
#include "VCPU_top___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void VCPU_top___024root___dump_triggers__stl(VCPU_top___024root* vlSelf);
#endif  // VL_DEBUG

VL_ATTR_COLD void VCPU_top___024root___eval_triggers__stl(VCPU_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCPU_top___024root___eval_triggers__stl\n"); );
    VCPU_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VstlTriggered.setBit(0U, (IData)(vlSelfRef.__VstlFirstIteration));
    vlSelfRef.__VstlTriggered.setBit(1U, vlSelfRef.__Vtrigprevexpr___TOP__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__quotient__0.neq(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__quotient));
    vlSelfRef.__VstlTriggered.setBit(2U, vlSelfRef.__Vtrigprevexpr___TOP__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend__0.neq(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend));
    vlSelfRef.__VstlTriggered.setBit(3U, vlSelfRef.__Vtrigprevexpr___TOP__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor__0.neq(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor));
    vlSelfRef.__VstlTriggered.setBit(4U, vlSelfRef.__Vtrigprevexpr___TOP__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__ready__0.neq(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__ready));
    vlSelfRef.__Vtrigprevexpr___TOP__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__quotient__0.assign(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__quotient);
    vlSelfRef.__Vtrigprevexpr___TOP__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend__0.assign(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend);
    vlSelfRef.__Vtrigprevexpr___TOP__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor__0.assign(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor);
    vlSelfRef.__Vtrigprevexpr___TOP__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__ready__0.assign(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__ready);
    if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.__VstlDidInit)))))) {
        vlSelfRef.__VstlDidInit = 1U;
        vlSelfRef.__VstlTriggered.setBit(1U, 1U);
        vlSelfRef.__VstlTriggered.setBit(2U, 1U);
        vlSelfRef.__VstlTriggered.setBit(3U, 1U);
        vlSelfRef.__VstlTriggered.setBit(4U, 1U);
    }
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        VCPU_top___024root___dump_triggers__stl(vlSelf);
    }
#endif
}
