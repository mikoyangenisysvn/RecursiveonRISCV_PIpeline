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
