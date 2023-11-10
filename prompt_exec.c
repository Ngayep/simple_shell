#include "shell.h"

/**
 *prompt_exec - executes commands issued at the prompt
 *@prompt: string corresponding to the command issued
 */

void prompt_exec(const char *prompt)
{
	pid_t child_pid;

	child_pid = fork();

	if (child_pid == -1)
	{
		perror("sorry, fork failed");
		exit(EXIT_FAILURE);
	} else if (child_pid == 0)
	{
		execlp(prompt, prompt, (char *)NULL);
		perror("this is execlp");
		exit(EXIT_FAILURE);
	} else
	{
		wait(NULL);
	}
}
