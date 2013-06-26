#include "Analysis_TestMode_DUC.h"
#include "cvixml.h"
#include "Analysis_OscilloscopeMode_MB.h"
#include <ansi_c.h>
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
Stack panel_stack;
PanelAppearance appearance; 
OpenPETTree current_location;
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
			while(!StackEmpty(&panel_stack)) {
				StackPop(&panel_stack);
			}
			HidePanel (panel);
			
			// fix current location to specify no selections
			current_location.MB = -1;
			current_location.DUC = -1;
			current_location.DB = -1;
			strcpy(current_location.mode, "NULL");
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
			DisplayPanel (StackPop(&panel_stack));
			HidePanel (panel);
			
			// fix current location
			if(current_location.DB != -1) 
				current_location.DB = -1;
			else if(current_location.DUC != -1)
				current_location.DUC = -1;
			else if(current_location.MB != -1)
				current_location.MB = -1;
			else
				strcpy(current_location.mode, "NULL");
			
			break;
	}
	return 0;
}

int CVICALLBACK TreeControl (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			// eventData2 contains specific item double-clicked on
			// switch on eventData2 to provide panel change
			break;
	}
	return 0;
}


// initalizes stack
void StackInit(Stack *S)
{
    S->current_size = 0;
	return;
}

// returns top value on success and -1 on failure
// does not change stack structure
int StackPeek(Stack *S)
{
    if (S->current_size == 0) {
		// stack empty
		fprintf(stderr, "Error: empty stack found in call to Stack_Top()\n");
        return -1;
    } 

    return S->data[S->current_size-1];
}

// retuns 1 if empty 0 if not
int StackEmpty(Stack *S)
{
	if (S->current_size == 0) {
		return 1;  // true
    } else {
		return 0;  // false
	}
}
	

// returns 0 on succcess and -1 on failure
int StackPush(Stack *S, int d)
{
    if (S->current_size < STACK_MAXSIZE) {
        S->data[S->current_size] = d;
		S->current_size++;
		return 0;
	} else {
        fprintf(stderr, "Error: exceeded stack range on attempt to push\n");
		return -1;
	}
}

// returns popped value on success and -1 on failure
int StackPop(Stack *S)
{
    if (S->current_size == 0) {
        fprintf(stderr, "Error: empty stack found on attempt to pop\n");
		return -1;
	} else {
        S->current_size--;
		return S->data[S->current_size];
	}
}  

void OpenPETTreeInit(OpenPETTree *T) 
{
	// a value of -1 in any location specifies an undeclared value
	T->MB=-1;
	T->DUC=-1;
	T->DB=-1;
	strcpy(T->mode,"NULL");
	return;
}

Header CreateHeader(char filename[], char usercomments[], double duration, char datatype[]/*, double timewindow, unsigned short int sofwareversion, unsigned short int firmware version */) 
{
	Header H;
	strcpy(H.filename,filename);
	strcpy(H.usercomments,usercomments);
	GetCurrentDateTime(&H.datetime);
	H.duration = duration;
	strcpy(H.datatype,datatype);
	H.timewindow = .12;
	H.softwareversion=11;
	H.firmwareversion=12;
	
	return H;
	
}


/*

void SaveXMLHeader(void) 
{
	CVIXMLElement DateElement;
	CVIXMLDocument xmlDoc;
	// XML example http://api.wunderground.com/api/8629c52c6434d424/geolookup/conditions/forecast/q/TX/Dallas.xml
	
	CVIXMLNewDocument ("RootElement", &xmlDoc);
	
	CVIXMLSaveDocument (xmlDoc, 0, "Test.xml");
}

void SavePanelAppearance(int panel, PanelAppearance *appearance)
{
	GetPanelAttribute (panel, ATTR_HEIGHT, &appearance->height);
	GetPanelAttribute (panel, ATTR_WIDTH, &appearance->width);
	GetPanelAttribute (panel, ATTR_TOP, &appearance->top);
	GetPanelAttribute (panel, ATTR_LEFT, &appearance->left);
}
	

void RecallPanelAppearance(int panel, PanelAppearance *appearance) 
{
	SetPanelAttribute (panel, ATTR_HEIGHT, appearance->height);
	SetPanelAttribute (panel, ATTR_WIDTH, appearance->width);
	SetPanelAttribute (panel, ATTR_TOP, appearance->top);
	SetPanelAttribute (panel, ATTR_LEFT, appearance->left);
}

*/

int CVICALLBACK PanelTreeInit (int panel, int event, void *callbackData,
		int eventData1, int eventData2)
{
	char title_string[30];
	char temp_string[10];
	
	switch (event)
	{
		case EVENT_GOT_FOCUS:
			sprintf (title_string, "%s ", current_location.mode); 
			//strcat to add on MB0, etc.
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
			if(current_location.DB != -1)
			{
				sprintf(temp_string, "DB%d ", current_location.DB);
				strcat(title_string, temp_string); 
			}
			
			SetPanelAttribute (panel, ATTR_TITLE, title_string);
	
			// populate instrument tree
			break;
		case EVENT_LOST_FOCUS:
			// maybe use to clean up memory
			break;
		case EVENT_CLOSE:

			break;
	}
	return 0;
}
