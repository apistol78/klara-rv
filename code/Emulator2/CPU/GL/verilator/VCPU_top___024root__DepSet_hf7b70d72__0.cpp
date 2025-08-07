// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VCPU_top.h for the primary calling header

#include "VCPU_top__pch.h"
#include "VCPU_top___024root.h"

void VCPU_top___024root___ico_sequent__TOP__0(VCPU_top___024root* vlSelf);

void VCPU_top___024root___eval_ico(VCPU_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCPU_top___024root___eval_ico\n"); );
    VCPU_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VicoTriggered.word(0U))) {
        VCPU_top___024root___ico_sequent__TOP__0(vlSelf);
    }
}

VL_INLINE_OPT void VCPU_top___024root___ico_sequent__TOP__0(VCPU_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCPU_top___024root___ico_sequent__TOP__0\n"); );
    VCPU_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.CPU_top__DOT__cpu_ibus_ready = ((IData)(vlSelfRef.CPU_top__DOT__cpu_ibus_request) 
                                              & ((1U 
                                                  == (IData)(vlSelfRef.CPU_top__DOT__bus__DOT__state)) 
                                                 & (IData)(vlSelfRef.bus_ready)));
    vlSelfRef.CPU_top__DOT__cpu_dbus_ready = ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__wb_request) 
                                              & ((2U 
                                                  == (IData)(vlSelfRef.CPU_top__DOT__bus__DOT__state)) 
                                                 & (IData)(vlSelfRef.bus_ready)));
    vlSelfRef.CPU_top__DOT__bus__DOT__next_state = vlSelfRef.CPU_top__DOT__bus__DOT__state;
    if ((0U == (IData)(vlSelfRef.CPU_top__DOT__bus__DOT__state))) {
        if (vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__wb_request) {
            vlSelfRef.CPU_top__DOT__bus__DOT__next_state = 2U;
        } else if (vlSelfRef.CPU_top__DOT__cpu_ibus_request) {
            vlSelfRef.CPU_top__DOT__bus__DOT__next_state = 1U;
        }
    } else if ((1U == (IData)(vlSelfRef.CPU_top__DOT__bus__DOT__state))) {
        if (vlSelfRef.bus_ready) {
            vlSelfRef.CPU_top__DOT__bus__DOT__next_state = 0U;
        }
    } else if ((2U == (IData)(vlSelfRef.CPU_top__DOT__bus__DOT__state))) {
        if (vlSelfRef.bus_ready) {
            vlSelfRef.CPU_top__DOT__bus__DOT__next_state = 0U;
        }
    } else {
        vlSelfRef.CPU_top__DOT__bus__DOT__next_state = 0U;
    }
}

void VCPU_top___024root___eval_triggers__ico(VCPU_top___024root* vlSelf);

bool VCPU_top___024root___eval_phase__ico(VCPU_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCPU_top___024root___eval_phase__ico\n"); );
    VCPU_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VicoExecute;
    // Body
    VCPU_top___024root___eval_triggers__ico(vlSelf);
    __VicoExecute = vlSelfRef.__VicoTriggered.any();
    if (__VicoExecute) {
        VCPU_top___024root___eval_ico(vlSelf);
    }
    return (__VicoExecute);
}

void VCPU_top___024root___act_sequent__TOP__0(VCPU_top___024root* vlSelf);
void VCPU_top___024root___act_sequent__TOP__1(VCPU_top___024root* vlSelf);
void VCPU_top___024root___act_sequent__TOP__2(VCPU_top___024root* vlSelf);
void VCPU_top___024root___act_comb__TOP__0(VCPU_top___024root* vlSelf);
void VCPU_top___024root___act_comb__TOP__1(VCPU_top___024root* vlSelf);

void VCPU_top___024root___eval_act(VCPU_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCPU_top___024root___eval_act\n"); );
    VCPU_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((8ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VCPU_top___024root___act_sequent__TOP__0(vlSelf);
    }
    if ((4ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VCPU_top___024root___act_sequent__TOP__1(vlSelf);
        vlSelfRef.__Vm_traceActivity[1U] = 1U;
    }
    if ((6ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VCPU_top___024root___act_sequent__TOP__2(vlSelf);
        vlSelfRef.__Vm_traceActivity[2U] = 1U;
    }
    if ((7ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VCPU_top___024root___act_comb__TOP__0(vlSelf);
    }
    if ((6ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VCPU_top___024root___act_comb__TOP__1(vlSelf);
        vlSelfRef.__Vm_traceActivity[3U] = 1U;
    }
}

VL_INLINE_OPT void VCPU_top___024root___act_sequent__TOP__0(VCPU_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCPU_top___024root___act_sequent__TOP__0\n"); );
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
    vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__ack 
        = vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__ready
        [0x20U];
    vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__div_ready 
        = ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__div_request) 
           & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__ack));
}

VL_INLINE_OPT void VCPU_top___024root___act_sequent__TOP__1(VCPU_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCPU_top___024root___act_sequent__TOP__1\n"); );
    VCPU_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor[2U] 
        = vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
        [1U];
    vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor[4U] 
        = vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
        [3U];
    vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor[5U] 
        = vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
        [4U];
    vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor[6U] 
        = vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
        [5U];
    vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor[8U] 
        = vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
        [7U];
    vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor[9U] 
        = vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
        [8U];
    vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor[0xaU] 
        = vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
        [9U];
    vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor[0xcU] 
        = vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
        [0xbU];
    vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor[0xdU] 
        = vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
        [0xcU];
    vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor[0xeU] 
        = vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
        [0xdU];
    vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor[0x10U] 
        = vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
        [0xfU];
    vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor[0x11U] 
        = vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
        [0x10U];
    vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor[0x12U] 
        = vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
        [0x11U];
    vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor[0x14U] 
        = vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
        [0x13U];
    vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor[0x15U] 
        = vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
        [0x14U];
    vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor[0x16U] 
        = vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
        [0x15U];
    vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor[0x18U] 
        = vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
        [0x17U];
    vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor[0x19U] 
        = vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
        [0x18U];
    vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor[0x1aU] 
        = vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
        [0x19U];
    vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor[0x1cU] 
        = vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
        [0x1bU];
    vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor[0x1dU] 
        = vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
        [0x1cU];
    vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor[0x1fU] 
        = vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
        [0x1eU];
}

VL_INLINE_OPT void VCPU_top___024root___act_sequent__TOP__2(VCPU_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCPU_top___024root___act_sequent__TOP__2\n"); );
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
        = ((2U & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__s))
            ? (- vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
               [0x20U]) : vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
           [0x20U]);
}

VL_INLINE_OPT void VCPU_top___024root___act_comb__TOP__0(VCPU_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCPU_top___024root___act_comb__TOP__0\n"); );
    VCPU_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__quotient[2U] 
        = (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__quotient
           [1U] | VL_SHIFTL_III(32,32,32, (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__1__KET____DOT__q), 0x1eU));
    vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__quotient[4U] 
        = (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__quotient
           [3U] | VL_SHIFTL_III(32,32,32, (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__3__KET____DOT__q), 0x1cU));
    vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__quotient[5U] 
        = (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__quotient
           [4U] | VL_SHIFTL_III(32,32,32, (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__4__KET____DOT__q), 0x1bU));
    vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__quotient[6U] 
        = (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__quotient
           [5U] | VL_SHIFTL_III(32,32,32, (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__5__KET____DOT__q), 0x1aU));
    vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__quotient[8U] 
        = (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__quotient
           [7U] | VL_SHIFTL_III(32,32,32, (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__7__KET____DOT__q), 0x18U));
    vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__quotient[9U] 
        = (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__quotient
           [8U] | VL_SHIFTL_III(32,32,32, (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__8__KET____DOT__q), 0x17U));
    vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__quotient[0xaU] 
        = (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__quotient
           [9U] | VL_SHIFTL_III(32,32,32, (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__9__KET____DOT__q), 0x16U));
    vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__quotient[0xcU] 
        = (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__quotient
           [0xbU] | VL_SHIFTL_III(32,32,32, (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__11__KET____DOT__q), 0x14U));
    vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__quotient[0xdU] 
        = (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__quotient
           [0xcU] | VL_SHIFTL_III(32,32,32, (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__12__KET____DOT__q), 0x13U));
    vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__quotient[0xeU] 
        = (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__quotient
           [0xdU] | VL_SHIFTL_III(32,32,32, (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__13__KET____DOT__q), 0x12U));
    vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__quotient[0x10U] 
        = (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__quotient
           [0xfU] | VL_SHIFTL_III(32,32,32, (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__15__KET____DOT__q), 0x10U));
    vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__quotient[0x11U] 
        = (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__quotient
           [0x10U] | VL_SHIFTL_III(32,32,32, (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__16__KET____DOT__q), 0xfU));
    vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__quotient[0x12U] 
        = (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__quotient
           [0x11U] | VL_SHIFTL_III(32,32,32, (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__17__KET____DOT__q), 0xeU));
    vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__quotient[0x14U] 
        = (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__quotient
           [0x13U] | VL_SHIFTL_III(32,32,32, (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__19__KET____DOT__q), 0xcU));
    vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__quotient[0x15U] 
        = (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__quotient
           [0x14U] | VL_SHIFTL_III(32,32,32, (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__20__KET____DOT__q), 0xbU));
    vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__quotient[0x16U] 
        = (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__quotient
           [0x15U] | VL_SHIFTL_III(32,32,32, (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__21__KET____DOT__q), 0xaU));
    vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__quotient[0x18U] 
        = (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__quotient
           [0x17U] | VL_SHIFTL_III(32,32,32, (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__23__KET____DOT__q), 8U));
    vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__quotient[0x19U] 
        = (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__quotient
           [0x18U] | VL_SHIFTL_III(32,32,32, (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__24__KET____DOT__q), 7U));
    vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__quotient[0x1aU] 
        = (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__quotient
           [0x19U] | VL_SHIFTL_III(32,32,32, (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__25__KET____DOT__q), 6U));
    vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__quotient[0x1cU] 
        = (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__quotient
           [0x1bU] | VL_SHIFTL_III(32,32,32, (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__27__KET____DOT__q), 4U));
    vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__quotient[0x1dU] 
        = (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__quotient
           [0x1cU] | VL_SHIFTL_III(32,32,32, (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__28__KET____DOT__q), 3U));
    vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__quotient[0x1fU] 
        = (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__quotient
           [0x1eU] | VL_SHIFTL_III(32,32,32, (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__30__KET____DOT__q), 1U));
    vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__div_result 
        = (((1U & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__s)) 
            != (1U & ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__s) 
                      >> 1U))) ? (- vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__quotient
                                  [0x20U]) : vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__quotient
           [0x20U]);
}

VL_INLINE_OPT void VCPU_top___024root___act_comb__TOP__1(VCPU_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCPU_top___024root___act_comb__TOP__1\n"); );
    VCPU_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
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

void VCPU_top___024root___nba_sequent__TOP__0(VCPU_top___024root* vlSelf);
void VCPU_top___024root___nba_sequent__TOP__1(VCPU_top___024root* vlSelf);
void VCPU_top___024root___nba_sequent__TOP__2(VCPU_top___024root* vlSelf);
void VCPU_top___024root___nba_sequent__TOP__3(VCPU_top___024root* vlSelf);
void VCPU_top___024root___nba_comb__TOP__0(VCPU_top___024root* vlSelf);
void VCPU_top___024root___nba_comb__TOP__1(VCPU_top___024root* vlSelf);
void VCPU_top___024root___nba_comb__TOP__2(VCPU_top___024root* vlSelf);

void VCPU_top___024root___eval_nba(VCPU_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCPU_top___024root___eval_nba\n"); );
    VCPU_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((0x10ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VCPU_top___024root___nba_sequent__TOP__0(vlSelf);
        vlSelfRef.__Vm_traceActivity[4U] = 1U;
    }
    if ((0x50ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VCPU_top___024root___nba_sequent__TOP__1(vlSelf);
        vlSelfRef.__Vm_traceActivity[5U] = 1U;
    }
    if ((0x30ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VCPU_top___024root___nba_sequent__TOP__2(vlSelf);
        vlSelfRef.__Vm_traceActivity[6U] = 1U;
    }
    if ((0x10ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VCPU_top___024root___nba_sequent__TOP__3(vlSelf);
        vlSelfRef.__Vm_traceActivity[7U] = 1U;
    }
    if ((0x50ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VCPU_top___024root___nba_comb__TOP__0(vlSelf);
    }
    if ((0x30ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VCPU_top___024root___nba_comb__TOP__1(vlSelf);
        vlSelfRef.__Vm_traceActivity[8U] = 1U;
    }
    if ((0x70ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VCPU_top___024root___nba_comb__TOP__2(vlSelf);
        vlSelfRef.__Vm_traceActivity[9U] = 1U;
    }
}

VL_INLINE_OPT void VCPU_top___024root___nba_sequent__TOP__0(VCPU_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCPU_top___024root___nba_sequent__TOP__0\n"); );
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
    CData/*0:0*/ __Vdly__CPU_top__DOT__cpu__DOT__csr__DOT__mstatus_mie;
    __Vdly__CPU_top__DOT__cpu__DOT__csr__DOT__mstatus_mie = 0;
    CData/*0:0*/ __Vdly__CPU_top__DOT__cpu__DOT__csr__DOT__mie_meie;
    __Vdly__CPU_top__DOT__cpu__DOT__csr__DOT__mie_meie = 0;
    CData/*0:0*/ __Vdly__CPU_top__DOT__cpu__DOT__csr__DOT__mie_mtie;
    __Vdly__CPU_top__DOT__cpu__DOT__csr__DOT__mie_mtie = 0;
    CData/*0:0*/ __Vdly__CPU_top__DOT__cpu__DOT__csr__DOT__mie_msie;
    __Vdly__CPU_top__DOT__cpu__DOT__csr__DOT__mie_msie = 0;
    IData/*31:0*/ __Vdly__CPU_top__DOT__cpu__DOT__csr__DOT__mtvec;
    __Vdly__CPU_top__DOT__cpu__DOT__csr__DOT__mtvec = 0;
    IData/*31:0*/ __Vdly__CPU_top__DOT__cpu__DOT__csr__DOT__mepc;
    __Vdly__CPU_top__DOT__cpu__DOT__csr__DOT__mepc = 0;
    CData/*0:0*/ __Vdly__CPU_top__DOT__cpu__DOT__csr__DOT__mip_meip;
    __Vdly__CPU_top__DOT__cpu__DOT__csr__DOT__mip_meip = 0;
    CData/*0:0*/ __Vdly__CPU_top__DOT__cpu__DOT__csr__DOT__mip_mtip;
    __Vdly__CPU_top__DOT__cpu__DOT__csr__DOT__mip_mtip = 0;
    CData/*0:0*/ __Vdly__CPU_top__DOT__cpu__DOT__csr__DOT__mip_msip;
    __Vdly__CPU_top__DOT__cpu__DOT__csr__DOT__mip_msip = 0;
    CData/*2:0*/ __Vdly__CPU_top__DOT__cpu__DOT__csr__DOT__issued;
    __Vdly__CPU_top__DOT__cpu__DOT__csr__DOT__issued = 0;
    CData/*0:0*/ __Vdly__CPU_top__DOT__cpu__DOT__csr_irq_pending;
    __Vdly__CPU_top__DOT__cpu__DOT__csr_irq_pending = 0;
    IData/*31:0*/ __Vdly__CPU_top__DOT__cpu__DOT__csr_irq_pc;
    __Vdly__CPU_top__DOT__cpu__DOT__csr_irq_pc = 0;
    CData/*0:0*/ __Vdly__CPU_top__DOT__cpu__DOT__csr__DOT__mstatus_mpie;
    __Vdly__CPU_top__DOT__cpu__DOT__csr__DOT__mstatus_mpie = 0;
    QData/*63:0*/ __Vdly__CPU_top__DOT__cpu__DOT__csr__DOT__wtime;
    __Vdly__CPU_top__DOT__cpu__DOT__csr__DOT__wtime = 0;
    SData/*13:0*/ __Vdly__CPU_top__DOT__cpu__DOT__csr__DOT__prescale;
    __Vdly__CPU_top__DOT__cpu__DOT__csr__DOT__prescale = 0;
    CData/*1:0*/ __Vdly__CPU_top__DOT__cpu__DOT__fetch__DOT__state;
    __Vdly__CPU_top__DOT__cpu__DOT__fetch__DOT__state = 0;
    IData/*31:0*/ __Vdly__CPU_top__DOT__cpu__DOT__fetch__DOT__pc;
    __Vdly__CPU_top__DOT__cpu__DOT__fetch__DOT__pc = 0;
    VlWide<4>/*116:0*/ __Vdly__CPU_top__DOT__cpu__DOT__fetch__DOT__data;
    VL_ZERO_W(117, __Vdly__CPU_top__DOT__cpu__DOT__fetch__DOT__data);
    CData/*0:0*/ __Vdly__CPU_top__DOT__cpu__DOT__fetch__DOT__irq_pending_r;
    __Vdly__CPU_top__DOT__cpu__DOT__fetch__DOT__irq_pending_r = 0;
    CData/*0:0*/ __Vdly__CPU_top__DOT__cpu_ibus_request;
    __Vdly__CPU_top__DOT__cpu_ibus_request = 0;
    CData/*0:0*/ __Vdly__CPU_top__DOT__cpu__DOT__execute__DOT__last_strobe;
    __Vdly__CPU_top__DOT__cpu__DOT__execute__DOT__last_strobe = 0;
    VlWide<4>/*112:0*/ __Vdly__CPU_top__DOT__cpu__DOT__execute__DOT__data;
    VL_ZERO_W(113, __Vdly__CPU_top__DOT__cpu__DOT__execute__DOT__data);
    CData/*0:0*/ __Vdly__CPU_top__DOT__cpu__DOT__execute__DOT__mul_signed;
    __Vdly__CPU_top__DOT__cpu__DOT__execute__DOT__mul_signed = 0;
    CData/*1:0*/ __Vdly__CPU_top__DOT__cpu__DOT__execute__DOT__multiply__DOT__latch;
    __Vdly__CPU_top__DOT__cpu__DOT__execute__DOT__multiply__DOT__latch = 0;
    CData/*2:0*/ __Vdly__CPU_top__DOT__cpu__DOT__memory__DOT__state;
    __Vdly__CPU_top__DOT__cpu__DOT__memory__DOT__state = 0;
    CData/*0:0*/ __Vdly__CPU_top__DOT__cpu__DOT__memory__DOT__last_strobe;
    __Vdly__CPU_top__DOT__cpu__DOT__memory__DOT__last_strobe = 0;
    CData/*0:0*/ __Vdly__CPU_top__DOT__cpu__DOT__memory__DOT__dcache_ready;
    __Vdly__CPU_top__DOT__cpu__DOT__memory__DOT__dcache_ready = 0;
    CData/*0:0*/ __Vdly__CPU_top__DOT__cpu__DOT__memory__DOT__genblk3__DOT__dcache__DOT__cache_rw;
    __Vdly__CPU_top__DOT__cpu__DOT__memory__DOT__genblk3__DOT__dcache__DOT__cache_rw = 0;
    CData/*3:0*/ __Vdly__CPU_top__DOT__cpu__DOT__memory__DOT__genblk3__DOT__dcache__DOT__state;
    __Vdly__CPU_top__DOT__cpu__DOT__memory__DOT__genblk3__DOT__dcache__DOT__state = 0;
    SData/*12:0*/ __Vdly__CPU_top__DOT__cpu__DOT__memory__DOT__genblk3__DOT__dcache__DOT__flush_address;
    __Vdly__CPU_top__DOT__cpu__DOT__memory__DOT__genblk3__DOT__dcache__DOT__flush_address = 0;
    IData/*31:0*/ __Vdly__CPU_top__DOT__cpu__DOT__memory__DOT__dcache_rdata;
    __Vdly__CPU_top__DOT__cpu__DOT__memory__DOT__dcache_rdata = 0;
    QData/*63:0*/ __Vdly__CPU_top__DOT__cpu__DOT__writeback__DOT__retired;
    __Vdly__CPU_top__DOT__cpu__DOT__writeback__DOT__retired = 0;
    QData/*50:0*/ __VdlyVal__CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT__cache__DOT__data__v0;
    __VdlyVal__CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT__cache__DOT__data__v0 = 0;
    SData/*11:0*/ __VdlyDim0__CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT__cache__DOT__data__v0;
    __VdlyDim0__CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT__cache__DOT__data__v0 = 0;
    CData/*0:0*/ __VdlySet__CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT__cache__DOT__data__v0;
    __VdlySet__CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT__cache__DOT__data__v0 = 0;
    QData/*63:0*/ __VdlyVal__CPU_top__DOT__cpu__DOT__memory__DOT__genblk3__DOT__dcache__DOT__cache__DOT__data__v0;
    __VdlyVal__CPU_top__DOT__cpu__DOT__memory__DOT__genblk3__DOT__dcache__DOT__cache__DOT__data__v0 = 0;
    SData/*11:0*/ __VdlyDim0__CPU_top__DOT__cpu__DOT__memory__DOT__genblk3__DOT__dcache__DOT__cache__DOT__data__v0;
    __VdlyDim0__CPU_top__DOT__cpu__DOT__memory__DOT__genblk3__DOT__dcache__DOT__cache__DOT__data__v0 = 0;
    CData/*0:0*/ __VdlySet__CPU_top__DOT__cpu__DOT__memory__DOT__genblk3__DOT__dcache__DOT__cache__DOT__data__v0;
    __VdlySet__CPU_top__DOT__cpu__DOT__memory__DOT__genblk3__DOT__dcache__DOT__cache__DOT__data__v0 = 0;
    // Body
    __Vdly__CPU_top__DOT__cpu__DOT__csr__DOT__prescale 
        = vlSelfRef.CPU_top__DOT__cpu__DOT__csr__DOT__prescale;
    __Vdly__CPU_top__DOT__cpu__DOT__csr__DOT__wtime 
        = vlSelfRef.CPU_top__DOT__cpu__DOT__csr__DOT__wtime;
    __Vdly__CPU_top__DOT__cpu_ibus_request = vlSelfRef.CPU_top__DOT__cpu_ibus_request;
    __VdlySet__CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT__cache__DOT__data__v0 = 0U;
    __Vdly__CPU_top__DOT__cpu__DOT__writeback__DOT__retired 
        = vlSelfRef.CPU_top__DOT__cpu__DOT__writeback__DOT__retired;
    __Vdly__CPU_top__DOT__cpu__DOT__memory__DOT__state 
        = vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__state;
    __Vdly__CPU_top__DOT__cpu__DOT__memory__DOT__last_strobe 
        = vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__last_strobe;
    vlSelfRef.__Vdly__CPU_top__DOT__cpu__DOT__memory__DOT__data[0U] 
        = vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__data[0U];
    vlSelfRef.__Vdly__CPU_top__DOT__cpu__DOT__memory__DOT__data[1U] 
        = vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__data[1U];
    vlSelfRef.__Vdly__CPU_top__DOT__cpu__DOT__memory__DOT__data[2U] 
        = vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__data[2U];
    __Vdly__CPU_top__DOT__cpu__DOT__execute__DOT__mul_signed 
        = vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__mul_signed;
    __Vdly__CPU_top__DOT__cpu__DOT__execute__DOT__multiply__DOT__latch 
        = vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__multiply__DOT__latch;
    __Vdly__CPU_top__DOT__cpu__DOT__execute__DOT__last_strobe 
        = vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__last_strobe;
    __Vdly__CPU_top__DOT__cpu__DOT__execute__DOT__data[0U] 
        = vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__data[0U];
    __Vdly__CPU_top__DOT__cpu__DOT__execute__DOT__data[1U] 
        = vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__data[1U];
    __Vdly__CPU_top__DOT__cpu__DOT__execute__DOT__data[2U] 
        = vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__data[2U];
    __Vdly__CPU_top__DOT__cpu__DOT__execute__DOT__data[3U] 
        = vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__data[3U];
    __Vdly__CPU_top__DOT__cpu__DOT__memory__DOT__dcache_ready 
        = vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__dcache_ready;
    __Vdly__CPU_top__DOT__cpu__DOT__memory__DOT__genblk3__DOT__dcache__DOT__cache_rw 
        = vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__genblk3__DOT__dcache__DOT__cache_rw;
    __Vdly__CPU_top__DOT__cpu__DOT__memory__DOT__dcache_rdata 
        = vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__dcache_rdata;
    __Vdly__CPU_top__DOT__cpu__DOT__memory__DOT__genblk3__DOT__dcache__DOT__state 
        = vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__genblk3__DOT__dcache__DOT__state;
    __Vdly__CPU_top__DOT__cpu__DOT__memory__DOT__genblk3__DOT__dcache__DOT__flush_address 
        = vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__genblk3__DOT__dcache__DOT__flush_address;
    __VdlySet__CPU_top__DOT__cpu__DOT__memory__DOT__genblk3__DOT__dcache__DOT__cache__DOT__data__v0 = 0U;
    __Vdly__CPU_top__DOT__cpu__DOT__fetch__DOT__state 
        = vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__state;
    __Vdly__CPU_top__DOT__cpu__DOT__fetch__DOT__irq_pending_r 
        = vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__irq_pending_r;
    __Vdly__CPU_top__DOT__cpu__DOT__fetch__DOT__pc 
        = vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__pc;
    __Vdly__CPU_top__DOT__cpu__DOT__fetch__DOT__data[0U] 
        = vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__data[0U];
    __Vdly__CPU_top__DOT__cpu__DOT__fetch__DOT__data[1U] 
        = vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__data[1U];
    __Vdly__CPU_top__DOT__cpu__DOT__fetch__DOT__data[2U] 
        = vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__data[2U];
    __Vdly__CPU_top__DOT__cpu__DOT__fetch__DOT__data[3U] 
        = vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__data[3U];
    __Vdly__CPU_top__DOT__cpu__DOT__csr__DOT__issued 
        = vlSelfRef.CPU_top__DOT__cpu__DOT__csr__DOT__issued;
    __Vdly__CPU_top__DOT__cpu__DOT__csr_irq_pending 
        = vlSelfRef.CPU_top__DOT__cpu__DOT__csr_irq_pending;
    __Vdly__CPU_top__DOT__cpu__DOT__csr_irq_pc = vlSelfRef.CPU_top__DOT__cpu__DOT__csr_irq_pc;
    __Vdly__CPU_top__DOT__cpu__DOT__csr__DOT__mstatus_mie 
        = vlSelfRef.CPU_top__DOT__cpu__DOT__csr__DOT__mstatus_mie;
    __Vdly__CPU_top__DOT__cpu__DOT__csr__DOT__mie_meie 
        = vlSelfRef.CPU_top__DOT__cpu__DOT__csr__DOT__mie_meie;
    __Vdly__CPU_top__DOT__cpu__DOT__csr__DOT__mie_mtie 
        = vlSelfRef.CPU_top__DOT__cpu__DOT__csr__DOT__mie_mtie;
    __Vdly__CPU_top__DOT__cpu__DOT__csr__DOT__mie_msie 
        = vlSelfRef.CPU_top__DOT__cpu__DOT__csr__DOT__mie_msie;
    __Vdly__CPU_top__DOT__cpu__DOT__csr__DOT__mtvec 
        = vlSelfRef.CPU_top__DOT__cpu__DOT__csr__DOT__mtvec;
    __Vdly__CPU_top__DOT__cpu__DOT__csr__DOT__mepc 
        = vlSelfRef.CPU_top__DOT__cpu__DOT__csr__DOT__mepc;
    __Vdly__CPU_top__DOT__cpu__DOT__csr__DOT__mip_meip 
        = vlSelfRef.CPU_top__DOT__cpu__DOT__csr__DOT__mip_meip;
    __Vdly__CPU_top__DOT__cpu__DOT__csr__DOT__mip_mtip 
        = vlSelfRef.CPU_top__DOT__cpu__DOT__csr__DOT__mip_mtip;
    __Vdly__CPU_top__DOT__cpu__DOT__csr__DOT__mip_msip 
        = vlSelfRef.CPU_top__DOT__cpu__DOT__csr__DOT__mip_msip;
    __Vdly__CPU_top__DOT__cpu__DOT__csr__DOT__mstatus_mpie 
        = vlSelfRef.CPU_top__DOT__cpu__DOT__csr__DOT__mstatus_mpie;
    __Vdly__CPU_top__DOT__cpu__DOT__execute__DOT__multiply__DOT__latch 
        = ((2U & ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__multiply__DOT__latch) 
                  << 1U)) | (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__mul_request));
    if (vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__genblk3__DOT__dcache__DOT__cache_rw) {
        __VdlyVal__CPU_top__DOT__cpu__DOT__memory__DOT__genblk3__DOT__dcache__DOT__cache__DOT__data__v0 
            = vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__genblk3__DOT__dcache__DOT__cache_wdata;
        __VdlyDim0__CPU_top__DOT__cpu__DOT__memory__DOT__genblk3__DOT__dcache__DOT__cache__DOT__data__v0 
            = vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__genblk3__DOT__dcache__DOT__cache_address;
        __VdlySet__CPU_top__DOT__cpu__DOT__memory__DOT__genblk3__DOT__dcache__DOT__cache__DOT__data__v0 = 1U;
    }
    vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT__cache__DOT__o_pa_ready = 0U;
    vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT__cache__DOT__o_pa_ready = 1U;
    vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__genblk3__DOT__dcache__DOT__cache__DOT__o_valid = 1U;
    vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__genblk3__DOT__dcache__DOT__cache__DOT__o_ready = 1U;
    vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT__set_r 
        = vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT__cache_rd_set;
    vlSelfRef.CPU_top__DOT__bus__DOT__state = vlSelfRef.CPU_top__DOT__bus__DOT__next_state;
    vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT__cache__DOT__o_pb_ready = 0U;
    if (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT__cache_wr_request) {
        __VdlyVal__CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT__cache__DOT__data__v0 
            = vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT__cache_wr_wdata;
        __VdlyDim0__CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT__cache__DOT__data__v0 
            = vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT__cache_wr_set;
        __VdlySet__CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT__cache__DOT__data__v0 = 1U;
        vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT__cache__DOT__o_pb_ready = 1U;
    }
    if ((1U & (~ (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT____Vcellinp__fetch__i_busy)))) {
        vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_skid__DOT__r_data[0U] 
            = vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__data[0U];
        vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_skid__DOT__r_data[1U] 
            = vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__data[1U];
        vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_skid__DOT__r_data[2U] 
            = vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__data[2U];
        vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_skid__DOT__r_data[3U] 
            = vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__data[3U];
    }
    if (vlSelfRef.reset) {
        vlSelfRef.CPU_top__DOT__cpu__DOT__csr__DOT__cycle = 0ULL;
        __Vdly__CPU_top__DOT__cpu__DOT__csr__DOT__wtime = 0ULL;
        __Vdly__CPU_top__DOT__cpu__DOT__csr__DOT__prescale = 0U;
        vlSelfRef.CPU_top__DOT__cpu__DOT__decode_fault = 0U;
        __Vdly__CPU_top__DOT__cpu__DOT__writeback__DOT__retired = 0ULL;
        vlSelfRef.CPU_top__DOT__cpu__DOT__writeback__DOT__data = 0ULL;
    } else {
        vlSelfRef.CPU_top__DOT__cpu__DOT__csr__DOT__cycle 
            = (1ULL + vlSelfRef.CPU_top__DOT__cpu__DOT__csr__DOT__cycle);
        __Vdly__CPU_top__DOT__cpu__DOT__csr__DOT__prescale 
            = (0x3fffU & ((IData)(1U) + (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__csr__DOT__prescale)));
        if ((0x2710U <= (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__csr__DOT__prescale))) {
            __Vdly__CPU_top__DOT__cpu__DOT__csr__DOT__wtime 
                = (1ULL + vlSelfRef.CPU_top__DOT__cpu__DOT__csr__DOT__wtime);
            __Vdly__CPU_top__DOT__cpu__DOT__csr__DOT__prescale = 0U;
        }
        if (((1U & (vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__data[2U] 
                    >> 5U)) != (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__writeback__DOT__last_strobe))) {
            __Vdly__CPU_top__DOT__cpu__DOT__writeback__DOT__retired 
                = (1ULL + vlSelfRef.CPU_top__DOT__cpu__DOT__writeback__DOT__retired);
            vlSelfRef.CPU_top__DOT__cpu__DOT__writeback__DOT__last_pc 
                = ((vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__data[2U] 
                    << 0x1bU) | (vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__data[1U] 
                                 >> 5U));
        }
        vlSelfRef.CPU_top__DOT__cpu__DOT__writeback__DOT__data 
            = (0x1fffffffffULL & (((QData)((IData)(
                                                   vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__data[1U])) 
                                   << 0x20U) | (QData)((IData)(
                                                               vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__data[0U]))));
    }
    if (vlSelfRef.reset) {
        __Vdly__CPU_top__DOT__cpu__DOT__csr__DOT__mstatus_mie = 0U;
        __Vdly__CPU_top__DOT__cpu__DOT__csr__DOT__mie_meie = 0U;
        __Vdly__CPU_top__DOT__cpu__DOT__csr__DOT__mie_mtie = 0U;
        __Vdly__CPU_top__DOT__cpu__DOT__csr__DOT__mie_msie = 0U;
        __Vdly__CPU_top__DOT__cpu__DOT__csr__DOT__mtvec = 0U;
        __Vdly__CPU_top__DOT__cpu__DOT__csr__DOT__mepc = 0U;
        vlSelfRef.CPU_top__DOT__cpu__DOT__csr__DOT__mcause = 0U;
        __Vdly__CPU_top__DOT__cpu__DOT__csr__DOT__mip_meip = 0U;
        __Vdly__CPU_top__DOT__cpu__DOT__csr__DOT__mip_mtip = 0U;
        __Vdly__CPU_top__DOT__cpu__DOT__csr__DOT__mip_msip = 0U;
        vlSelfRef.CPU_top__DOT__cpu__DOT__csr__DOT__mscratch = 0U;
        __Vdly__CPU_top__DOT__cpu__DOT__csr__DOT__issued = 0U;
        __Vdly__CPU_top__DOT__cpu__DOT__csr_irq_pending = 0U;
    } else {
        if (vlSelfRef.CPU_top__DOT__cpu__DOT__csr_wdata_wr) {
            if ((0x300U == (0xfffU & ((vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[1U] 
                                       << 2U) | (vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[0U] 
                                                 >> 0x1eU))))) {
                __Vdly__CPU_top__DOT__cpu__DOT__csr__DOT__mstatus_mie 
                    = (1U & (vlSelfRef.CPU_top__DOT__cpu__DOT__csr_wdata 
                             >> 3U));
            } else if ((0x304U == (0xfffU & ((vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[1U] 
                                              << 2U) 
                                             | (vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[0U] 
                                                >> 0x1eU))))) {
                __Vdly__CPU_top__DOT__cpu__DOT__csr__DOT__mie_meie 
                    = (1U & (vlSelfRef.CPU_top__DOT__cpu__DOT__csr_wdata 
                             >> 0xbU));
                __Vdly__CPU_top__DOT__cpu__DOT__csr__DOT__mie_mtie 
                    = (1U & (vlSelfRef.CPU_top__DOT__cpu__DOT__csr_wdata 
                             >> 7U));
                __Vdly__CPU_top__DOT__cpu__DOT__csr__DOT__mie_msie 
                    = (1U & (vlSelfRef.CPU_top__DOT__cpu__DOT__csr_wdata 
                             >> 3U));
            } else if ((0x305U == (0xfffU & ((vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[1U] 
                                              << 2U) 
                                             | (vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[0U] 
                                                >> 0x1eU))))) {
                __Vdly__CPU_top__DOT__cpu__DOT__csr__DOT__mtvec 
                    = vlSelfRef.CPU_top__DOT__cpu__DOT__csr_wdata;
            } else if ((0x340U == (0xfffU & ((vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[1U] 
                                              << 2U) 
                                             | (vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[0U] 
                                                >> 0x1eU))))) {
                vlSelfRef.CPU_top__DOT__cpu__DOT__csr__DOT__mscratch 
                    = vlSelfRef.CPU_top__DOT__cpu__DOT__csr_wdata;
            } else if ((0x341U == (0xfffU & ((vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[1U] 
                                              << 2U) 
                                             | (vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[0U] 
                                                >> 0x1eU))))) {
                __Vdly__CPU_top__DOT__cpu__DOT__csr__DOT__mepc 
                    = vlSelfRef.CPU_top__DOT__cpu__DOT__csr_wdata;
            } else if ((0x344U == (0xfffU & ((vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[1U] 
                                              << 2U) 
                                             | (vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[0U] 
                                                >> 0x1eU))))) {
                __Vdly__CPU_top__DOT__cpu__DOT__csr__DOT__mip_mtip 
                    = (1U & (vlSelfRef.CPU_top__DOT__cpu__DOT__csr_wdata 
                             >> 7U));
                __Vdly__CPU_top__DOT__cpu__DOT__csr__DOT__mip_msip 
                    = (1U & (vlSelfRef.CPU_top__DOT__cpu__DOT__csr_wdata 
                             >> 3U));
            }
        }
        if (((IData)(vlSelfRef.timer_interrupt) & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__csr__DOT__mie_mtie))) {
            __Vdly__CPU_top__DOT__cpu__DOT__csr__DOT__mip_mtip = 1U;
        }
        if (((IData)(vlSelfRef.external_interrupt) 
             & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__csr__DOT__mie_meie))) {
            __Vdly__CPU_top__DOT__cpu__DOT__csr__DOT__mip_meip = 1U;
        }
        if (((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute_ecall) 
             & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__csr__DOT__mie_msie))) {
            __Vdly__CPU_top__DOT__cpu__DOT__csr__DOT__mip_msip = 1U;
        }
        if (((~ (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__csr_irq_pending)) 
             & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__csr__DOT__mstatus_mie))) {
            if (vlSelfRef.CPU_top__DOT__cpu__DOT__csr__DOT__mip_meip) {
                vlSelfRef.CPU_top__DOT__cpu__DOT__csr__DOT__mcause = 0x80000800U;
                __Vdly__CPU_top__DOT__cpu__DOT__csr__DOT__issued = 2U;
            } else if (vlSelfRef.CPU_top__DOT__cpu__DOT__csr__DOT__mip_mtip) {
                vlSelfRef.CPU_top__DOT__cpu__DOT__csr__DOT__mcause = 0x80000080U;
                __Vdly__CPU_top__DOT__cpu__DOT__csr__DOT__issued = 1U;
            } else if (vlSelfRef.CPU_top__DOT__cpu__DOT__csr__DOT__mip_msip) {
                vlSelfRef.CPU_top__DOT__cpu__DOT__csr__DOT__mcause = 0x800U;
                __Vdly__CPU_top__DOT__cpu__DOT__csr__DOT__issued = 4U;
            }
            if ((((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__csr__DOT__mip_mtip) 
                  | (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__csr__DOT__mip_meip)) 
                 | (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__csr__DOT__mip_msip))) {
                __Vdly__CPU_top__DOT__cpu__DOT__csr_irq_pending = 1U;
                __Vdly__CPU_top__DOT__cpu__DOT__csr_irq_pc 
                    = vlSelfRef.CPU_top__DOT__cpu__DOT__csr__DOT__mtvec;
                __Vdly__CPU_top__DOT__cpu__DOT__csr__DOT__mstatus_mpie 
                    = vlSelfRef.CPU_top__DOT__cpu__DOT__csr__DOT__mstatus_mie;
                __Vdly__CPU_top__DOT__cpu__DOT__csr__DOT__mstatus_mie = 0U;
            }
        }
        if (vlSelfRef.CPU_top__DOT__cpu__DOT__execute_mret) {
            if (VL_UNLIKELY((vlSelfRef.CPU_top__DOT__cpu__DOT__csr__DOT__mstatus_mie))) {
                VL_WRITEF_NX("recursive interrupt detected, not validated\n",0);
            }
            __Vdly__CPU_top__DOT__cpu__DOT__csr__DOT__mstatus_mie 
                = vlSelfRef.CPU_top__DOT__cpu__DOT__csr__DOT__mstatus_mpie;
            __Vdly__CPU_top__DOT__cpu__DOT__csr__DOT__mstatus_mpie = 0U;
        }
        if (vlSelfRef.CPU_top__DOT__cpu__DOT__csr_irq_dispatched) {
            __Vdly__CPU_top__DOT__cpu__DOT__csr__DOT__mepc 
                = vlSelfRef.CPU_top__DOT__cpu__DOT__csr_irq_epc;
            if ((1U & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__csr__DOT__issued))) {
                __Vdly__CPU_top__DOT__cpu__DOT__csr__DOT__mip_mtip = 0U;
            }
            __Vdly__CPU_top__DOT__cpu__DOT__csr_irq_pending = 0U;
            if ((2U & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__csr__DOT__issued))) {
                __Vdly__CPU_top__DOT__cpu__DOT__csr__DOT__mip_meip = 0U;
            }
            if ((4U & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__csr__DOT__issued))) {
                __Vdly__CPU_top__DOT__cpu__DOT__csr__DOT__mip_msip = 0U;
            }
            __Vdly__CPU_top__DOT__cpu__DOT__csr__DOT__issued = 0U;
        }
    }
    vlSelfRef.CPU_top__DOT__cpu__DOT__csr__DOT__prescale 
        = __Vdly__CPU_top__DOT__cpu__DOT__csr__DOT__prescale;
    vlSelfRef.CPU_top__DOT__cpu__DOT__csr__DOT__wtime 
        = __Vdly__CPU_top__DOT__cpu__DOT__csr__DOT__wtime;
    vlSelfRef.CPU_top__DOT__cpu__DOT__writeback__DOT__retired 
        = __Vdly__CPU_top__DOT__cpu__DOT__writeback__DOT__retired;
    vlSelfRef.CPU_top__DOT__cpu__DOT__csr__DOT__issued 
        = __Vdly__CPU_top__DOT__cpu__DOT__csr__DOT__issued;
    vlSelfRef.CPU_top__DOT__cpu__DOT__csr__DOT__mstatus_mie 
        = __Vdly__CPU_top__DOT__cpu__DOT__csr__DOT__mstatus_mie;
    vlSelfRef.CPU_top__DOT__cpu__DOT__csr__DOT__mie_meie 
        = __Vdly__CPU_top__DOT__cpu__DOT__csr__DOT__mie_meie;
    vlSelfRef.CPU_top__DOT__cpu__DOT__csr__DOT__mie_mtie 
        = __Vdly__CPU_top__DOT__cpu__DOT__csr__DOT__mie_mtie;
    vlSelfRef.CPU_top__DOT__cpu__DOT__csr__DOT__mie_msie 
        = __Vdly__CPU_top__DOT__cpu__DOT__csr__DOT__mie_msie;
    vlSelfRef.CPU_top__DOT__cpu__DOT__csr__DOT__mtvec 
        = __Vdly__CPU_top__DOT__cpu__DOT__csr__DOT__mtvec;
    vlSelfRef.CPU_top__DOT__cpu__DOT__csr__DOT__mip_meip 
        = __Vdly__CPU_top__DOT__cpu__DOT__csr__DOT__mip_meip;
    vlSelfRef.CPU_top__DOT__cpu__DOT__csr__DOT__mip_mtip 
        = __Vdly__CPU_top__DOT__cpu__DOT__csr__DOT__mip_mtip;
    vlSelfRef.CPU_top__DOT__cpu__DOT__csr__DOT__mip_msip 
        = __Vdly__CPU_top__DOT__cpu__DOT__csr__DOT__mip_msip;
    vlSelfRef.CPU_top__DOT__cpu__DOT__csr__DOT__mstatus_mpie 
        = __Vdly__CPU_top__DOT__cpu__DOT__csr__DOT__mstatus_mpie;
    __Vdly__CPU_top__DOT__cpu__DOT__memory__DOT__dcache_ready = 0U;
    __Vdly__CPU_top__DOT__cpu__DOT__memory__DOT__genblk3__DOT__dcache__DOT__cache_rw = 0U;
    if ((8U & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__genblk3__DOT__dcache__DOT__state))) {
        if ((4U & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__genblk3__DOT__dcache__DOT__state))) {
            __Vdly__CPU_top__DOT__cpu__DOT__memory__DOT__genblk3__DOT__dcache__DOT__state = 0U;
        } else if ((2U & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__genblk3__DOT__dcache__DOT__state))) {
            if ((1U & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__genblk3__DOT__dcache__DOT__state))) {
                if ((0x1000U > (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__genblk3__DOT__dcache__DOT__flush_address))) {
                    __Vdly__CPU_top__DOT__cpu__DOT__memory__DOT__genblk3__DOT__dcache__DOT__flush_address 
                        = (0x1fffU & ((IData)(1U) + (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__genblk3__DOT__dcache__DOT__flush_address)));
                    __Vdly__CPU_top__DOT__cpu__DOT__memory__DOT__genblk3__DOT__dcache__DOT__cache_rw = 1U;
                    vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__genblk3__DOT__dcache__DOT__cache_wdata = 0xfffffff0ULL;
                } else {
                    __Vdly__CPU_top__DOT__cpu__DOT__memory__DOT__genblk3__DOT__dcache__DOT__flush_address = 0U;
                    __Vdly__CPU_top__DOT__cpu__DOT__memory__DOT__genblk3__DOT__dcache__DOT__state = 0U;
                }
            } else {
                vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__wb_rw = 0U;
                vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__wb_address 
                    = (0xfffffffcU & ((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__data[1U] 
                                       << 0x1bU) | 
                                      (0x7fffffcU & 
                                       (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__data[0U] 
                                        >> 5U))));
                vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__wb_request = 1U;
                if (vlSelfRef.CPU_top__DOT__cpu_dbus_ready) {
                    __Vdly__CPU_top__DOT__cpu__DOT__memory__DOT__genblk3__DOT__dcache__DOT__cache_rw = 1U;
                    vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__genblk3__DOT__dcache__DOT__cache_wdata 
                        = (((QData)((IData)(vlSelfRef.bus_rdata)) 
                            << 0x20U) | (QData)((IData)(
                                                        (1U 
                                                         | (0xfffffffcU 
                                                            & ((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__data[1U] 
                                                                << 0x1bU) 
                                                               | (0x7fffffcU 
                                                                  & (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__data[0U] 
                                                                     >> 5U))))))));
                    vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__wb_request = 0U;
                    __Vdly__CPU_top__DOT__cpu__DOT__memory__DOT__dcache_rdata 
                        = vlSelfRef.bus_rdata;
                    __Vdly__CPU_top__DOT__cpu__DOT__memory__DOT__dcache_ready = 1U;
                    __Vdly__CPU_top__DOT__cpu__DOT__memory__DOT__genblk3__DOT__dcache__DOT__state = 0U;
                }
            }
        } else if ((1U & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__genblk3__DOT__dcache__DOT__state))) {
            if (vlSelfRef.CPU_top__DOT__cpu_dbus_ready) {
                vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__wb_request = 0U;
                __Vdly__CPU_top__DOT__cpu__DOT__memory__DOT__genblk3__DOT__dcache__DOT__state = 0xaU;
            }
        } else if (((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__genblk3__DOT__dcache__DOT__cache_rdata) 
                    & (((IData)((vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__genblk3__DOT__dcache__DOT__cache_rdata 
                                 >> 2U)) << 2U) == 
                       (0xfffffffcU & ((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__data[1U] 
                                        << 0x1bU) | 
                                       (0x7fffffcU 
                                        & (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__data[0U] 
                                           >> 5U))))))) {
            __Vdly__CPU_top__DOT__cpu__DOT__memory__DOT__dcache_rdata 
                = (IData)((vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__genblk3__DOT__dcache__DOT__cache_rdata 
                           >> 0x20U));
            __Vdly__CPU_top__DOT__cpu__DOT__memory__DOT__dcache_ready = 1U;
            __Vdly__CPU_top__DOT__cpu__DOT__memory__DOT__genblk3__DOT__dcache__DOT__state = 0U;
        } else if ((1U & (IData)((vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__genblk3__DOT__dcache__DOT__cache_rdata 
                                  >> 1U)))) {
            vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__wb_rw = 1U;
            vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__wb_address 
                = ((IData)((vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__genblk3__DOT__dcache__DOT__cache_rdata 
                            >> 2U)) << 2U);
            vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__wb_request = 1U;
            vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__wb_wdata 
                = (IData)((vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__genblk3__DOT__dcache__DOT__cache_rdata 
                           >> 0x20U));
            __Vdly__CPU_top__DOT__cpu__DOT__memory__DOT__genblk3__DOT__dcache__DOT__state = 9U;
        } else {
            vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__wb_rw = 0U;
            vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__wb_address 
                = (0xfffffffcU & ((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__data[1U] 
                                   << 0x1bU) | (0x7fffffcU 
                                                & (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__data[0U] 
                                                   >> 5U))));
            vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__wb_request = 1U;
            __Vdly__CPU_top__DOT__cpu__DOT__memory__DOT__genblk3__DOT__dcache__DOT__state = 0xaU;
        }
    } else if ((4U & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__genblk3__DOT__dcache__DOT__state))) {
        if ((2U & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__genblk3__DOT__dcache__DOT__state))) {
            if ((1U & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__genblk3__DOT__dcache__DOT__state))) {
                if (vlSelfRef.CPU_top__DOT__cpu_dbus_ready) {
                    __Vdly__CPU_top__DOT__cpu__DOT__memory__DOT__genblk3__DOT__dcache__DOT__cache_rw = 1U;
                    vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__genblk3__DOT__dcache__DOT__cache_wdata 
                        = (((QData)((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__dcache_wdata)) 
                            << 0x20U) | (QData)((IData)(
                                                        (3U 
                                                         | (0xfffffffcU 
                                                            & ((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__data[1U] 
                                                                << 0x1bU) 
                                                               | (0x7fffffcU 
                                                                  & (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__data[0U] 
                                                                     >> 5U))))))));
                    vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__wb_request = 0U;
                    __Vdly__CPU_top__DOT__cpu__DOT__memory__DOT__dcache_ready = 1U;
                    __Vdly__CPU_top__DOT__cpu__DOT__memory__DOT__genblk3__DOT__dcache__DOT__state = 0U;
                }
            } else if (((IData)((vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__genblk3__DOT__dcache__DOT__cache_rdata 
                                 >> 1U)) & (((IData)(
                                                     (vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__genblk3__DOT__dcache__DOT__cache_rdata 
                                                      >> 2U)) 
                                             << 2U) 
                                            != (0xfffffffcU 
                                                & ((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__data[1U] 
                                                    << 0x1bU) 
                                                   | (0x7fffffcU 
                                                      & (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__data[0U] 
                                                         >> 5U))))))) {
                vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__wb_rw = 1U;
                vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__wb_address 
                    = ((IData)((vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__genblk3__DOT__dcache__DOT__cache_rdata 
                                >> 2U)) << 2U);
                vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__wb_request = 1U;
                vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__wb_wdata 
                    = (IData)((vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__genblk3__DOT__dcache__DOT__cache_rdata 
                               >> 0x20U));
                __Vdly__CPU_top__DOT__cpu__DOT__memory__DOT__genblk3__DOT__dcache__DOT__state = 7U;
            } else {
                __Vdly__CPU_top__DOT__cpu__DOT__memory__DOT__genblk3__DOT__dcache__DOT__cache_rw = 1U;
                vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__genblk3__DOT__dcache__DOT__cache_wdata 
                    = (((QData)((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__dcache_wdata)) 
                        << 0x20U) | (QData)((IData)(
                                                    (3U 
                                                     | (0xfffffffcU 
                                                        & ((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__data[1U] 
                                                            << 0x1bU) 
                                                           | (0x7fffffcU 
                                                              & (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__data[0U] 
                                                                 >> 5U))))))));
                __Vdly__CPU_top__DOT__cpu__DOT__memory__DOT__dcache_ready = 1U;
                __Vdly__CPU_top__DOT__cpu__DOT__memory__DOT__genblk3__DOT__dcache__DOT__state = 0U;
            }
        } else if ((1U & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__genblk3__DOT__dcache__DOT__state))) {
            if (vlSelfRef.CPU_top__DOT__cpu_dbus_ready) {
                vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__wb_request = 0U;
                __Vdly__CPU_top__DOT__cpu__DOT__memory__DOT__dcache_rdata 
                    = vlSelfRef.bus_rdata;
                __Vdly__CPU_top__DOT__cpu__DOT__memory__DOT__dcache_ready = 1U;
                __Vdly__CPU_top__DOT__cpu__DOT__memory__DOT__genblk3__DOT__dcache__DOT__state = 0U;
            }
        } else {
            __Vdly__CPU_top__DOT__cpu__DOT__memory__DOT__genblk3__DOT__dcache__DOT__flush_address 
                = (0x1fffU & ((IData)(1U) + (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__genblk3__DOT__dcache__DOT__flush_address)));
            __Vdly__CPU_top__DOT__cpu__DOT__memory__DOT__genblk3__DOT__dcache__DOT__state = 1U;
        }
    } else if ((2U & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__genblk3__DOT__dcache__DOT__state))) {
        if ((1U & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__genblk3__DOT__dcache__DOT__state))) {
            if (vlSelfRef.CPU_top__DOT__cpu_dbus_ready) {
                __Vdly__CPU_top__DOT__cpu__DOT__memory__DOT__genblk3__DOT__dcache__DOT__cache_rw = 1U;
                vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__genblk3__DOT__dcache__DOT__cache_wdata 
                    = (((QData)((IData)((vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__genblk3__DOT__dcache__DOT__cache_rdata 
                                         >> 0x20U))) 
                        << 0x20U) | (QData)((IData)(
                                                    (1U 
                                                     | ((IData)(
                                                                (vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__genblk3__DOT__dcache__DOT__cache_rdata 
                                                                 >> 2U)) 
                                                        << 2U)))));
                vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__wb_request = 0U;
                __Vdly__CPU_top__DOT__cpu__DOT__memory__DOT__genblk3__DOT__dcache__DOT__state = 4U;
            }
        } else if ((1U & (IData)((vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__genblk3__DOT__dcache__DOT__cache_rdata 
                                  >> 1U)))) {
            vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__wb_rw = 1U;
            vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__wb_address 
                = ((IData)((vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__genblk3__DOT__dcache__DOT__cache_rdata 
                            >> 2U)) << 2U);
            vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__wb_request = 1U;
            vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__wb_wdata 
                = (IData)((vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__genblk3__DOT__dcache__DOT__cache_rdata 
                           >> 0x20U));
            __Vdly__CPU_top__DOT__cpu__DOT__memory__DOT__genblk3__DOT__dcache__DOT__state = 3U;
        } else {
            __Vdly__CPU_top__DOT__cpu__DOT__memory__DOT__genblk3__DOT__dcache__DOT__flush_address 
                = (0x1fffU & ((IData)(1U) + (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__genblk3__DOT__dcache__DOT__flush_address)));
            __Vdly__CPU_top__DOT__cpu__DOT__memory__DOT__genblk3__DOT__dcache__DOT__state = 1U;
        }
    } else if ((1U & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__genblk3__DOT__dcache__DOT__state))) {
        if ((1U & (~ (IData)(vlSelfRef.CPU_top__DOT__cpu_dbus_ready)))) {
            if ((0x1000U > (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__genblk3__DOT__dcache__DOT__flush_address))) {
                __Vdly__CPU_top__DOT__cpu__DOT__memory__DOT__genblk3__DOT__dcache__DOT__state = 2U;
            } else {
                __Vdly__CPU_top__DOT__cpu__DOT__memory__DOT__dcache_ready = 1U;
                __Vdly__CPU_top__DOT__cpu__DOT__memory__DOT__genblk3__DOT__dcache__DOT__state = 0U;
            }
        }
    } else if (((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__dcache_request) 
                & (~ (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__dcache_ready)))) {
        if (vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__dcache_flush) {
            __Vdly__CPU_top__DOT__cpu__DOT__memory__DOT__genblk3__DOT__dcache__DOT__flush_address = 0U;
            __Vdly__CPU_top__DOT__cpu__DOT__memory__DOT__genblk3__DOT__dcache__DOT__state = 1U;
        } else if ((2U == (0xfU & (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__data[1U] 
                                   >> 1U)))) {
            if (vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__dcache_rw) {
                if (((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__genblk3__DOT__dcache__DOT__cache_rdata) 
                     & (((IData)((vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__genblk3__DOT__dcache__DOT__cache_rdata 
                                  >> 2U)) << 2U) == 
                        (0xfffffffcU & ((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__data[1U] 
                                         << 0x1bU) 
                                        | (0x7fffffcU 
                                           & (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__data[0U] 
                                              >> 5U))))))) {
                    __Vdly__CPU_top__DOT__cpu__DOT__memory__DOT__genblk3__DOT__dcache__DOT__cache_rw = 1U;
                    vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__genblk3__DOT__dcache__DOT__cache_wdata 
                        = (((QData)((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__dcache_wdata)) 
                            << 0x20U) | (QData)((IData)(
                                                        (3U 
                                                         | (0xfffffffcU 
                                                            & ((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__data[1U] 
                                                                << 0x1bU) 
                                                               | (0x7fffffcU 
                                                                  & (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__data[0U] 
                                                                     >> 5U))))))));
                    __Vdly__CPU_top__DOT__cpu__DOT__memory__DOT__dcache_ready = 1U;
                } else {
                    __Vdly__CPU_top__DOT__cpu__DOT__memory__DOT__genblk3__DOT__dcache__DOT__state = 6U;
                }
            } else if (((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__genblk3__DOT__dcache__DOT__cache_rdata) 
                        & (((IData)((vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__genblk3__DOT__dcache__DOT__cache_rdata 
                                     >> 2U)) << 2U) 
                           == (0xfffffffcU & ((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__data[1U] 
                                               << 0x1bU) 
                                              | (0x7fffffcU 
                                                 & (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__data[0U] 
                                                    >> 5U))))))) {
                __Vdly__CPU_top__DOT__cpu__DOT__memory__DOT__dcache_rdata 
                    = (IData)((vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__genblk3__DOT__dcache__DOT__cache_rdata 
                               >> 0x20U));
                __Vdly__CPU_top__DOT__cpu__DOT__memory__DOT__dcache_ready = 1U;
            } else {
                __Vdly__CPU_top__DOT__cpu__DOT__memory__DOT__genblk3__DOT__dcache__DOT__state = 8U;
            }
        } else {
            vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__wb_rw 
                = vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__dcache_rw;
            vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__wb_address 
                = (0xfffffffcU & ((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__data[1U] 
                                   << 0x1bU) | (0x7fffffcU 
                                                & (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__data[0U] 
                                                   >> 5U))));
            vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__wb_request = 1U;
            vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__wb_wdata 
                = vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__dcache_wdata;
            __Vdly__CPU_top__DOT__cpu__DOT__memory__DOT__genblk3__DOT__dcache__DOT__state = 5U;
        }
    }
    vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT__cache_wr_request = 0U;
    if (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT__initialized) {
        if (((~ (IData)(vlSelfRef.CPU_top__DOT__cpu_ibus_request)) 
             & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT__cache_invalid))) {
            vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT__cache_wr_set 
                = (0xfffU & (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__pc 
                             >> 2U));
            vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT__cache_wr_wdata 
                = ((0xffffffffULL & vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT__cache_wr_wdata) 
                   | ((QData)((IData)((0x40000U | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__pc 
                                                   >> 0xeU)))) 
                      << 0x20U));
            __Vdly__CPU_top__DOT__cpu_ibus_request = 1U;
            vlSelfRef.CPU_top__DOT__cpu_ibus_address 
                = vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__pc;
        }
        if (((IData)(vlSelfRef.CPU_top__DOT__cpu_ibus_request) 
             & (IData)(vlSelfRef.CPU_top__DOT__cpu_ibus_ready))) {
            vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT__cache_wr_request = 1U;
            vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT__cache_wr_wdata 
                = ((0x7ffff00000000ULL & vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT__cache_wr_wdata) 
                   | (IData)((IData)(vlSelfRef.bus_rdata)));
            __Vdly__CPU_top__DOT__cpu_ibus_request = 0U;
        }
    }
    if ((1U & (~ (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT__initialized)))) {
        if ((0x1000U > vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT__clear_set)) {
            vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT__cache_wr_request = 1U;
            vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT__cache_wr_set 
                = (0xfffU & vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT__clear_set);
            vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT__cache_wr_wdata = 0ULL;
            vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT__clear_set 
                = ((IData)(1U) + vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT__clear_set);
        } else {
            vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT__initialized = 1U;
        }
    }
    if (vlSelfRef.reset) {
        __Vdly__CPU_top__DOT__cpu__DOT__memory__DOT__genblk3__DOT__dcache__DOT__flush_address = 0U;
        __Vdly__CPU_top__DOT__cpu__DOT__memory__DOT__genblk3__DOT__dcache__DOT__state = 0xbU;
        vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT__clear_set = 0U;
        vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT__initialized = 0U;
        __Vdly__CPU_top__DOT__cpu__DOT__fetch__DOT__state = 0U;
        __Vdly__CPU_top__DOT__cpu__DOT__fetch__DOT__pc = 0U;
        __Vdly__CPU_top__DOT__cpu__DOT__fetch__DOT__data[0U] = 0U;
        __Vdly__CPU_top__DOT__cpu__DOT__fetch__DOT__data[1U] = 0U;
        __Vdly__CPU_top__DOT__cpu__DOT__fetch__DOT__data[2U] = 0U;
        __Vdly__CPU_top__DOT__cpu__DOT__fetch__DOT__data[3U] = 0U;
        __Vdly__CPU_top__DOT__cpu__DOT__fetch__DOT__irq_pending_r = 0U;
        __Vdly__CPU_top__DOT__cpu__DOT__execute__DOT__last_strobe = 0U;
        __Vdly__CPU_top__DOT__cpu__DOT__execute__DOT__data[0U] = 0U;
        __Vdly__CPU_top__DOT__cpu__DOT__execute__DOT__data[1U] = 0U;
        __Vdly__CPU_top__DOT__cpu__DOT__execute__DOT__data[2U] = 0U;
        __Vdly__CPU_top__DOT__cpu__DOT__execute__DOT__data[3U] = 0U;
        vlSelfRef.CPU_top__DOT__cpu__DOT__csr_wdata_wr = 0U;
        vlSelfRef.CPU_top__DOT__cpu__DOT__csr_wdata = 0U;
        vlSelfRef.CPU_top__DOT__cpu__DOT__execute_jump = 0U;
        vlSelfRef.CPU_top__DOT__cpu__DOT__execute_jump_pc = 0U;
        vlSelfRef.CPU_top__DOT__cpu__DOT__execute_mret = 0U;
        vlSelfRef.CPU_top__DOT__cpu__DOT__execute_ecall = 0U;
        vlSelfRef.CPU_top__DOT__cpu__DOT__execute_fault = 0U;
        vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[0U] = 0U;
        vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[1U] = 0U;
        vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[2U] = 0U;
        vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[3U] = 0U;
    } else {
        vlSelfRef.CPU_top__DOT__cpu__DOT__csr_irq_dispatched = 0U;
        if ((0U == (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__state))) {
            if ((1U == (((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__irq_pending_r) 
                         << 1U) | (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__csr_irq_pending)))) {
                vlSelfRef.CPU_top__DOT__cpu__DOT__csr_irq_dispatched = 1U;
                vlSelfRef.CPU_top__DOT__cpu__DOT__csr_irq_epc 
                    = vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__pc;
                __Vdly__CPU_top__DOT__cpu__DOT__fetch__DOT__pc 
                    = vlSelfRef.CPU_top__DOT__cpu__DOT__csr_irq_pc;
            } else if (((~ (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT____Vcellinp__fetch__i_busy)) 
                        & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__icache_ready))) {
                __Vdly__CPU_top__DOT__cpu__DOT__fetch__DOT__data[1U] 
                    = ((0xfffffU & __Vdly__CPU_top__DOT__cpu__DOT__fetch__DOT__data[1U]) 
                       | ((IData)((((QData)((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)) 
                                    << 0x20U) | (QData)((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__pc)))) 
                          << 0x14U));
                __Vdly__CPU_top__DOT__cpu__DOT__fetch__DOT__data[2U] 
                    = (((IData)((((QData)((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)) 
                                  << 0x20U) | (QData)((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__pc)))) 
                        >> 0xcU) | ((IData)(((((QData)((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)) 
                                               << 0x20U) 
                                              | (QData)((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__pc))) 
                                             >> 0x20U)) 
                                    << 0x14U));
                __Vdly__CPU_top__DOT__cpu__DOT__fetch__DOT__data[3U] 
                    = (0x1fffffU & (((IData)(((((QData)((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)) 
                                                << 0x20U) 
                                               | (QData)((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__pc))) 
                                              >> 0x20U)) 
                                     >> 0xcU) | (0x100000U 
                                                 & ((~ 
                                                     (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__data[3U] 
                                                      >> 0x14U)) 
                                                    << 0x14U))));
                __Vdly__CPU_top__DOT__cpu__DOT__fetch__DOT__data[1U] 
                    = ((0xfff07fffU & __Vdly__CPU_top__DOT__cpu__DOT__fetch__DOT__data[1U]) 
                       | ((((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__is_JUMP_CONDITIONAL) 
                            | ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__is_I) 
                               | ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__is_R) 
                                  | ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__is_S) 
                                     | (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT____VdfgRegularize_hef2daed4_0_14)))))
                            ? (0x1fU & (IData)((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata 
                                                >> 0xfU)))
                            : 0U) << 0xfU));
                __Vdly__CPU_top__DOT__cpu__DOT__fetch__DOT__data[1U] 
                    = ((0xffff83ffU & __Vdly__CPU_top__DOT__cpu__DOT__fetch__DOT__data[1U]) 
                       | ((((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__is_JUMP_CONDITIONAL) 
                            | ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__is_R) 
                               | ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__is_S) 
                                  | (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__have_RS3))))
                            ? (0x1fU & (IData)((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata 
                                                >> 0x14U)))
                            : 0U) << 0xaU));
                __Vdly__CPU_top__DOT__cpu__DOT__fetch__DOT__data[1U] 
                    = ((0xfffffc1fU & __Vdly__CPU_top__DOT__cpu__DOT__fetch__DOT__data[1U]) 
                       | (((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__have_RS3)
                            ? (0x1fU & (IData)((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata 
                                                >> 0x1bU)))
                            : 0U) << 5U));
                __Vdly__CPU_top__DOT__cpu__DOT__fetch__DOT__data[1U] 
                    = ((0xffffffe0U & __Vdly__CPU_top__DOT__cpu__DOT__fetch__DOT__data[1U]) 
                       | (((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__is_I) 
                           | ((0x6fU == (0x7fU & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata))) 
                              | ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__is_R) 
                                 | (((0x17U == (0x7fU 
                                                & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata))) 
                                     | (0x37U == (0x7fU 
                                                  & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)))) 
                                    | (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT____VdfgRegularize_hef2daed4_0_14)))))
                           ? (0x1fU & (IData)((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata 
                                               >> 7U)))
                           : 0U));
                if (((((0x6fU == (0x7fU & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata))) 
                       | (0x67U == (0x707fU & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)))) 
                      | (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__is_JUMP_CONDITIONAL)) 
                     | (0x30200073U == (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)))) {
                    __Vdly__CPU_top__DOT__cpu__DOT__fetch__DOT__state = 1U;
                } else if (((0x73U == (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)) 
                            | (0x10500073U == (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)))) {
                    __Vdly__CPU_top__DOT__cpu__DOT__fetch__DOT__state = 2U;
                } else {
                    __Vdly__CPU_top__DOT__cpu__DOT__fetch__DOT__pc 
                        = ((IData)(4U) + vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__pc);
                }
            }
            __Vdly__CPU_top__DOT__cpu__DOT__fetch__DOT__irq_pending_r 
                = vlSelfRef.CPU_top__DOT__cpu__DOT__csr_irq_pending;
        } else if ((1U == (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__state))) {
            if (vlSelfRef.CPU_top__DOT__cpu__DOT__execute_jump) {
                __Vdly__CPU_top__DOT__cpu__DOT__fetch__DOT__pc 
                    = vlSelfRef.CPU_top__DOT__cpu__DOT__execute_jump_pc;
                __Vdly__CPU_top__DOT__cpu__DOT__fetch__DOT__state = 0U;
            }
        } else if ((2U == (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__state))) {
            if ((1U == (((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__irq_pending_r) 
                         << 1U) | (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__csr_irq_pending)))) {
                vlSelfRef.CPU_top__DOT__cpu__DOT__csr_irq_dispatched = 1U;
                vlSelfRef.CPU_top__DOT__cpu__DOT__csr_irq_epc 
                    = vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__pc;
                __Vdly__CPU_top__DOT__cpu__DOT__fetch__DOT__state = 0U;
                __Vdly__CPU_top__DOT__cpu__DOT__fetch__DOT__pc 
                    = vlSelfRef.CPU_top__DOT__cpu__DOT__csr_irq_pc;
            }
            __Vdly__CPU_top__DOT__cpu__DOT__fetch__DOT__irq_pending_r 
                = vlSelfRef.CPU_top__DOT__cpu__DOT__csr_irq_pending;
        } else {
            __Vdly__CPU_top__DOT__cpu__DOT__fetch__DOT__state = 0U;
        }
        vlSelfRef.CPU_top__DOT__cpu__DOT__csr_wdata_wr = 0U;
        vlSelfRef.CPU_top__DOT__cpu__DOT__execute_jump = 0U;
        vlSelfRef.CPU_top__DOT__cpu__DOT__execute_mret = 0U;
        vlSelfRef.CPU_top__DOT__cpu__DOT__execute_ecall = 0U;
        vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__mul_request = 0U;
        __Vdly__CPU_top__DOT__cpu__DOT__execute__DOT__mul_signed = 0U;
        vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__div_request = 0U;
        vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__div_signed = 0U;
        if (((~ (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__memory_busy)) 
             & ((1U & (vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[3U] 
                       >> 0x15U)) != (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__last_strobe)))) {
            __Vdly__CPU_top__DOT__cpu__DOT__execute__DOT__data[2U] 
                = ((0x7ffU & __Vdly__CPU_top__DOT__cpu__DOT__execute__DOT__data[2U]) 
                   | ((IData)(((QData)((IData)(((vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[3U] 
                                                 << 0xbU) 
                                                | (vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[2U] 
                                                   >> 0x15U)))) 
                               << 5U)) << 0xbU));
            __Vdly__CPU_top__DOT__cpu__DOT__execute__DOT__data[3U] 
                = ((0x10000U & __Vdly__CPU_top__DOT__cpu__DOT__execute__DOT__data[3U]) 
                   | (0x1ffffU & (((IData)(((QData)((IData)(
                                                            ((vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[3U] 
                                                              << 0xbU) 
                                                             | (vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[2U] 
                                                                >> 0x15U)))) 
                                            << 5U)) 
                                   >> 0x15U) | ((IData)(
                                                        (((QData)((IData)(
                                                                          ((vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[3U] 
                                                                            << 0xbU) 
                                                                           | (vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[2U] 
                                                                              >> 0x15U)))) 
                                                          << 5U) 
                                                         >> 0x20U)) 
                                                << 0xbU))));
            __Vdly__CPU_top__DOT__cpu__DOT__execute__DOT__data[1U] 
                = ((0xfffff83fU & __Vdly__CPU_top__DOT__cpu__DOT__execute__DOT__data[1U]) 
                   | (0xffffffc0U & ((0x600U & (vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[0U] 
                                                << 1U)) 
                                     | (0xc0U & vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[0U]))));
            __Vdly__CPU_top__DOT__cpu__DOT__execute__DOT__data[0U] 
                = (IData)((((QData)((IData)((1U & (
                                                   vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[0U] 
                                                   >> 5U)))) 
                            << 0x25U) | (((QData)((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__alu_signed_sum_result)) 
                                          << 5U) | (QData)((IData)(
                                                                   (0x1fU 
                                                                    & ((vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[2U] 
                                                                        << 2U) 
                                                                       | (vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[1U] 
                                                                          >> 0x1eU))))))));
            __Vdly__CPU_top__DOT__cpu__DOT__execute__DOT__data[1U] 
                = ((0xffffffc0U & __Vdly__CPU_top__DOT__cpu__DOT__execute__DOT__data[1U]) 
                   | (IData)(((((QData)((IData)((1U 
                                                 & (vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[0U] 
                                                    >> 5U)))) 
                                << 0x25U) | (((QData)((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__alu_signed_sum_result)) 
                                              << 5U) 
                                             | (QData)((IData)(
                                                               (0x1fU 
                                                                & ((vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[2U] 
                                                                    << 2U) 
                                                                   | (vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[1U] 
                                                                      >> 0x1eU))))))) 
                              >> 0x20U)));
            if ((0x20000000U & vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[0U])) {
                __Vdly__CPU_top__DOT__cpu__DOT__execute__DOT__data[1U] 
                    = ((0x7ffU & __Vdly__CPU_top__DOT__cpu__DOT__execute__DOT__data[1U]) 
                       | (((0U == (0xfU & (vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[0U] 
                                           >> 0x14U)))
                            ? vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__alu_signed_sum_result
                            : ((1U == (0xfU & (vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[0U] 
                                               >> 0x14U)))
                                ? vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__alu_signed_sum_result
                                : ((2U == (0xfU & (
                                                   vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[0U] 
                                                   >> 0x14U)))
                                    ? (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__alu_operand1 
                                       - vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__alu_operand2)
                                    : ((3U == (0xfU 
                                               & (vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[0U] 
                                                  >> 0x14U)))
                                        ? (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__alu_operand1 
                                           & vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__alu_operand2)
                                        : ((4U == (0xfU 
                                                   & (vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[0U] 
                                                      >> 0x14U)))
                                            ? (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__alu_operand1 
                                               | vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__alu_operand2)
                                            : ((5U 
                                                == 
                                                (0xfU 
                                                 & (vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[0U] 
                                                    >> 0x14U)))
                                                ? (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__alu_operand1 
                                                   ^ vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__alu_operand2)
                                                : 0U)))))) 
                          << 0xbU));
                __Vdly__CPU_top__DOT__cpu__DOT__execute__DOT__data[2U] 
                    = ((0xfffff800U & __Vdly__CPU_top__DOT__cpu__DOT__execute__DOT__data[2U]) 
                       | (((0U == (0xfU & (vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[0U] 
                                           >> 0x14U)))
                            ? vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__alu_signed_sum_result
                            : ((1U == (0xfU & (vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[0U] 
                                               >> 0x14U)))
                                ? vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__alu_signed_sum_result
                                : ((2U == (0xfU & (
                                                   vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[0U] 
                                                   >> 0x14U)))
                                    ? (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__alu_operand1 
                                       - vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__alu_operand2)
                                    : ((3U == (0xfU 
                                               & (vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[0U] 
                                                  >> 0x14U)))
                                        ? (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__alu_operand1 
                                           & vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__alu_operand2)
                                        : ((4U == (0xfU 
                                                   & (vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[0U] 
                                                      >> 0x14U)))
                                            ? (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__alu_operand1 
                                               | vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__alu_operand2)
                                            : ((5U 
                                                == 
                                                (0xfU 
                                                 & (vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[0U] 
                                                    >> 0x14U)))
                                                ? (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__alu_operand1 
                                                   ^ vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__alu_operand2)
                                                : 0U)))))) 
                          >> 0x15U));
                __Vdly__CPU_top__DOT__cpu__DOT__execute__DOT__last_strobe 
                    = (1U & (vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[3U] 
                             >> 0x15U));
                __Vdly__CPU_top__DOT__cpu__DOT__execute__DOT__data[3U] 
                    = ((0xffffU & __Vdly__CPU_top__DOT__cpu__DOT__execute__DOT__data[3U]) 
                       | (0x10000U & ((~ (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__data[3U] 
                                          >> 0x10U)) 
                                      << 0x10U)));
                __Vdly__CPU_top__DOT__cpu__DOT__execute__DOT__data[2U] 
                    = ((0xffff07ffU & __Vdly__CPU_top__DOT__cpu__DOT__execute__DOT__data[2U]) 
                       | (((0x200U & vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[0U])
                            ? 0U : (0x1fU & ((vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[2U] 
                                              << 2U) 
                                             | (vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[1U] 
                                                >> 0x1eU)))) 
                          << 0xbU));
            } else if ((0x10000000U & vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[0U])) {
                __Vdly__CPU_top__DOT__cpu__DOT__execute__DOT__data[1U] 
                    = ((0x7ffU & __Vdly__CPU_top__DOT__cpu__DOT__execute__DOT__data[1U]) 
                       | (((6U == (0xfU & (vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[0U] 
                                           >> 0x14U)))
                            ? (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__alu_operand1 
                               << (0x1fU & vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__alu_operand2))
                            : ((7U == (0xfU & (vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[0U] 
                                               >> 0x14U)))
                                ? (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__alu_operand1 
                                   >> (0x1fU & vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__alu_operand2))
                                : ((8U == (0xfU & (
                                                   vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[0U] 
                                                   >> 0x14U)))
                                    ? VL_SHIFTRS_III(32,32,5, vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__alu_operand1, 
                                                     (0x1fU 
                                                      & vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__alu_operand2))
                                    : 0U))) << 0xbU));
                __Vdly__CPU_top__DOT__cpu__DOT__execute__DOT__data[2U] 
                    = ((0xfffff800U & __Vdly__CPU_top__DOT__cpu__DOT__execute__DOT__data[2U]) 
                       | (((6U == (0xfU & (vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[0U] 
                                           >> 0x14U)))
                            ? (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__alu_operand1 
                               << (0x1fU & vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__alu_operand2))
                            : ((7U == (0xfU & (vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[0U] 
                                               >> 0x14U)))
                                ? (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__alu_operand1 
                                   >> (0x1fU & vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__alu_operand2))
                                : ((8U == (0xfU & (
                                                   vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[0U] 
                                                   >> 0x14U)))
                                    ? VL_SHIFTRS_III(32,32,5, vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__alu_operand1, 
                                                     (0x1fU 
                                                      & vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__alu_operand2))
                                    : 0U))) >> 0x15U));
                __Vdly__CPU_top__DOT__cpu__DOT__execute__DOT__last_strobe 
                    = (1U & (vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[3U] 
                             >> 0x15U));
                __Vdly__CPU_top__DOT__cpu__DOT__execute__DOT__data[3U] 
                    = ((0xffffU & __Vdly__CPU_top__DOT__cpu__DOT__execute__DOT__data[3U]) 
                       | (0x10000U & ((~ (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__data[3U] 
                                          >> 0x10U)) 
                                      << 0x10U)));
                __Vdly__CPU_top__DOT__cpu__DOT__execute__DOT__data[2U] 
                    = ((0xffff07ffU & __Vdly__CPU_top__DOT__cpu__DOT__execute__DOT__data[2U]) 
                       | (((0x200U & vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[0U])
                            ? 0U : (0x1fU & ((vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[2U] 
                                              << 2U) 
                                             | (vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[1U] 
                                                >> 0x1eU)))) 
                          << 0xbU));
            } else if ((0x8000000U & vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[0U])) {
                __Vdly__CPU_top__DOT__cpu__DOT__execute__DOT__data[1U] 
                    = ((0x7ffU & __Vdly__CPU_top__DOT__cpu__DOT__execute__DOT__data[1U]) 
                       | ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__alu_compare_result) 
                          << 0xbU));
                __Vdly__CPU_top__DOT__cpu__DOT__execute__DOT__data[2U] 
                    = ((0xfffff800U & __Vdly__CPU_top__DOT__cpu__DOT__execute__DOT__data[2U]) 
                       | ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__alu_compare_result) 
                          >> 0x15U));
                __Vdly__CPU_top__DOT__cpu__DOT__execute__DOT__last_strobe 
                    = (1U & (vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[3U] 
                             >> 0x15U));
                __Vdly__CPU_top__DOT__cpu__DOT__execute__DOT__data[3U] 
                    = ((0xffffU & __Vdly__CPU_top__DOT__cpu__DOT__execute__DOT__data[3U]) 
                       | (0x10000U & ((~ (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__data[3U] 
                                          >> 0x10U)) 
                                      << 0x10U)));
                __Vdly__CPU_top__DOT__cpu__DOT__execute__DOT__data[2U] 
                    = ((0xffff07ffU & __Vdly__CPU_top__DOT__cpu__DOT__execute__DOT__data[2U]) 
                       | (((0x200U & vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[0U])
                            ? 0U : (0x1fU & ((vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[2U] 
                                              << 2U) 
                                             | (vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[1U] 
                                                >> 0x1eU)))) 
                          << 0xbU));
            } else if ((0x2000000U & vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[0U])) {
                __Vdly__CPU_top__DOT__cpu__DOT__execute__DOT__data[1U] 
                    = ((0x7ffU & __Vdly__CPU_top__DOT__cpu__DOT__execute__DOT__data[1U]) 
                       | (((IData)(4U) + ((vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[3U] 
                                           << 0xbU) 
                                          | (vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[2U] 
                                             >> 0x15U))) 
                          << 0xbU));
                __Vdly__CPU_top__DOT__cpu__DOT__execute__DOT__data[2U] 
                    = ((0xfffff800U & __Vdly__CPU_top__DOT__cpu__DOT__execute__DOT__data[2U]) 
                       | (((IData)(4U) + ((vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[3U] 
                                           << 0xbU) 
                                          | (vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[2U] 
                                             >> 0x15U))) 
                          >> 0x15U));
                vlSelfRef.CPU_top__DOT__cpu__DOT__execute_jump = 1U;
                vlSelfRef.CPU_top__DOT__cpu__DOT__execute_jump_pc 
                    = vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__alu_signed_sum_result;
                __Vdly__CPU_top__DOT__cpu__DOT__execute__DOT__last_strobe 
                    = (1U & (vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[3U] 
                             >> 0x15U));
                __Vdly__CPU_top__DOT__cpu__DOT__execute__DOT__data[3U] 
                    = ((0xffffU & __Vdly__CPU_top__DOT__cpu__DOT__execute__DOT__data[3U]) 
                       | (0x10000U & ((~ (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__data[3U] 
                                          >> 0x10U)) 
                                      << 0x10U)));
                __Vdly__CPU_top__DOT__cpu__DOT__execute__DOT__data[2U] 
                    = ((0xffff07ffU & __Vdly__CPU_top__DOT__cpu__DOT__execute__DOT__data[2U]) 
                       | (((0x200U & vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[0U])
                            ? 0U : (0x1fU & ((vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[2U] 
                                              << 2U) 
                                             | (vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[1U] 
                                                >> 0x1eU)))) 
                          << 0xbU));
            } else if ((0x1000000U & vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[0U])) {
                __Vdly__CPU_top__DOT__cpu__DOT__execute__DOT__data[3U] 
                    = ((0xffffU & __Vdly__CPU_top__DOT__cpu__DOT__execute__DOT__data[3U]) 
                       | (0x10000U & ((~ (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__data[3U] 
                                          >> 0x10U)) 
                                      << 0x10U)));
                if (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__alu_compare_result) {
                    vlSelfRef.CPU_top__DOT__cpu__DOT__execute_jump = 1U;
                    vlSelfRef.CPU_top__DOT__cpu__DOT__execute_jump_pc 
                        = (((vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[3U] 
                             << 0xbU) | (vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[2U] 
                                         >> 0x15U)) 
                           + ((vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[1U] 
                               << 2U) | (vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[0U] 
                                         >> 0x1eU)));
                } else {
                    vlSelfRef.CPU_top__DOT__cpu__DOT__execute_jump = 1U;
                    vlSelfRef.CPU_top__DOT__cpu__DOT__execute_jump_pc 
                        = ((IData)(4U) + ((vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[3U] 
                                           << 0xbU) 
                                          | (vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[2U] 
                                             >> 0x15U)));
                }
                __Vdly__CPU_top__DOT__cpu__DOT__execute__DOT__last_strobe 
                    = (1U & (vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[3U] 
                             >> 0x15U));
                __Vdly__CPU_top__DOT__cpu__DOT__execute__DOT__data[2U] 
                    = ((0xffff07ffU & __Vdly__CPU_top__DOT__cpu__DOT__execute__DOT__data[2U]) 
                       | (((0x200U & vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[0U])
                            ? 0U : (0x1fU & ((vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[2U] 
                                              << 2U) 
                                             | (vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[1U] 
                                                >> 0x1eU)))) 
                          << 0xbU));
            } else if ((0x200U & vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[0U])) {
                __Vdly__CPU_top__DOT__cpu__DOT__execute__DOT__data[3U] 
                    = ((0xffffU & __Vdly__CPU_top__DOT__cpu__DOT__execute__DOT__data[3U]) 
                       | (0x10000U & ((~ (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__data[3U] 
                                          >> 0x10U)) 
                                      << 0x10U)));
                __Vdly__CPU_top__DOT__cpu__DOT__execute__DOT__last_strobe 
                    = (1U & (vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[3U] 
                             >> 0x15U));
                __Vdly__CPU_top__DOT__cpu__DOT__execute__DOT__data[2U] 
                    = ((0xffff07ffU & __Vdly__CPU_top__DOT__cpu__DOT__execute__DOT__data[2U]) 
                       | (((0x200U & vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[0U])
                            ? 0U : (0x1fU & ((vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[2U] 
                                              << 2U) 
                                             | (vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[1U] 
                                                >> 0x1eU)))) 
                          << 0xbU));
            } else if ((0x100U & vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[0U])) {
                __Vdly__CPU_top__DOT__cpu__DOT__execute__DOT__data[1U] 
                    = ((0x7ffU & __Vdly__CPU_top__DOT__cpu__DOT__execute__DOT__data[1U]) 
                       | (vlSelfRef.CPU_top__DOT__cpu__DOT__forward__DOT__rs2 
                          << 0xbU));
                __Vdly__CPU_top__DOT__cpu__DOT__execute__DOT__data[2U] 
                    = ((0xfffff800U & __Vdly__CPU_top__DOT__cpu__DOT__execute__DOT__data[2U]) 
                       | (vlSelfRef.CPU_top__DOT__cpu__DOT__forward__DOT__rs2 
                          >> 0x15U));
                __Vdly__CPU_top__DOT__cpu__DOT__execute__DOT__last_strobe 
                    = (1U & (vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[3U] 
                             >> 0x15U));
                __Vdly__CPU_top__DOT__cpu__DOT__execute__DOT__data[3U] 
                    = ((0xffffU & __Vdly__CPU_top__DOT__cpu__DOT__execute__DOT__data[3U]) 
                       | (0x10000U & ((~ (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__data[3U] 
                                          >> 0x10U)) 
                                      << 0x10U)));
                __Vdly__CPU_top__DOT__cpu__DOT__execute__DOT__data[2U] 
                    = ((0xffff07ffU & __Vdly__CPU_top__DOT__cpu__DOT__execute__DOT__data[2U]) 
                       | (((0x200U & vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[0U])
                            ? 0U : (0x1fU & ((vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[2U] 
                                              << 2U) 
                                             | (vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[1U] 
                                                >> 0x1eU)))) 
                          << 0xbU));
            } else if ((0x4000000U & vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[0U])) {
                if ((0x10U & vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[0U])) {
                    __Vdly__CPU_top__DOT__cpu__DOT__execute__DOT__data[3U] 
                        = ((0xffffU & __Vdly__CPU_top__DOT__cpu__DOT__execute__DOT__data[3U]) 
                           | (0x10000U & ((~ (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__data[3U] 
                                              >> 0x10U)) 
                                          << 0x10U)));
                    __Vdly__CPU_top__DOT__cpu__DOT__execute__DOT__last_strobe 
                        = (1U & (vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[3U] 
                                 >> 0x15U));
                    __Vdly__CPU_top__DOT__cpu__DOT__execute__DOT__data[2U] 
                        = ((0xffff07ffU & __Vdly__CPU_top__DOT__cpu__DOT__execute__DOT__data[2U]) 
                           | (((0x200U & vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[0U])
                                ? 0U : (0x1fU & ((vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[2U] 
                                                  << 2U) 
                                                 | (vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[1U] 
                                                    >> 0x1eU)))) 
                              << 0xbU));
                } else if ((8U & vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[0U])) {
                    if ((4U & vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[0U])) {
                        if ((2U & vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[0U])) {
                            if ((1U & vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[0U])) {
                                __Vdly__CPU_top__DOT__cpu__DOT__execute__DOT__data[3U] 
                                    = ((0xffffU & __Vdly__CPU_top__DOT__cpu__DOT__execute__DOT__data[3U]) 
                                       | (0x10000U 
                                          & ((~ (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__data[3U] 
                                                 >> 0x10U)) 
                                             << 0x10U)));
                                __Vdly__CPU_top__DOT__cpu__DOT__execute__DOT__last_strobe 
                                    = (1U & (vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[3U] 
                                             >> 0x15U));
                                __Vdly__CPU_top__DOT__cpu__DOT__execute__DOT__data[2U] 
                                    = ((0xffff07ffU 
                                        & __Vdly__CPU_top__DOT__cpu__DOT__execute__DOT__data[2U]) 
                                       | (((0x200U 
                                            & vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[0U])
                                            ? 0U : 
                                           (0x1fU & 
                                            ((vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[2U] 
                                              << 2U) 
                                             | (vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[1U] 
                                                >> 0x1eU)))) 
                                          << 0xbU));
                            } else {
                                vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__div_request = 1U;
                                vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__div_signed = 0U;
                                if (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__div_ready) {
                                    __Vdly__CPU_top__DOT__cpu__DOT__execute__DOT__data[1U] 
                                        = ((0x7ffU 
                                            & __Vdly__CPU_top__DOT__cpu__DOT__execute__DOT__data[1U]) 
                                           | (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__div_remainder 
                                              << 0xbU));
                                    __Vdly__CPU_top__DOT__cpu__DOT__execute__DOT__data[2U] 
                                        = ((0xfffff800U 
                                            & __Vdly__CPU_top__DOT__cpu__DOT__execute__DOT__data[2U]) 
                                           | (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__div_remainder 
                                              >> 0x15U));
                                    __Vdly__CPU_top__DOT__cpu__DOT__execute__DOT__last_strobe 
                                        = (1U & (vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[3U] 
                                                 >> 0x15U));
                                    __Vdly__CPU_top__DOT__cpu__DOT__execute__DOT__data[3U] 
                                        = ((0xffffU 
                                            & __Vdly__CPU_top__DOT__cpu__DOT__execute__DOT__data[3U]) 
                                           | (0x10000U 
                                              & ((~ 
                                                  (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__data[3U] 
                                                   >> 0x10U)) 
                                                 << 0x10U)));
                                    __Vdly__CPU_top__DOT__cpu__DOT__execute__DOT__data[2U] 
                                        = ((0xffff07ffU 
                                            & __Vdly__CPU_top__DOT__cpu__DOT__execute__DOT__data[2U]) 
                                           | (((0x200U 
                                                & vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[0U])
                                                ? 0U
                                                : (0x1fU 
                                                   & ((vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[2U] 
                                                       << 2U) 
                                                      | (vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[1U] 
                                                         >> 0x1eU)))) 
                                              << 0xbU));
                                }
                            }
                        } else if ((1U & vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[0U])) {
                            vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__div_request = 1U;
                            vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__div_signed = 1U;
                            if (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__div_ready) {
                                __Vdly__CPU_top__DOT__cpu__DOT__execute__DOT__data[1U] 
                                    = ((0x7ffU & __Vdly__CPU_top__DOT__cpu__DOT__execute__DOT__data[1U]) 
                                       | (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__div_remainder 
                                          << 0xbU));
                                __Vdly__CPU_top__DOT__cpu__DOT__execute__DOT__data[2U] 
                                    = ((0xfffff800U 
                                        & __Vdly__CPU_top__DOT__cpu__DOT__execute__DOT__data[2U]) 
                                       | (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__div_remainder 
                                          >> 0x15U));
                                __Vdly__CPU_top__DOT__cpu__DOT__execute__DOT__last_strobe 
                                    = (1U & (vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[3U] 
                                             >> 0x15U));
                                __Vdly__CPU_top__DOT__cpu__DOT__execute__DOT__data[3U] 
                                    = ((0xffffU & __Vdly__CPU_top__DOT__cpu__DOT__execute__DOT__data[3U]) 
                                       | (0x10000U 
                                          & ((~ (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__data[3U] 
                                                 >> 0x10U)) 
                                             << 0x10U)));
                                __Vdly__CPU_top__DOT__cpu__DOT__execute__DOT__data[2U] 
                                    = ((0xffff07ffU 
                                        & __Vdly__CPU_top__DOT__cpu__DOT__execute__DOT__data[2U]) 
                                       | (((0x200U 
                                            & vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[0U])
                                            ? 0U : 
                                           (0x1fU & 
                                            ((vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[2U] 
                                              << 2U) 
                                             | (vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[1U] 
                                                >> 0x1eU)))) 
                                          << 0xbU));
                            }
                        } else {
                            __Vdly__CPU_top__DOT__cpu__DOT__execute__DOT__data[3U] 
                                = ((0xffffU & __Vdly__CPU_top__DOT__cpu__DOT__execute__DOT__data[3U]) 
                                   | (0x10000U & ((~ 
                                                   (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__data[3U] 
                                                    >> 0x10U)) 
                                                  << 0x10U)));
                            vlSelfRef.CPU_top__DOT__cpu__DOT__execute_jump = 1U;
                            vlSelfRef.CPU_top__DOT__cpu__DOT__execute_jump_pc 
                                = vlSelfRef.CPU_top__DOT__cpu__DOT__csr__DOT__mepc;
                            vlSelfRef.CPU_top__DOT__cpu__DOT__execute_mret = 1U;
                            __Vdly__CPU_top__DOT__cpu__DOT__execute__DOT__last_strobe 
                                = (1U & (vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[3U] 
                                         >> 0x15U));
                            __Vdly__CPU_top__DOT__cpu__DOT__execute__DOT__data[2U] 
                                = ((0xffff07ffU & __Vdly__CPU_top__DOT__cpu__DOT__execute__DOT__data[2U]) 
                                   | (((0x200U & vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[0U])
                                        ? 0U : (0x1fU 
                                                & ((vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[2U] 
                                                    << 2U) 
                                                   | (vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[1U] 
                                                      >> 0x1eU)))) 
                                      << 0xbU));
                        }
                    } else if ((2U & vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[0U])) {
                        if ((1U & vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[0U])) {
                            vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__mul_request = 1U;
                            __Vdly__CPU_top__DOT__cpu__DOT__execute__DOT__mul_signed = 0U;
                            if (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__multiply__DOT__r2_request) {
                                __Vdly__CPU_top__DOT__cpu__DOT__execute__DOT__data[1U] 
                                    = ((0x7ffU & __Vdly__CPU_top__DOT__cpu__DOT__execute__DOT__data[1U]) 
                                       | ((IData)((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__multiply__DOT__r2_result 
                                                   >> 0x20U)) 
                                          << 0xbU));
                                __Vdly__CPU_top__DOT__cpu__DOT__execute__DOT__data[2U] 
                                    = ((0xfffff800U 
                                        & __Vdly__CPU_top__DOT__cpu__DOT__execute__DOT__data[2U]) 
                                       | ((IData)((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__multiply__DOT__r2_result 
                                                   >> 0x20U)) 
                                          >> 0x15U));
                                __Vdly__CPU_top__DOT__cpu__DOT__execute__DOT__last_strobe 
                                    = (1U & (vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[3U] 
                                             >> 0x15U));
                                __Vdly__CPU_top__DOT__cpu__DOT__execute__DOT__data[3U] 
                                    = ((0xffffU & __Vdly__CPU_top__DOT__cpu__DOT__execute__DOT__data[3U]) 
                                       | (0x10000U 
                                          & ((~ (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__data[3U] 
                                                 >> 0x10U)) 
                                             << 0x10U)));
                                __Vdly__CPU_top__DOT__cpu__DOT__execute__DOT__data[2U] 
                                    = ((0xffff07ffU 
                                        & __Vdly__CPU_top__DOT__cpu__DOT__execute__DOT__data[2U]) 
                                       | (((0x200U 
                                            & vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[0U])
                                            ? 0U : 
                                           (0x1fU & 
                                            ((vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[2U] 
                                              << 2U) 
                                             | (vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[1U] 
                                                >> 0x1eU)))) 
                                          << 0xbU));
                            }
                        } else {
                            vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__mul_request = 1U;
                            __Vdly__CPU_top__DOT__cpu__DOT__execute__DOT__mul_signed = 1U;
                            if (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__multiply__DOT__r2_request) {
                                __Vdly__CPU_top__DOT__cpu__DOT__execute__DOT__data[1U] 
                                    = ((0x7ffU & __Vdly__CPU_top__DOT__cpu__DOT__execute__DOT__data[1U]) 
                                       | ((IData)((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__multiply__DOT__r2_result 
                                                   >> 0x20U)) 
                                          << 0xbU));
                                __Vdly__CPU_top__DOT__cpu__DOT__execute__DOT__data[2U] 
                                    = ((0xfffff800U 
                                        & __Vdly__CPU_top__DOT__cpu__DOT__execute__DOT__data[2U]) 
                                       | ((IData)((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__multiply__DOT__r2_result 
                                                   >> 0x20U)) 
                                          >> 0x15U));
                                __Vdly__CPU_top__DOT__cpu__DOT__execute__DOT__last_strobe 
                                    = (1U & (vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[3U] 
                                             >> 0x15U));
                                __Vdly__CPU_top__DOT__cpu__DOT__execute__DOT__data[3U] 
                                    = ((0xffffU & __Vdly__CPU_top__DOT__cpu__DOT__execute__DOT__data[3U]) 
                                       | (0x10000U 
                                          & ((~ (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__data[3U] 
                                                 >> 0x10U)) 
                                             << 0x10U)));
                                __Vdly__CPU_top__DOT__cpu__DOT__execute__DOT__data[2U] 
                                    = ((0xffff07ffU 
                                        & __Vdly__CPU_top__DOT__cpu__DOT__execute__DOT__data[2U]) 
                                       | (((0x200U 
                                            & vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[0U])
                                            ? 0U : 
                                           (0x1fU & 
                                            ((vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[2U] 
                                              << 2U) 
                                             | (vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[1U] 
                                                >> 0x1eU)))) 
                                          << 0xbU));
                            }
                        }
                    } else if ((1U & vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[0U])) {
                        vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__mul_request = 1U;
                        __Vdly__CPU_top__DOT__cpu__DOT__execute__DOT__mul_signed = 1U;
                        if (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__multiply__DOT__r2_request) {
                            __Vdly__CPU_top__DOT__cpu__DOT__execute__DOT__data[1U] 
                                = ((0x7ffU & __Vdly__CPU_top__DOT__cpu__DOT__execute__DOT__data[1U]) 
                                   | ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__multiply__DOT__r2_result) 
                                      << 0xbU));
                            __Vdly__CPU_top__DOT__cpu__DOT__execute__DOT__data[2U] 
                                = ((0xfffff800U & __Vdly__CPU_top__DOT__cpu__DOT__execute__DOT__data[2U]) 
                                   | ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__multiply__DOT__r2_result) 
                                      >> 0x15U));
                            __Vdly__CPU_top__DOT__cpu__DOT__execute__DOT__last_strobe 
                                = (1U & (vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[3U] 
                                         >> 0x15U));
                            __Vdly__CPU_top__DOT__cpu__DOT__execute__DOT__data[3U] 
                                = ((0xffffU & __Vdly__CPU_top__DOT__cpu__DOT__execute__DOT__data[3U]) 
                                   | (0x10000U & ((~ 
                                                   (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__data[3U] 
                                                    >> 0x10U)) 
                                                  << 0x10U)));
                            __Vdly__CPU_top__DOT__cpu__DOT__execute__DOT__data[2U] 
                                = ((0xffff07ffU & __Vdly__CPU_top__DOT__cpu__DOT__execute__DOT__data[2U]) 
                                   | (((0x200U & vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[0U])
                                        ? 0U : (0x1fU 
                                                & ((vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[2U] 
                                                    << 2U) 
                                                   | (vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[1U] 
                                                      >> 0x1eU)))) 
                                      << 0xbU));
                        }
                    } else {
                        __Vdly__CPU_top__DOT__cpu__DOT__execute__DOT__data[1U] 
                            = (0x100U | __Vdly__CPU_top__DOT__cpu__DOT__execute__DOT__data[1U]);
                        __Vdly__CPU_top__DOT__cpu__DOT__execute__DOT__last_strobe 
                            = (1U & (vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[3U] 
                                     >> 0x15U));
                        __Vdly__CPU_top__DOT__cpu__DOT__execute__DOT__data[3U] 
                            = ((0xffffU & __Vdly__CPU_top__DOT__cpu__DOT__execute__DOT__data[3U]) 
                               | (0x10000U & ((~ (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__data[3U] 
                                                  >> 0x10U)) 
                                              << 0x10U)));
                        __Vdly__CPU_top__DOT__cpu__DOT__execute__DOT__data[2U] 
                            = ((0xffff07ffU & __Vdly__CPU_top__DOT__cpu__DOT__execute__DOT__data[2U]) 
                               | (((0x200U & vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[0U])
                                    ? 0U : (0x1fU & 
                                            ((vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[2U] 
                                              << 2U) 
                                             | (vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[1U] 
                                                >> 0x1eU)))) 
                                  << 0xbU));
                    }
                } else if ((4U & vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[0U])) {
                    if ((2U & vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[0U])) {
                        if ((1U & vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[0U])) {
                            __Vdly__CPU_top__DOT__cpu__DOT__execute__DOT__data[3U] 
                                = ((0xffffU & __Vdly__CPU_top__DOT__cpu__DOT__execute__DOT__data[3U]) 
                                   | (0x10000U & ((~ 
                                                   (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__data[3U] 
                                                    >> 0x10U)) 
                                                  << 0x10U)));
                            vlSelfRef.CPU_top__DOT__cpu__DOT__execute_ecall = 1U;
                            __Vdly__CPU_top__DOT__cpu__DOT__execute__DOT__last_strobe 
                                = (1U & (vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[3U] 
                                         >> 0x15U));
                            __Vdly__CPU_top__DOT__cpu__DOT__execute__DOT__data[2U] 
                                = ((0xffff07ffU & __Vdly__CPU_top__DOT__cpu__DOT__execute__DOT__data[2U]) 
                                   | (((0x200U & vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[0U])
                                        ? 0U : (0x1fU 
                                                & ((vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[2U] 
                                                    << 2U) 
                                                   | (vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[1U] 
                                                      >> 0x1eU)))) 
                                      << 0xbU));
                        } else {
                            vlSelfRef.CPU_top__DOT__cpu__DOT__execute_fault = 1U;
                        }
                    } else if ((1U & vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[0U])) {
                        vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__div_request = 1U;
                        vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__div_signed = 0U;
                        if (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__div_ready) {
                            __Vdly__CPU_top__DOT__cpu__DOT__execute__DOT__data[1U] 
                                = ((0x7ffU & __Vdly__CPU_top__DOT__cpu__DOT__execute__DOT__data[1U]) 
                                   | (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__div_result 
                                      << 0xbU));
                            __Vdly__CPU_top__DOT__cpu__DOT__execute__DOT__data[2U] 
                                = ((0xfffff800U & __Vdly__CPU_top__DOT__cpu__DOT__execute__DOT__data[2U]) 
                                   | (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__div_result 
                                      >> 0x15U));
                            __Vdly__CPU_top__DOT__cpu__DOT__execute__DOT__last_strobe 
                                = (1U & (vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[3U] 
                                         >> 0x15U));
                            __Vdly__CPU_top__DOT__cpu__DOT__execute__DOT__data[3U] 
                                = ((0xffffU & __Vdly__CPU_top__DOT__cpu__DOT__execute__DOT__data[3U]) 
                                   | (0x10000U & ((~ 
                                                   (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__data[3U] 
                                                    >> 0x10U)) 
                                                  << 0x10U)));
                            __Vdly__CPU_top__DOT__cpu__DOT__execute__DOT__data[2U] 
                                = ((0xffff07ffU & __Vdly__CPU_top__DOT__cpu__DOT__execute__DOT__data[2U]) 
                                   | (((0x200U & vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[0U])
                                        ? 0U : (0x1fU 
                                                & ((vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[2U] 
                                                    << 2U) 
                                                   | (vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[1U] 
                                                      >> 0x1eU)))) 
                                      << 0xbU));
                        }
                    } else {
                        vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__div_request = 1U;
                        vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__div_signed = 1U;
                        if (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__div_ready) {
                            __Vdly__CPU_top__DOT__cpu__DOT__execute__DOT__data[1U] 
                                = ((0x7ffU & __Vdly__CPU_top__DOT__cpu__DOT__execute__DOT__data[1U]) 
                                   | (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__div_result 
                                      << 0xbU));
                            __Vdly__CPU_top__DOT__cpu__DOT__execute__DOT__data[2U] 
                                = ((0xfffff800U & __Vdly__CPU_top__DOT__cpu__DOT__execute__DOT__data[2U]) 
                                   | (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__div_result 
                                      >> 0x15U));
                            __Vdly__CPU_top__DOT__cpu__DOT__execute__DOT__last_strobe 
                                = (1U & (vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[3U] 
                                         >> 0x15U));
                            __Vdly__CPU_top__DOT__cpu__DOT__execute__DOT__data[3U] 
                                = ((0xffffU & __Vdly__CPU_top__DOT__cpu__DOT__execute__DOT__data[3U]) 
                                   | (0x10000U & ((~ 
                                                   (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__data[3U] 
                                                    >> 0x10U)) 
                                                  << 0x10U)));
                            __Vdly__CPU_top__DOT__cpu__DOT__execute__DOT__data[2U] 
                                = ((0xffff07ffU & __Vdly__CPU_top__DOT__cpu__DOT__execute__DOT__data[2U]) 
                                   | (((0x200U & vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[0U])
                                        ? 0U : (0x1fU 
                                                & ((vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[2U] 
                                                    << 2U) 
                                                   | (vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[1U] 
                                                      >> 0x1eU)))) 
                                      << 0xbU));
                        }
                    }
                } else if ((2U & vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[0U])) {
                    if ((1U & vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[0U])) {
                        __Vdly__CPU_top__DOT__cpu__DOT__execute__DOT__data[1U] 
                            = ((0x7ffU & __Vdly__CPU_top__DOT__cpu__DOT__execute__DOT__data[1U]) 
                               | (vlSelfRef.CPU_top__DOT__cpu__DOT__csr_rdata 
                                  << 0xbU));
                        __Vdly__CPU_top__DOT__cpu__DOT__execute__DOT__data[2U] 
                            = ((0xfffff800U & __Vdly__CPU_top__DOT__cpu__DOT__execute__DOT__data[2U]) 
                               | (vlSelfRef.CPU_top__DOT__cpu__DOT__csr_rdata 
                                  >> 0x15U));
                        vlSelfRef.CPU_top__DOT__cpu__DOT__csr_wdata 
                            = vlSelfRef.CPU_top__DOT__cpu__DOT__forward__DOT__rs1;
                        vlSelfRef.CPU_top__DOT__cpu__DOT__csr_wdata_wr = 1U;
                        __Vdly__CPU_top__DOT__cpu__DOT__execute__DOT__last_strobe 
                            = (1U & (vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[3U] 
                                     >> 0x15U));
                        __Vdly__CPU_top__DOT__cpu__DOT__execute__DOT__data[3U] 
                            = ((0xffffU & __Vdly__CPU_top__DOT__cpu__DOT__execute__DOT__data[3U]) 
                               | (0x10000U & ((~ (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__data[3U] 
                                                  >> 0x10U)) 
                                              << 0x10U)));
                        __Vdly__CPU_top__DOT__cpu__DOT__execute__DOT__data[2U] 
                            = ((0xffff07ffU & __Vdly__CPU_top__DOT__cpu__DOT__execute__DOT__data[2U]) 
                               | (((0x200U & vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[0U])
                                    ? 0U : (0x1fU & 
                                            ((vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[2U] 
                                              << 2U) 
                                             | (vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[1U] 
                                                >> 0x1eU)))) 
                                  << 0xbU));
                    } else {
                        __Vdly__CPU_top__DOT__cpu__DOT__execute__DOT__data[1U] 
                            = ((0x7ffU & __Vdly__CPU_top__DOT__cpu__DOT__execute__DOT__data[1U]) 
                               | (vlSelfRef.CPU_top__DOT__cpu__DOT__csr_rdata 
                                  << 0xbU));
                        __Vdly__CPU_top__DOT__cpu__DOT__execute__DOT__data[2U] 
                            = ((0xfffff800U & __Vdly__CPU_top__DOT__cpu__DOT__execute__DOT__data[2U]) 
                               | (vlSelfRef.CPU_top__DOT__cpu__DOT__csr_rdata 
                                  >> 0x15U));
                        vlSelfRef.CPU_top__DOT__cpu__DOT__csr_wdata 
                            = (vlSelfRef.CPU_top__DOT__cpu__DOT__csr_rdata 
                               | vlSelfRef.CPU_top__DOT__cpu__DOT__forward__DOT__rs1);
                        vlSelfRef.CPU_top__DOT__cpu__DOT__csr_wdata_wr = 1U;
                        __Vdly__CPU_top__DOT__cpu__DOT__execute__DOT__last_strobe 
                            = (1U & (vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[3U] 
                                     >> 0x15U));
                        __Vdly__CPU_top__DOT__cpu__DOT__execute__DOT__data[3U] 
                            = ((0xffffU & __Vdly__CPU_top__DOT__cpu__DOT__execute__DOT__data[3U]) 
                               | (0x10000U & ((~ (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__data[3U] 
                                                  >> 0x10U)) 
                                              << 0x10U)));
                        __Vdly__CPU_top__DOT__cpu__DOT__execute__DOT__data[2U] 
                            = ((0xffff07ffU & __Vdly__CPU_top__DOT__cpu__DOT__execute__DOT__data[2U]) 
                               | (((0x200U & vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[0U])
                                    ? 0U : (0x1fU & 
                                            ((vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[2U] 
                                              << 2U) 
                                             | (vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[1U] 
                                                >> 0x1eU)))) 
                                  << 0xbU));
                    }
                } else if ((1U & vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[0U])) {
                    __Vdly__CPU_top__DOT__cpu__DOT__execute__DOT__data[1U] 
                        = ((0x7ffU & __Vdly__CPU_top__DOT__cpu__DOT__execute__DOT__data[1U]) 
                           | (vlSelfRef.CPU_top__DOT__cpu__DOT__csr_rdata 
                              << 0xbU));
                    __Vdly__CPU_top__DOT__cpu__DOT__execute__DOT__data[2U] 
                        = ((0xfffff800U & __Vdly__CPU_top__DOT__cpu__DOT__execute__DOT__data[2U]) 
                           | (vlSelfRef.CPU_top__DOT__cpu__DOT__csr_rdata 
                              >> 0x15U));
                    vlSelfRef.CPU_top__DOT__cpu__DOT__csr_wdata 
                        = (vlSelfRef.CPU_top__DOT__cpu__DOT__csr_rdata 
                           & (~ vlSelfRef.CPU_top__DOT__cpu__DOT__forward__DOT__rs1));
                    vlSelfRef.CPU_top__DOT__cpu__DOT__csr_wdata_wr = 1U;
                    __Vdly__CPU_top__DOT__cpu__DOT__execute__DOT__last_strobe 
                        = (1U & (vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[3U] 
                                 >> 0x15U));
                    __Vdly__CPU_top__DOT__cpu__DOT__execute__DOT__data[3U] 
                        = ((0xffffU & __Vdly__CPU_top__DOT__cpu__DOT__execute__DOT__data[3U]) 
                           | (0x10000U & ((~ (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__data[3U] 
                                              >> 0x10U)) 
                                          << 0x10U)));
                    __Vdly__CPU_top__DOT__cpu__DOT__execute__DOT__data[2U] 
                        = ((0xffff07ffU & __Vdly__CPU_top__DOT__cpu__DOT__execute__DOT__data[2U]) 
                           | (((0x200U & vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[0U])
                                ? 0U : (0x1fU & ((vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[2U] 
                                                  << 2U) 
                                                 | (vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[1U] 
                                                    >> 0x1eU)))) 
                              << 0xbU));
                } else {
                    __Vdly__CPU_top__DOT__cpu__DOT__execute__DOT__data[3U] 
                        = ((0xffffU & __Vdly__CPU_top__DOT__cpu__DOT__execute__DOT__data[3U]) 
                           | (0x10000U & ((~ (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__data[3U] 
                                              >> 0x10U)) 
                                          << 0x10U)));
                    __Vdly__CPU_top__DOT__cpu__DOT__execute__DOT__last_strobe 
                        = (1U & (vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[3U] 
                                 >> 0x15U));
                    __Vdly__CPU_top__DOT__cpu__DOT__execute__DOT__data[2U] 
                        = ((0xffff07ffU & __Vdly__CPU_top__DOT__cpu__DOT__execute__DOT__data[2U]) 
                           | (((0x200U & vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[0U])
                                ? 0U : (0x1fU & ((vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[2U] 
                                                  << 2U) 
                                                 | (vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[1U] 
                                                    >> 0x1eU)))) 
                              << 0xbU));
                }
            } else {
                vlSelfRef.CPU_top__DOT__cpu__DOT__execute_fault = 1U;
            }
        }
        vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[2U] 
            = ((0x1fffffU & vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[2U]) 
               | (0xffe00000U & (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[1U] 
                                 << 1U)));
        vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[3U] 
            = ((0x200000U & vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[3U]) 
               | (0x1fffffU & ((0x1ffffeU & (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                             << 1U)) 
                               | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[1U] 
                                  >> 0x1fU))));
        vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[2U] 
            = ((0xffe3ffffU & vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[2U]) 
               | (0xfffc0000U & (((0U != (0x1fU & (
                                                   vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[1U] 
                                                   >> 5U))) 
                                  << 0x14U) | (((0U 
                                                 != 
                                                 (0x1fU 
                                                  & (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[1U] 
                                                     >> 0xaU))) 
                                                << 0x13U) 
                                               | ((0U 
                                                   != 
                                                   (0x1fU 
                                                    & (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[1U] 
                                                       >> 0xfU))) 
                                                  << 0x12U)))));
        vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[1U] 
            = ((0x3fffffffU & vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[1U]) 
               | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[1U] 
                  << 0x1eU));
        vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[2U] 
            = ((0xfffc0000U & vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[2U]) 
               | (0x3ffffU & (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[1U] 
                              >> 2U)));
        vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[0U] 
            = ((0x3fffffffU & vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[0U]) 
               | (((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__is_B)
                    ? (((- (IData)((1U & (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                          >> 0x13U)))) 
                        << 0xcU) | ((0x800U & (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                               >> 0x10U)) 
                                    | ((0x7e0U & (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                  >> 8U)) 
                                       | (0x1eU & (
                                                   vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                   >> 0x1bU)))))
                    : ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__is_I)
                        ? (((- (IData)((1U & (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                              >> 0x13U)))) 
                            << 0xbU) | (0x7ffU & (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                  >> 8U)))
                        : ((0x6fU == (0x7fU & (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                               >> 0x14U)))
                            ? (((- (IData)((1U & (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                  >> 0x13U)))) 
                                << 0x14U) | (((0xff000U 
                                               & (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                  << 0xcU)) 
                                              | (0x800U 
                                                 & (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                    << 3U))) 
                                             | (0x7feU 
                                                & (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                   >> 8U))))
                            : ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__is_S)
                                ? (((- (IData)((1U 
                                                & (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                   >> 0x13U)))) 
                                    << 0xbU) | ((0x7e0U 
                                                 & (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                    >> 8U)) 
                                                | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                   >> 0x1bU)))
                                : ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__is_U)
                                    ? (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                       << 0xcU) : ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__is_R)
                                                    ? 
                                                   (0x3fU 
                                                    & (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                       >> 8U))
                                                    : 
                                                   ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__is_CSR)
                                                     ? 
                                                    (0xfffU 
                                                     & (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                        >> 8U))
                                                     : 0U))))))) 
                  << 0x1eU));
        vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[1U] 
            = ((0xc0000000U & vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[1U]) 
               | (((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__is_B)
                    ? (((- (IData)((1U & (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                          >> 0x13U)))) 
                        << 0xcU) | ((0x800U & (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                               >> 0x10U)) 
                                    | ((0x7e0U & (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                  >> 8U)) 
                                       | (0x1eU & (
                                                   vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                   >> 0x1bU)))))
                    : ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__is_I)
                        ? (((- (IData)((1U & (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                              >> 0x13U)))) 
                            << 0xbU) | (0x7ffU & (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                  >> 8U)))
                        : ((0x6fU == (0x7fU & (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                               >> 0x14U)))
                            ? (((- (IData)((1U & (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                  >> 0x13U)))) 
                                << 0x14U) | (((0xff000U 
                                               & (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                  << 0xcU)) 
                                              | (0x800U 
                                                 & (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                    << 3U))) 
                                             | (0x7feU 
                                                & (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                   >> 8U))))
                            : ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__is_S)
                                ? (((- (IData)((1U 
                                                & (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                   >> 0x13U)))) 
                                    << 0xbU) | ((0x7e0U 
                                                 & (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                    >> 8U)) 
                                                | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                   >> 0x1bU)))
                                : ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__is_U)
                                    ? (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                       << 0xcU) : ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__is_R)
                                                    ? 
                                                   (0x3fU 
                                                    & (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                       >> 8U))
                                                    : 
                                                   ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__is_CSR)
                                                     ? 
                                                    (0xfffU 
                                                     & (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                        >> 8U))
                                                     : 0U))))))) 
                  >> 2U));
        vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[0U] 
            = ((0xc3ffffffU & vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[0U]) 
               | (0xfc000000U & (((((0x33U == (0xfe00707fU 
                                               & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                   << 0xcU) 
                                                  | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                     >> 0x14U)))) 
                                    | ((0x13U == (0x707fU 
                                                  & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                      << 0xcU) 
                                                     | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                        >> 0x14U)))) 
                                       | ((0x7033U 
                                           == (0xfe00707fU 
                                               & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                   << 0xcU) 
                                                  | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                     >> 0x14U)))) 
                                          | ((0x7013U 
                                              == (0x707fU 
                                                  & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                      << 0xcU) 
                                                     | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                        >> 0x14U)))) 
                                             | ((0x17U 
                                                 == 
                                                 (0x7fU 
                                                  & (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                     >> 0x14U))) 
                                                | ((0x37U 
                                                    == 
                                                    (0x7fU 
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
                                                                         >> 0x14U)))))))))))))) 
                                   << 0x1dU) | (((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT____VdfgRegularize_h2cfc3394_0_9) 
                                                 | ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT____VdfgRegularize_h2cfc3394_0_25) 
                                                    | (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT____VdfgRegularize_h2cfc3394_0_24))) 
                                                << 0x1cU)) 
                                 | ((((0x2033U == (0xfe00707fU 
                                                   & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                       << 0xcU) 
                                                      | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                         >> 0x14U)))) 
                                      | ((0x2013U == 
                                          (0x707fU 
                                           & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                               << 0xcU) 
                                              | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                 >> 0x14U)))) 
                                         | ((0x3013U 
                                             == (0x707fU 
                                                 & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                     << 0xcU) 
                                                    | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                       >> 0x14U)))) 
                                            | (0x3033U 
                                               == (0xfe00707fU 
                                                   & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                       << 0xcU) 
                                                      | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                         >> 0x14U))))))) 
                                     << 0x1bU) | (((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT____VdfgRegularize_h2cfc3394_0_26) 
                                                   | ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT____VdfgRegularize_h2cfc3394_0_23) 
                                                      | ((0x100073U 
                                                          == 
                                                          ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                            << 0xcU) 
                                                           | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                              >> 0x14U))) 
                                                         | ((0x73U 
                                                             == 
                                                             ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                               << 0xcU) 
                                                              | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                                 >> 0x14U))) 
                                                            | ((0xfU 
                                                                == 
                                                                (0x707fU 
                                                                 & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                                     << 0xcU) 
                                                                    | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                                       >> 0x14U)))) 
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
                                                                                >> 0x14U)))))))))))))) 
                                                  << 0x1aU)))));
        vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[0U] 
            = ((0xfc007fffU & vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[0U]) 
               | (0xffff8000U & ((((0x6fU == (0x7fU 
                                              & (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                 >> 0x14U))) 
                                   | (0x67U == (0x707fU 
                                                & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                    << 0xcU) 
                                                   | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                      >> 0x14U))))) 
                                  << 0x19U) | (((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__is_B) 
                                                << 0x18U) 
                                               | (((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__alu_operation) 
                                                   << 0x14U) 
                                                  | (((0x17U 
                                                       == 
                                                       (0x7fU 
                                                        & (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                           >> 0x14U)))
                                                       ? 8U
                                                       : 
                                                      ((0x6fU 
                                                        == 
                                                        (0x7fU 
                                                         & (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                            >> 0x14U)))
                                                        ? 8U
                                                        : 
                                                       ((0x37U 
                                                         == 
                                                         (0x7fU 
                                                          & (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                             >> 0x14U)))
                                                         ? 0x10U
                                                         : 2U))) 
                                                     << 0xfU))))));
        vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[0U] 
            = ((0xffff803fU & vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[0U]) 
               | (0xffffffc0U & (((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__alu_operand2) 
                                  << 0xaU) | ((((0x2007U 
                                                 == 
                                                 (0x707fU 
                                                  & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                      << 0xcU) 
                                                     | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                        >> 0x14U)))) 
                                                | ((3U 
                                                    == 
                                                    (0x707fU 
                                                     & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                         << 0xcU) 
                                                        | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                           >> 0x14U)))) 
                                                   | ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT____VdfgRegularize_h2cfc3394_0_20) 
                                                      | (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT____VdfgRegularize_h2cfc3394_0_19)))) 
                                               << 9U) 
                                              | (((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__is_S) 
                                                  << 8U) 
                                                 | ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__memory_width) 
                                                    << 6U))))));
        vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[0U] 
            = ((0xffffffdfU & vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[0U]) 
               | (((3U == (0x707fU & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                       << 0xcU) | (
                                                   vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                   >> 0x14U)))) 
                   | (0x1003U == (0x707fU & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                              << 0xcU) 
                                             | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                >> 0x14U))))) 
                  << 5U));
        vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[0U] 
            = ((0xffffffe0U & vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[0U]) 
               | ((0x3073U == (0x707fU & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                           << 0xcU) 
                                          | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                             >> 0x14U))))
                   ? 1U : ((0x2073U == (0x707fU & (
                                                   (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                    << 0xcU) 
                                                   | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                      >> 0x14U))))
                            ? 2U : ((0x1073U == (0x707fU 
                                                 & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                     << 0xcU) 
                                                    | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                       >> 0x14U))))
                                     ? 3U : ((0x2004033U 
                                              == (0xfe00707fU 
                                                  & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                      << 0xcU) 
                                                     | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                        >> 0x14U))))
                                              ? 4U : 
                                             ((0x2005033U 
                                               == (0xfe00707fU 
                                                   & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                       << 0xcU) 
                                                      | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                         >> 0x14U))))
                                               ? 5U
                                               : ((0x100073U 
                                                   == 
                                                   ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                     << 0xcU) 
                                                    | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                       >> 0x14U)))
                                                   ? 6U
                                                   : 
                                                  ((0x73U 
                                                    == 
                                                    ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                      << 0xcU) 
                                                     | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                        >> 0x14U)))
                                                    ? 7U
                                                    : 
                                                   ((0xfU 
                                                     == 
                                                     (0x707fU 
                                                      & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                          << 0xcU) 
                                                         | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                            >> 0x14U))))
                                                     ? 8U
                                                     : 
                                                    ((0x2000033U 
                                                      == 
                                                      (0xfe00707fU 
                                                       & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                           << 0xcU) 
                                                          | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                             >> 0x14U))))
                                                      ? 9U
                                                      : 
                                                     ((0x2001033U 
                                                       == 
                                                       (0xfe00707fU 
                                                        & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                            << 0xcU) 
                                                           | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                              >> 0x14U))))
                                                       ? 0xaU
                                                       : 
                                                      ((0x2003033U 
                                                        == 
                                                        (0xfe00707fU 
                                                         & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                             << 0xcU) 
                                                            | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                               >> 0x14U))))
                                                        ? 0xbU
                                                        : 
                                                       ((0x30200073U 
                                                         == 
                                                         ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                           << 0xcU) 
                                                          | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                             >> 0x14U)))
                                                         ? 0xcU
                                                         : 
                                                        ((0x2006033U 
                                                          == 
                                                          (0xfe00707fU 
                                                           & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                               << 0xcU) 
                                                              | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                                 >> 0x14U))))
                                                          ? 0xdU
                                                          : 
                                                         ((0x2007033U 
                                                           == 
                                                           (0xfe00707fU 
                                                            & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                                << 0xcU) 
                                                               | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                                  >> 0x14U))))
                                                           ? 0xeU
                                                           : 0U)))))))))))))));
        vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[3U] 
            = ((0x1fffffU & vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[3U]) 
               | (0x200000U & (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                               << 1U)));
    }
    if ((1U & (~ (IData)(vlSelfRef.reset)))) {
        vlSelfRef.CPU_top__DOT__cpu__DOT__writeback__DOT__last_strobe 
            = (1U & (vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__data[2U] 
                     >> 5U));
    }
    vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__genblk3__DOT__dcache__DOT__state 
        = __Vdly__CPU_top__DOT__cpu__DOT__memory__DOT__genblk3__DOT__dcache__DOT__state;
    vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__genblk3__DOT__dcache__DOT__flush_address 
        = __Vdly__CPU_top__DOT__cpu__DOT__memory__DOT__genblk3__DOT__dcache__DOT__flush_address;
    vlSelfRef.CPU_top__DOT__cpu_ibus_request = __Vdly__CPU_top__DOT__cpu_ibus_request;
    vlSelfRef.CPU_top__DOT__cpu__DOT__csr_irq_pc = __Vdly__CPU_top__DOT__cpu__DOT__csr_irq_pc;
    vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__state 
        = __Vdly__CPU_top__DOT__cpu__DOT__fetch__DOT__state;
    vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__irq_pending_r 
        = __Vdly__CPU_top__DOT__cpu__DOT__fetch__DOT__irq_pending_r;
    vlSelfRef.CPU_top__DOT__cpu__DOT__csr_irq_pending 
        = __Vdly__CPU_top__DOT__cpu__DOT__csr_irq_pending;
    vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__pc 
        = __Vdly__CPU_top__DOT__cpu__DOT__fetch__DOT__pc;
    vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__data[0U] 
        = __Vdly__CPU_top__DOT__cpu__DOT__fetch__DOT__data[0U];
    vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__data[1U] 
        = __Vdly__CPU_top__DOT__cpu__DOT__fetch__DOT__data[1U];
    vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__data[2U] 
        = __Vdly__CPU_top__DOT__cpu__DOT__fetch__DOT__data[2U];
    vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__data[3U] 
        = __Vdly__CPU_top__DOT__cpu__DOT__fetch__DOT__data[3U];
    if ((1U & (~ (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__genblk3__DOT__dcache__DOT__cache_rw)))) {
        vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__genblk3__DOT__dcache__DOT__cache_rdata 
            = vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__genblk3__DOT__dcache__DOT__cache__DOT__data
            [vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__genblk3__DOT__dcache__DOT__cache_address];
    }
    vlSelfRef.bus_wdata = 0U;
    vlSelfRef.CPU_top__DOT__cpu_dbus_ready = ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__wb_request) 
                                              & ((2U 
                                                  == (IData)(vlSelfRef.CPU_top__DOT__bus__DOT__state)) 
                                                 & (IData)(vlSelfRef.bus_ready)));
    if ((4U & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__state))) {
        if ((2U & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__state))) {
            __Vdly__CPU_top__DOT__cpu__DOT__memory__DOT__state = 0U;
        } else if ((1U & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__state))) {
            if (vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__dcache_ready) {
                vlSelfRef.__Vdly__CPU_top__DOT__cpu__DOT__memory__DOT__data[0U] 
                    = ((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__data[2U] 
                        << 0x15U) | (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__data[1U] 
                                     >> 0xbU));
                vlSelfRef.__Vdly__CPU_top__DOT__cpu__DOT__memory__DOT__data[1U] 
                    = ((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__data[3U] 
                        << 0x15U) | (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__data[2U] 
                                     >> 0xbU));
                vlSelfRef.__Vdly__CPU_top__DOT__cpu__DOT__memory__DOT__data[2U] 
                    = ((0x20U & vlSelfRef.__Vdly__CPU_top__DOT__cpu__DOT__memory__DOT__data[2U]) 
                       | (0x1fU & (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__data[3U] 
                                   >> 0xbU)));
                vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__dcache_request = 0U;
                vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__dcache_flush = 0U;
                vlSelfRef.__Vdly__CPU_top__DOT__cpu__DOT__memory__DOT__data[2U] 
                    = ((0x1fU & vlSelfRef.__Vdly__CPU_top__DOT__cpu__DOT__memory__DOT__data[2U]) 
                       | (0x20U & ((~ (vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__data[2U] 
                                       >> 5U)) << 5U)));
                __Vdly__CPU_top__DOT__cpu__DOT__memory__DOT__last_strobe 
                    = (1U & (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__data[3U] 
                             >> 0x10U));
                __Vdly__CPU_top__DOT__cpu__DOT__memory__DOT__state = 0U;
            }
        } else {
            vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__dcache_request = 1U;
            vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__dcache_wdata 
                = ((0U == (3U & (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__data[1U] 
                                 >> 6U))) ? ((0x40U 
                                              & vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__data[0U])
                                              ? ((0x20U 
                                                  & vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__data[0U])
                                                  ? 
                                                 ((0xff000000U 
                                                   & (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__data[1U] 
                                                      << 0xdU)) 
                                                  | (0xffffffU 
                                                     & vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__rmw_rdata))
                                                  : 
                                                 ((0xff000000U 
                                                   & vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__rmw_rdata) 
                                                  | ((0xff0000U 
                                                      & (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__data[1U] 
                                                         << 5U)) 
                                                     | (0xffffU 
                                                        & vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__rmw_rdata))))
                                              : ((0x20U 
                                                  & vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__data[0U])
                                                  ? 
                                                 ((0xffff0000U 
                                                   & vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__rmw_rdata) 
                                                  | ((0xff00U 
                                                      & (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__data[1U] 
                                                         >> 3U)) 
                                                     | (0xffU 
                                                        & vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__rmw_rdata)))
                                                  : 
                                                 ((0xffffff00U 
                                                   & vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__rmw_rdata) 
                                                  | (0xffU 
                                                     & (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__data[1U] 
                                                        >> 0xbU)))))
                    : ((0U == (3U & (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__data[0U] 
                                     >> 5U))) ? ((0xffff0000U 
                                                  & vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__rmw_rdata) 
                                                 | (0xffffU 
                                                    & (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__data[1U] 
                                                       >> 0xbU)))
                        : ((2U == (3U & (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__data[0U] 
                                         >> 5U))) ? 
                           ((0xffff0000U & (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__data[1U] 
                                            << 5U)) 
                            | (0xffffU & vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__rmw_rdata))
                            : 0U)));
            vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__dcache_rw = 1U;
            if (vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__dcache_ready) {
                vlSelfRef.__Vdly__CPU_top__DOT__cpu__DOT__memory__DOT__data[0U] 
                    = ((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__data[2U] 
                        << 0x15U) | (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__data[1U] 
                                     >> 0xbU));
                vlSelfRef.__Vdly__CPU_top__DOT__cpu__DOT__memory__DOT__data[1U] 
                    = ((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__data[3U] 
                        << 0x15U) | (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__data[2U] 
                                     >> 0xbU));
                vlSelfRef.__Vdly__CPU_top__DOT__cpu__DOT__memory__DOT__data[2U] 
                    = ((0x20U & vlSelfRef.__Vdly__CPU_top__DOT__cpu__DOT__memory__DOT__data[2U]) 
                       | (0x1fU & (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__data[3U] 
                                   >> 0xbU)));
                vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__dcache_request = 0U;
                vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__dcache_rw = 0U;
                vlSelfRef.__Vdly__CPU_top__DOT__cpu__DOT__memory__DOT__data[2U] 
                    = ((0x1fU & vlSelfRef.__Vdly__CPU_top__DOT__cpu__DOT__memory__DOT__data[2U]) 
                       | (0x20U & ((~ (vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__data[2U] 
                                       >> 5U)) << 5U)));
                __Vdly__CPU_top__DOT__cpu__DOT__memory__DOT__last_strobe 
                    = (1U & (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__data[3U] 
                             >> 0x10U));
                __Vdly__CPU_top__DOT__cpu__DOT__memory__DOT__state = 0U;
            }
        }
    } else if ((2U & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__state))) {
        if ((1U & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__state))) {
            if (vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__dcache_ready) {
                vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__dcache_request = 0U;
                vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__rmw_rdata 
                    = vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__dcache_rdata;
                __Vdly__CPU_top__DOT__cpu__DOT__memory__DOT__state = 4U;
            }
        } else if (vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__dcache_ready) {
            vlSelfRef.__Vdly__CPU_top__DOT__cpu__DOT__memory__DOT__data[0U] 
                = ((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__data[2U] 
                    << 0x15U) | (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__data[1U] 
                                 >> 0xbU));
            vlSelfRef.__Vdly__CPU_top__DOT__cpu__DOT__memory__DOT__data[1U] 
                = ((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__data[3U] 
                    << 0x15U) | (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__data[2U] 
                                 >> 0xbU));
            vlSelfRef.__Vdly__CPU_top__DOT__cpu__DOT__memory__DOT__data[2U] 
                = ((0x20U & vlSelfRef.__Vdly__CPU_top__DOT__cpu__DOT__memory__DOT__data[2U]) 
                   | (0x1fU & (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__data[3U] 
                               >> 0xbU)));
            vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__dcache_request = 0U;
            vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__dcache_rw = 0U;
            vlSelfRef.__Vdly__CPU_top__DOT__cpu__DOT__memory__DOT__data[2U] 
                = ((0x1fU & vlSelfRef.__Vdly__CPU_top__DOT__cpu__DOT__memory__DOT__data[2U]) 
                   | (0x20U & ((~ (vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__data[2U] 
                                   >> 5U)) << 5U)));
            __Vdly__CPU_top__DOT__cpu__DOT__memory__DOT__last_strobe 
                = (1U & (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__data[3U] 
                         >> 0x10U));
            __Vdly__CPU_top__DOT__cpu__DOT__memory__DOT__state = 0U;
        }
    } else if ((1U & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__state))) {
        if (vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__dcache_ready) {
            vlSelfRef.__Vdly__CPU_top__DOT__cpu__DOT__memory__DOT__data[1U] 
                = ((0x1fU & vlSelfRef.__Vdly__CPU_top__DOT__cpu__DOT__memory__DOT__data[1U]) 
                   | (0xffffffe0U & ((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__data[3U] 
                                      << 0x15U) | (0x1fffe0U 
                                                   & (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__data[2U] 
                                                      >> 0xbU)))));
            vlSelfRef.__Vdly__CPU_top__DOT__cpu__DOT__memory__DOT__data[2U] 
                = ((0x20U & vlSelfRef.__Vdly__CPU_top__DOT__cpu__DOT__memory__DOT__data[2U]) 
                   | (0x1fU & (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__data[3U] 
                               >> 0xbU)));
            vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__dcache_request = 0U;
            vlSelfRef.__Vdly__CPU_top__DOT__cpu__DOT__memory__DOT__data[0U] 
                = ((2U == (3U & (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__data[1U] 
                                 >> 6U))) ? vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__dcache_rdata
                    : ((1U == (3U & (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__data[1U] 
                                     >> 6U))) ? (((- (IData)(
                                                             (1U 
                                                              & ((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__data[1U] 
                                                                  >> 5U) 
                                                                 & (vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT____VdfgRegularize_h6f8eb4f6_1_0 
                                                                    >> 0xfU))))) 
                                                  << 0x10U) 
                                                 | (0xffffU 
                                                    & vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT____VdfgRegularize_h6f8eb4f6_1_0))
                        : ((0U == (3U & (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__data[1U] 
                                         >> 6U))) ? 
                           (((- (IData)((1U & ((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__data[1U] 
                                                >> 5U) 
                                               & (vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT____VdfgRegularize_h6f8eb4f6_1_0 
                                                  >> 7U))))) 
                             << 8U) | (0xffU & vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT____VdfgRegularize_h6f8eb4f6_1_0))
                            : 0U)));
            __Vdly__CPU_top__DOT__cpu__DOT__memory__DOT__last_strobe 
                = (1U & (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__data[3U] 
                         >> 0x10U));
            __Vdly__CPU_top__DOT__cpu__DOT__memory__DOT__state = 0U;
            vlSelfRef.__Vdly__CPU_top__DOT__cpu__DOT__memory__DOT__data[1U] 
                = ((0xffffffe0U & vlSelfRef.__Vdly__CPU_top__DOT__cpu__DOT__memory__DOT__data[1U]) 
                   | (0x1fU & vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__data[0U]));
            vlSelfRef.__Vdly__CPU_top__DOT__cpu__DOT__memory__DOT__data[2U] 
                = ((0x1fU & vlSelfRef.__Vdly__CPU_top__DOT__cpu__DOT__memory__DOT__data[2U]) 
                   | (0x20U & ((~ (vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__data[2U] 
                                   >> 5U)) << 5U)));
        }
    } else {
        vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__dcache_request = 0U;
        vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__dcache_rw = 0U;
        vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__dcache_wdata = 0U;
        vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__dcache_flush = 0U;
        if (((1U & (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__data[3U] 
                    >> 0x10U)) != (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__last_strobe))) {
            if ((0x400U & vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__data[1U])) {
                vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__dcache_request = 1U;
                __Vdly__CPU_top__DOT__cpu__DOT__memory__DOT__state = 1U;
            } else if ((0x200U & vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__data[1U])) {
                vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__dcache_request = 1U;
                if ((2U == (3U & (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__data[1U] 
                                  >> 6U)))) {
                    vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__dcache_rw = 1U;
                    vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__dcache_wdata 
                        = ((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__data[2U] 
                            << 0x15U) | (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__data[1U] 
                                         >> 0xbU));
                    __Vdly__CPU_top__DOT__cpu__DOT__memory__DOT__state = 2U;
                } else {
                    __Vdly__CPU_top__DOT__cpu__DOT__memory__DOT__state = 3U;
                }
            } else if ((0x100U & vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__data[1U])) {
                vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__dcache_request = 1U;
                vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__dcache_flush = 1U;
                __Vdly__CPU_top__DOT__cpu__DOT__memory__DOT__state = 5U;
            } else {
                vlSelfRef.__Vdly__CPU_top__DOT__cpu__DOT__memory__DOT__data[0U] 
                    = ((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__data[2U] 
                        << 0x15U) | (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__data[1U] 
                                     >> 0xbU));
                vlSelfRef.__Vdly__CPU_top__DOT__cpu__DOT__memory__DOT__data[1U] 
                    = ((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__data[3U] 
                        << 0x15U) | (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__data[2U] 
                                     >> 0xbU));
                vlSelfRef.__Vdly__CPU_top__DOT__cpu__DOT__memory__DOT__data[2U] 
                    = ((0x20U & ((~ (vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__data[2U] 
                                     >> 5U)) << 5U)) 
                       | (0x1fU & (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__data[3U] 
                                   >> 0xbU)));
                __Vdly__CPU_top__DOT__cpu__DOT__memory__DOT__last_strobe 
                    = (1U & (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__data[3U] 
                             >> 0x10U));
            }
        }
    }
    vlSelfRef.bus_request = 0U;
    if ((0U != (IData)(vlSelfRef.CPU_top__DOT__bus__DOT__state))) {
        if ((1U == (IData)(vlSelfRef.CPU_top__DOT__bus__DOT__state))) {
            vlSelfRef.bus_request = vlSelfRef.CPU_top__DOT__cpu_ibus_request;
        } else if ((2U == (IData)(vlSelfRef.CPU_top__DOT__bus__DOT__state))) {
            vlSelfRef.bus_request = vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__wb_request;
        }
    }
    vlSelfRef.CPU_top__DOT__cpu_ibus_ready = ((IData)(vlSelfRef.CPU_top__DOT__cpu_ibus_request) 
                                              & ((1U 
                                                  == (IData)(vlSelfRef.CPU_top__DOT__bus__DOT__state)) 
                                                 & (IData)(vlSelfRef.bus_ready)));
    vlSelfRef.CPU_top__DOT__bus__DOT__next_state = vlSelfRef.CPU_top__DOT__bus__DOT__state;
    vlSelfRef.bus_rw = 0U;
    vlSelfRef.bus_address = 0U;
    if ((0U == (IData)(vlSelfRef.CPU_top__DOT__bus__DOT__state))) {
        if (vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__wb_request) {
            vlSelfRef.bus_wdata = vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__wb_wdata;
            vlSelfRef.CPU_top__DOT__bus__DOT__next_state = 2U;
            vlSelfRef.bus_rw = vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__wb_rw;
            vlSelfRef.bus_address = vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__wb_address;
        } else if (vlSelfRef.CPU_top__DOT__cpu_ibus_request) {
            vlSelfRef.CPU_top__DOT__bus__DOT__next_state = 1U;
            vlSelfRef.bus_rw = 0U;
            vlSelfRef.bus_address = vlSelfRef.CPU_top__DOT__cpu_ibus_address;
        }
    } else {
        if ((1U != (IData)(vlSelfRef.CPU_top__DOT__bus__DOT__state))) {
            if ((2U == (IData)(vlSelfRef.CPU_top__DOT__bus__DOT__state))) {
                vlSelfRef.bus_wdata = vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__wb_wdata;
                vlSelfRef.bus_rw = vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__wb_rw;
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
            vlSelfRef.bus_address = vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__wb_address;
        } else {
            vlSelfRef.CPU_top__DOT__bus__DOT__next_state = 0U;
        }
    }
    vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata 
        = vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT__cache__DOT__data
        [vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT__cache_rd_set];
    vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__genblk3__DOT__dcache__DOT__cache_rw 
        = __Vdly__CPU_top__DOT__cpu__DOT__memory__DOT__genblk3__DOT__dcache__DOT__cache_rw;
    if (__VdlySet__CPU_top__DOT__cpu__DOT__memory__DOT__genblk3__DOT__dcache__DOT__cache__DOT__data__v0) {
        vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__genblk3__DOT__dcache__DOT__cache__DOT__data[__VdlyDim0__CPU_top__DOT__cpu__DOT__memory__DOT__genblk3__DOT__dcache__DOT__cache__DOT__data__v0] 
            = __VdlyVal__CPU_top__DOT__cpu__DOT__memory__DOT__genblk3__DOT__dcache__DOT__cache__DOT__data__v0;
    }
    vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__state 
        = __Vdly__CPU_top__DOT__cpu__DOT__memory__DOT__state;
    vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__dcache_ready 
        = __Vdly__CPU_top__DOT__cpu__DOT__memory__DOT__dcache_ready;
    vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__dcache_rdata 
        = __Vdly__CPU_top__DOT__cpu__DOT__memory__DOT__dcache_rdata;
    vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__last_strobe 
        = __Vdly__CPU_top__DOT__cpu__DOT__memory__DOT__last_strobe;
    if (__VdlySet__CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT__cache__DOT__data__v0) {
        vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT__cache__DOT__data[__VdlyDim0__CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT__cache__DOT__data__v0] 
            = __VdlyVal__CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT__cache__DOT__data__v0;
    }
    vlSelfRef.CPU_top__DOT__cpu__DOT__csr__DOT__mepc 
        = __Vdly__CPU_top__DOT__cpu__DOT__csr__DOT__mepc;
    vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__last_strobe 
        = __Vdly__CPU_top__DOT__cpu__DOT__execute__DOT__last_strobe;
    vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__data[0U] 
        = __Vdly__CPU_top__DOT__cpu__DOT__execute__DOT__data[0U];
    vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__data[1U] 
        = __Vdly__CPU_top__DOT__cpu__DOT__execute__DOT__data[1U];
    vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__data[2U] 
        = __Vdly__CPU_top__DOT__cpu__DOT__execute__DOT__data[2U];
    vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__data[3U] 
        = __Vdly__CPU_top__DOT__cpu__DOT__execute__DOT__data[3U];
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
    vlSelfRef.__VdfgRegularize_hd87f99a1_9_0 = ((0x23U 
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
    CPU_top__DOT__cpu__DOT__fetch__DOT____VdfgRegularize_hef2daed4_0_10 
        = ((0x20002053U == (0xfe00707fU & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata))) 
           | (0x8000053U == (0xfe00007fU & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata))));
    vlSelfRef.cpu_fault = ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__decode_fault) 
                           | (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute_fault));
    vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__multiply__DOT__r2_request 
        = vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__multiply__DOT__r1_request;
    vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT____VdfgRegularize_h6f8eb4f6_1_0 
        = VL_SHIFTR_III(32,32,32, vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__dcache_rdata, 
                        VL_SHIFTL_III(32,32,32, (3U 
                                                 & (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__data[0U] 
                                                    >> 5U)), 3U));
    vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__genblk3__DOT__dcache__DOT__cache_address 
        = (0xfffU & (((1U == (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__genblk3__DOT__dcache__DOT__state)) 
                      | ((2U == (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__genblk3__DOT__dcache__DOT__state)) 
                         | ((3U == (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__genblk3__DOT__dcache__DOT__state)) 
                            | (0xbU == (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__genblk3__DOT__dcache__DOT__state)))))
                      ? (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__genblk3__DOT__dcache__DOT__flush_address)
                      : ((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__data[0U] 
                          << 0x19U) | (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__data[0U] 
                                       >> 7U))));
    vlSelfRef.CPU_top__DOT__cpu__DOT__memory_busy = 
        (((1U & (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__data[3U] 
                 >> 0x10U)) != (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__last_strobe)) 
         & (IData)((0U != (0x700U & vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__data[1U]))));
    vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__multiply__DOT__r2_result 
        = (((1U & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__multiply__DOT__r1_s)) 
            != (1U & ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__multiply__DOT__r1_s) 
                      >> 1U))) ? (- vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__multiply__DOT__r1_intermediate)
            : vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__multiply__DOT__r1_intermediate);
    vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__is_S 
        = ((0x2027U == (0x707fU & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata))) 
           | (IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_9_0));
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
    vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__multiply__DOT__r1_request 
        = vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__multiply__DOT__r0_request;
    vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__multiply__DOT__r1_s 
        = vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__multiply__DOT__r0_s;
    vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__multiply__DOT__r1_intermediate 
        = ((QData)((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__multiply__DOT__r0_uop1)) 
           * (QData)((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__multiply__DOT__r0_uop2)));
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
    vlSelfRef.CPU_top__DOT__cpu__DOT____Vcellinp__fetch__i_busy 
        = ((((1U & (vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[3U] 
                    >> 0x15U)) != (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__last_strobe)) 
            & (vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[0U] 
               >> 0x1aU)) | (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__memory_busy));
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
    vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__multiply__DOT__r0_request 
        = (1U == (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__multiply__DOT__latch));
    vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__multiply__DOT__r0_s 
        = ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__mul_signed)
            ? ((2U & (vlSelfRef.CPU_top__DOT__cpu__DOT__forward__DOT__rs1 
                      >> 0x1eU)) | (vlSelfRef.CPU_top__DOT__cpu__DOT__forward__DOT__rs2 
                                    >> 0x1fU)) : 0U);
    vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__multiply__DOT__r0_uop2 
        = (((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__mul_signed) 
            & (vlSelfRef.CPU_top__DOT__cpu__DOT__forward__DOT__rs2 
               >> 0x1fU)) ? (- vlSelfRef.CPU_top__DOT__cpu__DOT__forward__DOT__rs2)
            : vlSelfRef.CPU_top__DOT__cpu__DOT__forward__DOT__rs2);
    vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__multiply__DOT__r0_uop1 
        = (((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__mul_signed) 
            & (vlSelfRef.CPU_top__DOT__cpu__DOT__forward__DOT__rs1 
               >> 0x1fU)) ? (- vlSelfRef.CPU_top__DOT__cpu__DOT__forward__DOT__rs1)
            : vlSelfRef.CPU_top__DOT__cpu__DOT__forward__DOT__rs1);
    vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__multiply__DOT__latch 
        = __Vdly__CPU_top__DOT__cpu__DOT__execute__DOT__multiply__DOT__latch;
    vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__mul_signed 
        = __Vdly__CPU_top__DOT__cpu__DOT__execute__DOT__mul_signed;
}

VL_INLINE_OPT void VCPU_top___024root___nba_sequent__TOP__1(VCPU_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCPU_top___024root___nba_sequent__TOP__1\n"); );
    VCPU_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VdlyVal__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__ready__v0;
    __VdlyVal__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__ready__v0 = 0;
    IData/*31:0*/ __VdlyVal__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend__v0;
    __VdlyVal__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend__v0 = 0;
    IData/*31:0*/ __VdlyVal__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor__v0;
    __VdlyVal__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor__v0 = 0;
    IData/*31:0*/ __VdlyVal__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__quotient__v0;
    __VdlyVal__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__quotient__v0 = 0;
    CData/*0:0*/ __VdlyVal__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__ready__v1;
    __VdlyVal__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__ready__v1 = 0;
    IData/*31:0*/ __VdlyVal__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend__v1;
    __VdlyVal__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend__v1 = 0;
    IData/*31:0*/ __VdlyVal__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor__v1;
    __VdlyVal__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor__v1 = 0;
    IData/*31:0*/ __VdlyVal__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__quotient__v1;
    __VdlyVal__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__quotient__v1 = 0;
    CData/*0:0*/ __VdlyVal__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__ready__v2;
    __VdlyVal__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__ready__v2 = 0;
    IData/*31:0*/ __VdlyVal__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend__v2;
    __VdlyVal__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend__v2 = 0;
    IData/*31:0*/ __VdlyVal__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor__v2;
    __VdlyVal__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor__v2 = 0;
    IData/*31:0*/ __VdlyVal__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__quotient__v2;
    __VdlyVal__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__quotient__v2 = 0;
    CData/*0:0*/ __VdlyVal__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__ready__v3;
    __VdlyVal__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__ready__v3 = 0;
    IData/*31:0*/ __VdlyVal__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend__v3;
    __VdlyVal__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend__v3 = 0;
    IData/*31:0*/ __VdlyVal__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor__v3;
    __VdlyVal__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor__v3 = 0;
    IData/*31:0*/ __VdlyVal__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__quotient__v3;
    __VdlyVal__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__quotient__v3 = 0;
    CData/*0:0*/ __VdlyVal__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__ready__v4;
    __VdlyVal__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__ready__v4 = 0;
    IData/*31:0*/ __VdlyVal__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend__v4;
    __VdlyVal__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend__v4 = 0;
    IData/*31:0*/ __VdlyVal__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor__v4;
    __VdlyVal__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor__v4 = 0;
    IData/*31:0*/ __VdlyVal__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__quotient__v4;
    __VdlyVal__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__quotient__v4 = 0;
    CData/*0:0*/ __VdlyVal__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__ready__v5;
    __VdlyVal__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__ready__v5 = 0;
    IData/*31:0*/ __VdlyVal__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend__v5;
    __VdlyVal__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend__v5 = 0;
    IData/*31:0*/ __VdlyVal__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor__v5;
    __VdlyVal__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor__v5 = 0;
    IData/*31:0*/ __VdlyVal__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__quotient__v5;
    __VdlyVal__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__quotient__v5 = 0;
    CData/*0:0*/ __VdlyVal__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__ready__v6;
    __VdlyVal__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__ready__v6 = 0;
    IData/*31:0*/ __VdlyVal__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend__v6;
    __VdlyVal__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend__v6 = 0;
    IData/*31:0*/ __VdlyVal__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor__v6;
    __VdlyVal__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor__v6 = 0;
    IData/*31:0*/ __VdlyVal__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__quotient__v6;
    __VdlyVal__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__quotient__v6 = 0;
    CData/*0:0*/ __VdlyVal__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__ready__v7;
    __VdlyVal__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__ready__v7 = 0;
    IData/*31:0*/ __VdlyVal__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend__v7;
    __VdlyVal__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend__v7 = 0;
    IData/*31:0*/ __VdlyVal__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor__v7;
    __VdlyVal__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor__v7 = 0;
    IData/*31:0*/ __VdlyVal__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__quotient__v7;
    __VdlyVal__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__quotient__v7 = 0;
    CData/*0:0*/ __VdlyVal__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__ready__v8;
    __VdlyVal__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__ready__v8 = 0;
    IData/*31:0*/ __VdlyVal__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend__v8;
    __VdlyVal__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend__v8 = 0;
    IData/*31:0*/ __VdlyVal__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor__v8;
    __VdlyVal__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor__v8 = 0;
    IData/*31:0*/ __VdlyVal__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__quotient__v8;
    __VdlyVal__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__quotient__v8 = 0;
    CData/*0:0*/ __VdlyVal__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__ready__v9;
    __VdlyVal__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__ready__v9 = 0;
    IData/*31:0*/ __VdlyVal__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend__v9;
    __VdlyVal__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend__v9 = 0;
    IData/*31:0*/ __VdlyVal__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor__v9;
    __VdlyVal__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor__v9 = 0;
    IData/*31:0*/ __VdlyVal__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__quotient__v9;
    __VdlyVal__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__quotient__v9 = 0;
    // Body
    if (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT____Vcellinp__df__rst) {
        __VdlyVal__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__quotient__v0 = 0U;
        __VdlyVal__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__quotient__v1 = 0U;
        __VdlyVal__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__quotient__v2 = 0U;
        __VdlyVal__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__quotient__v3 = 0U;
        __VdlyVal__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__quotient__v4 = 0U;
        __VdlyVal__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__quotient__v5 = 0U;
        __VdlyVal__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__quotient__v6 = 0U;
        __VdlyVal__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__quotient__v7 = 0U;
        __VdlyVal__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__quotient__v8 = 0U;
        __VdlyVal__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__quotient__v9 = 0U;
        __VdlyVal__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend__v0 = 0U;
        __VdlyVal__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend__v1 = 0U;
        __VdlyVal__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend__v2 = 0U;
        __VdlyVal__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend__v3 = 0U;
        __VdlyVal__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend__v4 = 0U;
        __VdlyVal__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend__v5 = 0U;
        __VdlyVal__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend__v6 = 0U;
        __VdlyVal__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend__v7 = 0U;
        __VdlyVal__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend__v8 = 0U;
        __VdlyVal__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend__v9 = 0U;
        __VdlyVal__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor__v0 = 0U;
        __VdlyVal__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor__v1 = 0U;
        __VdlyVal__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor__v2 = 0U;
        __VdlyVal__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor__v3 = 0U;
        __VdlyVal__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor__v4 = 0U;
        __VdlyVal__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor__v5 = 0U;
        __VdlyVal__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor__v6 = 0U;
        __VdlyVal__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor__v7 = 0U;
        __VdlyVal__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor__v8 = 0U;
        __VdlyVal__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor__v9 = 0U;
    } else {
        __VdlyVal__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__quotient__v0 
            = (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__quotient
               [0U] | VL_SHIFTL_III(32,32,32, (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__0__KET____DOT__q), 0x1fU));
        __VdlyVal__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__quotient__v1 
            = (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__quotient
               [2U] | VL_SHIFTL_III(32,32,32, (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__2__KET____DOT__q), 0x1dU));
        __VdlyVal__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__quotient__v2 
            = (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__quotient
               [6U] | VL_SHIFTL_III(32,32,32, (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__6__KET____DOT__q), 0x19U));
        __VdlyVal__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__quotient__v3 
            = (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__quotient
               [0xaU] | VL_SHIFTL_III(32,32,32, (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__10__KET____DOT__q), 0x15U));
        __VdlyVal__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__quotient__v4 
            = (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__quotient
               [0xeU] | VL_SHIFTL_III(32,32,32, (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__14__KET____DOT__q), 0x11U));
        __VdlyVal__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__quotient__v5 
            = (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__quotient
               [0x12U] | VL_SHIFTL_III(32,32,32, (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__18__KET____DOT__q), 0xdU));
        __VdlyVal__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__quotient__v6 
            = (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__quotient
               [0x16U] | VL_SHIFTL_III(32,32,32, (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__22__KET____DOT__q), 9U));
        __VdlyVal__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__quotient__v7 
            = (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__quotient
               [0x1aU] | VL_SHIFTL_III(32,32,32, (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__26__KET____DOT__q), 5U));
        __VdlyVal__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__quotient__v8 
            = (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__quotient
               [0x1dU] | VL_SHIFTL_III(32,32,32, (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__29__KET____DOT__q), 2U));
        __VdlyVal__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__quotient__v9 
            = (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__quotient
               [0x1fU] | (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__31__KET____DOT__q));
        __VdlyVal__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend__v0 
            = (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__0__KET____DOT__d);
        __VdlyVal__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend__v1 
            = (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__2__KET____DOT__d);
        __VdlyVal__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend__v2 
            = (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__6__KET____DOT__d);
        __VdlyVal__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend__v3 
            = (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__10__KET____DOT__d);
        __VdlyVal__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend__v4 
            = (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__14__KET____DOT__d);
        __VdlyVal__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend__v5 
            = (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__18__KET____DOT__d);
        __VdlyVal__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend__v6 
            = (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__22__KET____DOT__d);
        __VdlyVal__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend__v7 
            = (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__26__KET____DOT__d);
        __VdlyVal__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend__v8 
            = (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__29__KET____DOT__d);
        __VdlyVal__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend__v9 
            = vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__31__KET____DOT__t;
        __VdlyVal__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor__v0 
            = vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
            [0U];
        __VdlyVal__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor__v1 
            = vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
            [2U];
        __VdlyVal__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor__v2 
            = vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
            [6U];
        __VdlyVal__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor__v3 
            = vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
            [0xaU];
        __VdlyVal__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor__v4 
            = vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
            [0xeU];
        __VdlyVal__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor__v5 
            = vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
            [0x12U];
        __VdlyVal__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor__v6 
            = vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
            [0x16U];
        __VdlyVal__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor__v7 
            = vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
            [0x1aU];
        __VdlyVal__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor__v8 
            = vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
            [0x1dU];
        __VdlyVal__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor__v9 
            = vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
            [0x1fU];
    }
    __VdlyVal__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__ready__v0 
        = ((~ (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT____Vcellinp__df__rst)) 
           & vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__ready
           [0U]);
    __VdlyVal__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__ready__v1 
        = ((~ (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT____Vcellinp__df__rst)) 
           & vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__ready
           [2U]);
    __VdlyVal__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__ready__v2 
        = ((~ (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT____Vcellinp__df__rst)) 
           & vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__ready
           [6U]);
    __VdlyVal__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__ready__v3 
        = ((~ (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT____Vcellinp__df__rst)) 
           & vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__ready
           [0xaU]);
    __VdlyVal__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__ready__v4 
        = ((~ (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT____Vcellinp__df__rst)) 
           & vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__ready
           [0xeU]);
    __VdlyVal__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__ready__v5 
        = ((~ (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT____Vcellinp__df__rst)) 
           & vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__ready
           [0x12U]);
    __VdlyVal__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__ready__v6 
        = ((~ (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT____Vcellinp__df__rst)) 
           & vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__ready
           [0x16U]);
    __VdlyVal__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__ready__v7 
        = ((~ (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT____Vcellinp__df__rst)) 
           & vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__ready
           [0x1aU]);
    __VdlyVal__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__ready__v8 
        = ((~ (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT____Vcellinp__df__rst)) 
           & vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__ready
           [0x1dU]);
    __VdlyVal__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__ready__v9 
        = ((~ (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT____Vcellinp__df__rst)) 
           & vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__ready
           [0x1fU]);
    vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__quotient[1U] 
        = __VdlyVal__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__quotient__v0;
    vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__quotient[3U] 
        = __VdlyVal__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__quotient__v1;
    vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__quotient[7U] 
        = __VdlyVal__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__quotient__v2;
    vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__quotient[0xbU] 
        = __VdlyVal__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__quotient__v3;
    vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__quotient[0xfU] 
        = __VdlyVal__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__quotient__v4;
    vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__quotient[0x13U] 
        = __VdlyVal__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__quotient__v5;
    vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__quotient[0x17U] 
        = __VdlyVal__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__quotient__v6;
    vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__quotient[0x1bU] 
        = __VdlyVal__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__quotient__v7;
    vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__quotient[0x1eU] 
        = __VdlyVal__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__quotient__v8;
    vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__quotient[0x20U] 
        = __VdlyVal__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__quotient__v9;
    vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__ready[1U] 
        = __VdlyVal__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__ready__v0;
    vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__ready[3U] 
        = __VdlyVal__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__ready__v1;
    vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__ready[7U] 
        = __VdlyVal__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__ready__v2;
    vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__ready[0xbU] 
        = __VdlyVal__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__ready__v3;
    vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__ready[0xfU] 
        = __VdlyVal__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__ready__v4;
    vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__ready[0x13U] 
        = __VdlyVal__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__ready__v5;
    vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__ready[0x17U] 
        = __VdlyVal__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__ready__v6;
    vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__ready[0x1bU] 
        = __VdlyVal__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__ready__v7;
    vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__ready[0x1eU] 
        = __VdlyVal__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__ready__v8;
    vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__ready[0x20U] 
        = __VdlyVal__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__ready__v9;
    vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend[1U] 
        = __VdlyVal__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend__v0;
    vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend[3U] 
        = __VdlyVal__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend__v1;
    vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend[7U] 
        = __VdlyVal__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend__v2;
    vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend[0xbU] 
        = __VdlyVal__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend__v3;
    vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend[0xfU] 
        = __VdlyVal__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend__v4;
    vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend[0x13U] 
        = __VdlyVal__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend__v5;
    vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend[0x17U] 
        = __VdlyVal__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend__v6;
    vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend[0x1bU] 
        = __VdlyVal__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend__v7;
    vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend[0x1eU] 
        = __VdlyVal__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend__v8;
    vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend[0x20U] 
        = __VdlyVal__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend__v9;
    vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor[1U] 
        = __VdlyVal__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor__v0;
    vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor[3U] 
        = __VdlyVal__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor__v1;
    vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor[7U] 
        = __VdlyVal__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor__v2;
    vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor[0xbU] 
        = __VdlyVal__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor__v3;
    vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor[0xfU] 
        = __VdlyVal__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor__v4;
    vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor[0x13U] 
        = __VdlyVal__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor__v5;
    vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor[0x17U] 
        = __VdlyVal__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor__v6;
    vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor[0x1bU] 
        = __VdlyVal__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor__v7;
    vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor[0x1eU] 
        = __VdlyVal__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor__v8;
    vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor[0x20U] 
        = __VdlyVal__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor__v9;
}

VL_INLINE_OPT void VCPU_top___024root___nba_sequent__TOP__2(VCPU_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCPU_top___024root___nba_sequent__TOP__2\n"); );
    VCPU_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __Vdly__CPU_top__DOT__cpu__DOT__registers__DOT__last_write_strobe;
    __Vdly__CPU_top__DOT__cpu__DOT__registers__DOT__last_write_strobe = 0;
    IData/*31:0*/ __VdlyVal__CPU_top__DOT__cpu__DOT__registers__DOT__r__v0;
    __VdlyVal__CPU_top__DOT__cpu__DOT__registers__DOT__r__v0 = 0;
    CData/*4:0*/ __VdlyDim0__CPU_top__DOT__cpu__DOT__registers__DOT__r__v0;
    __VdlyDim0__CPU_top__DOT__cpu__DOT__registers__DOT__r__v0 = 0;
    CData/*0:0*/ __VdlySet__CPU_top__DOT__cpu__DOT__registers__DOT__r__v0;
    __VdlySet__CPU_top__DOT__cpu__DOT__registers__DOT__r__v0 = 0;
    // Body
    __Vdly__CPU_top__DOT__cpu__DOT__registers__DOT__last_write_strobe 
        = vlSelfRef.CPU_top__DOT__cpu__DOT__registers__DOT__last_write_strobe;
    __VdlySet__CPU_top__DOT__cpu__DOT__registers__DOT__r__v0 = 0U;
    if (vlSelfRef.reset) {
        vlSelfRef.CPU_top__DOT__cpu__DOT__registers__DOT__I = 0x20U;
        __Vdly__CPU_top__DOT__cpu__DOT__registers__DOT__last_write_strobe = 0U;
        vlSelfRef.CPU_top__DOT__cpu__DOT__registers__DOT__r[0U] = 0U;
        vlSelfRef.CPU_top__DOT__cpu__DOT__registers__DOT__rs1 = 0U;
        vlSelfRef.CPU_top__DOT__cpu__DOT__registers__DOT__rs2 = 0U;
        vlSelfRef.CPU_top__DOT__cpu__DOT__registers__DOT__rs3 = 0U;
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
        vlSelfRef.CPU_top__DOT__cpu__DOT__registers__DOT__r[2U] = 0x10000400U;
    } else {
        if (((1U & (vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__data[2U] 
                    >> 5U)) != (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__registers__DOT__last_write_strobe))) {
            if ((0U != (0x1fU & vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__data[1U]))) {
                __VdlyVal__CPU_top__DOT__cpu__DOT__registers__DOT__r__v0 
                    = vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__data[0U];
                __VdlyDim0__CPU_top__DOT__cpu__DOT__registers__DOT__r__v0 
                    = (0x1fU & vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__data[1U]);
                __VdlySet__CPU_top__DOT__cpu__DOT__registers__DOT__r__v0 = 1U;
            }
            __Vdly__CPU_top__DOT__cpu__DOT__registers__DOT__last_write_strobe 
                = (1U & (vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__data[2U] 
                         >> 5U));
        }
        vlSelfRef.CPU_top__DOT__cpu__DOT__registers__DOT__rs1 
            = ((0U != (0x1fU & (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[1U] 
                                >> 0xfU))) ? vlSelfRef.CPU_top__DOT__cpu__DOT__registers__DOT__r
               [(0x1fU & (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[1U] 
                          >> 0xfU))] : 0U);
        vlSelfRef.CPU_top__DOT__cpu__DOT__registers__DOT__rs2 
            = ((0U != (0x1fU & (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[1U] 
                                >> 0xaU))) ? vlSelfRef.CPU_top__DOT__cpu__DOT__registers__DOT__r
               [(0x1fU & (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[1U] 
                          >> 0xaU))] : 0U);
        vlSelfRef.CPU_top__DOT__cpu__DOT__registers__DOT__rs3 
            = ((0U != (0x1fU & (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[1U] 
                                >> 5U))) ? vlSelfRef.CPU_top__DOT__cpu__DOT__registers__DOT__r
               [(0x1fU & (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[1U] 
                          >> 5U))] : 0U);
    }
    vlSelfRef.CPU_top__DOT__cpu__DOT__registers__DOT__last_write_strobe 
        = __Vdly__CPU_top__DOT__cpu__DOT__registers__DOT__last_write_strobe;
    if (__VdlySet__CPU_top__DOT__cpu__DOT__registers__DOT__r__v0) {
        vlSelfRef.CPU_top__DOT__cpu__DOT__registers__DOT__r[__VdlyDim0__CPU_top__DOT__cpu__DOT__registers__DOT__r__v0] 
            = __VdlyVal__CPU_top__DOT__cpu__DOT__registers__DOT__r__v0;
    }
}

VL_INLINE_OPT void VCPU_top___024root___nba_sequent__TOP__3(VCPU_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCPU_top___024root___nba_sequent__TOP__3\n"); );
    VCPU_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
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
    vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__ready[0U] 
        = vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__div_request;
    vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT____Vcellinp__df__rst 
        = (1U & (~ (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__div_request)));
    vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__data[0U] 
        = vlSelfRef.__Vdly__CPU_top__DOT__cpu__DOT__memory__DOT__data[0U];
    vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__data[1U] 
        = vlSelfRef.__Vdly__CPU_top__DOT__cpu__DOT__memory__DOT__data[1U];
    vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__data[2U] 
        = vlSelfRef.__Vdly__CPU_top__DOT__cpu__DOT__memory__DOT__data[2U];
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
    vlSelfRef.__VdfgRegularize_hd87f99a1_4_0 = ((0x23U 
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
           | (IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_4_0));
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

VL_INLINE_OPT void VCPU_top___024root___nba_comb__TOP__0(VCPU_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCPU_top___024root___nba_comb__TOP__0\n"); );
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

VL_INLINE_OPT void VCPU_top___024root___nba_comb__TOP__1(VCPU_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCPU_top___024root___nba_comb__TOP__1\n"); );
    VCPU_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
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
    vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor[0U] 
        = (((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__div_signed) 
            & (vlSelfRef.CPU_top__DOT__cpu__DOT__forward__DOT__rs2 
               >> 0x1fU)) ? (- vlSelfRef.CPU_top__DOT__cpu__DOT__forward__DOT__rs2)
            : vlSelfRef.CPU_top__DOT__cpu__DOT__forward__DOT__rs2);
    vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__s 
        = ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__div_signed)
            ? ((2U & (vlSelfRef.CPU_top__DOT__cpu__DOT__forward__DOT__rs1 
                      >> 0x1eU)) | (vlSelfRef.CPU_top__DOT__cpu__DOT__forward__DOT__rs2 
                                    >> 0x1fU)) : 0U);
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
    vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend[0U] 
        = (((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__div_signed) 
            & (vlSelfRef.CPU_top__DOT__cpu__DOT__forward__DOT__rs1 
               >> 0x1fU)) ? (- vlSelfRef.CPU_top__DOT__cpu__DOT__forward__DOT__rs1)
            : vlSelfRef.CPU_top__DOT__cpu__DOT__forward__DOT__rs1);
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
}

VL_INLINE_OPT void VCPU_top___024root___nba_comb__TOP__2(VCPU_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCPU_top___024root___nba_comb__TOP__2\n"); );
    VCPU_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__div_result 
        = (((1U & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__s)) 
            != (1U & ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__s) 
                      >> 1U))) ? (- vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__quotient
                                  [0x20U]) : vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__quotient
           [0x20U]);
    vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__div_remainder 
        = ((2U & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__s))
            ? (- vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
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

void VCPU_top___024root___eval_triggers__act(VCPU_top___024root* vlSelf);

bool VCPU_top___024root___eval_phase__act(VCPU_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCPU_top___024root___eval_phase__act\n"); );
    VCPU_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlTriggerVec<7> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    VCPU_top___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelfRef.__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelfRef.__VactTriggered, vlSelfRef.__VnbaTriggered);
        vlSelfRef.__VnbaTriggered.thisOr(vlSelfRef.__VactTriggered);
        VCPU_top___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool VCPU_top___024root___eval_phase__nba(VCPU_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCPU_top___024root___eval_phase__nba\n"); );
    VCPU_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelfRef.__VnbaTriggered.any();
    if (__VnbaExecute) {
        VCPU_top___024root___eval_nba(vlSelf);
        vlSelfRef.__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VCPU_top___024root___dump_triggers__ico(VCPU_top___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void VCPU_top___024root___dump_triggers__nba(VCPU_top___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void VCPU_top___024root___dump_triggers__act(VCPU_top___024root* vlSelf);
#endif  // VL_DEBUG

void VCPU_top___024root___eval(VCPU_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCPU_top___024root___eval\n"); );
    VCPU_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __VicoIterCount;
    CData/*0:0*/ __VicoContinue;
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VicoIterCount = 0U;
    vlSelfRef.__VicoFirstIteration = 1U;
    __VicoContinue = 1U;
    while (__VicoContinue) {
        if (VL_UNLIKELY(((0x64U < __VicoIterCount)))) {
#ifdef VL_DEBUG
            VCPU_top___024root___dump_triggers__ico(vlSelf);
#endif
            VL_FATAL_MT("rtl/cpu/CPU_top.sv", 14, "", "Input combinational region did not converge.");
        }
        __VicoIterCount = ((IData)(1U) + __VicoIterCount);
        __VicoContinue = 0U;
        if (VCPU_top___024root___eval_phase__ico(vlSelf)) {
            __VicoContinue = 1U;
        }
        vlSelfRef.__VicoFirstIteration = 0U;
    }
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY(((0x64U < __VnbaIterCount)))) {
#ifdef VL_DEBUG
            VCPU_top___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("rtl/cpu/CPU_top.sv", 14, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelfRef.__VactIterCount = 0U;
        vlSelfRef.__VactContinue = 1U;
        while (vlSelfRef.__VactContinue) {
            if (VL_UNLIKELY(((0x64U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                VCPU_top___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("rtl/cpu/CPU_top.sv", 14, "", "Active region did not converge.");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
            vlSelfRef.__VactContinue = 0U;
            if (VCPU_top___024root___eval_phase__act(vlSelf)) {
                vlSelfRef.__VactContinue = 1U;
            }
        }
        if (VCPU_top___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void VCPU_top___024root___eval_debug_assertions(VCPU_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCPU_top___024root___eval_debug_assertions\n"); );
    VCPU_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (VL_UNLIKELY(((vlSelfRef.reset & 0xfeU)))) {
        Verilated::overWidthError("reset");}
    if (VL_UNLIKELY(((vlSelfRef.clock & 0xfeU)))) {
        Verilated::overWidthError("clock");}
    if (VL_UNLIKELY(((vlSelfRef.timer_interrupt & 0xfeU)))) {
        Verilated::overWidthError("timer_interrupt");}
    if (VL_UNLIKELY(((vlSelfRef.external_interrupt 
                      & 0xfeU)))) {
        Verilated::overWidthError("external_interrupt");}
    if (VL_UNLIKELY(((vlSelfRef.bus_ready & 0xfeU)))) {
        Verilated::overWidthError("bus_ready");}
}
#endif  // VL_DEBUG
