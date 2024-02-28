#include "shell.h"
#include <fcntl.h>
#include <stdlib.h>
/**
 *execCommand - Function to execute child program
 *@coomand: Command to execute
 *@argv:
 *Return: int exit status
 */

int execCommand(char **command, char **argv, int indexint) {
  char *commmandPath;
  pid_t childPid;
  int exitStatus;

  commmandPath = getPath(command[0]);
  if (!commmandPath) {
    printError(argv[0], command[0], indexint);
    freeMemory(command);
    return (127);
  }
  childPid = fork();

  if (childPid == 0) {
    if (execve(commmandPath, command, environ) == -1) {
      free(commmandPath), commmandPath = NULL;
      freeMemory(command);
    }

    else {
      waitpid(childPid, &exitStatus, 0);
      freeMemory(command);
      free(commmandPath), commmandPath = NULL;
    }
  }

  return (WEXITSTATUS(exitStatus));
}
