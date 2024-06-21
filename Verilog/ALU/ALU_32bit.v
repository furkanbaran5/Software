module ALU_32bit (
    input wire [31:0] A,
    input wire [31:0] B,
    input wire [2:0] ALUControl,
    output wire [31:0] result,
    output wire zero
);

wire [31:0] result_bits[0:7];
wire zero_bits[0:7];

// 4-bitlik ALU modülünü çağır
genvar i;
generate
    for (i = 0; i < 8; i = i + 1) begin : alu_loop
        ALU_4bit ALU_inst (
            .A(A[i*4 +: 4]),
            .B(B[i*4 +: 4]),
            .ALUControl(ALUControl),
            .result(result_bits[i]),
            .zero(zero_bits[i])
        );
    end
endgenerate

// Sonuçları birleştir
assign result = {result_bits[7], result_bits[6], result_bits[5], result_bits[4], 
                 result_bits[3], result_bits[2], result_bits[1], result_bits[0]};
assign zero = (zero_bits[7] & zero_bits[6] & zero_bits[5] & zero_bits[4] &
               zero_bits[3] & zero_bits[2] & zero_bits[1] & zero_bits[0]);

endmodule