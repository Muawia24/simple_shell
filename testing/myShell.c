#include "shell.h"

/**
* main - Entry point to awesome shell
* @argc: Number of argunmebnt
* @argv: Arguments to passed
* Return: 0 if success
*/

int main(int argc, char **argv)
{
	char *userInput = NULL;
	char **command = NULL;
	int exitStatus = 0;
	(void)argc;

	while (true)
	{
		if (isatty(0))
			_print("$ ");

		userInput = getUserInput();

		if (userInput == NULL)   /* handle C-d case of EOF */
		{
			if (isatty(0))
				_print("\n");
			return (exitStatus);
		}

		command = tokenizer(userInput); /* The command is 2d array of strings example: ls -la */

		if(!command) /* if user just hit enter without any input loop*/
			continue;

		exitStatus = execCommand(command, argv);

		/*free userInput to avoid memory leak because getline allocate memory*/
	}

}
