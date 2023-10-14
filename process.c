#include "main.h"

/**
 * create_child_process - Creates child process
 * @sh_name: shell name
 * Return: process id
 */
pid_t create_child_process(char *sh_name)
{
	pid_t pid;

	pid = fork();
	if (pid == -1)
		perror(sh_name);
	return (pid);
}
