#include "shell.h"
char **tokenizer(char *userInput) {
  char *token = NULL, *tmp = NULL;
  char **arrayOfTokens = NULL;
  int count = 0, i = 0;

  if (!userInput) /*that case no input from user*/
  {
    return (NULL);
  }
  /*userInput = "ls -la"*/
  tmp = _strdup(userInput); /*tmp = "ls -la"*/
  token = strtok(tmp, SEP);

  if (token == NULL) /*that case user just enter spaces*/
  {
    free(userInput), userInput = NULL;
    free(tmp), tmp = NULL;
    return (NULL);
  } /*toke = ls*/

  while (token) {
    count++;                   /*count = 2*/
    token = strtok(NULL, SEP); /*after loop token = NULL*/
  }

  free(tmp), tmp = NULL; /*tmp = NULL*/

  arrayOfTokens =
      malloc(sizeof(char *) * (count + 1)); /*malloc 3 string due to NULL*/

  if (!arrayOfTokens) /*if success arrayOfTokens = {"","",NULL}*/
  {
    free(userInput), userInput = NULL;
    return (NULL);
  }

  token = strtok(userInput, SEP); /*first token = "ls"*/

  while (token) {
    arrayOfTokens[i++] = _strdup(token); /*arrayOfTokens = {"ls","-la",NULL}*/
    token = strtok(NULL, SEP);
  }

  free(userInput), userInput = NULL;
  arrayOfTokens[i] = NULL;

  return (arrayOfTokens);
}
