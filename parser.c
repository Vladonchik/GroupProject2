//
//  paser.c
//  The parser needs to accept a string from the text input
//
//  Created by ben on 07/11/2014.
//
//

#include <stdio.h>
#include "parser.h"

void parse(char *inputString)
{
    int numberOfChunks;
    char **commandArray = breakUpString(inputString, &numberOfChunks);
    
    //testCommandArray(commandArray, numberOfChunks);
    
    enum commandType action = getAction(commandArray[0]);//the first string in the command should contain the action
    if(action==ERROR)//if getAction returns ERROR then the input as invalid
    {                //Error messaging handled in getAction function
        return;
    }
    
    //testGetAction(action);
    
    
    freeCommandArray(commandArray, numberOfChunks);
}

/* Takes the first string of the input command and tests it against the correct syntax to find which command they want to execute  */
enum commandType getAction( const char * inputAction )
{
    /*first lets make an array of strings to hold all the possible action commands*/
    const char **validActions;
    int numberOfActions=5;//have 5 action commands at this time: upgrade, execute, set, man, cat
    validActions=(const char **)malloc(numberOfActions*sizeof(char*));//array of $[numberOfActions] strings
    validActions[0]="upgrade";
    validActions[1]="execute";
    validActions[2]="set";
    validActions[3]="man";
    validActions[4]="cat";
    
    enum commandType action = ERROR;
    for(int i=0; i<numberOfActions; ++i)
    {
        if(strcmp(inputAction,validActions[i])==0)
        {
            switch (i)
            {
                case 0:
                    action = upgrade;
                    return action;
                case 1:
                    action = execute;
                    return action;
                case 2:
                    action = set;
                    return action;
                case 3:
                    action = man;
                    return action;
                case 4:
                    action = cat;
                    return action;
                
            }
        }
    }
    
    if(action==ERROR)
    {
        fprintf(stderr,"*** Action not recognised ***\n");
        fprintf(stderr,"Possible commands: \n");
        for(int i=0; i<numberOfActions; ++i)
        {
            fprintf(stderr,"%s\n",validActions[i]);
        }
        fprintf(stderr,"\nType man [COMMAND] for usage\n");
    }
    free(validActions);
    return action;
}

/* Takes the input string and breaks into separate words (where there is a space and new string starts) each of these words is stored in the commandArray which is an array of strings*/
char **breakUpString(const char * inputString, int *numberOfChunksPtr)
{
    char    *stringChunk,  //holds the chunks on the input string as we break it up
            *inputStringDuplicate = strdup(inputString),//duplicate input string for editting
            **commandArray = NULL;//this will be an array to hold each of the chunk strings
    int     numberOfChunks=0;
    
    //using http://www.tutorialspoint.com/c_standard_library/c_function_strtok.htm
    stringChunk = strtok(inputStringDuplicate, " "); // gets the first chunk (up to the first space)
    
    // walk through rest of string
    while( stringChunk != NULL )
    {
        ++numberOfChunks;
        commandArray=(char **)realloc(commandArray,numberOfChunks*sizeof(char*));//array of strings
        commandArray[numberOfChunks-1]=(char *)malloc((size_t)(strlen(stringChunk)*sizeof(char)+1));
        strcpy(commandArray[numberOfChunks-1],stringChunk);
        
        stringChunk = strtok(NULL, " ");
    }
    free(inputStringDuplicate);//frees the malloc made in strdup()
    //$(numberOfChunks) strings now stored in the commandArray
    *numberOfChunksPtr=numberOfChunks;
    return commandArray;
}

/* duplicates a string */
char *strdup(const char * s)
{
    size_t len = 1+strlen(s);
    char *p = malloc(len);
    
    return p ? memcpy(p, s, len) : NULL;//if malloc worked then duplicate the strings
}

/*frees the memory allocated in breakup string funct*/
void freeCommandArray(char **commandArray,int numberOfChunks)
{
    for(int i=0; i<numberOfChunks; ++i)
    {
        free(commandArray[i]);
    }
    free(commandArray);
}

/* test function. Prints contents of commandArray*/
void testCommandArray(char ** commandArray, int numberOfChunks)
{
    for(int i=0; i<numberOfChunks; ++i)
    {
        printf("%s",commandArray[i]);
        printf("|\n");
    }
}

void testGetAction(enum commandType action)
{
    /*first lets make an array of strings to hold all the possible action commands*/
    const char **validActions;
    int numberOfActions=5;//have 5 action commands at this time: upgrade, execute, set, man, cat
    validActions=(const char **)malloc(numberOfActions*sizeof(char*));//array of $[numberOfActions] strings
    validActions[0]="upgrade";
    validActions[1]="execute";
    validActions[2]="set";
    validActions[3]="man";
    validActions[4]="cat";
    printf("****testGetAction****\n");
    printf("read action: %s\n", validActions[action]);
}