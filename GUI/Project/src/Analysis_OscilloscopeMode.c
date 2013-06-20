#include <userint.h>
#include "Analysis_OscilloscopeMode.h"
#include "UI_Common.h"

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
