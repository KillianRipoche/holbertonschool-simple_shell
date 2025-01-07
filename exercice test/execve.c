#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void)
{
	pid_t child_pid;
	int i, status;

	for (i = 0; i < 5; i++)
	{
		child_pid = fork();
		if (child_pid == -1)
		{
			perror("Fork error");
			return (1);
		}

		if (child_pid == 0)
		{
			printf("Child %d: Executing 'ls -l /tmp'\n", i + 1);
			execlp("ls", "ls", "-l", "/tmp", NULL);
			perror("execlp error");
			exit(1);
		}
		else // Code executed by the parent process
		{
			wait(&status); // Wait for the child to finish
			printf("Child %d has finished.\n", i + 1);
		}
	}

	printf("All child processes have completed.\n");
	return (0);
}
