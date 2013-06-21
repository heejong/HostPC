#include <userint.h>
#include "Collection_SysConfig_MB.h"
#include "UI_Common.h"

extern int panelHandle_wordlength; 
extern Stack panel_stack;   // defined in UI_Common   

int CVICALLBACK Next (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			// load bit length panel
			DisplayPanel (panelHandle_wordlength);
			StackPush(&panel_stack, panel);
			HidePanel (panel);
			break;
	}
	return 0;
}

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
