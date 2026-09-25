//1 TOP
module RISCV_Pipeline (
  input wire clk,
  input wire rst_n
);
  // =========================================================================
  // HAZARD & CONTROL FLUSH / STALL LOGIC
  // =========================================================================
  wire stall_load;
  wire PCSel_E;

  wire pc_write_en   = !stall_load || PCSel_E;
  wire stall_if_id   = stall_load && !PCSel_E;
  wire flush_if_id   = PCSel_E;
  wire bubble_id_ex  = stall_load || PCSel_E;

  // =========================================================================
  // 1. INSTRUCTION FETCH (IF) STAGE
  // =========================================================================
  wire [31:0] PC_F, PC_next_F, PC_Plus4_F, Instr_F;
  wire [31:0] Addr_instr_mem;
  wire [31:0] PC_target_E;

  assign PC_next_F      = PCSel_E ? PC_target_E : PC_Plus4_F;
  assign PC_Plus4_F     = PC_F + 32'd4;

  assign Addr_instr_mem = {2'b0, PC_F[31:2]};

  Program_Counter PC_inst (
    .clk      (clk),
    .rst_n    (rst_n),
    .pc_write (pc_write_en),
    .PC_in    (PC_next_F),
    .PC_out   (PC_F)
  );

  Instruction_Memory IMEM_inst (
    .addr (Addr_instr_mem),
    .inst (Instr_F)
  );

  // =========================================================================
  // PIPELINE REGISTER: IF / ID
  // =========================================================================
  wire [31:0] PC_D, PC_Plus4_D, Instr_D;

  IF_ID_reg IF_ID_inst (
    .clk        (clk),
    .rst_n      (rst_n),
    .stall      (stall_if_id),
    .flush      (flush_if_id),
    .PC_in      (PC_F),
    .PC_Plus4_in(PC_Plus4_F),
    .Instr_in   (Instr_F),
    .PC_D       (PC_D),
    .PC_Plus4_D (PC_Plus4_D),
    .Instr_D    (Instr_D)
  );

  // =========================================================================
  // 2. INSTRUCTION DECODE (ID) STAGE
  // =========================================================================
  wire [2:0]  ImmSel_D;
  wire        RegWEn_D, BrUn_D, ASel_D, BSel_D, MemRW_D;
  wire [1:0]  WBSel_D;
  wire [3:0]  ALUSel_D;
  wire        UsesRs1_D, UsesRs2_D, Is_Branch_D, Is_Jump_D, Is_JALR_D, Is_Load_D;
  wire [31:0] Imm_D;
  wire [31:0] rf_DataA_D, rf_DataB_D;
  wire [31:0] DataA_D, DataB_D;

  control_unit Control_logic_inst (
    .opcode_eff (Instr_D[6:2]),
    .funct7_fif (Instr_D[30]),
    .funct3     (Instr_D[14:12]),
    .ImmSel     (ImmSel_D),
    .RegWEn     (RegWEn_D),
    .BrUn       (BrUn_D),
    .ASel       (ASel_D),
    .BSel       (BSel_D),
    .ALUSel     (ALUSel_D),
    .MemRW      (MemRW_D),
    .WBSel      (WBSel_D),
    .UsesRs1    (UsesRs1_D),
    .UsesRs2    (UsesRs2_D),
    .Is_Branch  (Is_Branch_D),
    .Is_Jump    (Is_Jump_D),
    .Is_JALR    (Is_JALR_D),
    .Is_Load    (Is_Load_D)
  );

  wire [31:0] DataD_W;
  wire [4:0]  addrD_W;
  wire        RegWEn_W;

  RegisterFile Reg_inst (
    .clk       (clk),
    .reset     (rst_n),
    .addrA     (Instr_D[19:15]),
    .addrB     (Instr_D[24:20]),
    .addrD     (addrD_W),
    .dataD     (DataD_W),
    .reg_write (RegWEn_W),
    .dataA     (rf_DataA_D),
    .dataB     (rf_DataB_D)
  );

  // WB-to-ID Bypass
  assign DataA_D = (RegWEn_W && (addrD_W != 5'd0) && (addrD_W == Instr_D[19:15])) ? DataD_W : rf_DataA_D;
  assign DataB_D = (RegWEn_W && (addrD_W != 5'd0) && (addrD_W == Instr_D[24:20])) ? DataD_W : rf_DataB_D;

  Immediate_Generator Imm_Gen_inst (
    .Inst   (Instr_D),
    .ImmSel (ImmSel_D),
    .Imm    (Imm_D)
  );

  // =========================================================================
  // PIPELINE REGISTER: ID / EX
  // =========================================================================
  wire [31:0] PC_E, PC_Plus4_E, DataA_E, DataB_E, Imm_E;
  wire [4:0]  addrA_E, addrB_E, addrD_E;
  wire [2:0]  funct3_E;
  wire [3:0]  ALUSel_E;
  wire [1:0]  WBSel_E;
  wire        RegWEn_E, BrUn_E, ASel_E, BSel_E, MemRW_E;
  wire        Is_Branch_E, Is_Jump_E, Is_JALR_E, Is_Load_E;

  ID_EX_reg ID_EX_inst (
    .clk        (clk),
    .rst_n      (rst_n),
    .bubble     (bubble_id_ex),
    .PC_D       (PC_D),
    .PC_Plus4_D (PC_Plus4_D),
    .DataA_D    (DataA_D),
    .DataB_D    (DataB_D),
    .Imm_D      (Imm_D),
    .addrA_D    (Instr_D[19:15]),
    .addrB_D    (Instr_D[24:20]),
    .addrD_D    (Instr_D[11:7]),
    .funct3_D   (Instr_D[14:12]),
    .ALUSel_D   (ALUSel_D),
    .WBSel_D    (WBSel_D),
    .RegWEn_D   (RegWEn_D),
    .BrUn_D     (BrUn_D),
    .ASel_D     (ASel_D),
    .BSel_D     (BSel_D),
    .MemRW_D    (MemRW_D),
    .Is_Branch_D(Is_Branch_D),
    .Is_Jump_D  (Is_Jump_D),
    .Is_JALR_D  (Is_JALR_D),
    .Is_Load_D  (Is_Load_D),

    .PC_E       (PC_E),
    .PC_Plus4_E (PC_Plus4_E),
    .DataA_E    (DataA_E),
    .DataB_E    (DataB_E),
    .Imm_E      (Imm_E),
    .addrA_E    (addrA_E),
    .addrB_E    (addrB_E),
    .addrD_E    (addrD_E),
    .funct3_E   (funct3_E),
    .ALUSel_E   (ALUSel_E),
    .WBSel_E    (WBSel_E),
    .RegWEn_E   (RegWEn_E),
    .BrUn_E     (BrUn_E),
    .ASel_E     (ASel_E),
    .BSel_E     (BSel_E),
    .MemRW_E    (MemRW_E),
    .Is_Branch_E(Is_Branch_E),
    .Is_Jump_E  (Is_Jump_E),
    .Is_JALR_E  (Is_JALR_E),
    .Is_Load_E  (Is_Load_E)
  );

  hazard_detect Hazard_inst (
    .Is_Load_E (Is_Load_E),
    .addrD_E   (addrD_E),
    .addrA_D   (Instr_D[19:15]),
    .addrB_D   (Instr_D[24:20]),
    .UsesRs1_D (UsesRs1_D),
    .UsesRs2_D (UsesRs2_D),
    .stall_load(stall_load)
  );

  // =========================================================================
  // 3. EXECUTE (EX) STAGE & DATA FORWARDING
  // =========================================================================
  wire [4:0]  addrD_M;
  wire        RegWEn_M;
  wire [1:0]  fwdA, fwdB;
  wire [31:0] ForwardData_M;

  forward_unit Forward_inst (
    .addrA_E (addrA_E),
    .addrB_E (addrB_E),
    .addrD_M (addrD_M),
    .addrD_W (addrD_W),
    .RegWEn_M(RegWEn_M),
    .RegWEn_W(RegWEn_W),
    .fwdA    (fwdA),
    .fwdB    (fwdB)
  );

  reg [31:0] fwd_DataA_E, fwd_DataB_E;

  always @(*) begin
    case (fwdA)
      2'b10:   fwd_DataA_E = ForwardData_M;
      2'b01:   fwd_DataA_E = DataD_W;
      default: fwd_DataA_E = DataA_E;
    endcase

    case (fwdB)
      2'b10:   fwd_DataB_E = ForwardData_M;
      2'b01:   fwd_DataB_E = DataD_W;
      default: fwd_DataB_E = DataB_E;
    endcase
  end

  wire [31:0] Mux_ALU_DataA_E = ASel_E ? PC_E  : fwd_DataA_E;
  wire [31:0] Mux_ALU_DataB_E = BSel_E ? Imm_E : fwd_DataB_E;

  wire [31:0] ALU_out_E;
  ALU ALU_mod_inst (
    .operand_0 (Mux_ALU_DataA_E),
    .operand_1 (Mux_ALU_DataB_E),
    .ALU_Sel   (ALUSel_E),
    .result    (ALU_out_E)
  );

  wire BrEq_E, BrLT_E;
  Branch_Comp Branch_Comp_inst (
    .operand_0 (fwd_DataA_E),
    .operand_1 (fwd_DataB_E),
    .BrUn      (BrUn_E),
    .BrEq      (BrEq_E),
    .BrLT      (BrLT_E)
  );

  Branch_Resolve BranchResolve_inst (
    .Is_Branch_E (Is_Branch_E),
    .Is_Jump_E   (Is_Jump_E),
    .funct3_E    (funct3_E),
    .BrEq_E      (BrEq_E),
    .BrLt_E      (BrLT_E),
    .PCSel_E     (PCSel_E)
  );

  assign PC_target_E = Is_JALR_E ? {ALU_out_E[31:1], 1'b0} : ALU_out_E;

  // =========================================================================
  // PIPELINE REGISTER: EX / MEM
  // =========================================================================
  wire [31:0] ALU_out_M, DataB_M, PC_Plus4_M;
  wire [1:0]  WBSel_M;
  wire        MemRW_M;
  wire [2:0]  funct3_M;

  EX_MEM_reg EX_MEM_inst (
    .clk        (clk),
    .rst_n      (rst_n),
    .ALU_out_E  (ALU_out_E),
    .DataB_fwd_E(fwd_DataB_E),
    .PC_Plus4_E (PC_Plus4_E),
    .addrD_E    (addrD_E),
    .WBSel_E    (WBSel_E),
    .RegWEn_E   (RegWEn_E),
    .MemRW_E    (MemRW_E),
    .funct3_E   (funct3_E),

    .ALU_out_M  (ALU_out_M),
    .DataB_M    (DataB_M),
    .PC_Plus4_M (PC_Plus4_M),
    .addrD_M    (addrD_M),
    .WBSel_M    (WBSel_M),
    .RegWEn_M   (RegWEn_M),
    .MemRW_M    (MemRW_M),
    .funct3_M   (funct3_M)
  );

  // =========================================================================
  // 4. MEMORY (MEM) STAGE
  // =========================================================================
  // Forward đúng PC_Plus4 khi lệnh là Jump
  assign ForwardData_M = (WBSel_M == 2'b10) ? PC_Plus4_M : ALU_out_M;
  wire [31:0] DataR_M;
  Data_Memory DMEM_inst (
    .clk    (clk),
    .MemRW  (MemRW_M),
    .addr   (ALU_out_M),
    .DataW  (DataB_M),
    .funct3 (funct3_M),
    .DataR  (DataR_M)
  );

  // =========================================================================
  // PIPELINE REGISTER: MEM / WB
  // =========================================================================
  wire [31:0] ALU_out_W, DataR_W, PC_Plus4_W;
  wire [1:0]  WBSel_W;

  MEM_WB_reg MEM_WB_inst (
    .clk       (clk),
    .rst_n     (rst_n),
    .ALU_out_M (ALU_out_M),
    .DataR_M   (DataR_M),
    .PC_Plus4_M(PC_Plus4_M),
    .addrD_M   (addrD_M),
    .WBSel_M   (WBSel_M),
    .RegWEn_M  (RegWEn_M),

    .ALU_out_W (ALU_out_W),
    .DataR_W   (DataR_W),
    .PC_Plus4_W(PC_Plus4_W),
    .addrD_W   (addrD_W),
    .WBSel_W   (WBSel_W),
    .RegWEn_W  (RegWEn_W)
  );

  // =========================================================================
  // 5. WRITE BACK (WB) STAGE
  // =========================================================================
  assign DataD_W = (WBSel_W == 2'b00) ? DataR_W  :
    (WBSel_W == 2'b01) ? ALU_out_W :
    PC_Plus4_W;

endmodule


//2PC
module Program_Counter (
    input  wire        clk,
    input  wire        rst_n,
    input  wire        pc_write,  
    input  wire [31:0] PC_in,
    output reg  [31:0] PC_out
);

    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            PC_out <= 32'b0;
        end 
        else if (pc_write) begin
            PC_out <= PC_in;
        end
    end

endmodule

//3 IMEM
module Instruction_Memory (
  input wire [31:0] addr,
  output wire [31:0] inst
);
  reg [31:0] memory [0:255];
  
  assign inst = memory[addr[7:0]]; 
endmodule

//4 main_decoder
module main_decoder (
  input  wire [4:0] opcode_eff,
  input  wire [2:0] funct3,

  output reg  [2:0] ImmSel,
  output reg        RegWEn,
  output reg        BrUn,
  output reg        ASel,
  output reg        BSel,
  output reg        MemRW,
  output reg  [1:0] WBSel,
  output reg        arithmetic,
  output reg        i_type,
  output reg        pass_b,

  output reg        UsesRs1,
  output reg        UsesRs2,
  output reg        Is_Branch,
  output reg        Is_Jump,
  output reg        Is_JALR,
  output reg        Is_Load
);

  localparam OP_LOAD   = 5'b00000;
  localparam OP_IMM    = 5'b00100;
  localparam OP_AUIPC  = 5'b00101;
  localparam OP_STORE  = 5'b01000;
  localparam OP_REG    = 5'b01100;
  localparam OP_LUI    = 5'b01101;
  localparam OP_BRANCH = 5'b11000;
  localparam OP_JALR   = 5'b11001;
  localparam OP_JAL    = 5'b11011;

  localparam IMM_I     = 3'b000;
  localparam IMM_S     = 3'b001;
  localparam IMM_B     = 3'b010;
  localparam IMM_U     = 3'b011;
  localparam IMM_J     = 3'b100;

  localparam WB_MEM    = 2'b00;
  localparam WB_ALU    = 2'b01;
  localparam WB_PC4    = 2'b10;

  always @(*) begin
    ImmSel     = IMM_I;
    RegWEn     = 1'b0;
    BrUn       = 1'b0;
    ASel       = 1'b0;
    BSel       = 1'b0;
    MemRW      = 1'b0;
    WBSel      = WB_ALU;
    arithmetic = 1'b0;
    i_type     = 1'b0;
    pass_b     = 1'b0;

    UsesRs1    = 1'b0;
    UsesRs2    = 1'b0;
    Is_Branch  = 1'b0;
    Is_Jump    = 1'b0;
    Is_JALR    = 1'b0;
    Is_Load    = 1'b0;

    case (opcode_eff)
      OP_LOAD: begin
        ImmSel  = IMM_I;
        RegWEn  = 1'b1;
        BSel    = 1'b1;
        WBSel   = WB_MEM;
        UsesRs1 = 1'b1;
        Is_Load = 1'b1;
      end

      OP_STORE: begin
        ImmSel  = IMM_S;
        BSel    = 1'b1;
        MemRW   = 1'b1;
        UsesRs1 = 1'b1;
        UsesRs2 = 1'b1;
      end

      OP_REG: begin
        RegWEn     = 1'b1;
        arithmetic = 1'b1;
        UsesRs1    = 1'b1;
        UsesRs2    = 1'b1;
      end

      OP_IMM: begin
        ImmSel     = IMM_I;
        RegWEn     = 1'b1;
        BSel       = 1'b1;
        arithmetic = 1'b1;
        i_type     = 1'b1;
        UsesRs1    = 1'b1;
      end

      OP_BRANCH: begin
        ImmSel    = IMM_B;
        ASel      = 1'b1;
        BSel      = 1'b1;
        Is_Branch = 1'b1;
        UsesRs1   = 1'b1;
        UsesRs2   = 1'b1;

        if (funct3 == 3'b110 || funct3 == 3'b111) begin
          BrUn = 1'b1;
        end
      end

      OP_JAL: begin
        ImmSel  = IMM_J;
        RegWEn  = 1'b1;
        ASel    = 1'b1;
        BSel    = 1'b1;
        WBSel   = WB_PC4;
        Is_Jump = 1'b1;
      end

      OP_JALR: begin
        ImmSel  = IMM_I;
        RegWEn  = 1'b1;
        ASel    = 1'b0;
        BSel    = 1'b1;
        WBSel   = WB_PC4;
        Is_Jump = 1'b1;
        Is_JALR = 1'b1;
        UsesRs1 = 1'b1;
      end

      OP_LUI: begin
        ImmSel = IMM_U;
        RegWEn = 1'b1;
        BSel   = 1'b1;
        pass_b = 1'b1;
      end

      OP_AUIPC: begin
        ImmSel = IMM_U;
        RegWEn = 1'b1;
        ASel   = 1'b1;
        BSel   = 1'b1;
      end

      default: ;
    endcase
  end

endmodule

//5 alu_decoder
module ALU_decoder (
    input  wire       arithmetic,
    input  wire       pass_b,
    input  wire [2:0] funct3,
    input  wire       funct7_fif,
    input  wire       i_type,
    output reg  [3:0] ALUSel
);

    localparam ADD     = 4'h0;
    localparam SUB     = 4'h1;
    localparam AND_OP  = 4'h2;
    localparam OR_OP   = 4'h3;
    localparam XOR_OP  = 4'h4;
    localparam SLL_OP  = 4'h5;
    localparam SRL_OP  = 4'h6;
    localparam SRA_OP  = 4'h7;
    localparam SLT_OP  = 4'h8;
    localparam SLTU_OP = 4'h9;
    localparam PASS_B  = 4'hA;

    always @(*) begin
        ALUSel = ADD;
        if (pass_b) begin
            ALUSel = PASS_B;
        end else if (arithmetic) begin
            case (funct3)
                3'b000:  ALUSel = (!i_type && funct7_fif) ? SUB : ADD;
                3'b001:  ALUSel = SLL_OP;
                3'b010:  ALUSel = SLT_OP;
                3'b011:  ALUSel = SLTU_OP;
                3'b100:  ALUSel = XOR_OP;
                3'b101:  ALUSel = funct7_fif ? SRA_OP : SRL_OP;
                3'b110:  ALUSel = OR_OP;
                3'b111:  ALUSel = AND_OP;
                default: ALUSel = ADD;
            endcase
        end
    end

endmodule

//6 control_unit
module control_unit (
  input  wire [4:0] opcode_eff,
  input  wire       funct7_fif,
  input  wire [2:0] funct3,

  output wire [2:0] ImmSel,
  output wire       RegWEn,
  output wire       BrUn,
  output wire       ASel,
  output wire       BSel,
  output wire [3:0] ALUSel,
  output wire       MemRW,
  output wire [1:0] WBSel,

  output wire       UsesRs1,
  output wire       UsesRs2,
  output wire       Is_Branch,
  output wire       Is_Jump,   // JAL hoặc JALR
  output wire       Is_JALR,   // Chỉ đúng với opcode 1100111 (JALR)
  output wire       Is_Load
);

  wire arithmetic;
  wire i_type;
  wire pass_b;

  main_decoder main_decoder_inst (
    .opcode_eff (opcode_eff),
    .funct3     (funct3),
    .ImmSel     (ImmSel),
    .RegWEn     (RegWEn),
    .BrUn       (BrUn),
    .ASel       (ASel),
    .BSel       (BSel),
    .MemRW      (MemRW),
    .WBSel      (WBSel),
    .arithmetic (arithmetic),
    .i_type     (i_type),
    .pass_b     (pass_b),
    .UsesRs1    (UsesRs1),
    .UsesRs2    (UsesRs2),
    .Is_Branch  (Is_Branch),
    .Is_Jump    (Is_Jump),
    .Is_JALR    (Is_JALR),
    .Is_Load    (Is_Load)
  );

  ALU_decoder ALU_decoder_inst (
    .arithmetic (arithmetic),
    .pass_b     (pass_b),
    .funct3     (funct3),
    .funct7_fif (funct7_fif),
    .i_type     (i_type),
    .ALUSel     (ALUSel)
  );

endmodule

//7 Imm_gen
module Immediate_Generator (
  input  wire [31:0] Inst,
  input  wire [2:0]  ImmSel,
  output reg  [31:0] Imm
);

  localparam IMM_I = 3'b000;
  localparam IMM_S = 3'b001;
  localparam IMM_B = 3'b010;
  localparam IMM_U = 3'b011;
  localparam IMM_J = 3'b100;

  always @(*) begin
    case (ImmSel)
      IMM_I: Imm = {{20{Inst[31]}}, Inst[31:20]};
      IMM_S: Imm = {{20{Inst[31]}}, Inst[31:25], Inst[11:7]};
      IMM_B: Imm = {{19{Inst[31]}}, Inst[31], Inst[7],
                    Inst[30:25], Inst[11:8], 1'b0};
      IMM_U: Imm = {Inst[31:12], 12'b0};
      IMM_J: Imm = {{11{Inst[31]}}, Inst[31], Inst[19:12],
                    Inst[20], Inst[30:21], 1'b0};
      default: Imm = 32'b0;
    endcase
  end

endmodule

//8 Register_file
module RegisterFile (
  input wire clk,
  input wire reset,
  input wire [4:0] addrA,
  input wire [4:0] addrB,
  input wire [4:0] addrD,
  input wire [31:0] dataD,
  input wire reg_write,
  output wire [31:0] dataA,
  output wire [31:0] dataB
);
  reg [31:0] registers [0:31];
  integer i;

  always @(posedge clk or negedge reset) begin
    if (!reset) begin
      for (i = 0; i < 32; i = i + 1)
        registers [i] <= 32'b0;
    end else if (reg_write && (addrD != 5'd0)) begin
      registers [addrD] <= dataD;
    end
  end

  assign dataA = (addrA == 5'd0) ? 32'b0 :
                 ((addrA == addrD) && reg_write) ? dataD : 
                 registers[addrA];

  assign dataB = (addrB == 5'd0) ? 32'b0 :
                 ((addrB == addrD) && reg_write) ? dataD : 
                 registers[addrB];

endmodule

//9 Branch_comp
module Branch_Comp (
  input wire [31:0] operand_0,
  input wire [31:0] operand_1,
  input wire BrUn,
  output wire BrEq,
  output wire BrLT
);

  assign BrEq = (operand_0 == operand_1);
  assign BrLT = BrUn ? (operand_0 < operand_1)
    : ($signed(operand_0) < $signed(operand_1));

endmodule

//10 ALU
module ALU (
  input wire [3:0] ALU_Sel,
  input wire [31:0] operand_0,
  input wire [31:0] operand_1,
  output reg [31:0] result
);
  localparam ADD = 4'h0;
  localparam SUB = 4'h1;
  localparam AND_OP = 4'h2;
  localparam OR_OP = 4'h3;
  localparam XOR_OP = 4'h4;
  localparam SLL_OP = 4'h5;
  localparam SRL_OP = 4'h6;
  localparam SRA_OP = 4'h7;
  localparam SLT_OP = 4'h8;
  localparam SLTU_OP = 4'h9;
  localparam PASS_B = 4'hA;
  
  always @(*) begin
    case (ALU_Sel)
      ADD:
        result = operand_0 + operand_1;
      SUB:
        result = operand_0 - operand_1;
      AND_OP:
        result = operand_0 & operand_1;
      OR_OP:
        result = operand_0 | operand_1;
      XOR_OP:
        result = operand_0 ^ operand_1;
      SLL_OP:
        result = operand_0 << operand_1[4:0];
      SRL_OP:
        result = operand_0 >> operand_1[4:0];
      SRA_OP: 
        result = $signed(operand_0) >>> operand_1[4:0]; 
      SLT_OP: 
        result = ($signed(operand_0) < $signed(operand_1));
      SLTU_OP:
        result = operand_0 < operand_1;
      PASS_B:
        result = operand_1;
      default: result = 32'b0;
    endcase
  end
endmodule

//11 DMEM
module Data_Memory (
  input wire clk,
  input wire MemRW,
  input wire [31:0] addr,
  input wire [31:0] DataW,
  input wire [2:0] funct3,
  output reg [31:0] DataR
);

  reg [31:0] memory [0:1024];

  wire [9:0] ram_addr;
  wire [31:0] word;
  reg [7:0] selected_byte;
  reg [15:0] selected_half;

  assign ram_addr = (addr - 32'h00000400) >> 2;  
  assign word = memory[ram_addr];

  always @(*) begin
    case (addr[1:0])
      2'b00: selected_byte = word[7:0];
      2'b01: selected_byte = word[15:8];
      2'b10: selected_byte = word[23:16];
      default: selected_byte = word[31:24];
    endcase

    selected_half = addr[1] ? word[31:16] : word[15:0];

    case (funct3)
      3'b000: DataR = {{24{selected_byte[7]}}, selected_byte};
      3'b001: DataR = {{16{selected_half[15]}}, selected_half};
      3'b010: DataR = word;
      3'b100: DataR = {24'b0, selected_byte};
      3'b101: DataR = {16'b0, selected_half};
      default: DataR = 32'b0;
    endcase
  end

  always @(posedge clk) begin
    if (MemRW) begin
      case (funct3)
        3'b000: begin
          case (addr[1:0])
            2'b00: memory[ram_addr][7:0] <= DataW[7:0];
            2'b01: memory[ram_addr][15:8] <= DataW[7:0];
            2'b10: memory[ram_addr][23:16] <= DataW[7:0];
            default: memory[ram_addr][31:24] <= DataW[7:0];
          endcase
        end
        3'b001: begin
          if (addr[1])
            memory[ram_addr][31:16] <= DataW[15:0];
          else
            memory[ram_addr][15:0] <= DataW[15:0];
        end
        3'b010: memory[ram_addr] <= DataW;
        default: ;
      endcase
    end
  end

endmodule

//12 IF_ID_reg
module IF_ID_reg(
  input clk, rst_n, stall, flush,
  input [31:0] PC_in, PC_Plus4_in, Instr_in,
  output reg [31:0] PC_D, PC_Plus4_D, Instr_D
);
  always @(posedge clk or negedge rst_n) begin
    if (~rst_n) begin
      PC_D <= 32'b0; 
      PC_Plus4_D <= 32'b0; 
      Instr_D <= 32'h00000013; // addi x0,x0,0
    end else if (flush) begin
      PC_D <= 32'b0; 
      PC_Plus4_D <= 32'b0; 
      Instr_D <= 32'h00000013; // addi x0,x0,0
    end else if (!stall) begin
      PC_D <= PC_in; 
      PC_Plus4_D <= PC_Plus4_in; 
      Instr_D <= Instr_in;
    end
  end
endmodule

//13 ID_EX_reg
module ID_EX_reg(
  input clk, rst_n, bubble,
  input [31:0] PC_D, PC_Plus4_D, DataA_D, DataB_D, Imm_D,
  input [4:0]  addrA_D, addrB_D, addrD_D,
  input [2:0]  funct3_D,
  input [3:0]  ALUSel_D,
  input [1:0]  WBSel_D,
  input        RegWEn_D, BrUn_D, ASel_D, BSel_D, MemRW_D,
  Is_Branch_D, Is_Jump_D, Is_JALR_D, Is_Load_D,

  output reg [31:0] PC_E, PC_Plus4_E, DataA_E, DataB_E, Imm_E,
  output reg [4:0]  addrA_E, addrB_E, addrD_E,
  output reg [2:0]  funct3_E,
  output reg [3:0]  ALUSel_E,
  output reg [1:0]  WBSel_E,
  output reg        RegWEn_E, BrUn_E, ASel_E, BSel_E, MemRW_E,
  Is_Branch_E, Is_Jump_E, Is_JALR_E, Is_Load_E
);

  always @(posedge clk or negedge rst_n) begin
    if (~rst_n) begin
      PC_E        <= 32'b0;
      PC_Plus4_E  <= 32'b0;
      DataA_E     <= 32'b0;
      DataB_E     <= 32'b0;
      Imm_E       <= 32'b0;
      addrA_E     <= 5'b0;
      addrB_E     <= 5'b0;
      addrD_E     <= 5'b0;
      funct3_E    <= 3'b0;
      ALUSel_E    <= 4'b0;
      WBSel_E     <= 2'b0;

      RegWEn_E    <= 1'b0;
      BrUn_E      <= 1'b0;
      ASel_E      <= 1'b0;
      BSel_E      <= 1'b0;
      MemRW_E     <= 1'b0;
      Is_Branch_E <= 1'b0;
      Is_Jump_E   <= 1'b0;
      Is_JALR_E   <= 1'b0;
      Is_Load_E   <= 1'b0;
    end else if (bubble) begin
      PC_E        <= 32'b0;
      PC_Plus4_E  <= 32'b0;
      DataA_E     <= 32'b0;
      DataB_E     <= 32'b0;
      Imm_E       <= 32'b0;
      addrA_E     <= 5'b0;
      addrB_E     <= 5'b0;
      addrD_E     <= 5'b0;
      funct3_E    <= 3'b0;
      ALUSel_E    <= 4'b0;
      WBSel_E     <= 2'b0;

      RegWEn_E    <= 1'b0;
      BrUn_E      <= 1'b0;
      ASel_E      <= 1'b0;
      BSel_E      <= 1'b0;
      MemRW_E     <= 1'b0;
      Is_Branch_E <= 1'b0;
      Is_Jump_E   <= 1'b0;
      Is_JALR_E   <= 1'b0;
      Is_Load_E   <= 1'b0;
    end else begin
      PC_E        <= PC_D;
      PC_Plus4_E  <= PC_Plus4_D;
      DataA_E     <= DataA_D;
      DataB_E     <= DataB_D;
      Imm_E       <= Imm_D;
      addrA_E     <= addrA_D;
      addrB_E     <= addrB_D;
      addrD_E     <= addrD_D;
      funct3_E    <= funct3_D;
      ALUSel_E    <= ALUSel_D;
      WBSel_E     <= WBSel_D;

      RegWEn_E    <= RegWEn_D;
      BrUn_E      <= BrUn_D;
      ASel_E      <= ASel_D;
      BSel_E      <= BSel_D;
      MemRW_E     <= MemRW_D;
      Is_Branch_E <= Is_Branch_D;
      Is_Jump_E   <= Is_Jump_D;
      Is_JALR_E   <= Is_JALR_D;
      Is_Load_E   <= Is_Load_D;
    end
  end

endmodule


//14 EX_MEM_reg
module EX_MEM_reg(
    input clk, rst_n,
    input [31:0] ALU_out_E, DataB_fwd_E, PC_Plus4_E,
    input [4:0]  addrD_E,
    input [1:0]  WBSel_E,
    input        RegWEn_E, MemRW_E,
    input [2:0]  funct3_E,
  
    output reg [31:0] ALU_out_M, DataB_M, PC_Plus4_M,
    output reg [4:0]  addrD_M,
    output reg [1:0]  WBSel_M,
    output reg        RegWEn_M, MemRW_M,
    output reg [2:0]  funct3_M
);

    always @(posedge clk or negedge rst_n) begin
        if (~rst_n) begin
            ALU_out_M  <= 32'b0;
            DataB_M    <= 32'b0;
            PC_Plus4_M <= 32'b0;
            addrD_M    <= 5'b0;
            WBSel_M    <= 2'b0;
            RegWEn_M   <= 1'b0;
            MemRW_M    <= 1'b0;
            funct3_M   <= 3'b0;
        end else begin
            ALU_out_M  <= ALU_out_E;
            DataB_M    <= DataB_fwd_E;
            PC_Plus4_M <= PC_Plus4_E;
            addrD_M    <= addrD_E;
            WBSel_M    <= WBSel_E;
            RegWEn_M   <= RegWEn_E;
            MemRW_M    <= MemRW_E;
            funct3_M   <= funct3_E;
        end
    end

endmodule


//15 MEM_WB_reg
module MEM_WB_reg(
  input clk, rst_n,
  input [31:0] ALU_out_M, DataR_M, PC_Plus4_M,
  input [4:0]  addrD_M,
  input [1:0]  WBSel_M,
  input        RegWEn_M,

  output reg [31:0] ALU_out_W, DataR_W, PC_Plus4_W,
  output reg [4:0]  addrD_W,
  output reg [1:0]  WBSel_W,
  output reg        RegWEn_W
);

  always @(posedge clk or negedge rst_n) begin
    if (~rst_n) begin
      ALU_out_W  <= 32'b0;
      DataR_W    <= 32'b0;
      PC_Plus4_W <= 32'b0;
      addrD_W    <= 5'b0;
      WBSel_W    <= 2'b0;
      RegWEn_W   <= 1'b0;
    end else begin
      ALU_out_W  <= ALU_out_M;
      DataR_W    <= DataR_M;
      PC_Plus4_W <= PC_Plus4_M;
      addrD_W    <= addrD_M;
      WBSel_W    <= WBSel_M;
      RegWEn_W   <= RegWEn_M;
    end
  end

endmodule

//16 Forwarding_unit
module forward_unit (
  input  wire [4:0] addrA_E, addrB_E,
  input  wire [4:0] addrD_M, addrD_W,
  input  wire       RegWEn_M, RegWEn_W,
  output reg  [1:0] fwdA, fwdB
);

  always @(*) begin
    fwdA = 2'b00;
    if (RegWEn_M && (addrD_M != 5'b0) && (addrD_M == addrA_E)) begin
      fwdA = 2'b10;
    end else if (RegWEn_W && (addrD_W != 5'b0) && (addrD_W == addrA_E)) begin
      fwdA = 2'b01;
    end

    fwdB = 2'b00;
    if (RegWEn_M && (addrD_M != 5'b0) && (addrD_M == addrB_E)) begin
      fwdB = 2'b10;
    end else if (RegWEn_W && (addrD_W != 5'b0) && (addrD_W == addrB_E)) begin
      fwdB = 2'b01;
    end
  end

endmodule

//17 Hazard_detect
module hazard_detect (
  input  wire       Is_Load_E,
  input  wire [4:0] addrD_E,
  input  wire [4:0] addrA_D, addrB_D,
  input  wire       UsesRs1_D, UsesRs2_D,
  output wire       stall_load
);

  assign stall_load = Is_Load_E && (addrD_E != 5'b0) &&
    ((UsesRs1_D && (addrD_E == addrA_D)) ||
     (UsesRs2_D && (addrD_E == addrB_D)));

endmodule

//18 Branch_Resovle
module Branch_Resolve (
    input  wire       Is_Branch_E,
    input  wire       Is_Jump_E,
    input  wire [2:0] funct3_E,
    input  wire       BrEq_E,
    input  wire       BrLt_E,
    output reg        PCSel_E
);

    always @(*) begin
        if (Is_Jump_E) begin
            PCSel_E = 1'b1;
        end else if (Is_Branch_E) begin
            if (funct3_E[2]) begin
                PCSel_E = BrLt_E ? ~funct3_E[0] : funct3_E[0];
            end else begin
                PCSel_E = BrEq_E ? ~funct3_E[0] : funct3_E[0];
            end
        end else begin
            PCSel_E = 1'b0;
        end
    end

endmodule


