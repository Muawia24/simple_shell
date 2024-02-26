#include "shell.h"
/**
 * getBuiltIn - handeling the built is commands
 * @command: command input
 * Return: void
 */
void getBuiltIn(char *command)
{
	if (strcmp(command,"exit") == 0)
	{
		return (exit(EXIT_SUCCESS));
	}

	else if (strcmp(command, "env") == 0)
	{
		print_env();
	}
}
/**
 * print_env - print the environment variabled
 * Return: nothing
 */
void print_env()
{
	extern char **environ;
	unsigned int i = 0;

	while (environ[i])
	{
		printf("%s\n", environ[i]);
		i++;
	}
}
