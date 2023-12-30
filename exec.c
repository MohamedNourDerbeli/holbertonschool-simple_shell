#include "shell.h"
/**
 * exec - Executes an external command.
 *
 * @command: Array of strings representing the command and its arguments.
 * @av: Array of strings representing the command-line arguments.
 * @idx: Index of the command in the shell's execution history.
 * Return: The exit status of the executed command.
 */
int exec(char **command, char **av, int idx)

{
	pid_t child;
	int status;
	char *path;

	/*Get the full path of the executable command*/
	path = handle_path(command[0]);
	if (!path)
	{
		/*Print an error message if the command is not found*/
		fprintf(stderr, "%s: %d: %s: not found\n", av[0], idx, command[0]);
		/*Free the array of command arguments*/
		free_array(command);
		/*Return an exit status indicating command not found*/
		return (127);
	}
	/* Create a child process using fork*/
	child = fork();
	if (child == 0)
	{
		/*Child process: execute the command using execve*/
		if (execve(path, command, environ) == -1)
		{
			/*Free allocated memory for path and command*/
			free(path), path = NULL;
			free_array(command);
		}
	}
	else
	{
		/*Parent process: wait for the child to complete*/
		waitpid(child, &status, 0);
		free_array(command);
		free(path), path = NULL;
	}
	/*Return the exit status of the executed command*/
	return (WEXITSTATUS(status));
}
