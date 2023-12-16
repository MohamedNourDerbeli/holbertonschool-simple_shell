#include "shell.h"

char *handle_path(char *command)
{
	char *env, *path, *cmd;
	struct stat buf;
	int i;

	for (i = 0; command[i]; i++)
	{
		if (command[i] == '/')
		{
			if (stat(command, &buf) == 0)
				return (my_strdup(command));

			return (NULL);
		}
	}

	env = _get_env("PATH");
	if (!env)
		return (NULL);

	path = strtok(env, ":");
	while (path)
	{
		cmd = malloc(strlen(path) + strlen(command) + 2);
		if (cmd)
		{
			strcpy(cmd, path);
			strcat(cmd, "/");
			strcat(cmd, command);
			if (stat(cmd, &buf) == 0)
			{
				free(env);
				return (cmd);
			}
			free(cmd), cmd = NULL;

			path = strtok(NULL, ":");
		}
	}
	free(env);
	free(path);
	return (NULL);
}
