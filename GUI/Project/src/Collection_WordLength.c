#include <ansi_c.h>
#include <userint.h>
#include "Collection_WordLength.h"
#include "UI_Common.h"

extern Stack panel_stack;
extern int panelHandle_calibration;

int CVICALLBACK SaveSetup (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			DisplayPanel (panelHandle_calibration);
			StackPush(&panel_stack, panel);
			HidePanel (panel);
			break;
	}
	return 0;
}

int CVICALLBACK SingleEventChange (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	int ring_index;
	switch (event)
	{
		case EVENT_COMMIT:
			GetCtrlIndex (panel, control, &ring_index);
			if(ring_index == 0) {
				// 32-bit single event word
				SetCtrlAttribute (panel, WORDLENGTH_COINCIDENCE_32_RING, ATTR_VISIBLE, 1);
				SetCtrlAttribute (panel, WORDLENGTH_COINCIDENCE_64_RING, ATTR_VISIBLE, 0); 
			} else {
				// 64-bit single event word
				SetCtrlAttribute (panel, WORDLENGTH_COINCIDENCE_64_RING, ATTR_VISIBLE, 1);
				SetCtrlAttribute (panel, WORDLENGTH_COINCIDENCE_32_RING, ATTR_VISIBLE, 0);
			}
			break;
	}
	return 0;
}
