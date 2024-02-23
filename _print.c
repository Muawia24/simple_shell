#include "shell.h"

/**
* _print - Function to print to stdout
* @string: String to printed
*/

void _print(const char *string)
{
	write(STDOUT_FILENO, string, strlen(string));
}

