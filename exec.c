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
		if (strcmp(command[0], "exit") == 0)
		{
			free_array(command);
			exit(0);
		}

		if (execve(command[0], command, environ) == -1)
		{
			perror(av[0]);
			free_array(command);
			exit(2);
		}
	}
	else
	{
		waitpid(child, &status, 0);
		free_array(command);
	}
	return (WEXITSTATUS(status));
}
