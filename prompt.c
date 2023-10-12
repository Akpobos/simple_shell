#include "header.h"

/**
 * prompt - prompts user for input
 * @input: input/command from user
 */
void prompt(char input[MAX_INPUT])
{
	printf("shell$");

	if (fgets(input, sizeof(char)*MAX_INPUT, stdin) == NULL)
		exit(1);
}
