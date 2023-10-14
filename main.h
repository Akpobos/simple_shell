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
#include <sys/stat.h>

/* prompt.c */
void prompt(char **buffer, char *sh_name);
void clean_buffer(char **buffer, ssize_t len);

/* print.c */
void _print(char *buffer);

/* string.c */
unsigned int _strlen(char *buffer);
int _strcmp(char *str1, char *str2);
void build_command(char **buffer, char *(*cmd_arr)[TOK_BUFSIZE]);

/* free.c */
void _free(char **buffer);

/* execute.c */
void execute(char *command[TOK_BUFSIZE], char *sh_name, char **env);

/* process.c */
pid_t create_child_process(char *sh_name);

/* built-ins.c */
int handle_built_ins(char *command[TOK_BUFSIZE]);

#endif
