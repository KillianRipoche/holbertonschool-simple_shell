#include "main.h"

int main(int argc, char *argv[])
{
	char *line = NULL;
	size_t len = 0;
	ssize_t Numc_read;

	(void)argc;

	while (1)
	{

		if (isatty(STDIN_FILENO))
		{
			printf("$ ");
			fflush(stdout);
		}

		Numc_read = getline(&line, &len, stdin);

		if (Numc_read == -1)
		{
			if (isatty(STDIN_FILENO))
				printf("\n");
			break;
		}

		line[Numc_read - 1] = '\0';

		if (strlen(line) == 0)
			continue;

		if (strcmp(line, "exit") == 0)
		{
			free(line);
			exit(0);
		}

		execute_command(line, argv[0]);
	}

	free(line);
	return 0;
}

void execute_command(char *line, char *exec_name)
{
	pid_t child_pid = fork();

	if (child_pid < 0)
	{
		perror(exec_name);
		return;
	}
	else if (child_pid == 0)
	{
		char *args[2];
		args[0] = line;
		args[1] = NULL;

		free(line);

		if (execve(line, args, NULL) == -1)
		{
			perror(exec_name);
			exit(1);
		}
	}
	else
	{
		if (wait(NULL) == -1)
		{
			perror(exec_name);
		}
	}
}
