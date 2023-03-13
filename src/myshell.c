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

int main (){
    char user_input[command_len];
    char* command_given;
    char* args[args_len];
    char cwd[1028];

     while (true) {
        printf("Shell Active ~%s $ ", getenv("PWD"));
        fgets(user_input, command_len, stdin);
        user_input[strcspn(user_input, "\n")] = '\0';

        // splits input into tokens
        input_splitter(user_input, &command_given, args);

        if (command_given == NULL) {
            continue;
        }

        //cd command
        if (strcmp(command_given, "cd") == 0) 
        {
            if (args[1] != NULL)
            {
                if (chdir(args[1]) == -1){
                    printf("No such directory\n");
                }
                else {
                    getcwd(cwd, sizeof(cwd));
                    setenv("PWD", cwd, 1);
                }   
            } 
            else 
            {
                printf("%s\n", getenv("PWD"));        
            }
        
        } 
        //exit command
        else if (strcmp(command_given, "exit") == 0) 
        {
            printf("Exiting The Shell\n");
            exit(0);
        
        }
        //pwd command
        else if (strcmp(command_given, "pwd") == 0) 
        {
            printf("%s\n", getenv("PWD")); 
        
        } 
        else 
        {
            // execute command using system()
            //run it on your system
            system(user_input);
        }
    }
}