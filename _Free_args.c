
#include "main.h"

/**
 * free_args - Frees the argument array
 * @args: The argument array to free
 */
void free_args(char **args)
{
	int i = 0;

	if (!args)
		return;

	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args);
}
