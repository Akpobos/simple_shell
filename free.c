#include "main.h"

/**
 * _free - Free and set pointer to NULL
 * @buffer: Pointer to pointer to string
 * Return: Nothing
 */
void _free(char **buffer)
{
	free(*buffer);
	*buffer = NULL;
}
