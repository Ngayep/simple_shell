#include "shell.h"

/**
 * prompt_read - reads the input at the prompt
 * @prompt: pointer to the command entered at the prompt
 * @len: pointer to the  size of the command
 * @program_name: name of the program found in argv[0]
 * Return: 0
 */

void prompt_read(char **prompt, size_t *len, char *program_name)
{
	ssize_t read_bytes;

	if (prompt == NULL || len == NULL || program_name == NULL)
	{
		write(STDERR_FILENO, program_name, _strlen(program_name));
		write(STDERR_FILENO, ": prompt_read, Invalid input parameters\n", 40);
		exit(EXIT_FAILURE);
	}

	read_bytes = getline(prompt, len, stdin);

	if (read_bytes == -1)
	{
		perror(": prompt_read: getline failed");
		exit(EXIT_FAILURE);
	}
	else if (read_bytes == 0)
	{
		exit(EXIT_SUCCESS);
	}

	if ((*prompt)[read_bytes - 1] == '\n')
	{
		(*prompt)[read_bytes - 1] = '\0';
	}
}
