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

#define  OMODE                            1
#define  OMODE_TAB                        2       /* control type: tab, callback function: (none) */
#define  OMODE_PICTURE                    3       /* control type: picture, callback function: (none) */
#define  OMODE_SAVE_OUTPUT                4       /* control type: command, callback function: SaveOutput */
#define  OMODE_SAVE_PLOT                  5       /* control type: command, callback function: SavePlot */
#define  OMODE_COMMANDBUTTON_3            6       /* control type: command, callback function: Quit */
#define  OMODE_COMMANDBUTTON              7       /* control type: command, callback function: Back */
#define  OMODE_COMMANDBUTTON_2            8       /* control type: command, callback function: Main */
#define  OMODE_DECORATION_10              9       /* control type: deco, callback function: (none) */
#define  OMODE_DECORATION_9               10      /* control type: deco, callback function: (none) */
#define  OMODE_COMMANDBUTTON_4            11      /* control type: command, callback function: ShowEnergySpectrum */

#define  OMODE_ENGY                       2
#define  OMODE_ENGY_PICTURE_2             2       /* control type: picture, callback function: (none) */
#define  OMODE_ENGY_SAVE_OUTPUT           3       /* control type: command, callback function: SaveOutput */
#define  OMODE_ENGY_NUMERIC_3             4       /* control type: numeric, callback function: (none) */
#define  OMODE_ENGY_SAVE_PLOT             5       /* control type: command, callback function: SavePlot */
#define  OMODE_ENGY_COMMANDBUTTON         6       /* control type: command, callback function: ClosePopup */

     /* tab page panel controls */
#define  TABPANEL_PICTURE_3               2       /* control type: picture, callback function: (none) */

     /* tab page panel controls */
#define  TABPANEL_2_PICTURE_3             2       /* control type: picture, callback function: (none) */


     /* Menu Bars, Menus, and Menu Items: */

          /* (no menu bars in the resource file) */


     /* Callback Prototypes: */

int  CVICALLBACK Back(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK ClosePopup(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK Main(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK Quit(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK SaveOutput(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK SavePlot(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK ShowEnergySpectrum(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);


#ifdef __cplusplus
    }
#endif
