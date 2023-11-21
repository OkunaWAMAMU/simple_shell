#include "main.h"

/**
 * find_path - Finds the full path of a command in
 *the PATH environment variable.
 * @command: The command to find.
 *
 * Return: The full path of the command, or NULL if not found.
 */
char *find_path(const char *command)
{
	char *path = getenv("PATH");
	char *token = strtok(path, ":");

	while (token != NULL)
	{
		char *full_path = malloc(strlen(token) + strlen(command) + 2);

		if (full_path == NULL)
		{
			perror("malloc");
			exit(EXIT_FAILURE);
		}
		strcpy(full_path, token);
		strcat(full_path, "/");
		strcat(full_path, command);

		if (access(full_path, X_OK) == 0)
		{
			return (full_path);
		}

		free(full_path);
		token = strtok(NULL, ":");
	}

	return (NULL);
}
