`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   18:59:30 10/13/2015
// Design Name:   CustomLogicComponent
// Module Name:   C:/Users/Andrew/Desktop/School/Computer Science/CS140L/Lab1/CustomLogicComponentTest.v
// Project Name:  Lab1
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: CustomLogicComponent
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module CustomLogicComponentTest;

	// Inputs
	reg A;
	reg B;
	reg C;

	// Outputs
	wire F;

	// Instantiate the Unit Under Test (UUT)
	CustomLogicComponent uut (
		.A(A), 
		.B(B), 
		.C(C), 
		.F(F)
	);

	initial begin
		// Initialize Inputs
		A = 0;
		B = 0;
		C = 0;

		// Wait 100 ns for global reset to finish
		#100;
		
		A = 0;
		B = 0;
		C = 1;
		
		#100;
		
		A = 0;
		B = 1;
		C = 0;
		
		#100;
		
		A = 0;
		B = 1;
		C = 1;
		
		#100;
		
		A = 1;
		B = 0;
		C = 0;
		
		#100;
		
		A = 1;
		B = 0;
		C = 1;
		
		#100;
		
		A = 1;
		B = 1;
		C = 0;
		
		#100;
		
		A = 1;
		B = 1;
		C = 1;
		
        
		// Add stimulus here

	end
      
endmodule

