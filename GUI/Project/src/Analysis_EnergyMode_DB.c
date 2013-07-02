#include <ansi_c.h>
#include <userint.h>
#include "Analysis_EnergyMode_DB.h" 

#include "UI_Common.h"

extern int panelHandle;
extern int panelHandle_emode_mb; 
extern int panelHandle_emode_duc; 
extern int panelHandle_emode_db;
extern int panelHandle_emode; 
extern Stack panel_stack;   // defined in UI_Common
extern OpenPETTree current_location;


int CVICALLBACK EnergyModeDB (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			// switch on control for MB0...MB7
			switch (control)
			{
				case EMODEDB_BUTTON_0:
					current_location.DB = 0;
					break;
				case EMODEDB_BUTTON_1:
					current_location.DB = 1;
					break;
				case EMODEDB_BUTTON_2:
					current_location.DB = 2;
					break;
				case EMODEDB_BUTTON_3:
					current_location.DB = 3;
					break;
				case EMODEDB_BUTTON_4:
					current_location.DB = 4;
					break;
				case EMODEDB_BUTTON_5:
					current_location.DB = 5;
					break;
				case EMODEDB_BUTTON_6:
					current_location.DB = 6;
					break;
				case EMODEDB_BUTTON_7:
					current_location.DB = 7;
					break;
			}
			
			DisplayPanel (panelHandle_emode);
			StackPush(&panel_stack, panel); 
			HidePanel (panel);
			break;
	}
	return 0;
}

int CVICALLBACK EnergyModeDBTree (int panel, int control, int event,
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
				StackPush(&panel_stack, panelHandle_emode_mb); 
				StackPush(&panel_stack, panelHandle_emode_duc); 
				StackPush(&panel_stack, panelHandle_emode_db);
				
				HidePanel (panel);				
				DisplayPanel (panelHandle_emode);
				
			}
			else if (new_location.DUC != -1)
			{
				HidePanel(panel);				
				StackPush(&panel_stack, panelHandle_emode_mb); 
				StackPush(&panel_stack, panelHandle_emode_duc); 
				DisplayPanel(panelHandle_emode_db);
			}
			else if (new_location.MB != -1)
			{
				HidePanel(panel);
				StackPush(&panel_stack, panelHandle_emode_mb); 
				DisplayPanel(panelHandle_emode_duc);
			}
			else if (new_location.MB == -1)
			{
				HidePanel(panel);
				DisplayPanel(panelHandle_emode_mb);
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
