#include <stdio.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include "shell.h"

/**
 * main - Simple Shell functionality
 *
 * Return: void
 */

int main(void)
{
	char *line = NULL, *argv[MAX_ARGS], *working_cmd;
	size_t len = 0;
	ssize_t input;
	int i;

	while (1)
	{
		if (isatty(STDIN_FILENO) != 0)
			printf("$ ");
		input = getline(&line, &len, stdin);
		if (input == -1)
			break;
		line[strcspn(line, "\n")] = '\0';
		i = 0;
		argv[i] = strtok(line, " ");
		while (argv[i] != NULL && i < MAX_ARGS - 1)
		{
			i++;
			argv[i] = strtok(NULL, " ");
		}
		if (argv[0] == NULL)
			continue;
		if (built_ins(argv[0], environ) == 1)
			continue;
		working_cmd = _which(argv[0]);
		if (working_cmd == NULL)
		{
			perror("command not found");
			continue;
		}
		argv[0] = working_cmd;
		launch_exec_child(argv);
		free(working_cmd);
	}
	free(line);
	return (0);
}
