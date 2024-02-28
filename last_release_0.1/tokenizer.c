#include "shell.h"
#include <stdlib.h>
#include <string.h>

/**
 * tokenizer - Tokenize the line
 * @userLine: line
 * Return: command
 */

char **tokenizer(char *userLine)
{
	char *token = NULL, *tmp = NULL;
	char **command = NULL;
	int count = 0, i = 0;

	if (!userLine)
		return (NULL);
	tmp = _strdup(userLine);

	token = strtok(tmp, SEP);
	if (token == NULL)
	{
		free(userLine), userLine = NULL;
		free(tmp), tmp = NULL;
		return (NULL);
	}
	while (token)
	{
		count++;
		token = strtok(NULL, SEP);
	}
	free(tmp), tmp = NULL;

	command = malloc(sizeof(char *) * (count + 1));
	if (!command)
	{
		free(userLine), userLine = NULL;
		return (NULL);
	}

	token = strtok(userLine, SEP);
	while (token)
	{
		command[i] = _strdup(token);
		token = strtok(NULL, SEP);
		i++;
	}
	free(userLine), userLine = NULL;
	command[i] = NULL;

	return (command);
}
