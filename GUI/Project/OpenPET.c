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

#include "Analysis_TestMode2.h"

//==============================================================================
// Constants

//==============================================================================
// Types

//==============================================================================
// Static global variables

static int panelHandle;
int panelHandle_testmode2; 

//==============================================================================
// Static functions

//==============================================================================
// Global variables

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
    
    /* display the panel and run the user interface */
    errChk (DisplayPanel (panelHandle));
    errChk (RunUserInterface ());

Error:
    /* clean up */
    DiscardPanel (panelHandle);
	DiscardPanel (panelHandle_testmode2);
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

int CVICALLBACK Test (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{

	switch (event)
	{
		case EVENT_COMMIT:
			InstallPopup (panelHandle_testmode2);
			break;
	}

	return 0;
}
