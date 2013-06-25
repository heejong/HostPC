#include <userint.h>
#include "Analysis_UserDefinedMode_MB.h"
#include "UI_Common.h"

extern Stack panel_stack;   // defined in UI_Common
extern int panelHandle_usermode;
extern PanelAppearance appearance;

int CVICALLBACK UserModeMB (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			DisplayPanel (panelHandle_usermode);
			StackPush(&panel_stack, panel);
			//SavePanelAppearance(panel, &appearance);
			HidePanel (panel); 
			break;
	}
	return 0;
}
