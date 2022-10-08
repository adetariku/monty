#define _POSIX_C_SOURCE  200809L
#define _GNU_SOURCE
#include "monty.h"
/**
 * add_node - add a new node to a double linked list
 * @head: double pointer to the beginning of a linked list
 * @n: value to to added
 *
 * Description: adding a new node to the head of a linked list
 *
 * Return: 1 on success, exit otherwise
 */
void add_node(stack_t **head, const int data)
{
	stack_t *newnode = NULL;

	newnode = malloc(sizeof(stack_t));
	if (newnode == NULL)
	{
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		free_stack_t(*head);

		exit(EXIT_FAILURE);
	}
	newnode->n = data;
	newnode->next = NULL;
	newnode->prev = NULL;
	if (*head == NULL)
		*head = newnode;
	else
	{
		newnode->next = *head;
		(*head)->prev = newnode;
		*head = newnode;
	}
}

/**
 * add_node_rear -  pushes a node to the rear end.
 * @stack: double pointer to header of the stack.
 * @argument: integer push.
 *
 * Return: void.
 */
void  add_node_rear(stack_t **stack, int data)
{
	stack_t *newnode = NULL, *temp = NULL;

	newnode = malloc(sizeof(stack_t));
	if (newnode == NULL)
	{
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		free_stack_t(*stack);

		exit(EXIT_FAILURE);
	}

	newnode->n = data;
	newnode->next = NULL;
	newnode->prev = NULL;

	if (*stack == NULL)
		*stack = newnode;
	else
	{
		temp = *stack;
		while (temp->next != NULL)
			temp = temp->next;
		newnode->prev = temp;
		temp->next = newnode;
	}
}
