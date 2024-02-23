#include "shell.h"

/**
* getUserInput - Function to get user input
* Return: Inputed line from user
*/

char *getUserInput(void)
{
	char *buf = NULL;
	size_t len;
	ssize_t n;

	buf = NULL;
	len = 0;
	n = getline(&buf, &len, stdin);
	if (n == -1)
	{
		free(buf);
		return (NULL);
	}

	return (buf);
}
