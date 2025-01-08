#include "main.h"

/**
 * get_command_path - entry
 *
 * @command: erhbr
 * @env:nrtnr
 * Return: ujbzjvd
 */
char *get_command_path(char *command, char **env)
{
	char *path, *path_copy, *dir, *full_path;
	struct stat st;

	if (strchr(command, '/') != NULL)
	{
		if (stat(command, &st) == 0)
			return (strdup(command));
		return (NULL);
	}

	path = find_path_in_env(env);

	if (!path)
		return (NULL);

	path_copy = strdup(path);

	if (!path_copy)
		return (NULL);

	dir = strtok(path_copy, ":");

	while (dir)
	{
		full_path = build_full_path(dir, command);

		if (!full_path)
		{
			free(path_copy);
			return (NULL);
		}

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

/**
 * find_path_in_env - entry
 *
 * @env: vnerubjn
 * Return: Null
 */
char *find_path_in_env(char **env)
{
	int i = 0;

	while (env[i])
	{
		if (strncmp(env[i], "PATH=", 5) == 0)
			return (env[i] + 5);

		i++;
	}
	return (NULL);
}

/**
 * build_full_path - Entry
 *
 * @dir: zegv
 * @command: rebbeb
 * Return: full path
 */
char *build_full_path(char *dir, char *command)
{
	char *full_path;

	full_path = malloc(strlen(dir) + strlen(command) + 2);

	if (!full_path)
		return (NULL);

	sprintf(full_path, "%s/%s", dir, command);

	return (full_path);
}
