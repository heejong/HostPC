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

typedef struct NodeDescriptor {
	// to make firmware easier, these are all bit-level data structures
	// for example type address stores 16 bits. the first 4 are board type and next 12 are address
	// version number is an int because floats are difficult in VHDL
	unsigned short int type_address;						// node type and absolute address	
	unsigned short int hardware_version_number; 			// hardware version number
	char hardware_version_description[DESCRIPTION_LIMIT];   // description of hardware version (i.e. for test)
	unsigned short int firmware_version_number; 			// firmware version number
	char firmware_version_description[DESCRIPTION_LIMIT];   // description of firmware version (i.e. for test)
	unsigned short int software_version_number; 			// software version number
	char software_version_description[DESCRIPTION_LIMIT];   // description of software version (i.e. for test)
	unsigned short int node_integrity;    					// node integrity (0 functioning; 1-0xFFFF FFFF malfunctioning with error code to specify ADC, etc.)
} NodeDescriptor;

typedef struct OffspringDescriptor {
	unsigned char status;            // offspring connection status - 8 bits: 1 for each child
	unsigned char enable;		     // offspring enable/disable status - 8 bits: 1 for each child
	unsigned short int type_address[8];  // offspring node types and absolute addresses - 8 elements of 16 bits
} OffspringDescriptor;

typedef struct NodeProfile {
	struct NodeDescriptor node_descriptor; 
	struct OffspringDescriptor offspring_descriptor;
	// struct HardwareDescriptor1;    i.e. ADC
	// struct ApplicationSpecificDescriptor;  i.e. Energy Window
	// struct UserDescriptor1;
	
} NodeProfile;

typedef struct OpenPETSystemNode {
	struct NodeProfile profile;   // information about this node
	struct OpenPETSystemNode* child_nodes[8];	   // array of pointers to 8 possible child nodes
} OpenPETSystemNode;



		
//==============================================================================
// External variables

//==============================================================================
// Global functions


OpenPETSystemNode* CreateSystemNode(NodeProfile profile);

OpenPETSystemNode* InsertSystemNode( OpenPETSystemNode *parent, unsigned short int position, NodeProfile profile);

void DisposeAllSystemNodes(OpenPETSystemNode *root);

int OpenPETSystemRead(OpenPETSystemNode *config /*, *data_stream */);

void OpenPETSystemWrite(FILE *output, OpenPETSystemNode *node); 
	
int OpenPETSystemNodeWrite(FILE *output, OpenPETSystemNode *node);

void InitNodeProfileToExampleValues(NodeProfile *profile);

void OpenPETSystemCreateExample(OpenPETSystemNode *root_node, int size);

int IsChildConnected(OpenPETSystemNode *parent, int location);

#ifdef __cplusplus
    }
#endif

#endif  /* ndef __System_Common_H__ */
