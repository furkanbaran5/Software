`include "cache_and_ram.v"

module testbench;

reg [31:0] address, data;
reg mode, clk;
wire [31:0] out;

cache_and_ram tb(
    .address(address),
    .data(data),
    .mode(mode),
    .clk(clk),
    .out(out)
);

// GTKWave için dump ile vcd oluşturma
initial begin
    $dumpfile("testbench.vcd");
    $dumpvars(0, testbench);
end

initial begin
    clk = 1'b1;
    
    // İlk yazma işlemleri
    address = 32'b00000000000000000000000000000000;          // 0
    data = 32'b00000000000000000011100011000000;             // 14528
    mode = 1'b1;
    #50;
    $display("address = %d veri = %d mod = %d cikti = %d", address % 4096, data, mode, out);
    
    address = 32'b10100111111001011111101111011100;          // 2816867292 % size = 3036
    data = 32'b00000000000010000000100001010101;             // 526421
    mode = 1'b1;
    #50;
    $display("address = %d veri = %d mod = %d cikti = %d", address % 4096, data, mode, out);
    
    address = 32'b00000000000011110100011111010001;          // 1001425 % size = 2001
    data = 32'b00000001100000110001101100010110;             // 25369366
    mode = 1'b1;
    #50;
    $display("address = %d veri = %d mod = %d cikti = %d", address % 4096, data, mode, out);
    
    address = 32'b10100111111001011111101111011100;          // 2816867292 % size = 3036
    data = 32'b00000000000000000011100011000000;             // 14528
    mode = 1'b1;
    #50;
    $display("address = %d veri = %d mod = %d cikti = %d", address % 4096, data, mode, out);
    
    address = 32'b00000000000011110100011111010001;          // 1001425 % size = 2001
    data = 32'b00000000000000000011100011000000;             // 14528
    mode = 1'b1;
    #50;
    $display("address = %d veri = %d mod = %d cikti = %d", address % 4096, data, mode, out);
    
    // Okuma işlemleri
    address = 32'b00000000000011110100011111010001;          // 1001425 % size = 2001
    data = 32'b00000000000000000000000000000000;             // 0
    mode = 1'b0;
    #50;
    $display("address = %d veri = %d mod = %d cikti = %d", address % 4096, data, mode, out);
    
    address = 32'b10100111111001011111101111011100;          // 2816867292 % size = 3036
    data = 32'b00000000000000000000000000000000;             // 0
    mode = 1'b0;
    #50;
    $display("address = %d veri = %d mod = %d cikti = %d", address % 4096, data, mode, out);
    
    address = 32'b00000000000000000000000000000000;          // 0
    data = 32'b00000000000000000011100011000000;             // 14528
    mode = 1'b0;
    #50;
    $display("address = %d veri = %d mod = %d cikti = %d", address % 4096, data, mode, out);
    
    // Simülasyonu durdur
    $finish;
end

always #25 clk = ~clk;

endmodule