#include "shell.h"
/**
 * free_array - Frees a dynamically allocated 2D array of strings.
 *
 * @command: The 2D array of strings to be freed.
 */
void free_array(char **command)
{
	int i;

	/*Check if the input array is NULL*/
	if (!command)
		return;
	/*Iterate through the rows of the array*/
	for (i = 0; command[i]; i++)
		/*Free the memory allocated for each string in the row*/
		free(command[i]), command[i] = NULL;
	/*Free the memory allocated for the array of pointers*/
	free(command), command = NULL;
}
