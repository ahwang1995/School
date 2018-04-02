`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   16:34:33 11/20/2015
// Design Name:   ShiftRegister1D
// Module Name:   C:/Users/Andrew/Desktop/School/Computer Science/CS140L/Lab3/ShiftRegister1DTest.v
// Project Name:  Lab3
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: ShiftRegister1D
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module ShiftRegister1DTest;

	// Inputs
	reg Clk;
	reg D;

	// Outputs
	wire [7:0] Q;

	// Instantiate the Unit Under Test (UUT)
	ShiftRegister1D uut (
		.Clk(Clk), 
		.D(D), 
		.Q(Q)
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
		#1500
		D = 1;

		// Wait 100 ns for global reset to finish
		end
		always begin
		#17 Clk = ~Clk;
        
		// Add stimulus here

	end
      
endmodule

