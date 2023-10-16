#include "main.h"

/**
 * handle_built_ins - Handle's shell built-ins
 * @command: user tokenized command
 * Return: 0 if builtin handled else -1
 */
int handle_built_ins(char *command[TOK_BUFSIZE])
{
	built_ins_t built_ins[] = {
		{ "exit", exit_built_in }
	};
	size_t i;

	for (i = 0; i < 1; i++)
	{
		if (_strcmp(command[0], (built_ins + i)->built_in) == 0)
		{
			return ((built_ins + i)->handler(command));
		}
	}
	return (-1);
}
