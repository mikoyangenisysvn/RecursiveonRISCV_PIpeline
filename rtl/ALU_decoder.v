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
