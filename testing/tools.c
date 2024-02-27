#include "shell.h"

void printError(char *shellNme, char *invalidCommand, int indexint) {
  char *index, *message; /* why? Because write function don't print numbers so
                            we will convert index to chr * */
  message = ": not found\n";
  index = _itoa(indexint);

  _printE(shellNme);
  _printE(": ");
  _printE(index);
  _printE(": ");
  _printE(invalidCommand);
  _printE(message);

  free(index);
}
char *_itoa(int n) {
  char buffer[50];
  int i;

  i = 0;
  if (n == 0) {
    buffer[i++] = '0';
  } else {
    while (n > 0) {
      buffer[i++] = (n % 10) + '0';
      n /= 10;
    }
  }

  buffer[i] = '\0';
  reverseString(buffer, i);

  return (_strdup(buffer));
}

void reverseString(char *string, int len) {
  char tmp;
  int begin, end;

  begin = 0;
  end = len - 1;
  while (begin < end) {
    tmp = string[begin];
    string[begin] = string[end];
    begin++;
    end--;
  }
}
