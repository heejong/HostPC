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

#define  CONFIGMB                         1
#define  CONFIGMB_COMMANDBUTTON_12        2       /* control type: command, callback function: SaveSetup */
#define  CONFIGMB_COMMANDBUTTON_11        3       /* control type: command, callback function: (none) */
#define  CONFIGMB_COMMANDBUTTON_13        4       /* control type: command, callback function: Quit */
#define  CONFIGMB_COMMANDBUTTON_14        5       /* control type: command, callback function: Back */
#define  CONFIGMB_COMMANDBUTTON_15        6       /* control type: command, callback function: Main */
#define  CONFIGMB_COMMANDBUTTON_10        7       /* control type: command, callback function: (none) */
#define  CONFIGMB_TEXTMSG_4               8       /* control type: textMsg, callback function: (none) */
#define  CONFIGMB_TEXTMSG_3               9       /* control type: textMsg, callback function: (none) */
#define  CONFIGMB_COMMANDBUTTON_9         10      /* control type: command, callback function: (none) */
#define  CONFIGMB_FILETEXT                11      /* control type: string, callback function: (none) */
#define  CONFIGMB_LOAD                    12      /* control type: command, callback function: (none) */
#define  CONFIGMB_SINGLEEVENT_RING        13      /* control type: ring, callback function: SingleEventChange */
#define  CONFIGMB_COINCIDENCE_64_RING     14      /* control type: ring, callback function: (none) */
#define  CONFIGMB_COINCIDENCE_32_RING     15      /* control type: ring, callback function: (none) */
#define  CONFIGMB_COMMANDBUTTON_8         16      /* control type: command, callback function: (none) */
#define  CONFIGMB_COMMANDBUTTON_7         17      /* control type: command, callback function: (none) */
#define  CONFIGMB_COMMANDBUTTON_6         18      /* control type: command, callback function: (none) */
#define  CONFIGMB_COMMANDBUTTON_5         19      /* control type: command, callback function: (none) */
#define  CONFIGMB_TEXTMSG                 20      /* control type: textMsg, callback function: (none) */
#define  CONFIGMB_COMMANDBUTTON_4         21      /* control type: command, callback function: SystemConfigMB */
#define  CONFIGMB_DECORATION_17           22      /* control type: deco, callback function: (none) */
#define  CONFIGMB_DECORATION_16           23      /* control type: deco, callback function: (none) */
#define  CONFIGMB_DECORATION              24      /* control type: deco, callback function: (none) */
#define  CONFIGMB_DECORATION_2            25      /* control type: deco, callback function: (none) */
#define  CONFIGMB_DECORATION_3            26      /* control type: deco, callback function: (none) */
#define  CONFIGMB_DECORATION_4            27      /* control type: deco, callback function: (none) */
#define  CONFIGMB_DECORATION_5            28      /* control type: deco, callback function: (none) */
#define  CONFIGMB_DECORATION_6            29      /* control type: deco, callback function: (none) */
#define  CONFIGMB_DECORATION_7            30      /* control type: deco, callback function: (none) */
#define  CONFIGMB_DECORATION_8            31      /* control type: deco, callback function: (none) */
#define  CONFIGMB_TREE                    32      /* control type: tree, callback function: (none) */
#define  CONFIGMB_DECORATION_9            33      /* control type: deco, callback function: (none) */
#define  CONFIGMB_TOGGLEBUTTON_10         34      /* control type: textButton, callback function: (none) */
#define  CONFIGMB_TOGGLEBUTTON_9          35      /* control type: textButton, callback function: (none) */
#define  CONFIGMB_TOGGLEBUTTON_8          36      /* control type: textButton, callback function: (none) */
#define  CONFIGMB_TOGGLEBUTTON_7          37      /* control type: textButton, callback function: (none) */
#define  CONFIGMB_TOGGLEBUTTON_6          38      /* control type: textButton, callback function: (none) */
#define  CONFIGMB_TOGGLEBUTTON_5          39      /* control type: textButton, callback function: (none) */
#define  CONFIGMB_TOGGLEBUTTON_4          40      /* control type: textButton, callback function: (none) */
#define  CONFIGMB_TOGGLEBUTTON_3          41      /* control type: textButton, callback function: (none) */


     /* Menu Bars, Menus, and Menu Items: */

          /* (no menu bars in the resource file) */


     /* Callback Prototypes: */

int  CVICALLBACK Back(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK Main(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK Quit(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK SaveSetup(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK SingleEventChange(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK SystemConfigMB(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);


#ifdef __cplusplus
    }
#endif
