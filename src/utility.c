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
#include <sys/wait.h>

//This file has all the commands that are implemented for the shell

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

//Changing directory function
void change_directory(char** args){
    char cwd[1028];
    if (args[1] != NULL)
            {
                if (chdir(args[1]) == -1){ //checks if chdir is successful
                    printf("No such file or directory\n");
                }
                else {
                    getcwd(cwd, sizeof(cwd)); //get current working directory
                    setenv("PWD", cwd, 1); //set environment variable to current working directory
                }   
            } 
            else 
            {
                printf("%s\n", getenv("PWD"));        
            }
}

//Function that exits the shell
void exit_command(){
    printf("-------------------------------\n");
    printf("| Exiting The Shell, Goodbye! |\n");
    printf("-------------------------------\n");
    exit(0);
}

//Function that prints current working directory
void pwd_command(){
    printf("%s\n", getenv("PWD")); 
}

//Function that lists the contents of the current directory
void dir_command(){
    system("ls -al");
}

//Function that clears the screen
void clr_command(){
    system("clear");
}

//Function that echos the arguments
void echo_command(char** args){ //Feed in the arguments from user input
    int i = 1;
    while (args[i] != NULL){ //Loop through the arguments and print them out
        printf("%s ", args[i]);
        i++;
    }
    printf("\n");
}

//Function that pauses the shell
void pause_command(){
    while (true){
        if (getchar() == '\n'){
            break;
        }
    }
}

//Function that lists all the environment strings
void environ_command(){
    system("env");
}

//Function that executes the command given by the user
void exec_command(char** args){
    pid_t pid = fork(); //child process made
    if (pid == 0){ //if it's a child process
        execvp(args[0], args); //execute the command
        printf("Execution error occurred\n");
        exit(0);
    }
    else if (pid > 0){ //parent process
        wait(NULL); //wait for child process to finish
    }
    else {
        printf("Fork failed\n");
    }
}