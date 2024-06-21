
module Data_Memory(clk,rst,WE,WD,A,RD);

    input clk,rst,WE;
    input [31:0]A,WD;
    output [31:0]RD;

    reg [31:0] mem [1023:0];

    always @ (posedge clk)
    begin
        if(WE)
            mem[A] <= WD;
    end

    assign RD = (~rst) ? 32'd0 : mem[A];

    initial begin
        //ARR Dizisi
        mem[0] = 32'd3;     mem[1] = 32'd7;     mem[2] = 32'd2;     mem[3] = 32'd6;     mem[4] = 32'd5;     mem[5] = 32'd4;     mem[6] = 32'd1;     mem[7] = 32'd1000;  mem[8] = 32'd999;   mem[9] = 32'd25;
        mem[10] = 32'd90;   mem[11] = 32'd100;  mem[12] = 32'd30;   mem[13] = 32'd20;   mem[14] = 32'd10;   mem[15] = 32'd200;  mem[16] = 32'd3300; mem[17] = 32'd250;  mem[18] = 32'd12;   mem[19] = 32'd75;
        //COUNT Dizisi
        mem[20] = 32'd17;   mem[21] = 32'd13;   mem[22] = 32'd18;   mem[23] = 32'd14;   mem[24] = 32'd15;   mem[25] = 32'd16;   mem[26] = 32'd19;   mem[27] = 32'd1;    mem[28] = 32'd2;    mem[29] = 32'd9;
        mem[30] = 32'd6;    mem[31] = 32'd5;    mem[32] = 32'd8;    mem[33] = 32'd10;   mem[34] = 32'd12;   mem[35] = 32'd4;    mem[36] = 32'd0;    mem[37] = 32'd3;    mem[38] = 32'd11;   mem[39] = 32'd7;
    end


endmodule