#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "shell.h"

/**
 * _which - searches PATH for a command matching *command
 * and returns the complete path if it is possible to run
 * @command: command entered into shell, such as ls
 *
 * Return: location of the command executable
 * followed by the command itself
 */

char *_which(char *command)
{
	char compl_path[1024];
	char *path_dir;
	char *path_dir_item;
	char *path_copy;
	int i = 0;

	if (command[i] == '/')
		return (command);

	path_dir = _getenv("PATH");

	if (path_dir == NULL)
		return (NULL);

	path_copy = strdup(path_dir);
	path_dir_item = strtok(path_copy, ":");

	while (path_dir_item != NULL)
	{
		sprintf(compl_path, "%s/%s", path_dir_item, command);

		if (access(compl_path, X_OK) == 0)
		{
			free(path_copy);
			return (strdup(compl_path));
		}

		path_dir_item = strtok(NULL, ":");
	}

	free(path_copy);
	return (NULL);
}
