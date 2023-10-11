# User Manual

## Built-in Shell Commands

### CD - Change Directory

The `cd` command changes the current working directory of the shell. It takes a single argument, which is the path to the new working directory. If no argument is given, the current working directory is printed to the commandline.

### ECHO - Print to Commandline

The `echo` command prints its arguments to the commandline. It takes any number of arguments, which are printed to the commandline separated by a single space.

### QUIT - Exit the Shell

The `quit` command exits the shell. It takes no arguments.

### CLR - Clear the Terminal Window/Screen

The `clr` command clears the terminal window/screen. It takes no arguments.

### DIR - List Directory Contents

The `dir` command lists the contents of the current working directory. It takes no arguments.
Works the same as the `ls -al` command on Linux.

### PWD - Print Working Directory

The `pwd` command prints the current working directory. It takes no arguments.

### ENVIRON - List Environment Variables

The `environ` command lists the environment variables. It takes no arguments.

### HELP - Displays User Manual

The `help` command displays the user manual to the commandline. It takes no arguments.

### PAUSE - Pauses the Operation of the Shell

The `pause` command pauses the operation of the shell until the user presses the enter key. It takes no arguments.

---

## Shell Environment

This Shell is a command-line interpreter that provides a command line user interface for Unix-like operating systems. It is a program that reads commands from the keyboard and gives them to the operating system to perform. The shell is a command language interpreter that executes commands read from the standard input device (usually the keyboard) and writes the command's output to the standard output device (usually the display screen). If it's not a built-in command, the shell passes the command to the operating system to perform using `system(command)`. This Shell supports background execution aswell as foreground execution. I/O isn't currently supported with this shell. If the user input cannot be regonized by the operating system then an error will be thrown onto the terminal or which ever diplay screen the user is using to display the output of the shell. This shell is merely a C program that can be ran on linux/Unix based operating systems like Ubuntu. This shell itself acts as a parent process from which child process can be created and executed from. 

---

## Arguments

**The shell supports arguments to commands. Arguments are separated by spaces.**

Explanation of the shell's argument handling:

1. The shell reads a line of input from the user.
2. The shell tokenizes the input into arguments.
3. The shell executes the command with the arguments.

Example:

`echo` HelloWorld

`command` [arg1] [arg2] .. [argn]

Explanation:

1. The shell reads the line `echo HelloWorld` from the user.
2. The shell tokenizes the input into two arguments in total: `echo` and `HelloWorld`.
3. The shell executes the command `echo` with the argument `HelloWorld`.

---

## I/O Redirection

**Disclaimer: This shell doesn't support I/O redirection at this current moment in time** 

- I/O redirection is a mechanism that allows a process to read input from a file or write output to a file. 
- Redirection is used to change the default input/output source of a process.
- the `>` and `<` symbols are used in conjunction with processes to redirect input and output. 
- The symbols are called redirection operators. 
- They each take a single argument, which is the path to the file to read from or write to.

---

## Background Execution

**Background execution is a feature of the shell that allows a process to run in the background. This shell supports background execution of processes.
Background execution is useful when a user wants to run a process and continue using the shell.**

**To run a process in background, the user must append an `&` to the end of the command. The shell will then execute the command in the background.**

Example:

`gedit &`

Explanation:

1. The shell reads the line `gedit &` from the user.
2. The shell tokenizes the input into two arguments: `gedit` and `&`.
3. The shell executes the command `gedit` with the argument `&`.
4. The shell executes the command `gedit` in the background (meaning the geddit text editior will run in the background).

---

## Foreground Execution

Foreground execution is running a process or command in real time and waiting until the command or process is fully executed until you regain access to the commandline. The user can only run a single command or process with foreground execution at a time. This shell supports foreground execution of processes.

---

## Process Concept

A process is an instance of a computer program that is being executed. It contains the program code and its current activity.Each process is executed in a separate address space, and one process cannot access the variables and data structures of another process. Each process is given a unique process ID (PID), which is used to identify the process.

--- 

## Batch Mode

This shell supports batch mode. Batch mode is a feature of the shell that allows a user to run a script of commands. The script of commands is stored in a file. The shell will then execute the commands in the file one by one. The shell will exit after the script has finished executing.

To run the shell in batch mode, the user must pass the path to the script file as an argument to the shell. The shell will then execute the commands in the file one by one. The shell will exit after the script has finished executing.

Example:

`./shell script.txt`

---

## The Make File

The make file creates this shell from the files that source files within the src directory. It first complies the C files into object files, then the object files are linked together to create the shell executable. The make file also cleans the bin directory of any object files and the shell executable.

**Disclaimer: the following commands can only be executed successfully in the home directory of the shell project**

Command to run the make file to create the shell executable:

`make`

Command to clean the bin directory:

`make clean`

**Additional Disclaimer: The make file is only compatible with Linux/Unix based operating systems like Ubuntu.**

---

## References

### **Citations List to material used to create this shell:**

*CHDIR(3) - linux man page (no date) chdir(3): change working directory - Linux man page. Available at: https://linux.die.net/man/3/chdir (Accessed: March 17, 2023).*

*System(3) - linux man page (no date) system(3): execute shell command - Linux man page. Available at: https://linux.die.net/man/3/system (Accessed: March 17, 2023).*

*Setenv(3) - linux man page (no date) setenv(3): change/add environment variable - Linux man page. Available at: https://linux.die.net/man/3/setenv (Accessed: March 17, 2023).*

*ECHO(1) - linux man page (no date) echo(1): line of text - Linux man page. Available at: https://linux.die.net/man/1/echo (Accessed: March 17, 2023).*

*Getenv(3) - linux man page (no date) getenv(3): environment variable - Linux man page. Available at: https://linux.die.net/man/3/getenv (Accessed: March 17, 2023).*

*Fgets(3) - linux man page (no date) fgets(3): input of char/strings - Linux man page. Available at: https://linux.die.net/man/3/fgets (Accessed: March 17, 2023).*

*Exit(3) - linux man page (no date) exit(3): cause normal process termination - Linux man page. Available at: https://linux.die.net/man/3/exit (Accessed: March 17, 2023).*

*Fork(3) - linux man page (no date) fork(3): create new process - Linux man page. Available at: https://linux.die.net/man/3/fork (Accessed: March 17, 2023).*

*Execvp(3) - linux man page (no date) execvp(3): execute file - Linux man page. Available at: https://linux.die.net/man/3/execvp (Accessed: March 17, 2023).*

*Fopen(3) - linux man page (no date) fopen(3): stream open functions - Linux man page. Available at: https://linux.die.net/man/3/fopen (Accessed: March 17, 2023).*

*Making your own linux shell in C (2020) GeeksforGeeks. GeeksforGeeks. Available at: https://www.geeksforgeeks.org/making-linux-shell-c/ (Accessed: March 17, 2023).*

---

## Author Information

#### Razvan Gorea

