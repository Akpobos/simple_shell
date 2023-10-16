#include "main.h"

/**
 * print_current_env - prints current environment
 * @environ: pointer to string array
 */
void print_current_env(char *environ[])
{
	int count = 0;

	while (environ[count] != NULL)
	{
		printf("%s\n", environ[count]);
		count++;
	}
}
