#include <userint.h>
#include "Analysis_TimeMode_MB.h"
#include "UI_Common.h"

extern int previous_panelHandle;   // defined in UI_Common
extern int panelHandle_timemode;

int CVICALLBACK TimeModeMB (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			DisplayPanel (panelHandle_timemode);
			previous_panelHandle = panel; 
			HidePanel (panel); 
			break;
	}
	return 0;
}



