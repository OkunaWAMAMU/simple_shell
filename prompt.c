#include "main.h"

/**
 * display_prompt - Displays the shell prompt.
 */
void display_prompt(void)
{
	write(STDOUT_FILENO, "#cisfun$ ", 9);
}

/**
 * read_input - Reads input from the user using custom_getline.
 * @input: Pointer to store the input string.
 * @len: Pointer to the length of the input string.
 *
 * Return: Returns 1 if successful, 0 on failure.
 */
int read_input(char **input, size_t *len)
{
	ssize_t read = custom_getline(input, len, stdin);

	return (read != -1);
}

/**
 * handle_exit - Handles the "exit" command.
 * @input: The user input string.
 *
 * Return: Returns 1 if the exit command is encountered, 0 otherwise.
 */
int handle_exit(const char *input)
{
	if (strcmp(input, "exit") == 0)
	{
		return (1);
	}
	return (0);
}

/**
 * execute_command - Executes the command using fork and execve.
 * @input: The user input string.
 */
void execute_command(__attribute__((unused)) const char *input)
{
	pid_t child_pid;
	int status;
	char *command_path = find_path(input);

	if (command_path == NULL)
	{
		write(STDERR_FILENO, "Command not found\n", 18);
		return;
	}

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("fork");
		free(command_path);
		exit(EXIT_FAILURE);
	}
	if (child_pid == 0)
	{
		char *temp_args[] = {(char *)input, NULL};

		if (execve(command_path, temp_args, NULL) == -1)
		{
			perror("execve");
			free(command_path);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		/* Parent process */
		waitpid(child_pid, &status, 0);
		if (WIFEXITED(status) && WEXITSTATUS(status) != 0)
		{
			write(STDERR_FILENO, "Command execution failed\n", 26);
		}
	}

	free(command_path);
}
/**
 * prompt - Main prompt function to run the shell.
 */
void prompt(void)
{
	char *input = NULL;
	size_t len = 0;

	while (1)
	{
		display_prompt();

		if (!read_input(&input, &len))
		{
			if (isatty(STDIN_FILENO))
			{
				write(STDOUT_FILENO, "\n", 1);
			}
			free(input);
			exit(0);
		}

		if (input[len - 1] == '\n')
		{
			input[len - 1] = '\0';
		}

		if (handle_exit(input))
		{
			free(input);
			exit(0);
		}

		execute_command(input);

		free(input);
	}
}

