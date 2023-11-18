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
		perror("tokenize_input: strdup failed");
		exit(EXIT_FAILURE);
	}

	token = strtok(input_copy, " ");
	*argc = 0;

	while (token != NULL)
	{
		*argv = append_node(*argv, token);
		(*argc)++;
		token = strtok(NULL, " ");
	}
	free(input_copy);
}

/**
 * execute_command - execute a command with arguments
 * @argv: array of arguments
 * @command: command to be executed
 */
void execute_command(const char *command, char *argv[])
{
	char *full_path = searchpath(command);

	if (full_path != NULL)
	{
		if (execve(full_path, argv, NULL) == -1)
		{
			perror("execute_command: execve failed");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		char not_found_msg[] = "Command not found:";
		size_t cmd_len = _strlen(command);
		size_t not_found_len = sizeof(not_found_msg) - 1;

		write(STDOUT_FILENO, not_found_msg, not_found_len);
		write(STDOUT_FILENO, command, cmd_len);
		write(STDOUT_FILENO, "\n", 1);
		exit(EXIT_FAILURE);
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
	char **argv_array = NULL;
	Node *argv = NULL;
	int j, argc = 0;

	if (child_pid == -1)
	{
		perror("fork failed");
		exit(EXIT_FAILURE);
	}
	else if (child_pid == 0)
	{
		tokenize_input(prompt, &argv, &argc);
		if (argc > 0)
		{
			handle_exit(argv);
			handle_env(argv);
		}

		argv_array = convert_to_argv(argv, &argc);
		execute_command(prompt, argv_array);
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
		for (j = 0; j < argc; j++)
		{
			free(argv_array[j]);
		}
		free(argv_array);

		exit(EXIT_SUCCESS);
	}
}
