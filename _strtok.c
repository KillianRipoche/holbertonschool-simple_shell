#include "main.h"
/**
 * tokenize_input - Splits the input into tokens
 * @input: The input string to tokenize
 *
 * Return: A dynamically allocated array of strings (tokens)
 * or NULL if memory allocation fails
 */
char **tokenize_input(char *input)
{
	char **tokens, *token;
	int token_count = 0;

	tokens = malloc(sizeof(char *) * MAX_TOKENS);

	if (!tokens)
		return (NULL);

	/* Tokens are separated by spaces, tabs, and newlines */
	token = strtok(input, " \t\n");

	/* Loop through the tokens and store them in the array */
	while (token && token_count < MAX_TOKENS - 1)
	{
		/* Duplicate the token and store it in the tokens array */
		tokens[token_count] = strdup(token);
		if (!tokens[token_count])
		{
			free_args(tokens);
			return (NULL);
		}
		token_count++;
		token = strtok(NULL, " \t\n"); /* Get the next token */
	}

	tokens[token_count] = NULL;

	return (tokens);
}
