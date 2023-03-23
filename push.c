#include "monty.h"
#include <stdlib.h>

/**
 * push - Adds a new node at the beginning
 *
 * @head: Head
 *
 * @n: Value
 *
 * Return: stack_s
 */

stack_t *push(stack_t **head, const int n)
{

	stack_t *temp, *node = malloc(sizeof(stack_t));
	

	if (node == NULL)
	{
		fprintf(stderr, "Error: malloc failed");
		exit(EXIT_FAILURE);
	}

	node->n = n;
	node->prev = NULL;
	node->next = NULL;

	if (*head == NULL)
	{
		node->next = NULL;
		*head = node;
		return (*head);
	}
	temp = *head;
	node->next = temp;
	temp->prev = node;
	*head = node;
	return (node);
}
