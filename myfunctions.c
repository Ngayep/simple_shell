#include "shell.h"

/**
 * _strlen - returns the lenght of a string
 * @s: the string whose lenght is to be returned
 * Return: the lenght of the string
 */

size_t _strlen(const char *s)
{
	const char *p = s;

	while (*p != '\0')
	{
		p++;
	}
	return (p - s);
}


/**
 * *_strcpy - copies the string pointed to by src
 * including the terminating null byte (\0)
 * to the buffer pointed to by dest
 * @dest: pointer to the buffer in which we copy the string
 * @src: string to be copied
 *
 * Return: the pointer to dest
 */

char *_strcpy(char *dest, const char *src)
{
	char *original_dest = dest;

	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (original_dest);
}

/**
 * _strdup - duplicates a string using dynamic memory allocation
 * @s: input string to duplicate
 * Return: pointer to the newly allocated string
 */

char *_strdup(const char *s)
{
	size_t len;
	char *dup_str;

	len = _strlen(s) + 1;
	dup_str = (char *)malloc(len * sizeof(*dup_str));

	if (dup_str == NULL)
	{
		perror("malloc failed to allocate memory");
		exit(EXIT_FAILURE);
	}
	_strcpy(dup_str, s);
	return (dup_str);
}

/**
 * free_list - free the linked list
 * @head: pointer to the head of the linked list
 */
void free_list(Node *head)
{
	if (head == NULL)
	{
		return;
	}
	while (head != NULL)
	{
		Node *temp = head;

		head = head->next;
		free(temp->data);
		free(temp);
	}
}
/**
 * convert_to_argv - converts a linked list to an array
 * @head: head of node
 * @argc: argument count
 * Return: an array
 */
char **convert_to_argv(Node *head, int *argc)
{
	char **argv_array = (char **)malloc((*argc + 1) * sizeof(char *));
	int i = 0;
	Node *current = head;

	*argc = 0;

	while (current != NULL)
	{
		(*argc)++;
		current = current->next;
	}

	if (argv_array == NULL)
	{
		perror("malloc failed");
		exit(EXIT_FAILURE);
	}

	current = head;

	while (current != NULL)
	{
		argv_array[i] = _strdup(current->data);
		if (argv_array[i] == NULL)
		{
			perror("malloc failed");
			exit(EXIT_FAILURE);
		}
		current = current->next;
		i++;
	}
	argv_array[i] = NULL;
	return (argv_array);
}
