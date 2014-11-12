//
// sputFunctions.c
// Created by bclarke on 2014/09/11
// tags: stack, abstraction, struct pointers
//
/*---------- Standard Headers -----------*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*---------- Custom Headers	-----------*/

#include ".headers/debug.h"
#include ".headers/sputFunctions.h"

/*---------- Data Types -----------*/


//int main()	{

//	StackStructure newStack = createStack(10);
//	int i;
//	for(i = 0; i < 10; i++)	{
//		iprint(newStack->current->num);
//		newStack->current = newStack->current->nextNode;
//	}

//}


/*---------- Functions ----------*/

StackStructure createStack(int size )	{

	StackStructure createdStack = (StackStructure) malloc(sizeof(StackStructure*));
	createdStack->nItems = 0;
	StackNode firstNode;
	createdStack->start = createdStack->current = firstNode = (StackNode) malloc(sizeof(StackNode*));
	
	int	i;

	for (i = 0; i < size; i++)	{

		createdStack->current->nextNode = createNode();
		createdStack->current = createdStack->current->nextNode;

	}
	createdStack->current = createdStack->start;
	return createdStack;
}

StackNode createNode()	{

	StackNode newNode = (StackNode) malloc(sizeof(StackNode*));
	newNode->num = 0;
	newNode->nextNode = NULL;
	return newNode;

}
