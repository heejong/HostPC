#include <ansi_c.h>
#include <userint.h>
#include "Analysis_OscilloscopeMode.h"
#include "UI_Common.h"

extern int panelHandle_testmode2;
extern OpenPETTree current_location; 

int CVICALLBACK InitializeOscilloscopeMode (int panel, int event, void *callbackData,
		int eventData1, int eventData2)
{
	char title_string[50];
	switch (event)
	{
		case EVENT_GOT_FOCUS:
			sprintf(title_string, "Oscilloscope Mode - MB%d DUC%d DB%d", current_location.MB, current_location.DUC, current_location.DB);
			SetPanelAttribute (panel, ATTR_TITLE, title_string); 
			break;
		case EVENT_LOST_FOCUS:

			break;
		case EVENT_CLOSE:

			break;
	}
	return 0;
}

int CVICALLBACK ShowEnergySpectrum (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	int panelHandle_energyPopup;
	switch (event)
	{
		case EVENT_COMMIT:
			panelHandle_energyPopup = LoadPanel (0, "Analysis_OscilloscopeMode.uir", OMODE_ENGY);
			InstallPopup (panelHandle_energyPopup);
			//MessagePopup("Hey","Hello");

			break;
		case EVENT_CLOSE:
			RemovePopup(1);
			break;
	}
	return 0;
}

int CVICALLBACK ClosePopup (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			RemovePopup(1); 
			break;
	}
	return 0;
}
