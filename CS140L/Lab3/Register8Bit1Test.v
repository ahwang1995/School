`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   13:35:51 11/19/2015
// Design Name:   Register8Bit1C
// Module Name:   C:/Users/Andrew/Desktop/School/Computer Science/CS140L/Lab3/Register8Bit1Test.v
// Project Name:  Lab3
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: Register8Bit1C
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module Register8Bit1Test;

	// Inputs
	reg P1;
	reg P2;
	reg P3;
	reg P4;
	reg P5;
	reg P6;
	reg P7;
	reg P8;
	reg reset;
	reg Clk;

	// Outputs
	wire Q1;
	wire Q2;
	wire Q3;
	wire Q4;
	wire Q5;
	wire Q6;
	wire Q7;
	wire Q8;

	// Instantiate the Unit Under Test (UUT)
	Register8Bit1C uut (
		.P1(P1), 
		.P2(P2), 
		.P3(P3), 
		.P4(P4), 
		.P5(P5), 
		.P6(P6), 
		.P7(P7), 
		.P8(P8), 
		.reset(reset), 
		.Clk(Clk), 
		.Q1(Q1), 
		.Q2(Q2), 
		.Q3(Q3), 
		.Q4(Q4), 
		.Q5(Q5), 
		.Q6(Q6), 
		.Q7(Q7), 
		.Q8(Q8)
	);

	initial begin
		// Initialize Inputs
		P1 = 0;
		P2 = 0;
		P3 = 0;
		P4 = 0;
		P5 = 0;
		P6 = 0;
		P7 = 0;
		P8 = 0;
		reset = 0;
		Clk = 0;
		end
		always begin
		#200 Clk= ~Clk;
		#25 P1 = ~P1;
		#35 P2 = ~P2;
		#45 P3 = ~P3;
		#55 P4 = ~P4;
		#65 P5 = ~P5;
		#75 P6 = ~P6;
		#85 P7 = ~P7;
		#95 P8 = ~P8;
		#200 reset = ~reset;
		// Wait 100 ns for global reset to finish
		
		// Add stimulus here

	end
      
endmodule

