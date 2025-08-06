// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_fst_c.h"
#include "VCPU_top__Syms.h"


void VCPU_top___024root__trace_chg_0_sub_0(VCPU_top___024root* vlSelf, VerilatedFst::Buffer* bufp);

void VCPU_top___024root__trace_chg_0(void* voidSelf, VerilatedFst::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCPU_top___024root__trace_chg_0\n"); );
    // Init
    VCPU_top___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VCPU_top___024root*>(voidSelf);
    VCPU_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    VCPU_top___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void VCPU_top___024root__trace_chg_0_sub_0(VCPU_top___024root* vlSelf, VerilatedFst::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCPU_top___024root__trace_chg_0_sub_0\n"); );
    VCPU_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[0U]))) {
        bufp->chgIData(oldp+0,(vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__genblk1__DOT__dcache__DOT__wb__DOT__unnamedblk1__DOT__i),32);
    }
    if (VL_UNLIKELY(((vlSelfRef.__Vm_traceActivity[1U] 
                      | vlSelfRef.__Vm_traceActivity
                      [5U])))) {
        bufp->chgBit(oldp+1,(vlSelfRef.CPU_top__DOT__cpu_dbus_ready));
        bufp->chgCData(oldp+2,(vlSelfRef.CPU_top__DOT__bus__DOT__next_state),2);
        bufp->chgBit(oldp+3,(vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__genblk1__DOT__dcache__DOT__wb_ready));
        bufp->chgBit(oldp+4,(vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__genblk1__DOT__dcache__DOT__wb__DOT__next_wb_dirty[0]));
        bufp->chgBit(oldp+5,(vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__genblk1__DOT__dcache__DOT__wb__DOT__next_wb_dirty[1]));
        bufp->chgBit(oldp+6,(vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__genblk1__DOT__dcache__DOT__wb__DOT__next_wb_dirty[2]));
        bufp->chgBit(oldp+7,(vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__genblk1__DOT__dcache__DOT__wb__DOT__next_wb_dirty[3]));
    }
    if (VL_UNLIKELY(((((((vlSelfRef.__Vm_traceActivity
                          [2U] | vlSelfRef.__Vm_traceActivity
                          [3U]) | vlSelfRef.__Vm_traceActivity
                         [4U]) | vlSelfRef.__Vm_traceActivity
                        [6U]) | vlSelfRef.__Vm_traceActivity
                       [9U]) | vlSelfRef.__Vm_traceActivity
                      [0xaU])))) {
        bufp->chgBit(oldp+8,((1U & ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__0__KET____DOT__q)
                                     ? ((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                         [0U] >> 0x1fU) 
                                        - vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                        [0U]) : (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                                 [0U] 
                                                 >> 0x1fU)))));
        bufp->chgQData(oldp+9,((0x1ffffffffULL & VL_SHIFTR_QQI(33,33,32, 
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
        bufp->chgSData(oldp+11,((0x7ffU & ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__10__KET____DOT__q)
                                            ? ((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                                [0xaU] 
                                                >> 0x15U) 
                                               - vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                               [0xaU])
                                            : (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                               [0xaU] 
                                               >> 0x15U)))),11);
        bufp->chgQData(oldp+12,((0x7ffffffffffULL & 
                                 VL_SHIFTR_QQI(43,43,32, 
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
        bufp->chgSData(oldp+14,((0x7fffU & ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__14__KET____DOT__q)
                                             ? ((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                                 [0xeU] 
                                                 >> 0x11U) 
                                                - vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                                [0xeU])
                                             : (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                                [0xeU] 
                                                >> 0x11U)))),15);
        bufp->chgQData(oldp+15,((0x7fffffffffffULL 
                                 & VL_SHIFTR_QQI(47,47,32, 
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
        bufp->chgIData(oldp+17,((0x7ffffU & ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__18__KET____DOT__q)
                                              ? ((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                                  [0x12U] 
                                                  >> 0xdU) 
                                                 - 
                                                 vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                                 [0x12U])
                                              : (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                                 [0x12U] 
                                                 >> 0xdU)))),19);
        bufp->chgQData(oldp+18,((0x7ffffffffffffULL 
                                 & VL_SHIFTR_QQI(51,51,32, 
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
        bufp->chgIData(oldp+20,((0x7fffffU & ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__22__KET____DOT__q)
                                               ? ((
                                                   vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                                   [0x16U] 
                                                   >> 9U) 
                                                  - 
                                                  vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                                  [0x16U])
                                               : (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                                  [0x16U] 
                                                  >> 9U)))),23);
        bufp->chgQData(oldp+21,((0x7fffffffffffffULL 
                                 & VL_SHIFTR_QQI(55,55,32, 
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
        bufp->chgIData(oldp+23,((0x7ffffffU & ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__26__KET____DOT__q)
                                                ? (
                                                   (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                                    [0x1aU] 
                                                    >> 5U) 
                                                   - 
                                                   vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                                   [0x1aU])
                                                : (
                                                   vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                                   [0x1aU] 
                                                   >> 5U)))),27);
        bufp->chgQData(oldp+24,((0x7ffffffffffffffULL 
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
        bufp->chgIData(oldp+26,((0x3fffffffU & ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__29__KET____DOT__q)
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
                                                 >> 2U)))),30);
        bufp->chgQData(oldp+27,((0x3fffffffffffffffULL 
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
        bufp->chgCData(oldp+29,((7U & ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__2__KET____DOT__q)
                                        ? ((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                            [2U] >> 0x1dU) 
                                           - vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                           [2U]) : 
                                       (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                        [2U] >> 0x1dU)))),3);
        bufp->chgQData(oldp+30,((0x7ffffffffULL & VL_SHIFTR_QQI(35,35,32, 
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
        bufp->chgIData(oldp+32,(((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__31__KET____DOT__q)
                                  ? (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                     [0x1fU] - vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                     [0x1fU]) : vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                 [0x1fU])),32);
        bufp->chgQData(oldp+33,(VL_SHIFTR_QQI(64,64,32, 
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
        bufp->chgCData(oldp+35,((0x7fU & ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__6__KET____DOT__q)
                                           ? ((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                               [6U] 
                                               >> 0x19U) 
                                              - vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                              [6U])
                                           : (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                              [6U] 
                                              >> 0x19U)))),7);
        bufp->chgQData(oldp+36,((0x7fffffffffULL & 
                                 VL_SHIFTR_QQI(39,39,32, 
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
    }
    if (VL_UNLIKELY(((((vlSelfRef.__Vm_traceActivity
                        [2U] | vlSelfRef.__Vm_traceActivity
                        [3U]) | vlSelfRef.__Vm_traceActivity
                       [6U]) | vlSelfRef.__Vm_traceActivity
                      [9U])))) {
        bufp->chgSData(oldp+38,((0xfffU & ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__11__KET____DOT__q)
                                            ? ((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                                [0xbU] 
                                                >> 0x14U) 
                                               - vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                               [0xbU])
                                            : (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                               [0xbU] 
                                               >> 0x14U)))),12);
        bufp->chgQData(oldp+39,((0xfffffffffffULL & 
                                 VL_SHIFTR_QQI(44,44,32, 
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
        bufp->chgSData(oldp+41,((0x1fffU & ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__12__KET____DOT__q)
                                             ? ((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                                 [0xcU] 
                                                 >> 0x13U) 
                                                - vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                                [0xcU])
                                             : (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                                [0xcU] 
                                                >> 0x13U)))),13);
        bufp->chgQData(oldp+42,((0x1fffffffffffULL 
                                 & VL_SHIFTR_QQI(45,45,32, 
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
        bufp->chgSData(oldp+44,((0x3fffU & ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__13__KET____DOT__q)
                                             ? ((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                                 [0xdU] 
                                                 >> 0x12U) 
                                                - vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                                [0xdU])
                                             : (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                                [0xdU] 
                                                >> 0x12U)))),14);
        bufp->chgQData(oldp+45,((0x3fffffffffffULL 
                                 & VL_SHIFTR_QQI(46,46,32, 
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
        bufp->chgSData(oldp+47,((0xffffU & ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__15__KET____DOT__q)
                                             ? ((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                                 [0xfU] 
                                                 >> 0x10U) 
                                                - vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                                [0xfU])
                                             : (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                                [0xfU] 
                                                >> 0x10U)))),16);
        bufp->chgQData(oldp+48,((0xffffffffffffULL 
                                 & VL_SHIFTR_QQI(48,48,32, 
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
        bufp->chgIData(oldp+50,((0x1ffffU & ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__16__KET____DOT__q)
                                              ? ((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                                  [0x10U] 
                                                  >> 0xfU) 
                                                 - 
                                                 vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                                 [0x10U])
                                              : (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                                 [0x10U] 
                                                 >> 0xfU)))),17);
        bufp->chgQData(oldp+51,((0x1ffffffffffffULL 
                                 & VL_SHIFTR_QQI(49,49,32, 
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
        bufp->chgIData(oldp+53,((0x3ffffU & ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__17__KET____DOT__q)
                                              ? ((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                                  [0x11U] 
                                                  >> 0xeU) 
                                                 - 
                                                 vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                                 [0x11U])
                                              : (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                                 [0x11U] 
                                                 >> 0xeU)))),18);
        bufp->chgQData(oldp+54,((0x3ffffffffffffULL 
                                 & VL_SHIFTR_QQI(50,50,32, 
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
        bufp->chgIData(oldp+56,((0xfffffU & ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__19__KET____DOT__q)
                                              ? ((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                                  [0x13U] 
                                                  >> 0xcU) 
                                                 - 
                                                 vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                                 [0x13U])
                                              : (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                                 [0x13U] 
                                                 >> 0xcU)))),20);
        bufp->chgQData(oldp+57,((0xfffffffffffffULL 
                                 & VL_SHIFTR_QQI(52,52,32, 
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
        bufp->chgCData(oldp+59,((3U & ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__1__KET____DOT__q)
                                        ? ((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                            [1U] >> 0x1eU) 
                                           - vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                           [1U]) : 
                                       (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                        [1U] >> 0x1eU)))),2);
        bufp->chgQData(oldp+60,((0x3ffffffffULL & VL_SHIFTR_QQI(34,34,32, 
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
        bufp->chgIData(oldp+62,((0x1fffffU & ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__20__KET____DOT__q)
                                               ? ((
                                                   vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                                   [0x14U] 
                                                   >> 0xbU) 
                                                  - 
                                                  vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                                  [0x14U])
                                               : (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                                  [0x14U] 
                                                  >> 0xbU)))),21);
        bufp->chgQData(oldp+63,((0x1fffffffffffffULL 
                                 & VL_SHIFTR_QQI(53,53,32, 
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
        bufp->chgIData(oldp+65,((0x3fffffU & ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__21__KET____DOT__q)
                                               ? ((
                                                   vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                                   [0x15U] 
                                                   >> 0xaU) 
                                                  - 
                                                  vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                                  [0x15U])
                                               : (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                                  [0x15U] 
                                                  >> 0xaU)))),22);
        bufp->chgQData(oldp+66,((0x3fffffffffffffULL 
                                 & VL_SHIFTR_QQI(54,54,32, 
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
        bufp->chgIData(oldp+68,((0xffffffU & ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__23__KET____DOT__q)
                                               ? ((
                                                   vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                                   [0x17U] 
                                                   >> 8U) 
                                                  - 
                                                  vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                                  [0x17U])
                                               : (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                                  [0x17U] 
                                                  >> 8U)))),24);
        bufp->chgQData(oldp+69,((0xffffffffffffffULL 
                                 & VL_SHIFTR_QQI(56,56,32, 
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
        bufp->chgIData(oldp+71,((0x1ffffffU & ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__24__KET____DOT__q)
                                                ? (
                                                   (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                                    [0x18U] 
                                                    >> 7U) 
                                                   - 
                                                   vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                                   [0x18U])
                                                : (
                                                   vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                                   [0x18U] 
                                                   >> 7U)))),25);
        bufp->chgQData(oldp+72,((0x1ffffffffffffffULL 
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
        bufp->chgIData(oldp+74,((0x3ffffffU & ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__25__KET____DOT__q)
                                                ? (
                                                   (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                                    [0x19U] 
                                                    >> 6U) 
                                                   - 
                                                   vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                                   [0x19U])
                                                : (
                                                   vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                                   [0x19U] 
                                                   >> 6U)))),26);
        bufp->chgQData(oldp+75,((0x3ffffffffffffffULL 
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
        bufp->chgIData(oldp+77,((0xfffffffU & ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__27__KET____DOT__q)
                                                ? (
                                                   (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                                    [0x1bU] 
                                                    >> 4U) 
                                                   - 
                                                   vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                                   [0x1bU])
                                                : (
                                                   vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                                   [0x1bU] 
                                                   >> 4U)))),28);
        bufp->chgQData(oldp+78,((0xfffffffffffffffULL 
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
        bufp->chgIData(oldp+80,((0x1fffffffU & ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__28__KET____DOT__q)
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
                                                 >> 3U)))),29);
        bufp->chgQData(oldp+81,((0x1fffffffffffffffULL 
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
        bufp->chgIData(oldp+83,((0x7fffffffU & ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__30__KET____DOT__q)
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
                                                 >> 1U)))),31);
        bufp->chgQData(oldp+84,((0x7fffffffffffffffULL 
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
        bufp->chgCData(oldp+86,((0xfU & ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__3__KET____DOT__q)
                                          ? ((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                              [3U] 
                                              >> 0x1cU) 
                                             - vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                             [3U]) : 
                                         (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                          [3U] >> 0x1cU)))),4);
        bufp->chgQData(oldp+87,((0xfffffffffULL & VL_SHIFTR_QQI(36,36,32, 
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
        bufp->chgCData(oldp+89,((0x1fU & ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__4__KET____DOT__q)
                                           ? ((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                               [4U] 
                                               >> 0x1bU) 
                                              - vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                              [4U])
                                           : (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                              [4U] 
                                              >> 0x1bU)))),5);
        bufp->chgQData(oldp+90,((0x1fffffffffULL & 
                                 VL_SHIFTR_QQI(37,37,32, 
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
        bufp->chgCData(oldp+92,((0x3fU & ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__5__KET____DOT__q)
                                           ? ((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                               [5U] 
                                               >> 0x1aU) 
                                              - vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                              [5U])
                                           : (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                              [5U] 
                                              >> 0x1aU)))),6);
        bufp->chgQData(oldp+93,((0x3fffffffffULL & 
                                 VL_SHIFTR_QQI(38,38,32, 
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
        bufp->chgCData(oldp+95,((0xffU & ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__7__KET____DOT__q)
                                           ? ((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                               [7U] 
                                               >> 0x18U) 
                                              - vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                              [7U])
                                           : (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                              [7U] 
                                              >> 0x18U)))),8);
        bufp->chgQData(oldp+96,((0xffffffffffULL & 
                                 VL_SHIFTR_QQI(40,40,32, 
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
        bufp->chgSData(oldp+98,((0x1ffU & ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__8__KET____DOT__q)
                                            ? ((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                                [8U] 
                                                >> 0x17U) 
                                               - vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                               [8U])
                                            : (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                               [8U] 
                                               >> 0x17U)))),9);
        bufp->chgQData(oldp+99,((0x1ffffffffffULL & 
                                 VL_SHIFTR_QQI(41,41,32, 
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
        bufp->chgSData(oldp+101,((0x3ffU & ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__9__KET____DOT__q)
                                             ? ((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                                 [9U] 
                                                 >> 0x16U) 
                                                - vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                                [9U])
                                             : (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                                [9U] 
                                                >> 0x16U)))),10);
        bufp->chgQData(oldp+102,((0x3ffffffffffULL 
                                  & VL_SHIFTR_QQI(42,42,32, 
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
    }
    if (VL_UNLIKELY((((vlSelfRef.__Vm_traceActivity
                       [2U] | vlSelfRef.__Vm_traceActivity
                       [6U]) | vlSelfRef.__Vm_traceActivity
                      [9U])))) {
        bufp->chgBit(oldp+104,((1U & vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                [0U])));
        bufp->chgSData(oldp+105,((0x7ffU & vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                  [0xaU])),11);
        bufp->chgSData(oldp+106,((0xfffU & vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                  [0xbU])),12);
        bufp->chgSData(oldp+107,((0x1fffU & vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                  [0xcU])),13);
        bufp->chgSData(oldp+108,((0x3fffU & vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                  [0xdU])),14);
        bufp->chgSData(oldp+109,((0x7fffU & vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                  [0xeU])),15);
        bufp->chgSData(oldp+110,((0xffffU & vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                  [0xfU])),16);
        bufp->chgIData(oldp+111,((0x1ffffU & vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                  [0x10U])),17);
        bufp->chgIData(oldp+112,((0x3ffffU & vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                  [0x11U])),18);
        bufp->chgIData(oldp+113,((0x7ffffU & vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                  [0x12U])),19);
        bufp->chgIData(oldp+114,((0xfffffU & vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                  [0x13U])),20);
        bufp->chgCData(oldp+115,((3U & vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                  [1U])),2);
        bufp->chgIData(oldp+116,((0x1fffffU & vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                  [0x14U])),21);
        bufp->chgIData(oldp+117,((0x3fffffU & vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                  [0x15U])),22);
        bufp->chgIData(oldp+118,((0x7fffffU & vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                  [0x16U])),23);
        bufp->chgIData(oldp+119,((0xffffffU & vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                  [0x17U])),24);
        bufp->chgIData(oldp+120,((0x1ffffffU & vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                  [0x18U])),25);
        bufp->chgIData(oldp+121,((0x3ffffffU & vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                  [0x19U])),26);
        bufp->chgIData(oldp+122,((0x7ffffffU & vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                  [0x1aU])),27);
        bufp->chgIData(oldp+123,((0xfffffffU & vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                  [0x1bU])),28);
        bufp->chgIData(oldp+124,((0x1fffffffU & vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                  [0x1cU])),29);
        bufp->chgIData(oldp+125,((0x3fffffffU & vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                  [0x1dU])),30);
        bufp->chgCData(oldp+126,((7U & vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                  [2U])),3);
        bufp->chgIData(oldp+127,((0x7fffffffU & vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                  [0x1eU])),31);
        bufp->chgIData(oldp+128,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                 [0x1fU]),32);
        bufp->chgCData(oldp+129,((0xfU & vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                  [3U])),4);
        bufp->chgCData(oldp+130,((0x1fU & vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                  [4U])),5);
        bufp->chgCData(oldp+131,((0x3fU & vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                  [5U])),6);
        bufp->chgCData(oldp+132,((0x7fU & vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                  [6U])),7);
        bufp->chgCData(oldp+133,((0xffU & vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                  [7U])),8);
        bufp->chgSData(oldp+134,((0x1ffU & vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                  [8U])),9);
        bufp->chgSData(oldp+135,((0x3ffU & vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                  [9U])),10);
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[3U]))) {
        bufp->chgBit(oldp+136,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__11__KET____DOT__q));
        bufp->chgBit(oldp+137,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__12__KET____DOT__q));
        bufp->chgBit(oldp+138,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__13__KET____DOT__q));
        bufp->chgBit(oldp+139,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__15__KET____DOT__q));
        bufp->chgBit(oldp+140,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__16__KET____DOT__q));
        bufp->chgBit(oldp+141,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__17__KET____DOT__q));
        bufp->chgBit(oldp+142,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__19__KET____DOT__q));
        bufp->chgBit(oldp+143,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__1__KET____DOT__q));
        bufp->chgBit(oldp+144,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__20__KET____DOT__q));
        bufp->chgBit(oldp+145,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__21__KET____DOT__q));
        bufp->chgBit(oldp+146,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__23__KET____DOT__q));
        bufp->chgBit(oldp+147,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__24__KET____DOT__q));
        bufp->chgBit(oldp+148,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__25__KET____DOT__q));
        bufp->chgBit(oldp+149,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__27__KET____DOT__q));
        bufp->chgBit(oldp+150,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__28__KET____DOT__q));
        bufp->chgBit(oldp+151,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__30__KET____DOT__q));
        bufp->chgBit(oldp+152,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__3__KET____DOT__q));
        bufp->chgBit(oldp+153,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__4__KET____DOT__q));
        bufp->chgBit(oldp+154,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__5__KET____DOT__q));
        bufp->chgBit(oldp+155,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__7__KET____DOT__q));
        bufp->chgBit(oldp+156,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__8__KET____DOT__q));
        bufp->chgBit(oldp+157,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__9__KET____DOT__q));
    }
    if (VL_UNLIKELY((((vlSelfRef.__Vm_traceActivity
                       [3U] | vlSelfRef.__Vm_traceActivity
                       [6U]) | vlSelfRef.__Vm_traceActivity
                      [9U])))) {
        bufp->chgIData(oldp+158,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                 [0x20U]),32);
        bufp->chgBit(oldp+159,((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                [0U] >> 0x1fU)));
        bufp->chgIData(oldp+160,(VL_SHIFTL_III(32,32,32, 
                                               vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                               [0U], 1U)),32);
        bufp->chgSData(oldp+161,((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                  [0xaU] >> 0x15U)),11);
        bufp->chgIData(oldp+162,(VL_SHIFTL_III(32,32,32, 
                                               vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                               [0xaU], 0xbU)),32);
        bufp->chgSData(oldp+163,((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                  [0xbU] >> 0x14U)),12);
        bufp->chgIData(oldp+164,(VL_SHIFTL_III(32,32,32, 
                                               vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                               [0xbU], 0xcU)),32);
        bufp->chgSData(oldp+165,((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                  [0xcU] >> 0x13U)),13);
        bufp->chgIData(oldp+166,(VL_SHIFTL_III(32,32,32, 
                                               vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                               [0xcU], 0xdU)),32);
        bufp->chgSData(oldp+167,((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                  [0xdU] >> 0x12U)),14);
        bufp->chgIData(oldp+168,(VL_SHIFTL_III(32,32,32, 
                                               vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                               [0xdU], 0xeU)),32);
        bufp->chgSData(oldp+169,((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                  [0xeU] >> 0x11U)),15);
        bufp->chgIData(oldp+170,(VL_SHIFTL_III(32,32,32, 
                                               vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                               [0xeU], 0xfU)),32);
        bufp->chgSData(oldp+171,((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                  [0xfU] >> 0x10U)),16);
        bufp->chgIData(oldp+172,(VL_SHIFTL_III(32,32,32, 
                                               vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                               [0xfU], 0x10U)),32);
        bufp->chgIData(oldp+173,((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                  [0x10U] >> 0xfU)),17);
        bufp->chgIData(oldp+174,(VL_SHIFTL_III(32,32,32, 
                                               vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                               [0x10U], 0x11U)),32);
        bufp->chgIData(oldp+175,((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                  [0x11U] >> 0xeU)),18);
        bufp->chgIData(oldp+176,(VL_SHIFTL_III(32,32,32, 
                                               vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                               [0x11U], 0x12U)),32);
        bufp->chgIData(oldp+177,((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                  [0x12U] >> 0xdU)),19);
        bufp->chgIData(oldp+178,(VL_SHIFTL_III(32,32,32, 
                                               vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                               [0x12U], 0x13U)),32);
        bufp->chgIData(oldp+179,((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                  [0x13U] >> 0xcU)),20);
        bufp->chgIData(oldp+180,(VL_SHIFTL_III(32,32,32, 
                                               vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                               [0x13U], 0x14U)),32);
        bufp->chgCData(oldp+181,((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                  [1U] >> 0x1eU)),2);
        bufp->chgIData(oldp+182,(VL_SHIFTL_III(32,32,32, 
                                               vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                               [1U], 2U)),32);
        bufp->chgIData(oldp+183,((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                  [0x14U] >> 0xbU)),21);
        bufp->chgIData(oldp+184,(VL_SHIFTL_III(32,32,32, 
                                               vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                               [0x14U], 0x15U)),32);
        bufp->chgIData(oldp+185,((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                  [0x15U] >> 0xaU)),22);
        bufp->chgIData(oldp+186,(VL_SHIFTL_III(32,32,32, 
                                               vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                               [0x15U], 0x16U)),32);
        bufp->chgIData(oldp+187,((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                  [0x16U] >> 9U)),23);
        bufp->chgIData(oldp+188,(VL_SHIFTL_III(32,32,32, 
                                               vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                               [0x16U], 0x17U)),32);
        bufp->chgIData(oldp+189,((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                  [0x17U] >> 8U)),24);
        bufp->chgIData(oldp+190,(VL_SHIFTL_III(32,32,32, 
                                               vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                               [0x17U], 0x18U)),32);
        bufp->chgIData(oldp+191,((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                  [0x18U] >> 7U)),25);
        bufp->chgIData(oldp+192,(VL_SHIFTL_III(32,32,32, 
                                               vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                               [0x18U], 0x19U)),32);
        bufp->chgIData(oldp+193,((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                  [0x19U] >> 6U)),26);
        bufp->chgIData(oldp+194,(VL_SHIFTL_III(32,32,32, 
                                               vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                               [0x19U], 0x1aU)),32);
        bufp->chgIData(oldp+195,((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                  [0x1aU] >> 5U)),27);
        bufp->chgIData(oldp+196,(VL_SHIFTL_III(32,32,32, 
                                               vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                               [0x1aU], 0x1bU)),32);
        bufp->chgIData(oldp+197,((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                  [0x1bU] >> 4U)),28);
        bufp->chgIData(oldp+198,(VL_SHIFTL_III(32,32,32, 
                                               vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                               [0x1bU], 0x1cU)),32);
        bufp->chgIData(oldp+199,((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                  [0x1cU] >> 3U)),29);
        bufp->chgIData(oldp+200,(VL_SHIFTL_III(32,32,32, 
                                               vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                               [0x1cU], 0x1dU)),32);
        bufp->chgIData(oldp+201,((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                  [0x1dU] >> 2U)),30);
        bufp->chgIData(oldp+202,(VL_SHIFTL_III(32,32,32, 
                                               vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                               [0x1dU], 0x1eU)),32);
        bufp->chgCData(oldp+203,((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                  [2U] >> 0x1dU)),3);
        bufp->chgIData(oldp+204,(VL_SHIFTL_III(32,32,32, 
                                               vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                               [2U], 3U)),32);
        bufp->chgIData(oldp+205,((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                  [0x1eU] >> 1U)),31);
        bufp->chgIData(oldp+206,(VL_SHIFTL_III(32,32,32, 
                                               vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                               [0x1eU], 0x1fU)),32);
        bufp->chgIData(oldp+207,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                 [0x1fU]),32);
        bufp->chgCData(oldp+208,((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                  [3U] >> 0x1cU)),4);
        bufp->chgIData(oldp+209,(VL_SHIFTL_III(32,32,32, 
                                               vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                               [3U], 4U)),32);
        bufp->chgCData(oldp+210,((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                  [4U] >> 0x1bU)),5);
        bufp->chgIData(oldp+211,(VL_SHIFTL_III(32,32,32, 
                                               vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                               [4U], 5U)),32);
        bufp->chgCData(oldp+212,((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                  [5U] >> 0x1aU)),6);
        bufp->chgIData(oldp+213,(VL_SHIFTL_III(32,32,32, 
                                               vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                               [5U], 6U)),32);
        bufp->chgCData(oldp+214,((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                  [6U] >> 0x19U)),7);
        bufp->chgIData(oldp+215,(VL_SHIFTL_III(32,32,32, 
                                               vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                               [6U], 7U)),32);
        bufp->chgCData(oldp+216,((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                  [7U] >> 0x18U)),8);
        bufp->chgIData(oldp+217,(VL_SHIFTL_III(32,32,32, 
                                               vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                               [7U], 8U)),32);
        bufp->chgSData(oldp+218,((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                  [8U] >> 0x17U)),9);
        bufp->chgIData(oldp+219,(VL_SHIFTL_III(32,32,32, 
                                               vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                               [8U], 9U)),32);
        bufp->chgSData(oldp+220,((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                  [9U] >> 0x16U)),10);
        bufp->chgIData(oldp+221,(VL_SHIFTL_III(32,32,32, 
                                               vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                               [9U], 0xaU)),32);
    }
    if (VL_UNLIKELY(((vlSelfRef.__Vm_traceActivity[4U] 
                      | vlSelfRef.__Vm_traceActivity
                      [0xaU])))) {
        bufp->chgBit(oldp+222,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__0__KET____DOT__q));
        bufp->chgBit(oldp+223,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__10__KET____DOT__q));
        bufp->chgBit(oldp+224,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__14__KET____DOT__q));
        bufp->chgBit(oldp+225,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__18__KET____DOT__q));
        bufp->chgBit(oldp+226,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__22__KET____DOT__q));
        bufp->chgBit(oldp+227,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__26__KET____DOT__q));
        bufp->chgBit(oldp+228,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__29__KET____DOT__q));
        bufp->chgBit(oldp+229,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__2__KET____DOT__q));
        bufp->chgBit(oldp+230,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__31__KET____DOT__q));
        bufp->chgBit(oldp+231,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__6__KET____DOT__q));
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[5U]))) {
        bufp->chgBit(oldp+232,(vlSelfRef.CPU_top__DOT__cpu_ibus_request));
        bufp->chgIData(oldp+233,(vlSelfRef.CPU_top__DOT__cpu_ibus_address),32);
        bufp->chgBit(oldp+234,(vlSelfRef.CPU_top__DOT__cpu_dbus_rw));
        bufp->chgBit(oldp+235,(vlSelfRef.CPU_top__DOT__cpu_dbus_request));
        bufp->chgIData(oldp+236,(vlSelfRef.CPU_top__DOT__cpu_dbus_address),32);
        bufp->chgIData(oldp+237,(vlSelfRef.CPU_top__DOT__cpu_dbus_wdata),32);
        bufp->chgCData(oldp+238,(vlSelfRef.CPU_top__DOT__bus__DOT__state),2);
        bufp->chgBit(oldp+239,((((1U & (vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[3U] 
                                        >> 0x15U)) 
                                 != (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__last_strobe)) 
                                & (vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[0U] 
                                   >> 0x1aU))));
        bufp->chgBit(oldp+240,(vlSelfRef.CPU_top__DOT__cpu__DOT__memory_busy));
        bufp->chgSData(oldp+241,((0xfffU & ((vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[1U] 
                                             << 2U) 
                                            | (vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[0U] 
                                               >> 0x1eU)))),12);
        bufp->chgIData(oldp+242,(vlSelfRef.CPU_top__DOT__cpu__DOT__csr_rdata),32);
        bufp->chgBit(oldp+243,(vlSelfRef.CPU_top__DOT__cpu__DOT__csr_wdata_wr));
        bufp->chgIData(oldp+244,(vlSelfRef.CPU_top__DOT__cpu__DOT__csr_wdata),32);
        bufp->chgIData(oldp+245,(vlSelfRef.CPU_top__DOT__cpu__DOT__csr__DOT__mepc),32);
        bufp->chgQData(oldp+246,(vlSelfRef.CPU_top__DOT__cpu__DOT__writeback__DOT__retired),64);
        bufp->chgBit(oldp+248,(vlSelfRef.CPU_top__DOT__cpu__DOT__csr_irq_pending));
        bufp->chgIData(oldp+249,(vlSelfRef.CPU_top__DOT__cpu__DOT__csr_irq_pc),32);
        bufp->chgBit(oldp+250,(vlSelfRef.CPU_top__DOT__cpu__DOT__csr_irq_dispatched));
        bufp->chgIData(oldp+251,(vlSelfRef.CPU_top__DOT__cpu__DOT__csr_irq_epc),32);
        bufp->chgBit(oldp+252,((1U & (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__data[3U] 
                                      >> 0x14U))));
        bufp->chgIData(oldp+253,(((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__data[3U] 
                                   << 0xcU) | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__data[2U] 
                                               >> 0x14U))),32);
        bufp->chgIData(oldp+254,(((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__data[2U] 
                                   << 0xcU) | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__data[1U] 
                                               >> 0x14U))),32);
        bufp->chgCData(oldp+255,((0x1fU & (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__data[1U] 
                                           >> 0xfU))),5);
        bufp->chgCData(oldp+256,((0x1fU & (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__data[1U] 
                                           >> 0xaU))),5);
        bufp->chgCData(oldp+257,((0x1fU & (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__data[1U] 
                                           >> 5U))),5);
        bufp->chgCData(oldp+258,((0x1fU & vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__data[1U])),5);
        bufp->chgIData(oldp+259,(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__data[0U]),32);
        bufp->chgBit(oldp+260,(vlSelfRef.CPU_top__DOT__cpu__DOT__decode_fault));
        bufp->chgBit(oldp+261,((1U & (vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[3U] 
                                      >> 0x15U))));
        bufp->chgIData(oldp+262,(((vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[3U] 
                                   << 0xbU) | (vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[2U] 
                                               >> 0x15U))),32);
        bufp->chgCData(oldp+263,((7U & (vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[2U] 
                                        >> 0x12U))),3);
        bufp->chgCData(oldp+264,((0x1fU & (vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[2U] 
                                           >> 0xdU))),5);
        bufp->chgCData(oldp+265,((0x1fU & (vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[2U] 
                                           >> 8U))),5);
        bufp->chgCData(oldp+266,((0x1fU & (vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[2U] 
                                           >> 3U))),5);
        bufp->chgCData(oldp+267,((0x1fU & ((vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[2U] 
                                            << 2U) 
                                           | (vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[1U] 
                                              >> 0x1eU)))),5);
        bufp->chgIData(oldp+268,(((vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[1U] 
                                   << 2U) | (vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[0U] 
                                             >> 0x1eU))),32);
        bufp->chgBit(oldp+269,((1U & (vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[0U] 
                                      >> 0x1dU))));
        bufp->chgBit(oldp+270,((1U & (vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[0U] 
                                      >> 0x1cU))));
        bufp->chgBit(oldp+271,((1U & (vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[0U] 
                                      >> 0x1bU))));
        bufp->chgBit(oldp+272,((1U & (vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[0U] 
                                      >> 0x1aU))));
        bufp->chgBit(oldp+273,((1U & (vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[0U] 
                                      >> 0x19U))));
        bufp->chgBit(oldp+274,((1U & (vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[0U] 
                                      >> 0x18U))));
        bufp->chgCData(oldp+275,((0xfU & (vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[0U] 
                                          >> 0x14U))),4);
        bufp->chgCData(oldp+276,((0x1fU & (vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[0U] 
                                           >> 0xfU))),5);
        bufp->chgCData(oldp+277,((0x1fU & (vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[0U] 
                                           >> 0xaU))),5);
        bufp->chgBit(oldp+278,((1U & (vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[0U] 
                                      >> 9U))));
        bufp->chgBit(oldp+279,((1U & (vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[0U] 
                                      >> 8U))));
        bufp->chgCData(oldp+280,((3U & (vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[0U] 
                                        >> 6U))),2);
        bufp->chgBit(oldp+281,((1U & (vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[0U] 
                                      >> 5U))));
        bufp->chgCData(oldp+282,((0x1fU & vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[0U])),5);
        bufp->chgBit(oldp+283,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute_fault));
        bufp->chgBit(oldp+284,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute_jump));
        bufp->chgIData(oldp+285,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute_jump_pc),32);
        bufp->chgBit(oldp+286,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute_ecall));
        bufp->chgBit(oldp+287,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute_mret));
        bufp->chgBit(oldp+288,((1U & (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__data[3U] 
                                      >> 0x10U))));
        bufp->chgIData(oldp+289,(((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__data[3U] 
                                   << 0x10U) | (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__data[2U] 
                                                >> 0x10U))),32);
        bufp->chgCData(oldp+290,((0x1fU & (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__data[2U] 
                                           >> 0xbU))),5);
        bufp->chgIData(oldp+291,(((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__data[2U] 
                                   << 0x15U) | (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__data[1U] 
                                                >> 0xbU))),32);
        bufp->chgBit(oldp+292,((1U & (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__data[1U] 
                                      >> 0xaU))));
        bufp->chgBit(oldp+293,((1U & (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__data[1U] 
                                      >> 9U))));
        bufp->chgBit(oldp+294,((1U & (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__data[1U] 
                                      >> 8U))));
        bufp->chgCData(oldp+295,((3U & (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__data[1U] 
                                        >> 6U))),2);
        bufp->chgBit(oldp+296,((1U & (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__data[1U] 
                                      >> 5U))));
        bufp->chgIData(oldp+297,(((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__data[1U] 
                                   << 0x1bU) | (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__data[0U] 
                                                >> 5U))),32);
        bufp->chgCData(oldp+298,((0x1fU & vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__data[0U])),5);
        bufp->chgCData(oldp+299,((0x1fU & (IData)((vlSelfRef.CPU_top__DOT__cpu__DOT__writeback__DOT__data 
                                                   >> 0x20U)))),5);
        bufp->chgIData(oldp+300,((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__writeback__DOT__data)),32);
        bufp->chgBit(oldp+301,(vlSelfRef.CPU_top__DOT__cpu__DOT__csr__DOT__mstatus_mpie));
        bufp->chgBit(oldp+302,(vlSelfRef.CPU_top__DOT__cpu__DOT__csr__DOT__mstatus_mie));
        bufp->chgBit(oldp+303,(vlSelfRef.CPU_top__DOT__cpu__DOT__csr__DOT__mie_meie));
        bufp->chgBit(oldp+304,(vlSelfRef.CPU_top__DOT__cpu__DOT__csr__DOT__mie_mtie));
        bufp->chgBit(oldp+305,(vlSelfRef.CPU_top__DOT__cpu__DOT__csr__DOT__mie_msie));
        bufp->chgIData(oldp+306,(vlSelfRef.CPU_top__DOT__cpu__DOT__csr__DOT__mtvec),32);
        bufp->chgIData(oldp+307,(vlSelfRef.CPU_top__DOT__cpu__DOT__csr__DOT__mcause),32);
        bufp->chgBit(oldp+308,(vlSelfRef.CPU_top__DOT__cpu__DOT__csr__DOT__mip_meip));
        bufp->chgBit(oldp+309,(vlSelfRef.CPU_top__DOT__cpu__DOT__csr__DOT__mip_mtip));
        bufp->chgBit(oldp+310,(vlSelfRef.CPU_top__DOT__cpu__DOT__csr__DOT__mip_msip));
        bufp->chgIData(oldp+311,(vlSelfRef.CPU_top__DOT__cpu__DOT__csr__DOT__mscratch),32);
        bufp->chgIData(oldp+312,((((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__csr__DOT__mstatus_mpie) 
                                   << 4U) | ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__csr__DOT__mstatus_mie) 
                                             << 3U))),32);
        bufp->chgIData(oldp+313,((((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__csr__DOT__mie_meie) 
                                   << 0xbU) | (((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__csr__DOT__mie_mtie) 
                                                << 7U) 
                                               | ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__csr__DOT__mie_msie) 
                                                  << 3U)))),32);
        bufp->chgIData(oldp+314,((((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__csr__DOT__mip_meip) 
                                   << 0xbU) | (((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__csr__DOT__mip_mtip) 
                                                << 7U) 
                                               | ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__csr__DOT__mip_msip) 
                                                  << 3U)))),32);
        bufp->chgQData(oldp+315,(vlSelfRef.CPU_top__DOT__cpu__DOT__csr__DOT__cycle),64);
        bufp->chgQData(oldp+317,(vlSelfRef.CPU_top__DOT__cpu__DOT__csr__DOT__wtime),64);
        bufp->chgSData(oldp+319,(vlSelfRef.CPU_top__DOT__cpu__DOT__csr__DOT__prescale),14);
        bufp->chgCData(oldp+320,(vlSelfRef.CPU_top__DOT__cpu__DOT__csr__DOT__issued),3);
        bufp->chgBit(oldp+321,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__mul_request));
        bufp->chgBit(oldp+322,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__mul_signed));
        bufp->chgBit(oldp+323,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__multiply__DOT__r2_request));
        bufp->chgQData(oldp+324,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__multiply__DOT__r2_result),64);
        bufp->chgBit(oldp+326,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__div_request));
        bufp->chgBit(oldp+327,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__div_signed));
        bufp->chgBit(oldp+328,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__last_strobe));
        bufp->chgCData(oldp+329,((0xfU & (vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[0U] 
                                          >> 0x14U))),4);
        bufp->chgBit(oldp+330,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__multiply__DOT__r0_request));
        bufp->chgCData(oldp+331,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__multiply__DOT__r0_s),2);
        bufp->chgIData(oldp+332,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__multiply__DOT__r0_uop1),32);
        bufp->chgIData(oldp+333,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__multiply__DOT__r0_uop2),32);
        bufp->chgBit(oldp+334,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__multiply__DOT__r1_request));
        bufp->chgCData(oldp+335,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__multiply__DOT__r1_s),2);
        bufp->chgQData(oldp+336,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__multiply__DOT__r1_intermediate),64);
        bufp->chgCData(oldp+338,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__multiply__DOT__latch),2);
        bufp->chgBit(oldp+339,((0x33U == (0xfe00707fU 
                                          & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)))));
        bufp->chgBit(oldp+340,((0x13U == (0x707fU & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)))));
        bufp->chgBit(oldp+341,((0x7033U == (0xfe00707fU 
                                            & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)))));
        bufp->chgBit(oldp+342,((0x7013U == (0x707fU 
                                            & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)))));
        bufp->chgBit(oldp+343,((0x17U == (0x7fU & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)))));
        bufp->chgBit(oldp+344,((0x63U == (0x707fU & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)))));
        bufp->chgBit(oldp+345,((0x5063U == (0x707fU 
                                            & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)))));
        bufp->chgBit(oldp+346,((0x7063U == (0x707fU 
                                            & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)))));
        bufp->chgBit(oldp+347,((0x4063U == (0x707fU 
                                            & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)))));
        bufp->chgBit(oldp+348,((0x6063U == (0x707fU 
                                            & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)))));
        bufp->chgBit(oldp+349,((0x1063U == (0x707fU 
                                            & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)))));
        bufp->chgBit(oldp+350,((0x3073U == (0x707fU 
                                            & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)))));
        bufp->chgBit(oldp+351,((0x2073U == (0x707fU 
                                            & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)))));
        bufp->chgBit(oldp+352,((0x1073U == (0x707fU 
                                            & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)))));
        bufp->chgBit(oldp+353,((0x2004033U == (0xfe00707fU 
                                               & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)))));
        bufp->chgBit(oldp+354,((0x2005033U == (0xfe00707fU 
                                               & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)))));
        bufp->chgBit(oldp+355,((0x100073U == (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata))));
        bufp->chgBit(oldp+356,((0x73U == (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata))));
        bufp->chgBit(oldp+357,((0x53U == (0xfe00007fU 
                                          & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)))));
        bufp->chgBit(oldp+358,((0xc0000053U == (0xfff0007fU 
                                                & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)))));
        bufp->chgBit(oldp+359,((0xc0100053U == (0xfff0007fU 
                                                & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)))));
        bufp->chgBit(oldp+360,((0xd0000053U == (0xfff0007fU 
                                                & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)))));
        bufp->chgBit(oldp+361,((0xd0100053U == (0xfff0007fU 
                                                & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)))));
        bufp->chgBit(oldp+362,((0x18000053U == (0xfe00007fU 
                                                & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)))));
        bufp->chgBit(oldp+363,((0xfU == (0x707fU & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)))));
        bufp->chgBit(oldp+364,((0xa0002053U == (0xfe00707fU 
                                                & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)))));
        bufp->chgBit(oldp+365,((0xa0000053U == (0xfe00707fU 
                                                & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)))));
        bufp->chgBit(oldp+366,((0xa0001053U == (0xfe00707fU 
                                                & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)))));
        bufp->chgBit(oldp+367,((0x2007U == (0x707fU 
                                            & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)))));
        bufp->chgBit(oldp+368,((0x43U == (0x600007fU 
                                          & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)))));
        bufp->chgBit(oldp+369,((0x47U == (0x600007fU 
                                          & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)))));
        bufp->chgBit(oldp+370,((0x4fU == (0x600007fU 
                                          & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)))));
        bufp->chgBit(oldp+371,((0x4bU == (0x600007fU 
                                          & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)))));
        bufp->chgBit(oldp+372,((0x28000053U == (0xfe00707fU 
                                                & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)))));
        bufp->chgBit(oldp+373,((0x28001053U == (0xfe00707fU 
                                                & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)))));
        bufp->chgBit(oldp+374,((0x10000053U == (0xfe00007fU 
                                                & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)))));
        bufp->chgBit(oldp+375,((0xe0000053U == (0xfff0707fU 
                                                & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)))));
        bufp->chgBit(oldp+376,((0xf0000053U == (0xfff0707fU 
                                                & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)))));
        bufp->chgBit(oldp+377,((0x20000053U == (0xfe00707fU 
                                                & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)))));
        bufp->chgBit(oldp+378,((0x20001053U == (0xfe00707fU 
                                                & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)))));
        bufp->chgBit(oldp+379,((0x20002053U == (0xfe00707fU 
                                                & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)))));
        bufp->chgBit(oldp+380,((0x8000053U == (0xfe00007fU 
                                               & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)))));
        bufp->chgBit(oldp+381,((0x2027U == (0x707fU 
                                            & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)))));
        bufp->chgBit(oldp+382,((0x6fU == (0x7fU & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)))));
        bufp->chgBit(oldp+383,((0x67U == (0x707fU & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)))));
        bufp->chgBit(oldp+384,((3U == (0x707fU & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)))));
        bufp->chgBit(oldp+385,((0x4003U == (0x707fU 
                                            & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)))));
        bufp->chgBit(oldp+386,((0x1003U == (0x707fU 
                                            & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)))));
        bufp->chgBit(oldp+387,((0x5003U == (0x707fU 
                                            & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)))));
        bufp->chgBit(oldp+388,((0x37U == (0x7fU & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)))));
        bufp->chgBit(oldp+389,((0x2003U == (0x707fU 
                                            & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)))));
        bufp->chgBit(oldp+390,((0x2000033U == (0xfe00707fU 
                                               & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)))));
        bufp->chgBit(oldp+391,((0x2001033U == (0xfe00707fU 
                                               & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)))));
        bufp->chgBit(oldp+392,((0x2003033U == (0xfe00707fU 
                                               & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)))));
        bufp->chgBit(oldp+393,((0x30200073U == (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata))));
        bufp->chgBit(oldp+394,((0x6033U == (0xfe00707fU 
                                            & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)))));
        bufp->chgBit(oldp+395,((0x6013U == (0x707fU 
                                            & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)))));
        bufp->chgBit(oldp+396,((0x2006033U == (0xfe00707fU 
                                               & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)))));
        bufp->chgBit(oldp+397,((0x2007033U == (0xfe00707fU 
                                               & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)))));
        bufp->chgBit(oldp+398,((0x23U == (0x707fU & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)))));
        bufp->chgBit(oldp+399,((0x1023U == (0x707fU 
                                            & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)))));
        bufp->chgBit(oldp+400,((0x1033U == (0xfe00707fU 
                                            & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)))));
        bufp->chgBit(oldp+401,((0x1013U == (0xfc00707fU 
                                            & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)))));
        bufp->chgBit(oldp+402,((0x2033U == (0xfe00707fU 
                                            & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)))));
        bufp->chgBit(oldp+403,((0x2013U == (0x707fU 
                                            & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)))));
        bufp->chgBit(oldp+404,((0x3013U == (0x707fU 
                                            & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)))));
        bufp->chgBit(oldp+405,((0x3033U == (0xfe00707fU 
                                            & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)))));
        bufp->chgBit(oldp+406,((0x40005033U == (0xfe00707fU 
                                                & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)))));
        bufp->chgBit(oldp+407,((0x40005013U == (0xfc00707fU 
                                                & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)))));
        bufp->chgBit(oldp+408,((0x5033U == (0xfe00707fU 
                                            & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)))));
        bufp->chgBit(oldp+409,((0x5013U == (0xfc00707fU 
                                            & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)))));
        bufp->chgBit(oldp+410,((0x40000033U == (0xfe00707fU 
                                                & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)))));
        bufp->chgBit(oldp+411,((0x2023U == (0x707fU 
                                            & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)))));
        bufp->chgBit(oldp+412,((0x10500073U == (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata))));
        bufp->chgBit(oldp+413,((0x4033U == (0xfe00707fU 
                                            & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)))));
        bufp->chgBit(oldp+414,((0x4013U == (0x707fU 
                                            & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)))));
        bufp->chgBit(oldp+415,(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__is_JUMP_CONDITIONAL));
        bufp->chgBit(oldp+416,(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__is_I));
        bufp->chgBit(oldp+417,(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__is_R));
        bufp->chgBit(oldp+418,(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__have_RS3));
        bufp->chgBit(oldp+419,(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__is_S));
        bufp->chgBit(oldp+420,(((0x17U == (0x7fU & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata))) 
                                | (0x37U == (0x7fU 
                                             & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata))))));
        bufp->chgBit(oldp+421,(((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT____VdfgRegularize_hef2daed4_0_20) 
                                | (0x30200073U == (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)))));
        bufp->chgBit(oldp+422,(((0x33U == (0xfe00707fU 
                                           & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata))) 
                                | ((0x13U == (0x707fU 
                                              & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata))) 
                                   | ((0x7033U == (0xfe00707fU 
                                                   & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata))) 
                                      | ((0x7013U == 
                                          (0x707fU 
                                           & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata))) 
                                         | ((0x17U 
                                             == (0x7fU 
                                                 & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata))) 
                                            | ((0x37U 
                                                == 
                                                (0x7fU 
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
        bufp->chgBit(oldp+423,(((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT____VdfgRegularize_hef2daed4_0_8) 
                                | ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT____VdfgRegularize_hef2daed4_0_19) 
                                   | (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT____VdfgRegularize_hef2daed4_0_18)))));
        bufp->chgBit(oldp+424,(((0x2033U == (0xfe00707fU 
                                             & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata))) 
                                | ((0x2013U == (0x707fU 
                                                & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata))) 
                                   | ((0x3013U == (0x707fU 
                                                   & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata))) 
                                      | (0x3033U == 
                                         (0xfe00707fU 
                                          & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata))))))));
        bufp->chgBit(oldp+425,(((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT____VdfgRegularize_hef2daed4_0_20) 
                                | ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT____VdfgRegularize_hef2daed4_0_17) 
                                   | ((0x100073U == (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)) 
                                      | ((0x73U == (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)) 
                                         | ((0xfU == 
                                             (0x707fU 
                                              & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata))) 
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
        bufp->chgBit(oldp+426,(((0x6fU == (0x7fU & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata))) 
                                | (0x67U == (0x707fU 
                                             & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata))))));
        bufp->chgBit(oldp+427,(((3U == (0x707fU & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata))) 
                                | ((0x4003U == (0x707fU 
                                                & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata))) 
                                   | ((0x1003U == (0x707fU 
                                                   & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata))) 
                                      | ((0x5003U == 
                                          (0x707fU 
                                           & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata))) 
                                         | ((0x2003U 
                                             == (0x707fU 
                                                 & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata))) 
                                            | (IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_8_0))))))));
        bufp->chgBit(oldp+428,(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__is_FPU));
        bufp->chgBit(oldp+429,(((0x2007U == (0x707fU 
                                             & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata))) 
                                | (0x2027U == (0x707fU 
                                               & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata))))));
        bufp->chgBit(oldp+430,(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__RD_bank));
        bufp->chgBit(oldp+431,(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__RS1_bank));
        bufp->chgBit(oldp+432,(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__RS2_bank));
        bufp->chgBit(oldp+433,(vlSelfRef.CPU_top__DOT__cpu__DOT____Vcellinp__fetch__i_busy));
        bufp->chgCData(oldp+434,(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__state),2);
        bufp->chgIData(oldp+435,(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__pc),32);
        bufp->chgIData(oldp+436,((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)),32);
        bufp->chgBit(oldp+437,(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__icache_ready));
        bufp->chgBit(oldp+438,(((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__is_JUMP_CONDITIONAL) 
                                | ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__is_I) 
                                   | ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__is_R) 
                                      | ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__is_S) 
                                         | (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT____VdfgRegularize_hef2daed4_0_14)))))));
        bufp->chgBit(oldp+439,(((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__is_JUMP_CONDITIONAL) 
                                | ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__is_R) 
                                   | ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__is_S) 
                                      | (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__have_RS3))))));
        bufp->chgBit(oldp+440,(((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__is_I) 
                                | ((0x6fU == (0x7fU 
                                              & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata))) 
                                   | ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__is_R) 
                                      | (((0x17U == 
                                           (0x7fU & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata))) 
                                          | (0x37U 
                                             == (0x7fU 
                                                 & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)))) 
                                         | (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT____VdfgRegularize_hef2daed4_0_14)))))));
        bufp->chgBit(oldp+441,(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__irq_pending_r));
        bufp->chgBit(oldp+442,(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT__initialized));
        bufp->chgIData(oldp+443,(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT__clear_set),32);
        bufp->chgBit(oldp+444,(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT__cache_invalid));
        bufp->chgSData(oldp+445,((0xfffU & (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__pc 
                                            >> 2U))),12);
        bufp->chgIData(oldp+446,((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__pc 
                                  >> 0xeU)),18);
        bufp->chgSData(oldp+447,(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT__cache_rd_set),12);
        bufp->chgBit(oldp+448,((1U & (IData)((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata 
                                              >> 0x32U)))));
        bufp->chgIData(oldp+449,((0x3ffffU & (IData)(
                                                     (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata 
                                                      >> 0x20U)))),18);
        bufp->chgIData(oldp+450,((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)),32);
        bufp->chgBit(oldp+451,(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT__cache_wr_request));
        bufp->chgSData(oldp+452,(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT__cache_wr_set),12);
        bufp->chgBit(oldp+453,((1U & (IData)((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT__cache_wr_wdata 
                                              >> 0x32U)))));
        bufp->chgIData(oldp+454,((0x3ffffU & (IData)(
                                                     (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT__cache_wr_wdata 
                                                      >> 0x20U)))),18);
        bufp->chgIData(oldp+455,((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT__cache_wr_wdata)),32);
        bufp->chgSData(oldp+456,(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT__set_r),12);
        bufp->chgIData(oldp+457,(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT__cache_rd_set),32);
        bufp->chgQData(oldp+458,(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata),51);
        bufp->chgBit(oldp+460,(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT__cache__DOT__o_pa_ready));
        bufp->chgIData(oldp+461,(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT__cache_wr_set),32);
        bufp->chgQData(oldp+462,(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT__cache_wr_wdata),51);
        bufp->chgBit(oldp+464,(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT__cache__DOT__o_pb_ready));
        bufp->chgWData(oldp+465,(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__data),117);
        bufp->chgWData(oldp+469,(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_skid__DOT__r_data),117);
        bufp->chgBit(oldp+473,(vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__dcache_rw));
        bufp->chgBit(oldp+474,(vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__dcache_request));
        bufp->chgBit(oldp+475,(vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__dcache_flush));
        bufp->chgBit(oldp+476,(vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__dcache_ready));
        bufp->chgIData(oldp+477,((0xfffffffcU & ((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__data[1U] 
                                                  << 0x1bU) 
                                                 | (0x7fffffcU 
                                                    & (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__data[0U] 
                                                       >> 5U))))),32);
        bufp->chgIData(oldp+478,(vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__dcache_rdata),32);
        bufp->chgIData(oldp+479,(vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__dcache_wdata),32);
        bufp->chgBit(oldp+480,((2U == (0xfU & (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__data[1U] 
                                               >> 1U)))));
        bufp->chgCData(oldp+481,((3U & (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__data[0U] 
                                        >> 5U))),2);
        bufp->chgCData(oldp+482,((0xffU & vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT____VdfgRegularize_h9eb5ee7c_0_0)),8);
        bufp->chgSData(oldp+483,((0xffffU & vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT____VdfgRegularize_h9eb5ee7c_0_0)),16);
        bufp->chgCData(oldp+484,(vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__state),3);
        bufp->chgIData(oldp+485,(vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__rmw_rdata),32);
        bufp->chgBit(oldp+486,(vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__last_strobe));
        bufp->chgCData(oldp+487,(vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__genblk1__DOT__dcache__DOT__state),4);
        bufp->chgSData(oldp+488,(vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__genblk1__DOT__dcache__DOT__flush_address),13);
        bufp->chgBit(oldp+489,(vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__genblk1__DOT__dcache__DOT__wb_rw));
        bufp->chgBit(oldp+490,(vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__genblk1__DOT__dcache__DOT__wb_request));
        bufp->chgIData(oldp+491,(vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__genblk1__DOT__dcache__DOT__wb_address),32);
        bufp->chgIData(oldp+492,(vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__genblk1__DOT__dcache__DOT__wb_wdata),32);
        bufp->chgBit(oldp+493,(vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__genblk1__DOT__dcache__DOT__wb_cached));
        bufp->chgBit(oldp+494,(vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__genblk1__DOT__dcache__DOT__cache_rw));
        bufp->chgSData(oldp+495,(vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__genblk1__DOT__dcache__DOT__cache_address),12);
        bufp->chgQData(oldp+496,(vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__genblk1__DOT__dcache__DOT__cache_wdata),64);
        bufp->chgQData(oldp+498,(vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__genblk1__DOT__dcache__DOT__cache_rdata),64);
        bufp->chgBit(oldp+500,((1U & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__genblk1__DOT__dcache__DOT__cache_rdata))));
        bufp->chgBit(oldp+501,((1U & (IData)((vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__genblk1__DOT__dcache__DOT__cache_rdata 
                                              >> 1U)))));
        bufp->chgIData(oldp+502,(((IData)((vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__genblk1__DOT__dcache__DOT__cache_rdata 
                                           >> 2U)) 
                                  << 2U)),32);
        bufp->chgIData(oldp+503,((IData)((vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__genblk1__DOT__dcache__DOT__cache_rdata 
                                          >> 0x20U))),32);
        bufp->chgIData(oldp+504,(vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__genblk1__DOT__dcache__DOT__cache_address),32);
        bufp->chgBit(oldp+505,(vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__genblk1__DOT__dcache__DOT__cache__DOT__o_ready));
        bufp->chgBit(oldp+506,(vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__genblk1__DOT__dcache__DOT__cache__DOT__o_valid));
        bufp->chgBit(oldp+507,(vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__genblk1__DOT__dcache__DOT__wb__DOT__wb_dirty[0]));
        bufp->chgBit(oldp+508,(vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__genblk1__DOT__dcache__DOT__wb__DOT__wb_dirty[1]));
        bufp->chgBit(oldp+509,(vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__genblk1__DOT__dcache__DOT__wb__DOT__wb_dirty[2]));
        bufp->chgBit(oldp+510,(vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__genblk1__DOT__dcache__DOT__wb__DOT__wb_dirty[3]));
        bufp->chgIData(oldp+511,(vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__genblk1__DOT__dcache__DOT__wb__DOT__wb_address[0]),32);
        bufp->chgIData(oldp+512,(vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__genblk1__DOT__dcache__DOT__wb__DOT__wb_address[1]),32);
        bufp->chgIData(oldp+513,(vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__genblk1__DOT__dcache__DOT__wb__DOT__wb_address[2]),32);
        bufp->chgIData(oldp+514,(vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__genblk1__DOT__dcache__DOT__wb__DOT__wb_address[3]),32);
        bufp->chgIData(oldp+515,(vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__genblk1__DOT__dcache__DOT__wb__DOT__wb_data[0]),32);
        bufp->chgIData(oldp+516,(vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__genblk1__DOT__dcache__DOT__wb__DOT__wb_data[1]),32);
        bufp->chgIData(oldp+517,(vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__genblk1__DOT__dcache__DOT__wb__DOT__wb_data[2]),32);
        bufp->chgIData(oldp+518,(vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__genblk1__DOT__dcache__DOT__wb__DOT__wb_data[3]),32);
        bufp->chgIData(oldp+519,(vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__genblk1__DOT__dcache__DOT__wb__DOT__next_wb_address[0]),32);
        bufp->chgIData(oldp+520,(vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__genblk1__DOT__dcache__DOT__wb__DOT__next_wb_address[1]),32);
        bufp->chgIData(oldp+521,(vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__genblk1__DOT__dcache__DOT__wb__DOT__next_wb_address[2]),32);
        bufp->chgIData(oldp+522,(vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__genblk1__DOT__dcache__DOT__wb__DOT__next_wb_address[3]),32);
        bufp->chgIData(oldp+523,(vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__genblk1__DOT__dcache__DOT__wb__DOT__next_wb_data[0]),32);
        bufp->chgIData(oldp+524,(vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__genblk1__DOT__dcache__DOT__wb__DOT__next_wb_data[1]),32);
        bufp->chgIData(oldp+525,(vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__genblk1__DOT__dcache__DOT__wb__DOT__next_wb_data[2]),32);
        bufp->chgIData(oldp+526,(vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__genblk1__DOT__dcache__DOT__wb__DOT__next_wb_data[3]),32);
        bufp->chgBit(oldp+527,(vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__genblk1__DOT__dcache__DOT__wb__DOT__wb_dirty
                               [0U]));
        bufp->chgBit(oldp+528,(vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__genblk1__DOT__dcache__DOT__wb__DOT__wb_dirty
                               [1U]));
        bufp->chgBit(oldp+529,(vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__genblk1__DOT__dcache__DOT__wb__DOT__wb_dirty
                               [2U]));
        bufp->chgBit(oldp+530,(vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__genblk1__DOT__dcache__DOT__wb__DOT__wb_dirty
                               [3U]));
        bufp->chgBit(oldp+531,(vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__genblk1__DOT__dcache__DOT__wb__DOT__all_dirty));
        bufp->chgBit(oldp+532,(vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__genblk1__DOT__dcache__DOT__wb__DOT__any_dirty));
        bufp->chgIData(oldp+533,(vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__genblk1__DOT__dcache__DOT__wb__DOT__unnamedblk2__DOT__i),32);
        bufp->chgBit(oldp+534,(vlSelfRef.CPU_top__DOT__cpu__DOT__writeback__DOT__last_strobe));
        bufp->chgIData(oldp+535,(vlSelfRef.CPU_top__DOT__cpu__DOT__writeback__DOT__last_pc),32);
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[7U]))) {
        bufp->chgIData(oldp+536,(vlSelfRef.CPU_top__DOT__cpu__DOT__registers__DOT__rs1),32);
        bufp->chgIData(oldp+537,(vlSelfRef.CPU_top__DOT__cpu__DOT__registers__DOT__rs2),32);
        bufp->chgIData(oldp+538,(vlSelfRef.CPU_top__DOT__cpu__DOT__registers__DOT__rs3),32);
        bufp->chgBit(oldp+539,(vlSelfRef.CPU_top__DOT__cpu__DOT__registers__DOT__last_write_strobe));
        bufp->chgIData(oldp+540,(vlSelfRef.CPU_top__DOT__cpu__DOT__registers__DOT__r[0]),32);
        bufp->chgIData(oldp+541,(vlSelfRef.CPU_top__DOT__cpu__DOT__registers__DOT__r[1]),32);
        bufp->chgIData(oldp+542,(vlSelfRef.CPU_top__DOT__cpu__DOT__registers__DOT__r[2]),32);
        bufp->chgIData(oldp+543,(vlSelfRef.CPU_top__DOT__cpu__DOT__registers__DOT__r[3]),32);
        bufp->chgIData(oldp+544,(vlSelfRef.CPU_top__DOT__cpu__DOT__registers__DOT__r[4]),32);
        bufp->chgIData(oldp+545,(vlSelfRef.CPU_top__DOT__cpu__DOT__registers__DOT__r[5]),32);
        bufp->chgIData(oldp+546,(vlSelfRef.CPU_top__DOT__cpu__DOT__registers__DOT__r[6]),32);
        bufp->chgIData(oldp+547,(vlSelfRef.CPU_top__DOT__cpu__DOT__registers__DOT__r[7]),32);
        bufp->chgIData(oldp+548,(vlSelfRef.CPU_top__DOT__cpu__DOT__registers__DOT__r[8]),32);
        bufp->chgIData(oldp+549,(vlSelfRef.CPU_top__DOT__cpu__DOT__registers__DOT__r[9]),32);
        bufp->chgIData(oldp+550,(vlSelfRef.CPU_top__DOT__cpu__DOT__registers__DOT__r[10]),32);
        bufp->chgIData(oldp+551,(vlSelfRef.CPU_top__DOT__cpu__DOT__registers__DOT__r[11]),32);
        bufp->chgIData(oldp+552,(vlSelfRef.CPU_top__DOT__cpu__DOT__registers__DOT__r[12]),32);
        bufp->chgIData(oldp+553,(vlSelfRef.CPU_top__DOT__cpu__DOT__registers__DOT__r[13]),32);
        bufp->chgIData(oldp+554,(vlSelfRef.CPU_top__DOT__cpu__DOT__registers__DOT__r[14]),32);
        bufp->chgIData(oldp+555,(vlSelfRef.CPU_top__DOT__cpu__DOT__registers__DOT__r[15]),32);
        bufp->chgIData(oldp+556,(vlSelfRef.CPU_top__DOT__cpu__DOT__registers__DOT__r[16]),32);
        bufp->chgIData(oldp+557,(vlSelfRef.CPU_top__DOT__cpu__DOT__registers__DOT__r[17]),32);
        bufp->chgIData(oldp+558,(vlSelfRef.CPU_top__DOT__cpu__DOT__registers__DOT__r[18]),32);
        bufp->chgIData(oldp+559,(vlSelfRef.CPU_top__DOT__cpu__DOT__registers__DOT__r[19]),32);
        bufp->chgIData(oldp+560,(vlSelfRef.CPU_top__DOT__cpu__DOT__registers__DOT__r[20]),32);
        bufp->chgIData(oldp+561,(vlSelfRef.CPU_top__DOT__cpu__DOT__registers__DOT__r[21]),32);
        bufp->chgIData(oldp+562,(vlSelfRef.CPU_top__DOT__cpu__DOT__registers__DOT__r[22]),32);
        bufp->chgIData(oldp+563,(vlSelfRef.CPU_top__DOT__cpu__DOT__registers__DOT__r[23]),32);
        bufp->chgIData(oldp+564,(vlSelfRef.CPU_top__DOT__cpu__DOT__registers__DOT__r[24]),32);
        bufp->chgIData(oldp+565,(vlSelfRef.CPU_top__DOT__cpu__DOT__registers__DOT__r[25]),32);
        bufp->chgIData(oldp+566,(vlSelfRef.CPU_top__DOT__cpu__DOT__registers__DOT__r[26]),32);
        bufp->chgIData(oldp+567,(vlSelfRef.CPU_top__DOT__cpu__DOT__registers__DOT__r[27]),32);
        bufp->chgIData(oldp+568,(vlSelfRef.CPU_top__DOT__cpu__DOT__registers__DOT__r[28]),32);
        bufp->chgIData(oldp+569,(vlSelfRef.CPU_top__DOT__cpu__DOT__registers__DOT__r[29]),32);
        bufp->chgIData(oldp+570,(vlSelfRef.CPU_top__DOT__cpu__DOT__registers__DOT__r[30]),32);
        bufp->chgIData(oldp+571,(vlSelfRef.CPU_top__DOT__cpu__DOT__registers__DOT__r[31]),32);
        bufp->chgIData(oldp+572,(vlSelfRef.CPU_top__DOT__cpu__DOT__registers__DOT__I),32);
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[8U]))) {
        bufp->chgBit(oldp+573,((1U & (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                      >> 0x14U))));
        bufp->chgIData(oldp+574,(((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                   << 0xcU) | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                               >> 0x14U))),32);
        bufp->chgIData(oldp+575,(((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                   << 0xcU) | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[1U] 
                                               >> 0x14U))),32);
        bufp->chgCData(oldp+576,((0x1fU & (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[1U] 
                                           >> 0xfU))),5);
        bufp->chgCData(oldp+577,((0x1fU & (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[1U] 
                                           >> 0xaU))),5);
        bufp->chgCData(oldp+578,((0x1fU & (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[1U] 
                                           >> 5U))),5);
        bufp->chgCData(oldp+579,((0x1fU & vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[1U])),5);
        bufp->chgIData(oldp+580,(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[0U]),32);
        bufp->chgBit(oldp+581,((1U & (vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__data[2U] 
                                      >> 5U))));
        bufp->chgIData(oldp+582,(((vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__data[2U] 
                                   << 0x1bU) | (vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__data[1U] 
                                                >> 5U))),32);
        bufp->chgCData(oldp+583,((0x1fU & vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__data[1U])),5);
        bufp->chgIData(oldp+584,(vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__data[0U]),32);
        bufp->chgBit(oldp+585,(((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__is_B) 
                                | ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__is_I) 
                                   | ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__is_R) 
                                      | ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__is_S) 
                                         | (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT____VdfgRegularize_h2cfc3394_0_18)))))));
        bufp->chgBit(oldp+586,(((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__is_B) 
                                | ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__is_R) 
                                   | ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__is_S) 
                                      | (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__have_RS3))))));
        bufp->chgBit(oldp+587,(vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__have_RS3));
        bufp->chgBit(oldp+588,(((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__is_I) 
                                | ((0x6fU == (0x7fU 
                                              & (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                 >> 0x14U))) 
                                   | ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__is_R) 
                                      | ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__is_U) 
                                         | (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT____VdfgRegularize_h2cfc3394_0_18)))))));
        bufp->chgIData(oldp+589,((((- (IData)((1U & 
                                               (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
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
        bufp->chgIData(oldp+590,((((- (IData)((1U & 
                                               (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                >> 0x13U)))) 
                                   << 0xbU) | (0x7ffU 
                                               & (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                  >> 8U)))),32);
        bufp->chgIData(oldp+591,((((- (IData)((1U & 
                                               (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
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
        bufp->chgIData(oldp+592,((((- (IData)((1U & 
                                               (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                >> 0x13U)))) 
                                   << 0xbU) | ((0x7e0U 
                                                & (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                   >> 8U)) 
                                               | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                  >> 0x1bU)))),32);
        bufp->chgIData(oldp+593,((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                  << 0xcU)),32);
        bufp->chgIData(oldp+594,((0x3fU & (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                           >> 8U))),32);
        bufp->chgIData(oldp+595,((0xfffU & (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                            >> 8U))),32);
        bufp->chgBit(oldp+596,((0x33U == (0xfe00707fU 
                                          & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                              << 0xcU) 
                                             | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                >> 0x14U))))));
        bufp->chgBit(oldp+597,((0x13U == (0x707fU & 
                                          ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                            << 0xcU) 
                                           | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                              >> 0x14U))))));
        bufp->chgBit(oldp+598,((0x7033U == (0xfe00707fU 
                                            & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                << 0xcU) 
                                               | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                  >> 0x14U))))));
        bufp->chgBit(oldp+599,((0x7013U == (0x707fU 
                                            & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                << 0xcU) 
                                               | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                  >> 0x14U))))));
        bufp->chgBit(oldp+600,((0x17U == (0x7fU & (
                                                   vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                   >> 0x14U)))));
        bufp->chgBit(oldp+601,((0x63U == (0x707fU & 
                                          ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                            << 0xcU) 
                                           | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                              >> 0x14U))))));
        bufp->chgBit(oldp+602,((0x5063U == (0x707fU 
                                            & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                << 0xcU) 
                                               | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                  >> 0x14U))))));
        bufp->chgBit(oldp+603,((0x7063U == (0x707fU 
                                            & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                << 0xcU) 
                                               | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                  >> 0x14U))))));
        bufp->chgBit(oldp+604,((0x4063U == (0x707fU 
                                            & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                << 0xcU) 
                                               | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                  >> 0x14U))))));
        bufp->chgBit(oldp+605,((0x6063U == (0x707fU 
                                            & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                << 0xcU) 
                                               | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                  >> 0x14U))))));
        bufp->chgBit(oldp+606,((0x1063U == (0x707fU 
                                            & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                << 0xcU) 
                                               | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                  >> 0x14U))))));
        bufp->chgBit(oldp+607,((0x3073U == (0x707fU 
                                            & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                << 0xcU) 
                                               | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                  >> 0x14U))))));
        bufp->chgBit(oldp+608,((0x2073U == (0x707fU 
                                            & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                << 0xcU) 
                                               | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                  >> 0x14U))))));
        bufp->chgBit(oldp+609,((0x1073U == (0x707fU 
                                            & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                << 0xcU) 
                                               | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                  >> 0x14U))))));
        bufp->chgBit(oldp+610,((0x2004033U == (0xfe00707fU 
                                               & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                   << 0xcU) 
                                                  | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                     >> 0x14U))))));
        bufp->chgBit(oldp+611,((0x2005033U == (0xfe00707fU 
                                               & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                   << 0xcU) 
                                                  | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                     >> 0x14U))))));
        bufp->chgBit(oldp+612,((0x100073U == ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                               << 0xcU) 
                                              | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                 >> 0x14U)))));
        bufp->chgBit(oldp+613,((0x73U == ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                           << 0xcU) 
                                          | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                             >> 0x14U)))));
        bufp->chgBit(oldp+614,((0x53U == (0xfe00007fU 
                                          & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                              << 0xcU) 
                                             | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                >> 0x14U))))));
        bufp->chgBit(oldp+615,((0xc0000053U == (0xfff0007fU 
                                                & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                    << 0xcU) 
                                                   | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                      >> 0x14U))))));
        bufp->chgBit(oldp+616,((0xc0100053U == (0xfff0007fU 
                                                & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                    << 0xcU) 
                                                   | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                      >> 0x14U))))));
        bufp->chgBit(oldp+617,((0xd0000053U == (0xfff0007fU 
                                                & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                    << 0xcU) 
                                                   | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                      >> 0x14U))))));
        bufp->chgBit(oldp+618,((0xd0100053U == (0xfff0007fU 
                                                & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                    << 0xcU) 
                                                   | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                      >> 0x14U))))));
        bufp->chgBit(oldp+619,((0x18000053U == (0xfe00007fU 
                                                & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                    << 0xcU) 
                                                   | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                      >> 0x14U))))));
        bufp->chgBit(oldp+620,((0xfU == (0x707fU & 
                                         ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                           << 0xcU) 
                                          | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                             >> 0x14U))))));
        bufp->chgBit(oldp+621,((0xa0002053U == (0xfe00707fU 
                                                & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                    << 0xcU) 
                                                   | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                      >> 0x14U))))));
        bufp->chgBit(oldp+622,((0xa0000053U == (0xfe00707fU 
                                                & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                    << 0xcU) 
                                                   | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                      >> 0x14U))))));
        bufp->chgBit(oldp+623,((0xa0001053U == (0xfe00707fU 
                                                & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                    << 0xcU) 
                                                   | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                      >> 0x14U))))));
        bufp->chgBit(oldp+624,((0x2007U == (0x707fU 
                                            & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                << 0xcU) 
                                               | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                  >> 0x14U))))));
        bufp->chgBit(oldp+625,((0x43U == (0x600007fU 
                                          & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                              << 0xcU) 
                                             | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                >> 0x14U))))));
        bufp->chgBit(oldp+626,((0x47U == (0x600007fU 
                                          & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                              << 0xcU) 
                                             | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                >> 0x14U))))));
        bufp->chgBit(oldp+627,((0x4fU == (0x600007fU 
                                          & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                              << 0xcU) 
                                             | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                >> 0x14U))))));
        bufp->chgBit(oldp+628,((0x4bU == (0x600007fU 
                                          & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                              << 0xcU) 
                                             | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                >> 0x14U))))));
        bufp->chgBit(oldp+629,((0x28000053U == (0xfe00707fU 
                                                & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                    << 0xcU) 
                                                   | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                      >> 0x14U))))));
        bufp->chgBit(oldp+630,((0x28001053U == (0xfe00707fU 
                                                & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                    << 0xcU) 
                                                   | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                      >> 0x14U))))));
        bufp->chgBit(oldp+631,((0x10000053U == (0xfe00007fU 
                                                & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                    << 0xcU) 
                                                   | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                      >> 0x14U))))));
        bufp->chgBit(oldp+632,((0xe0000053U == (0xfff0707fU 
                                                & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                    << 0xcU) 
                                                   | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                      >> 0x14U))))));
        bufp->chgBit(oldp+633,((0xf0000053U == (0xfff0707fU 
                                                & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                    << 0xcU) 
                                                   | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                      >> 0x14U))))));
        bufp->chgBit(oldp+634,((0x20000053U == (0xfe00707fU 
                                                & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                    << 0xcU) 
                                                   | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                      >> 0x14U))))));
        bufp->chgBit(oldp+635,((0x20001053U == (0xfe00707fU 
                                                & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                    << 0xcU) 
                                                   | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                      >> 0x14U))))));
        bufp->chgBit(oldp+636,((0x20002053U == (0xfe00707fU 
                                                & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                    << 0xcU) 
                                                   | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                      >> 0x14U))))));
        bufp->chgBit(oldp+637,((0x8000053U == (0xfe00007fU 
                                               & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                   << 0xcU) 
                                                  | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                     >> 0x14U))))));
        bufp->chgBit(oldp+638,((0x2027U == (0x707fU 
                                            & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                << 0xcU) 
                                               | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                  >> 0x14U))))));
        bufp->chgBit(oldp+639,((0x6fU == (0x7fU & (
                                                   vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                   >> 0x14U)))));
        bufp->chgBit(oldp+640,((0x67U == (0x707fU & 
                                          ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                            << 0xcU) 
                                           | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                              >> 0x14U))))));
        bufp->chgBit(oldp+641,((3U == (0x707fU & ((
                                                   vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                   << 0xcU) 
                                                  | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                     >> 0x14U))))));
        bufp->chgBit(oldp+642,((0x4003U == (0x707fU 
                                            & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                << 0xcU) 
                                               | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                  >> 0x14U))))));
        bufp->chgBit(oldp+643,((0x1003U == (0x707fU 
                                            & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                << 0xcU) 
                                               | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                  >> 0x14U))))));
        bufp->chgBit(oldp+644,((0x5003U == (0x707fU 
                                            & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                << 0xcU) 
                                               | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                  >> 0x14U))))));
        bufp->chgBit(oldp+645,((0x37U == (0x7fU & (
                                                   vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                   >> 0x14U)))));
        bufp->chgBit(oldp+646,((0x2003U == (0x707fU 
                                            & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                << 0xcU) 
                                               | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                  >> 0x14U))))));
        bufp->chgBit(oldp+647,((0x2000033U == (0xfe00707fU 
                                               & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                   << 0xcU) 
                                                  | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                     >> 0x14U))))));
        bufp->chgBit(oldp+648,((0x2001033U == (0xfe00707fU 
                                               & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                   << 0xcU) 
                                                  | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                     >> 0x14U))))));
        bufp->chgBit(oldp+649,((0x2003033U == (0xfe00707fU 
                                               & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                   << 0xcU) 
                                                  | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                     >> 0x14U))))));
        bufp->chgBit(oldp+650,((0x30200073U == ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                 << 0xcU) 
                                                | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                   >> 0x14U)))));
        bufp->chgBit(oldp+651,((0x6033U == (0xfe00707fU 
                                            & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                << 0xcU) 
                                               | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                  >> 0x14U))))));
        bufp->chgBit(oldp+652,((0x6013U == (0x707fU 
                                            & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                << 0xcU) 
                                               | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                  >> 0x14U))))));
        bufp->chgBit(oldp+653,((0x2006033U == (0xfe00707fU 
                                               & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                   << 0xcU) 
                                                  | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                     >> 0x14U))))));
        bufp->chgBit(oldp+654,((0x2007033U == (0xfe00707fU 
                                               & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                   << 0xcU) 
                                                  | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                     >> 0x14U))))));
        bufp->chgBit(oldp+655,((0x23U == (0x707fU & 
                                          ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                            << 0xcU) 
                                           | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                              >> 0x14U))))));
        bufp->chgBit(oldp+656,((0x1023U == (0x707fU 
                                            & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                << 0xcU) 
                                               | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                  >> 0x14U))))));
        bufp->chgBit(oldp+657,((0x1033U == (0xfe00707fU 
                                            & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                << 0xcU) 
                                               | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                  >> 0x14U))))));
        bufp->chgBit(oldp+658,((0x1013U == (0xfc00707fU 
                                            & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                << 0xcU) 
                                               | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                  >> 0x14U))))));
        bufp->chgBit(oldp+659,((0x2033U == (0xfe00707fU 
                                            & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                << 0xcU) 
                                               | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                  >> 0x14U))))));
        bufp->chgBit(oldp+660,((0x2013U == (0x707fU 
                                            & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                << 0xcU) 
                                               | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                  >> 0x14U))))));
        bufp->chgBit(oldp+661,((0x3013U == (0x707fU 
                                            & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                << 0xcU) 
                                               | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                  >> 0x14U))))));
        bufp->chgBit(oldp+662,((0x3033U == (0xfe00707fU 
                                            & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                << 0xcU) 
                                               | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                  >> 0x14U))))));
        bufp->chgBit(oldp+663,((0x40005033U == (0xfe00707fU 
                                                & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                    << 0xcU) 
                                                   | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                      >> 0x14U))))));
        bufp->chgBit(oldp+664,((0x40005013U == (0xfc00707fU 
                                                & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                    << 0xcU) 
                                                   | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                      >> 0x14U))))));
        bufp->chgBit(oldp+665,((0x5033U == (0xfe00707fU 
                                            & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                << 0xcU) 
                                               | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                  >> 0x14U))))));
        bufp->chgBit(oldp+666,((0x5013U == (0xfc00707fU 
                                            & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                << 0xcU) 
                                               | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                  >> 0x14U))))));
        bufp->chgBit(oldp+667,((0x40000033U == (0xfe00707fU 
                                                & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                    << 0xcU) 
                                                   | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                      >> 0x14U))))));
        bufp->chgBit(oldp+668,((0x2023U == (0x707fU 
                                            & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                << 0xcU) 
                                               | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                  >> 0x14U))))));
        bufp->chgBit(oldp+669,((0x10500073U == ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                 << 0xcU) 
                                                | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                   >> 0x14U)))));
        bufp->chgBit(oldp+670,((0x4033U == (0xfe00707fU 
                                            & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                << 0xcU) 
                                               | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                  >> 0x14U))))));
        bufp->chgBit(oldp+671,((0x4013U == (0x707fU 
                                            & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                << 0xcU) 
                                               | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                  >> 0x14U))))));
        bufp->chgBit(oldp+672,(vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__is_B));
        bufp->chgBit(oldp+673,(vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__is_I));
        bufp->chgBit(oldp+674,(vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__is_R));
        bufp->chgBit(oldp+675,(vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__is_S));
        bufp->chgBit(oldp+676,(vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__is_U));
        bufp->chgBit(oldp+677,(vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__is_CSR));
        bufp->chgBit(oldp+678,(((0x33U == (0xfe00707fU 
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
                                      | ((0x7013U == 
                                          (0x707fU 
                                           & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                               << 0xcU) 
                                              | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                 >> 0x14U)))) 
                                         | ((0x17U 
                                             == (0x7fU 
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
                                                                     >> 0x14U))))))))))))))));
        bufp->chgBit(oldp+679,(((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT____VdfgRegularize_h2cfc3394_0_9) 
                                | ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT____VdfgRegularize_h2cfc3394_0_25) 
                                   | (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT____VdfgRegularize_h2cfc3394_0_24)))));
        bufp->chgBit(oldp+680,(((0x2033U == (0xfe00707fU 
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
                                      | (0x3033U == 
                                         (0xfe00707fU 
                                          & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                              << 0xcU) 
                                             | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                >> 0x14U)))))))));
        bufp->chgBit(oldp+681,(((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT____VdfgRegularize_h2cfc3394_0_26) 
                                | ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT____VdfgRegularize_h2cfc3394_0_23) 
                                   | ((0x100073U == 
                                       ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                         << 0xcU) | 
                                        (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                         >> 0x14U))) 
                                      | ((0x73U == 
                                          ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                            << 0xcU) 
                                           | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                              >> 0x14U))) 
                                         | ((0xfU == 
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
                                                                     >> 0x14U))))))))))))))));
        bufp->chgBit(oldp+682,(((0x6fU == (0x7fU & 
                                           (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                            >> 0x14U))) 
                                | (0x67U == (0x707fU 
                                             & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                 << 0xcU) 
                                                | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                   >> 0x14U)))))));
        bufp->chgBit(oldp+683,(((3U == (0x707fU & (
                                                   (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
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
                                      | ((0x5003U == 
                                          (0x707fU 
                                           & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                               << 0xcU) 
                                              | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                 >> 0x14U)))) 
                                         | ((0x2003U 
                                             == (0x707fU 
                                                 & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                     << 0xcU) 
                                                    | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                       >> 0x14U)))) 
                                            | (IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_3_0))))))));
        bufp->chgBit(oldp+684,(vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__is_FPU));
        bufp->chgBit(oldp+685,(((0x2007U == (0x707fU 
                                             & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                 << 0xcU) 
                                                | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                   >> 0x14U)))) 
                                | (0x2027U == (0x707fU 
                                               & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                   << 0xcU) 
                                                  | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                     >> 0x14U)))))));
        bufp->chgBit(oldp+686,(vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__RD_bank));
        bufp->chgBit(oldp+687,(vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__RS1_bank));
        bufp->chgBit(oldp+688,(vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__RS2_bank));
        bufp->chgCData(oldp+689,(vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__alu_operation),4);
        bufp->chgCData(oldp+690,(((0x17U == (0x7fU 
                                             & (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                >> 0x14U)))
                                   ? 8U : ((0x6fU == 
                                            (0x7fU 
                                             & (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                >> 0x14U)))
                                            ? 8U : 
                                           ((0x37U 
                                             == (0x7fU 
                                                 & (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                    >> 0x14U)))
                                             ? 0x10U
                                             : 2U)))),5);
        bufp->chgCData(oldp+691,(vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__alu_operand2),5);
        bufp->chgBit(oldp+692,(((0x2007U == (0x707fU 
                                             & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                 << 0xcU) 
                                                | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                   >> 0x14U)))) 
                                | ((3U == (0x707fU 
                                           & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                               << 0xcU) 
                                              | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                 >> 0x14U)))) 
                                   | ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT____VdfgRegularize_h2cfc3394_0_20) 
                                      | (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT____VdfgRegularize_h2cfc3394_0_19))))));
        bufp->chgCData(oldp+693,(vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__memory_width),2);
        bufp->chgBit(oldp+694,(((3U == (0x707fU & (
                                                   (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                    << 0xcU) 
                                                   | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                      >> 0x14U)))) 
                                | (0x1003U == (0x707fU 
                                               & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                   << 0xcU) 
                                                  | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                     >> 0x14U)))))));
        bufp->chgBit(oldp+695,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT____Vcellinp__df__rst));
        bufp->chgWData(oldp+696,(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data),117);
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[9U]))) {
        bufp->chgIData(oldp+700,(vlSelfRef.CPU_top__DOT__cpu__DOT__forward__DOT__rs1),32);
        bufp->chgIData(oldp+701,(vlSelfRef.CPU_top__DOT__cpu__DOT__forward__DOT__rs2),32);
        bufp->chgIData(oldp+702,(vlSelfRef.CPU_top__DOT__cpu__DOT__forward__DOT__rs3),32);
        bufp->chgIData(oldp+703,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__alu_operand1),32);
        bufp->chgIData(oldp+704,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__alu_operand2),32);
        bufp->chgIData(oldp+705,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__alu_signed_sum_result),32);
        bufp->chgBit(oldp+706,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__alu_compare_result));
        bufp->chgIData(oldp+707,((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__alu_operand1 
                                  - vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__alu_operand2)),32);
        bufp->chgIData(oldp+708,((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__alu_operand1 
                                  & vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__alu_operand2)),32);
        bufp->chgIData(oldp+709,((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__alu_operand1 
                                  | vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__alu_operand2)),32);
        bufp->chgIData(oldp+710,((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__alu_operand1 
                                  ^ vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__alu_operand2)),32);
        bufp->chgIData(oldp+711,((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__alu_operand1 
                                  << (0x1fU & vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__alu_operand2))),32);
        bufp->chgIData(oldp+712,((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__alu_operand1 
                                  >> (0x1fU & vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__alu_operand2))),32);
        bufp->chgIData(oldp+713,(VL_SHIFTRS_III(32,32,5, vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__alu_operand1, 
                                                (0x1fU 
                                                 & vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__alu_operand2))),32);
        bufp->chgBit(oldp+714,(VL_LTS_III(32, vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__alu_operand1, vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__alu_operand2)));
        bufp->chgBit(oldp+715,((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__alu_operand1 
                                < vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__alu_operand2)));
        bufp->chgBit(oldp+716,((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__alu_operand1 
                                == vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__alu_operand2)));
        bufp->chgBit(oldp+717,((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__alu_operand1 
                                != vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__alu_operand2)));
        bufp->chgBit(oldp+718,(VL_GTES_III(32, vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__alu_operand1, vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__alu_operand2)));
        bufp->chgBit(oldp+719,((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__alu_operand1 
                                >= vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__alu_operand2)));
        bufp->chgBit(oldp+720,((vlSelfRef.CPU_top__DOT__cpu__DOT__forward__DOT__rs1 
                                >> 0x1fU)));
        bufp->chgBit(oldp+721,((vlSelfRef.CPU_top__DOT__cpu__DOT__forward__DOT__rs2 
                                >> 0x1fU)));
        bufp->chgCData(oldp+722,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__s),2);
    }
    bufp->chgBit(oldp+723,(vlSelfRef.reset));
    bufp->chgBit(oldp+724,(vlSelfRef.clock));
    bufp->chgBit(oldp+725,(vlSelfRef.timer_interrupt));
    bufp->chgBit(oldp+726,(vlSelfRef.external_interrupt));
    bufp->chgBit(oldp+727,(vlSelfRef.bus_rw));
    bufp->chgBit(oldp+728,(vlSelfRef.bus_request));
    bufp->chgBit(oldp+729,(vlSelfRef.bus_ready));
    bufp->chgIData(oldp+730,(vlSelfRef.bus_address),32);
    bufp->chgIData(oldp+731,(vlSelfRef.bus_rdata),32);
    bufp->chgIData(oldp+732,(vlSelfRef.bus_wdata),32);
    bufp->chgBit(oldp+733,(vlSelfRef.cpu_fault));
    bufp->chgBit(oldp+734,(((IData)(vlSelfRef.CPU_top__DOT__cpu_ibus_request) 
                            & ((1U == (IData)(vlSelfRef.CPU_top__DOT__bus__DOT__state)) 
                               & (IData)(vlSelfRef.bus_ready)))));
    bufp->chgIData(oldp+735,(((0U == (0xfU & (vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[0U] 
                                              >> 0x14U)))
                               ? vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__alu_signed_sum_result
                               : ((1U == (0xfU & (vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[0U] 
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
                                           : ((4U == 
                                               (0xfU 
                                                & (vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[0U] 
                                                   >> 0x14U)))
                                               ? (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__alu_operand1 
                                                  | vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__alu_operand2)
                                               : ((5U 
                                                   == 
                                                   (0xfU 
                                                    & (vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[0U] 
                                                       >> 0x14U)))
                                                   ? 
                                                  (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__alu_operand1 
                                                   ^ vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__alu_operand2)
                                                   : 0U))))))),32);
    bufp->chgIData(oldp+736,(((6U == (0xfU & (vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[0U] 
                                              >> 0x14U)))
                               ? (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__alu_operand1 
                                  << (0x1fU & vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__alu_operand2))
                               : ((7U == (0xfU & (vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[0U] 
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
    bufp->chgBit(oldp+737,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__div_ready));
    bufp->chgIData(oldp+738,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__div_result),32);
    bufp->chgIData(oldp+739,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__div_remainder),32);
    bufp->chgIData(oldp+740,((((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__div_signed) 
                               & (vlSelfRef.CPU_top__DOT__cpu__DOT__forward__DOT__rs1 
                                  >> 0x1fU)) ? (- vlSelfRef.CPU_top__DOT__cpu__DOT__forward__DOT__rs1)
                               : vlSelfRef.CPU_top__DOT__cpu__DOT__forward__DOT__rs1)),32);
    bufp->chgIData(oldp+741,((((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__div_signed) 
                               & (vlSelfRef.CPU_top__DOT__cpu__DOT__forward__DOT__rs2 
                                  >> 0x1fU)) ? (- vlSelfRef.CPU_top__DOT__cpu__DOT__forward__DOT__rs2)
                               : vlSelfRef.CPU_top__DOT__cpu__DOT__forward__DOT__rs2)),32);
    bufp->chgIData(oldp+742,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__quotient
                             [0x20U]),32);
    bufp->chgBit(oldp+743,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__ack));
}

void VCPU_top___024root__trace_cleanup(void* voidSelf, VerilatedFst* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCPU_top___024root__trace_cleanup\n"); );
    // Init
    VCPU_top___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VCPU_top___024root*>(voidSelf);
    VCPU_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[2U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[3U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[4U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[5U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[6U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[7U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[8U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[9U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[0xaU] = 0U;
}
