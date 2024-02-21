#include "shell.h"

/**
 * tokenize - tokenizes the input command
 * @userInput: inputed line by user
 * Return: An array of strings
 */

char **tokenize(char *userInput)
{
	int i, count;
	char *token, *tmp;
	char **arrayOfTokens;
	
	i = 0;
	count = 0;
	token = NULL;
	tmp = NULL;
	arrayOfTokens = NULL;

	if (userInput == NULL)
		return (NULL);
	tmp = strdup(userInput); /*create tmp using it to count of strings then we used in malloc*/
	token = strtok(tmp, "\n");
	while (token) /*while to count*/
	{
		count++;
		token = strtok(NULL, "\n");
	}
	/*free(tmp);*/
	tmp = NULL;
	arrayOfTokens= malloc(sizeof(char *) * (count + 1));
	if (arrayOfTokens == NULL)
	{
		perror("Error");
		free(userInput);
		userInput = NULL;
		return (NULL);
	}
	/*all above lines to calculate count*/
	token = strtok(userInput, "\n");
	while (token)
	{
		arrayOfTokens[i++] = token;
		token = strtok(NULL, "\n");
	}
	arrayOfTokens[i] = NULL; /*last token must be equal NULL*/

	return (arrayOfTokens);

}
