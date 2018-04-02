`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    23:41:12 10/25/2015 
// Design Name: 
// Module Name:    Mux4Bit2x1 
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
module Mux4Bit2x1(input[3:0] A,B,input Sel,output[3:0] Z);
reg[3:0]Z;
always@(A | B | Sel)
	case(Sel)
	0:Z=B;
	1:Z=A;
	endcase
endmodule
