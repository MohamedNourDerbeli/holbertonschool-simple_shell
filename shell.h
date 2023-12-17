#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
extern char **environ;
char *read_line(void);
int is_built_in(char **command);
void handle_built_in(char **command, int *status, int idx);
char *handle_path(char *command);
char *_get_env(char *var);
char *my_strdup(const char *s);
char **split_str(char *line);
void free_array(char **command);
int exec(char **arr, char **av, int idx);
#endif
