//==============================================================================
/** @file UI_Common.c                          
    @brief This file provides the implementation for "UI_Common.h"

### HARDWARE/FIRMWARE ENVIRONMENT
      OS    |    HW type     |    HW ver.   |          FW ver.  
	--------|----------------|--------------|-------------------------  
      Win   |    Host PC     |     N/A      |           N/A
	  
### FILE REFERENCES
    - <ansi_c.h> - NI library packaging together several common C libraries
	- <userint.h> - the NI user interface library 
	- "UI_Common.h" - UI utility structures and functions
	
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
	See "UI_Common.h" for more information.
	
###	ALGORITHM
	The algorithm used for each function is defined with the function it describes.	
	
###	DEVELOPMENT HISTORY
       Date    |  Author         |  Email Address     | Ver. |Description Of Change  
	   --------|-----------------|--------------------|------|---------------------
	 08/09/2013| George Netscher | gmnetscher@lbl.gov | 1.0  |conclusion of summer work
	 
### Copyright (c) 2013 by LBNL. All Rights Reserved.
*/
//==============================================================================


//==============================================================================
// Include files
//#include "cvixml.h"
#include <ansi_c.h>
#include <userint.h>
#include "UI_Common.h"
#include "OpenPET.h" 
#include "System_Common.h"
//#include <libxml/xmlreader.h>

//==============================================================================
// Constants

//==============================================================================
// Types

//==============================================================================
// Static global variables
extern int panelHandle;
extern int system_size;

//==============================================================================
// Static functions

//==============================================================================
// Global variables
Stack panel_stack;
//PanelAppearance appearance; 
OpenPETTree current_location; // used to show the currently specified location in the tree
OpenPETTree sys_config;
OpenPETSystemNode *sys_config1;


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
		fprintf(stderr, "Error: empty stack found in call to Stack_Peek()\n");
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
int StackPush(Stack *S, int panel)
{
    if (S->current_size < STACK_MAXSIZE) {
        S->data[S->current_size] = panel;
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


/*
Header CreateHeader(char filename[], char usercomments[], double duration, char datatype[], double timewindow, unsigned short int sofwareversion, unsigned short int firmware version ) 
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
*/


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
	char item_label_root[15], item_label[15],item_label_level1[5], item_label_level2[5], item_label_level3[5];
	int idx_level1, idx_level2, idx_level3, i, j, k;
	int num_items=1;
	int current_boards[3], idx=0;
	int notInitializedFlag=0; // 1 if panel needs to be initialized

	// enable windows red x to terminate program
	if(event == EVENT_CLOSE)
		QuitUserInterface (0);
	
	// initialize panel when it gets focus
	if(event != EVENT_GOT_FOCUS)
		return 0;

	// only initialize panel once
	// if title_string is blank, or
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
		
	/**************** specify title to show location in tree ******************/
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

	/************* cycle through each control and initialize as needed ***************/
	GetPanelAttribute (panel, ATTR_PANEL_FIRST_CTRL, &control_id);  // first control
	while(control_id != 0) 
	{
	
		GetCtrlAttribute (panel, control_id, ATTR_CONSTANT_NAME, control_name);
		
		/********************** initialze tree control *************************/
		if(strcmp(control_name, "TREE") == 0)
		{
			FillTreeControl(panel, control_id);
		}
		
		/********** enable/disable buttons according to system configuration ************/
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

void FillTreeControl(int panel, int control_id)
{
	int num_items, i, j, k, idx_level1, idx_level2, idx_level3;
	int CUC_children, children_level1, children_level2;
	unsigned short int bit_mask_level1=0, bit_mask_level2=0,bit_mask_level3=0;  
	char item_label_root[15], item_label[15],item_label_level1[5], item_label_level2[5], item_label_level3[5];
	OpenPETSystemNode *node_level1, *node_level2, *node_level3;
	unsigned short int type_address;
	
	
	GetNumListItems(panel, control_id, &num_items);
	
	//if(system_size == 1) // large system
	//{
	
		if(num_items == 1) 
		{
			// need to create table
			
			// will handle small size, medium size, large size based on bottom level containing offspring_descriptor.status = 0 (nothing connected to bottom row)
			// the only thing that needs to be changed are the tags used to insert
		
			// bit-wise AND boards connected and boards enabled to determine boards to display
			CUC_children = sys_config1->profile.offspring_descriptor.status & sys_config1->profile.offspring_descriptor.enable; 
			bit_mask_level1 = 0x0080;  // 1000 0000
		
			for(i=0; i<8; i++)   
			{
				if(CUC_children & bit_mask_level1) // enters if statement for any nonzero value - will enter for 1000 0000 AND 0000 0001
				{
					// insert correct item with correct tag based on system size
					if(system_size == 1)
					{
						// large system -> add MB as a child
						sprintf(item_label_level1, "MB%d", i);
						strcpy(item_label, item_label_level1);	  // i.e. tag = MB0
						idx_level1 = InsertTreeItem (panel, control_id, VAL_CHILD, 0, VAL_LAST, item_label_level1, item_label, 0, num_items++);
					}
					else if(system_size == 2)
					{
						// medium system -> add DUC as a child
						sprintf(item_label_level1, "DUC%d", i);
						strcpy(item_label, item_label_level1);	  // i.e. tag = DUC0
						idx_level1 = InsertTreeItem (panel, control_id, VAL_CHILD, 0, VAL_LAST, item_label_level1, item_label, 0, num_items++);	
					} 
					else if(system_size == 3)
					{
						// small system -> add DB as a child
						sprintf(item_label_level1, "DB%d", i);
						strcpy(item_label, item_label_level1);	  // i.e. tag = DB0
						idx_level1 = InsertTreeItem (panel, control_id, VAL_CHILD, 0, VAL_LAST, item_label_level1, item_label, 0, num_items++);			
					}
					else 
					{
						fprintf(stderr, "Error: Could not determine system size in FillTreeControl()"); 
						exit(1);
					}
						
					// prepare this level1 node to add level2 children
					node_level1 = sys_config1->child_nodes[i];
					children_level1 = node_level1->profile.offspring_descriptor.status & node_level1->profile.offspring_descriptor.enable; 
					bit_mask_level2 = 0x0080;  // 1000 0000
				
					for(j=0; j<8; j++)	  
					{
						if(children_level1 & bit_mask_level2) 
						{
							// insert correct item with correct tag based on system size
						 	if(system_size == 1)
							{
								// large system -> add DUC as child
								sprintf(item_label_level2, "DUC%d", j);
								strcat(item_label, item_label_level2);   // i.e. tag = MB0DUC0
								strcpy(item_label_root, item_label);
								idx_level2 = InsertTreeItem (panel, control_id, VAL_CHILD, idx_level1, VAL_LAST, item_label_level2, item_label, 0, num_items++);
							}
							else if(system_size == 2)
							{
								// medium system -> add DB as child
								sprintf(item_label_level2, "DB%d", j);
								strcat(item_label, item_label_level2);   // i.e. tag = DUC0DB0
								strcpy(item_label_root, item_label);
								idx_level2 = InsertTreeItem (panel, control_id, VAL_CHILD, idx_level1, VAL_LAST, item_label_level2, item_label, 0, num_items++);
							}
							else if(system_size == 3)
							{
								fprintf(stderr, "Error: Should not have found attempt to add boards to level2 of small system in FillTreeControl()");
								exit(1);
							}
							else
							{
								fprintf(stderr, "Error: Could not determine system size in FillTreeControl()"); 
								exit(1);
							}
							
							// prepare this DUC node to add DB children
							node_level2 = node_level1->child_nodes[i];
							children_level2 = node_level2->profile.offspring_descriptor.status & node_level2->profile.offspring_descriptor.enable; 
							bit_mask_level3 = 0x0080;  // 1000 0000
				
							for(k=0; k<8; k++)		 
							{
								if(children_level2 & bit_mask_level3)
								{
									if(system_size != 1) 
									{
										fprintf(stderr, "Error: Invalid attempt to add to level3 when not in large system");
										exit(1);
									}
									//add DB as child
									sprintf(item_label_level3, "DB%d", k); 
									strcat(item_label, item_label_level3);   // i.e. tag = MB0DUC0DB0
									idx_level3 = InsertTreeItem (panel, control_id, VAL_CHILD, idx_level2, VAL_LAST, item_label_level3, item_label, 0, num_items++);
									strcpy(item_label,item_label_root);   // tag = MB0DUC0
								}
							
								// shift bit mask
								bit_mask_level3 = bit_mask_level3 >> 1; 
							}
						}
					
						strcpy(item_label,item_label_level1);   // tag = MB0   (reset tag)
						if(system_size == 1) 
						{
							if(j != current_location.DUC)
								SetTreeItemAttribute (panel, control_id, idx_level2, ATTR_COLLAPSED, 1);
						} 
						
					
						// shift bit mask
						bit_mask_level2 = bit_mask_level2 >> 1; 
					}
				
				}
			
				strcpy(item_label,"");   // tag = ""   (reset tag)
				if(system_size == 1)
				{
					if(i != current_location.MB)
						SetTreeItemAttribute (panel, control_id, idx_level1, ATTR_COLLAPSED, 1);
				}
				else if(system_size == 2)
				{
					if(i != current_location.DUC)
						SetTreeItemAttribute (panel, control_id, idx_level1, ATTR_COLLAPSED, 1);		
				}
				
				// shift bit mask
				bit_mask_level1 = bit_mask_level1 >> 1;   // 1000 0000 -> 0100 0000 -> ... -> 0000 0001 -> 0000 0000   
			}
		}
		else 
		{
			// tree already created, just need to show correct location
			for(i=1; i<num_items; i++)
			{
				// collapse all
				SetTreeItemAttribute (panel, control_id, i, ATTR_COLLAPSED, 1);	
			}
			
			if(current_location.MB != -1)
			{
				sprintf(item_label, "MB%d", current_location.MB);
				GetTreeItemFromTag (panel, control_id, item_label, &idx_level1);
				SetTreeItemAttribute (panel, control_id, idx_level1, ATTR_COLLAPSED, 0);	
			} 
			if(current_location.DUC != -1)
			{
				sprintf(item_label, "MB%dDUC%d", current_location.MB, current_location.DUC);
				GetTreeItemFromTag (panel, control_id, item_label, &idx_level2);
				SetTreeItemAttribute (panel, control_id, idx_level2, ATTR_COLLAPSED, 0);	
			} 
			if(current_location.DB != -1)
			{
				sprintf(item_label, "MB%dDUC%dDB%d", current_location.MB, current_location.DUC, current_location.DB);
				GetTreeItemFromTag (panel, control_id, item_label, &idx_level3);
				SetTreeItemAttribute (panel, control_id, idx_level3, ATTR_SELECTED, 1);
			} 
		
		
		}
	/*
	}
	else if(system_size == 2)  // medium-sized system
	{
		if(num_items == 1) 
		{
			// need to create table
		
			// bit-wise AND boards connected and boards enabled to determine boards to display
			CUC_children = sys_config1->profile.offspring_descriptor.status & sys_config1->profile.offspring_descriptor.enable; 

			bit_mask_level2 = 0x0080;  // 1000 0000
		
			for(j=0; j<8; j++)	  
			{
				if(CUC_children & bit_mask_level2) 
				{
				 	//add DUC as child
					sprintf(item_label_level2, "DUC%d", j);  // tag = DUC0 
					strcpy(item_label, item_label_level2);
					idx_level2 = InsertTreeItem (panel, control_id, VAL_CHILD, 0, VAL_LAST, item_label_level2, item_label, 0, num_items++);
				
					// prepare this DUC node to add DB children
					node_level2 = sys_config1->child_nodes[i];
					children_level2 = node_level2->profile.offspring_descriptor.status & node_level2->profile.offspring_descriptor.enable; 
					bit_mask_level3 = 0x0080;  // 1000 0000
		
					for(k=0; k<8; k++)		 
					{
						if(children_level2 & bit_mask_level3)
						{
							//add DB as child
							sprintf(item_label_level3, "DB%d", k); 
							strcat(item_label, item_label_level3);   // tag = MB0DUC0DB0
							idx_level3 = InsertTreeItem (panel, control_id, VAL_CHILD, idx_level2, VAL_LAST, item_label_level3, item_label, 0, num_items++);
							strcpy(item_label,item_label_root);   // tag = MB0DUC0
						}
					
						// shift bit mask
						bit_mask_level3 = bit_mask_level3 >> 1; 
					}
				}
			
				strcpy(item_label,item_label_level1);   // tag = MB0   (reset tag)
				if(j != current_location.DUC)
					SetTreeItemAttribute (panel, control_id, idx_level2, ATTR_COLLAPSED, 1);
			
				// shift bit mask
				bit_mask_level2 = bit_mask_level2 >> 1; 
			}
		}
		else 
		{
			// tree already created, just need to show correct location
			for(i=1; i<num_items; i++)
			{
				// collapse all
				SetTreeItemAttribute (panel, control_id, i, ATTR_COLLAPSED, 1);	
			}
			
			if(current_location.MB != -1)
			{
				sprintf(item_label, "MB%d", current_location.MB);
				GetTreeItemFromTag (panel, control_id, item_label, &idx_level1);
				SetTreeItemAttribute (panel, control_id, idx_level1, ATTR_COLLAPSED, 0);	
			} 
			if(current_location.DUC != -1)
			{
				sprintf(item_label, "MB%dDUC%d", current_location.MB, current_location.DUC);
				GetTreeItemFromTag (panel, control_id, item_label, &idx_level2);
				SetTreeItemAttribute (panel, control_id, idx_level2, ATTR_COLLAPSED, 0);	
			} 
			if(current_location.DB != -1)
			{
				sprintf(item_label, "MB%dDUC%dDB%d", current_location.MB, current_location.DUC, current_location.DB);
				GetTreeItemFromTag (panel, control_id, item_label, &idx_level3);
				SetTreeItemAttribute (panel, control_id, idx_level3, ATTR_SELECTED, 1);
			} 
		
		
		}
	}
	else if(system_size == 3)
	{
		
		
	}
	else
	{
		fprintf(stderr, "Error: Could not determine system size in FillTreeControl()");
	}
	*/
	return;	
}

int SystemSize(OpenPETSystemNode *root_node)
{
	// return 1 for large, 2 for medium, 3 for small
	// return -1 for error
	unsigned short int bit_mask=0x0080, type_address;
	int CUC_children, i;

	// determine where child nodes are connected
	CUC_children = sys_config1->profile.offspring_descriptor.status & sys_config1->profile.offspring_descriptor.enable;
	
	for(i=0; i<8; i++)
	{
		if(CUC_children & bit_mask)
		{
			type_address = root_node->profile.offspring_descriptor.type_address[i]; // first connected child
			if(type_address & 0x1000)   // 0001 = MB
				return 1;               // must be large system	
			if(type_address & 0x2000)   // 0010 = DUC
				return 2;				// must be medium system
			if(type_address & 0x3000)   // 0011 = DB
	   			return 3;				// must be small system
			else
			{
				fprintf(stderr, "Error: Could not determine system configuration in SystemSize()");	
				return -1;
			}
				
		}
		bit_mask = bit_mask >> 1; 	
	}

	fprintf(stderr, "Error: Could not determine system configuration in SystemSize()");	
	return -1;
		
}

