//header for myshell by 32153682 이창민, ckdals0115@naver.com
//mysh.h
#include<unistd.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<wait.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>
#include<signal.h>
#include<errno.h>
#define MAX 100
//static int child_pid = 0;
//static int COUNT = 0;
//static char* COMMAND_PATH = "Desktop/Sys/mysh/";

void redirection_com(char** commands, int i);
void background_com(char** commands, int i);
char** get_tokens(char* CommandLine);
void execute_com(char** command);
