`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   14:29:11 12/01/2015
// Design Name:   TinyCpu
// Module Name:   C:/Users/Andrew/Desktop/School/Computer Science/CS140L/Lab4/TinyCpuTester.v
// Project Name:  Lab4
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: TinyCpu
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module TinyCpuTester;
// Inputs
reg [11:0] In;
reg Clk;
// Outputs
wire [7:0] Result;
wire [7:0] RegA;
wire [7:0] RegB;
// Instantiate the Unit Under Test (UUT)
TinyCpu uut (
.In(In), 
.Clk(Clk),

.Result(Result),
// I'm declaring extra output below, just to observe the values stored in registers.
.RegA(RegA), // I'm feeding the output wire of the registerA to this output to see the value stored in RegisterA
.RegB(RegB) // I'm feeding the output wire of the registerB to this output to see the value stored in RegisterB
// You can do it just by writing something "assign RegB = RegisterBoutwire;" RegisterBoutwire is the wire name that I used to connect my RegisterB to ALU
//By the end of this test your Result should be 00000011
);
initial begin
// Initialize Inputs
In = 0;
Clk = 0;
// Wait 100 ns for global reset to finish
#100;
In = 12'b000000000000; // Clear all register
#100;
In = 12'b000100000111; // Write A= 00000111
#100;
In = 12'b001000001000; // Write B= 00001000
#100;
In = 12'b010000000000; // Result = A+B
#100;
In = 12'b100100000000; // Result = A^B

#100;
In = 12'b101100000000; // Compare A to B

#100;
In = 12'b011000000000; // Result = A>>1
#100;
In = 12'b001100000000; // B = Result
#100;
//By the end of this test your Result should be 00000011

end

always begin
Clk= ~Clk;
#13;
end

      
endmodule

