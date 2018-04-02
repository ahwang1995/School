`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    22:34:34 11/30/2015 
// Design Name: 
// Module Name:    TinyCpu 
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
module TinyCpu(
 input [11:0] In,
 input Clk,
 output [7:0] Result,RegA,RegB
);
wire [7:0] data,RegAwire,RegBwire,dataB,RegAdd,RegLeft,RegRight,RegAnd,RegOr,RegXor,RegNand,RegComp,muxOut;
wire [3:0] instruction,S;
wire Clear,EnableA,EnableB,EnableOut;
BusSplit BusSplit(In,data,instruction);
InstructionDecoder InstructionDecoder(instruction,Clear,EnableA,EnableB,EnableOut,
													S[0],S[1],S[2],S[3]);
Register8bit RegisterA(Clk,Clear,EnableA,data,RegAwire);
Mux2to1 Mux2to1(data,Result,S[0],dataB);
Register8bit RegisterB(Clk,Clear,EnableB,dataB,RegBwire);
Alu ALU1(RegAwire,RegBwire,RegAdd,RegLeft,RegRight,RegAnd,RegOr,RegXor,RegNand,RegComp);
Mux8to1 Mux8to1(RegAdd,RegLeft,RegRight,RegAnd,RegOr,RegXor,RegNand,RegComp,S[3:1],muxOut);
Register8bit RegisterOut(Clk,Clear,EnableOut,muxOut,Result);
assign RegA = RegAwire;
assign RegB = RegBwire;

endmodule
