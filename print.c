#include "main.h"

/**
 * _print - Prints the string to the stdout
 * @buffer: The string
 * Return: nothing
 */
void _print(char *buffer)
{
	unsigned int len;

	if (buffer == NULL)
		return;
	len = _strlen(buffer);
	write(STDOUT_FILENO, buffer, len);
}
