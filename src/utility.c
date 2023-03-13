/*
Student Name: Razvan Gorea
Student ID: 21306373

I declare that this material, which I now submit for assessment, 
is entirely my own work and has not been taken from the work of others save,
and to the extent that such work has been cited 
and acknowledged within the text of my work.*/

//C Libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include "utility.h"

//function that splits user input into tokens
void input_splitter(char* user_input, char** command_given, char** args) {
    char* tokens;
    int i = 0;

    //check whether length is zero and set command given to NULL
    if (strlen(user_input) == 0) 
    {
        *command_given = NULL;
        return;
    }

    // split input into tokens based on whitespace
    tokens = strtok(user_input, " \n");
    
    //first token passed is the command
    *command_given = tokens;

    //tokens left over become the rest of the arguments
    while (tokens != NULL && i < args_len) {
        args[i] = tokens;
        i++;
        tokens = strtok(NULL, " \n");
    }

    //NULL terminator placed at the end of the args array
    args[i] = NULL;
}