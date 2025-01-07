#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

char *_getenv(const char *name, char **env);
int main(void);
void execute_command(char *line);

#endif
