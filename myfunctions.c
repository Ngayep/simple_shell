#include "shell.h"

/**
 * _strlen - returns the lenght of a string
 * @s: the string whose lenght is to be returned
 * Return: the lenght of the string
 */

size_t _strlen(const char *s)
{
	size_t len;

	len = 0;
	while (*s != '\0')
	{
		len++;
		s++;
	}
	return (len);
}
