#include "shell.h"
/**
 * _strtok - tokenizes the user input
 * @userInput: pointer to user input
 * @delim: pointer to the delimiter
 * Return: the tokenized input
 */

char *_strtok(char *userInput, char *delim)
{
	static char *ptr;

	if (userInput == NULL)
	{
		userInput = ptr;
		if (userInput == NULL)
			return (NULL);
	}

	userInput += strspn(userInput, delim);
	if (*userInput == '\0')
	{
		ptr = NULL;
		return (ptr);
	}

	ptr = userInput + strcspn(userInput, delim);

	if (ptr[0] != '\0')
	{
		ptr[0] = '\0';
		ptr++;
	}
	else
	{
		ptr = NULL;
	}

	return (userInput);
}
