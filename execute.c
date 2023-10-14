#include "main.h"

/**
 * execute - Executes a command
 * @command: The user tokenized command
 * @sh_name: The shell name
 * @env: Environment variables
 * Return: Nothing
 */
void execute(char *command[TOK_BUFSIZE], char *sh_name, char **env)
{
	if (execve(command[0], command, env) == -1)
	{
		perror(sh_name);
		exit(EXIT_SUCCESS);
	}
}
