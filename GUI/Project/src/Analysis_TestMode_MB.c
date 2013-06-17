#include <userint.h>
#include "Analysis_TestMode_MB.h"

#include "UI_Common.h"

extern int panelHandle_testmode2;
extern int panelHandle_testmode_mb;
extern int previous_panelHandle;   // defined in UI_Common
extern int panelHandle_emode;

int CVICALLBACK Init (int panel, int event, void *callbackData,
		int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_GOT_FOCUS:

			break;
		case EVENT_LOST_FOCUS:

			break;
		case EVENT_CLOSE:

			break;
	}
	return 0;
}

int CVICALLBACK TestModeMB (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			// switch on control for MB0...MB8
			DisplayPanel (panelHandle_testmode2);
			previous_panelHandle = panel; 
			HidePanel (panel); 
			break;
	}
	return 0;
}
