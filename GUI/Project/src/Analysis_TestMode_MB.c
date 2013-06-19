#include <userint.h>
#include "Analysis_TestMode_MB.h"

#include "UI_Common.h"

extern int panelHandle_testmode2;
extern int panelHandle_testmode_mb;
extern Stack panel_stack;   // defined in UI_Common
extern PanelAppearance appearance;

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
			StackPush(&panel_stack, panel); 
			SavePanelAppearance(panel, &appearance);
			HidePanel (panel); 
			break;
	}
	return 0;
}
