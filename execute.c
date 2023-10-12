#include "header.h"

/**
 * execute - executes commands
 * @input: Inpute from the user
 * @pointerStr: pointer to array of strings
 */
void execute(char input[MAX_INPUT])
{
	int len = strlen(input);
	int pid;

	if (len > 0)
		if (input[len - 1] == '\n')
			input[len - 1] = '\0';

	pid = fork();

	if (pid == -1)
	{
		perror("Error when forking");
		exit(1);
	}
	else if (pid == 0)
	{
		char *pointerStr[2];

		pointerStr[0] = input;
		pointerStr[1] = NULL;

		if (execve(input, pointerStr, NULL) == -1)
		{
			perror("");
			exit(2);
		}
	}

	else
	{
		wait(NULL);
		/*Parent code*/
	}
}
