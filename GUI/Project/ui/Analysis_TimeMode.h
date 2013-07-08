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

#define  TIMEMODE                         1
#define  TIMEMODE_TAB                     2       /* control type: tab, callback function: (none) */
#define  TIMEMODE_PICTURE                 3       /* control type: picture, callback function: (none) */
#define  TIMEMODE_SAVE_OUTPUT             4       /* control type: command, callback function: SaveOutput */
#define  TIMEMODE_SAVE_PLOT               5       /* control type: command, callback function: SavePlot */
#define  TIMEMODE_COMMANDBUTTON_3         6       /* control type: command, callback function: Quit */
#define  TIMEMODE_COMMANDBUTTON           7       /* control type: command, callback function: Back */
#define  TIMEMODE_COMMANDBUTTON_2         8       /* control type: command, callback function: Main */
#define  TIMEMODE_DECORATION_9            9       /* control type: deco, callback function: (none) */
#define  TIMEMODE_DECORATION              10      /* control type: deco, callback function: (none) */
#define  TIMEMODE_TREE                    11      /* control type: tree, callback function: TimeModeTree */

     /* tab page panel controls */
#define  TABPANEL_PICTURE_4               2       /* control type: picture, callback function: (none) */

     /* tab page panel controls */
#define  TABPANEL_2_PICTURE_4             2       /* control type: picture, callback function: (none) */


     /* Menu Bars, Menus, and Menu Items: */

          /* (no menu bars in the resource file) */


     /* Callback Prototypes: */

int  CVICALLBACK Back(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK Main(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK Quit(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK SaveOutput(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK SavePlot(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK TimeModeTree(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);


#ifdef __cplusplus
    }
#endif
