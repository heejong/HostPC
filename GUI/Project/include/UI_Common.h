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
#define STACK_MAXSIZE 10  
		
//==============================================================================
// Types

// stack provides data structure with lowest implementation cost to give location along panel tree 
// note this is not a general implementation - limited to int and predefined size
// no need to deal with malloc and void* for this narrow use case
typedef struct Stack {
    int     data[STACK_MAXSIZE]; 
    int     current_size;
} Stack;

//==============================================================================
// External variables

//==============================================================================
// Global functions

int CVICALLBACK Quit (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2);

int CVICALLBACK Main (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2);

int CVICALLBACK Back (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2);

// stack functions
void StackInit(Stack *S);
int StackPeek(Stack *S);
int StackEmpty(Stack *S);
int StackPush(Stack *S, int d);
int StackPop(Stack *S);


#ifdef __cplusplus
    }
#endif

#endif  /* ndef __UI_Common_H__ */
