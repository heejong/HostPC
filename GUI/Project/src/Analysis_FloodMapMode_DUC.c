#include <userint.h>
#include "Analysis_FloodMapMode_DUC.h"

extern int panelHandle_fmmode;
extern int previous_panelHandle;   // defined in UI_Common

int CVICALLBACK FloodMapModeDUC (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			DisplayPanel (panelHandle_fmmode);  
			previous_panelHandle = panel;
			HidePanel (panel);
			break;
	}
	return 0;
}
