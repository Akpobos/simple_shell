#include "main.h"

/**
 * exit_built_in - Handles the exit command
 * @command: Command array
 * Return: Exit if success
 */
int exit_built_in(char *command[TOK_BUFSIZE])
{
	if (command[1] != NULL)
	{
		int stat = _atoi(command[1]);
		exit(stat);
	}
	else
		exit(EXIT_SUCCESS);
}
