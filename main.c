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
	int status = 0;

	while (1)
	{
		line = read_line();
		if (line == NULL)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			return (status);
		}
		command = split_str(line);
		if (!command)
			continue;
		status = exec(command, av);
	}

	return (0);
}

