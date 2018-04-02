`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    20:11:49 10/25/2015 
// Design Name: 
// Module Name:    Mux4x1 
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
module Mux4x1(input A,B,C,D,Sel1,Sel2,output Z);
Mux2x1 muxAB(.A(A),.B(B),.Sel(Sel1));
Mux2x1 muxCD(.A(C),.B(D),.Sel(Sel1));
Mux2x1 muxZ(.A(muxAB.Z),.B(muxCD.Z),.Sel(Sel2));
assign Z = muxZ.Z;

endmodule
