`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    21:03:23 10/13/2015 
// Design Name: 
// Module Name:    EncoderDesign 
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
module EncoderDesign(input A,B,C,D,E,F,G,H,output X,Y,Z);

assign X = A|B|C|D;
assign Y = A|B|E|F;
assign Z = G|E|C|A;

endmodule
