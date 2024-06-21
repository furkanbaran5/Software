module cache();

parameter size = 64;		// cache boyutu
parameter index_size = 6;	// index boyutu


reg [31:0] cache [0:size - 1]; //cache'deki verileri register'a kaydeder
reg [11 - index_size:0] tag_array [0:size - 1]; // cache'deki tag'lar
reg valid_array [0:size - 1]; //0 - veri yok 1 - veri var

initial
	begin: initialization
		integer i;
		for (i = 0; i < size; i = i + 1)
		begin
			valid_array[i] = 1'b0;
			tag_array[i] = 6'b000000;
		end
	end

endmodule 
