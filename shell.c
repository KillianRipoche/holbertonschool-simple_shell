#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

int main()
{
	char *buffer = NULL;
	size_t buff_size = 0;
	pid_t child_pid;
	char *args[] = {buffer, NULL};

	while (1)
	{
		printf("bienvenue à la maison\n");
		printf("type 'exit' to quit\n");
		printf("$");

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
				perror("execve failed");
				exit(1);
			}
		}
		else
		{
			wait(NULL);
		}

		free(buffer);
		return (0);
	}
}
