#define _GNU_SOURCE
#include "monty.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
	char *line = NULL;
    size_t len = 0;
    size_t read;
    int line_number = 0;
    char *opcode;
	FILE *file;
    if (argc != 2)
    {
        fprintf(stderr, "USAGE: %s file\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    file = fopen(argv[1], "r");
    if (!file)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    while ((read = (getline(&line, &len, file))) != (size_t)-1)
    {
        line_number++;
        opcode = strtok(line, " \n");
        if (!opcode || opcode[0] == '#')
            continue;
        fprintf(stderr, "Error at line %d: Unknown opcode '%s'\n", line_number, opcode);
        free(line);
        fclose(file);
        exit(EXIT_FAILURE);
    }

    free(line);
    fclose(file);
    exit(EXIT_SUCCESS);
}

