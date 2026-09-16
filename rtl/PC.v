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
