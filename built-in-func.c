#include "main.h"

/**
 * exit_built_in - Handles the exit command
 * @command: Command array
 * Return: Exit if success
 */
int exit_built_in(char *command[TOK_BUFSIZE])
{
	_free(command);
	exit(EXIT_SUCCESS);
}
