#include <ansi_c.h>
#include <analysis.h>
#include <userint.h>
#include "Analysis_TestMode2.h"

#include "UI_Common.h"

extern int panelHandle_testmode2;
extern PanelAppearance appearance;
extern OpenPETTree current_location; 

int CVICALLBACK InitializeTestMode2 (int panel, int event, void *callbackData,
		int eventData1, int eventData2)
{
	double histogram_axis[] = {0,1,2,3,4,5,6,7,8,9,10};
	unsigned long histogram_array[] = {0,0,0,0,0,0,0,0,0,0,0}; // length=11
	FILE *fp;
	int i, j, count=0;
	char out[100];
	unsigned short bit_error_count;
	char title_string[50];
	
	unsigned int event_word, event_words[65536];  // may need to check 32-bit size
	
	switch (event)
	{
		case EVENT_GOT_FOCUS:
			//RecallPanelAppearance(panel, &appearance);
			sprintf(title_string, "Test Mode 2 - MB%d DUC%d DB%d", current_location.MB, current_location.DUC, current_location.DB);
			SetPanelAttribute (panel, ATTR_TITLE, title_string); 
			
			fp = fopen("..\\ExampleBinOutput.bin","rb");
			if(fp == NULL) {
				MessagePopup("Error","Could not open file");
				break;
			}
			
			// performed buffered read to decrease processing time
			while( !feof(fp) ) { // check EOF
				fread (event_words, 4, 65536, fp); // read 4 bytes at a time into buffer of 2^16 32-bit words
				if( ferror(fp) ) {
					MessagePopup("Error","Read error");
					break;
				}
				for(i=0; i<65536; i++) {
					// 01010101010 for testmode2
					bit_error_count = 0;
					// loop unrolled for speed
					if(event_words[i] & 0x0001) {
						// should be 0
						histogram_array[0]++;
					}
					if( !(event_words[i] & 0x0002 ) ) {
						// should be 1
						histogram_array[1]++;
					}
					if(event_words[i] & 0x0004) {
						// should be 0
						histogram_array[2]++;
					}
					if( !(event_words[i] & 0x0008 ) ) {
						// should be 1
						histogram_array[3]++;
					}
					if(event_words[i] & 0x0010) {
						// should be 0
						histogram_array[4]++;
					}
					if( !(event_words[i] & 0x0020 ) ) {
						// should be 1
						histogram_array[5]++;
					}
					if(event_words[i] & 0x0040) {
						// should be 0
						histogram_array[6]++;
					}
					if( !(event_words[i] & 0x0080 ) ) {
						// should be 1
						histogram_array[7]++;
					}
					if(event_words[i] & 0x0100) {
						// should be 0
						histogram_array[8]++;
					}
					if( !(event_words[i] & 0x0200 ) ) {
						// should be 1
						histogram_array[9]++;
					}
					if(event_words[i] & 0x0400) {
						// should be 0
						histogram_array[10]++;
					}
					
				}
				
			}
			SetCtrlAttribute (panelHandle_testmode2, TESTMODE2_HISTOGRAM, ATTR_DIMMED, 0);
			PlotXY (panelHandle_testmode2, TESTMODE2_HISTOGRAM, histogram_axis, histogram_array, 11,
					VAL_DOUBLE, VAL_SIZE_T, VAL_VERTICAL_BAR, VAL_EMPTY_SQUARE, VAL_SOLID, 1, VAL_RED);
			
			break;
		case EVENT_LOST_FOCUS:

			break;
		case EVENT_CLOSE:
			QuitUserInterface (0);
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
