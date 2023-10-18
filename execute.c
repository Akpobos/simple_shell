#include "main.h"

/**
 * build_dir - Build full path. ls - /bin/ls
 * @command: The command array
 * @env: Environment variable
 * Return: -1 if path is not found else 1
 */
int build_dir(char *command[TOK_BUFSIZE], char **env)
{
	char *path = _getenv("PATH", env), *tmp = NULL, *dir = NULL;
	size_t path_len = _strlen(path);
	int is_found = -1;

	tmp = malloc(sizeof(*tmp) * (path_len + 1));
	if (tmp == NULL)
		return (is_found);
	_strlcpy(tmp, path, path_len);
	if (tmp != NULL)
	{
		char *token = strtok(tmp, ":");

		while (token != NULL)
		{
			size_t len = (_strlen(token) + _strlen(command[0]) + 2);
			struct stat st;

			dir = malloc(sizeof(*dir) * len);
			if (dir == NULL)
			{
				is_found = -1;
				break;
			}
			_strlcpy(dir, token, len);
			_strlcat(dir, "/", len);
			_strlcat(dir, command[0], len);
			if (stat(dir, &st) != -1)
			{
				command[0] = dir;
				is_found = 1;
				break;
			}
			_free(&dir);
			token = strtok(NULL, ":");
		}
	}
	_free(&tmp);
	tmp = NULL;
	return (is_found);
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
	if (*(command[0]) != '/' && *(command[0]) != '.')
	{
		int is_built_in = handle_built_ins(command), is_found;

		if (is_built_in != -1)
			return (-1);
		is_found = build_dir(command, env);
		if (access(command[0], X_OK) == -1)
		{
			if (is_found != -1)
				_free(command);
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
