#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "shell.h"

/**
 * _getenv - searches environ for environment variable
 * entered, and returns the values held by the var
 * @name: environment variable to search for
 *
 * Return: values applied to the env var
 */

char *_getenv(const char *name)
{
	int i = 0;
	size_t len;

	len = strlen(name);

	while (environ[i] != NULL)
	{
		if (strncmp(environ[i], name, len) == 0
				&& environ[i][len] == '=')
			return (environ[i] + len + 1);
	i++;
	}

	return (NULL);
}
