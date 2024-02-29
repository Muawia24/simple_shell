#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * getPath - Get $PATH of command
 * @command: command to find a PATH for it
 * Return: Full path
 */

char *getPath(char *command);
char *getPath(char *command)
{
	char *envPath, *PathOfCommand, *directories;
	int i;
	struct stat st;

	for (i = 0; command[i]; i++)
	{
		if (command[i] == '/')
		{
			if (stat(command, &st) == 0)
				return (_strdup(command));
			return (NULL);
		}
	}

	envPath = getEnv("PATH");

	if (!envPath)
		return (NULL);

	directories = strtok(envPath, ":");

	while (directories)
	{
		PathOfCommand = malloc(_strlen(directories) + _strlen(command) + 2);
		if (PathOfCommand)
		{
			_strcpy(PathOfCommand, directories);
			_strcat(PathOfCommand, "/");
			_strcat(PathOfCommand, command);
			if (stat(PathOfCommand, &st) == 0)
			{
				free(envPath);
				return (PathOfCommand);
			}
			free(PathOfCommand), PathOfCommand = NULL;
			directories = strtok(NULL, ":");
		}
	}

	free(envPath);
	return (NULL);
}
