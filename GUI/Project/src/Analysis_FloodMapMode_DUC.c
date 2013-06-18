#include <userint.h>
#include "Analysis_FloodMapMode_DUC.h"
#include "UI_Common.h"

extern int panelHandle_fmmode;
extern Stack panel_stack;   // defined in UI_Common

int CVICALLBACK FloodMapModeDUC (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			DisplayPanel (panelHandle_fmmode);  
			StackPush(&panel_stack, panel);
			HidePanel (panel);
			break;
	}
	return 0;
}
