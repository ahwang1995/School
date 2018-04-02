`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    17:58:32 11/19/2015 
// Design Name: 
// Module Name:    ShiftRegister1D 
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
module ShiftRegister1D(input Clk,D,output reg[7:0] Q);
wire[7:0] QF;
DFlipFlop1B FF1(Clk,D,QF[0]);
DFlipFlop1B FF2(Clk,QF[0],QF[1]);
DFlipFlop1B FF3(Clk,QF[1],QF[2]);
DFlipFlop1B FF4(Clk,QF[2],QF[3]);
DFlipFlop1B FF5(Clk,QF[3],QF[4]);
DFlipFlop1B FF6(Clk,QF[4],QF[5]);
DFlipFlop1B FF7(Clk,QF[5],QF[6]);
DFlipFlop1B FF8(Clk,QF[6],QF[7]);
always@(posedge Clk)
begin
	Q <= QF;
end
endmodule
