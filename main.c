#include "monty.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * main - entry
 * @argc: no. of commandline args
 * @argv: pointer to commandline args
 * Description: checker
 *
 * Return: always 0
 */

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	FILE *file = fopen(argv[1], "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	
    while ((read = getline(&line, &len, file)) != -1)
    {
        line_number++;
        opcode = strtok(line, " \n");
        if (!opcode || opcode[0] == '#')
            continue;
        get_instructions();
        fprintf(stderr, ERROR_UNKNOWN, line_number, opcode);
        free(line);
        fclose(file);
        exit(EXIT_FAILURE);
    }

    free(line);
    fclose(file);
    exit(EXIT_SUCCESS);
}
