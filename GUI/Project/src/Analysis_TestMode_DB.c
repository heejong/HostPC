#include <userint.h>
#include "Analysis_TestMode_DB.h"
#include "UI_Common.h"

extern int panelHandle_testmode2;
extern Stack panel_stack;   // defined in UI_Common
extern OpenPETTree current_location;  


int CVICALLBACK TestModeDB (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			// switch on control for DB0...DB7
			switch (control)
			{
				case TESTMODEDB_DB0_BUTTON:
					current_location.DB = 0;
					break;
				case TESTMODEDB_DB1_BUTTON:
					current_location.DB = 1;
					break;
				case TESTMODEDB_DB2_BUTTON:
					current_location.DB = 2;
					break;
				case TESTMODEDB_DB3_BUTTON:
					current_location.DB = 3;
					break;
				case TESTMODEDB_DB4_BUTTON:
					current_location.DB = 4;
					break;
				case TESTMODEDB_DB5_BUTTON:
					current_location.DB = 5;
					break;
				case TESTMODEDB_DB6_BUTTON:
					current_location.DB = 6;
					break;
				case TESTMODEDB_DB7_BUTTON:
					current_location.DB = 7;
					break;
			}
			
			DisplayPanel (panelHandle_testmode2);
			StackPush(&panel_stack, panel); 
			HidePanel (panel); 
			break;
	}
	return 0;
}
