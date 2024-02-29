#ifndef SHELL_H
#define SHELL_H

/* Libararies */
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

/* Global functions */
#define SEP " \t\n"
extern char **environ;

/* Functions */
char *getInput(void);
char **tokenizer(char *userLine);
int _strlen(char *string);
int _strcmp(char *string1, char *string2);
char *stringtarts_with(const char *haystack, const char *needle);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
char *_strdup(const char *str);
void _puts(char *str);
void freeAllocated(char **_2darray);
int execCommand(char **command, char **argv, int index);
char *getEnv(char *envVriable);
char *getPath(char *command);
char *_itoa(int n);
void Error(char *name, char *command, int idx);
void reverseString(char *string, int len);



#endif
