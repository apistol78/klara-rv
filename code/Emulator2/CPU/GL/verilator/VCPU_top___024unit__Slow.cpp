// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VCPU_top.h for the primary calling header

#include "VCPU_top__pch.h"
#include "VCPU_top__Syms.h"
#include "VCPU_top___024unit.h"

void VCPU_top___024unit___ctor_var_reset(VCPU_top___024unit* vlSelf);

VCPU_top___024unit::VCPU_top___024unit(VCPU_top__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    VCPU_top___024unit___ctor_var_reset(this);
}

void VCPU_top___024unit::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

VCPU_top___024unit::~VCPU_top___024unit() {
}
