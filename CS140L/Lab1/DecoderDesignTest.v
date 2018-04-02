`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   21:19:46 10/13/2015
// Design Name:   DecoderDesign
// Module Name:   C:/Users/Andrew/Desktop/School/Computer Science/CS140L/Lab1/DecoderDesignTest.v
// Project Name:  Lab1
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: DecoderDesign
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module DecoderDesignTest;

	// Inputs
	reg I;
	reg J;
	reg K;

	// Outputs
	wire P;
	wire Q;
	wire R;
	wire S;
	wire T;
	wire U;
	wire V;
	wire W;

	// Instantiate the Unit Under Test (UUT)
	DecoderDesign uut (
		.I(I), 
		.J(J), 
		.K(K), 
		.P(P), 
		.Q(Q), 
		.R(R), 
		.S(S), 
		.T(T), 
		.U(U), 
		.V(V), 
		.W(W)
	);

	initial begin
		// Initialize Inputs
		I = 0;
		J = 0;
		K = 0;

		// Wait 100 ns for global reset to finish
		#100;
        
		// Add stimulus here
		
		I = 0;
		J = 0;
		K = 1;
		
		#100;
		
		I = 0;
		J = 1;
		K = 0;
		
		#100;
		
		I = 0;
		J = 1;
		K = 1;
		
		#100;
		
		I = 1;
		J = 0;
		K = 0;
		
		#100;
		
		I = 1;
		J = 0;
		K = 1;
		
		#100;
		
		I = 1;
		J = 1;
		K = 0;
		
		#100;
		
		I = 1;
		J = 1;
		K = 1;
	end
      
endmodule

