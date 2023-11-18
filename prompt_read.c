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
		perror("prompt_read: getline failed");
		exit(EXIT_FAILURE);
	}
	else if (read_bytes == 0)
	{
		myprintf("\n");
		exit(EXIT_SUCCESS);
	}

	if ((*prompt)[read_bytes - 1] == '\n')
	{
		(*prompt)[read_bytes - 1] = '\0';
	}
}

/**
 * searchpath - search the command in each dir of the Path
 * @command: command issued
 * Return: full path if success, 0 otherwise
 */

char *searchpath(const char *command)
{
	char *path = getenv("PATH");
	char *path_copy = _strdup(path);
	char *dir = strtok(path_copy, ":");

	while (dir != NULL)
	{
		size_t dir_len = _strlen(dir);
		size_t cmd_len = _strlen(command);
		char *full_path = malloc(dir_len + 1 + cmd_len + 2);

		if (!full_path)
		{
			perror("malloc");
			exit(EXIT_FAILURE);
		}

		_strcpy(full_path, dir);
		full_path[dir_len] = '/';
		_strcpy(full_path + dir_len + 1, command);

		if (access(full_path, X_OK) == 0)
		{
			free(path_copy);
			return (full_path);
		}
		free(full_path);
		dir = strtok(NULL, ":");
	}
	free(path_copy);
	return (NULL);
}
