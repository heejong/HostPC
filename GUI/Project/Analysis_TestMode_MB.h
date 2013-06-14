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
#define  TESTMODEMB_STRING_25             3       /* control type: string, callback function: (none) */
#define  TESTMODEMB_STRING_22             4       /* control type: string, callback function: (none) */
#define  TESTMODEMB_STRING_23             5       /* control type: string, callback function: (none) */
#define  TESTMODEMB_STRING_20             6       /* control type: string, callback function: (none) */
#define  TESTMODEMB_STRING_21             7       /* control type: string, callback function: (none) */
#define  TESTMODEMB_STRING_18             8       /* control type: string, callback function: (none) */
#define  TESTMODEMB_STRING_19             9       /* control type: string, callback function: (none) */
#define  TESTMODEMB_STRING_16             10      /* control type: string, callback function: (none) */
#define  TESTMODEMB_COMMANDBUTTON_11      11      /* control type: command, callback function: (none) */
#define  TESTMODEMB_STRING_17             12      /* control type: string, callback function: (none) */
#define  TESTMODEMB_STRING_14             13      /* control type: string, callback function: (none) */
#define  TESTMODEMB_COMMANDBUTTON_10      14      /* control type: command, callback function: (none) */
#define  TESTMODEMB_STRING_15             15      /* control type: string, callback function: (none) */
#define  TESTMODEMB_STRING_12             16      /* control type: string, callback function: (none) */
#define  TESTMODEMB_COMMANDBUTTON_9       17      /* control type: command, callback function: (none) */
#define  TESTMODEMB_STRING_13             18      /* control type: string, callback function: (none) */
#define  TESTMODEMB_STRING_11             19      /* control type: string, callback function: MB0 */
#define  TESTMODEMB_COMMANDBUTTON_8       20      /* control type: command, callback function: (none) */
#define  TESTMODEMB_STRING                21      /* control type: string, callback function: MB0 */
#define  TESTMODEMB_COMMANDBUTTON_7       22      /* control type: command, callback function: (none) */
#define  TESTMODEMB_COMMANDBUTTON         23      /* control type: command, callback function: Back */
#define  TESTMODEMB_COMMANDBUTTON_6       24      /* control type: command, callback function: (none) */
#define  TESTMODEMB_COMMANDBUTTON_2       25      /* control type: command, callback function: Main */
#define  TESTMODEMB_COMMANDBUTTON_3       26      /* control type: command, callback function: Quit */
#define  TESTMODEMB_COMMANDBUTTON_5       27      /* control type: command, callback function: (none) */
#define  TESTMODEMB_TEXTMSG_2             28      /* control type: textMsg, callback function: (none) */
#define  TESTMODEMB_TEXTMSG               29      /* control type: textMsg, callback function: (none) */
#define  TESTMODEMB_COMMANDBUTTON_4       30      /* control type: command, callback function: MB0 */
#define  TESTMODEMB_DECORATION            31      /* control type: deco, callback function: MB0 */
#define  TESTMODEMB_DECORATION_2          32      /* control type: deco, callback function: (none) */
#define  TESTMODEMB_DECORATION_3          33      /* control type: deco, callback function: (none) */
#define  TESTMODEMB_DECORATION_4          34      /* control type: deco, callback function: (none) */
#define  TESTMODEMB_DECORATION_5          35      /* control type: deco, callback function: (none) */
#define  TESTMODEMB_DECORATION_6          36      /* control type: deco, callback function: (none) */
#define  TESTMODEMB_DECORATION_7          37      /* control type: deco, callback function: (none) */
#define  TESTMODEMB_DECORATION_8          38      /* control type: deco, callback function: (none) */
#define  TESTMODEMB_SPLITTER              39      /* control type: splitter, callback function: (none) */


     /* Menu Bars, Menus, and Menu Items: */

          /* (no menu bars in the resource file) */


     /* Callback Prototypes: */

int  CVICALLBACK Back(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK Init(int panel, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK Main(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK MB0(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK Quit(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);


#ifdef __cplusplus
    }
#endif
