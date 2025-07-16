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
    if (VL_UNLIKELY((((((((vlSelfRef.__Vm_traceActivity
                           [1U] | vlSelfRef.__Vm_traceActivity
                           [2U]) | vlSelfRef.__Vm_traceActivity
                          [3U]) | vlSelfRef.__Vm_traceActivity
                         [4U]) | vlSelfRef.__Vm_traceActivity
                        [6U]) | vlSelfRef.__Vm_traceActivity
                       [7U]) | vlSelfRef.__Vm_traceActivity
                      [8U])))) {
        bufp->chgBit(oldp+0,((1U & ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__0__KET____DOT__q)
                                     ? ((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                         [0U] >> 0x1fU) 
                                        - vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                        [0U]) : (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                                 [0U] 
                                                 >> 0x1fU)))));
        bufp->chgQData(oldp+1,((0x1ffffffffULL & VL_SHIFTR_QQI(33,33,32, 
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
        bufp->chgSData(oldp+3,((0x7ffU & ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__10__KET____DOT__q)
                                           ? ((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                               [0xaU] 
                                               >> 0x15U) 
                                              - vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                              [0xaU])
                                           : (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                              [0xaU] 
                                              >> 0x15U)))),11);
        bufp->chgQData(oldp+4,((0x7ffffffffffULL & 
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
        bufp->chgSData(oldp+6,((0x7fffU & ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__14__KET____DOT__q)
                                            ? ((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                                [0xeU] 
                                                >> 0x11U) 
                                               - vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                               [0xeU])
                                            : (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                               [0xeU] 
                                               >> 0x11U)))),15);
        bufp->chgQData(oldp+7,((0x7fffffffffffULL & 
                                VL_SHIFTR_QQI(47,47,32, 
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
        bufp->chgIData(oldp+9,((0x7ffffU & ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__18__KET____DOT__q)
                                             ? ((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                                 [0x12U] 
                                                 >> 0xdU) 
                                                - vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                                [0x12U])
                                             : (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                                [0x12U] 
                                                >> 0xdU)))),19);
        bufp->chgQData(oldp+10,((0x7ffffffffffffULL 
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
        bufp->chgIData(oldp+12,((0x7fffffU & ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__22__KET____DOT__q)
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
        bufp->chgQData(oldp+13,((0x7fffffffffffffULL 
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
        bufp->chgIData(oldp+15,((0x7ffffffU & ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__26__KET____DOT__q)
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
        bufp->chgQData(oldp+16,((0x7ffffffffffffffULL 
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
        bufp->chgIData(oldp+18,((0x3fffffffU & ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__29__KET____DOT__q)
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
        bufp->chgQData(oldp+19,((0x3fffffffffffffffULL 
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
        bufp->chgCData(oldp+21,((7U & ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__2__KET____DOT__q)
                                        ? ((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                            [2U] >> 0x1dU) 
                                           - vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                           [2U]) : 
                                       (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                        [2U] >> 0x1dU)))),3);
        bufp->chgQData(oldp+22,((0x7ffffffffULL & VL_SHIFTR_QQI(35,35,32, 
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
        bufp->chgIData(oldp+24,(((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__31__KET____DOT__q)
                                  ? (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                     [0x1fU] - vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                     [0x1fU]) : vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                 [0x1fU])),32);
        bufp->chgQData(oldp+25,(VL_SHIFTR_QQI(64,64,32, 
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
        bufp->chgCData(oldp+27,((0x7fU & ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__6__KET____DOT__q)
                                           ? ((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                               [6U] 
                                               >> 0x19U) 
                                              - vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                              [6U])
                                           : (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                              [6U] 
                                              >> 0x19U)))),7);
        bufp->chgQData(oldp+28,((0x7fffffffffULL & 
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
    if (VL_UNLIKELY((((((vlSelfRef.__Vm_traceActivity
                         [1U] | vlSelfRef.__Vm_traceActivity
                         [2U]) | vlSelfRef.__Vm_traceActivity
                        [4U]) | vlSelfRef.__Vm_traceActivity
                       [6U]) | vlSelfRef.__Vm_traceActivity
                      [7U])))) {
        bufp->chgSData(oldp+30,((0xfffU & ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__11__KET____DOT__q)
                                            ? ((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                                [0xbU] 
                                                >> 0x14U) 
                                               - vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                               [0xbU])
                                            : (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                               [0xbU] 
                                               >> 0x14U)))),12);
        bufp->chgQData(oldp+31,((0xfffffffffffULL & 
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
        bufp->chgSData(oldp+33,((0x1fffU & ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__12__KET____DOT__q)
                                             ? ((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                                 [0xcU] 
                                                 >> 0x13U) 
                                                - vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                                [0xcU])
                                             : (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                                [0xcU] 
                                                >> 0x13U)))),13);
        bufp->chgQData(oldp+34,((0x1fffffffffffULL 
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
        bufp->chgSData(oldp+36,((0x3fffU & ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__13__KET____DOT__q)
                                             ? ((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                                 [0xdU] 
                                                 >> 0x12U) 
                                                - vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                                [0xdU])
                                             : (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                                [0xdU] 
                                                >> 0x12U)))),14);
        bufp->chgQData(oldp+37,((0x3fffffffffffULL 
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
        bufp->chgSData(oldp+39,((0xffffU & ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__15__KET____DOT__q)
                                             ? ((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                                 [0xfU] 
                                                 >> 0x10U) 
                                                - vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                                [0xfU])
                                             : (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                                [0xfU] 
                                                >> 0x10U)))),16);
        bufp->chgQData(oldp+40,((0xffffffffffffULL 
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
        bufp->chgIData(oldp+42,((0x1ffffU & ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__16__KET____DOT__q)
                                              ? ((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                                  [0x10U] 
                                                  >> 0xfU) 
                                                 - 
                                                 vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                                 [0x10U])
                                              : (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                                 [0x10U] 
                                                 >> 0xfU)))),17);
        bufp->chgQData(oldp+43,((0x1ffffffffffffULL 
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
        bufp->chgIData(oldp+45,((0x3ffffU & ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__17__KET____DOT__q)
                                              ? ((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                                  [0x11U] 
                                                  >> 0xeU) 
                                                 - 
                                                 vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                                 [0x11U])
                                              : (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                                 [0x11U] 
                                                 >> 0xeU)))),18);
        bufp->chgQData(oldp+46,((0x3ffffffffffffULL 
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
        bufp->chgIData(oldp+48,((0xfffffU & ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__19__KET____DOT__q)
                                              ? ((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                                  [0x13U] 
                                                  >> 0xcU) 
                                                 - 
                                                 vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                                 [0x13U])
                                              : (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                                 [0x13U] 
                                                 >> 0xcU)))),20);
        bufp->chgQData(oldp+49,((0xfffffffffffffULL 
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
        bufp->chgCData(oldp+51,((3U & ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__1__KET____DOT__q)
                                        ? ((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                            [1U] >> 0x1eU) 
                                           - vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                           [1U]) : 
                                       (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                        [1U] >> 0x1eU)))),2);
        bufp->chgQData(oldp+52,((0x3ffffffffULL & VL_SHIFTR_QQI(34,34,32, 
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
        bufp->chgIData(oldp+54,((0x1fffffU & ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__20__KET____DOT__q)
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
        bufp->chgQData(oldp+55,((0x1fffffffffffffULL 
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
        bufp->chgIData(oldp+57,((0x3fffffU & ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__21__KET____DOT__q)
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
        bufp->chgQData(oldp+58,((0x3fffffffffffffULL 
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
        bufp->chgIData(oldp+60,((0xffffffU & ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__23__KET____DOT__q)
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
        bufp->chgQData(oldp+61,((0xffffffffffffffULL 
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
        bufp->chgIData(oldp+63,((0x1ffffffU & ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__24__KET____DOT__q)
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
        bufp->chgQData(oldp+64,((0x1ffffffffffffffULL 
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
        bufp->chgIData(oldp+66,((0x3ffffffU & ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__25__KET____DOT__q)
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
        bufp->chgQData(oldp+67,((0x3ffffffffffffffULL 
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
        bufp->chgIData(oldp+69,((0xfffffffU & ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__27__KET____DOT__q)
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
        bufp->chgQData(oldp+70,((0xfffffffffffffffULL 
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
        bufp->chgIData(oldp+72,((0x1fffffffU & ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__28__KET____DOT__q)
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
        bufp->chgQData(oldp+73,((0x1fffffffffffffffULL 
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
        bufp->chgIData(oldp+75,((0x7fffffffU & ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__30__KET____DOT__q)
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
        bufp->chgQData(oldp+76,((0x7fffffffffffffffULL 
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
        bufp->chgCData(oldp+78,((0xfU & ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__3__KET____DOT__q)
                                          ? ((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                              [3U] 
                                              >> 0x1cU) 
                                             - vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                             [3U]) : 
                                         (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                          [3U] >> 0x1cU)))),4);
        bufp->chgQData(oldp+79,((0xfffffffffULL & VL_SHIFTR_QQI(36,36,32, 
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
        bufp->chgCData(oldp+81,((0x1fU & ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__4__KET____DOT__q)
                                           ? ((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                               [4U] 
                                               >> 0x1bU) 
                                              - vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                              [4U])
                                           : (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                              [4U] 
                                              >> 0x1bU)))),5);
        bufp->chgQData(oldp+82,((0x1fffffffffULL & 
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
        bufp->chgCData(oldp+84,((0x3fU & ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__5__KET____DOT__q)
                                           ? ((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                               [5U] 
                                               >> 0x1aU) 
                                              - vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                              [5U])
                                           : (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                              [5U] 
                                              >> 0x1aU)))),6);
        bufp->chgQData(oldp+85,((0x3fffffffffULL & 
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
        bufp->chgCData(oldp+87,((0xffU & ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__7__KET____DOT__q)
                                           ? ((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                               [7U] 
                                               >> 0x18U) 
                                              - vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                              [7U])
                                           : (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                              [7U] 
                                              >> 0x18U)))),8);
        bufp->chgQData(oldp+88,((0xffffffffffULL & 
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
        bufp->chgSData(oldp+90,((0x1ffU & ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__8__KET____DOT__q)
                                            ? ((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                                [8U] 
                                                >> 0x17U) 
                                               - vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                               [8U])
                                            : (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                               [8U] 
                                               >> 0x17U)))),9);
        bufp->chgQData(oldp+91,((0x1ffffffffffULL & 
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
        bufp->chgSData(oldp+93,((0x3ffU & ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__9__KET____DOT__q)
                                            ? ((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                                [9U] 
                                                >> 0x16U) 
                                               - vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                               [9U])
                                            : (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                               [9U] 
                                               >> 0x16U)))),10);
        bufp->chgQData(oldp+94,((0x3ffffffffffULL & 
                                 VL_SHIFTR_QQI(42,42,32, 
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
                       [1U] | vlSelfRef.__Vm_traceActivity
                       [6U]) | vlSelfRef.__Vm_traceActivity
                      [7U])))) {
        bufp->chgBit(oldp+96,((1U & vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                               [0U])));
        bufp->chgSData(oldp+97,((0x7ffU & vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                 [0xaU])),11);
        bufp->chgSData(oldp+98,((0xfffU & vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                 [0xbU])),12);
        bufp->chgSData(oldp+99,((0x1fffU & vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                 [0xcU])),13);
        bufp->chgSData(oldp+100,((0x3fffU & vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                  [0xdU])),14);
        bufp->chgSData(oldp+101,((0x7fffU & vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                  [0xeU])),15);
        bufp->chgSData(oldp+102,((0xffffU & vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                  [0xfU])),16);
        bufp->chgIData(oldp+103,((0x1ffffU & vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                  [0x10U])),17);
        bufp->chgIData(oldp+104,((0x3ffffU & vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                  [0x11U])),18);
        bufp->chgIData(oldp+105,((0x7ffffU & vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                  [0x12U])),19);
        bufp->chgIData(oldp+106,((0xfffffU & vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                  [0x13U])),20);
        bufp->chgCData(oldp+107,((3U & vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                  [1U])),2);
        bufp->chgIData(oldp+108,((0x1fffffU & vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                  [0x14U])),21);
        bufp->chgIData(oldp+109,((0x3fffffU & vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                  [0x15U])),22);
        bufp->chgIData(oldp+110,((0x7fffffU & vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                  [0x16U])),23);
        bufp->chgIData(oldp+111,((0xffffffU & vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                  [0x17U])),24);
        bufp->chgIData(oldp+112,((0x1ffffffU & vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                  [0x18U])),25);
        bufp->chgIData(oldp+113,((0x3ffffffU & vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                  [0x19U])),26);
        bufp->chgIData(oldp+114,((0x7ffffffU & vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                  [0x1aU])),27);
        bufp->chgIData(oldp+115,((0xfffffffU & vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                  [0x1bU])),28);
        bufp->chgIData(oldp+116,((0x1fffffffU & vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                  [0x1cU])),29);
        bufp->chgIData(oldp+117,((0x3fffffffU & vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                  [0x1dU])),30);
        bufp->chgCData(oldp+118,((7U & vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                  [2U])),3);
        bufp->chgIData(oldp+119,((0x7fffffffU & vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                  [0x1eU])),31);
        bufp->chgIData(oldp+120,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                 [0x1fU]),32);
        bufp->chgCData(oldp+121,((0xfU & vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                  [3U])),4);
        bufp->chgCData(oldp+122,((0x1fU & vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                  [4U])),5);
        bufp->chgCData(oldp+123,((0x3fU & vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                  [5U])),6);
        bufp->chgCData(oldp+124,((0x7fU & vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                  [6U])),7);
        bufp->chgCData(oldp+125,((0xffU & vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                  [7U])),8);
        bufp->chgSData(oldp+126,((0x1ffU & vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                  [8U])),9);
        bufp->chgSData(oldp+127,((0x3ffU & vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor
                                  [9U])),10);
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[2U]))) {
        bufp->chgBit(oldp+128,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__11__KET____DOT__q));
        bufp->chgBit(oldp+129,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__12__KET____DOT__q));
        bufp->chgBit(oldp+130,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__13__KET____DOT__q));
        bufp->chgBit(oldp+131,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__15__KET____DOT__q));
        bufp->chgBit(oldp+132,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__16__KET____DOT__q));
        bufp->chgBit(oldp+133,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__17__KET____DOT__q));
        bufp->chgBit(oldp+134,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__19__KET____DOT__q));
        bufp->chgBit(oldp+135,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__1__KET____DOT__q));
        bufp->chgBit(oldp+136,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__20__KET____DOT__q));
        bufp->chgBit(oldp+137,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__21__KET____DOT__q));
        bufp->chgBit(oldp+138,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__23__KET____DOT__q));
        bufp->chgBit(oldp+139,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__24__KET____DOT__q));
        bufp->chgBit(oldp+140,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__25__KET____DOT__q));
        bufp->chgBit(oldp+141,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__27__KET____DOT__q));
        bufp->chgBit(oldp+142,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__28__KET____DOT__q));
        bufp->chgBit(oldp+143,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__30__KET____DOT__q));
        bufp->chgBit(oldp+144,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__3__KET____DOT__q));
        bufp->chgBit(oldp+145,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__4__KET____DOT__q));
        bufp->chgBit(oldp+146,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__5__KET____DOT__q));
        bufp->chgBit(oldp+147,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__7__KET____DOT__q));
        bufp->chgBit(oldp+148,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__8__KET____DOT__q));
        bufp->chgBit(oldp+149,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__9__KET____DOT__q));
    }
    if (VL_UNLIKELY((((vlSelfRef.__Vm_traceActivity
                       [2U] | vlSelfRef.__Vm_traceActivity
                       [4U]) | vlSelfRef.__Vm_traceActivity
                      [6U])))) {
        bufp->chgIData(oldp+150,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                 [0x20U]),32);
        bufp->chgBit(oldp+151,((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                [0U] >> 0x1fU)));
        bufp->chgIData(oldp+152,(VL_SHIFTL_III(32,32,32, 
                                               vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                               [0U], 1U)),32);
        bufp->chgSData(oldp+153,((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                  [0xaU] >> 0x15U)),11);
        bufp->chgIData(oldp+154,(VL_SHIFTL_III(32,32,32, 
                                               vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                               [0xaU], 0xbU)),32);
        bufp->chgSData(oldp+155,((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                  [0xbU] >> 0x14U)),12);
        bufp->chgIData(oldp+156,(VL_SHIFTL_III(32,32,32, 
                                               vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                               [0xbU], 0xcU)),32);
        bufp->chgSData(oldp+157,((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                  [0xcU] >> 0x13U)),13);
        bufp->chgIData(oldp+158,(VL_SHIFTL_III(32,32,32, 
                                               vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                               [0xcU], 0xdU)),32);
        bufp->chgSData(oldp+159,((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                  [0xdU] >> 0x12U)),14);
        bufp->chgIData(oldp+160,(VL_SHIFTL_III(32,32,32, 
                                               vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                               [0xdU], 0xeU)),32);
        bufp->chgSData(oldp+161,((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                  [0xeU] >> 0x11U)),15);
        bufp->chgIData(oldp+162,(VL_SHIFTL_III(32,32,32, 
                                               vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                               [0xeU], 0xfU)),32);
        bufp->chgSData(oldp+163,((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                  [0xfU] >> 0x10U)),16);
        bufp->chgIData(oldp+164,(VL_SHIFTL_III(32,32,32, 
                                               vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                               [0xfU], 0x10U)),32);
        bufp->chgIData(oldp+165,((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                  [0x10U] >> 0xfU)),17);
        bufp->chgIData(oldp+166,(VL_SHIFTL_III(32,32,32, 
                                               vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                               [0x10U], 0x11U)),32);
        bufp->chgIData(oldp+167,((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                  [0x11U] >> 0xeU)),18);
        bufp->chgIData(oldp+168,(VL_SHIFTL_III(32,32,32, 
                                               vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                               [0x11U], 0x12U)),32);
        bufp->chgIData(oldp+169,((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                  [0x12U] >> 0xdU)),19);
        bufp->chgIData(oldp+170,(VL_SHIFTL_III(32,32,32, 
                                               vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                               [0x12U], 0x13U)),32);
        bufp->chgIData(oldp+171,((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                  [0x13U] >> 0xcU)),20);
        bufp->chgIData(oldp+172,(VL_SHIFTL_III(32,32,32, 
                                               vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                               [0x13U], 0x14U)),32);
        bufp->chgCData(oldp+173,((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                  [1U] >> 0x1eU)),2);
        bufp->chgIData(oldp+174,(VL_SHIFTL_III(32,32,32, 
                                               vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                               [1U], 2U)),32);
        bufp->chgIData(oldp+175,((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                  [0x14U] >> 0xbU)),21);
        bufp->chgIData(oldp+176,(VL_SHIFTL_III(32,32,32, 
                                               vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                               [0x14U], 0x15U)),32);
        bufp->chgIData(oldp+177,((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                  [0x15U] >> 0xaU)),22);
        bufp->chgIData(oldp+178,(VL_SHIFTL_III(32,32,32, 
                                               vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                               [0x15U], 0x16U)),32);
        bufp->chgIData(oldp+179,((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                  [0x16U] >> 9U)),23);
        bufp->chgIData(oldp+180,(VL_SHIFTL_III(32,32,32, 
                                               vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                               [0x16U], 0x17U)),32);
        bufp->chgIData(oldp+181,((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                  [0x17U] >> 8U)),24);
        bufp->chgIData(oldp+182,(VL_SHIFTL_III(32,32,32, 
                                               vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                               [0x17U], 0x18U)),32);
        bufp->chgIData(oldp+183,((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                  [0x18U] >> 7U)),25);
        bufp->chgIData(oldp+184,(VL_SHIFTL_III(32,32,32, 
                                               vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                               [0x18U], 0x19U)),32);
        bufp->chgIData(oldp+185,((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                  [0x19U] >> 6U)),26);
        bufp->chgIData(oldp+186,(VL_SHIFTL_III(32,32,32, 
                                               vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                               [0x19U], 0x1aU)),32);
        bufp->chgIData(oldp+187,((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                  [0x1aU] >> 5U)),27);
        bufp->chgIData(oldp+188,(VL_SHIFTL_III(32,32,32, 
                                               vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                               [0x1aU], 0x1bU)),32);
        bufp->chgIData(oldp+189,((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                  [0x1bU] >> 4U)),28);
        bufp->chgIData(oldp+190,(VL_SHIFTL_III(32,32,32, 
                                               vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                               [0x1bU], 0x1cU)),32);
        bufp->chgIData(oldp+191,((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                  [0x1cU] >> 3U)),29);
        bufp->chgIData(oldp+192,(VL_SHIFTL_III(32,32,32, 
                                               vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                               [0x1cU], 0x1dU)),32);
        bufp->chgIData(oldp+193,((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                  [0x1dU] >> 2U)),30);
        bufp->chgIData(oldp+194,(VL_SHIFTL_III(32,32,32, 
                                               vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                               [0x1dU], 0x1eU)),32);
        bufp->chgCData(oldp+195,((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                  [2U] >> 0x1dU)),3);
        bufp->chgIData(oldp+196,(VL_SHIFTL_III(32,32,32, 
                                               vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                               [2U], 3U)),32);
        bufp->chgIData(oldp+197,((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                  [0x1eU] >> 1U)),31);
        bufp->chgIData(oldp+198,(VL_SHIFTL_III(32,32,32, 
                                               vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                               [0x1eU], 0x1fU)),32);
        bufp->chgIData(oldp+199,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                 [0x1fU]),32);
        bufp->chgCData(oldp+200,((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                  [3U] >> 0x1cU)),4);
        bufp->chgIData(oldp+201,(VL_SHIFTL_III(32,32,32, 
                                               vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                               [3U], 4U)),32);
        bufp->chgCData(oldp+202,((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                  [4U] >> 0x1bU)),5);
        bufp->chgIData(oldp+203,(VL_SHIFTL_III(32,32,32, 
                                               vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                               [4U], 5U)),32);
        bufp->chgCData(oldp+204,((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                  [5U] >> 0x1aU)),6);
        bufp->chgIData(oldp+205,(VL_SHIFTL_III(32,32,32, 
                                               vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                               [5U], 6U)),32);
        bufp->chgCData(oldp+206,((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                  [6U] >> 0x19U)),7);
        bufp->chgIData(oldp+207,(VL_SHIFTL_III(32,32,32, 
                                               vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                               [6U], 7U)),32);
        bufp->chgCData(oldp+208,((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                  [7U] >> 0x18U)),8);
        bufp->chgIData(oldp+209,(VL_SHIFTL_III(32,32,32, 
                                               vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                               [7U], 8U)),32);
        bufp->chgSData(oldp+210,((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                  [8U] >> 0x17U)),9);
        bufp->chgIData(oldp+211,(VL_SHIFTL_III(32,32,32, 
                                               vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                               [8U], 9U)),32);
        bufp->chgSData(oldp+212,((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                  [9U] >> 0x16U)),10);
        bufp->chgIData(oldp+213,(VL_SHIFTL_III(32,32,32, 
                                               vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend
                                               [9U], 0xaU)),32);
    }
    if (VL_UNLIKELY(((vlSelfRef.__Vm_traceActivity[3U] 
                      | vlSelfRef.__Vm_traceActivity
                      [8U])))) {
        bufp->chgBit(oldp+214,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__0__KET____DOT__q));
        bufp->chgBit(oldp+215,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__10__KET____DOT__q));
        bufp->chgBit(oldp+216,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__14__KET____DOT__q));
        bufp->chgBit(oldp+217,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__18__KET____DOT__q));
        bufp->chgBit(oldp+218,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__22__KET____DOT__q));
        bufp->chgBit(oldp+219,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__26__KET____DOT__q));
        bufp->chgBit(oldp+220,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__29__KET____DOT__q));
        bufp->chgBit(oldp+221,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__2__KET____DOT__q));
        bufp->chgBit(oldp+222,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__31__KET____DOT__q));
        bufp->chgBit(oldp+223,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__6__KET____DOT__q));
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[4U]))) {
        bufp->chgBit(oldp+224,(vlSelfRef.CPU_top__DOT__cpu_ibus_request));
        bufp->chgIData(oldp+225,(vlSelfRef.CPU_top__DOT__cpu_ibus_address),32);
        bufp->chgBit(oldp+226,(vlSelfRef.CPU_top__DOT__cpu_dbus_rw));
        bufp->chgBit(oldp+227,(vlSelfRef.CPU_top__DOT__cpu_dbus_request));
        bufp->chgIData(oldp+228,(vlSelfRef.CPU_top__DOT__cpu_dbus_address),32);
        bufp->chgIData(oldp+229,(vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__genblk1__DOT__dcache__DOT__wb__DOT__wb_data),32);
        bufp->chgCData(oldp+230,(vlSelfRef.CPU_top__DOT__bus__DOT__state),2);
        bufp->chgBit(oldp+231,(((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT____VdfgRegularize_h9a67d98d_0_0) 
                                & (vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[0U] 
                                   >> 0x1aU))));
        bufp->chgBit(oldp+232,(vlSelfRef.CPU_top__DOT__cpu__DOT__memory_busy));
        bufp->chgSData(oldp+233,((0xfffU & ((vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[1U] 
                                             << 2U) 
                                            | (vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[0U] 
                                               >> 0x1eU)))),12);
        bufp->chgIData(oldp+234,(vlSelfRef.CPU_top__DOT__cpu__DOT__csr_rdata),32);
        bufp->chgBit(oldp+235,(vlSelfRef.CPU_top__DOT__cpu__DOT__csr_wdata_wr));
        bufp->chgIData(oldp+236,(vlSelfRef.CPU_top__DOT__cpu__DOT__csr_wdata),32);
        bufp->chgIData(oldp+237,(vlSelfRef.CPU_top__DOT__cpu__DOT__csr__DOT__mepc),32);
        bufp->chgQData(oldp+238,(vlSelfRef.CPU_top__DOT__cpu__DOT__writeback__DOT__retired),64);
        bufp->chgBit(oldp+240,(vlSelfRef.CPU_top__DOT__cpu__DOT__csr_irq_pending));
        bufp->chgIData(oldp+241,(vlSelfRef.CPU_top__DOT__cpu__DOT__csr_irq_pc),32);
        bufp->chgBit(oldp+242,(vlSelfRef.CPU_top__DOT__cpu__DOT__csr_irq_dispatched));
        bufp->chgIData(oldp+243,(vlSelfRef.CPU_top__DOT__cpu__DOT__csr_irq_epc),32);
        bufp->chgBit(oldp+244,((1U & (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__data[3U] 
                                      >> 0x14U))));
        bufp->chgIData(oldp+245,(((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__data[3U] 
                                   << 0xcU) | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__data[2U] 
                                               >> 0x14U))),32);
        bufp->chgIData(oldp+246,(((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__data[2U] 
                                   << 0xcU) | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__data[1U] 
                                               >> 0x14U))),32);
        bufp->chgCData(oldp+247,((0x1fU & (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__data[1U] 
                                           >> 0xfU))),5);
        bufp->chgCData(oldp+248,((0x1fU & (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__data[1U] 
                                           >> 0xaU))),5);
        bufp->chgCData(oldp+249,((0x1fU & (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__data[1U] 
                                           >> 5U))),5);
        bufp->chgCData(oldp+250,((0x1fU & vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__data[1U])),5);
        bufp->chgIData(oldp+251,(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__data[0U]),32);
        bufp->chgBit(oldp+252,(vlSelfRef.CPU_top__DOT__cpu__DOT__decode_fault));
        bufp->chgBit(oldp+253,((1U & (vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[3U] 
                                      >> 0x15U))));
        bufp->chgIData(oldp+254,(((vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[3U] 
                                   << 0xbU) | (vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[2U] 
                                               >> 0x15U))),32);
        bufp->chgCData(oldp+255,((7U & (vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[2U] 
                                        >> 0x12U))),3);
        bufp->chgCData(oldp+256,((0x1fU & (vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[2U] 
                                           >> 0xdU))),5);
        bufp->chgCData(oldp+257,((0x1fU & (vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[2U] 
                                           >> 8U))),5);
        bufp->chgCData(oldp+258,((0x1fU & (vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[2U] 
                                           >> 3U))),5);
        bufp->chgCData(oldp+259,((0x1fU & ((vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[2U] 
                                            << 2U) 
                                           | (vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[1U] 
                                              >> 0x1eU)))),5);
        bufp->chgIData(oldp+260,(((vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[1U] 
                                   << 2U) | (vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[0U] 
                                             >> 0x1eU))),32);
        bufp->chgBit(oldp+261,((1U & (vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[0U] 
                                      >> 0x1dU))));
        bufp->chgBit(oldp+262,((1U & (vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[0U] 
                                      >> 0x1cU))));
        bufp->chgBit(oldp+263,((1U & (vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[0U] 
                                      >> 0x1bU))));
        bufp->chgBit(oldp+264,((1U & (vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[0U] 
                                      >> 0x1aU))));
        bufp->chgBit(oldp+265,((1U & (vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[0U] 
                                      >> 0x19U))));
        bufp->chgBit(oldp+266,((1U & (vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[0U] 
                                      >> 0x18U))));
        bufp->chgCData(oldp+267,((0xfU & (vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[0U] 
                                          >> 0x14U))),4);
        bufp->chgCData(oldp+268,((0x1fU & (vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[0U] 
                                           >> 0xfU))),5);
        bufp->chgCData(oldp+269,((0x1fU & (vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[0U] 
                                           >> 0xaU))),5);
        bufp->chgBit(oldp+270,((1U & (vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[0U] 
                                      >> 9U))));
        bufp->chgBit(oldp+271,((1U & (vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[0U] 
                                      >> 8U))));
        bufp->chgCData(oldp+272,((3U & (vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[0U] 
                                        >> 6U))),2);
        bufp->chgBit(oldp+273,((1U & (vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[0U] 
                                      >> 5U))));
        bufp->chgCData(oldp+274,((0x1fU & vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[0U])),5);
        bufp->chgBit(oldp+275,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute_fault));
        bufp->chgBit(oldp+276,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute_jump));
        bufp->chgIData(oldp+277,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute_jump_pc),32);
        bufp->chgBit(oldp+278,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute_ecall));
        bufp->chgBit(oldp+279,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute_mret));
        bufp->chgBit(oldp+280,((1U & (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__data[3U] 
                                      >> 0x10U))));
        bufp->chgIData(oldp+281,(((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__data[3U] 
                                   << 0x10U) | (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__data[2U] 
                                                >> 0x10U))),32);
        bufp->chgCData(oldp+282,((0x1fU & (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__data[2U] 
                                           >> 0xbU))),5);
        bufp->chgIData(oldp+283,(((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__data[2U] 
                                   << 0x15U) | (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__data[1U] 
                                                >> 0xbU))),32);
        bufp->chgBit(oldp+284,((1U & (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__data[1U] 
                                      >> 0xaU))));
        bufp->chgBit(oldp+285,((1U & (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__data[1U] 
                                      >> 9U))));
        bufp->chgBit(oldp+286,((1U & (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__data[1U] 
                                      >> 8U))));
        bufp->chgCData(oldp+287,((3U & (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__data[1U] 
                                        >> 6U))),2);
        bufp->chgBit(oldp+288,((1U & (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__data[1U] 
                                      >> 5U))));
        bufp->chgIData(oldp+289,(((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__data[1U] 
                                   << 0x1bU) | (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__data[0U] 
                                                >> 5U))),32);
        bufp->chgCData(oldp+290,((0x1fU & vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__data[0U])),5);
        bufp->chgCData(oldp+291,((0x1fU & (IData)((vlSelfRef.CPU_top__DOT__cpu__DOT__writeback__DOT__data 
                                                   >> 0x20U)))),5);
        bufp->chgIData(oldp+292,((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__writeback__DOT__data)),32);
        bufp->chgBit(oldp+293,(vlSelfRef.CPU_top__DOT__cpu__DOT__csr__DOT__mstatus_mpie));
        bufp->chgBit(oldp+294,(vlSelfRef.CPU_top__DOT__cpu__DOT__csr__DOT__mstatus_mie));
        bufp->chgBit(oldp+295,(vlSelfRef.CPU_top__DOT__cpu__DOT__csr__DOT__mie_meie));
        bufp->chgBit(oldp+296,(vlSelfRef.CPU_top__DOT__cpu__DOT__csr__DOT__mie_mtie));
        bufp->chgBit(oldp+297,(vlSelfRef.CPU_top__DOT__cpu__DOT__csr__DOT__mie_msie));
        bufp->chgIData(oldp+298,(vlSelfRef.CPU_top__DOT__cpu__DOT__csr__DOT__mtvec),32);
        bufp->chgIData(oldp+299,(vlSelfRef.CPU_top__DOT__cpu__DOT__csr__DOT__mcause),32);
        bufp->chgBit(oldp+300,(vlSelfRef.CPU_top__DOT__cpu__DOT__csr__DOT__mip_meip));
        bufp->chgBit(oldp+301,(vlSelfRef.CPU_top__DOT__cpu__DOT__csr__DOT__mip_mtip));
        bufp->chgBit(oldp+302,(vlSelfRef.CPU_top__DOT__cpu__DOT__csr__DOT__mip_msip));
        bufp->chgIData(oldp+303,(vlSelfRef.CPU_top__DOT__cpu__DOT__csr__DOT__mscratch),32);
        bufp->chgIData(oldp+304,((((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__csr__DOT__mstatus_mpie) 
                                   << 4U) | ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__csr__DOT__mstatus_mie) 
                                             << 3U))),32);
        bufp->chgIData(oldp+305,((((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__csr__DOT__mie_meie) 
                                   << 0xbU) | (((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__csr__DOT__mie_mtie) 
                                                << 7U) 
                                               | ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__csr__DOT__mie_msie) 
                                                  << 3U)))),32);
        bufp->chgIData(oldp+306,((((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__csr__DOT__mip_meip) 
                                   << 0xbU) | (((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__csr__DOT__mip_mtip) 
                                                << 7U) 
                                               | ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__csr__DOT__mip_msip) 
                                                  << 3U)))),32);
        bufp->chgQData(oldp+307,(vlSelfRef.CPU_top__DOT__cpu__DOT__csr__DOT__cycle),64);
        bufp->chgQData(oldp+309,(vlSelfRef.CPU_top__DOT__cpu__DOT__csr__DOT__wtime),64);
        bufp->chgSData(oldp+311,(vlSelfRef.CPU_top__DOT__cpu__DOT__csr__DOT__prescale),14);
        bufp->chgCData(oldp+312,(vlSelfRef.CPU_top__DOT__cpu__DOT__csr__DOT__issued),3);
        bufp->chgBit(oldp+313,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__mul_request));
        bufp->chgBit(oldp+314,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__mul_signed));
        bufp->chgBit(oldp+315,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__multiply__DOT__ready));
        bufp->chgQData(oldp+316,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__multiply__DOT__result),64);
        bufp->chgBit(oldp+318,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__div_request));
        bufp->chgBit(oldp+319,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__div_signed));
        bufp->chgBit(oldp+320,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__last_strobe));
        bufp->chgCData(oldp+321,((0xfU & (vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[0U] 
                                          >> 0x14U))),4);
        bufp->chgIData(oldp+322,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__unumerator),32);
        bufp->chgIData(oldp+323,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__udenominator),32);
        bufp->chgCData(oldp+324,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__s),2);
        bufp->chgBit(oldp+325,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__llth));
        bufp->chgBit(oldp+326,(((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__div_request) 
                                & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__llth))));
        bufp->chgCData(oldp+327,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__multiply__DOT__m_s),2);
        bufp->chgIData(oldp+328,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__multiply__DOT__m_uop1),32);
        bufp->chgIData(oldp+329,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__multiply__DOT__m_uop2),32);
        bufp->chgQData(oldp+330,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__multiply__DOT__m_product),64);
        bufp->chgCData(oldp+332,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__multiply__DOT__state),2);
        bufp->chgCData(oldp+333,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__multiply__DOT__cnt),8);
        bufp->chgBit(oldp+334,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__multiply__DOT__m__DOT__valid_out));
        bufp->chgQData(oldp+335,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__multiply__DOT__m__DOT__partial_products[0]),64);
        bufp->chgQData(oldp+337,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__multiply__DOT__m__DOT__partial_products[1]),64);
        bufp->chgQData(oldp+339,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__multiply__DOT__m__DOT__partial_products[2]),64);
        bufp->chgQData(oldp+341,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__multiply__DOT__m__DOT__partial_products[3]),64);
        bufp->chgQData(oldp+343,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__multiply__DOT__m__DOT__partial_products[4]),64);
        bufp->chgQData(oldp+345,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__multiply__DOT__m__DOT__partial_products[5]),64);
        bufp->chgQData(oldp+347,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__multiply__DOT__m__DOT__partial_products[6]),64);
        bufp->chgQData(oldp+349,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__multiply__DOT__m__DOT__partial_products[7]),64);
        bufp->chgQData(oldp+351,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__multiply__DOT__m__DOT__partial_products[8]),64);
        bufp->chgQData(oldp+353,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__multiply__DOT__m__DOT__partial_products[9]),64);
        bufp->chgQData(oldp+355,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__multiply__DOT__m__DOT__partial_products[10]),64);
        bufp->chgQData(oldp+357,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__multiply__DOT__m__DOT__partial_products[11]),64);
        bufp->chgQData(oldp+359,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__multiply__DOT__m__DOT__partial_products[12]),64);
        bufp->chgQData(oldp+361,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__multiply__DOT__m__DOT__partial_products[13]),64);
        bufp->chgQData(oldp+363,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__multiply__DOT__m__DOT__partial_products[14]),64);
        bufp->chgQData(oldp+365,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__multiply__DOT__m__DOT__partial_products[15]),64);
        bufp->chgQData(oldp+367,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__multiply__DOT__m__DOT__partial_products[16]),64);
        bufp->chgQData(oldp+369,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__multiply__DOT__m__DOT__partial_products[17]),64);
        bufp->chgQData(oldp+371,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__multiply__DOT__m__DOT__partial_products[18]),64);
        bufp->chgQData(oldp+373,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__multiply__DOT__m__DOT__partial_products[19]),64);
        bufp->chgQData(oldp+375,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__multiply__DOT__m__DOT__partial_products[20]),64);
        bufp->chgQData(oldp+377,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__multiply__DOT__m__DOT__partial_products[21]),64);
        bufp->chgQData(oldp+379,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__multiply__DOT__m__DOT__partial_products[22]),64);
        bufp->chgQData(oldp+381,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__multiply__DOT__m__DOT__partial_products[23]),64);
        bufp->chgQData(oldp+383,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__multiply__DOT__m__DOT__partial_products[24]),64);
        bufp->chgQData(oldp+385,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__multiply__DOT__m__DOT__partial_products[25]),64);
        bufp->chgQData(oldp+387,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__multiply__DOT__m__DOT__partial_products[26]),64);
        bufp->chgQData(oldp+389,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__multiply__DOT__m__DOT__partial_products[27]),64);
        bufp->chgQData(oldp+391,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__multiply__DOT__m__DOT__partial_products[28]),64);
        bufp->chgQData(oldp+393,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__multiply__DOT__m__DOT__partial_products[29]),64);
        bufp->chgQData(oldp+395,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__multiply__DOT__m__DOT__partial_products[30]),64);
        bufp->chgQData(oldp+397,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__multiply__DOT__m__DOT__partial_products[31]),64);
        bufp->chgQData(oldp+399,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__multiply__DOT__m__DOT__stage1_sum[0]),64);
        bufp->chgQData(oldp+401,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__multiply__DOT__m__DOT__stage1_sum[1]),64);
        bufp->chgQData(oldp+403,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__multiply__DOT__m__DOT__stage1_sum[2]),64);
        bufp->chgQData(oldp+405,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__multiply__DOT__m__DOT__stage1_sum[3]),64);
        bufp->chgQData(oldp+407,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__multiply__DOT__m__DOT__stage1_sum[4]),64);
        bufp->chgQData(oldp+409,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__multiply__DOT__m__DOT__stage1_sum[5]),64);
        bufp->chgQData(oldp+411,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__multiply__DOT__m__DOT__stage1_sum[6]),64);
        bufp->chgQData(oldp+413,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__multiply__DOT__m__DOT__stage1_sum[7]),64);
        bufp->chgQData(oldp+415,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__multiply__DOT__m__DOT__stage1_sum[8]),64);
        bufp->chgQData(oldp+417,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__multiply__DOT__m__DOT__stage1_sum[9]),64);
        bufp->chgQData(oldp+419,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__multiply__DOT__m__DOT__stage1_sum[10]),64);
        bufp->chgQData(oldp+421,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__multiply__DOT__m__DOT__stage1_sum[11]),64);
        bufp->chgQData(oldp+423,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__multiply__DOT__m__DOT__stage1_sum[12]),64);
        bufp->chgQData(oldp+425,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__multiply__DOT__m__DOT__stage1_sum[13]),64);
        bufp->chgQData(oldp+427,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__multiply__DOT__m__DOT__stage1_sum[14]),64);
        bufp->chgQData(oldp+429,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__multiply__DOT__m__DOT__stage1_sum[15]),64);
        bufp->chgIData(oldp+431,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__multiply__DOT__m__DOT__j),32);
        bufp->chgQData(oldp+432,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__multiply__DOT__m__DOT__stage2_sum[0]),64);
        bufp->chgQData(oldp+434,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__multiply__DOT__m__DOT__stage2_sum[1]),64);
        bufp->chgQData(oldp+436,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__multiply__DOT__m__DOT__stage2_sum[2]),64);
        bufp->chgQData(oldp+438,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__multiply__DOT__m__DOT__stage2_sum[3]),64);
        bufp->chgQData(oldp+440,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__multiply__DOT__m__DOT__stage2_sum[4]),64);
        bufp->chgQData(oldp+442,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__multiply__DOT__m__DOT__stage2_sum[5]),64);
        bufp->chgQData(oldp+444,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__multiply__DOT__m__DOT__stage2_sum[6]),64);
        bufp->chgQData(oldp+446,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__multiply__DOT__m__DOT__stage2_sum[7]),64);
        bufp->chgQData(oldp+448,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__multiply__DOT__m__DOT__stage3_sum[0]),64);
        bufp->chgQData(oldp+450,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__multiply__DOT__m__DOT__stage3_sum[1]),64);
        bufp->chgQData(oldp+452,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__multiply__DOT__m__DOT__stage3_sum[2]),64);
        bufp->chgQData(oldp+454,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__multiply__DOT__m__DOT__stage3_sum[3]),64);
        bufp->chgQData(oldp+456,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__multiply__DOT__m__DOT__stage4_a),64);
        bufp->chgQData(oldp+458,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__multiply__DOT__m__DOT__stage4_b),64);
        bufp->chgBit(oldp+460,((0x33U == (0xfe00707fU 
                                          & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)))));
        bufp->chgBit(oldp+461,((0x13U == (0x707fU & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)))));
        bufp->chgBit(oldp+462,((0x7033U == (0xfe00707fU 
                                            & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)))));
        bufp->chgBit(oldp+463,((0x7013U == (0x707fU 
                                            & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)))));
        bufp->chgBit(oldp+464,((0x17U == (0x7fU & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)))));
        bufp->chgBit(oldp+465,((0x63U == (0x707fU & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)))));
        bufp->chgBit(oldp+466,((0x5063U == (0x707fU 
                                            & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)))));
        bufp->chgBit(oldp+467,((0x7063U == (0x707fU 
                                            & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)))));
        bufp->chgBit(oldp+468,((0x4063U == (0x707fU 
                                            & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)))));
        bufp->chgBit(oldp+469,((0x6063U == (0x707fU 
                                            & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)))));
        bufp->chgBit(oldp+470,((0x1063U == (0x707fU 
                                            & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)))));
        bufp->chgBit(oldp+471,((0x3073U == (0x707fU 
                                            & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)))));
        bufp->chgBit(oldp+472,((0x2073U == (0x707fU 
                                            & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)))));
        bufp->chgBit(oldp+473,((0x1073U == (0x707fU 
                                            & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)))));
        bufp->chgBit(oldp+474,((0x2004033U == (0xfe00707fU 
                                               & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)))));
        bufp->chgBit(oldp+475,((0x2005033U == (0xfe00707fU 
                                               & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)))));
        bufp->chgBit(oldp+476,((0x100073U == (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata))));
        bufp->chgBit(oldp+477,((0x73U == (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata))));
        bufp->chgBit(oldp+478,((0x53U == (0xfe00007fU 
                                          & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)))));
        bufp->chgBit(oldp+479,((0xc0000053U == (0xfff0007fU 
                                                & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)))));
        bufp->chgBit(oldp+480,((0xc0100053U == (0xfff0007fU 
                                                & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)))));
        bufp->chgBit(oldp+481,((0xd0000053U == (0xfff0007fU 
                                                & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)))));
        bufp->chgBit(oldp+482,((0xd0100053U == (0xfff0007fU 
                                                & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)))));
        bufp->chgBit(oldp+483,((0x18000053U == (0xfe00007fU 
                                                & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)))));
        bufp->chgBit(oldp+484,((0xfU == (0x707fU & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)))));
        bufp->chgBit(oldp+485,((0xa0002053U == (0xfe00707fU 
                                                & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)))));
        bufp->chgBit(oldp+486,((0xa0000053U == (0xfe00707fU 
                                                & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)))));
        bufp->chgBit(oldp+487,((0xa0001053U == (0xfe00707fU 
                                                & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)))));
        bufp->chgBit(oldp+488,((0x2007U == (0x707fU 
                                            & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)))));
        bufp->chgBit(oldp+489,((0x43U == (0x600007fU 
                                          & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)))));
        bufp->chgBit(oldp+490,((0x47U == (0x600007fU 
                                          & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)))));
        bufp->chgBit(oldp+491,((0x4fU == (0x600007fU 
                                          & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)))));
        bufp->chgBit(oldp+492,((0x4bU == (0x600007fU 
                                          & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)))));
        bufp->chgBit(oldp+493,((0x28000053U == (0xfe00707fU 
                                                & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)))));
        bufp->chgBit(oldp+494,((0x28001053U == (0xfe00707fU 
                                                & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)))));
        bufp->chgBit(oldp+495,((0x10000053U == (0xfe00007fU 
                                                & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)))));
        bufp->chgBit(oldp+496,((0xe0000053U == (0xfff0707fU 
                                                & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)))));
        bufp->chgBit(oldp+497,((0xf0000053U == (0xfff0707fU 
                                                & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)))));
        bufp->chgBit(oldp+498,((0x20000053U == (0xfe00707fU 
                                                & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)))));
        bufp->chgBit(oldp+499,((0x20001053U == (0xfe00707fU 
                                                & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)))));
        bufp->chgBit(oldp+500,((0x20002053U == (0xfe00707fU 
                                                & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)))));
        bufp->chgBit(oldp+501,((0x8000053U == (0xfe00007fU 
                                               & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)))));
        bufp->chgBit(oldp+502,((0x2027U == (0x707fU 
                                            & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)))));
        bufp->chgBit(oldp+503,((0x6fU == (0x7fU & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)))));
        bufp->chgBit(oldp+504,((0x67U == (0x707fU & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)))));
        bufp->chgBit(oldp+505,((3U == (0x707fU & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)))));
        bufp->chgBit(oldp+506,((0x4003U == (0x707fU 
                                            & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)))));
        bufp->chgBit(oldp+507,((0x1003U == (0x707fU 
                                            & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)))));
        bufp->chgBit(oldp+508,((0x5003U == (0x707fU 
                                            & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)))));
        bufp->chgBit(oldp+509,((0x37U == (0x7fU & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)))));
        bufp->chgBit(oldp+510,((0x2003U == (0x707fU 
                                            & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)))));
        bufp->chgBit(oldp+511,((0x2000033U == (0xfe00707fU 
                                               & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)))));
        bufp->chgBit(oldp+512,((0x2001033U == (0xfe00707fU 
                                               & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)))));
        bufp->chgBit(oldp+513,((0x2003033U == (0xfe00707fU 
                                               & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)))));
        bufp->chgBit(oldp+514,((0x30200073U == (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata))));
        bufp->chgBit(oldp+515,((0x6033U == (0xfe00707fU 
                                            & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)))));
        bufp->chgBit(oldp+516,((0x6013U == (0x707fU 
                                            & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)))));
        bufp->chgBit(oldp+517,((0x2006033U == (0xfe00707fU 
                                               & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)))));
        bufp->chgBit(oldp+518,((0x2007033U == (0xfe00707fU 
                                               & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)))));
        bufp->chgBit(oldp+519,((0x23U == (0x707fU & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)))));
        bufp->chgBit(oldp+520,((0x1023U == (0x707fU 
                                            & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)))));
        bufp->chgBit(oldp+521,((0x1033U == (0xfe00707fU 
                                            & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)))));
        bufp->chgBit(oldp+522,((0x1013U == (0xfc00707fU 
                                            & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)))));
        bufp->chgBit(oldp+523,((0x2033U == (0xfe00707fU 
                                            & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)))));
        bufp->chgBit(oldp+524,((0x2013U == (0x707fU 
                                            & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)))));
        bufp->chgBit(oldp+525,((0x3013U == (0x707fU 
                                            & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)))));
        bufp->chgBit(oldp+526,((0x3033U == (0xfe00707fU 
                                            & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)))));
        bufp->chgBit(oldp+527,((0x40005033U == (0xfe00707fU 
                                                & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)))));
        bufp->chgBit(oldp+528,((0x40005013U == (0xfc00707fU 
                                                & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)))));
        bufp->chgBit(oldp+529,((0x5033U == (0xfe00707fU 
                                            & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)))));
        bufp->chgBit(oldp+530,((0x5013U == (0xfc00707fU 
                                            & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)))));
        bufp->chgBit(oldp+531,((0x40000033U == (0xfe00707fU 
                                                & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)))));
        bufp->chgBit(oldp+532,((0x2023U == (0x707fU 
                                            & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)))));
        bufp->chgBit(oldp+533,((0x10500073U == (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata))));
        bufp->chgBit(oldp+534,((0x4033U == (0xfe00707fU 
                                            & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)))));
        bufp->chgBit(oldp+535,((0x4013U == (0x707fU 
                                            & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)))));
        bufp->chgBit(oldp+536,(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__is_JUMP_CONDITIONAL));
        bufp->chgBit(oldp+537,(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__is_I));
        bufp->chgBit(oldp+538,(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__is_R));
        bufp->chgBit(oldp+539,(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__have_RS3));
        bufp->chgBit(oldp+540,(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__is_S));
        bufp->chgBit(oldp+541,(((0x17U == (0x7fU & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata))) 
                                | (0x37U == (0x7fU 
                                             & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata))))));
        bufp->chgBit(oldp+542,(((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT____VdfgRegularize_hef2daed4_0_20) 
                                | (0x30200073U == (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)))));
        bufp->chgBit(oldp+543,(((0x33U == (0xfe00707fU 
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
        bufp->chgBit(oldp+544,(((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT____VdfgRegularize_hef2daed4_0_8) 
                                | ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT____VdfgRegularize_hef2daed4_0_19) 
                                   | (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT____VdfgRegularize_hef2daed4_0_18)))));
        bufp->chgBit(oldp+545,(((0x2033U == (0xfe00707fU 
                                             & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata))) 
                                | ((0x2013U == (0x707fU 
                                                & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata))) 
                                   | ((0x3013U == (0x707fU 
                                                   & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata))) 
                                      | (0x3033U == 
                                         (0xfe00707fU 
                                          & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata))))))));
        bufp->chgBit(oldp+546,(((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT____VdfgRegularize_hef2daed4_0_20) 
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
        bufp->chgBit(oldp+547,(((0x6fU == (0x7fU & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata))) 
                                | (0x67U == (0x707fU 
                                             & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata))))));
        bufp->chgBit(oldp+548,(((3U == (0x707fU & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata))) 
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
        bufp->chgBit(oldp+549,(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__is_FPU));
        bufp->chgBit(oldp+550,(((0x2007U == (0x707fU 
                                             & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata))) 
                                | (0x2027U == (0x707fU 
                                               & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata))))));
        bufp->chgBit(oldp+551,(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__RD_bank));
        bufp->chgBit(oldp+552,(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__RS1_bank));
        bufp->chgBit(oldp+553,(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__RS2_bank));
        bufp->chgBit(oldp+554,(vlSelfRef.CPU_top__DOT__cpu__DOT____Vcellinp__fetch__i_busy));
        bufp->chgCData(oldp+555,(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__state),2);
        bufp->chgIData(oldp+556,(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__pc),32);
        bufp->chgIData(oldp+557,((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)),32);
        bufp->chgBit(oldp+558,(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__icache_ready));
        bufp->chgBit(oldp+559,(((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__is_JUMP_CONDITIONAL) 
                                | ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__is_I) 
                                   | ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__is_R) 
                                      | ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__is_S) 
                                         | (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT____VdfgRegularize_hef2daed4_0_14)))))));
        bufp->chgBit(oldp+560,(((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__is_JUMP_CONDITIONAL) 
                                | ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__is_R) 
                                   | ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__is_S) 
                                      | (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__have_RS3))))));
        bufp->chgBit(oldp+561,(((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__is_I) 
                                | ((0x6fU == (0x7fU 
                                              & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata))) 
                                   | ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__is_R) 
                                      | (((0x17U == 
                                           (0x7fU & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata))) 
                                          | (0x37U 
                                             == (0x7fU 
                                                 & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)))) 
                                         | (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT____VdfgRegularize_hef2daed4_0_14)))))));
        bufp->chgBit(oldp+562,(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__irq_pending_r));
        bufp->chgBit(oldp+563,(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT__initialized));
        bufp->chgIData(oldp+564,(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT__clear_set),32);
        bufp->chgBit(oldp+565,(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT__cache_invalid));
        bufp->chgSData(oldp+566,((0xfffU & (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__pc 
                                            >> 2U))),12);
        bufp->chgIData(oldp+567,((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__pc 
                                  >> 0xeU)),18);
        bufp->chgSData(oldp+568,(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT__cache_rd_set),12);
        bufp->chgBit(oldp+569,((1U & (IData)((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata 
                                              >> 0x32U)))));
        bufp->chgIData(oldp+570,((0x3ffffU & (IData)(
                                                     (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata 
                                                      >> 0x20U)))),18);
        bufp->chgIData(oldp+571,((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata)),32);
        bufp->chgBit(oldp+572,(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT__cache_wr_request));
        bufp->chgSData(oldp+573,(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT__cache_wr_set),12);
        bufp->chgBit(oldp+574,((1U & (IData)((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT__cache_wr_wdata 
                                              >> 0x32U)))));
        bufp->chgIData(oldp+575,((0x3ffffU & (IData)(
                                                     (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT__cache_wr_wdata 
                                                      >> 0x20U)))),18);
        bufp->chgIData(oldp+576,((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT__cache_wr_wdata)),32);
        bufp->chgSData(oldp+577,(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT__set_r),12);
        bufp->chgIData(oldp+578,(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT__cache_rd_set),32);
        bufp->chgQData(oldp+579,(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata),51);
        bufp->chgBit(oldp+581,(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT__cache__DOT__o_pa_ready));
        bufp->chgIData(oldp+582,(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT__cache_wr_set),32);
        bufp->chgQData(oldp+583,(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT__cache_wr_wdata),51);
        bufp->chgBit(oldp+585,(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT__cache__DOT__o_pb_ready));
        bufp->chgWData(oldp+586,(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch__DOT__data),117);
        bufp->chgWData(oldp+590,(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_skid__DOT__r_data),117);
        bufp->chgBit(oldp+594,(vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__dcache_rw));
        bufp->chgBit(oldp+595,(vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__dcache_request));
        bufp->chgBit(oldp+596,(vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__dcache_flush));
        bufp->chgBit(oldp+597,(vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__dcache_ready));
        bufp->chgIData(oldp+598,((0xfffffffcU & ((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__data[1U] 
                                                  << 0x1bU) 
                                                 | (0x7fffffcU 
                                                    & (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__data[0U] 
                                                       >> 5U))))),32);
        bufp->chgIData(oldp+599,(vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__dcache_rdata),32);
        bufp->chgIData(oldp+600,(vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__dcache_wdata),32);
        bufp->chgBit(oldp+601,((2U == (0xfU & (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__data[1U] 
                                               >> 1U)))));
        bufp->chgCData(oldp+602,((3U & (vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__data[0U] 
                                        >> 5U))),2);
        bufp->chgCData(oldp+603,((0xffU & vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT____VdfgRegularize_h9eb5ee7c_0_0)),8);
        bufp->chgSData(oldp+604,((0xffffU & vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT____VdfgRegularize_h9eb5ee7c_0_0)),16);
        bufp->chgCData(oldp+605,(vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__state),3);
        bufp->chgIData(oldp+606,(vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__rmw_rdata),32);
        bufp->chgBit(oldp+607,(vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__last_strobe));
        bufp->chgCData(oldp+608,(vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__genblk1__DOT__dcache__DOT__state),4);
        bufp->chgSData(oldp+609,(vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__genblk1__DOT__dcache__DOT__flush_address),13);
        bufp->chgBit(oldp+610,(vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__genblk1__DOT__dcache__DOT__wb_rw));
        bufp->chgBit(oldp+611,(vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__genblk1__DOT__dcache__DOT__wb_request));
        bufp->chgIData(oldp+612,(vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__genblk1__DOT__dcache__DOT__wb_address),32);
        bufp->chgIData(oldp+613,(vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__genblk1__DOT__dcache__DOT__wb_wdata),32);
        bufp->chgBit(oldp+614,(vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__genblk1__DOT__dcache__DOT__cache_rw));
        bufp->chgSData(oldp+615,(vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__genblk1__DOT__dcache__DOT__cache_address),12);
        bufp->chgQData(oldp+616,(vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__genblk1__DOT__dcache__DOT__cache_wdata),64);
        bufp->chgQData(oldp+618,(vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__genblk1__DOT__dcache__DOT__cache_rdata),64);
        bufp->chgBit(oldp+620,((1U & (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__genblk1__DOT__dcache__DOT__cache_rdata))));
        bufp->chgBit(oldp+621,((1U & (IData)((vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__genblk1__DOT__dcache__DOT__cache_rdata 
                                              >> 1U)))));
        bufp->chgIData(oldp+622,(((IData)((vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__genblk1__DOT__dcache__DOT__cache_rdata 
                                           >> 2U)) 
                                  << 2U)),32);
        bufp->chgIData(oldp+623,((IData)((vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__genblk1__DOT__dcache__DOT__cache_rdata 
                                          >> 0x20U))),32);
        bufp->chgIData(oldp+624,(vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__genblk1__DOT__dcache__DOT__cache_address),32);
        bufp->chgBit(oldp+625,(vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__genblk1__DOT__dcache__DOT__cache__DOT__o_ready));
        bufp->chgBit(oldp+626,(vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__genblk1__DOT__dcache__DOT__cache__DOT__o_valid));
        bufp->chgBit(oldp+627,(vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__genblk1__DOT__dcache__DOT__wb__DOT__wb_dirty));
        bufp->chgIData(oldp+628,(vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__genblk1__DOT__dcache__DOT__wb__DOT__wb_address),32);
        bufp->chgIData(oldp+629,(vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__genblk1__DOT__dcache__DOT__wb__DOT__next_wb_address),32);
        bufp->chgIData(oldp+630,(vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__genblk1__DOT__dcache__DOT__wb__DOT__next_wb_data),32);
        bufp->chgBit(oldp+631,(vlSelfRef.CPU_top__DOT__cpu__DOT__writeback__DOT__last_strobe));
        bufp->chgIData(oldp+632,(vlSelfRef.CPU_top__DOT__cpu__DOT__writeback__DOT__last_pc),32);
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[5U]))) {
        bufp->chgIData(oldp+633,(vlSelfRef.CPU_top__DOT__cpu__DOT__registers__DOT__rs1),32);
        bufp->chgIData(oldp+634,(vlSelfRef.CPU_top__DOT__cpu__DOT__registers__DOT__rs2),32);
        bufp->chgIData(oldp+635,(vlSelfRef.CPU_top__DOT__cpu__DOT__registers__DOT__rs3),32);
        bufp->chgBit(oldp+636,(vlSelfRef.CPU_top__DOT__cpu__DOT__registers__DOT__last_write_strobe));
        bufp->chgIData(oldp+637,(vlSelfRef.CPU_top__DOT__cpu__DOT__registers__DOT__r[0]),32);
        bufp->chgIData(oldp+638,(vlSelfRef.CPU_top__DOT__cpu__DOT__registers__DOT__r[1]),32);
        bufp->chgIData(oldp+639,(vlSelfRef.CPU_top__DOT__cpu__DOT__registers__DOT__r[2]),32);
        bufp->chgIData(oldp+640,(vlSelfRef.CPU_top__DOT__cpu__DOT__registers__DOT__r[3]),32);
        bufp->chgIData(oldp+641,(vlSelfRef.CPU_top__DOT__cpu__DOT__registers__DOT__r[4]),32);
        bufp->chgIData(oldp+642,(vlSelfRef.CPU_top__DOT__cpu__DOT__registers__DOT__r[5]),32);
        bufp->chgIData(oldp+643,(vlSelfRef.CPU_top__DOT__cpu__DOT__registers__DOT__r[6]),32);
        bufp->chgIData(oldp+644,(vlSelfRef.CPU_top__DOT__cpu__DOT__registers__DOT__r[7]),32);
        bufp->chgIData(oldp+645,(vlSelfRef.CPU_top__DOT__cpu__DOT__registers__DOT__r[8]),32);
        bufp->chgIData(oldp+646,(vlSelfRef.CPU_top__DOT__cpu__DOT__registers__DOT__r[9]),32);
        bufp->chgIData(oldp+647,(vlSelfRef.CPU_top__DOT__cpu__DOT__registers__DOT__r[10]),32);
        bufp->chgIData(oldp+648,(vlSelfRef.CPU_top__DOT__cpu__DOT__registers__DOT__r[11]),32);
        bufp->chgIData(oldp+649,(vlSelfRef.CPU_top__DOT__cpu__DOT__registers__DOT__r[12]),32);
        bufp->chgIData(oldp+650,(vlSelfRef.CPU_top__DOT__cpu__DOT__registers__DOT__r[13]),32);
        bufp->chgIData(oldp+651,(vlSelfRef.CPU_top__DOT__cpu__DOT__registers__DOT__r[14]),32);
        bufp->chgIData(oldp+652,(vlSelfRef.CPU_top__DOT__cpu__DOT__registers__DOT__r[15]),32);
        bufp->chgIData(oldp+653,(vlSelfRef.CPU_top__DOT__cpu__DOT__registers__DOT__r[16]),32);
        bufp->chgIData(oldp+654,(vlSelfRef.CPU_top__DOT__cpu__DOT__registers__DOT__r[17]),32);
        bufp->chgIData(oldp+655,(vlSelfRef.CPU_top__DOT__cpu__DOT__registers__DOT__r[18]),32);
        bufp->chgIData(oldp+656,(vlSelfRef.CPU_top__DOT__cpu__DOT__registers__DOT__r[19]),32);
        bufp->chgIData(oldp+657,(vlSelfRef.CPU_top__DOT__cpu__DOT__registers__DOT__r[20]),32);
        bufp->chgIData(oldp+658,(vlSelfRef.CPU_top__DOT__cpu__DOT__registers__DOT__r[21]),32);
        bufp->chgIData(oldp+659,(vlSelfRef.CPU_top__DOT__cpu__DOT__registers__DOT__r[22]),32);
        bufp->chgIData(oldp+660,(vlSelfRef.CPU_top__DOT__cpu__DOT__registers__DOT__r[23]),32);
        bufp->chgIData(oldp+661,(vlSelfRef.CPU_top__DOT__cpu__DOT__registers__DOT__r[24]),32);
        bufp->chgIData(oldp+662,(vlSelfRef.CPU_top__DOT__cpu__DOT__registers__DOT__r[25]),32);
        bufp->chgIData(oldp+663,(vlSelfRef.CPU_top__DOT__cpu__DOT__registers__DOT__r[26]),32);
        bufp->chgIData(oldp+664,(vlSelfRef.CPU_top__DOT__cpu__DOT__registers__DOT__r[27]),32);
        bufp->chgIData(oldp+665,(vlSelfRef.CPU_top__DOT__cpu__DOT__registers__DOT__r[28]),32);
        bufp->chgIData(oldp+666,(vlSelfRef.CPU_top__DOT__cpu__DOT__registers__DOT__r[29]),32);
        bufp->chgIData(oldp+667,(vlSelfRef.CPU_top__DOT__cpu__DOT__registers__DOT__r[30]),32);
        bufp->chgIData(oldp+668,(vlSelfRef.CPU_top__DOT__cpu__DOT__registers__DOT__r[31]),32);
        bufp->chgIData(oldp+669,(vlSelfRef.CPU_top__DOT__cpu__DOT__registers__DOT__I),32);
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[7U]))) {
        bufp->chgBit(oldp+670,((1U & (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                      >> 0x14U))));
        bufp->chgIData(oldp+671,(((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                   << 0xcU) | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                               >> 0x14U))),32);
        bufp->chgIData(oldp+672,(((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                   << 0xcU) | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[1U] 
                                               >> 0x14U))),32);
        bufp->chgCData(oldp+673,((0x1fU & (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[1U] 
                                           >> 0xfU))),5);
        bufp->chgCData(oldp+674,((0x1fU & (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[1U] 
                                           >> 0xaU))),5);
        bufp->chgCData(oldp+675,((0x1fU & (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[1U] 
                                           >> 5U))),5);
        bufp->chgCData(oldp+676,((0x1fU & vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[1U])),5);
        bufp->chgIData(oldp+677,(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[0U]),32);
        bufp->chgBit(oldp+678,((1U & (vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__data[2U] 
                                      >> 5U))));
        bufp->chgIData(oldp+679,(((vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__data[2U] 
                                   << 0x1bU) | (vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__data[1U] 
                                                >> 5U))),32);
        bufp->chgCData(oldp+680,((0x1fU & vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__data[1U])),5);
        bufp->chgIData(oldp+681,(vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__data[0U]),32);
        bufp->chgBit(oldp+682,(((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__is_B) 
                                | ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__is_I) 
                                   | ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__is_R) 
                                      | ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__is_S) 
                                         | (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT____VdfgRegularize_h2cfc3394_0_18)))))));
        bufp->chgBit(oldp+683,(((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__is_B) 
                                | ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__is_R) 
                                   | ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__is_S) 
                                      | (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__have_RS3))))));
        bufp->chgBit(oldp+684,(vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__have_RS3));
        bufp->chgBit(oldp+685,(((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__is_I) 
                                | ((0x6fU == (0x7fU 
                                              & (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                 >> 0x14U))) 
                                   | ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__is_R) 
                                      | ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__is_U) 
                                         | (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT____VdfgRegularize_h2cfc3394_0_18)))))));
        bufp->chgIData(oldp+686,((((- (IData)((1U & 
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
        bufp->chgIData(oldp+687,((((- (IData)((1U & 
                                               (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                >> 0x13U)))) 
                                   << 0xbU) | (0x7ffU 
                                               & (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                  >> 8U)))),32);
        bufp->chgIData(oldp+688,((((- (IData)((1U & 
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
        bufp->chgIData(oldp+689,((((- (IData)((1U & 
                                               (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                >> 0x13U)))) 
                                   << 0xbU) | ((0x7e0U 
                                                & (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                   >> 8U)) 
                                               | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                  >> 0x1bU)))),32);
        bufp->chgIData(oldp+690,((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                  << 0xcU)),32);
        bufp->chgIData(oldp+691,((0x3fU & (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                           >> 8U))),32);
        bufp->chgIData(oldp+692,((0xfffU & (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                            >> 8U))),32);
        bufp->chgBit(oldp+693,((0x33U == (0xfe00707fU 
                                          & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                              << 0xcU) 
                                             | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                >> 0x14U))))));
        bufp->chgBit(oldp+694,((0x13U == (0x707fU & 
                                          ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                            << 0xcU) 
                                           | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                              >> 0x14U))))));
        bufp->chgBit(oldp+695,((0x7033U == (0xfe00707fU 
                                            & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                << 0xcU) 
                                               | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                  >> 0x14U))))));
        bufp->chgBit(oldp+696,((0x7013U == (0x707fU 
                                            & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                << 0xcU) 
                                               | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                  >> 0x14U))))));
        bufp->chgBit(oldp+697,((0x17U == (0x7fU & (
                                                   vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                   >> 0x14U)))));
        bufp->chgBit(oldp+698,((0x63U == (0x707fU & 
                                          ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                            << 0xcU) 
                                           | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                              >> 0x14U))))));
        bufp->chgBit(oldp+699,((0x5063U == (0x707fU 
                                            & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                << 0xcU) 
                                               | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                  >> 0x14U))))));
        bufp->chgBit(oldp+700,((0x7063U == (0x707fU 
                                            & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                << 0xcU) 
                                               | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                  >> 0x14U))))));
        bufp->chgBit(oldp+701,((0x4063U == (0x707fU 
                                            & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                << 0xcU) 
                                               | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                  >> 0x14U))))));
        bufp->chgBit(oldp+702,((0x6063U == (0x707fU 
                                            & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                << 0xcU) 
                                               | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                  >> 0x14U))))));
        bufp->chgBit(oldp+703,((0x1063U == (0x707fU 
                                            & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                << 0xcU) 
                                               | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                  >> 0x14U))))));
        bufp->chgBit(oldp+704,((0x3073U == (0x707fU 
                                            & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                << 0xcU) 
                                               | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                  >> 0x14U))))));
        bufp->chgBit(oldp+705,((0x2073U == (0x707fU 
                                            & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                << 0xcU) 
                                               | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                  >> 0x14U))))));
        bufp->chgBit(oldp+706,((0x1073U == (0x707fU 
                                            & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                << 0xcU) 
                                               | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                  >> 0x14U))))));
        bufp->chgBit(oldp+707,((0x2004033U == (0xfe00707fU 
                                               & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                   << 0xcU) 
                                                  | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                     >> 0x14U))))));
        bufp->chgBit(oldp+708,((0x2005033U == (0xfe00707fU 
                                               & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                   << 0xcU) 
                                                  | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                     >> 0x14U))))));
        bufp->chgBit(oldp+709,((0x100073U == ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                               << 0xcU) 
                                              | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                 >> 0x14U)))));
        bufp->chgBit(oldp+710,((0x73U == ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                           << 0xcU) 
                                          | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                             >> 0x14U)))));
        bufp->chgBit(oldp+711,((0x53U == (0xfe00007fU 
                                          & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                              << 0xcU) 
                                             | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                >> 0x14U))))));
        bufp->chgBit(oldp+712,((0xc0000053U == (0xfff0007fU 
                                                & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                    << 0xcU) 
                                                   | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                      >> 0x14U))))));
        bufp->chgBit(oldp+713,((0xc0100053U == (0xfff0007fU 
                                                & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                    << 0xcU) 
                                                   | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                      >> 0x14U))))));
        bufp->chgBit(oldp+714,((0xd0000053U == (0xfff0007fU 
                                                & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                    << 0xcU) 
                                                   | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                      >> 0x14U))))));
        bufp->chgBit(oldp+715,((0xd0100053U == (0xfff0007fU 
                                                & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                    << 0xcU) 
                                                   | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                      >> 0x14U))))));
        bufp->chgBit(oldp+716,((0x18000053U == (0xfe00007fU 
                                                & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                    << 0xcU) 
                                                   | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                      >> 0x14U))))));
        bufp->chgBit(oldp+717,((0xfU == (0x707fU & 
                                         ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                           << 0xcU) 
                                          | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                             >> 0x14U))))));
        bufp->chgBit(oldp+718,((0xa0002053U == (0xfe00707fU 
                                                & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                    << 0xcU) 
                                                   | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                      >> 0x14U))))));
        bufp->chgBit(oldp+719,((0xa0000053U == (0xfe00707fU 
                                                & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                    << 0xcU) 
                                                   | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                      >> 0x14U))))));
        bufp->chgBit(oldp+720,((0xa0001053U == (0xfe00707fU 
                                                & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                    << 0xcU) 
                                                   | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                      >> 0x14U))))));
        bufp->chgBit(oldp+721,((0x2007U == (0x707fU 
                                            & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                << 0xcU) 
                                               | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                  >> 0x14U))))));
        bufp->chgBit(oldp+722,((0x43U == (0x600007fU 
                                          & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                              << 0xcU) 
                                             | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                >> 0x14U))))));
        bufp->chgBit(oldp+723,((0x47U == (0x600007fU 
                                          & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                              << 0xcU) 
                                             | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                >> 0x14U))))));
        bufp->chgBit(oldp+724,((0x4fU == (0x600007fU 
                                          & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                              << 0xcU) 
                                             | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                >> 0x14U))))));
        bufp->chgBit(oldp+725,((0x4bU == (0x600007fU 
                                          & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                              << 0xcU) 
                                             | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                >> 0x14U))))));
        bufp->chgBit(oldp+726,((0x28000053U == (0xfe00707fU 
                                                & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                    << 0xcU) 
                                                   | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                      >> 0x14U))))));
        bufp->chgBit(oldp+727,((0x28001053U == (0xfe00707fU 
                                                & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                    << 0xcU) 
                                                   | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                      >> 0x14U))))));
        bufp->chgBit(oldp+728,((0x10000053U == (0xfe00007fU 
                                                & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                    << 0xcU) 
                                                   | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                      >> 0x14U))))));
        bufp->chgBit(oldp+729,((0xe0000053U == (0xfff0707fU 
                                                & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                    << 0xcU) 
                                                   | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                      >> 0x14U))))));
        bufp->chgBit(oldp+730,((0xf0000053U == (0xfff0707fU 
                                                & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                    << 0xcU) 
                                                   | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                      >> 0x14U))))));
        bufp->chgBit(oldp+731,((0x20000053U == (0xfe00707fU 
                                                & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                    << 0xcU) 
                                                   | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                      >> 0x14U))))));
        bufp->chgBit(oldp+732,((0x20001053U == (0xfe00707fU 
                                                & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                    << 0xcU) 
                                                   | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                      >> 0x14U))))));
        bufp->chgBit(oldp+733,((0x20002053U == (0xfe00707fU 
                                                & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                    << 0xcU) 
                                                   | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                      >> 0x14U))))));
        bufp->chgBit(oldp+734,((0x8000053U == (0xfe00007fU 
                                               & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                   << 0xcU) 
                                                  | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                     >> 0x14U))))));
        bufp->chgBit(oldp+735,((0x2027U == (0x707fU 
                                            & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                << 0xcU) 
                                               | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                  >> 0x14U))))));
        bufp->chgBit(oldp+736,((0x6fU == (0x7fU & (
                                                   vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                   >> 0x14U)))));
        bufp->chgBit(oldp+737,((0x67U == (0x707fU & 
                                          ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                            << 0xcU) 
                                           | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                              >> 0x14U))))));
        bufp->chgBit(oldp+738,((3U == (0x707fU & ((
                                                   vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                   << 0xcU) 
                                                  | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                     >> 0x14U))))));
        bufp->chgBit(oldp+739,((0x4003U == (0x707fU 
                                            & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                << 0xcU) 
                                               | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                  >> 0x14U))))));
        bufp->chgBit(oldp+740,((0x1003U == (0x707fU 
                                            & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                << 0xcU) 
                                               | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                  >> 0x14U))))));
        bufp->chgBit(oldp+741,((0x5003U == (0x707fU 
                                            & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                << 0xcU) 
                                               | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                  >> 0x14U))))));
        bufp->chgBit(oldp+742,((0x37U == (0x7fU & (
                                                   vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                   >> 0x14U)))));
        bufp->chgBit(oldp+743,((0x2003U == (0x707fU 
                                            & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                << 0xcU) 
                                               | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                  >> 0x14U))))));
        bufp->chgBit(oldp+744,((0x2000033U == (0xfe00707fU 
                                               & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                   << 0xcU) 
                                                  | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                     >> 0x14U))))));
        bufp->chgBit(oldp+745,((0x2001033U == (0xfe00707fU 
                                               & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                   << 0xcU) 
                                                  | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                     >> 0x14U))))));
        bufp->chgBit(oldp+746,((0x2003033U == (0xfe00707fU 
                                               & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                   << 0xcU) 
                                                  | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                     >> 0x14U))))));
        bufp->chgBit(oldp+747,((0x30200073U == ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                 << 0xcU) 
                                                | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                   >> 0x14U)))));
        bufp->chgBit(oldp+748,((0x6033U == (0xfe00707fU 
                                            & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                << 0xcU) 
                                               | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                  >> 0x14U))))));
        bufp->chgBit(oldp+749,((0x6013U == (0x707fU 
                                            & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                << 0xcU) 
                                               | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                  >> 0x14U))))));
        bufp->chgBit(oldp+750,((0x2006033U == (0xfe00707fU 
                                               & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                   << 0xcU) 
                                                  | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                     >> 0x14U))))));
        bufp->chgBit(oldp+751,((0x2007033U == (0xfe00707fU 
                                               & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                   << 0xcU) 
                                                  | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                     >> 0x14U))))));
        bufp->chgBit(oldp+752,((0x23U == (0x707fU & 
                                          ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                            << 0xcU) 
                                           | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                              >> 0x14U))))));
        bufp->chgBit(oldp+753,((0x1023U == (0x707fU 
                                            & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                << 0xcU) 
                                               | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                  >> 0x14U))))));
        bufp->chgBit(oldp+754,((0x1033U == (0xfe00707fU 
                                            & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                << 0xcU) 
                                               | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                  >> 0x14U))))));
        bufp->chgBit(oldp+755,((0x1013U == (0xfc00707fU 
                                            & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                << 0xcU) 
                                               | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                  >> 0x14U))))));
        bufp->chgBit(oldp+756,((0x2033U == (0xfe00707fU 
                                            & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                << 0xcU) 
                                               | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                  >> 0x14U))))));
        bufp->chgBit(oldp+757,((0x2013U == (0x707fU 
                                            & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                << 0xcU) 
                                               | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                  >> 0x14U))))));
        bufp->chgBit(oldp+758,((0x3013U == (0x707fU 
                                            & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                << 0xcU) 
                                               | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                  >> 0x14U))))));
        bufp->chgBit(oldp+759,((0x3033U == (0xfe00707fU 
                                            & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                << 0xcU) 
                                               | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                  >> 0x14U))))));
        bufp->chgBit(oldp+760,((0x40005033U == (0xfe00707fU 
                                                & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                    << 0xcU) 
                                                   | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                      >> 0x14U))))));
        bufp->chgBit(oldp+761,((0x40005013U == (0xfc00707fU 
                                                & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                    << 0xcU) 
                                                   | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                      >> 0x14U))))));
        bufp->chgBit(oldp+762,((0x5033U == (0xfe00707fU 
                                            & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                << 0xcU) 
                                               | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                  >> 0x14U))))));
        bufp->chgBit(oldp+763,((0x5013U == (0xfc00707fU 
                                            & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                << 0xcU) 
                                               | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                  >> 0x14U))))));
        bufp->chgBit(oldp+764,((0x40000033U == (0xfe00707fU 
                                                & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                    << 0xcU) 
                                                   | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                      >> 0x14U))))));
        bufp->chgBit(oldp+765,((0x2023U == (0x707fU 
                                            & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                << 0xcU) 
                                               | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                  >> 0x14U))))));
        bufp->chgBit(oldp+766,((0x10500073U == ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                 << 0xcU) 
                                                | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                   >> 0x14U)))));
        bufp->chgBit(oldp+767,((0x4033U == (0xfe00707fU 
                                            & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                << 0xcU) 
                                               | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                  >> 0x14U))))));
        bufp->chgBit(oldp+768,((0x4013U == (0x707fU 
                                            & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                << 0xcU) 
                                               | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                  >> 0x14U))))));
        bufp->chgBit(oldp+769,(vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__is_B));
        bufp->chgBit(oldp+770,(vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__is_I));
        bufp->chgBit(oldp+771,(vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__is_R));
        bufp->chgBit(oldp+772,(vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__is_S));
        bufp->chgBit(oldp+773,(vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__is_U));
        bufp->chgBit(oldp+774,(vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__is_CSR));
        bufp->chgBit(oldp+775,(((0x33U == (0xfe00707fU 
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
        bufp->chgBit(oldp+776,(((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT____VdfgRegularize_h2cfc3394_0_9) 
                                | ((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT____VdfgRegularize_h2cfc3394_0_25) 
                                   | (IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT____VdfgRegularize_h2cfc3394_0_24)))));
        bufp->chgBit(oldp+777,(((0x2033U == (0xfe00707fU 
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
        bufp->chgBit(oldp+778,(((IData)(vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT____VdfgRegularize_h2cfc3394_0_26) 
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
        bufp->chgBit(oldp+779,(((0x6fU == (0x7fU & 
                                           (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                            >> 0x14U))) 
                                | (0x67U == (0x707fU 
                                             & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                 << 0xcU) 
                                                | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                   >> 0x14U)))))));
        bufp->chgBit(oldp+780,(((3U == (0x707fU & (
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
        bufp->chgBit(oldp+781,(vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__is_FPU));
        bufp->chgBit(oldp+782,(((0x2007U == (0x707fU 
                                             & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                 << 0xcU) 
                                                | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                   >> 0x14U)))) 
                                | (0x2027U == (0x707fU 
                                               & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                   << 0xcU) 
                                                  | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                     >> 0x14U)))))));
        bufp->chgBit(oldp+783,(vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__RD_bank));
        bufp->chgBit(oldp+784,(vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__RS1_bank));
        bufp->chgBit(oldp+785,(vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__RS2_bank));
        bufp->chgCData(oldp+786,(vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__alu_operation),4);
        bufp->chgCData(oldp+787,(((0x17U == (0x7fU 
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
        bufp->chgCData(oldp+788,(vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__alu_operand2),5);
        bufp->chgBit(oldp+789,(((0x2007U == (0x707fU 
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
        bufp->chgCData(oldp+790,(vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__memory_width),2);
        bufp->chgBit(oldp+791,(((3U == (0x707fU & (
                                                   (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                    << 0xcU) 
                                                   | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                      >> 0x14U)))) 
                                | (0x1003U == (0x707fU 
                                               & ((vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[3U] 
                                                   << 0xcU) 
                                                  | (vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data[2U] 
                                                     >> 0x14U)))))));
        bufp->chgBit(oldp+792,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT____Vcellinp__df__rst));
        bufp->chgWData(oldp+793,(vlSelfRef.CPU_top__DOT__cpu__DOT__fetch_data),117);
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[9U]))) {
        bufp->chgIData(oldp+797,(vlSelfRef.CPU_top__DOT__cpu__DOT__forward__DOT__rs1),32);
        bufp->chgIData(oldp+798,(vlSelfRef.CPU_top__DOT__cpu__DOT__forward__DOT__rs2),32);
        bufp->chgIData(oldp+799,(vlSelfRef.CPU_top__DOT__cpu__DOT__forward__DOT__rs3),32);
        bufp->chgIData(oldp+800,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__alu_operand1),32);
        bufp->chgIData(oldp+801,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__alu_operand2),32);
        bufp->chgIData(oldp+802,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__alu_signed_sum_result),32);
        bufp->chgBit(oldp+803,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__alu_compare_result));
        bufp->chgIData(oldp+804,((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__alu_operand1 
                                  - vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__alu_operand2)),32);
        bufp->chgIData(oldp+805,((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__alu_operand1 
                                  & vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__alu_operand2)),32);
        bufp->chgIData(oldp+806,((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__alu_operand1 
                                  | vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__alu_operand2)),32);
        bufp->chgIData(oldp+807,((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__alu_operand1 
                                  ^ vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__alu_operand2)),32);
        bufp->chgIData(oldp+808,((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__alu_operand1 
                                  << (0x1fU & vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__alu_operand2))),32);
        bufp->chgIData(oldp+809,((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__alu_operand1 
                                  >> (0x1fU & vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__alu_operand2))),32);
        bufp->chgIData(oldp+810,(VL_SHIFTRS_III(32,32,5, vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__alu_operand1, 
                                                (0x1fU 
                                                 & vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__alu_operand2))),32);
        bufp->chgBit(oldp+811,(VL_LTS_III(32, vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__alu_operand1, vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__alu_operand2)));
        bufp->chgBit(oldp+812,((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__alu_operand1 
                                < vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__alu_operand2)));
        bufp->chgBit(oldp+813,((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__alu_operand1 
                                == vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__alu_operand2)));
        bufp->chgBit(oldp+814,((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__alu_operand1 
                                != vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__alu_operand2)));
        bufp->chgBit(oldp+815,(VL_GTES_III(32, vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__alu_operand1, vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__alu_operand2)));
        bufp->chgBit(oldp+816,((vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__alu_operand1 
                                >= vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__alu_operand2)));
        bufp->chgBit(oldp+817,((vlSelfRef.CPU_top__DOT__cpu__DOT__forward__DOT__rs1 
                                >> 0x1fU)));
        bufp->chgBit(oldp+818,((vlSelfRef.CPU_top__DOT__cpu__DOT__forward__DOT__rs2 
                                >> 0x1fU)));
    }
    bufp->chgBit(oldp+819,(vlSelfRef.reset));
    bufp->chgBit(oldp+820,(vlSelfRef.clock));
    bufp->chgBit(oldp+821,(vlSelfRef.timer_interrupt));
    bufp->chgBit(oldp+822,(vlSelfRef.external_interrupt));
    bufp->chgBit(oldp+823,(vlSelfRef.bus_rw));
    bufp->chgBit(oldp+824,(vlSelfRef.bus_request));
    bufp->chgBit(oldp+825,(vlSelfRef.bus_ready));
    bufp->chgIData(oldp+826,(vlSelfRef.bus_address),32);
    bufp->chgIData(oldp+827,(vlSelfRef.bus_rdata),32);
    bufp->chgIData(oldp+828,(vlSelfRef.bus_wdata),32);
    bufp->chgBit(oldp+829,(vlSelfRef.cpu_fault));
    bufp->chgBit(oldp+830,(((IData)(vlSelfRef.CPU_top__DOT__cpu_ibus_request) 
                            & ((1U == (IData)(vlSelfRef.CPU_top__DOT__bus__DOT__state)) 
                               & (IData)(vlSelfRef.bus_ready)))));
    bufp->chgBit(oldp+831,(vlSelfRef.CPU_top__DOT__cpu_dbus_ready));
    bufp->chgCData(oldp+832,(vlSelfRef.CPU_top__DOT__bus__DOT__next_state),2);
    bufp->chgIData(oldp+833,(((0U == (0xfU & (vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[0U] 
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
    bufp->chgIData(oldp+834,(((6U == (0xfU & (vlSelfRef.CPU_top__DOT__cpu__DOT__decode__DOT__data[0U] 
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
    bufp->chgBit(oldp+835,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__div_ready));
    bufp->chgIData(oldp+836,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__div_result),32);
    bufp->chgIData(oldp+837,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__div_remainder),32);
    bufp->chgIData(oldp+838,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__quotient
                             [0x20U]),32);
    bufp->chgBit(oldp+839,(vlSelfRef.CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__ack));
    bufp->chgBit(oldp+840,(vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__genblk1__DOT__dcache__DOT__wb_ready));
    bufp->chgBit(oldp+841,(vlSelfRef.CPU_top__DOT__cpu__DOT__memory__DOT__genblk1__DOT__dcache__DOT__wb__DOT__next_wb_dirty));
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
}
