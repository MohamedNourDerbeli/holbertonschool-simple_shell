#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
extern char **environ;
char *read_line(void);
char *my_strdup(const char *s);
char **split_str(char *line);
void free_array(char **command);
int exec(char **arr, char **av);
#endif
