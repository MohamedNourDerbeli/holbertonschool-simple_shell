#include "shell.h"
/**
 * exec - exec
 * @command: char
 * @av: char
 * Return: Always 0.
 */
int exec(char **command, char **av)
{
	pid_t child;
	int status;


	child = fork();
	if (child == 0)
	{
		if (execve(handle_path(command[0]), command, environ) == -1)
		{
			perror(av[0]);
			free_array(command);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		waitpid(child, &status, 0);
		free_array(command);
	}

	return (WEXITSTATUS(status));
}
