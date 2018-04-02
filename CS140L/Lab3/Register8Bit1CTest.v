`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   13:53:42 11/19/2015
// Design Name:   Register8Bit1C
// Module Name:   C:/Users/Andrew/Desktop/School/Computer Science/CS140L/Lab3/Register8Bit1CTest.v
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

module Register8Bit1CTest;

	// Inputs
	reg P;

	// Instantiate the Unit Under Test (UUT)
	Register1C uut (
		.P(P)
	);

	initial begin
		// Initialize Inputs
		P = 0;
		end
		always begin
		#17 P = ~P;
		// Wait 100 ns for global reset to finish
        
		// Add stimulus here

	end
      
endmodule

