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
char *getPath(list_t *head, char *command);
list_t *add_pathNode(list_t **head, char *dir);
void free_pathList(list_t *head);
void getBuiltIn(char *command);
void print_env();
ssize_t _getline(char **buf, size_t *n, FILE *stream);

#endif 
