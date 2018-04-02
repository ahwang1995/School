`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    20:40:41 11/19/2015 
// Design Name: 
// Module Name:    FSMdiv3 
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
module FSMdiv3(input Clk,reset,Datain,output REM );
reg[1:0] state,nextstate;

parameter S0 = 2'b00;
parameter S1 = 2'b01;
parameter S2 = 2'b10;

always@(posedge Clk,posedge reset)
	if(reset)
	state <=S0;
	else
	state <= nextstate;
	
	always@(state,Datain)
		case(state)
			S0:	if	(Datain)	nextstate = S1;
					else		nextstate = S0;
			S1:	if	(Datain)	nextstate = S0;
					else		nextstate = S2;
			S2:	if	(Datain)	nextstate = S2;
					else		nextstate = S1;
			default:			nextstate = S0;
		endcase
	assign REM = (state == S0);
		

endmodule
