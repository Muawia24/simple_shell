#include "shell.h"

/**
* getUserInput - Function to get user input
* Return: Inputed line from user
*/

char *getUserInput(void)
{
	char *storedInput;
	size_t len;
	ssize_t n;

	storedInput = NULL;
	len = 0;
	n = getline(&storedInput, &len, stdin);
	if (n == -1)
	{
		free(storedInput);
		return (NULL);
	}

	return (storedInput);
}