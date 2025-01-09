
#include "main.h"
/**
 * tokenize_input - Splits the input into tokens
 * @input: The input string
 *
 * Return: Array of strings (tokens)
 */
char **tokenize_input(char *input)
{
	char **tokens, *token;
	int token_count = 0;

	tokens = malloc(sizeof(char *) * MAX_TOKENS);

	if (!tokens)
		return (NULL);

	token = strtok(input, " \t\n");

	while (token && token_count < MAX_TOKENS - 1)
	{
		tokens[token_count] = strdup(token);
		if (!tokens[token_count])
		{
			free_args(tokens);
			return (NULL);
		}
		token_count++;
		token = strtok(NULL, " \t\n");
	}

	tokens[token_count] = NULL;

	return (tokens);
}
