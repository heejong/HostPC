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

#define  SYSCONFIG                        1
#define  SYSCONFIG_COMMANDBUTTON_12       2       /* control type: command, callback function: SaveSetup */
#define  SYSCONFIG_COMMANDBUTTON_13       3       /* control type: command, callback function: Quit */
#define  SYSCONFIG_COMMANDBUTTON_14       4       /* control type: command, callback function: Back */
#define  SYSCONFIG_COMMANDBUTTON_15       5       /* control type: command, callback function: Main */
#define  SYSCONFIG_TEXTMSG                6       /* control type: textMsg, callback function: (none) */
#define  SYSCONFIG_DECORATION_9           7       /* control type: deco, callback function: (none) */
#define  SYSCONFIG_TAB                    8       /* control type: tab, callback function: (none) */

     /* tab page panel controls */
#define  TABPANEL_SUBTITLE2               2       /* control type: textMsg, callback function: (none) */
#define  TABPANEL_COINCIDENCE_64_RING     3       /* control type: ring, callback function: (none) */
#define  TABPANEL_SUBTITLE1               4       /* control type: textMsg, callback function: (none) */
#define  TABPANEL_COINCIDENCE_32_RING     5       /* control type: ring, callback function: (none) */
#define  TABPANEL_FILETEXT                6       /* control type: string, callback function: (none) */
#define  TABPANEL_DECORATION_17           7       /* control type: deco, callback function: (none) */
#define  TABPANEL_LOAD                    8       /* control type: command, callback function: (none) */
#define  TABPANEL_DECORATION_16           9       /* control type: deco, callback function: (none) */
#define  TABPANEL_SINGLEEVENT_RING        10      /* control type: ring, callback function: SingleEventChange */

     /* tab page panel controls */
#define  TABPANEL_2_TREE                  2       /* control type: tree, callback function: SysConfigTree */


     /* Menu Bars, Menus, and Menu Items: */

          /* (no menu bars in the resource file) */


     /* Callback Prototypes: */

int  CVICALLBACK Back(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK Main(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK Quit(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK SaveSetup(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK SingleEventChange(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK SysConfigTree(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);


#ifdef __cplusplus
    }
#endif
