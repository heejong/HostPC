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
#define  TESTMODEMB_MB7_EVENTS            2       /* control type: string, callback function: (none) */
#define  TESTMODEMB_MB6_EVENTS            3       /* control type: string, callback function: (none) */
#define  TESTMODEMB_MB5_EVENTS            4       /* control type: string, callback function: (none) */
#define  TESTMODEMB_MB4_EVENTS            5       /* control type: string, callback function: (none) */
#define  TESTMODEMB_COMMANDBUTTON_12      6       /* control type: command, callback function: Quit */
#define  TESTMODEMB_COMMANDBUTTON_13      7       /* control type: command, callback function: Back */
#define  TESTMODEMB_COMMANDBUTTON_14      8       /* control type: command, callback function: Main */
#define  TESTMODEMB_MB3_EVENTS            9       /* control type: string, callback function: (none) */
#define  TESTMODEMB_MB7_BUTTON            10      /* control type: command, callback function: TestModeMB */
#define  TESTMODEMB_MB2_EVENTS            11      /* control type: string, callback function: (none) */
#define  TESTMODEMB_MB6_BUTTON            12      /* control type: command, callback function: TestModeMB */
#define  TESTMODEMB_MB1_EVENTS            13      /* control type: string, callback function: (none) */
#define  TESTMODEMB_MB5_BUTTON            14      /* control type: command, callback function: TestModeMB */
#define  TESTMODEMB_MB7_ERRORS            15      /* control type: string, callback function: (none) */
#define  TESTMODEMB_MB6_ERRORS            16      /* control type: string, callback function: (none) */
#define  TESTMODEMB_MB3_ERRORS            17      /* control type: string, callback function: (none) */
#define  TESTMODEMB_MB4_ERRORS            18      /* control type: string, callback function: (none) */
#define  TESTMODEMB_MB5_ERRORS            19      /* control type: string, callback function: (none) */
#define  TESTMODEMB_MB2_ERRORS            20      /* control type: string, callback function: (none) */
#define  TESTMODEMB_MB1_ERRORS            21      /* control type: string, callback function: (none) */
#define  TESTMODEMB_MB0_ERRORS            22      /* control type: string, callback function: (none) */
#define  TESTMODEMB_MB0_EVENTS            23      /* control type: string, callback function: (none) */
#define  TESTMODEMB_MB4_BUTTON            24      /* control type: command, callback function: TestModeMB */
#define  TESTMODEMB_MB3_BUTTON            25      /* control type: command, callback function: TestModeMB */
#define  TESTMODEMB_MB2_BUTTON            26      /* control type: command, callback function: TestModeMB */
#define  TESTMODEMB_MB1_BUTTON            27      /* control type: command, callback function: TestModeMB */
#define  TESTMODEMB_TEXTMSG               28      /* control type: textMsg, callback function: (none) */
#define  TESTMODEMB_MB0_BUTTON            29      /* control type: command, callback function: TestModeMB */
#define  TESTMODEMB_DECORATION            30      /* control type: deco, callback function: (none) */
#define  TESTMODEMB_DECORATION_9          31      /* control type: deco, callback function: (none) */
#define  TESTMODEMB_DECORATION_2          32      /* control type: deco, callback function: (none) */
#define  TESTMODEMB_DECORATION_3          33      /* control type: deco, callback function: (none) */
#define  TESTMODEMB_DECORATION_4          34      /* control type: deco, callback function: (none) */
#define  TESTMODEMB_DECORATION_5          35      /* control type: deco, callback function: (none) */
#define  TESTMODEMB_TEXTMSG_2             36      /* control type: textMsg, callback function: (none) */
#define  TESTMODEMB_DECORATION_6          37      /* control type: deco, callback function: (none) */
#define  TESTMODEMB_DECORATION_7          38      /* control type: deco, callback function: (none) */
#define  TESTMODEMB_DECORATION_8          39      /* control type: deco, callback function: (none) */
#define  TESTMODEMB_TREE                  40      /* control type: tree, callback function: (none) */


     /* Menu Bars, Menus, and Menu Items: */

          /* (no menu bars in the resource file) */


     /* Callback Prototypes: */

int  CVICALLBACK Back(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK Main(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK PanelTreeInit(int panel, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK Quit(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK TestModeMB(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);


#ifdef __cplusplus
    }
#endif
