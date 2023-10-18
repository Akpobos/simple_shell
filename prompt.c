#include "main.h"

/**
 * check_emptiness - Check if the input is empty
 * @buffer: The buffer
 * Return: Nothing
 */
void check_emptiness(char **buffer)
{
	size_t i, is_empty = 1;

	for (i = 0; (*buffer)[i] != '\0'; i++)
	{
		if ((*buffer)[i] != ' ' && (*buffer)[i] != '\n')
		{
			is_empty = 0;
			break;
		}
	}

	if (is_empty)
		_free(buffer);
}

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
	int ia = isatty(STDIN_FILENO);

	if (*buffer != NULL)
		_free(buffer);
	if (ia)
		_print(sd);
	read = getline(buffer, &n, stdin);
	if (read == -1)
	{
		if (feof(stdin))
		{
			if (ia)
				_print("\n");
			_free(buffer);
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
		check_emptiness(buffer);
		clean_buffer(buffer, read);
	}
}
