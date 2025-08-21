#include <stdio.h>
#include "shell.h"
#include <string.h>
#include <stdlib.h>

int last_status = 0;

/**
 * built_ins - function mapping inbuilt shell functions
 * @line: command to check in the list of functions
 * @environ: environment to access
 * @status: status returned by global variable
 * Return: corresponding function, or 0 if no match found
 */

int built_ins(char *line, char **environ)
{
	char *argv[MAX_ARGS];
	char *token;
	int i = 0;

	token = strtok(line, " ");
	while (token != NULL && i < MAX_ARGS - 1)
	{
		argv[i++] = token;
		token = strtok(NULL, " ");
	}
	argv[i] = NULL;

	if (argv[0] == NULL)
		return (0);

	if (strcmp(argv[0], "exit") == 0)
	{
		free(line);
		exit(last_status);
	}
	if (strcmp(argv[0], "env") == 0)
	{
		printenv(environ);
		return (1);
	}

	return (0);
}

/**
 * printenv - prints a list of environment variables
 * and their values
 * @environ: environment to access
 *
 * Return: printed list of environment variables
 */

void printenv(char **environ)
{
	int i;

	for (i = 0; environ[i] != NULL; i++)
		printf("%s\n", environ[i]);
}
