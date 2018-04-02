`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   13:23:52 10/26/2015
// Design Name:   CarryRippleAdder
// Module Name:   C:/Users/Andrew/Desktop/School/Computer Science/CS140L/Lab2/CarryRippleAdderTest.v
// Project Name:  Lab2
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: CarryRippleAdder
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module CarryRippleAdderTest;

	// Inputs
	reg [3:0] A;
	reg [3:0] B;
	reg Cin;

	// Outputs
	wire [3:0] S;
	wire Cout;
	wire OF;

	// Instantiate the Unit Under Test (UUT)
	CarryRippleAdder uut (
		.A(A), 
		.B(B), 
		.Cin(Cin), 
		.S(S), 
		.Cout(Cout),
		.OF(OF)
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

