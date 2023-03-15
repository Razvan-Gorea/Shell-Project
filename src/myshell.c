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
#include "shellcontainer.h"

//This is the main file for the entire shell

int main (int argc, char** argv){
    if (argc == 1)
    {
    shell(argc, argv, stdin);
    }
    else {
        FILE* fp = fopen(argv[1], "r");
        shell(argc, argv, fp);
    }
}