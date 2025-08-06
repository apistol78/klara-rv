// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See VCPU_top.h for the primary calling header

#ifndef VERILATED_VCPU_TOP___024ROOT_H_
#define VERILATED_VCPU_TOP___024ROOT_H_  // guard

#include "verilated.h"


class VCPU_top__Syms;

class alignas(VL_CACHE_LINE_BYTES) VCPU_top___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        VL_IN8(reset,0,0);
        VL_IN8(clock,0,0);
        CData/*0:0*/ CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT____Vcellinp__df__rst;
        VL_IN8(timer_interrupt,0,0);
        VL_IN8(external_interrupt,0,0);
        VL_OUT8(bus_rw,0,0);
        VL_OUT8(bus_request,0,0);
        VL_IN8(bus_ready,0,0);
        VL_OUT8(cpu_fault,0,0);
        CData/*0:0*/ CPU_top__DOT__cpu_ibus_request;
        CData/*0:0*/ CPU_top__DOT__cpu_ibus_ready;
        CData/*0:0*/ CPU_top__DOT__cpu_dbus_rw;
        CData/*0:0*/ CPU_top__DOT__cpu_dbus_request;
        CData/*0:0*/ CPU_top__DOT__cpu_dbus_ready;
        CData/*1:0*/ CPU_top__DOT__bus__DOT__state;
        CData/*1:0*/ CPU_top__DOT__bus__DOT__next_state;
        CData/*0:0*/ CPU_top__DOT__cpu__DOT__csr_wdata_wr;
        CData/*0:0*/ CPU_top__DOT__cpu__DOT__csr_irq_pending;
        CData/*0:0*/ CPU_top__DOT__cpu__DOT__csr_irq_dispatched;
        CData/*0:0*/ CPU_top__DOT__cpu__DOT____Vcellinp__fetch__i_busy;
        CData/*0:0*/ CPU_top__DOT__cpu__DOT__decode_fault;
        CData/*0:0*/ CPU_top__DOT__cpu__DOT__execute_fault;
        CData/*0:0*/ CPU_top__DOT__cpu__DOT__execute_jump;
        CData/*0:0*/ CPU_top__DOT__cpu__DOT__execute_ecall;
        CData/*0:0*/ CPU_top__DOT__cpu__DOT__execute_mret;
        CData/*0:0*/ CPU_top__DOT__cpu__DOT__memory_busy;
        CData/*0:0*/ CPU_top__DOT__cpu__DOT__csr__DOT__mstatus_mpie;
        CData/*0:0*/ CPU_top__DOT__cpu__DOT__csr__DOT__mstatus_mie;
        CData/*0:0*/ CPU_top__DOT__cpu__DOT__csr__DOT__mie_meie;
        CData/*0:0*/ CPU_top__DOT__cpu__DOT__csr__DOT__mie_mtie;
        CData/*0:0*/ CPU_top__DOT__cpu__DOT__csr__DOT__mie_msie;
        CData/*0:0*/ CPU_top__DOT__cpu__DOT__csr__DOT__mip_meip;
        CData/*0:0*/ CPU_top__DOT__cpu__DOT__csr__DOT__mip_mtip;
        CData/*0:0*/ CPU_top__DOT__cpu__DOT__csr__DOT__mip_msip;
        CData/*2:0*/ CPU_top__DOT__cpu__DOT__csr__DOT__issued;
        CData/*0:0*/ CPU_top__DOT__cpu__DOT__registers__DOT__last_write_strobe;
        CData/*1:0*/ CPU_top__DOT__cpu__DOT__fetch__DOT__state;
        CData/*0:0*/ CPU_top__DOT__cpu__DOT__fetch__DOT__icache_ready;
        CData/*0:0*/ CPU_top__DOT__cpu__DOT__fetch__DOT__is_I;
        CData/*0:0*/ CPU_top__DOT__cpu__DOT__fetch__DOT__is_R;
        CData/*0:0*/ CPU_top__DOT__cpu__DOT__fetch__DOT__is_S;
        CData/*0:0*/ CPU_top__DOT__cpu__DOT__fetch__DOT__is_JUMP_CONDITIONAL;
        CData/*0:0*/ CPU_top__DOT__cpu__DOT__fetch__DOT__is_FPU;
        CData/*0:0*/ CPU_top__DOT__cpu__DOT__fetch__DOT__RD_bank;
        CData/*0:0*/ CPU_top__DOT__cpu__DOT__fetch__DOT__RS1_bank;
        CData/*0:0*/ CPU_top__DOT__cpu__DOT__fetch__DOT__RS2_bank;
        CData/*0:0*/ CPU_top__DOT__cpu__DOT__fetch__DOT__have_RS3;
        CData/*0:0*/ CPU_top__DOT__cpu__DOT__fetch__DOT__irq_pending_r;
        CData/*0:0*/ CPU_top__DOT__cpu__DOT__fetch__DOT____VdfgRegularize_hef2daed4_0_8;
        CData/*0:0*/ CPU_top__DOT__cpu__DOT__fetch__DOT____VdfgRegularize_hef2daed4_0_14;
        CData/*0:0*/ CPU_top__DOT__cpu__DOT__fetch__DOT____VdfgRegularize_hef2daed4_0_17;
        CData/*0:0*/ CPU_top__DOT__cpu__DOT__fetch__DOT____VdfgRegularize_hef2daed4_0_18;
        CData/*0:0*/ CPU_top__DOT__cpu__DOT__fetch__DOT____VdfgRegularize_hef2daed4_0_19;
        CData/*0:0*/ CPU_top__DOT__cpu__DOT__fetch__DOT____VdfgRegularize_hef2daed4_0_20;
        CData/*0:0*/ CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT__initialized;
        CData/*0:0*/ CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT__cache_invalid;
        CData/*0:0*/ CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT__cache_wr_request;
        CData/*0:0*/ CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT__cache__DOT__o_pa_ready;
        CData/*0:0*/ CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT__cache__DOT__o_pb_ready;
        CData/*0:0*/ CPU_top__DOT__cpu__DOT__decode__DOT__is_B;
        CData/*0:0*/ CPU_top__DOT__cpu__DOT__decode__DOT__is_I;
        CData/*0:0*/ CPU_top__DOT__cpu__DOT__decode__DOT__is_R;
        CData/*0:0*/ CPU_top__DOT__cpu__DOT__decode__DOT__is_S;
        CData/*0:0*/ CPU_top__DOT__cpu__DOT__decode__DOT__is_U;
    };
    struct {
        CData/*0:0*/ CPU_top__DOT__cpu__DOT__decode__DOT__is_CSR;
        CData/*0:0*/ CPU_top__DOT__cpu__DOT__decode__DOT__is_FPU;
        CData/*0:0*/ CPU_top__DOT__cpu__DOT__decode__DOT__RD_bank;
        CData/*0:0*/ CPU_top__DOT__cpu__DOT__decode__DOT__RS1_bank;
        CData/*0:0*/ CPU_top__DOT__cpu__DOT__decode__DOT__RS2_bank;
        CData/*3:0*/ CPU_top__DOT__cpu__DOT__decode__DOT__alu_operation;
        CData/*4:0*/ CPU_top__DOT__cpu__DOT__decode__DOT__alu_operand2;
        CData/*1:0*/ CPU_top__DOT__cpu__DOT__decode__DOT__memory_width;
        CData/*0:0*/ CPU_top__DOT__cpu__DOT__decode__DOT__have_RS3;
        CData/*0:0*/ CPU_top__DOT__cpu__DOT__decode__DOT____VdfgRegularize_h2cfc3394_0_9;
        CData/*0:0*/ CPU_top__DOT__cpu__DOT__decode__DOT____VdfgRegularize_h2cfc3394_0_18;
        CData/*0:0*/ CPU_top__DOT__cpu__DOT__decode__DOT____VdfgRegularize_h2cfc3394_0_19;
        CData/*0:0*/ CPU_top__DOT__cpu__DOT__decode__DOT____VdfgRegularize_h2cfc3394_0_20;
        CData/*0:0*/ CPU_top__DOT__cpu__DOT__decode__DOT____VdfgRegularize_h2cfc3394_0_23;
        CData/*0:0*/ CPU_top__DOT__cpu__DOT__decode__DOT____VdfgRegularize_h2cfc3394_0_24;
        CData/*0:0*/ CPU_top__DOT__cpu__DOT__decode__DOT____VdfgRegularize_h2cfc3394_0_25;
        CData/*0:0*/ CPU_top__DOT__cpu__DOT__decode__DOT____VdfgRegularize_h2cfc3394_0_26;
        CData/*0:0*/ CPU_top__DOT__cpu__DOT__execute__DOT__alu_compare_result;
        CData/*0:0*/ CPU_top__DOT__cpu__DOT__execute__DOT__mul_request;
        CData/*0:0*/ CPU_top__DOT__cpu__DOT__execute__DOT__mul_signed;
        CData/*0:0*/ CPU_top__DOT__cpu__DOT__execute__DOT__div_request;
        CData/*0:0*/ CPU_top__DOT__cpu__DOT__execute__DOT__div_signed;
        CData/*0:0*/ CPU_top__DOT__cpu__DOT__execute__DOT__div_ready;
        CData/*0:0*/ CPU_top__DOT__cpu__DOT__execute__DOT__last_strobe;
        CData/*0:0*/ CPU_top__DOT__cpu__DOT__execute__DOT__multiply__DOT__r0_request;
        CData/*1:0*/ CPU_top__DOT__cpu__DOT__execute__DOT__multiply__DOT__r0_s;
        CData/*0:0*/ CPU_top__DOT__cpu__DOT__execute__DOT__multiply__DOT__r1_request;
        CData/*1:0*/ CPU_top__DOT__cpu__DOT__execute__DOT__multiply__DOT__r1_s;
        CData/*0:0*/ CPU_top__DOT__cpu__DOT__execute__DOT__multiply__DOT__r2_request;
        CData/*1:0*/ CPU_top__DOT__cpu__DOT__execute__DOT__multiply__DOT__latch;
        CData/*1:0*/ CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__s;
        CData/*0:0*/ CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__ack;
        CData/*0:0*/ CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__0__KET____DOT__q;
        CData/*0:0*/ CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__1__KET____DOT__q;
        CData/*0:0*/ CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__2__KET____DOT__q;
        CData/*0:0*/ CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__3__KET____DOT__q;
        CData/*0:0*/ CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__4__KET____DOT__q;
        CData/*0:0*/ CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__5__KET____DOT__q;
        CData/*0:0*/ CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__6__KET____DOT__q;
        CData/*0:0*/ CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__7__KET____DOT__q;
        CData/*0:0*/ CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__8__KET____DOT__q;
        CData/*0:0*/ CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__9__KET____DOT__q;
        CData/*0:0*/ CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__10__KET____DOT__q;
        CData/*0:0*/ CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__11__KET____DOT__q;
        CData/*0:0*/ CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__12__KET____DOT__q;
        CData/*0:0*/ CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__13__KET____DOT__q;
        CData/*0:0*/ CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__14__KET____DOT__q;
        CData/*0:0*/ CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__15__KET____DOT__q;
        CData/*0:0*/ CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__16__KET____DOT__q;
        CData/*0:0*/ CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__17__KET____DOT__q;
        CData/*0:0*/ CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__18__KET____DOT__q;
        CData/*0:0*/ CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__19__KET____DOT__q;
        CData/*0:0*/ CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__20__KET____DOT__q;
        CData/*0:0*/ CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__21__KET____DOT__q;
        CData/*0:0*/ CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__22__KET____DOT__q;
        CData/*0:0*/ CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__23__KET____DOT__q;
        CData/*0:0*/ CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__24__KET____DOT__q;
        CData/*0:0*/ CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__25__KET____DOT__q;
        CData/*0:0*/ CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__26__KET____DOT__q;
        CData/*0:0*/ CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__27__KET____DOT__q;
        CData/*0:0*/ CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__28__KET____DOT__q;
        CData/*0:0*/ CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__29__KET____DOT__q;
        CData/*0:0*/ CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__30__KET____DOT__q;
        CData/*0:0*/ CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__31__KET____DOT__q;
    };
    struct {
        CData/*0:0*/ CPU_top__DOT__cpu__DOT__memory__DOT__dcache_rw;
        CData/*0:0*/ CPU_top__DOT__cpu__DOT__memory__DOT__dcache_request;
        CData/*0:0*/ CPU_top__DOT__cpu__DOT__memory__DOT__dcache_flush;
        CData/*0:0*/ CPU_top__DOT__cpu__DOT__memory__DOT__dcache_ready;
        CData/*2:0*/ CPU_top__DOT__cpu__DOT__memory__DOT__state;
        CData/*0:0*/ CPU_top__DOT__cpu__DOT__memory__DOT__last_strobe;
        CData/*3:0*/ CPU_top__DOT__cpu__DOT__memory__DOT__genblk1__DOT__dcache__DOT__state;
        CData/*0:0*/ CPU_top__DOT__cpu__DOT__memory__DOT__genblk1__DOT__dcache__DOT__wb_rw;
        CData/*0:0*/ CPU_top__DOT__cpu__DOT__memory__DOT__genblk1__DOT__dcache__DOT__wb_request;
        CData/*0:0*/ CPU_top__DOT__cpu__DOT__memory__DOT__genblk1__DOT__dcache__DOT__wb_ready;
        CData/*0:0*/ CPU_top__DOT__cpu__DOT__memory__DOT__genblk1__DOT__dcache__DOT__wb_cached;
        CData/*0:0*/ CPU_top__DOT__cpu__DOT__memory__DOT__genblk1__DOT__dcache__DOT__cache_rw;
        CData/*0:0*/ CPU_top__DOT__cpu__DOT__memory__DOT__genblk1__DOT__dcache__DOT__wb__DOT__all_dirty;
        CData/*0:0*/ CPU_top__DOT__cpu__DOT__memory__DOT__genblk1__DOT__dcache__DOT__wb__DOT__any_dirty;
        CData/*0:0*/ CPU_top__DOT__cpu__DOT__memory__DOT__genblk1__DOT__dcache__DOT__cache__DOT__o_ready;
        CData/*0:0*/ CPU_top__DOT__cpu__DOT__memory__DOT__genblk1__DOT__dcache__DOT__cache__DOT__o_valid;
        CData/*0:0*/ CPU_top__DOT__cpu__DOT__writeback__DOT__last_strobe;
        CData/*0:0*/ __VdfgRegularize_hd87f99a1_3_0;
        CData/*0:0*/ __VdfgRegularize_hd87f99a1_8_0;
        CData/*0:0*/ __VstlDidInit;
        CData/*0:0*/ __VstlFirstIteration;
        CData/*0:0*/ __VicoFirstIteration;
        CData/*0:0*/ __Vtrigprevexpr___TOP__clock__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__reset__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT____Vcellinp__df__rst__0;
        CData/*0:0*/ __VactDidInit;
        CData/*0:0*/ __VactContinue;
        SData/*13:0*/ CPU_top__DOT__cpu__DOT__csr__DOT__prescale;
        SData/*11:0*/ CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT__cache_rd_set;
        SData/*11:0*/ CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT__cache_wr_set;
        SData/*11:0*/ CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT__set_r;
        SData/*12:0*/ CPU_top__DOT__cpu__DOT__memory__DOT__genblk1__DOT__dcache__DOT__flush_address;
        SData/*11:0*/ CPU_top__DOT__cpu__DOT__memory__DOT__genblk1__DOT__dcache__DOT__cache_address;
        VL_OUT(bus_address,31,0);
        VL_IN(bus_rdata,31,0);
        VL_OUT(bus_wdata,31,0);
        IData/*31:0*/ CPU_top__DOT__cpu_ibus_address;
        IData/*31:0*/ CPU_top__DOT__cpu_dbus_address;
        IData/*31:0*/ CPU_top__DOT__cpu_dbus_wdata;
        IData/*31:0*/ CPU_top__DOT__cpu__DOT__o_dcache_hit;
        IData/*31:0*/ CPU_top__DOT__cpu__DOT__o_dcache_miss;
        IData/*31:0*/ CPU_top__DOT__cpu__DOT__csr_rdata;
        IData/*31:0*/ CPU_top__DOT__cpu__DOT__csr_wdata;
        IData/*31:0*/ CPU_top__DOT__cpu__DOT__csr_irq_pc;
        IData/*31:0*/ CPU_top__DOT__cpu__DOT__csr_irq_epc;
        IData/*31:0*/ CPU_top__DOT__cpu__DOT__execute_jump_pc;
        IData/*31:0*/ CPU_top__DOT__cpu__DOT__csr__DOT__mtvec;
        IData/*31:0*/ CPU_top__DOT__cpu__DOT__csr__DOT__mepc;
        IData/*31:0*/ CPU_top__DOT__cpu__DOT__csr__DOT__mcause;
        IData/*31:0*/ CPU_top__DOT__cpu__DOT__csr__DOT__mscratch;
        IData/*31:0*/ CPU_top__DOT__cpu__DOT__registers__DOT__rs1;
        IData/*31:0*/ CPU_top__DOT__cpu__DOT__registers__DOT__rs2;
        IData/*31:0*/ CPU_top__DOT__cpu__DOT__registers__DOT__rs3;
        IData/*31:0*/ CPU_top__DOT__cpu__DOT__registers__DOT__I;
        IData/*31:0*/ CPU_top__DOT__cpu__DOT__fetch__DOT__pc;
        IData/*31:0*/ CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT__clear_set;
        VlWide<4>/*116:0*/ CPU_top__DOT__cpu__DOT__fetch_skid__DOT__r_data;
        IData/*31:0*/ CPU_top__DOT__cpu__DOT__forward__DOT__rs1;
        IData/*31:0*/ CPU_top__DOT__cpu__DOT__forward__DOT__rs2;
        IData/*31:0*/ CPU_top__DOT__cpu__DOT__forward__DOT__rs3;
        IData/*31:0*/ CPU_top__DOT__cpu__DOT__execute__DOT__alu_operand1;
        IData/*31:0*/ CPU_top__DOT__cpu__DOT__execute__DOT__alu_operand2;
        IData/*31:0*/ CPU_top__DOT__cpu__DOT__execute__DOT__alu_signed_sum_result;
        IData/*31:0*/ CPU_top__DOT__cpu__DOT__execute__DOT__div_result;
    };
    struct {
        IData/*31:0*/ CPU_top__DOT__cpu__DOT__execute__DOT__div_remainder;
        IData/*31:0*/ CPU_top__DOT__cpu__DOT__execute__DOT__multiply__DOT__r0_uop1;
        IData/*31:0*/ CPU_top__DOT__cpu__DOT__execute__DOT__multiply__DOT__r0_uop2;
        IData/*31:0*/ CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__31__KET____DOT__t;
        IData/*31:0*/ CPU_top__DOT__cpu__DOT__memory__DOT__dcache_rdata;
        IData/*31:0*/ CPU_top__DOT__cpu__DOT__memory__DOT__dcache_wdata;
        IData/*31:0*/ CPU_top__DOT__cpu__DOT__memory__DOT__rmw_rdata;
        IData/*31:0*/ CPU_top__DOT__cpu__DOT__memory__DOT____VdfgRegularize_h9eb5ee7c_0_0;
        IData/*31:0*/ CPU_top__DOT__cpu__DOT__memory__DOT__genblk1__DOT__dcache__DOT__wb_address;
        IData/*31:0*/ CPU_top__DOT__cpu__DOT__memory__DOT__genblk1__DOT__dcache__DOT__wb_wdata;
        IData/*31:0*/ CPU_top__DOT__cpu__DOT__memory__DOT__genblk1__DOT__dcache__DOT__wb__DOT__unnamedblk1__DOT__i;
        IData/*31:0*/ CPU_top__DOT__cpu__DOT__memory__DOT__genblk1__DOT__dcache__DOT__wb__DOT__unnamedblk2__DOT__i;
        IData/*31:0*/ CPU_top__DOT__cpu__DOT__writeback__DOT__last_pc;
        IData/*31:0*/ __VactIterCount;
        VlWide<4>/*116:0*/ CPU_top__DOT__cpu__DOT__fetch_data;
        QData/*63:0*/ CPU_top__DOT__cpu__DOT__csr__DOT__cycle;
        QData/*63:0*/ CPU_top__DOT__cpu__DOT__csr__DOT__wtime;
        VlWide<4>/*116:0*/ CPU_top__DOT__cpu__DOT__fetch__DOT__data;
        QData/*50:0*/ CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT__cache_wr_wdata;
        QData/*50:0*/ CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT____Vcellout__cache__o_pa_rdata;
        VlWide<4>/*117:0*/ CPU_top__DOT__cpu__DOT__decode__DOT__data;
        VlWide<4>/*112:0*/ CPU_top__DOT__cpu__DOT__execute__DOT__data;
        QData/*63:0*/ CPU_top__DOT__cpu__DOT__execute__DOT__multiply__DOT__r1_intermediate;
        QData/*63:0*/ CPU_top__DOT__cpu__DOT__execute__DOT__multiply__DOT__r2_result;
        QData/*32:0*/ CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__0__KET____DOT__d;
        QData/*34:0*/ CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__2__KET____DOT__d;
        QData/*38:0*/ CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__6__KET____DOT__d;
        QData/*42:0*/ CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__10__KET____DOT__d;
        QData/*46:0*/ CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__14__KET____DOT__d;
        QData/*50:0*/ CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__18__KET____DOT__d;
        QData/*54:0*/ CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__22__KET____DOT__d;
        QData/*58:0*/ CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__26__KET____DOT__d;
        QData/*61:0*/ CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__gen_div__BRA__29__KET____DOT__d;
        VlWide<3>/*69:0*/ CPU_top__DOT__cpu__DOT__memory__DOT__data;
        QData/*63:0*/ CPU_top__DOT__cpu__DOT__memory__DOT__genblk1__DOT__dcache__DOT__cache_wdata;
        QData/*63:0*/ CPU_top__DOT__cpu__DOT__memory__DOT__genblk1__DOT__dcache__DOT__cache_rdata;
        QData/*36:0*/ CPU_top__DOT__cpu__DOT__writeback__DOT__data;
        QData/*63:0*/ CPU_top__DOT__cpu__DOT__writeback__DOT__retired;
        VlWide<3>/*69:0*/ __Vdly__CPU_top__DOT__cpu__DOT__memory__DOT__data;
        VlUnpacked<IData/*31:0*/, 32> CPU_top__DOT__cpu__DOT__registers__DOT__r;
        VlUnpacked<QData/*50:0*/, 4096> CPU_top__DOT__cpu__DOT__fetch__DOT__genblk1__DOT__icache__DOT__cache__DOT__data;
        VlUnpacked<CData/*0:0*/, 33> CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__ready;
        VlUnpacked<IData/*31:0*/, 33> CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend;
        VlUnpacked<IData/*31:0*/, 33> CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor;
        VlUnpacked<IData/*31:0*/, 33> CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__quotient;
        VlUnpacked<CData/*0:0*/, 4> CPU_top__DOT__cpu__DOT__memory__DOT__genblk1__DOT__dcache__DOT__wb__DOT__wb_dirty;
        VlUnpacked<IData/*31:0*/, 4> CPU_top__DOT__cpu__DOT__memory__DOT__genblk1__DOT__dcache__DOT__wb__DOT__wb_address;
        VlUnpacked<IData/*31:0*/, 4> CPU_top__DOT__cpu__DOT__memory__DOT__genblk1__DOT__dcache__DOT__wb__DOT__wb_data;
        VlUnpacked<CData/*0:0*/, 4> CPU_top__DOT__cpu__DOT__memory__DOT__genblk1__DOT__dcache__DOT__wb__DOT__next_wb_dirty;
        VlUnpacked<IData/*31:0*/, 4> CPU_top__DOT__cpu__DOT__memory__DOT__genblk1__DOT__dcache__DOT__wb__DOT__next_wb_address;
        VlUnpacked<IData/*31:0*/, 4> CPU_top__DOT__cpu__DOT__memory__DOT__genblk1__DOT__dcache__DOT__wb__DOT__next_wb_data;
        VlUnpacked<QData/*63:0*/, 4096> CPU_top__DOT__cpu__DOT__memory__DOT__genblk1__DOT__dcache__DOT__cache__DOT__data;
        VlUnpacked<IData/*31:0*/, 33> __Vtrigprevexpr___TOP__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__quotient__0;
        VlUnpacked<IData/*31:0*/, 33> __Vtrigprevexpr___TOP__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend__0;
        VlUnpacked<IData/*31:0*/, 33> __Vtrigprevexpr___TOP__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor__0;
        VlUnpacked<CData/*0:0*/, 33> __Vtrigprevexpr___TOP__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__ready__0;
        VlUnpacked<IData/*31:0*/, 33> __Vtrigprevexpr___TOP__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__quotient__1;
        VlUnpacked<IData/*31:0*/, 33> __Vtrigprevexpr___TOP__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__dividend__1;
        VlUnpacked<IData/*31:0*/, 33> __Vtrigprevexpr___TOP__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__divisor__1;
        VlUnpacked<CData/*0:0*/, 33> __Vtrigprevexpr___TOP__CPU_top__DOT__cpu__DOT__execute__DOT__divide__DOT__df__DOT__ready__1;
        VlUnpacked<CData/*0:0*/, 11> __Vm_traceActivity;
    };
    VlTriggerVec<5> __VstlTriggered;
    VlTriggerVec<1> __VicoTriggered;
    VlTriggerVec<7> __VactTriggered;
    VlTriggerVec<7> __VnbaTriggered;

    // INTERNAL VARIABLES
    VCPU_top__Syms* const vlSymsp;

    // CONSTRUCTORS
    VCPU_top___024root(VCPU_top__Syms* symsp, const char* v__name);
    ~VCPU_top___024root();
    VL_UNCOPYABLE(VCPU_top___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
