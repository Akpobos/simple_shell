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

/**
 * struct built_ins_s - holds built_in and their calling function
 * @built_in: The built in name
 * @handler: The function to handle the built in
 */
struct built_ins_s
{
	char *built_in;
	int (*handler)(char *command[TOK_BUFSIZE]);
};

/* typedef */
typedef struct built_ins_s built_ins_t;

/* built-in-func.c */
int exit_built_in(char *command[TOK_BUFSIZE]);

/* prompt.c */
void prompt(char **buffer, char *sh_name);
void clean_buffer(char **buffer, ssize_t len);

/* print.c */
void _print(char *buffer);

/* string.c */
size_t _strlen(char *buffer);
int _strcmp(char *str1, char *str2);
size_t _strlcat(char *dst, const char *src, size_t dstsize);
size_t _strlcpy(char *dst, const char *src, size_t dstsize);
void build_command(char **buffer, char *command[TOK_BUFSIZE]);


/* free.c */
void _free(char **buffer);

/* execute.c */
void execute(char *command[TOK_BUFSIZE], char *sh_name, char **env);
int should_exec_command(char *command[TOK_BUFSIZE], char **env, char *sh_name);
void build_dir(char *command[TOK_BUFSIZE], char **env);

/* process.c */
pid_t create_child_process(char *sh_name);

/* built-ins.c */
int handle_built_ins(char *command[TOK_BUFSIZE]);

/* env.c */
char *_getenv(char *name, char **env);

#endif
