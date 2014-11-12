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

struct queueNode {

    int num;
    struct queueNode *nextNode;

};

struct actionQueueStructure  {

    struct queueNode *start;
    struct queueNode *current;
    int nItems;

};

//int main()	{

//	ActionQueueStructure newStack = createActionQueue(1);
//	int i;
//	for(i = 0; i < 10; i++)	{
//		iprint(pushToQueue(newStack,i));		
//		iprint(popFromQueue(newStack));
//	}

//}


/*---------- Functions ----------*/

ActionQueueStructure createActionQueue(int size )	{

	ActionQueueStructure newActionQueue = (ActionQueueStructure) malloc(sizeof(*newActionQueue));
	newActionQueue->nItems = 0;
	QueueNode firstNode;
	newActionQueue->start = newActionQueue->current = firstNode = (QueueNode) malloc(sizeof(*firstNode));
	
	int	i;

	for (i = 0; i < size; i++)	{

		newActionQueue->current->nextNode = createNode();
		newActionQueue->current = newActionQueue->current->nextNode;

	}
	newActionQueue->current = newActionQueue->start;
	return newActionQueue;
}

QueueNode createNode()	{
	QueueNode newNode = (QueueNode) malloc(sizeof(*newNode));
	newNode->num = 0;
	newNode->nextNode = NULL;
	return newNode;

}

int pushToQueue(ActionQueueStructure queue, int newData)	{
	
	if(queue->current != NULL)	{
		queue->current->nextNode = createNode();
		queue->current->num = newData;
		queue->current = queue->current->nextNode;
		(queue->nItems)++;
		return (queue->nItems);
		}
	return 0;
}

int popFromQueue(ActionQueueStructure queue)	{

	int data = queue->start->num;
	QueueNode tempStart = queue->start;
	queue->start = queue->start->nextNode;	
	free(tempStart);	
	--(queue->nItems);
	return data;
}
