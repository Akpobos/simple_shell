#include "main.h"

/**
 * _strcspn - calculates the length of the number
 * of characters before the 1st occurrence of character
 * present in both the string.
 * @s1: The Target string in which search has to be made.
 * @s2: Argument string containing characters to match
 * in target string.
 * Return: number of characters before the 1st occurrence
 */
size_t _strcspn(const char *s1, const char *s2)
{
	size_t count = 0;

	while (*s1)
	{
		const char *r = s2;

		while (*r)
		{
			if (*s1 == *r)
				return (count);
			r++;
		}
		s1++;
		count++;
	}
	return (count);
}
