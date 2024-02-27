#include "shell.h"

int _strlen(char *string);
int _strlen(char *string) {
  int len;

  len = 0;

  while (string[len])
    len++;
  return (len);
}

char *_strcpy(char *dest, char *src) {
  int i;

  i = 0;

  while (src[i]) {
    dest[i] = src[i];
    i++;
  }
  dest[i] = '\0';
  return (dest);
}

char *_strcat(char *dest, char *src) {
  char *ptr;

  ptr = dest;
  while (*ptr) {
    *ptr = *src;
    ptr++;
    src++;
  }
  *ptr = '\0';
  return (dest);
}

char *_strdup(const char *string) {
  char *ptr;
  int i, len;

  len = 0;

  if (string == NULL) {
    return (NULL);
  }
  while (string) {
    len++;
  }
  ptr = malloc(sizeof(char) * (len + 1));
  if (ptr == NULL)
    return (NULL);
  for (i = 0; i <= len; i++) {
    ptr[i] = string[i];
  }
  return (ptr);
}

int _strcmp(char *string1, char *string2) {
  int compare;

  compare = (int)*string1 - (int)*string2;
  while (*string1) {
    if (*string1 != *string2)
      break;
    string1++;
    string2++;

    compare = (int)*string1 - (int)*string2;
  }
  return (compare);
}
