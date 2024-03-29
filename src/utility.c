//C Libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include "utility.h"
#include <sys/wait.h>
#include "shellcontainer.h"
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
void quit_command(){
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
void exec_command(char** args)
{
    pid_t pid = fork(); //child process made
    if (pid == 0){ //if it's a child process
        setenv("parent", getenv("shell"), 1);//sets the parent environment variable
        execvp(args[0], args); //execute the command
        printf("Execution error occurred or command doesn't exist\n");
        exit(0);
    }
    else if (pid > 0){ //parent process
        wait(NULL); //wait for child process to finish
    }
    else {
        printf("Fork failed\n");
    }
}

//Function that sets the shell environment
void set_shell_env()
{
    char buf[100];
    readlink("/proc/self/exe", buf, sizeof(buf));
    setenv("shell", buf, 1); //set environment variable to current working directory
}

//Function that enables background processing and execution
void background_process(char** args)
{
    pid_t pid = fork(); //child process made
    if (pid == 0)
    { //if it's a child process
        setenv("parent", getenv("shell"), 1);//sets the parent environment variable
        execvp(args[0], args); //execute the command
        printf("Execution error occurred or command doesn't exist\n");
        exit(0);
    }
    else if (pid > 0)
    { //parent process
        printf("Background Process Started\n");
        printf("Unique Process ID: %d\n", pid);
    }
    else 
    {
        printf("Fork failed\n");
    }
}

//Function that prints the user manual (readme.md from the manual directory) to the commandline
void help_command()
{
    char line[500];
    FILE *man; //file pointer to the readme.md file

    man = fopen("/home/razvan/2023-ca216-myshell/manual/readme.md", "r"); //pointer opens file
    
    if (man == NULL)//checks if the pointer is NULL
    {
        printf("File couldn't be opened.\n");
    }

    while (fgets(line, 500, man) != NULL)//reads the file line by line
    {
        printf("%s", line);//prints the lines of the file one by one
    }

    fclose(man);//closes the file
}
