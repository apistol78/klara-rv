// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See VCPU_top.h for the primary calling header

#ifndef VERILATED_VCPU_TOP___024UNIT_H_
#define VERILATED_VCPU_TOP___024UNIT_H_  // guard

#include "verilated.h"


class VCPU_top__Syms;

class alignas(VL_CACHE_LINE_BYTES) VCPU_top___024unit final : public VerilatedModule {
  public:

    // INTERNAL VARIABLES
    VCPU_top__Syms* const vlSymsp;

    // CONSTRUCTORS
    VCPU_top___024unit(VCPU_top__Syms* symsp, const char* v__name);
    ~VCPU_top___024unit();
    VL_UNCOPYABLE(VCPU_top___024unit);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
