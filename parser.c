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
    
    char    *stringChunk,  //holds the chunks on the input string as we break it up
            *inputStringDuplicate = strdup(inputString),//duplicate input string for editting
            **commandArray = NULL;//this will be an array to hold each of the chunk strings
    int     numberOfChunks=0;
    
                                                    //using http://www.tutorialspoint.com/c_standard_library/c_function_strtok.htm
    stringChunk = strtok(inputStringDuplicate, "-"); // gets the first chunk up to the -
    
    // walk through rest of string
    while( stringChunk != NULL )
    {
        ++numberOfChunks
        //printf( " %s\n", stringChunk );
        commandArray=(char **)realloc(commandArray,numberOfChunks*sizeof(char*);//array of strings
        commandArray[0]=(char *)malloc(sizeof(stringChunk));
        
        stringChunk = strtok(NULL, "-");
    }
    
}

char * strdup(const char * s)
{
    size_t len = 1+strlen(s);
    char *p = malloc(len);
    
    return p ? memcpy(p, s, len) : NULL;//if malloc worked then duplicate the strings
}