#include "header.h"

/**
 * _strlen - finds length of string
 * @str: Sting
 * Return: length of string
 */
unsigned int _strlen(char *str)
{
	unsigned int len = 0;
	int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		len++;
	}

	return (len);
}
