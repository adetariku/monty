#define _POSIX_C_SOURCE  200809L
#define _GNU_SOURCE
#include <ctype.h>
#include "monty.h"
/**
 * is_string_only_digits - checks if string is made of digits only
 * @args: a pointer to character array
 *
 * Return: 1 if only digits,  0 otherwise
 */
static int is_string_only_digits(char *args)
{
	unsigned int index;
	unsigned int len = strlen(args);

	for (index = 0; index < len; index++)
	{
		if (args[index] == '-' && index == 0)
			continue;
		if (isdigit(args[index]) == 0)
			return (0);
	}
	return (1);
}
/**
 * push - pushes an integer to a stack
 * @head: double pointer to the beginning of the stack
 * @line_number: script line-number
 *
 * Return: void(Nothing)
 */

void push(stack_t **head, unsigned int line_number)
{
	int n;
	char *args;

	args = strtok(NULL, " \n\t\r\v\f");

	if (args == NULL || is_string_only_digits(args))
	{
		dprintf(STDOUT_FILENO,
			"L%u: usage: push integer\n",
			line_number);
		exit(EXIT_FAILURE);
	}
	n = atoi(args);

	if (to_stack_or_queue == 's')
		add_node(head, n);

	if (to_stack_or_queue == 'q')
		add_node_rear(head, n);
}
