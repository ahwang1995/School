`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    14:08:29 10/26/2015 
// Design Name: 
// Module Name:    CarryLookAheadAdder 
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
module CarryLookAheadAdder(input[3:0] A,B,input Cin,output[3:0] S,
    output Cout,PG,GG);
wire[3:0] G,P,C;

assign G = A&B;
assign P = A^B;
assign C[0] = Cin;
assign C[1] = G[0] | (P[0]&C[0]);
assign C[2] = G[1] | (P[1]&G[0]) | (P[1]&P[0]&C[0]);
assign C[3] = G[2] | (P[2]&G[1]) | (P[2]&P[1]&G[0]) | (P[2]&P[1]&P[0]&C[0]);
assign Cout = G[3] | (P[3]&G[2]) | (P[3]&P[2]&G[1]) | (P[3]&P[2]&P[1]&G[0]) |
	(P[3]&P[2]&P[1]&P[0]&C[0]);
assign S = P^C;
assign PG = P[3]&P[2]&P[1]&P[0];
assign GG = G[3] | (P[3]&G[2]) | (P[3]&P[2]&G[1]) | (P[3]&P[2]&P[1]&G[0]);

endmodule
