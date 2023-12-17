#include "shell.h"

int is_built_in(char *command)

{
	char *built[] = {"exit", NULL};
	int i;
	for (i = 0; built[i]; i++)
	{
		if (strcmp(command,built[i])==0)
		{
			return (1);
		}
	}
	return (0);
}
void handle_built_in(char **command, int status,int idx)
{
	(void)status;
	(void)idx;
	if (strcmp(command[0], "exit") == 0)
	{
		free_array(command);
		exit(127);
	}
}
