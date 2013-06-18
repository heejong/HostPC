#include <userint.h>
#include "Analysis_OscilloscopeMode_MB.h"
#include "UI_Common.h"

extern Stack panel_stack;
extern int panelHandle_omode;

int CVICALLBACK OscilloscopeModeMB (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			DisplayPanel (panelHandle_omode);
			StackPush(&panel_stack, panel); 
			HidePanel (panel);
			break;
	}
	return 0;
}
