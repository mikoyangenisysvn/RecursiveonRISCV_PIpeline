// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals

#include "verilated_vcd_c.h"
#include "Vtb_RISCV_Pipeline__Syms.h"


void Vtb_RISCV_Pipeline___024root__trace_chg_0_sub_0(Vtb_RISCV_Pipeline___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vtb_RISCV_Pipeline___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_RISCV_Pipeline___024root__trace_chg_0\n"); );
    // Body
    Vtb_RISCV_Pipeline___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtb_RISCV_Pipeline___024root*>(voidSelf);
    Vtb_RISCV_Pipeline__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    Vtb_RISCV_Pipeline___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

extern const VlUnpacked<CData/*0:0*/, 128> Vtb_RISCV_Pipeline__ConstPool__TABLE_h3cb0ade6_0;
extern const VlUnpacked<CData/*2:0*/, 256> Vtb_RISCV_Pipeline__ConstPool__TABLE_h6a3b8cf2_0;
extern const VlUnpacked<CData/*0:0*/, 256> Vtb_RISCV_Pipeline__ConstPool__TABLE_hd82a1090_0;
extern const VlUnpacked<CData/*0:0*/, 256> Vtb_RISCV_Pipeline__ConstPool__TABLE_hadc3105f_0;
extern const VlUnpacked<CData/*0:0*/, 256> Vtb_RISCV_Pipeline__ConstPool__TABLE_h5ac4bd78_0;
extern const VlUnpacked<CData/*0:0*/, 256> Vtb_RISCV_Pipeline__ConstPool__TABLE_h70db338c_0;
extern const VlUnpacked<CData/*0:0*/, 256> Vtb_RISCV_Pipeline__ConstPool__TABLE_h2471d231_0;
extern const VlUnpacked<CData/*1:0*/, 256> Vtb_RISCV_Pipeline__ConstPool__TABLE_h7320afc7_0;
extern const VlUnpacked<CData/*3:0*/, 128> Vtb_RISCV_Pipeline__ConstPool__TABLE_h4d17e3b4_0;
extern const VlUnpacked<CData/*0:0*/, 256> Vtb_RISCV_Pipeline__ConstPool__TABLE_hc9903a88_0;
extern const VlUnpacked<CData/*0:0*/, 256> Vtb_RISCV_Pipeline__ConstPool__TABLE_h2817a251_0;
extern const VlUnpacked<CData/*0:0*/, 256> Vtb_RISCV_Pipeline__ConstPool__TABLE_hb37d2bb4_0;
extern const VlUnpacked<CData/*0:0*/, 256> Vtb_RISCV_Pipeline__ConstPool__TABLE_h41ca9fcd_0;
extern const VlUnpacked<CData/*0:0*/, 256> Vtb_RISCV_Pipeline__ConstPool__TABLE_h35a60bd7_0;
extern const VlUnpacked<CData/*0:0*/, 256> Vtb_RISCV_Pipeline__ConstPool__TABLE_h020b1e42_0;
extern const VlUnpacked<CData/*0:0*/, 256> Vtb_RISCV_Pipeline__ConstPool__TABLE_h0ae2a928_0;
extern const VlUnpacked<CData/*0:0*/, 256> Vtb_RISCV_Pipeline__ConstPool__TABLE_h77ea30c7_0;
extern const VlUnpacked<CData/*0:0*/, 256> Vtb_RISCV_Pipeline__ConstPool__TABLE_hb03ac117_0;
void Vtb_RISCV_Pipeline___024root__trace_chg_dtype____0(Vtb_RISCV_Pipeline___024root* vlSelf, VerilatedVcd::Buffer* bufp, uint32_t offset, const VlUnpacked<IData/*31:0*/, 32>& __VdtypeVar);

void Vtb_RISCV_Pipeline___024root__trace_chg_0_sub_0(Vtb_RISCV_Pipeline___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_RISCV_Pipeline___024root__trace_chg_0_sub_0\n"); );
    Vtb_RISCV_Pipeline__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 0);
    if (VL_UNLIKELY(((vlSelfRef.__Vm_traceActivity[1U] 
                      | vlSelfRef.__Vm_traceActivity[2U])))) {
        bufp->chgIData(oldp+0,(vlSelfRef.tb_RISCV_Pipeline__DOT__instr_count),32);
        bufp->chgIData(oldp+1,(vlSelfRef.tb_RISCV_Pipeline__DOT__stall_count),32);
        bufp->chgIData(oldp+2,(vlSelfRef.tb_RISCV_Pipeline__DOT__flush_count),32);
        bufp->chgBit(oldp+3,(vlSelfRef.tb_RISCV_Pipeline__DOT__pipeline_filled));
        bufp->chgBit(oldp+4,(vlSelfRef.tb_RISCV_Pipeline__DOT__PCSel_E_d1));
        bufp->chgIData(oldp+5,(vlSelfRef.tb_RISCV_Pipeline__DOT__min_sp),32);
        bufp->chgIData(oldp+6,(vlSelfRef.tb_RISCV_Pipeline__DOT__min_sp_cycle),32);
        bufp->chgBit(oldp+7,(vlSelfRef.tb_RISCV_Pipeline__DOT__sp_initialized));
        bufp->chgBit(oldp+8,(vlSelfRef.tb_RISCV_Pipeline__DOT__done_reported));
        bufp->chgIData(oldp+9,(vlSelfRef.tb_RISCV_Pipeline__DOT__done_cycle),32);
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[3U]))) {
        bufp->chgBit(oldp+10,(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__stall_load));
        bufp->chgBit(oldp+11,(Vtb_RISCV_Pipeline__ConstPool__TABLE_h3cb0ade6_0
                              [((((IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__BrEq_E) 
                                  << 6U) | ((IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__BrLT_E) 
                                            << 5U)) 
                                | (((IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__funct3_E) 
                                    << 2U) | (((IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__Is_Branch_E) 
                                               << 1U) 
                                              | (IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__Is_Jump_E))))]));
        bufp->chgBit(oldp+12,((1U & ((~ (IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__stall_load)) 
                                     | Vtb_RISCV_Pipeline__ConstPool__TABLE_h3cb0ade6_0
                                     [((((IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__BrEq_E) 
                                         << 6U) | ((IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__BrLT_E) 
                                                   << 5U)) 
                                       | (((IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__funct3_E) 
                                           << 2U) | 
                                          (((IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__Is_Branch_E) 
                                            << 1U) 
                                           | (IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__Is_Jump_E))))]))));
        bufp->chgBit(oldp+13,(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__stall_if_id));
        bufp->chgBit(oldp+14,(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__bubble_id_ex));
        bufp->chgIData(oldp+15,(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__PC_F),32);
        bufp->chgIData(oldp+16,((Vtb_RISCV_Pipeline__ConstPool__TABLE_h3cb0ade6_0
                                 [((((IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__BrEq_E) 
                                     << 6U) | ((IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__BrLT_E) 
                                               << 5U)) 
                                   | (((IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__funct3_E) 
                                       << 2U) | (((IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__Is_Branch_E) 
                                                  << 1U) 
                                                 | (IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__Is_Jump_E))))]
                                  ? vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__PC_target_E
                                  : ((IData)(4U) + vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__PC_F))),32);
        bufp->chgIData(oldp+17,(((IData)(4U) + vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__PC_F)),32);
        bufp->chgIData(oldp+18,((vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__PC_F 
                                 >> 2U)),32);
        bufp->chgIData(oldp+19,(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__PC_target_E),32);
        bufp->chgIData(oldp+20,(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__PC_D),32);
        bufp->chgIData(oldp+21,(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__PC_Plus4_D),32);
        bufp->chgIData(oldp+22,(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__Instr_D),32);
        bufp->chgCData(oldp+23,(Vtb_RISCV_Pipeline__ConstPool__TABLE_h6a3b8cf2_0
                                [vlSelfRef.__VdfgRegularize_h6e95ff9d_0_0]),3);
        bufp->chgBit(oldp+24,(Vtb_RISCV_Pipeline__ConstPool__TABLE_hd82a1090_0
                              [vlSelfRef.__VdfgRegularize_h6e95ff9d_0_0]));
        bufp->chgBit(oldp+25,(Vtb_RISCV_Pipeline__ConstPool__TABLE_hadc3105f_0
                              [vlSelfRef.__VdfgRegularize_h6e95ff9d_0_0]));
        bufp->chgBit(oldp+26,(Vtb_RISCV_Pipeline__ConstPool__TABLE_h5ac4bd78_0
                              [vlSelfRef.__VdfgRegularize_h6e95ff9d_0_0]));
        bufp->chgBit(oldp+27,(Vtb_RISCV_Pipeline__ConstPool__TABLE_h70db338c_0
                              [vlSelfRef.__VdfgRegularize_h6e95ff9d_0_0]));
        bufp->chgBit(oldp+28,(Vtb_RISCV_Pipeline__ConstPool__TABLE_h2471d231_0
                              [vlSelfRef.__VdfgRegularize_h6e95ff9d_0_0]));
        bufp->chgCData(oldp+29,(Vtb_RISCV_Pipeline__ConstPool__TABLE_h7320afc7_0
                                [vlSelfRef.__VdfgRegularize_h6e95ff9d_0_0]),2);
        bufp->chgCData(oldp+30,(Vtb_RISCV_Pipeline__ConstPool__TABLE_h4d17e3b4_0
                                [(((((IData)(Vtb_RISCV_Pipeline__ConstPool__TABLE_hc9903a88_0
                                             [vlSelfRef.__VdfgRegularize_h6e95ff9d_0_0]) 
                                     << 1U) << 5U) 
                                   | (0x00000020U & 
                                      (vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__Instr_D 
                                       >> 0x00000019U))) 
                                  | ((0x0000001cU & 
                                      (vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__Instr_D 
                                       >> 0x0000000aU)) 
                                     | (((IData)(Vtb_RISCV_Pipeline__ConstPool__TABLE_h2817a251_0
                                                 [vlSelfRef.__VdfgRegularize_h6e95ff9d_0_0]) 
                                         << 1U) | Vtb_RISCV_Pipeline__ConstPool__TABLE_hb37d2bb4_0
                                        [vlSelfRef.__VdfgRegularize_h6e95ff9d_0_0])))]),4);
        bufp->chgBit(oldp+31,(Vtb_RISCV_Pipeline__ConstPool__TABLE_h41ca9fcd_0
                              [vlSelfRef.__VdfgRegularize_h6e95ff9d_0_0]));
        bufp->chgBit(oldp+32,(Vtb_RISCV_Pipeline__ConstPool__TABLE_h35a60bd7_0
                              [vlSelfRef.__VdfgRegularize_h6e95ff9d_0_0]));
        bufp->chgBit(oldp+33,(Vtb_RISCV_Pipeline__ConstPool__TABLE_h020b1e42_0
                              [vlSelfRef.__VdfgRegularize_h6e95ff9d_0_0]));
        bufp->chgBit(oldp+34,(Vtb_RISCV_Pipeline__ConstPool__TABLE_h0ae2a928_0
                              [vlSelfRef.__VdfgRegularize_h6e95ff9d_0_0]));
        bufp->chgBit(oldp+35,(Vtb_RISCV_Pipeline__ConstPool__TABLE_h77ea30c7_0
                              [vlSelfRef.__VdfgRegularize_h6e95ff9d_0_0]));
        bufp->chgBit(oldp+36,(Vtb_RISCV_Pipeline__ConstPool__TABLE_hb03ac117_0
                              [vlSelfRef.__VdfgRegularize_h6e95ff9d_0_0]));
        bufp->chgIData(oldp+37,(((4U & Vtb_RISCV_Pipeline__ConstPool__TABLE_h6a3b8cf2_0
                                  [vlSelfRef.__VdfgRegularize_h6e95ff9d_0_0])
                                  ? ((- (IData)((1U 
                                                 & (~ (IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_1))))) 
                                     & (((((0x00000ffeU 
                                            & ((- (IData)(
                                                          (vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__Instr_D 
                                                           >> 0x0000001fU))) 
                                               << 1U)) 
                                           | (vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__Instr_D 
                                              >> 0x0000001fU)) 
                                          << 0x00000014U) 
                                         | ((((0x000001feU 
                                               & (vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__Instr_D 
                                                  >> 0x0000000bU)) 
                                              | (1U 
                                                 & (vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__Instr_D 
                                                    >> 0x00000014U))) 
                                             << 0x0000000bU) 
                                            | (0x000007feU 
                                               & (vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__Instr_D 
                                                  >> 0x00000014U)))) 
                                        & (- (IData)(
                                                     (1U 
                                                      & (~ (IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_5)))))))
                                  : ((IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_5)
                                      ? (((IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_1)
                                           ? (0x7ffff800U 
                                              & (vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__Instr_D 
                                                 >> 1U))
                                           : ((0x7ffff000U 
                                               & ((- (IData)(
                                                             (vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__Instr_D 
                                                              >> 0x0000001fU))) 
                                                  << 0x0000000cU)) 
                                              | ((((2U 
                                                    & (vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__Instr_D 
                                                       >> 0x0000001eU)) 
                                                   | (1U 
                                                      & (vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__Instr_D 
                                                         >> 7U))) 
                                                  << 0x0000000aU) 
                                                 | ((0x000003f0U 
                                                     & (vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__Instr_D 
                                                        >> 0x00000015U)) 
                                                    | (0x0000000fU 
                                                       & (vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__Instr_D 
                                                          >> 8U)))))) 
                                         << 1U) : (
                                                   ((- (IData)(
                                                               (vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__Instr_D 
                                                                >> 0x0000001fU))) 
                                                    << 0x0000000cU) 
                                                   | ((0x00000fe0U 
                                                       & (vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__Instr_D 
                                                          >> 0x00000014U)) 
                                                      | (0x0000001fU 
                                                         & ((IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_1)
                                                             ? 
                                                            (vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__Instr_D 
                                                             >> 7U)
                                                             : 
                                                            (vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__Instr_D 
                                                             >> 0x00000014U)))))))),32);
        bufp->chgIData(oldp+38,(((((IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__RegWEn_W) 
                                   & (IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_3))
                                   ? vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__DataD_W
                                   : vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__Reg_inst__DOT__registers
                                  [(0x0000001fU & (vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__Instr_D 
                                                   >> 0x0000000fU))]) 
                                 & (- (IData)((0U != 
                                               (0x0000001fU 
                                                & (vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__Instr_D 
                                                   >> 0x0000000fU))))))),32);
        bufp->chgIData(oldp+39,(((((IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__RegWEn_W) 
                                   & (IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_4))
                                   ? vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__DataD_W
                                   : vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__Reg_inst__DOT__registers
                                  [(0x0000001fU & (vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__Instr_D 
                                                   >> 0x00000014U))]) 
                                 & (- (IData)((0U != 
                                               (0x0000001fU 
                                                & (vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__Instr_D 
                                                   >> 0x00000014U))))))),32);
        bufp->chgIData(oldp+40,((((IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_3) 
                                  & (IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_2))
                                  ? vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__DataD_W
                                  : ((((IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__RegWEn_W) 
                                       & (IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_3))
                                       ? vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__DataD_W
                                       : vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__Reg_inst__DOT__registers
                                      [(0x0000001fU 
                                        & (vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__Instr_D 
                                           >> 0x0000000fU))]) 
                                     & (- (IData)((0U 
                                                   != 
                                                   (0x0000001fU 
                                                    & (vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__Instr_D 
                                                       >> 0x0000000fU)))))))),32);
        bufp->chgIData(oldp+41,((((IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_4) 
                                  & (IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_2))
                                  ? vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__DataD_W
                                  : ((((IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__RegWEn_W) 
                                       & (IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_4))
                                       ? vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__DataD_W
                                       : vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__Reg_inst__DOT__registers
                                      [(0x0000001fU 
                                        & (vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__Instr_D 
                                           >> 0x00000014U))]) 
                                     & (- (IData)((0U 
                                                   != 
                                                   (0x0000001fU 
                                                    & (vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__Instr_D 
                                                       >> 0x00000014U)))))))),32);
        bufp->chgIData(oldp+42,(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__DataD_W),32);
        bufp->chgCData(oldp+43,(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__addrD_W),5);
        bufp->chgBit(oldp+44,(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__RegWEn_W));
        bufp->chgIData(oldp+45,(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__PC_E),32);
        bufp->chgIData(oldp+46,(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__PC_Plus4_E),32);
        bufp->chgIData(oldp+47,(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__DataA_E),32);
        bufp->chgIData(oldp+48,(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__DataB_E),32);
        bufp->chgIData(oldp+49,(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__Imm_E),32);
        bufp->chgCData(oldp+50,(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__addrA_E),5);
        bufp->chgCData(oldp+51,(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__addrB_E),5);
        bufp->chgCData(oldp+52,(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__addrD_E),5);
        bufp->chgCData(oldp+53,(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__funct3_E),3);
        bufp->chgCData(oldp+54,(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__ALUSel_E),4);
        bufp->chgCData(oldp+55,(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__WBSel_E),2);
        bufp->chgBit(oldp+56,(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__RegWEn_E));
        bufp->chgBit(oldp+57,(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__BrUn_E));
        bufp->chgBit(oldp+58,(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__ASel_E));
        bufp->chgBit(oldp+59,(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__BSel_E));
        bufp->chgBit(oldp+60,(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__MemRW_E));
        bufp->chgBit(oldp+61,(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__Is_Branch_E));
        bufp->chgBit(oldp+62,(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__Is_Jump_E));
        bufp->chgBit(oldp+63,(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__Is_JALR_E));
        bufp->chgBit(oldp+64,(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__Is_Load_E));
        bufp->chgCData(oldp+65,(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__addrD_M),5);
        bufp->chgBit(oldp+66,(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__RegWEn_M));
        bufp->chgCData(oldp+67,(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__fwdA),2);
        bufp->chgCData(oldp+68,(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__fwdB),2);
        bufp->chgIData(oldp+69,(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__ForwardData_M),32);
        bufp->chgIData(oldp+70,(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__fwd_DataA_E),32);
        bufp->chgIData(oldp+71,(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__fwd_DataB_E),32);
        bufp->chgIData(oldp+72,(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__Mux_ALU_DataA_E),32);
        bufp->chgIData(oldp+73,(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__Mux_ALU_DataB_E),32);
        bufp->chgIData(oldp+74,(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__ALU_out_E),32);
        bufp->chgBit(oldp+75,(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__BrEq_E));
        bufp->chgBit(oldp+76,(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__BrLT_E));
        bufp->chgIData(oldp+77,(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__ALU_out_M),32);
        bufp->chgIData(oldp+78,(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__DataB_M),32);
        bufp->chgIData(oldp+79,(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__PC_Plus4_M),32);
        bufp->chgCData(oldp+80,(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__WBSel_M),2);
        bufp->chgBit(oldp+81,(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__MemRW_M));
        bufp->chgCData(oldp+82,(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__funct3_M),3);
        bufp->chgIData(oldp+83,(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__ALU_out_W),32);
        bufp->chgIData(oldp+84,(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__DataR_W),32);
        bufp->chgIData(oldp+85,(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__PC_Plus4_W),32);
        bufp->chgCData(oldp+86,(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__WBSel_W),2);
        bufp->chgCData(oldp+87,((0x0000001fU & (vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__Instr_D 
                                                >> 2U))),5);
        bufp->chgBit(oldp+88,((1U & (vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__Instr_D 
                                     >> 0x0000001eU))));
        bufp->chgCData(oldp+89,((7U & (vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__Instr_D 
                                       >> 0x0000000cU))),3);
        bufp->chgBit(oldp+90,(Vtb_RISCV_Pipeline__ConstPool__TABLE_h2817a251_0
                              [vlSelfRef.__VdfgRegularize_h6e95ff9d_0_0]));
        bufp->chgBit(oldp+91,(Vtb_RISCV_Pipeline__ConstPool__TABLE_hc9903a88_0
                              [vlSelfRef.__VdfgRegularize_h6e95ff9d_0_0]));
        bufp->chgBit(oldp+92,(Vtb_RISCV_Pipeline__ConstPool__TABLE_hb37d2bb4_0
                              [vlSelfRef.__VdfgRegularize_h6e95ff9d_0_0]));
        bufp->chgSData(oldp+93,((0x000003ffU & ((vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__ALU_out_M 
                                                 - (IData)(0x00000400U)) 
                                                >> 2U))),10);
        bufp->chgCData(oldp+94,((0x0000001fU & (vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__Instr_D 
                                                >> 0x0000000fU))),5);
        bufp->chgCData(oldp+95,((0x0000001fU & (vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__Instr_D 
                                                >> 0x00000014U))),5);
        bufp->chgCData(oldp+96,((0x0000001fU & (vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__Instr_D 
                                                >> 7U))),5);
        Vtb_RISCV_Pipeline___024root__trace_chg_dtype____0(vlSelf, bufp, 97, vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__Reg_inst__DOT__registers);
        bufp->chgIData(oldp+129,(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__Reg_inst__DOT__i),32);
    }
    bufp->chgBit(oldp+130,(vlSelfRef.tb_RISCV_Pipeline__DOT__clk));
    bufp->chgBit(oldp+131,(vlSelfRef.tb_RISCV_Pipeline__DOT__rst_n));
    bufp->chgIData(oldp+132,(vlSelfRef.tb_RISCV_Pipeline__DOT__fd),32);
    bufp->chgBit(oldp+133,(vlSelfRef.tb_RISCV_Pipeline__DOT__loaded));
    bufp->chgIData(oldp+134,(vlSelfRef.tb_RISCV_Pipeline__DOT__cycle),32);
    bufp->chgIData(oldp+135,(vlSelfRef.tb_RISCV_Pipeline__DOT__report_result__Vstatic__canary_now),32);
    bufp->chgIData(oldp+136,(vlSelfRef.tb_RISCV_Pipeline__DOT__report_result__Vstatic__a0),32);
    bufp->chgDouble(oldp+137,(vlSelfRef.tb_RISCV_Pipeline__DOT__report_result__Vstatic__cpi));
    bufp->chgIData(oldp+139,(vlSelfRef.tb_RISCV_Pipeline__DOT__report_result__Vstatic__stack_used_bytes),32);
    bufp->chgIData(oldp+140,(vlSelfRef.tb_RISCV_Pipeline__DOT__report_result__Vstatic__flush_penalty_cycles),32);
    bufp->chgIData(oldp+141,(vlSelfRef.tb_RISCV_Pipeline__DOT__report_result__Vstatic__total_overhead_cycles),32);
    bufp->chgIData(oldp+142,(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__IMEM_inst__DOT__memory
                             [(0x000000ffU & (vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__PC_F 
                                              >> 2U))]),32);
    bufp->chgIData(oldp+143,(((4U & (IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__funct3_M))
                               ? ((- (IData)((1U & 
                                              (~ ((IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__funct3_M) 
                                                  >> 1U))))) 
                                  & ((1U & (IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__funct3_M))
                                      ? (IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__DMEM_inst__DOT__selected_half)
                                      : (IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__DMEM_inst__DOT__selected_byte)))
                               : ((2U & (IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__funct3_M))
                                   ? (vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__DMEM_inst__DOT__memory
                                      [(0x000003ffU 
                                        & ((vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__ALU_out_M 
                                            - (IData)(0x00000400U)) 
                                           >> 2U))] 
                                      & (- (IData)(
                                                   (1U 
                                                    & (~ (IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__funct3_M))))))
                                   : ((1U & (IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__funct3_M))
                                       ? (((- (IData)(
                                                      (1U 
                                                       & ((IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__DMEM_inst__DOT__selected_half) 
                                                          >> 0x0000000fU)))) 
                                           << 0x00000010U) 
                                          | (IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__DMEM_inst__DOT__selected_half))
                                       : (((- (IData)(
                                                      (1U 
                                                       & ((IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__DMEM_inst__DOT__selected_byte) 
                                                          >> 7U)))) 
                                           << 8U) | (IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__DMEM_inst__DOT__selected_byte)))))),32);
    bufp->chgIData(oldp+144,(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__DMEM_inst__DOT__memory
                             [(0x000003ffU & ((vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__ALU_out_M 
                                               - (IData)(0x00000400U)) 
                                              >> 2U))]),32);
    bufp->chgCData(oldp+145,(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__DMEM_inst__DOT__selected_byte),8);
    bufp->chgSData(oldp+146,(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__DMEM_inst__DOT__selected_half),16);
}

void Vtb_RISCV_Pipeline___024root__trace_chg_dtype____0(Vtb_RISCV_Pipeline___024root* vlSelf, VerilatedVcd::Buffer* bufp, uint32_t offset, const VlUnpacked<IData/*31:0*/, 32>& __VdtypeVar) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_RISCV_Pipeline___024root__trace_chg_dtype____0\n"); );
    Vtb_RISCV_Pipeline__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode +  offset);
    bufp->chgIData(oldp+0,(__VdtypeVar[0]),32);
    bufp->chgIData(oldp+1,(__VdtypeVar[1]),32);
    bufp->chgIData(oldp+2,(__VdtypeVar[2]),32);
    bufp->chgIData(oldp+3,(__VdtypeVar[3]),32);
    bufp->chgIData(oldp+4,(__VdtypeVar[4]),32);
    bufp->chgIData(oldp+5,(__VdtypeVar[5]),32);
    bufp->chgIData(oldp+6,(__VdtypeVar[6]),32);
    bufp->chgIData(oldp+7,(__VdtypeVar[7]),32);
    bufp->chgIData(oldp+8,(__VdtypeVar[8]),32);
    bufp->chgIData(oldp+9,(__VdtypeVar[9]),32);
    bufp->chgIData(oldp+10,(__VdtypeVar[10]),32);
    bufp->chgIData(oldp+11,(__VdtypeVar[11]),32);
    bufp->chgIData(oldp+12,(__VdtypeVar[12]),32);
    bufp->chgIData(oldp+13,(__VdtypeVar[13]),32);
    bufp->chgIData(oldp+14,(__VdtypeVar[14]),32);
    bufp->chgIData(oldp+15,(__VdtypeVar[15]),32);
    bufp->chgIData(oldp+16,(__VdtypeVar[16]),32);
    bufp->chgIData(oldp+17,(__VdtypeVar[17]),32);
    bufp->chgIData(oldp+18,(__VdtypeVar[18]),32);
    bufp->chgIData(oldp+19,(__VdtypeVar[19]),32);
    bufp->chgIData(oldp+20,(__VdtypeVar[20]),32);
    bufp->chgIData(oldp+21,(__VdtypeVar[21]),32);
    bufp->chgIData(oldp+22,(__VdtypeVar[22]),32);
    bufp->chgIData(oldp+23,(__VdtypeVar[23]),32);
    bufp->chgIData(oldp+24,(__VdtypeVar[24]),32);
    bufp->chgIData(oldp+25,(__VdtypeVar[25]),32);
    bufp->chgIData(oldp+26,(__VdtypeVar[26]),32);
    bufp->chgIData(oldp+27,(__VdtypeVar[27]),32);
    bufp->chgIData(oldp+28,(__VdtypeVar[28]),32);
    bufp->chgIData(oldp+29,(__VdtypeVar[29]),32);
    bufp->chgIData(oldp+30,(__VdtypeVar[30]),32);
    bufp->chgIData(oldp+31,(__VdtypeVar[31]),32);
}

void Vtb_RISCV_Pipeline___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_RISCV_Pipeline___024root__trace_cleanup\n"); );
    // Body
    Vtb_RISCV_Pipeline___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtb_RISCV_Pipeline___024root*>(voidSelf);
    Vtb_RISCV_Pipeline__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[2U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[3U] = 0U;
}
