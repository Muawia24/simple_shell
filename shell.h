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

typedef struct list_s
{
char *dir;
struct list_s *next;
} list_t;

void _print(const char *string);
char *getUserInput(void);
char **tokenize(char *userInput);

#endif 
