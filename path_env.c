#include "shell.h"
#include <unistd.h>

/**
 * print_env - prinnts the environment
 */
void print_env(void)
{
	char *env;

	for (env = *environ; env != NULL; env = *(environ + 1))
	{
		write(STDOUT_FILENO, env, _strlen(env));
		write(STDOUT_FILENO, "\n", 1);
	}
}
