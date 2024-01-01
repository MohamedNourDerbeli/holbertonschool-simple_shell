#include "shell.h"
/**
 * _get_env - Retrieves the value of an environment variable.
 *
 * @var: The name of the environment variable to retrieve.
 * Return: A dynamically allocated string containing the value of the variable.
 * Returns NULL if the variable is not found or
 * in case of memory allocation failure.
 */
char *_get_env(char *var)

{
	char *tmp, *value, *key, *env;
	int i;
	/*Iterate through the environment variables*/
	for (i = 0; environ[i]; i++)
	{
		/*Duplicate the current environment variable for parsing*/
		tmp = my_strdup(environ[i]);
		/* Extract the key (variable name) from the duplicated string*/
		key = strtok(tmp, "=");
		/*Check if the key matches the specified variable name*/
		if (key != NULL && strcmp(key, var) == 0)
		{
			/* Extract the value associated with the key*/
			value = strtok(NULL, "\n");
			/*Duplicate the value or set env to NULL if the value is NULL*/
			env = (value != NULL) ? my_strdup(value) : NULL;
			/* Free the duplicated string and return the value (or NULL)*/
			free(tmp);
			return (env);
		}
		/*Free the duplicated string*/
		free(tmp), tmp = NULL;
	}
	/*Return NULL if the variable is not found*/
	return (NULL);
}
