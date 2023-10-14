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
