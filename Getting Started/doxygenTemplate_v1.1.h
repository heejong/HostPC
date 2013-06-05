/** @file doxygenTemplate_v1.1.c                          
    @brief Briefly state the purpose of the file.  

### HARDWARE/FIRMWARE ENVIRONMENT
	Specify the Operation system     
    (Win or NIOS II), hardware type and version (PC or    
    detector board) and the version of FPGA firmware that 
    support this version of software code ( DUC: Detector 
    Unit Controller, and/or CUC: coincidence Unit         
    Controller, or CDUC: Coincidence/ Detector Unit       
    Controller)                                           
      OS    |    HW type     |    HW ver.   |          FW ver.  
	--------|----------------|--------------|-------------------------  
    NIOS II | Support Board  |     1.0      | DUC1.0,CUC1.0 or CDUC1.0
### FILE REFERENCES
	Specify the name, I/O, and description of files  
    used by functions within this file. If the file does  
    not have file references, entering "none".            
      File Name      |      I/O        |  Description                
	-----------------|-----------------|-----------------  
      ref1.h         |      I          |    details   
      ref2.h         |      IO         |    details                
### EXTERNAL VARIABLES
	Specify the source, name, type, I/O, and      
    description of variables being used by the      
    unit that do not come in through the calling    
    sequence. If the unit does not have external    
    variables, indicate so by entering "none".
     Source file | Var. name  | Type | I/O | Description            
	-------------|------------|------|-----|----------
       ref1.h    |    var     | int  |  O  |  details            
### EXTERNAL REFERENCES
	Specify the exact name of each unit called  
    or invoked by this unit, followed by a        
    one-line description of the unit. If the      
    unit does not have external references,       
    indicate so by entering "none".              
       Name       |    Description                              
	 -------------|---------------------
       func(int)  |     details                              
### ABNORMAL TERMINATION CONDITIONS, ERROR AND WARNING MESSAGES
    Describe the circumstances under which the unit        
    terminates abnormally. List error messages that this   
    unit issues and briefly explain what triggers each.    
### ASSUMPTIONS, CONSTRAINTS, RESTRICTIONS
	Describe the assumptions  
    that are important to the design and implementation    
    of the unit (e.g., "It is assumed that all input       
    data have been checked for validity.") Include         
    descriptions of constraints and restrictions imposed   
    by the unit (e.g., "The unit must complete its         
    execution within 75 microseconds.") This section       
    contains information that explains the                 
    characteristics and peculiarities of the unit.         
### NOTES
	Specify any additional information needed to         
    understand the file's data or functions.               
###	ALGORITHM
	Describe algorithm used in the program if necessary.  
###	DEVELOPMENT HISTORY
	Outline the file's development history.     
       Date    |  Author         |  Email Address     | Ver. |Description Of Change  
	   --------|-----------------|--------------------|------|---------------------
     05/28/2013| Qiyu Peng       | QPeng@lbl.gov      | 1.0  |defined content  
	 06/04/2013| George Netscher | gmnetscher@lbl.gov | 1.1  |doxygen formatting
### Copyright (c) 2013 by LBNL. All Rights Reserved.
*/

///////////////////////////////////////////////////////////////////////////////

// personal comments unseen by Doxygen
/*
Doxygen cannot see me
*/

///////////////////////////////////////////////////////////////////////////////

/** @brief A brief function description stating the purpose.
	@param i a description of the input integer i
	@param f a description of the input float f
	@return a description of the function output

	In-depth details go here. We will outline the format 
	that the detailed description should take in the following 
	sections. Note the blank line placed between the Doxygen 
	commands above and the detailed text to follow.
*/
int BriefExample(int i, float f);

///////////////////////////////////////////////////////////////////////////////

/** @brief A brief function description stating the purpose.
	@param i a description of the input integer i
	@param f a description of the input float f
	@return a description of the function output

### HARDWARE/FIRMWARE ENVIRONMENT
	Specify the Operation system     
    (Win or NIOS II), hardware type and version (PC or    
    detector board) and the version of FPGA firmware that 
    support this version of software code ( DUC: Detector 
    Unit Controller, and/or CUC: coincidence Unit         
    Controller, or CDUC: Coincidence/ Detector Unit       
    Controller)                                           
      OS    |    HW type     |    HW ver.   |          FW ver.  
	--------|----------------|--------------|-------------------------  
    NIOS II | Support Board  |     1.0      | DUC1.0,CUC1.0 or CDUC1.0
### FILE REFERENCES
	Specify the name, I/O, and description of files  
    used by functions within this file. If the file does  
    not have file references, entering "none".            
      File Name      |      I/O        |  Description                
	-----------------|-----------------|-----------------  
      ref1.h         |      I          |    details   
      ref2.h         |      IO         |    details                
### EXTERNAL VARIABLES
	Specify the source, name, type, I/O, and      
    description of variables being used by the      
    unit that do not come in through the calling    
    sequence. If the unit does not have external    
    variables, indicate so by entering "none".
     Source file | Var. name  | Type | I/O | Description            
	-------------|------------|------|-----|----------
       ref1.h    |    var     | int  |  O  |  details            
### EXTERNAL REFERENCES
	Specify the exact name of each unit called  
    or invoked by this unit, followed by a        
    one-line description of the unit. If the      
    unit does not have external references,       
    indicate so by entering "none".              
       Name       |    Description                              
	 -------------|---------------------
       func(int)  |     details                              
### ABNORMAL TERMINATION CONDITIONS, ERROR AND WARNING MESSAGES
    Describe the circumstances under which the unit        
    terminates abnormally. List error messages that this   
    unit issues and briefly explain what triggers each.    
### ASSUMPTIONS, CONSTRAINTS, RESTRICTIONS
	Describe the assumptions  
    that are important to the design and implementation    
    of the unit (e.g., "It is assumed that all input       
    data have been checked for validity.") Include         
    descriptions of constraints and restrictions imposed   
    by the unit (e.g., "The unit must complete its         
    execution within 75 microseconds.") This section       
    contains information that explains the                 
    characteristics and peculiarities of the unit.         
### NOTES
	Specify any additional information needed to         
    understand the file's data or functions.               
###	ALGORITHM
	Describe algorithm used in the program if necessary.  
###	DEVELOPMENT HISTORY
	Outline the file's development history.     
       Date    |  Author         |  Email Address     | Ver. |Description Of Change  
	   --------|-----------------|--------------------|------|---------------------
     05/28/2013| Qiyu Peng       | QPeng@lbl.gov      | 1.0  |defined content  
	 06/04/2013| George Netscher | gmnetscher@lbl.gov | 1.1  |doxygen formatting
### Copyright (c) 2013 by LBNL. All Rights Reserved.
*/
int ExtendedExample(int i, float f);