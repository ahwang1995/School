`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    18:33:30 11/30/2015 
// Design Name: 
// Module Name:    BusSplit 
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
module BusSplit(input [11:0] In, output [7:0] data, output [3:0] instruction);
 assign data = In[7:0];
 assign instruction = In[11:8];

endmodule
