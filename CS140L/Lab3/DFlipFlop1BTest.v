`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   22:44:44 11/18/2015
// Design Name:   DFlipFlop1B
// Module Name:   C:/Users/Andrew/Desktop/School/Computer Science/CS140L/Lab3/DFlipFlop1BTest.v
// Project Name:  Lab3
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: DFlipFlop1B
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module DFlipFlop1BTest;

	// Inputs
	reg D;
	reg Clk;

	// Outputs
	wire Q;
	wire QL;

	// Instantiate the Unit Under Test (UUT)
	DFlipFlop1B uut (
		.D(D), 
		.Clk(Clk), 
		.Q(Q), 
		.QL(QL)
	);

	initial begin
		// Initialize Inputs
		D = 0;
		Clk = 0;
		#623
		D = 1;
		#1000
		D = 0;
		#1200
		D = 1;
		end
		always begin
		#17 Clk = ~Clk;
		// Wait 100 ns for global reset to finish
        
		// Add stimulus here

	end
      
endmodule

