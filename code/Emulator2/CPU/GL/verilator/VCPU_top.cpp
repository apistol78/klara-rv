// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "VCPU_top__pch.h"
#include "verilated_fst_c.h"

//============================================================
// Constructors

VCPU_top::VCPU_top(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new VCPU_top__Syms(contextp(), _vcname__, this)}
    , reset{vlSymsp->TOP.reset}
    , clock{vlSymsp->TOP.clock}
    , timer_interrupt{vlSymsp->TOP.timer_interrupt}
    , external_interrupt{vlSymsp->TOP.external_interrupt}
    , bus_rw{vlSymsp->TOP.bus_rw}
    , bus_request{vlSymsp->TOP.bus_request}
    , bus_ready{vlSymsp->TOP.bus_ready}
    , cpu_fault{vlSymsp->TOP.cpu_fault}
    , bus_address{vlSymsp->TOP.bus_address}
    , bus_rdata{vlSymsp->TOP.bus_rdata}
    , bus_wdata{vlSymsp->TOP.bus_wdata}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
    contextp()->traceBaseModelCbAdd(
        [this](VerilatedTraceBaseC* tfp, int levels, int options) { traceBaseModel(tfp, levels, options); });
}

VCPU_top::VCPU_top(const char* _vcname__)
    : VCPU_top(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

VCPU_top::~VCPU_top() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void VCPU_top___024root___eval_debug_assertions(VCPU_top___024root* vlSelf);
#endif  // VL_DEBUG
void VCPU_top___024root___eval_static(VCPU_top___024root* vlSelf);
void VCPU_top___024root___eval_initial(VCPU_top___024root* vlSelf);
void VCPU_top___024root___eval_settle(VCPU_top___024root* vlSelf);
void VCPU_top___024root___eval(VCPU_top___024root* vlSelf);

void VCPU_top::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate VCPU_top::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    VCPU_top___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_activity = true;
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        VCPU_top___024root___eval_static(&(vlSymsp->TOP));
        VCPU_top___024root___eval_initial(&(vlSymsp->TOP));
        VCPU_top___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    VCPU_top___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool VCPU_top::eventsPending() { return false; }

uint64_t VCPU_top::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* VCPU_top::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void VCPU_top___024root___eval_final(VCPU_top___024root* vlSelf);

VL_ATTR_COLD void VCPU_top::final() {
    VCPU_top___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* VCPU_top::hierName() const { return vlSymsp->name(); }
const char* VCPU_top::modelName() const { return "VCPU_top"; }
unsigned VCPU_top::threads() const { return 1; }
void VCPU_top::prepareClone() const { contextp()->prepareClone(); }
void VCPU_top::atClone() const {
    contextp()->threadPoolpOnClone();
}
std::unique_ptr<VerilatedTraceConfig> VCPU_top::traceConfig() const {
    return std::unique_ptr<VerilatedTraceConfig>{new VerilatedTraceConfig{false, false, false}};
};

//============================================================
// Trace configuration

void VCPU_top___024root__trace_decl_types(VerilatedFst* tracep);

void VCPU_top___024root__trace_init_top(VCPU_top___024root* vlSelf, VerilatedFst* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedFst* tracep, uint32_t code) {
    // Callback from tracep->open()
    VCPU_top___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VCPU_top___024root*>(voidSelf);
    VCPU_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->pushPrefix(std::string{vlSymsp->name()}, VerilatedTracePrefixType::SCOPE_MODULE);
    VCPU_top___024root__trace_decl_types(tracep);
    VCPU_top___024root__trace_init_top(vlSelf, tracep);
    tracep->popPrefix();
}

VL_ATTR_COLD void VCPU_top___024root__trace_register(VCPU_top___024root* vlSelf, VerilatedFst* tracep);

VL_ATTR_COLD void VCPU_top::traceBaseModel(VerilatedTraceBaseC* tfp, int levels, int options) {
    (void)levels; (void)options;
    VerilatedFstC* const stfp = dynamic_cast<VerilatedFstC*>(tfp);
    if (VL_UNLIKELY(!stfp)) {
        vl_fatal(__FILE__, __LINE__, __FILE__,"'VCPU_top::trace()' called on non-VerilatedFstC object;"
            " use --trace-fst with VerilatedFst object, and --trace-vcd with VerilatedVcd object");
    }
    stfp->spTrace()->addModel(this);
    stfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP));
    VCPU_top___024root__trace_register(&(vlSymsp->TOP), stfp->spTrace());
}
