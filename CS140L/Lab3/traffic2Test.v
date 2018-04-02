`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   16:17:40 11/20/2015
// Design Name:   traffic2
// Module Name:   C:/Users/Andrew/Desktop/School/Computer Science/CS140L/Lab3/traffic2Test.v
// Project Name:  Lab3
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: traffic2
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module traffic2Test;

	// Inputs
	reg Clk;
	reg Sensor;

	// Outputs
	wire TL1R;
	wire TL1Y;
	wire TL1G;
	wire TL2R;
	wire TL2Y;
	wire TL2G;

	// Instantiate the Unit Under Test (UUT)
	traffic2 uut (
		.Clk(Clk), 
		.Sensor(Sensor), 
		.TL1R(TL1R), 
		.TL1Y(TL1Y), 
		.TL1G(TL1G), 
		.TL2R(TL2R), 
		.TL2Y(TL2Y), 
		.TL2G(TL2G)
	);

	initial begin
		// Initialize Inputs
		Clk = 0;
		Sensor = 1;
		// Wait 100 ns for global reset to finish
		#623;
		Sensor = 0;
		#1000;
		Sensor = 1;

        
		// Add stimulus here

	end
      
		always begin
		#7;
		Clk = ~Clk;
		end
      
endmodule

