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

#define  TESTMODE2                        1       /* callback function: InitializeTestMode2 */
#define  TESTMODE2_EXPECTED_VALUE         2       /* control type: string, callback function: (none) */
#define  TESTMODE2_HISTOGRAM              3       /* control type: graph, callback function: (none) */
#define  TESTMODE2_SAVE_OUTPUT            4       /* control type: command, callback function: SaveOutput */
#define  TESTMODE2_SAVE_PLOT              5       /* control type: command, callback function: SavePlot */
#define  TESTMODE2_COMMANDBUTTON_12       6       /* control type: command, callback function: Quit */
#define  TESTMODE2_COMMANDBUTTON_13       7       /* control type: command, callback function: Back */
#define  TESTMODE2_COMMANDBUTTON_14       8       /* control type: command, callback function: Main */
#define  TESTMODE2_DECORATION_9           9       /* control type: deco, callback function: (none) */
#define  TESTMODE2_TREE                   10      /* control type: tree, callback function: EnergyModeMBTree */
#define  TESTMODE2_DECORATION             11      /* control type: deco, callback function: (none) */


     /* Menu Bars, Menus, and Menu Items: */

#define  MENUBAR                          1
#define  MENUBAR_MENU1                    2


     /* Callback Prototypes: */

int  CVICALLBACK Back(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK EnergyModeMBTree(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK InitializeTestMode2(int panel, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK Main(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK Quit(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK SaveOutput(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK SavePlot(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);


#ifdef __cplusplus
    }
#endif
