#include "main.h"

/**
 * handle_built_ins - Handle's shell built-ins
 * @command: user tokenized command
 * Return: 0 if builtin handled else -1
 */
int handle_built_ins(char *command[TOK_BUFSIZE], char *environ[])
{
	if (_strcmp(command[0], "exit") == 0)
	{
		exit(EXIT_SUCCESS);
	}
	else if (_strcmp(command[0], "env") == 0)
	{
		print_current_env(environ);
		return (1);
	}
	return (-1);
}
