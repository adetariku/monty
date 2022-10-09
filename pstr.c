#include "monty.h"
/**
  * _pstr - prints the string starting from the top of the stack,
  * followed by a new line
  * @head: the double pointer to the start of the list (NULL)
  * @line_number: the line of the file it's on
  * Return: nothing, void
  */
void _pstr(stack_t **head, unsigned int line_number)
{
	stack_t *temp;

	(void) line_number;
	temp = *head;
	while (temp != NULL)
	{
		if (temp->n < 1 || temp->n > 127)
			break;
		putchar(temp->n);
		temp = temp->next;
	}
	putchar('\n');
}
