#include "shell.h"
#include <unistd.h>

/**
* getUserInput - Function to get user input
* Return: Inputed line from user
*/

char *getUserInput(void)
{
	char *storedInput = NULL;
	size_t len = 0; 
	ssize_t n;
	
	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "$ ", 2);
	n = getline(&storedInput, &len, stdin);
	if (n == -1)
	{
		free(storedInput);
		return (NULL);
	}

	return (storedInput);
}
