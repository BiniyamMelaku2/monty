#include "monty.h"

/**
 * instruct_push - pushes a data/number to stack
 * @stack: pointer to the top node of stack
 * @line: the current file line number calling instruction
 */
void instruct_push(stack_t **stack, unsigned int line)
{
stack_t *node = malloc(sizeof(stack_t));
char *operd;
int num;
if (node == NULL)
{
printf("Error: malloc failed\n");
exit(EXIT_FAILURE);
}
operd = strtok(NULL, delims);
if (operd == NULL || stack == NULL)
{
printf("L%u: usage: push integer\n", line);
exit(EXIT_FAILURE);
}
num = _strtol(operd, line);  /* num must only be type int */
node->n = num;
node->prev = NULL;
node->next = *stack;
if (node->next != NULL)
node->next->prev = node;
*stack = node;  /* stack shall be on top of linked list nodes */
}

/**
 * instruct_pall - prints all of the data/number in the stack
 * @stack: pointer to the top node of stack
 * @line: the current file line number calling instruction
 */
void instruct_pall(stack_t **stack, unsigned int line)
{
stack_t *node = *stack;
(void) line;
while (node != NULL)
{
printf("%d\n", node->n);
node = node->next;
}
}

/**
 * instruct_pint - prints the value at the top of the stack
 * @stack: pointer to the top node of stack
 * @line: the current file line number calling instruction
 */
void instruct_pint(stack_t **stack, unsigned int line)
{
if (stack == NULL || *stack == NULL)
{
printf("L%u: can't pint , stack empty\n", line);
exit(EXIT_FAILURE);
}
printf("%d\n", (*stack)->n);
}

/**
 * instruct_pop - removes the top element of the stack
 * @stack: pointer to the top node of stack
 * @line: the current file line number calling instruction
 */
void instruct_pop(stack_t **stack, unsigned int line)
{
stack_t *node;
if (stack == NULL || *stack == NULL)
{
printf("L%u: can't pop an empty stack\n", line);
exit(EXIT_FAILURE);
}
node = *stack;
*stack = (*stack)->next;
free(node);
}

/**
 * instruct_swap - swaps the top two elements of the stack
 * @stack: pointer to the top node of stack
 * @line: the current file line number calling instruction
 */
void instruct_swap(stack_t **stack, unsigned int line __attribute__ ((unused)))
{
stack_t *tmp;

if (!(*stack) || !((*stack)->next))
{
printf("L%u: can't swap, stack too short\n", line);
exit(EXIT_FAILURE);
}
tmp = (*stack)->next;
(*stack)->prev = (*stack)->next;
(*stack)->next = tmp->next;
tmp->prev = NULL;
(*stack)->prev = tmp;
if (tmp->next)
tmp->next->prev = *stack;
tmp->next = *stack;
*stack = (*stack)->prev;
}
