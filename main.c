#include <stdio.h>
#include <stdlib.h>
#include "monty.h"
#include "string.h"
/**
 * main - entry point to the program
 * @argc: argument count
 * @argv: argument list
 * Return: always 0
 */
int main(int argc, char *argv[])
{
	char line[50], *opcodes[2], *token;
	FILE *file;
	stack_t *head = NULL;
	int i, line_number = 1;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s", argv[1]);
	}
	while (fgets(line, 50, file) != NULL)
	{
		i = 0;
		token = strtok(line, " ");
		while (token != NULL)
		{
			opcodes[i] = token;
			i++;
			token = strtok(NULL, " ");
		}
		if (strcmp(opcodes[0], "push") == 0)
		{
			if (opcodes[1] == 0 || opcodes[1] == NULL)
			{
				fprintf(stderr, "L%d: usage: push integer\n", line_number);
				exit(EXIT_FAILURE);
			}
			push(&head, atoi(opcodes[1]));
		}
		line_number++;
	}
	pall(&head, line_number);
	fclose(file);
	return (0);
}
