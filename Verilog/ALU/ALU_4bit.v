module ALU_4bit (
    input wire [3:0] A,
    input wire [3:0] B,
    input wire [2:0] ALUControl,
    output wire [3:0] result,
    output wire zero
);

wire [3:0] result_bits[0:3];
wire zero_bits[0:3];

// 1-bitlik ALU modülünü çağır
genvar i;
generate
    for (i = 0; i < 4; i = i + 1) begin : alu_loop
        ALU_1bit ALU_inst (
            .A(A[i]),
            .B(B[i]),
            .ALUControl(ALUControl),
            .result(result_bits[i]),
            .zero(zero_bits[i])
        );
    end
endgenerate

// Sonuçları birleştir
assign result = {result_bits[3], result_bits[2], result_bits[1], result_bits[0]};
assign zero = (zero_bits[3] & zero_bits[2] & zero_bits[1] & zero_bits[0]);

endmodule