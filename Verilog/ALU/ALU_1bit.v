module ALU_1bit (
    input wire A,
    input wire B,
    input wire [2:0] ALUControl,
    output wire result,
    output wire zero
);

// ALU işlevlerini uygula
assign result = (ALUControl == 3'b000) ? (A + B) :
                (ALUControl == 3'b001) ? (A - B) :
                (ALUControl == 3'b010) ? (A & B) :
                (ALUControl == 3'b011) ? (A ^ B) :
                (ALUControl == 3'b101) ? (A < B) : 0;

// Sonucun sıfır olup olmadığını kontrol et
assign zero = (result == 0) ? 1'b1 : 1'b0;

endmodule