#include <stdio.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include "shell.h"

/**
 * main - Simple Shell functionality, a simplified version
 * of a regular shell environment
 * @argc: argument count (unused in this implementation)
 * @argv: holds the program name
 *
 * Return: void
 */

int main(int argc, char **argv)
{
	char *line = NULL, *argv_tokens[MAX_ARGS], *working_cmd, *progname = argv[0];
	size_t len = 0;
	ssize_t input;
	int i, status = 0, line_count = 1;

	(void)argc;
	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf("$ ");
		input = getline(&line, &len, stdin);
		if (input == -1)
		{
			free(line);
			exit(status);
		}
		line[strcspn(line, "\n")] = '\0';
		i = 0;
		argv_tokens[i] = strtok(line, " ");
		for (; argv_tokens[i] && i < MAX_ARGS - 1; i++)
			argv_tokens[i + 1] = strtok(NULL, " ");
		if (!argv_tokens[0] || built_ins(argv_tokens, environ, &status) == 1)
			continue;
		working_cmd = _which(argv_tokens[0]);
		if (working_cmd == NULL)
		{
			fprintf(stderr, "%s: %d: %s: not found\n"
					, progname, line_count, argv_tokens[0]);
			status = 2;
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
