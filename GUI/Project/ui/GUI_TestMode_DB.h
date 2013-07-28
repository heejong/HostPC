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

#define  TESTMODEDB                       1       /* callback function: PanelTreeInit */
#define  TESTMODEDB_EVENTS_7              2       /* control type: string, callback function: (none) */
#define  TESTMODEDB_EVENTS_6              3       /* control type: string, callback function: (none) */
#define  TESTMODEDB_EVENTS_5              4       /* control type: string, callback function: (none) */
#define  TESTMODEDB_EVENTS_4              5       /* control type: string, callback function: (none) */
#define  TESTMODEDB_COMMANDBUTTON_12      6       /* control type: command, callback function: Quit */
#define  TESTMODEDB_COMMANDBUTTON_13      7       /* control type: command, callback function: Back */
#define  TESTMODEDB_COMMANDBUTTON_14      8       /* control type: command, callback function: Main */
#define  TESTMODEDB_EVENTS_3              9       /* control type: string, callback function: (none) */
#define  TESTMODEDB_BUTTON_7              10      /* control type: command, callback function: TestModeDB */
#define  TESTMODEDB_EVENTS_2              11      /* control type: string, callback function: (none) */
#define  TESTMODEDB_BUTTON_6              12      /* control type: command, callback function: TestModeDB */
#define  TESTMODEDB_EVENTS_1              13      /* control type: string, callback function: (none) */
#define  TESTMODEDB_BUTTON_5              14      /* control type: command, callback function: TestModeDB */
#define  TESTMODEDB_ERRORS_7              15      /* control type: string, callback function: (none) */
#define  TESTMODEDB_ERRORS_6              16      /* control type: string, callback function: (none) */
#define  TESTMODEDB_ERRORS_3              17      /* control type: string, callback function: (none) */
#define  TESTMODEDB_ERRORS_4              18      /* control type: string, callback function: (none) */
#define  TESTMODEDB_ERRORS_5              19      /* control type: string, callback function: (none) */
#define  TESTMODEDB_ERRORS_2              20      /* control type: string, callback function: (none) */
#define  TESTMODEDB_ERRORS_1              21      /* control type: string, callback function: (none) */
#define  TESTMODEDB_ERRORS_0              22      /* control type: string, callback function: (none) */
#define  TESTMODEDB_EVENTS_0              23      /* control type: string, callback function: (none) */
#define  TESTMODEDB_BUTTON_4              24      /* control type: command, callback function: TestModeDB */
#define  TESTMODEDB_BUTTON_3              25      /* control type: command, callback function: TestModeDB */
#define  TESTMODEDB_BUTTON_2              26      /* control type: command, callback function: TestModeDB */
#define  TESTMODEDB_BUTTON_1              27      /* control type: command, callback function: TestModeDB */
#define  TESTMODEDB_TEXTMSG               28      /* control type: textMsg, callback function: (none) */
#define  TESTMODEDB_BUTTON_0              29      /* control type: command, callback function: TestModeDB */
#define  TESTMODEDB_DECORATION            30      /* control type: deco, callback function: (none) */
#define  TESTMODEDB_DECORATION_9          31      /* control type: deco, callback function: (none) */
#define  TESTMODEDB_DECORATION_2          32      /* control type: deco, callback function: (none) */
#define  TESTMODEDB_DECORATION_3          33      /* control type: deco, callback function: (none) */
#define  TESTMODEDB_DECORATION_4          34      /* control type: deco, callback function: (none) */
#define  TESTMODEDB_DECORATION_5          35      /* control type: deco, callback function: (none) */
#define  TESTMODEDB_TEXTMSG_2             36      /* control type: textMsg, callback function: (none) */
#define  TESTMODEDB_DECORATION_6          37      /* control type: deco, callback function: (none) */
#define  TESTMODEDB_DECORATION_7          38      /* control type: deco, callback function: (none) */
#define  TESTMODEDB_DECORATION_8          39      /* control type: deco, callback function: (none) */
#define  TESTMODEDB_TREE                  40      /* control type: tree, callback function: TestModeDBTree */


     /* Menu Bars, Menus, and Menu Items: */

          /* (no menu bars in the resource file) */


     /* Callback Prototypes: */

int  CVICALLBACK Back(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK Main(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK PanelTreeInit(int panel, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK Quit(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK TestModeDB(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK TestModeDBTree(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);


#ifdef __cplusplus
    }
#endif
