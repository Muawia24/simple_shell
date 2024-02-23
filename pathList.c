#include "shell.h"

/**
 * add_pathNode - create linked list of path
 * @head: head of list
 * @dir: pointer to the content of path directories
 * Return: pointer to the new node added
 */
list_t *add_pathNode(list_t **head, char *dir)
{
	list_t *new = malloc(sizeof(list_t));

	if (new == NULL)
		return (NULL);
	new->dir = dir;
	new->next = *head;
	*head = new;

	return (new);
}

/**
 * free_pathList - frees nodes of list
 * @head: head of nodes
 * Return: nothing
 */
void free_pathList(list_t *head)
{
	list_t *temp;

	while (head)
	{
		temp = head;
		head = head->next;
		free(temp->dir);
		free(temp);
	}
}


/**
 * getPath - adding path directories to linked list
 * and then looping through it.
 * @h: head node
 * @command: command input
 * Return: current directory.
 */
char *getPath(list_t *h, char *command)
{
	list_t *head;
	char *token, *ptr, *ptr2;
	list_t *current;
	char **arr;

	/* Extract and tokenize the env variable "PATH" by ":"*/

	head = NULL;
	ptr = getenv("PATH");
	token = strtok(ptr, ":");

	while (token)
	{
		add_pathNode(&head, token);	/*addes directories to linked list*/
		token = strtok(NULL, ":");
	}

	/* Looping through the list and checking for the command executable*/

	current = head;
	while (current)
	{
		strcat(ptr2, current->dir);
		strcat(ptr2, "/");
		strcat(ptr2, command);
		if (access(ptr2, X_OK) == 0)
		{
			printf("is found");
			return (ptr2);
		}
		else
			current = current->next;
	}
	printf("not in path");
	return (NULL);
}
