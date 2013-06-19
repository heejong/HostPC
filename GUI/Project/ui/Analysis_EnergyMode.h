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

#define  EMODE                            1
#define  EMODE_PICTURE                    2       /* control type: picture, callback function: (none) */
#define  EMODE_PICTURE_2                  3       /* control type: picture, callback function: (none) */
#define  EMODE_SAVE_OUTPUT                4       /* control type: command, callback function: SaveOutput */
#define  EMODE_SAVE_PLOT                  5       /* control type: command, callback function: SavePlot */
#define  EMODE_COMMANDBUTTON_3            6       /* control type: command, callback function: Quit */
#define  EMODE_COMMANDBUTTON              7       /* control type: command, callback function: Back */
#define  EMODE_COMMANDBUTTON_2            8       /* control type: command, callback function: Main */
#define  EMODE_NUMERIC                    9       /* control type: numeric, callback function: (none) */
#define  EMODE_ANALYSIS_METHOD            10      /* control type: ring, callback function: DetermineEnergyWindow */
#define  EMODE_METHOD_AMOUNT              11      /* control type: numeric, callback function: (none) */
#define  EMODE_NEW_WINDOW_BUTTON          12      /* control type: command, callback function: (none) */
#define  EMODE_NUMERIC_3                  13      /* control type: numeric, callback function: (none) */
#define  EMODE_DECORATION                 14      /* control type: deco, callback function: (none) */
#define  EMODE_DECORATION_9               15      /* control type: deco, callback function: (none) */


     /* Menu Bars, Menus, and Menu Items: */

          /* (no menu bars in the resource file) */


     /* Callback Prototypes: */

int  CVICALLBACK Back(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK DetermineEnergyWindow(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK Main(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK Quit(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK SaveOutput(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK SavePlot(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);


#ifdef __cplusplus
    }
#endif
