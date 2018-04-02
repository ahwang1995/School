`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   17:40:12 11/19/2015
// Design Name:   Register1C
// Module Name:   C:/Users/Andrew/Desktop/School/Computer Science/CS140L/Lab3/Register1CTest.v
// Project Name:  Lab3
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: Register1C
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module Register1CTest;

	// Inputs
	reg [7:0] P;
	reg reset;
	reg Clk;

	// Outputs
	wire [7:0] Q;

	// Instantiate the Unit Under Test (UUT)
	Register1C uut (
		.P(P), 
		.reset(reset), 
		.Clk(Clk), 
		.Q(Q)
	);

	initial begin
		// Initialize Inputs
		P = 0;
		reset = 0;
		Clk = 0;
		#623
		P = 1010101;
		#1000
		P = 0101010;
		#1200
		reset = 1;
		#1500
		P = 1110000;
		reset = 0;

		// Wait 100 ns for global reset to finish
		end
		always begin
		#17 Clk = ~Clk;
        
		// Add stimulus here

	end
      
endmodule

