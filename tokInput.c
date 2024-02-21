#include "shell.h"
/**
 * tokenize - tokenizes the input command
 * @userInput: inputed line by user
 * Return: An array of strings
 */
 
char **tokenize(char *userInput) {
  int count = 0;
  char *token = strtok(userInput, "\n");

<<<<<<< HEAD
char **tokenize(char *userInput)
{
	int i, count;
	char *token, *tmp;
	char **arrayOfTokens;
	
	i = 0;
	count = 0;
	token = NULL;
	tmp = NULL;
	arrayOfTokens = NULL;

	if (userInput == NULL)
		return (NULL);
	tmp = strdup(userInput); /*create tmp using it to count of strings then we used in malloc*/
	token = strtok(tmp, "\n");
	while (token) /*while to count*/
	{
		count++;
		token = strtok(NULL, "\n");
	}
	/*free(tmp);*/
	tmp = NULL;
	arrayOfTokens= malloc(sizeof(char *) * (count + 1));
	if (arrayOfTokens == NULL)
	{
		perror("Error");
		free(userInput);
		userInput = NULL;
		return (NULL);
	}
	/*all above lines to calculate count*/
	token = strtok(userInput, "\n");
	while (token)
	{
		arrayOfTokens[i++] = token;
		token = strtok(NULL, "\n");
	}
	arrayOfTokens[i] = NULL; /*last token must be equal NULL*/
=======
  while (token) {
    count++;
    token = strtok(NULL, "\n");
  }

  // Allocate memory for tokens array
  char **arrayOfTokens = malloc(sizeof(char *) * (count + 1));
  if (!arrayOfTokens) {
    perror("Error allocating memory for tokens");
    return NULL;
  }
>>>>>>> e6ed4f7037e2c20534caea935c42867dca9f90c9

  // Tokenize userInput into arrayOfTokens
  count = 0;
  token = strtok(userInput, "\n");
  while (token) {
    arrayOfTokens[count++] = token;
    token = strtok(NULL, "\n");
  }
  arrayOfTokens[count] = NULL; // Ensure last token is NULL

<<<<<<< HEAD
}
=======
  return arrayOfTokens;
}
>>>>>>> e6ed4f7037e2c20534caea935c42867dca9f90c9
