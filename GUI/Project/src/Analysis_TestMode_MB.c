#include <ansi_c.h>
#include <userint.h>
#include "Analysis_TestMode_MB.h"

#include "UI_Common.h"

extern int panelHandle_testmode_duc; 
extern Stack panel_stack;   // defined in UI_Common
extern OpenPETTree current_location;

int CVICALLBACK TestModeMB (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			// switch on control for MB0...MB7
			switch (control)
			{
				case TESTMODEMB_BUTTON_0:
					current_location.MB = 0;
					break;
				case TESTMODEMB_BUTTON_1:
					current_location.MB = 1;
					break;
				case TESTMODEMB_BUTTON_2:
					current_location.MB = 2;
					break;
				case TESTMODEMB_BUTTON_3:
					current_location.MB = 3;
					break;
				case TESTMODEMB_BUTTON_4:
					current_location.MB = 4;
					break;
				case TESTMODEMB_BUTTON_5:
					current_location.MB = 5;
					break;
				case TESTMODEMB_BUTTON_6:
					current_location.MB = 6;
					break;
				case TESTMODEMB_BUTTON_7:
					current_location.MB = 7;
					break;
			}
			
			DisplayPanel (panelHandle_testmode_duc);
			StackPush(&panel_stack, panel); 
			HidePanel (panel);
			break;
	}
	return 0;
}
