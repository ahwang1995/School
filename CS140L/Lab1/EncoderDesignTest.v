`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   21:09:14 10/13/2015
// Design Name:   EncoderDesign
// Module Name:   C:/Users/Andrew/Desktop/School/Computer Science/CS140L/Lab1/EncoderDesignTest.v
// Project Name:  Lab1
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: EncoderDesign
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module EncoderDesignTest;

	// Inputs
	reg A;
	reg B;
	reg C;
	reg D;
	reg E;
	reg F;
	reg G;
	reg H;

	// Outputs
	wire X;
	wire Y;
	wire Z;

	// Instantiate the Unit Under Test (UUT)
	EncoderDesign uut (
		.A(A), 
		.B(B), 
		.C(C), 
		.D(D), 
		.E(E), 
		.F(F), 
		.G(G), 
		.H(H), 
		.X(X), 
		.Y(Y), 
		.Z(Z)
	);

	initial begin
		// Initialize Inputs
		A = 0;
		B = 0;
		C = 0;
		D = 0;
		E = 0;
		F = 0;
		G = 0;
		H = 0;

		// Wait 100 ns for global reset to finish
		#100;
        
		// Add stimulus here
		A = 1;
		B = 0;
		C = 0;
		D = 0;
		E = 0;
		F = 0;
		G = 0;
		H = 0;
		#100;
		
		A = 0;
		B = 1;
		C = 0;
		D = 0;
		E = 0;
		F = 0;
		G = 0;
		H = 0;
		#100;
		
		A = 0;
		B = 0;
		C = 1;
		D = 0;
		E = 0;
		F = 0;
		G = 0;
		H = 0;
		#100;
		
		A = 0;
		B = 0;
		C = 0;
		D = 1;
		E = 0;
		F = 0;
		G = 0;
		H = 0;
		#100;
		
		A = 0;
		B = 0;
		C = 0;
		D = 0;
		E = 1;
		F = 0;
		G = 0;
		H = 0;
		#100;
		
		A = 0;
		B = 0;
		C = 0;
		D = 0;
		E = 0;
		F = 1;
		G = 0;
		H = 0;
		#100;
		
		A = 0;
		B = 0;
		C = 0;
		D = 0;
		E = 0;
		F = 0;
		G = 1;
		H = 0;
		#100;
		
		A = 0;
		B = 0;
		C = 0;
		D = 0;
		E = 0;
		F = 0;
		G = 0;
		H = 1;
		#100;
		
	end
      
endmodule

