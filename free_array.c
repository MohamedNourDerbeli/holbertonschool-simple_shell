#include "shell.h"

void free_array(char **command)
{
	int i ;

	if (!command)
		return;

	for (i = 0; command[i]; i++)
		free(command[i]), command[i] = NULL;
	free(command), command = NULL;
}
