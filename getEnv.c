#include "shell.h"
#include <stdlib.h>
#include <string.h>
#include <time.h>

/**
 * getEnv - Function to looking for env variables in linux
 * @envVriable: environment variable to looking for
 * Return: global env variable
 */

char *getEnv(char *envVriable)
{
	int i;
	char *tmpOfEnviron, *envKey, *envValue, *env;

	for (i = 0; environ[i]; i++)
	{
		tmpOfEnviron = _strdup(environ[i]);
		envKey = strtok(tmpOfEnviron, "=");

		if (_strcmp(envKey, envVriable) == 0)
		{
			envValue = strtok(NULL, "\n");
			env = _strdup(envValue);
			free(tmpOfEnviron);
			return (env);
		}

		free(tmpOfEnviron), tmpOfEnviron = NULL;
	}
	return (NULL);
}
