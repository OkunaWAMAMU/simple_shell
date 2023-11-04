#include "main.h"
/**
  *main- readline to print
  *
  *Return: always 0 (success)
  */



int main(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	char prompt[] = "$ ";

	write(1, prompt, strlen(prompt));

		fflush(stdout); /* Ensure the prompt is displayed immediately */

		read = getline(&line, &len, stdin);

		if (read != -1)
		{

		size_t newline_p = strcspn(line, "\n");

		if (newline_p < (size_t)read)
			line[newline_p] = '\0';
		char to_out[1024];
		int message_lenth = snprintf(to_out, sizeof(to_out), "%s\n", line);


		write(1, to_out, message_lenth);
	}

	free(line);
	return (0);
}
