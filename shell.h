#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>

/**
 * struct Node - list of arguments
 * @data: argument stored
 * @next: address of next element
*/

typedef struct Node
{
	char *data;
	struct Node *next;
} Node;

extern char **environ;

void myprintf(const char *str);
void prompt_display(void);
void prompt_exec(const char *prompt);
void prompt_read(char **prompt, size_t *len, char *program_name);
void tokenize_input(const char *input, Node **argv, int *argc);
Node *append_node(Node *head, const char *data);
void free_list(Node *head);
char **convert_to_argv(Node *head, int *argc);
void execute_command(char *argv[]);
void print_env(void);
void wait_check_status(pid_t child_pid);
void handle_exit(Node *argv);
void handle_env(Node *argv);
int _strcmp(const char *str1, const char *str2);
char *_strdup(const char *s);
size_t _strlen(const char *s);
char *_strcpy(char *dest, const char *src);

#endif
