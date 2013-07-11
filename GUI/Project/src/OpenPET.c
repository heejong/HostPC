//==============================================================================
/** @file OpenPET.c                          
    @brief This file provides the functionality for the OpenPET main screen

### HARDWARE/FIRMWARE ENVIRONMENT
      OS    |    HW type     |    HW ver.   |          FW ver.  
	--------|----------------|--------------|-------------------------  
      Win   |    Host PC     |     N/A      |           N/A
	  
### FILE REFERENCES
    - <ansi_c.h> - NI library packaging together several common C libraries
	- <userint.h> - the NI user interface library 
	- "toolbox.h" - NI library providing support functions
	- "UI_Common.h" - UI utility structures and functions
	- "OpenPET.h" - header file linking this .c file to "OpenPET.uir"
	- "Analysis_TestMode1.h" - test mode 1 analysis  
	- "Analysis_TestMode2.h" - test mode 2 analysis 
	- "Analysis_TestMode_MB.h" - test mode MB navigation
	- "Analysis_TestMode_DUC.h" - test mode DUC navigation  
	- "Analysis_TestMode_DB.h" - test mode DB navigation  
	- "Analysis_EnergyMode.h" - energy mode analysis
	- "Analysis_EnergyMode_MB.h" - energy mode MB navigation  
	- "Analysis_EnergyMode_DUC.h" - energy mode DUC navigation  
	- "Analysis_EnergyMode_DB.h" - energy mode DB navigation  
	- "Analysis_FloodMapMode.h" - flood map mode analysis     
	- "Analysis_FloodMapMode_MB.h" - flood map mode MB navigation    
	- "Analysis_FloodMapMode_DUC.h" - flood map mode DUC navigation    
	- "Analysis_TimeMode.h" - time mode analysis   
	- "Analysis_TimeMode_MB.h" - time mode MB navigation 
	- "Analysis_TimeMode_DUC.h" - time mode DUC navigation 
	- "Analysis_TimeMode_DB.h" - time mode DB navigation 
	- "Analysis_OscilloscopeMode.h" - oscilloscope mode analysis
	- "Analysis_OscilloscopeMode_MB.h" - oscilloscope mode MB navigation  
	- "Analysis_OscilloscopeMode_DUC.h" - oscilloscope mode DUC navigation 
	- "Analysis_OscilloscopeMode_DB.h" - oscilloscope mode DB navigation 
	- "Analysis_UserDefinedMode.h" - user mode analysis      
	- "Analysis_UserDefinedMode_MB.h" - user mode MB navigation  
	- "Analysis_UserDefinedMode_DUC.h" - user mode DUC navigation    
	- "Analysis_UserDefinedMode_DB.h" - user mode DB navigation  
	
### EXTERNAL VARIABLES
    none    
	
### EXTERNAL REFERENCES
    none     
	
### ABNORMAL TERMINATION CONDITIONS, ERROR AND WARNING MESSAGES
	Other errors may be generated by CVI/LabWindows. The LabWindows documentation is available online 
	at <a href="linkURL"> http://zone.ni.com/reference/en-XX/help/370051V-01/ </a>.
	
### ASSUMPTIONS, CONSTRAINTS, RESTRICTIONS
	Assumptions for each variable and function are listed individually.	
	
### NOTES
	This panel will be the first one loaded and all other panels are called starting from this one.
	
###	ALGORITHM
	All panels are loaded into memory initially to provide faster navigation once the program has loaded. 
	Different pathways are reachable from this screen and available by user selection.
	
###	DEVELOPMENT HISTORY
       Date    |  Author         |  Email Address     | Ver. |Description Of Change  
	   --------|-----------------|--------------------|------|---------------------
	 08/09/2013| George Netscher | gmnetscher@lbl.gov | 1.0  |conclusion of summer work
	 
### Copyright (c) 2013 by LBNL. All Rights Reserved.
*/
//==============================================================================

// Doxygen documentation for Opening Page

/** @mainpage

@section intro Introduction
This page documents the code used for the OpenPET project sponsored by the Moses Laboratory at the
Lawrence Berkeley National Laboratory.

@section starting Getting Started
The complete documentation for each file and each function is given under the files tab. 

*/

//==============================================================================
// Include files

#include <ansi_c.h>
#include <userint.h>
#include "OpenPET.h"
#include "toolbox.h"

#include "UI_Common.h"
#include "Analysis_TestMode1.h" 
#include "Analysis_TestMode2.h"
#include "Analysis_TestMode_MB.h" 
#include "Analysis_TestMode_DUC.h"  
#include "Analysis_TestMode_DB.h"  
#include "Analysis_EnergyMode.h"
#include "Analysis_EnergyMode_MB.h" 
#include "Analysis_EnergyMode_DUC.h" 
#include "Analysis_EnergyMode_DB.h" 
#include "Analysis_FloodMapMode.h"    
#include "Analysis_FloodMapMode_MB.h"    
#include "Analysis_FloodMapMode_DUC.h"    
#include "Analysis_TimeMode.h"    
#include "Analysis_TimeMode_MB.h" 
#include "Analysis_TimeMode_DUC.h"
#include "Analysis_TimeMode_DB.h"
#include "Analysis_OscilloscopeMode.h"    
#include "Analysis_OscilloscopeMode_MB.h" 
#include "Analysis_OscilloscopeMode_DUC.h"
#include "Analysis_OscilloscopeMode_DB.h"
#include "Analysis_UserDefinedMode.h"    
#include "Analysis_UserDefinedMode_MB.h"
#include "Analysis_UserDefinedMode_DUC.h"  
#include "Analysis_UserDefinedMode_DB.h"  
#include "Collection_SysConfig_MB.h"
#include "Collection_WordLength.h"   
#include "Collection_Calibration.h"    

//==============================================================================
// Constants

//==============================================================================
// Types

//==============================================================================
// Static global variables

//==============================================================================
// Static functions

//==============================================================================
// Global variables
int panelHandle;					/**< main screen panel handle */
int panelHandle_testmode_mb; 		/**< test mode MB panel handle */
int panelHandle_testmode_duc; 		/**< test mode DUC panel handle */
int panelHandle_testmode_db;		/**< test mode DB panel handle */
int panelHandle_testmode1; 			/**< test mode 1 analysis screen panel handle */
int panelHandle_testmode2; 			/**< test mode 2 analysis screen panel handle */
int panelHandle_emode_mb;  			/**< energy mode MB panel handle */
int panelHandle_emode_duc; 	 		/**< energy mode DUC panel handle */
int panelHandle_emode_db;			/**< energy mode DB panel handle */
int panelHandle_emode; 				/**< energy mode analysis screen panel handle */
int panelHandle_fmmode_mb;  		/**< flood map mode MB panel handle */
int panelHandle_fmmode_duc; 	 	/**< flood map mode DUC panel handle */
int panelHandle_fmmode; 			/**< flood map mode analysis screen panel handle */
int panelHandle_timemode_mb;  		/**< time mode MB panel handle */
int panelHandle_timemode_duc; 		/**< time mode DUC panel handle */
int panelHandle_timemode_db;		/**< time mode DB panel handle */
int panelHandle_timemode; 			/**< time mode analysis screen panel handle */
int panelHandle_omode_mb;  			/**< oscilloscope mode MB panel handle */
int panelHandle_omode_duc; 	 		/**< oscilloscope mode DUC panel handle */
int panelHandle_omode_db;			/**< oscilloscope mode DB panel handle */
int panelHandle_omode; 				/**< oscilloscope mode analysis screen panel handle */
int panelHandle_usermode_mb;  		/**< user mode MB panel handle */
int panelHandle_usermode_duc; 		/**< user mode DUC panel handle */
int panelHandle_usermode_db;		/**< user mode DB panel handle */
int panelHandle_usermode; 			/**< user mode analysis screen panel handle */
int panelHandle_sysconfig_mb;
int panelHandle_wordlength; 
int panelHandle_calibration;

extern Stack panel_stack;
//extern PanelAppearance appearance; 
extern OpenPETTree current_location;
extern OpenPETTree sys_config;

//==============================================================================
// Global functions

/** @brief This is the main entry-point function.
	@param argc the argument count
	@param *argv[] the argument vector
	@return integer indicating reason for exit. 0 indicates success

### EXTERNAL VARIABLES
	- extern Stack @ref panel_stack - "UI_Common.c"
	- extern OpenPETTree @ref current_location - "UI_Common.c"
	- extern OpenPETTree @ref sys_config - "UI_Common.c"  

### ABNORMAL TERMINATION CONDITIONS, ERROR AND WARNING MESSAGES
	Errors may be generated by CVI/LabWindows. The LabWindows documentation is available online 
	at <a href="linkURL"> http://zone.ni.com/reference/en-XX/help/370051V-01/ </a>.
	
###	ALGORITHM
	After any necessary initialization, each panel is loaded into memory, the first panel is displayed, and the user interface is initiated.
	If there is an error, all panels are cleaned up and discarded using the tools from toolbox.h.
	
###	DEVELOPMENT HISTORY
       Date    |  Author         |  Email Address     | Ver. |Description Of Change  
	   --------|-----------------|--------------------|------|---------------------
	 08/09/2013| George Netscher | gmnetscher@lbl.gov | 1.0  |conclusion of summer work
	 
### Copyright (c) 2013 by LBNL. All Rights Reserved.
*/
int main (int argc, char *argv[])
{
    int error = 0;
    
    /* initialize and load resources */
	StackInit(&panel_stack);
	OpenPETTreeInit(&current_location);
	//OpenPETTreeInit(&sys_config);
	sys_config.MB = 1;
	sys_config.DUC = 7;  // example setup used for test
	sys_config.DB = 7;
	
	
    nullChk (InitCVIRTE (0, argv, 0));
    errChk (panelHandle = LoadPanel (0, "OpenPET.uir", PANEL));
	errChk (panelHandle_testmode1 = LoadPanel (0, "Analysis_TestMode1.uir", TESTMODE1));   
	errChk (panelHandle_testmode2 = LoadPanel (0, "Analysis_TestMode2.uir", TESTMODE2)); 
	errChk (panelHandle_testmode_mb = LoadPanel (0, "Analysis_TestMode_MB.uir", TESTMODEMB));
	errChk (panelHandle_testmode_duc = LoadPanel (0, "Analysis_TestMode_DUC.uir", TESTMODEDU)); 
	errChk (panelHandle_testmode_db = LoadPanel (0, "Analysis_TestMode_DB.uir", TESTMODEDB)); 
	errChk (panelHandle_emode = LoadPanel (0, "Analysis_EnergyMode.uir", EMODE)); 
	errChk (panelHandle_emode_mb = LoadPanel (0, "Analysis_EnergyMode_MB.uir", EMODEMB));  
	errChk (panelHandle_emode_duc = LoadPanel (0, "Analysis_EnergyMode_DUC.uir", EMODEDU));  
	errChk (panelHandle_emode_db = LoadPanel (0, "Analysis_EnergyMode_DB.uir", EMODEDB));  
	errChk (panelHandle_fmmode = LoadPanel (0, "Analysis_FloodMapMode.uir", FMMODE)); 
	errChk (panelHandle_fmmode_mb = LoadPanel (0, "Analysis_FloodMapMode_MB.uir", FMMODEMB)); 
	errChk (panelHandle_fmmode_duc = LoadPanel (0, "Analysis_FloodMapMode_DUC.uir", FMMODEDU)); 
	errChk (panelHandle_timemode = LoadPanel (0, "Analysis_TimeMode.uir", TIMEMODE)); 
	errChk (panelHandle_timemode_mb = LoadPanel (0, "Analysis_TimeMode_MB.uir", TIMEMODEMB)); 	
	errChk (panelHandle_timemode_duc = LoadPanel (0, "Analysis_TimeMode_DUC.uir", TIMEMODEDU));
	errChk (panelHandle_timemode_db = LoadPanel (0, "Analysis_TimeMode_DB.uir", TIMEMODEDB));
	errChk (panelHandle_omode = LoadPanel (0, "Analysis_OscilloscopeMode.uir", OMODE)); 
	errChk (panelHandle_omode_mb = LoadPanel (0, "Analysis_OscilloscopeMode_MB.uir", OMODEMB)); 
	errChk (panelHandle_omode_duc = LoadPanel (0, "Analysis_OscilloscopeMode_DUC.uir", OMODEDU)); 
	errChk (panelHandle_omode_db = LoadPanel (0, "Analysis_OscilloscopeMode_DB.uir", OMODEDB)); 
	errChk (panelHandle_usermode = LoadPanel (0, "Analysis_UserDefinedMode.uir", USERMODE)); 
	errChk (panelHandle_usermode_mb = LoadPanel (0, "Analysis_UserDefinedMode_MB.uir", USERMODEMB)); 
	errChk (panelHandle_usermode_duc = LoadPanel (0, "Analysis_UserDefinedMode_DUC.uir", USERMODEDU)); 
	errChk (panelHandle_usermode_db = LoadPanel (0, "Analysis_UserDefinedMode_DB.uir", USERMODEDB)); 
	errChk (panelHandle_sysconfig_mb = LoadPanel (0, "Collection_SysConfig_MB.uir", CONFIGMB));
	errChk (panelHandle_wordlength = LoadPanel (0, "Collection_WordLength.uir", WORDLENGTH));
	errChk (panelHandle_calibration = LoadPanel (0, "Collection_Calibration.uir", CALIBRATE));
    
    /* display the panel and run the user interface */
    errChk (DisplayPanel (panelHandle));
    errChk (RunUserInterface ());

Error:
    /* clean up */
    DiscardPanel (panelHandle);
	DiscardPanel (panelHandle_testmode1); 
	DiscardPanel (panelHandle_testmode2);
	DiscardPanel (panelHandle_testmode_mb); 
	DiscardPanel (panelHandle_testmode_duc);
	DiscardPanel (panelHandle_testmode_db);
	DiscardPanel (panelHandle_emode); 
	DiscardPanel (panelHandle_emode_mb);
	DiscardPanel (panelHandle_emode_duc); 
	DiscardPanel (panelHandle_emode_db); 
	DiscardPanel (panelHandle_fmmode);   
	DiscardPanel (panelHandle_fmmode_mb); 
	DiscardPanel (panelHandle_fmmode_duc); 
	DiscardPanel (panelHandle_timemode);   
	DiscardPanel (panelHandle_timemode_mb); 
	DiscardPanel (panelHandle_timemode_duc);
	DiscardPanel (panelHandle_timemode_db);
	DiscardPanel (panelHandle_omode);   
	DiscardPanel (panelHandle_omode_mb);
	DiscardPanel (panelHandle_omode_duc);
	DiscardPanel (panelHandle_omode_db);
	DiscardPanel (panelHandle_usermode);   
	DiscardPanel (panelHandle_usermode_mb); 
	DiscardPanel (panelHandle_usermode_duc); 
	DiscardPanel (panelHandle_usermode_db); 
	DiscardPanel (panelHandle_sysconfig_mb);
	DiscardPanel (panelHandle_wordlength);
	DiscardPanel (panelHandle_calibration);
    return 0;
}

																														
//==============================================================================
// UI callback function prototypes

/** @brief This is the panel callback function to handle panel events
	@param panel the panel handle of the panel on which the button is used
	@param event the type of event generated (i.e. left-click causes EVENT_COMMIT)
	@param *callbackData stores the data returned to the UI handled internally by LabWindows
	@param eventData1 stores ancillary information such as the mouse x-position within the panel
	@param eventData2 stores ancillary information such as the mouse y-position within the panel
	@return 1 or 0 specifies whether or not the event should be swallowed. 0 is default-no and 1 is yes-swallow.

### EXTERNAL VARIABLES
	- extern Stack @ref panel_stack - "UI_Common.c"
	- extern OpenPETTree @ref current_location - "UI_Common.c"
	- extern OpenPETTree @ref sys_config - "UI_Common.c"  

### ABNORMAL TERMINATION CONDITIONS, ERROR AND WARNING MESSAGES
	Errors may be generated by CVI/LabWindows. The LabWindows documentation is available online 
	at <a href="linkURL"> http://zone.ni.com/reference/en-XX/help/370051V-01/ </a>.
	
###	ALGORITHM
	After any necessary initialization, each panel is loaded into memory, the first panel is displayed, and the user interface is initiated.
	If there is an error, all panels are cleaned up and discarded using the tools from toolbox.h.
	
###	DEVELOPMENT HISTORY
       Date    |  Author         |  Email Address     | Ver. |Description Of Change  
	   --------|-----------------|--------------------|------|---------------------
	 08/09/2013| George Netscher | gmnetscher@lbl.gov | 1.0  |conclusion of summer work
	 
### Copyright (c) 2013 by LBNL. All Rights Reserved.
*/
int CVICALLBACK panelCB (int panel, int event, void *callbackData,
        int eventData1, int eventData2)
{
    if (event == EVENT_CLOSE)
        QuitUserInterface (0);
    return 0;
}

int CVICALLBACK CollectNewData (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			SetCtrlAttribute (PANEL, PANEL_SETUP, ATTR_VISIBLE, 1);
			SetCtrlAttribute (PANEL, PANEL_CALIBRATE, ATTR_VISIBLE, 1);
			SetCtrlAttribute (PANEL, PANEL_RUN, ATTR_VISIBLE, 1);
			
			SetCtrlAttribute (PANEL, PANEL_FILETEXT, ATTR_VISIBLE, 0); 
			SetCtrlAttribute (PANEL, PANEL_LOAD, ATTR_VISIBLE, 0); 
			SetCtrlAttribute (PANEL, PANEL_GO, ATTR_VISIBLE, 0);  
			
			SetCtrlAttribute (PANEL, PANEL_COMMANDBUTTON, ATTR_VISIBLE, 0); 
			SetCtrlAttribute (PANEL, PANEL_COMMANDBUTTON_2, ATTR_VISIBLE, 0);  
			SetCtrlAttribute (PANEL, PANEL_COMMANDBUTTON_3, ATTR_VISIBLE, 0);  
			SetCtrlAttribute (PANEL, PANEL_COMMANDBUTTON_4, ATTR_VISIBLE, 0);
			SetCtrlAttribute (PANEL, PANEL_COMMANDBUTTON_5, ATTR_VISIBLE, 0);
			SetCtrlAttribute (PANEL, PANEL_COMMANDBUTTON_6, ATTR_VISIBLE, 0);
			SetCtrlAttribute (PANEL, PANEL_COMMANDBUTTON_7, ATTR_VISIBLE, 0);
			break;
	}
	return 0;
}

int CVICALLBACK AnalyzeExistingData (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			SetCtrlAttribute (PANEL, PANEL_FILETEXT, ATTR_VISIBLE, 1); 
			SetCtrlAttribute (PANEL, PANEL_LOAD, ATTR_VISIBLE, 1);  
			SetCtrlAttribute (PANEL, PANEL_GO, ATTR_VISIBLE, 1);  
			
			SetCtrlAttribute (PANEL, PANEL_SETUP, ATTR_VISIBLE, 0);
			SetCtrlAttribute (PANEL, PANEL_CALIBRATE, ATTR_VISIBLE, 0);
			SetCtrlAttribute (PANEL, PANEL_RUN, ATTR_VISIBLE, 0);
			break;
	}
	return 0;
}

int CVICALLBACK Setup (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			DisplayPanel (panelHandle_sysconfig_mb);
			StackPush(&panel_stack, panelHandle);
			HidePanel (panelHandle);
			break;
	}
	return 0;
}

int CVICALLBACK Calibrate (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			DisplayPanel (panelHandle_calibration);
			StackPush(&panel_stack, panel);
			HidePanel (panel);
			break;
	}
	return 0;
}

int CVICALLBACK Run (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:

			break;
	}
	return 0;
}

int CVICALLBACK LoadDataFile (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			// FileSelectPopup ("c:\\Documents and Settings\\OpenPET\\My Documents\\GitHub\\HostPC\\GUI\\Project", "*.*", "", "", VAL_LOAD_BUTTON, 0, 0, 1, 0, analysis_file);
			break;
	}
	return 0;
}

int CVICALLBACK Go (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	//Header header;
	switch (event)
	{
		case EVENT_COMMIT: 
			// view status word to determine analysis type
			SetCtrlAttribute (PANEL, PANEL_COMMANDBUTTON, ATTR_VISIBLE, 1); 
			SetCtrlAttribute (PANEL, PANEL_COMMANDBUTTON_2, ATTR_VISIBLE, 1);  
			SetCtrlAttribute (PANEL, PANEL_COMMANDBUTTON_3, ATTR_VISIBLE, 1);  
			SetCtrlAttribute (PANEL, PANEL_COMMANDBUTTON_4, ATTR_VISIBLE, 1);
			SetCtrlAttribute (PANEL, PANEL_COMMANDBUTTON_5, ATTR_VISIBLE, 1);
			SetCtrlAttribute (PANEL, PANEL_COMMANDBUTTON_6, ATTR_VISIBLE, 1); 
			SetCtrlAttribute (PANEL, PANEL_COMMANDBUTTON_7, ATTR_VISIBLE, 1);  
			
			//header = CreateHeader("test.txt", "User comment.", 30.0, "single");
			
			break;
	}
	return 0;
}

int CVICALLBACK DisplayEnergyMode (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			strcpy(current_location.mode,"Energy Mode");
			DisplayPanel (panelHandle_emode_mb);
			StackPush(&panel_stack, panel);
			HidePanel (panel);
			break;
	}
	return 0;
}

int CVICALLBACK DisplayTestMode1 (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			strcpy(current_location.mode,"Test Mode 1");
			DisplayPanel (panelHandle_testmode_mb);
			StackPush(&panel_stack, panel);
			HidePanel (panel);
			break;
	}
	return 0;
}

int CVICALLBACK DisplayTestMode2 (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			strcpy(current_location.mode,"Test Mode 2");
			DisplayPanel (panelHandle_testmode_mb);
			StackPush(&panel_stack, panel);
			HidePanel (panel);
			break;
	}
	return 0;
}

int CVICALLBACK DisplayFloodMapMode (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			strcpy(current_location.mode,"Flood Map Mode"); 
			DisplayPanel (panelHandle_fmmode_mb);
			StackPush(&panel_stack, panel);
			HidePanel (panel);
			break;
	}
	return 0;
}

int CVICALLBACK DisplayTimeMode (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			strcpy(current_location.mode,"Time Mode"); 
			DisplayPanel (panelHandle_timemode_mb);
			StackPush(&panel_stack, panel);
			HidePanel (panel);
			break;
	}
	return 0;
}

int CVICALLBACK DisplayOscilloscopeMode (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			strcpy(current_location.mode,"Oscilloscope Mode"); 
			DisplayPanel (panelHandle_omode_mb);
			StackPush(&panel_stack, panel);
			HidePanel (panel);
			break;
	}
	return 0;
}

int CVICALLBACK DisplayUserMode (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			strcpy(current_location.mode,"User Mode"); 
			DisplayPanel (panelHandle_usermode_mb);
			StackPush(&panel_stack, panel);
			HidePanel (panel);
			break;
	}
	return 0;
}
