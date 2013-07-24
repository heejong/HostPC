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
	
	OpenPETSystemWrite(output, node->child_node0);
	OpenPETSystemWrite(output, node->child_node1);
	OpenPETSystemWrite(output, node->child_node2);
	OpenPETSystemWrite(output, node->child_node3);
	OpenPETSystemWrite(output, node->child_node4);
	OpenPETSystemWrite(output, node->child_node5);
	OpenPETSystemWrite(output, node->child_node6);
	OpenPETSystemWrite(output, node->child_node7);
	
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
	// this function will need to be rewritten to read from the USchild_node data stream
	// once that data format has been specified
	// should first determine if Small, Medium, or Large setup
	// then, fill in appropriate look up table
	// return 0 if successful and -1 if it fails to open the stream, etc.
	
	// for now, simply read in dummy values
	NodeProfile profile;
	NodeDescriptor node_descriptor;
	OpenPETSystemNode *Mchild_node, *DUC, *Dchild_node;	
	unsigned short int Mchild_node_status[8] = {1,1,0,0,0,0,0,0};
	unsigned short int ones[8] = {1,1,1,1,1,1,1,1};
	unsigned short int type_address[16] = {0};
	int i, j, k;
	/*
	memcpy(node_descriptor.type_address, type_address, sizeof(type_address));	
	node_descriptor.firmware_version = 1;
	node_descriptor.software_version = 1;
	node_descriptor.node_integrity = 1;

	memcpy(profile.status, Mchild_node_status, sizeof(profile.status));
	memcpy(profile.enable, ones, sizeof(ones));
	memcpy(profile.type_address, type_address, sizeof(type_address));
	
	
	profile.type_address[0]=0;
	profile.type_address[1]=0;
	profile.type_address[2]=0;
	profile.type_address[3]=0;
		
	//add nodes
	sys_config1 = InsertSystemNode(sys_config1, 0, profile);
	for(i=0; i<2; i++)
	{
		// in real function, should read in Mchild_node profile
		profile.type_address[0]=0;
		profile.type_address[1]=0;
		profile.type_address[2]=0;
		profile.type_address[3]=1;
		Mchild_node = InsertSystemNode(sys_config1, i, profile);
		for(j=0; j<7; j++)
		{
			// in real function, should read each DUC profile
			profile.type_address[0]=0;
			profile.type_address[1]=0;
			profile.type_address[2]=1;
			profile.type_address[3]=0;
			DUC = InsertSystemNode(Mchild_node, j, profile);
			for(k=0; k<7; k++)
			{
				// in real function, should read each Dchild_node profile
				profile.type_address[0]=0;
				profile.type_address[1]=0;
				profile.type_address[2]=1;
				profile.type_address[3]=1;
				Dchild_node = InsertSystemNode(DUC, k, profile);	
			}
		}
	}
	
	 */
	return 0;
	
	
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
	new_node->child_node0 = NULL;
	new_node->child_node1 = NULL;
	new_node->child_node2 = NULL;
	new_node->child_node3 = NULL;
	new_node->child_node4 = NULL;
	new_node->child_node5 = NULL;
	new_node->child_node6 = NULL;
	new_node->child_node7 = NULL;
	
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
				root_node->child_node0 = CreateSystemNode(profile);
				return root_node->child_node0;
			case 1:
				root_node->child_node1 = CreateSystemNode(profile);
				return root_node->child_node1;
			case 2:
				root_node->child_node2 = CreateSystemNode(profile);
				return root_node->child_node2;
			case 3:
				root_node->child_node3 = CreateSystemNode(profile);
				return root_node->child_node3;
			case 4:
				root_node->child_node4 = CreateSystemNode(profile);
				return root_node->child_node4;
			case 5:
				root_node->child_node5 = CreateSystemNode(profile);
				return root_node->child_node5;
			case 6:
				root_node->child_node6 = CreateSystemNode(profile);
				return root_node->child_node6;
			case 7:
				root_node->child_node7 = CreateSystemNode(profile);
				return root_node->child_node7;
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
		DisposeAllSystemNodes( root_node->child_node0 );		
		DisposeAllSystemNodes( root_node->child_node1 );
		DisposeAllSystemNodes( root_node->child_node2 );
		DisposeAllSystemNodes( root_node->child_node3 );
		DisposeAllSystemNodes( root_node->child_node4 );
		DisposeAllSystemNodes( root_node->child_node5 );
		DisposeAllSystemNodes( root_node->child_node6 );
		DisposeAllSystemNodes( root_node->child_node7 );
		
		free( root_node );
	}
}


