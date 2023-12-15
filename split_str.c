#include "shell.h"
/**
 * split_str - shell
 *
 * @line: char
 * Return: Always 0.
 */

char **split_str(char *line)
{
	char *token, *delim = " \t\n", *tmp = NULL, **command = NULL;
	int count = 0, i = 0;

	if (!line)
		return (NULL);
	tmp = my_strdup(line);
	token = strtok(tmp, delim);
	if (token == NULL)
	{
		free(line), line = NULL;
		free(tmp), tmp = NULL;
		return (NULL);
	}

	while (token)
	{
		count++;
		token = strtok(NULL, delim);
	}
	free(tmp), tmp = NULL;
	command = malloc(sizeof(char *) * (count + 1));
	if (!command)
	{
		free(line), line = NULL;
		return (NULL);
	}

	token = strtok(line, delim);
	while (token)
	{
		command[i] = my_strdup(token);
		token = strtok(NULL, delim);
		i++;
	}
	free(line), line = NULL;
	command[i] = NULL;
	return (command);
}
