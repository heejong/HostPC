#include <userint.h>
#include "Analysis_TestMode_DUC.h"
#include "UI_Common.h"

extern int panelHandle_testmode_db; 
extern Stack panel_stack;   // defined in UI_Common
extern OpenPETTree current_location;   

int CVICALLBACK TestModeDUC (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			// switch on control for DUC0...DUC7 
			switch (control)
			{
				case TESTMODEDU_DUC0_BUTTON:
					current_location.DUC = 0;
					break;
				case TESTMODEDU_DUC1_BUTTON:
					current_location.DUC = 1;
					break;
				case TESTMODEDU_DUC2_BUTTON:
					current_location.DUC = 2;
					break;
				case TESTMODEDU_DUC3_BUTTON:
					current_location.DUC = 3;
					break;
				case TESTMODEDU_DUC4_BUTTON:
					current_location.DUC = 4;
					break;
				case TESTMODEDU_DUC5_BUTTON:
					current_location.DUC = 5;
					break;
				case TESTMODEDU_DUC6_BUTTON:
					current_location.DUC = 6;
					break;
				case TESTMODEDU_DUC7_BUTTON:
					current_location.DUC = 7;
					break;
			}
			
			DisplayPanel (panelHandle_testmode_db);
			StackPush(&panel_stack, panel); 
			HidePanel (panel);
			break;
	}
	return 0;
}
