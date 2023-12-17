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
				return my_strdup(command);

			return NULL;
		}
	}

	env = _get_env("PATH");
	if (!env)
		return NULL;

	path = strtok(env, ":");
	while (path)
	{
		cmd = malloc(strlen(path) + strlen(command) + 2);
		if (cmd != NULL)
		{
			snprintf(cmd, strlen(path) + strlen(command) + 2, "%s/%s", path, command);
			if (stat(cmd, &buf) == 0)
			{
				free(env);
				return cmd;
			}

			free(cmd);

			path = strtok(NULL, ":");
		}
		else
		{
			free(env);
			return NULL;
		}
	}

	free(env);
	return NULL;
}
