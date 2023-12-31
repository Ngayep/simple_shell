#include "shell.h"

/**
 * main - simple shell
 *
 * Return: 0
 */

int main(void)
{
	char *prompt = NULL;
	size_t prompt_size = 0;

	while (1)
	{
		prompt_display();
		prompt_read(&prompt, &prompt_size, "/bin/sh");
		if (prompt == NULL || prompt_size == 0)
		{
			continue;
		}
		if (_strcmp(prompt, "exit") == 0)
		{
			free(prompt);
			break;
		}
		prompt_exec(prompt);

		prompt_size = 0;
	}
	return (0);
}
