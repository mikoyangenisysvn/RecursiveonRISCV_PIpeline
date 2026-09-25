// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals

#include "verilated_vcd_c.h"
#include "Vtb_RISCV_Pipeline__Syms.h"


VL_ATTR_COLD void Vtb_RISCV_Pipeline___024root__trace_init_dtype____0(Vtb_RISCV_Pipeline___024root* vlSelf, VerilatedVcd* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction);

VL_ATTR_COLD void Vtb_RISCV_Pipeline___024root__trace_init_sub__TOP__0(Vtb_RISCV_Pipeline___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_RISCV_Pipeline___024root__trace_init_sub__TOP__0\n"); );
    Vtb_RISCV_Pipeline__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const int c = vlSymsp->__Vm_baseCode;
    VL_TRACE_PUSH_PREFIX(tracep, "tb_RISCV_Pipeline", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BIT(tracep,c+130,0,"clk",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+131,0,"rst_n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+147,0,"CANARY_WORD_IDX",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+148,0,"CANARY_VALUE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+149,0,"STACK_TOP_BYTE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+132,0,"fd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+133,0,"loaded",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+134,0,"cycle",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+0,0,"instr_count",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+1,0,"stall_count",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+2,0,"flush_count",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+3,0,"pipeline_filled",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+4,0,"PCSel_E_d1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+5,0,"min_sp",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+6,0,"min_sp_cycle",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+7,0,"sp_initialized",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+8,0,"done_reported",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+9,0,"done_cycle",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+135,0,"report_result__Vstatic__canary_now",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+136,0,"report_result__Vstatic__a0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_DOUBLE(tracep,c+137,0,"report_result__Vstatic__cpi",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::DOUBLE);
    VL_TRACE_DECL_BUS(tracep,c+139,0,"report_result__Vstatic__stack_used_bytes",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+140,0,"report_result__Vstatic__flush_penalty_cycles",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+141,0,"report_result__Vstatic__total_overhead_cycles",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, 31,0);
    VL_TRACE_PUSH_PREFIX(tracep, "dut", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BIT(tracep,c+130,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+131,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+10,0,"stall_load",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+11,0,"PCSel_E",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+12,0,"pc_write_en",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+13,0,"stall_if_id",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+11,0,"flush_if_id",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+14,0,"bubble_id_ex",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+15,0,"PC_F",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+16,0,"PC_next_F",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+17,0,"PC_Plus4_F",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+142,0,"Instr_F",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+18,0,"Addr_instr_mem",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+19,0,"PC_target_E",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+20,0,"PC_D",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+21,0,"PC_Plus4_D",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+22,0,"Instr_D",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+23,0,"ImmSel_D",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BIT(tracep,c+24,0,"RegWEn_D",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+25,0,"BrUn_D",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+26,0,"ASel_D",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+27,0,"BSel_D",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+28,0,"MemRW_D",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+29,0,"WBSel_D",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BUS(tracep,c+30,0,"ALUSel_D",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BIT(tracep,c+31,0,"UsesRs1_D",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+32,0,"UsesRs2_D",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+33,0,"Is_Branch_D",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+34,0,"Is_Jump_D",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+35,0,"Is_JALR_D",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+36,0,"Is_Load_D",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+37,0,"Imm_D",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+38,0,"rf_DataA_D",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+39,0,"rf_DataB_D",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+40,0,"DataA_D",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+41,0,"DataB_D",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+42,0,"DataD_W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+43,0,"addrD_W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BIT(tracep,c+44,0,"RegWEn_W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+45,0,"PC_E",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+46,0,"PC_Plus4_E",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+47,0,"DataA_E",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+48,0,"DataB_E",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+49,0,"Imm_E",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+50,0,"addrA_E",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BUS(tracep,c+51,0,"addrB_E",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BUS(tracep,c+52,0,"addrD_E",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BUS(tracep,c+53,0,"funct3_E",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BUS(tracep,c+54,0,"ALUSel_E",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+55,0,"WBSel_E",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BIT(tracep,c+56,0,"RegWEn_E",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+57,0,"BrUn_E",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+58,0,"ASel_E",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+59,0,"BSel_E",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+60,0,"MemRW_E",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+61,0,"Is_Branch_E",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+62,0,"Is_Jump_E",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+63,0,"Is_JALR_E",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+64,0,"Is_Load_E",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+65,0,"addrD_M",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BIT(tracep,c+66,0,"RegWEn_M",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+67,0,"fwdA",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BUS(tracep,c+68,0,"fwdB",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BUS(tracep,c+69,0,"ForwardData_M",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+70,0,"fwd_DataA_E",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+71,0,"fwd_DataB_E",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+72,0,"Mux_ALU_DataA_E",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+73,0,"Mux_ALU_DataB_E",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+74,0,"ALU_out_E",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+75,0,"BrEq_E",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+76,0,"BrLT_E",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+77,0,"ALU_out_M",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+78,0,"DataB_M",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+79,0,"PC_Plus4_M",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+80,0,"WBSel_M",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BIT(tracep,c+81,0,"MemRW_M",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+82,0,"funct3_M",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BUS(tracep,c+143,0,"DataR_M",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+83,0,"ALU_out_W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+84,0,"DataR_W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+85,0,"PC_Plus4_W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+86,0,"WBSel_W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_PUSH_PREFIX(tracep, "ALU_mod_inst", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+54,0,"ALU_Sel",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+72,0,"operand_0",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+73,0,"operand_1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+74,0,"result",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+150,0,"ADD",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+151,0,"SUB",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+152,0,"AND_OP",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+153,0,"OR_OP",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+154,0,"XOR_OP",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+155,0,"SLL_OP",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+156,0,"SRL_OP",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+157,0,"SRA_OP",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+158,0,"SLT_OP",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+159,0,"SLTU_OP",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+160,0,"PASS_B",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "BranchResolve_inst", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BIT(tracep,c+61,0,"Is_Branch_E",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+62,0,"Is_Jump_E",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+53,0,"funct3_E",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BIT(tracep,c+75,0,"BrEq_E",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+76,0,"BrLt_E",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+11,0,"PCSel_E",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "Branch_Comp_inst", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+70,0,"operand_0",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+71,0,"operand_1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+57,0,"BrUn",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+75,0,"BrEq",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+76,0,"BrLT",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "Control_logic_inst", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+87,0,"opcode_eff",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BIT(tracep,c+88,0,"funct7_fif",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+89,0,"funct3",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BUS(tracep,c+23,0,"ImmSel",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BIT(tracep,c+24,0,"RegWEn",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+25,0,"BrUn",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+26,0,"ASel",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+27,0,"BSel",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+30,0,"ALUSel",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BIT(tracep,c+28,0,"MemRW",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+29,0,"WBSel",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BIT(tracep,c+31,0,"UsesRs1",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+32,0,"UsesRs2",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+33,0,"Is_Branch",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+34,0,"Is_Jump",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+35,0,"Is_JALR",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+36,0,"Is_Load",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+90,0,"arithmetic",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+91,0,"i_type",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+92,0,"pass_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_PUSH_PREFIX(tracep, "ALU_decoder_inst", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BIT(tracep,c+90,0,"arithmetic",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+92,0,"pass_b",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+89,0,"funct3",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BIT(tracep,c+88,0,"funct7_fif",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+91,0,"i_type",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+30,0,"ALUSel",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+150,0,"ADD",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+151,0,"SUB",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+152,0,"AND_OP",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+153,0,"OR_OP",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+154,0,"XOR_OP",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+155,0,"SLL_OP",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+156,0,"SRL_OP",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+157,0,"SRA_OP",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+158,0,"SLT_OP",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+159,0,"SLTU_OP",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+160,0,"PASS_B",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "main_decoder_inst", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+87,0,"opcode_eff",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BUS(tracep,c+89,0,"funct3",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BUS(tracep,c+23,0,"ImmSel",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BIT(tracep,c+24,0,"RegWEn",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+25,0,"BrUn",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+26,0,"ASel",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+27,0,"BSel",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+28,0,"MemRW",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+29,0,"WBSel",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BIT(tracep,c+90,0,"arithmetic",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+91,0,"i_type",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+92,0,"pass_b",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+31,0,"UsesRs1",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+32,0,"UsesRs2",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+33,0,"Is_Branch",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+34,0,"Is_Jump",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+35,0,"Is_JALR",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+36,0,"Is_Load",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+161,0,"OP_LOAD",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BUS(tracep,c+162,0,"OP_IMM",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BUS(tracep,c+163,0,"OP_AUIPC",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BUS(tracep,c+164,0,"OP_STORE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BUS(tracep,c+165,0,"OP_REG",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BUS(tracep,c+166,0,"OP_LUI",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BUS(tracep,c+167,0,"OP_BRANCH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BUS(tracep,c+168,0,"OP_JALR",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BUS(tracep,c+169,0,"OP_JAL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BUS(tracep,c+170,0,"IMM_I",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BUS(tracep,c+171,0,"IMM_S",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BUS(tracep,c+172,0,"IMM_B",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BUS(tracep,c+173,0,"IMM_U",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BUS(tracep,c+174,0,"IMM_J",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BUS(tracep,c+175,0,"WB_MEM",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BUS(tracep,c+176,0,"WB_ALU",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BUS(tracep,c+177,0,"WB_PC4",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "DMEM_inst", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BIT(tracep,c+130,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+81,0,"MemRW",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+77,0,"addr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+78,0,"DataW",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+82,0,"funct3",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BUS(tracep,c+143,0,"DataR",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+93,0,"ram_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 9,0);
    VL_TRACE_DECL_BUS(tracep,c+144,0,"word",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+145,0,"selected_byte",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+146,0,"selected_half",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 15,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "EX_MEM_inst", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BIT(tracep,c+130,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+131,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+74,0,"ALU_out_E",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+71,0,"DataB_fwd_E",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+46,0,"PC_Plus4_E",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+52,0,"addrD_E",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BUS(tracep,c+55,0,"WBSel_E",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BIT(tracep,c+56,0,"RegWEn_E",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+60,0,"MemRW_E",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+53,0,"funct3_E",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BUS(tracep,c+77,0,"ALU_out_M",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+78,0,"DataB_M",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+79,0,"PC_Plus4_M",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+65,0,"addrD_M",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BUS(tracep,c+80,0,"WBSel_M",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BIT(tracep,c+66,0,"RegWEn_M",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+81,0,"MemRW_M",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+82,0,"funct3_M",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "Forward_inst", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+50,0,"addrA_E",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BUS(tracep,c+51,0,"addrB_E",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BUS(tracep,c+65,0,"addrD_M",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BUS(tracep,c+43,0,"addrD_W",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BIT(tracep,c+66,0,"RegWEn_M",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+44,0,"RegWEn_W",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+67,0,"fwdA",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BUS(tracep,c+68,0,"fwdB",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "Hazard_inst", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BIT(tracep,c+64,0,"Is_Load_E",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+52,0,"addrD_E",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BUS(tracep,c+94,0,"addrA_D",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BUS(tracep,c+95,0,"addrB_D",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BIT(tracep,c+31,0,"UsesRs1_D",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+32,0,"UsesRs2_D",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+10,0,"stall_load",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "ID_EX_inst", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BIT(tracep,c+130,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+131,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+14,0,"bubble",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+20,0,"PC_D",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+21,0,"PC_Plus4_D",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+40,0,"DataA_D",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+41,0,"DataB_D",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+37,0,"Imm_D",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+94,0,"addrA_D",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BUS(tracep,c+95,0,"addrB_D",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BUS(tracep,c+96,0,"addrD_D",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BUS(tracep,c+89,0,"funct3_D",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BUS(tracep,c+30,0,"ALUSel_D",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+29,0,"WBSel_D",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BIT(tracep,c+24,0,"RegWEn_D",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+25,0,"BrUn_D",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+26,0,"ASel_D",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+27,0,"BSel_D",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+28,0,"MemRW_D",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+33,0,"Is_Branch_D",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+34,0,"Is_Jump_D",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+35,0,"Is_JALR_D",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+36,0,"Is_Load_D",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+45,0,"PC_E",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+46,0,"PC_Plus4_E",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+47,0,"DataA_E",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+48,0,"DataB_E",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+49,0,"Imm_E",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+50,0,"addrA_E",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BUS(tracep,c+51,0,"addrB_E",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BUS(tracep,c+52,0,"addrD_E",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BUS(tracep,c+53,0,"funct3_E",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BUS(tracep,c+54,0,"ALUSel_E",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+55,0,"WBSel_E",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BIT(tracep,c+56,0,"RegWEn_E",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+57,0,"BrUn_E",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+58,0,"ASel_E",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+59,0,"BSel_E",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+60,0,"MemRW_E",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+61,0,"Is_Branch_E",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+62,0,"Is_Jump_E",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+63,0,"Is_JALR_E",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+64,0,"Is_Load_E",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "IF_ID_inst", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BIT(tracep,c+130,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+131,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+13,0,"stall",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+11,0,"flush",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+15,0,"PC_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+17,0,"PC_Plus4_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+142,0,"Instr_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+20,0,"PC_D",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+21,0,"PC_Plus4_D",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+22,0,"Instr_D",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "IMEM_inst", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+18,0,"addr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+142,0,"inst",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "Imm_Gen_inst", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+22,0,"Inst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+23,0,"ImmSel",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BUS(tracep,c+37,0,"Imm",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+170,0,"IMM_I",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BUS(tracep,c+171,0,"IMM_S",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BUS(tracep,c+172,0,"IMM_B",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BUS(tracep,c+173,0,"IMM_U",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BUS(tracep,c+174,0,"IMM_J",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "MEM_WB_inst", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BIT(tracep,c+130,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+131,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+77,0,"ALU_out_M",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+143,0,"DataR_M",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+79,0,"PC_Plus4_M",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+65,0,"addrD_M",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BUS(tracep,c+80,0,"WBSel_M",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BIT(tracep,c+66,0,"RegWEn_M",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+83,0,"ALU_out_W",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+84,0,"DataR_W",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+85,0,"PC_Plus4_W",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+43,0,"addrD_W",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BUS(tracep,c+86,0,"WBSel_W",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BIT(tracep,c+44,0,"RegWEn_W",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "PC_inst", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BIT(tracep,c+130,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+131,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+12,0,"pc_write",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+16,0,"PC_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+15,0,"PC_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "Reg_inst", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BIT(tracep,c+130,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+131,0,"reset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+94,0,"addrA",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BUS(tracep,c+95,0,"addrB",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BUS(tracep,c+43,0,"addrD",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BUS(tracep,c+42,0,"dataD",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+44,0,"reg_write",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+38,0,"dataA",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+39,0,"dataB",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);

    Vtb_RISCV_Pipeline___024root__trace_init_dtype____0(vlSelf, tracep, "registers", 0, c+97, VerilatedTraceSigDirection::NONE);
    VL_TRACE_DECL_BUS(tracep,c+129,0,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, 31,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
}

VL_ATTR_COLD void Vtb_RISCV_Pipeline___024root__trace_init_dtype_sub____0(Vtb_RISCV_Pipeline___024root* vlSelf, VerilatedVcd* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction);

VL_ATTR_COLD void Vtb_RISCV_Pipeline___024root__trace_init_dtype____0(Vtb_RISCV_Pipeline___024root* vlSelf, VerilatedVcd* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_RISCV_Pipeline___024root__trace_init_dtype____0\n"); );
    Vtb_RISCV_Pipeline__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vtb_RISCV_Pipeline___024root__trace_init_dtype_sub____0(vlSelf, tracep, name, fidx, c, direction);
}

VL_ATTR_COLD void Vtb_RISCV_Pipeline___024root__trace_init_dtype_sub____0(Vtb_RISCV_Pipeline___024root* vlSelf, VerilatedVcd* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_RISCV_Pipeline___024root__trace_init_dtype_sub____0\n"); );
    Vtb_RISCV_Pipeline__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    VL_TRACE_PUSH_PREFIX(tracep, name, VerilatedTracePrefixType::ARRAY_UNPACKED, 0, 31);
    for (int i = 0; i < 32; ++i) {
        VL_TRACE_DECL_BUS_ARRAY(tracep,c+0+i*1,fidx,"",-1, direction, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, (i + 0), 31,0);
    }
    VL_TRACE_POP_PREFIX(tracep);
}

VL_ATTR_COLD void Vtb_RISCV_Pipeline___024root__trace_init_top(Vtb_RISCV_Pipeline___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_RISCV_Pipeline___024root__trace_init_top\n"); );
    Vtb_RISCV_Pipeline__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vtb_RISCV_Pipeline___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vtb_RISCV_Pipeline___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
VL_ATTR_COLD void Vtb_RISCV_Pipeline___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vtb_RISCV_Pipeline___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vtb_RISCV_Pipeline___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void Vtb_RISCV_Pipeline___024root__trace_register(Vtb_RISCV_Pipeline___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_RISCV_Pipeline___024root__trace_register\n"); );
    Vtb_RISCV_Pipeline__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    tracep->addConstCb(&Vtb_RISCV_Pipeline___024root__trace_const_0, 0, vlSelf);
    tracep->addFullCb(&Vtb_RISCV_Pipeline___024root__trace_full_0, 0, vlSelf);
    tracep->addChgCb(&Vtb_RISCV_Pipeline___024root__trace_chg_0, 0, vlSelf);
    tracep->addCleanupCb(&Vtb_RISCV_Pipeline___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vtb_RISCV_Pipeline___024root__trace_const_0_sub_0(Vtb_RISCV_Pipeline___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vtb_RISCV_Pipeline___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_RISCV_Pipeline___024root__trace_const_0\n"); );
    // Body
    Vtb_RISCV_Pipeline___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtb_RISCV_Pipeline___024root*>(voidSelf);
    Vtb_RISCV_Pipeline__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    Vtb_RISCV_Pipeline___024root__trace_const_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vtb_RISCV_Pipeline___024root__trace_const_0_sub_0(Vtb_RISCV_Pipeline___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_RISCV_Pipeline___024root__trace_const_0_sub_0\n"); );
    Vtb_RISCV_Pipeline__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    bufp->fullIData(oldp+147,(0U),32);
    bufp->fullIData(oldp+148,(0xdeadbeefU),32);
    bufp->fullIData(oldp+149,(0x00001400U),32);
    bufp->fullCData(oldp+150,(0U),4);
    bufp->fullCData(oldp+151,(1U),4);
    bufp->fullCData(oldp+152,(2U),4);
    bufp->fullCData(oldp+153,(3U),4);
    bufp->fullCData(oldp+154,(4U),4);
    bufp->fullCData(oldp+155,(5U),4);
    bufp->fullCData(oldp+156,(6U),4);
    bufp->fullCData(oldp+157,(7U),4);
    bufp->fullCData(oldp+158,(8U),4);
    bufp->fullCData(oldp+159,(9U),4);
    bufp->fullCData(oldp+160,(0x0aU),4);
    bufp->fullCData(oldp+161,(0U),5);
    bufp->fullCData(oldp+162,(4U),5);
    bufp->fullCData(oldp+163,(5U),5);
    bufp->fullCData(oldp+164,(8U),5);
    bufp->fullCData(oldp+165,(0x0cU),5);
    bufp->fullCData(oldp+166,(0x0dU),5);
    bufp->fullCData(oldp+167,(0x18U),5);
    bufp->fullCData(oldp+168,(0x19U),5);
    bufp->fullCData(oldp+169,(0x1bU),5);
    bufp->fullCData(oldp+170,(0U),3);
    bufp->fullCData(oldp+171,(1U),3);
    bufp->fullCData(oldp+172,(2U),3);
    bufp->fullCData(oldp+173,(3U),3);
    bufp->fullCData(oldp+174,(4U),3);
    bufp->fullCData(oldp+175,(0U),2);
    bufp->fullCData(oldp+176,(1U),2);
    bufp->fullCData(oldp+177,(2U),2);
}

VL_ATTR_COLD void Vtb_RISCV_Pipeline___024root__trace_full_0_sub_0(Vtb_RISCV_Pipeline___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vtb_RISCV_Pipeline___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_RISCV_Pipeline___024root__trace_full_0\n"); );
    // Body
    Vtb_RISCV_Pipeline___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtb_RISCV_Pipeline___024root*>(voidSelf);
    Vtb_RISCV_Pipeline__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    Vtb_RISCV_Pipeline___024root__trace_full_0_sub_0((&vlSymsp->TOP), bufp);
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
VL_ATTR_COLD void Vtb_RISCV_Pipeline___024root__trace_full_dtype____0(Vtb_RISCV_Pipeline___024root* vlSelf, VerilatedVcd::Buffer* bufp, uint32_t offset, const VlUnpacked<IData/*31:0*/, 32>& __VdtypeVar);

VL_ATTR_COLD void Vtb_RISCV_Pipeline___024root__trace_full_0_sub_0(Vtb_RISCV_Pipeline___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_RISCV_Pipeline___024root__trace_full_0_sub_0\n"); );
    Vtb_RISCV_Pipeline__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    bufp->fullIData(oldp+0,(vlSelfRef.tb_RISCV_Pipeline__DOT__instr_count),32);
    bufp->fullIData(oldp+1,(vlSelfRef.tb_RISCV_Pipeline__DOT__stall_count),32);
    bufp->fullIData(oldp+2,(vlSelfRef.tb_RISCV_Pipeline__DOT__flush_count),32);
    bufp->fullBit(oldp+3,(vlSelfRef.tb_RISCV_Pipeline__DOT__pipeline_filled));
    bufp->fullBit(oldp+4,(vlSelfRef.tb_RISCV_Pipeline__DOT__PCSel_E_d1));
    bufp->fullIData(oldp+5,(vlSelfRef.tb_RISCV_Pipeline__DOT__min_sp),32);
    bufp->fullIData(oldp+6,(vlSelfRef.tb_RISCV_Pipeline__DOT__min_sp_cycle),32);
    bufp->fullBit(oldp+7,(vlSelfRef.tb_RISCV_Pipeline__DOT__sp_initialized));
    bufp->fullBit(oldp+8,(vlSelfRef.tb_RISCV_Pipeline__DOT__done_reported));
    bufp->fullIData(oldp+9,(vlSelfRef.tb_RISCV_Pipeline__DOT__done_cycle),32);
    bufp->fullBit(oldp+10,(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__stall_load));
    bufp->fullBit(oldp+11,(Vtb_RISCV_Pipeline__ConstPool__TABLE_h3cb0ade6_0
                           [((((IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__BrEq_E) 
                               << 6U) | ((IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__BrLT_E) 
                                         << 5U)) | 
                             (((IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__funct3_E) 
                               << 2U) | (((IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__Is_Branch_E) 
                                          << 1U) | (IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__Is_Jump_E))))]));
    bufp->fullBit(oldp+12,((1U & ((~ (IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__stall_load)) 
                                  | Vtb_RISCV_Pipeline__ConstPool__TABLE_h3cb0ade6_0
                                  [((((IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__BrEq_E) 
                                      << 6U) | ((IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__BrLT_E) 
                                                << 5U)) 
                                    | (((IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__funct3_E) 
                                        << 2U) | (((IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__Is_Branch_E) 
                                                   << 1U) 
                                                  | (IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__Is_Jump_E))))]))));
    bufp->fullBit(oldp+13,(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__stall_if_id));
    bufp->fullBit(oldp+14,(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__bubble_id_ex));
    bufp->fullIData(oldp+15,(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__PC_F),32);
    bufp->fullIData(oldp+16,((Vtb_RISCV_Pipeline__ConstPool__TABLE_h3cb0ade6_0
                              [((((IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__BrEq_E) 
                                  << 6U) | ((IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__BrLT_E) 
                                            << 5U)) 
                                | (((IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__funct3_E) 
                                    << 2U) | (((IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__Is_Branch_E) 
                                               << 1U) 
                                              | (IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__Is_Jump_E))))]
                               ? vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__PC_target_E
                               : ((IData)(4U) + vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__PC_F))),32);
    bufp->fullIData(oldp+17,(((IData)(4U) + vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__PC_F)),32);
    bufp->fullIData(oldp+18,((vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__PC_F 
                              >> 2U)),32);
    bufp->fullIData(oldp+19,(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__PC_target_E),32);
    bufp->fullIData(oldp+20,(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__PC_D),32);
    bufp->fullIData(oldp+21,(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__PC_Plus4_D),32);
    bufp->fullIData(oldp+22,(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__Instr_D),32);
    bufp->fullCData(oldp+23,(Vtb_RISCV_Pipeline__ConstPool__TABLE_h6a3b8cf2_0
                             [vlSelfRef.__VdfgRegularize_h6e95ff9d_0_0]),3);
    bufp->fullBit(oldp+24,(Vtb_RISCV_Pipeline__ConstPool__TABLE_hd82a1090_0
                           [vlSelfRef.__VdfgRegularize_h6e95ff9d_0_0]));
    bufp->fullBit(oldp+25,(Vtb_RISCV_Pipeline__ConstPool__TABLE_hadc3105f_0
                           [vlSelfRef.__VdfgRegularize_h6e95ff9d_0_0]));
    bufp->fullBit(oldp+26,(Vtb_RISCV_Pipeline__ConstPool__TABLE_h5ac4bd78_0
                           [vlSelfRef.__VdfgRegularize_h6e95ff9d_0_0]));
    bufp->fullBit(oldp+27,(Vtb_RISCV_Pipeline__ConstPool__TABLE_h70db338c_0
                           [vlSelfRef.__VdfgRegularize_h6e95ff9d_0_0]));
    bufp->fullBit(oldp+28,(Vtb_RISCV_Pipeline__ConstPool__TABLE_h2471d231_0
                           [vlSelfRef.__VdfgRegularize_h6e95ff9d_0_0]));
    bufp->fullCData(oldp+29,(Vtb_RISCV_Pipeline__ConstPool__TABLE_h7320afc7_0
                             [vlSelfRef.__VdfgRegularize_h6e95ff9d_0_0]),2);
    bufp->fullCData(oldp+30,(Vtb_RISCV_Pipeline__ConstPool__TABLE_h4d17e3b4_0
                             [(((((IData)(Vtb_RISCV_Pipeline__ConstPool__TABLE_hc9903a88_0
                                          [vlSelfRef.__VdfgRegularize_h6e95ff9d_0_0]) 
                                  << 1U) << 5U) | (0x00000020U 
                                                   & (vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__Instr_D 
                                                      >> 0x00000019U))) 
                               | ((0x0000001cU & (vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__Instr_D 
                                                  >> 0x0000000aU)) 
                                  | (((IData)(Vtb_RISCV_Pipeline__ConstPool__TABLE_h2817a251_0
                                              [vlSelfRef.__VdfgRegularize_h6e95ff9d_0_0]) 
                                      << 1U) | Vtb_RISCV_Pipeline__ConstPool__TABLE_hb37d2bb4_0
                                     [vlSelfRef.__VdfgRegularize_h6e95ff9d_0_0])))]),4);
    bufp->fullBit(oldp+31,(Vtb_RISCV_Pipeline__ConstPool__TABLE_h41ca9fcd_0
                           [vlSelfRef.__VdfgRegularize_h6e95ff9d_0_0]));
    bufp->fullBit(oldp+32,(Vtb_RISCV_Pipeline__ConstPool__TABLE_h35a60bd7_0
                           [vlSelfRef.__VdfgRegularize_h6e95ff9d_0_0]));
    bufp->fullBit(oldp+33,(Vtb_RISCV_Pipeline__ConstPool__TABLE_h020b1e42_0
                           [vlSelfRef.__VdfgRegularize_h6e95ff9d_0_0]));
    bufp->fullBit(oldp+34,(Vtb_RISCV_Pipeline__ConstPool__TABLE_h0ae2a928_0
                           [vlSelfRef.__VdfgRegularize_h6e95ff9d_0_0]));
    bufp->fullBit(oldp+35,(Vtb_RISCV_Pipeline__ConstPool__TABLE_h77ea30c7_0
                           [vlSelfRef.__VdfgRegularize_h6e95ff9d_0_0]));
    bufp->fullBit(oldp+36,(Vtb_RISCV_Pipeline__ConstPool__TABLE_hb03ac117_0
                           [vlSelfRef.__VdfgRegularize_h6e95ff9d_0_0]));
    bufp->fullIData(oldp+37,(((4U & Vtb_RISCV_Pipeline__ConstPool__TABLE_h6a3b8cf2_0
                               [vlSelfRef.__VdfgRegularize_h6e95ff9d_0_0])
                               ? ((- (IData)((1U & 
                                              (~ (IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_1))))) 
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
                                           | (1U & 
                                              (vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__Instr_D 
                                               >> 0x00000014U))) 
                                          << 0x0000000bU) 
                                         | (0x000007feU 
                                            & (vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__Instr_D 
                                               >> 0x00000014U)))) 
                                     & (- (IData)((1U 
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
                                      << 1U) : (((- (IData)(
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
    bufp->fullIData(oldp+38,(((((IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__RegWEn_W) 
                                & (IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_3))
                                ? vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__DataD_W
                                : vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__Reg_inst__DOT__registers
                               [(0x0000001fU & (vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__Instr_D 
                                                >> 0x0000000fU))]) 
                              & (- (IData)((0U != (0x0000001fU 
                                                   & (vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__Instr_D 
                                                      >> 0x0000000fU))))))),32);
    bufp->fullIData(oldp+39,(((((IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__RegWEn_W) 
                                & (IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_4))
                                ? vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__DataD_W
                                : vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__Reg_inst__DOT__registers
                               [(0x0000001fU & (vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__Instr_D 
                                                >> 0x00000014U))]) 
                              & (- (IData)((0U != (0x0000001fU 
                                                   & (vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__Instr_D 
                                                      >> 0x00000014U))))))),32);
    bufp->fullIData(oldp+40,((((IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_3) 
                               & (IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_2))
                               ? vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__DataD_W
                               : ((((IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__RegWEn_W) 
                                    & (IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_3))
                                    ? vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__DataD_W
                                    : vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__Reg_inst__DOT__registers
                                   [(0x0000001fU & 
                                     (vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__Instr_D 
                                      >> 0x0000000fU))]) 
                                  & (- (IData)((0U 
                                                != 
                                                (0x0000001fU 
                                                 & (vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__Instr_D 
                                                    >> 0x0000000fU)))))))),32);
    bufp->fullIData(oldp+41,((((IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_4) 
                               & (IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_2))
                               ? vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__DataD_W
                               : ((((IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__RegWEn_W) 
                                    & (IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_4))
                                    ? vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__DataD_W
                                    : vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__Reg_inst__DOT__registers
                                   [(0x0000001fU & 
                                     (vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__Instr_D 
                                      >> 0x00000014U))]) 
                                  & (- (IData)((0U 
                                                != 
                                                (0x0000001fU 
                                                 & (vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__Instr_D 
                                                    >> 0x00000014U)))))))),32);
    bufp->fullIData(oldp+42,(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__DataD_W),32);
    bufp->fullCData(oldp+43,(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__addrD_W),5);
    bufp->fullBit(oldp+44,(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__RegWEn_W));
    bufp->fullIData(oldp+45,(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__PC_E),32);
    bufp->fullIData(oldp+46,(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__PC_Plus4_E),32);
    bufp->fullIData(oldp+47,(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__DataA_E),32);
    bufp->fullIData(oldp+48,(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__DataB_E),32);
    bufp->fullIData(oldp+49,(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__Imm_E),32);
    bufp->fullCData(oldp+50,(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__addrA_E),5);
    bufp->fullCData(oldp+51,(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__addrB_E),5);
    bufp->fullCData(oldp+52,(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__addrD_E),5);
    bufp->fullCData(oldp+53,(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__funct3_E),3);
    bufp->fullCData(oldp+54,(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__ALUSel_E),4);
    bufp->fullCData(oldp+55,(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__WBSel_E),2);
    bufp->fullBit(oldp+56,(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__RegWEn_E));
    bufp->fullBit(oldp+57,(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__BrUn_E));
    bufp->fullBit(oldp+58,(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__ASel_E));
    bufp->fullBit(oldp+59,(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__BSel_E));
    bufp->fullBit(oldp+60,(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__MemRW_E));
    bufp->fullBit(oldp+61,(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__Is_Branch_E));
    bufp->fullBit(oldp+62,(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__Is_Jump_E));
    bufp->fullBit(oldp+63,(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__Is_JALR_E));
    bufp->fullBit(oldp+64,(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__Is_Load_E));
    bufp->fullCData(oldp+65,(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__addrD_M),5);
    bufp->fullBit(oldp+66,(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__RegWEn_M));
    bufp->fullCData(oldp+67,(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__fwdA),2);
    bufp->fullCData(oldp+68,(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__fwdB),2);
    bufp->fullIData(oldp+69,(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__ForwardData_M),32);
    bufp->fullIData(oldp+70,(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__fwd_DataA_E),32);
    bufp->fullIData(oldp+71,(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__fwd_DataB_E),32);
    bufp->fullIData(oldp+72,(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__Mux_ALU_DataA_E),32);
    bufp->fullIData(oldp+73,(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__Mux_ALU_DataB_E),32);
    bufp->fullIData(oldp+74,(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__ALU_out_E),32);
    bufp->fullBit(oldp+75,(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__BrEq_E));
    bufp->fullBit(oldp+76,(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__BrLT_E));
    bufp->fullIData(oldp+77,(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__ALU_out_M),32);
    bufp->fullIData(oldp+78,(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__DataB_M),32);
    bufp->fullIData(oldp+79,(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__PC_Plus4_M),32);
    bufp->fullCData(oldp+80,(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__WBSel_M),2);
    bufp->fullBit(oldp+81,(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__MemRW_M));
    bufp->fullCData(oldp+82,(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__funct3_M),3);
    bufp->fullIData(oldp+83,(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__ALU_out_W),32);
    bufp->fullIData(oldp+84,(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__DataR_W),32);
    bufp->fullIData(oldp+85,(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__PC_Plus4_W),32);
    bufp->fullCData(oldp+86,(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__WBSel_W),2);
    bufp->fullCData(oldp+87,((0x0000001fU & (vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__Instr_D 
                                             >> 2U))),5);
    bufp->fullBit(oldp+88,((1U & (vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__Instr_D 
                                  >> 0x0000001eU))));
    bufp->fullCData(oldp+89,((7U & (vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__Instr_D 
                                    >> 0x0000000cU))),3);
    bufp->fullBit(oldp+90,(Vtb_RISCV_Pipeline__ConstPool__TABLE_h2817a251_0
                           [vlSelfRef.__VdfgRegularize_h6e95ff9d_0_0]));
    bufp->fullBit(oldp+91,(Vtb_RISCV_Pipeline__ConstPool__TABLE_hc9903a88_0
                           [vlSelfRef.__VdfgRegularize_h6e95ff9d_0_0]));
    bufp->fullBit(oldp+92,(Vtb_RISCV_Pipeline__ConstPool__TABLE_hb37d2bb4_0
                           [vlSelfRef.__VdfgRegularize_h6e95ff9d_0_0]));
    bufp->fullSData(oldp+93,((0x000003ffU & ((vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__ALU_out_M 
                                              - (IData)(0x00000400U)) 
                                             >> 2U))),10);
    bufp->fullCData(oldp+94,((0x0000001fU & (vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__Instr_D 
                                             >> 0x0000000fU))),5);
    bufp->fullCData(oldp+95,((0x0000001fU & (vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__Instr_D 
                                             >> 0x00000014U))),5);
    bufp->fullCData(oldp+96,((0x0000001fU & (vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__Instr_D 
                                             >> 7U))),5);
    Vtb_RISCV_Pipeline___024root__trace_full_dtype____0(vlSelf, bufp, 97, vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__Reg_inst__DOT__registers);
    bufp->fullIData(oldp+129,(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__Reg_inst__DOT__i),32);
    bufp->fullBit(oldp+130,(vlSelfRef.tb_RISCV_Pipeline__DOT__clk));
    bufp->fullBit(oldp+131,(vlSelfRef.tb_RISCV_Pipeline__DOT__rst_n));
    bufp->fullIData(oldp+132,(vlSelfRef.tb_RISCV_Pipeline__DOT__fd),32);
    bufp->fullBit(oldp+133,(vlSelfRef.tb_RISCV_Pipeline__DOT__loaded));
    bufp->fullIData(oldp+134,(vlSelfRef.tb_RISCV_Pipeline__DOT__cycle),32);
    bufp->fullIData(oldp+135,(vlSelfRef.tb_RISCV_Pipeline__DOT__report_result__Vstatic__canary_now),32);
    bufp->fullIData(oldp+136,(vlSelfRef.tb_RISCV_Pipeline__DOT__report_result__Vstatic__a0),32);
    bufp->fullDouble(oldp+137,(vlSelfRef.tb_RISCV_Pipeline__DOT__report_result__Vstatic__cpi));
    bufp->fullIData(oldp+139,(vlSelfRef.tb_RISCV_Pipeline__DOT__report_result__Vstatic__stack_used_bytes),32);
    bufp->fullIData(oldp+140,(vlSelfRef.tb_RISCV_Pipeline__DOT__report_result__Vstatic__flush_penalty_cycles),32);
    bufp->fullIData(oldp+141,(vlSelfRef.tb_RISCV_Pipeline__DOT__report_result__Vstatic__total_overhead_cycles),32);
    bufp->fullIData(oldp+142,(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__IMEM_inst__DOT__memory
                              [(0x000000ffU & (vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__PC_F 
                                               >> 2U))]),32);
    bufp->fullIData(oldp+143,(((4U & (IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__funct3_M))
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
                                            << 8U) 
                                           | (IData)(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__DMEM_inst__DOT__selected_byte)))))),32);
    bufp->fullIData(oldp+144,(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__DMEM_inst__DOT__memory
                              [(0x000003ffU & ((vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__ALU_out_M 
                                                - (IData)(0x00000400U)) 
                                               >> 2U))]),32);
    bufp->fullCData(oldp+145,(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__DMEM_inst__DOT__selected_byte),8);
    bufp->fullSData(oldp+146,(vlSelfRef.tb_RISCV_Pipeline__DOT__dut__DOT__DMEM_inst__DOT__selected_half),16);
}

VL_ATTR_COLD void Vtb_RISCV_Pipeline___024root__trace_full_dtype____0(Vtb_RISCV_Pipeline___024root* vlSelf, VerilatedVcd::Buffer* bufp, uint32_t offset, const VlUnpacked<IData/*31:0*/, 32>& __VdtypeVar) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_RISCV_Pipeline___024root__trace_full_dtype____0\n"); );
    Vtb_RISCV_Pipeline__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + offset);
    bufp->fullIData(oldp+0,(__VdtypeVar[0]),32);
    bufp->fullIData(oldp+1,(__VdtypeVar[1]),32);
    bufp->fullIData(oldp+2,(__VdtypeVar[2]),32);
    bufp->fullIData(oldp+3,(__VdtypeVar[3]),32);
    bufp->fullIData(oldp+4,(__VdtypeVar[4]),32);
    bufp->fullIData(oldp+5,(__VdtypeVar[5]),32);
    bufp->fullIData(oldp+6,(__VdtypeVar[6]),32);
    bufp->fullIData(oldp+7,(__VdtypeVar[7]),32);
    bufp->fullIData(oldp+8,(__VdtypeVar[8]),32);
    bufp->fullIData(oldp+9,(__VdtypeVar[9]),32);
    bufp->fullIData(oldp+10,(__VdtypeVar[10]),32);
    bufp->fullIData(oldp+11,(__VdtypeVar[11]),32);
    bufp->fullIData(oldp+12,(__VdtypeVar[12]),32);
    bufp->fullIData(oldp+13,(__VdtypeVar[13]),32);
    bufp->fullIData(oldp+14,(__VdtypeVar[14]),32);
    bufp->fullIData(oldp+15,(__VdtypeVar[15]),32);
    bufp->fullIData(oldp+16,(__VdtypeVar[16]),32);
    bufp->fullIData(oldp+17,(__VdtypeVar[17]),32);
    bufp->fullIData(oldp+18,(__VdtypeVar[18]),32);
    bufp->fullIData(oldp+19,(__VdtypeVar[19]),32);
    bufp->fullIData(oldp+20,(__VdtypeVar[20]),32);
    bufp->fullIData(oldp+21,(__VdtypeVar[21]),32);
    bufp->fullIData(oldp+22,(__VdtypeVar[22]),32);
    bufp->fullIData(oldp+23,(__VdtypeVar[23]),32);
    bufp->fullIData(oldp+24,(__VdtypeVar[24]),32);
    bufp->fullIData(oldp+25,(__VdtypeVar[25]),32);
    bufp->fullIData(oldp+26,(__VdtypeVar[26]),32);
    bufp->fullIData(oldp+27,(__VdtypeVar[27]),32);
    bufp->fullIData(oldp+28,(__VdtypeVar[28]),32);
    bufp->fullIData(oldp+29,(__VdtypeVar[29]),32);
    bufp->fullIData(oldp+30,(__VdtypeVar[30]),32);
    bufp->fullIData(oldp+31,(__VdtypeVar[31]),32);
}
