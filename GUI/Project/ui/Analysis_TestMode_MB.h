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

#define  TESTMODEMB                       1       /* callback function: Init */
#define  TESTMODEMB_STRING_24             2       /* control type: string, callback function: (none) */
#define  TESTMODEMB_STRING_22             3       /* control type: string, callback function: (none) */
#define  TESTMODEMB_STRING_20             4       /* control type: string, callback function: (none) */
#define  TESTMODEMB_STRING_18             5       /* control type: string, callback function: (none) */
#define  TESTMODEMB_COMMANDBUTTON_12      6       /* control type: command, callback function: Quit */
#define  TESTMODEMB_COMMANDBUTTON_13      7       /* control type: command, callback function: Back */
#define  TESTMODEMB_SPLITTER_2            8       /* control type: splitter, callback function: (none) */
#define  TESTMODEMB_COMMANDBUTTON_14      9       /* control type: command, callback function: Main */
#define  TESTMODEMB_STRING_16             10      /* control type: string, callback function: (none) */
#define  TESTMODEMB_COMMANDBUTTON_11      11      /* control type: command, callback function: (none) */
#define  TESTMODEMB_STRING_14             12      /* control type: string, callback function: (none) */
#define  TESTMODEMB_COMMANDBUTTON_10      13      /* control type: command, callback function: (none) */
#define  TESTMODEMB_STRING_12             14      /* control type: string, callback function: (none) */
#define  TESTMODEMB_COMMANDBUTTON_9       15      /* control type: command, callback function: (none) */
#define  TESTMODEMB_STRING_32             16      /* control type: string, callback function: (none) */
#define  TESTMODEMB_STRING_31             17      /* control type: string, callback function: (none) */
#define  TESTMODEMB_STRING_30             18      /* control type: string, callback function: (none) */
#define  TESTMODEMB_STRING_29             19      /* control type: string, callback function: (none) */
#define  TESTMODEMB_STRING_28             20      /* control type: string, callback function: (none) */
#define  TESTMODEMB_STRING_27             21      /* control type: string, callback function: (none) */
#define  TESTMODEMB_STRING_26             22      /* control type: string, callback function: (none) */
#define  TESTMODEMB_STRING_25             23      /* control type: string, callback function: (none) */
#define  TESTMODEMB_STRING_11             24      /* control type: string, callback function: (none) */
#define  TESTMODEMB_COMMANDBUTTON_8       25      /* control type: command, callback function: (none) */
#define  TESTMODEMB_COMMANDBUTTON_7       26      /* control type: command, callback function: (none) */
#define  TESTMODEMB_COMMANDBUTTON_6       27      /* control type: command, callback function: (none) */
#define  TESTMODEMB_COMMANDBUTTON_5       28      /* control type: command, callback function: (none) */
#define  TESTMODEMB_TEXTMSG               29      /* control type: textMsg, callback function: (none) */
#define  TESTMODEMB_COMMANDBUTTON_4       30      /* control type: command, callback function: TestModeMB */
#define  TESTMODEMB_DECORATION            31      /* control type: deco, callback function: (none) */
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
int  CVICALLBACK Init(int panel, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK Main(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK Quit(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK TestModeMB(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);


#ifdef __cplusplus
    }
#endif
