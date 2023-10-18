#include "main.h"

/**
 * _atoi - converts string to integer
 * @str: string
 * Return: integer
 */
int _atoi(const char *str)
{
	int num = 0;
	int sign = 1;

	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		else
			sign = 1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		num = num * 10 + (*str - '0');
		str++;
	}

	return (num * sign);
}
