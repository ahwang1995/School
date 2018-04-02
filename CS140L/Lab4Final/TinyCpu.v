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
 output [7:0] Result
);
wire [7:0] data,RegA,RegB,dataB,RegAdd,RegRight,RegAnd,RegOr,RegXor,RegNand,RegComp;
wire [3:0] instruction,S;
wire Clear,EnableA,EnableB,EnableOut;
BusSplit BusSplit(In,data,instruction);
InstructionDecoder InstructionDecoder(instruction,Clear,EnableA,EnableB,EnableOut,
													S[0],S[1],S[2],S[3]);
Register8Bit RegisterA(data,Clk,Clear,EnableA,RegA);
Mux2to1 Mux2to1(data,Result,S[0],dataB);
Register8Bit RegisterB(dataB,Clk,Clear,EnableB,RegB);
ALU ALU(RegA,RegB,instruction,RegAdd,RegRight,RegAnd,RegOr,RegXor,RegNand,RegComp);
Mux8to1 Mux8to1(RegAdd,RegLeft,RegRight,RegAnd,RegOr,RegXor,RegNand,RegComp,S[3:1]);
Register8Bit RegisterOut(Y,Clk,Clear,EnableOut,Result);

endmodule
