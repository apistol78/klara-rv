// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VCPU_top.h for the primary calling header

#include "VCPU_top__pch.h"
#include "VCPU_top__Syms.h"
#include "VCPU_top___024root.h"

void VCPU_top___024root___ctor_var_reset(VCPU_top___024root* vlSelf);

VCPU_top___024root::VCPU_top___024root(VCPU_top__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    VCPU_top___024root___ctor_var_reset(this);
}

void VCPU_top___024root::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

VCPU_top___024root::~VCPU_top___024root() {
}
