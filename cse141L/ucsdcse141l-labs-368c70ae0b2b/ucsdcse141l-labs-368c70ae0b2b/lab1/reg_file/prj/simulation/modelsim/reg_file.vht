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

-- ***************************************************************************
-- This file contains a Vhdl test bench template that is freely editable to   
-- suit user's needs .Comments are provided in each section to help the user  
-- fill out necessary details.                                                
-- ***************************************************************************
-- Generated on "01/22/2016 04:54:14"
                                                            
-- Vhdl Test Bench template for design  :  reg_file
-- 
-- Simulation tool : ModelSim-Altera (VHDL)
-- 

LIBRARY ieee;                                               
USE ieee.std_logic_1164.all;                                

ENTITY reg_file_vhd_tst IS
END reg_file_vhd_tst;
ARCHITECTURE reg_file_arch OF reg_file_vhd_tst IS
-- constants                                                 
-- signals                                                   
SIGNAL clk : STD_LOGIC;
SIGNAL rd_addr_i : STD_LOGIC_VECTOR(5 DOWNTO 0);
SIGNAL rd_val_o : STD_LOGIC_VECTOR(31 DOWNTO 0);
SIGNAL rs_addr_i : STD_LOGIC_VECTOR(5 DOWNTO 0);
SIGNAL rs_val_o : STD_LOGIC_VECTOR(31 DOWNTO 0);
SIGNAL w_addr_i : STD_LOGIC_VECTOR(5 DOWNTO 0);
SIGNAL w_data_i : STD_LOGIC_VECTOR(31 DOWNTO 0);
SIGNAL wen_i : STD_LOGIC;
COMPONENT reg_file
	PORT (
	clk : IN STD_LOGIC;
	rd_addr_i : IN STD_LOGIC_VECTOR(5 DOWNTO 0);
	rd_val_o : BUFFER STD_LOGIC_VECTOR(31 DOWNTO 0);
	rs_addr_i : IN STD_LOGIC_VECTOR(5 DOWNTO 0);
	rs_val_o : BUFFER STD_LOGIC_VECTOR(31 DOWNTO 0);
	w_addr_i : IN STD_LOGIC_VECTOR(5 DOWNTO 0);
	w_data_i : IN STD_LOGIC_VECTOR(31 DOWNTO 0);
	wen_i : IN STD_LOGIC
	);
END COMPONENT;
BEGIN
	i1 : reg_file
	PORT MAP (
-- list connections between master ports and signals
	clk => clk,
	rd_addr_i => rd_addr_i,
	rd_val_o => rd_val_o,
	rs_addr_i => rs_addr_i,
	rs_val_o => rs_val_o,
	w_addr_i => w_addr_i,
	w_data_i => w_data_i,
	wen_i => wen_i
	);
init : PROCESS                                               
-- variable declarations                                     
BEGIN                                                        
        -- code that executes only once                      
WAIT;                                                       
END PROCESS init;                                           
always : PROCESS                                              
-- optional sensitivity list                                  
-- (        )                                                 
-- variable declarations                                      
BEGIN                                                         
        -- code executes for every event on sensitivity list  
WAIT;                                                        
END PROCESS always;                                          
END reg_file_arch;
