#include "shell.sh"
/**
 * tokenize - tokenizes the input command
 * @userInput: inputed line by user
 * Return: An array of strings
 */
 
char **tokenize(char *userInput) {
  int count = 0;
  char *token = strtok(userInput, "\n");

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

  // Tokenize userInput into arrayOfTokens
  count = 0;
  token = strtok(userInput, "\n");
  while (token) {
    arrayOfTokens[count++] = token;
    token = strtok(NULL, "\n");
  }
  arrayOfTokens[count] = NULL; // Ensure last token is NULL

  return arrayOfTokens;
}