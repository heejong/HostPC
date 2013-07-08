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
OpenPETTree current_location; // used to show the currently specified location in the tree
OpenPETTree sys_config;		  // used to show the full system tree

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
	int new_panel;
	switch (event)
	{
		case EVENT_COMMIT:
			new_panel = StackPop(&panel_stack);
			DisplayPanel (new_panel);
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

int  CVICALLBACK PanelTreeInit(int panel, int event, void *callbackData, 
								int eventData1, int eventData2)
{
	char control_name[20];
	int control_id, board_number;
	char title_string[30];
	char temp_string[10];
	char item_label_root[15], item_label[15],item_label_MB[5], item_label_DUC[5], item_label_DB[5];
	int idx_MB, idx_DUC, idx_DB, i, j, k;
	int num_items=1;
	int current_boards[3], idx=0;
	int notInitializedFlag=0; // 1 if panel needs to be initialized

	if(event == EVENT_CLOSE)
		QuitUserInterface (0);
	
	// initialize panel when it gets focus
	if(event != EVENT_GOT_FOCUS)
		return 0;

	// only initialize panel once
	// if title_string is blank 
	// if title_string values don't match current location
	
	GetPanelAttribute (panel, ATTR_TITLE, title_string);
	current_boards[0] = current_location.MB;
	current_boards[1] = current_location.DUC;
	current_boards[2] = current_location.DB;
	
	for(i=0; i<30; i++)
	{
		// walk through title string and pull out board numbers
		if( isdigit(title_string[i]) )
		{
			if( current_boards[idx++] != (int)(title_string[i] - '0') )
				notInitializedFlag = 1;
		}
	}
	
	
	if(strcmp(title_string,"") != 0 && !notInitializedFlag)
		return 0;
		
	// specify title to show location in tree *****
	sprintf (title_string, "%s ", current_location.mode); 
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

	// enable/disable buttons according to system configuration *****
	
	GetPanelAttribute (panel, ATTR_PANEL_FIRST_CTRL, &control_id);  // first control
	// cycle through controls disabling those not needed
	while(control_id != 0) 
	{
	
		GetCtrlAttribute (panel, control_id, ATTR_CONSTANT_NAME, control_name);
		
		// populate instrument tree
		if(strcmp(control_name, "TREE") == 0)
		{
			GetNumListItems (panel, control_id, &num_items);
			if(num_items==1) 
			{
				// need to create table
				for(i=0; i<=sys_config.MB; i++)
				{
					//add MB as child
					sprintf(item_label_MB, "MB%d", i);
					strcpy(item_label, item_label_MB);	  // tag = MB0
					idx_MB = InsertTreeItem (panel, control_id, VAL_CHILD, 0, VAL_LAST, item_label_MB, item_label, 0, num_items++);
				
					for(j=0; j<=sys_config.DUC; j++)	  // assumes same number of DUC into each MB
					{
						//add DUC as child
						sprintf(item_label_DUC, "DUC%d", j);
						strcat(item_label, item_label_DUC);   // tag = MB0DUC0
						strcpy(item_label_root, item_label);
						idx_DUC = InsertTreeItem (panel, control_id, VAL_CHILD, idx_MB, VAL_LAST, item_label_DUC, item_label, 0, num_items++);
					
						for(k=0; k<=sys_config.DB; k++)		 // assumes same number of DB into each DUC
						{
							//add DB as child
							sprintf(item_label_DB, "DB%d", k); 
							strcat(item_label, item_label_DB);   // tag = MB0DUC0DB0
							idx_DB = InsertTreeItem (panel, control_id, VAL_CHILD, idx_DUC, VAL_LAST, item_label_DB, item_label, 0, num_items++);
							strcpy(item_label,item_label_root);   // tag = MB0DUC0
							//if(k == current_location.DB)
							//	 SetActiveTreeItem (panel, control_id, idx_DB, VAL_REPLACE_SELECTION_WITH_ITEM);
						}
						strcpy(item_label,item_label_MB);   // tag = MB0
						if(j != current_location.DUC)
							SetTreeItemAttribute (panel, control_id, idx_DUC, ATTR_COLLAPSED, 1);
					
					}
					strcpy(item_label,"");   // tag = ""
					if(i != current_location.MB)
						SetTreeItemAttribute (panel, control_id, idx_MB, ATTR_COLLAPSED, 1);
				}
			} 
			else 
			{
				// table already created, just need to show correct location
				for(i=1; i<num_items; i++)
				{
					// collapse all
					SetTreeItemAttribute (panel, control_id, i, ATTR_COLLAPSED, 1);	
				}
					
				// need to properly expand columns
				// scroll through each item and compare item name??
				// get a hold of item handle somehow, perhaps better insertion scheme
				// GetTreeItermFromTag()
				if(current_location.MB != -1)
				{
					sprintf(item_label, "MB%d", current_location.MB);
					GetTreeItemFromTag (panel, control_id, item_label, &idx_MB);
					SetTreeItemAttribute (panel, control_id, idx_MB, ATTR_COLLAPSED, 0);	
				} 
				if(current_location.DUC != -1)
				{
					sprintf(item_label, "MB%dDUC%d", current_location.MB, current_location.DUC);
					GetTreeItemFromTag (panel, control_id, item_label, &idx_DUC);
					SetTreeItemAttribute (panel, control_id, idx_DUC, ATTR_COLLAPSED, 0);	
				} 
				/*if(current_location.DB != -1)
				{
					sprintf(item_label, "MB%d", current_location.MB);
					GetTreeItemFromTag (panel, control_id, item_label, idx_MB);
					SetTreeItemAttribute (panel, control_id, idx_MB, ATTR_COLLAPSED, 0);	
				}*/ 
				
				
			}
		}
		
		
		if(CheckButtonEventError(control_name))	   // BUTTON, EVENTS, ERRORS
		{
			board_number = ((unsigned short int) control_name[7])-48; // convert ASCII number to int
			if(current_location.MB == -1)
			{
				// haven't chosen MB yet, so on MB screen
				if(board_number > sys_config.MB) 
					SetCtrlAttribute (panel, control_id, ATTR_DIMMED, 1); // dim
			}
			else if(current_location.DUC == -1)
			{
				// already chosen MB, so on DUC screen
				if(board_number > sys_config.DUC) 
					SetCtrlAttribute (panel, control_id, ATTR_DIMMED, 1); // dim
			}
			else if(current_location.DB == -1)
			{
				// already chosen MB & DUC, so on DB screen
				if(board_number > sys_config.DB) 
					SetCtrlAttribute (panel, control_id, ATTR_DIMMED, 1); // dim
			}
			
		}
			
		GetCtrlAttribute (panel, control_id, ATTR_NEXT_CTRL, &control_id);
		
	
	}
	
	return 0;
}

int CheckButtonEventError(char control_name[]) 
{
	// determines if control name is BUTTON*, EVENTS*, or ERRORS* indicating the control needs to be updated in real time
	if(control_name[0] != 'B' && control_name[0] != 'E')
		return 0;  // false
	if(control_name[1] != 'U' && control_name[1] != 'V' && control_name[1] != 'R')
		return 0;  // false
	if(control_name[2] != 'T' && control_name[2] != 'E' && control_name[2] != 'R')
		return 0;  // false
	if(control_name[3] != 'T' && control_name[3] != 'N' && control_name[3] != 'O')
		return 0;  // false
	if(control_name[4] != 'O' && control_name[4] != 'T' && control_name[4] != 'R')
		return 0;  // false
	if(control_name[5] != 'N' && control_name[5] != 'S')
		return 0;  // false
	
	return 1; // true
}
/*
int CVICALLBACK InstrumentTreeControl (int panel, int control, int event,
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
			strcpy(new_location.mode, current_location.mode);
			
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
			
			// determine proper panel to display
			
			// determine mode: Time Mode, Energy Mode, Test Mode, Flood Map Mode, User Mode 
			if(strcmp(new_location.mode, "Time Mode") == 0)
			{
				// hide panel & show new panel
			
				// clear panel stack & update with proper panels for back button to work
			}
			else if(strcmp(new_location.mode, "Energy Mode") == 0)
			{
				// hide panel & show new panel
			
				// clear panel stack & update with proper panels for back button to work
			}
			else if(strcmp(new_location.mode, "Test Mode") == 0)
			{
				// hide panel & show new panel
				
			
				// clear panel stack & update with proper panels for back button to work
			}
			else if(strcmp(new_location.mode, "Flood Map Mode") == 0)
			{
				// hide panel & show new panel
			
				// clear panel stack & update with proper panels for back button to work
			}
			else if(strcmp(new_location.mode, "User Mode") == 0)
			{
				// hide panel & show new panel
			
				// clear panel stack & update with proper panels for back button to work
			} 
			else 
			{
				// Error
				QuitUserInterface (1);	
			}
			
			break;
	}
	return 0;
}
*/
