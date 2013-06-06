----------------------------------------------------------------------------------
--! 1.FILE NAME: Specify the name of the file 
--! 2.PURPOSE: Briefly state the purpose of the unit.  
--! 3.HARDWARE REQUIREMENTs : Specify the Operation system     *
*               (Win or NIOS II), hardware type and version (PC or    *
*               detector board) and the version of FPGA firmware that *
*               support this version of software code ( DUC: Detector *
*               Unit Controller, and/or CUC: coincidence Unit         *
*               Controller, or CDUC: Coincidence/ Detector Unit       *
*               Controller)                                           *
*      OS        HW type         HW ver.       FW ver.                *
*     NIOS II  Support Board     1.0       DUC1.0,CUC1.0 or CDUC1.0   *

--! Company:        Lawrence Berkeley Laboratory
--! Designer:       Qiyu Peng
--
--! Module Name:    Main_FPGA_TopDesign  
--! Functions:      Main FPGA TopDesign
--! Dependencies:   N/A 
--
--! Design Name:    N/A  
--! Project Name:   N/A
--! Target Devices: Altera Cyclone III EP3C40F780C7 (Main FPGA)
--! Tool versions:  Quartus II 12.0
--
--! Version:        1.0
--! Create Date:    10/10/2012  
--! Update Date:    
--
--! Notes:         System Framework   
--
--*********************************************************************
--! * To be done.
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
--!                     
--*********************************************************************
--	
--! 12.Copyright (c) 2013 by LBNL. All Rights Reserved.                 
----------------------------------------------------------------------------------




/**********************************************************************
* 1.FILE NAME: Specify the name of the file                           *
* 2.PURPOSE: Briefly state the purpose of the unit.                   *
* 3.HARDWARE/FIRMWARE ENVIRONMENTs : Specify the Operation system     *
*               (Win or NIOS II), hardware type and version (PC or    *
*               detector board) and the version of FPGA firmware that *
*               support this version of software code ( DUC: Detector *
*               Unit Controller, and/or CUC: coincidence Unit         *
*               Controller, or CDUC: Coincidence/ Detector Unit       *
*               Controller)                                           *
*      OS        HW type         HW ver.       FW ver.                *
*     NIOS II  Support Board     1.0       DUC1.0,CUC1.0 or CDUC1.0   *
* 4.FILE REFERENCES: Specify the name, I/O, and description of files  *
*               used by functions within this file. If the file does  *
*               not have file references, entering “none.”            *
*      File Name            I/O            Description                *
*      ----!                ----!            -----------!                *
*      ----!                ----!            -----------!                *
* 5.EXTERNAL VARIABLES: Specify the source, name, type, I/O, and      *
*                     description of variables being used by the      *
*                     unit that do not come in through the calling    *
*                     sequence. If the unit does not have external    *
*                     variables, indicate so by entering “none.”      *
*    Source:                                                          *
*       Name         Type         I/O          Description            *
*       ----!         ----!          ---!         -----------!            *
* 6.EXTERNAL REFERENCES:  Specify the exact name of each unit called  *
*                       or invoked by this unit, followed by a        *
*                       one-line description of the unit. If the      *
*                       unit does not have external references,       *
*                       indicate so by entering “none.”*              *
*       Name                 Description                              *
*       ----!                 -----------!                              *
* 7.ABNORMAL TERMINATION CONDITIONS, ERROR AND WARNING MESSAGES:      *
*              Describe the circumstances under which the unit        *
*              terminates abnormally. List error messages that this   *
*              unit issues and briefly explain what triggers each.    *
* 8.ASSUMPTIONS, CONSTRAINTS, RESTRICTIONS: Describe the assumptions  *
*              that are important to the design and implementation    *
*              of the unit (e.g., “It is assumed that all input       *
*              data have been checked for validity.”) Include         *
*              descriptions of constraints and restrictions imposed   *
*              by the unit (e.g., “The unit must complete its         *
*              execution within 75 microseconds.”) This section       *
*              contains information that explains the                 *
*              characteristics and peculiarities of the unit.         *
* 9.NOTES: Notes—Specify any additional information needed to         *
*              understand the file’s data or functions.               *
* 10.ALGORITHM : Describe algorithm used in the program if necessary  *
* 11.DEVELOPMENT HISTORY: Outline the file’s development history      *
*    Date       Author   Email Code      Ver.  Description Of Change  *
*  05/28/2013  Qiyu Peng  QPeng@lbl.gov  1.0   ---------------------!  *
* 12.Copyright (c) 2013 by LBNL. All Rights Reserved.                 *
***********************************************************************/








/**********************************************************************
* 1.FUNCTION NAME: example:int main(int argc, char **argv)            *
* 2.PURPOSE: Briefly state the purpose of the fuction                 *
* 3.HARDWARE/FIRMWARE ENVIRONMENTs : Specify the Operation system     *
*               (Win or NIOS II), hardware type and version (PC or    *
*               detector board) and the version of FPGA firmware that *
*               support this version of software code ( DUC: Detector *
*               Unit Controller, and/or CUC: coincidence Unit         *
*               Controller, or CDUC: Coincidence/ Detector Unit       *
*               Controller)                                           *
*      OS        HW type         HW ver.       FW ver.                *
*     NIOS II  Support Board     1.0       DUC1.0,CUC1.0 or CDUC1.0   *
* 4.USAGES: explain how to use the function                           *
*  4.1 input arguments:                                               *
*      name         - description                                     *
*      example:argc - An integer that contains number of              *
*             arguments in argv. argc>=1.                             *
*  4.2 return values:                                                 *
*      name         - description                                     *
* 5.FILE REFERENCES: Specify the name, I/O, and description of files  *
*               used by functions within this file. If the file does  *
*               not have file references, entering “none.”            *
*      File Name            I/O            Description                *
*      ----!                ----!            -----------!                *
*      ----!                ----!            -----------!                *
* 6.EXTERNAL VARIABLES: Specify the source, name, type, I/O, and      *
*                     description of variables being used by the      *
*                     unit that do not come in through the calling    *
*                     sequence. If the unit does not have external    *
*                     variables, indicate so by entering “none.”      *
*    Source:                                                          *
*       Name         Type         I/O          Description            *
*       ----!         ----!          ---!         -----------!            *
* 7.EXTERNAL REFERENCES:  Specify the exact name of each unit called  *
*                       or invoked by this unit, followed by a        *
*                       one-line description of the unit. If the      *
*                       unit does not have external references,       *
*                       indicate so by entering “none.”*              *
*       Name                 Description                              *
*       ----!                 -----------!                              *
* 8.ABNORMAL TERMINATION CONDITIONS, ERROR AND WARNING MESSAGES:      *
*              Describe the circumstances under which the unit        *
*              terminates abnormally. List error messages that this   *
*              unit issues and briefly explain what triggers each.    *
* 9.ASSUMPTIONS, CONSTRAINTS, RESTRICTIONS: Describe the assumptions  *
*              that are important to the design and implementation    *
*              of the unit (e.g., “It is assumed that all input       *
*              data have been checked for validity.”) Include         *
*              descriptions of constraints and restrictions imposed   *
*              by the unit (e.g., “The unit must complete its         *
*              execution within 75 microseconds.”) This section       *
*              contains information that explains the                 *
*              characteristics and peculiarities of the unit.         *
* 10.NOTES: Notes—Specify any additional information needed to        *
*              understand the file’s data or functions.               *
* 11.ALGORITHM : Describe algorithm used in the program if necessary  *
* 12.DEVELOPMENT HISTORY: Outline the file’s development history      *
*    Date       Author   Email Code      Ver.  Description Of Change  *
*  05/28/2013  Qiyu Peng  QPeng@lbl.gov  1.0   ---------------------!  *
***********************************************************************/


