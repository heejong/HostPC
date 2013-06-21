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
#define  CONFIGMB_COMMANDBUTTON_12        2       /* control type: command, callback function: Next */
#define  CONFIGMB_COMMANDBUTTON_11        3       /* control type: command, callback function: (none) */
#define  CONFIGMB_COMMANDBUTTON_13        4       /* control type: command, callback function: Quit */
#define  CONFIGMB_COMMANDBUTTON_14        5       /* control type: command, callback function: Back */
#define  CONFIGMB_COMMANDBUTTON_15        6       /* control type: command, callback function: Main */
#define  CONFIGMB_TEXTMSG_4               7       /* control type: textMsg, callback function: (none) */
#define  CONFIGMB_COMMANDBUTTON_10        8       /* control type: command, callback function: (none) */
#define  CONFIGMB_COMMANDBUTTON_9         9       /* control type: command, callback function: (none) */
#define  CONFIGMB_COMMANDBUTTON_8         10      /* control type: command, callback function: (none) */
#define  CONFIGMB_FILETEXT                11      /* control type: string, callback function: (none) */
#define  CONFIGMB_LOAD                    12      /* control type: command, callback function: (none) */
#define  CONFIGMB_COMMANDBUTTON_7         13      /* control type: command, callback function: (none) */
#define  CONFIGMB_COMMANDBUTTON_6         14      /* control type: command, callback function: (none) */
#define  CONFIGMB_COMMANDBUTTON_5         15      /* control type: command, callback function: (none) */
#define  CONFIGMB_TEXTMSG                 16      /* control type: textMsg, callback function: (none) */
#define  CONFIGMB_COMMANDBUTTON_4         17      /* control type: command, callback function: SystemConfigMB */
#define  CONFIGMB_DECORATION              18      /* control type: deco, callback function: (none) */
#define  CONFIGMB_DECORATION_2            19      /* control type: deco, callback function: (none) */
#define  CONFIGMB_DECORATION_3            20      /* control type: deco, callback function: (none) */
#define  CONFIGMB_DECORATION_4            21      /* control type: deco, callback function: (none) */
#define  CONFIGMB_DECORATION_5            22      /* control type: deco, callback function: (none) */
#define  CONFIGMB_DECORATION_6            23      /* control type: deco, callback function: (none) */
#define  CONFIGMB_DECORATION_7            24      /* control type: deco, callback function: (none) */
#define  CONFIGMB_DECORATION_8            25      /* control type: deco, callback function: (none) */
#define  CONFIGMB_TREE                    26      /* control type: tree, callback function: (none) */
#define  CONFIGMB_DECORATION_9            27      /* control type: deco, callback function: (none) */
#define  CONFIGMB_TOGGLEBUTTON_10         28      /* control type: textButton, callback function: (none) */
#define  CONFIGMB_TOGGLEBUTTON_9          29      /* control type: textButton, callback function: (none) */
#define  CONFIGMB_TOGGLEBUTTON_8          30      /* control type: textButton, callback function: (none) */
#define  CONFIGMB_TOGGLEBUTTON_7          31      /* control type: textButton, callback function: (none) */
#define  CONFIGMB_TOGGLEBUTTON_6          32      /* control type: textButton, callback function: (none) */
#define  CONFIGMB_TOGGLEBUTTON_5          33      /* control type: textButton, callback function: (none) */
#define  CONFIGMB_TOGGLEBUTTON_4          34      /* control type: textButton, callback function: (none) */
#define  CONFIGMB_TOGGLEBUTTON_3          35      /* control type: textButton, callback function: (none) */


     /* Menu Bars, Menus, and Menu Items: */

          /* (no menu bars in the resource file) */


     /* Callback Prototypes: */

int  CVICALLBACK Back(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK Main(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK Next(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK Quit(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK SystemConfigMB(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);


#ifdef __cplusplus
    }
#endif
