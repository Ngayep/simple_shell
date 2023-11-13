#include "shell.h"

/**
 * prompt_read - reads the input at the prompt
 * @prompt: command entered at the prompt
 * @len: size of the command
 * Return: 0
 */

void prompt_read(char *prompt, size_t len)
{
	size_t prompt_len;
	size_t i;

	char *trimmed;

	if (fgets(prompt, len, stdin) == NULL)
	{
		if (feof(stdin))
		{
			myprintf("\n");
			exit(EXIT_SUCCESS);
		} else
		{
			perror("prompt_read");
			exit(EXIT_FAILURE);
		}
	}

	prompt_len = _strlen(prompt);

	for (i = 0; i < prompt_len && prompt[i] != '\n'; i++)
	{

	}
	i = 0;

	trimmed = (char *)malloc((i + 1) * sizeof(char));
	if (trimmed == NULL)
	{
		perror("malloc failed");
		exit(EXIT_FAILURE);
	}
	prompt[i] = '\0';

	_strcpy(trimmed, prompt);
	_strcpy(prompt, trimmed);
}

/**
 * handle_path_env - handles path and environment variables
 * @command: the command and its arguments to be executed
 *
 *
* void handle_path_env(char const *command[])
*{
*	if (execve(command[0], command, NULL) == -1)
*	{
*		myprintf("Failure to execute: \n");
*		myprintf(command[0]);
*		perror("execve");
*
*exit(EXIT_FAILURE);
*	}
*}
*/
