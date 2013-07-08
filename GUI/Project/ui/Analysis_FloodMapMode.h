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

#define  FMMODE                           1
#define  FMMODE_TAB                       2       /* control type: tab, callback function: (none) */
#define  FMMODE_PICTURE                   3       /* control type: picture, callback function: (none) */
#define  FMMODE_SAVE_OUTPUT               4       /* control type: command, callback function: SaveOutput */
#define  FMMODE_SAVE_PLOT                 5       /* control type: command, callback function: SavePlot */
#define  FMMODE_COMMANDBUTTON_3           6       /* control type: command, callback function: Quit */
#define  FMMODE_COMMANDBUTTON             7       /* control type: command, callback function: Back */
#define  FMMODE_COMMANDBUTTON_2           8       /* control type: command, callback function: Main */
#define  FMMODE_DECORATION_9              9       /* control type: deco, callback function: (none) */
#define  FMMODE_TREE                      10      /* control type: tree, callback function: FloodMapModeTree */
#define  FMMODE_DECORATION                11      /* control type: deco, callback function: (none) */

     /* tab page panel controls */
#define  TABPANEL_TEXTMSG                 2       /* control type: textMsg, callback function: (none) */
#define  TABPANEL_TEXTMSG_3               3       /* control type: textMsg, callback function: (none) */
#define  TABPANEL_TEXTMSG_2               4       /* control type: textMsg, callback function: (none) */
#define  TABPANEL_PICTURE_2               5       /* control type: picture, callback function: (none) */

     /* tab page panel controls */
#define  TABPANEL_2_TEXTMSG               2       /* control type: textMsg, callback function: (none) */
#define  TABPANEL_2_TEXTMSG_3             3       /* control type: textMsg, callback function: (none) */
#define  TABPANEL_2_TEXTMSG_2             4       /* control type: textMsg, callback function: (none) */
#define  TABPANEL_2_PICTURE_2             5       /* control type: picture, callback function: (none) */


     /* Menu Bars, Menus, and Menu Items: */

          /* (no menu bars in the resource file) */


     /* Callback Prototypes: */

int  CVICALLBACK Back(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK FloodMapModeTree(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK Main(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK Quit(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK SaveOutput(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK SavePlot(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);


#ifdef __cplusplus
    }
#endif
