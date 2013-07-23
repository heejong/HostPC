//==============================================================================
//
// Title:       System_Common.c
// Purpose:     A short description of the implementation.
//
// Created on:  7/23/2013 at 10:36:21 AM by William Moses.
// Copyright:   Lawrence Berkeley National Laboratory. All Rights Reserved.
//
//==============================================================================

//==============================================================================
// Include files

//#include "System_Common.h"

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
	
	OpenPETSystemWrite(output, node->B0);
	OpenPETSystemWrite(output, node->B1);
	OpenPETSystemWrite(output, node->B2);
	OpenPETSystemWrite(output, node->B3);
	OpenPETSystemWrite(output, node->B4);
	OpenPETSystemWrite(output, node->B5);
	OpenPETSystemWrite(output, node->B6);
	OpenPETSystemWrite(output, node->B7);
	
}

int OpenPETSystemNodeWrite(FILE *output, OpenPETSystemNode *node)
{
	// print 1 node to file
	// fprintf(output, "%d\n", node->node_config.firmware_version);
	// ...
	// fprintf all elements in node_config and profile for a given node
	// fprintf(output, "\n\n");
	// return 0 on success, -1 on failure
}

int OpenPETSystemRead(OpenPETSystemNode *config /*, *data_stream */) 
{
	// this function will need to be rewritten to read from the USB data stream
	// once that data format has been specified
	// should first determine if Small, Medium, or Large setup
	// then, fill in appropriate look up table
	// return 0 if successful and -1 if it fails to open the stream, etc.
	
	// for now, simply read in dummy values
	OffspringProfile profile;
	NodeConfiguration node_config;
	OpenPETSystemNode *MB, *DUC, *DB;	
	unsigned short int MB_status[8] = {1,1,0,0,0,0,0,0};
	unsigned short int ones[8] = {1,1,1,1,1,1,1,1};
	unsigned short int type_address[16] = {0};
	int i, j, k;
	
	memcpy(node_config.type_address, type_address, sizeof(type_address));	
	node_config.firmware_version = 1;
	node_config.software_version = 1;
	node_config.node_integrity = 1;

	memcpy(profile.status, MB_status, sizeof(profile.status));
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
		// in real function, should read in MB profile
		profile.type_address[0]=0;
		profile.type_address[1]=0;
		profile.type_address[2]=0;
		profile.type_address[3]=1;
		MB = InsertSystemNode(sys_config1, i, profile);
		for(j=0; j<7; j++)
		{
			// in real function, should read each DUC profile
			profile.type_address[0]=0;
			profile.type_address[1]=0;
			profile.type_address[2]=1;
			profile.type_address[3]=0;
			DUC = InsertSystemNode(MB, j, profile);
			for(k=0; k<7; k++)
			{
				// in real function, should read each DB profile
				profile.type_address[0]=0;
				profile.type_address[1]=0;
				profile.type_address[2]=1;
				profile.type_address[3]=1;
				DB = InsertSystemNode(DUC, k, profile);	
			}
		}
	}
	
	
	return 0;
	
	
}

OpenPETSystemNode* CreateSystemNode(OffspringProfile profile) 
{
	OpenPETSystemNode *new_node = (OpenPETSystemNode*) malloc(sizeof(OpenPETSystemNode));
	if(new_node == NULL)
	{
		fprintf(stderr, "Error: Unable to allocate memory for OpenPETSystemNode in CreateSystemNode()\n");
		exit(1);
	}
	new_node->profile = profile;
	new_node->B0 = NULL;
	new_node->B1 = NULL;
	new_node->B2 = NULL;
	new_node->B3 = NULL;
	new_node->B4 = NULL;
	new_node->B5 = NULL;
	new_node->B6 = NULL;
	new_node->B7 = NULL;
	
	return new_node;
}


OpenPETSystemNode* InsertSystemNode( OpenPETSystemNode *root, unsigned short int position, OffspringProfile profile)
{
	if(root == NULL) 
	{
		root = CreateSystemNode(profile);
		return root;
	}
	else 
	{
		switch(position)
		{
			case 0:
				root->B0 = CreateSystemNode(profile);
				return root->B0;
			case 1:
				root->B1 = CreateSystemNode(profile);
				return root->B1;
			case 2:
				root->B2 = CreateSystemNode(profile);
				return root->B2;
			case 3:
				root->B3 = CreateSystemNode(profile);
				return root->B3;
			case 4:
				root->B4 = CreateSystemNode(profile);
				return root->B4;
			case 5:
				root->B5 = CreateSystemNode(profile);
				return root->B5;
			case 6:
				root->B6 = CreateSystemNode(profile);
				return root->B6;
			case 7:
				root->B7 = CreateSystemNode(profile);
				return root->B7;
			default:
				fprintf(stderr, "Error: System nodes must be placed in position [0-7]. Illegal placement input to InsertSystemNode()");
				exit(1);
		}
	}
	
	return root;
		
}

void DisposeAllSystemNodes(OpenPETSystemNode *root) 
{
	// clean up all memory by recursively removing all system nodes
	if(root != NULL)
	{
		DisposeAllSystemNodes( root->B0 );		
		DisposeAllSystemNodes( root->B1 );
		DisposeAllSystemNodes( root->B2 );
		DisposeAllSystemNodes( root->B3 );
		DisposeAllSystemNodes( root->B4 );
		DisposeAllSystemNodes( root->B5 );
		DisposeAllSystemNodes( root->B6 );
		DisposeAllSystemNodes( root->B7 );
		
		free( root );
	}
}


