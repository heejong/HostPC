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

#define  FMMODEMB                         1
#define  FMMODEMB_STRING_24               2       /* control type: string, callback function: (none) */
#define  FMMODEMB_STRING_22               3       /* control type: string, callback function: (none) */
#define  FMMODEMB_STRING_20               4       /* control type: string, callback function: (none) */
#define  FMMODEMB_STRING_18               5       /* control type: string, callback function: (none) */
#define  FMMODEMB_STRING_16               6       /* control type: string, callback function: (none) */
#define  FMMODEMB_COMMANDBUTTON_11        7       /* control type: command, callback function: (none) */
#define  FMMODEMB_STRING_14               8       /* control type: string, callback function: (none) */
#define  FMMODEMB_COMMANDBUTTON_10        9       /* control type: command, callback function: (none) */
#define  FMMODEMB_STRING_12               10      /* control type: string, callback function: (none) */
#define  FMMODEMB_COMMANDBUTTON_9         11      /* control type: command, callback function: (none) */
#define  FMMODEMB_STRING_11               12      /* control type: string, callback function: (none) */
#define  FMMODEMB_COMMANDBUTTON_8         13      /* control type: command, callback function: (none) */
#define  FMMODEMB_COMMANDBUTTON_7         14      /* control type: command, callback function: (none) */
#define  FMMODEMB_COMMANDBUTTON           15      /* control type: command, callback function: Back */
#define  FMMODEMB_COMMANDBUTTON_6         16      /* control type: command, callback function: (none) */
#define  FMMODEMB_COMMANDBUTTON_2         17      /* control type: command, callback function: Main */
#define  FMMODEMB_COMMANDBUTTON_3         18      /* control type: command, callback function: Quit */
#define  FMMODEMB_COMMANDBUTTON_5         19      /* control type: command, callback function: (none) */
#define  FMMODEMB_TEXTMSG                 20      /* control type: textMsg, callback function: (none) */
#define  FMMODEMB_COMMANDBUTTON_4         21      /* control type: command, callback function: FloodMapModeMB */
#define  FMMODEMB_DECORATION              22      /* control type: deco, callback function: (none) */
#define  FMMODEMB_DECORATION_2            23      /* control type: deco, callback function: (none) */
#define  FMMODEMB_DECORATION_3            24      /* control type: deco, callback function: (none) */
#define  FMMODEMB_DECORATION_4            25      /* control type: deco, callback function: (none) */
#define  FMMODEMB_DECORATION_5            26      /* control type: deco, callback function: (none) */
#define  FMMODEMB_DECORATION_6            27      /* control type: deco, callback function: (none) */
#define  FMMODEMB_DECORATION_7            28      /* control type: deco, callback function: (none) */
#define  FMMODEMB_DECORATION_8            29      /* control type: deco, callback function: (none) */
#define  FMMODEMB_SPLITTER                30      /* control type: splitter, callback function: (none) */


     /* Menu Bars, Menus, and Menu Items: */

          /* (no menu bars in the resource file) */


     /* Callback Prototypes: */

int  CVICALLBACK Back(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK FloodMapModeMB(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK Main(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK Quit(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);


#ifdef __cplusplus
    }
#endif
