#include "shell.h"
/**
 * split_str - Tokenizes a string into an array of strings.
 *
 * @line: The string to be tokenized.
 * Return: An array of strings (tokens).
 *         Returns NULL on failure or when @line is NULL.
 */

char **split_str(char *line)
{
	char *token, *delim = " \t\n", *tmp = NULL, **command = NULL;
	int count = 0, i = 0;
	/* Check if the input string is NULL*/
	if (!line)
		return (NULL);
	/*Duplicate the input string to avoid modifying the original*/
	tmp = my_strdup(line);
	/*Tokenize the duplicated string to count the number of tokens*/
	token = strtok(tmp, delim);
	if (token == NULL)
	{
		/*Free allocated memory and set pointers to NULL*/
		free(line), line = NULL;
		free(tmp), tmp = NULL;
		return (NULL);
	}

	while (token)
	{
		count++;
		token = strtok(NULL, delim);
	}
	/*Free the duplicated string*/
	free(tmp), tmp = NULL;
	/*Allocate memory for the array of strings (tokens)*/
	command = malloc(sizeof(char *) * (count + 1));
	if (!command)
	{
		/*Free original line and return NULL in case of memory allocation failure*/
		free(line), line = NULL;
		return (NULL);
	}
	/*Tokenize the original string and copy tokens to the array*/
	token = strtok(line, delim);
	while (token)
	{
		command[i] = my_strdup(token);
		token = strtok(NULL, delim);
		i++;
	}
	/*Free the original line and set the last element of the array to NULL*/
	free(line), line = NULL;
	command[i] = NULL;
	/* Return the array of strings (tokens)*/
	return (command);
}
