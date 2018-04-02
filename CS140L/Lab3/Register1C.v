`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    14:03:43 11/19/2015 
// Design Name: 
// Module Name:    Register1C 
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
module Register1C(input[7:0] P,input reset,Clk,output reg[7:0] Q);
wire[7:0] QF;
DFlipFlop1B FF1(Clk,P[0],QF[0]);
DFlipFlop1B FF2(Clk,P[1],QF[1]);
DFlipFlop1B FF3(Clk,P[2],QF[2]);
DFlipFlop1B FF4(Clk,P[3],QF[3]);
DFlipFlop1B FF5(Clk,P[4],QF[4]);
DFlipFlop1B FF6(Clk,P[5],QF[5]);
DFlipFlop1B FF7(Clk,P[6],QF[6]);
DFlipFlop1B FF8(Clk,P[7],QF[7]);
always@(posedge Clk)
begin
	if(reset)
	Q <= 7'b0;
	else
	Q <= QF;
end
endmodule
