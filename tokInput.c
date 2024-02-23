#include "shell.h"
/**
 * tokenize - tokenizes the input command
 * @userInput: inputed line by user
 * Return: An array of strings
 */
char **tokenize(char *userInput)
{
	int count = 0;
	char *ptr = userInput;
	char *token;

	/* Allocate memory for tokens array*/

	char **arr = malloc(sizeof(char *) * 1024);

	if (!arr)
	{
		perror("Error allocating memory for tokens");
		return (NULL);
	}

	/* Tokenize userInput into arrayOfTokens*/
	count = 0;
	token = strtok(userInput, " \n");
	arr[0] = token;
	while (token)
	{
		arr[count] = token;
		token = strtok(NULL, " \n");
		count++;
	}
	arr[count] = NULL; /* Ensure last token is NULL*/

	return (arr);
}
