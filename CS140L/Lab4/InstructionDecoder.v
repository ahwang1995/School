`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    17:45:36 11/30/2015 
// Design Name: 
// Module Name:    InstructionDecoder 
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

module InstructionDecoder(input [3:0] Instruction, output reg Clear,EnableA,EnableB,
EnableOut,S0,S1,S2,S3);
parameter clear = 4'b0000, Move1 = 4'b0001, Move2 = 4'b0010, Storeout = 4'b0011,
add = 4'b0100, Shiftleft = 4'b0101, Shiftright = 4'b0110, And = 4'b0111, Or = 4'b1000,
XOR = 4'b1001, NAND = 4'b1010, Compare = 4'b1011;
 always@(Instruction) begin
 if(Instruction == clear)
 begin
 Clear <= 1'b1;
 EnableA <= 1'b1;
 EnableB <= 1'b1;
 EnableOut <= 1'b1;
 S0 <= 1'bx;
 S1 <= 1'bx;
 S2 <= 1'bx;
 S3 <= 1'bx;
 end
 else if (Instruction == Move1)
 begin
 Clear <= 1'b0;
 EnableA <= 1'b1;
 EnableB <= 1'b0;
 EnableOut <= 1'b0;
 S0 <= 1'bx;
 S1 <= 1'bx;
 S2 <= 1'bx;
 S3 <= 1'bx;
 end
 else if (Instruction == Move2)
 begin
 Clear <= 1'b0;
 EnableA <= 1'b0;
 EnableB <= 1'b1;
 EnableOut <= 1'b0;
 S0 <= 1'b0;
 S1 <= 1'bx;
 S2 <= 1'bx;
 S3 <= 1'bx;
 end
 else if (Instruction == Storeout)
 begin
 Clear <= 1'b0;
 EnableA <= 1'b0;
 EnableB <= 1'b1;
 EnableOut <= 1'b0;
 S0 <= 1'b1;
 S1 <= 1'bx;
 S2 <= 1'bx;
 S3 <= 1'bx;
 end
 else if (Instruction == add)
 begin
 Clear <= 1'b0;
 EnableA <= 1'b0;
 EnableB <= 1'b0;
 EnableOut <= 1'b1;
 S0 <= 1'bx;
 S1 <= 1'b0;
 S2 <= 1'b0;
 S3 <= 1'b0;
 end
 else if (Instruction == Shiftleft)
 begin
 Clear <= 1'b0;
 EnableA <= 1'b0;
 EnableB <= 1'b0;
 EnableOut <= 1'b1;
 S0 <= 1'bx;
 S1 <= 1'b0;
 S2 <= 1'b0;
 S3 <= 1'b1;
 end
 else if (Instruction == Shiftright)
 begin
 Clear <= 1'b0;
 EnableA <= 1'b0;
 EnableB <= 1'b0;
 EnableOut <= 1'b1;
 S0 <= 1'bx;
 S1 <= 1'b0;
 S2 <= 1'b1;
 S3 <= 1'b0;
 end
 else if (Instruction == And)
 begin
 Clear <= 1'b0;
 EnableA <= 1'b0;
 EnableB <= 1'b0;
 EnableOut <= 1'b1;
 S0 <= 1'bx;
 S1 <= 1'b0;
 S2 <= 1'b1;
 S3 <= 1'b1;
 end
 else if (Instruction == Or)
 begin
 Clear <= 1'b0;
 EnableA <= 1'b0;
 EnableB <= 1'b0;
 EnableOut <= 1'b1;
 S0 <= 1'bx;
 S1 <= 1'b1;
 S2 <= 1'b0;
 S3 <= 1'b0;
 end
 else if (Instruction == XOR)
 begin
 Clear <= 1'b0;
 EnableA <= 1'b0;
 EnableB <= 1'b0;
 EnableOut <= 1'b1;
 S0 <= 1'bx;
 S1 <= 1'b1;
 S2 <= 1'b0;
 S3 <= 1'b1;
 end
 else if (Instruction == NAND)
 begin
 Clear <= 1'b0;
 EnableA <= 1'b0;
 EnableB <= 1'b0;
 EnableOut <= 1'b1;
 S0 <= 1'bx;
 S1 <= 1'b1;
 S2 <= 1'b1;
 S3 <= 1'b0;
 end
 else if (Instruction == Compare)
 begin
 Clear <= 1'b0;
 EnableA <= 1'b0;
 EnableB <= 1'b0;
 EnableOut <= 1'b1;
 S0 <= 1'bx;
 S1 <= 1'b1;
 S2 <= 1'b1;
 S3 <= 1'b1;
 end
 end
endmodule

