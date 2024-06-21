module cache_and_ram(
    input [31:0] address,
    input [31:0] data,
    input mode,  // 1 ise yaz, 0 ise oku
    input clk,
    output reg [31:0] out
);

    // Cache parametreleri
    parameter CACHE_SIZE = 256;
    parameter BLOCK_SIZE = 4;
    parameter NUM_BLOCKS = CACHE_SIZE / BLOCK_SIZE;
    
    // Bellek
    reg [31:0] ram [0:4095];
    
    // Cache
    reg [31:0] cache_data [0:NUM_BLOCKS-1];
    reg [31:0] cache_tags [0:NUM_BLOCKS-1];
    reg cache_valid [0:NUM_BLOCKS-1];
    
    integer i;
    
    initial begin
        for (i = 0; i < NUM_BLOCKS; i = i + 1) begin
            cache_valid[i] = 1'b0;
            cache_tags[i] = 32'b0;
            cache_data[i] = 32'b0;
        end
    end

    // tag ve index'i addresten çıkarma
    wire [23:0] tag = address[31:8];
    wire [7:0] index = address[7:2];
    wire [1:0] block_offset = address[1:0];

    always @(posedge clk) begin
        if (mode == 1'b1) begin // yazma
            if (cache_valid[index] && cache_tags[index] == tag) begin
                // Cache hit ve yazma
                cache_data[index] <= data;
                ram[address[11:2]] <= data; // Belleğe yazma
                $display("Write Hit: Address %d, Data %d", address, data);
            end else begin
                // Cache miss ve yazma
                cache_data[index] <= data;
                cache_tags[index] <= tag;
                cache_valid[index] <= 1'b1;
                ram[address[11:2]] <= data; // tahsis etme
                $display("Write Miss: Address %d, Data %d", address, data);
            end
        end else begin // okuma
            if (cache_valid[index] && cache_tags[index] == tag) begin
                // Cache hit ve okuma
                out <= cache_data[index];
                $display("Read Hit: Address %d, Data %d", address, cache_data[index]);
            end else begin
                // Cache miss okuma
                cache_data[index] <= ram[address[11:2]];
                cache_tags[index] <= tag;
                cache_valid[index] <= 1'b1;
                out <= ram[address[11:2]];
                $display("Read Miss: Address %d, Data %d", address, ram[address[11:2]]);
            end
        end
    end
endmodule