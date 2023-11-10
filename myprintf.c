#include "shell.h"

/**
 * myprintf - display input
 * @str: pointer to a character string
 * Return: 0
 */

void myprintf(const char *str)
{
	write(STDOUT_FILENO, &str, _strlen(str));
}
