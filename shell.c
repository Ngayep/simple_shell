#include "shell.h"

/**
 * main - simple shell
 *
 * Return: 0
 */

int main(void)
{
	char prompt[250];

	while (1)
	{
		prompt_display();
		prompt_read(prompt, sizeof(prompt));
		prompt_exec(prompt);
	}
	return (0);
}
