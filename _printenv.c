#include "main.h"

/**
 * print_env - Prints the environment variables to the standard output
 *
 * @env: The array of environment variable
 */
void print_env(char **env)
{
	int i = 0;

	if (!env) /* Check if the environment variable array is NULL */
		return;

	/* Iterate through each environment variable and print it */
	while (env[i])
	{
		write(STDOUT_FILENO, env[i], strlen(env[i]));
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
}
