#include "shell.h"

/**
 * prompt_read - reads the input at the prompt
 * @prompt: command entered at the prompt
 * @len: size of the command
 * Return: 0
 */

void prompt_read(char *prompt, size_t len)
{
	if (fgets(prompt, len, stdin) == NULL)
	{
		if (feof(stdin))
		{
			myprintf("\n");
			exit(EXIT_SUCCESS);
		} else
		{
			myprintf("failure to read input.\n");
			exit(EXIT_FAILURE);
		}
	}
	prompt[strcspn(prompt, "\n")] = '\0';
}
