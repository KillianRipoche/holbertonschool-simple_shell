
#include "main.h"

/**
 * tokenize_input - Splits the input into tokens
 * @input: The input string
 *
 * Return: Array of strings (tokens)
 */
char **tokenize_input(char *input)
{
	char **tokens = NULL;
	char *token;
	int token_count = 0;

	tokens = malloc(sizeof(char *) * MAX_TOKENS);
	if (!tokens)
		return (NULL);

	token = strtok(input, " \t\n");
	while (token && token_count < MAX_TOKENS - 1)
	{
		tokens[token_count] = token;
		token_count++;
		token = strtok(NULL, " \t\n");
	}
	tokens[token_count] = NULL;

	return (tokens);
}

/**
 * free_args - Frees the argument array
 * @args: The argument array to free
 */
void free_args(char **args)
{
	if (args)
		free(args);
}

/**
 * get_command_path - Gets the full path of a command
 * @command: The command to find
 *
 * Return: Full path of the command or NULL if not found
 */
char *get_command_path(char *command)
{
	char *path, *path_copy, *dir, *full_path;
	struct stat st;

	if (strchr(command, '/') != NULL)
	{
		if (stat(command, &st) == 0)
			return (strdup(command));
		return (NULL);
	}

	path = getenv("PATH");
	if (!path)
		return (NULL);

	path_copy = strdup(path);
	dir = strtok(path_copy, ":");

	while (dir)
	{
		full_path = malloc(strlen(dir) + strlen(command) + 2);
		sprintf(full_path, "%s/%s", dir, command);

		if (stat(full_path, &st) == 0)
		{
			free(path_copy);
			return (full_path);
		}

		free(full_path);
		dir = strtok(NULL, ":");
	}

	free(path_copy);
	return (NULL);
}
