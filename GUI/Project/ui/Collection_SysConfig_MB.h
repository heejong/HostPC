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
#define  CONFIGMB_COMMANDBUTTON_10        4       /* control type: command, callback function: (none) */
#define  CONFIGMB_COMMANDBUTTON_9         5       /* control type: command, callback function: (none) */
#define  CONFIGMB_COMMANDBUTTON_8         6       /* control type: command, callback function: (none) */
#define  CONFIGMB_FILETEXT                7       /* control type: string, callback function: (none) */
#define  CONFIGMB_LOAD                    8       /* control type: command, callback function: LoadDataFile */
#define  CONFIGMB_COMMANDBUTTON_7         9       /* control type: command, callback function: (none) */
#define  CONFIGMB_COMMANDBUTTON_6         10      /* control type: command, callback function: (none) */
#define  CONFIGMB_COMMANDBUTTON_5         11      /* control type: command, callback function: (none) */
#define  CONFIGMB_TEXTMSG                 12      /* control type: textMsg, callback function: (none) */
#define  CONFIGMB_COMMANDBUTTON_4         13      /* control type: command, callback function: SystemConfigMB */
#define  CONFIGMB_DECORATION              14      /* control type: deco, callback function: (none) */
#define  CONFIGMB_DECORATION_2            15      /* control type: deco, callback function: (none) */
#define  CONFIGMB_DECORATION_3            16      /* control type: deco, callback function: (none) */
#define  CONFIGMB_DECORATION_4            17      /* control type: deco, callback function: (none) */
#define  CONFIGMB_DECORATION_5            18      /* control type: deco, callback function: (none) */
#define  CONFIGMB_DECORATION_6            19      /* control type: deco, callback function: (none) */
#define  CONFIGMB_DECORATION_7            20      /* control type: deco, callback function: (none) */
#define  CONFIGMB_DECORATION_8            21      /* control type: deco, callback function: (none) */
#define  CONFIGMB_TREE                    22      /* control type: tree, callback function: (none) */
#define  CONFIGMB_DECORATION_9            23      /* control type: deco, callback function: (none) */
#define  CONFIGMB_TOGGLEBUTTON_10         24      /* control type: textButton, callback function: (none) */
#define  CONFIGMB_TOGGLEBUTTON_9          25      /* control type: textButton, callback function: (none) */
#define  CONFIGMB_TOGGLEBUTTON_8          26      /* control type: textButton, callback function: (none) */
#define  CONFIGMB_TOGGLEBUTTON_7          27      /* control type: textButton, callback function: (none) */
#define  CONFIGMB_TOGGLEBUTTON_6          28      /* control type: textButton, callback function: (none) */
#define  CONFIGMB_TOGGLEBUTTON_5          29      /* control type: textButton, callback function: (none) */
#define  CONFIGMB_TOGGLEBUTTON_4          30      /* control type: textButton, callback function: (none) */
#define  CONFIGMB_TOGGLEBUTTON_3          31      /* control type: textButton, callback function: (none) */
#define  CONFIGMB_TEXTMSG_3               32      /* control type: textMsg, callback function: (none) */
#define  CONFIGMB_RADIOBUTTON             33      /* control type: radioButton, callback function: (none) */


     /* Menu Bars, Menus, and Menu Items: */

          /* (no menu bars in the resource file) */


     /* Callback Prototypes: */

int  CVICALLBACK LoadDataFile(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK Next(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK SystemConfigMB(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);


#ifdef __cplusplus
    }
#endif
