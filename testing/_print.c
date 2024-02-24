#include "shell.h"

/**
* _print - Function to print to stdout
* @string: String to printed
*/

void _print(const char *string)
{
	write(1, string, strlen(string));
}
