
`include "ALU_Decoder.v"
`include "Main_Decoder.v"

module Control_Unit_Top(PCSrc,Op,RegWrite,ImmSrc,ALUSrc,MemWrite,zero,ResultSrc,funct3,funct7,ALUControl);

    input [6:0]Op;
    input [2:0]funct3;
    input zero,funct7;
    output PCSrc,RegWrite,ALUSrc,MemWrite;
    output [1:0]ImmSrc,ResultSrc;
    output [2:0]ALUControl;
    wire Branch,Jump,x;
    wire [1:0]ALUOp;

    Main_Decoder Main_Decoder(
        .Op(Op),
        .RegWrite(RegWrite),
        .Jump(Jump),
        .ImmSrc(ImmSrc),
        .MemWrite(MemWrite),
        .ResultSrc(ResultSrc),
        .Branch(Branch),
        .ALUSrc(ALUSrc),
        .ALUOp(ALUOp)
    );
    assign x = zero & Branch;
    assign PCSrc = x | Jump ;

    ALU_Decoder ALU_Decoder(
        .ALUOp(ALUOp),
        .funct3(funct3),
        .funct7(funct7),
        .op(Op),
        .ALUControl(ALUControl)
    );


endmodule