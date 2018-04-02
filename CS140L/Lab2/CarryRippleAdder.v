`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    10:28:22 10/26/2015 
// Design Name: 
// Module Name:    CarryRippleAdder 
// Project Name: 
// Target Devices: 
// Tool versions: 
// Description: 
//
// Dependencies: 
//
// Revision: 
// Revision 0.01 - File Created
// Additional Comments: 
//
//////////////////////////////////////////////////////////////////////////////////
module CarryRippleAdder(input[3:0] A,B,input Cin,
    output[3:0] S,output Cout,OF);
FullAdder FA0(.A(A[0]),.B((B[0])^Cin),.Cin(Cin));
FullAdder FA1(.A(A[1]),.B((B[1])^Cin),.Cin(FA0.Cout)); 
FullAdder FA2(.A(A[2]),.B((B[2])^Cin),.Cin(FA1.Cout));
FullAdder FA3(.A(A[3]),.B((B[3])^Cin),.Cin(FA2.Cout));
assign S = {FA3.S,FA2.S,FA1.S,FA0.S};
assign Cout = FA3.Cout;
assign OF = FA2.Cout^FA3.Cout;
endmodule
