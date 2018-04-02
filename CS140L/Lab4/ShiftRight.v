`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    19:06:16 11/30/2015 
// Design Name: 
// Module Name:    ShiftRight 
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
module ShiftRight(
input [7:0] A,
 output [7:0] Out2
 );
assign Out2 = A >> 1; 

endmodule
