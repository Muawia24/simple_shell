#include "shell.h"
#include <unistd.h>

/**
 * freeAllocated - Avoid memory leak
 * @_2darray: 2D Array to free
 */

void freeAllocated(char **_2darray);
void freeAllocated(char **_2darray)
{
	int i = 0;

	if (!_2darray)
		return;

	for (i = 0; _2darray[i]; i++)
		free(_2darray[i]), _2darray[i] = NULL;
	free(_2darray), _2darray = NULL;
}

/**
 * Error - print Error
 * @name: name
 * @command: command
 * @idx: index
 */

void Error(char *name, char *command, int idx)
{
	char *index, msg[] = ": not found\n";

	index = _itoa(idx);

	write(STDERR_FILENO, name, _strlen(name));
	write(STDERR_FILENO, ":", 2);
	write(STDERR_FILENO, index, _strlen(index));
	write(STDERR_FILENO, ":", 2);
	write(STDERR_FILENO, command, _strlen(command));
	write(STDERR_FILENO, msg, _strlen(msg));

	free(index);
}
/**
 * stringReverse - revserse string
 * @str: string to reverse
 */
void stringReverse(char  *str)
{
	int len = strlen(str);
	char *start = str;
	char *end = str + len - 1;

	while (start < end)
	{
		char temp = *start;
		*start = *end;
		*end = temp;
		start++;
		end--;
	}



/**
 * _itoa - string to number
 * @n: number
 * Return: string
 */
char *_itoa(int n)
{
	char buffer[20];
	int i;

	i = 0;
	if (n == 0)
	{
		buffer[i++] = '0';
	}
	else
	{
		while (n > 0)
		{
			buffer[i++] = (n % 10) + '0';
			n /= 10;
		}
	}

	buffer[i] = '\0';
	stringReverse(buffer);

	return (_strdup(buffer));
}

/**
 * reverseString - reverse String
 * @string: string to reverse
 * @len: len of string
 */

void reverseString(char *string, int len)
{
	/* char tmp; */
	int begin, end;

	begin = 0;
	end = len - 1;
	while (begin < end)
	{
		/* tmp = string[begin]; */
		string[begin] = string[end];
		begin++;
		end--;
	}
}
