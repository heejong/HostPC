#include <userint.h>
#include "GUI_Calibration.h"

int CVICALLBACK CalibrateInMinutes (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			SetCtrlAttribute (panel, CALIBRATE_EVENTS_BUTTON, ATTR_CTRL_VAL, 0);
			SetCtrlAttribute (panel, CALIBRATE_MINUTES_NUMERIC, ATTR_DIMMED, 0);
			SetCtrlAttribute (panel, CALIBRATE_EVENTS_NUMERIC, ATTR_DIMMED, 1);
			break;
	}
	return 0;
}

int CVICALLBACK CalibrateInEvents (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			SetCtrlAttribute (panel, CALIBRATE_MINUTES_BUTTON, ATTR_CTRL_VAL, 0);
			SetCtrlAttribute (panel, CALIBRATE_MINUTES_NUMERIC, ATTR_DIMMED, 1);
			SetCtrlAttribute (panel, CALIBRATE_EVENTS_NUMERIC, ATTR_DIMMED, 0);
			break;
	}
	return 0;
}
