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

int main(int argc, char **argv)
{
	char *line = NULL, *argv_tokens[MAX_ARGS], *working_cmd;
	size_t len = 0;
	ssize_t input;
	int i;
	int status = 0;
	char *progname = argv[0];
	int line_count = 1;

	(void)argc;
	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf("$ ");
		input = getline(&line, &len, stdin);
		if (input == -1)
			break;
		line[strcspn(line, "\n")] = '\0';
		i = 0;
		argv_tokens[i] = strtok(line, " ");
		while (argv_tokens[i] != NULL && i < MAX_ARGS - 1)
		{
			i++;
			argv_tokens[i] = strtok(NULL, " ");
		}
		if (argv_tokens[0] == NULL)
			continue;
		if (built_ins(argv_tokens[0], environ) == 1)
			continue;
		working_cmd = _which(argv_tokens[0]);
		if (working_cmd == NULL)
		{
			fprintf(stderr, "%s: %d: %s: not found\n", progname, line_count, argv_tokens[0]);
			status = 127;
			line_count++;
			continue;
		}
		argv_tokens[0] = working_cmd;
		status = launch_exec_child(argv_tokens);
		free(working_cmd);
	}
	free(line);
	return (status);
}
