-- Copyright (C) 1991-2015 Altera Corporation. All rights reserved.
-- Your use of Altera Corporation's design tools, logic functions 
-- and other software and tools, and its AMPP partner logic 
-- functions, and any output files from any of the foregoing 
-- (including device programming or simulation files), and any 
-- associated documentation or information are expressly subject 
-- to the terms and conditions of the Altera Program License 
-- Subscription Agreement, the Altera Quartus II License Agreement,
-- the Altera MegaCore Function License Agreement, or other 
-- applicable license agreement, including, without limitation, 
-- that your use is for the sole purpose of programming logic 
-- devices manufactured by Altera and sold by Altera or its 
-- authorized distributors.  Please refer to the applicable 
-- agreement for further details.

-- VENDOR "Altera"
-- PROGRAM "Quartus II 64-Bit"
-- VERSION "Version 15.0.0 Build 145 04/22/2015 SJ Web Edition"

-- DATE "01/22/2016 05:50:38"

-- 
-- Device: Altera 5CGXFC7C7F23C8 Package FBGA484
-- 

-- 
-- This VHDL file should be used for ModelSim-Altera (VHDL) only
-- 

LIBRARY ALTERA;
LIBRARY ALTERA_LNSIM;
LIBRARY CYCLONEV;
LIBRARY IEEE;
USE ALTERA.ALTERA_PRIMITIVES_COMPONENTS.ALL;
USE ALTERA_LNSIM.ALTERA_LNSIM_COMPONENTS.ALL;
USE CYCLONEV.CYCLONEV_COMPONENTS.ALL;
USE IEEE.STD_LOGIC_1164.ALL;

ENTITY 	reg_file_wrap IS
    PORT (
	clk : IN std_logic;
	rs_addr_i : IN std_logic_vector(4 DOWNTO 0);
	rd_addr_i : IN std_logic_vector(4 DOWNTO 0);
	w_addr_i : IN std_logic_vector(4 DOWNTO 0);
	wen_i : IN std_logic;
	w_data_i : IN std_logic_vector(63 DOWNTO 0);
	rs_val_o : OUT std_logic_vector(63 DOWNTO 0);
	rd_val_o : OUT std_logic_vector(63 DOWNTO 0)
	);
END reg_file_wrap;

-- Design Ports Information
-- rs_val_o[0]	=>  Location: PIN_D19,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- rs_val_o[1]	=>  Location: PIN_G12,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- rs_val_o[2]	=>  Location: PIN_R15,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- rs_val_o[3]	=>  Location: PIN_B18,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- rs_val_o[4]	=>  Location: PIN_T14,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- rs_val_o[5]	=>  Location: PIN_F10,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- rs_val_o[6]	=>  Location: PIN_P9,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- rs_val_o[7]	=>  Location: PIN_A22,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- rs_val_o[8]	=>  Location: PIN_AA12,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- rs_val_o[9]	=>  Location: PIN_M21,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- rs_val_o[10]	=>  Location: PIN_H8,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- rs_val_o[11]	=>  Location: PIN_T20,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- rs_val_o[12]	=>  Location: PIN_Y20,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- rs_val_o[13]	=>  Location: PIN_H11,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- rs_val_o[14]	=>  Location: PIN_R14,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- rs_val_o[15]	=>  Location: PIN_D12,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- rs_val_o[16]	=>  Location: PIN_L7,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- rs_val_o[17]	=>  Location: PIN_W22,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- rs_val_o[18]	=>  Location: PIN_P14,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- rs_val_o[19]	=>  Location: PIN_E19,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- rs_val_o[20]	=>  Location: PIN_K7,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- rs_val_o[21]	=>  Location: PIN_D22,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- rs_val_o[22]	=>  Location: PIN_U21,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- rs_val_o[23]	=>  Location: PIN_P7,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- rs_val_o[24]	=>  Location: PIN_AB21,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- rs_val_o[25]	=>  Location: PIN_Y19,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- rs_val_o[26]	=>  Location: PIN_P18,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- rs_val_o[27]	=>  Location: PIN_P19,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- rs_val_o[28]	=>  Location: PIN_P8,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- rs_val_o[29]	=>  Location: PIN_T12,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- rs_val_o[30]	=>  Location: PIN_T22,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- rs_val_o[31]	=>  Location: PIN_AB22,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- rs_val_o[32]	=>  Location: PIN_V6,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- rs_val_o[33]	=>  Location: PIN_B17,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- rs_val_o[34]	=>  Location: PIN_Y21,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- rs_val_o[35]	=>  Location: PIN_C19,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- rs_val_o[36]	=>  Location: PIN_U15,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- rs_val_o[37]	=>  Location: PIN_AA22,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- rs_val_o[38]	=>  Location: PIN_Y22,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- rs_val_o[39]	=>  Location: PIN_W19,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- rs_val_o[40]	=>  Location: PIN_AB10,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- rs_val_o[41]	=>  Location: PIN_T15,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- rs_val_o[42]	=>  Location: PIN_P17,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- rs_val_o[43]	=>  Location: PIN_U16,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- rs_val_o[44]	=>  Location: PIN_AB17,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- rs_val_o[45]	=>  Location: PIN_R22,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- rs_val_o[46]	=>  Location: PIN_P22,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- rs_val_o[47]	=>  Location: PIN_AA13,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- rs_val_o[48]	=>  Location: PIN_U17,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- rs_val_o[49]	=>  Location: PIN_R17,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- rs_val_o[50]	=>  Location: PIN_M9,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- rs_val_o[51]	=>  Location: PIN_AA10,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- rs_val_o[52]	=>  Location: PIN_R21,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- rs_val_o[53]	=>  Location: PIN_N9,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- rs_val_o[54]	=>  Location: PIN_AB7,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- rs_val_o[55]	=>  Location: PIN_J7,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- rs_val_o[56]	=>  Location: PIN_Y11,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- rs_val_o[57]	=>  Location: PIN_W16,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- rs_val_o[58]	=>  Location: PIN_AA15,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- rs_val_o[59]	=>  Location: PIN_F13,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- rs_val_o[60]	=>  Location: PIN_M8,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- rs_val_o[61]	=>  Location: PIN_U20,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- rs_val_o[62]	=>  Location: PIN_A9,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- rs_val_o[63]	=>  Location: PIN_E22,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- rd_val_o[0]	=>  Location: PIN_A19,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- rd_val_o[1]	=>  Location: PIN_M7,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- rd_val_o[2]	=>  Location: PIN_L22,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- rd_val_o[3]	=>  Location: PIN_N21,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- rd_val_o[4]	=>  Location: PIN_L17,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- rd_val_o[5]	=>  Location: PIN_K22,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- rd_val_o[6]	=>  Location: PIN_AB8,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- rd_val_o[7]	=>  Location: PIN_AB6,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- rd_val_o[8]	=>  Location: PIN_V16,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- rd_val_o[9]	=>  Location: PIN_AA18,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- rd_val_o[10]	=>  Location: PIN_N6,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- rd_val_o[11]	=>  Location: PIN_B13,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- rd_val_o[12]	=>  Location: PIN_F12,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- rd_val_o[13]	=>  Location: PIN_U8,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- rd_val_o[14]	=>  Location: PIN_V9,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- rd_val_o[15]	=>  Location: PIN_P6,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- rd_val_o[16]	=>  Location: PIN_M22,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- rd_val_o[17]	=>  Location: PIN_E14,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- rd_val_o[18]	=>  Location: PIN_K17,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- rd_val_o[19]	=>  Location: PIN_V10,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- rd_val_o[20]	=>  Location: PIN_E16,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- rd_val_o[21]	=>  Location: PIN_D13,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- rd_val_o[22]	=>  Location: PIN_AA14,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- rd_val_o[23]	=>  Location: PIN_H20,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- rd_val_o[24]	=>  Location: PIN_Y15,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- rd_val_o[25]	=>  Location: PIN_E15,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- rd_val_o[26]	=>  Location: PIN_AA7,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- rd_val_o[27]	=>  Location: PIN_G18,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- rd_val_o[28]	=>  Location: PIN_C18,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- rd_val_o[29]	=>  Location: PIN_R6,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- rd_val_o[30]	=>  Location: PIN_U7,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- rd_val_o[31]	=>  Location: PIN_P16,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- rd_val_o[32]	=>  Location: PIN_H10,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- rd_val_o[33]	=>  Location: PIN_F22,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- rd_val_o[34]	=>  Location: PIN_R16,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- rd_val_o[35]	=>  Location: PIN_N20,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- rd_val_o[36]	=>  Location: PIN_Y14,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- rd_val_o[37]	=>  Location: PIN_AB5,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- rd_val_o[38]	=>  Location: PIN_R5,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- rd_val_o[39]	=>  Location: PIN_C13,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- rd_val_o[40]	=>  Location: PIN_R7,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- rd_val_o[41]	=>  Location: PIN_A18,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- rd_val_o[42]	=>  Location: PIN_H15,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- rd_val_o[43]	=>  Location: PIN_L8,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- rd_val_o[44]	=>  Location: PIN_N16,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- rd_val_o[45]	=>  Location: PIN_A15,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- rd_val_o[46]	=>  Location: PIN_AA8,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- rd_val_o[47]	=>  Location: PIN_J11,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- rd_val_o[48]	=>  Location: PIN_N19,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- rd_val_o[49]	=>  Location: PIN_B16,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- rd_val_o[50]	=>  Location: PIN_A12,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- rd_val_o[51]	=>  Location: PIN_A13,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- rd_val_o[52]	=>  Location: PIN_B12,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- rd_val_o[53]	=>  Location: PIN_T19,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- rd_val_o[54]	=>  Location: PIN_M6,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- rd_val_o[55]	=>  Location: PIN_M18,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- rd_val_o[56]	=>  Location: PIN_F15,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- rd_val_o[57]	=>  Location: PIN_AA9,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- rd_val_o[58]	=>  Location: PIN_K16,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- rd_val_o[59]	=>  Location: PIN_H16,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- rd_val_o[60]	=>  Location: PIN_N8,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- rd_val_o[61]	=>  Location: PIN_F14,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- rd_val_o[62]	=>  Location: PIN_J21,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- rd_val_o[63]	=>  Location: PIN_R11,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- clk	=>  Location: PIN_M16,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- wen_i	=>  Location: PIN_Y10,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- w_data_i[0]	=>  Location: PIN_T9,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- w_addr_i[0]	=>  Location: PIN_T7,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- w_addr_i[1]	=>  Location: PIN_V14,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- w_addr_i[2]	=>  Location: PIN_G20,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- w_addr_i[3]	=>  Location: PIN_U12,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- w_addr_i[4]	=>  Location: PIN_E12,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- rs_addr_i[0]	=>  Location: PIN_C15,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- rs_addr_i[1]	=>  Location: PIN_AB20,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- rs_addr_i[2]	=>  Location: PIN_U11,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- rs_addr_i[3]	=>  Location: PIN_U10,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- rs_addr_i[4]	=>  Location: PIN_J17,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- w_data_i[1]	=>  Location: PIN_AB18,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- w_data_i[2]	=>  Location: PIN_AA19,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- w_data_i[3]	=>  Location: PIN_AA17,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- w_data_i[4]	=>  Location: PIN_U6,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- w_data_i[5]	=>  Location: PIN_H13,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- w_data_i[6]	=>  Location: PIN_G17,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- w_data_i[7]	=>  Location: PIN_J13,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- w_data_i[8]	=>  Location: PIN_R12,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- w_data_i[9]	=>  Location: PIN_Y9,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- w_data_i[10]	=>  Location: PIN_L19,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- w_data_i[11]	=>  Location: PIN_V13,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- w_data_i[12]	=>  Location: PIN_U13,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- w_data_i[13]	=>  Location: PIN_AB15,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- w_data_i[14]	=>  Location: PIN_V18,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- w_data_i[15]	=>  Location: PIN_T10,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- w_data_i[16]	=>  Location: PIN_V19,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- w_data_i[17]	=>  Location: PIN_R9,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- w_data_i[18]	=>  Location: PIN_F20,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- w_data_i[19]	=>  Location: PIN_Y17,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- w_data_i[20]	=>  Location: PIN_T18,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- w_data_i[21]	=>  Location: PIN_P12,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- w_data_i[22]	=>  Location: PIN_V15,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- w_data_i[23]	=>  Location: PIN_B21,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- w_data_i[24]	=>  Location: PIN_T13,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- w_data_i[25]	=>  Location: PIN_U22,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- w_data_i[26]	=>  Location: PIN_W8,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- w_data_i[27]	=>  Location: PIN_T17,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- w_data_i[28]	=>  Location: PIN_K21,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- w_data_i[29]	=>  Location: PIN_B15,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- w_data_i[30]	=>  Location: PIN_M20,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- w_data_i[31]	=>  Location: PIN_K20,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- w_data_i[32]	=>  Location: PIN_F18,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- w_data_i[33]	=>  Location: PIN_A14,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- w_data_i[34]	=>  Location: PIN_B22,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- w_data_i[35]	=>  Location: PIN_H14,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- w_data_i[36]	=>  Location: PIN_Y16,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- w_data_i[37]	=>  Location: PIN_G10,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- w_data_i[38]	=>  Location: PIN_J22,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- w_data_i[39]	=>  Location: PIN_AB13,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- w_data_i[40]	=>  Location: PIN_K19,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- w_data_i[41]	=>  Location: PIN_W21,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- w_data_i[42]	=>  Location: PIN_A20,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- w_data_i[43]	=>  Location: PIN_AB11,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- w_data_i[44]	=>  Location: PIN_V21,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- w_data_i[45]	=>  Location: PIN_C11,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- w_data_i[46]	=>  Location: PIN_G16,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- w_data_i[47]	=>  Location: PIN_AB12,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- w_data_i[48]	=>  Location: PIN_T8,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- w_data_i[49]	=>  Location: PIN_L18,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- w_data_i[50]	=>  Location: PIN_W9,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- w_data_i[51]	=>  Location: PIN_G13,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- w_data_i[52]	=>  Location: PIN_E20,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- w_data_i[53]	=>  Location: PIN_B11,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- w_data_i[54]	=>  Location: PIN_R10,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- w_data_i[55]	=>  Location: PIN_G22,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- w_data_i[56]	=>  Location: PIN_V20,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- w_data_i[57]	=>  Location: PIN_C21,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- w_data_i[58]	=>  Location: PIN_G11,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- w_data_i[59]	=>  Location: PIN_C16,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- w_data_i[60]	=>  Location: PIN_J18,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- w_data_i[61]	=>  Location: PIN_G15,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- w_data_i[62]	=>  Location: PIN_AA20,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- w_data_i[63]	=>  Location: PIN_A17,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- rd_addr_i[0]	=>  Location: PIN_K9,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- rd_addr_i[1]	=>  Location: PIN_H18,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- rd_addr_i[2]	=>  Location: PIN_J19,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- rd_addr_i[3]	=>  Location: PIN_F19,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- rd_addr_i[4]	=>  Location: PIN_D17,	 I/O Standard: 2.5 V,	 Current Strength: Default


ARCHITECTURE structure OF reg_file_wrap IS
SIGNAL gnd : std_logic := '0';
SIGNAL vcc : std_logic := '1';
SIGNAL unknown : std_logic := 'X';
SIGNAL devoe : std_logic := '1';
SIGNAL devclrn : std_logic := '1';
SIGNAL devpor : std_logic := '1';
SIGNAL ww_devoe : std_logic;
SIGNAL ww_devclrn : std_logic;
SIGNAL ww_devpor : std_logic;
SIGNAL ww_clk : std_logic;
SIGNAL ww_rs_addr_i : std_logic_vector(4 DOWNTO 0);
SIGNAL ww_rd_addr_i : std_logic_vector(4 DOWNTO 0);
SIGNAL ww_w_addr_i : std_logic_vector(4 DOWNTO 0);
SIGNAL ww_wen_i : std_logic;
SIGNAL ww_w_data_i : std_logic_vector(63 DOWNTO 0);
SIGNAL ww_rs_val_o : std_logic_vector(63 DOWNTO 0);
SIGNAL ww_rd_val_o : std_logic_vector(63 DOWNTO 0);
SIGNAL \rf|RF_rtl_0|auto_generated|ram_block1a0_PORTADATAIN_bus\ : std_logic_vector(39 DOWNTO 0);
SIGNAL \rf|RF_rtl_0|auto_generated|ram_block1a0_PORTAADDR_bus\ : std_logic_vector(4 DOWNTO 0);
SIGNAL \rf|RF_rtl_0|auto_generated|ram_block1a0_PORTBADDR_bus\ : std_logic_vector(4 DOWNTO 0);
SIGNAL \rf|RF_rtl_0|auto_generated|ram_block1a0_PORTBDATAOUT_bus\ : std_logic_vector(39 DOWNTO 0);
SIGNAL \rf|RF_rtl_0|auto_generated|ram_block1a40_PORTADATAIN_bus\ : std_logic_vector(39 DOWNTO 0);
SIGNAL \rf|RF_rtl_0|auto_generated|ram_block1a40_PORTAADDR_bus\ : std_logic_vector(4 DOWNTO 0);
SIGNAL \rf|RF_rtl_0|auto_generated|ram_block1a40_PORTBADDR_bus\ : std_logic_vector(4 DOWNTO 0);
SIGNAL \rf|RF_rtl_0|auto_generated|ram_block1a40_PORTBDATAOUT_bus\ : std_logic_vector(39 DOWNTO 0);
SIGNAL \rf|RF_rtl_1|auto_generated|ram_block1a0_PORTADATAIN_bus\ : std_logic_vector(39 DOWNTO 0);
SIGNAL \rf|RF_rtl_1|auto_generated|ram_block1a0_PORTAADDR_bus\ : std_logic_vector(4 DOWNTO 0);
SIGNAL \rf|RF_rtl_1|auto_generated|ram_block1a0_PORTBADDR_bus\ : std_logic_vector(4 DOWNTO 0);
SIGNAL \rf|RF_rtl_1|auto_generated|ram_block1a0_PORTBDATAOUT_bus\ : std_logic_vector(39 DOWNTO 0);
SIGNAL \rf|RF_rtl_1|auto_generated|ram_block1a40_PORTADATAIN_bus\ : std_logic_vector(39 DOWNTO 0);
SIGNAL \rf|RF_rtl_1|auto_generated|ram_block1a40_PORTAADDR_bus\ : std_logic_vector(4 DOWNTO 0);
SIGNAL \rf|RF_rtl_1|auto_generated|ram_block1a40_PORTBADDR_bus\ : std_logic_vector(4 DOWNTO 0);
SIGNAL \rf|RF_rtl_1|auto_generated|ram_block1a40_PORTBDATAOUT_bus\ : std_logic_vector(39 DOWNTO 0);
SIGNAL \~QUARTUS_CREATED_GND~I_combout\ : std_logic;
SIGNAL \clk~input_o\ : std_logic;
SIGNAL \clk~inputCLKENA0_outclk\ : std_logic;
SIGNAL \wen_i~input_o\ : std_logic;
SIGNAL \wen_r~feeder_combout\ : std_logic;
SIGNAL \wen_r~q\ : std_logic;
SIGNAL \w_data_i[0]~input_o\ : std_logic;
SIGNAL \w_addr_i[0]~input_o\ : std_logic;
SIGNAL \w_addr_i[1]~input_o\ : std_logic;
SIGNAL \w_addr_i[2]~input_o\ : std_logic;
SIGNAL \w_addr_r[2]~feeder_combout\ : std_logic;
SIGNAL \w_addr_i[3]~input_o\ : std_logic;
SIGNAL \w_addr_r[3]~feeder_combout\ : std_logic;
SIGNAL \w_addr_i[4]~input_o\ : std_logic;
SIGNAL \rs_addr_i[0]~input_o\ : std_logic;
SIGNAL \rs_addr_r[0]~feeder_combout\ : std_logic;
SIGNAL \rs_addr_i[1]~input_o\ : std_logic;
SIGNAL \rs_addr_i[2]~input_o\ : std_logic;
SIGNAL \rs_addr_i[3]~input_o\ : std_logic;
SIGNAL \rs_addr_r[3]~feeder_combout\ : std_logic;
SIGNAL \rs_addr_i[4]~input_o\ : std_logic;
SIGNAL \rs_addr_r[4]~feeder_combout\ : std_logic;
SIGNAL \w_data_i[1]~input_o\ : std_logic;
SIGNAL \w_data_i[2]~input_o\ : std_logic;
SIGNAL \w_data_i[3]~input_o\ : std_logic;
SIGNAL \w_data_i[4]~input_o\ : std_logic;
SIGNAL \w_data_i[5]~input_o\ : std_logic;
SIGNAL \w_data_r[5]~feeder_combout\ : std_logic;
SIGNAL \w_data_i[6]~input_o\ : std_logic;
SIGNAL \w_data_i[7]~input_o\ : std_logic;
SIGNAL \w_data_i[8]~input_o\ : std_logic;
SIGNAL \w_data_r[8]~feeder_combout\ : std_logic;
SIGNAL \w_data_i[9]~input_o\ : std_logic;
SIGNAL \w_data_i[10]~input_o\ : std_logic;
SIGNAL \w_data_r[10]~feeder_combout\ : std_logic;
SIGNAL \w_data_i[11]~input_o\ : std_logic;
SIGNAL \w_data_r[11]~feeder_combout\ : std_logic;
SIGNAL \w_data_i[12]~input_o\ : std_logic;
SIGNAL \w_data_r[12]~feeder_combout\ : std_logic;
SIGNAL \w_data_i[13]~input_o\ : std_logic;
SIGNAL \w_data_r[13]~feeder_combout\ : std_logic;
SIGNAL \w_data_i[14]~input_o\ : std_logic;
SIGNAL \w_data_i[15]~input_o\ : std_logic;
SIGNAL \w_data_r[15]~feeder_combout\ : std_logic;
SIGNAL \w_data_i[16]~input_o\ : std_logic;
SIGNAL \w_data_r[16]~feeder_combout\ : std_logic;
SIGNAL \w_data_i[17]~input_o\ : std_logic;
SIGNAL \w_data_r[17]~feeder_combout\ : std_logic;
SIGNAL \w_data_i[18]~input_o\ : std_logic;
SIGNAL \w_data_i[19]~input_o\ : std_logic;
SIGNAL \w_data_r[19]~feeder_combout\ : std_logic;
SIGNAL \w_data_i[20]~input_o\ : std_logic;
SIGNAL \w_data_i[21]~input_o\ : std_logic;
SIGNAL \w_data_i[22]~input_o\ : std_logic;
SIGNAL \w_data_i[23]~input_o\ : std_logic;
SIGNAL \w_data_r[23]~feeder_combout\ : std_logic;
SIGNAL \w_data_i[24]~input_o\ : std_logic;
SIGNAL \w_data_r[24]~feeder_combout\ : std_logic;
SIGNAL \w_data_i[25]~input_o\ : std_logic;
SIGNAL \w_data_i[26]~input_o\ : std_logic;
SIGNAL \w_data_i[27]~input_o\ : std_logic;
SIGNAL \w_data_r[27]~feeder_combout\ : std_logic;
SIGNAL \w_data_i[28]~input_o\ : std_logic;
SIGNAL \w_data_i[29]~input_o\ : std_logic;
SIGNAL \w_data_r[29]~feeder_combout\ : std_logic;
SIGNAL \w_data_i[30]~input_o\ : std_logic;
SIGNAL \w_data_r[30]~feeder_combout\ : std_logic;
SIGNAL \w_data_i[31]~input_o\ : std_logic;
SIGNAL \w_data_r[31]~feeder_combout\ : std_logic;
SIGNAL \w_data_i[32]~input_o\ : std_logic;
SIGNAL \w_data_i[33]~input_o\ : std_logic;
SIGNAL \w_data_r[33]~feeder_combout\ : std_logic;
SIGNAL \w_data_i[34]~input_o\ : std_logic;
SIGNAL \w_data_i[35]~input_o\ : std_logic;
SIGNAL \w_data_i[36]~input_o\ : std_logic;
SIGNAL \w_data_i[37]~input_o\ : std_logic;
SIGNAL \w_data_r[37]~feeder_combout\ : std_logic;
SIGNAL \w_data_i[38]~input_o\ : std_logic;
SIGNAL \w_data_r[38]~feeder_combout\ : std_logic;
SIGNAL \w_data_i[39]~input_o\ : std_logic;
SIGNAL \w_data_r[39]~feeder_combout\ : std_logic;
SIGNAL \rf|RF_rtl_0|auto_generated|ram_block1a0~portbdataout\ : std_logic;
SIGNAL \rf|RF_rtl_0|auto_generated|ram_block1a1\ : std_logic;
SIGNAL \rf|RF_rtl_0|auto_generated|ram_block1a2\ : std_logic;
SIGNAL \rf|RF_rtl_0|auto_generated|ram_block1a3\ : std_logic;
SIGNAL \rf|RF_rtl_0|auto_generated|ram_block1a4\ : std_logic;
SIGNAL \rf|RF_rtl_0|auto_generated|ram_block1a5\ : std_logic;
SIGNAL \rf|RF_rtl_0|auto_generated|ram_block1a6\ : std_logic;
SIGNAL \rf|RF_rtl_0|auto_generated|ram_block1a7\ : std_logic;
SIGNAL \rf|RF_rtl_0|auto_generated|ram_block1a8\ : std_logic;
SIGNAL \rf|RF_rtl_0|auto_generated|ram_block1a9\ : std_logic;
SIGNAL \rf|RF_rtl_0|auto_generated|ram_block1a10\ : std_logic;
SIGNAL \rf|RF_rtl_0|auto_generated|ram_block1a11\ : std_logic;
SIGNAL \rf|RF_rtl_0|auto_generated|ram_block1a12\ : std_logic;
SIGNAL \rf|RF_rtl_0|auto_generated|ram_block1a13\ : std_logic;
SIGNAL \rf|RF_rtl_0|auto_generated|ram_block1a14\ : std_logic;
SIGNAL \rf|RF_rtl_0|auto_generated|ram_block1a15\ : std_logic;
SIGNAL \rf|RF_rtl_0|auto_generated|ram_block1a16\ : std_logic;
SIGNAL \rf|RF_rtl_0|auto_generated|ram_block1a17\ : std_logic;
SIGNAL \rf|RF_rtl_0|auto_generated|ram_block1a18\ : std_logic;
SIGNAL \rf|RF_rtl_0|auto_generated|ram_block1a19\ : std_logic;
SIGNAL \rf|RF_rtl_0|auto_generated|ram_block1a20\ : std_logic;
SIGNAL \rf|RF_rtl_0|auto_generated|ram_block1a21\ : std_logic;
SIGNAL \rf|RF_rtl_0|auto_generated|ram_block1a22\ : std_logic;
SIGNAL \rf|RF_rtl_0|auto_generated|ram_block1a23\ : std_logic;
SIGNAL \rf|RF_rtl_0|auto_generated|ram_block1a24\ : std_logic;
SIGNAL \rf|RF_rtl_0|auto_generated|ram_block1a25\ : std_logic;
SIGNAL \rf|RF_rtl_0|auto_generated|ram_block1a26\ : std_logic;
SIGNAL \rf|RF_rtl_0|auto_generated|ram_block1a27\ : std_logic;
SIGNAL \rf|RF_rtl_0|auto_generated|ram_block1a28\ : std_logic;
SIGNAL \rf|RF_rtl_0|auto_generated|ram_block1a29\ : std_logic;
SIGNAL \rf|RF_rtl_0|auto_generated|ram_block1a30\ : std_logic;
SIGNAL \rf|RF_rtl_0|auto_generated|ram_block1a31\ : std_logic;
SIGNAL \rf|RF_rtl_0|auto_generated|ram_block1a32\ : std_logic;
SIGNAL \rf|RF_rtl_0|auto_generated|ram_block1a33\ : std_logic;
SIGNAL \rf|RF_rtl_0|auto_generated|ram_block1a34\ : std_logic;
SIGNAL \rf|RF_rtl_0|auto_generated|ram_block1a35\ : std_logic;
SIGNAL \rf|RF_rtl_0|auto_generated|ram_block1a36\ : std_logic;
SIGNAL \rf|RF_rtl_0|auto_generated|ram_block1a37\ : std_logic;
SIGNAL \rf|RF_rtl_0|auto_generated|ram_block1a38\ : std_logic;
SIGNAL \rf|RF_rtl_0|auto_generated|ram_block1a39\ : std_logic;
SIGNAL \w_data_i[40]~input_o\ : std_logic;
SIGNAL \w_data_i[41]~input_o\ : std_logic;
SIGNAL \w_data_r[41]~feeder_combout\ : std_logic;
SIGNAL \w_data_i[42]~input_o\ : std_logic;
SIGNAL \w_data_r[42]~feeder_combout\ : std_logic;
SIGNAL \w_data_i[43]~input_o\ : std_logic;
SIGNAL \w_data_r[43]~feeder_combout\ : std_logic;
SIGNAL \w_data_i[44]~input_o\ : std_logic;
SIGNAL \w_data_i[45]~input_o\ : std_logic;
SIGNAL \w_data_r[45]~feeder_combout\ : std_logic;
SIGNAL \w_data_i[46]~input_o\ : std_logic;
SIGNAL \w_data_r[46]~feeder_combout\ : std_logic;
SIGNAL \w_data_i[47]~input_o\ : std_logic;
SIGNAL \w_data_r[47]~feeder_combout\ : std_logic;
SIGNAL \w_data_i[48]~input_o\ : std_logic;
SIGNAL \w_data_i[49]~input_o\ : std_logic;
SIGNAL \w_data_r[49]~feeder_combout\ : std_logic;
SIGNAL \w_data_i[50]~input_o\ : std_logic;
SIGNAL \w_data_r[50]~feeder_combout\ : std_logic;
SIGNAL \w_data_i[51]~input_o\ : std_logic;
SIGNAL \w_data_r[51]~feeder_combout\ : std_logic;
SIGNAL \w_data_i[52]~input_o\ : std_logic;
SIGNAL \w_data_i[53]~input_o\ : std_logic;
SIGNAL \w_data_r[53]~feeder_combout\ : std_logic;
SIGNAL \w_data_i[54]~input_o\ : std_logic;
SIGNAL \w_data_r[54]~feeder_combout\ : std_logic;
SIGNAL \w_data_i[55]~input_o\ : std_logic;
SIGNAL \w_data_r[55]~feeder_combout\ : std_logic;
SIGNAL \w_data_i[56]~input_o\ : std_logic;
SIGNAL \w_data_r[56]~feeder_combout\ : std_logic;
SIGNAL \w_data_i[57]~input_o\ : std_logic;
SIGNAL \w_data_r[57]~feeder_combout\ : std_logic;
SIGNAL \w_data_i[58]~input_o\ : std_logic;
SIGNAL \w_data_i[59]~input_o\ : std_logic;
SIGNAL \w_data_r[59]~feeder_combout\ : std_logic;
SIGNAL \w_data_i[60]~input_o\ : std_logic;
SIGNAL \w_data_i[61]~input_o\ : std_logic;
SIGNAL \w_data_i[62]~input_o\ : std_logic;
SIGNAL \w_data_r[62]~feeder_combout\ : std_logic;
SIGNAL \w_data_i[63]~input_o\ : std_logic;
SIGNAL \rf|RF_rtl_0|auto_generated|ram_block1a40~portbdataout\ : std_logic;
SIGNAL \rf|RF_rtl_0|auto_generated|ram_block1a41\ : std_logic;
SIGNAL \rf|RF_rtl_0|auto_generated|ram_block1a42\ : std_logic;
SIGNAL \rf|RF_rtl_0|auto_generated|ram_block1a43\ : std_logic;
SIGNAL \rf|RF_rtl_0|auto_generated|ram_block1a44\ : std_logic;
SIGNAL \rf|RF_rtl_0|auto_generated|ram_block1a45\ : std_logic;
SIGNAL \rf|RF_rtl_0|auto_generated|ram_block1a46\ : std_logic;
SIGNAL \rf|RF_rtl_0|auto_generated|ram_block1a47\ : std_logic;
SIGNAL \rf|RF_rtl_0|auto_generated|ram_block1a48\ : std_logic;
SIGNAL \rf|RF_rtl_0|auto_generated|ram_block1a49\ : std_logic;
SIGNAL \rf|RF_rtl_0|auto_generated|ram_block1a50\ : std_logic;
SIGNAL \rf|RF_rtl_0|auto_generated|ram_block1a51\ : std_logic;
SIGNAL \rf|RF_rtl_0|auto_generated|ram_block1a52\ : std_logic;
SIGNAL \rf|RF_rtl_0|auto_generated|ram_block1a53\ : std_logic;
SIGNAL \rf|RF_rtl_0|auto_generated|ram_block1a54\ : std_logic;
SIGNAL \rf|RF_rtl_0|auto_generated|ram_block1a55\ : std_logic;
SIGNAL \rf|RF_rtl_0|auto_generated|ram_block1a56\ : std_logic;
SIGNAL \rf|RF_rtl_0|auto_generated|ram_block1a57\ : std_logic;
SIGNAL \rf|RF_rtl_0|auto_generated|ram_block1a58\ : std_logic;
SIGNAL \rf|RF_rtl_0|auto_generated|ram_block1a59\ : std_logic;
SIGNAL \rf|RF_rtl_0|auto_generated|ram_block1a60\ : std_logic;
SIGNAL \rf|RF_rtl_0|auto_generated|ram_block1a61\ : std_logic;
SIGNAL \rf|RF_rtl_0|auto_generated|ram_block1a62\ : std_logic;
SIGNAL \rf|RF_rtl_0|auto_generated|ram_block1a63\ : std_logic;
SIGNAL \rd_addr_i[0]~input_o\ : std_logic;
SIGNAL \rd_addr_r[0]~feeder_combout\ : std_logic;
SIGNAL \rd_addr_i[1]~input_o\ : std_logic;
SIGNAL \rd_addr_r[1]~feeder_combout\ : std_logic;
SIGNAL \rd_addr_i[2]~input_o\ : std_logic;
SIGNAL \rd_addr_r[2]~feeder_combout\ : std_logic;
SIGNAL \rd_addr_i[3]~input_o\ : std_logic;
SIGNAL \rd_addr_i[4]~input_o\ : std_logic;
SIGNAL \rf|RF_rtl_1|auto_generated|ram_block1a0~portbdataout\ : std_logic;
SIGNAL \rf|RF_rtl_1|auto_generated|ram_block1a1\ : std_logic;
SIGNAL \rf|RF_rtl_1|auto_generated|ram_block1a2\ : std_logic;
SIGNAL \rf|RF_rtl_1|auto_generated|ram_block1a3\ : std_logic;
SIGNAL \rf|RF_rtl_1|auto_generated|ram_block1a4\ : std_logic;
SIGNAL \rf|RF_rtl_1|auto_generated|ram_block1a5\ : std_logic;
SIGNAL \rf|RF_rtl_1|auto_generated|ram_block1a6\ : std_logic;
SIGNAL \rf|RF_rtl_1|auto_generated|ram_block1a7\ : std_logic;
SIGNAL \rf|RF_rtl_1|auto_generated|ram_block1a8\ : std_logic;
SIGNAL \rf|RF_rtl_1|auto_generated|ram_block1a9\ : std_logic;
SIGNAL \rf|RF_rtl_1|auto_generated|ram_block1a10\ : std_logic;
SIGNAL \rf|RF_rtl_1|auto_generated|ram_block1a11\ : std_logic;
SIGNAL \rf|RF_rtl_1|auto_generated|ram_block1a12\ : std_logic;
SIGNAL \rf|RF_rtl_1|auto_generated|ram_block1a13\ : std_logic;
SIGNAL \rf|RF_rtl_1|auto_generated|ram_block1a14\ : std_logic;
SIGNAL \rf|RF_rtl_1|auto_generated|ram_block1a15\ : std_logic;
SIGNAL \rf|RF_rtl_1|auto_generated|ram_block1a16\ : std_logic;
SIGNAL \rf|RF_rtl_1|auto_generated|ram_block1a17\ : std_logic;
SIGNAL \rf|RF_rtl_1|auto_generated|ram_block1a18\ : std_logic;
SIGNAL \rf|RF_rtl_1|auto_generated|ram_block1a19\ : std_logic;
SIGNAL \rf|RF_rtl_1|auto_generated|ram_block1a20\ : std_logic;
SIGNAL \rf|RF_rtl_1|auto_generated|ram_block1a21\ : std_logic;
SIGNAL \rf|RF_rtl_1|auto_generated|ram_block1a22\ : std_logic;
SIGNAL \rf|RF_rtl_1|auto_generated|ram_block1a23\ : std_logic;
SIGNAL \rf|RF_rtl_1|auto_generated|ram_block1a24\ : std_logic;
SIGNAL \rf|RF_rtl_1|auto_generated|ram_block1a25\ : std_logic;
SIGNAL \rf|RF_rtl_1|auto_generated|ram_block1a26\ : std_logic;
SIGNAL \rf|RF_rtl_1|auto_generated|ram_block1a27\ : std_logic;
SIGNAL \rf|RF_rtl_1|auto_generated|ram_block1a28\ : std_logic;
SIGNAL \rf|RF_rtl_1|auto_generated|ram_block1a29\ : std_logic;
SIGNAL \rf|RF_rtl_1|auto_generated|ram_block1a30\ : std_logic;
SIGNAL \rf|RF_rtl_1|auto_generated|ram_block1a31\ : std_logic;
SIGNAL \rf|RF_rtl_1|auto_generated|ram_block1a32\ : std_logic;
SIGNAL \rf|RF_rtl_1|auto_generated|ram_block1a33\ : std_logic;
SIGNAL \rf|RF_rtl_1|auto_generated|ram_block1a34\ : std_logic;
SIGNAL \rf|RF_rtl_1|auto_generated|ram_block1a35\ : std_logic;
SIGNAL \rf|RF_rtl_1|auto_generated|ram_block1a36\ : std_logic;
SIGNAL \rf|RF_rtl_1|auto_generated|ram_block1a37\ : std_logic;
SIGNAL \rf|RF_rtl_1|auto_generated|ram_block1a38\ : std_logic;
SIGNAL \rf|RF_rtl_1|auto_generated|ram_block1a39\ : std_logic;
SIGNAL \rf|RF_rtl_1|auto_generated|ram_block1a40~portbdataout\ : std_logic;
SIGNAL \rf|RF_rtl_1|auto_generated|ram_block1a41\ : std_logic;
SIGNAL \rf|RF_rtl_1|auto_generated|ram_block1a42\ : std_logic;
SIGNAL \rf|RF_rtl_1|auto_generated|ram_block1a43\ : std_logic;
SIGNAL \rf|RF_rtl_1|auto_generated|ram_block1a44\ : std_logic;
SIGNAL \rf|RF_rtl_1|auto_generated|ram_block1a45\ : std_logic;
SIGNAL \rf|RF_rtl_1|auto_generated|ram_block1a46\ : std_logic;
SIGNAL \rf|RF_rtl_1|auto_generated|ram_block1a47\ : std_logic;
SIGNAL \rf|RF_rtl_1|auto_generated|ram_block1a48\ : std_logic;
SIGNAL \rf|RF_rtl_1|auto_generated|ram_block1a49\ : std_logic;
SIGNAL \rf|RF_rtl_1|auto_generated|ram_block1a50\ : std_logic;
SIGNAL \rf|RF_rtl_1|auto_generated|ram_block1a51\ : std_logic;
SIGNAL \rf|RF_rtl_1|auto_generated|ram_block1a52\ : std_logic;
SIGNAL \rf|RF_rtl_1|auto_generated|ram_block1a53\ : std_logic;
SIGNAL \rf|RF_rtl_1|auto_generated|ram_block1a54\ : std_logic;
SIGNAL \rf|RF_rtl_1|auto_generated|ram_block1a55\ : std_logic;
SIGNAL \rf|RF_rtl_1|auto_generated|ram_block1a56\ : std_logic;
SIGNAL \rf|RF_rtl_1|auto_generated|ram_block1a57\ : std_logic;
SIGNAL \rf|RF_rtl_1|auto_generated|ram_block1a58\ : std_logic;
SIGNAL \rf|RF_rtl_1|auto_generated|ram_block1a59\ : std_logic;
SIGNAL \rf|RF_rtl_1|auto_generated|ram_block1a60\ : std_logic;
SIGNAL \rf|RF_rtl_1|auto_generated|ram_block1a61\ : std_logic;
SIGNAL \rf|RF_rtl_1|auto_generated|ram_block1a62\ : std_logic;
SIGNAL \rf|RF_rtl_1|auto_generated|ram_block1a63\ : std_logic;
SIGNAL w_data_r : std_logic_vector(63 DOWNTO 0);
SIGNAL w_addr_r : std_logic_vector(4 DOWNTO 0);
SIGNAL rs_addr_r : std_logic_vector(4 DOWNTO 0);
SIGNAL rd_addr_r : std_logic_vector(4 DOWNTO 0);
SIGNAL \ALT_INV_rd_addr_i[2]~input_o\ : std_logic;
SIGNAL \ALT_INV_rd_addr_i[1]~input_o\ : std_logic;
SIGNAL \ALT_INV_rd_addr_i[0]~input_o\ : std_logic;
SIGNAL \ALT_INV_w_data_i[62]~input_o\ : std_logic;
SIGNAL \ALT_INV_w_data_i[59]~input_o\ : std_logic;
SIGNAL \ALT_INV_w_data_i[57]~input_o\ : std_logic;
SIGNAL \ALT_INV_w_data_i[56]~input_o\ : std_logic;
SIGNAL \ALT_INV_w_data_i[55]~input_o\ : std_logic;
SIGNAL \ALT_INV_w_data_i[54]~input_o\ : std_logic;
SIGNAL \ALT_INV_w_data_i[53]~input_o\ : std_logic;
SIGNAL \ALT_INV_w_data_i[51]~input_o\ : std_logic;
SIGNAL \ALT_INV_w_data_i[50]~input_o\ : std_logic;
SIGNAL \ALT_INV_w_data_i[49]~input_o\ : std_logic;
SIGNAL \ALT_INV_w_data_i[47]~input_o\ : std_logic;
SIGNAL \ALT_INV_w_data_i[46]~input_o\ : std_logic;
SIGNAL \ALT_INV_w_data_i[45]~input_o\ : std_logic;
SIGNAL \ALT_INV_w_data_i[43]~input_o\ : std_logic;
SIGNAL \ALT_INV_w_data_i[42]~input_o\ : std_logic;
SIGNAL \ALT_INV_w_data_i[41]~input_o\ : std_logic;
SIGNAL \ALT_INV_w_data_i[39]~input_o\ : std_logic;
SIGNAL \ALT_INV_w_data_i[38]~input_o\ : std_logic;
SIGNAL \ALT_INV_w_data_i[37]~input_o\ : std_logic;
SIGNAL \ALT_INV_w_data_i[33]~input_o\ : std_logic;
SIGNAL \ALT_INV_w_data_i[31]~input_o\ : std_logic;
SIGNAL \ALT_INV_w_data_i[30]~input_o\ : std_logic;
SIGNAL \ALT_INV_w_data_i[29]~input_o\ : std_logic;
SIGNAL \ALT_INV_w_data_i[27]~input_o\ : std_logic;
SIGNAL \ALT_INV_w_data_i[24]~input_o\ : std_logic;
SIGNAL \ALT_INV_w_data_i[23]~input_o\ : std_logic;
SIGNAL \ALT_INV_w_data_i[19]~input_o\ : std_logic;
SIGNAL \ALT_INV_w_data_i[17]~input_o\ : std_logic;
SIGNAL \ALT_INV_w_data_i[16]~input_o\ : std_logic;
SIGNAL \ALT_INV_w_data_i[15]~input_o\ : std_logic;
SIGNAL \ALT_INV_w_data_i[13]~input_o\ : std_logic;
SIGNAL \ALT_INV_w_data_i[12]~input_o\ : std_logic;
SIGNAL \ALT_INV_w_data_i[11]~input_o\ : std_logic;
SIGNAL \ALT_INV_w_data_i[10]~input_o\ : std_logic;
SIGNAL \ALT_INV_w_data_i[8]~input_o\ : std_logic;
SIGNAL \ALT_INV_w_data_i[5]~input_o\ : std_logic;
SIGNAL \ALT_INV_rs_addr_i[4]~input_o\ : std_logic;
SIGNAL \ALT_INV_rs_addr_i[3]~input_o\ : std_logic;
SIGNAL \ALT_INV_rs_addr_i[0]~input_o\ : std_logic;
SIGNAL \ALT_INV_w_addr_i[3]~input_o\ : std_logic;
SIGNAL \ALT_INV_w_addr_i[2]~input_o\ : std_logic;
SIGNAL \ALT_INV_wen_i~input_o\ : std_logic;

BEGIN

ww_clk <= clk;
ww_rs_addr_i <= rs_addr_i;
ww_rd_addr_i <= rd_addr_i;
ww_w_addr_i <= w_addr_i;
ww_wen_i <= wen_i;
ww_w_data_i <= w_data_i;
rs_val_o <= ww_rs_val_o;
rd_val_o <= ww_rd_val_o;
ww_devoe <= devoe;
ww_devclrn <= devclrn;
ww_devpor <= devpor;

\rf|RF_rtl_0|auto_generated|ram_block1a0_PORTADATAIN_bus\ <= (w_data_r(39) & w_data_r(38) & w_data_r(37) & w_data_r(36) & w_data_r(35) & w_data_r(34) & w_data_r(33) & w_data_r(32) & w_data_r(31) & w_data_r(30) & w_data_r(29) & w_data_r(28) & 
w_data_r(27) & w_data_r(26) & w_data_r(25) & w_data_r(24) & w_data_r(23) & w_data_r(22) & w_data_r(21) & w_data_r(20) & w_data_r(19) & w_data_r(18) & w_data_r(17) & w_data_r(16) & w_data_r(15) & w_data_r(14) & w_data_r(13) & w_data_r(12)
& w_data_r(11) & w_data_r(10) & w_data_r(9) & w_data_r(8) & w_data_r(7) & w_data_r(6) & w_data_r(5) & w_data_r(4) & w_data_r(3) & w_data_r(2) & w_data_r(1) & w_data_r(0));

\rf|RF_rtl_0|auto_generated|ram_block1a0_PORTAADDR_bus\ <= (w_addr_r(4) & w_addr_r(3) & w_addr_r(2) & w_addr_r(1) & w_addr_r(0));

\rf|RF_rtl_0|auto_generated|ram_block1a0_PORTBADDR_bus\ <= (rs_addr_r(4) & rs_addr_r(3) & rs_addr_r(2) & rs_addr_r(1) & rs_addr_r(0));

\rf|RF_rtl_0|auto_generated|ram_block1a0~portbdataout\ <= \rf|RF_rtl_0|auto_generated|ram_block1a0_PORTBDATAOUT_bus\(0);
\rf|RF_rtl_0|auto_generated|ram_block1a1\ <= \rf|RF_rtl_0|auto_generated|ram_block1a0_PORTBDATAOUT_bus\(1);
\rf|RF_rtl_0|auto_generated|ram_block1a2\ <= \rf|RF_rtl_0|auto_generated|ram_block1a0_PORTBDATAOUT_bus\(2);
\rf|RF_rtl_0|auto_generated|ram_block1a3\ <= \rf|RF_rtl_0|auto_generated|ram_block1a0_PORTBDATAOUT_bus\(3);
\rf|RF_rtl_0|auto_generated|ram_block1a4\ <= \rf|RF_rtl_0|auto_generated|ram_block1a0_PORTBDATAOUT_bus\(4);
\rf|RF_rtl_0|auto_generated|ram_block1a5\ <= \rf|RF_rtl_0|auto_generated|ram_block1a0_PORTBDATAOUT_bus\(5);
\rf|RF_rtl_0|auto_generated|ram_block1a6\ <= \rf|RF_rtl_0|auto_generated|ram_block1a0_PORTBDATAOUT_bus\(6);
\rf|RF_rtl_0|auto_generated|ram_block1a7\ <= \rf|RF_rtl_0|auto_generated|ram_block1a0_PORTBDATAOUT_bus\(7);
\rf|RF_rtl_0|auto_generated|ram_block1a8\ <= \rf|RF_rtl_0|auto_generated|ram_block1a0_PORTBDATAOUT_bus\(8);
\rf|RF_rtl_0|auto_generated|ram_block1a9\ <= \rf|RF_rtl_0|auto_generated|ram_block1a0_PORTBDATAOUT_bus\(9);
\rf|RF_rtl_0|auto_generated|ram_block1a10\ <= \rf|RF_rtl_0|auto_generated|ram_block1a0_PORTBDATAOUT_bus\(10);
\rf|RF_rtl_0|auto_generated|ram_block1a11\ <= \rf|RF_rtl_0|auto_generated|ram_block1a0_PORTBDATAOUT_bus\(11);
\rf|RF_rtl_0|auto_generated|ram_block1a12\ <= \rf|RF_rtl_0|auto_generated|ram_block1a0_PORTBDATAOUT_bus\(12);
\rf|RF_rtl_0|auto_generated|ram_block1a13\ <= \rf|RF_rtl_0|auto_generated|ram_block1a0_PORTBDATAOUT_bus\(13);
\rf|RF_rtl_0|auto_generated|ram_block1a14\ <= \rf|RF_rtl_0|auto_generated|ram_block1a0_PORTBDATAOUT_bus\(14);
\rf|RF_rtl_0|auto_generated|ram_block1a15\ <= \rf|RF_rtl_0|auto_generated|ram_block1a0_PORTBDATAOUT_bus\(15);
\rf|RF_rtl_0|auto_generated|ram_block1a16\ <= \rf|RF_rtl_0|auto_generated|ram_block1a0_PORTBDATAOUT_bus\(16);
\rf|RF_rtl_0|auto_generated|ram_block1a17\ <= \rf|RF_rtl_0|auto_generated|ram_block1a0_PORTBDATAOUT_bus\(17);
\rf|RF_rtl_0|auto_generated|ram_block1a18\ <= \rf|RF_rtl_0|auto_generated|ram_block1a0_PORTBDATAOUT_bus\(18);
\rf|RF_rtl_0|auto_generated|ram_block1a19\ <= \rf|RF_rtl_0|auto_generated|ram_block1a0_PORTBDATAOUT_bus\(19);
\rf|RF_rtl_0|auto_generated|ram_block1a20\ <= \rf|RF_rtl_0|auto_generated|ram_block1a0_PORTBDATAOUT_bus\(20);
\rf|RF_rtl_0|auto_generated|ram_block1a21\ <= \rf|RF_rtl_0|auto_generated|ram_block1a0_PORTBDATAOUT_bus\(21);
\rf|RF_rtl_0|auto_generated|ram_block1a22\ <= \rf|RF_rtl_0|auto_generated|ram_block1a0_PORTBDATAOUT_bus\(22);
\rf|RF_rtl_0|auto_generated|ram_block1a23\ <= \rf|RF_rtl_0|auto_generated|ram_block1a0_PORTBDATAOUT_bus\(23);
\rf|RF_rtl_0|auto_generated|ram_block1a24\ <= \rf|RF_rtl_0|auto_generated|ram_block1a0_PORTBDATAOUT_bus\(24);
\rf|RF_rtl_0|auto_generated|ram_block1a25\ <= \rf|RF_rtl_0|auto_generated|ram_block1a0_PORTBDATAOUT_bus\(25);
\rf|RF_rtl_0|auto_generated|ram_block1a26\ <= \rf|RF_rtl_0|auto_generated|ram_block1a0_PORTBDATAOUT_bus\(26);
\rf|RF_rtl_0|auto_generated|ram_block1a27\ <= \rf|RF_rtl_0|auto_generated|ram_block1a0_PORTBDATAOUT_bus\(27);
\rf|RF_rtl_0|auto_generated|ram_block1a28\ <= \rf|RF_rtl_0|auto_generated|ram_block1a0_PORTBDATAOUT_bus\(28);
\rf|RF_rtl_0|auto_generated|ram_block1a29\ <= \rf|RF_rtl_0|auto_generated|ram_block1a0_PORTBDATAOUT_bus\(29);
\rf|RF_rtl_0|auto_generated|ram_block1a30\ <= \rf|RF_rtl_0|auto_generated|ram_block1a0_PORTBDATAOUT_bus\(30);
\rf|RF_rtl_0|auto_generated|ram_block1a31\ <= \rf|RF_rtl_0|auto_generated|ram_block1a0_PORTBDATAOUT_bus\(31);
\rf|RF_rtl_0|auto_generated|ram_block1a32\ <= \rf|RF_rtl_0|auto_generated|ram_block1a0_PORTBDATAOUT_bus\(32);
\rf|RF_rtl_0|auto_generated|ram_block1a33\ <= \rf|RF_rtl_0|auto_generated|ram_block1a0_PORTBDATAOUT_bus\(33);
\rf|RF_rtl_0|auto_generated|ram_block1a34\ <= \rf|RF_rtl_0|auto_generated|ram_block1a0_PORTBDATAOUT_bus\(34);
\rf|RF_rtl_0|auto_generated|ram_block1a35\ <= \rf|RF_rtl_0|auto_generated|ram_block1a0_PORTBDATAOUT_bus\(35);
\rf|RF_rtl_0|auto_generated|ram_block1a36\ <= \rf|RF_rtl_0|auto_generated|ram_block1a0_PORTBDATAOUT_bus\(36);
\rf|RF_rtl_0|auto_generated|ram_block1a37\ <= \rf|RF_rtl_0|auto_generated|ram_block1a0_PORTBDATAOUT_bus\(37);
\rf|RF_rtl_0|auto_generated|ram_block1a38\ <= \rf|RF_rtl_0|auto_generated|ram_block1a0_PORTBDATAOUT_bus\(38);
\rf|RF_rtl_0|auto_generated|ram_block1a39\ <= \rf|RF_rtl_0|auto_generated|ram_block1a0_PORTBDATAOUT_bus\(39);

\rf|RF_rtl_0|auto_generated|ram_block1a40_PORTADATAIN_bus\ <= (gnd & gnd & gnd & gnd & gnd & gnd & gnd & gnd & gnd & gnd & gnd & gnd & gnd & gnd & gnd & gnd & w_data_r(63) & w_data_r(62) & w_data_r(61) & w_data_r(60) & w_data_r(59) & w_data_r(58) & 
w_data_r(57) & w_data_r(56) & w_data_r(55) & w_data_r(54) & w_data_r(53) & w_data_r(52) & w_data_r(51) & w_data_r(50) & w_data_r(49) & w_data_r(48) & w_data_r(47) & w_data_r(46) & w_data_r(45) & w_data_r(44) & w_data_r(43) & w_data_r(42)
& w_data_r(41) & w_data_r(40));

\rf|RF_rtl_0|auto_generated|ram_block1a40_PORTAADDR_bus\ <= (w_addr_r(4) & w_addr_r(3) & w_addr_r(2) & w_addr_r(1) & w_addr_r(0));

\rf|RF_rtl_0|auto_generated|ram_block1a40_PORTBADDR_bus\ <= (rs_addr_r(4) & rs_addr_r(3) & rs_addr_r(2) & rs_addr_r(1) & rs_addr_r(0));

\rf|RF_rtl_0|auto_generated|ram_block1a40~portbdataout\ <= \rf|RF_rtl_0|auto_generated|ram_block1a40_PORTBDATAOUT_bus\(0);
\rf|RF_rtl_0|auto_generated|ram_block1a41\ <= \rf|RF_rtl_0|auto_generated|ram_block1a40_PORTBDATAOUT_bus\(1);
\rf|RF_rtl_0|auto_generated|ram_block1a42\ <= \rf|RF_rtl_0|auto_generated|ram_block1a40_PORTBDATAOUT_bus\(2);
\rf|RF_rtl_0|auto_generated|ram_block1a43\ <= \rf|RF_rtl_0|auto_generated|ram_block1a40_PORTBDATAOUT_bus\(3);
\rf|RF_rtl_0|auto_generated|ram_block1a44\ <= \rf|RF_rtl_0|auto_generated|ram_block1a40_PORTBDATAOUT_bus\(4);
\rf|RF_rtl_0|auto_generated|ram_block1a45\ <= \rf|RF_rtl_0|auto_generated|ram_block1a40_PORTBDATAOUT_bus\(5);
\rf|RF_rtl_0|auto_generated|ram_block1a46\ <= \rf|RF_rtl_0|auto_generated|ram_block1a40_PORTBDATAOUT_bus\(6);
\rf|RF_rtl_0|auto_generated|ram_block1a47\ <= \rf|RF_rtl_0|auto_generated|ram_block1a40_PORTBDATAOUT_bus\(7);
\rf|RF_rtl_0|auto_generated|ram_block1a48\ <= \rf|RF_rtl_0|auto_generated|ram_block1a40_PORTBDATAOUT_bus\(8);
\rf|RF_rtl_0|auto_generated|ram_block1a49\ <= \rf|RF_rtl_0|auto_generated|ram_block1a40_PORTBDATAOUT_bus\(9);
\rf|RF_rtl_0|auto_generated|ram_block1a50\ <= \rf|RF_rtl_0|auto_generated|ram_block1a40_PORTBDATAOUT_bus\(10);
\rf|RF_rtl_0|auto_generated|ram_block1a51\ <= \rf|RF_rtl_0|auto_generated|ram_block1a40_PORTBDATAOUT_bus\(11);
\rf|RF_rtl_0|auto_generated|ram_block1a52\ <= \rf|RF_rtl_0|auto_generated|ram_block1a40_PORTBDATAOUT_bus\(12);
\rf|RF_rtl_0|auto_generated|ram_block1a53\ <= \rf|RF_rtl_0|auto_generated|ram_block1a40_PORTBDATAOUT_bus\(13);
\rf|RF_rtl_0|auto_generated|ram_block1a54\ <= \rf|RF_rtl_0|auto_generated|ram_block1a40_PORTBDATAOUT_bus\(14);
\rf|RF_rtl_0|auto_generated|ram_block1a55\ <= \rf|RF_rtl_0|auto_generated|ram_block1a40_PORTBDATAOUT_bus\(15);
\rf|RF_rtl_0|auto_generated|ram_block1a56\ <= \rf|RF_rtl_0|auto_generated|ram_block1a40_PORTBDATAOUT_bus\(16);
\rf|RF_rtl_0|auto_generated|ram_block1a57\ <= \rf|RF_rtl_0|auto_generated|ram_block1a40_PORTBDATAOUT_bus\(17);
\rf|RF_rtl_0|auto_generated|ram_block1a58\ <= \rf|RF_rtl_0|auto_generated|ram_block1a40_PORTBDATAOUT_bus\(18);
\rf|RF_rtl_0|auto_generated|ram_block1a59\ <= \rf|RF_rtl_0|auto_generated|ram_block1a40_PORTBDATAOUT_bus\(19);
\rf|RF_rtl_0|auto_generated|ram_block1a60\ <= \rf|RF_rtl_0|auto_generated|ram_block1a40_PORTBDATAOUT_bus\(20);
\rf|RF_rtl_0|auto_generated|ram_block1a61\ <= \rf|RF_rtl_0|auto_generated|ram_block1a40_PORTBDATAOUT_bus\(21);
\rf|RF_rtl_0|auto_generated|ram_block1a62\ <= \rf|RF_rtl_0|auto_generated|ram_block1a40_PORTBDATAOUT_bus\(22);
\rf|RF_rtl_0|auto_generated|ram_block1a63\ <= \rf|RF_rtl_0|auto_generated|ram_block1a40_PORTBDATAOUT_bus\(23);

\rf|RF_rtl_1|auto_generated|ram_block1a0_PORTADATAIN_bus\ <= (w_data_r(39) & w_data_r(38) & w_data_r(37) & w_data_r(36) & w_data_r(35) & w_data_r(34) & w_data_r(33) & w_data_r(32) & w_data_r(31) & w_data_r(30) & w_data_r(29) & w_data_r(28) & 
w_data_r(27) & w_data_r(26) & w_data_r(25) & w_data_r(24) & w_data_r(23) & w_data_r(22) & w_data_r(21) & w_data_r(20) & w_data_r(19) & w_data_r(18) & w_data_r(17) & w_data_r(16) & w_data_r(15) & w_data_r(14) & w_data_r(13) & w_data_r(12)
& w_data_r(11) & w_data_r(10) & w_data_r(9) & w_data_r(8) & w_data_r(7) & w_data_r(6) & w_data_r(5) & w_data_r(4) & w_data_r(3) & w_data_r(2) & w_data_r(1) & w_data_r(0));

\rf|RF_rtl_1|auto_generated|ram_block1a0_PORTAADDR_bus\ <= (w_addr_r(4) & w_addr_r(3) & w_addr_r(2) & w_addr_r(1) & w_addr_r(0));

\rf|RF_rtl_1|auto_generated|ram_block1a0_PORTBADDR_bus\ <= (rd_addr_r(4) & rd_addr_r(3) & rd_addr_r(2) & rd_addr_r(1) & rd_addr_r(0));

\rf|RF_rtl_1|auto_generated|ram_block1a0~portbdataout\ <= \rf|RF_rtl_1|auto_generated|ram_block1a0_PORTBDATAOUT_bus\(0);
\rf|RF_rtl_1|auto_generated|ram_block1a1\ <= \rf|RF_rtl_1|auto_generated|ram_block1a0_PORTBDATAOUT_bus\(1);
\rf|RF_rtl_1|auto_generated|ram_block1a2\ <= \rf|RF_rtl_1|auto_generated|ram_block1a0_PORTBDATAOUT_bus\(2);
\rf|RF_rtl_1|auto_generated|ram_block1a3\ <= \rf|RF_rtl_1|auto_generated|ram_block1a0_PORTBDATAOUT_bus\(3);
\rf|RF_rtl_1|auto_generated|ram_block1a4\ <= \rf|RF_rtl_1|auto_generated|ram_block1a0_PORTBDATAOUT_bus\(4);
\rf|RF_rtl_1|auto_generated|ram_block1a5\ <= \rf|RF_rtl_1|auto_generated|ram_block1a0_PORTBDATAOUT_bus\(5);
\rf|RF_rtl_1|auto_generated|ram_block1a6\ <= \rf|RF_rtl_1|auto_generated|ram_block1a0_PORTBDATAOUT_bus\(6);
\rf|RF_rtl_1|auto_generated|ram_block1a7\ <= \rf|RF_rtl_1|auto_generated|ram_block1a0_PORTBDATAOUT_bus\(7);
\rf|RF_rtl_1|auto_generated|ram_block1a8\ <= \rf|RF_rtl_1|auto_generated|ram_block1a0_PORTBDATAOUT_bus\(8);
\rf|RF_rtl_1|auto_generated|ram_block1a9\ <= \rf|RF_rtl_1|auto_generated|ram_block1a0_PORTBDATAOUT_bus\(9);
\rf|RF_rtl_1|auto_generated|ram_block1a10\ <= \rf|RF_rtl_1|auto_generated|ram_block1a0_PORTBDATAOUT_bus\(10);
\rf|RF_rtl_1|auto_generated|ram_block1a11\ <= \rf|RF_rtl_1|auto_generated|ram_block1a0_PORTBDATAOUT_bus\(11);
\rf|RF_rtl_1|auto_generated|ram_block1a12\ <= \rf|RF_rtl_1|auto_generated|ram_block1a0_PORTBDATAOUT_bus\(12);
\rf|RF_rtl_1|auto_generated|ram_block1a13\ <= \rf|RF_rtl_1|auto_generated|ram_block1a0_PORTBDATAOUT_bus\(13);
\rf|RF_rtl_1|auto_generated|ram_block1a14\ <= \rf|RF_rtl_1|auto_generated|ram_block1a0_PORTBDATAOUT_bus\(14);
\rf|RF_rtl_1|auto_generated|ram_block1a15\ <= \rf|RF_rtl_1|auto_generated|ram_block1a0_PORTBDATAOUT_bus\(15);
\rf|RF_rtl_1|auto_generated|ram_block1a16\ <= \rf|RF_rtl_1|auto_generated|ram_block1a0_PORTBDATAOUT_bus\(16);
\rf|RF_rtl_1|auto_generated|ram_block1a17\ <= \rf|RF_rtl_1|auto_generated|ram_block1a0_PORTBDATAOUT_bus\(17);
\rf|RF_rtl_1|auto_generated|ram_block1a18\ <= \rf|RF_rtl_1|auto_generated|ram_block1a0_PORTBDATAOUT_bus\(18);
\rf|RF_rtl_1|auto_generated|ram_block1a19\ <= \rf|RF_rtl_1|auto_generated|ram_block1a0_PORTBDATAOUT_bus\(19);
\rf|RF_rtl_1|auto_generated|ram_block1a20\ <= \rf|RF_rtl_1|auto_generated|ram_block1a0_PORTBDATAOUT_bus\(20);
\rf|RF_rtl_1|auto_generated|ram_block1a21\ <= \rf|RF_rtl_1|auto_generated|ram_block1a0_PORTBDATAOUT_bus\(21);
\rf|RF_rtl_1|auto_generated|ram_block1a22\ <= \rf|RF_rtl_1|auto_generated|ram_block1a0_PORTBDATAOUT_bus\(22);
\rf|RF_rtl_1|auto_generated|ram_block1a23\ <= \rf|RF_rtl_1|auto_generated|ram_block1a0_PORTBDATAOUT_bus\(23);
\rf|RF_rtl_1|auto_generated|ram_block1a24\ <= \rf|RF_rtl_1|auto_generated|ram_block1a0_PORTBDATAOUT_bus\(24);
\rf|RF_rtl_1|auto_generated|ram_block1a25\ <= \rf|RF_rtl_1|auto_generated|ram_block1a0_PORTBDATAOUT_bus\(25);
\rf|RF_rtl_1|auto_generated|ram_block1a26\ <= \rf|RF_rtl_1|auto_generated|ram_block1a0_PORTBDATAOUT_bus\(26);
\rf|RF_rtl_1|auto_generated|ram_block1a27\ <= \rf|RF_rtl_1|auto_generated|ram_block1a0_PORTBDATAOUT_bus\(27);
\rf|RF_rtl_1|auto_generated|ram_block1a28\ <= \rf|RF_rtl_1|auto_generated|ram_block1a0_PORTBDATAOUT_bus\(28);
\rf|RF_rtl_1|auto_generated|ram_block1a29\ <= \rf|RF_rtl_1|auto_generated|ram_block1a0_PORTBDATAOUT_bus\(29);
\rf|RF_rtl_1|auto_generated|ram_block1a30\ <= \rf|RF_rtl_1|auto_generated|ram_block1a0_PORTBDATAOUT_bus\(30);
\rf|RF_rtl_1|auto_generated|ram_block1a31\ <= \rf|RF_rtl_1|auto_generated|ram_block1a0_PORTBDATAOUT_bus\(31);
\rf|RF_rtl_1|auto_generated|ram_block1a32\ <= \rf|RF_rtl_1|auto_generated|ram_block1a0_PORTBDATAOUT_bus\(32);
\rf|RF_rtl_1|auto_generated|ram_block1a33\ <= \rf|RF_rtl_1|auto_generated|ram_block1a0_PORTBDATAOUT_bus\(33);
\rf|RF_rtl_1|auto_generated|ram_block1a34\ <= \rf|RF_rtl_1|auto_generated|ram_block1a0_PORTBDATAOUT_bus\(34);
\rf|RF_rtl_1|auto_generated|ram_block1a35\ <= \rf|RF_rtl_1|auto_generated|ram_block1a0_PORTBDATAOUT_bus\(35);
\rf|RF_rtl_1|auto_generated|ram_block1a36\ <= \rf|RF_rtl_1|auto_generated|ram_block1a0_PORTBDATAOUT_bus\(36);
\rf|RF_rtl_1|auto_generated|ram_block1a37\ <= \rf|RF_rtl_1|auto_generated|ram_block1a0_PORTBDATAOUT_bus\(37);
\rf|RF_rtl_1|auto_generated|ram_block1a38\ <= \rf|RF_rtl_1|auto_generated|ram_block1a0_PORTBDATAOUT_bus\(38);
\rf|RF_rtl_1|auto_generated|ram_block1a39\ <= \rf|RF_rtl_1|auto_generated|ram_block1a0_PORTBDATAOUT_bus\(39);

\rf|RF_rtl_1|auto_generated|ram_block1a40_PORTADATAIN_bus\ <= (gnd & gnd & gnd & gnd & gnd & gnd & gnd & gnd & gnd & gnd & gnd & gnd & gnd & gnd & gnd & gnd & w_data_r(63) & w_data_r(62) & w_data_r(61) & w_data_r(60) & w_data_r(59) & w_data_r(58) & 
w_data_r(57) & w_data_r(56) & w_data_r(55) & w_data_r(54) & w_data_r(53) & w_data_r(52) & w_data_r(51) & w_data_r(50) & w_data_r(49) & w_data_r(48) & w_data_r(47) & w_data_r(46) & w_data_r(45) & w_data_r(44) & w_data_r(43) & w_data_r(42)
& w_data_r(41) & w_data_r(40));

\rf|RF_rtl_1|auto_generated|ram_block1a40_PORTAADDR_bus\ <= (w_addr_r(4) & w_addr_r(3) & w_addr_r(2) & w_addr_r(1) & w_addr_r(0));

\rf|RF_rtl_1|auto_generated|ram_block1a40_PORTBADDR_bus\ <= (rd_addr_r(4) & rd_addr_r(3) & rd_addr_r(2) & rd_addr_r(1) & rd_addr_r(0));

\rf|RF_rtl_1|auto_generated|ram_block1a40~portbdataout\ <= \rf|RF_rtl_1|auto_generated|ram_block1a40_PORTBDATAOUT_bus\(0);
\rf|RF_rtl_1|auto_generated|ram_block1a41\ <= \rf|RF_rtl_1|auto_generated|ram_block1a40_PORTBDATAOUT_bus\(1);
\rf|RF_rtl_1|auto_generated|ram_block1a42\ <= \rf|RF_rtl_1|auto_generated|ram_block1a40_PORTBDATAOUT_bus\(2);
\rf|RF_rtl_1|auto_generated|ram_block1a43\ <= \rf|RF_rtl_1|auto_generated|ram_block1a40_PORTBDATAOUT_bus\(3);
\rf|RF_rtl_1|auto_generated|ram_block1a44\ <= \rf|RF_rtl_1|auto_generated|ram_block1a40_PORTBDATAOUT_bus\(4);
\rf|RF_rtl_1|auto_generated|ram_block1a45\ <= \rf|RF_rtl_1|auto_generated|ram_block1a40_PORTBDATAOUT_bus\(5);
\rf|RF_rtl_1|auto_generated|ram_block1a46\ <= \rf|RF_rtl_1|auto_generated|ram_block1a40_PORTBDATAOUT_bus\(6);
\rf|RF_rtl_1|auto_generated|ram_block1a47\ <= \rf|RF_rtl_1|auto_generated|ram_block1a40_PORTBDATAOUT_bus\(7);
\rf|RF_rtl_1|auto_generated|ram_block1a48\ <= \rf|RF_rtl_1|auto_generated|ram_block1a40_PORTBDATAOUT_bus\(8);
\rf|RF_rtl_1|auto_generated|ram_block1a49\ <= \rf|RF_rtl_1|auto_generated|ram_block1a40_PORTBDATAOUT_bus\(9);
\rf|RF_rtl_1|auto_generated|ram_block1a50\ <= \rf|RF_rtl_1|auto_generated|ram_block1a40_PORTBDATAOUT_bus\(10);
\rf|RF_rtl_1|auto_generated|ram_block1a51\ <= \rf|RF_rtl_1|auto_generated|ram_block1a40_PORTBDATAOUT_bus\(11);
\rf|RF_rtl_1|auto_generated|ram_block1a52\ <= \rf|RF_rtl_1|auto_generated|ram_block1a40_PORTBDATAOUT_bus\(12);
\rf|RF_rtl_1|auto_generated|ram_block1a53\ <= \rf|RF_rtl_1|auto_generated|ram_block1a40_PORTBDATAOUT_bus\(13);
\rf|RF_rtl_1|auto_generated|ram_block1a54\ <= \rf|RF_rtl_1|auto_generated|ram_block1a40_PORTBDATAOUT_bus\(14);
\rf|RF_rtl_1|auto_generated|ram_block1a55\ <= \rf|RF_rtl_1|auto_generated|ram_block1a40_PORTBDATAOUT_bus\(15);
\rf|RF_rtl_1|auto_generated|ram_block1a56\ <= \rf|RF_rtl_1|auto_generated|ram_block1a40_PORTBDATAOUT_bus\(16);
\rf|RF_rtl_1|auto_generated|ram_block1a57\ <= \rf|RF_rtl_1|auto_generated|ram_block1a40_PORTBDATAOUT_bus\(17);
\rf|RF_rtl_1|auto_generated|ram_block1a58\ <= \rf|RF_rtl_1|auto_generated|ram_block1a40_PORTBDATAOUT_bus\(18);
\rf|RF_rtl_1|auto_generated|ram_block1a59\ <= \rf|RF_rtl_1|auto_generated|ram_block1a40_PORTBDATAOUT_bus\(19);
\rf|RF_rtl_1|auto_generated|ram_block1a60\ <= \rf|RF_rtl_1|auto_generated|ram_block1a40_PORTBDATAOUT_bus\(20);
\rf|RF_rtl_1|auto_generated|ram_block1a61\ <= \rf|RF_rtl_1|auto_generated|ram_block1a40_PORTBDATAOUT_bus\(21);
\rf|RF_rtl_1|auto_generated|ram_block1a62\ <= \rf|RF_rtl_1|auto_generated|ram_block1a40_PORTBDATAOUT_bus\(22);
\rf|RF_rtl_1|auto_generated|ram_block1a63\ <= \rf|RF_rtl_1|auto_generated|ram_block1a40_PORTBDATAOUT_bus\(23);
\ALT_INV_rd_addr_i[2]~input_o\ <= NOT \rd_addr_i[2]~input_o\;
\ALT_INV_rd_addr_i[1]~input_o\ <= NOT \rd_addr_i[1]~input_o\;
\ALT_INV_rd_addr_i[0]~input_o\ <= NOT \rd_addr_i[0]~input_o\;
\ALT_INV_w_data_i[62]~input_o\ <= NOT \w_data_i[62]~input_o\;
\ALT_INV_w_data_i[59]~input_o\ <= NOT \w_data_i[59]~input_o\;
\ALT_INV_w_data_i[57]~input_o\ <= NOT \w_data_i[57]~input_o\;
\ALT_INV_w_data_i[56]~input_o\ <= NOT \w_data_i[56]~input_o\;
\ALT_INV_w_data_i[55]~input_o\ <= NOT \w_data_i[55]~input_o\;
\ALT_INV_w_data_i[54]~input_o\ <= NOT \w_data_i[54]~input_o\;
\ALT_INV_w_data_i[53]~input_o\ <= NOT \w_data_i[53]~input_o\;
\ALT_INV_w_data_i[51]~input_o\ <= NOT \w_data_i[51]~input_o\;
\ALT_INV_w_data_i[50]~input_o\ <= NOT \w_data_i[50]~input_o\;
\ALT_INV_w_data_i[49]~input_o\ <= NOT \w_data_i[49]~input_o\;
\ALT_INV_w_data_i[47]~input_o\ <= NOT \w_data_i[47]~input_o\;
\ALT_INV_w_data_i[46]~input_o\ <= NOT \w_data_i[46]~input_o\;
\ALT_INV_w_data_i[45]~input_o\ <= NOT \w_data_i[45]~input_o\;
\ALT_INV_w_data_i[43]~input_o\ <= NOT \w_data_i[43]~input_o\;
\ALT_INV_w_data_i[42]~input_o\ <= NOT \w_data_i[42]~input_o\;
\ALT_INV_w_data_i[41]~input_o\ <= NOT \w_data_i[41]~input_o\;
\ALT_INV_w_data_i[39]~input_o\ <= NOT \w_data_i[39]~input_o\;
\ALT_INV_w_data_i[38]~input_o\ <= NOT \w_data_i[38]~input_o\;
\ALT_INV_w_data_i[37]~input_o\ <= NOT \w_data_i[37]~input_o\;
\ALT_INV_w_data_i[33]~input_o\ <= NOT \w_data_i[33]~input_o\;
\ALT_INV_w_data_i[31]~input_o\ <= NOT \w_data_i[31]~input_o\;
\ALT_INV_w_data_i[30]~input_o\ <= NOT \w_data_i[30]~input_o\;
\ALT_INV_w_data_i[29]~input_o\ <= NOT \w_data_i[29]~input_o\;
\ALT_INV_w_data_i[27]~input_o\ <= NOT \w_data_i[27]~input_o\;
\ALT_INV_w_data_i[24]~input_o\ <= NOT \w_data_i[24]~input_o\;
\ALT_INV_w_data_i[23]~input_o\ <= NOT \w_data_i[23]~input_o\;
\ALT_INV_w_data_i[19]~input_o\ <= NOT \w_data_i[19]~input_o\;
\ALT_INV_w_data_i[17]~input_o\ <= NOT \w_data_i[17]~input_o\;
\ALT_INV_w_data_i[16]~input_o\ <= NOT \w_data_i[16]~input_o\;
\ALT_INV_w_data_i[15]~input_o\ <= NOT \w_data_i[15]~input_o\;
\ALT_INV_w_data_i[13]~input_o\ <= NOT \w_data_i[13]~input_o\;
\ALT_INV_w_data_i[12]~input_o\ <= NOT \w_data_i[12]~input_o\;
\ALT_INV_w_data_i[11]~input_o\ <= NOT \w_data_i[11]~input_o\;
\ALT_INV_w_data_i[10]~input_o\ <= NOT \w_data_i[10]~input_o\;
\ALT_INV_w_data_i[8]~input_o\ <= NOT \w_data_i[8]~input_o\;
\ALT_INV_w_data_i[5]~input_o\ <= NOT \w_data_i[5]~input_o\;
\ALT_INV_rs_addr_i[4]~input_o\ <= NOT \rs_addr_i[4]~input_o\;
\ALT_INV_rs_addr_i[3]~input_o\ <= NOT \rs_addr_i[3]~input_o\;
\ALT_INV_rs_addr_i[0]~input_o\ <= NOT \rs_addr_i[0]~input_o\;
\ALT_INV_w_addr_i[3]~input_o\ <= NOT \w_addr_i[3]~input_o\;
\ALT_INV_w_addr_i[2]~input_o\ <= NOT \w_addr_i[2]~input_o\;
\ALT_INV_wen_i~input_o\ <= NOT \wen_i~input_o\;

-- Location: IOOBUF_X86_Y81_N19
\rs_val_o[0]~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \rf|RF_rtl_0|auto_generated|ram_block1a0~portbdataout\,
	devoe => ww_devoe,
	o => ww_rs_val_o(0));

-- Location: IOOBUF_X52_Y81_N19
\rs_val_o[1]~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \rf|RF_rtl_0|auto_generated|ram_block1a1\,
	devoe => ww_devoe,
	o => ww_rs_val_o(1));

-- Location: IOOBUF_X89_Y6_N22
\rs_val_o[2]~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \rf|RF_rtl_0|auto_generated|ram_block1a2\,
	devoe => ww_devoe,
	o => ww_rs_val_o(2));

-- Location: IOOBUF_X84_Y81_N36
\rs_val_o[3]~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \rf|RF_rtl_0|auto_generated|ram_block1a3\,
	devoe => ww_devoe,
	o => ww_rs_val_o(3));

-- Location: IOOBUF_X60_Y0_N19
\rs_val_o[4]~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \rf|RF_rtl_0|auto_generated|ram_block1a4\,
	devoe => ww_devoe,
	o => ww_rs_val_o(4));

-- Location: IOOBUF_X40_Y81_N19
\rs_val_o[5]~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \rf|RF_rtl_0|auto_generated|ram_block1a5\,
	devoe => ww_devoe,
	o => ww_rs_val_o(5));

-- Location: IOOBUF_X40_Y0_N19
\rs_val_o[6]~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \rf|RF_rtl_0|auto_generated|ram_block1a6\,
	devoe => ww_devoe,
	o => ww_rs_val_o(6));

-- Location: IOOBUF_X78_Y81_N53
\rs_val_o[7]~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \rf|RF_rtl_0|auto_generated|ram_block1a7\,
	devoe => ww_devoe,
	o => ww_rs_val_o(7));

-- Location: IOOBUF_X40_Y0_N36
\rs_val_o[8]~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \rf|RF_rtl_0|auto_generated|ram_block1a8\,
	devoe => ww_devoe,
	o => ww_rs_val_o(8));

-- Location: IOOBUF_X89_Y37_N56
\rs_val_o[9]~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \rf|RF_rtl_0|auto_generated|ram_block1a9\,
	devoe => ww_devoe,
	o => ww_rs_val_o(9));

-- Location: IOOBUF_X38_Y81_N36
\rs_val_o[10]~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \rf|RF_rtl_0|auto_generated|ram_block1a10\,
	devoe => ww_devoe,
	o => ww_rs_val_o(10));

-- Location: IOOBUF_X89_Y4_N96
\rs_val_o[11]~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \rf|RF_rtl_0|auto_generated|ram_block1a11\,
	devoe => ww_devoe,
	o => ww_rs_val_o(11));

-- Location: IOOBUF_X66_Y0_N59
\rs_val_o[12]~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \rf|RF_rtl_0|auto_generated|ram_block1a12\,
	devoe => ww_devoe,
	o => ww_rs_val_o(12));

-- Location: IOOBUF_X52_Y81_N2
\rs_val_o[13]~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \rf|RF_rtl_0|auto_generated|ram_block1a13\,
	devoe => ww_devoe,
	o => ww_rs_val_o(13));

-- Location: IOOBUF_X68_Y0_N2
\rs_val_o[14]~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \rf|RF_rtl_0|auto_generated|ram_block1a14\,
	devoe => ww_devoe,
	o => ww_rs_val_o(14));

-- Location: IOOBUF_X50_Y81_N42
\rs_val_o[15]~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \rf|RF_rtl_0|auto_generated|ram_block1a15\,
	devoe => ww_devoe,
	o => ww_rs_val_o(15));

-- Location: IOOBUF_X40_Y81_N36
\rs_val_o[16]~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \rf|RF_rtl_0|auto_generated|ram_block1a16\,
	devoe => ww_devoe,
	o => ww_rs_val_o(16));

-- Location: IOOBUF_X66_Y0_N76
\rs_val_o[17]~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \rf|RF_rtl_0|auto_generated|ram_block1a17\,
	devoe => ww_devoe,
	o => ww_rs_val_o(17));

-- Location: IOOBUF_X68_Y0_N19
\rs_val_o[18]~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \rf|RF_rtl_0|auto_generated|ram_block1a18\,
	devoe => ww_devoe,
	o => ww_rs_val_o(18));

-- Location: IOOBUF_X86_Y81_N2
\rs_val_o[19]~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \rf|RF_rtl_0|auto_generated|ram_block1a19\,
	devoe => ww_devoe,
	o => ww_rs_val_o(19));

-- Location: IOOBUF_X40_Y81_N53
\rs_val_o[20]~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \rf|RF_rtl_0|auto_generated|ram_block1a20\,
	devoe => ww_devoe,
	o => ww_rs_val_o(20));

-- Location: IOOBUF_X80_Y81_N53
\rs_val_o[21]~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \rf|RF_rtl_0|auto_generated|ram_block1a21\,
	devoe => ww_devoe,
	o => ww_rs_val_o(21));

-- Location: IOOBUF_X72_Y0_N53
\rs_val_o[22]~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \rf|RF_rtl_0|auto_generated|ram_block1a22\,
	devoe => ww_devoe,
	o => ww_rs_val_o(22));

-- Location: IOOBUF_X8_Y0_N36
\rs_val_o[23]~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \rf|RF_rtl_0|auto_generated|ram_block1a23\,
	devoe => ww_devoe,
	o => ww_rs_val_o(23));

-- Location: IOOBUF_X58_Y0_N76
\rs_val_o[24]~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \rf|RF_rtl_0|auto_generated|ram_block1a24\,
	devoe => ww_devoe,
	o => ww_rs_val_o(24));

-- Location: IOOBUF_X66_Y0_N42
\rs_val_o[25]~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \rf|RF_rtl_0|auto_generated|ram_block1a25\,
	devoe => ww_devoe,
	o => ww_rs_val_o(25));

-- Location: IOOBUF_X89_Y9_N56
\rs_val_o[26]~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \rf|RF_rtl_0|auto_generated|ram_block1a26\,
	devoe => ww_devoe,
	o => ww_rs_val_o(26));

-- Location: IOOBUF_X89_Y9_N39
\rs_val_o[27]~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \rf|RF_rtl_0|auto_generated|ram_block1a27\,
	devoe => ww_devoe,
	o => ww_rs_val_o(27));

-- Location: IOOBUF_X28_Y0_N19
\rs_val_o[28]~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \rf|RF_rtl_0|auto_generated|ram_block1a28\,
	devoe => ww_devoe,
	o => ww_rs_val_o(28));

-- Location: IOOBUF_X52_Y0_N19
\rs_val_o[29]~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \rf|RF_rtl_0|auto_generated|ram_block1a29\,
	devoe => ww_devoe,
	o => ww_rs_val_o(29));

-- Location: IOOBUF_X89_Y6_N39
\rs_val_o[30]~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \rf|RF_rtl_0|auto_generated|ram_block1a30\,
	devoe => ww_devoe,
	o => ww_rs_val_o(30));

-- Location: IOOBUF_X64_Y0_N53
\rs_val_o[31]~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \rf|RF_rtl_0|auto_generated|ram_block1a31\,
	devoe => ww_devoe,
	o => ww_rs_val_o(31));

-- Location: IOOBUF_X6_Y0_N36
\rs_val_o[32]~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \rf|RF_rtl_0|auto_generated|ram_block1a32\,
	devoe => ww_devoe,
	o => ww_rs_val_o(32));

-- Location: IOOBUF_X84_Y81_N53
\rs_val_o[33]~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \rf|RF_rtl_0|auto_generated|ram_block1a33\,
	devoe => ww_devoe,
	o => ww_rs_val_o(33));

-- Location: IOOBUF_X68_Y0_N53
\rs_val_o[34]~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \rf|RF_rtl_0|auto_generated|ram_block1a34\,
	devoe => ww_devoe,
	o => ww_rs_val_o(34));

-- Location: IOOBUF_X78_Y81_N2
\rs_val_o[35]~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \rf|RF_rtl_0|auto_generated|ram_block1a35\,
	devoe => ww_devoe,
	o => ww_rs_val_o(35));

-- Location: IOOBUF_X60_Y0_N2
\rs_val_o[36]~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \rf|RF_rtl_0|auto_generated|ram_block1a36\,
	devoe => ww_devoe,
	o => ww_rs_val_o(36));

-- Location: IOOBUF_X64_Y0_N36
\rs_val_o[37]~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \rf|RF_rtl_0|auto_generated|ram_block1a37\,
	devoe => ww_devoe,
	o => ww_rs_val_o(37));

-- Location: IOOBUF_X66_Y0_N93
\rs_val_o[38]~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \rf|RF_rtl_0|auto_generated|ram_block1a38\,
	devoe => ww_devoe,
	o => ww_rs_val_o(38));

-- Location: IOOBUF_X62_Y0_N2
\rs_val_o[39]~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \rf|RF_rtl_0|auto_generated|ram_block1a39\,
	devoe => ww_devoe,
	o => ww_rs_val_o(39));

-- Location: IOOBUF_X38_Y0_N53
\rs_val_o[40]~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \rf|RF_rtl_0|auto_generated|ram_block1a40~portbdataout\,
	devoe => ww_devoe,
	o => ww_rs_val_o(40));

-- Location: IOOBUF_X89_Y6_N5
\rs_val_o[41]~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \rf|RF_rtl_0|auto_generated|ram_block1a41\,
	devoe => ww_devoe,
	o => ww_rs_val_o(41));

-- Location: IOOBUF_X89_Y9_N22
\rs_val_o[42]~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \rf|RF_rtl_0|auto_generated|ram_block1a42\,
	devoe => ww_devoe,
	o => ww_rs_val_o(42));

-- Location: IOOBUF_X72_Y0_N19
\rs_val_o[43]~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \rf|RF_rtl_0|auto_generated|ram_block1a43\,
	devoe => ww_devoe,
	o => ww_rs_val_o(43));

-- Location: IOOBUF_X56_Y0_N53
\rs_val_o[44]~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \rf|RF_rtl_0|auto_generated|ram_block1a44\,
	devoe => ww_devoe,
	o => ww_rs_val_o(44));

-- Location: IOOBUF_X89_Y6_N56
\rs_val_o[45]~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \rf|RF_rtl_0|auto_generated|ram_block1a45\,
	devoe => ww_devoe,
	o => ww_rs_val_o(45));

-- Location: IOOBUF_X89_Y8_N56
\rs_val_o[46]~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \rf|RF_rtl_0|auto_generated|ram_block1a46\,
	devoe => ww_devoe,
	o => ww_rs_val_o(46));

-- Location: IOOBUF_X52_Y0_N36
\rs_val_o[47]~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \rf|RF_rtl_0|auto_generated|ram_block1a47\,
	devoe => ww_devoe,
	o => ww_rs_val_o(47));

-- Location: IOOBUF_X72_Y0_N2
\rs_val_o[48]~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \rf|RF_rtl_0|auto_generated|ram_block1a48\,
	devoe => ww_devoe,
	o => ww_rs_val_o(48));

-- Location: IOOBUF_X89_Y8_N22
\rs_val_o[49]~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \rf|RF_rtl_0|auto_generated|ram_block1a49\,
	devoe => ww_devoe,
	o => ww_rs_val_o(49));

-- Location: IOOBUF_X32_Y0_N2
\rs_val_o[50]~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \rf|RF_rtl_0|auto_generated|ram_block1a50\,
	devoe => ww_devoe,
	o => ww_rs_val_o(50));

-- Location: IOOBUF_X32_Y0_N53
\rs_val_o[51]~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \rf|RF_rtl_0|auto_generated|ram_block1a51\,
	devoe => ww_devoe,
	o => ww_rs_val_o(51));

-- Location: IOOBUF_X89_Y8_N39
\rs_val_o[52]~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \rf|RF_rtl_0|auto_generated|ram_block1a52\,
	devoe => ww_devoe,
	o => ww_rs_val_o(52));

-- Location: IOOBUF_X40_Y0_N2
\rs_val_o[53]~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \rf|RF_rtl_0|auto_generated|ram_block1a53\,
	devoe => ww_devoe,
	o => ww_rs_val_o(53));

-- Location: IOOBUF_X28_Y0_N36
\rs_val_o[54]~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \rf|RF_rtl_0|auto_generated|ram_block1a54\,
	devoe => ww_devoe,
	o => ww_rs_val_o(54));

-- Location: IOOBUF_X38_Y81_N2
\rs_val_o[55]~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \rf|RF_rtl_0|auto_generated|ram_block1a55\,
	devoe => ww_devoe,
	o => ww_rs_val_o(55));

-- Location: IOOBUF_X40_Y0_N53
\rs_val_o[56]~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \rf|RF_rtl_0|auto_generated|ram_block1a56\,
	devoe => ww_devoe,
	o => ww_rs_val_o(56));

-- Location: IOOBUF_X64_Y0_N2
\rs_val_o[57]~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \rf|RF_rtl_0|auto_generated|ram_block1a57\,
	devoe => ww_devoe,
	o => ww_rs_val_o(57));

-- Location: IOOBUF_X54_Y0_N36
\rs_val_o[58]~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \rf|RF_rtl_0|auto_generated|ram_block1a58\,
	devoe => ww_devoe,
	o => ww_rs_val_o(58));

-- Location: IOOBUF_X58_Y81_N59
\rs_val_o[59]~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \rf|RF_rtl_0|auto_generated|ram_block1a59\,
	devoe => ww_devoe,
	o => ww_rs_val_o(59));

-- Location: IOOBUF_X32_Y0_N19
\rs_val_o[60]~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \rf|RF_rtl_0|auto_generated|ram_block1a60\,
	devoe => ww_devoe,
	o => ww_rs_val_o(60));

-- Location: IOOBUF_X72_Y0_N36
\rs_val_o[61]~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \rf|RF_rtl_0|auto_generated|ram_block1a61\,
	devoe => ww_devoe,
	o => ww_rs_val_o(61));

-- Location: IOOBUF_X36_Y81_N53
\rs_val_o[62]~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \rf|RF_rtl_0|auto_generated|ram_block1a62\,
	devoe => ww_devoe,
	o => ww_rs_val_o(62));

-- Location: IOOBUF_X80_Y81_N36
\rs_val_o[63]~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \rf|RF_rtl_0|auto_generated|ram_block1a63\,
	devoe => ww_devoe,
	o => ww_rs_val_o(63));

-- Location: IOOBUF_X74_Y81_N93
\rd_val_o[0]~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \rf|RF_rtl_1|auto_generated|ram_block1a0~portbdataout\,
	devoe => ww_devoe,
	o => ww_rd_val_o(0));

-- Location: IOOBUF_X8_Y0_N2
\rd_val_o[1]~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \rf|RF_rtl_1|auto_generated|ram_block1a1\,
	devoe => ww_devoe,
	o => ww_rd_val_o(1));

-- Location: IOOBUF_X89_Y36_N56
\rd_val_o[2]~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \rf|RF_rtl_1|auto_generated|ram_block1a2\,
	devoe => ww_devoe,
	o => ww_rd_val_o(2));

-- Location: IOOBUF_X89_Y35_N96
\rd_val_o[3]~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \rf|RF_rtl_1|auto_generated|ram_block1a3\,
	devoe => ww_devoe,
	o => ww_rd_val_o(3));

-- Location: IOOBUF_X89_Y37_N22
\rd_val_o[4]~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \rf|RF_rtl_1|auto_generated|ram_block1a4\,
	devoe => ww_devoe,
	o => ww_rd_val_o(4));

-- Location: IOOBUF_X89_Y38_N56
\rd_val_o[5]~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \rf|RF_rtl_1|auto_generated|ram_block1a5\,
	devoe => ww_devoe,
	o => ww_rd_val_o(5));

-- Location: IOOBUF_X30_Y0_N36
\rd_val_o[6]~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \rf|RF_rtl_1|auto_generated|ram_block1a6\,
	devoe => ww_devoe,
	o => ww_rd_val_o(6));

-- Location: IOOBUF_X26_Y0_N93
\rd_val_o[7]~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \rf|RF_rtl_1|auto_generated|ram_block1a7\,
	devoe => ww_devoe,
	o => ww_rd_val_o(7));

-- Location: IOOBUF_X64_Y0_N19
\rd_val_o[8]~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \rf|RF_rtl_1|auto_generated|ram_block1a8\,
	devoe => ww_devoe,
	o => ww_rd_val_o(8));

-- Location: IOOBUF_X60_Y0_N36
\rd_val_o[9]~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \rf|RF_rtl_1|auto_generated|ram_block1a9\,
	devoe => ww_devoe,
	o => ww_rd_val_o(9));

-- Location: IOOBUF_X4_Y0_N2
\rd_val_o[10]~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \rf|RF_rtl_1|auto_generated|ram_block1a10\,
	devoe => ww_devoe,
	o => ww_rd_val_o(10));

-- Location: IOOBUF_X60_Y81_N36
\rd_val_o[11]~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \rf|RF_rtl_1|auto_generated|ram_block1a11\,
	devoe => ww_devoe,
	o => ww_rd_val_o(11));

-- Location: IOOBUF_X56_Y81_N53
\rd_val_o[12]~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \rf|RF_rtl_1|auto_generated|ram_block1a12\,
	devoe => ww_devoe,
	o => ww_rd_val_o(12));

-- Location: IOOBUF_X2_Y0_N76
\rd_val_o[13]~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \rf|RF_rtl_1|auto_generated|ram_block1a13\,
	devoe => ww_devoe,
	o => ww_rd_val_o(13));

-- Location: IOOBUF_X26_Y0_N59
\rd_val_o[14]~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \rf|RF_rtl_1|auto_generated|ram_block1a14\,
	devoe => ww_devoe,
	o => ww_rd_val_o(14));

-- Location: IOOBUF_X4_Y0_N19
\rd_val_o[15]~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \rf|RF_rtl_1|auto_generated|ram_block1a15\,
	devoe => ww_devoe,
	o => ww_rd_val_o(15));

-- Location: IOOBUF_X89_Y36_N39
\rd_val_o[16]~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \rf|RF_rtl_1|auto_generated|ram_block1a16\,
	devoe => ww_devoe,
	o => ww_rd_val_o(16));

-- Location: IOOBUF_X58_Y81_N42
\rd_val_o[17]~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \rf|RF_rtl_1|auto_generated|ram_block1a17\,
	devoe => ww_devoe,
	o => ww_rd_val_o(17));

-- Location: IOOBUF_X89_Y37_N5
\rd_val_o[18]~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \rf|RF_rtl_1|auto_generated|ram_block1a18\,
	devoe => ww_devoe,
	o => ww_rd_val_o(18));

-- Location: IOOBUF_X26_Y0_N42
\rd_val_o[19]~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \rf|RF_rtl_1|auto_generated|ram_block1a19\,
	devoe => ww_devoe,
	o => ww_rd_val_o(19));

-- Location: IOOBUF_X70_Y81_N19
\rd_val_o[20]~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \rf|RF_rtl_1|auto_generated|ram_block1a20\,
	devoe => ww_devoe,
	o => ww_rd_val_o(20));

-- Location: IOOBUF_X54_Y81_N2
\rd_val_o[21]~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \rf|RF_rtl_1|auto_generated|ram_block1a21\,
	devoe => ww_devoe,
	o => ww_rd_val_o(21));

-- Location: IOOBUF_X52_Y0_N53
\rd_val_o[22]~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \rf|RF_rtl_1|auto_generated|ram_block1a22\,
	devoe => ww_devoe,
	o => ww_rd_val_o(22));

-- Location: IOOBUF_X80_Y81_N19
\rd_val_o[23]~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \rf|RF_rtl_1|auto_generated|ram_block1a23\,
	devoe => ww_devoe,
	o => ww_rd_val_o(23));

-- Location: IOOBUF_X54_Y0_N2
\rd_val_o[24]~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \rf|RF_rtl_1|auto_generated|ram_block1a24\,
	devoe => ww_devoe,
	o => ww_rd_val_o(24));

-- Location: IOOBUF_X66_Y81_N42
\rd_val_o[25]~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \rf|RF_rtl_1|auto_generated|ram_block1a25\,
	devoe => ww_devoe,
	o => ww_rd_val_o(25));

-- Location: IOOBUF_X28_Y0_N53
\rd_val_o[26]~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \rf|RF_rtl_1|auto_generated|ram_block1a26\,
	devoe => ww_devoe,
	o => ww_rd_val_o(26));

-- Location: IOOBUF_X68_Y81_N2
\rd_val_o[27]~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \rf|RF_rtl_1|auto_generated|ram_block1a27\,
	devoe => ww_devoe,
	o => ww_rd_val_o(27));

-- Location: IOOBUF_X78_Y81_N19
\rd_val_o[28]~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \rf|RF_rtl_1|auto_generated|ram_block1a28\,
	devoe => ww_devoe,
	o => ww_rd_val_o(28));

-- Location: IOOBUF_X2_Y0_N59
\rd_val_o[29]~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \rf|RF_rtl_1|auto_generated|ram_block1a29\,
	devoe => ww_devoe,
	o => ww_rd_val_o(29));

-- Location: IOOBUF_X2_Y0_N93
\rd_val_o[30]~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \rf|RF_rtl_1|auto_generated|ram_block1a30\,
	devoe => ww_devoe,
	o => ww_rd_val_o(30));

-- Location: IOOBUF_X89_Y9_N5
\rd_val_o[31]~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \rf|RF_rtl_1|auto_generated|ram_block1a31\,
	devoe => ww_devoe,
	o => ww_rd_val_o(31));

-- Location: IOOBUF_X58_Y81_N93
\rd_val_o[32]~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \rf|RF_rtl_1|auto_generated|ram_block1a32\,
	devoe => ww_devoe,
	o => ww_rd_val_o(32));

-- Location: IOOBUF_X82_Y81_N93
\rd_val_o[33]~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \rf|RF_rtl_1|auto_generated|ram_block1a33\,
	devoe => ww_devoe,
	o => ww_rd_val_o(33));

-- Location: IOOBUF_X89_Y8_N5
\rd_val_o[34]~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \rf|RF_rtl_1|auto_generated|ram_block1a34\,
	devoe => ww_devoe,
	o => ww_rd_val_o(34));

-- Location: IOOBUF_X89_Y35_N79
\rd_val_o[35]~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \rf|RF_rtl_1|auto_generated|ram_block1a35\,
	devoe => ww_devoe,
	o => ww_rd_val_o(35));

-- Location: IOOBUF_X54_Y0_N19
\rd_val_o[36]~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \rf|RF_rtl_1|auto_generated|ram_block1a36\,
	devoe => ww_devoe,
	o => ww_rd_val_o(36));

-- Location: IOOBUF_X26_Y0_N76
\rd_val_o[37]~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \rf|RF_rtl_1|auto_generated|ram_block1a37\,
	devoe => ww_devoe,
	o => ww_rd_val_o(37));

-- Location: IOOBUF_X2_Y0_N42
\rd_val_o[38]~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \rf|RF_rtl_1|auto_generated|ram_block1a38\,
	devoe => ww_devoe,
	o => ww_rd_val_o(38));

-- Location: IOOBUF_X54_Y81_N19
\rd_val_o[39]~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \rf|RF_rtl_1|auto_generated|ram_block1a39\,
	devoe => ww_devoe,
	o => ww_rd_val_o(39));

-- Location: IOOBUF_X8_Y0_N53
\rd_val_o[40]~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \rf|RF_rtl_1|auto_generated|ram_block1a40~portbdataout\,
	devoe => ww_devoe,
	o => ww_rd_val_o(40));

-- Location: IOOBUF_X74_Y81_N42
\rd_val_o[41]~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \rf|RF_rtl_1|auto_generated|ram_block1a41\,
	devoe => ww_devoe,
	o => ww_rd_val_o(41));

-- Location: IOOBUF_X64_Y81_N19
\rd_val_o[42]~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \rf|RF_rtl_1|auto_generated|ram_block1a42\,
	devoe => ww_devoe,
	o => ww_rd_val_o(42));

-- Location: IOOBUF_X52_Y81_N36
\rd_val_o[43]~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \rf|RF_rtl_1|auto_generated|ram_block1a43\,
	devoe => ww_devoe,
	o => ww_rd_val_o(43));

-- Location: IOOBUF_X89_Y35_N45
\rd_val_o[44]~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \rf|RF_rtl_1|auto_generated|ram_block1a44\,
	devoe => ww_devoe,
	o => ww_rd_val_o(44));

-- Location: IOOBUF_X66_Y81_N76
\rd_val_o[45]~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \rf|RF_rtl_1|auto_generated|ram_block1a45\,
	devoe => ww_devoe,
	o => ww_rd_val_o(45));

-- Location: IOOBUF_X30_Y0_N53
\rd_val_o[46]~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \rf|RF_rtl_1|auto_generated|ram_block1a46\,
	devoe => ww_devoe,
	o => ww_rd_val_o(46));

-- Location: IOOBUF_X58_Y81_N76
\rd_val_o[47]~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \rf|RF_rtl_1|auto_generated|ram_block1a47\,
	devoe => ww_devoe,
	o => ww_rd_val_o(47));

-- Location: IOOBUF_X89_Y36_N5
\rd_val_o[48]~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \rf|RF_rtl_1|auto_generated|ram_block1a48\,
	devoe => ww_devoe,
	o => ww_rd_val_o(48));

-- Location: IOOBUF_X72_Y81_N36
\rd_val_o[49]~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \rf|RF_rtl_1|auto_generated|ram_block1a49\,
	devoe => ww_devoe,
	o => ww_rd_val_o(49));

-- Location: IOOBUF_X54_Y81_N53
\rd_val_o[50]~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \rf|RF_rtl_1|auto_generated|ram_block1a50\,
	devoe => ww_devoe,
	o => ww_rd_val_o(50));

-- Location: IOOBUF_X60_Y81_N53
\rd_val_o[51]~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \rf|RF_rtl_1|auto_generated|ram_block1a51\,
	devoe => ww_devoe,
	o => ww_rd_val_o(51));

-- Location: IOOBUF_X54_Y81_N36
\rd_val_o[52]~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \rf|RF_rtl_1|auto_generated|ram_block1a52\,
	devoe => ww_devoe,
	o => ww_rd_val_o(52));

-- Location: IOOBUF_X89_Y4_N79
\rd_val_o[53]~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \rf|RF_rtl_1|auto_generated|ram_block1a53\,
	devoe => ww_devoe,
	o => ww_rd_val_o(53));

-- Location: IOOBUF_X8_Y0_N19
\rd_val_o[54]~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \rf|RF_rtl_1|auto_generated|ram_block1a54\,
	devoe => ww_devoe,
	o => ww_rd_val_o(54));

-- Location: IOOBUF_X89_Y36_N22
\rd_val_o[55]~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \rf|RF_rtl_1|auto_generated|ram_block1a55\,
	devoe => ww_devoe,
	o => ww_rd_val_o(55));

-- Location: IOOBUF_X66_Y81_N59
\rd_val_o[56]~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \rf|RF_rtl_1|auto_generated|ram_block1a56\,
	devoe => ww_devoe,
	o => ww_rd_val_o(56));

-- Location: IOOBUF_X32_Y0_N36
\rd_val_o[57]~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \rf|RF_rtl_1|auto_generated|ram_block1a57\,
	devoe => ww_devoe,
	o => ww_rd_val_o(57));

-- Location: IOOBUF_X64_Y81_N53
\rd_val_o[58]~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \rf|RF_rtl_1|auto_generated|ram_block1a58\,
	devoe => ww_devoe,
	o => ww_rd_val_o(58));

-- Location: IOOBUF_X64_Y81_N2
\rd_val_o[59]~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \rf|RF_rtl_1|auto_generated|ram_block1a59\,
	devoe => ww_devoe,
	o => ww_rd_val_o(59));

-- Location: IOOBUF_X28_Y0_N2
\rd_val_o[60]~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \rf|RF_rtl_1|auto_generated|ram_block1a60\,
	devoe => ww_devoe,
	o => ww_rd_val_o(60));

-- Location: IOOBUF_X62_Y81_N53
\rd_val_o[61]~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \rf|RF_rtl_1|auto_generated|ram_block1a61\,
	devoe => ww_devoe,
	o => ww_rd_val_o(61));

-- Location: IOOBUF_X84_Y81_N2
\rd_val_o[62]~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \rf|RF_rtl_1|auto_generated|ram_block1a62\,
	devoe => ww_devoe,
	o => ww_rd_val_o(62));

-- Location: IOOBUF_X38_Y0_N2
\rd_val_o[63]~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \rf|RF_rtl_1|auto_generated|ram_block1a63\,
	devoe => ww_devoe,
	o => ww_rd_val_o(63));

-- Location: IOIBUF_X89_Y35_N61
\clk~input\ : cyclonev_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_clk,
	o => \clk~input_o\);

-- Location: CLKCTRL_G10
\clk~inputCLKENA0\ : cyclonev_clkena
-- pragma translate_off
GENERIC MAP (
	clock_type => "global clock",
	disable_mode => "low",
	ena_register_mode => "always enabled",
	ena_register_power_up => "high",
	test_syn => "high")
-- pragma translate_on
PORT MAP (
	inclk => \clk~input_o\,
	outclk => \clk~inputCLKENA0_outclk\);

-- Location: IOIBUF_X34_Y0_N92
\wen_i~input\ : cyclonev_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_wen_i,
	o => \wen_i~input_o\);

-- Location: LABCELL_X68_Y11_N9
\wen_r~feeder\ : cyclonev_lcell_comb
-- Equation(s):
-- \wen_r~feeder_combout\ = ( \wen_i~input_o\ )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0000000000000000000000000000000011111111111111111111111111111111",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	dataf => \ALT_INV_wen_i~input_o\,
	combout => \wen_r~feeder_combout\);

-- Location: FF_X68_Y11_N11
wen_r : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~inputCLKENA0_outclk\,
	d => \wen_r~feeder_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \wen_r~q\);

-- Location: IOIBUF_X30_Y0_N18
\w_data_i[0]~input\ : cyclonev_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_w_data_i(0),
	o => \w_data_i[0]~input_o\);

-- Location: FF_X68_Y9_N38
\w_data_r[0]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~inputCLKENA0_outclk\,
	asdata => \w_data_i[0]~input_o\,
	sload => VCC,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => w_data_r(0));

-- Location: IOIBUF_X6_Y0_N18
\w_addr_i[0]~input\ : cyclonev_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_w_addr_i(0),
	o => \w_addr_i[0]~input_o\);

-- Location: FF_X68_Y11_N14
\w_addr_r[0]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~inputCLKENA0_outclk\,
	asdata => \w_addr_i[0]~input_o\,
	sload => VCC,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => w_addr_r(0));

-- Location: IOIBUF_X56_Y0_N18
\w_addr_i[1]~input\ : cyclonev_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_w_addr_i(1),
	o => \w_addr_i[1]~input_o\);

-- Location: FF_X68_Y11_N47
\w_addr_r[1]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~inputCLKENA0_outclk\,
	asdata => \w_addr_i[1]~input_o\,
	sload => VCC,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => w_addr_r(1));

-- Location: IOIBUF_X80_Y81_N1
\w_addr_i[2]~input\ : cyclonev_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_w_addr_i(2),
	o => \w_addr_i[2]~input_o\);

-- Location: LABCELL_X70_Y11_N57
\w_addr_r[2]~feeder\ : cyclonev_lcell_comb
-- Equation(s):
-- \w_addr_r[2]~feeder_combout\ = ( \w_addr_i[2]~input_o\ )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0000000000000000000000000000000011111111111111111111111111111111",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	dataf => \ALT_INV_w_addr_i[2]~input_o\,
	combout => \w_addr_r[2]~feeder_combout\);

-- Location: FF_X70_Y11_N59
\w_addr_r[2]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~inputCLKENA0_outclk\,
	d => \w_addr_r[2]~feeder_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => w_addr_r(2));

-- Location: IOIBUF_X36_Y0_N1
\w_addr_i[3]~input\ : cyclonev_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_w_addr_i(3),
	o => \w_addr_i[3]~input_o\);

-- Location: LABCELL_X68_Y11_N57
\w_addr_r[3]~feeder\ : cyclonev_lcell_comb
-- Equation(s):
-- \w_addr_r[3]~feeder_combout\ = ( \w_addr_i[3]~input_o\ )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0000000000000000000000000000000011111111111111111111111111111111",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	dataf => \ALT_INV_w_addr_i[3]~input_o\,
	combout => \w_addr_r[3]~feeder_combout\);

-- Location: FF_X68_Y11_N59
\w_addr_r[3]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~inputCLKENA0_outclk\,
	d => \w_addr_r[3]~feeder_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => w_addr_r(3));

-- Location: IOIBUF_X50_Y81_N58
\w_addr_i[4]~input\ : cyclonev_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_w_addr_i(4),
	o => \w_addr_i[4]~input_o\);

-- Location: FF_X68_Y11_N26
\w_addr_r[4]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~inputCLKENA0_outclk\,
	asdata => \w_addr_i[4]~input_o\,
	sload => VCC,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => w_addr_r(4));

-- Location: IOIBUF_X62_Y81_N1
\rs_addr_i[0]~input\ : cyclonev_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_rs_addr_i(0),
	o => \rs_addr_i[0]~input_o\);

-- Location: LABCELL_X68_Y10_N12
\rs_addr_r[0]~feeder\ : cyclonev_lcell_comb
-- Equation(s):
-- \rs_addr_r[0]~feeder_combout\ = ( \rs_addr_i[0]~input_o\ )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0000000000000000000000000000000011111111111111111111111111111111",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	dataf => \ALT_INV_rs_addr_i[0]~input_o\,
	combout => \rs_addr_r[0]~feeder_combout\);

-- Location: FF_X68_Y10_N14
\rs_addr_r[0]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~inputCLKENA0_outclk\,
	d => \rs_addr_r[0]~feeder_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => rs_addr_r(0));

-- Location: IOIBUF_X58_Y0_N92
\rs_addr_i[1]~input\ : cyclonev_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_rs_addr_i(1),
	o => \rs_addr_i[1]~input_o\);

-- Location: FF_X68_Y10_N50
\rs_addr_r[1]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~inputCLKENA0_outclk\,
	asdata => \rs_addr_i[1]~input_o\,
	sload => VCC,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => rs_addr_r(1));

-- Location: IOIBUF_X36_Y0_N18
\rs_addr_i[2]~input\ : cyclonev_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_rs_addr_i(2),
	o => \rs_addr_i[2]~input_o\);

-- Location: FF_X68_Y10_N41
\rs_addr_r[2]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~inputCLKENA0_outclk\,
	asdata => \rs_addr_i[2]~input_o\,
	sload => VCC,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => rs_addr_r(2));

-- Location: IOIBUF_X30_Y0_N1
\rs_addr_i[3]~input\ : cyclonev_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_rs_addr_i(3),
	o => \rs_addr_i[3]~input_o\);

-- Location: LABCELL_X68_Y10_N6
\rs_addr_r[3]~feeder\ : cyclonev_lcell_comb
-- Equation(s):
-- \rs_addr_r[3]~feeder_combout\ = ( \rs_addr_i[3]~input_o\ )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0000000000000000000000000000000011111111111111111111111111111111",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	dataf => \ALT_INV_rs_addr_i[3]~input_o\,
	combout => \rs_addr_r[3]~feeder_combout\);

-- Location: FF_X68_Y10_N8
\rs_addr_r[3]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~inputCLKENA0_outclk\,
	d => \rs_addr_r[3]~feeder_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => rs_addr_r(3));

-- Location: IOIBUF_X64_Y81_N35
\rs_addr_i[4]~input\ : cyclonev_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_rs_addr_i(4),
	o => \rs_addr_i[4]~input_o\);

-- Location: LABCELL_X68_Y10_N42
\rs_addr_r[4]~feeder\ : cyclonev_lcell_comb
-- Equation(s):
-- \rs_addr_r[4]~feeder_combout\ = ( \rs_addr_i[4]~input_o\ )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0000000000000000000000000000000011111111111111111111111111111111",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	dataf => \ALT_INV_rs_addr_i[4]~input_o\,
	combout => \rs_addr_r[4]~feeder_combout\);

-- Location: FF_X68_Y10_N44
\rs_addr_r[4]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~inputCLKENA0_outclk\,
	d => \rs_addr_r[4]~feeder_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => rs_addr_r(4));

-- Location: IOIBUF_X56_Y0_N35
\w_data_i[1]~input\ : cyclonev_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_w_data_i(1),
	o => \w_data_i[1]~input_o\);

-- Location: FF_X68_Y9_N2
\w_data_r[1]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~inputCLKENA0_outclk\,
	asdata => \w_data_i[1]~input_o\,
	sload => VCC,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => w_data_r(1));

-- Location: IOIBUF_X62_Y0_N52
\w_data_i[2]~input\ : cyclonev_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_w_data_i(2),
	o => \w_data_i[2]~input_o\);

-- Location: FF_X68_Y11_N5
\w_data_r[2]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~inputCLKENA0_outclk\,
	asdata => \w_data_i[2]~input_o\,
	sload => VCC,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => w_data_r(2));

-- Location: IOIBUF_X60_Y0_N52
\w_data_i[3]~input\ : cyclonev_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_w_data_i(3),
	o => \w_data_i[3]~input_o\);

-- Location: FF_X68_Y7_N35
\w_data_r[3]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~inputCLKENA0_outclk\,
	asdata => \w_data_i[3]~input_o\,
	sload => VCC,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => w_data_r(3));

-- Location: IOIBUF_X6_Y0_N52
\w_data_i[4]~input\ : cyclonev_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_w_data_i(4),
	o => \w_data_i[4]~input_o\);

-- Location: FF_X66_Y9_N8
\w_data_r[4]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~inputCLKENA0_outclk\,
	asdata => \w_data_i[4]~input_o\,
	sload => VCC,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => w_data_r(4));

-- Location: IOIBUF_X56_Y81_N1
\w_data_i[5]~input\ : cyclonev_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_w_data_i(5),
	o => \w_data_i[5]~input_o\);

-- Location: LABCELL_X68_Y9_N39
\w_data_r[5]~feeder\ : cyclonev_lcell_comb
-- Equation(s):
-- \w_data_r[5]~feeder_combout\ = ( \w_data_i[5]~input_o\ )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0000000000000000000000000000000011111111111111111111111111111111",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	dataf => \ALT_INV_w_data_i[5]~input_o\,
	combout => \w_data_r[5]~feeder_combout\);

-- Location: FF_X68_Y9_N41
\w_data_r[5]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~inputCLKENA0_outclk\,
	d => \w_data_r[5]~feeder_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => w_data_r(5));

-- Location: IOIBUF_X70_Y81_N35
\w_data_i[6]~input\ : cyclonev_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_w_data_i(6),
	o => \w_data_i[6]~input_o\);

-- Location: FF_X70_Y11_N53
\w_data_r[6]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~inputCLKENA0_outclk\,
	asdata => \w_data_i[6]~input_o\,
	sload => VCC,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => w_data_r(6));

-- Location: IOIBUF_X60_Y81_N18
\w_data_i[7]~input\ : cyclonev_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_w_data_i(7),
	o => \w_data_i[7]~input_o\);

-- Location: FF_X66_Y11_N5
\w_data_r[7]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~inputCLKENA0_outclk\,
	asdata => \w_data_i[7]~input_o\,
	sload => VCC,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => w_data_r(7));

-- Location: IOIBUF_X36_Y0_N52
\w_data_i[8]~input\ : cyclonev_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_w_data_i(8),
	o => \w_data_i[8]~input_o\);

-- Location: LABCELL_X68_Y8_N42
\w_data_r[8]~feeder\ : cyclonev_lcell_comb
-- Equation(s):
-- \w_data_r[8]~feeder_combout\ = ( \w_data_i[8]~input_o\ )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0000000000000000000000000000000011111111111111111111111111111111",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	dataf => \ALT_INV_w_data_i[8]~input_o\,
	combout => \w_data_r[8]~feeder_combout\);

-- Location: FF_X68_Y8_N44
\w_data_r[8]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~inputCLKENA0_outclk\,
	d => \w_data_r[8]~feeder_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => w_data_r(8));

-- Location: IOIBUF_X34_Y0_N75
\w_data_i[9]~input\ : cyclonev_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_w_data_i(9),
	o => \w_data_i[9]~input_o\);

-- Location: FF_X66_Y9_N29
\w_data_r[9]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~inputCLKENA0_outclk\,
	asdata => \w_data_i[9]~input_o\,
	sload => VCC,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => w_data_r(9));

-- Location: IOIBUF_X89_Y38_N4
\w_data_i[10]~input\ : cyclonev_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_w_data_i(10),
	o => \w_data_i[10]~input_o\);

-- Location: MLABCELL_X72_Y11_N18
\w_data_r[10]~feeder\ : cyclonev_lcell_comb
-- Equation(s):
-- \w_data_r[10]~feeder_combout\ = ( \w_data_i[10]~input_o\ )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0000000000000000000000000000000011111111111111111111111111111111",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	dataf => \ALT_INV_w_data_i[10]~input_o\,
	combout => \w_data_r[10]~feeder_combout\);

-- Location: FF_X72_Y11_N20
\w_data_r[10]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~inputCLKENA0_outclk\,
	d => \w_data_r[10]~feeder_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => w_data_r(10));

-- Location: IOIBUF_X50_Y0_N58
\w_data_i[11]~input\ : cyclonev_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_w_data_i(11),
	o => \w_data_i[11]~input_o\);

-- Location: LABCELL_X68_Y7_N15
\w_data_r[11]~feeder\ : cyclonev_lcell_comb
-- Equation(s):
-- \w_data_r[11]~feeder_combout\ = ( \w_data_i[11]~input_o\ )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0000000000000000000000000000000011111111111111111111111111111111",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	dataf => \ALT_INV_w_data_i[11]~input_o\,
	combout => \w_data_r[11]~feeder_combout\);

-- Location: FF_X68_Y7_N17
\w_data_r[11]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~inputCLKENA0_outclk\,
	d => \w_data_r[11]~feeder_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => w_data_r(11));

-- Location: IOIBUF_X50_Y0_N41
\w_data_i[12]~input\ : cyclonev_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_w_data_i(12),
	o => \w_data_i[12]~input_o\);

-- Location: LABCELL_X68_Y11_N42
\w_data_r[12]~feeder\ : cyclonev_lcell_comb
-- Equation(s):
-- \w_data_r[12]~feeder_combout\ = ( \w_data_i[12]~input_o\ )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0000000000000000000000000000000011111111111111111111111111111111",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	dataf => \ALT_INV_w_data_i[12]~input_o\,
	combout => \w_data_r[12]~feeder_combout\);

-- Location: FF_X68_Y11_N44
\w_data_r[12]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~inputCLKENA0_outclk\,
	d => \w_data_r[12]~feeder_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => w_data_r(12));

-- Location: IOIBUF_X54_Y0_N52
\w_data_i[13]~input\ : cyclonev_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_w_data_i(13),
	o => \w_data_i[13]~input_o\);

-- Location: LABCELL_X63_Y9_N54
\w_data_r[13]~feeder\ : cyclonev_lcell_comb
-- Equation(s):
-- \w_data_r[13]~feeder_combout\ = ( \w_data_i[13]~input_o\ )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0000000000000000000000000000000011111111111111111111111111111111",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	dataf => \ALT_INV_w_data_i[13]~input_o\,
	combout => \w_data_r[13]~feeder_combout\);

-- Location: FF_X63_Y9_N56
\w_data_r[13]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~inputCLKENA0_outclk\,
	d => \w_data_r[13]~feeder_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => w_data_r(13));

-- Location: IOIBUF_X70_Y0_N1
\w_data_i[14]~input\ : cyclonev_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_w_data_i(14),
	o => \w_data_i[14]~input_o\);

-- Location: FF_X70_Y7_N2
\w_data_r[14]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~inputCLKENA0_outclk\,
	asdata => \w_data_i[14]~input_o\,
	sload => VCC,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => w_data_r(14));

-- Location: IOIBUF_X34_Y0_N58
\w_data_i[15]~input\ : cyclonev_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_w_data_i(15),
	o => \w_data_i[15]~input_o\);

-- Location: LABCELL_X66_Y9_N15
\w_data_r[15]~feeder\ : cyclonev_lcell_comb
-- Equation(s):
-- \w_data_r[15]~feeder_combout\ = ( \w_data_i[15]~input_o\ )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0000000000000000000000000000000011111111111111111111111111111111",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	dataf => \ALT_INV_w_data_i[15]~input_o\,
	combout => \w_data_r[15]~feeder_combout\);

-- Location: FF_X66_Y9_N17
\w_data_r[15]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~inputCLKENA0_outclk\,
	d => \w_data_r[15]~feeder_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => w_data_r(15));

-- Location: IOIBUF_X70_Y0_N18
\w_data_i[16]~input\ : cyclonev_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_w_data_i(16),
	o => \w_data_i[16]~input_o\);

-- Location: LABCELL_X70_Y7_N33
\w_data_r[16]~feeder\ : cyclonev_lcell_comb
-- Equation(s):
-- \w_data_r[16]~feeder_combout\ = ( \w_data_i[16]~input_o\ )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0000000000000000000000000000000011111111111111111111111111111111",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	dataf => \ALT_INV_w_data_i[16]~input_o\,
	combout => \w_data_r[16]~feeder_combout\);

-- Location: FF_X70_Y7_N35
\w_data_r[16]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~inputCLKENA0_outclk\,
	d => \w_data_r[16]~feeder_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => w_data_r(16));

-- Location: IOIBUF_X34_Y0_N41
\w_data_i[17]~input\ : cyclonev_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_w_data_i(17),
	o => \w_data_i[17]~input_o\);

-- Location: LABCELL_X68_Y9_N27
\w_data_r[17]~feeder\ : cyclonev_lcell_comb
-- Equation(s):
-- \w_data_r[17]~feeder_combout\ = ( \w_data_i[17]~input_o\ )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0000000000000000000000000000000011111111111111111111111111111111",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	dataf => \ALT_INV_w_data_i[17]~input_o\,
	combout => \w_data_r[17]~feeder_combout\);

-- Location: FF_X68_Y9_N29
\w_data_r[17]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~inputCLKENA0_outclk\,
	d => \w_data_r[17]~feeder_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => w_data_r(17));

-- Location: IOIBUF_X76_Y81_N52
\w_data_i[18]~input\ : cyclonev_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_w_data_i(18),
	o => \w_data_i[18]~input_o\);

-- Location: FF_X70_Y9_N59
\w_data_r[18]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~inputCLKENA0_outclk\,
	asdata => \w_data_i[18]~input_o\,
	sload => VCC,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => w_data_r(18));

-- Location: IOIBUF_X58_Y0_N41
\w_data_i[19]~input\ : cyclonev_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_w_data_i(19),
	o => \w_data_i[19]~input_o\);

-- Location: LABCELL_X64_Y9_N33
\w_data_r[19]~feeder\ : cyclonev_lcell_comb
-- Equation(s):
-- \w_data_r[19]~feeder_combout\ = ( \w_data_i[19]~input_o\ )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0000000000000000000000000000000011111111111111111111111111111111",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	dataf => \ALT_INV_w_data_i[19]~input_o\,
	combout => \w_data_r[19]~feeder_combout\);

-- Location: FF_X64_Y9_N35
\w_data_r[19]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~inputCLKENA0_outclk\,
	d => \w_data_r[19]~feeder_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => w_data_r(19));

-- Location: IOIBUF_X89_Y4_N44
\w_data_i[20]~input\ : cyclonev_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_w_data_i(20),
	o => \w_data_i[20]~input_o\);

-- Location: FF_X70_Y11_N14
\w_data_r[20]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~inputCLKENA0_outclk\,
	asdata => \w_data_i[20]~input_o\,
	sload => VCC,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => w_data_r(20));

-- Location: IOIBUF_X36_Y0_N35
\w_data_i[21]~input\ : cyclonev_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_w_data_i(21),
	o => \w_data_i[21]~input_o\);

-- Location: FF_X68_Y9_N26
\w_data_r[21]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~inputCLKENA0_outclk\,
	asdata => \w_data_i[21]~input_o\,
	sload => VCC,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => w_data_r(21));

-- Location: IOIBUF_X56_Y0_N1
\w_data_i[22]~input\ : cyclonev_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_w_data_i(22),
	o => \w_data_i[22]~input_o\);

-- Location: FF_X66_Y9_N59
\w_data_r[22]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~inputCLKENA0_outclk\,
	asdata => \w_data_i[22]~input_o\,
	sload => VCC,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => w_data_r(22));

-- Location: IOIBUF_X82_Y81_N58
\w_data_i[23]~input\ : cyclonev_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_w_data_i(23),
	o => \w_data_i[23]~input_o\);

-- Location: LABCELL_X70_Y11_N27
\w_data_r[23]~feeder\ : cyclonev_lcell_comb
-- Equation(s):
-- \w_data_r[23]~feeder_combout\ = ( \w_data_i[23]~input_o\ )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0000000000000000000000000000000011111111111111111111111111111111",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	dataf => \ALT_INV_w_data_i[23]~input_o\,
	combout => \w_data_r[23]~feeder_combout\);

-- Location: FF_X70_Y11_N29
\w_data_r[23]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~inputCLKENA0_outclk\,
	d => \w_data_r[23]~feeder_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => w_data_r(23));

-- Location: IOIBUF_X52_Y0_N1
\w_data_i[24]~input\ : cyclonev_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_w_data_i(24),
	o => \w_data_i[24]~input_o\);

-- Location: LABCELL_X67_Y9_N39
\w_data_r[24]~feeder\ : cyclonev_lcell_comb
-- Equation(s):
-- \w_data_r[24]~feeder_combout\ = ( \w_data_i[24]~input_o\ )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0000000000000000000000000000000011111111111111111111111111111111",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	dataf => \ALT_INV_w_data_i[24]~input_o\,
	combout => \w_data_r[24]~feeder_combout\);

-- Location: FF_X67_Y9_N41
\w_data_r[24]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~inputCLKENA0_outclk\,
	d => \w_data_r[24]~feeder_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => w_data_r(24));

-- Location: IOIBUF_X70_Y0_N52
\w_data_i[25]~input\ : cyclonev_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_w_data_i(25),
	o => \w_data_i[25]~input_o\);

-- Location: FF_X70_Y7_N41
\w_data_r[25]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~inputCLKENA0_outclk\,
	asdata => \w_data_i[25]~input_o\,
	sload => VCC,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => w_data_r(25));

-- Location: IOIBUF_X4_Y0_N52
\w_data_i[26]~input\ : cyclonev_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_w_data_i(26),
	o => \w_data_i[26]~input_o\);

-- Location: FF_X68_Y9_N35
\w_data_r[26]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~inputCLKENA0_outclk\,
	asdata => \w_data_i[26]~input_o\,
	sload => VCC,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => w_data_r(26));

-- Location: IOIBUF_X89_Y4_N61
\w_data_i[27]~input\ : cyclonev_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_w_data_i(27),
	o => \w_data_i[27]~input_o\);

-- Location: LABCELL_X70_Y11_N0
\w_data_r[27]~feeder\ : cyclonev_lcell_comb
-- Equation(s):
-- \w_data_r[27]~feeder_combout\ = ( \w_data_i[27]~input_o\ )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0000000000000000000000000000000011111111111111111111111111111111",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	dataf => \ALT_INV_w_data_i[27]~input_o\,
	combout => \w_data_r[27]~feeder_combout\);

-- Location: FF_X70_Y11_N2
\w_data_r[27]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~inputCLKENA0_outclk\,
	d => \w_data_r[27]~feeder_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => w_data_r(27));

-- Location: IOIBUF_X89_Y38_N38
\w_data_i[28]~input\ : cyclonev_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_w_data_i(28),
	o => \w_data_i[28]~input_o\);

-- Location: FF_X72_Y13_N56
\w_data_r[28]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~inputCLKENA0_outclk\,
	asdata => \w_data_i[28]~input_o\,
	sload => VCC,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => w_data_r(28));

-- Location: IOIBUF_X62_Y81_N18
\w_data_i[29]~input\ : cyclonev_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_w_data_i(29),
	o => \w_data_i[29]~input_o\);

-- Location: LABCELL_X68_Y9_N6
\w_data_r[29]~feeder\ : cyclonev_lcell_comb
-- Equation(s):
-- \w_data_r[29]~feeder_combout\ = ( \w_data_i[29]~input_o\ )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0000000000000000000000000000000011111111111111111111111111111111",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	dataf => \ALT_INV_w_data_i[29]~input_o\,
	combout => \w_data_r[29]~feeder_combout\);

-- Location: FF_X68_Y9_N8
\w_data_r[29]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~inputCLKENA0_outclk\,
	d => \w_data_r[29]~feeder_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => w_data_r(29));

-- Location: IOIBUF_X89_Y37_N38
\w_data_i[30]~input\ : cyclonev_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_w_data_i(30),
	o => \w_data_i[30]~input_o\);

-- Location: LABCELL_X71_Y11_N33
\w_data_r[30]~feeder\ : cyclonev_lcell_comb
-- Equation(s):
-- \w_data_r[30]~feeder_combout\ = ( \w_data_i[30]~input_o\ )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0000000000000000000000000000000011111111111111111111111111111111",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	dataf => \ALT_INV_w_data_i[30]~input_o\,
	combout => \w_data_r[30]~feeder_combout\);

-- Location: FF_X71_Y11_N35
\w_data_r[30]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~inputCLKENA0_outclk\,
	d => \w_data_r[30]~feeder_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => w_data_r(30));

-- Location: IOIBUF_X72_Y81_N1
\w_data_i[31]~input\ : cyclonev_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_w_data_i(31),
	o => \w_data_i[31]~input_o\);

-- Location: LABCELL_X70_Y11_N6
\w_data_r[31]~feeder\ : cyclonev_lcell_comb
-- Equation(s):
-- \w_data_r[31]~feeder_combout\ = ( \w_data_i[31]~input_o\ )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0000000000000000000000000000000011111111111111111111111111111111",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	dataf => \ALT_INV_w_data_i[31]~input_o\,
	combout => \w_data_r[31]~feeder_combout\);

-- Location: FF_X70_Y11_N8
\w_data_r[31]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~inputCLKENA0_outclk\,
	d => \w_data_r[31]~feeder_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => w_data_r(31));

-- Location: IOIBUF_X76_Y81_N18
\w_data_i[32]~input\ : cyclonev_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_w_data_i(32),
	o => \w_data_i[32]~input_o\);

-- Location: FF_X70_Y9_N50
\w_data_r[32]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~inputCLKENA0_outclk\,
	asdata => \w_data_i[32]~input_o\,
	sload => VCC,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => w_data_r(32));

-- Location: IOIBUF_X66_Y81_N92
\w_data_i[33]~input\ : cyclonev_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_w_data_i(33),
	o => \w_data_i[33]~input_o\);

-- Location: LABCELL_X68_Y11_N0
\w_data_r[33]~feeder\ : cyclonev_lcell_comb
-- Equation(s):
-- \w_data_r[33]~feeder_combout\ = ( \w_data_i[33]~input_o\ )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0000000000000000000000000000000011111111111111111111111111111111",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	dataf => \ALT_INV_w_data_i[33]~input_o\,
	combout => \w_data_r[33]~feeder_combout\);

-- Location: FF_X68_Y11_N2
\w_data_r[33]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~inputCLKENA0_outclk\,
	d => \w_data_r[33]~feeder_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => w_data_r(33));

-- Location: IOIBUF_X78_Y81_N35
\w_data_i[34]~input\ : cyclonev_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_w_data_i(34),
	o => \w_data_i[34]~input_o\);

-- Location: FF_X70_Y11_N26
\w_data_r[34]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~inputCLKENA0_outclk\,
	asdata => \w_data_i[34]~input_o\,
	sload => VCC,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => w_data_r(34));

-- Location: IOIBUF_X60_Y81_N1
\w_data_i[35]~input\ : cyclonev_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_w_data_i(35),
	o => \w_data_i[35]~input_o\);

-- Location: FF_X68_Y11_N41
\w_data_r[35]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~inputCLKENA0_outclk\,
	asdata => \w_data_i[35]~input_o\,
	sload => VCC,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => w_data_r(35));

-- Location: IOIBUF_X58_Y0_N58
\w_data_i[36]~input\ : cyclonev_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_w_data_i(36),
	o => \w_data_i[36]~input_o\);

-- Location: FF_X68_Y8_N35
\w_data_r[36]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~inputCLKENA0_outclk\,
	asdata => \w_data_i[36]~input_o\,
	sload => VCC,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => w_data_r(36));

-- Location: IOIBUF_X40_Y81_N1
\w_data_i[37]~input\ : cyclonev_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_w_data_i(37),
	o => \w_data_i[37]~input_o\);

-- Location: LABCELL_X66_Y9_N51
\w_data_r[37]~feeder\ : cyclonev_lcell_comb
-- Equation(s):
-- \w_data_r[37]~feeder_combout\ = ( \w_data_i[37]~input_o\ )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0000000000000000000000000000000011111111111111111111111111111111",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	dataf => \ALT_INV_w_data_i[37]~input_o\,
	combout => \w_data_r[37]~feeder_combout\);

-- Location: FF_X66_Y9_N53
\w_data_r[37]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~inputCLKENA0_outclk\,
	d => \w_data_r[37]~feeder_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => w_data_r(37));

-- Location: IOIBUF_X84_Y81_N18
\w_data_i[38]~input\ : cyclonev_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_w_data_i(38),
	o => \w_data_i[38]~input_o\);

-- Location: LABCELL_X71_Y11_N51
\w_data_r[38]~feeder\ : cyclonev_lcell_comb
-- Equation(s):
-- \w_data_r[38]~feeder_combout\ = ( \w_data_i[38]~input_o\ )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0000000000000000000000000000000011111111111111111111111111111111",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	dataf => \ALT_INV_w_data_i[38]~input_o\,
	combout => \w_data_r[38]~feeder_combout\);

-- Location: FF_X71_Y11_N53
\w_data_r[38]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~inputCLKENA0_outclk\,
	d => \w_data_r[38]~feeder_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => w_data_r(38));

-- Location: IOIBUF_X50_Y0_N92
\w_data_i[39]~input\ : cyclonev_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_w_data_i(39),
	o => \w_data_i[39]~input_o\);

-- Location: LABCELL_X66_Y9_N18
\w_data_r[39]~feeder\ : cyclonev_lcell_comb
-- Equation(s):
-- \w_data_r[39]~feeder_combout\ = ( \w_data_i[39]~input_o\ )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0000000000000000000000000000000011111111111111111111111111111111",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	dataf => \ALT_INV_w_data_i[39]~input_o\,
	combout => \w_data_r[39]~feeder_combout\);

-- Location: FF_X66_Y9_N20
\w_data_r[39]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~inputCLKENA0_outclk\,
	d => \w_data_r[39]~feeder_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => w_data_r(39));

-- Location: M10K_X69_Y9_N0
\rf|RF_rtl_0|auto_generated|ram_block1a0\ : cyclonev_ram_block
-- pragma translate_off
GENERIC MAP (
	data_interleave_offset_in_bits => 1,
	data_interleave_width_in_bits => 1,
	logical_ram_name => "reg_file:rf|altsyncram:RF_rtl_0|altsyncram_83n1:auto_generated|ALTSYNCRAM",
	mixed_port_feed_through_mode => "old",
	operation_mode => "dual_port",
	port_a_address_clear => "none",
	port_a_address_width => 5,
	port_a_byte_enable_clock => "none",
	port_a_data_out_clear => "none",
	port_a_data_out_clock => "none",
	port_a_data_width => 40,
	port_a_first_address => 0,
	port_a_first_bit_number => 0,
	port_a_last_address => 31,
	port_a_logical_ram_depth => 32,
	port_a_logical_ram_width => 64,
	port_a_read_during_write_mode => "new_data_no_nbe_read",
	port_b_address_clear => "none",
	port_b_address_clock => "clock0",
	port_b_address_width => 5,
	port_b_data_out_clear => "none",
	port_b_data_out_clock => "none",
	port_b_data_width => 40,
	port_b_first_address => 0,
	port_b_first_bit_number => 0,
	port_b_last_address => 31,
	port_b_logical_ram_depth => 32,
	port_b_logical_ram_width => 64,
	port_b_read_during_write_mode => "new_data_no_nbe_read",
	port_b_read_enable_clock => "clock0",
	ram_block_type => "M20K")
-- pragma translate_on
PORT MAP (
	portawe => \wen_r~q\,
	portbre => VCC,
	clk0 => \clk~inputCLKENA0_outclk\,
	portadatain => \rf|RF_rtl_0|auto_generated|ram_block1a0_PORTADATAIN_bus\,
	portaaddr => \rf|RF_rtl_0|auto_generated|ram_block1a0_PORTAADDR_bus\,
	portbaddr => \rf|RF_rtl_0|auto_generated|ram_block1a0_PORTBADDR_bus\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	portbdataout => \rf|RF_rtl_0|auto_generated|ram_block1a0_PORTBDATAOUT_bus\);

-- Location: IOIBUF_X72_Y81_N18
\w_data_i[40]~input\ : cyclonev_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_w_data_i(40),
	o => \w_data_i[40]~input_o\);

-- Location: FF_X71_Y11_N14
\w_data_r[40]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~inputCLKENA0_outclk\,
	asdata => \w_data_i[40]~input_o\,
	sload => VCC,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => w_data_r(40));

-- Location: IOIBUF_X68_Y0_N35
\w_data_i[41]~input\ : cyclonev_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_w_data_i(41),
	o => \w_data_i[41]~input_o\);

-- Location: LABCELL_X68_Y8_N18
\w_data_r[41]~feeder\ : cyclonev_lcell_comb
-- Equation(s):
-- \w_data_r[41]~feeder_combout\ = ( \w_data_i[41]~input_o\ )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0000000000000000000000000000000011111111111111111111111111111111",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	dataf => \ALT_INV_w_data_i[41]~input_o\,
	combout => \w_data_r[41]~feeder_combout\);

-- Location: FF_X68_Y8_N20
\w_data_r[41]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~inputCLKENA0_outclk\,
	d => \w_data_r[41]~feeder_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => w_data_r(41));

-- Location: IOIBUF_X74_Y81_N75
\w_data_i[42]~input\ : cyclonev_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_w_data_i(42),
	o => \w_data_i[42]~input_o\);

-- Location: MLABCELL_X72_Y11_N39
\w_data_r[42]~feeder\ : cyclonev_lcell_comb
-- Equation(s):
-- \w_data_r[42]~feeder_combout\ = ( \w_data_i[42]~input_o\ )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0000000000000000000000000000000011111111111111111111111111111111",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	dataf => \ALT_INV_w_data_i[42]~input_o\,
	combout => \w_data_r[42]~feeder_combout\);

-- Location: FF_X72_Y11_N41
\w_data_r[42]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~inputCLKENA0_outclk\,
	d => \w_data_r[42]~feeder_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => w_data_r(42));

-- Location: IOIBUF_X38_Y0_N35
\w_data_i[43]~input\ : cyclonev_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_w_data_i(43),
	o => \w_data_i[43]~input_o\);

-- Location: LABCELL_X66_Y12_N45
\w_data_r[43]~feeder\ : cyclonev_lcell_comb
-- Equation(s):
-- \w_data_r[43]~feeder_combout\ = ( \w_data_i[43]~input_o\ )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0000000000000000000000000000000011111111111111111111111111111111",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	dataf => \ALT_INV_w_data_i[43]~input_o\,
	combout => \w_data_r[43]~feeder_combout\);

-- Location: FF_X66_Y12_N47
\w_data_r[43]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~inputCLKENA0_outclk\,
	d => \w_data_r[43]~feeder_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => w_data_r(43));

-- Location: IOIBUF_X70_Y0_N35
\w_data_i[44]~input\ : cyclonev_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_w_data_i(44),
	o => \w_data_i[44]~input_o\);

-- Location: FF_X70_Y10_N50
\w_data_r[44]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~inputCLKENA0_outclk\,
	asdata => \w_data_i[44]~input_o\,
	sload => VCC,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => w_data_r(44));

-- Location: IOIBUF_X50_Y81_N75
\w_data_i[45]~input\ : cyclonev_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_w_data_i(45),
	o => \w_data_i[45]~input_o\);

-- Location: LABCELL_X66_Y11_N39
\w_data_r[45]~feeder\ : cyclonev_lcell_comb
-- Equation(s):
-- \w_data_r[45]~feeder_combout\ = ( \w_data_i[45]~input_o\ )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0000000000000000000000000000000011111111111111111111111111111111",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	dataf => \ALT_INV_w_data_i[45]~input_o\,
	combout => \w_data_r[45]~feeder_combout\);

-- Location: FF_X66_Y11_N41
\w_data_r[45]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~inputCLKENA0_outclk\,
	d => \w_data_r[45]~feeder_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => w_data_r(45));

-- Location: IOIBUF_X70_Y81_N52
\w_data_i[46]~input\ : cyclonev_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_w_data_i(46),
	o => \w_data_i[46]~input_o\);

-- Location: LABCELL_X70_Y14_N3
\w_data_r[46]~feeder\ : cyclonev_lcell_comb
-- Equation(s):
-- \w_data_r[46]~feeder_combout\ = ( \w_data_i[46]~input_o\ )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0000000000000000000000000000000011111111111111111111111111111111",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	dataf => \ALT_INV_w_data_i[46]~input_o\,
	combout => \w_data_r[46]~feeder_combout\);

-- Location: FF_X70_Y14_N5
\w_data_r[46]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~inputCLKENA0_outclk\,
	d => \w_data_r[46]~feeder_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => w_data_r(46));

-- Location: IOIBUF_X50_Y0_N75
\w_data_i[47]~input\ : cyclonev_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_w_data_i(47),
	o => \w_data_i[47]~input_o\);

-- Location: LABCELL_X68_Y8_N9
\w_data_r[47]~feeder\ : cyclonev_lcell_comb
-- Equation(s):
-- \w_data_r[47]~feeder_combout\ = ( \w_data_i[47]~input_o\ )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0000000000000000000000000000000011111111111111111111111111111111",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	dataf => \ALT_INV_w_data_i[47]~input_o\,
	combout => \w_data_r[47]~feeder_combout\);

-- Location: FF_X68_Y8_N11
\w_data_r[47]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~inputCLKENA0_outclk\,
	d => \w_data_r[47]~feeder_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => w_data_r(47));

-- Location: IOIBUF_X6_Y0_N1
\w_data_i[48]~input\ : cyclonev_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_w_data_i(48),
	o => \w_data_i[48]~input_o\);

-- Location: FF_X68_Y12_N44
\w_data_r[48]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~inputCLKENA0_outclk\,
	asdata => \w_data_i[48]~input_o\,
	sload => VCC,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => w_data_r(48));

-- Location: IOIBUF_X89_Y38_N21
\w_data_i[49]~input\ : cyclonev_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_w_data_i(49),
	o => \w_data_i[49]~input_o\);

-- Location: LABCELL_X70_Y14_N51
\w_data_r[49]~feeder\ : cyclonev_lcell_comb
-- Equation(s):
-- \w_data_r[49]~feeder_combout\ = ( \w_data_i[49]~input_o\ )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0000000000000000000000000000000011111111111111111111111111111111",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	dataf => \ALT_INV_w_data_i[49]~input_o\,
	combout => \w_data_r[49]~feeder_combout\);

-- Location: FF_X70_Y14_N53
\w_data_r[49]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~inputCLKENA0_outclk\,
	d => \w_data_r[49]~feeder_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => w_data_r(49));

-- Location: IOIBUF_X4_Y0_N35
\w_data_i[50]~input\ : cyclonev_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_w_data_i(50),
	o => \w_data_i[50]~input_o\);

-- Location: LABCELL_X68_Y10_N18
\w_data_r[50]~feeder\ : cyclonev_lcell_comb
-- Equation(s):
-- \w_data_r[50]~feeder_combout\ = ( \w_data_i[50]~input_o\ )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0000000000000000000000000000000011111111111111111111111111111111",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	dataf => \ALT_INV_w_data_i[50]~input_o\,
	combout => \w_data_r[50]~feeder_combout\);

-- Location: FF_X68_Y10_N20
\w_data_r[50]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~inputCLKENA0_outclk\,
	d => \w_data_r[50]~feeder_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => w_data_r(50));

-- Location: IOIBUF_X56_Y81_N18
\w_data_i[51]~input\ : cyclonev_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_w_data_i(51),
	o => \w_data_i[51]~input_o\);

-- Location: LABCELL_X66_Y11_N48
\w_data_r[51]~feeder\ : cyclonev_lcell_comb
-- Equation(s):
-- \w_data_r[51]~feeder_combout\ = ( \w_data_i[51]~input_o\ )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0000000000000000000000000000000011111111111111111111111111111111",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	dataf => \ALT_INV_w_data_i[51]~input_o\,
	combout => \w_data_r[51]~feeder_combout\);

-- Location: FF_X66_Y11_N50
\w_data_r[51]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~inputCLKENA0_outclk\,
	d => \w_data_r[51]~feeder_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => w_data_r(51));

-- Location: IOIBUF_X76_Y81_N35
\w_data_i[52]~input\ : cyclonev_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_w_data_i(52),
	o => \w_data_i[52]~input_o\);

-- Location: FF_X70_Y10_N14
\w_data_r[52]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~inputCLKENA0_outclk\,
	asdata => \w_data_i[52]~input_o\,
	sload => VCC,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => w_data_r(52));

-- Location: IOIBUF_X50_Y81_N92
\w_data_i[53]~input\ : cyclonev_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_w_data_i(53),
	o => \w_data_i[53]~input_o\);

-- Location: LABCELL_X68_Y10_N3
\w_data_r[53]~feeder\ : cyclonev_lcell_comb
-- Equation(s):
-- \w_data_r[53]~feeder_combout\ = ( \w_data_i[53]~input_o\ )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0000000000000000000000000000000011111111111111111111111111111111",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	dataf => \ALT_INV_w_data_i[53]~input_o\,
	combout => \w_data_r[53]~feeder_combout\);

-- Location: FF_X68_Y10_N5
\w_data_r[53]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~inputCLKENA0_outclk\,
	d => \w_data_r[53]~feeder_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => w_data_r(53));

-- Location: IOIBUF_X38_Y0_N18
\w_data_i[54]~input\ : cyclonev_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_w_data_i(54),
	o => \w_data_i[54]~input_o\);

-- Location: LABCELL_X68_Y12_N57
\w_data_r[54]~feeder\ : cyclonev_lcell_comb
-- Equation(s):
-- \w_data_r[54]~feeder_combout\ = ( \w_data_i[54]~input_o\ )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0000000000000000000000000000000011111111111111111111111111111111",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	dataf => \ALT_INV_w_data_i[54]~input_o\,
	combout => \w_data_r[54]~feeder_combout\);

-- Location: FF_X68_Y12_N59
\w_data_r[54]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~inputCLKENA0_outclk\,
	d => \w_data_r[54]~feeder_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => w_data_r(54));

-- Location: IOIBUF_X82_Y81_N75
\w_data_i[55]~input\ : cyclonev_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_w_data_i(55),
	o => \w_data_i[55]~input_o\);

-- Location: LABCELL_X70_Y10_N39
\w_data_r[55]~feeder\ : cyclonev_lcell_comb
-- Equation(s):
-- \w_data_r[55]~feeder_combout\ = ( \w_data_i[55]~input_o\ )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0000000000000000000000000000000011111111111111111111111111111111",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	dataf => \ALT_INV_w_data_i[55]~input_o\,
	combout => \w_data_r[55]~feeder_combout\);

-- Location: FF_X70_Y10_N41
\w_data_r[55]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~inputCLKENA0_outclk\,
	d => \w_data_r[55]~feeder_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => w_data_r(55));

-- Location: IOIBUF_X62_Y0_N18
\w_data_i[56]~input\ : cyclonev_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_w_data_i(56),
	o => \w_data_i[56]~input_o\);

-- Location: LABCELL_X68_Y8_N36
\w_data_r[56]~feeder\ : cyclonev_lcell_comb
-- Equation(s):
-- \w_data_r[56]~feeder_combout\ = ( \w_data_i[56]~input_o\ )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0000000000000000000000000000000011111111111111111111111111111111",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	dataf => \ALT_INV_w_data_i[56]~input_o\,
	combout => \w_data_r[56]~feeder_combout\);

-- Location: FF_X68_Y8_N38
\w_data_r[56]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~inputCLKENA0_outclk\,
	d => \w_data_r[56]~feeder_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => w_data_r(56));

-- Location: IOIBUF_X82_Y81_N41
\w_data_i[57]~input\ : cyclonev_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_w_data_i(57),
	o => \w_data_i[57]~input_o\);

-- Location: LABCELL_X71_Y11_N6
\w_data_r[57]~feeder\ : cyclonev_lcell_comb
-- Equation(s):
-- \w_data_r[57]~feeder_combout\ = ( \w_data_i[57]~input_o\ )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0000000000000000000000000000000011111111111111111111111111111111",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	dataf => \ALT_INV_w_data_i[57]~input_o\,
	combout => \w_data_r[57]~feeder_combout\);

-- Location: FF_X71_Y11_N8
\w_data_r[57]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~inputCLKENA0_outclk\,
	d => \w_data_r[57]~feeder_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => w_data_r(57));

-- Location: IOIBUF_X56_Y81_N35
\w_data_i[58]~input\ : cyclonev_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_w_data_i(58),
	o => \w_data_i[58]~input_o\);

-- Location: FF_X67_Y11_N2
\w_data_r[58]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~inputCLKENA0_outclk\,
	asdata => \w_data_i[58]~input_o\,
	sload => VCC,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => w_data_r(58));

-- Location: IOIBUF_X72_Y81_N52
\w_data_i[59]~input\ : cyclonev_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_w_data_i(59),
	o => \w_data_i[59]~input_o\);

-- Location: LABCELL_X70_Y11_N39
\w_data_r[59]~feeder\ : cyclonev_lcell_comb
-- Equation(s):
-- \w_data_r[59]~feeder_combout\ = ( \w_data_i[59]~input_o\ )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0000000000000000000000000000000011111111111111111111111111111111",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	dataf => \ALT_INV_w_data_i[59]~input_o\,
	combout => \w_data_r[59]~feeder_combout\);

-- Location: FF_X70_Y11_N41
\w_data_r[59]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~inputCLKENA0_outclk\,
	d => \w_data_r[59]~feeder_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => w_data_r(59));

-- Location: IOIBUF_X68_Y81_N52
\w_data_i[60]~input\ : cyclonev_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_w_data_i(60),
	o => \w_data_i[60]~input_o\);

-- Location: FF_X68_Y13_N50
\w_data_r[60]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~inputCLKENA0_outclk\,
	asdata => \w_data_i[60]~input_o\,
	sload => VCC,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => w_data_r(60));

-- Location: IOIBUF_X62_Y81_N35
\w_data_i[61]~input\ : cyclonev_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_w_data_i(61),
	o => \w_data_i[61]~input_o\);

-- Location: FF_X66_Y11_N11
\w_data_r[61]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~inputCLKENA0_outclk\,
	asdata => \w_data_i[61]~input_o\,
	sload => VCC,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => w_data_r(61));

-- Location: IOIBUF_X62_Y0_N35
\w_data_i[62]~input\ : cyclonev_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_w_data_i(62),
	o => \w_data_i[62]~input_o\);

-- Location: LABCELL_X68_Y10_N45
\w_data_r[62]~feeder\ : cyclonev_lcell_comb
-- Equation(s):
-- \w_data_r[62]~feeder_combout\ = ( \w_data_i[62]~input_o\ )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0000000000000000000000000000000011111111111111111111111111111111",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	dataf => \ALT_INV_w_data_i[62]~input_o\,
	combout => \w_data_r[62]~feeder_combout\);

-- Location: FF_X68_Y10_N47
\w_data_r[62]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~inputCLKENA0_outclk\,
	d => \w_data_r[62]~feeder_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => w_data_r(62));

-- Location: IOIBUF_X74_Y81_N58
\w_data_i[63]~input\ : cyclonev_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_w_data_i(63),
	o => \w_data_i[63]~input_o\);

-- Location: FF_X73_Y13_N53
\w_data_r[63]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~inputCLKENA0_outclk\,
	asdata => \w_data_i[63]~input_o\,
	sload => VCC,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => w_data_r(63));

-- Location: M10K_X69_Y10_N0
\rf|RF_rtl_0|auto_generated|ram_block1a40\ : cyclonev_ram_block
-- pragma translate_off
GENERIC MAP (
	data_interleave_offset_in_bits => 1,
	data_interleave_width_in_bits => 1,
	logical_ram_name => "reg_file:rf|altsyncram:RF_rtl_0|altsyncram_83n1:auto_generated|ALTSYNCRAM",
	mixed_port_feed_through_mode => "old",
	operation_mode => "dual_port",
	port_a_address_clear => "none",
	port_a_address_width => 5,
	port_a_byte_enable_clock => "none",
	port_a_data_out_clear => "none",
	port_a_data_out_clock => "none",
	port_a_data_width => 40,
	port_a_first_address => 0,
	port_a_first_bit_number => 40,
	port_a_last_address => 31,
	port_a_logical_ram_depth => 32,
	port_a_logical_ram_width => 64,
	port_a_read_during_write_mode => "new_data_no_nbe_read",
	port_b_address_clear => "none",
	port_b_address_clock => "clock0",
	port_b_address_width => 5,
	port_b_data_out_clear => "none",
	port_b_data_out_clock => "none",
	port_b_data_width => 40,
	port_b_first_address => 0,
	port_b_first_bit_number => 40,
	port_b_last_address => 31,
	port_b_logical_ram_depth => 32,
	port_b_logical_ram_width => 64,
	port_b_read_during_write_mode => "new_data_no_nbe_read",
	port_b_read_enable_clock => "clock0",
	ram_block_type => "M20K")
-- pragma translate_on
PORT MAP (
	portawe => \wen_r~q\,
	portbre => VCC,
	clk0 => \clk~inputCLKENA0_outclk\,
	portadatain => \rf|RF_rtl_0|auto_generated|ram_block1a40_PORTADATAIN_bus\,
	portaaddr => \rf|RF_rtl_0|auto_generated|ram_block1a40_PORTAADDR_bus\,
	portbaddr => \rf|RF_rtl_0|auto_generated|ram_block1a40_PORTBADDR_bus\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	portbdataout => \rf|RF_rtl_0|auto_generated|ram_block1a40_PORTBDATAOUT_bus\);

-- Location: IOIBUF_X52_Y81_N52
\rd_addr_i[0]~input\ : cyclonev_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_rd_addr_i(0),
	o => \rd_addr_i[0]~input_o\);

-- Location: LABCELL_X68_Y11_N18
\rd_addr_r[0]~feeder\ : cyclonev_lcell_comb
-- Equation(s):
-- \rd_addr_r[0]~feeder_combout\ = ( \rd_addr_i[0]~input_o\ )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0000000000000000000000000000000011111111111111111111111111111111",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	dataf => \ALT_INV_rd_addr_i[0]~input_o\,
	combout => \rd_addr_r[0]~feeder_combout\);

-- Location: FF_X68_Y11_N20
\rd_addr_r[0]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~inputCLKENA0_outclk\,
	d => \rd_addr_r[0]~feeder_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => rd_addr_r(0));

-- Location: IOIBUF_X68_Y81_N18
\rd_addr_i[1]~input\ : cyclonev_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_rd_addr_i(1),
	o => \rd_addr_i[1]~input_o\);

-- Location: LABCELL_X68_Y11_N48
\rd_addr_r[1]~feeder\ : cyclonev_lcell_comb
-- Equation(s):
-- \rd_addr_r[1]~feeder_combout\ = ( \rd_addr_i[1]~input_o\ )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0000000000000000000000000000000011111111111111111111111111111111",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	dataf => \ALT_INV_rd_addr_i[1]~input_o\,
	combout => \rd_addr_r[1]~feeder_combout\);

-- Location: FF_X68_Y11_N50
\rd_addr_r[1]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~inputCLKENA0_outclk\,
	d => \rd_addr_r[1]~feeder_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => rd_addr_r(1));

-- Location: IOIBUF_X68_Y81_N35
\rd_addr_i[2]~input\ : cyclonev_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_rd_addr_i(2),
	o => \rd_addr_i[2]~input_o\);

-- Location: LABCELL_X68_Y11_N36
\rd_addr_r[2]~feeder\ : cyclonev_lcell_comb
-- Equation(s):
-- \rd_addr_r[2]~feeder_combout\ = ( \rd_addr_i[2]~input_o\ )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0000000000000000000000000000000011111111111111111111111111111111",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	dataf => \ALT_INV_rd_addr_i[2]~input_o\,
	combout => \rd_addr_r[2]~feeder_combout\);

-- Location: FF_X68_Y11_N38
\rd_addr_r[2]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~inputCLKENA0_outclk\,
	d => \rd_addr_r[2]~feeder_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => rd_addr_r(2));

-- Location: IOIBUF_X76_Y81_N1
\rd_addr_i[3]~input\ : cyclonev_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_rd_addr_i(3),
	o => \rd_addr_i[3]~input_o\);

-- Location: FF_X70_Y11_N11
\rd_addr_r[3]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~inputCLKENA0_outclk\,
	asdata => \rd_addr_i[3]~input_o\,
	sload => VCC,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => rd_addr_r(3));

-- Location: IOIBUF_X70_Y81_N1
\rd_addr_i[4]~input\ : cyclonev_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_rd_addr_i(4),
	o => \rd_addr_i[4]~input_o\);

-- Location: FF_X70_Y11_N23
\rd_addr_r[4]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~inputCLKENA0_outclk\,
	asdata => \rd_addr_i[4]~input_o\,
	sload => VCC,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => rd_addr_r(4));

-- Location: M10K_X69_Y11_N0
\rf|RF_rtl_1|auto_generated|ram_block1a0\ : cyclonev_ram_block
-- pragma translate_off
GENERIC MAP (
	data_interleave_offset_in_bits => 1,
	data_interleave_width_in_bits => 1,
	logical_ram_name => "reg_file:rf|altsyncram:RF_rtl_1|altsyncram_83n1:auto_generated|ALTSYNCRAM",
	mixed_port_feed_through_mode => "old",
	operation_mode => "dual_port",
	port_a_address_clear => "none",
	port_a_address_width => 5,
	port_a_byte_enable_clock => "none",
	port_a_data_out_clear => "none",
	port_a_data_out_clock => "none",
	port_a_data_width => 40,
	port_a_first_address => 0,
	port_a_first_bit_number => 0,
	port_a_last_address => 31,
	port_a_logical_ram_depth => 32,
	port_a_logical_ram_width => 64,
	port_a_read_during_write_mode => "new_data_no_nbe_read",
	port_b_address_clear => "none",
	port_b_address_clock => "clock0",
	port_b_address_width => 5,
	port_b_data_out_clear => "none",
	port_b_data_out_clock => "none",
	port_b_data_width => 40,
	port_b_first_address => 0,
	port_b_first_bit_number => 0,
	port_b_last_address => 31,
	port_b_logical_ram_depth => 32,
	port_b_logical_ram_width => 64,
	port_b_read_during_write_mode => "new_data_no_nbe_read",
	port_b_read_enable_clock => "clock0",
	ram_block_type => "M20K")
-- pragma translate_on
PORT MAP (
	portawe => \wen_r~q\,
	portbre => VCC,
	clk0 => \clk~inputCLKENA0_outclk\,
	portadatain => \rf|RF_rtl_1|auto_generated|ram_block1a0_PORTADATAIN_bus\,
	portaaddr => \rf|RF_rtl_1|auto_generated|ram_block1a0_PORTAADDR_bus\,
	portbaddr => \rf|RF_rtl_1|auto_generated|ram_block1a0_PORTBADDR_bus\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	portbdataout => \rf|RF_rtl_1|auto_generated|ram_block1a0_PORTBDATAOUT_bus\);

-- Location: M10K_X69_Y12_N0
\rf|RF_rtl_1|auto_generated|ram_block1a40\ : cyclonev_ram_block
-- pragma translate_off
GENERIC MAP (
	data_interleave_offset_in_bits => 1,
	data_interleave_width_in_bits => 1,
	logical_ram_name => "reg_file:rf|altsyncram:RF_rtl_1|altsyncram_83n1:auto_generated|ALTSYNCRAM",
	mixed_port_feed_through_mode => "old",
	operation_mode => "dual_port",
	port_a_address_clear => "none",
	port_a_address_width => 5,
	port_a_byte_enable_clock => "none",
	port_a_data_out_clear => "none",
	port_a_data_out_clock => "none",
	port_a_data_width => 40,
	port_a_first_address => 0,
	port_a_first_bit_number => 40,
	port_a_last_address => 31,
	port_a_logical_ram_depth => 32,
	port_a_logical_ram_width => 64,
	port_a_read_during_write_mode => "new_data_no_nbe_read",
	port_b_address_clear => "none",
	port_b_address_clock => "clock0",
	port_b_address_width => 5,
	port_b_data_out_clear => "none",
	port_b_data_out_clock => "none",
	port_b_data_width => 40,
	port_b_first_address => 0,
	port_b_first_bit_number => 40,
	port_b_last_address => 31,
	port_b_logical_ram_depth => 32,
	port_b_logical_ram_width => 64,
	port_b_read_during_write_mode => "new_data_no_nbe_read",
	port_b_read_enable_clock => "clock0",
	ram_block_type => "M20K")
-- pragma translate_on
PORT MAP (
	portawe => \wen_r~q\,
	portbre => VCC,
	clk0 => \clk~inputCLKENA0_outclk\,
	portadatain => \rf|RF_rtl_1|auto_generated|ram_block1a40_PORTADATAIN_bus\,
	portaaddr => \rf|RF_rtl_1|auto_generated|ram_block1a40_PORTAADDR_bus\,
	portbaddr => \rf|RF_rtl_1|auto_generated|ram_block1a40_PORTBADDR_bus\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	portbdataout => \rf|RF_rtl_1|auto_generated|ram_block1a40_PORTBDATAOUT_bus\);

-- Location: MLABCELL_X3_Y39_N3
\~QUARTUS_CREATED_GND~I\ : cyclonev_lcell_comb
-- Equation(s):

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0000000000000000000000000000000000000000000000000000000000000000",
	shared_arith => "off")
-- pragma translate_on
;
END structure;


