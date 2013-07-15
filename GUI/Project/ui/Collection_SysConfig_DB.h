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
#define  CONFIGMB_BUTTON_7                3       /* control type: command, callback function: SysConfigDB */
#define  CONFIGMB_COMMANDBUTTON_13        4       /* control type: command, callback function: Quit */
#define  CONFIGMB_COMMANDBUTTON_14        5       /* control type: command, callback function: Back */
#define  CONFIGMB_COMMANDBUTTON_15        6       /* control type: command, callback function: Main */
#define  CONFIGMB_BUTTON_6                7       /* control type: command, callback function: SysConfigDB */
#define  CONFIGMB_BUTTON_5                8       /* control type: command, callback function: SysConfigDB */
#define  CONFIGMB_BUTTON_4                9       /* control type: command, callback function: SysConfigDB */
#define  CONFIGMB_BUTTON_3                10      /* control type: command, callback function: SysConfigDB */
#define  CONFIGMB_BUTTON_2                11      /* control type: command, callback function: SysConfigDB */
#define  CONFIGMB_BUTTON_1                12      /* control type: command, callback function: SysConfigDB */
#define  CONFIGMB_TEXTMSG                 13      /* control type: textMsg, callback function: (none) */
#define  CONFIGMB_BUTTON_0                14      /* control type: command, callback function: SysConfigDB */
#define  CONFIGMB_DECORATION              15      /* control type: deco, callback function: (none) */
#define  CONFIGMB_DECORATION_2            16      /* control type: deco, callback function: (none) */
#define  CONFIGMB_DECORATION_3            17      /* control type: deco, callback function: (none) */
#define  CONFIGMB_DECORATION_4            18      /* control type: deco, callback function: (none) */
#define  CONFIGMB_DECORATION_5            19      /* control type: deco, callback function: (none) */
#define  CONFIGMB_DECORATION_6            20      /* control type: deco, callback function: (none) */
#define  CONFIGMB_DECORATION_7            21      /* control type: deco, callback function: (none) */
#define  CONFIGMB_DECORATION_8            22      /* control type: deco, callback function: (none) */
#define  CONFIGMB_TREE                    23      /* control type: tree, callback function: (none) */
#define  CONFIGMB_DECORATION_9            24      /* control type: deco, callback function: (none) */
#define  CONFIGMB_TOGGLEBUTTON_16         25      /* control type: textButton, callback function: (none) */
#define  CONFIGMB_TOGGLEBUTTON_7          26      /* control type: textButton, callback function: (none) */
#define  CONFIGMB_TOGGLEBUTTON_5          27      /* control type: textButton, callback function: (none) */
#define  CONFIGMB_TOGGLEBUTTON_4          28      /* control type: textButton, callback function: (none) */
#define  CONFIGMB_TOGGLEBUTTON_3          29      /* control type: textButton, callback function: (none) */
#define  CONFIGMB_TOGGLEBUTTON_2          30      /* control type: textButton, callback function: (none) */
#define  CONFIGMB_TOGGLEBUTTON_1          31      /* control type: textButton, callback function: (none) */
#define  CONFIGMB_TOGGLEBUTTON_0          32      /* control type: textButton, callback function: (none) */


     /* Menu Bars, Menus, and Menu Items: */

          /* (no menu bars in the resource file) */


     /* Callback Prototypes: */

int  CVICALLBACK Back(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK Main(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK Quit(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK SaveSetup(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK SysConfigDB(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);


#ifdef __cplusplus
    }
#endif
