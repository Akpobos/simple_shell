#include "main.h"

/**
 * build_dir - Build full path. ls - /bin/ls
 * @command: The command array
 * @env: Environment variable
 * Return: Nothing
 */
void build_dir(char *command[TOK_BUFSIZE], char **env)
{
	char *path = _getenv("PATH", env), *tmp = NULL, *dir = NULL;
	size_t path_len = _strlen(path);

	tmp = malloc(sizeof(*tmp) * path_len);
	if (tmp == NULL)
		return;
	_strlcpy(tmp, path, path_len);
	if (tmp != NULL)
	{
		char *token = strtok(tmp, ":");

		while (token != NULL)
		{
			size_t len = (_strlen(token) + _strlen(command[0]) + 1);
			struct stat st;

			dir = malloc(sizeof(*dir) * len);
			if (dir == NULL)
				break;
			_strlcat(dir, token, len);
			_strlcat(dir, "/", len);
			_strlcat(dir, command[0], len);
			if (stat(dir, &st) != -1)
			{
				command[0] = dir;
				break;
			}
			_free(&dir);
			token = strtok(NULL, ":");
		}
	}
	_free(&tmp);
	tmp = NULL;
}

/**
 * should_exec_command - Check if to call execve
 * @command: The command array
 * @env: Environment variables
 * @sh_name: Shell name
 * Return: -1 if execve should not be called
 */
int should_exec_command(char *command[TOK_BUFSIZE], char **env, char *sh_name)
{
	if (*(command[0]) != '/')
	{
		int is_built_in = handle_built_ins(command);

		if (is_built_in != -1)
			return (-1);
		build_dir(command, env);
		if (access(command[0], X_OK) == -1)
		{
			_free(&command[0]);
			perror(sh_name);
			return (-1);
		}

		return (2);
	}
	else if (access(command[0], X_OK) == -1)
	{
		perror(sh_name);
		return (-1);
	}
	return (1);
}

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
