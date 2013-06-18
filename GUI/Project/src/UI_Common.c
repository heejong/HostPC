#include <ansi_c.h>
#include "Analysis_TestMode_MB.h"
#include "Analysis_TestMode2.h"
#include <userint.h>
//==============================================================================
//
// Title:       UI_Common.c
// Purpose:     A short description of the implementation.
//
// Created on:  6/14/2013 at 10:02:00 AM by PC User.
// Copyright:   Lawrence Berkeley Laboratory. All Rights Reserved.
//
//==============================================================================

//==============================================================================
// Include files

#include "UI_Common.h"
#include "OpenPET.h" 

//==============================================================================
// Constants

//==============================================================================
// Types

//==============================================================================
// Static global variables
extern int panelHandle;

//==============================================================================
// Static functions

//==============================================================================
// Global variables
Stack panel_stack;

//==============================================================================
// Global functions


int CVICALLBACK Quit (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			QuitUserInterface (0);
			break;
	}
	return 0;
}

int CVICALLBACK Main (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			DisplayPanel (panelHandle);
			while(!StackEmpty(&panel_stack)) {
				StackPop(&panel_stack);
			}
			HidePanel (panel);
			break;
	}
	return 0;
}

int CVICALLBACK Back (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			DisplayPanel (StackPop(&panel_stack));
			HidePanel (panel);
			break;
	}
	return 0;
}

// initalizes stack
void StackInit(Stack *S)
{
    S->current_size = 0;
}

// returns top value on success and -1 on failure
// does not change stack structure
int StackPeek(Stack *S)
{
    if (S->current_size == 0) {
		// stack empty
		fprintf(stderr, "Error: empty stack found in call to Stack_Top()\n");
        return -1;
    } 

    return S->data[S->current_size-1];
}

// retuns 1 if empty 0 if not
int StackEmpty(Stack *S)
{
	if (S->current_size == 0) {
		return 1;  // true
    } else {
		return 0;  // false
	}
}
	

// returns 0 on succcess and -1 on failure
int StackPush(Stack *S, int d)
{
    if (S->current_size < STACK_MAXSIZE) {
        S->data[S->current_size] = d;
		S->current_size++;
		return 0;
	} else {
        fprintf(stderr, "Error: exceeded stack range on attempt to push\n");
		return -1;
	}
}

// returns popped value on success and -1 on failure
int StackPop(Stack *S)
{
    if (S->current_size == 0) {
        fprintf(stderr, "Error: empty stack found on attempt to pop\n");
		return -1;
	} else {
        S->current_size--;
		return S->data[S->current_size];
	}
}
