#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

int pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current;
	
	(void)line_number;

	current = *stack;
	if (*stack == NULL)
		return (-1);

	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}

	return (0);
}

