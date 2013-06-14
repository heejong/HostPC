#include "Analysis_TestMode_MB.h"
#include "Analysis_TestMode2.h"
#include <userint.h>
//==============================================================================
//
// Title:       UI_Common.c
// Purpose:     A short description of the implementation.
//
// Created on:  6/14/2013 at 10:02:00 AM by PC User.
// Copyright:   Lawrence Berkeley Laboratory. All Rights Reserved.
//
//==============================================================================

//==============================================================================
// Include files

#include "UI_Common.h"
#include "OpenPET.h" 

//==============================================================================
// Constants

//==============================================================================
// Types

//==============================================================================
// Static global variables
extern int panelHandle;

//==============================================================================
// Static functions

//==============================================================================
// Global variables
int previous_panelHandle;

//==============================================================================
// Global functions


int CVICALLBACK Quit (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			QuitUserInterface (0);
			break;
	}
	return 0;
}

int CVICALLBACK Main (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			DisplayPanel (panelHandle);
			HidePanel (panel);
			break;
	}
	return 0;
}

int CVICALLBACK Back (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			DisplayPanel (previous_panelHandle);
			HidePanel (panel);
			break;
	}
	return 0;
}
