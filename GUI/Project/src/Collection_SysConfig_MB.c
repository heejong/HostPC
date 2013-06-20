#include <userint.h>
#include "Collection_SysConfig_MB.h"

int CVICALLBACK LoadDataFile (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			//FileSelectPopup
			break;
	}
	return 0;
}

int CVICALLBACK Next (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			// load bit length panel
			break;
	}
	return 0;
}

int CVICALLBACK SystemConfigMB (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			// load DUC panel
			break;
	}
	return 0;
}
