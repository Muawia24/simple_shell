#include "shell.h"

/**
 * _getline - getline-like function
 * @buf: array to store input
 * @n: size of buf in bytes
 * @stream: file input
 * Return: pointer to the stored input
 */
ssize_t _getline(char **buf, size_t *n, FILE *stream)
{
	char *line = *buf, ch;
	size_t size = *n, i = 0;

	if (line == NULL || size == 0)
	{
		size = 128;
		line = malloc(*n);
		if (line == NULL)
			return (-1);
	}

	while (((ch = fgetc(stream)) != EOF) && (ch != '\n'))
	{
		if (i >= (size - 1))	/* Relocating buf size if i > n */
		{
			size_t new_size = size * 2;
			char *new = malloc(new_size);

			if (new == NULL)
			{
				free(line);
				return (-1);
			}
			line = new;
			size *= 2;
		}

		line[i++] = ch;	 /* Storing char input*/
	}
	if (i == 0 && ch == EOF)
		return (-1);

	line[i] = '\0';
	*buf = line;	/* putting the input into main buf variable*/
	*n = size;

	return (i);
}
/**
 * getUserInput - gets user input
 * Return: pointer to user input
 */
char *getUserInput(void)
{
	size_t len = 0;
	char *buf = NULL;
	ssize_t n;

	while ((n = _getline(&buf, &len, stdin)) == -1)
		return (NULL);
	return (buf);
}
