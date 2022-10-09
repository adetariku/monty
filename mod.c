#include "monty.h"

/**
 * _mod - get the module of the second top element of the stack and top element
 * @head: double pointer to header (top) of the stack.
 * @line_number: counter for line number of the file.
 *
 * Return: void.
 */
void _mod(stack_t **head, unsigned int line_number)
{
	stack_t *temp = *head;
	int num_of_nodes = 1; /*number of elements in stack*/

	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		free_stack_t(*head);

		exit(EXIT_FAILURE);
	}

	while (temp->next != NULL)
	{
		temp = temp->next;
		num_of_nodes++;
	}

	if (num_of_nodes + 1 <= 2)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		free_stack_t(*head);

		exit(EXIT_FAILURE);
	}

	temp = *head; /*current equals to head to make module*/

	if (temp->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp->next->n = temp->next->n % temp->n; /*do the mod*/

	*head = temp->next;
	free(temp);
	temp->prev = NULL;
}
