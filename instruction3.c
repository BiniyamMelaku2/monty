#include "monty.h"

/**
 * instruct_mod - rest of the division of the second top by the top
 * @stack: pointer to the top node of stack
 * @line: the current file line number calling instruction
 */
void instruct_mod(stack_t **stack, unsigned int line)
{
int tmp;
if (*stack == NULL || (*stack)->next == NULL)
{
printf("L%u: can't mod, stack too short\n", line);
exit(EXIT_FAILURE);
}

tmp = (*stack)->n;
if (tmp == 0)
{
printf("L%u: division by zero\n", line);
exit(EXIT_FAILURE);
}
instruct_pop(stack, line);
(*stack)->n %= tmp;
}

/**
 * instruct_pchar - prints the char at the top of the stack
 * @stack: pointer to the top node of stack
 * @line: the current file line number calling instruction
 */
void instruct_pchar(stack_t **stack, unsigned int line)
{
int ch;
if (*stack == NULL)
{
printf("L%u: can't pchar, stack empty\n", line);
exit(EXIT_FAILURE);
}

ch = (*stack)->n;
if (!(ch >= 0 && ch <= 127))
{
printf("L%u: can't pchar, value out of range\n", line);
exit(EXIT_FAILURE);
}
putchar(ch);
putchar('\n');
}

/**
 * instruct_pstr - prints the string starting at the top of the stack
 * @stack: pointer to the top node of stack
 * @line: the current file line number calling instruction
 */
void instruct_pstr(stack_t **stack, unsigned int line __attribute__ ((unused)))
{
stack_t *tmp = *stack;
if (*stack == NULL)
{
putchar('\n');
return;
}
while (tmp)
{
if (isascii(tmp->n) && tmp->n != 0)
putchar(tmp->n);
else
break;
tmp = tmp->next;
}
putchar('\n');
}

/**
 * instruct_rotl - rotl rotates the stack to the top
 * @stack: pointer to the top node of stack
 * @line: the current file line number calling instruction
 */
void instruct_rotl(stack_t **stack, unsigned int line __attribute__ ((unused)))
{
stack_t *tmp = *stack, *rotl_top;
if (*stack == NULL || (*stack)->next == NULL)
return;
rotl_top = (*stack)->next;
rotl_top->prev = NULL;
while (tmp->next != NULL)
tmp = tmp->next;
tmp->next = *stack;
(*stack)->next = NULL;
(*stack)->prev = tmp;
(*stack) = rotl_top;
}

/**
 * instruct_rotr - rotr rotates the stack to the bottom
 * @stack: pointer to the top node of stack
 * @line: the current file line number calling instruction
 */
void instruct_rotr(stack_t **stack, unsigned int line __attribute__ ((unused)))
{
stack_t *tmp = *stack;
if (*stack == NULL || (*stack)->next == NULL)
return;
while (tmp->next != NULL)
tmp = tmp->next;

tmp->next = *stack;
tmp->prev->next = NULL;
tmp->prev = NULL;
(*stack)->prev = tmp;
(*stack) = tmp;
}
