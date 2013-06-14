//==============================================================================
//
// Title:       UI_Common.h
// Purpose:     A short description of the interface.
//
// Created on:  6/14/2013 at 10:02:00 AM by PC User.
// Copyright:   Lawrence Berkeley Laboratory. All Rights Reserved.
//
//==============================================================================

#ifndef __UI_Common_H__
#define __UI_Common_H__

#ifdef __cplusplus
    extern "C" {
#endif

//==============================================================================
// Include files

#include "cvidef.h"

//==============================================================================
// Constants

//==============================================================================
// Types

//==============================================================================
// External variables

//==============================================================================
// Global functions

int CVICALLBACK Quit (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2);

#ifdef __cplusplus
    }
#endif

#endif  /* ndef __UI_Common_H__ */
