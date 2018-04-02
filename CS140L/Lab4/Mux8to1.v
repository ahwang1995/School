`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    18:51:54 11/30/2015 
// Design Name: 
// Module Name:    Mux8to1 
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
module Mux8to1(
 input [7:0] A,B,C,D,E,F,G,H,
 input [2:0] Sel,
 output reg [7:0] Y
 );
 always@(A or B or C or D or E or F or G or H or Sel)
 begin
 if((Sel[0] == 1'b0)&&(Sel[1] == 1'b0)&&(Sel[2] == 1'b0))
 Y <= A;
 else if((Sel[0] == 1'b0)&&(Sel[1] == 1'b0)&&(Sel[2] == 1'b1))
 Y <= B;
 else if((Sel[0] == 1'b0)&&(Sel[1] == 1'b1)&&(Sel[2] == 1'b0))
 Y <= C;
 else if((Sel[0] == 1'b0)&&(Sel[1] == 1'b1)&&(Sel[2] == 1'b1))
 Y <= D;
 else if((Sel[0] == 1'b1)&&(Sel[1] == 1'b0)&&(Sel[2] == 1'b0))
 Y <= E;
 else if((Sel[0] == 1'b1)&&(Sel[1] == 1'b0)&&(Sel[2] == 1'b1))
 Y <= F;
 else if((Sel[0] == 1'b1)&&(Sel[1] == 1'b1)&&(Sel[2] == 1'b0))
 Y <= G;
 else if((Sel[0] == 1'b1)&&(Sel[1] == 1'b1)&&(Sel[2] == 1'b1))
 Y <= H;
 end
 // if else block...

endmodule
