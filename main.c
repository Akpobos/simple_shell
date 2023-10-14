#include "main.h"

/**
 * main - Simple shell entry
 * @ac: Argument count
 * @av: Argument Vector
 * @env: Env variables
 * Return: int
 */
int main(int ac, char *av[], char **env)
{
	char *buffer = NULL;
	char *command[TOK_BUFSIZE] = { NULL };
	pid_t pid;
	(void)ac;

	while (true)
	{
		prompt(&buffer, av[0]);
		if (buffer == NULL)
			continue;

		build_command(&buffer, &command);
		if (*(command[0]) != '/')
		{
			int check;

			check = handle_built_ins(command);
			if (check != -1)
				continue;
		}
		pid = create_child_process(av[0]);
		if (pid == -1)
			continue;

		if (pid == 0)
		{
			execute(command, av[0], env);
		}
		else
		{
			int status;

			wait(&status);
		}
	}
	_free(&buffer);
	exit(EXIT_SUCCESS);
}
