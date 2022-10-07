#include "monty.h"

/**
 * pop - removes the top element from a stack.
 * @header: double pointer to header of the stack.
 * @line_number: counter for line number
 *
 * Return: void.
 */
void _pop(stack_t **head, unsigned int line_number)
{
	stack_t *temp;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		free_stack_t(*head);

		exit(EXIT_FAILURE);
	}

	temp = *head;
	if ((*head)->next)
		(*head)->next->prev = NULL;
	*head = (*head)->next;
	free(temp);
}
