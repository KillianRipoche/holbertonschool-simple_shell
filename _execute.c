#include "main.h"

/**
 * execute_command - Executes the given command
 * @command: The command to execute
 * @env: environnement
 */
void execute_command(char *command, char **env)
{
	char **args, *path;
	pid_t child_pid;
	int status;

	args = tokenize_input(command);
	if (!args || !args[0]) /* check if the code is empty */
	{
		free_args(args);
		return;
	}
	path = get_command_path(args[0], env); /* Resolve the full path */
	if (!path)
	{
		fprintf(stderr, "Command not found: %s\n", args[0]);
		free_args(args);
		return;
	}
	child_pid = fork(); /* Create a child process using fork */
	if (child_pid == -1)
	{
		perror("fork");
		free_args(args);
		free(path);
		return;
	}
	if (child_pid == 0) /* In the child process */
	{
		if (execve(path, args, env) == -1)
		{
			perror("execve");
			free(path);
			free_args(args);
			exit(EXIT_FAILURE);
		}
	}
	else /* In the parent process */
		wait(&status); /* Wait for the child process to finish */

	free_args(args);
	free(path);
}
