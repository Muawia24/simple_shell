#ifndef SHELL_H
#define SHELL_H

#include <errno.h>
#include <fcntl.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#define SEP " \t\n"
extern char **environ;

void printError(char *shellNme, char *invalidCommand, int indexint);
void _printE(char *string);
char *_itoa(int n);
void reverseString(char *string, int len);
int _strcmp(char *string1, char *string2);
char *_strdup(const char *string);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
int _strlen(char *string);
int execCommand(char **command, char **argv, int indexint);
void freeMemory(char **_2dArray);
void _print(char *string);
char *getUserInput(void);
char **tokenizer(char *userInput);
char *getEnv(char *envVar);
char *getPath(char *command);

#endif
