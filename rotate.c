#include "monty.h"

/**
  * rotr - Rotates the stack to the bottom
  * @head: The head of the stack
  * @line_number: The line on which the error occurred
  *
  * Return: Nothing
  */
void rotr(stack_t **head, unsigned int line_number)
{
	stack_t *end = NULL;
	(void) line_number;

	if (*head && (*head)->next)
	{
		end = *head;

		while (end->next != NULL)
			end = end->next;

		end->prev->next = NULL;
		end->next = *head;
		*head = end;
	}
}

/**
  * rotl - Rotates the stack to the top
  * @stack: The head of the stack
  * @line_number: The line on which the error occurred
  *
  * Return: Nothing
  */
void rotl(stack_t **head, unsigned int line_number)
{
	stack_t *temp = *head;
	unsigned int value = 0;
	(void) line_number;

	if (temp && temp->next)
	{
		while (temp->next != NULL)
		{
			value = temp->n;
			temp->n = temp->next->n;
			temp->next->n = value;
			temp = temp->next;
		}
	}
}
