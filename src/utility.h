/*
Student Name: Razvan Gorea
Student ID: 21306373

I declare that this material, which I now submit for assessment, 
is entirely my own work and has not been taken from the work of others save,
and to the extent that such work has been cited 
and acknowledged within the text of my work.*/

#define args_len 15
#define command_len 1028

//Function prototypes for shell commands

void input_splitter(char* user_input, char** command_given, char** args);
void change_directory(char** args);
void quit_command();
void pwd_command();
void dir_command();
void clr_command();
void echo_command(char** args);
void pause_command();
void environ_command();
void exec_command(char** args);
void set_shell_env();
void background_process(char** args);
void help_command();