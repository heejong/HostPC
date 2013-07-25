//==============================================================================
/** @file UI_Common.h                          
    @brief This file provides the utility structures and functions common to several user interface panels.

### HARDWARE/FIRMWARE ENVIRONMENT
      OS    |    HW type     |    HW ver.   |          FW ver.  
	--------|----------------|--------------|-------------------------  
      Win   |    Host PC     |     N/A      |           N/A
	  
### FILE REFERENCES
    - <ansi_c.h> - NI library packaging together several common C libraries
	- <userint.h> - the NI user interface library 
	
### EXTERNAL VARIABLES
    none    
	
### EXTERNAL REFERENCES
    none     
	
### ABNORMAL TERMINATION CONDITIONS, ERROR AND WARNING MESSAGES
    - Error: empty stack found in call to Stack_Peek()
	  + In a call to the function Stack_Peek(), an instance of the struct Stack was found to be empty
	 
	- Error: exceeded stack range on attempt to push
	  + In a call to the function StackPush(), the limit of STACK_MAXSIZE was reached. It is defined in this
	    file and can be increased as needed.		   
	   
	- Error: empty stack found on attempt to pop
	  + In a call to the function StackPop(), an instance of the struct Stack was found to be empty
	 
	Other errors may be generated by CVI/LabWindows. The LabWindows documentation is available online 
	at <a href="linkURL"> http://zone.ni.com/reference/en-XX/help/370051V-01/ </a>.
	
### ASSUMPTIONS, CONSTRAINTS, RESTRICTIONS
	To call functions and structures in this file "UI_Common.h" must be added to the include path.
	Assumptions for each variable and function are listed individually.	
	
### NOTES
	As much common functionality as possible was added to this file to reduce redundancy in other files. 
	Functions and controls that had to be defined individually are defined in the .c files that have been 
	given the same names as the .uir files to which they correspond. Most notably, the tree control event
	implementation had to be defined seperately, but the tree panels are initialized from a single function
	defined in this file.
	
###	ALGORITHM
	The algorithm used for each function is defined with the function it describes.	
	
###	DEVELOPMENT HISTORY
       Date    |  Author         |  Email Address     | Ver. |Description Of Change  
	   --------|-----------------|--------------------|------|---------------------
	 08/09/2013| George Netscher | gmnetscher@lbl.gov | 1.0  |conclusion of summer work
	 
### Copyright (c) 2013 by LBNL. All Rights Reserved.
*/
//==============================================================================

#ifndef __UI_Common_H__
#define __UI_Common_H__

#ifdef __cplusplus
    extern "C" {
#endif

//==============================================================================
// Include files

#include "System_Common.h"  // needed for OpenPETSystemNode type

//==============================================================================
// Constants
#define STACK_MAXSIZE 10  
#define MB_MAX 8
#define DUC_MAX 8
#define DB_MAX 8
		
//==============================================================================
// Types

/** @brief Stack structure created to store current panel location along panel tree.

The stack provides a data structure with low implementation cost to give the current location
along the panel tree. Note this is not a general implementation. It is limited to storing ints
in order to store each panel handle and has a predefined size limit given by STACK_MAXSIZE. 
*/
typedef struct Stack {
    /** 
	The data array stores each panel handle added to the stack
	*/
	int data[STACK_MAXSIZE]; 
	/**
	current_size indicates the current number of items in the stack
	*/
    int current_size;
} Stack;

/** @brief OpenPETTree structure created to store the hardware boards and mode that currently have focus.

This data structure stores the current focus in order to properly update the panels to display. 
For example, if the user wants to examine the Energy Mode data of Detector Board 1 of Detector Unit
Controller 2 of Multiplexer Board 0, the title bar and tree control need to be updated to properly 
specify that location. The OpenPETTree structure would store {1, 2, 0, "Energy Mode"}.  
*/
typedef struct OpenPETTree {
	/**
	MB stores the current Multiplexer Board
	*/
	short int MB;
	
	/**
	DUC stores the current Detector Unit Controller
	*/
	short int DUC;
	
	/**
	DB stores the current Detector Board
	*/
	short int DB;
	
	/**
	mode stores the current analysis mode as a string literal limited to {"Time Mode", "Energy Mode",
	"Test Mode 1", "Test Mode 2", "Flood Map Mode", "User Mode"}.
	*/
	char mode[20]; 
} OpenPETTree;

// used to keep window in the same location when changing between panels
/*		
typedef struct PanelAppearance {
	// panel size
	int height;
	int width;
	// panel position
	int top;
	int left;
} PanelAppearance;
*/


/*
typedef struct Header {
	char filename[50];
	char usercomments[200];
	double datetime; 
	double duration;
	char datatype[10];
	double timewindow;
	unsigned short int softwareversion;
	unsigned short int firmwareversion;
	// more can be added if necessary
} Header;
*/

//==============================================================================
// External variables

//==============================================================================
// Global functions

/** @brief The quit button causes the program to terminate.
	@param panel the panel handle of the panel on which the button is used
	@param control the control id of the button used
	@param event the type of event generated (i.e. left-click causes EVENT_COMMIT)
	@param *callbackData stores the data returned to the UI handled internally by LabWindows
	@param eventData1 stores ancillary information such as the mouse x-position within the panel
	@param eventData2 stores ancillary information such as the mouse y-position within the panel
	@return 1 or 0 specifies whether or not the event should be swallowed. 0 is default-no and 1 is yes-swallow.
	
### ABNORMAL TERMINATION CONDITIONS, ERROR AND WARNING MESSAGES
	Errors may be generated by CVI/LabWindows. The LabWindows documentation is available online 
	at <a href="linkURL"> http://zone.ni.com/reference/en-XX/help/370051V-01/ </a>.
	
###	ALGORITHM
	Regardless of the panel location, the quit button causes the program to exit.	

###	DEVELOPMENT HISTORY
       Date    |  Author         |  Email Address     | Ver. |Description Of Change  
	   --------|-----------------|--------------------|------|---------------------
	 08/09/2013| George Netscher | gmnetscher@lbl.gov | 1.0  |conclusion of summer work
	 
### Copyright (c) 2013 by LBNL. All Rights Reserved.
*/
int CVICALLBACK Quit (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2);

/** @brief The main button causes the program to return to the main screen.
	@param panel the panel handle of the panel on which the button is used
	@param control the control id of the button used
	@param event the type of event generated (i.e. left-click causes EVENT_COMMIT)
	@param *callbackData stores the data returned to the UI handled internally by LabWindows
	@param eventData1 stores ancillary information such as the mouse x-position within the panel
	@param eventData2 stores ancillary information such as the mouse y-position within the panel
	@return 1 or 0 specifies whether or not the event should be swallowed. 0 is default-no and 1 is yes-swallow.
	
### ABNORMAL TERMINATION CONDITIONS, ERROR AND WARNING MESSAGES
	Errors may be generated by CVI/LabWindows. The LabWindows documentation is available online 
	at <a href="linkURL"> http://zone.ni.com/reference/en-XX/help/370051V-01/ </a>.
	
###	ALGORITHM
	The main panel is displayed, the panel_stack is cleared, and the current_location tree is cleared.

###	DEVELOPMENT HISTORY
       Date    |  Author         |  Email Address     | Ver. |Description Of Change  
	   --------|-----------------|--------------------|------|---------------------
	 08/09/2013| George Netscher | gmnetscher@lbl.gov | 1.0  |conclusion of summer work
	 
### Copyright (c) 2013 by LBNL. All Rights Reserved.
*/
int CVICALLBACK Main (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2);

/** @brief The back button causes the program to revert to the previous screen.
	@param panel the panel handle of the panel on which the button is used
	@param control the control id of the button used
	@param event the type of event generated (i.e. left-click causes EVENT_COMMIT)
	@param *callbackData stores the data returned to the UI handled internally by LabWindows
	@param eventData1 stores ancillary information such as the mouse x-position within the panel
	@param eventData2 stores ancillary information such as the mouse y-position within the panel
	@return 1 or 0 specifies whether or not the event should be swallowed. 0 is default-no and 1 is yes-swallow.

### ABNORMAL TERMINATION CONDITIONS, ERROR AND WARNING MESSAGES
	Errors may be generated by CVI/LabWindows. The LabWindows documentation is available online 
	at <a href="linkURL"> http://zone.ni.com/reference/en-XX/help/370051V-01/ </a>.
	
###	ALGORITHM
	The previous panel is displayed, the panel_stack is updated, and the current_location tree is updated.	

###	DEVELOPMENT HISTORY
       Date    |  Author         |  Email Address     | Ver. |Description Of Change  
	   --------|-----------------|--------------------|------|---------------------
	 08/09/2013| George Netscher | gmnetscher@lbl.gov | 1.0  |conclusion of summer work
	 
### Copyright (c) 2013 by LBNL. All Rights Reserved.
*/
int CVICALLBACK Back (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2);

/** @brief Initializes a stack to default values. Should be called once before a stack instance is used. 
	@param *Stack a pointer to a Stack object
	@return void
	  
### ABNORMAL TERMINATION CONDITIONS, ERROR AND WARNING MESSAGES
	Errors may be generated by CVI/LabWindows. The LabWindows documentation is available online 
	at <a href="linkURL"> http://zone.ni.com/reference/en-XX/help/370051V-01/ </a>.

###	DEVELOPMENT HISTORY
       Date    |  Author         |  Email Address     | Ver. |Description Of Change  
	   --------|-----------------|--------------------|------|---------------------
	 08/09/2013| George Netscher | gmnetscher@lbl.gov | 1.0  |conclusion of summer work
	 
### Copyright (c) 2013 by LBNL. All Rights Reserved.
*/
void StackInit(Stack *S);

/** @brief Returns top value on stack if available without altering stack structure. 
	@param *Stack a pointer to a Stack object
	@return top panel handle value on success and -1 on failure
	  
### ABNORMAL TERMINATION CONDITIONS, ERROR AND WARNING MESSAGES
	- Error: empty stack found in call to Stack_Peek()
	  + In a call to the function Stack_Peek(), an instance of the struct Stack was found to be empty

	Errors may be generated by CVI/LabWindows. The LabWindows documentation is available online 
	at <a href="linkURL"> http://zone.ni.com/reference/en-XX/help/370051V-01/ </a>.

###	DEVELOPMENT HISTORY
       Date    |  Author         |  Email Address     | Ver. |Description Of Change  
	   --------|-----------------|--------------------|------|---------------------
	 08/09/2013| George Netscher | gmnetscher@lbl.gov | 1.0  |conclusion of summer work
	 
### Copyright (c) 2013 by LBNL. All Rights Reserved.
*/
int StackPeek(Stack *S);

/** @brief Checks to see if stack is empty  
	@param *Stack a pointer to a Stack object
	@return 1 if stack is empty, and 0 if stack is not empty
	  
### ABNORMAL TERMINATION CONDITIONS, ERROR AND WARNING MESSAGES
	Errors may be generated by CVI/LabWindows. The LabWindows documentation is available online 
	at <a href="linkURL"> http://zone.ni.com/reference/en-XX/help/370051V-01/ </a>.

###	DEVELOPMENT HISTORY
       Date    |  Author         |  Email Address     | Ver. |Description Of Change  
	   --------|-----------------|--------------------|------|---------------------
	 08/09/2013| George Netscher | gmnetscher@lbl.gov | 1.0  |conclusion of summer work
	 
### Copyright (c) 2013 by LBNL. All Rights Reserved.
*/
int StackEmpty(Stack *S);

/** @brief Adds an element to the stack  
	@param *Stack a pointer to a Stack object
	@param panel a panel handle to the panel which should be added to the panel stack
	@return 0 on succcess, and -1 on failure
	  
### ABNORMAL TERMINATION CONDITIONS, ERROR AND WARNING MESSAGES
	- Error: exceeded stack range on attempt to push
	  + In a call to the function StackPush(), the limit of STACK_MAXSIZE was reached. It is defined in this
	    file and can be increased as needed.

	Errors may be generated by CVI/LabWindows. The LabWindows documentation is available online 
	at <a href="linkURL"> http://zone.ni.com/reference/en-XX/help/370051V-01/ </a>.

###	DEVELOPMENT HISTORY
       Date    |  Author         |  Email Address     | Ver. |Description Of Change  
	   --------|-----------------|--------------------|------|---------------------
	 08/09/2013| George Netscher | gmnetscher@lbl.gov | 1.0  |conclusion of summer work
	 
### Copyright (c) 2013 by LBNL. All Rights Reserved.
*/
int StackPush(Stack *S, int panel);

/** @brief Removes an element from the stack  
	@param *Stack a pointer to a Stack object
	@return panel handle value on success and -1 on failure
	  
### ABNORMAL TERMINATION CONDITIONS, ERROR AND WARNING MESSAGES
	- Error: empty stack found on attempt to pop
	  + In a call to the function StackPop(), an instance of the struct Stack was found to be empty

	Errors may be generated by CVI/LabWindows. The LabWindows documentation is available online 
	at <a href="linkURL"> http://zone.ni.com/reference/en-XX/help/370051V-01/ </a>.

###	DEVELOPMENT HISTORY
       Date    |  Author         |  Email Address     | Ver. |Description Of Change  
	   --------|-----------------|--------------------|------|---------------------
	 08/09/2013| George Netscher | gmnetscher@lbl.gov | 1.0  |conclusion of summer work
	 
### Copyright (c) 2013 by LBNL. All Rights Reserved.
*/
int StackPop(Stack *S);

/** @brief Initializes an OpenPETTree instance to default values. Should be called once before an object is used.
	@param *T a pointer to the OpenPETTree object to initialize
	@return void

### ABNORMAL TERMINATION CONDITIONS, ERROR AND WARNING MESSAGES
	Errors may be generated by CVI/LabWindows. The LabWindows documentation is available online 
	at <a href="linkURL"> http://zone.ni.com/reference/en-XX/help/370051V-01/ </a>.
	
###	ALGORITHM
	MB, DUC, and DB set to -1 and mode set to "NULL"

###	DEVELOPMENT HISTORY
       Date    |  Author         |  Email Address     | Ver. |Description Of Change  
	   --------|-----------------|--------------------|------|---------------------
	 08/09/2013| George Netscher | gmnetscher@lbl.gov | 1.0  |conclusion of summer work
	 
### Copyright (c) 2013 by LBNL. All Rights Reserved.
*/
void OpenPETTreeInit(OpenPETTree *T);

/** @brief This function initializes each of the panels used to navigate the hardware tree. It is called
           automatically by each tree panel.
	@param panel the panel handle of the panel on which the button is used
	@param event the type of event generated (i.e. left-click causes EVENT_COMMIT)
	@param *callbackData stores the data returned to the UI handled internally by LabWindows
	@param eventData1 stores ancillary information such as the mouse x-position within the panel
	@param eventData2 stores ancillary information such as the mouse y-position within the panel
	@return 1 or 0 specifies whether or not the event should be swallowed. 0 is default-no and 1 is yes-swallow.

### ABNORMAL TERMINATION CONDITIONS, ERROR AND WARNING MESSAGES
	Errors may be generated by CVI/LabWindows. The LabWindows documentation is available online 
	at <a href="linkURL"> http://zone.ni.com/reference/en-XX/help/370051V-01/ </a>.
	
###	ALGORITHM
	The panel is initialized once when the panel receives focus for the first time. The notInitializedFlag
	is used to prevent repeating the initialization. It is set to 1 if the title string differs from the 
	location expected by the values in current_location. To initialize, the panel title, tree control, and 
	active buttons must be updated. The panel title is updated first. Next, each control is examined and updated
	as needed. The tree control is updated by inserting each DB as a DUC child, each DUC as a MB child, and each
	MB as a CUC child. The CUC is already present by default. Each item inserted is given a tag (i.e. MB0,
	MB0DUC1, or MB0DUC1DB2). These tags allow them to be reached in the future. The tree is collapsed as needed
	to show only the relevant items. If the tree has already been created, it is simply collapsed to show only
	the relevant items. Every other control is updated by simply greying it out if it is not applicable.

###	DEVELOPMENT HISTORY
       Date    |  Author         |  Email Address     | Ver. |Description Of Change  
	   --------|-----------------|--------------------|------|---------------------
	 08/09/2013| George Netscher | gmnetscher@lbl.gov | 1.0  |conclusion of summer work
	 
### Copyright (c) 2013 by LBNL. All Rights Reserved.
*/
int  CVICALLBACK PanelTreeInit(int panel, int event, void *callbackData, 
								int eventData1, int eventData2);

/** @brief Checks to see if a control is a button or an event/error indicator  
	@param control_name[] char array containing the name of the control (i.e. BUTTON_2)
	@return 1 if true, 0 if false
	  
### ABNORMAL TERMINATION CONDITIONS, ERROR AND WARNING MESSAGES
	Errors may be generated by CVI/LabWindows. The LabWindows documentation is available online 
	at <a href="linkURL"> http://zone.ni.com/reference/en-XX/help/370051V-01/ </a>.

###	DEVELOPMENT HISTORY
       Date    |  Author         |  Email Address     | Ver. |Description Of Change  
	   --------|-----------------|--------------------|------|---------------------
	 08/09/2013| George Netscher | gmnetscher@lbl.gov | 1.0  |conclusion of summer work
	 
### Copyright (c) 2013 by LBNL. All Rights Reserved.
*/
int CheckButtonEventError(char control_name[]);

//void SaveXMLHeader(void);
//void SavePanelAppearance(int panel, PanelAppearance *appearance);
//void RecallPanelAppearance(int panel, PanelAppearance *appearance);
//Header CreateHeader(char filename[], char usercomments[], double duration, char datatype[]/*, double timewindow, unsigned short int sofwareversion, unsigned short int firmware version */);

void FillTreeControl(int panel, int control_id);

int SystemSize(OpenPETSystemNode *root_node);

#ifdef __cplusplus
    }
#endif

#endif  /* ndef __UI_Common_H__ */
