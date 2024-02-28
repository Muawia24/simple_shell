#include "shell.h"

/**
 * execCommand - To execute the command
 * @command: command to execute
 * @argv: argunments
 * Return: exit status
 */

int execCommand(char **command, char **argv)
{
	pid_t childPid;
	int status;

	childPid = fork();
	if (childPid == 0)
	{
		if (execve(command[0], command, environ) == -1)
		{
			perror(argv[0]);
			freeAllocated(command);
			exit(127);
		}
	}
	else
	{
		waitpid(childPid, &status, 0);
		freeAllocated(command);
	}

	return (WEXITSTATUS(status));
}
