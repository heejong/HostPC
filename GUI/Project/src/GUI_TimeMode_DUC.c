//==============================================================================
/** @file GUI_TimeMode_DUC.c                          
    @brief This file provides the functions needed for the time mode DUC screen.

### HARDWARE/FIRMWARE ENVIRONMENT
      OS    |    HW type     |    HW ver.   |          FW ver.  
	--------|----------------|--------------|-------------------------  
      Win   |    Host PC     |     N/A      |           N/A
	  
### FILE REFERENCES
    - <ansi_c.h> - NI library packaging together several common C libraries
	- <userint.h> - the NI user interface library 
	- "UI_Common.h" - UI utility structures and functions
	- "GUI_TimeMode_DUC.h" - provides connection to "GUI_TimeMode.uir"
	
### EXTERNAL VARIABLES
    - extern int @ref panelHandle - "OpenPET.c"
	- extern int @ref panelHandle_timemode_mb - "OpenPET.c"
	- extern int @ref panelHandle_timemode_duc - "OpenPET.c"
	- extern int @ref panelHandle_timemode_db - "OpenPET.c"
	- extern int @ref panelHandle_timemode - "OpenPET.c" 
	- extern Stack @ref panel_stack - "UI_Common.c"
	- extern OpenPETTree @ref current_location - "UI_Common.c"
	
### EXTERNAL REFERENCES
    none     
	
### ABNORMAL TERMINATION CONDITIONS, ERROR AND WARNING MESSAGES
	Other errors may be generated by CVI/LabWindows. The LabWindows documentation is available online 
	at <a href="linkURL"> http://zone.ni.com/reference/en-XX/help/370051V-01/ </a>.
	
### ASSUMPTIONS, CONSTRAINTS, RESTRICTIONS
	To call functions and structures in this file "GUI_TimeMode_DUC.h" must be added to the include path.
	Assumptions for each variable and function are listed individually.	
	
### NOTES
	Each .uir file defines how the panel looks, each .c file give the panel functionality, and a .h file
	is automatically generated by LabWindows to tie the two together.
	
###	ALGORITHM
	The algorithm used for each function is defined with the function it describes.	
	
###	DEVELOPMENT HISTORY
       Date    |  Author         |  Email Address     | Ver. |Description Of Change  
	   --------|-----------------|--------------------|------|---------------------
	 08/09/2013| George Netscher | gmnetscher@lbl.gov | 1.0  |conclusion of summer work
	 
### Copyright (c) 2013 by LBNL. All Rights Reserved.
*/
//==============================================================================

#include <ansi_c.h>
#include <userint.h>
#include "GUI_TimeMode_DUC.h" 
#include "UI_Common.h"

// defined in OpenPET
extern int panelHandle;					/**< main screen panel handle */
extern int panelHandle_timemode_mb;  	/**< time mode MB panel handle */
extern int panelHandle_timemode_duc; 	/**< time mode DUC panel handle */
extern int panelHandle_timemode_db;		/**< time mode DB panel handle */
extern int panelHandle_timemode; 		/**< time mode analysis screen panel handle */

// defined in UI_Common
extern Stack panel_stack;   			/**< stack containing previous panels */	
extern OpenPETTree current_location;	/**< current location in panel tree */
extern int system_size;

/** @brief This function gives the button functionality
	@param panel the panel handle of the panel on which the button is used
	@param control the control on which the event is generated
	@param event the type of event generated (i.e. left-click causes EVENT_COMMIT)
	@param *callbackData stores the data returned to the UI handled internally by LabWindows
	@param eventData1 stores ancillary information such as the mouse x-position within the panel
	@param eventData2 stores ancillary information such as the mouse y-position within the panel
	@return 1 or 0 specifies whether or not the event should be swallowed. 0 is default-no and 1 is yes-swallow.

### EXTERNAL VARIABLES
    - extern int @ref panelHandle - "OpenPET.c"
	- extern int @ref panelHandle_timemode_mb - "OpenPET.c"
	- extern int @ref panelHandle_timemode_duc - "OpenPET.c"
	- extern int @ref panelHandle_timemode_db - "OpenPET.c"
	- extern int @ref panelHandle_timemode - "OpenPET.c" 
	- extern Stack @ref panel_stack - "UI_Common.c"
	- extern OpenPETTree @ref current_location - "UI_Common.c"

### ABNORMAL TERMINATION CONDITIONS, ERROR AND WARNING MESSAGES
	Errors may be generated by CVI/LabWindows. The LabWindows documentation is available online 
	at <a href="linkURL"> http://zone.ni.com/reference/en-XX/help/370051V-01/ </a>.
	
###	ALGORITHM
	When the button is clicked, the current location is updated, the proper panel is displayed, and the
	stack is updated.
	
###	DEVELOPMENT HISTORY
       Date    |  Author         |  Email Address     | Ver. |Description Of Change  
	   --------|-----------------|--------------------|------|---------------------
	 08/09/2013| George Netscher | gmnetscher@lbl.gov | 1.0  |conclusion of summer work
	 
### Copyright (c) 2013 by LBNL. All Rights Reserved.
*/
int CVICALLBACK TimeModeDUC (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			// switch on control for DUC0...DUC7
			switch (control)
			{
				case TIMEMODEDU_BUTTON_0:
					current_location.DUC = 0;
					break;
				case TIMEMODEDU_BUTTON_1:
					current_location.DUC = 1;
					break;
				case TIMEMODEDU_BUTTON_2:
					current_location.DUC = 2;
					break;
				case TIMEMODEDU_BUTTON_3:
					current_location.DUC = 3;
					break;
				case TIMEMODEDU_BUTTON_4:
					current_location.DUC = 4;
					break;
				case TIMEMODEDU_BUTTON_5:
					current_location.DUC = 5;
					break;
				case TIMEMODEDU_BUTTON_6:
					current_location.DUC = 6;
					break;
				case TIMEMODEDU_BUTTON_7:
					current_location.DUC = 7;
					break;
			}
			
			DisplayPanel (panelHandle_timemode_db);
			StackPush(&panel_stack, panel); 
			HidePanel (panel);
			break;
	}
	return 0;
}

/** @brief This function gives the tree functionality
	@param panel the panel handle of the panel on which the button is used
	@param control the control on which the event is generated
	@param event the type of event generated (i.e. left-click causes EVENT_COMMIT)
	@param *callbackData stores the data returned to the UI handled internally by LabWindows
	@param eventData1 stores ancillary information such as the mouse x-position within the panel
	@param eventData2 stores ancillary information such as the mouse y-position within the panel
	@return 1 or 0 specifies whether or not the event should be swallowed. 0 is default-no and 1 is yes-swallow.

### EXTERNAL VARIABLES
    - extern int @ref panelHandle - "OpenPET.c"
	- extern int @ref panelHandle_timemode_mb - "OpenPET.c"
	- extern int @ref panelHandle_timemode_duc - "OpenPET.c"
	- extern int @ref panelHandle_timemode_db - "OpenPET.c"
	- extern int @ref panelHandle_timemode - "OpenPET.c" 
	- extern Stack @ref panel_stack - "UI_Common.c"
	- extern OpenPETTree @ref current_location - "UI_Common.c"

### ABNORMAL TERMINATION CONDITIONS, ERROR AND WARNING MESSAGES
	Errors may be generated by CVI/LabWindows. The LabWindows documentation is available online 
	at <a href="linkURL"> http://zone.ni.com/reference/en-XX/help/370051V-01/ </a>.
	
###	ALGORITHM
	The tree item double-clicked on is given as an index in eventData2. The tag is extracted (i.e. MB0DUC1DB2).
	This tag is parsed to specify the new desired location. The new panel is displayed and the stack is
	updated to allow the desired functionality in the back button.
	
###	DEVELOPMENT HISTORY
       Date    |  Author         |  Email Address     | Ver. |Description Of Change  
	   --------|-----------------|--------------------|------|---------------------
	 08/09/2013| George Netscher | gmnetscher@lbl.gov | 1.0  |conclusion of summer work
	 
### Copyright (c) 2013 by LBNL. All Rights Reserved.
*/
int CVICALLBACK TimeModeDUCTree (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	char item_tag[32];
	OpenPETTree new_location;
	int i, idx, current_boards[3]={-1,-1,-1};
	
	switch (event)
	{
		case EVENT_COMMIT:
			// eventData2 contains index of tree item double-clicked
			GetTreeItemTag(panel, control, eventData2, item_tag);
			
			// update current_location so panel will initialize properly
			OpenPETTreeInit(&new_location);   // set to (-1, -1, -1, "NULL")
			new_location.mode = current_location.mode;
			
			if(system_size == 1)
				// large system -> fill in MB, DUC, and DB board locations
				idx = 0;
			else if(system_size == 2)
				// medium system -> fill in DUC and DB board locations
				idx = 1;
			else if(system_size == 3)
				// small system -> only fill in DB board location
				idx = 2;
			for(i=0; i<32; i++)
			{
				// walk through tag string and pull out board numbers
				if( isdigit(item_tag[i]) )
				{
					current_boards[idx++] = (int)(item_tag[i] - '0');
				}
			}
			new_location.MB = current_boards[0];
			new_location.DUC = current_boards[1];
			new_location.DB = current_boards[2];
			
			// clear panel stack up to root panel 
			while( StackPeek(&panel_stack) != panelHandle )
			{
				StackPop(&panel_stack);	
			}
			
			// determine proper panel to display
			if(new_location.DB != -1) 
			{
				if(system_size == 1)
					// large size
					StackPush(&panel_stack, panelHandle_timemode_mb); 
				if(system_size == 1 || system_size == 2)
					// large or medium size
					StackPush(&panel_stack, panelHandle_timemode_duc);
				
				StackPush(&panel_stack, panelHandle_timemode_db);
				
				HidePanel (panel);				
				DisplayPanel (panelHandle_timemode);
				
			}
			else if (new_location.DUC != -1)
			{
				// in small size, this will never be reached because DUC always equals -1
				if(system_size == 1)
					// large size
					StackPush(&panel_stack, panelHandle_timemode_mb); 
				if(system_size == 1 || system_size == 2)
					// large or medium size
					StackPush(&panel_stack, panelHandle_timemode_duc); 
				
				HidePanel(panel);
				DisplayPanel(panelHandle_timemode_db);
			}
			else if (new_location.MB != -1)
			{
				// in small or medium size, this will never be reached because MB always equals -1
				if(system_size == 1)
					// large size
					StackPush(&panel_stack, panelHandle_timemode_mb);
				
				HidePanel(panel);  
				DisplayPanel(panelHandle_timemode_duc);
			}
			else 
			{
				// only large system should reach here
				HidePanel(panel);
				DisplayPanel(panelHandle_timemode_mb);
			}
			
			current_location.MB = new_location.MB;
			current_location.DUC = new_location.DUC;
			current_location.DB = new_location.DB;
			
			break;
	}
	return 0;
}
