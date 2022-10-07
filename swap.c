#include "monty.h"

/**
 * swap -  swaps the top two elements of a stack.
 * @head: pointer to header of the stack.
 * @line_number: counter for line number of the file.
 *
 * Return: void.
 */
void _swap(stack_t **head, unsigned int line_number)
{
	stack_t *temp;

	if (!head || !*head || !((*head)->next))
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		free_stack_t(*head);

		exit(EXIT_FAILURE);
	}

	temp = *head;
	*head = (*head)->next;
	(*head)->prev = NULL;
	if ((*head)->next)
		((*head)->next)->prev = temp;
	temp->next = (*head)->next;
	(*head)->next = temp;
	temp->prev = *head;
}
