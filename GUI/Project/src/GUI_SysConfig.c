#include <ansi_c.h>
#include <userint.h>
#include "GUI_SysConfig.h"
#include "UI_Common.h"

extern int panelHandle_calibration;
extern Stack panel_stack;   // defined in UI_Common  
extern OpenPETTree current_location;
extern OpenPETSysConfig sys_config;  

int CVICALLBACK SaveSetup (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			// save system configuration by pulling checked items from tree control
			
			
			// display next panel
			DisplayPanel (panelHandle_calibration);
			StackPush(&panel_stack, panel);
			HidePanel (panel);
			break;
	}
	return 0;
}

int CVICALLBACK SingleEventChange (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	int ring_index;
	switch (event)
	{
		case EVENT_COMMIT:
			GetCtrlIndex (panel, control, &ring_index);
			if(ring_index == 0) {
				// 32-bit single event word
				SetCtrlAttribute (panel, SYSCONFIG_COINCIDENCE_32_RING, ATTR_VISIBLE, 1);
				SetCtrlAttribute (panel, SYSCONFIG_COINCIDENCE_64_RING, ATTR_VISIBLE, 0); 
			} else {
				// 64-bit single event word
				SetCtrlAttribute (panel, SYSCONFIG_COINCIDENCE_64_RING, ATTR_VISIBLE, 1);
				SetCtrlAttribute (panel, SYSCONFIG_COINCIDENCE_32_RING, ATTR_VISIBLE, 0);
			}
			break;
	}
	return 0;
}

// give tree event functionality
int CVICALLBACK SysConfigTree (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:

			break;
	}
	return 0;
}

// initialize tree control
int CVICALLBACK InitializeSysConfig (int panel, int event, void *callbackData,
		int eventData1, int eventData2)
{
	char title_string[50];
	char item_label_root[15], item_label[15],item_label_MB[5], item_label_DUC[5], item_label_DB[5];
	int idx_MB, idx_DUC, idx_DB, i, j, k;
	int num_items=1;
	int current_boards[3], idx=0;
	
	switch (event)
	{
		case EVENT_GOT_FOCUS:
			SetActiveCtrl(panel, SYSCONFIG_SAVE);
			
			// populate instrument tree
			GetNumListItems (panel, SYSCONFIG_TREE, &num_items);
			if(num_items==1) 
			{
				CheckListItem (panel, SYSCONFIG_TREE, 0, 1);
				// need to create table
				for(i=0; i<=sys_config.MB; i++)
				{
					//add MB as child
					sprintf(item_label_MB, "MB%d", i);
					strcpy(item_label, item_label_MB);	  // tag = MB0
					idx_MB = InsertTreeItem (panel, SYSCONFIG_TREE, VAL_CHILD, 0, VAL_LAST, item_label_MB, item_label, 0, num_items++);
					CheckListItem (panel, SYSCONFIG_TREE, idx_MB, 1);
		
					for(j=0; j<=sys_config.DUC; j++)	  // assumes same number of DUC into each MB
					{
						//add DUC as child
						sprintf(item_label_DUC, "DUC%d", j);
						strcat(item_label, item_label_DUC);   // tag = MB0DUC0
						strcpy(item_label_root, item_label);
						idx_DUC = InsertTreeItem (panel, SYSCONFIG_TREE, VAL_CHILD, idx_MB, VAL_LAST, item_label_DUC, item_label, 0, num_items++);
						CheckListItem (panel, SYSCONFIG_TREE, idx_DUC, 1);
						
						for(k=0; k<=sys_config.DB; k++)		 // assumes same number of DB into each DUC
						{
							//add DB as child
							sprintf(item_label_DB, "DB%d", k); 
							strcat(item_label, item_label_DB);   // tag = MB0DUC0DB0
							idx_DB = InsertTreeItem (panel, SYSCONFIG_TREE, VAL_CHILD, idx_DUC, VAL_LAST, item_label_DB, item_label, 0, num_items++);
							strcpy(item_label,item_label_root);   // tag = MB0DUC0
							if(k == current_location.DB)
								SetTreeItemAttribute (panel, SYSCONFIG_TREE, idx_DB, ATTR_SELECTED, 1);
								CheckListItem (panel, SYSCONFIG_TREE, idx_DB, 1);
						}
						strcpy(item_label,item_label_MB);   // tag = MB0
						if(j != current_location.DUC)
							SetTreeItemAttribute (panel, SYSCONFIG_TREE, idx_DUC, ATTR_COLLAPSED, 1);
			
					}
					strcpy(item_label,"");   // tag = ""
					if(i != current_location.MB)
						SetTreeItemAttribute (panel, SYSCONFIG_TREE, idx_MB, ATTR_COLLAPSED, 1);
				}
			} 
			else 
			{
				// table already created, just need to show correct location
				for(i=1; i<num_items; i++)
				{
					// collapse all
					SetTreeItemAttribute (panel, SYSCONFIG_TREE, i, ATTR_COLLAPSED, 1);	
				}

				if(current_location.MB != -1)
				{
					sprintf(item_label, "MB%d", current_location.MB);
					GetTreeItemFromTag (panel, SYSCONFIG_TREE, item_label, &idx_MB);
					SetTreeItemAttribute (panel, SYSCONFIG_TREE, idx_MB, ATTR_COLLAPSED, 0);	
				} 
				if(current_location.DUC != -1)
				{
					sprintf(item_label, "MB%dDUC%d", current_location.MB, current_location.DUC);
					GetTreeItemFromTag (panel, SYSCONFIG_TREE, item_label, &idx_DUC);
					SetTreeItemAttribute (panel, SYSCONFIG_TREE, idx_DUC, ATTR_COLLAPSED, 0);	
				} 
				if(current_location.DB != -1)
				{
					sprintf(item_label, "MB%dDUC%dDB%d", current_location.MB, current_location.DUC, current_location.DB);
					GetTreeItemFromTag (panel, SYSCONFIG_TREE, item_label, &idx_DB);
					SetTreeItemAttribute (panel, SYSCONFIG_TREE, idx_DB, ATTR_SELECTED, 1);
				} 
			}
			break;
		case EVENT_LOST_FOCUS:

			break;
		case EVENT_CLOSE:

			break;
	}
	return 0;
}
