module ram();

parameter size = 4096; //bellekteki kelime boyutu

reg [31:0] ram [0:size-1]; //bellek için matris boyutu

endmodule
