// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing declarations
#include "verilated_fst_c.h"


void VCPU_top___024root__traceDeclTypesSub0(VerilatedFst* tracep) {
    {
        const char* __VenumItemNames[]
        = {"ZERO", "RA", "SP", "GP", "TP", "T0", "T1", 
                                "T2", "S0", "S1", "A0", 
                                "A1", "A2", "A3", "A4", 
                                "A5", "A6", "A7", "S2", 
                                "S3", "S4", "S5", "S6", 
                                "S7", "S8", "S9", "S10", 
                                "S11", "T3", "T4", 
                                "T5", "T6"};
        const char* __VenumItemValues[]
        = {"0", "1", "10", "11", "100", "101", "110", 
                                "111", "1000", "1001", 
                                "1010", "1011", "1100", 
                                "1101", "1110", "1111", 
                                "10000", "10001", "10010", 
                                "10011", "10100", "10101", 
                                "10110", "10111", "11000", 
                                "11001", "11010", "11011", 
                                "11100", "11101", "11110", 
                                "11111"};
        tracep->declDTypeEnum(1, "$unit::register_t", 32, 5, __VenumItemNames, __VenumItemValues);
    }
    {
        const char* __VenumItemNames[]
        = {"WAIT_ICACHE", "WAIT_JUMP", "WAIT_IRQ"};
        const char* __VenumItemValues[]
        = {"0", "1", "10"};
        tracep->declDTypeEnum(2, "CPU_Fetch.state_t", 3, 2, __VenumItemNames, __VenumItemValues);
    }
    {
        const char* __VenumItemNames[]
        = {"IDLE", "READ", "WRITE_WORD", "WRITE_RMW_0", 
                                "WRITE_RMW_1", "FLUSH"};
        const char* __VenumItemValues[]
        = {"0", "1", "10", "11", "100", "101"};
        tracep->declDTypeEnum(3, "CPU_Memory.state_t", 6, 3, __VenumItemNames, __VenumItemValues);
    }
    {
        const char* __VenumItemNames[]
        = {"IDLE", "FLUSH_SETUP", "FLUSH_CHECK", "FLUSH_WRITE", 
                                "PASS_THROUGH", "WRITE_SETUP", 
                                "WRITE_WAIT", "READ_SETUP", 
                                "READ_WB_WAIT", "READ_BUS_WAIT", 
                                "INITIALIZE"};
        const char* __VenumItemValues[]
        = {"0", "1", "10", "11", "100", "101", "110", 
                                "111", "1000", "1001", 
                                "1010"};
        tracep->declDTypeEnum(4, "CPU_DCache_Reg.state_t", 11, 4, __VenumItemNames, __VenumItemValues);
    }
}

void VCPU_top___024root__trace_decl_types(VerilatedFst* tracep) {
    VCPU_top___024root__traceDeclTypesSub0(tracep);
}
