#include "main.h"

/**
 * free_args - Frees the argument array
 * @args: The argument array to free
 */
void free_args(char **args)
{
	int i = 0;

	if (!args) /* Check if the argument array is NULL */
		return;

	while (args[i]) /* Iterate through the array and free each string */
	{
		free(args[i]);
		i++;
	}
	free(args);
}
