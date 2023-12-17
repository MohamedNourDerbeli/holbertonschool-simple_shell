#include "shell.h"
/**
 * main - shell
 *
 * @ac: int
 * @av: char
 * Return: Always 0.
 */

int main(__attribute__((unused)) int ac, char **av)
{
	char *line = NULL;
	char **command = NULL;
	int status = 0, idx = 0;

	while (1)
	{

		line = read_line();
		if (line == NULL)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			return (status);
		}
		idx++;
		command = split_str(line);
		if (!command)
			continue;
		if (is_built_in(command[0])==1)
			handle_built_in(command, status, idx);
		else
			status = exec(command, av, idx);
	}

	return (0);
}
