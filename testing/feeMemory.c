#include "shell.h"

/**
 * freeMemory - Function to free memory after using pointer
 * @_2dArray: 2d Array
 */

void freeMemory(char **_2dArray) {
  int i;

  if (!_2dArray)
    return;

  for (i = 0; _2dArray[i]; i++) {
    free(_2dArray[i]);
    _2dArray[i] = NULL;
  }

  free(_2dArray), _2dArray = NULL;
}
