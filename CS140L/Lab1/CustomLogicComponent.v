`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    17:05:14 10/13/2015 
// Design Name: 
// Module Name:    CustomLogicComponent 
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
module CustomLogicComponent(input A,B,C,output F);


assign F = (!A|B|!C)&(!A|!B|C)&(A|!B|!C);


endmodule
