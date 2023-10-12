#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_INPUT 1024

void prompt(char input[MAX_INPUT]);
void execute(char input[MAX_INPUT]);

#endif /*HEADER_H*/
