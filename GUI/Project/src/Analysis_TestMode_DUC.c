#include <ansi_c.h>
#include <userint.h>
#include "Analysis_TestMode_DUC.h"
#include "UI_Common.h"

extern int panelHandle;
extern int panelHandle_testmode_mb; 
extern int panelHandle_testmode_duc; 
extern int panelHandle_testmode_db;
extern int panelHandle_testmode2; 
//extern int panelHandle_testmode1; 
extern Stack panel_stack;   // defined in UI_Common
extern OpenPETTree current_location;  

int CVICALLBACK TestModeDUC (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			// switch on control for DUC0...DUC7 
			switch (control)
			{
				case TESTMODEDU_DUC0_BUTTON:
					current_location.DUC = 0;
					break;
				case TESTMODEDU_DUC1_BUTTON:
					current_location.DUC = 1;
					break;
				case TESTMODEDU_DUC2_BUTTON:
					current_location.DUC = 2;
					break;
				case TESTMODEDU_DUC3_BUTTON:
					current_location.DUC = 3;
					break;
				case TESTMODEDU_DUC4_BUTTON:
					current_location.DUC = 4;
					break;
				case TESTMODEDU_DUC5_BUTTON:
					current_location.DUC = 5;
					break;
				case TESTMODEDU_DUC6_BUTTON:
					current_location.DUC = 6;
					break;
				case TESTMODEDU_DUC7_BUTTON:
					current_location.DUC = 7;
					break;
			}
			
			DisplayPanel (panelHandle_testmode_db);
			StackPush(&panel_stack, panel); 
			HidePanel (panel);
			break;
	}
	return 0;
}


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
			break;
	}
	return 0;
}

int CVICALLBACK TestModeDUCTree (int panel, int control, int event,
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
			
			// clear panel stack up to root panel 
			while( StackPeek(&panel_stack) != panelHandle )
			{
				StackPop(&panel_stack);	
			}
			
			// determine proper panel to display
			if(new_location.DB != -1) 
			{
				StackPush(&panel_stack, panelHandle_testmode_mb); 
				StackPush(&panel_stack, panelHandle_testmode_duc); 
				StackPush(&panel_stack, panelHandle_testmode_db);
				
				if(strcmp(current_location.mode,"Test Mode 2") == 0)
				{
					DisplayPanel (panelHandle_testmode2);
				}
				else 
				{	
					// StackPush(&panel_stack, panelHandle_testmode1); 
					// DisplayPanel (panelHandle_testmode1);
				}
				
				HidePanel (panel);
			}
			else if (new_location.DUC != -1)
			{
				StackPush(&panel_stack, panelHandle_testmode_mb); 
				StackPush(&panel_stack, panelHandle_testmode_duc); 
				DisplayPanel(panelHandle_testmode_db);
				HidePanel(panel);
			}
			else if (new_location.MB != -1)
			{
				StackPush(&panel_stack, panelHandle_testmode_mb); 
				DisplayPanel(panelHandle_testmode_duc);
				HidePanel(panel);
			}
			else if (new_location.MB == -1)
			{
				DisplayPanel(panelHandle_testmode_mb);
				HidePanel(panel);
			}
			else {
				DisplayPanel(StackPop(&panel_stack));
				HidePanel(panel);
			}
			
			current_location.MB = new_location.MB;
			current_location.DUC = new_location.DUC;
			current_location.DB = new_location.DB;
			
			break;
	}
	return 0;
}
