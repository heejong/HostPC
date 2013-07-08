#include <ansi_c.h>
#include <userint.h>
#include "Analysis_FloodMapMode.h"
#include "UI_Common.h"
#include "OpenPET.h"

extern int panelHandle;
extern int panelHandle_fmmode_mb; 
extern int panelHandle_fmmode_duc; 
extern int panelHandle_fmmode; 

extern Stack panel_stack;   // defined in UI_Common
extern OpenPETTree current_location;
extern OpenPETTree sys_config;  

int CVICALLBACK InitializeFloodMapMode (int panel, int event, void *callbackData,
		int eventData1, int eventData2)
{
	char title_string[50];
	
	char item_label_root[15], item_label[15],item_label_MB[5], item_label_DUC[5], item_label_DB[5];
	int idx_MB, idx_DUC, idx_DB, i, j, k;
	int num_items=1;
	int current_boards[3], idx=0;
	int notInitializedFlag=0; // 1 if panel needs to be initialized
	switch (event)
	{
		case EVENT_GOT_FOCUS:
			sprintf(title_string, "FloodMap Mode - MB%d DUC%d", current_location.MB, current_location.DUC);
			SetPanelAttribute (panel, ATTR_TITLE, title_string); 
		
			// populate instrument tree
			GetNumListItems (panel, FMMODE_TREE, &num_items);
			if(num_items==1) 
			{
				// need to create table
				for(i=0; i<=sys_config.MB; i++)
				{
					//add MB as child
					sprintf(item_label_MB, "MB%d", i);
					strcpy(item_label, item_label_MB);	  // tag = MB0
					idx_MB = InsertTreeItem (panel, FMMODE_TREE, VAL_CHILD, 0, VAL_LAST, item_label_MB, item_label, 0, num_items++);
		
					for(j=0; j<=sys_config.DUC; j++)	  // assumes same number of DUC into each MB
					{
						//add DUC as child
						sprintf(item_label_DUC, "DUC%d", j);
						strcat(item_label, item_label_DUC);   // tag = MB0DUC0
						strcpy(item_label_root, item_label);
						idx_DUC = InsertTreeItem (panel, FMMODE_TREE, VAL_CHILD, idx_MB, VAL_LAST, item_label_DUC, item_label, 0, num_items++);
			
						for(k=0; k<=sys_config.DB; k++)		 // assumes same number of DB into each DUC
						{
							//add DB as child
							sprintf(item_label_DB, "DB%d", k); 
							strcat(item_label, item_label_DB);   // tag = MB0DUC0DB0
							idx_DB = InsertTreeItem (panel, FMMODE_TREE, VAL_CHILD, idx_DUC, VAL_LAST, item_label_DB, item_label, 0, num_items++);
							strcpy(item_label,item_label_root);   // tag = MB0DUC0
							//if(k == current_location.DB)
							//	SetTreeItemAttribute (panel, FMMODE_TREE, idx_DB, ATTR_SELECTED, 1);
						}
						strcpy(item_label,item_label_MB);   // tag = MB0
						if(j != current_location.DUC)
							SetTreeItemAttribute (panel, FMMODE_TREE, idx_DUC, ATTR_COLLAPSED, 1);
			
					}
					strcpy(item_label,"");   // tag = ""
					if(i != current_location.MB)
						SetTreeItemAttribute (panel, FMMODE_TREE, idx_MB, ATTR_COLLAPSED, 1);
				}
			} 
			else 
			{
				// table already created, just need to show correct location
				for(i=1; i<num_items; i++)
				{
					// collapse all
					SetTreeItemAttribute (panel, FMMODE_TREE, i, ATTR_COLLAPSED, 1);	
				}
			
				// need to properly expand columns
				// scroll through each item and compare item name??
				// get a hold of item handle somehow, perhaps better insertion scheme
				// GetTreeItermFromTag()
				if(current_location.MB != -1)
				{
					sprintf(item_label, "MB%d", current_location.MB);
					GetTreeItemFromTag (panel, FMMODE_TREE, item_label, &idx_MB);
					SetTreeItemAttribute (panel, FMMODE_TREE, idx_MB, ATTR_COLLAPSED, 0);	
				} 
				if(current_location.DUC != -1)
				{
					sprintf(item_label, "MB%dDUC%d", current_location.MB, current_location.DUC);
					GetTreeItemFromTag (panel, FMMODE_TREE, item_label, &idx_DUC);
					SetTreeItemAttribute (panel, FMMODE_TREE, idx_DUC, ATTR_COLLAPSED, 0);	
				} 
				/*
				if(current_location.DB != -1)
				{
					sprintf(item_label, "MB%dDUC%dDB%d", current_location.MB, current_location.DUC, current_location.DB);
					GetTreeItemFromTag (panel, FMMODE_TREE, item_label, &idx_DB);
					SetTreeItemAttribute (panel, FMMODE_TREE, idx_DB, ATTR_SELECTED, 1);
				} 
				*/
			}
			
			//SetActiveCtrl(panel, FMMODE_TREE);
			break;
		case EVENT_LOST_FOCUS:

			break;
		case EVENT_CLOSE:

			break;
	}
	return 0;
}

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
