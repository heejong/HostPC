//==============================================================================
/** @file GUI_FloodMapMode.c                          
    @brief This file provides the functions needed for the flood map mode final analysis screen.

### HARDWARE/FIRMWARE ENVIRONMENT
      OS    |    HW type     |    HW ver.   |          FW ver.  
	--------|----------------|--------------|-------------------------  
      Win   |    Host PC     |     N/A      |           N/A
	  
### FILE REFERENCES
    - <ansi_c.h> - NI library packaging together several common C libraries
	- <userint.h> - the NI user interface library 
	- "UI_Common.h" - UI utility structures and functions
	- "GUI_FloodMapMode.h" - provides connection to "GUI_Flood MapMode.uir"
	
### EXTERNAL VARIABLES
    - extern int @ref panelHandle - "OpenPET.c"
	- extern int @ref panelHandle_fmmode_mb - "OpenPET.c"
	- extern int @ref panelHandle_fmmode_duc - "OpenPET.c"
	- extern int @ref panelHandle_fmmode - "OpenPET.c" 
	- extern Stack @ref panel_stack - "UI_Common.c"
	- extern OpenPETTree @ref current_location - "UI_Common.c"
	- extern OpenPETSysConfig @ref sys_config - "UI_Common.c"   
	
### EXTERNAL REFERENCES
    none     
	
### ABNORMAL TERMINATION CONDITIONS, ERROR AND WARNING MESSAGES
	Other errors may be generated by CVI/LabWindows. The LabWindows documentation is available online 
	at <a href="linkURL"> http://zone.ni.com/reference/en-XX/help/370051V-01/ </a>.
	
### ASSUMPTIONS, CONSTRAINTS, RESTRICTIONS
	To call functions and structures in this file "GUI_FloodMapMode.h" must be added to the include path.
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
#include "GUI_FloodMapMode.h"
#include "UI_Common.h"

// defined in OpenPET
extern int panelHandle;					/**< main screen panel handle */
extern int panelHandle_fmmode_mb;  		/**< flood map mode MB panel handle */
extern int panelHandle_fmmode_duc; 	 	/**< flood map mode DUC panel handle */
extern int panelHandle_fmmode; 			/**< flood map mode analysis screen panel handle */

// defined in UI_Common
extern Stack panel_stack;   			/**< stack containing previous panels */	
extern OpenPETTree current_location;	/**< current location in panel tree */
extern OpenPETTree sys_config;  		/**< hardward system configuration */

/** @brief This function initializes the panel
	@param panel the panel handle of the panel on which the button is used
	@param event the type of event generated (i.e. left-click causes EVENT_COMMIT)
	@param *callbackData stores the data returned to the UI handled internally by LabWindows
	@param eventData1 stores ancillary information such as the mouse x-position within the panel
	@param eventData2 stores ancillary information such as the mouse y-position within the panel
	@return 1 or 0 specifies whether or not the event should be swallowed. 0 is default-no and 1 is yes-swallow.

### EXTERNAL VARIABLES
	- extern OpenPETTree @ref current_location - "UI_Common.c"
	- extern OpenPETSysConfig @ref sys_config - "UI_Common.c" 

### ABNORMAL TERMINATION CONDITIONS, ERROR AND WARNING MESSAGES
	Errors may be generated by CVI/LabWindows. The LabWindows documentation is available online 
	at <a href="linkURL"> http://zone.ni.com/reference/en-XX/help/370051V-01/ </a>.
	
###	ALGORITHM
	The panel is initialized when the panel receives focus. To initialize, the panel title, tree control, and 
	active items must be updated. The panel title is updated first. Next, the tree control is updated by inserting each DB as a DUC child, each DUC as a MB child, and each
	MB as a CUC child. The CUC is already present by default. Each item inserted is given a tag (i.e. MB0,
	MB0DUC1, or MB0DUC1DB2). These tags allow them to be reached in the future. The tree is collapsed as needed
	to show only the relevant items. If the tree has already been created, it is simply collapsed to show only
	the relevant items. Every other control is updated to display relevant information.

###	DEVELOPMENT HISTORY
       Date    |  Author         |  Email Address     | Ver. |Description Of Change  
	   --------|-----------------|--------------------|------|---------------------
	 08/09/2013| George Netscher | gmnetscher@lbl.gov | 1.0  |conclusion of summer work
	 
### Copyright (c) 2013 by LBNL. All Rights Reserved.
*/
int CVICALLBACK InitializeFloodMapMode (int panel, int event, void *callbackData,
		int eventData1, int eventData2)
{
	char title_string[50];
	
	char item_label_root[15], item_label[15],item_label_MB[5], item_label_DUC[5], item_label_DB[5], temp_string[10];
	int idx_MB, idx_DUC, idx_DB, i, j, k;
	int num_items=1;
	int current_boards[3], idx=0;
	int notInitializedFlag=0; // 1 if panel needs to be initialized
	
	char filepath[260]; // max allowed by Windows OS
	int *floodmap_array;
	int rows, columns;
	
	switch (event)
	{
		case EVENT_GOT_FOCUS:
			switch(current_location.mode)
			{
				case OSCILLOSCOPE:
					sprintf (title_string, "Oscilloscope Mode "); 
					break;
				case TEST1:
					sprintf (title_string, "Test Mode 1 "); 
					break;
				case TEST2:
					sprintf (title_string, "Test Mode 2 "); 
					break;
				case ENERGY:
					sprintf (title_string, "Energy Mode "); 
					break;
				case FLOODMAP:
					sprintf (title_string, "Flood Map Mode "); 
					break;
				case TIME:
					sprintf (title_string, "Time Mode "); 
					break;
				case USER:
					sprintf (title_string, "User Mode "); 
					break;
			} 
			if(current_location.MB != -1) 
			{
				sprintf(temp_string, "- MB%d ", current_location.MB);
				strcat(title_string, temp_string); 	
			}
			if(current_location.DUC != -1) 
			{
				sprintf(temp_string, "DUC%d ", current_location.DUC);
				strcat(title_string, temp_string); 	
			}
			SetPanelAttribute (panel, ATTR_TITLE, title_string); 
		
			// populate instrument tree
			FillTreeControl( panel, FMMODE_TREE);
			
			// read data file
			DetermineFolderPath(filepath, "C:\\Documents and Settings\\OpenPET\\My Documents\\GitHub\\HostPC\\GUI\\Example file structure\\REPORT_data_07162013\\");
			strcat(filepath, "FloodMapMode_Block0.txt");
			DetermineArraySize(filepath, &rows, &columns);
			
			//ReadArrayFromFile(filepath, floodmap_array);
			
			//SetActiveCtrl(panel, FMMODE_TREE);
			break;
		case EVENT_LOST_FOCUS:

			break;
		case EVENT_CLOSE:
			QuitUserInterface (0);
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
	- extern int @ref panelHandle_fmmode_mb - "OpenPET.c"
	- extern int @ref panelHandle_fmmode_duc - "OpenPET.c"
	- extern int @ref panelHandle_fmmode - "OpenPET.c" 
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
int CVICALLBACK FloodMapModeTree (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	char item_tag[32];
	OpenPETTree new_location;
	int i, idx=0, current_boards[3]={-1,-1,-1};
	
	switch (event)
	{
		case EVENT_COMMIT:

			// eventData2 contains index of tree item double-clicked
			GetTreeItemTag(panel, control, eventData2, item_tag);
			
			// update current_location so panel will initialize properly
			OpenPETTreeInit(&new_location);   // set to (-1, -1, -1, "NULL")
			new_location.mode = current_location.mode;
			
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
			/*
			if(new_location.DB != -1) 
			{
				StackPush(&panel_stack, panelHandle_fmmode_mb); 
				StackPush(&panel_stack, panelHandle_fmmode_duc); 
				
				HidePanel (panel);				
				DisplayPanel (panelHandle_fmmode);
				
			}
			*/
			if (new_location.DUC != -1)
			{
				HidePanel(panel);				
				StackPush(&panel_stack, panelHandle_fmmode_mb); 
				StackPush(&panel_stack, panelHandle_fmmode_duc); 
				DisplayPanel(panelHandle_fmmode);
			}
			else if (new_location.MB != -1)
			{
				HidePanel(panel);
				StackPush(&panel_stack, panelHandle_fmmode_mb); 
				DisplayPanel(panelHandle_fmmode_duc);
			}
			else if (new_location.MB == -1)
			{
				HidePanel(panel);
				DisplayPanel(panelHandle_fmmode_mb);
			}
			else {
				HidePanel(panel); 
				DisplayPanel(StackPop(&panel_stack));
			}
			
			current_location.MB = new_location.MB;
			current_location.DUC = new_location.DUC;
			current_location.DB = new_location.DB;
			break;
	}
	return 0;
}
