
#include "main.h"

/**
 * print_env - Entry
 *
 * @env: Environnement
 */
void print_env(char **env)
{
	int i = 0;

	if (!env)
		return;

	while (env[i])
	{
		write(STDOUT_FILENO, env[i], strlen(env[i]));
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
}
