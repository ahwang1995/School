`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   20:40:55 10/25/2015
// Design Name:   Mux4x1
// Module Name:   C:/Users/Andrew/Desktop/School/Computer Science/CS140L/Lab2/Mux4x1Test.v
// Project Name:  Lab2
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: Mux4x1
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module Mux4x1Test;

	// Inputs
	reg A;
	reg B;
	reg C;
	reg D;
	reg Sel1;
	reg Sel2;

	// Outputs
	wire Z;

	// Instantiate the Unit Under Test (UUT)
	Mux4x1 uut (
		.A(A), 
		.B(B), 
		.C(C), 
		.D(D), 
		.Sel1(Sel1), 
		.Sel2(Sel2), 
		.Z(Z)
	);

	initial begin
		// Initialize Inputs
		A = 0;
		B = 1;
		C = 0;
		D = 1;
		Sel1 = 0;
		Sel2 = 0;

		// Wait 100 ns for global reset to finish
		#100;
        
		// Add stimulus here
		A = 0;
		B = 1;
		C = 0;
		D = 1;
		Sel1 = 0;
		Sel2 = 1;
		
		#100;
		
		A = 0;
		B = 1;
		C = 0;
		D = 1;
		Sel1 = 1;
		Sel2 = 0;
		
		#100;
		
		A = 0;
		B = 1;
		C = 0;
		D = 1;
		Sel1 = 1;
		Sel2 = 1;
		
		#100;
		

	end
      
endmodule

