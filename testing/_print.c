#include "shell.h"

/**
 * _print - Function to print to stdout
 * @string: String to printed
 */

void _print(char *string) { write(1, string, _strlen(string)); }

/**
 * _printE - Function to print to stdout
 * @string: String to printed
 */

void _printE(char *string) { write(2, string, _strlen(string)); }
