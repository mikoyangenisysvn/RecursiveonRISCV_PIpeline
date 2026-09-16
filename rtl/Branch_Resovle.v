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
