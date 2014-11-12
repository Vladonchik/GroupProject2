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
#include ".headers/parser.h"
#include ".headers/actionQueueDataStructure.h"

/*---------- Data Types -----------*/

struct queueNode {
	
	commandType command; //command for execution
	upgradeStat option; //stat to change
	int target;	//target of command
    struct queueNode *nextNode;

};

struct actionQueueStructure  {

    struct queueNode *start;
    struct queueNode *current;
    int nItems;

};

int main()	{

	ActionQueueStructure newStack = createActionQueue(1);
	pushToQueue(newStack,10);
	pushToQueue(newStack,20);
	pushToQueue(newStack,30);
	iprint(popFromQueue(newStack));
	iprint(popFromQueue(newStack));
}


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

int pushToQueue(ActionQueueStructure queue, commandType command, upgradeStat option, int target)	{
	
	if(queue->current != NULL)	{
		queue->current->nextNode = createNode();
		queue->current->command = command;
		queue->current->option = option;
		queue->current->target = target;
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
