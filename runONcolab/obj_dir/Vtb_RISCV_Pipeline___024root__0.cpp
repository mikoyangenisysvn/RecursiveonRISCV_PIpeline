// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_RISCV_Pipeline.h for the primary calling header

#include "Vtb_RISCV_Pipeline__pch.h"

VlCoroutine Vtb_RISCV_Pipeline___024root___eval_initial__TOP__Vtiming__0(Vtb_RISCV_Pipeline___024root* vlSelf);
VlCoroutine Vtb_RISCV_Pipeline___024root___eval_initial__TOP__Vtiming__1(Vtb_RISCV_Pipeline___024root* vlSelf);
VlCoroutine Vtb_RISCV_Pipeline___024root___eval_initial__TOP__Vtiming__2(Vtb_RISCV_Pipeline___024root* vlSelf);

void Vtb_RISCV_Pipeline___024root___eval_initial(Vtb_RISCV_Pipeline___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_RISCV_Pipeline___024root___eval_initial\n"); );
    Vtb_RISCV_Pipeline__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    {
        // Inlined CFunc: _eval_initial__TOP
        vlSelfRef.tb_RISCV_Pipeline__DOT__clk = 0U;
        vlSelfRef.tb_RISCV_Pipeline__DOT__instr_count = 0U;
        vlSelfRef.tb_RISCV_Pipeline__DOT__stall_count = 0U;
        vlSelfRef.tb_RISCV_Pipeline__DOT__flush_count = 0U;
        vlSelfRef.tb_RISCV_Pipeline__DOT__pipeline_filled = 0U;
        vlSelfRef.tb_RISCV_Pipeline__DOT__PCSel_E_d1 = 0U;
        vlSelfRef.tb_RISCV_Pipeline__DOT__min_sp = 0x00001400U;
        vlSelfRef.tb_RISCV_Pipeline__DOT__min_sp_cycle = 0U;
        vlSelfRef.tb_RISCV_Pipeline__DOT__sp_initialized = 0U;
        vlSelfRef.tb_RISCV_Pipeline__DOT__done_reported = 0U;
        vlSelfRef.tb_RISCV_Pipeline__DOT__done_cycle = 0xffffffffU;
        vlSymsp->_vm_contextp__->dumpfile("waveform.vcd"s);
        vlSymsp->_traceDumpOpen();
    }
    vlSelfRef.__Vm_traceActivity[1U] = 1U;
    Vtb_RISCV_Pipeline___024root___eval_initial__TOP__Vtiming__0(vlSelf);
    Vtb_RISCV_Pipeline___024root___eval_initial__TOP__Vtiming__1(vlSelf);
    Vtb_RISCV_Pipeline___024root___eval_initial__TOP__Vtiming__2(vlSelf);
}

VlCoroutine Vtb_RISCV_Pipeline___024root___eval_initial__TOP__Vtiming__0(Vtb_RISCV_Pipeline___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_RISCV_Pipeline___024root___eval_initial__TOP__Vtiming__0\n"); );
    Vtb_RISCV_Pipeline__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    VL_WRITEF_NX("========================================\n RISC-V Pipeline Test: Recursion/Iteration\n========================================\n",0);
    vlSelfRef.tb_RISCV_Pipeline__DOT__loaded = 0U;
    vlSelfRef.tb_RISCV_Pipeline__DOT__fd = VL_FOPEN_NN("./mem/imem.hex"s
                                                       , "r"s);
    ;
    if (VL_UNLIKELY(((0U != vlSelfRef.tb_RISCV_Pipeline__DOT__fd)))) {
        VL_FCLOSE_I(vlSelfRef.tb_RISCV_Pipeline__DOT__fd); VL_READMEM_N(true
                                                                        , 32
                                                                        , 256
                                                                        , 0
                                                                        , "./mem/imem.hex"s
                                                                        ,  &(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__IMEM_inst__DOT__memory)
                                                                        , 0
                                                                        , ~0ULL);
        VL_WRITEF_NX("[TB] Loaded: ./mem/imem.hex\n",0);
        vlSelfRef.tb_RISCV_Pipeline__DOT__loaded = 1U;
    }
    if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__loaded)))))) {
        VL_WRITEF_NX("[TB] *** ERROR *** Cannot find imem.hex!\n",0);
        VL_FINISH_MT("tb/tb_RISCV_Pipeline.v", 47, "");
    }
    vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__DMEM_inst__DOT__memory[0U] = 0xdeadbeefU;
    VL_WRITEF_NX("[TB] Canary pre-loaded at DMEM word idx 0 = 0xdeadbeef\n",0);
    vlSelfRef.tb_RISCV_Pipeline__DOT__rst_n = 0U;
    co_await vlSelfRef.__VdlySched.delay(0x0000000000004e20ULL, 
                                         nullptr, "tb/tb_RISCV_Pipeline.v", 
                                         55);
    vlSelfRef.tb_RISCV_Pipeline__DOT__rst_n = 1U;
    VL_WRITEF_NX("[TB] Reset released, simulation started\n",0);
    co_return;
}

VlCoroutine Vtb_RISCV_Pipeline___024root___eval_initial__TOP__Vtiming__1(Vtb_RISCV_Pipeline___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_RISCV_Pipeline___024root___eval_initial__TOP__Vtiming__1\n"); );
    Vtb_RISCV_Pipeline__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    co_await vlSelfRef.__VdlySched.delay(0x0000000011e1a300ULL, 
                                         nullptr, "tb/tb_RISCV_Pipeline.v", 
                                         212);
    if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__done_reported)))))) {
        VL_WRITEF_NX("[TB] *** WARNING *** Program never reached the halt loop within timeout.\n",0);
    }
    vlSelfRef.tb_RISCV_Pipeline__DOT__report_result__Vstatic__canary_now 
        = vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__DMEM_inst__DOT__memory[0U];
    vlSelfRef.tb_RISCV_Pipeline__DOT__report_result__Vstatic__a0 
        = vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__Reg_inst__DOT__registers[10U];
    vlSelfRef.tb_RISCV_Pipeline__DOT__report_result__Vstatic__cpi 
        = (VL_LTS_III(32, 0U, vlSelfRef.tb_RISCV_Pipeline__DOT__instr_count)
            ? (VL_ISTOR_D_I(32, vlSelfRef.tb_RISCV_Pipeline__DOT__cycle) 
               / VL_ISTOR_D_I(32, vlSelfRef.tb_RISCV_Pipeline__DOT__instr_count))
            : 0.0);
    vlSelfRef.tb_RISCV_Pipeline__DOT__report_result__Vstatic__stack_used_bytes 
        = ((IData)(0x00001400U) - vlSelfRef.tb_RISCV_Pipeline__DOT__min_sp);
    vlSelfRef.tb_RISCV_Pipeline__DOT__report_result__Vstatic__flush_penalty_cycles 
        = VL_MULS_III(32, (IData)(2U), vlSelfRef.tb_RISCV_Pipeline__DOT__flush_count);
    vlSelfRef.tb_RISCV_Pipeline__DOT__report_result__Vstatic__total_overhead_cycles 
        = (vlSelfRef.tb_RISCV_Pipeline__DOT__stall_count 
           + vlSelfRef.tb_RISCV_Pipeline__DOT__report_result__Vstatic__flush_penalty_cycles);
    VL_WRITEF_NX("========================================\n[TB] Simulation finished at cycle %0d\n[TB] a0 (status) = %0d (0 = pass, nonzero = fail)\n[TB] Canary now  = 0x%08h (expected 0xdeadbeef)\n",3
                 , '~',32,vlSelfRef.tb_RISCV_Pipeline__DOT__cycle
                 , '~',32,vlSelfRef.tb_RISCV_Pipeline__DOT__report_result__Vstatic__a0
                 , '#',32,vlSelfRef.tb_RISCV_Pipeline__DOT__report_result__Vstatic__canary_now);
    if (VL_LIKELY((vlSelfRef.tb_RISCV_Pipeline__DOT__done_reported))) {
        if ((0U == vlSelfRef.tb_RISCV_Pipeline__DOT__report_result__Vstatic__a0)) {
            VL_WRITEF_NX("[TB] *** PASS *** status == 0\n",0);
        } else {
            VL_WRITEF_NX("[TB] *** FAIL *** status == %0d\n",1
                         , '~',32,vlSelfRef.tb_RISCV_Pipeline__DOT__report_result__Vstatic__a0);
        }
    } else {
        VL_WRITEF_NX("[TB] *** INCONCLUSIVE *** halt loop never reached -- so on numbers below are NOT trustworthy\n",0);
    }
    if ((0xdeadbeefU != vlSelfRef.tb_RISCV_Pipeline__DOT__report_result__Vstatic__canary_now)) {
        VL_WRITEF_NX("[TB] *** NOTE *** Canary corrupted -> stack overflow occurred\n",0);
    } else {
        VL_WRITEF_NX("[TB] Canary intact -> no stack overflow detected\n",0);
    }
    if (VL_UNLIKELY((vlSelfRef.tb_RISCV_Pipeline__DOT__done_reported))) {
        VL_WRITEF_NX("[TB] Cycles to completion = %0d\n",1
                     , '~',32,vlSelfRef.tb_RISCV_Pipeline__DOT__done_cycle);
    }
    VL_WRITEF_NX("[TB] Key registers:\n  x1(ra)  = %0d\n  x2(sp)  = %0d\n  x10(a0) = %0d\n----------------------------------------\n[REPORT] --- Architecture / Trade-off metrics ---\n[REPORT] Total cycles                       = %0d\n[REPORT] Instruction count (IC, corrected)  = %0d\n[REPORT] CPI (corrected)                    = %0.3f\n[REPORT] --- Hazard breakdown ---\n[REPORT] Load-Use stall events/cycles       = %0d (%0.1f%% of total)\n[REPORT] Branch/Jump redirect EVENTS        = %0d\n",9
                 , '#',32,vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__Reg_inst__DOT__registers[1U]
                 , '#',32,vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__Reg_inst__DOT__registers[2U]
                 , '#',32,vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__Reg_inst__DOT__registers[10U]
                 , '~',32,vlSelfRef.tb_RISCV_Pipeline__DOT__cycle
                 , '~',32,vlSelfRef.tb_RISCV_Pipeline__DOT__instr_count
                 , 'D',vlSelfRef.tb_RISCV_Pipeline__DOT__report_result__Vstatic__cpi
                 , '~',32,vlSelfRef.tb_RISCV_Pipeline__DOT__stall_count
                 , 'D',((100.0 * VL_ISTOR_D_I(32, vlSelfRef.tb_RISCV_Pipeline__DOT__stall_count)) 
                        / VL_ISTOR_D_I(32, vlSelfRef.tb_RISCV_Pipeline__DOT__cycle))
                 , '~',32,vlSelfRef.tb_RISCV_Pipeline__DOT__flush_count);
    VL_WRITEF_NX("[REPORT] Branch/Jump flush PENALTY cycles   = %0d (2 x events, %0.1f%% of total)\n[REPORT] Total hazard overhead cycles       = %0d (%0.1f%% of total)\n[REPORT] --- Stack usage ---\n[REPORT] Stack top (byte)                   = 5120\n[REPORT] Min sp reached (byte)               = %0d (at cycle %0d)\n[REPORT] Max stack usage (bytes)             = %0d\n----------------------------------------\n",7
                 , '~',32,vlSelfRef.tb_RISCV_Pipeline__DOT__report_result__Vstatic__flush_penalty_cycles
                 , 'D',((100.0 * VL_ISTOR_D_I(32, vlSelfRef.tb_RISCV_Pipeline__DOT__report_result__Vstatic__flush_penalty_cycles)) 
                        / VL_ISTOR_D_I(32, vlSelfRef.tb_RISCV_Pipeline__DOT__cycle))
                 , '~',32,vlSelfRef.tb_RISCV_Pipeline__DOT__report_result__Vstatic__total_overhead_cycles
                 , 'D',((100.0 * VL_ISTOR_D_I(32, vlSelfRef.tb_RISCV_Pipeline__DOT__report_result__Vstatic__total_overhead_cycles)) 
                        / VL_ISTOR_D_I(32, vlSelfRef.tb_RISCV_Pipeline__DOT__cycle))
                 , '~',32,vlSelfRef.tb_RISCV_Pipeline__DOT__min_sp
                 , '~',32,vlSelfRef.tb_RISCV_Pipeline__DOT__min_sp_cycle
                 , '~',32,vlSelfRef.tb_RISCV_Pipeline__DOT__report_result__Vstatic__stack_used_bytes);
    VL_FINISH_MT("tb/tb_RISCV_Pipeline.v", 217, "");
    co_return;
}

VlCoroutine Vtb_RISCV_Pipeline___024root___eval_initial__TOP__Vtiming__2(Vtb_RISCV_Pipeline___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_RISCV_Pipeline___024root___eval_initial__TOP__Vtiming__2\n"); );
    Vtb_RISCV_Pipeline__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    while (VL_LIKELY(!vlSymsp->_vm_contextp__->gotFinish())) {
        co_await vlSelfRef.__VdlySched.delay(0x0000000000001388ULL, 
                                             nullptr, 
                                             "tb/tb_RISCV_Pipeline.v", 
                                             14);
        vlSelfRef.tb_RISCV_Pipeline__DOT__clk = (1U 
                                                 & (~ (IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__clk)));
    }
    co_return;
}

bool Vtb_RISCV_Pipeline___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_RISCV_Pipeline___024root___trigger_anySet__act\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        if (in[n]) {
            return (1U);
        }
        n = ((IData)(1U) + n);
    } while ((1U > n));
    return (0U);
}

extern const VlUnpacked<CData/*0:0*/, 128> Vtb_RISCV_Pipeline__ConstPool__TABLE_h3cb0ade6_0;

void Vtb_RISCV_Pipeline___024root___nba_sequent__TOP__0(Vtb_RISCV_Pipeline___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_RISCV_Pipeline___024root___nba_sequent__TOP__0\n"); );
    Vtb_RISCV_Pipeline__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __Vdly__tb_RISCV_Pipeline__DOT__cycle;
    __Vdly__tb_RISCV_Pipeline__DOT__cycle = 0;
    CData/*0:0*/ __Vdly__tb_RISCV_Pipeline__DOT__pipeline_filled;
    __Vdly__tb_RISCV_Pipeline__DOT__pipeline_filled = 0;
    CData/*0:0*/ __Vdly__tb_RISCV_Pipeline__DOT__sp_initialized;
    __Vdly__tb_RISCV_Pipeline__DOT__sp_initialized = 0;
    // Body
    __Vdly__tb_RISCV_Pipeline__DOT__sp_initialized 
        = vlSelfRef.tb_RISCV_Pipeline__DOT__sp_initialized;
    if (VL_UNLIKELY((((IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__stall_load) 
                      & Vtb_RISCV_Pipeline__ConstPool__TABLE_h3cb0ade6_0
                      [((((IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__BrEq_E) 
                          << 6U) | ((IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__BrLT_E) 
                                    << 5U)) | (((IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__funct3_E) 
                                                << 2U) 
                                               | (((IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__Is_Branch_E) 
                                                   << 1U) 
                                                  | (IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__Is_Jump_E))))])))) {
        VL_WRITEF_NX("[HAZARD-OVERLAP] cycle=%0d - stall_load and PCSel_E both 1! (should be impossible by design -- check control_unit decode)\n",1
                     , '~',32,vlSelfRef.tb_RISCV_Pipeline__DOT__cycle);
    }
    __Vdly__tb_RISCV_Pipeline__DOT__cycle = vlSelfRef.tb_RISCV_Pipeline__DOT__cycle;
    vlSelfRef.__VdlySet__tb_RISCV_Pipeline__DOT__dut__DOT__DMEM_inst__DOT__memory__v0 = 0U;
    vlSelfRef.__VdlySet__tb_RISCV_Pipeline__DOT__dut__DOT__DMEM_inst__DOT__memory__v1 = 0U;
    vlSelfRef.__VdlySet__tb_RISCV_Pipeline__DOT__dut__DOT__DMEM_inst__DOT__memory__v2 = 0U;
    vlSelfRef.__VdlySet__tb_RISCV_Pipeline__DOT__dut__DOT__DMEM_inst__DOT__memory__v3 = 0U;
    vlSelfRef.__VdlySet__tb_RISCV_Pipeline__DOT__dut__DOT__DMEM_inst__DOT__memory__v4 = 0U;
    vlSelfRef.__VdlySet__tb_RISCV_Pipeline__DOT__dut__DOT__DMEM_inst__DOT__memory__v5 = 0U;
    vlSelfRef.__VdlySet__tb_RISCV_Pipeline__DOT__dut__DOT__DMEM_inst__DOT__memory__v6 = 0U;
    __Vdly__tb_RISCV_Pipeline__DOT__pipeline_filled 
        = vlSelfRef.tb_RISCV_Pipeline__DOT__pipeline_filled;
    if (VL_UNLIKELY((VL_GTS_III(32, 0x00000046U, vlSelfRef.tb_RISCV_Pipeline__DOT__cycle)))) {
        VL_WRITEF_NX("[TRACE] cycle=%0d  PC_D=0x%08h Instr_D=0x%08h  PCSel_E=%b stall_load=%b\n",5
                     , '~',32,vlSelfRef.tb_RISCV_Pipeline__DOT__cycle
                     , '#',32,vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__PC_D
                     , '#',32,vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__Instr_D
                     , '#',1,Vtb_RISCV_Pipeline__ConstPool__TABLE_h3cb0ade6_0
                     [((((IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__BrEq_E) 
                         << 6U) | ((IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__BrLT_E) 
                                   << 5U)) | (((IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__funct3_E) 
                                               << 2U) 
                                              | (((IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__Is_Branch_E) 
                                                  << 1U) 
                                                 | (IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__Is_Jump_E))))]
                     , '#',1,vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__stall_load);
    }
    if (VL_UNLIKELY((((IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__done_reported) 
                      & (vlSelfRef.tb_RISCV_Pipeline__DOT__cycle 
                         == ((IData)(5U) + vlSelfRef.tb_RISCV_Pipeline__DOT__done_cycle)))))) {
        vlSelfRef.tb_RISCV_Pipeline__DOT__report_result__Vstatic__canary_now 
            = vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__DMEM_inst__DOT__memory[0U];
        vlSelfRef.tb_RISCV_Pipeline__DOT__report_result__Vstatic__a0 
            = vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__Reg_inst__DOT__registers[10U];
        vlSelfRef.tb_RISCV_Pipeline__DOT__report_result__Vstatic__cpi 
            = (VL_LTS_III(32, 0U, vlSelfRef.tb_RISCV_Pipeline__DOT__instr_count)
                ? (VL_ISTOR_D_I(32, vlSelfRef.tb_RISCV_Pipeline__DOT__cycle) 
                   / VL_ISTOR_D_I(32, vlSelfRef.tb_RISCV_Pipeline__DOT__instr_count))
                : 0.0);
        vlSelfRef.tb_RISCV_Pipeline__DOT__report_result__Vstatic__stack_used_bytes 
            = ((IData)(0x00001400U) - vlSelfRef.tb_RISCV_Pipeline__DOT__min_sp);
        vlSelfRef.tb_RISCV_Pipeline__DOT__report_result__Vstatic__flush_penalty_cycles 
            = VL_MULS_III(32, (IData)(2U), vlSelfRef.tb_RISCV_Pipeline__DOT__flush_count);
        vlSelfRef.tb_RISCV_Pipeline__DOT__report_result__Vstatic__total_overhead_cycles 
            = (vlSelfRef.tb_RISCV_Pipeline__DOT__stall_count 
               + vlSelfRef.tb_RISCV_Pipeline__DOT__report_result__Vstatic__flush_penalty_cycles);
        VL_WRITEF_NX("========================================\n[TB] Simulation finished at cycle %0d\n[TB] a0 (status) = %0d (0 = pass, nonzero = fail)\n[TB] Canary now  = 0x%08h (expected 0xdeadbeef)\n",3
                     , '~',32,vlSelfRef.tb_RISCV_Pipeline__DOT__cycle
                     , '~',32,vlSelfRef.tb_RISCV_Pipeline__DOT__report_result__Vstatic__a0
                     , '#',32,vlSelfRef.tb_RISCV_Pipeline__DOT__report_result__Vstatic__canary_now);
        if (VL_LIKELY((vlSelfRef.tb_RISCV_Pipeline__DOT__done_reported))) {
            if ((0U == vlSelfRef.tb_RISCV_Pipeline__DOT__report_result__Vstatic__a0)) {
                VL_WRITEF_NX("[TB] *** PASS *** status == 0\n",0);
            } else {
                VL_WRITEF_NX("[TB] *** FAIL *** status == %0d\n",1
                             , '~',32,vlSelfRef.tb_RISCV_Pipeline__DOT__report_result__Vstatic__a0);
            }
        } else {
            VL_WRITEF_NX("[TB] *** INCONCLUSIVE *** halt loop never reached -- so on numbers below are NOT trustworthy\n",0);
        }
        if ((0xdeadbeefU != vlSelfRef.tb_RISCV_Pipeline__DOT__report_result__Vstatic__canary_now)) {
            VL_WRITEF_NX("[TB] *** NOTE *** Canary corrupted -> stack overflow occurred\n",0);
        } else {
            VL_WRITEF_NX("[TB] Canary intact -> no stack overflow detected\n",0);
        }
        if (VL_UNLIKELY((vlSelfRef.tb_RISCV_Pipeline__DOT__done_reported))) {
            VL_WRITEF_NX("[TB] Cycles to completion = %0d\n",1
                         , '~',32,vlSelfRef.tb_RISCV_Pipeline__DOT__done_cycle);
        }
        VL_WRITEF_NX("[TB] Key registers:\n  x1(ra)  = %0d\n  x2(sp)  = %0d\n  x10(a0) = %0d\n----------------------------------------\n[REPORT] --- Architecture / Trade-off metrics ---\n[REPORT] Total cycles                       = %0d\n[REPORT] Instruction count (IC, corrected)  = %0d\n[REPORT] CPI (corrected)                    = %0.3f\n[REPORT] --- Hazard breakdown ---\n[REPORT] Load-Use stall events/cycles       = %0d (%0.1f%% of total)\n[REPORT] Branch/Jump redirect EVENTS        = %0d\n",9
                     , '#',32,vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__Reg_inst__DOT__registers[1U]
                     , '#',32,vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__Reg_inst__DOT__registers[2U]
                     , '#',32,vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__Reg_inst__DOT__registers[10U]
                     , '~',32,vlSelfRef.tb_RISCV_Pipeline__DOT__cycle
                     , '~',32,vlSelfRef.tb_RISCV_Pipeline__DOT__instr_count
                     , 'D',vlSelfRef.tb_RISCV_Pipeline__DOT__report_result__Vstatic__cpi
                     , '~',32,vlSelfRef.tb_RISCV_Pipeline__DOT__stall_count
                     , 'D',((100.0 * VL_ISTOR_D_I(32, vlSelfRef.tb_RISCV_Pipeline__DOT__stall_count)) 
                            / VL_ISTOR_D_I(32, vlSelfRef.tb_RISCV_Pipeline__DOT__cycle))
                     , '~',32,vlSelfRef.tb_RISCV_Pipeline__DOT__flush_count);
        VL_WRITEF_NX("[REPORT] Branch/Jump flush PENALTY cycles   = %0d (2 x events, %0.1f%% of total)\n[REPORT] Total hazard overhead cycles       = %0d (%0.1f%% of total)\n[REPORT] --- Stack usage ---\n[REPORT] Stack top (byte)                   = 5120\n[REPORT] Min sp reached (byte)               = %0d (at cycle %0d)\n[REPORT] Max stack usage (bytes)             = %0d\n----------------------------------------\n",7
                     , '~',32,vlSelfRef.tb_RISCV_Pipeline__DOT__report_result__Vstatic__flush_penalty_cycles
                     , 'D',((100.0 * VL_ISTOR_D_I(32, vlSelfRef.tb_RISCV_Pipeline__DOT__report_result__Vstatic__flush_penalty_cycles)) 
                            / VL_ISTOR_D_I(32, vlSelfRef.tb_RISCV_Pipeline__DOT__cycle))
                     , '~',32,vlSelfRef.tb_RISCV_Pipeline__DOT__report_result__Vstatic__total_overhead_cycles
                     , 'D',((100.0 * VL_ISTOR_D_I(32, vlSelfRef.tb_RISCV_Pipeline__DOT__report_result__Vstatic__total_overhead_cycles)) 
                            / VL_ISTOR_D_I(32, vlSelfRef.tb_RISCV_Pipeline__DOT__cycle))
                     , '~',32,vlSelfRef.tb_RISCV_Pipeline__DOT__min_sp
                     , '~',32,vlSelfRef.tb_RISCV_Pipeline__DOT__min_sp_cycle
                     , '~',32,vlSelfRef.tb_RISCV_Pipeline__DOT__report_result__Vstatic__stack_used_bytes);
        VL_FINISH_MT("tb/tb_RISCV_Pipeline.v", 223, "");
    }
    __Vdly__tb_RISCV_Pipeline__DOT__cycle = ((IData)(1U) 
                                             + vlSelfRef.tb_RISCV_Pipeline__DOT__cycle);
    if (VL_UNLIKELY((((0U == VL_MODDIVS_III(32, vlSelfRef.tb_RISCV_Pipeline__DOT__cycle, (IData)(0x000000c8U))) 
                      & VL_LTS_III(32, 0U, vlSelfRef.tb_RISCV_Pipeline__DOT__cycle))))) {
        VL_WRITEF_NX("[TB] Cycle %0d, PC=0x%08h\n",2
                     , '~',32,vlSelfRef.tb_RISCV_Pipeline__DOT__cycle
                     , '#',32,vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__PC_F);
    }
    if (vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__MemRW_M) {
        if ((0U == (IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__funct3_M))) {
            if ((0U == (3U & vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__ALU_out_M))) {
                vlSelfRef.__VdlyVal__tb_RISCV_Pipeline__DOT__dut__DOT__DMEM_inst__DOT__memory__v0 
                    = (0x000000ffU & vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__DataB_M);
                vlSelfRef.__VdlyDim0__tb_RISCV_Pipeline__DOT__dut__DOT__DMEM_inst__DOT__memory__v0 
                    = (0x000003ffU & ((vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__ALU_out_M 
                                       - (IData)(0x00000400U)) 
                                      >> 2U));
                vlSelfRef.__VdlySet__tb_RISCV_Pipeline__DOT__dut__DOT__DMEM_inst__DOT__memory__v0 = 1U;
            } else if ((1U == (3U & vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__ALU_out_M))) {
                vlSelfRef.__VdlyVal__tb_RISCV_Pipeline__DOT__dut__DOT__DMEM_inst__DOT__memory__v1 
                    = (0x000000ffU & vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__DataB_M);
                vlSelfRef.__VdlyDim0__tb_RISCV_Pipeline__DOT__dut__DOT__DMEM_inst__DOT__memory__v1 
                    = (0x000003ffU & ((vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__ALU_out_M 
                                       - (IData)(0x00000400U)) 
                                      >> 2U));
                vlSelfRef.__VdlySet__tb_RISCV_Pipeline__DOT__dut__DOT__DMEM_inst__DOT__memory__v1 = 1U;
            } else if ((2U == (3U & vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__ALU_out_M))) {
                vlSelfRef.__VdlyVal__tb_RISCV_Pipeline__DOT__dut__DOT__DMEM_inst__DOT__memory__v2 
                    = (0x000000ffU & vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__DataB_M);
                vlSelfRef.__VdlyDim0__tb_RISCV_Pipeline__DOT__dut__DOT__DMEM_inst__DOT__memory__v2 
                    = (0x000003ffU & ((vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__ALU_out_M 
                                       - (IData)(0x00000400U)) 
                                      >> 2U));
                vlSelfRef.__VdlySet__tb_RISCV_Pipeline__DOT__dut__DOT__DMEM_inst__DOT__memory__v2 = 1U;
            } else {
                vlSelfRef.__VdlyVal__tb_RISCV_Pipeline__DOT__dut__DOT__DMEM_inst__DOT__memory__v3 
                    = (0x000000ffU & vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__DataB_M);
                vlSelfRef.__VdlyDim0__tb_RISCV_Pipeline__DOT__dut__DOT__DMEM_inst__DOT__memory__v3 
                    = (0x000003ffU & ((vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__ALU_out_M 
                                       - (IData)(0x00000400U)) 
                                      >> 2U));
                vlSelfRef.__VdlySet__tb_RISCV_Pipeline__DOT__dut__DOT__DMEM_inst__DOT__memory__v3 = 1U;
            }
        } else if ((1U == (IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__funct3_M))) {
            if ((2U & vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__ALU_out_M)) {
                vlSelfRef.__VdlyVal__tb_RISCV_Pipeline__DOT__dut__DOT__DMEM_inst__DOT__memory__v4 
                    = (0x0000ffffU & vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__DataB_M);
                vlSelfRef.__VdlyDim0__tb_RISCV_Pipeline__DOT__dut__DOT__DMEM_inst__DOT__memory__v4 
                    = (0x000003ffU & ((vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__ALU_out_M 
                                       - (IData)(0x00000400U)) 
                                      >> 2U));
                vlSelfRef.__VdlySet__tb_RISCV_Pipeline__DOT__dut__DOT__DMEM_inst__DOT__memory__v4 = 1U;
            } else {
                vlSelfRef.__VdlyVal__tb_RISCV_Pipeline__DOT__dut__DOT__DMEM_inst__DOT__memory__v5 
                    = (0x0000ffffU & vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__DataB_M);
                vlSelfRef.__VdlyDim0__tb_RISCV_Pipeline__DOT__dut__DOT__DMEM_inst__DOT__memory__v5 
                    = (0x000003ffU & ((vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__ALU_out_M 
                                       - (IData)(0x00000400U)) 
                                      >> 2U));
                vlSelfRef.__VdlySet__tb_RISCV_Pipeline__DOT__dut__DOT__DMEM_inst__DOT__memory__v5 = 1U;
            }
        } else if ((2U == (IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__funct3_M))) {
            vlSelfRef.__VdlyVal__tb_RISCV_Pipeline__DOT__dut__DOT__DMEM_inst__DOT__memory__v6 
                = vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__DataB_M;
            vlSelfRef.__VdlyDim0__tb_RISCV_Pipeline__DOT__dut__DOT__DMEM_inst__DOT__memory__v6 
                = (0x000003ffU & ((vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__ALU_out_M 
                                   - (IData)(0x00000400U)) 
                                  >> 2U));
            vlSelfRef.__VdlySet__tb_RISCV_Pipeline__DOT__dut__DOT__DMEM_inst__DOT__memory__v6 = 1U;
        }
    }
    if ((((IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__rst_n) 
          & (~ (IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__pipeline_filled))) 
         & VL_LTES_III(32, 2U, vlSelfRef.tb_RISCV_Pipeline__DOT__cycle))) {
        __Vdly__tb_RISCV_Pipeline__DOT__pipeline_filled = 1U;
    }
    if (((IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__rst_n) 
         & (IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__pipeline_filled))) {
        if ((1U & ((~ (IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__bubble_id_ex)) 
                   & (~ (IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__PCSel_E_d1))))) {
            vlSelfRef.tb_RISCV_Pipeline__DOT__instr_count 
                = ((IData)(1U) + vlSelfRef.tb_RISCV_Pipeline__DOT__instr_count);
        }
        if (vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__stall_load) {
            vlSelfRef.tb_RISCV_Pipeline__DOT__stall_count 
                = ((IData)(1U) + vlSelfRef.tb_RISCV_Pipeline__DOT__stall_count);
        }
        if (Vtb_RISCV_Pipeline__ConstPool__TABLE_h3cb0ade6_0
            [((((IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__BrEq_E) 
                << 6U) | ((IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__BrLT_E) 
                          << 5U)) | (((IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__funct3_E) 
                                      << 2U) | (((IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__Is_Branch_E) 
                                                 << 1U) 
                                                | (IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__Is_Jump_E))))]) {
            vlSelfRef.tb_RISCV_Pipeline__DOT__flush_count 
                = ((IData)(1U) + vlSelfRef.tb_RISCV_Pipeline__DOT__flush_count);
        }
    }
    if (VL_UNLIKELY((((((IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__rst_n) 
                        & (~ (IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__done_reported))) 
                       & (IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__Is_Jump_E)) 
                      & (vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__PC_target_E 
                         == vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__PC_E))))) {
        vlSelfRef.tb_RISCV_Pipeline__DOT__done_cycle 
            = vlSelfRef.tb_RISCV_Pipeline__DOT__cycle;
        VL_WRITEF_NX("[TB] *** HALT LOOP REACHED *** at cycle %0d, PC=0x%08h\n",2
                     , '~',32,vlSelfRef.tb_RISCV_Pipeline__DOT__cycle
                     , '#',32,vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__PC_E);
        vlSelfRef.tb_RISCV_Pipeline__DOT__done_reported = 1U;
    }
    vlSelfRef.tb_RISCV_Pipeline__DOT__pipeline_filled 
        = __Vdly__tb_RISCV_Pipeline__DOT__pipeline_filled;
    if ((((IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__rst_n) 
          & (~ (IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__sp_initialized))) 
         & (0x00001400U == vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__Reg_inst__DOT__registers[2U]))) {
        __Vdly__tb_RISCV_Pipeline__DOT__sp_initialized = 1U;
    }
    if ((((IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__rst_n) 
          & (IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__sp_initialized)) 
         & (vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__Reg_inst__DOT__registers[2U] 
            < vlSelfRef.tb_RISCV_Pipeline__DOT__min_sp))) {
        vlSelfRef.tb_RISCV_Pipeline__DOT__min_sp = vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__Reg_inst__DOT__registers[2U];
        vlSelfRef.tb_RISCV_Pipeline__DOT__min_sp_cycle 
            = vlSelfRef.tb_RISCV_Pipeline__DOT__cycle;
    }
    vlSelfRef.tb_RISCV_Pipeline__DOT__PCSel_E_d1 = Vtb_RISCV_Pipeline__ConstPool__TABLE_h3cb0ade6_0
        [((((IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__BrEq_E) 
            << 6U) | ((IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__BrLT_E) 
                      << 5U)) | (((IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__funct3_E) 
                                  << 2U) | (((IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__Is_Branch_E) 
                                             << 1U) 
                                            | (IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__Is_Jump_E))))];
    vlSelfRef.tb_RISCV_Pipeline__DOT__sp_initialized 
        = __Vdly__tb_RISCV_Pipeline__DOT__sp_initialized;
    vlSelfRef.tb_RISCV_Pipeline__DOT__cycle = __Vdly__tb_RISCV_Pipeline__DOT__cycle;
}

extern const VlUnpacked<CData/*3:0*/, 128> Vtb_RISCV_Pipeline__ConstPool__TABLE_h4d17e3b4_0;
extern const VlUnpacked<CData/*0:0*/, 256> Vtb_RISCV_Pipeline__ConstPool__TABLE_hc9903a88_0;
extern const VlUnpacked<CData/*0:0*/, 256> Vtb_RISCV_Pipeline__ConstPool__TABLE_h2817a251_0;
extern const VlUnpacked<CData/*0:0*/, 256> Vtb_RISCV_Pipeline__ConstPool__TABLE_hb37d2bb4_0;
extern const VlUnpacked<CData/*2:0*/, 256> Vtb_RISCV_Pipeline__ConstPool__TABLE_h6a3b8cf2_0;
extern const VlUnpacked<CData/*1:0*/, 256> Vtb_RISCV_Pipeline__ConstPool__TABLE_h7320afc7_0;
extern const VlUnpacked<CData/*0:0*/, 256> Vtb_RISCV_Pipeline__ConstPool__TABLE_h77ea30c7_0;
extern const VlUnpacked<CData/*0:0*/, 256> Vtb_RISCV_Pipeline__ConstPool__TABLE_h5ac4bd78_0;
extern const VlUnpacked<CData/*0:0*/, 256> Vtb_RISCV_Pipeline__ConstPool__TABLE_h70db338c_0;
extern const VlUnpacked<CData/*0:0*/, 256> Vtb_RISCV_Pipeline__ConstPool__TABLE_hb03ac117_0;
extern const VlUnpacked<CData/*0:0*/, 256> Vtb_RISCV_Pipeline__ConstPool__TABLE_hadc3105f_0;
extern const VlUnpacked<CData/*0:0*/, 256> Vtb_RISCV_Pipeline__ConstPool__TABLE_h2471d231_0;
extern const VlUnpacked<CData/*0:0*/, 256> Vtb_RISCV_Pipeline__ConstPool__TABLE_hd82a1090_0;
extern const VlUnpacked<CData/*0:0*/, 256> Vtb_RISCV_Pipeline__ConstPool__TABLE_h020b1e42_0;
extern const VlUnpacked<CData/*0:0*/, 256> Vtb_RISCV_Pipeline__ConstPool__TABLE_h0ae2a928_0;
extern const VlUnpacked<CData/*0:0*/, 256> Vtb_RISCV_Pipeline__ConstPool__TABLE_h41ca9fcd_0;
extern const VlUnpacked<CData/*0:0*/, 256> Vtb_RISCV_Pipeline__ConstPool__TABLE_h35a60bd7_0;

void Vtb_RISCV_Pipeline___024root___nba_sequent__TOP__1(Vtb_RISCV_Pipeline___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_RISCV_Pipeline___024root___nba_sequent__TOP__1\n"); );
    Vtb_RISCV_Pipeline__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __Vdly__tb_RISCV_Pipeline__DOT__dut__DOT__Instr_D;
    __Vdly__tb_RISCV_Pipeline__DOT__dut__DOT__Instr_D = 0;
    IData/*31:0*/ __VdlyVal__tb_RISCV_Pipeline__DOT__dut__DOT__Reg_inst__DOT__registers__v0;
    __VdlyVal__tb_RISCV_Pipeline__DOT__dut__DOT__Reg_inst__DOT__registers__v0 = 0;
    CData/*4:0*/ __VdlyDim0__tb_RISCV_Pipeline__DOT__dut__DOT__Reg_inst__DOT__registers__v0;
    __VdlyDim0__tb_RISCV_Pipeline__DOT__dut__DOT__Reg_inst__DOT__registers__v0 = 0;
    CData/*0:0*/ __VdlySet__tb_RISCV_Pipeline__DOT__dut__DOT__Reg_inst__DOT__registers__v0;
    __VdlySet__tb_RISCV_Pipeline__DOT__dut__DOT__Reg_inst__DOT__registers__v0 = 0;
    CData/*0:0*/ __VdlySet__tb_RISCV_Pipeline__DOT__dut__DOT__Reg_inst__DOT__registers__v1;
    __VdlySet__tb_RISCV_Pipeline__DOT__dut__DOT__Reg_inst__DOT__registers__v1 = 0;
    // Body
    __Vdly__tb_RISCV_Pipeline__DOT__dut__DOT__Instr_D 
        = vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__Instr_D;
    __VdlySet__tb_RISCV_Pipeline__DOT__dut__DOT__Reg_inst__DOT__registers__v0 = 0U;
    __VdlySet__tb_RISCV_Pipeline__DOT__dut__DOT__Reg_inst__DOT__registers__v1 = 0U;
    if ((1U & (~ (IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__rst_n)))) {
        vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__Reg_inst__DOT__i = 0x00000020U;
    }
    if (vlSelfRef.tb_RISCV_Pipeline__DOT__rst_n) {
        if (((IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__RegWEn_W) 
             & (0U != (IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__addrD_W)))) {
            __VdlyVal__tb_RISCV_Pipeline__DOT__dut__DOT__Reg_inst__DOT__registers__v0 
                = vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__DataD_W;
            __VdlyDim0__tb_RISCV_Pipeline__DOT__dut__DOT__Reg_inst__DOT__registers__v0 
                = vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__addrD_W;
            __VdlySet__tb_RISCV_Pipeline__DOT__dut__DOT__Reg_inst__DOT__registers__v0 = 1U;
        }
        vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__ALU_out_W 
            = vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__ALU_out_M;
        vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__WBSel_W 
            = vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__WBSel_M;
        vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__DataR_W 
            = ((4U & (IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__funct3_M))
                ? ((- (IData)((1U & (~ ((IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__funct3_M) 
                                        >> 1U))))) 
                   & ((1U & (IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__funct3_M))
                       ? (IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__DMEM_inst__DOT__selected_half)
                       : (IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__DMEM_inst__DOT__selected_byte)))
                : ((2U & (IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__funct3_M))
                    ? (vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__DMEM_inst__DOT__memory
                       [(0x000003ffU & ((vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__ALU_out_M 
                                         - (IData)(0x00000400U)) 
                                        >> 2U))] & 
                       (- (IData)((1U & (~ (IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__funct3_M))))))
                    : ((1U & (IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__funct3_M))
                        ? (((- (IData)((1U & ((IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__DMEM_inst__DOT__selected_half) 
                                              >> 0x0000000fU)))) 
                            << 0x00000010U) | (IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__DMEM_inst__DOT__selected_half))
                        : (((- (IData)((1U & ((IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__DMEM_inst__DOT__selected_byte) 
                                              >> 7U)))) 
                            << 8U) | (IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__DMEM_inst__DOT__selected_byte)))));
        vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__PC_Plus4_W 
            = vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__PC_Plus4_M;
        vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__DataB_M 
            = vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__fwd_DataB_E;
        vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__addrD_W 
            = vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__addrD_M;
        vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__WBSel_M 
            = vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__WBSel_E;
        vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__funct3_M 
            = vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__funct3_E;
        vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__ALU_out_M 
            = vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__ALU_out_E;
        vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__PC_Plus4_M 
            = vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__PC_Plus4_E;
        vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__addrD_M 
            = vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__addrD_E;
        if (Vtb_RISCV_Pipeline__ConstPool__TABLE_h3cb0ade6_0
            [((((IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__BrEq_E) 
                << 6U) | ((IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__BrLT_E) 
                          << 5U)) | (((IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__funct3_E) 
                                      << 2U) | (((IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__Is_Branch_E) 
                                                 << 1U) 
                                                | (IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__Is_Jump_E))))]) {
            __Vdly__tb_RISCV_Pipeline__DOT__dut__DOT__Instr_D = 0x00000013U;
        } else if ((1U & (~ (IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__stall_if_id)))) {
            __Vdly__tb_RISCV_Pipeline__DOT__dut__DOT__Instr_D 
                = vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__IMEM_inst__DOT__memory
                [(0x000000ffU & (vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__PC_F 
                                 >> 2U))];
        }
        if (vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__bubble_id_ex) {
            vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__ALUSel_E = 0U;
            vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__Imm_E = 0U;
            vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__addrB_E = 0U;
            vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__addrA_E = 0U;
            vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__DataA_E = 0U;
            vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__DataB_E = 0U;
            vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__PC_E = 0U;
        } else {
            vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__ALUSel_E 
                = Vtb_RISCV_Pipeline__ConstPool__TABLE_h4d17e3b4_0
                [(((((IData)(Vtb_RISCV_Pipeline__ConstPool__TABLE_hc9903a88_0
                             [vlSelfRef.__VdfgRegularize_h6e95ff9d_0_0]) 
                     << 1U) << 5U) | (0x00000020U & 
                                      (vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__Instr_D 
                                       >> 0x00000019U))) 
                  | ((0x0000001cU & (vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__Instr_D 
                                     >> 0x0000000aU)) 
                     | (((IData)(Vtb_RISCV_Pipeline__ConstPool__TABLE_h2817a251_0
                                 [vlSelfRef.__VdfgRegularize_h6e95ff9d_0_0]) 
                         << 1U) | Vtb_RISCV_Pipeline__ConstPool__TABLE_hb37d2bb4_0
                        [vlSelfRef.__VdfgRegularize_h6e95ff9d_0_0])))];
            vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__Imm_E 
                = ((4U & Vtb_RISCV_Pipeline__ConstPool__TABLE_h6a3b8cf2_0
                    [vlSelfRef.__VdfgRegularize_h6e95ff9d_0_0])
                    ? ((- (IData)((1U & (~ (IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_1))))) 
                       & (((((0x00000ffeU & ((- (IData)(
                                                        (vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__Instr_D 
                                                         >> 0x0000001fU))) 
                                             << 1U)) 
                             | (vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__Instr_D 
                                >> 0x0000001fU)) << 0x00000014U) 
                           | ((((0x000001feU & (vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__Instr_D 
                                                >> 0x0000000bU)) 
                                | (1U & (vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__Instr_D 
                                         >> 0x00000014U))) 
                               << 0x0000000bU) | (0x000007feU 
                                                  & (vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__Instr_D 
                                                     >> 0x00000014U)))) 
                          & (- (IData)((1U & (~ (IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_5)))))))
                    : ((IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_5)
                        ? (((IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_1)
                             ? (0x7ffff800U & (vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__Instr_D 
                                               >> 1U))
                             : ((0x7ffff000U & ((- (IData)(
                                                           (vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__Instr_D 
                                                            >> 0x0000001fU))) 
                                                << 0x0000000cU)) 
                                | ((((2U & (vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__Instr_D 
                                            >> 0x0000001eU)) 
                                     | (1U & (vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__Instr_D 
                                              >> 7U))) 
                                    << 0x0000000aU) 
                                   | ((0x000003f0U 
                                       & (vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__Instr_D 
                                          >> 0x00000015U)) 
                                      | (0x0000000fU 
                                         & (vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__Instr_D 
                                            >> 8U)))))) 
                           << 1U) : (((- (IData)((vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__Instr_D 
                                                  >> 0x0000001fU))) 
                                      << 0x0000000cU) 
                                     | ((0x00000fe0U 
                                         & (vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__Instr_D 
                                            >> 0x00000014U)) 
                                        | (0x0000001fU 
                                           & ((IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_1)
                                               ? (vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__Instr_D 
                                                  >> 7U)
                                               : (vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__Instr_D 
                                                  >> 0x00000014U)))))));
            vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__addrB_E 
                = (0x0000001fU & (vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__Instr_D 
                                  >> 0x00000014U));
            vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__addrA_E 
                = (0x0000001fU & (vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__Instr_D 
                                  >> 0x0000000fU));
            vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__DataA_E 
                = (((IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_3) 
                    & (IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_2))
                    ? vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__DataD_W
                    : ((((IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__RegWEn_W) 
                         & (IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_3))
                         ? vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__DataD_W
                         : vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__Reg_inst__DOT__registers
                        [(0x0000001fU & (vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__Instr_D 
                                         >> 0x0000000fU))]) 
                       & (- (IData)((0U != (0x0000001fU 
                                            & (vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__Instr_D 
                                               >> 0x0000000fU)))))));
            vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__DataB_E 
                = (((IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_4) 
                    & (IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_2))
                    ? vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__DataD_W
                    : ((((IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__RegWEn_W) 
                         & (IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_4))
                         ? vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__DataD_W
                         : vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__Reg_inst__DOT__registers
                        [(0x0000001fU & (vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__Instr_D 
                                         >> 0x00000014U))]) 
                       & (- (IData)((0U != (0x0000001fU 
                                            & (vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__Instr_D 
                                               >> 0x00000014U)))))));
            vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__PC_E 
                = vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__PC_D;
        }
        if (Vtb_RISCV_Pipeline__ConstPool__TABLE_h3cb0ade6_0
            [((((IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__BrEq_E) 
                << 6U) | ((IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__BrLT_E) 
                          << 5U)) | (((IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__funct3_E) 
                                      << 2U) | (((IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__Is_Branch_E) 
                                                 << 1U) 
                                                | (IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__Is_Jump_E))))]) {
            vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__PC_D = 0U;
        } else if ((1U & (~ (IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__stall_if_id)))) {
            vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__PC_D 
                = vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__PC_F;
        }
        if (vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__bubble_id_ex) {
            vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__WBSel_E = 0U;
            vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__PC_Plus4_E = 0U;
        } else {
            vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__WBSel_E 
                = Vtb_RISCV_Pipeline__ConstPool__TABLE_h7320afc7_0
                [vlSelfRef.__VdfgRegularize_h6e95ff9d_0_0];
            vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__PC_Plus4_E 
                = vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__PC_Plus4_D;
        }
        if (Vtb_RISCV_Pipeline__ConstPool__TABLE_h3cb0ade6_0
            [((((IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__BrEq_E) 
                << 6U) | ((IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__BrLT_E) 
                          << 5U)) | (((IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__funct3_E) 
                                      << 2U) | (((IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__Is_Branch_E) 
                                                 << 1U) 
                                                | (IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__Is_Jump_E))))]) {
            vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__PC_Plus4_D = 0U;
        } else if ((1U & (~ (IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__stall_if_id)))) {
            vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__PC_Plus4_D 
                = ((IData)(4U) + vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__PC_F);
        }
        if ((1U & ((~ (IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__stall_load)) 
                   | Vtb_RISCV_Pipeline__ConstPool__TABLE_h3cb0ade6_0
                   [((((IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__BrEq_E) 
                       << 6U) | ((IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__BrLT_E) 
                                 << 5U)) | (((IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__funct3_E) 
                                             << 2U) 
                                            | (((IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__Is_Branch_E) 
                                                << 1U) 
                                               | (IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__Is_Jump_E))))]))) {
            vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__PC_F 
                = vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__PC_next_F;
        }
        if (vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__bubble_id_ex) {
            vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__addrD_E = 0U;
            vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__funct3_E = 0U;
        } else {
            vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__addrD_E 
                = (0x0000001fU & (vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__Instr_D 
                                  >> 7U));
            vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__funct3_E 
                = (7U & (vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__Instr_D 
                         >> 0x0000000cU));
        }
    } else {
        __Vdly__tb_RISCV_Pipeline__DOT__dut__DOT__Instr_D = 0x00000013U;
        __VdlySet__tb_RISCV_Pipeline__DOT__dut__DOT__Reg_inst__DOT__registers__v1 = 1U;
        vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__ALUSel_E = 0U;
        vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__Imm_E = 0U;
        vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__addrB_E = 0U;
        vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__addrA_E = 0U;
        vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__ALU_out_W = 0U;
        vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__WBSel_W = 0U;
        vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__DataR_W = 0U;
        vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__DataA_E = 0U;
        vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__DataB_E = 0U;
        vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__PC_Plus4_W = 0U;
        vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__DataB_M = 0U;
        vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__PC_E = 0U;
        vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__addrD_W = 0U;
        vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__WBSel_M = 0U;
        vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__funct3_M = 0U;
        vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__ALU_out_M = 0U;
        vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__PC_Plus4_M = 0U;
        vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__PC_D = 0U;
        vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__addrD_M = 0U;
        vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__WBSel_E = 0U;
        vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__PC_Plus4_E = 0U;
        vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__addrD_E = 0U;
        vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__PC_Plus4_D = 0U;
        vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__PC_F = 0U;
        vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__funct3_E = 0U;
    }
    vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__Is_JALR_E 
        = ((IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__rst_n) 
           && ((1U & (~ (IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__bubble_id_ex))) 
               && Vtb_RISCV_Pipeline__ConstPool__TABLE_h77ea30c7_0
               [vlSelfRef.__VdfgRegularize_h6e95ff9d_0_0]));
    vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__ASel_E 
        = ((IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__rst_n) 
           && ((1U & (~ (IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__bubble_id_ex))) 
               && Vtb_RISCV_Pipeline__ConstPool__TABLE_h5ac4bd78_0
               [vlSelfRef.__VdfgRegularize_h6e95ff9d_0_0]));
    vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__BSel_E 
        = ((IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__rst_n) 
           && ((1U & (~ (IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__bubble_id_ex))) 
               && Vtb_RISCV_Pipeline__ConstPool__TABLE_h70db338c_0
               [vlSelfRef.__VdfgRegularize_h6e95ff9d_0_0]));
    vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__Is_Load_E 
        = ((IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__rst_n) 
           && ((1U & (~ (IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__bubble_id_ex))) 
               && Vtb_RISCV_Pipeline__ConstPool__TABLE_hb03ac117_0
               [vlSelfRef.__VdfgRegularize_h6e95ff9d_0_0]));
    vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__BrUn_E 
        = ((IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__rst_n) 
           && ((1U & (~ (IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__bubble_id_ex))) 
               && Vtb_RISCV_Pipeline__ConstPool__TABLE_hadc3105f_0
               [vlSelfRef.__VdfgRegularize_h6e95ff9d_0_0]));
    vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__MemRW_M 
        = ((IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__rst_n) 
           && (IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__MemRW_E));
    if (__VdlySet__tb_RISCV_Pipeline__DOT__dut__DOT__Reg_inst__DOT__registers__v0) {
        vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__Reg_inst__DOT__registers[__VdlyDim0__tb_RISCV_Pipeline__DOT__dut__DOT__Reg_inst__DOT__registers__v0] 
            = __VdlyVal__tb_RISCV_Pipeline__DOT__dut__DOT__Reg_inst__DOT__registers__v0;
    }
    if (__VdlySet__tb_RISCV_Pipeline__DOT__dut__DOT__Reg_inst__DOT__registers__v1) {
        vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__Reg_inst__DOT__registers[0U] = 0U;
        vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__Reg_inst__DOT__registers[1U] = 0U;
        vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__Reg_inst__DOT__registers[2U] = 0U;
        vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__Reg_inst__DOT__registers[3U] = 0U;
        vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__Reg_inst__DOT__registers[4U] = 0U;
        vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__Reg_inst__DOT__registers[5U] = 0U;
        vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__Reg_inst__DOT__registers[6U] = 0U;
        vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__Reg_inst__DOT__registers[7U] = 0U;
        vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__Reg_inst__DOT__registers[8U] = 0U;
        vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__Reg_inst__DOT__registers[9U] = 0U;
        vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__Reg_inst__DOT__registers[10U] = 0U;
        vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__Reg_inst__DOT__registers[11U] = 0U;
        vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__Reg_inst__DOT__registers[12U] = 0U;
        vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__Reg_inst__DOT__registers[13U] = 0U;
        vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__Reg_inst__DOT__registers[14U] = 0U;
        vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__Reg_inst__DOT__registers[15U] = 0U;
        vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__Reg_inst__DOT__registers[16U] = 0U;
        vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__Reg_inst__DOT__registers[17U] = 0U;
        vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__Reg_inst__DOT__registers[18U] = 0U;
        vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__Reg_inst__DOT__registers[19U] = 0U;
        vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__Reg_inst__DOT__registers[20U] = 0U;
        vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__Reg_inst__DOT__registers[21U] = 0U;
        vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__Reg_inst__DOT__registers[22U] = 0U;
        vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__Reg_inst__DOT__registers[23U] = 0U;
        vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__Reg_inst__DOT__registers[24U] = 0U;
        vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__Reg_inst__DOT__registers[25U] = 0U;
        vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__Reg_inst__DOT__registers[26U] = 0U;
        vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__Reg_inst__DOT__registers[27U] = 0U;
        vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__Reg_inst__DOT__registers[28U] = 0U;
        vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__Reg_inst__DOT__registers[29U] = 0U;
        vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__Reg_inst__DOT__registers[30U] = 0U;
        vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__Reg_inst__DOT__registers[31U] = 0U;
    }
    vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__RegWEn_W 
        = ((IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__rst_n) 
           && (IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__RegWEn_M));
    vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__DataD_W 
        = ((0U == (IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__WBSel_W))
            ? vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__DataR_W
            : ((1U == (IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__WBSel_W))
                ? vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__ALU_out_W
                : vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__PC_Plus4_W));
    vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__MemRW_E 
        = ((IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__rst_n) 
           && ((1U & (~ (IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__bubble_id_ex))) 
               && Vtb_RISCV_Pipeline__ConstPool__TABLE_h2471d231_0
               [vlSelfRef.__VdfgRegularize_h6e95ff9d_0_0]));
    vlSelfRef.__VdfgRegularize_h6e95ff9d_0_2 = ((IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__RegWEn_W) 
                                                & (0U 
                                                   != (IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__addrD_W)));
    vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__RegWEn_M 
        = ((IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__rst_n) 
           && (IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__RegWEn_E));
    vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__ForwardData_M 
        = ((2U == (IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__WBSel_M))
            ? vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__PC_Plus4_M
            : vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__ALU_out_M);
    vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__fwdA = 0U;
    if ((((IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__RegWEn_M) 
          & (0U != (IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__addrD_M))) 
         & ((IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__addrD_M) 
            == (IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__addrA_E)))) {
        vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__fwdA = 2U;
    } else if ((((IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__RegWEn_W) 
                 & (0U != (IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__addrD_W))) 
                & ((IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__addrD_W) 
                   == (IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__addrA_E)))) {
        vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__fwdA = 1U;
    }
    vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__fwdB = 0U;
    if ((((IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__RegWEn_M) 
          & (0U != (IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__addrD_M))) 
         & ((IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__addrD_M) 
            == (IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__addrB_E)))) {
        vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__fwdB = 2U;
    } else if ((((IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__RegWEn_W) 
                 & (0U != (IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__addrD_W))) 
                & ((IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__addrD_W) 
                   == (IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__addrB_E)))) {
        vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__fwdB = 1U;
    }
    vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__RegWEn_E 
        = ((IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__rst_n) 
           && ((1U & (~ (IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__bubble_id_ex))) 
               && Vtb_RISCV_Pipeline__ConstPool__TABLE_hd82a1090_0
               [vlSelfRef.__VdfgRegularize_h6e95ff9d_0_0]));
    vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__fwd_DataA_E 
        = ((2U == (IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__fwdA))
            ? vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__ForwardData_M
            : ((1U == (IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__fwdA))
                ? vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__DataD_W
                : vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__DataA_E));
    vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__fwd_DataB_E 
        = ((2U == (IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__fwdB))
            ? vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__ForwardData_M
            : ((1U == (IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__fwdB))
                ? vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__DataD_W
                : vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__DataB_E));
    vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__Mux_ALU_DataA_E 
        = ((IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__ASel_E)
            ? vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__PC_E
            : vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__fwd_DataA_E);
    vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__Mux_ALU_DataB_E 
        = ((IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__BSel_E)
            ? vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__Imm_E
            : vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__fwd_DataB_E);
    vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__ALU_out_E 
        = ((8U & (IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__ALUSel_E))
            ? (((2U & (IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__ALUSel_E))
                 ? (vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__Mux_ALU_DataB_E 
                    & (- (IData)((1U & (~ (IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__ALUSel_E))))))
                 : ((1U & (IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__ALUSel_E))
                     ? (vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__Mux_ALU_DataA_E 
                        < vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__Mux_ALU_DataB_E)
                     : VL_LTS_III(32, vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__Mux_ALU_DataA_E, vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__Mux_ALU_DataB_E))) 
               & (- (IData)((1U & (~ ((IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__ALUSel_E) 
                                      >> 2U)))))) : 
           ((4U & (IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__ALUSel_E))
             ? ((2U & (IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__ALUSel_E))
                 ? ((1U & (IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__ALUSel_E))
                     ? VL_SHIFTRS_III(32,32,5, vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__Mux_ALU_DataA_E, 
                                      (0x0000001fU 
                                       & vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__Mux_ALU_DataB_E))
                     : (vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__Mux_ALU_DataA_E 
                        >> (0x0000001fU & vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__Mux_ALU_DataB_E)))
                 : ((1U & (IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__ALUSel_E))
                     ? (vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__Mux_ALU_DataA_E 
                        << (0x0000001fU & vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__Mux_ALU_DataB_E))
                     : (vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__Mux_ALU_DataA_E 
                        ^ vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__Mux_ALU_DataB_E)))
             : ((2U & (IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__ALUSel_E))
                 ? ((1U & (IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__ALUSel_E))
                     ? (vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__Mux_ALU_DataA_E 
                        | vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__Mux_ALU_DataB_E)
                     : (vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__Mux_ALU_DataA_E 
                        & vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__Mux_ALU_DataB_E))
                 : ((1U & (IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__ALUSel_E))
                     ? (vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__Mux_ALU_DataA_E 
                        - vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__Mux_ALU_DataB_E)
                     : (vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__Mux_ALU_DataA_E 
                        + vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__Mux_ALU_DataB_E)))));
    vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__BrEq_E 
        = (vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__fwd_DataA_E 
           == vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__fwd_DataB_E);
    vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__BrLT_E 
        = ((IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__BrUn_E)
            ? (vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__fwd_DataA_E 
               < vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__fwd_DataB_E)
            : VL_LTS_III(32, vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__fwd_DataA_E, vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__fwd_DataB_E));
    vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__PC_target_E 
        = ((0xfffffffeU & vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__ALU_out_E) 
           | (1U & ((~ (IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__Is_JALR_E)) 
                    & vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__ALU_out_E)));
    vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__Is_Branch_E 
        = ((IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__rst_n) 
           && ((1U & (~ (IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__bubble_id_ex))) 
               && Vtb_RISCV_Pipeline__ConstPool__TABLE_h020b1e42_0
               [vlSelfRef.__VdfgRegularize_h6e95ff9d_0_0]));
    vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__Is_Jump_E 
        = ((IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__rst_n) 
           && ((1U & (~ (IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__bubble_id_ex))) 
               && Vtb_RISCV_Pipeline__ConstPool__TABLE_h0ae2a928_0
               [vlSelfRef.__VdfgRegularize_h6e95ff9d_0_0]));
    vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__Instr_D 
        = __Vdly__tb_RISCV_Pipeline__DOT__dut__DOT__Instr_D;
    vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__PC_next_F 
        = (Vtb_RISCV_Pipeline__ConstPool__TABLE_h3cb0ade6_0
           [((((IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__BrEq_E) 
               << 6U) | ((IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__BrLT_E) 
                         << 5U)) | (((IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__funct3_E) 
                                     << 2U) | (((IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__Is_Branch_E) 
                                                << 1U) 
                                               | (IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__Is_Jump_E))))]
            ? vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__PC_target_E
            : ((IData)(4U) + vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__PC_F));
    vlSelfRef.__VdfgRegularize_h6e95ff9d_0_3 = ((IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__addrD_W) 
                                                == 
                                                (0x0000001fU 
                                                 & (vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__Instr_D 
                                                    >> 0x0000000fU)));
    vlSelfRef.__VdfgRegularize_h6e95ff9d_0_4 = ((IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__addrD_W) 
                                                == 
                                                (0x0000001fU 
                                                 & (vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__Instr_D 
                                                    >> 0x00000014U)));
    vlSelfRef.__VdfgRegularize_h6e95ff9d_0_0 = ((0x000000e0U 
                                                 & (vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__Instr_D 
                                                    >> 7U)) 
                                                | (0x0000001fU 
                                                   & (vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__Instr_D 
                                                      >> 2U)));
    vlSelfRef.__VdfgRegularize_h6e95ff9d_0_1 = (1U 
                                                & Vtb_RISCV_Pipeline__ConstPool__TABLE_h6a3b8cf2_0
                                                [vlSelfRef.__VdfgRegularize_h6e95ff9d_0_0]);
    vlSelfRef.__VdfgRegularize_h6e95ff9d_0_5 = (1U 
                                                & (Vtb_RISCV_Pipeline__ConstPool__TABLE_h6a3b8cf2_0
                                                   [vlSelfRef.__VdfgRegularize_h6e95ff9d_0_0] 
                                                   >> 1U));
    vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__stall_load 
        = ((IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__Is_Load_E) 
           & ((0U != (IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__addrD_E)) 
              & ((Vtb_RISCV_Pipeline__ConstPool__TABLE_h41ca9fcd_0
                  [vlSelfRef.__VdfgRegularize_h6e95ff9d_0_0] 
                  & ((IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__addrD_E) 
                     == (0x0000001fU & (vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__Instr_D 
                                        >> 0x0000000fU)))) 
                 | (Vtb_RISCV_Pipeline__ConstPool__TABLE_h35a60bd7_0
                    [vlSelfRef.__VdfgRegularize_h6e95ff9d_0_0] 
                    & ((IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__addrD_E) 
                       == (0x0000001fU & (vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__Instr_D 
                                          >> 0x00000014U)))))));
    vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__bubble_id_ex 
        = (Vtb_RISCV_Pipeline__ConstPool__TABLE_h3cb0ade6_0
           [((((IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__BrEq_E) 
               << 6U) | ((IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__BrLT_E) 
                         << 5U)) | (((IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__funct3_E) 
                                     << 2U) | (((IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__Is_Branch_E) 
                                                << 1U) 
                                               | (IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__Is_Jump_E))))] 
           | (IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__stall_load));
    vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__stall_if_id 
        = ((~ (IData)(Vtb_RISCV_Pipeline__ConstPool__TABLE_h3cb0ade6_0
                      [((((IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__BrEq_E) 
                          << 6U) | ((IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__BrLT_E) 
                                    << 5U)) | (((IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__funct3_E) 
                                                << 2U) 
                                               | (((IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__Is_Branch_E) 
                                                   << 1U) 
                                                  | (IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__Is_Jump_E))))])) 
           & (IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__stall_load));
}

void Vtb_RISCV_Pipeline___024root___eval_nba(Vtb_RISCV_Pipeline___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_RISCV_Pipeline___024root___eval_nba\n"); );
    Vtb_RISCV_Pipeline__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vtb_RISCV_Pipeline___024root___nba_sequent__TOP__0(vlSelf);
        vlSelfRef.__Vm_traceActivity[2U] = 1U;
    }
    if ((3ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vtb_RISCV_Pipeline___024root___nba_sequent__TOP__1(vlSelf);
        vlSelfRef.__Vm_traceActivity[3U] = 1U;
    }
    if ((1ULL & vlSelfRef.__VnbaTriggered[0U])) {
        {
            // Inlined CFunc: _nba_sequent__TOP__2
            if (vlSelfRef.__VdlySet__tb_RISCV_Pipeline__DOT__dut__DOT__DMEM_inst__DOT__memory__v0) {
                vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__DMEM_inst__DOT__memory[vlSelfRef.__VdlyDim0__tb_RISCV_Pipeline__DOT__dut__DOT__DMEM_inst__DOT__memory__v0] 
                    = ((0xffffff00U & vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__DMEM_inst__DOT__memory
                        [vlSelfRef.__VdlyDim0__tb_RISCV_Pipeline__DOT__dut__DOT__DMEM_inst__DOT__memory__v0]) 
                       | (IData)(vlSelfRef.__VdlyVal__tb_RISCV_Pipeline__DOT__dut__DOT__DMEM_inst__DOT__memory__v0));
            }
            if (vlSelfRef.__VdlySet__tb_RISCV_Pipeline__DOT__dut__DOT__DMEM_inst__DOT__memory__v1) {
                vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__DMEM_inst__DOT__memory[vlSelfRef.__VdlyDim0__tb_RISCV_Pipeline__DOT__dut__DOT__DMEM_inst__DOT__memory__v1] 
                    = ((0xffff00ffU & vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__DMEM_inst__DOT__memory
                        [vlSelfRef.__VdlyDim0__tb_RISCV_Pipeline__DOT__dut__DOT__DMEM_inst__DOT__memory__v1]) 
                       | ((IData)(vlSelfRef.__VdlyVal__tb_RISCV_Pipeline__DOT__dut__DOT__DMEM_inst__DOT__memory__v1) 
                          << 8U));
            }
            if (vlSelfRef.__VdlySet__tb_RISCV_Pipeline__DOT__dut__DOT__DMEM_inst__DOT__memory__v2) {
                vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__DMEM_inst__DOT__memory[vlSelfRef.__VdlyDim0__tb_RISCV_Pipeline__DOT__dut__DOT__DMEM_inst__DOT__memory__v2] 
                    = ((0xff00ffffU & vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__DMEM_inst__DOT__memory
                        [vlSelfRef.__VdlyDim0__tb_RISCV_Pipeline__DOT__dut__DOT__DMEM_inst__DOT__memory__v2]) 
                       | ((IData)(vlSelfRef.__VdlyVal__tb_RISCV_Pipeline__DOT__dut__DOT__DMEM_inst__DOT__memory__v2) 
                          << 0x00000010U));
            }
            if (vlSelfRef.__VdlySet__tb_RISCV_Pipeline__DOT__dut__DOT__DMEM_inst__DOT__memory__v3) {
                vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__DMEM_inst__DOT__memory[vlSelfRef.__VdlyDim0__tb_RISCV_Pipeline__DOT__dut__DOT__DMEM_inst__DOT__memory__v3] 
                    = ((0x00ffffffU & vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__DMEM_inst__DOT__memory
                        [vlSelfRef.__VdlyDim0__tb_RISCV_Pipeline__DOT__dut__DOT__DMEM_inst__DOT__memory__v3]) 
                       | ((IData)(vlSelfRef.__VdlyVal__tb_RISCV_Pipeline__DOT__dut__DOT__DMEM_inst__DOT__memory__v3) 
                          << 0x00000018U));
            }
            if (vlSelfRef.__VdlySet__tb_RISCV_Pipeline__DOT__dut__DOT__DMEM_inst__DOT__memory__v4) {
                vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__DMEM_inst__DOT__memory[vlSelfRef.__VdlyDim0__tb_RISCV_Pipeline__DOT__dut__DOT__DMEM_inst__DOT__memory__v4] 
                    = ((0x0000ffffU & vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__DMEM_inst__DOT__memory
                        [vlSelfRef.__VdlyDim0__tb_RISCV_Pipeline__DOT__dut__DOT__DMEM_inst__DOT__memory__v4]) 
                       | ((IData)(vlSelfRef.__VdlyVal__tb_RISCV_Pipeline__DOT__dut__DOT__DMEM_inst__DOT__memory__v4) 
                          << 0x00000010U));
            }
            if (vlSelfRef.__VdlySet__tb_RISCV_Pipeline__DOT__dut__DOT__DMEM_inst__DOT__memory__v5) {
                vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__DMEM_inst__DOT__memory[vlSelfRef.__VdlyDim0__tb_RISCV_Pipeline__DOT__dut__DOT__DMEM_inst__DOT__memory__v5] 
                    = ((0xffff0000U & vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__DMEM_inst__DOT__memory
                        [vlSelfRef.__VdlyDim0__tb_RISCV_Pipeline__DOT__dut__DOT__DMEM_inst__DOT__memory__v5]) 
                       | (IData)(vlSelfRef.__VdlyVal__tb_RISCV_Pipeline__DOT__dut__DOT__DMEM_inst__DOT__memory__v5));
            }
            if (vlSelfRef.__VdlySet__tb_RISCV_Pipeline__DOT__dut__DOT__DMEM_inst__DOT__memory__v6) {
                vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__DMEM_inst__DOT__memory[vlSelfRef.__VdlyDim0__tb_RISCV_Pipeline__DOT__dut__DOT__DMEM_inst__DOT__memory__v6] 
                    = vlSelfRef.__VdlyVal__tb_RISCV_Pipeline__DOT__dut__DOT__DMEM_inst__DOT__memory__v6;
            }
        }
    }
    if ((7ULL & vlSelfRef.__VnbaTriggered[0U])) {
        {
            // Inlined CFunc: _act_sequent__TOP__0
            vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__DMEM_inst__DOT__selected_byte 
                = (0x000000ffU & ((0U == (3U & vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__ALU_out_M))
                                   ? vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__DMEM_inst__DOT__memory
                                  [(0x000003ffU & (
                                                   (vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__ALU_out_M 
                                                    - (IData)(0x00000400U)) 
                                                   >> 2U))]
                                   : ((1U == (3U & vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__ALU_out_M))
                                       ? (vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__DMEM_inst__DOT__memory
                                          [(0x000003ffU 
                                            & ((vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__ALU_out_M 
                                                - (IData)(0x00000400U)) 
                                               >> 2U))] 
                                          >> 8U) : 
                                      ((2U == (3U & vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__ALU_out_M))
                                        ? (vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__DMEM_inst__DOT__memory
                                           [(0x000003ffU 
                                             & ((vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__ALU_out_M 
                                                 - (IData)(0x00000400U)) 
                                                >> 2U))] 
                                           >> 0x00000010U)
                                        : (vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__DMEM_inst__DOT__memory
                                           [(0x000003ffU 
                                             & ((vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__ALU_out_M 
                                                 - (IData)(0x00000400U)) 
                                                >> 2U))] 
                                           >> 0x00000018U)))));
            vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__DMEM_inst__DOT__selected_half 
                = (0x0000ffffU & ((2U & vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__ALU_out_M)
                                   ? (vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__DMEM_inst__DOT__memory
                                      [(0x000003ffU 
                                        & ((vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__ALU_out_M 
                                            - (IData)(0x00000400U)) 
                                           >> 2U))] 
                                      >> 0x00000010U)
                                   : vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__DMEM_inst__DOT__memory
                                  [(0x000003ffU & (
                                                   (vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__ALU_out_M 
                                                    - (IData)(0x00000400U)) 
                                                   >> 2U))]));
        }
    }
}

void Vtb_RISCV_Pipeline___024root___trigger_orInto__act_vec_vec(VlUnpacked<QData/*63:0*/, 1> &out, const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_RISCV_Pipeline___024root___trigger_orInto__act_vec_vec\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = (out[n] | in[n]);
        n = ((IData)(1U) + n);
    } while ((0U >= n));
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_RISCV_Pipeline___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG

bool Vtb_RISCV_Pipeline___024root___eval_phase__act(Vtb_RISCV_Pipeline___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_RISCV_Pipeline___024root___eval_phase__act\n"); );
    Vtb_RISCV_Pipeline__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VactExecute;
    // Body
    {
        // Inlined CFunc: _eval_triggers_vec__act
        vlSelfRef.__VactTriggered[0U] = (QData)((IData)(
                                                        ((vlSelfRef.__VdlySched.awaitingCurrentTime() 
                                                          << 2U) 
                                                         | ((((~ (IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__rst_n)) 
                                                              & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__tb_RISCV_Pipeline__DOT__rst_n__0)) 
                                                             << 1U) 
                                                            | ((IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__clk) 
                                                               & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__tb_RISCV_Pipeline__DOT__clk__0)))))));
        vlSelfRef.__Vtrigprevexpr___TOP__tb_RISCV_Pipeline__DOT__clk__0 
            = vlSelfRef.tb_RISCV_Pipeline__DOT__clk;
        vlSelfRef.__Vtrigprevexpr___TOP__tb_RISCV_Pipeline__DOT__rst_n__0 
            = vlSelfRef.tb_RISCV_Pipeline__DOT__rst_n;
    }
    Vtb_RISCV_Pipeline___024root___trigger_orInto__act_vec_vec(vlSelfRef.__VactTriggered, vlSelfRef.__VactTriggeredAcc);
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtb_RISCV_Pipeline___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
    }
#endif
    Vtb_RISCV_Pipeline___024root___trigger_orInto__act_vec_vec(vlSelfRef.__VnbaTriggered, vlSelfRef.__VactTriggered);
    __VactExecute = Vtb_RISCV_Pipeline___024root___trigger_anySet__act(vlSelfRef.__VactTriggered);
    if (__VactExecute) {
        vlSelfRef.__VactTriggeredAcc.fill(0ULL);
        {
            // Inlined CFunc: _timing_resume
            if ((4ULL & vlSelfRef.__VactTriggered[0U])) {
                vlSelfRef.__VdlySched.resume();
            }
        }
        {
            // Inlined CFunc: _eval_act
            if ((4ULL & vlSelfRef.__VactTriggered[0U])) {
                {
                    // Inlined CFunc: _act_sequent__TOP__0
                    vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__DMEM_inst__DOT__selected_byte 
                        = (0x000000ffU & ((0U == (3U 
                                                  & vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__ALU_out_M))
                                           ? vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__DMEM_inst__DOT__memory
                                          [(0x000003ffU 
                                            & ((vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__ALU_out_M 
                                                - (IData)(0x00000400U)) 
                                               >> 2U))]
                                           : ((1U == 
                                               (3U 
                                                & vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__ALU_out_M))
                                               ? (vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__DMEM_inst__DOT__memory
                                                  [
                                                  (0x000003ffU 
                                                   & ((vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__ALU_out_M 
                                                       - (IData)(0x00000400U)) 
                                                      >> 2U))] 
                                                  >> 8U)
                                               : ((2U 
                                                   == 
                                                   (3U 
                                                    & vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__ALU_out_M))
                                                   ? 
                                                  (vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__DMEM_inst__DOT__memory
                                                   [
                                                   (0x000003ffU 
                                                    & ((vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__ALU_out_M 
                                                        - (IData)(0x00000400U)) 
                                                       >> 2U))] 
                                                   >> 0x00000010U)
                                                   : 
                                                  (vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__DMEM_inst__DOT__memory
                                                   [
                                                   (0x000003ffU 
                                                    & ((vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__ALU_out_M 
                                                        - (IData)(0x00000400U)) 
                                                       >> 2U))] 
                                                   >> 0x00000018U)))));
                    vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__DMEM_inst__DOT__selected_half 
                        = (0x0000ffffU & ((2U & vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__ALU_out_M)
                                           ? (vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__DMEM_inst__DOT__memory
                                              [(0x000003ffU 
                                                & ((vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__ALU_out_M 
                                                    - (IData)(0x00000400U)) 
                                                   >> 2U))] 
                                              >> 0x00000010U)
                                           : vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__DMEM_inst__DOT__memory
                                          [(0x000003ffU 
                                            & ((vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__ALU_out_M 
                                                - (IData)(0x00000400U)) 
                                               >> 2U))]));
                }
            }
        }
    }
    return (__VactExecute);
}

bool Vtb_RISCV_Pipeline___024root___eval_phase__inact(Vtb_RISCV_Pipeline___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_RISCV_Pipeline___024root___eval_phase__inact\n"); );
    Vtb_RISCV_Pipeline__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VinactExecute;
    // Body
    __VinactExecute = vlSelfRef.__VdlySched.awaitingZeroDelay();
    if (__VinactExecute) {
        VL_FATAL_MT("tb/tb_RISCV_Pipeline.v", 4, "", "ZERODLY: Design Verilated with '--no-sched-zero-delay', but #0 delay executed at runtime");
    }
    return (__VinactExecute);
}

void Vtb_RISCV_Pipeline___024root___trigger_clear__act(VlUnpacked<QData/*63:0*/, 1> &out) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_RISCV_Pipeline___024root___trigger_clear__act\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = 0ULL;
        n = ((IData)(1U) + n);
    } while ((1U > n));
}

bool Vtb_RISCV_Pipeline___024root___eval_phase__nba(Vtb_RISCV_Pipeline___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_RISCV_Pipeline___024root___eval_phase__nba\n"); );
    Vtb_RISCV_Pipeline__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = Vtb_RISCV_Pipeline___024root___trigger_anySet__act(vlSelfRef.__VnbaTriggered);
    if (__VnbaExecute) {
        Vtb_RISCV_Pipeline___024root___eval_nba(vlSelf);
        Vtb_RISCV_Pipeline___024root___trigger_clear__act(vlSelfRef.__VnbaTriggered);
    }
    return (__VnbaExecute);
}

void Vtb_RISCV_Pipeline___024root___eval(Vtb_RISCV_Pipeline___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_RISCV_Pipeline___024root___eval\n"); );
    Vtb_RISCV_Pipeline__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __VnbaIterCount;
    // Body
    __VnbaIterCount = 0U;
    do {
        if (VL_UNLIKELY(((0x00002710U < __VnbaIterCount)))) {
#ifdef VL_DEBUG
            Vtb_RISCV_Pipeline___024root___dump_triggers__act(vlSelfRef.__VnbaTriggered, "nba"s);
#endif
            VL_FATAL_MT("tb/tb_RISCV_Pipeline.v", 4, "", "DIDNOTCONVERGE: NBA region did not converge after '--converge-limit' of 10000 tries");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        vlSelfRef.__VinactIterCount = 0U;
        do {
            if (VL_UNLIKELY(((0x00002710U < vlSelfRef.__VinactIterCount)))) {
                VL_FATAL_MT("tb/tb_RISCV_Pipeline.v", 4, "", "DIDNOTCONVERGE: Inactive region did not converge after '--converge-limit' of 10000 tries");
            }
            vlSelfRef.__VinactIterCount = ((IData)(1U) 
                                           + vlSelfRef.__VinactIterCount);
            vlSelfRef.__VactIterCount = 0U;
            do {
                if (VL_UNLIKELY(((0x00002710U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                    Vtb_RISCV_Pipeline___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
#endif
                    VL_FATAL_MT("tb/tb_RISCV_Pipeline.v", 4, "", "DIDNOTCONVERGE: Active region did not converge after '--converge-limit' of 10000 tries");
                }
                vlSelfRef.__VactIterCount = ((IData)(1U) 
                                             + vlSelfRef.__VactIterCount);
                vlSelfRef.__VactPhaseResult = Vtb_RISCV_Pipeline___024root___eval_phase__act(vlSelf);
            } while (vlSelfRef.__VactPhaseResult);
            vlSelfRef.__VinactPhaseResult = Vtb_RISCV_Pipeline___024root___eval_phase__inact(vlSelf);
        } while (vlSelfRef.__VinactPhaseResult);
        vlSelfRef.__VnbaPhaseResult = Vtb_RISCV_Pipeline___024root___eval_phase__nba(vlSelf);
    } while (vlSelfRef.__VnbaPhaseResult);
}

#ifdef VL_DEBUG
void Vtb_RISCV_Pipeline___024root___eval_debug_assertions(Vtb_RISCV_Pipeline___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_RISCV_Pipeline___024root___eval_debug_assertions\n"); );
    Vtb_RISCV_Pipeline__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}
#endif  // VL_DEBUG
