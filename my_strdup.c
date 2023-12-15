#include "shell.h"
/**
 * my_strdup - string duplicate
 * @s: const char
 * Return: Always 0.
 */
char *my_strdup(const char *s)
{
	if (s == NULL)
	{
		return (NULL);
	}

	size_t len = strlen(s) + 1;
	char *dup_str = (char *)malloc(len);

	if (dup_str == NULL)
	{
		return (NULL);
	}

	strcpy(dup_str, s);
	return (dup_str);
}
