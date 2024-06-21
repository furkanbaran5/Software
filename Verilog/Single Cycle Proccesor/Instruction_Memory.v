
module Instruction_Memory(rst,A,RD);

  input rst;
  input [31:0]A;
  output [31:0]RD;

  reg [31:0] mem [1023:0];
  
  assign RD = (~rst) ? {32{1'b0}} : mem[A[31:2]];

  initial begin
    mem[0] = 32'h00500c63;
    mem[1] = 32'h00002083;
    mem[2] = 32'h01402103;
    mem[3] = 32'h02112423;
    mem[4] = 32'h00100013;
    mem[5] = 32'hfedff36f;
    mem[6] = 32'h01400013;
    mem[7] = 32'h02828293;
    mem[8] = 32'h00500863;
    mem[9] = 32'h00002083;
    mem[10] = 32'h00100013;
    mem[11] = 32'hff5ff36f;
  end
  /*
  start:
  
  loop1:
  beq x0,x5, continue1
  lw x1, 0(x0)
  lw x2, 20(x0),
  sw x1, 40(x2)
  addi x0 , x0 ,1
  jal x6,loop1
  continue1:
  
  addi x0,x0,20
  addi x5,x5,40

  loop2:
  beq x0,x5, continue2
  lw x1, (x0)
  addi x0 , x0 ,1
  jal x6,loop2
  continue2:*/


endmodule