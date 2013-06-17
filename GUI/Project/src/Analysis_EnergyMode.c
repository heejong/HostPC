#include <ansi_c.h>
#include <userint.h>
#include "Analysis_EnergyMode.h"
#include "UI_Common.h"
#include "OpenPET.h"

extern int panelHandle_emode; 

int CVICALLBACK DetermineEnergyWindow (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	int ring_index;
	switch (event)
	{
		case EVENT_COMMIT:
			GetCtrlIndex (panelHandle_emode, EMODE_ANALYSIS_METHOD, &ring_index);
			if(ring_index == 0) {
				SetCtrlAttribute (panelHandle_emode, EMODE_METHOD_AMOUNT, ATTR_VISIBLE, 1);
			} else {
				SetCtrlAttribute (panelHandle_emode, EMODE_METHOD_AMOUNT, ATTR_VISIBLE, 0);
			}
			break;
	}
	return 0;
}
