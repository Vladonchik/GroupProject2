//
//  parser.h
//  
//
//  Created by ben on 07/11/2014.
//
//

#ifndef _parser_h
#define _parser_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum commandType
{
    commandError=-1,
    upgrade=0,
    execute=1,
    set=2,
    man=3,
    cat=4
};
typedef enum commandType commandType;

enum upgradeStat
{
    statError=-1,
    power=0,
    range=1,
    speed=2,
    AOErange=3,
    AOEpower=4
};
typedef enum upgradeStat upgradeStat;


int getAction( const char * inputAction );
char * strdup(const char * s);
void parse(char *inputString);
void freeCommandArray(char **commandArray,int numberOfChunks);
char ** breakUpString(const char * inputString, int *numberOfChunksPtr);
void testCommandArray(char ** commandArray, int numberOfChunks);
void testGetAction(enum commandType action);
void actionUsageError( commandType action, const char ** validActions, int numberOfActions);
upgradeStat getUpgradeStats(const char * inputStringUpgradeStats);



#endif


