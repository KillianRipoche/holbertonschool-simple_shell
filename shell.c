#include "main.h"

int main(int argc, char *argv[])
{
	char *buffer = NULL;
	size_t buff_size = 0;
	pid_t child_pid;
	char *args[2];
	(void)argc;
	(void)argv;

	while (1)
	{
		printf("Welcome to my shell\n");
		printf("type 'exit' to quit\n");
		printf("$ ");

		if (getline(&buffer, &buff_size, stdin) == -1)
		{
			perror("getline failed");
			free(buffer);
			exit(1);
		}

		buffer[strcspn(buffer, "\n")] = 0;

		if (strcmp(buffer, "exit") == 0)
		{
			free(buffer);
			exit(0);
		}

		child_pid = fork();
		if (child_pid < 0)
		{
			perror("fork failed");
			free(buffer);
			exit(1);
		}
		else if (child_pid == 0)
		{

			if (execve(buffer, args, NULL) == -1)
			{
				perror(argv[0]);
				free(buffer);
				exit(1);
			}
		}
		else
		{
			if (wait(NULL) == -1)
			{
				perror("wait failed");
			}
		}
	}

	free(buffer);
	return 0;
}
