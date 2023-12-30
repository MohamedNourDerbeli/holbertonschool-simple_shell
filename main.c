#include "shell.h"
/**
 * main - Entry point for the custom shell program.
 *
 * @ac: Number of arguments (unused in this context).
 * @av: Array of command-line arguments.
 * Return: Always 0.
 */

int main(__attribute__((unused)) int ac, char **av)
{
	char *line = NULL;
	char **command = NULL;
	int status = 0, idx = 0;
	/*Infinite loop for continuous shell operation*/
	while (1)
	{
		/*Read a line of input from the user*/
		line = read_line();
		/*If no input is provided (e.g., user presses Ctrl+D), exit the shell*/
		if (line == NULL)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			return (status);
		}
		/*Increment command index*/
		idx++;

		/*Split the input line into individual commands*/
		command = split_str(line);

		/*If splitting fails, skip to the next iteration*/
		if (!command)
			continue;

		/*Check if the command is a built-in shell command*/
		if (is_built_in(command) == 1)
			handle_built_in(command, &status);
		else
			/*Execute the external command and update the shell status*/
			status = exec(command, av, idx);
	}
	/*The program should never reach this point due to the infinite loop*/
	return (0);
}
