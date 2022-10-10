#ifndef MONTY_H
#define MONTY_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>


/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;


/**
 * struct param_s - holds all variables to be passed
 * @STACK_OR_QUEUE: flag to determine stack(0) or queue(1)
 * @fname: path to a filename
 * @fp: file pointer to a file
 * @tokened: tokenized string of our input from file
 * @head: head of our stack
 * @line_number: line number that was just read from file
 * @buf: buffer for the line in the file
 *
 * Description: A struct that we make global to pass variables
 *  for stack, queues, LIFO, FIFO holberton project
 */
typedef struct param_s
{
	int STACK_OR_QUEUE;
	char *fname;
	FILE *fp;
	char **tokened;
	char *buf;
	struct stack_s *head;
	unsigned int line_number;
} vars_t;

/** extern vars_t *element; 
*/




/* global struct to hold flag for queue and stack length */
extern char to_stack_or_queue;

stack_t *create_node(stack_t **node, int n);
stack_t *create_first_node(stack_t **node, int n);
void push(stack_t **head, unsigned int number);
void _pall(stack_t **head, unsigned int number);
void free_stack_t(stack_t *head);
void add_node(stack_t **head, const int data);
void add_node_rear(stack_t **head, const int data);
void _add(stack_t **head, unsigned int line_number);
void _sub(stack_t **head, unsigned int line_number);
void _mul(stack_t **head, unsigned int line_number);
void _div(stack_t **head, unsigned int line_number);
void _mod(stack_t **head, unsigned int line_number);
void _nop(stack_t **head, unsigned int line_number);
void _swap(stack_t **head, unsigned int line_number);
void _pop(stack_t **head, unsigned int line_number);
void _pint(stack_t **head, unsigned int line_number);
void _pchar(stack_t **head, unsigned int line_number);
void _pstr(stack_t **head, unsigned int line_number);
void _stack(stack_t **head, unsigned int line_number);
void _queue(stack_t **head, unsigned int line_number);
void rotl(stack_t **stack, unsigned int line_number);
void rotr(stack_t **stack, unsigned int line_number);
#endif 
