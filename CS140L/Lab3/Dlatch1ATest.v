`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   20:55:03 11/18/2015
// Design Name:   Dlatch1A
// Module Name:   C:/Users/Andrew/Desktop/School/Computer Science/CS140L/Lab3/Dlatch1ATest.v
// Project Name:  Lab3
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: Dlatch1A
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module Dlatch1ATest;

	// Inputs
	reg Clk;
	reg D;

	// Outputs
	wire Q;
	wire Qbar;

	// Instantiate the Unit Under Test (UUT)
	Dlatch1A uut (
		.Clk(Clk), 
		.D(D), 
		.Q(Q), 
		.Qbar(Qbar)
	);

	initial begin
		// Initialize Inputs
		Clk = 0;
		D = 1;
		end
		always begin
		#17 Clk = ~Clk;
		#68 D = ~D;
		// Wait 100 ns for global reset to finish
        
		// Add stimulus here

	end
      
endmodule

