#include "shell.h"
#include <unistd.h>

/**
 * main - Entry point to awesome shell
 * @argc: Number of argunmebnt
 * @argv: Arguments to passed
 * Return: 0 if success
 */

int main(int argc, char **argv)
{
	char *userInput = NULL;
	char **command = NULL;
	int indexint = 0;
	int exitStatus = 0;
	(void)argc;

while (1) { // Main loop
    userInput = getUserInput();

    if (userInput == NULL) { // Handle Ctrl+D (EOF)
        if (isatty(STDIN_FILENO)) {
            write(STDOUT_FILENO, "\n", 1); // Print newline for clarity
        }
        return exitStatus; // Exit the shell
    }

    indexint++;
    command = tokenizer(userInput);

    if (!command) { // Handle empty user input
        continue; // Avoid unnecessary processing
    }

    // Check for exit command
    if (strcmp(command[0], "exit") == 0) {
        free(userInput);
        freeMemory(command);
        break; // Break out of the main loop
    }

    exitStatus = execCommand(command, argv, indexint);

    free(userInput); // Free memory allocated by getline in getUserInput
}
}
