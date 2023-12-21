#include "shell.h"
/**
 * _get_env - read the code
 * @var: char
 * Return: Always 0.
 */
char *_get_env(char *var)

{
	char *tmp, *value, *key, *env;
	int i;

	for (i = 0; environ[i]; i++)
	{
		tmp = my_strdup(environ[i]);
		key = strtok(tmp, "=");
		if (key != NULL && strcmp(key, var) == 0)
		{
			value = strtok(NULL, "\n");
			env = (value != NULL) ? my_strdup(value) : NULL;
			free(tmp);
			return (env);
		}
		free(tmp), tmp = NULL;
	}
	return (NULL);
}
