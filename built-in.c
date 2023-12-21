#include "shell.h"
/**
 * is_built_in - check the code
 * @command: char
 * Return: Always 0.
 */
int is_built_in(char **command)

{
	char *built[] = {"exit", "env", "cd", "help", NULL};
	int i;

	for (i = 0; built[i]; i++)
	{
		if (strcmp(command[0], built[i]) == 0)
		{
			return (1);
		}
	}
	return (0);

}
/**
 * handle_built_in - check the code
 * @command: char
 * @status: int
 * @idx: int
 * @av: char
 */
void handle_built_in(char **command, int *status, int idx, char **av)

{
	if (strcmp(command[0], "exit") == 0)
	{
		hsh_exit(command, status);
	}
	else if (strcmp(command[0], "env") == 0)
	{
		hsh_env(command, status);
	}
}
/**
 * hsh_exit - check the code
 * @cmd: char
 * @status: int
 * Return: Always 0.
 */
void hsh_exit(char **cmd, int *status)

{
	free_array(cmd);
	exit(*status);
}
/**
 * hsh_env - check the code
 * @cmd: char
 * @status: int
 * Return: Always 0.
 */
void hsh_env(char **cmd, int *status)

{
	int i;

	for (i = 0; environ[i]; i++)
	{
		printf("%s\n", environ[i]);
	}
	free_array(cmd);
	(*status) = 0;
}
