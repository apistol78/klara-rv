// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "VCPU_top__pch.h"
#include "VCPU_top.h"
#include "VCPU_top___024root.h"
#include "VCPU_top___024unit.h"

// FUNCTIONS
VCPU_top__Syms::~VCPU_top__Syms()
{
}

VCPU_top__Syms::VCPU_top__Syms(VerilatedContext* contextp, const char* namep, VCPU_top* modelp)
    : VerilatedSyms{contextp}
    // Setup internal state of the Syms class
    , __Vm_modelp{modelp}
    // Setup module instances
    , TOP{this, namep}
{
        // Check resources
        Verilated::stackCheck(1269);
    // Configure time unit / time precision
    _vm_contextp__->timeunit(-9);
    _vm_contextp__->timeprecision(-9);
    // Setup each module's pointers to their submodules
    // Setup each module's pointer back to symbol table (for public functions)
    TOP.__Vconfigure(true);
}
