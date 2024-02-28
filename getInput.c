#include "shell.h"
#include <stddef.h>
#include <stdio.h>
#include <unistd.h>

/**
 * getInput - Function to get input from user
 *
 * Return: Line
 */

char *getInput(void)
{
	char *userLine = NULL;
	size_t len = 0;
	ssize_t nread;

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "$ ", 2);
	nread = getline(&userLine, &len, stdin);
	if (nread == -1)
	{
		free(userLine);
		return (NULL);
	}


	return (userLine);
}
