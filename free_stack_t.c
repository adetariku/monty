#include "monty.h"

/**
 * free_stack - frees the stack on exit
 * @status: exit status
 * @arg: double pointer to the stack
 *
 * Return: void
 */
void free_stack_t(stack_t *head)
{
	stack_t *temp;
	while (head != NULL)
	{
		temp = (head)->next;
		free(head);
		head = temp;
	}
}
