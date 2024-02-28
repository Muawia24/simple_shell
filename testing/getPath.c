#include "shell.h"

char *getPath(char *command) {
  int i;
	char *envPath;
	char *commandPath;
	char *directoryOfCommand;
  struct stat st;

  for (i = 0; command[i];
       i++) /* this for loop to check if comman is valid path */
  {
    if (command[i] == '/') {
      if (stat(command, &st) == 0) {
        return (_strdup(command));
      }
      return (NULL);
    }
  }

	envPath = getEnv("PATH");
	if (!envPath) /* if unset path */
	{
		return (NULL);
	}

	directoryOfCommand = strtok(envPath, ":");
	while (directoryOfCommand)
	{
		/* size = len(directory) + len(command) + 2(\n and \0)*/
		commandPath = malloc(_strlen(directoryOfCommand) + _strlen(command) + 2);
		if (commandPath)
		{
			_strcpy(commandPath, directoryOfCommand);
			_strcat(commandPath, "/");
			_strcat(commandPath, command);

			if (stat(commandPath, &st) == 0)
			{
				free(envPath), envPath = NULL;
				return (commandPath);
			}
			free(commandPath), commandPath = NULL;
			directoryOfCommand = strtok(NULL, ":");
		}
	}
	free(envPath), envPath = NULL;
	return (NULL);
}
