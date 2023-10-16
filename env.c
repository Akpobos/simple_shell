#include "main.h"

/**
 * _getenv - Get an environment variable
 * @name: The name of the env var
 * @env: Environment variable array
 * Return: Pointer to env var
 */
char *_getenv(char *name, char **env)
{
	size_t i;

	for (i = 0; env[i] != NULL; i++)
	{
		char *path = NULL;
		size_t len = _strlen(name);

		path = malloc(sizeof(path) * len);
		if (path == NULL)
			return (NULL);
		_strlcpy(path, env[i], _strlen(name));
		if (_strcmp(strtok(path, "="), name) == 0)
		{
			_free(&path);
			return (env[i] + _strlen(name) + 1);
		}
		_free(&path);
	}
	return (NULL);
}
