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

#define  CONFIGDU                         1
#define  CONFIGDU_BUTTON_7                2       /* control type: command, callback function: SysConfigDUC */
#define  CONFIGDU_COMMANDBUTTON_13        3       /* control type: command, callback function: Quit */
#define  CONFIGDU_COMMANDBUTTON_14        4       /* control type: command, callback function: Back */
#define  CONFIGDU_COMMANDBUTTON_15        5       /* control type: command, callback function: Main */
#define  CONFIGDU_BUTTON_6                6       /* control type: command, callback function: SysConfigDUC */
#define  CONFIGDU_BUTTON_5                7       /* control type: command, callback function: SysConfigDUC */
#define  CONFIGDU_BUTTON_4                8       /* control type: command, callback function: SysConfigDUC */
#define  CONFIGDU_BUTTON_3                9       /* control type: command, callback function: SysConfigDUC */
#define  CONFIGDU_BUTTON_2                10      /* control type: command, callback function: SysConfigDUC */
#define  CONFIGDU_BUTTON_1                11      /* control type: command, callback function: SysConfigDUC */
#define  CONFIGDU_TEXTMSG                 12      /* control type: textMsg, callback function: (none) */
#define  CONFIGDU_BUTTON_0                13      /* control type: command, callback function: SysConfigDUC */
#define  CONFIGDU_DECORATION              14      /* control type: deco, callback function: (none) */
#define  CONFIGDU_DECORATION_2            15      /* control type: deco, callback function: (none) */
#define  CONFIGDU_DECORATION_3            16      /* control type: deco, callback function: (none) */
#define  CONFIGDU_DECORATION_4            17      /* control type: deco, callback function: (none) */
#define  CONFIGDU_DECORATION_5            18      /* control type: deco, callback function: (none) */
#define  CONFIGDU_DECORATION_6            19      /* control type: deco, callback function: (none) */
#define  CONFIGDU_DECORATION_7            20      /* control type: deco, callback function: (none) */
#define  CONFIGDU_DECORATION_8            21      /* control type: deco, callback function: (none) */
#define  CONFIGDU_TREE                    22      /* control type: tree, callback function: (none) */
#define  CONFIGDU_DECORATION_9            23      /* control type: deco, callback function: (none) */
#define  CONFIGDU_TOGGLEBUTTON_6          24      /* control type: textButton, callback function: (none) */
#define  CONFIGDU_TOGGLEBUTTON_7          25      /* control type: textButton, callback function: (none) */
#define  CONFIGDU_TOGGLEBUTTON_5          26      /* control type: textButton, callback function: (none) */
#define  CONFIGDU_TOGGLEBUTTON_4          27      /* control type: textButton, callback function: (none) */
#define  CONFIGDU_TOGGLEBUTTON_3          28      /* control type: textButton, callback function: (none) */
#define  CONFIGDU_TOGGLEBUTTON_2          29      /* control type: textButton, callback function: (none) */
#define  CONFIGDU_TOGGLEBUTTON_1          30      /* control type: textButton, callback function: (none) */
#define  CONFIGDU_TOGGLEBUTTON_0          31      /* control type: textButton, callback function: (none) */


     /* Menu Bars, Menus, and Menu Items: */

          /* (no menu bars in the resource file) */


     /* Callback Prototypes: */

int  CVICALLBACK Back(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK Main(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK Quit(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK SysConfigDUC(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);


#ifdef __cplusplus
    }
#endif
