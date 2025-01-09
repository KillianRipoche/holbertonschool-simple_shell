#include "main.h"

/**
 * get_command_path - Finds the full path of a command
 *
 * @command: The name of the command to locate
 * @env: The environment variables
 * Return: The full path of the command if found, or NULL if not found
 */
char *get_command_path(char *command, char **env)
{
	char *path, *path_copy, *dir, *full_path;
	struct stat st;

	if (strchr(command, '/') != NULL) /* check if it's an absolute path*/
	{
		if (stat(command, &st) == 0) /* Check if the file exists */
			return (strdup(command));
		return (NULL);
	}

	path = find_path_in_env(env); /* Get the PATH environment */
	if (!path)
		return (NULL);

	path_copy = strdup(path); /* to avoid modifying the original */
	if (!path_copy)
		return (NULL);

	dir = strtok(path_copy, ":"); /* Tokenize the PATH */
	while (dir)
	{
		full_path = build_full_path(dir, command);
		if (!full_path)
		{
			free(path_copy);
			return (NULL);
		}
		if (stat(full_path, &st) == 0) /* Check if the command exists */
		{
			free(path_copy);
			return (full_path);
		}
		free(full_path);
		dir = strtok(NULL, ":"); /* Move to the next directory in PATH */
	}

	free(path_copy);
	return (NULL);
}

/**
 * find_path_in_env - Finds the PATH variable in the environment
 *
 * @env: The array of environment variables
 * Return: A pointer to the PATH variable value (string) or NULL if not found
 */
char *find_path_in_env(char **env)
{
	int i = 0;

	while (env[i]) /* Iterate through the environment variables */
	{
		/* Check if the current variable starts with "PATH=" */
		if (strncmp(env[i], "PATH=", 5) == 0)
			return (env[i] + 5);

		i++;
	}
	return (NULL);
}

/**
 * build_full_path - Constructs the full path to a command
 *
 * @dir: The directory in which to look for the command
 * @command: The command to append to the directory
 * Return: A dynamically allocated string containing the full path,
 * or NULL if memory allocation fails
 */
char *build_full_path(char *dir, char *command)
{
	char *full_path;

	/*Allocate memory for the full path: directory + "/" + command + null */
	full_path = malloc(strlen(dir) + strlen(command) + 2);

	if (!full_path)
		return (NULL);
	/* Format the full path as "dir/command */
	sprintf(full_path, "%s/%s", dir, command);

	return (full_path);
}
