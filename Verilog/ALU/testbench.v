`timescale 1ns / 1ns

module testbench;

    // Parametreler
    parameter WIDTH = 32;
    
    // Giriş sinyalleri
    reg [WIDTH-1:0] A, B;
    reg [2:0] ALUControl;
    
    // Çıkış sinyalleri
    wire [WIDTH-1:0] result;
    wire zero;
    
    // ALU modülü çağır
    Top_ALU uut (
        .A(A),
        .B(B),
        .ALUControl(ALUControl),
        .result(result),
        .zero(zero)
    );

    // Girişleri başlat
    initial begin
        // Test vektörlerini ayarla
        A = 32'hABCDEFFA;
        B = 32'h12345678;
        ALUControl = 3'b000; // Toplama
        
        #10;
        
        // Sonuçları kontrol et
        $display("ALU Control: %b", ALUControl);
        $display("A: %h", A);
        $display("B: %h", B);
        $display("Result: %h", result);
        $display("Zero Flag: %b", zero);
        
        // Diğer ALU kontrol sinyalleri ve giriş verileri için aynı işlemi tekrarlayın
        // Subtraction
        ALUControl = 3'b001; // Çıkarma
        #10;
        $display("ALU Control: %b", ALUControl);
        $display("A: %h", A);
        $display("B: %h", B);
        $display("Result: %h", result);
        $display("Zero Flag: %b", zero);
        
        // AND
        ALUControl = 3'b010; // AND
        #10;
        $display("ALU Control: %b", ALUControl);
        $display("A: %h", A);
        $display("B: %h", B);
        $display("Result: %h", result);
        $display("Zero Flag: %b", zero);
        
        // XOR
        ALUControl = 3'b011; // XOR
        #10;
        $display("ALU Control: %b", ALUControl);
        $display("A: %h", A);
        $display("B: %h", B);
        $display("Result: %h", result);
        $display("Zero Flag: %b", zero);
        
        // SLT
        ALUControl = 3'b101; // SLT
        #10;
        $display("ALU Control: %b", ALUControl);
        $display("A: %h", A);
        $display("B: %h", B);
        $display("Result: %h", result);
        $display("Zero Flag: %b", zero);
        
        // Test tamamlandı
        $finish;
    end

endmodule