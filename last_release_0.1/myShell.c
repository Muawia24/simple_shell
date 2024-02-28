#include "shell.h"
#include <stdio.h>
#include <unistd.h>

/**
 * main - Entry point of simple shell
 * @argc: arg count
 * @argv: arg vector
 *
 * Return: 0 on success, 1 on error
 */

int main(int argc, char **argv)
{
	char *userInput = NULL;
	char **command = NULL;
	int status = 0;
	(void) argc;

	while (true)
	{
		userInput = getInput();
		if (userInput == NULL) /* C-d */
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			return (status);
		}

		command = tokenizer(userInput);
		if (!command)
			continue;

		status = execCommand(command, argv);
	}
}
