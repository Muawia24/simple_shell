#include "shell.h"
#include <stdlib.h>

/**
 * execCommand - To execute the command
 * @command: command to execute
 * @argv: argunments
 * Return: exit status
 */

int execCommand(char **command, char **argv, int index)
{
	pid_t childPid;
	int status;
	char *pathOfCommand;

	pathOfCommand = getPath(command[0]);
	if (!pathOfCommand)
	{
		Error(argv[0], command[0], index);
		freeAllocated(command);
		return (127);
	}

	childPid = fork();
	if (childPid == 0)
	{
		if (execve(pathOfCommand, command, environ) == -1)
		{
			free(pathOfCommand), pathOfCommand = NULL;
			freeAllocated(command);
		}
	}
	else
	{
		waitpid(childPid, &status, 0);
		freeAllocated(command);
		free(pathOfCommand), pathOfCommand = NULL;
	}

	return (WEXITSTATUS(status));
}
