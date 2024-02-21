#include "shell.h"

/**
* main - Entry point to awesome shell
* @argc: Number of argunmebnt
* @argv: Arguments to passed
* Return: 0 if success
*/

int main(int argc, char *argv[])
{
	pid_t child;
	char *userInput = NULL;
	int exitStatus = 0, status;
	char **arr;
	char *head = NULL;
	(void)argc;
	(void)argv;

	while (true)
	{

		if (isatty(0))
			_print("$ ");
		userInput = getUserInput();
		if (userInput == NULL)   /* C-d */
		{
			if (isatty(0))
				_print("\n");
			return (exitStatus);
		}
		_print(userInput);
		arr = tokenize(userInput);
		child = fork();
		free(userInput);

		if (child == 0)
		{
			char *p = getPath(&head);
			strcat(p, arr[0]);
			if (execve(p, arr, NULL) == -1)
				perror("Error");
		}
		else
		{
			wait(&status);
		}

	}

	return (0);
}
