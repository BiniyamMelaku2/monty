#include "monty.h"

/**
 * execute_file - performs stack operations reading from a file
 * @filename: the name of the file
 * @stack: pointer to top node of a stack
 * Return: exitcodes for failure or 0 Success
 */

int execute_file(char *filename, stack_t **stack)
{
char *lineptr = NULL, *oper;
unsigned int line = 0;
FILE *myfile;
size_t llen;
ssize_t read;

if (!filename)
{
fprintf(stdout, "Error: Can't open file %s\n", filename);
exit(EXIT_FAILURE);
}

myfile = fopen(filename, "r");
if (myfile == NULL)
{
fprintf(stdout, "Error: Can't open file %s\n", filename);
exit(EXIT_FAILURE);
}
atexit(free_stack);

while ((read = getline(&lineptr, &llen, myfile)) != -1)
{
oper = strtok(lineptr, delims);
line++;
if (oper)
call_oper(stack, oper, line);
}
free(lineptr);
fclose(myfile);
return (EXIT_SUCCESS);
}
