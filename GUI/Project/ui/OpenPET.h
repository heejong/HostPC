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

#define  PANEL                            1       /* callback function: panelCB */
#define  PANEL_ANALYZE                    2       /* control type: command, callback function: AnalyzeExistingData */
#define  PANEL_COLLECT                    3       /* control type: command, callback function: CollectNewData */
#define  PANEL_RUN                        4       /* control type: command, callback function: Run */
#define  PANEL_CALIBRATE                  5       /* control type: command, callback function: Calibrate */
#define  PANEL_GO                         6       /* control type: command, callback function: Go */
#define  PANEL_SETUP                      7       /* control type: command, callback function: Setup */
#define  PANEL_QUIT                       8       /* control type: command, callback function: Quit */
#define  PANEL_FILETEXT                   9       /* control type: string, callback function: (none) */
#define  PANEL_LOAD                       10      /* control type: command, callback function: LoadDataFile */
#define  PANEL_COMMANDBUTTON_5            11      /* control type: command, callback function: DisplayOscilloscopeMode */
#define  PANEL_COMMANDBUTTON_4            12      /* control type: command, callback function: DisplayTimeMode */
#define  PANEL_COMMANDBUTTON_3            13      /* control type: command, callback function: DisplayFloodMapMode */
#define  PANEL_COMMANDBUTTON_2            14      /* control type: command, callback function: DisplayEnergyMode */
#define  PANEL_COMMANDBUTTON_7            15      /* control type: command, callback function: DisplayTestMode2 */
#define  PANEL_COMMANDBUTTON              16      /* control type: command, callback function: DisplayTestMode1 */
#define  PANEL_COMMANDBUTTON_6            17      /* control type: command, callback function: DisplayUserMode */
#define  PANEL_DECORATION_9               18      /* control type: deco, callback function: (none) */


     /* Menu Bars, Menus, and Menu Items: */

          /* (no menu bars in the resource file) */


     /* Callback Prototypes: */

int  CVICALLBACK AnalyzeExistingData(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK Calibrate(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK CollectNewData(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK DisplayEnergyMode(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK DisplayFloodMapMode(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK DisplayOscilloscopeMode(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK DisplayTestMode1(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK DisplayTestMode2(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK DisplayTimeMode(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK DisplayUserMode(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK Go(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK LoadDataFile(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK panelCB(int panel, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK Quit(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK Run(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK Setup(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);


#ifdef __cplusplus
    }
#endif
