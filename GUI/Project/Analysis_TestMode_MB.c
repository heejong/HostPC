#include "OpenPET.h"
#include <userint.h>
#include "Analysis_TestMode_MB.h"

#include "UI_Common.h"

extern int panelHandle_testmode2;
extern int panelHandle_testmode_mb;
extern int previous_panelHandle;

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

int CVICALLBACK MB0 (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			//MessagePopup("Test","button click!");
			DisplayPanel (panelHandle_testmode2);
			previous_panelHandle = panelHandle_testmode_mb;
			HidePanel (panelHandle_testmode_mb);
			break;
	}
	return 0;
}
