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

#define  EMODEMB                          1
#define  EMODEMB_STRING_24                2       /* control type: string, callback function: (none) */
#define  EMODEMB_STRING_22                3       /* control type: string, callback function: (none) */
#define  EMODEMB_STRING_20                4       /* control type: string, callback function: (none) */
#define  EMODEMB_STRING_18                5       /* control type: string, callback function: (none) */
#define  EMODEMB_COMMANDBUTTON_12         6       /* control type: command, callback function: Quit */
#define  EMODEMB_COMMANDBUTTON_13         7       /* control type: command, callback function: Back */
#define  EMODEMB_COMMANDBUTTON_14         8       /* control type: command, callback function: Main */
#define  EMODEMB_STRING_16                9       /* control type: string, callback function: (none) */
#define  EMODEMB_COMMANDBUTTON_11         10      /* control type: command, callback function: (none) */
#define  EMODEMB_STRING_14                11      /* control type: string, callback function: (none) */
#define  EMODEMB_COMMANDBUTTON_10         12      /* control type: command, callback function: (none) */
#define  EMODEMB_STRING_12                13      /* control type: string, callback function: (none) */
#define  EMODEMB_COMMANDBUTTON_9          14      /* control type: command, callback function: (none) */
#define  EMODEMB_STRING_11                15      /* control type: string, callback function: (none) */
#define  EMODEMB_COMMANDBUTTON_8          16      /* control type: command, callback function: (none) */
#define  EMODEMB_COMMANDBUTTON_7          17      /* control type: command, callback function: (none) */
#define  EMODEMB_COMMANDBUTTON_6          18      /* control type: command, callback function: (none) */
#define  EMODEMB_COMMANDBUTTON_5          19      /* control type: command, callback function: (none) */
#define  EMODEMB_TEXTMSG                  20      /* control type: textMsg, callback function: (none) */
#define  EMODEMB_COMMANDBUTTON_4          21      /* control type: command, callback function: EnergyModeMB */
#define  EMODEMB_DECORATION               22      /* control type: deco, callback function: (none) */
#define  EMODEMB_DECORATION_2             23      /* control type: deco, callback function: (none) */
#define  EMODEMB_DECORATION_3             24      /* control type: deco, callback function: (none) */
#define  EMODEMB_DECORATION_4             25      /* control type: deco, callback function: (none) */
#define  EMODEMB_DECORATION_5             26      /* control type: deco, callback function: (none) */
#define  EMODEMB_DECORATION_6             27      /* control type: deco, callback function: (none) */
#define  EMODEMB_DECORATION_7             28      /* control type: deco, callback function: (none) */
#define  EMODEMB_DECORATION_8             29      /* control type: deco, callback function: (none) */
#define  EMODEMB_TREE                     30      /* control type: tree, callback function: (none) */
#define  EMODEMB_DECORATION_9             31      /* control type: deco, callback function: (none) */


     /* Menu Bars, Menus, and Menu Items: */

          /* (no menu bars in the resource file) */


     /* Callback Prototypes: */

int  CVICALLBACK Back(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK EnergyModeMB(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK Main(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK Quit(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);


#ifdef __cplusplus
    }
#endif