`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   14:28:38 10/26/2015
// Design Name:   CarryLookAheadAdder
// Module Name:   C:/Users/Andrew/Desktop/School/Computer Science/CS140L/Lab2/CarryLookAheadAdderTest.v
// Project Name:  Lab2
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: CarryLookAheadAdder
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module CarryLookAheadAdderTest;

	// Inputs
	reg [3:0] A;
	reg [3:0] B;
	reg Cin;

	// Outputs
	wire [3:0] S;
	wire Cout;
	wire PG;
	wire GG;

	// Instantiate the Unit Under Test (UUT)
	CarryLookAheadAdder uut (
		.A(A), 
		.B(B), 
		.Cin(Cin), 
		.S(S), 
		.Cout(Cout), 
		.PG(PG), 
		.GG(GG)
	);

	initial begin
		// Initialize Inputs
		A = 0011;
		B = 1000;
		Cin = 0;

		// Wait 100 ns for global reset to finish
		#100;
        
		// Add stimulus here
		A = 0011;
		B = 1000;
		Cin = 1;
		
		#100;
		A = 0011;
		B = 0111;
		Cin = 0;
		
		#100;
		A = 0011;
		B = 0111;
		Cin = 1;
		
		#100;

	end
      
endmodule

