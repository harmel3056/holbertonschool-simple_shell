#include <stdio.h>
#include "shell.h"
#include <string.h>
#include <stdlib.h>


/**
 * built_ins - function mapping inbuilt shell functions
 * @argv: commands to check against inbuilt functionality
 * @environ: environment to access
 * @status: status returned by global variable
 *
 * Return: corresponding function, or 0 if no match found
 */

int built_ins(char *argv[], char **environ, int *status)
{
	if (argv[0] == NULL)
		return (0);

	if (strcmp(argv[0], "exit") == 0)
	{
		exit(*status);
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
