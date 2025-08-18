#ifndef SHELL_H
#define SHELL_H

extern char **environ;

char *_which(const char *command);
char *_getenv(const char *name);
int launch_exec_child(char *argv[]);
int main(void);

#endif
