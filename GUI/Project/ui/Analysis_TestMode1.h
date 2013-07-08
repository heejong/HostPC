/**************************************************************************/
/* LabWindows/CVI User Interface Resource (UIR) Include File              */
/* Copyright (c) National Instruments 2013. All Rights Reserved.          */
/*                                                                        */
/* WARNING: Do not add to, delete from, or otherwise modify the contents  */
/*          of this include file.                                         */
/**************************************************************************/

#include <userint.h>

#ifdef __cplusplus
    extern "C" {
#endif

     /* Panels and Controls: */

#define  TESTMODE1                        1       /* callback function: InitializeTestMode1 */
#define  TESTMODE1_EXPECTED_VALUE         2       /* control type: string, callback function: (none) */
#define  TESTMODE1_HISTOGRAM              3       /* control type: graph, callback function: (none) */
#define  TESTMODE1_SAVE_OUTPUT            4       /* control type: command, callback function: SaveOutput */
#define  TESTMODE1_SAVE_PLOT              5       /* control type: command, callback function: SavePlot */
#define  TESTMODE1_COMMANDBUTTON_12       6       /* control type: command, callback function: Quit */
#define  TESTMODE1_COMMANDBUTTON_13       7       /* control type: command, callback function: Back */
#define  TESTMODE1_COMMANDBUTTON_14       8       /* control type: command, callback function: Main */
#define  TESTMODE1_DECORATION_9           9       /* control type: deco, callback function: (none) */
#define  TESTMODE1_TREE                   10      /* control type: tree, callback function: TestMode1Tree */
#define  TESTMODE1_DECORATION             11      /* control type: deco, callback function: (none) */


     /* Menu Bars, Menus, and Menu Items: */

          /* (no menu bars in the resource file) */


     /* Callback Prototypes: */

int  CVICALLBACK Back(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK InitializeTestMode1(int panel, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK Main(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK Quit(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK SaveOutput(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK SavePlot(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK TestMode1Tree(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);


#ifdef __cplusplus
    }
#endif
