#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>
#include <stdbool.h>

#define SEP " \t\n"
extern char **environ;

int execCommand(char **command, char **argv);
void freeMemory(char **_2dArray);
void _print(const char *string);
char *getUserInput(void);
char **tokenizer(char *userInput);


#endif 
