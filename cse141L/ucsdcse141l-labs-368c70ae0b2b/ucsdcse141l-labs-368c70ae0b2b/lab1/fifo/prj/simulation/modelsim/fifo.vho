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

-- DATE "01/22/2016 06:35:29"

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

ENTITY 	fifo IS
    PORT (
	clk : IN std_logic;
	d_i : IN std_logic_vector(26 DOWNTO 0);
	enque_i : IN std_logic;
	deque_i : IN std_logic;
	clear_i : IN std_logic;
	d_o : OUT std_logic_vector(26 DOWNTO 0);
	empty_o : OUT std_logic;
	full_o : OUT std_logic;
	valid_o : OUT std_logic
	);
END fifo;

-- Design Ports Information
-- d_o[0]	=>  Location: PIN_T10,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- d_o[1]	=>  Location: PIN_W19,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- d_o[2]	=>  Location: PIN_P9,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- d_o[3]	=>  Location: PIN_AB10,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- d_o[4]	=>  Location: PIN_V19,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- d_o[5]	=>  Location: PIN_AA22,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- d_o[6]	=>  Location: PIN_Y11,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- d_o[7]	=>  Location: PIN_T12,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- d_o[8]	=>  Location: PIN_V16,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- d_o[9]	=>  Location: PIN_U20,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- d_o[10]	=>  Location: PIN_V18,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- d_o[11]	=>  Location: PIN_Y14,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- d_o[12]	=>  Location: PIN_W16,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- d_o[13]	=>  Location: PIN_R10,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- d_o[14]	=>  Location: PIN_N9,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- d_o[15]	=>  Location: PIN_V21,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- d_o[16]	=>  Location: PIN_W21,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- d_o[17]	=>  Location: PIN_R11,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- d_o[18]	=>  Location: PIN_AA12,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- d_o[19]	=>  Location: PIN_AA20,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- d_o[20]	=>  Location: PIN_AA19,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- d_o[21]	=>  Location: PIN_AB15,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- d_o[22]	=>  Location: PIN_U22,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- d_o[23]	=>  Location: PIN_Y21,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- d_o[24]	=>  Location: PIN_P14,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- d_o[25]	=>  Location: PIN_AA15,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- d_o[26]	=>  Location: PIN_R14,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- empty_o	=>  Location: PIN_AA10,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- full_o	=>  Location: PIN_AB11,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- valid_o	=>  Location: PIN_AA9,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- d_i[0]	=>  Location: PIN_AA13,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- clk	=>  Location: PIN_M16,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- enque_i	=>  Location: PIN_Y15,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- clear_i	=>  Location: PIN_U12,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- deque_i	=>  Location: PIN_P12,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- d_i[1]	=>  Location: PIN_Y17,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- d_i[2]	=>  Location: PIN_T13,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- d_i[3]	=>  Location: PIN_R12,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- d_i[4]	=>  Location: PIN_AA17,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- d_i[5]	=>  Location: PIN_V14,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- d_i[6]	=>  Location: PIN_AA14,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- d_i[7]	=>  Location: PIN_U11,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- d_i[8]	=>  Location: PIN_V20,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- d_i[9]	=>  Location: PIN_AB20,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- d_i[10]	=>  Location: PIN_Y16,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- d_i[11]	=>  Location: PIN_AA18,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- d_i[12]	=>  Location: PIN_AB18,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- d_i[13]	=>  Location: PIN_AB13,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- d_i[14]	=>  Location: PIN_U13,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- d_i[15]	=>  Location: PIN_AB21,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- d_i[16]	=>  Location: PIN_T14,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- d_i[17]	=>  Location: PIN_AB12,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- d_i[18]	=>  Location: PIN_V13,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- d_i[19]	=>  Location: PIN_Y20,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- d_i[20]	=>  Location: PIN_AB22,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- d_i[21]	=>  Location: PIN_W22,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- d_i[22]	=>  Location: PIN_U15,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- d_i[23]	=>  Location: PIN_V15,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- d_i[24]	=>  Location: PIN_Y22,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- d_i[25]	=>  Location: PIN_Y19,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- d_i[26]	=>  Location: PIN_AB17,	 I/O Standard: 2.5 V,	 Current Strength: Default


ARCHITECTURE structure OF fifo IS
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
SIGNAL ww_d_i : std_logic_vector(26 DOWNTO 0);
SIGNAL ww_enque_i : std_logic;
SIGNAL ww_deque_i : std_logic;
SIGNAL ww_clear_i : std_logic;
SIGNAL ww_d_o : std_logic_vector(26 DOWNTO 0);
SIGNAL ww_empty_o : std_logic;
SIGNAL ww_full_o : std_logic;
SIGNAL ww_valid_o : std_logic;
SIGNAL \storage_rtl_0|auto_generated|ram_block1a0_PORTADATAIN_bus\ : std_logic_vector(39 DOWNTO 0);
SIGNAL \storage_rtl_0|auto_generated|ram_block1a0_PORTAADDR_bus\ : std_logic_vector(1 DOWNTO 0);
SIGNAL \storage_rtl_0|auto_generated|ram_block1a0_PORTBADDR_bus\ : std_logic_vector(1 DOWNTO 0);
SIGNAL \storage_rtl_0|auto_generated|ram_block1a0_PORTBDATAOUT_bus\ : std_logic_vector(39 DOWNTO 0);
SIGNAL \~QUARTUS_CREATED_GND~I_combout\ : std_logic;
SIGNAL \enque_i~input_o\ : std_logic;
SIGNAL \clk~input_o\ : std_logic;
SIGNAL \clk~inputCLKENA0_outclk\ : std_logic;
SIGNAL \d_i[0]~input_o\ : std_logic;
SIGNAL \clear_i~input_o\ : std_logic;
SIGNAL \wptr_r_a[0]~0_combout\ : std_logic;
SIGNAL \wptr_r_a[1]~1_combout\ : std_logic;
SIGNAL \deque_i~input_o\ : std_logic;
SIGNAL \rptr_r_a[0]~0_combout\ : std_logic;
SIGNAL \rptr_r_a[1]~1_combout\ : std_logic;
SIGNAL \d_i[1]~input_o\ : std_logic;
SIGNAL \d_i[2]~input_o\ : std_logic;
SIGNAL \d_i[3]~input_o\ : std_logic;
SIGNAL \d_i[4]~input_o\ : std_logic;
SIGNAL \d_i[5]~input_o\ : std_logic;
SIGNAL \d_i[6]~input_o\ : std_logic;
SIGNAL \d_i[7]~input_o\ : std_logic;
SIGNAL \d_i[8]~input_o\ : std_logic;
SIGNAL \d_i[9]~input_o\ : std_logic;
SIGNAL \d_i[10]~input_o\ : std_logic;
SIGNAL \d_i[11]~input_o\ : std_logic;
SIGNAL \d_i[12]~input_o\ : std_logic;
SIGNAL \d_i[13]~input_o\ : std_logic;
SIGNAL \d_i[14]~input_o\ : std_logic;
SIGNAL \d_i[15]~input_o\ : std_logic;
SIGNAL \d_i[16]~input_o\ : std_logic;
SIGNAL \d_i[17]~input_o\ : std_logic;
SIGNAL \d_i[18]~input_o\ : std_logic;
SIGNAL \d_i[19]~input_o\ : std_logic;
SIGNAL \d_i[20]~input_o\ : std_logic;
SIGNAL \d_i[21]~input_o\ : std_logic;
SIGNAL \d_i[22]~input_o\ : std_logic;
SIGNAL \d_i[23]~input_o\ : std_logic;
SIGNAL \d_i[24]~input_o\ : std_logic;
SIGNAL \d_i[25]~input_o\ : std_logic;
SIGNAL \d_i[26]~input_o\ : std_logic;
SIGNAL \storage_rtl_0|auto_generated|ram_block1a0~portbdataout\ : std_logic;
SIGNAL \storage~0_combout\ : std_logic;
SIGNAL \storage~1_combout\ : std_logic;
SIGNAL \storage_rtl_0|auto_generated|ram_block1a1\ : std_logic;
SIGNAL \storage~2_combout\ : std_logic;
SIGNAL \storage_rtl_0|auto_generated|ram_block1a2\ : std_logic;
SIGNAL \storage~3_combout\ : std_logic;
SIGNAL \storage_rtl_0|auto_generated|ram_block1a3\ : std_logic;
SIGNAL \storage~4_combout\ : std_logic;
SIGNAL \storage_rtl_0|auto_generated|ram_block1a4\ : std_logic;
SIGNAL \storage~5_combout\ : std_logic;
SIGNAL \storage_rtl_0|auto_generated|ram_block1a5\ : std_logic;
SIGNAL \storage~6_combout\ : std_logic;
SIGNAL \storage_rtl_0|auto_generated|ram_block1a6\ : std_logic;
SIGNAL \storage~7_combout\ : std_logic;
SIGNAL \storage_rtl_0|auto_generated|ram_block1a7\ : std_logic;
SIGNAL \storage~8_combout\ : std_logic;
SIGNAL \storage_rtl_0|auto_generated|ram_block1a8\ : std_logic;
SIGNAL \storage~9_combout\ : std_logic;
SIGNAL \storage_rtl_0|auto_generated|ram_block1a9\ : std_logic;
SIGNAL \storage~10_combout\ : std_logic;
SIGNAL \storage_rtl_0|auto_generated|ram_block1a10\ : std_logic;
SIGNAL \storage~11_combout\ : std_logic;
SIGNAL \storage_rtl_0|auto_generated|ram_block1a11\ : std_logic;
SIGNAL \storage~12_combout\ : std_logic;
SIGNAL \storage_rtl_0|auto_generated|ram_block1a12\ : std_logic;
SIGNAL \storage~13_combout\ : std_logic;
SIGNAL \storage_rtl_0|auto_generated|ram_block1a13\ : std_logic;
SIGNAL \storage~14_combout\ : std_logic;
SIGNAL \storage_rtl_0|auto_generated|ram_block1a14\ : std_logic;
SIGNAL \storage~15_combout\ : std_logic;
SIGNAL \storage_rtl_0|auto_generated|ram_block1a15\ : std_logic;
SIGNAL \storage~16_combout\ : std_logic;
SIGNAL \storage_rtl_0|auto_generated|ram_block1a16\ : std_logic;
SIGNAL \storage~17_combout\ : std_logic;
SIGNAL \storage_rtl_0|auto_generated|ram_block1a17\ : std_logic;
SIGNAL \storage~18_combout\ : std_logic;
SIGNAL \storage_rtl_0|auto_generated|ram_block1a18\ : std_logic;
SIGNAL \storage~19_combout\ : std_logic;
SIGNAL \storage_rtl_0|auto_generated|ram_block1a19\ : std_logic;
SIGNAL \storage~20_combout\ : std_logic;
SIGNAL \storage_rtl_0|auto_generated|ram_block1a20\ : std_logic;
SIGNAL \storage~21_combout\ : std_logic;
SIGNAL \storage_rtl_0|auto_generated|ram_block1a21\ : std_logic;
SIGNAL \storage~22_combout\ : std_logic;
SIGNAL \storage_rtl_0|auto_generated|ram_block1a22\ : std_logic;
SIGNAL \storage~23_combout\ : std_logic;
SIGNAL \storage_rtl_0|auto_generated|ram_block1a23\ : std_logic;
SIGNAL \storage~24_combout\ : std_logic;
SIGNAL \storage_rtl_0|auto_generated|ram_block1a24\ : std_logic;
SIGNAL \storage~25_combout\ : std_logic;
SIGNAL \storage_rtl_0|auto_generated|ram_block1a25\ : std_logic;
SIGNAL \storage~26_combout\ : std_logic;
SIGNAL \storage_rtl_0|auto_generated|ram_block1a26\ : std_logic;
SIGNAL \storage~27_combout\ : std_logic;
SIGNAL \Equal1~0_combout\ : std_logic;
SIGNAL \Equal0~0_combout\ : std_logic;
SIGNAL storage_rtl_0_bypass : std_logic_vector(0 TO 31);
SIGNAL rptr_r : std_logic_vector(1 DOWNTO 0);
SIGNAL wptr_r : std_logic_vector(1 DOWNTO 0);
SIGNAL \ALT_INV_deque_i~input_o\ : std_logic;
SIGNAL \ALT_INV_clear_i~input_o\ : std_logic;
SIGNAL \ALT_INV_enque_i~input_o\ : std_logic;
SIGNAL \ALT_INV_Equal0~0_combout\ : std_logic;
SIGNAL \ALT_INV_Equal1~0_combout\ : std_logic;
SIGNAL ALT_INV_wptr_r : std_logic_vector(1 DOWNTO 0);
SIGNAL ALT_INV_rptr_r : std_logic_vector(1 DOWNTO 0);
SIGNAL ALT_INV_storage_rtl_0_bypass : std_logic_vector(31 DOWNTO 0);
SIGNAL \ALT_INV_storage~0_combout\ : std_logic;
SIGNAL \storage_rtl_0|auto_generated|ALT_INV_ram_block1a1\ : std_logic;
SIGNAL \storage_rtl_0|auto_generated|ALT_INV_ram_block1a2\ : std_logic;
SIGNAL \storage_rtl_0|auto_generated|ALT_INV_ram_block1a3\ : std_logic;
SIGNAL \storage_rtl_0|auto_generated|ALT_INV_ram_block1a4\ : std_logic;
SIGNAL \storage_rtl_0|auto_generated|ALT_INV_ram_block1a5\ : std_logic;
SIGNAL \storage_rtl_0|auto_generated|ALT_INV_ram_block1a6\ : std_logic;
SIGNAL \storage_rtl_0|auto_generated|ALT_INV_ram_block1a7\ : std_logic;
SIGNAL \storage_rtl_0|auto_generated|ALT_INV_ram_block1a8\ : std_logic;
SIGNAL \storage_rtl_0|auto_generated|ALT_INV_ram_block1a9\ : std_logic;
SIGNAL \storage_rtl_0|auto_generated|ALT_INV_ram_block1a10\ : std_logic;
SIGNAL \storage_rtl_0|auto_generated|ALT_INV_ram_block1a11\ : std_logic;
SIGNAL \storage_rtl_0|auto_generated|ALT_INV_ram_block1a12\ : std_logic;
SIGNAL \storage_rtl_0|auto_generated|ALT_INV_ram_block1a13\ : std_logic;
SIGNAL \storage_rtl_0|auto_generated|ALT_INV_ram_block1a14\ : std_logic;
SIGNAL \storage_rtl_0|auto_generated|ALT_INV_ram_block1a15\ : std_logic;
SIGNAL \storage_rtl_0|auto_generated|ALT_INV_ram_block1a16\ : std_logic;
SIGNAL \storage_rtl_0|auto_generated|ALT_INV_ram_block1a17\ : std_logic;
SIGNAL \storage_rtl_0|auto_generated|ALT_INV_ram_block1a18\ : std_logic;
SIGNAL \storage_rtl_0|auto_generated|ALT_INV_ram_block1a19\ : std_logic;
SIGNAL \storage_rtl_0|auto_generated|ALT_INV_ram_block1a20\ : std_logic;
SIGNAL \storage_rtl_0|auto_generated|ALT_INV_ram_block1a21\ : std_logic;
SIGNAL \storage_rtl_0|auto_generated|ALT_INV_ram_block1a22\ : std_logic;
SIGNAL \storage_rtl_0|auto_generated|ALT_INV_ram_block1a23\ : std_logic;
SIGNAL \storage_rtl_0|auto_generated|ALT_INV_ram_block1a24\ : std_logic;
SIGNAL \storage_rtl_0|auto_generated|ALT_INV_ram_block1a25\ : std_logic;
SIGNAL \storage_rtl_0|auto_generated|ALT_INV_ram_block1a26\ : std_logic;
SIGNAL \storage_rtl_0|auto_generated|ALT_INV_ram_block1a0~portbdataout\ : std_logic;

BEGIN

ww_clk <= clk;
ww_d_i <= d_i;
ww_enque_i <= enque_i;
ww_deque_i <= deque_i;
ww_clear_i <= clear_i;
d_o <= ww_d_o;
empty_o <= ww_empty_o;
full_o <= ww_full_o;
valid_o <= ww_valid_o;
ww_devoe <= devoe;
ww_devclrn <= devclrn;
ww_devpor <= devpor;

\storage_rtl_0|auto_generated|ram_block1a0_PORTADATAIN_bus\ <= (gnd & gnd & gnd & gnd & gnd & gnd & gnd & gnd & gnd & gnd & gnd & gnd & gnd & \d_i[26]~input_o\ & \d_i[25]~input_o\ & \d_i[24]~input_o\ & \d_i[23]~input_o\ & \d_i[22]~input_o\ & 
\d_i[21]~input_o\ & \d_i[20]~input_o\ & \d_i[19]~input_o\ & \d_i[18]~input_o\ & \d_i[17]~input_o\ & \d_i[16]~input_o\ & \d_i[15]~input_o\ & \d_i[14]~input_o\ & \d_i[13]~input_o\ & \d_i[12]~input_o\ & \d_i[11]~input_o\ & \d_i[10]~input_o\ & 
\d_i[9]~input_o\ & \d_i[8]~input_o\ & \d_i[7]~input_o\ & \d_i[6]~input_o\ & \d_i[5]~input_o\ & \d_i[4]~input_o\ & \d_i[3]~input_o\ & \d_i[2]~input_o\ & \d_i[1]~input_o\ & \d_i[0]~input_o\);

\storage_rtl_0|auto_generated|ram_block1a0_PORTAADDR_bus\ <= (wptr_r(1) & wptr_r(0));

\storage_rtl_0|auto_generated|ram_block1a0_PORTBADDR_bus\ <= (\rptr_r_a[1]~1_combout\ & \rptr_r_a[0]~0_combout\);

\storage_rtl_0|auto_generated|ram_block1a0~portbdataout\ <= \storage_rtl_0|auto_generated|ram_block1a0_PORTBDATAOUT_bus\(0);
\storage_rtl_0|auto_generated|ram_block1a1\ <= \storage_rtl_0|auto_generated|ram_block1a0_PORTBDATAOUT_bus\(1);
\storage_rtl_0|auto_generated|ram_block1a2\ <= \storage_rtl_0|auto_generated|ram_block1a0_PORTBDATAOUT_bus\(2);
\storage_rtl_0|auto_generated|ram_block1a3\ <= \storage_rtl_0|auto_generated|ram_block1a0_PORTBDATAOUT_bus\(3);
\storage_rtl_0|auto_generated|ram_block1a4\ <= \storage_rtl_0|auto_generated|ram_block1a0_PORTBDATAOUT_bus\(4);
\storage_rtl_0|auto_generated|ram_block1a5\ <= \storage_rtl_0|auto_generated|ram_block1a0_PORTBDATAOUT_bus\(5);
\storage_rtl_0|auto_generated|ram_block1a6\ <= \storage_rtl_0|auto_generated|ram_block1a0_PORTBDATAOUT_bus\(6);
\storage_rtl_0|auto_generated|ram_block1a7\ <= \storage_rtl_0|auto_generated|ram_block1a0_PORTBDATAOUT_bus\(7);
\storage_rtl_0|auto_generated|ram_block1a8\ <= \storage_rtl_0|auto_generated|ram_block1a0_PORTBDATAOUT_bus\(8);
\storage_rtl_0|auto_generated|ram_block1a9\ <= \storage_rtl_0|auto_generated|ram_block1a0_PORTBDATAOUT_bus\(9);
\storage_rtl_0|auto_generated|ram_block1a10\ <= \storage_rtl_0|auto_generated|ram_block1a0_PORTBDATAOUT_bus\(10);
\storage_rtl_0|auto_generated|ram_block1a11\ <= \storage_rtl_0|auto_generated|ram_block1a0_PORTBDATAOUT_bus\(11);
\storage_rtl_0|auto_generated|ram_block1a12\ <= \storage_rtl_0|auto_generated|ram_block1a0_PORTBDATAOUT_bus\(12);
\storage_rtl_0|auto_generated|ram_block1a13\ <= \storage_rtl_0|auto_generated|ram_block1a0_PORTBDATAOUT_bus\(13);
\storage_rtl_0|auto_generated|ram_block1a14\ <= \storage_rtl_0|auto_generated|ram_block1a0_PORTBDATAOUT_bus\(14);
\storage_rtl_0|auto_generated|ram_block1a15\ <= \storage_rtl_0|auto_generated|ram_block1a0_PORTBDATAOUT_bus\(15);
\storage_rtl_0|auto_generated|ram_block1a16\ <= \storage_rtl_0|auto_generated|ram_block1a0_PORTBDATAOUT_bus\(16);
\storage_rtl_0|auto_generated|ram_block1a17\ <= \storage_rtl_0|auto_generated|ram_block1a0_PORTBDATAOUT_bus\(17);
\storage_rtl_0|auto_generated|ram_block1a18\ <= \storage_rtl_0|auto_generated|ram_block1a0_PORTBDATAOUT_bus\(18);
\storage_rtl_0|auto_generated|ram_block1a19\ <= \storage_rtl_0|auto_generated|ram_block1a0_PORTBDATAOUT_bus\(19);
\storage_rtl_0|auto_generated|ram_block1a20\ <= \storage_rtl_0|auto_generated|ram_block1a0_PORTBDATAOUT_bus\(20);
\storage_rtl_0|auto_generated|ram_block1a21\ <= \storage_rtl_0|auto_generated|ram_block1a0_PORTBDATAOUT_bus\(21);
\storage_rtl_0|auto_generated|ram_block1a22\ <= \storage_rtl_0|auto_generated|ram_block1a0_PORTBDATAOUT_bus\(22);
\storage_rtl_0|auto_generated|ram_block1a23\ <= \storage_rtl_0|auto_generated|ram_block1a0_PORTBDATAOUT_bus\(23);
\storage_rtl_0|auto_generated|ram_block1a24\ <= \storage_rtl_0|auto_generated|ram_block1a0_PORTBDATAOUT_bus\(24);
\storage_rtl_0|auto_generated|ram_block1a25\ <= \storage_rtl_0|auto_generated|ram_block1a0_PORTBDATAOUT_bus\(25);
\storage_rtl_0|auto_generated|ram_block1a26\ <= \storage_rtl_0|auto_generated|ram_block1a0_PORTBDATAOUT_bus\(26);
\ALT_INV_deque_i~input_o\ <= NOT \deque_i~input_o\;
\ALT_INV_clear_i~input_o\ <= NOT \clear_i~input_o\;
\ALT_INV_enque_i~input_o\ <= NOT \enque_i~input_o\;
\ALT_INV_Equal0~0_combout\ <= NOT \Equal0~0_combout\;
\ALT_INV_Equal1~0_combout\ <= NOT \Equal1~0_combout\;
ALT_INV_wptr_r(1) <= NOT wptr_r(1);
ALT_INV_rptr_r(1) <= NOT rptr_r(1);
ALT_INV_wptr_r(0) <= NOT wptr_r(0);
ALT_INV_rptr_r(0) <= NOT rptr_r(0);
ALT_INV_storage_rtl_0_bypass(31) <= NOT storage_rtl_0_bypass(31);
ALT_INV_storage_rtl_0_bypass(30) <= NOT storage_rtl_0_bypass(30);
ALT_INV_storage_rtl_0_bypass(29) <= NOT storage_rtl_0_bypass(29);
ALT_INV_storage_rtl_0_bypass(28) <= NOT storage_rtl_0_bypass(28);
ALT_INV_storage_rtl_0_bypass(27) <= NOT storage_rtl_0_bypass(27);
ALT_INV_storage_rtl_0_bypass(26) <= NOT storage_rtl_0_bypass(26);
ALT_INV_storage_rtl_0_bypass(25) <= NOT storage_rtl_0_bypass(25);
ALT_INV_storage_rtl_0_bypass(24) <= NOT storage_rtl_0_bypass(24);
ALT_INV_storage_rtl_0_bypass(23) <= NOT storage_rtl_0_bypass(23);
ALT_INV_storage_rtl_0_bypass(22) <= NOT storage_rtl_0_bypass(22);
ALT_INV_storage_rtl_0_bypass(21) <= NOT storage_rtl_0_bypass(21);
ALT_INV_storage_rtl_0_bypass(20) <= NOT storage_rtl_0_bypass(20);
ALT_INV_storage_rtl_0_bypass(19) <= NOT storage_rtl_0_bypass(19);
ALT_INV_storage_rtl_0_bypass(18) <= NOT storage_rtl_0_bypass(18);
ALT_INV_storage_rtl_0_bypass(17) <= NOT storage_rtl_0_bypass(17);
ALT_INV_storage_rtl_0_bypass(16) <= NOT storage_rtl_0_bypass(16);
ALT_INV_storage_rtl_0_bypass(15) <= NOT storage_rtl_0_bypass(15);
ALT_INV_storage_rtl_0_bypass(14) <= NOT storage_rtl_0_bypass(14);
ALT_INV_storage_rtl_0_bypass(13) <= NOT storage_rtl_0_bypass(13);
ALT_INV_storage_rtl_0_bypass(12) <= NOT storage_rtl_0_bypass(12);
ALT_INV_storage_rtl_0_bypass(11) <= NOT storage_rtl_0_bypass(11);
ALT_INV_storage_rtl_0_bypass(10) <= NOT storage_rtl_0_bypass(10);
ALT_INV_storage_rtl_0_bypass(9) <= NOT storage_rtl_0_bypass(9);
ALT_INV_storage_rtl_0_bypass(8) <= NOT storage_rtl_0_bypass(8);
ALT_INV_storage_rtl_0_bypass(7) <= NOT storage_rtl_0_bypass(7);
ALT_INV_storage_rtl_0_bypass(6) <= NOT storage_rtl_0_bypass(6);
\ALT_INV_storage~0_combout\ <= NOT \storage~0_combout\;
ALT_INV_storage_rtl_0_bypass(4) <= NOT storage_rtl_0_bypass(4);
ALT_INV_storage_rtl_0_bypass(3) <= NOT storage_rtl_0_bypass(3);
ALT_INV_storage_rtl_0_bypass(2) <= NOT storage_rtl_0_bypass(2);
ALT_INV_storage_rtl_0_bypass(1) <= NOT storage_rtl_0_bypass(1);
ALT_INV_storage_rtl_0_bypass(0) <= NOT storage_rtl_0_bypass(0);
ALT_INV_storage_rtl_0_bypass(5) <= NOT storage_rtl_0_bypass(5);
\storage_rtl_0|auto_generated|ALT_INV_ram_block1a1\ <= NOT \storage_rtl_0|auto_generated|ram_block1a1\;
\storage_rtl_0|auto_generated|ALT_INV_ram_block1a2\ <= NOT \storage_rtl_0|auto_generated|ram_block1a2\;
\storage_rtl_0|auto_generated|ALT_INV_ram_block1a3\ <= NOT \storage_rtl_0|auto_generated|ram_block1a3\;
\storage_rtl_0|auto_generated|ALT_INV_ram_block1a4\ <= NOT \storage_rtl_0|auto_generated|ram_block1a4\;
\storage_rtl_0|auto_generated|ALT_INV_ram_block1a5\ <= NOT \storage_rtl_0|auto_generated|ram_block1a5\;
\storage_rtl_0|auto_generated|ALT_INV_ram_block1a6\ <= NOT \storage_rtl_0|auto_generated|ram_block1a6\;
\storage_rtl_0|auto_generated|ALT_INV_ram_block1a7\ <= NOT \storage_rtl_0|auto_generated|ram_block1a7\;
\storage_rtl_0|auto_generated|ALT_INV_ram_block1a8\ <= NOT \storage_rtl_0|auto_generated|ram_block1a8\;
\storage_rtl_0|auto_generated|ALT_INV_ram_block1a9\ <= NOT \storage_rtl_0|auto_generated|ram_block1a9\;
\storage_rtl_0|auto_generated|ALT_INV_ram_block1a10\ <= NOT \storage_rtl_0|auto_generated|ram_block1a10\;
\storage_rtl_0|auto_generated|ALT_INV_ram_block1a11\ <= NOT \storage_rtl_0|auto_generated|ram_block1a11\;
\storage_rtl_0|auto_generated|ALT_INV_ram_block1a12\ <= NOT \storage_rtl_0|auto_generated|ram_block1a12\;
\storage_rtl_0|auto_generated|ALT_INV_ram_block1a13\ <= NOT \storage_rtl_0|auto_generated|ram_block1a13\;
\storage_rtl_0|auto_generated|ALT_INV_ram_block1a14\ <= NOT \storage_rtl_0|auto_generated|ram_block1a14\;
\storage_rtl_0|auto_generated|ALT_INV_ram_block1a15\ <= NOT \storage_rtl_0|auto_generated|ram_block1a15\;
\storage_rtl_0|auto_generated|ALT_INV_ram_block1a16\ <= NOT \storage_rtl_0|auto_generated|ram_block1a16\;
\storage_rtl_0|auto_generated|ALT_INV_ram_block1a17\ <= NOT \storage_rtl_0|auto_generated|ram_block1a17\;
\storage_rtl_0|auto_generated|ALT_INV_ram_block1a18\ <= NOT \storage_rtl_0|auto_generated|ram_block1a18\;
\storage_rtl_0|auto_generated|ALT_INV_ram_block1a19\ <= NOT \storage_rtl_0|auto_generated|ram_block1a19\;
\storage_rtl_0|auto_generated|ALT_INV_ram_block1a20\ <= NOT \storage_rtl_0|auto_generated|ram_block1a20\;
\storage_rtl_0|auto_generated|ALT_INV_ram_block1a21\ <= NOT \storage_rtl_0|auto_generated|ram_block1a21\;
\storage_rtl_0|auto_generated|ALT_INV_ram_block1a22\ <= NOT \storage_rtl_0|auto_generated|ram_block1a22\;
\storage_rtl_0|auto_generated|ALT_INV_ram_block1a23\ <= NOT \storage_rtl_0|auto_generated|ram_block1a23\;
\storage_rtl_0|auto_generated|ALT_INV_ram_block1a24\ <= NOT \storage_rtl_0|auto_generated|ram_block1a24\;
\storage_rtl_0|auto_generated|ALT_INV_ram_block1a25\ <= NOT \storage_rtl_0|auto_generated|ram_block1a25\;
\storage_rtl_0|auto_generated|ALT_INV_ram_block1a26\ <= NOT \storage_rtl_0|auto_generated|ram_block1a26\;
\storage_rtl_0|auto_generated|ALT_INV_ram_block1a0~portbdataout\ <= NOT \storage_rtl_0|auto_generated|ram_block1a0~portbdataout\;

-- Location: IOOBUF_X34_Y0_N59
\d_o[0]~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \storage~1_combout\,
	devoe => ww_devoe,
	o => ww_d_o(0));

-- Location: IOOBUF_X62_Y0_N2
\d_o[1]~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \storage~2_combout\,
	devoe => ww_devoe,
	o => ww_d_o(1));

-- Location: IOOBUF_X40_Y0_N19
\d_o[2]~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \storage~3_combout\,
	devoe => ww_devoe,
	o => ww_d_o(2));

-- Location: IOOBUF_X38_Y0_N53
\d_o[3]~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \storage~4_combout\,
	devoe => ww_devoe,
	o => ww_d_o(3));

-- Location: IOOBUF_X70_Y0_N19
\d_o[4]~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \storage~5_combout\,
	devoe => ww_devoe,
	o => ww_d_o(4));

-- Location: IOOBUF_X64_Y0_N36
\d_o[5]~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \storage~6_combout\,
	devoe => ww_devoe,
	o => ww_d_o(5));

-- Location: IOOBUF_X40_Y0_N53
\d_o[6]~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \storage~7_combout\,
	devoe => ww_devoe,
	o => ww_d_o(6));

-- Location: IOOBUF_X52_Y0_N19
\d_o[7]~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \storage~8_combout\,
	devoe => ww_devoe,
	o => ww_d_o(7));

-- Location: IOOBUF_X64_Y0_N19
\d_o[8]~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \storage~9_combout\,
	devoe => ww_devoe,
	o => ww_d_o(8));

-- Location: IOOBUF_X72_Y0_N36
\d_o[9]~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \storage~10_combout\,
	devoe => ww_devoe,
	o => ww_d_o(9));

-- Location: IOOBUF_X70_Y0_N2
\d_o[10]~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \storage~11_combout\,
	devoe => ww_devoe,
	o => ww_d_o(10));

-- Location: IOOBUF_X54_Y0_N19
\d_o[11]~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \storage~12_combout\,
	devoe => ww_devoe,
	o => ww_d_o(11));

-- Location: IOOBUF_X64_Y0_N2
\d_o[12]~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \storage~13_combout\,
	devoe => ww_devoe,
	o => ww_d_o(12));

-- Location: IOOBUF_X38_Y0_N19
\d_o[13]~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \storage~14_combout\,
	devoe => ww_devoe,
	o => ww_d_o(13));

-- Location: IOOBUF_X40_Y0_N2
\d_o[14]~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \storage~15_combout\,
	devoe => ww_devoe,
	o => ww_d_o(14));

-- Location: IOOBUF_X70_Y0_N36
\d_o[15]~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \storage~16_combout\,
	devoe => ww_devoe,
	o => ww_d_o(15));

-- Location: IOOBUF_X68_Y0_N36
\d_o[16]~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \storage~17_combout\,
	devoe => ww_devoe,
	o => ww_d_o(16));

-- Location: IOOBUF_X38_Y0_N2
\d_o[17]~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \storage~18_combout\,
	devoe => ww_devoe,
	o => ww_d_o(17));

-- Location: IOOBUF_X40_Y0_N36
\d_o[18]~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \storage~19_combout\,
	devoe => ww_devoe,
	o => ww_d_o(18));

-- Location: IOOBUF_X62_Y0_N36
\d_o[19]~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \storage~20_combout\,
	devoe => ww_devoe,
	o => ww_d_o(19));

-- Location: IOOBUF_X62_Y0_N53
\d_o[20]~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \storage~21_combout\,
	devoe => ww_devoe,
	o => ww_d_o(20));

-- Location: IOOBUF_X54_Y0_N53
\d_o[21]~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \storage~22_combout\,
	devoe => ww_devoe,
	o => ww_d_o(21));

-- Location: IOOBUF_X70_Y0_N53
\d_o[22]~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \storage~23_combout\,
	devoe => ww_devoe,
	o => ww_d_o(22));

-- Location: IOOBUF_X68_Y0_N53
\d_o[23]~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \storage~24_combout\,
	devoe => ww_devoe,
	o => ww_d_o(23));

-- Location: IOOBUF_X68_Y0_N19
\d_o[24]~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \storage~25_combout\,
	devoe => ww_devoe,
	o => ww_d_o(24));

-- Location: IOOBUF_X54_Y0_N36
\d_o[25]~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \storage~26_combout\,
	devoe => ww_devoe,
	o => ww_d_o(25));

-- Location: IOOBUF_X68_Y0_N2
\d_o[26]~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \storage~27_combout\,
	devoe => ww_devoe,
	o => ww_d_o(26));

-- Location: IOOBUF_X32_Y0_N53
\empty_o~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \ALT_INV_Equal1~0_combout\,
	devoe => ww_devoe,
	o => ww_empty_o);

-- Location: IOOBUF_X38_Y0_N36
\full_o~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \ALT_INV_Equal0~0_combout\,
	devoe => ww_devoe,
	o => ww_full_o);

-- Location: IOOBUF_X32_Y0_N36
\valid_o~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \Equal1~0_combout\,
	devoe => ww_devoe,
	o => ww_valid_o);

-- Location: IOIBUF_X54_Y0_N1
\enque_i~input\ : cyclonev_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_enque_i,
	o => \enque_i~input_o\);

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

-- Location: IOIBUF_X52_Y0_N35
\d_i[0]~input\ : cyclonev_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_d_i(0),
	o => \d_i[0]~input_o\);

-- Location: IOIBUF_X36_Y0_N1
\clear_i~input\ : cyclonev_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_clear_i,
	o => \clear_i~input_o\);

-- Location: LABCELL_X57_Y4_N21
\wptr_r_a[0]~0\ : cyclonev_lcell_comb
-- Equation(s):
-- \wptr_r_a[0]~0_combout\ = ( wptr_r(0) & ( !\clear_i~input_o\ & ( !\enque_i~input_o\ ) ) ) # ( !wptr_r(0) & ( !\clear_i~input_o\ & ( \enque_i~input_o\ ) ) )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0000111100001111111100001111000000000000000000000000000000000000",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	datac => \ALT_INV_enque_i~input_o\,
	datae => ALT_INV_wptr_r(0),
	dataf => \ALT_INV_clear_i~input_o\,
	combout => \wptr_r_a[0]~0_combout\);

-- Location: FF_X57_Y4_N23
\wptr_r[0]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~inputCLKENA0_outclk\,
	d => \wptr_r_a[0]~0_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => wptr_r(0));

-- Location: LABCELL_X57_Y4_N54
\wptr_r_a[1]~1\ : cyclonev_lcell_comb
-- Equation(s):
-- \wptr_r_a[1]~1_combout\ = ( \enque_i~input_o\ & ( (!\clear_i~input_o\ & (!wptr_r(0) $ (!wptr_r(1)))) ) ) # ( !\enque_i~input_o\ & ( (!\clear_i~input_o\ & wptr_r(1)) ) )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0000000011001100000000001100110000001100110000000000110011000000",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	datab => \ALT_INV_clear_i~input_o\,
	datac => ALT_INV_wptr_r(0),
	datad => ALT_INV_wptr_r(1),
	dataf => \ALT_INV_enque_i~input_o\,
	combout => \wptr_r_a[1]~1_combout\);

-- Location: FF_X57_Y4_N56
\wptr_r[1]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~inputCLKENA0_outclk\,
	d => \wptr_r_a[1]~1_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => wptr_r(1));

-- Location: IOIBUF_X36_Y0_N35
\deque_i~input\ : cyclonev_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_deque_i,
	o => \deque_i~input_o\);

-- Location: FF_X57_Y4_N14
\rptr_r[0]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~inputCLKENA0_outclk\,
	asdata => \rptr_r_a[0]~0_combout\,
	sload => VCC,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => rptr_r(0));

-- Location: LABCELL_X57_Y4_N27
\rptr_r_a[0]~0\ : cyclonev_lcell_comb
-- Equation(s):
-- \rptr_r_a[0]~0_combout\ = ( rptr_r(0) & ( (!\deque_i~input_o\ & !\clear_i~input_o\) ) ) # ( !rptr_r(0) & ( (\deque_i~input_o\ & !\clear_i~input_o\) ) )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0101000001010000010100000101000010100000101000001010000010100000",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	dataa => \ALT_INV_deque_i~input_o\,
	datac => \ALT_INV_clear_i~input_o\,
	dataf => ALT_INV_rptr_r(0),
	combout => \rptr_r_a[0]~0_combout\);

-- Location: FF_X57_Y4_N35
\rptr_r[1]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~inputCLKENA0_outclk\,
	asdata => \rptr_r_a[1]~1_combout\,
	sload => VCC,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => rptr_r(1));

-- Location: LABCELL_X57_Y4_N39
\rptr_r_a[1]~1\ : cyclonev_lcell_comb
-- Equation(s):
-- \rptr_r_a[1]~1_combout\ = ( rptr_r(1) & ( (!\clear_i~input_o\ & ((!\deque_i~input_o\) # (!rptr_r(0)))) ) ) # ( !rptr_r(1) & ( (\deque_i~input_o\ & (!\clear_i~input_o\ & rptr_r(0))) ) )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0000010000000100000001000000010011001000110010001100100011001000",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	dataa => \ALT_INV_deque_i~input_o\,
	datab => \ALT_INV_clear_i~input_o\,
	datac => ALT_INV_rptr_r(0),
	dataf => ALT_INV_rptr_r(1),
	combout => \rptr_r_a[1]~1_combout\);

-- Location: IOIBUF_X58_Y0_N41
\d_i[1]~input\ : cyclonev_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_d_i(1),
	o => \d_i[1]~input_o\);

-- Location: IOIBUF_X52_Y0_N1
\d_i[2]~input\ : cyclonev_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_d_i(2),
	o => \d_i[2]~input_o\);

-- Location: IOIBUF_X36_Y0_N52
\d_i[3]~input\ : cyclonev_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_d_i(3),
	o => \d_i[3]~input_o\);

-- Location: IOIBUF_X60_Y0_N52
\d_i[4]~input\ : cyclonev_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_d_i(4),
	o => \d_i[4]~input_o\);

-- Location: IOIBUF_X56_Y0_N18
\d_i[5]~input\ : cyclonev_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_d_i(5),
	o => \d_i[5]~input_o\);

-- Location: IOIBUF_X52_Y0_N52
\d_i[6]~input\ : cyclonev_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_d_i(6),
	o => \d_i[6]~input_o\);

-- Location: IOIBUF_X36_Y0_N18
\d_i[7]~input\ : cyclonev_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_d_i(7),
	o => \d_i[7]~input_o\);

-- Location: IOIBUF_X62_Y0_N18
\d_i[8]~input\ : cyclonev_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_d_i(8),
	o => \d_i[8]~input_o\);

-- Location: IOIBUF_X58_Y0_N92
\d_i[9]~input\ : cyclonev_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_d_i(9),
	o => \d_i[9]~input_o\);

-- Location: IOIBUF_X58_Y0_N58
\d_i[10]~input\ : cyclonev_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_d_i(10),
	o => \d_i[10]~input_o\);

-- Location: IOIBUF_X60_Y0_N35
\d_i[11]~input\ : cyclonev_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_d_i(11),
	o => \d_i[11]~input_o\);

-- Location: IOIBUF_X56_Y0_N35
\d_i[12]~input\ : cyclonev_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_d_i(12),
	o => \d_i[12]~input_o\);

-- Location: IOIBUF_X50_Y0_N92
\d_i[13]~input\ : cyclonev_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_d_i(13),
	o => \d_i[13]~input_o\);

-- Location: IOIBUF_X50_Y0_N41
\d_i[14]~input\ : cyclonev_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_d_i(14),
	o => \d_i[14]~input_o\);

-- Location: IOIBUF_X58_Y0_N75
\d_i[15]~input\ : cyclonev_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_d_i(15),
	o => \d_i[15]~input_o\);

-- Location: IOIBUF_X60_Y0_N18
\d_i[16]~input\ : cyclonev_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_d_i(16),
	o => \d_i[16]~input_o\);

-- Location: IOIBUF_X50_Y0_N75
\d_i[17]~input\ : cyclonev_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_d_i(17),
	o => \d_i[17]~input_o\);

-- Location: IOIBUF_X50_Y0_N58
\d_i[18]~input\ : cyclonev_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_d_i(18),
	o => \d_i[18]~input_o\);

-- Location: IOIBUF_X66_Y0_N58
\d_i[19]~input\ : cyclonev_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_d_i(19),
	o => \d_i[19]~input_o\);

-- Location: IOIBUF_X64_Y0_N52
\d_i[20]~input\ : cyclonev_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_d_i(20),
	o => \d_i[20]~input_o\);

-- Location: IOIBUF_X66_Y0_N75
\d_i[21]~input\ : cyclonev_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_d_i(21),
	o => \d_i[21]~input_o\);

-- Location: IOIBUF_X60_Y0_N1
\d_i[22]~input\ : cyclonev_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_d_i(22),
	o => \d_i[22]~input_o\);

-- Location: IOIBUF_X56_Y0_N1
\d_i[23]~input\ : cyclonev_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_d_i(23),
	o => \d_i[23]~input_o\);

-- Location: IOIBUF_X66_Y0_N92
\d_i[24]~input\ : cyclonev_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_d_i(24),
	o => \d_i[24]~input_o\);

-- Location: IOIBUF_X66_Y0_N41
\d_i[25]~input\ : cyclonev_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_d_i(25),
	o => \d_i[25]~input_o\);

-- Location: IOIBUF_X56_Y0_N52
\d_i[26]~input\ : cyclonev_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_d_i(26),
	o => \d_i[26]~input_o\);

-- Location: M10K_X58_Y4_N0
\storage_rtl_0|auto_generated|ram_block1a0\ : cyclonev_ram_block
-- pragma translate_off
GENERIC MAP (
	data_interleave_offset_in_bits => 1,
	data_interleave_width_in_bits => 1,
	logical_ram_name => "altsyncram:storage_rtl_0|altsyncram_6gi1:auto_generated|ALTSYNCRAM",
	mixed_port_feed_through_mode => "dont_care",
	operation_mode => "dual_port",
	port_a_address_clear => "none",
	port_a_address_width => 2,
	port_a_byte_enable_clock => "none",
	port_a_data_out_clear => "none",
	port_a_data_out_clock => "none",
	port_a_data_width => 40,
	port_a_first_address => 0,
	port_a_first_bit_number => 0,
	port_a_last_address => 3,
	port_a_logical_ram_depth => 4,
	port_a_logical_ram_width => 27,
	port_a_read_during_write_mode => "new_data_no_nbe_read",
	port_b_address_clear => "none",
	port_b_address_clock => "clock0",
	port_b_address_width => 2,
	port_b_data_out_clear => "none",
	port_b_data_out_clock => "none",
	port_b_data_width => 40,
	port_b_first_address => 0,
	port_b_first_bit_number => 0,
	port_b_last_address => 3,
	port_b_logical_ram_depth => 4,
	port_b_logical_ram_width => 27,
	port_b_read_during_write_mode => "new_data_no_nbe_read",
	port_b_read_enable_clock => "clock0",
	ram_block_type => "M20K")
-- pragma translate_on
PORT MAP (
	portawe => \enque_i~input_o\,
	portbre => VCC,
	clk0 => \clk~inputCLKENA0_outclk\,
	portadatain => \storage_rtl_0|auto_generated|ram_block1a0_PORTADATAIN_bus\,
	portaaddr => \storage_rtl_0|auto_generated|ram_block1a0_PORTAADDR_bus\,
	portbaddr => \storage_rtl_0|auto_generated|ram_block1a0_PORTBADDR_bus\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	portbdataout => \storage_rtl_0|auto_generated|ram_block1a0_PORTBDATAOUT_bus\);

-- Location: FF_X57_Y4_N17
\storage_rtl_0_bypass[5]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~inputCLKENA0_outclk\,
	asdata => \d_i[0]~input_o\,
	sload => VCC,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => storage_rtl_0_bypass(5));

-- Location: FF_X57_Y4_N40
\storage_rtl_0_bypass[2]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~inputCLKENA0_outclk\,
	asdata => \rptr_r_a[0]~0_combout\,
	sload => VCC,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => storage_rtl_0_bypass(2));

-- Location: FF_X57_Y4_N19
\storage_rtl_0_bypass[1]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~inputCLKENA0_outclk\,
	asdata => wptr_r(0),
	sload => VCC,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => storage_rtl_0_bypass(1));

-- Location: FF_X57_Y4_N29
\storage_rtl_0_bypass[0]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~inputCLKENA0_outclk\,
	asdata => \enque_i~input_o\,
	sload => VCC,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => storage_rtl_0_bypass(0));

-- Location: FF_X57_Y4_N25
\storage_rtl_0_bypass[3]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~inputCLKENA0_outclk\,
	asdata => wptr_r(1),
	sload => VCC,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => storage_rtl_0_bypass(3));

-- Location: FF_X57_Y4_N32
\storage_rtl_0_bypass[4]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~inputCLKENA0_outclk\,
	asdata => \rptr_r_a[1]~1_combout\,
	sload => VCC,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => storage_rtl_0_bypass(4));

-- Location: LABCELL_X57_Y4_N30
\storage~0\ : cyclonev_lcell_comb
-- Equation(s):
-- \storage~0_combout\ = ( storage_rtl_0_bypass(4) & ( (storage_rtl_0_bypass(0) & (storage_rtl_0_bypass(3) & (!storage_rtl_0_bypass(2) $ (storage_rtl_0_bypass(1))))) ) ) # ( !storage_rtl_0_bypass(4) & ( (storage_rtl_0_bypass(0) & (!storage_rtl_0_bypass(3) & 
-- (!storage_rtl_0_bypass(2) $ (storage_rtl_0_bypass(1))))) ) )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0000100100000000000000000000100100001001000000000000000000001001",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	dataa => ALT_INV_storage_rtl_0_bypass(2),
	datab => ALT_INV_storage_rtl_0_bypass(1),
	datac => ALT_INV_storage_rtl_0_bypass(0),
	datad => ALT_INV_storage_rtl_0_bypass(3),
	datae => ALT_INV_storage_rtl_0_bypass(4),
	combout => \storage~0_combout\);

-- Location: LABCELL_X57_Y4_N15
\storage~1\ : cyclonev_lcell_comb
-- Equation(s):
-- \storage~1_combout\ = ( storage_rtl_0_bypass(5) & ( \storage~0_combout\ ) ) # ( storage_rtl_0_bypass(5) & ( !\storage~0_combout\ & ( \storage_rtl_0|auto_generated|ram_block1a0~portbdataout\ ) ) ) # ( !storage_rtl_0_bypass(5) & ( !\storage~0_combout\ & ( 
-- \storage_rtl_0|auto_generated|ram_block1a0~portbdataout\ ) ) )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0101010101010101010101010101010100000000000000001111111111111111",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	dataa => \storage_rtl_0|auto_generated|ALT_INV_ram_block1a0~portbdataout\,
	datae => ALT_INV_storage_rtl_0_bypass(5),
	dataf => \ALT_INV_storage~0_combout\,
	combout => \storage~1_combout\);

-- Location: FF_X59_Y4_N5
\storage_rtl_0_bypass[6]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~inputCLKENA0_outclk\,
	asdata => \d_i[1]~input_o\,
	sload => VCC,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => storage_rtl_0_bypass(6));

-- Location: MLABCELL_X59_Y4_N3
\storage~2\ : cyclonev_lcell_comb
-- Equation(s):
-- \storage~2_combout\ = (!\storage~0_combout\ & (\storage_rtl_0|auto_generated|ram_block1a1\)) # (\storage~0_combout\ & ((storage_rtl_0_bypass(6))))

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0000101001011111000010100101111100001010010111110000101001011111",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	dataa => \ALT_INV_storage~0_combout\,
	datac => \storage_rtl_0|auto_generated|ALT_INV_ram_block1a1\,
	datad => ALT_INV_storage_rtl_0_bypass(6),
	combout => \storage~2_combout\);

-- Location: FF_X57_Y4_N59
\storage_rtl_0_bypass[7]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~inputCLKENA0_outclk\,
	asdata => \d_i[2]~input_o\,
	sload => VCC,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => storage_rtl_0_bypass(7));

-- Location: LABCELL_X57_Y4_N57
\storage~3\ : cyclonev_lcell_comb
-- Equation(s):
-- \storage~3_combout\ = ( \storage~0_combout\ & ( storage_rtl_0_bypass(7) ) ) # ( !\storage~0_combout\ & ( \storage_rtl_0|auto_generated|ram_block1a2\ ) )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0101010101010101010101010101010100000000111111110000000011111111",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	dataa => \storage_rtl_0|auto_generated|ALT_INV_ram_block1a2\,
	datad => ALT_INV_storage_rtl_0_bypass(7),
	dataf => \ALT_INV_storage~0_combout\,
	combout => \storage~3_combout\);

-- Location: FF_X57_Y4_N8
\storage_rtl_0_bypass[8]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~inputCLKENA0_outclk\,
	asdata => \d_i[3]~input_o\,
	sload => VCC,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => storage_rtl_0_bypass(8));

-- Location: LABCELL_X57_Y4_N6
\storage~4\ : cyclonev_lcell_comb
-- Equation(s):
-- \storage~4_combout\ = ( \storage_rtl_0|auto_generated|ram_block1a3\ & ( (!\storage~0_combout\) # (storage_rtl_0_bypass(8)) ) ) # ( !\storage_rtl_0|auto_generated|ram_block1a3\ & ( (\storage~0_combout\ & storage_rtl_0_bypass(8)) ) )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0000000001010101000000000101010110101010111111111010101011111111",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	dataa => \ALT_INV_storage~0_combout\,
	datad => ALT_INV_storage_rtl_0_bypass(8),
	dataf => \storage_rtl_0|auto_generated|ALT_INV_ram_block1a3\,
	combout => \storage~4_combout\);

-- Location: FF_X59_Y4_N59
\storage_rtl_0_bypass[9]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~inputCLKENA0_outclk\,
	asdata => \d_i[4]~input_o\,
	sload => VCC,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => storage_rtl_0_bypass(9));

-- Location: MLABCELL_X59_Y4_N57
\storage~5\ : cyclonev_lcell_comb
-- Equation(s):
-- \storage~5_combout\ = ( \storage_rtl_0|auto_generated|ram_block1a4\ & ( (!\storage~0_combout\) # (storage_rtl_0_bypass(9)) ) ) # ( !\storage_rtl_0|auto_generated|ram_block1a4\ & ( (\storage~0_combout\ & storage_rtl_0_bypass(9)) ) )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0000000001010101000000000101010110101010111111111010101011111111",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	dataa => \ALT_INV_storage~0_combout\,
	datad => ALT_INV_storage_rtl_0_bypass(9),
	dataf => \storage_rtl_0|auto_generated|ALT_INV_ram_block1a4\,
	combout => \storage~5_combout\);

-- Location: FF_X59_Y4_N29
\storage_rtl_0_bypass[10]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~inputCLKENA0_outclk\,
	asdata => \d_i[5]~input_o\,
	sload => VCC,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => storage_rtl_0_bypass(10));

-- Location: MLABCELL_X59_Y4_N27
\storage~6\ : cyclonev_lcell_comb
-- Equation(s):
-- \storage~6_combout\ = ( storage_rtl_0_bypass(10) & ( \storage_rtl_0|auto_generated|ram_block1a5\ ) ) # ( !storage_rtl_0_bypass(10) & ( \storage_rtl_0|auto_generated|ram_block1a5\ & ( !\storage~0_combout\ ) ) ) # ( storage_rtl_0_bypass(10) & ( 
-- !\storage_rtl_0|auto_generated|ram_block1a5\ & ( \storage~0_combout\ ) ) )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0000000000000000010101010101010110101010101010101111111111111111",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	dataa => \ALT_INV_storage~0_combout\,
	datae => ALT_INV_storage_rtl_0_bypass(10),
	dataf => \storage_rtl_0|auto_generated|ALT_INV_ram_block1a5\,
	combout => \storage~6_combout\);

-- Location: FF_X57_Y4_N38
\storage_rtl_0_bypass[11]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~inputCLKENA0_outclk\,
	asdata => \d_i[6]~input_o\,
	sload => VCC,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => storage_rtl_0_bypass(11));

-- Location: LABCELL_X57_Y4_N36
\storage~7\ : cyclonev_lcell_comb
-- Equation(s):
-- \storage~7_combout\ = ( \storage_rtl_0|auto_generated|ram_block1a6\ & ( (!\storage~0_combout\) # (storage_rtl_0_bypass(11)) ) ) # ( !\storage_rtl_0|auto_generated|ram_block1a6\ & ( (\storage~0_combout\ & storage_rtl_0_bypass(11)) ) )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0000000000001111000000000000111111110000111111111111000011111111",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	datac => \ALT_INV_storage~0_combout\,
	datad => ALT_INV_storage_rtl_0_bypass(11),
	dataf => \storage_rtl_0|auto_generated|ALT_INV_ram_block1a6\,
	combout => \storage~7_combout\);

-- Location: FF_X57_Y4_N11
\storage_rtl_0_bypass[12]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~inputCLKENA0_outclk\,
	asdata => \d_i[7]~input_o\,
	sload => VCC,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => storage_rtl_0_bypass(12));

-- Location: LABCELL_X57_Y4_N9
\storage~8\ : cyclonev_lcell_comb
-- Equation(s):
-- \storage~8_combout\ = ( \storage_rtl_0|auto_generated|ram_block1a7\ & ( (!\storage~0_combout\) # (storage_rtl_0_bypass(12)) ) ) # ( !\storage_rtl_0|auto_generated|ram_block1a7\ & ( (\storage~0_combout\ & storage_rtl_0_bypass(12)) ) )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0000000001010101000000000101010110101010111111111010101011111111",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	dataa => \ALT_INV_storage~0_combout\,
	datad => ALT_INV_storage_rtl_0_bypass(12),
	dataf => \storage_rtl_0|auto_generated|ALT_INV_ram_block1a7\,
	combout => \storage~8_combout\);

-- Location: FF_X59_Y4_N35
\storage_rtl_0_bypass[13]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~inputCLKENA0_outclk\,
	asdata => \d_i[8]~input_o\,
	sload => VCC,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => storage_rtl_0_bypass(13));

-- Location: MLABCELL_X59_Y4_N33
\storage~9\ : cyclonev_lcell_comb
-- Equation(s):
-- \storage~9_combout\ = ( \storage_rtl_0|auto_generated|ram_block1a8\ & ( (!\storage~0_combout\) # (storage_rtl_0_bypass(13)) ) ) # ( !\storage_rtl_0|auto_generated|ram_block1a8\ & ( (\storage~0_combout\ & storage_rtl_0_bypass(13)) ) )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0000000001010101000000000101010110101010111111111010101011111111",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	dataa => \ALT_INV_storage~0_combout\,
	datad => ALT_INV_storage_rtl_0_bypass(13),
	dataf => \storage_rtl_0|auto_generated|ALT_INV_ram_block1a8\,
	combout => \storage~9_combout\);

-- Location: FF_X59_Y4_N41
\storage_rtl_0_bypass[14]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~inputCLKENA0_outclk\,
	asdata => \d_i[9]~input_o\,
	sload => VCC,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => storage_rtl_0_bypass(14));

-- Location: MLABCELL_X59_Y4_N39
\storage~10\ : cyclonev_lcell_comb
-- Equation(s):
-- \storage~10_combout\ = (!\storage~0_combout\ & (\storage_rtl_0|auto_generated|ram_block1a9\)) # (\storage~0_combout\ & ((storage_rtl_0_bypass(14))))

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0000101001011111000010100101111100001010010111110000101001011111",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	dataa => \ALT_INV_storage~0_combout\,
	datac => \storage_rtl_0|auto_generated|ALT_INV_ram_block1a9\,
	datad => ALT_INV_storage_rtl_0_bypass(14),
	combout => \storage~10_combout\);

-- Location: FF_X59_Y4_N44
\storage_rtl_0_bypass[15]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~inputCLKENA0_outclk\,
	asdata => \d_i[10]~input_o\,
	sload => VCC,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => storage_rtl_0_bypass(15));

-- Location: MLABCELL_X59_Y4_N42
\storage~11\ : cyclonev_lcell_comb
-- Equation(s):
-- \storage~11_combout\ = ( \storage_rtl_0|auto_generated|ram_block1a10\ & ( (!\storage~0_combout\) # (storage_rtl_0_bypass(15)) ) ) # ( !\storage_rtl_0|auto_generated|ram_block1a10\ & ( (\storage~0_combout\ & storage_rtl_0_bypass(15)) ) )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0000000001010101000000000101010110101010111111111010101011111111",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	dataa => \ALT_INV_storage~0_combout\,
	datad => ALT_INV_storage_rtl_0_bypass(15),
	dataf => \storage_rtl_0|auto_generated|ALT_INV_ram_block1a10\,
	combout => \storage~11_combout\);

-- Location: FF_X59_Y4_N17
\storage_rtl_0_bypass[16]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~inputCLKENA0_outclk\,
	asdata => \d_i[11]~input_o\,
	sload => VCC,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => storage_rtl_0_bypass(16));

-- Location: MLABCELL_X59_Y4_N15
\storage~12\ : cyclonev_lcell_comb
-- Equation(s):
-- \storage~12_combout\ = ( \storage_rtl_0|auto_generated|ram_block1a11\ & ( (!\storage~0_combout\) # (storage_rtl_0_bypass(16)) ) ) # ( !\storage_rtl_0|auto_generated|ram_block1a11\ & ( (\storage~0_combout\ & storage_rtl_0_bypass(16)) ) )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0000000001010101000000000101010110101010111111111010101011111111",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	dataa => \ALT_INV_storage~0_combout\,
	datad => ALT_INV_storage_rtl_0_bypass(16),
	dataf => \storage_rtl_0|auto_generated|ALT_INV_ram_block1a11\,
	combout => \storage~12_combout\);

-- Location: FF_X59_Y4_N32
\storage_rtl_0_bypass[17]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~inputCLKENA0_outclk\,
	asdata => \d_i[12]~input_o\,
	sload => VCC,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => storage_rtl_0_bypass(17));

-- Location: MLABCELL_X59_Y4_N30
\storage~13\ : cyclonev_lcell_comb
-- Equation(s):
-- \storage~13_combout\ = ( \storage_rtl_0|auto_generated|ram_block1a12\ & ( (!\storage~0_combout\) # (storage_rtl_0_bypass(17)) ) ) # ( !\storage_rtl_0|auto_generated|ram_block1a12\ & ( (\storage~0_combout\ & storage_rtl_0_bypass(17)) ) )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0000000001010101000000000101010110101010111111111010101011111111",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	dataa => \ALT_INV_storage~0_combout\,
	datad => ALT_INV_storage_rtl_0_bypass(17),
	dataf => \storage_rtl_0|auto_generated|ALT_INV_ram_block1a12\,
	combout => \storage~13_combout\);

-- Location: FF_X57_Y4_N44
\storage_rtl_0_bypass[18]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~inputCLKENA0_outclk\,
	asdata => \d_i[13]~input_o\,
	sload => VCC,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => storage_rtl_0_bypass(18));

-- Location: LABCELL_X57_Y4_N42
\storage~14\ : cyclonev_lcell_comb
-- Equation(s):
-- \storage~14_combout\ = ( \storage_rtl_0|auto_generated|ram_block1a13\ & ( (!\storage~0_combout\) # (storage_rtl_0_bypass(18)) ) ) # ( !\storage_rtl_0|auto_generated|ram_block1a13\ & ( (\storage~0_combout\ & storage_rtl_0_bypass(18)) ) )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0000000001010101000000000101010110101010111111111010101011111111",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	dataa => \ALT_INV_storage~0_combout\,
	datad => ALT_INV_storage_rtl_0_bypass(18),
	dataf => \storage_rtl_0|auto_generated|ALT_INV_ram_block1a13\,
	combout => \storage~14_combout\);

-- Location: FF_X57_Y4_N47
\storage_rtl_0_bypass[19]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~inputCLKENA0_outclk\,
	asdata => \d_i[14]~input_o\,
	sload => VCC,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => storage_rtl_0_bypass(19));

-- Location: LABCELL_X57_Y4_N45
\storage~15\ : cyclonev_lcell_comb
-- Equation(s):
-- \storage~15_combout\ = (!\storage~0_combout\ & (\storage_rtl_0|auto_generated|ram_block1a14\)) # (\storage~0_combout\ & ((storage_rtl_0_bypass(19))))

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0000101001011111000010100101111100001010010111110000101001011111",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	dataa => \ALT_INV_storage~0_combout\,
	datac => \storage_rtl_0|auto_generated|ALT_INV_ram_block1a14\,
	datad => ALT_INV_storage_rtl_0_bypass(19),
	combout => \storage~15_combout\);

-- Location: FF_X59_Y4_N20
\storage_rtl_0_bypass[20]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~inputCLKENA0_outclk\,
	asdata => \d_i[15]~input_o\,
	sload => VCC,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => storage_rtl_0_bypass(20));

-- Location: MLABCELL_X59_Y4_N18
\storage~16\ : cyclonev_lcell_comb
-- Equation(s):
-- \storage~16_combout\ = ( \storage_rtl_0|auto_generated|ram_block1a15\ & ( (!\storage~0_combout\) # (storage_rtl_0_bypass(20)) ) ) # ( !\storage_rtl_0|auto_generated|ram_block1a15\ & ( (\storage~0_combout\ & storage_rtl_0_bypass(20)) ) )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0000000001010101000000000101010110101010111111111010101011111111",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	dataa => \ALT_INV_storage~0_combout\,
	datad => ALT_INV_storage_rtl_0_bypass(20),
	dataf => \storage_rtl_0|auto_generated|ALT_INV_ram_block1a15\,
	combout => \storage~16_combout\);

-- Location: FF_X59_Y4_N50
\storage_rtl_0_bypass[21]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~inputCLKENA0_outclk\,
	asdata => \d_i[16]~input_o\,
	sload => VCC,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => storage_rtl_0_bypass(21));

-- Location: MLABCELL_X59_Y4_N48
\storage~17\ : cyclonev_lcell_comb
-- Equation(s):
-- \storage~17_combout\ = ( \storage_rtl_0|auto_generated|ram_block1a16\ & ( (!\storage~0_combout\) # (storage_rtl_0_bypass(21)) ) ) # ( !\storage_rtl_0|auto_generated|ram_block1a16\ & ( (\storage~0_combout\ & storage_rtl_0_bypass(21)) ) )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0000000001010101000000000101010110101010111111111010101011111111",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	dataa => \ALT_INV_storage~0_combout\,
	datad => ALT_INV_storage_rtl_0_bypass(21),
	dataf => \storage_rtl_0|auto_generated|ALT_INV_ram_block1a16\,
	combout => \storage~17_combout\);

-- Location: FF_X57_Y4_N50
\storage_rtl_0_bypass[22]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~inputCLKENA0_outclk\,
	asdata => \d_i[17]~input_o\,
	sload => VCC,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => storage_rtl_0_bypass(22));

-- Location: LABCELL_X57_Y4_N48
\storage~18\ : cyclonev_lcell_comb
-- Equation(s):
-- \storage~18_combout\ = (!\storage~0_combout\ & (\storage_rtl_0|auto_generated|ram_block1a17\)) # (\storage~0_combout\ & ((storage_rtl_0_bypass(22))))

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0000101001011111000010100101111100001010010111110000101001011111",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	dataa => \ALT_INV_storage~0_combout\,
	datac => \storage_rtl_0|auto_generated|ALT_INV_ram_block1a17\,
	datad => ALT_INV_storage_rtl_0_bypass(22),
	combout => \storage~18_combout\);

-- Location: FF_X57_Y4_N53
\storage_rtl_0_bypass[23]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~inputCLKENA0_outclk\,
	asdata => \d_i[18]~input_o\,
	sload => VCC,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => storage_rtl_0_bypass(23));

-- Location: LABCELL_X57_Y4_N51
\storage~19\ : cyclonev_lcell_comb
-- Equation(s):
-- \storage~19_combout\ = (!\storage~0_combout\ & (\storage_rtl_0|auto_generated|ram_block1a18\)) # (\storage~0_combout\ & ((storage_rtl_0_bypass(23))))

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0000101001011111000010100101111100001010010111110000101001011111",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	dataa => \ALT_INV_storage~0_combout\,
	datac => \storage_rtl_0|auto_generated|ALT_INV_ram_block1a18\,
	datad => ALT_INV_storage_rtl_0_bypass(23),
	combout => \storage~19_combout\);

-- Location: FF_X59_Y4_N8
\storage_rtl_0_bypass[24]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~inputCLKENA0_outclk\,
	asdata => \d_i[19]~input_o\,
	sload => VCC,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => storage_rtl_0_bypass(24));

-- Location: MLABCELL_X59_Y4_N6
\storage~20\ : cyclonev_lcell_comb
-- Equation(s):
-- \storage~20_combout\ = ( storage_rtl_0_bypass(24) & ( \storage_rtl_0|auto_generated|ram_block1a19\ ) ) # ( !storage_rtl_0_bypass(24) & ( \storage_rtl_0|auto_generated|ram_block1a19\ & ( !\storage~0_combout\ ) ) ) # ( storage_rtl_0_bypass(24) & ( 
-- !\storage_rtl_0|auto_generated|ram_block1a19\ & ( \storage~0_combout\ ) ) )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0000000000000000000011110000111111110000111100001111111111111111",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	datac => \ALT_INV_storage~0_combout\,
	datae => ALT_INV_storage_rtl_0_bypass(24),
	dataf => \storage_rtl_0|auto_generated|ALT_INV_ram_block1a19\,
	combout => \storage~20_combout\);

-- Location: FF_X59_Y4_N56
\storage_rtl_0_bypass[25]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~inputCLKENA0_outclk\,
	asdata => \d_i[20]~input_o\,
	sload => VCC,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => storage_rtl_0_bypass(25));

-- Location: MLABCELL_X59_Y4_N54
\storage~21\ : cyclonev_lcell_comb
-- Equation(s):
-- \storage~21_combout\ = ( \storage_rtl_0|auto_generated|ram_block1a20\ & ( (!\storage~0_combout\) # (storage_rtl_0_bypass(25)) ) ) # ( !\storage_rtl_0|auto_generated|ram_block1a20\ & ( (\storage~0_combout\ & storage_rtl_0_bypass(25)) ) )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0000000001010101000000000101010110101010111111111010101011111111",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	dataa => \ALT_INV_storage~0_combout\,
	datad => ALT_INV_storage_rtl_0_bypass(25),
	dataf => \storage_rtl_0|auto_generated|ALT_INV_ram_block1a20\,
	combout => \storage~21_combout\);

-- Location: FF_X59_Y4_N23
\storage_rtl_0_bypass[26]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~inputCLKENA0_outclk\,
	asdata => \d_i[21]~input_o\,
	sload => VCC,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => storage_rtl_0_bypass(26));

-- Location: MLABCELL_X59_Y4_N21
\storage~22\ : cyclonev_lcell_comb
-- Equation(s):
-- \storage~22_combout\ = ( \storage_rtl_0|auto_generated|ram_block1a21\ & ( (!\storage~0_combout\) # (storage_rtl_0_bypass(26)) ) ) # ( !\storage_rtl_0|auto_generated|ram_block1a21\ & ( (\storage~0_combout\ & storage_rtl_0_bypass(26)) ) )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0000000001010101000000000101010110101010111111111010101011111111",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	dataa => \ALT_INV_storage~0_combout\,
	datad => ALT_INV_storage_rtl_0_bypass(26),
	dataf => \storage_rtl_0|auto_generated|ALT_INV_ram_block1a21\,
	combout => \storage~22_combout\);

-- Location: FF_X59_Y4_N53
\storage_rtl_0_bypass[27]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~inputCLKENA0_outclk\,
	asdata => \d_i[22]~input_o\,
	sload => VCC,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => storage_rtl_0_bypass(27));

-- Location: MLABCELL_X59_Y4_N51
\storage~23\ : cyclonev_lcell_comb
-- Equation(s):
-- \storage~23_combout\ = (!\storage~0_combout\ & (\storage_rtl_0|auto_generated|ram_block1a22\)) # (\storage~0_combout\ & ((storage_rtl_0_bypass(27))))

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0000101001011111000010100101111100001010010111110000101001011111",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	dataa => \ALT_INV_storage~0_combout\,
	datac => \storage_rtl_0|auto_generated|ALT_INV_ram_block1a22\,
	datad => ALT_INV_storage_rtl_0_bypass(27),
	combout => \storage~23_combout\);

-- Location: FF_X59_Y4_N2
\storage_rtl_0_bypass[28]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~inputCLKENA0_outclk\,
	asdata => \d_i[23]~input_o\,
	sload => VCC,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => storage_rtl_0_bypass(28));

-- Location: MLABCELL_X59_Y4_N0
\storage~24\ : cyclonev_lcell_comb
-- Equation(s):
-- \storage~24_combout\ = ( \storage_rtl_0|auto_generated|ram_block1a23\ & ( (!\storage~0_combout\) # (storage_rtl_0_bypass(28)) ) ) # ( !\storage_rtl_0|auto_generated|ram_block1a23\ & ( (\storage~0_combout\ & storage_rtl_0_bypass(28)) ) )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0000000001010101000000000101010110101010111111111010101011111111",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	dataa => \ALT_INV_storage~0_combout\,
	datad => ALT_INV_storage_rtl_0_bypass(28),
	dataf => \storage_rtl_0|auto_generated|ALT_INV_ram_block1a23\,
	combout => \storage~24_combout\);

-- Location: FF_X59_Y4_N38
\storage_rtl_0_bypass[29]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~inputCLKENA0_outclk\,
	asdata => \d_i[24]~input_o\,
	sload => VCC,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => storage_rtl_0_bypass(29));

-- Location: MLABCELL_X59_Y4_N36
\storage~25\ : cyclonev_lcell_comb
-- Equation(s):
-- \storage~25_combout\ = (!\storage~0_combout\ & (\storage_rtl_0|auto_generated|ram_block1a24\)) # (\storage~0_combout\ & ((storage_rtl_0_bypass(29))))

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0000101001011111000010100101111100001010010111110000101001011111",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	dataa => \ALT_INV_storage~0_combout\,
	datac => \storage_rtl_0|auto_generated|ALT_INV_ram_block1a24\,
	datad => ALT_INV_storage_rtl_0_bypass(29),
	combout => \storage~25_combout\);

-- Location: FF_X59_Y4_N14
\storage_rtl_0_bypass[30]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~inputCLKENA0_outclk\,
	asdata => \d_i[25]~input_o\,
	sload => VCC,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => storage_rtl_0_bypass(30));

-- Location: MLABCELL_X59_Y4_N12
\storage~26\ : cyclonev_lcell_comb
-- Equation(s):
-- \storage~26_combout\ = (!\storage~0_combout\ & (\storage_rtl_0|auto_generated|ram_block1a25\)) # (\storage~0_combout\ & ((storage_rtl_0_bypass(30))))

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0000101001011111000010100101111100001010010111110000101001011111",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	dataa => \ALT_INV_storage~0_combout\,
	datac => \storage_rtl_0|auto_generated|ALT_INV_ram_block1a25\,
	datad => ALT_INV_storage_rtl_0_bypass(30),
	combout => \storage~26_combout\);

-- Location: FF_X59_Y4_N47
\storage_rtl_0_bypass[31]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~inputCLKENA0_outclk\,
	asdata => \d_i[26]~input_o\,
	sload => VCC,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => storage_rtl_0_bypass(31));

-- Location: MLABCELL_X59_Y4_N45
\storage~27\ : cyclonev_lcell_comb
-- Equation(s):
-- \storage~27_combout\ = ( \storage_rtl_0|auto_generated|ram_block1a26\ & ( (!\storage~0_combout\) # (storage_rtl_0_bypass(31)) ) ) # ( !\storage_rtl_0|auto_generated|ram_block1a26\ & ( (\storage~0_combout\ & storage_rtl_0_bypass(31)) ) )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0000000001010101000000000101010110101010111111111010101011111111",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	dataa => \ALT_INV_storage~0_combout\,
	datad => ALT_INV_storage_rtl_0_bypass(31),
	dataf => \storage_rtl_0|auto_generated|ALT_INV_ram_block1a26\,
	combout => \storage~27_combout\);

-- Location: LABCELL_X57_Y4_N0
\Equal1~0\ : cyclonev_lcell_comb
-- Equation(s):
-- \Equal1~0_combout\ = ( rptr_r(0) & ( (!wptr_r(0)) # (!rptr_r(1) $ (!wptr_r(1))) ) ) # ( !rptr_r(0) & ( (!rptr_r(1) $ (!wptr_r(1))) # (wptr_r(0)) ) )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0111110101111101011111010111110110111110101111101011111010111110",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	dataa => ALT_INV_wptr_r(0),
	datab => ALT_INV_rptr_r(1),
	datac => ALT_INV_wptr_r(1),
	dataf => ALT_INV_rptr_r(0),
	combout => \Equal1~0_combout\);

-- Location: LABCELL_X57_Y4_N3
\Equal0~0\ : cyclonev_lcell_comb
-- Equation(s):
-- \Equal0~0_combout\ = ( rptr_r(0) & ( (!rptr_r(1) $ (!wptr_r(1))) # (wptr_r(0)) ) ) # ( !rptr_r(0) & ( (!wptr_r(0)) # (!rptr_r(1) $ (wptr_r(1))) ) )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "1111101010101111111110101010111101011111111101010101111111110101",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	dataa => ALT_INV_wptr_r(0),
	datac => ALT_INV_rptr_r(1),
	datad => ALT_INV_wptr_r(1),
	dataf => ALT_INV_rptr_r(0),
	combout => \Equal0~0_combout\);

-- Location: LABCELL_X63_Y21_N3
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


