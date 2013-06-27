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

#define  TESTMODEMB                       1       /* callback function: PanelTreeInit */
#define  TESTMODEMB_EVENTS_7              2       /* control type: string, callback function: (none) */
#define  TESTMODEMB_EVENTS_6              3       /* control type: string, callback function: (none) */
#define  TESTMODEMB_EVENTS_5              4       /* control type: string, callback function: (none) */
#define  TESTMODEMB_EVENTS_4              5       /* control type: string, callback function: (none) */
#define  TESTMODEMB_COMMANDBUTTON_12      6       /* control type: command, callback function: Quit */
#define  TESTMODEMB_COMMANDBUTTON_13      7       /* control type: command, callback function: Back */
#define  TESTMODEMB_COMMANDBUTTON_14      8       /* control type: command, callback function: Main */
#define  TESTMODEMB_EVENTS_3              9       /* control type: string, callback function: (none) */
#define  TESTMODEMB_BUTTON_7              10      /* control type: command, callback function: TestModeMB */
#define  TESTMODEMB_EVENTS_2              11      /* control type: string, callback function: (none) */
#define  TESTMODEMB_BUTTON_6              12      /* control type: command, callback function: TestModeMB */
#define  TESTMODEMB_EVENTS_1              13      /* control type: string, callback function: (none) */
#define  TESTMODEMB_BUTTON_5              14      /* control type: command, callback function: TestModeMB */
#define  TESTMODEMB_ERRORS_7              15      /* control type: string, callback function: (none) */
#define  TESTMODEMB_ERRORS_6              16      /* control type: string, callback function: (none) */
#define  TESTMODEMB_ERRORS_3              17      /* control type: string, callback function: (none) */
#define  TESTMODEMB_ERRORS_4              18      /* control type: string, callback function: (none) */
#define  TESTMODEMB_ERRORS_5              19      /* control type: string, callback function: (none) */
#define  TESTMODEMB_ERRORS_2              20      /* control type: string, callback function: (none) */
#define  TESTMODEMB_ERRORS_1              21      /* control type: string, callback function: (none) */
#define  TESTMODEMB_ERRORS_0              22      /* control type: string, callback function: (none) */
#define  TESTMODEMB_EVENTS_0              23      /* control type: string, callback function: (none) */
#define  TESTMODEMB_BUTTON_4              24      /* control type: command, callback function: TestModeMB */
#define  TESTMODEMB_BUTTON_3              25      /* control type: command, callback function: TestModeMB */
#define  TESTMODEMB_BUTTON_2              26      /* control type: command, callback function: TestModeMB */
#define  TESTMODEMB_BUTTON_1              27      /* control type: command, callback function: TestModeMB */
#define  TESTMODEMB_TEXT_TITLE            28      /* control type: textMsg, callback function: (none) */
#define  TESTMODEMB_BUTTON_0              29      /* control type: command, callback function: TestModeMB */
#define  TESTMODEMB_DECORATION_0          30      /* control type: deco, callback function: (none) */
#define  TESTMODEMB_DECORATION_9          31      /* control type: deco, callback function: (none) */
#define  TESTMODEMB_DECORATION_1          32      /* control type: deco, callback function: (none) */
#define  TESTMODEMB_DECORATION_2          33      /* control type: deco, callback function: (none) */
#define  TESTMODEMB_DECORATION_3          34      /* control type: deco, callback function: (none) */
#define  TESTMODEMB_DECORATION_4          35      /* control type: deco, callback function: (none) */
#define  TESTMODEMB_TEXT_INSTRUCTION      36      /* control type: textMsg, callback function: (none) */
#define  TESTMODEMB_DECORATION_5          37      /* control type: deco, callback function: (none) */
#define  TESTMODEMB_DECORATION_6          38      /* control type: deco, callback function: (none) */
#define  TESTMODEMB_DECORATION_7          39      /* control type: deco, callback function: (none) */
#define  TESTMODEMB_TREE                  40      /* control type: tree, callback function: InstrumentTreeControl */


     /* Menu Bars, Menus, and Menu Items: */

          /* (no menu bars in the resource file) */


     /* Callback Prototypes: */

int  CVICALLBACK Back(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK InstrumentTreeControl(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK Main(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK PanelTreeInit(int panel, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK Quit(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK TestModeMB(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);


#ifdef __cplusplus
    }
#endif
