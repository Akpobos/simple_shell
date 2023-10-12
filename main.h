#ifndef MAIN_H
#define MAIN_H

#define TOK_BUFSIZE 256
#define TOK_DELIM " "

#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

/* prompt.c */
void prompt(char **buffer, char *sh_name);
void clean_buffer(char **buffer, ssize_t len);

/* print.c */
void _print(char *buffer);

/* string.c */
unsigned int _strlen(char *buffer);

/* free.c */
void _free(char **buffer);

/* execute.c */
void execute(char **buffer, char *sh_name);

/* process.c */
pid_t create_child_process(char *sh_name);

#endif
