#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "shell.h"

char *_getenv(const char *name)
{
	int i = 0;
	size_t len;
       
	len = strlen(name); //works out the length of the variable name (PATH->4) (not inc terminator)

	while (environ[i] != NULL) //environ is null-terminated array
	{
		if (strncmp(environ[i], name, len) == 0 //targets name and names' len
				&& environ[i][len] == '=') //makes sure = follows name, in case of partial match like PATH->PATHWAY conflict
			return (environ[i] + len + 1); //returns pointer to the beginning of the value string
	i++;
	}

	return (NULL);
}
