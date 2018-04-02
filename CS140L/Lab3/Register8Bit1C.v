`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    13:10:11 11/19/2015 
// Design Name: 
// Module Name:    Register8Bit1C 
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
module Register8Bit1C(input[7:0] P,input reset,Clk,output[7:0] Q);
reg[7:0] Q;
DFlipFlop1B FF1(Clk,P[0],Q[0]);
DFlipFlop1B FF2(Clk,P[1],Q[1]);
DFlipFlop1B FF3(Clk,P[2],Q[2]);
DFlipFlop1B FF4(Clk,P[3],Q[3]);
DFlipFlop1B FF5(Clk,P[4],Q[4]);
DFlipFlop1B FF6(Clk,P[5],Q[5]);
DFlipFlop1B FF7(Clk,P[6],Q[6]);
DFlipFlop1B FF8(Clk,P[7],Q[7]);
always@(posedge Clk)
//begin
	if(reset)
		Q = 0;
//end
endmodule
