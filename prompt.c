#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
/** */
int main(int ac, char *argv[])
{
	char *prompt = "$";
	char *lineptr;
	size_t n = 0;

	(void)ac; (void)argv;

	printf("%s", prompt);
	getline(&lineptr, &n, stdin);
	printf("%s\n", lineptr);

	free(lineptr);
	return (0);
}