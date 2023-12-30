#include "shell.h"
/**
 * handle_path - Locates the full path of an executable command.
 *
 * @command: The command to find the full path for.
 * Return: A dynamically allocated string containing the full path of the command.
 *         Returns NULL if the command is not found or in case of memory allocation failure.
 */
char *handle_path(char *command)

{
	char *env, *path, *cmd;
	struct stat buf;
	int i;

	/*Check if the command contains a '/' (absolute or relative path)*/
	for (i = 0; command[i]; i++)
	{
		if (command[i] == '/')
		{
			/*Check if the file exists at the specified path*/
			if (stat(command, &buf) == 0)
				return (my_strdup(command));
			return (NULL);
		}
	}
	/*If the command does not contain '/', search in the directories listed in the PATH environment variable*/
	env = _get_env("PATH");
	if (!env)
		return (NULL);
	/*Tokenize the PATH variable to iterate through its directories*/
	path = strtok(env, ":");
	while (path)
	{
		/*Allocate memory for the full path by combining the directory and the command*/
		cmd = malloc(strlen(path) + strlen(command) + 2);
		if (cmd != NULL)
		{
			/* Construct the full path*/
			snprintf(cmd, strlen(path) + strlen(command) + 2, "%s/%s", path, command);
			/* Check if the file exists at the constructed path*/
			if (stat(cmd, &buf) == 0)
			{
				free(env);
				return (cmd);
			}
			/*Free the allocated memory for the current path*/
			free(cmd);
			/*Move to the next directory in PATH*/
			path = strtok(NULL, ":");
		}
		else
		{
			/* Free the environment variable and return NULL in case of memory allocation failure*/
			free(env);
			return (NULL);
		}
	}
	/*Free the environment variable and return NULL if the command is not found*/
	free(env);
	return (NULL);
}
