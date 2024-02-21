#include "shell.h"

/**
 * tokenize - tokenizes the input command
 * @command: pinter to the string input
 * Return: An array of strings
 */

char **tokenize(char *command)
{
	int i = 0;
	char *token;
	char **arr;

	token = strtok(command, "\n");
	arr = malloc(sizeof(char *) * 1024);
	if (arr == NULL)
		perror("Error");

	while (token)
	{
		arr[i] = token;
		token = strtok(NULL, "\n");
		i++;
	}
	return (arr);
}