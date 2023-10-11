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
