#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>
#include "shell.h"

/**
 * launch_exec_child - forks main() process, then runs execve with argv
 * data parsed above in the child process. The parent process waits
 * for the child process to complete.
 * @argv: command to execute
 *
 * Return: 0 on success, 1 on failure
 */

int launch_exec_child(char *argv[])
{
	pid_t pid;
	int status;

	pid = fork();

	if (pid == 0)
	{
		if (execve(argv[0], argv, environ) == -1)
		{
			perror("execve failure");
			exit(EXIT_FAILURE);
		}
	}

	else if (pid > 0)
		wait(&status);

	else
	{
		perror("fork failed");
		return (1);
	}

	return (0);
}
