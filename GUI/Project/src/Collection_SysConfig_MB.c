#include <userint.h>
#include "Collection_SysConfig_MB.h"
#include "UI_Common.h"

extern int panelHandle_wordlength;
extern int panelHandle_calibration;
extern Stack panel_stack;   // defined in UI_Common   

int CVICALLBACK SystemConfigMB (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			// load DUC panel
			break;
	}
	return 0;
}

int CVICALLBACK SaveSetup (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
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
				SetCtrlAttribute (panel, CONFIGMB_COINCIDENCE_32_RING, ATTR_VISIBLE, 1);
				SetCtrlAttribute (panel, CONFIGMB_COINCIDENCE_64_RING, ATTR_VISIBLE, 0); 
			} else {
				// 64-bit single event word
				SetCtrlAttribute (panel, CONFIGMB_COINCIDENCE_64_RING, ATTR_VISIBLE, 1);
				SetCtrlAttribute (panel, CONFIGMB_COINCIDENCE_32_RING, ATTR_VISIBLE, 0);
			}
			break;
	}
	return 0;
}
