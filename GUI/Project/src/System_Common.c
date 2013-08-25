//==============================================================================
//
// Title:       System_Common.c
// Purpose:     A short description of the implementation.
//
// Created on:  7/23/2013 at 10:36:21 AM by William Moses.
// Copyright:   Lawrence child_nodeerkeley National Laboratory. All Rights Reserved.
//
//==============================================================================

//==============================================================================
// Include files
#include <ansi_c.h>
#include "System_Common.h"

//==============================================================================
// Constants

//==============================================================================
// Types

//==============================================================================
// Static global variables

//==============================================================================
// Static functions

//==============================================================================
// Global variables
OpenPETSystemNode *sys_config1;		  // used to show the full system tree 

//==============================================================================
// Global functions



void OpenPETSystemWrite(FILE *output, OpenPETSystemNode *node) 
{
	// need to decide if this will be XML or not
	// write system tree to file 
	// depth-first recursive print
	if(node == NULL) 
	{
		// recursion end condition
		return;
	}
	
	OpenPETSystemNodeWrite(output, node);
	
	OpenPETSystemWrite(output, node->child_nodes[0]);
	OpenPETSystemWrite(output, node->child_nodes[1]);
	OpenPETSystemWrite(output, node->child_nodes[2]);
	OpenPETSystemWrite(output, node->child_nodes[3]);
	OpenPETSystemWrite(output, node->child_nodes[4]);
	OpenPETSystemWrite(output, node->child_nodes[5]);
	OpenPETSystemWrite(output, node->child_nodes[6]);
	OpenPETSystemWrite(output, node->child_nodes[7]);
	
}

int OpenPETSystemNodeWrite(FILE *output, OpenPETSystemNode *node)
{
	// print 1 node to file
	// fprintf(output, "%d\n", node->node_descriptor.firmware_version);
	// ...
	// fprintf all elements in node_descriptor and profile for a given node
	// fprintf(output, "\n\n");
	// return 0 on success, -1 on failure
	return 0;
}

int OpenPETSystemRead(OpenPETSystemNode *config /*, *data_stream */) 
{
	// this function will need to be written to read from the USB data stream
	// once that data format has been specified, and generate the proper
	// system configuration as a tree of OpenPETSytemNodes

	// return 0 if successful and -1 if it fails to open the stream, etc.
	
	return 0;
}

void InitNodeProfileToExampleValues(NodeProfile *profile)
{
	// only ysed to support OpenPETSystemCreateExample()
	// completely useless for actual GUI
	strcpy(profile->node_descriptor.hardware_version_description ,"Example");
	profile->node_descriptor.hardware_version_number = 1;
	strcpy(profile->node_descriptor.firmware_version_description ,"Example");
	profile->node_descriptor.firmware_version_number = 1;
	strcpy(profile->node_descriptor.software_version_description ,"Example");
	profile->node_descriptor.software_version_number = 1;
	profile->node_descriptor.node_integrity = 0;
	return;
}

void OpenPETSystemCreateExample(OpenPETSystemNode *root_node) 
{
	// This function is used just to generate an example tree data structure.
	// From this function the example system configuration file can be created,
	// but when the final GUI is complete, this function will not be necessary
	
	// node structures
	NodeProfile CUC_profile, MB_profile, DUC_profile, DB_profile;
	OpenPETSystemNode *MB, *DUC, *DB;
	
	// type address arrays
	unsigned short int CUC_offspring_type_address[8] = {0x1000, 0x1000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000};
	unsigned short int MB_offspring_type_address[8] = {0x2000, 0x2000, 0x2000, 0x2000, 0x2000, 0x2000, 0x2000, 0x2000}; 
	unsigned short int DUC_offspring_type_address[8] = {0x3000, 0x3000, 0x3000, 0x3000, 0x3000, 0x3000, 0x3000, 0x3000};  

	// fill in node descriptors 
	// for type address, just fill in absolute address with zeros but mark first 4 bits with type
	CUC_profile.node_descriptor.type_address = 0x0000;  // 0000 = CUC
	MB_profile.node_descriptor.type_address = 0x1000;   // 0001 = MB
	DUC_profile.node_descriptor.type_address = 0x2000;  // 0010 = DUC
	DB_profile.node_descriptor.type_address = 0x3000;   // 0011 = DB
	InitNodeProfileToExampleValues(&CUC_profile);      
	InitNodeProfileToExampleValues(&MB_profile);	    // just initialize to example values
	InitNodeProfileToExampleValues(&DUC_profile);
	InitNodeProfileToExampleValues(&DB_profile);
	
	// fill in offspring descriptors
	CUC_profile.offspring_descriptor.status = 0xF0;   // 1111 0000 = 4 boards attached
	CUC_profile.offspring_descriptor.enable = 0xF0;   // used for MB
	memcpy(CUC_profile.offspring_descriptor.type_address, CUC_offspring_type_address, sizeof(CUC_offspring_type_address));
	MB_profile.offspring_descriptor.status = 0xFF;    // 1111 1111 = 8 boards attached
	MB_profile.offspring_descriptor.enable = 0xFF;    // used for DUC
	memcpy(MB_profile.offspring_descriptor.type_address, MB_offspring_type_address, sizeof(MB_offspring_type_address));
	DUC_profile.offspring_descriptor.status = 0xFF;   // 1111 1111 = 8 boards attached
	DUC_profile.offspring_descriptor.enable = 0xFF;   // used for DB
	memcpy(DUC_profile.offspring_descriptor.type_address, DUC_offspring_type_address, sizeof(DUC_offspring_type_address));  	
	DB_profile.offspring_descriptor.status = 0x00;    // 0000 0000 = 0 boards attached
	DB_profile.offspring_descriptor.enable = 0x00;    // no boards attached to DB
	
	// local variables
	int i, j, k;

	//add nodes
	sys_config1 = InsertSystemNode(sys_config1, 0, CUC_profile);
	
	for(i=0; i<4; i++)
	{
		// in real function, should read in MB profile
		MB = InsertSystemNode(sys_config1, i, MB_profile);
		for(j=0; j<7; j++)
		{
			// in real function, should read each DUC profile
			DUC = InsertSystemNode(MB, j, DUC_profile);
			for(k=0; k<7; k++)
			{
				// in real function, should read each DB profile
				DB = InsertSystemNode(DUC, k, DB_profile);	
			}
		}
	}
	
	
	return;
}

OpenPETSystemNode* CreateSystemNode(NodeProfile profile) 
{
	OpenPETSystemNode *new_node = (OpenPETSystemNode*) malloc(sizeof(OpenPETSystemNode));
	if(new_node == NULL)
	{
		fprintf(stderr, "Error: Unable to allocate memory for OpenPETSystemNode in CreateSystemNode()\n");
		exit(1);
	}
	new_node->profile = profile;
	new_node->child_nodes[0] = NULL;
	new_node->child_nodes[1] = NULL;
	new_node->child_nodes[2] = NULL;
	new_node->child_nodes[3] = NULL;
	new_node->child_nodes[4] = NULL;
	new_node->child_nodes[5] = NULL;
	new_node->child_nodes[6] = NULL;
	new_node->child_nodes[7] = NULL;
	
	return new_node;
}


OpenPETSystemNode* InsertSystemNode( OpenPETSystemNode *root_node, unsigned short int position, NodeProfile profile)
{
	if(root_node == NULL) 
	{
		root_node = CreateSystemNode(profile);
		return root_node;
	}
	else 
	{
		switch(position)
		{
			case 0:
				root_node->child_nodes[0] = CreateSystemNode(profile);
				return root_node->child_nodes[0];
			case 1:
				root_node->child_nodes[1] = CreateSystemNode(profile);
				return root_node->child_nodes[1];
			case 2:
				root_node->child_nodes[2] = CreateSystemNode(profile);
				return root_node->child_nodes[2];
			case 3:
				root_node->child_nodes[3] = CreateSystemNode(profile);
				return root_node->child_nodes[3];
			case 4:
				root_node->child_nodes[4] = CreateSystemNode(profile);
				return root_node->child_nodes[4];
			case 5:
				root_node->child_nodes[5] = CreateSystemNode(profile);
				return root_node->child_nodes[5];
			case 6:
				root_node->child_nodes[6] = CreateSystemNode(profile);
				return root_node->child_nodes[6];
			case 7:
				root_node->child_nodes[7] = CreateSystemNode(profile);
				return root_node->child_nodes[7];
			default:
				fprintf(stderr, "Error: System nodes must be placed in position [0-7]. Illegal placement input to InsertSystemNode()");
				exit(1);
		}
	}
	
	return root_node;
		
}

void DisposeAllSystemNodes(OpenPETSystemNode *root_node) 
{
	// clean up all memory by recursively removing all system nodes
	if(root_node != NULL)
	{
		DisposeAllSystemNodes( root_node->child_nodes[0] );		
		DisposeAllSystemNodes( root_node->child_nodes[1] );
		DisposeAllSystemNodes( root_node->child_nodes[2] );
		DisposeAllSystemNodes( root_node->child_nodes[3] );
		DisposeAllSystemNodes( root_node->child_nodes[4] );
		DisposeAllSystemNodes( root_node->child_nodes[5] );
		DisposeAllSystemNodes( root_node->child_nodes[6] );
		DisposeAllSystemNodes( root_node->child_nodes[7] );
		
		free( root_node );
	}
}


