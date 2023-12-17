#include "shell.h"

int is_built_in(char *command)

{
	char *built[] = {"exit", NULL};
	int i;
	for (i = 0; built[i]; i++)
	{
		if (strcmp(command, built[i]) == 0)
		{
			return (1);
		}
	}
	return (0);
}
void handle_built_in(char **command, int status, int idx)
{
	int i;

	(void)idx;
	if (strcmp(command[0], "exit") == 0)
	{
		free_array(command);
		exit(status);
	}
	else if (strcmp(command[0], "env") == 0)
	{
		for (i = 0; environ[i]; i++)
		{
			printf("%s\n", environ[i]);
		}
		free_array(command);
		(status) = 0;
	}
}
