// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vtb_RISCV_Pipeline__pch.h"
#include "verilated_vcd_c.h"

//============================================================
// Constructors

Vtb_RISCV_Pipeline::Vtb_RISCV_Pipeline(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vtb_RISCV_Pipeline__Syms(contextp(), _vcname__, this)}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
    contextp()->traceBaseModelCbAdd(
        [this](VerilatedTraceBaseC* tfp, int levels, int options) { traceBaseModel(tfp, levels, options); });
}

Vtb_RISCV_Pipeline::Vtb_RISCV_Pipeline(const char* _vcname__)
    : Vtb_RISCV_Pipeline(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vtb_RISCV_Pipeline::~Vtb_RISCV_Pipeline() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vtb_RISCV_Pipeline___024root___eval_debug_assertions(Vtb_RISCV_Pipeline___024root* vlSelf);
#endif  // VL_DEBUG
void Vtb_RISCV_Pipeline___024root___eval_static(Vtb_RISCV_Pipeline___024root* vlSelf);
void Vtb_RISCV_Pipeline___024root___eval_initial(Vtb_RISCV_Pipeline___024root* vlSelf);
void Vtb_RISCV_Pipeline___024root___eval_settle(Vtb_RISCV_Pipeline___024root* vlSelf);
void Vtb_RISCV_Pipeline___024root___eval(Vtb_RISCV_Pipeline___024root* vlSelf);

void Vtb_RISCV_Pipeline::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vtb_RISCV_Pipeline::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vtb_RISCV_Pipeline___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_activity = true;
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vtb_RISCV_Pipeline___024root___eval_static(&(vlSymsp->TOP));
        Vtb_RISCV_Pipeline___024root___eval_initial(&(vlSymsp->TOP));
        Vtb_RISCV_Pipeline___024root___eval_settle(&(vlSymsp->TOP));
        vlSymsp->__Vm_didInit = true;
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vtb_RISCV_Pipeline___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

void Vtb_RISCV_Pipeline::eval_end_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+eval_end_step Vtb_RISCV_Pipeline::eval_end_step\n"); );
#ifdef VM_TRACE
    // Tracing
    if (VL_UNLIKELY(vlSymsp->__Vm_dumping)) vlSymsp->_traceDump();
#endif  // VM_TRACE
}

//============================================================
// Events and timing
bool Vtb_RISCV_Pipeline::eventsPending() { return !vlSymsp->TOP.__VdlySched.empty() && !contextp()->gotFinish(); }

uint64_t Vtb_RISCV_Pipeline::nextTimeSlot() { return vlSymsp->TOP.__VdlySched.nextTimeSlot(); }

//============================================================
// Utilities

const char* Vtb_RISCV_Pipeline::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vtb_RISCV_Pipeline___024root___eval_final(Vtb_RISCV_Pipeline___024root* vlSelf);

VL_ATTR_COLD void Vtb_RISCV_Pipeline::final() {
    contextp()->executingFinal(true);
    Vtb_RISCV_Pipeline___024root___eval_final(&(vlSymsp->TOP));
    contextp()->executingFinal(false);
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vtb_RISCV_Pipeline::hierName() const { return vlSymsp->name(); }
const char* Vtb_RISCV_Pipeline::modelName() const { return "Vtb_RISCV_Pipeline"; }
unsigned Vtb_RISCV_Pipeline::threads() const { return 1; }
void Vtb_RISCV_Pipeline::prepareClone() const { contextp()->prepareClone(); }
void Vtb_RISCV_Pipeline::atClone() const {
    contextp()->threadPoolpOnClone();
}
std::unique_ptr<VerilatedTraceConfig> Vtb_RISCV_Pipeline::traceConfig() const {
    return std::unique_ptr<VerilatedTraceConfig>{new VerilatedTraceConfig{false}};
};

//============================================================
// Trace configuration

void Vtb_RISCV_Pipeline___024root__trace_decl_types(VerilatedVcd* tracep);

void Vtb_RISCV_Pipeline___024root__trace_init_top(Vtb_RISCV_Pipeline___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vtb_RISCV_Pipeline___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtb_RISCV_Pipeline___024root*>(voidSelf);
    Vtb_RISCV_Pipeline__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->pushPrefix(vlSymsp->name(), VerilatedTracePrefixType::SCOPE_MODULE);
    Vtb_RISCV_Pipeline___024root__trace_decl_types(tracep);
    Vtb_RISCV_Pipeline___024root__trace_init_top(vlSelf, tracep);
    tracep->popPrefix();
}

VL_ATTR_COLD void Vtb_RISCV_Pipeline___024root__trace_register(Vtb_RISCV_Pipeline___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void Vtb_RISCV_Pipeline::traceBaseModel(VerilatedTraceBaseC* tfp, int levels, int options) {
    (void)levels; (void)options;
    VerilatedVcdC* const stfp = dynamic_cast<VerilatedVcdC*>(tfp);
    if (VL_UNLIKELY(!stfp)) {
        vl_fatal(__FILE__, __LINE__, __FILE__,"'Vtb_RISCV_Pipeline::trace()' called on non-VerilatedVcdC object;"
            " use --trace-fst with VerilatedFst object, and --trace-vcd with VerilatedVcd object");
    }
    stfp->spTrace()->addModel(this);
    stfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP), name(), false, 178);
    Vtb_RISCV_Pipeline___024root__trace_register(&(vlSymsp->TOP), stfp->spTrace());
}
