/*
Student Name: Razvan Gorea
Student ID: 21306373

I declare that this material, which I now submit for assessment, 
is entirely my own work and has not been taken from the work of others save,
and to the extent that such work has been cited 
and acknowledged within the text of my work. Citations for the code is in the readme.md file*/

//C Libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include "utility.h"

//Main Function for the shell

void shell(int argc, char** argv, FILE *fp, bool batch){
    char user_input[command_len]; //buffer for user input
    char* command_given; //command given by user
    char* args[args_len]; //array of arguments

     while (true) {
        
        set_shell_env(); //sets the shell environment
        
        if (batch == false){//if batch mode is not active
        printf("Shell Active ~%s $ ", getenv("PWD")); //prints current working directory aka commandline
        }

        if (fgets(user_input, command_len, fp) == NULL){
            printf("\n");
            break;
        }
        user_input[strcspn(user_input, "\n")] = '\0';

        //*splits user input into tokens
        input_splitter(user_input, &command_given, args);

        if (command_given == NULL) {
            continue;
        }

        //counter for arguments
        int len = 0;
        for (int i = 0; args[i]; i++) {
            len++;
        }

        //checks if last argument is '&' and runs the command/process in background
        if (strcmp(args[len-1], "&") == 0) {
            args[len-1] = NULL;
            //function call that starts running the process 
            //in the background
            background_process(args); 
        }

        //cd command to change directory
        if (strcmp(command_given, "cd") == 0) 
        {
            change_directory(args);
        } 
        
        //quit command to exit shell
        else if (strcmp(command_given, "quit") == 0) 
        {
            quit_command();
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

        //environ command to list all the environment strings
        else if (strcmp(command_given, "environ") == 0) 
        {
            environ_command();
        }

        //help command to access the user manual
        else if (strcmp(command_given, "help") == 0) 
        {
            help_command();
        }

        else {
            //forks a child process and execs
            exec_command(args);
        }
    }
}