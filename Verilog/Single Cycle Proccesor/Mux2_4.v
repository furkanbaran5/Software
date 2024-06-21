module Mux2_4 (a0,a1,a2,a3,s,c);

    input [31:0]a0,a1,a2,a3;
    input [1:0]s;
    output [31:0]c;

    assign c =  (s == 2'b00) ? a0 : 
                (s == 2'b01) ? a1 : 
                (s == 2'b10) ? a2 :
                               a3 ;
    
endmodule