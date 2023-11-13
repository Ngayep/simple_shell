#include "shell.h"

/**
 * tokenize_input - tokenize the input string into arguments
 * @input: input string to tokenize
 * @argv: pointer to store the head of the linkedlist of arguments
 * @argc: pointer to store argument count
 */

void tokenize_input(const char *input, Node **argv, int *argc)
{
	char *input_copy;
	char *token;

	if (input == NULL)
	{
		return;
	}

	input_copy = _strdup(input);

	if (input_copy == NULL)
	{
		return;
	}

	token = strtok(input_copy, " ");
	*argc = 0;

	while (token != NULL)
	{
		*argv = append_node(*argv, token);
		(*argc)++;
		token = strtok(NULL, " ");
	}
	if (*argc > 0 && _strcmp((*argv)->data, "exit") == 0)
	{
		free_list(*argv);
		free(input_copy);
		exit(EXIT_SUCCESS);
	}
	if (*argc > 0 && _strcmp((*argv)->data, "env"))
	{
		print_env();
		free_list(*argv);
		free(input_copy);
		exit(EXIT_SUCCESS);
	}
	if (input_copy != NULL)
	{
		free(input_copy);
	}
}

/**
 * execute_command - execute a command with arguments
 * @argv: array of arguments
 */
void execute_command(char *argv[])
{
	if (argv[0] != NULL)
	{
		if (execve(argv[0], argv, NULL) == -1)
		{
			myprintf("Failure to execute.\n");
			myprintf(argv[0]);
			perror("execve");
			exit(EXIT_FAILURE);
		}
	}
}

/**
 * wait_check_status - wait for a child process and check its status
 * @child_pid: the process ID of the child
 */
void wait_check_status(pid_t child_pid)
{
	 int status;
	if (child_pid != -1)
	{
		if (waitpid(child_pid, &status, 0) == -1)
		{
			perror("waitpid failed");
			exit(EXIT_FAILURE);
		}
		if (WIFEXITED(status))
		{
			int exit_status = WEXITSTATUS(status);
			(void)exit_status;

		} else if (WIFSIGNALED(status))
		{
			int signal_num = WTERMSIG(status);
			(void)signal_num;
		}
	}
}

/**
 *prompt_exec - executes commands issued at the prompt
 *@prompt: string corresponding to the command issued
 */

void prompt_exec(const char *prompt)
{
	pid_t child_pid = fork();

	if (child_pid == -1)
	{
		perror("fork failed");
		exit(EXIT_FAILURE);
	}
	else if (child_pid == 0)
	{
		char **argv_array;
		Node *argv = NULL;
		int argc, j;
		
		tokenize_input(prompt, &argv, &argc);

		argv_array = convert_to_argv(argv, &argc);

		execute_command(argv_array);
		
		free_list(argv);

		for (j = 0; j < argc; j++)
		{
			free(argv_array[j]);
		}
		free(argv_array);

		exit(EXIT_SUCCESS);
	}
	else
	{
		wait_check_status(child_pid);
	}
}
