`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   19:45:44 10/25/2015
// Design Name:   Mux2x1
// Module Name:   C:/Users/Andrew/Desktop/School/Computer Science/CS140L/Lab2/Mux2x1Test.v
// Project Name:  Lab2
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: Mux2x1
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module Mux2x1Test;

	// Inputs
	reg A;
	reg B;
	reg Sel;

	// Outputs
	wire Z;

	// Instantiate the Unit Under Test (UUT)
	Mux2x1 uut (
		.A(A), 
		.B(B), 
		.Sel(Sel), 
		.Z(Z)
	);

	initial begin
		// Initialize Inputs
		A = 0;
		B = 0;
		Sel = 0;

		// Wait 100 ns for global reset to finish
		#100;
        
		// Add stimulus here
		A = 0;
		B = 0;
		Sel = 1;
		
		#100;
		
		A = 0;
		B = 1;
		Sel = 0;
		
		#100;
		
		A = 0;
		B = 1;
		Sel = 1;
		
		#100;
		
		A = 1;
		B = 0;
		Sel = 0;
		
		#100;
		
		A = 1;
		B = 0;
		Sel = 1;
		
		#100;
		
		A = 1;
		B = 1;
		Sel = 0;
		
		#100;
		
		A = 1;
		B = 1;
		Sel = 1;
		
		#100;
	end
      
endmodule

