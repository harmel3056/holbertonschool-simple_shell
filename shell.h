#ifndef SHELL_H
#define SHELL_H

#define MAX_ARGS 64

extern char **environ;

char *_which(char *command);
char *_getenv(const char *name);
int built_ins(char *argv[], char **environ, int *status);
int launch_exec_child(char *argv[]);
void printenv(char **environ);

#endif
