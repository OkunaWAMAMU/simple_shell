#ifndef _MAIN_H
#define _MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#define MAX_LENGTH 1024
int _pid();
ssize_t custom_getline(char **lineptr, size_t *n, FILE *stream);
int _readline(void);
void prompt(void);
int count_arguments(const char *input);
char **split_arguments(const char *input);
char *find_path(const char *command);
#endif
