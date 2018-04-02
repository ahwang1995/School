`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    12:33:30 12/01/2015 
// Design Name: 
// Module Name:    Mux2to1 
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
module Mux2to1(input [7:0] datain,Outin,input Select0,output reg [7:0] Breg );
 always@(Select0 or datain or Outin)
 begin
 if(Select0 == 0)
 Breg <= datain;
 else if(Select0 == 1)
 Breg <= Outin;
 end
endmodule
