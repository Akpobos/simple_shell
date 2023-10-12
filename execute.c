#include "main.h"

/**
 * execute - Executes a command
 * @buffer: The user input
 * @sh_name: The shell name
 * Return: Nothing
 */
void execute(char **buffer, char *sh_name)
{
	if (buffer && *buffer)
	{
		char *cmd_arr[TOK_BUFSIZE];
		size_t count = 0;
		char *token = NULL;

		token = strtok(*buffer, TOK_DELIM);
		while (token != NULL)
		{
			cmd_arr[count++] = token;
			token = strtok(NULL, TOK_DELIM);
		}
		cmd_arr[count] = NULL;
		if (execve(cmd_arr[0], cmd_arr, NULL) == -1)
		{
			perror(sh_name);
		}
	}
}
