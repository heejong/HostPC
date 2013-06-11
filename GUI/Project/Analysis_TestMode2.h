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
#define  TESTMODE2_OKBUTTON               4       /* control type: command, callback function: Okay */
#define  TESTMODE2_SAVE_OUTPUT            5       /* control type: command, callback function: SaveOutput */
#define  TESTMODE2_SAVE_PLOT              6       /* control type: command, callback function: SavePlot */


     /* Menu Bars, Menus, and Menu Items: */

#define  MENUBAR                          1
#define  MENUBAR_MENU1                    2


     /* Callback Prototypes: */

int  CVICALLBACK InitializeTestMode2(int panel, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK Okay(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK SaveOutput(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK SavePlot(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);


#ifdef __cplusplus
    }
#endif
