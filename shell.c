#include "main.h"

int main(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;

	while (1)
	{

		if (isatty(STDIN_FILENO))
		{
			printf("$ ");
			fflush(stdout);
		}

		nread = getline(&line, &len, stdin);

		if (nread == -1)
		{
			if (isatty(STDIN_FILENO))
				printf("\n");
			break;
		}

		line[nread - 1] = '\0';

		if (strlen(line) == 0)
			continue;

		if (strcmp(line, "exit") == 0)
		{
			free(line);
			exit(0);
		}

		execute_command(line);
	}

	free(line);
	return 0;
}

void execute_command(char *line)
{
	pid_t child_pid = fork();

	if (child_pid < 0)
	{
		perror("fork failed");
		return;
	}
	else if (child_pid == 0)
	{
		char *args[2];
		args[0] = line;
		args[1] = NULL;

		if (execve(line, args, NULL) == -1)
		{
			perror("execve failed");
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
