#include "main.h"

/**
 * clean_buffer - Replace newline with terminator
 * @buffer: The buffer
 * @len: buffer length
 * Return: Nothing
 */
void clean_buffer(char **buffer, ssize_t len)
{
	if (*buffer && (*buffer)[len - 1] == '\n')
	{
		if (len == 1)
			_free(buffer);
		else
			(*buffer)[len - 1] = '\0';
	}
}

/**
 * prompt - Prompts a user for command
 * @buffer: Address to user input buffer
 * @sh_name: Shell name
 * Return: Nothing
 */
void prompt(char **buffer, char *sh_name)
{
	size_t n = 0;
	ssize_t read;

	char *sd = "#cisfun$ ";

	if (*buffer != NULL)
		_free(buffer);
	_print(sd);
	read = getline(buffer, &n, stdin);
	if (read == -1)
	{
		if (feof(stdin))
		{
			exit(EXIT_SUCCESS);
		}
		else
			perror(sh_name);
		_free(buffer);
	}
	else
	{
		if (feof(stdin))
		{
			_print("\n");
		}
		clean_buffer(buffer, read);
	}
}
