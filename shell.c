#include "main.h"

/**
 * main - Entry point for the simple shell program
 * @ac: Argument count (unused)
 * @av: Argument vector (unused)
 * @env: environnement
 *
 * Return: 0 on success
 */
int main(int ac, char **av, char **env)
{
	char *input = NULL;
	size_t input_size = 0;
	ssize_t read_size;

	(void)ac;
	(void)av;

	while (1) /* Main loop of the shell */
	{
		if (isatty(STDIN_FILENO)) /* Check if input is from a terminal */
			write(STDOUT_FILENO, "$ ", 2);

		/* Read a line of input from the user*/
		read_size = getline(&input, &input_size, stdin);
		if (read_size == -1)
			break;

		if (input[read_size - 1] == '\n')
			input[read_size - 1] = '\0';

		if (strcmp("env", input) == 0)
		{
			print_env(env);
			continue;
		}

		if (strcmp("exit", input) == 0)
		{
			free(input);
			exit(0);
		}

		execute_command(input, env);
	}

	free(input);
	return (0);
}
