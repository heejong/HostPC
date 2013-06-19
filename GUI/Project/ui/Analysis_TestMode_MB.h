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
#define  TESTMODEMB_COMMANDBUTTON_14      8       /* control type: command, callback function: Main */
#define  TESTMODEMB_STRING_16             9       /* control type: string, callback function: (none) */
#define  TESTMODEMB_COMMANDBUTTON_11      10      /* control type: command, callback function: (none) */
#define  TESTMODEMB_STRING_14             11      /* control type: string, callback function: (none) */
#define  TESTMODEMB_COMMANDBUTTON_10      12      /* control type: command, callback function: (none) */
#define  TESTMODEMB_STRING_12             13      /* control type: string, callback function: (none) */
#define  TESTMODEMB_COMMANDBUTTON_9       14      /* control type: command, callback function: (none) */
#define  TESTMODEMB_STRING_32             15      /* control type: string, callback function: (none) */
#define  TESTMODEMB_STRING_31             16      /* control type: string, callback function: (none) */
#define  TESTMODEMB_STRING_30             17      /* control type: string, callback function: (none) */
#define  TESTMODEMB_STRING_29             18      /* control type: string, callback function: (none) */
#define  TESTMODEMB_STRING_28             19      /* control type: string, callback function: (none) */
#define  TESTMODEMB_STRING_27             20      /* control type: string, callback function: (none) */
#define  TESTMODEMB_STRING_26             21      /* control type: string, callback function: (none) */
#define  TESTMODEMB_STRING_25             22      /* control type: string, callback function: (none) */
#define  TESTMODEMB_STRING_11             23      /* control type: string, callback function: (none) */
#define  TESTMODEMB_COMMANDBUTTON_8       24      /* control type: command, callback function: (none) */
#define  TESTMODEMB_COMMANDBUTTON_7       25      /* control type: command, callback function: (none) */
#define  TESTMODEMB_COMMANDBUTTON_6       26      /* control type: command, callback function: (none) */
#define  TESTMODEMB_COMMANDBUTTON_5       27      /* control type: command, callback function: (none) */
#define  TESTMODEMB_TEXTMSG               28      /* control type: textMsg, callback function: (none) */
#define  TESTMODEMB_COMMANDBUTTON_4       29      /* control type: command, callback function: TestModeMB */
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
int  CVICALLBACK Init(int panel, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK Main(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK Quit(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK TestModeMB(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);


#ifdef __cplusplus
    }
#endif
