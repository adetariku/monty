#include "monty.h"

/**
 * add - adds the top two elements of a stack.
 * @head: pointer to header of the stack.
 * @line_number: counter for line number
 *
 * Return: void.
 */
void _add(stack_t **head, unsigned int line_number)
{
	stack_t *temp;

	if (!head || !*head || !((*head)->next))
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		free_stack_t(*head);

		exit(EXIT_FAILURE);
	}

	temp = *head;
	*head = (*head)->next;
	(*head)->n += temp->n;
	(*head)->prev = NULL;
	free(temp);
}
