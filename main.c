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
	pid_t pid;
	(void)ac;

	while (true)
	{
		char *command[TOK_BUFSIZE] = { NULL };
		int exec_cmd;

		prompt(&buffer, av[0]);
		if (buffer == NULL)
			continue;

		build_command(&buffer, command);
		exec_cmd = should_exec_command(command, env, av[0]);
		if (exec_cmd == -1)
			continue;

		pid = create_child_process(av[0]);
		if (pid == -1)
			continue;

		if (pid == 0)
			execute(command, av[0], env);
		else
		{
			wait(NULL);
			if (exec_cmd == 2)
				_free(&command[0]);
		}
	}
	_free(&buffer);
	exit(EXIT_SUCCESS);
}
