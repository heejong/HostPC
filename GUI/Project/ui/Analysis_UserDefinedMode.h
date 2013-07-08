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

#define  USERMODE                         1       /* callback function: InitializeUserMode */
#define  USERMODE_HISTOGRAM               2       /* control type: graph, callback function: (none) */
#define  USERMODE_SAVE_OUTPUT             3       /* control type: command, callback function: SaveOutput */
#define  USERMODE_SAVE_PLOT               4       /* control type: command, callback function: SavePlot */
#define  USERMODE_COMMANDBUTTON_12        5       /* control type: command, callback function: Quit */
#define  USERMODE_COMMANDBUTTON_13        6       /* control type: command, callback function: Back */
#define  USERMODE_COMMANDBUTTON_14        7       /* control type: command, callback function: Main */
#define  USERMODE_DECORATION_9            8       /* control type: deco, callback function: (none) */
#define  USERMODE_TREE                    9       /* control type: tree, callback function: UserModeTree */
#define  USERMODE_DECORATION              10      /* control type: deco, callback function: (none) */


     /* Menu Bars, Menus, and Menu Items: */

          /* (no menu bars in the resource file) */


     /* Callback Prototypes: */

int  CVICALLBACK Back(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK InitializeUserMode(int panel, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK Main(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK Quit(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK SaveOutput(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK SavePlot(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK UserModeTree(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);


#ifdef __cplusplus
    }
#endif
