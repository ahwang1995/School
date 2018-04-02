`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    22:18:27 11/19/2015 
// Design Name: 
// Module Name:    traffic 
// Project Name: 
// Target Devices: 
// Tool versions: 
// Description: 
//
// Dependencies: 
//
// Revision: 
// Revision 0.01 - File Created
// Additional Comments: 
//
//////////////////////////////////////////////////////////////////////////////////
module traffic(input Clk,Sensor,output TL1R,TL1Y,TL1G,TL2R,TL2Y,TL2G);
reg counter40,counter3,counter10,checkSensor;
reg TL1R,TL1Y,TL1G,TL2R,TL2Y,TL2G;
initial
begin 
TL1R = 0;
TL1Y = 0;
TL2Y = 0;
TL2G = 0;
TL1G = 1;
TL2R = 1;
checkSensor = 0;
counter40 = 0;
counter3 = 0;
counter10 = 0;
end
always@(posedge Clk) 
begin
if(counter40 < 40)
begin
counter40  <= counter40 + 1;
end
	if(counter40 >= 40)
	begin
		if(Sensor == 0 || checkSensor == 1)
		begin
		checkSensor <= 1;
			if(counter3 <= 3)
			begin
				TL1G <= 0;
				TL1Y <= 1;
				counter3 <= counter3 + 1;
			end else begin
				TL1Y <= 0;
				if(counter10 <= 10)
				begin
				TL2R <= 0;
				TL2G <= 1;
				TL1R <= 1;
				counter10 = counter10 + 1;
				end else begin
				if(counter3 <= 6)
				begin
					TL2G <= 0;
					TL2Y <= 1;
					counter3 <= counter3 + 1;
				end else begin
					TL1R <= 0;
					TL1G <= 1;
					TL2Y <= 0;
					TL2R <= 1;
					counter3 <= 0;
					counter40 <= 0;
					counter10 <= 0;
					checkSensor <= 0;
				end
			end
		end
	end
end
end
endmodule
