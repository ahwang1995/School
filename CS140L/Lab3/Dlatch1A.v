`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    20:12:42 11/18/2015 
// Design Name: 
// Module Name:    Dlatch1A 
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
module Dlatch1A(input Clk,D,output Q,Qbar);
wire o1,o2;
//reg Q;
nand g1(o1,D,Clk);
nand g2(o2,Clk,o1);
nand g3(Q,o1,Qbar);
nand g4(Qbar,o2,Q);

endmodule
