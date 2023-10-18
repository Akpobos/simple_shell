#include "main.h"

/**
 * _free - Free and set pointer to NULL
 * @buffer: Pointer to pointer to string
 * Return: Nothing
 */
void _free(char **buffer)
{
	if (*buffer != NULL)
	{
		free(*buffer);
		*buffer = NULL;
	}
}
