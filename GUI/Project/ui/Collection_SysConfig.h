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

#define  SYSCONFIG                        1       /* callback function: InitializeSysConfig */
#define  SYSCONFIG_TREE                   2       /* control type: tree, callback function: SysConfigTree */
#define  SYSCONFIG_SUBTITLE2              3       /* control type: textMsg, callback function: (none) */
#define  SYSCONFIG_COINCIDENCE_64_RING    4       /* control type: ring, callback function: (none) */
#define  SYSCONFIG_SUBTITLE1              5       /* control type: textMsg, callback function: (none) */
#define  SYSCONFIG_COINCIDENCE_32_RING    6       /* control type: ring, callback function: (none) */
#define  SYSCONFIG_FILETEXT               7       /* control type: string, callback function: (none) */
#define  SYSCONFIG_DECORATION_17          8       /* control type: deco, callback function: (none) */
#define  SYSCONFIG_LOAD                   9       /* control type: command, callback function: (none) */
#define  SYSCONFIG_DECORATION_16          10      /* control type: deco, callback function: (none) */
#define  SYSCONFIG_SINGLEEVENT_RING       11      /* control type: ring, callback function: SingleEventChange */
#define  SYSCONFIG_COMMANDBUTTON_12       12      /* control type: command, callback function: SaveSetup */
#define  SYSCONFIG_COMMANDBUTTON_13       13      /* control type: command, callback function: Quit */
#define  SYSCONFIG_COMMANDBUTTON_14       14      /* control type: command, callback function: Back */
#define  SYSCONFIG_COMMANDBUTTON_15       15      /* control type: command, callback function: Main */
#define  SYSCONFIG_TEXTMSG                16      /* control type: textMsg, callback function: (none) */
#define  SYSCONFIG_DECORATION_9           17      /* control type: deco, callback function: (none) */


     /* Menu Bars, Menus, and Menu Items: */

          /* (no menu bars in the resource file) */


     /* Callback Prototypes: */

int  CVICALLBACK Back(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK InitializeSysConfig(int panel, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK Main(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK Quit(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK SaveSetup(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK SingleEventChange(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK SysConfigTree(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);


#ifdef __cplusplus
    }
#endif
