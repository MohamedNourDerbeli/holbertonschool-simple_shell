#include "shell.h"
/**
 * exec - exec
 * @command: char
 * @av: char
 * Return: Always 0.
 */
int exec(char **command, char **av, int idx)
{
	pid_t child;
	int status;
	char *path;
	path = handle_path(command[0]);
	if (!path)
	{
		fprintf(stderr, "%s: %d: %s: not found\n", av[0], idx, command[0]);
		free_array(command);
		return (127);
	}

	child = fork();
	if (child == 0)
	{
		if (execve(path, command, environ) == -1)
		{
			free(path), path = NULL;
			free_array(command);
		}
	}
	else
	{
		waitpid(child, &status, 0);
		free_array(command);
		free(path), path = NULL;
	}

	return (WEXITSTATUS(status));
}
