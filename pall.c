#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

/*
 * pall - function that prints elements of the stack
 * @stack: pointer to the stack
 * @line_number - current line number of execution
 * Return: 0 if sucess
 */

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

