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

#define  CALIBRATE                        1
#define  CALIBRATE_COMMANDBUTTON_15       2       /* control type: command, callback function: (none) */
#define  CALIBRATE_TEXTMSG_12             3       /* control type: textMsg, callback function: (none) */
#define  CALIBRATE_TEXTMSG                4       /* control type: textMsg, callback function: (none) */
#define  CALIBRATE_COMMANDBUTTON_12       5       /* control type: command, callback function: Quit */
#define  CALIBRATE_COMMANDBUTTON_13       6       /* control type: command, callback function: Back */
#define  CALIBRATE_COMMANDBUTTON_14       7       /* control type: command, callback function: Main */
#define  CALIBRATE_TEXTMSG_11             8       /* control type: textMsg, callback function: (none) */
#define  CALIBRATE_TEXTMSG_10             9       /* control type: textMsg, callback function: (none) */
#define  CALIBRATE_TEXTMSG_3              10      /* control type: textMsg, callback function: (none) */
#define  CALIBRATE_DECORATION_9           11      /* control type: deco, callback function: (none) */
#define  CALIBRATE_FILETEXT               12      /* control type: string, callback function: (none) */
#define  CALIBRATE_LOAD                   13      /* control type: command, callback function: (none) */
#define  CALIBRATE_COMMANDBUTTON_5        14      /* control type: command, callback function: DisplayOscilloscopeMode */
#define  CALIBRATE_COMMANDBUTTON_4        15      /* control type: command, callback function: DisplayTimeMode */
#define  CALIBRATE_COMMANDBUTTON_3        16      /* control type: command, callback function: DisplayFloodMapMode */
#define  CALIBRATE_COMMANDBUTTON_2        17      /* control type: command, callback function: DisplayEnergyMode */
#define  CALIBRATE_COMMANDBUTTON_16       18      /* control type: command, callback function: DisplayTestMode2 */
#define  CALIBRATE_COMMANDBUTTON          19      /* control type: command, callback function: DisplayTestMode1 */
#define  CALIBRATE_COMMANDBUTTON_6        20      /* control type: command, callback function: DisplayUserMode */
#define  CALIBRATE_DECORATION_14          21      /* control type: deco, callback function: (none) */
#define  CALIBRATE_DECORATION_13          22      /* control type: deco, callback function: (none) */
#define  CALIBRATE_DECORATION_16          23      /* control type: deco, callback function: (none) */
#define  CALIBRATE_DECORATION_17          24      /* control type: deco, callback function: (none) */
#define  CALIBRATE_DECORATION_15          25      /* control type: deco, callback function: (none) */
#define  CALIBRATE_DECORATION_12          26      /* control type: deco, callback function: (none) */
#define  CALIBRATE_DECORATION_3           27      /* control type: deco, callback function: (none) */
#define  CALIBRATE_TEXTMSG_5              28      /* control type: textMsg, callback function: (none) */
#define  CALIBRATE_TEXTMSG_4              29      /* control type: textMsg, callback function: (none) */
#define  CALIBRATE_DECORATION_10          30      /* control type: deco, callback function: (none) */
#define  CALIBRATE_TEXTMSG_6              31      /* control type: textMsg, callback function: (none) */
#define  CALIBRATE_TEXTMSG_7              32      /* control type: textMsg, callback function: (none) */
#define  CALIBRATE_TEXTMSG_8              33      /* control type: textMsg, callback function: (none) */
#define  CALIBRATE_TEXTMSG_9              34      /* control type: textMsg, callback function: (none) */
#define  CALIBRATE_DECORATION_11          35      /* control type: deco, callback function: (none) */
#define  CALIBRATE_MINUTES_NUMERIC        36      /* control type: numeric, callback function: (none) */
#define  CALIBRATE_EVENTS_NUMERIC         37      /* control type: numeric, callback function: (none) */
#define  CALIBRATE_EVENTS_BUTTON          38      /* control type: textButton, callback function: CalibrateInEvents */
#define  CALIBRATE_MINUTES_BUTTON         39      /* control type: textButton, callback function: CalibrateInMinutes */


     /* Menu Bars, Menus, and Menu Items: */

          /* (no menu bars in the resource file) */


     /* Callback Prototypes: */

int  CVICALLBACK Back(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK CalibrateInEvents(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK CalibrateInMinutes(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK DisplayEnergyMode(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK DisplayFloodMapMode(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK DisplayOscilloscopeMode(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK DisplayTestMode1(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK DisplayTestMode2(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK DisplayTimeMode(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK DisplayUserMode(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK Main(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK Quit(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);


#ifdef __cplusplus
    }
#endif
