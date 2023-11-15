#include "shell.h"

/**
 * prompt_read - reads the input at the prompt
 * @prompt: pointer to the command entered at the prompt
 * @len: pointer to the  size of the command
 * Return: 0
 */

void prompt_read(char **prompt, size_t *len)
{
	ssize_t read_bytes;

	read_bytes = getline(prompt, len, stdin);

	if (read_bytes == -1)
	{
		perror("prompt_read");
		exit(EXIT_FAILURE);
	} 
	else if (read_bytes == 0 || (*prompt)[0] == '\n')
	{
		myprintf("\n");
		exit(EXIT_SUCCESS);
	}

	if ((*prompt)[read_bytes -1] == '\n')
	{
		(*prompt)[read_bytes - 1] = '\0';
	}
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
