#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <limits.h>
#include <ctype.h>

#define delims "\n \t\r"
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
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
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
char *opcode;
void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct global_stack - new aggregate stack_t and instruction_t type
 * @top: points to top of stack linked list
 * @ops: points to stack instruction readline
 *
 * Description: aggregated linked list stack structure
 * for a globaly accessible stack data type
 */
typedef struct global_stack
{
stack_t **top;
instruction_t **ops;
} gl_stack;

extern gl_stack mystack;
void stack_init(stack_t **head);
void free_stack(void);
int execute_file(char *filename, stack_t **stack);
void call_oper(stack_t **stack, char *oper, unsigned int line);

void instruct_push(stack_t **stack, unsigned int line);
void instruct_pall(stack_t **stack, unsigned int line);
void instruct_pint(stack_t **stack, unsigned int line);
void instruct_pop(stack_t **stack, unsigned int line);
void instruct_swap(stack_t **stack, unsigned int line);
void instruct_add(stack_t **stack, unsigned int line);
void instruct_nop(stack_t **stack, unsigned int line);
void instruct_sub(stack_t **stack, unsigned int line);
void instruct_div(stack_t **stack, unsigned int line);
void instruct_mul(stack_t **stack, unsigned int line);
void instruct_mod(stack_t **stack, unsigned int line);
void instruct_pchar(stack_t **stack, unsigned int line);
void instruct_pstr(stack_t **stack, unsigned int line);
void instruct_rotl(stack_t **stack, unsigned int line);
void instruct_rotr(stack_t **stack, unsigned int line);

int _strtol(char *str, unsigned int line);
int _isdigit(char *str);
#endif
