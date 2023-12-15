#include "shell.h"
/**
 * read_line - read line
 * Return: Always 0.
 */

char *read_line(void)
{
	ssize_t n;
	size_t len = 0;
	char *buf = NULL;

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "$ ", 2);

	n = getline(&buf, &len, stdin);
	if (n == -1)
	{
		free(buf), buf = NULL;
		return (NULL);
	}
	return (buf);
}
