`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    21:15:41 10/13/2015 
// Design Name: 
// Module Name:    DecoderDesign 
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
module DecoderDesign(input I,J,K,output P,Q,R,S,T,U,V,W);

assign P = I&J&K;
assign Q = I&J&!K;
assign R = I&!J&K;
assign S = I&!J&!K;
assign T = !I&J&K;
assign U = !I&J&!K;
assign V = !I&!J&K;
assign W = !I&!J&!K;
endmodule
