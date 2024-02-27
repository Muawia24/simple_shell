#include "shell.h"

char *getEnv(char *envVar) {
  int i;
  char *tmp, *key, *valueOfKey, *env;

  key = tmp = valueOfKey = NULL;

  for (i = 0; environ[i]; i++) {
    tmp = strdup(environ[i]);
    key = strtok(tmp, "=");
    if (strcmp(key, envVar) == 0) {
      valueOfKey = strtok(NULL, "\n");
      env = strdup(valueOfKey);
      free(tmp);
      return (env);
    }
    free(tmp), tmp = NULL;
  }

  return (NULL);
}
