#define _POSIX_C_SOURCE  200809L
#define _GNU_SOURCE
#include "monty.h"
/**
 * get_opcode - reads opcode and checks if valid.
 * @head: double pointer to header a stack.
 * @line_number: counter for line number of the file.
 * @code: opcode to excecute.
 *
 * Return: void.
 */
void get_opcode(stack_t **stack, unsigned int line_number, char *code)
{
	int i = 0;
	instruction_t opcode_func[] = {
		{"add", _add},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"push", push},
		{"swap", _swap},
		{"nop", _nop},
		{"mul", _mul},
		{"div", _div},
		{"sub", _sub},
		{"mod", _mod},
		{"stack", _stack},
		{"queue", _queue},
		{"pchar", _pchar},
		{"pstr", _pstr},
		{"rotl", rotl},
		{"rotr", rotr},
		{NULL, NULL}
	};

	while (opcode_func[i].opcode)
	{
		if (strcmp(opcode_func[i].opcode, code) == 0)
		{
			opcode_func[i].f(stack, line_number);
			return;
		}
		i++;
	}
	dprintf(STDERR_FILENO, "L%u: unknown instruction %s\n", line_number, code);
	free_stack_t(*stack);
	/**
	 * close_file
	 */
	exit(EXIT_FAILURE);
}

