`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   23:45:21 10/25/2015
// Design Name:   Mux4Bit2x1
// Module Name:   C:/Users/Andrew/Desktop/School/Computer Science/CS140L/Lab2/Mux4Bit2x1Test.v
// Project Name:  Lab2
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: Mux4Bit2x1
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module Mux4Bit2x1Test;

	// Inputs
	reg [3:0] A;
	reg [3:0] B;
	reg [1:0] Sel;

	// Outputs
	wire [3:0] Z;

	// Instantiate the Unit Under Test (UUT)
	Mux4Bit2x1 uut (
		.A(A), 
		.B(B), 
		.Sel(Sel), 
		.Z(Z)
	);

	initial begin
		// Initialize Inputs
		A = 0011;
		B = 0101;
		Sel = 0;

		// Wait 100 ns for global reset to finish
		#100;
        
		// Add stimulus here
		A = 0011;
		B = 1010;
		Sel = 1;
		
		#100;
		
		

	end
      
endmodule

