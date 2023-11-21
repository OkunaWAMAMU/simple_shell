#include "main.h"
/**
 * custom_getline - Custom getline function
 * @lineptr: Pointer to the line read from input
 * @n: Pointer to the size of the line
 * @fd: File descriptor from which to read
 *
 * Return: Number of characters read, -1 on failure
 */
ssize_t custom_getline(char **lineptr, size_t *n, FILE *stream)
{
	size_t buf_size = 128;
	size_t pos = 0;
	char *buffer = malloc(buf_size);
	char c;

	*lineptr = NULL;
	*n = 0;
	if (!buffer)
		return (-1);

	while (read(fileno(stream), &c, 1) == 1)
	{
		if (c == '\n')
		{
			buffer[pos++] = '\0';
			*lineptr = buffer;
			*n = pos;
			return (pos);
		}
		buffer[pos++] = c;
		if (pos >= buf_size)
		{
			char *tmp = realloc(buffer, buf_size);

			buf_size += 128;

			if (!tmp)
			{
				free(buffer);
				return (-1);
			}
			buffer = tmp;
		}
	}
	free(buffer);
	return (-1);
}
