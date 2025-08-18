#ifndef SHELL_H
#define SHELL_H

extern char **environ;

int launch_exec_child(char *argv[]);
int main(void);

#endif
