#include "main.h"

/**
 * _strlcpy - Copies a string to another
 * @dst: The destination string
 * @src: The source string
 * @dstsize: Size of the destination string
 * Return: The string length
 */
size_t _strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t i = 0;

	while (*src != '\0' && i < dstsize)
	{
		dst[i] = *src;
		i++;
		src++;
	}
	dst[i] = '\0';
	return (i);
}

/**
 * _strlcat - Copied a string to another
 * @dst: The destination string
 * @src: The source string
 * @dstsize: Size of the destination string
 * Return: The joined string
 */
size_t _strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t i = 0;

	while (dst[i] != '\0')
		i++;
	while (*src != '\0' && i < dstsize)
	{
		dst[i] = *src;
		i++;
		src++;
	}
	dst[i] = '\0';
	return (i);
}

/**
 * _strlen - Get length of string
 * @buffer: The string
 * Return: The length of the string
 */
size_t _strlen(char *buffer)
{
	size_t len = 0;

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
 * @command: Pointer to the command array
 * Return: Nothing
 */
void build_command(char **buffer, char *command[TOK_BUFSIZE])
{
	if (buffer && *buffer)
	{
		size_t count = 0;
		char *token = NULL;

		token = strtok(*buffer, TOK_DELIM);
		while (token != NULL)
		{
			command[count++] = token;
			token = strtok(NULL, TOK_DELIM);
		}
		command[count] = NULL;
	}
}
