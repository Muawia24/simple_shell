#include "shell.h"
/**
*execCommand - Function to execute child program
*@coomand: Command to execute
*@argv: 
*Return: int exit status
*/

int execCommand(char **command, char **argv)
{
	pid_t childPid;
	int exitStatus;

	childPid = fork();

	if(childPid == 0)
	{
		if(execve(command[0], command, environ) == -1 )
		{
			perror(argv[0]);

			exit(0);
		}
		
		else
		{
			waitpid(childPid, &exitStatus, 0);
			freeMemory(command);
		}
	}

	return (WEXITSTATUS(exitStatus));
}
