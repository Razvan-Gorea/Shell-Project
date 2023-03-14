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

int main (int argc, char** argv){
    char user_input[command_len];
    char* command_given;
    char* args[args_len];

     while (true) {
        printf("Shell Active ~%s $ ", getenv("PWD")); //prints current working directory
        
        fgets(user_input, command_len, stdin);
        user_input[strcspn(user_input, "\n")] = '\0';

        // splits user input into tokens
        input_splitter(user_input, &command_given, args);

        if (command_given == NULL) {
            continue;
        }

        //cd command to change directory
        if (strcmp(command_given, "cd") == 0) 
        {
            change_directory(args);
        } 
        
        //exit command to exit shell
        else if (strcmp(command_given, "exit") == 0) 
        {
            exit_command();
        }
        
        //pwd command to print current working directory
        else if (strcmp(command_given, "pwd") == 0) 
        {
            pwd_command(); 
        }

        //dir command to list contents of current directory
        else if (strcmp(command_given, "dir") == 0) 
        {
            dir_command();
        }

        //clr command to clear the screen
        else if (strcmp(command_given, "clr") == 0) 
        {
            clr_command();
        }

        //echo command
        else if (strcmp(command_given, "echo") == 0) 
        {
            echo_command(args);
        }

        //pause command to pause the shell
        else if (strcmp(command_given, "pause") == 0) 
        {
            pause_command();
        }
        
        else 
        {
            //execute command using system()
            //run it on your system
            //caution: it might night work on all systems, and it might be dangerous
            //use this shell at your own risk
            system(user_input);
        }
    }
}