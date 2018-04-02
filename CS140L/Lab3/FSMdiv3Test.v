`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   21:06:19 11/19/2015
// Design Name:   FSMdiv3
// Module Name:   C:/Users/Andrew/Desktop/School/Computer Science/CS140L/Lab3/FSMdiv3Test.v
// Project Name:  Lab3
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: FSMdiv3
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module FSMdiv3Test;

	// Inputs
	reg Clk;
	reg reset;
	reg Datain;

	// Outputs
	wire REM;

	// Instantiate the Unit Under Test (UUT)
	FSMdiv3 uut (
		.Clk(Clk), 
		.reset(reset), 
		.Datain(Datain), 
		.REM(REM)
	);

		// Wait 100 ns for global reset to finish
		initial begin
		// Initialize Inputs
		reset = 1;
		Clk = 0;
		Datain = 0;

		// Wait 100 ns for global reset to finish
		#100;
        
		reset = 0;
		Datain = 1;
		#200
		Datain = 0;
		#40;
		Datain = 1;
		#20
	   reset = 1;
		#30
		Datain = 1;
		#40
		Datain = 0;
		// Add stimulus here

	end
	
	always begin
	#13
	Clk = ~Clk;
	end
        
		// Add stimulus here

      
endmodule

