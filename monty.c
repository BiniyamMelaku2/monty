#include "monty.h"

/* globally accessble stack struct type variable */
gl_stack mystack;

/**
 * stack_init - initialize stack top to head and head to null
 * @head: new created stack
 */

void stack_init(stack_t **head)
{
*head = NULL;
mystack.top = head;
}

/**
 * free_stack - frees malloced in stack nodes memory
 */
void free_stack(void)
{
stack_t *tmp = NULL, *head;
head = *mystack.top;
while (head != NULL)
{
tmp = head->next;
free(head);
head = tmp;
}
}

/**
 * main - monty bytecode interpreter
 * @argc: size of command line arguments
 * @argv: array of strings holding command line arguments
 * Return: exitcodes for failure or 0 Success
 */

int main(int argc, char **argv)
{
stack_t *head;
stack_init(&head);
if (argc != 2)
{
printf("USAGE: monty file\n");
exit(EXIT_FAILURE);
}
execute_file(argv[1], &head);
exit(EXIT_SUCCESS);
}
