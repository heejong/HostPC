#include <analysis.h>
#include <userint.h>
#include "Analysis_TestMode2.h"

extern int panelHandle_testmode2;

int CVICALLBACK InitializeTestMode2 (int panel, int event, void *callbackData,
		int eventData1, int eventData2)
{
	double histogram_axis[11];
	ssize_t histogram_array[11];
	double array[] = {0,0,0,0,0,0,0,0,1,1,6};
	switch (event)
	{
		case EVENT_GOT_FOCUS:
			Histogram (array, 11, 0.0, 11.0, histogram_array, histogram_axis, 11);
			PlotXY (panelHandle_testmode2, TESTMODE2_HISTOGRAM, histogram_axis, histogram_array, 11,
					VAL_DOUBLE, VAL_SIZE_T, VAL_VERTICAL_BAR, VAL_EMPTY_SQUARE, VAL_SOLID, 1, VAL_RED);
			break;
		case EVENT_LOST_FOCUS:

			break;
		case EVENT_CLOSE:
			RemovePopup (0);
			break;
	}
	return 0;
}

int CVICALLBACK SavePlot (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:

			break;
	}
	return 0;
}

int CVICALLBACK SaveOutput (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:

			break;
	}
	return 0;
}

int CVICALLBACK Okay (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			RemovePopup (0);
			break;
	}
	return 0;
}
