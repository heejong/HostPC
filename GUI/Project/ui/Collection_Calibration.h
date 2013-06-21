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
#define  CALIBRATE_TEXTMSG                3       /* control type: textMsg, callback function: (none) */
#define  CALIBRATE_COMMANDBUTTON_12       4       /* control type: command, callback function: Quit */
#define  CALIBRATE_COMMANDBUTTON_13       5       /* control type: command, callback function: Back */
#define  CALIBRATE_COMMANDBUTTON_14       6       /* control type: command, callback function: Main */
#define  CALIBRATE_TEXTMSG_3              7       /* control type: textMsg, callback function: (none) */
#define  CALIBRATE_DECORATION_9           8       /* control type: deco, callback function: (none) */
#define  CALIBRATE_FILETEXT               9       /* control type: string, callback function: (none) */
#define  CALIBRATE_LOAD                   10      /* control type: command, callback function: (none) */
#define  CALIBRATE_COMMANDBUTTON_5        11      /* control type: command, callback function: DisplayOscilloscopeMode */
#define  CALIBRATE_COMMANDBUTTON_4        12      /* control type: command, callback function: DisplayTimeMode */
#define  CALIBRATE_COMMANDBUTTON_3        13      /* control type: command, callback function: DisplayFloodMapMode */
#define  CALIBRATE_COMMANDBUTTON_2        14      /* control type: command, callback function: DisplayEnergyMode */
#define  CALIBRATE_COMMANDBUTTON          15      /* control type: command, callback function: DisplayTestMode */
#define  CALIBRATE_COMMANDBUTTON_6        16      /* control type: command, callback function: DisplayUserMode */
#define  CALIBRATE_DECORATION_14          17      /* control type: deco, callback function: (none) */
#define  CALIBRATE_DECORATION_13          18      /* control type: deco, callback function: (none) */
#define  CALIBRATE_DECORATION_12          19      /* control type: deco, callback function: (none) */
#define  CALIBRATE_DECORATION_3           20      /* control type: deco, callback function: (none) */
#define  CALIBRATE_TEXTMSG_5              21      /* control type: textMsg, callback function: (none) */
#define  CALIBRATE_TEXTMSG_4              22      /* control type: textMsg, callback function: (none) */
#define  CALIBRATE_DECORATION_10          23      /* control type: deco, callback function: (none) */
#define  CALIBRATE_TEXTMSG_6              24      /* control type: textMsg, callback function: (none) */
#define  CALIBRATE_TEXTMSG_7              25      /* control type: textMsg, callback function: (none) */
#define  CALIBRATE_TEXTMSG_8              26      /* control type: textMsg, callback function: (none) */
#define  CALIBRATE_TEXTMSG_9              27      /* control type: textMsg, callback function: (none) */
#define  CALIBRATE_DECORATION_11          28      /* control type: deco, callback function: (none) */

#define  RWAsicReg                        2
#define  RWAsicReg_ASIC_SLOT_TAB          2       /* control type: tab, callback function: viewSlotConfig */
#define  RWAsicReg_COMMANDBUTTON          3       /* control type: command, callback function: QuitCallback */
#define  RWAsicReg_DEA_LED_11             4       /* control type: LED, callback function: (none) */
#define  RWAsicReg_DEA_LED_10             5       /* control type: LED, callback function: (none) */
#define  RWAsicReg_DEA_LED_9              6       /* control type: LED, callback function: (none) */
#define  RWAsicReg_DEA_LED_8              7       /* control type: LED, callback function: (none) */
#define  RWAsicReg_DEA_LED_7              8       /* control type: LED, callback function: (none) */
#define  RWAsicReg_DEA_LED_6              9       /* control type: LED, callback function: (none) */
#define  RWAsicReg_DEA_LED_5              10      /* control type: LED, callback function: (none) */
#define  RWAsicReg_DEA_LED_4              11      /* control type: LED, callback function: (none) */
#define  RWAsicReg_DEA_LED_3              12      /* control type: LED, callback function: (none) */
#define  RWAsicReg_DEA_LED_2              13      /* control type: LED, callback function: (none) */
#define  RWAsicReg_DEA_LED_1              14      /* control type: LED, callback function: (none) */
#define  RWAsicReg_DEA_LED_0              15      /* control type: LED, callback function: (none) */
#define  RWAsicReg_CHECKBOX_DEA11         16      /* control type: radioButton, callback function: DEASel11 */
#define  RWAsicReg_CHECKBOX_DEA10         17      /* control type: radioButton, callback function: DEASel10 */
#define  RWAsicReg_CHECKBOX_DEA9          18      /* control type: radioButton, callback function: DEASel9 */
#define  RWAsicReg_CHECKBOX_DEA8          19      /* control type: radioButton, callback function: DEASel8 */
#define  RWAsicReg_CHECKBOX_DEA7          20      /* control type: radioButton, callback function: DEASel7 */
#define  RWAsicReg_CHECKBOX_DEA6          21      /* control type: radioButton, callback function: DEASel6 */
#define  RWAsicReg_CHECKBOX_DEA5          22      /* control type: radioButton, callback function: DEASel5 */
#define  RWAsicReg_CHECKBOX_DEA4          23      /* control type: radioButton, callback function: DEASel4 */
#define  RWAsicReg_CHECKBOX_DEA3          24      /* control type: radioButton, callback function: DEASel3 */
#define  RWAsicReg_CHECKBOX_DEA2          25      /* control type: radioButton, callback function: DEASel2 */
#define  RWAsicReg_CHECKBOX_DEA1          26      /* control type: radioButton, callback function: DEASel1 */
#define  RWAsicReg_CHECKBOX_DEA0          27      /* control type: radioButton, callback function: DEASel0 */
#define  RWAsicReg_ASIC_CONFIG_PATH       28      /* control type: string, callback function: (none) */
#define  RWAsicReg_CMDBUTTON_LOAD         29      /* control type: command, callback function: LoadAsicConfigFile */
#define  RWAsicReg_CMDBUTTON_SAVE         30      /* control type: command, callback function: SaveAsicConfigFile */
#define  RWAsicReg_DECORATION             31      /* control type: deco, callback function: (none) */
#define  RWAsicReg_CMDUPLOADCURRENT_2     32      /* control type: command, callback function: (none) */
#define  RWAsicReg_CMDDOWNLOADALL         33      /* control type: command, callback function: (none) */
#define  RWAsicReg_CMDUPLOADCURRENT       34      /* control type: command, callback function: upLoadCurrentASICConfig */
#define  RWAsicReg_CMDDOWNLOADCURRENT     35      /* control type: command, callback function: downLoadCurrentASICConfig */
#define  RWAsicReg_DECORATION_2           36      /* control type: deco, callback function: (none) */
#define  RWAsicReg_DECORATION_4           37      /* control type: deco, callback function: (none) */
#define  RWAsicReg_DECORATION_3           38      /* control type: deco, callback function: (none) */

     /* tab page panel controls */
#define  INFO_TABLE                       2       /* control type: table, callback function: (none) */

     /* tab page panel controls */
#define  Slot0_ASIC_TABLE_CH1             2       /* control type: table, callback function: AsicRegTable1 */
#define  Slot0_ASIC_TABLE_CH0             3       /* control type: table, callback function: AsicRegTable0 */
#define  Slot0_CMDBUTTON_SAVE1            4       /* control type: command, callback function: saveAsicRegTable1 */
#define  Slot0_CMDBUTTON_SAVE0            5       /* control type: command, callback function: saveAsicRegTable0 */

     /* tab page panel controls */
#define  Slot1_ASIC_TABLE_CH1             2       /* control type: table, callback function: AsicRegTable1 */
#define  Slot1_ASIC_TABLE_CH0             3       /* control type: table, callback function: AsicRegTable0 */
#define  Slot1_CMDBUTTON_SAVE1            4       /* control type: command, callback function: saveAsicRegTable1 */
#define  Slot1_CMDBUTTON_SAVE0            5       /* control type: command, callback function: saveAsicRegTable0 */

     /* tab page panel controls */
#define  Slot2_ASIC_TABLE_CH1             2       /* control type: table, callback function: AsicRegTable1 */
#define  Slot2_ASIC_TABLE_CH0             3       /* control type: table, callback function: AsicRegTable0 */
#define  Slot2_CMDBUTTON_SAVE1            4       /* control type: command, callback function: saveAsicRegTable1 */
#define  Slot2_CMDBUTTON_SAVE0            5       /* control type: command, callback function: saveAsicRegTable0 */

     /* tab page panel controls */
#define  Slot3_ASIC_TABLE_CH1             2       /* control type: table, callback function: AsicRegTable1 */
#define  Slot3_ASIC_TABLE_CH0             3       /* control type: table, callback function: AsicRegTable0 */
#define  Slot3_CMDBUTTON_SAVE1            4       /* control type: command, callback function: saveAsicRegTable1 */
#define  Slot3_CMDBUTTON_SAVE0            5       /* control type: command, callback function: saveAsicRegTable0 */

     /* tab page panel controls */
#define  Slot4_ASIC_TABLE_CH1             2       /* control type: table, callback function: AsicRegTable1 */
#define  Slot4_ASIC_TABLE_CH0             3       /* control type: table, callback function: AsicRegTable0 */
#define  Slot4_CMDBUTTON_SAVE1            4       /* control type: command, callback function: saveAsicRegTable1 */
#define  Slot4_CMDBUTTON_SAVE0            5       /* control type: command, callback function: saveAsicRegTable0 */

     /* tab page panel controls */
#define  Slot5_ASIC_TABLE_CH1             2       /* control type: table, callback function: AsicRegTable1 */
#define  Slot5_ASIC_TABLE_CH0             3       /* control type: table, callback function: AsicRegTable0 */
#define  Slot5_CMDBUTTON_SAVE1            4       /* control type: command, callback function: saveAsicRegTable1 */
#define  Slot5_CMDBUTTON_SAVE0            5       /* control type: command, callback function: saveAsicRegTable0 */

     /* tab page panel controls */
#define  Slot6_ASIC_TABLE_CH1             2       /* control type: table, callback function: AsicRegTable1 */
#define  Slot6_ASIC_TABLE_CH0             3       /* control type: table, callback function: AsicRegTable0 */
#define  Slot6_CMDBUTTON_SAVE1            4       /* control type: command, callback function: saveAsicRegTable1 */
#define  Slot6_CMDBUTTON_SAVE0            5       /* control type: command, callback function: saveAsicRegTable0 */

     /* tab page panel controls */
#define  Slot7_ASIC_TABLE_CH1             2       /* control type: table, callback function: AsicRegTable1 */
#define  Slot7_ASIC_TABLE_CH0             3       /* control type: table, callback function: AsicRegTable0 */
#define  Slot7_CMDBUTTON_SAVE1            4       /* control type: command, callback function: saveAsicRegTable1 */
#define  Slot7_CMDBUTTON_SAVE0            5       /* control type: command, callback function: saveAsicRegTable0 */


     /* Menu Bars, Menus, and Menu Items: */

          /* (no menu bars in the resource file) */


     /* Callback Prototypes: */

int  CVICALLBACK AsicRegTable0(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK AsicRegTable1(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK Back(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK DEASel0(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK DEASel1(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK DEASel10(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK DEASel11(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK DEASel2(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK DEASel3(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK DEASel4(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK DEASel5(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK DEASel6(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK DEASel7(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK DEASel8(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK DEASel9(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK DisplayEnergyMode(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK DisplayFloodMapMode(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK DisplayOscilloscopeMode(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK DisplayTestMode(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK DisplayTimeMode(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK DisplayUserMode(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK downLoadCurrentASICConfig(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK LoadAsicConfigFile(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK Main(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK Quit(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK QuitCallback(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK SaveAsicConfigFile(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK saveAsicRegTable0(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK saveAsicRegTable1(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK upLoadCurrentASICConfig(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK viewSlotConfig(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);


#ifdef __cplusplus
    }
#endif
