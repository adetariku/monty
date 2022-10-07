#include "monty.h"
/**
 * pall - displays all values in a `stack'
 * @head: double pointer to head of stack
 * @line_number: line number
 *
 * Return: void
 */
void _pall(stack_t **head, unsigned int line_number)
{
	stack_t *temp;

	(void)(line_number);
	temp = *head;
	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
