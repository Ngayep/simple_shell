#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void myprintf(const char *str);
void prompt_display(void);
void prompt_exec(const char *prompt);
void prompt_read(char *prompt, size_t len);

size_t _strlen(const char *s);

#endif
