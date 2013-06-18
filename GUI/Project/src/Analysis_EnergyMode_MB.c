#include <userint.h>
#include "Analysis_EnergyMode_MB.h"
#include "UI_Common.h"

extern int panelHandle_emode;
extern Stack panel_stack;   // defined in UI_Common

int CVICALLBACK EnergyModeMB (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			DisplayPanel (panelHandle_emode);  
			StackPush(&panel_stack, panel);
			HidePanel (panel);
			break;
	}
	return 0;
}
