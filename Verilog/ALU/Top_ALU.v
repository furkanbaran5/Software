module Top_ALU (
    input wire [31:0] A,
    input wire [31:0] B,
    input wire [2:0] ALUControl,
    output wire [31:0] result,
    output wire zero
);

// 32-bitlik ALU modülünü çağır
ALU_32bit ALU_inst (
    .A(A),
    .B(B),
    .ALUControl(ALUControl),
    .result(result),
    .zero(zero)
);

endmodule