// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtb_RISCV_Pipeline.h for the primary calling header

#ifndef VERILATED_VTB_RISCV_PIPELINE___024ROOT_H_
#define VERILATED_VTB_RISCV_PIPELINE___024ROOT_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"


class Vtb_RISCV_Pipeline__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtb_RISCV_Pipeline___024root final {
  public:

    // DESIGN SPECIFIC STATE
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        CData/*0:0*/ tb_RISCV_Pipeline__DOT__clk;
        CData/*0:0*/ tb_RISCV_Pipeline__DOT__rst_n;
        CData/*0:0*/ tb_RISCV_Pipeline__DOT__loaded;
        CData/*0:0*/ tb_RISCV_Pipeline__DOT__pipeline_filled;
        CData/*0:0*/ tb_RISCV_Pipeline__DOT__PCSel_E_d1;
        CData/*0:0*/ tb_RISCV_Pipeline__DOT__sp_initialized;
        CData/*0:0*/ tb_RISCV_Pipeline__DOT__done_reported;
        CData/*0:0*/ tb_RISCV_Pipeline__DOT__dut__DOT__stall_load;
        CData/*0:0*/ tb_RISCV_Pipeline__DOT__dut__DOT__stall_if_id;
        CData/*0:0*/ tb_RISCV_Pipeline__DOT__dut__DOT__bubble_id_ex;
        CData/*4:0*/ tb_RISCV_Pipeline__DOT__dut__DOT__addrD_W;
        CData/*0:0*/ tb_RISCV_Pipeline__DOT__dut__DOT__RegWEn_W;
        CData/*4:0*/ tb_RISCV_Pipeline__DOT__dut__DOT__addrA_E;
        CData/*4:0*/ tb_RISCV_Pipeline__DOT__dut__DOT__addrB_E;
        CData/*4:0*/ tb_RISCV_Pipeline__DOT__dut__DOT__addrD_E;
        CData/*2:0*/ tb_RISCV_Pipeline__DOT__dut__DOT__funct3_E;
        CData/*3:0*/ tb_RISCV_Pipeline__DOT__dut__DOT__ALUSel_E;
        CData/*1:0*/ tb_RISCV_Pipeline__DOT__dut__DOT__WBSel_E;
        CData/*0:0*/ tb_RISCV_Pipeline__DOT__dut__DOT__RegWEn_E;
        CData/*0:0*/ tb_RISCV_Pipeline__DOT__dut__DOT__BrUn_E;
        CData/*0:0*/ tb_RISCV_Pipeline__DOT__dut__DOT__ASel_E;
        CData/*0:0*/ tb_RISCV_Pipeline__DOT__dut__DOT__BSel_E;
        CData/*0:0*/ tb_RISCV_Pipeline__DOT__dut__DOT__MemRW_E;
        CData/*0:0*/ tb_RISCV_Pipeline__DOT__dut__DOT__Is_Branch_E;
        CData/*0:0*/ tb_RISCV_Pipeline__DOT__dut__DOT__Is_Jump_E;
        CData/*0:0*/ tb_RISCV_Pipeline__DOT__dut__DOT__Is_JALR_E;
        CData/*0:0*/ tb_RISCV_Pipeline__DOT__dut__DOT__Is_Load_E;
        CData/*4:0*/ tb_RISCV_Pipeline__DOT__dut__DOT__addrD_M;
        CData/*0:0*/ tb_RISCV_Pipeline__DOT__dut__DOT__RegWEn_M;
        CData/*1:0*/ tb_RISCV_Pipeline__DOT__dut__DOT__fwdA;
        CData/*1:0*/ tb_RISCV_Pipeline__DOT__dut__DOT__fwdB;
        CData/*0:0*/ tb_RISCV_Pipeline__DOT__dut__DOT__BrEq_E;
        CData/*0:0*/ tb_RISCV_Pipeline__DOT__dut__DOT__BrLT_E;
        CData/*1:0*/ tb_RISCV_Pipeline__DOT__dut__DOT__WBSel_M;
        CData/*0:0*/ tb_RISCV_Pipeline__DOT__dut__DOT__MemRW_M;
        CData/*2:0*/ tb_RISCV_Pipeline__DOT__dut__DOT__funct3_M;
        CData/*1:0*/ tb_RISCV_Pipeline__DOT__dut__DOT__WBSel_W;
        CData/*7:0*/ tb_RISCV_Pipeline__DOT__dut__DOT__DMEM_inst__DOT__selected_byte;
        CData/*7:0*/ __VdfgRegularize_h6e95ff9d_0_0;
        CData/*0:0*/ __VdfgRegularize_h6e95ff9d_0_1;
        CData/*0:0*/ __VdfgRegularize_h6e95ff9d_0_2;
        CData/*0:0*/ __VdfgRegularize_h6e95ff9d_0_3;
        CData/*0:0*/ __VdfgRegularize_h6e95ff9d_0_4;
        CData/*0:0*/ __VdfgRegularize_h6e95ff9d_0_5;
        CData/*7:0*/ __VdlyVal__tb_RISCV_Pipeline__DOT__dut__DOT__DMEM_inst__DOT__memory__v0;
        CData/*0:0*/ __VdlySet__tb_RISCV_Pipeline__DOT__dut__DOT__DMEM_inst__DOT__memory__v0;
        CData/*7:0*/ __VdlyVal__tb_RISCV_Pipeline__DOT__dut__DOT__DMEM_inst__DOT__memory__v1;
        CData/*0:0*/ __VdlySet__tb_RISCV_Pipeline__DOT__dut__DOT__DMEM_inst__DOT__memory__v1;
        CData/*7:0*/ __VdlyVal__tb_RISCV_Pipeline__DOT__dut__DOT__DMEM_inst__DOT__memory__v2;
        CData/*0:0*/ __VdlySet__tb_RISCV_Pipeline__DOT__dut__DOT__DMEM_inst__DOT__memory__v2;
        CData/*7:0*/ __VdlyVal__tb_RISCV_Pipeline__DOT__dut__DOT__DMEM_inst__DOT__memory__v3;
        CData/*0:0*/ __VdlySet__tb_RISCV_Pipeline__DOT__dut__DOT__DMEM_inst__DOT__memory__v3;
        CData/*0:0*/ __VdlySet__tb_RISCV_Pipeline__DOT__dut__DOT__DMEM_inst__DOT__memory__v4;
        CData/*0:0*/ __VdlySet__tb_RISCV_Pipeline__DOT__dut__DOT__DMEM_inst__DOT__memory__v5;
        CData/*0:0*/ __VdlySet__tb_RISCV_Pipeline__DOT__dut__DOT__DMEM_inst__DOT__memory__v6;
        CData/*0:0*/ __VstlFirstIteration;
        CData/*0:0*/ __VstlPhaseResult;
        CData/*0:0*/ __Vtrigprevexpr___TOP__tb_RISCV_Pipeline__DOT__clk__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__tb_RISCV_Pipeline__DOT__rst_n__0;
        CData/*0:0*/ __VactPhaseResult;
        CData/*0:0*/ __VinactPhaseResult;
        CData/*0:0*/ __VnbaPhaseResult;
        SData/*15:0*/ tb_RISCV_Pipeline__DOT__dut__DOT__DMEM_inst__DOT__selected_half;
        SData/*10:0*/ __VdlyDim0__tb_RISCV_Pipeline__DOT__dut__DOT__DMEM_inst__DOT__memory__v0;
    };
    struct {
        SData/*10:0*/ __VdlyDim0__tb_RISCV_Pipeline__DOT__dut__DOT__DMEM_inst__DOT__memory__v1;
        SData/*10:0*/ __VdlyDim0__tb_RISCV_Pipeline__DOT__dut__DOT__DMEM_inst__DOT__memory__v2;
        SData/*10:0*/ __VdlyDim0__tb_RISCV_Pipeline__DOT__dut__DOT__DMEM_inst__DOT__memory__v3;
        SData/*15:0*/ __VdlyVal__tb_RISCV_Pipeline__DOT__dut__DOT__DMEM_inst__DOT__memory__v4;
        SData/*10:0*/ __VdlyDim0__tb_RISCV_Pipeline__DOT__dut__DOT__DMEM_inst__DOT__memory__v4;
        SData/*15:0*/ __VdlyVal__tb_RISCV_Pipeline__DOT__dut__DOT__DMEM_inst__DOT__memory__v5;
        SData/*10:0*/ __VdlyDim0__tb_RISCV_Pipeline__DOT__dut__DOT__DMEM_inst__DOT__memory__v5;
        SData/*10:0*/ __VdlyDim0__tb_RISCV_Pipeline__DOT__dut__DOT__DMEM_inst__DOT__memory__v6;
        IData/*31:0*/ tb_RISCV_Pipeline__DOT__fd;
        IData/*31:0*/ tb_RISCV_Pipeline__DOT__cycle;
        IData/*31:0*/ tb_RISCV_Pipeline__DOT__instr_count;
        IData/*31:0*/ tb_RISCV_Pipeline__DOT__stall_count;
        IData/*31:0*/ tb_RISCV_Pipeline__DOT__flush_count;
        IData/*31:0*/ tb_RISCV_Pipeline__DOT__min_sp;
        IData/*31:0*/ tb_RISCV_Pipeline__DOT__min_sp_cycle;
        IData/*31:0*/ tb_RISCV_Pipeline__DOT__done_cycle;
        IData/*31:0*/ tb_RISCV_Pipeline__DOT__report_result__Vstatic__canary_now;
        IData/*31:0*/ tb_RISCV_Pipeline__DOT__report_result__Vstatic__a0;
        IData/*31:0*/ tb_RISCV_Pipeline__DOT__report_result__Vstatic__stack_used_bytes;
        IData/*31:0*/ tb_RISCV_Pipeline__DOT__report_result__Vstatic__flush_penalty_cycles;
        IData/*31:0*/ tb_RISCV_Pipeline__DOT__report_result__Vstatic__total_overhead_cycles;
        IData/*31:0*/ tb_RISCV_Pipeline__DOT__dut__DOT__PC_F;
        IData/*31:0*/ tb_RISCV_Pipeline__DOT__dut__DOT__PC_next_F;
        IData/*31:0*/ tb_RISCV_Pipeline__DOT__dut__DOT__PC_target_E;
        IData/*31:0*/ tb_RISCV_Pipeline__DOT__dut__DOT__PC_D;
        IData/*31:0*/ tb_RISCV_Pipeline__DOT__dut__DOT__PC_Plus4_D;
        IData/*31:0*/ tb_RISCV_Pipeline__DOT__dut__DOT__Instr_D;
        IData/*31:0*/ tb_RISCV_Pipeline__DOT__dut__DOT__DataD_W;
        IData/*31:0*/ tb_RISCV_Pipeline__DOT__dut__DOT__PC_E;
        IData/*31:0*/ tb_RISCV_Pipeline__DOT__dut__DOT__PC_Plus4_E;
        IData/*31:0*/ tb_RISCV_Pipeline__DOT__dut__DOT__DataA_E;
        IData/*31:0*/ tb_RISCV_Pipeline__DOT__dut__DOT__DataB_E;
        IData/*31:0*/ tb_RISCV_Pipeline__DOT__dut__DOT__Imm_E;
        IData/*31:0*/ tb_RISCV_Pipeline__DOT__dut__DOT__ForwardData_M;
        IData/*31:0*/ tb_RISCV_Pipeline__DOT__dut__DOT__fwd_DataA_E;
        IData/*31:0*/ tb_RISCV_Pipeline__DOT__dut__DOT__fwd_DataB_E;
        IData/*31:0*/ tb_RISCV_Pipeline__DOT__dut__DOT__Mux_ALU_DataA_E;
        IData/*31:0*/ tb_RISCV_Pipeline__DOT__dut__DOT__Mux_ALU_DataB_E;
        IData/*31:0*/ tb_RISCV_Pipeline__DOT__dut__DOT__ALU_out_E;
        IData/*31:0*/ tb_RISCV_Pipeline__DOT__dut__DOT__ALU_out_M;
        IData/*31:0*/ tb_RISCV_Pipeline__DOT__dut__DOT__DataB_M;
        IData/*31:0*/ tb_RISCV_Pipeline__DOT__dut__DOT__PC_Plus4_M;
        IData/*31:0*/ tb_RISCV_Pipeline__DOT__dut__DOT__ALU_out_W;
        IData/*31:0*/ tb_RISCV_Pipeline__DOT__dut__DOT__DataR_W;
        IData/*31:0*/ tb_RISCV_Pipeline__DOT__dut__DOT__PC_Plus4_W;
        IData/*31:0*/ tb_RISCV_Pipeline__DOT__dut__DOT__Reg_inst__DOT__i;
        IData/*31:0*/ __VdlyVal__tb_RISCV_Pipeline__DOT__dut__DOT__DMEM_inst__DOT__memory__v6;
        IData/*31:0*/ __VactIterCount;
        IData/*31:0*/ __VinactIterCount;
        IData/*31:0*/ __Vi;
        VlUnpacked<IData/*31:0*/, 1025> tb_RISCV_Pipeline__DOT__dut__DOT__DMEM_inst__DOT__memory;
        VlUnpacked<IData/*31:0*/, 32> tb_RISCV_Pipeline__DOT__dut__DOT__Reg_inst__DOT__registers;
        VlUnpacked<IData/*31:0*/, 256> tb_RISCV_Pipeline__DOT__dut__DOT__IMEM_inst__DOT__memory;
        VlUnpacked<QData/*63:0*/, 1> __VstlTriggered;
        VlUnpacked<QData/*63:0*/, 1> __VactTriggered;
        VlUnpacked<QData/*63:0*/, 1> __VactTriggeredAcc;
        VlUnpacked<QData/*63:0*/, 1> __VnbaTriggered;
        VlUnpacked<CData/*0:0*/, 4> __Vm_traceActivity;
    };
    double tb_RISCV_Pipeline__DOT__report_result__Vstatic__cpi;
    VlDelayScheduler __VdlySched;

    // INTERNAL VARIABLES
    Vtb_RISCV_Pipeline__Syms* vlSymsp;
    const char* vlNamep;

    // CONSTRUCTORS
    Vtb_RISCV_Pipeline___024root(Vtb_RISCV_Pipeline__Syms* symsp, const char* namep);
    ~Vtb_RISCV_Pipeline___024root();
    VL_UNCOPYABLE(Vtb_RISCV_Pipeline___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
