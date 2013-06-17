#include <userint.h>
#include "Analysis_FloodMapMode_MB.h"
#include "UI_Common.h"

extern int panelHandle_fmmode_duc;
extern int previous_panelHandle;   // defined in UI_Common

int CVICALLBACK FloodMapModeMB (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			DisplayPanel (panelHandle_fmmode_duc);  
			previous_panelHandle = panel;
			HidePanel (panel);
			break;
	}
	return 0;
}
