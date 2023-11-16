#include "shell.h"

/**
 * append_node - append a node to the linked list
 * @head: pointer to the head of te linked list
 * @data: string data to be stored in the node
 * Return: pointer to the new node
 */

Node *append_node(Node *head, const char *data)
{
	Node *new_node;
	char *copied_data;
	Node *current;

	(void)data;
	current = head;
	new_node = (Node *)malloc(sizeof(Node));

	if (new_node == NULL)
	{
		perror("malloc failed");
		exit(EXIT_FAILURE);
	}

	copied_data = _strdup(data);
	if (copied_data == NULL)
	{
		free(new_node);
		return (NULL);
	}
	if (head == NULL)
	{
		return (new_node);
	}
	while (current->next != NULL)
	{
		current = current->next;
	}
	current->next = new_node;
	return (head);
}

/**
 * _strcmp  - compares two strings
 * @str1: string to compare
 * @str2: string to compare
 * Return: null terminated strings
 */

int _strcmp(const char *str1, const char *str2)
{
	while (*str1 != '\0' && *str2 != '\0' && *str1 == *str2)
	{
		str1++;
		str2++;
	}
	return (*str1 - *str2);
}


