#include "shell.h"
/**
 * read_line - Reads a line of input from the user.
 *
 * Return: A pointer to the buffer containing the input line.
 *         Returns NULL on failure or when encountering EOF.
 */

char *read_line(void)
{
	ssize_t n;
	size_t len = 0;
	char *buf = NULL;
	/*Print a shell prompt if the input is from a terminal*/
	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "$ ", 2);
	/* Use getline to read a line of input*/
	n = getline(&buf, &len, stdin);
	/*Check for errors or encountering EOF*/
	if (n == -1)
	{
		/*Free allocated memory and set buffer to NULL*/
		free(buf), buf = NULL;
		return (NULL);
	}
	/*Return the buffer containing the input line*/
	return (buf);
}
