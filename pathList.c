#include "shell.h"

/**
 * add_pathNode - create linked list of path
 * @head: head of list
 * @dir: pointer to the content of path directories
 * Return: pointer to the new node added
 */
char *add_pathNode(char **head, char *dir)
{
	char *new = malloc(sizeof(list_t));
	if (neww == NULL)
		return (NULL);
	new->dir = dir;
	new->next = *head;
	*head = new;

	return (new);
}

/**
 * getPath - adding path directories to linked list
 * and then looping through it.
 * @h: head node
 * Return: current directory.
 */
char *getPath(char *head)
{
	list_t *head;
	char *token, *ptr, *current;
	char **arr;

	head = NULL;
	ptr = getenv("PATH");
	token = strtok(ptr, ":");
	arr = tokenize(userInput);
	while (token)
	{
		add_pathNode(&head, token);	/*addes directories to linked list*/
		token = strtok(NULL, ":");
	}
	
	current = head;
	while (current)
	{
		
		if (chdir(current->dir) == 0)
		{
			if (access(arr[0], X_OK) == 0)
			{
				printf("is found");
				return (current->dir);
			}
			else
				current = current->next;

		}
	}
	printf("not in path");
	return (NULL);
}	
