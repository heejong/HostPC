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

#define  OMODEDB                          1       /* callback function: PanelTreeInit */
#define  OMODEDB_EVENTS_7                 2       /* control type: string, callback function: (none) */
#define  OMODEDB_EVENTS_6                 3       /* control type: string, callback function: (none) */
#define  OMODEDB_EVENTS_5                 4       /* control type: string, callback function: (none) */
#define  OMODEDB_EVENTS_4                 5       /* control type: string, callback function: (none) */
#define  OMODEDB_COMMANDBUTTON_12         6       /* control type: command, callback function: Quit */
#define  OMODEDB_COMMANDBUTTON_13         7       /* control type: command, callback function: Back */
#define  OMODEDB_COMMANDBUTTON_14         8       /* control type: command, callback function: Main */
#define  OMODEDB_EVENTS_3                 9       /* control type: string, callback function: (none) */
#define  OMODEDB_BUTTON_7                 10      /* control type: command, callback function: OscilloscopeModeDB */
#define  OMODEDB_EVENTS_2                 11      /* control type: string, callback function: (none) */
#define  OMODEDB_BUTTON_6                 12      /* control type: command, callback function: OscilloscopeModeDB */
#define  OMODEDB_EVENTS_1                 13      /* control type: string, callback function: (none) */
#define  OMODEDB_BUTTON_5                 14      /* control type: command, callback function: OscilloscopeModeDB */
#define  OMODEDB_EVENTS_0                 15      /* control type: string, callback function: (none) */
#define  OMODEDB_BUTTON_4                 16      /* control type: command, callback function: OscilloscopeModeDB */
#define  OMODEDB_BUTTON_3                 17      /* control type: command, callback function: OscilloscopeModeDB */
#define  OMODEDB_BUTTON_2                 18      /* control type: command, callback function: OscilloscopeModeDB */
#define  OMODEDB_BUTTON_1                 19      /* control type: command, callback function: OscilloscopeModeDB */
#define  OMODEDB_TEXTMSG                  20      /* control type: textMsg, callback function: (none) */
#define  OMODEDB_BUTTON_0                 21      /* control type: command, callback function: OscilloscopeModeDB */
#define  OMODEDB_DECORATION               22      /* control type: deco, callback function: (none) */
#define  OMODEDB_DECORATION_2             23      /* control type: deco, callback function: (none) */
#define  OMODEDB_DECORATION_3             24      /* control type: deco, callback function: (none) */
#define  OMODEDB_DECORATION_4             25      /* control type: deco, callback function: (none) */
#define  OMODEDB_DECORATION_5             26      /* control type: deco, callback function: (none) */
#define  OMODEDB_DECORATION_6             27      /* control type: deco, callback function: (none) */
#define  OMODEDB_DECORATION_7             28      /* control type: deco, callback function: (none) */
#define  OMODEDB_DECORATION_8             29      /* control type: deco, callback function: (none) */
#define  OMODEDB_TREE                     30      /* control type: tree, callback function: OscilloscopeModeDBTree */
#define  OMODEDB_DECORATION_9             31      /* control type: deco, callback function: (none) */


     /* Menu Bars, Menus, and Menu Items: */

          /* (no menu bars in the resource file) */


     /* Callback Prototypes: */

int  CVICALLBACK Back(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK Main(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK OscilloscopeModeDB(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK OscilloscopeModeDBTree(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK PanelTreeInit(int panel, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK Quit(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);


#ifdef __cplusplus
    }
#endif
