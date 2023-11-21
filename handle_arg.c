#include "main.h"
/**
 * count_arguments - Counts the number of arguments
 *in an input string
 * @input: The input string
 *
 * Return: The number of arguments
 */
int count_arguments(const char *input)
{
	int count = 0;

	while (*input)
	{
		if (*input == ' ')
		{
			count++;
		}
		input++;
	}
	return (count + 1);
}
/**
 * split_arguments - Splits a string into separate arguments
 * @input: Input string to be tokenized
 *
 * Return: A null-terminated array of strings (arguments)
 */
char **split_arguments(const char *input)
{
	size_t num_args = 1;
	size_t i = 0, arg_index;
	size_t len = strlen(input);
	char **arguments = malloc((num_args + 1) * sizeof(char *));
	const char *start = input;

	while (i < len)
	{
		if (input[i] == ' ')
			num_args++;
		i++;
	}
	if (arguments == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}

	i = 0;
	for (arg_index = 0; arg_index < num_args; arg_index++)
	{
		size_t arg_len = input - start;

		while (*input && *input != ' ')
			input++;
		arguments[arg_index] = malloc(arg_len + 1);
		if (arguments[arg_index] == NULL)
		{
			perror("malloc");
			exit(EXIT_FAILURE);
		}
		memcpy(arguments[arg_index], start, arg_len);
		arguments[arg_index][arg_len] = '\0';
		if (*input == ' ')
			input++;
		start = input;
	}
	arguments[num_args] = NULL;
	return (arguments);
}
