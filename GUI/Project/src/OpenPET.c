//==============================================================================
//
// Title:       OpenPET
// Purpose:     The primary GUI file for the OpenPET project containing main().
//
// Created on:  6/11/2013 at 9:03:57 AM by George Netscher.
// Copyright:   Lawrence Berkeley Laboratory. All Rights Reserved.
//
//==============================================================================

//==============================================================================
// Include files

#include <ansi_c.h>
#include <cvirte.h>     
#include <userint.h>
#include "OpenPET.h"
#include "toolbox.h"

#include "UI_Common.h"
#include "Analysis_TestMode2.h"
#include "Analysis_TestMode_MB.h" 
#include "Analysis_EnergyMode.h"
#include "Analysis_EnergyMode_MB.h" 
#include "Analysis_FloodMapMode.h"    
#include "Analysis_FloodMapMode_MB.h"    
#include "Analysis_FloodMapMode_DUC.h"    
#include "Analysis_TimeMode.h"    
#include "Analysis_TimeMode_MB.h"   

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
int panelHandle;
int panelHandle_testmode2; 
int panelHandle_testmode_mb;
int panelHandle_emode;
int panelHandle_emode_mb;
int panelHandle_fmmode;
int panelHandle_fmmode_mb;
int panelHandle_fmmode_duc;
int panelHandle_timemode; 
int panelHandle_timemode_mb;

extern int previous_panelHandle;

//==============================================================================
// Global functions

/// HIFN The main entry-point function.
int main (int argc, char *argv[])
{
    int error = 0;
    
    /* initialize and load resources */
    nullChk (InitCVIRTE (0, argv, 0));
    errChk (panelHandle = LoadPanel (0, "OpenPET.uir", PANEL));
	errChk (panelHandle_testmode2 = LoadPanel (0, "Analysis_TestMode2.uir", TESTMODE2)); 
	errChk (panelHandle_testmode_mb = LoadPanel (0, "Analysis_TestMode_MB.uir", TESTMODEMB));
	errChk (panelHandle_emode_mb = LoadPanel (0, "Analysis_EnergyMode_MB.uir", EMODEMB));  
	errChk (panelHandle_emode = LoadPanel (0, "Analysis_EnergyMode.uir", EMODE)); 
	errChk (panelHandle_fmmode = LoadPanel (0, "Analysis_FloodMapMode.uir", FMMODE)); 
	errChk (panelHandle_fmmode_mb = LoadPanel (0, "Analysis_FloodMapMode_MB.uir", FMMODEMB)); 
	errChk (panelHandle_fmmode_duc = LoadPanel (0, "Analysis_FloodMapMode_DUC.uir", FMMODEDUC)); 
	errChk (panelHandle_timemode = LoadPanel (0, "Analysis_TimeMode.uir", TIMEMODE)); 
	errChk (panelHandle_timemode_mb = LoadPanel (0, "Analysis_TimeMode_MB.uir", TIMEMODEMB)); 	
    
    /* display the panel and run the user interface */
    errChk (DisplayPanel (panelHandle));
    errChk (RunUserInterface ());

Error:
    /* clean up */
    DiscardPanel (panelHandle);
	DiscardPanel (panelHandle_testmode2);
	DiscardPanel (panelHandle_testmode_mb); 
	DiscardPanel (panelHandle_emode); 
	DiscardPanel (panelHandle_emode_mb);
	DiscardPanel (panelHandle_fmmode);   
	DiscardPanel (panelHandle_fmmode_mb); 
	DiscardPanel (panelHandle_fmmode_duc); 
	DiscardPanel (panelHandle_timemode);   
	DiscardPanel (panelHandle_timemode_mb); 
    return 0;
}

																														
//==============================================================================
// UI callback function prototypes

/// HIFN Exit when the user dismisses the panel.
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
	switch (event)
	{
		case EVENT_COMMIT: 
			// view status word to determine analysis type
			SetCtrlAttribute (PANEL, PANEL_COMMANDBUTTON, ATTR_VISIBLE, 1); 
			SetCtrlAttribute (PANEL, PANEL_COMMANDBUTTON_2, ATTR_VISIBLE, 1);  
			SetCtrlAttribute (PANEL, PANEL_COMMANDBUTTON_3, ATTR_VISIBLE, 1);  
			SetCtrlAttribute (PANEL, PANEL_COMMANDBUTTON_4, ATTR_VISIBLE, 1);
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
			DisplayPanel (panelHandle_emode_mb);
			previous_panelHandle = panelHandle;
			HidePanel (panelHandle);
			break;
	}
	return 0;
}

int CVICALLBACK DisplayTestMode (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			DisplayPanel (panelHandle_testmode_mb);
			previous_panelHandle = panelHandle;
			HidePanel (panelHandle);
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
			DisplayPanel (panelHandle_fmmode_mb);
			previous_panelHandle = panelHandle;
			HidePanel (panelHandle);
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
			DisplayPanel (panelHandle_timemode_mb);
			previous_panelHandle = panelHandle;
			HidePanel (panelHandle);
			break;
	}
	return 0;
}
