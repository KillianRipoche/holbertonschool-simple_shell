#include "main.h"

int main(int argc, char *argv[], char **environ)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t Num_read;

	(void)argc;

	while (1)
	{

		if (isatty(STDIN_FILENO))
		{
			printf("$ ");
		}

		Num_read = getline(&line, &len, stdin);

		if (Num_read == -1)
		{
			if (isatty(STDIN_FILENO))
				printf("\n");
			break;
		}

		line[Num_read - 1] = '\0';

		if (strlen(line) == 0)
		{
			free(line);
			line = NULL;
			len = 0;
			continue;
		}
		/* if (strcmp(line, "exit") == 0)
		{
			free(line);
			exit(0);
		} */

		execute_command(line, argv[0], environ);
	}

	free(line);
	return 0;
}

void execute_command(char *line, char *exec_name, char **environ)
{
	pid_t child_pid = fork();

	if (child_pid < 0)
	{
		perror("fork");
		return;
	}
	else if (child_pid == 0)
	{
		char *args[2];
		args[0] = line;
		args[1] = NULL;

		if (execve(line, args, environ) == -1)
		{
			fprintf(stderr, "%s: No such file or directory\n", exec_name);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		if (wait(NULL) == -1)
		{
			perror("wait");
		}
	}
}
