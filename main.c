#include "header.h"

/**
 * main - entry point
 * Return: 0 on success
 */
int main(void)
{
	char input[MAX_INPUT] = {0};

	while(1)
	{
		prompt(input);
		execute(input);
	}

	return (0);
}
