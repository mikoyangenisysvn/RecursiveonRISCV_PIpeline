// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_RISCV_Pipeline.h for the primary calling header

#include "Vtb_RISCV_Pipeline__pch.h"

VL_ATTR_COLD void Vtb_RISCV_Pipeline___024root___eval_static(Vtb_RISCV_Pipeline___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_RISCV_Pipeline___024root___eval_static\n"); );
    Vtb_RISCV_Pipeline__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    {
        // Inlined CFunc: _eval_static__TOP
        vlSelfRef.tb_RISCV_Pipeline__DOT__cycle = 0U;
        const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->vlNamep);
        vlSelfRef.tb_RISCV_Pipeline__DOT__report_result__Vstatic__canary_now = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 959975680580030529ull);
        vlSelfRef.tb_RISCV_Pipeline__DOT__report_result__Vstatic__a0 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10955872136178834038ull);
        vlSelfRef.tb_RISCV_Pipeline__DOT__report_result__Vstatic__cpi = 0.0;
        vlSelfRef.tb_RISCV_Pipeline__DOT__report_result__Vstatic__stack_used_bytes = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 18322657238132635584ull);
        vlSelfRef.tb_RISCV_Pipeline__DOT__report_result__Vstatic__flush_penalty_cycles = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7616259973614183254ull);
        vlSelfRef.tb_RISCV_Pipeline__DOT__report_result__Vstatic__total_overhead_cycles = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1911903232260747380ull);
    }
    vlSelfRef.__Vtrigprevexpr___TOP__tb_RISCV_Pipeline__DOT__clk__0 
        = vlSelfRef.tb_RISCV_Pipeline__DOT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__tb_RISCV_Pipeline__DOT__rst_n__0 
        = vlSelfRef.tb_RISCV_Pipeline__DOT__rst_n;
    do {
        vlSelfRef.__VactTriggeredAcc[vlSelfRef.__Vi] 
            = vlSelfRef.__VactTriggered[vlSelfRef.__Vi];
        vlSelfRef.__Vi = ((IData)(1U) + vlSelfRef.__Vi);
    } while ((0U >= vlSelfRef.__Vi));
}

VL_ATTR_COLD void Vtb_RISCV_Pipeline___024root___eval_final(Vtb_RISCV_Pipeline___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_RISCV_Pipeline___024root___eval_final\n"); );
    Vtb_RISCV_Pipeline__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_RISCV_Pipeline___024root___dump_triggers__stl(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vtb_RISCV_Pipeline___024root___eval_phase__stl(Vtb_RISCV_Pipeline___024root* vlSelf);

VL_ATTR_COLD void Vtb_RISCV_Pipeline___024root___eval_settle(Vtb_RISCV_Pipeline___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_RISCV_Pipeline___024root___eval_settle\n"); );
    Vtb_RISCV_Pipeline__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __VstlIterCount;
    // Body
    __VstlIterCount = 0U;
    vlSelfRef.__VstlFirstIteration = 1U;
    do {
        if (VL_UNLIKELY(((0x00002710U < __VstlIterCount)))) {
#ifdef VL_DEBUG
            Vtb_RISCV_Pipeline___024root___dump_triggers__stl(vlSelfRef.__VstlTriggered, "stl"s);
#endif
            VL_FATAL_MT("tb/tb_RISCV_Pipeline.v", 4, "", "DIDNOTCONVERGE: Settle region did not converge after '--converge-limit' of 10000 tries");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        vlSelfRef.__VstlPhaseResult = Vtb_RISCV_Pipeline___024root___eval_phase__stl(vlSelf);
        vlSelfRef.__VstlFirstIteration = 0U;
    } while (vlSelfRef.__VstlPhaseResult);
}

VL_ATTR_COLD bool Vtb_RISCV_Pipeline___024root___trigger_anySet__stl(const VlUnpacked<QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_RISCV_Pipeline___024root___dump_triggers__stl(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_RISCV_Pipeline___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(Vtb_RISCV_Pipeline___024root___trigger_anySet__stl(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD bool Vtb_RISCV_Pipeline___024root___trigger_anySet__stl(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_RISCV_Pipeline___024root___trigger_anySet__stl\n"); );
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

extern const VlUnpacked<CData/*2:0*/, 256> Vtb_RISCV_Pipeline__ConstPool__TABLE_h6a3b8cf2_0;
extern const VlUnpacked<CData/*0:0*/, 256> Vtb_RISCV_Pipeline__ConstPool__TABLE_h41ca9fcd_0;
extern const VlUnpacked<CData/*0:0*/, 256> Vtb_RISCV_Pipeline__ConstPool__TABLE_h35a60bd7_0;
extern const VlUnpacked<CData/*0:0*/, 128> Vtb_RISCV_Pipeline__ConstPool__TABLE_h3cb0ade6_0;

VL_ATTR_COLD void Vtb_RISCV_Pipeline___024root___stl_sequent__TOP__0(Vtb_RISCV_Pipeline___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_RISCV_Pipeline___024root___stl_sequent__TOP__0\n"); );
    Vtb_RISCV_Pipeline__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__DMEM_inst__DOT__selected_byte 
        = (0x000000ffU & ((0U == (3U & vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__ALU_out_M))
                           ? vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__DMEM_inst__DOT__memory
                          [(0x000003ffU & ((vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__ALU_out_M 
                                            - (IData)(0x00000400U)) 
                                           >> 2U))]
                           : ((1U == (3U & vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__ALU_out_M))
                               ? (vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__DMEM_inst__DOT__memory
                                  [(0x000003ffU & (
                                                   (vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__ALU_out_M 
                                                    - (IData)(0x00000400U)) 
                                                   >> 2U))] 
                                  >> 8U) : ((2U == 
                                             (3U & vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__ALU_out_M))
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
                              [(0x000003ffU & ((vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__ALU_out_M 
                                                - (IData)(0x00000400U)) 
                                               >> 2U))] 
                              >> 0x00000010U) : vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__DMEM_inst__DOT__memory
                          [(0x000003ffU & ((vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__ALU_out_M 
                                            - (IData)(0x00000400U)) 
                                           >> 2U))]));
    vlSelfRef.__VdfgRegularize_h6e95ff9d_0_2 = ((IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__RegWEn_W) 
                                                & (0U 
                                                   != (IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__addrD_W)));
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
    vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__ForwardData_M 
        = ((2U == (IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__WBSel_M))
            ? vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__PC_Plus4_M
            : vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__ALU_out_M);
    vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__DataD_W 
        = ((0U == (IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__WBSel_W))
            ? vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__DataR_W
            : ((1U == (IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__WBSel_W))
                ? vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__ALU_out_W
                : vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__PC_Plus4_W));
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
    vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__fwd_DataB_E 
        = ((2U == (IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__fwdB))
            ? vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__ForwardData_M
            : ((1U == (IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__fwdB))
                ? vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__DataD_W
                : vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__DataB_E));
    vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__fwd_DataA_E 
        = ((2U == (IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__fwdA))
            ? vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__ForwardData_M
            : ((1U == (IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__fwdA))
                ? vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__DataD_W
                : vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__DataA_E));
    vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__Mux_ALU_DataB_E 
        = ((IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__BSel_E)
            ? vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__Imm_E
            : vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__fwd_DataB_E);
    vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__Mux_ALU_DataA_E 
        = ((IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__ASel_E)
            ? vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__PC_E
            : vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__fwd_DataA_E);
    vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__BrEq_E 
        = (vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__fwd_DataA_E 
           == vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__fwd_DataB_E);
    vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__BrLT_E 
        = ((IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__BrUn_E)
            ? (vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__fwd_DataA_E 
               < vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__fwd_DataB_E)
            : VL_LTS_III(32, vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__fwd_DataA_E, vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__fwd_DataB_E));
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
    vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__PC_target_E 
        = ((0xfffffffeU & vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__ALU_out_E) 
           | (1U & ((~ (IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__Is_JALR_E)) 
                    & vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__ALU_out_E)));
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
}

VL_ATTR_COLD bool Vtb_RISCV_Pipeline___024root___eval_phase__stl(Vtb_RISCV_Pipeline___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_RISCV_Pipeline___024root___eval_phase__stl\n"); );
    Vtb_RISCV_Pipeline__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VstlExecute;
    // Body
    {
        // Inlined CFunc: _eval_triggers_vec__stl
        vlSelfRef.__VstlTriggered[0U] = ((0xfffffffffffffffeULL 
                                          & vlSelfRef.__VstlTriggered[0U]) 
                                         | (IData)((IData)(vlSelfRef.__VstlFirstIteration)));
    }
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtb_RISCV_Pipeline___024root___dump_triggers__stl(vlSelfRef.__VstlTriggered, "stl"s);
    }
#endif
    __VstlExecute = Vtb_RISCV_Pipeline___024root___trigger_anySet__stl(vlSelfRef.__VstlTriggered);
    if (__VstlExecute) {
        {
            // Inlined CFunc: _eval_stl
            if ((1ULL & vlSelfRef.__VstlTriggered[0U])) {
                Vtb_RISCV_Pipeline___024root___stl_sequent__TOP__0(vlSelf);
                {
                    // Inlined CFunc: __Vm_traceActivitySetAll
                    vlSelfRef.__Vm_traceActivity[0U] = 1U;
                    vlSelfRef.__Vm_traceActivity[1U] = 1U;
                    vlSelfRef.__Vm_traceActivity[2U] = 1U;
                    vlSelfRef.__Vm_traceActivity[3U] = 1U;
                }
            }
        }
    }
    return (__VstlExecute);
}

bool Vtb_RISCV_Pipeline___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_RISCV_Pipeline___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_RISCV_Pipeline___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(Vtb_RISCV_Pipeline___024root___trigger_anySet__act(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: @(posedge tb_RISCV_Pipeline.clk)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 1U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 1 is active: @(negedge tb_RISCV_Pipeline.rst_n)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 2U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 2 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtb_RISCV_Pipeline___024root___ctor_var_reset(Vtb_RISCV_Pipeline___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_RISCV_Pipeline___024root___ctor_var_reset\n"); );
    Vtb_RISCV_Pipeline__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->vlNamep);
    vlSelf->tb_RISCV_Pipeline__DOT__clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13627959489628157483ull);
    vlSelf->tb_RISCV_Pipeline__DOT__rst_n = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9416098136144562625ull);
    vlSelf->tb_RISCV_Pipeline__DOT__fd = 0;
    vlSelf->tb_RISCV_Pipeline__DOT__loaded = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2545743934969495059ull);
    vlSelf->tb_RISCV_Pipeline__DOT__instr_count = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8606603958226262209ull);
    vlSelf->tb_RISCV_Pipeline__DOT__stall_count = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3188364048500591897ull);
    vlSelf->tb_RISCV_Pipeline__DOT__flush_count = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 9195951212735183319ull);
    vlSelf->tb_RISCV_Pipeline__DOT__pipeline_filled = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3465048714351870960ull);
    vlSelf->tb_RISCV_Pipeline__DOT__PCSel_E_d1 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12266930982158944251ull);
    vlSelf->tb_RISCV_Pipeline__DOT__min_sp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 9424941001883920030ull);
    vlSelf->tb_RISCV_Pipeline__DOT__min_sp_cycle = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14444082914981158418ull);
    vlSelf->tb_RISCV_Pipeline__DOT__sp_initialized = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7478792087403894903ull);
    vlSelf->tb_RISCV_Pipeline__DOT__done_reported = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12378809288922140426ull);
    vlSelf->tb_RISCV_Pipeline__DOT__done_cycle = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14428702719199679397ull);
    vlSelf->tb_RISCV_Pipeline__DOT__dut__DOT__stall_load = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15892245384309564870ull);
    vlSelf->tb_RISCV_Pipeline__DOT__dut__DOT__stall_if_id = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5513160517482480924ull);
    vlSelf->tb_RISCV_Pipeline__DOT__dut__DOT__bubble_id_ex = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11711766861435830490ull);
    vlSelf->tb_RISCV_Pipeline__DOT__dut__DOT__PC_F = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 224919878626221876ull);
    vlSelf->tb_RISCV_Pipeline__DOT__dut__DOT__PC_next_F = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8663997134317673494ull);
    vlSelf->tb_RISCV_Pipeline__DOT__dut__DOT__PC_target_E = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 16683467597759274536ull);
    vlSelf->tb_RISCV_Pipeline__DOT__dut__DOT__PC_D = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 9865107711940368014ull);
    vlSelf->tb_RISCV_Pipeline__DOT__dut__DOT__PC_Plus4_D = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3242120680615137639ull);
    vlSelf->tb_RISCV_Pipeline__DOT__dut__DOT__Instr_D = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7205015039376506429ull);
    vlSelf->tb_RISCV_Pipeline__DOT__dut__DOT__DataD_W = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3996391345795967892ull);
    vlSelf->tb_RISCV_Pipeline__DOT__dut__DOT__addrD_W = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 2521845980200234850ull);
    vlSelf->tb_RISCV_Pipeline__DOT__dut__DOT__RegWEn_W = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11195462389761577027ull);
    vlSelf->tb_RISCV_Pipeline__DOT__dut__DOT__PC_E = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7909110278348997113ull);
    vlSelf->tb_RISCV_Pipeline__DOT__dut__DOT__PC_Plus4_E = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 5986834024507800970ull);
    vlSelf->tb_RISCV_Pipeline__DOT__dut__DOT__DataA_E = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 16415409653558448546ull);
    vlSelf->tb_RISCV_Pipeline__DOT__dut__DOT__DataB_E = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13777748752652735883ull);
    vlSelf->tb_RISCV_Pipeline__DOT__dut__DOT__Imm_E = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14850532297946310620ull);
    vlSelf->tb_RISCV_Pipeline__DOT__dut__DOT__addrA_E = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 15503304897156847319ull);
    vlSelf->tb_RISCV_Pipeline__DOT__dut__DOT__addrB_E = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 7869246332376056221ull);
    vlSelf->tb_RISCV_Pipeline__DOT__dut__DOT__addrD_E = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 11368225956241011094ull);
    vlSelf->tb_RISCV_Pipeline__DOT__dut__DOT__funct3_E = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 17091896111398970223ull);
    vlSelf->tb_RISCV_Pipeline__DOT__dut__DOT__ALUSel_E = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 14832446746512339436ull);
    vlSelf->tb_RISCV_Pipeline__DOT__dut__DOT__WBSel_E = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 18258474620331553508ull);
    vlSelf->tb_RISCV_Pipeline__DOT__dut__DOT__RegWEn_E = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3363632879522174815ull);
    vlSelf->tb_RISCV_Pipeline__DOT__dut__DOT__BrUn_E = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15428627372029966730ull);
    vlSelf->tb_RISCV_Pipeline__DOT__dut__DOT__ASel_E = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9431609646057914165ull);
    vlSelf->tb_RISCV_Pipeline__DOT__dut__DOT__BSel_E = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14817293754586369793ull);
    vlSelf->tb_RISCV_Pipeline__DOT__dut__DOT__MemRW_E = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14446823015937100424ull);
    vlSelf->tb_RISCV_Pipeline__DOT__dut__DOT__Is_Branch_E = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13197114419694371563ull);
    vlSelf->tb_RISCV_Pipeline__DOT__dut__DOT__Is_Jump_E = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1628359824837201764ull);
    vlSelf->tb_RISCV_Pipeline__DOT__dut__DOT__Is_JALR_E = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16375712135683819460ull);
    vlSelf->tb_RISCV_Pipeline__DOT__dut__DOT__Is_Load_E = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10459937267334651729ull);
    vlSelf->tb_RISCV_Pipeline__DOT__dut__DOT__addrD_M = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 5687404531256865586ull);
    vlSelf->tb_RISCV_Pipeline__DOT__dut__DOT__RegWEn_M = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10638446090551023994ull);
    vlSelf->tb_RISCV_Pipeline__DOT__dut__DOT__fwdA = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 14974397799625567205ull);
    vlSelf->tb_RISCV_Pipeline__DOT__dut__DOT__fwdB = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 13567718086799296523ull);
    vlSelf->tb_RISCV_Pipeline__DOT__dut__DOT__ForwardData_M = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 9224539242556725464ull);
    vlSelf->tb_RISCV_Pipeline__DOT__dut__DOT__fwd_DataA_E = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 5241537876956021980ull);
    vlSelf->tb_RISCV_Pipeline__DOT__dut__DOT__fwd_DataB_E = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 15815940454953889093ull);
    vlSelf->tb_RISCV_Pipeline__DOT__dut__DOT__Mux_ALU_DataA_E = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13518346687907460608ull);
    vlSelf->tb_RISCV_Pipeline__DOT__dut__DOT__Mux_ALU_DataB_E = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2246589222307472219ull);
    vlSelf->tb_RISCV_Pipeline__DOT__dut__DOT__ALU_out_E = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 15027782737683695570ull);
    vlSelf->tb_RISCV_Pipeline__DOT__dut__DOT__BrEq_E = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11502259298534683160ull);
    vlSelf->tb_RISCV_Pipeline__DOT__dut__DOT__BrLT_E = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17354798209827537177ull);
    vlSelf->tb_RISCV_Pipeline__DOT__dut__DOT__ALU_out_M = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 4478966443289478152ull);
    vlSelf->tb_RISCV_Pipeline__DOT__dut__DOT__DataB_M = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14256078811001221394ull);
    vlSelf->tb_RISCV_Pipeline__DOT__dut__DOT__PC_Plus4_M = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1079580748496826131ull);
    vlSelf->tb_RISCV_Pipeline__DOT__dut__DOT__WBSel_M = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 3246936292005624051ull);
    vlSelf->tb_RISCV_Pipeline__DOT__dut__DOT__MemRW_M = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9554850826956976980ull);
    vlSelf->tb_RISCV_Pipeline__DOT__dut__DOT__funct3_M = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 11786894056972619883ull);
    vlSelf->tb_RISCV_Pipeline__DOT__dut__DOT__ALU_out_W = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 165060650070160184ull);
    vlSelf->tb_RISCV_Pipeline__DOT__dut__DOT__DataR_W = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12195365641296243100ull);
    vlSelf->tb_RISCV_Pipeline__DOT__dut__DOT__PC_Plus4_W = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 4945044618185295450ull);
    vlSelf->tb_RISCV_Pipeline__DOT__dut__DOT__WBSel_W = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 17169496881622692908ull);
    for (int __Vi0 = 0; __Vi0 < 1025; ++__Vi0) {
        vlSelf->tb_RISCV_Pipeline__DOT__dut__DOT__DMEM_inst__DOT__memory[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 4492356574143438825ull);
    }
    vlSelf->tb_RISCV_Pipeline__DOT__dut__DOT__DMEM_inst__DOT__selected_byte = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 10328261314369848473ull);
    vlSelf->tb_RISCV_Pipeline__DOT__dut__DOT__DMEM_inst__DOT__selected_half = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 4246793290556915772ull);
    for (int __Vi0 = 0; __Vi0 < 32; ++__Vi0) {
        vlSelf->tb_RISCV_Pipeline__DOT__dut__DOT__Reg_inst__DOT__registers[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 18351382139957046204ull);
    }
    vlSelf->tb_RISCV_Pipeline__DOT__dut__DOT__Reg_inst__DOT__i = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11597811706712945814ull);
    for (int __Vi0 = 0; __Vi0 < 256; ++__Vi0) {
        vlSelf->tb_RISCV_Pipeline__DOT__dut__DOT__IMEM_inst__DOT__memory[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 5539506111529541332ull);
    }
    vlSelf->__VdfgRegularize_h6e95ff9d_0_0 = 0;
    vlSelf->__VdfgRegularize_h6e95ff9d_0_1 = 0;
    vlSelf->__VdfgRegularize_h6e95ff9d_0_2 = 0;
    vlSelf->__VdfgRegularize_h6e95ff9d_0_3 = 0;
    vlSelf->__VdfgRegularize_h6e95ff9d_0_4 = 0;
    vlSelf->__VdfgRegularize_h6e95ff9d_0_5 = 0;
    vlSelf->__VdlyVal__tb_RISCV_Pipeline__DOT__dut__DOT__DMEM_inst__DOT__memory__v0 = 0;
    vlSelf->__VdlyDim0__tb_RISCV_Pipeline__DOT__dut__DOT__DMEM_inst__DOT__memory__v0 = 0;
    vlSelf->__VdlySet__tb_RISCV_Pipeline__DOT__dut__DOT__DMEM_inst__DOT__memory__v0 = 0;
    vlSelf->__VdlyVal__tb_RISCV_Pipeline__DOT__dut__DOT__DMEM_inst__DOT__memory__v1 = 0;
    vlSelf->__VdlyDim0__tb_RISCV_Pipeline__DOT__dut__DOT__DMEM_inst__DOT__memory__v1 = 0;
    vlSelf->__VdlySet__tb_RISCV_Pipeline__DOT__dut__DOT__DMEM_inst__DOT__memory__v1 = 0;
    vlSelf->__VdlyVal__tb_RISCV_Pipeline__DOT__dut__DOT__DMEM_inst__DOT__memory__v2 = 0;
    vlSelf->__VdlyDim0__tb_RISCV_Pipeline__DOT__dut__DOT__DMEM_inst__DOT__memory__v2 = 0;
    vlSelf->__VdlySet__tb_RISCV_Pipeline__DOT__dut__DOT__DMEM_inst__DOT__memory__v2 = 0;
    vlSelf->__VdlyVal__tb_RISCV_Pipeline__DOT__dut__DOT__DMEM_inst__DOT__memory__v3 = 0;
    vlSelf->__VdlyDim0__tb_RISCV_Pipeline__DOT__dut__DOT__DMEM_inst__DOT__memory__v3 = 0;
    vlSelf->__VdlySet__tb_RISCV_Pipeline__DOT__dut__DOT__DMEM_inst__DOT__memory__v3 = 0;
    vlSelf->__VdlyVal__tb_RISCV_Pipeline__DOT__dut__DOT__DMEM_inst__DOT__memory__v4 = 0;
    vlSelf->__VdlyDim0__tb_RISCV_Pipeline__DOT__dut__DOT__DMEM_inst__DOT__memory__v4 = 0;
    vlSelf->__VdlySet__tb_RISCV_Pipeline__DOT__dut__DOT__DMEM_inst__DOT__memory__v4 = 0;
    vlSelf->__VdlyVal__tb_RISCV_Pipeline__DOT__dut__DOT__DMEM_inst__DOT__memory__v5 = 0;
    vlSelf->__VdlyDim0__tb_RISCV_Pipeline__DOT__dut__DOT__DMEM_inst__DOT__memory__v5 = 0;
    vlSelf->__VdlySet__tb_RISCV_Pipeline__DOT__dut__DOT__DMEM_inst__DOT__memory__v5 = 0;
    vlSelf->__VdlyVal__tb_RISCV_Pipeline__DOT__dut__DOT__DMEM_inst__DOT__memory__v6 = 0;
    vlSelf->__VdlyDim0__tb_RISCV_Pipeline__DOT__dut__DOT__DMEM_inst__DOT__memory__v6 = 0;
    vlSelf->__VdlySet__tb_RISCV_Pipeline__DOT__dut__DOT__DMEM_inst__DOT__memory__v6 = 0;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VstlTriggered[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VactTriggered[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VactTriggeredAcc[__Vi0] = 0;
    }
    vlSelf->__Vtrigprevexpr___TOP__tb_RISCV_Pipeline__DOT__clk__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__tb_RISCV_Pipeline__DOT__rst_n__0 = 0;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VnbaTriggered[__Vi0] = 0;
    }
    vlSelf->__Vi = 0;
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}
