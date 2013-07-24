//==============================================================================
//
// Title:       System_Common.h
// Purpose:     A short description of the interface.
//
// Created on:  7/23/2013 at 10:36:21 AM by William Moses.
// Copyright:   Lawrence Berkeley National Laboratory. All Rights Reserved.
//
//==============================================================================

#ifndef __System_Common_H__
#define __System_Common_H__

#ifdef __cplusplus
    extern "C" {
#endif

//==============================================================================
// Include files

#include "cvidef.h"

//==============================================================================
// Constants
#define DESCRIPTION_LIMIT 32

//==============================================================================
// Types

typedef struct Node {
	struct NodeProfile profile;
	
	struct Node *B0;
	struct Node *B1;
	struct Node *B2;
	struct Node *B3;
	struct Node *B4;
	struct Node *B5;
	struct Node *B6;
	struct Node *B7;
	
} OpenPETSystemNode;

typedef struct NodeProfile {
	struct NodeDescriptor node_config; 
	struct OffspringDescriptor offspring_profile;
	// struct HardwareDescriptor1;    i.e. ADC
	// struct ApplicationSpecificDescriptor;  i.e. Energy Window
	// struct UserDescriptor1;
	
	
}

typedef struct NodeConfiguration {
	// to make firmware easier, these are all bit-level data structures
	// for example type address stores 16 bits. the first 4 are board type and next 12 are address
	// version number is an int because floats are difficult in VHDL
	unsigned short int type_address;						// node type and absolute address	
	unsigned short int firmware_version_number; 			// hardware version number
	char hardware_version_description[DESCRIPTION_LIMIT];   // description of hardware version (i.e. for test)
	unsigned short int firmware_version_number; 			// firmware version number
	char firmware_version_description[DESCRIPTION_LIMIT];   // description of firmware version (i.e. for test)
	unsigned short int firmware_version_number; 			// software version number
	char software_version_description[DESCRIPTION_LIMIT];   // description of software version (i.e. for test)
	unsigned short int node_integrity;    					// node integrity (0 functioning; 1-0xFFFF FFFF malfunctioning with error code to specify ADC, etc.)
} NodeConfiguration;

typedef struct OffspringProfile {
	unsigned char status;            // offspring connection status - 8 bits: 1 for each child
	unsigned char enable;		     // offspring enable/disable status - 8 bits: 1 for each child
	unsigned short int type_address[8];  // offspring node types and absolute addresses - 8 elements of 16 bits
} OffspringProfile;

		
//==============================================================================
// External variables

//==============================================================================
// Global functions


OpenPETSystemNode* CreateSystemNode(OffspringProfile profile);

OpenPETSystemNode* InsertSystemNode( OpenPETSystemNode *parent, unsigned short int position, OffspringProfile profile);

void DisposeAllSystemNodes(OpenPETSystemNode *root);

#ifdef __cplusplus
    }
#endif

#endif  /* ndef __System_Common_H__ */
