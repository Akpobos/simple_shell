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
 * str1 - string 1
 * str2 - string 2
 * Return: - if str1 < str2, 0 if str1 = str2 and + if str2 < str1
 */
int _strcmp(char *str1, char *str2)
{
	while(*str1 != '\0' && *str2 != '\0')
	{
		if ((*str1) != (*str2))
			return (*str1 - *str2);

		str1++;
		str2++;
	}
	return (*str1 - *str2);
}
