#include "main.h"

/**
 * _strlen - Get length of string
 * @buffer: The string
 * Return: The length of the string
 */
unsigned int _strlen(char *buffer)
{
	unsigned int len = 0;

	while (buffer[len])
		len++;
	return (len);
}

/**
 * _strcmp - compares two strings
 * @str1: string 1
 * @str2: string 2
 * Return: if str1 < str2, 0 if str1 = str2 and + if str2 < str1
 */
int _strcmp(char *str1, char *str2)
{
	while (*str1 != '\0' && *str2 != '\0')
	{
		if ((*str1) != (*str2))
			return (*str1 - *str2);

		str1++;
		str2++;
	}
	return (*str1 - *str2);
}

/**
 * build_command - Tokenize the user input
 * @buffer: Pointer to the user input
 * @cmd_arr: Pointer to the command array
 * Return: Nothing
 */
void build_command(char **buffer, char *(*cmd_arr)[TOK_BUFSIZE])
{
	if (buffer && *buffer)
	{
		size_t count = 0;
		char *token = NULL;

		token = strtok(*buffer, TOK_DELIM);
		while (token != NULL)
		{
			(*cmd_arr)[count++] = token;
			token = strtok(NULL, TOK_DELIM);
		}
		(*cmd_arr)[count] = NULL;
	}
}
