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
	char *line = NULL, *token, *argv[MAX_ARGS];
	char *working_cmd;
	size_t len = 0;
	ssize_t input;
	int i = 0;

	while (1)
	{
		printf("$ ");
		input = getline(&line, &len, stdin);

		if (input == -1)
			break;

		if (input == 1 && line[0] == '\n')
			continue;

		line[strcspn(line, "\n")] = '\0';

		if (built_ins(line, environ) == 1)
			continue;

		working_cmd = _which(line);
		if (working_cmd == NULL)
		{
			perror("command not found");
			continue;
		}

		token = strtok(working_cmd, " ");

		if (token == NULL)
			continue;

		for (i = 0; token != NULL && i < MAX_ARGS - 1; i++)
			argv[i] = token, token = strtok(NULL, " ");

		argv[i] = NULL;
		launch_exec_child(argv);
		free(working_cmd);
	}
	free(line);
	return (0);
}
