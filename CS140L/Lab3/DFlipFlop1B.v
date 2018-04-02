`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    22:37:32 11/18/2015 
// Design Name: 
// Module Name:    DFlipFlop1B 
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
module DFlipFlop1B(input Clk, D,output Q,QL);
wire Q1,Q2;
Dlatch1A master(~Clk,D,Q1);
Dlatch1A slave(Clk,Q1,Q,Q2);
assign QL = Q2;


endmodule
