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

#define  USERMODEMB                       1
#define  USERMODEMB_STRING_24             2       /* control type: string, callback function: (none) */
#define  USERMODEMB_STRING_22             3       /* control type: string, callback function: (none) */
#define  USERMODEMB_STRING_20             4       /* control type: string, callback function: (none) */
#define  USERMODEMB_STRING_18             5       /* control type: string, callback function: (none) */
#define  USERMODEMB_COMMANDBUTTON_12      6       /* control type: command, callback function: Quit */
#define  USERMODEMB_COMMANDBUTTON_13      7       /* control type: command, callback function: Back */
#define  USERMODEMB_SPLITTER_2            8       /* control type: splitter, callback function: (none) */
#define  USERMODEMB_COMMANDBUTTON_14      9       /* control type: command, callback function: Main */
#define  USERMODEMB_STRING_16             10      /* control type: string, callback function: (none) */
#define  USERMODEMB_COMMANDBUTTON_11      11      /* control type: command, callback function: (none) */
#define  USERMODEMB_STRING_14             12      /* control type: string, callback function: (none) */
#define  USERMODEMB_COMMANDBUTTON_10      13      /* control type: command, callback function: (none) */
#define  USERMODEMB_STRING_12             14      /* control type: string, callback function: (none) */
#define  USERMODEMB_COMMANDBUTTON_9       15      /* control type: command, callback function: (none) */
#define  USERMODEMB_STRING_11             16      /* control type: string, callback function: (none) */
#define  USERMODEMB_COMMANDBUTTON_8       17      /* control type: command, callback function: (none) */
#define  USERMODEMB_COMMANDBUTTON_7       18      /* control type: command, callback function: (none) */
#define  USERMODEMB_COMMANDBUTTON_6       19      /* control type: command, callback function: (none) */
#define  USERMODEMB_COMMANDBUTTON_5       20      /* control type: command, callback function: (none) */
#define  USERMODEMB_TEXTMSG               21      /* control type: textMsg, callback function: (none) */
#define  USERMODEMB_COMMANDBUTTON_4       22      /* control type: command, callback function: UserModeMB */
#define  USERMODEMB_DECORATION            23      /* control type: deco, callback function: (none) */
#define  USERMODEMB_DECORATION_2          24      /* control type: deco, callback function: (none) */
#define  USERMODEMB_DECORATION_3          25      /* control type: deco, callback function: (none) */
#define  USERMODEMB_DECORATION_4          26      /* control type: deco, callback function: (none) */
#define  USERMODEMB_DECORATION_5          27      /* control type: deco, callback function: (none) */
#define  USERMODEMB_DECORATION_6          28      /* control type: deco, callback function: (none) */
#define  USERMODEMB_DECORATION_7          29      /* control type: deco, callback function: (none) */
#define  USERMODEMB_DECORATION_8          30      /* control type: deco, callback function: (none) */
#define  USERMODEMB_TREE                  31      /* control type: tree, callback function: (none) */


     /* Menu Bars, Menus, and Menu Items: */

          /* (no menu bars in the resource file) */


     /* Callback Prototypes: */

int  CVICALLBACK Back(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK Main(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK Quit(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK UserModeMB(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);


#ifdef __cplusplus
    }
#endif
