`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    23:01:52 11/30/2015 
// Design Name: 
// Module Name:    Alu 
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
module Alu(input [7:0] InA,InB,output [7:0] RegAdd,RegLeft,
RegRight,RegAnd,RegOr,RegXor,RegNand,RegComp );
Adder Adder(InA,InB,RegAdd);
ShiftLeft ShiftLeft(InA,RegLeft);
ShiftRight ShiftRight(InA,RegRight);
assign RegAnd = InA & InB;
assign RegOr = InA | InB;
assign RegXor = InA^InB;
assign RegNand = ~(InA&InB);
Comparator Comparator(InA,InB,RegComp);

endmodule
