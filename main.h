#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>

/* Define the maximum number of tokens that can be created when tokenizing */
#define MAX_TOKENS 64

void print_env(char **env);
char *build_full_path(char *dir, char *command);
char *find_path_in_env(char **env);
char **tokenize_input(char *input);
void free_args(char **args);
char *get_command_path(char *command, char **env);
void execute_command(char *command, char **env);

#endif
