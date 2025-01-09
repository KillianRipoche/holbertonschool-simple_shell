#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

/**
 * main - PID
 *
 * Return: Always 0.
 */
int main(void)
{
	pid_t my_ppid, my_pid;

	my_pid = getpid();
	my_ppid = getppid();
	printf("%u\n%u\n", my_ppid, my_pid);
	return (0);
}
