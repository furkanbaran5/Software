
module Main_Decoder(Op,RegWrite,ImmSrc,ALUSrc,MemWrite,ResultSrc,Jump,Branch,ALUOp);
    input [6:0]Op;
    output RegWrite,ALUSrc,Jump,MemWrite,Branch;
    output [1:0]ImmSrc,ResultSrc,ALUOp;

    assign RegWrite = (Op == 7'b0000011 | Op == 7'b0110011 | Op == 7'b0010011 | Op == 7'b1101111) ? 1'b1 : 1'b0 ;
                                                              
    assign ImmSrc = (Op == 7'b0100011) ? 2'b01 : 
                    (Op == 7'b1100011) ? 2'b10 : 
                    (Op == 7'b1101111) ? 2'b11 :
                                         2'b00 ;
    assign Jump = (Op == 7'b1101111) ? 1'b1: 
                                        1'b0;
    assign ALUSrc = (Op == 7'b0110011 | Op == 7'b1100011) ? 1'b0 :
                                                            1'b1 ;
    assign MemWrite = (Op == 7'b0100011) ? 1'b1 :
                                           1'b0 ;
    assign ResultSrc = (Op == 7'b0000011) ? 2'b01 :
                        (Op == 7'b1101111) ? 2'b10 :
                                            2'b00 ;

    assign Branch = (Op == 7'b1100011) ? 1'b1 :
                                         1'b0 ;
    assign ALUOp = (Op == 7'b0110011) ? 2'b10 :
                   (Op == 7'b1100011) ? 2'b01 :
                   (Op == 7'b0010011) ? 2'b10 :
                                        2'b00 ;
   


endmodule