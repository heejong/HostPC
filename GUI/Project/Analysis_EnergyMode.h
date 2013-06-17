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

#define  EMODE                            1       /* callback function: InitializeEnergyMode */
#define  EMODE_PICTURE                    2       /* control type: picture, callback function: (none) */
#define  EMODE_PICTURE_2                  3       /* control type: picture, callback function: (none) */
#define  EMODE_SAVE_OUTPUT                4       /* control type: command, callback function: SaveOutput */
#define  EMODE_SAVE_PLOT                  5       /* control type: command, callback function: SavePlot */
#define  EMODE_COMMANDBUTTON              6       /* control type: command, callback function: Back */
#define  EMODE_COMMANDBUTTON_2            7       /* control type: command, callback function: Main */
#define  EMODE_COMMANDBUTTON_3            8       /* control type: command, callback function: Quit */
#define  EMODE_SPLITTER                   9       /* control type: splitter, callback function: (none) */
#define  EMODE_TEXTMSG_2                  10      /* control type: textMsg, callback function: (none) */
#define  EMODE_NUMERIC                    11      /* control type: numeric, callback function: (none) */
#define  EMODE_TEXTMSG                    12      /* control type: textMsg, callback function: (none) */
#define  EMODE_RING_2                     13      /* control type: ring, callback function: (none) */
#define  EMODE_NUMERIC_2                  14      /* control type: numeric, callback function: (none) */
#define  EMODE_COMMANDBUTTON_4            15      /* control type: command, callback function: (none) */
#define  EMODE_NUMERIC_3                  16      /* control type: numeric, callback function: (none) */


     /* Menu Bars, Menus, and Menu Items: */

          /* (no menu bars in the resource file) */


     /* Callback Prototypes: */

int  CVICALLBACK Back(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK InitializeEnergyMode(int panel, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK Main(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK Quit(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK SaveOutput(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK SavePlot(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);


#ifdef __cplusplus
    }
#endif
