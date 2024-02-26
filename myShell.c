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
	list_t *head = NULL;
	(void)argc, (void)argv;

	while (true)
	{

		if (isatty(0))
			_print("simple_shell$ ");
		userInput = getUserInput();
		if (userInput == NULL)	/*C-d*/
		{
			if (isatty(0))
				_print("\n");
			return (exitStatus);
		}
		arr = tokenize(userInput);
		printf("%s\n", arr[0]);
		getBuiltIn(arr[0]);
		child = fork();
		if (child == 0)
		{

		/* Line below checks for the command executable then execute it*/

			char *p = getPath(head, arr[0]);

			if (execve(p, arr, NULL) == -1)
				perror("Error");
		}
		else
		{
			wait(&status);
			free(userInput);
			free_pathList(head);
		}
	}
	return (0);
}
