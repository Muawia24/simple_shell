#include "shell.h"

/**
 * is_builtin - check if command builtin
 * @command: command
 * Return: int
 */

int is_builtin(char *command);
int is_builtin(char *command)
{
	char *builtsins[] = { "exit", "env", "setenv", "cd", NULL };
	int i;

	for (i = 0; builtsins[i]; i++)
	{
		if (_strcmp(command, builtsins[i]) == 0)
			return (1);
	}
	return (0);
}

/**
 * handleBuiltin - built in
 * @command: command
 * @argv: argv
 * @status: st
 * @index: index
 */

void handleBuiltin(char **command, char **argv, int *status, int index)
{
	(void) argv;
	(void) index;

	if (_strcmp(command[0], "exit") == 0)
		exitShell(command, status);
	else if (_strcmp(command[0], "env") == 0)
		printEnv(command, status);
}

/**
 * exitShell - exit
 * @command: command
 * @status: int
 */

void exitShell(char **command, int *status)
{
	freeAllocated(command);
	exit(*status);
}

/**
 * printEnv - print env var
 * @command: command
 * @status: st
 */

void printEnv(char **command, int *status)
{
	int i;


	for (i = 0; environ[i]; i++)
	{
		write(STDOUT_FILENO, environ[1], _strlen(environ[1]));
		write(STDOUT_FILENO, "\n", 1);
	}
	freeAllocated(command);
	*status = 0;
}
