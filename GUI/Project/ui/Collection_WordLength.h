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

#define  WORDLENGTH                       1
#define  WORDLENGTH_COMMANDBUTTON_12      2       /* control type: command, callback function: Quit */
#define  WORDLENGTH_COMMANDBUTTON_13      3       /* control type: command, callback function: Back */
#define  WORDLENGTH_COMMANDBUTTON_14      4       /* control type: command, callback function: Main */
#define  WORDLENGTH_TEXTMSG_3             5       /* control type: textMsg, callback function: (none) */
#define  WORDLENGTH_TEXTMSG_2             6       /* control type: textMsg, callback function: (none) */
#define  WORDLENGTH_TEXTMSG               7       /* control type: textMsg, callback function: (none) */
#define  WORDLENGTH_RADIOBUTTON_5         8       /* control type: radioButton, callback function: (none) */
#define  WORDLENGTH_RADIOBUTTON_6         9       /* control type: radioButton, callback function: (none) */
#define  WORDLENGTH_RADIOBUTTON_3         10      /* control type: radioButton, callback function: (none) */
#define  WORDLENGTH_RADIOBUTTON_4         11      /* control type: radioButton, callback function: (none) */
#define  WORDLENGTH_DECORATION_9          12      /* control type: deco, callback function: (none) */
#define  WORDLENGTH_RADIOBUTTON_2         13      /* control type: radioButton, callback function: (none) */
#define  WORDLENGTH_RADIOBUTTON           14      /* control type: radioButton, callback function: (none) */
#define  WORDLENGTH_RING                  15      /* control type: ring, callback function: (none) */


     /* Menu Bars, Menus, and Menu Items: */

          /* (no menu bars in the resource file) */


     /* Callback Prototypes: */

int  CVICALLBACK Back(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK Main(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK Quit(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);


#ifdef __cplusplus
    }
#endif
