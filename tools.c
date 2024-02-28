#include "shell.h"

/**
 * freeAllocated - Avoid memory leak
 * @_2darray: 2D Array to free
 */

void freeAllocated(char **_2darray)
{
	int i = 0;

	if (!_2darray)
		return;

	for (i = 0; _2darray[i]; i++)
		free(_2darray[i]), _2darray[i] = NULL;
	free(_2darray), _2darray = NULL;
}
