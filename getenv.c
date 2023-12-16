#include "shell.h"
char *_get_env(char *var)
{
	char *tmp, *value, *key, *env;
	int i;
	for (i = 0; environ[i]; i++)
	{
		tmp = my_strdup(environ[i]);
		key = strtok(tmp, "=");
		if (strcmp(key, var) == 0)
		{
			value = strtok(NULL, "\n");
			env = my_strdup(value);
			free(tmp);
			return (env);
		}
		free(tmp), tmp = NULL;
	}
	return (NULL);
}
