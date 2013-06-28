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

#define  TESTMODEDU                       1       /* callback function: PanelTreeInit */
#define  TESTMODEDU_DUC7_EVENTS           2       /* control type: string, callback function: (none) */
#define  TESTMODEDU_DUC6_EVENTS           3       /* control type: string, callback function: (none) */
#define  TESTMODEDU_DUC5_EVENTS           4       /* control type: string, callback function: (none) */
#define  TESTMODEDU_DUC4_EVENTS           5       /* control type: string, callback function: (none) */
#define  TESTMODEDU_COMMANDBUTTON_12      6       /* control type: command, callback function: Quit */
#define  TESTMODEDU_COMMANDBUTTON_13      7       /* control type: command, callback function: Back */
#define  TESTMODEDU_COMMANDBUTTON_14      8       /* control type: command, callback function: Main */
#define  TESTMODEDU_DUC3_EVENTS           9       /* control type: string, callback function: (none) */
#define  TESTMODEDU_DUC7_BUTTON           10      /* control type: command, callback function: TestModeDUC */
#define  TESTMODEDU_DUC2_EVENTS           11      /* control type: string, callback function: (none) */
#define  TESTMODEDU_DUC6_BUTTON           12      /* control type: command, callback function: TestModeDUC */
#define  TESTMODEDU_DUC1_EVENTS           13      /* control type: string, callback function: (none) */
#define  TESTMODEDU_DUC5_BUTTON           14      /* control type: command, callback function: TestModeDUC */
#define  TESTMODEDU_DUC7_ERRORS           15      /* control type: string, callback function: (none) */
#define  TESTMODEDU_DUC6_ERRORS           16      /* control type: string, callback function: (none) */
#define  TESTMODEDU_DUC3_ERRORS           17      /* control type: string, callback function: (none) */
#define  TESTMODEDU_DUC4_ERRORS           18      /* control type: string, callback function: (none) */
#define  TESTMODEDU_DUC5_ERRORS           19      /* control type: string, callback function: (none) */
#define  TESTMODEDU_DUC2_ERRORS           20      /* control type: string, callback function: (none) */
#define  TESTMODEDU_DUC1_ERRORS           21      /* control type: string, callback function: (none) */
#define  TESTMODEDU_DUC0_ERRORS           22      /* control type: string, callback function: (none) */
#define  TESTMODEDU_DUC0_EVENTS           23      /* control type: string, callback function: (none) */
#define  TESTMODEDU_DUC4_BUTTON           24      /* control type: command, callback function: TestModeDUC */
#define  TESTMODEDU_DUC3_BUTTON           25      /* control type: command, callback function: TestModeDUC */
#define  TESTMODEDU_DUC2_BUTTON           26      /* control type: command, callback function: TestModeDUC */
#define  TESTMODEDU_DUC1_BUTTON           27      /* control type: command, callback function: TestModeDUC */
#define  TESTMODEDU_TEXTMSG               28      /* control type: textMsg, callback function: (none) */
#define  TESTMODEDU_DUC0_BUTTON           29      /* control type: command, callback function: TestModeDUC */
#define  TESTMODEDU_DECORATION            30      /* control type: deco, callback function: (none) */
#define  TESTMODEDU_DECORATION_9          31      /* control type: deco, callback function: (none) */
#define  TESTMODEDU_DECORATION_2          32      /* control type: deco, callback function: (none) */
#define  TESTMODEDU_DECORATION_3          33      /* control type: deco, callback function: (none) */
#define  TESTMODEDU_DECORATION_4          34      /* control type: deco, callback function: (none) */
#define  TESTMODEDU_DECORATION_5          35      /* control type: deco, callback function: (none) */
#define  TESTMODEDU_TEXTMSG_2             36      /* control type: textMsg, callback function: (none) */
#define  TESTMODEDU_DECORATION_6          37      /* control type: deco, callback function: (none) */
#define  TESTMODEDU_DECORATION_7          38      /* control type: deco, callback function: (none) */
#define  TESTMODEDU_DECORATION_8          39      /* control type: deco, callback function: (none) */
#define  TESTMODEDU_TREE                  40      /* control type: tree, callback function: TestModeDUCTree */


     /* Menu Bars, Menus, and Menu Items: */

          /* (no menu bars in the resource file) */


     /* Callback Prototypes: */

int  CVICALLBACK Back(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK Main(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK PanelTreeInit(int panel, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK Quit(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK TestModeDUC(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK TestModeDUCTree(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);


#ifdef __cplusplus
    }
#endif
