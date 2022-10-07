#define _POSIX_C_SOURCE  200809L
#define _GNU_SOURCE  
#include "monty.h"
/**
 * pint -displays the value at the top of the stack
 * @stack: double pointer to header of the stack.
 * @line_number: counter for line number
 *
 * Return: void.
 */
void _pint(stack_t **head, unsigned int line_number)
{
	stack_t *temp = *head;

	if (*head == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: can't pint, stack empty\n", line_number);
		free_stack_t(*head);

		exit(EXIT_FAILURE);
	}

	printf("%d\n", temp->n);
}
