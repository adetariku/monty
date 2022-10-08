#define _POSIX_C_SOURCE  200809L
#define _GNU_SOURCE
#include "monty.h"
void get_opcode(stack_t **stack, unsigned int line_number, char *code);
char to_stack_or_queue = 's';

/**
 * main - Entry point
 * @argc: number of arguments passed as parameter
 * @argv: array of strings with the parameters
 *
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on any failure.
 */
int main(int argc, char *argv[])
{
	FILE *input_file = NULL;
	size_t length = 0;
	unsigned int line_number = 1;
	char *line = NULL;
	char *code = NULL;
	stack_t *head = NULL;

	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	input_file = fopen(argv[1], "r");
	if (input_file == NULL)
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (getline(&line, &length, input_file) != -1)
	{
		code = strtok(line, " \t\r\n\v\f");
		if (code != NULL && code[0] != '#')
			get_opcode(&head, line_number, code);
		line_number++;
	}

	free_stack_t(head);
	head = NULL;
	free(line);
	fclose(input_file);
	exit(EXIT_SUCCESS);
}

