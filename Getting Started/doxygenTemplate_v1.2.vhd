-------------------------------------------------------
--! @file
--! @brief Briefly state the purpose of the file. 
--! ### VERSION:   
--!     1.0
--! ### TARGET DEVICES: 
--!     Altera Cyclone III EP3C40F780C7 (Main FPGA, or FPGA in detecor board)
--! ### TOOL VERSION:  
--!     Quartus II 12.0
--! ### HARDWARE ENVIRONMENT
--!     Specify the hardware type (Support Board,  
--! Detector board, multiplexier board) and version,
--! and configuration type ( DUC: Detector 
--! Unit Controller, and/or CUC: coincidence Unit         
--! Controller, or CDUC: Coincidence/ Detector Unit       
--! Controller, or DB)                                           
--!     HW type     |    HW ver.  |  Config. type  |
--! ----------------|-------------|----------------| 
--!  Support Board  |     1.0     |    CDUC        |
--!
--! ### DEPENDENCIES: 
--!                Name            | version|  description    |
--! -------------------------------|--------|-----------------| 
--!  QuickUSB_CMD_RSP_Decoder.vhd  |  1.0   | USB cmd decoding|
--! ### SCHEMATIC DIAGRAM OR ALGORITHM (optional)
--!     Schematic diagram of the internal structure when necessary
--! @verbatim
--!    _______      _____________________________        _____________________	
--!   |SDRAM  |<-->|         Main_FPGA_CPU       | <--> |*Main FPGA HW manager|	
--!   |_______|    |_____________________________|      |_____________________| 
--!                  CMD  ||          /\ RSP                                        
--!    ________     ______\/____   ___||_______     ____                        
--!   |  S<-P  |<--| CoProcessor| | CoProcessor|<--|P<-S|<---Serial RSP         
--!   |________|   |____________| |____________|   |____|    from IO FPGA       
--!         ||           CMD  ||          /\ RSP             (FPGA_1_4,FPGA_5_8,                           
--!   ______\/_______   ______\/____   ___||_______          Slot1, ...Slot8)     
--!  |CMD_Destination| |   QuickUSB_CMD_RSP_Decoder|                              
--!  | _Controller   | |___________________________|                              
--!  |_______________|   CMD  ||          /\ RSP                                        
--!         ||          ______\/____   ___||_______             ______________________   
--!         \/         |   QuickUSB_Interface      | Event data|* Event data processor|    
--!     Serial CMD     |___________________________| <---------|______________________|   
--!    to IO FPGA                  /\                                    /\              
--! (FPGA_1_4,FPGA_5_8,            ||                                    ||              
--!  Slot1, ...Slot8)              \/                          Single event data         
--!                           Quick USB module                    from IO FPGA           
--! @endverbatim
--! ### TIMING DIAGRAM (optional)
--!     Schematic diagram of the internal structure when necessary
--! @verbatim
--!              _   _   _   _   _   _   _   _   _   _   _               
--! QUSB_IFCLK _| |_| |_| |_| |_| |_| |_| |_| |_| |_| |_| |_
--!           ___                                      ___
--! FIFO_EMPTY   |____________________..._____________|    EVENT_FIFO_EMPTY_in
--!                   ________________..._____________ 
--! FIFO_READ_REQ ___|                                |___ EVENT_FIFO_READ_REQUEST_out
--!                __  __  __  __  __  __  __  __  __  __
--! Addr           X \/A0\/A1\/A2\/A3\/..\/A2\/A2\/A2\/X   EVENT_ADDRESS_FROM_USB_out
--!                __/\__/\__/\__/\__/\__/\54/\55/\56/\__   
--!               ______  __  __  __  __  __  __  __  __
--! Event         X     \/D0\/D1\/D2\/D3\/..\/D2\/D2\/X    EVENT_DATA_TO_USB_in
--!               ______/\__/\__/\__/\__/\__/\54/\55/\__   
--!              _   _   _   _   _   _   _   _   _   _   _               
--! QUSB_IFCLK _| |_| |_| |_| |_| |_| |_| |_| |_| |_| |_| |_
--! @endverbatim
--! ### NOTES
--! 	Specify any additional information needed to         
--!     understand the file's data or functions.               
--!###	DEVELOPMENT HISTORY
--!	Outline the file's development history.     
--!       Date    |  Author         |  Email Address     | Ver. |Description Of Change  
--!	   --------|-----------------|--------------------|------|---------------------
--!     05/28/2013| Qiyu Peng       | QPeng@lbl.gov      | 1.0  |defined content  
--!	 06/04/2013| George Netscher | gmnetscher@lbl.gov | 1.1  |doxygen formatting
--!### Copyright (c) 2013 by LBNL. All Rights Reserved.
-------------------------------------------------------

-------------------------------------------------------
-- This is an example of binary counter
-------------------------------------------------------

library ieee;
use ieee.std_logic_1164.all;

-------------------------------------------------------
entity OR_ent is
port(	x_in: 	in std_logic;
	y_in: 	in std_logic;
	F_out: 	out std_logic
);
end OR_ent;  

-------------------------------------------------------

architecture OR_beh of OR_ent is 
begin 
    F_out <= x_in or y_in; 
end OR_beh;
