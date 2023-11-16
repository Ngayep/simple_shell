#include "shell.h"

/**
 * handle_exit - handle the "exit" command
 * @argv: pointer to the head of the linkedlist of arguments
 */

void handle_exit(Node *argv)
{
	if (argv != NULL && _strcmp(argv->data, "exit") == 0)
	{
		free_list(argv);
		exit(EXIT_SUCCESS);
	}
}

/**
 * handle_env - handle the "env" command
 * @argv: pointer to the head of the linkedlist of arguments
 */

void handle_env(Node *argv)
{
	if (argv != NULL && _strcmp(argv->data, "env") == 0)
	{
		print_env();
		free_list(argv);
		exit(EXIT_SUCCESS);
	}
}
