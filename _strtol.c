#include "monty.h"

/**
 * _strtol - converts string to int
 * @str: string operand input argument
 * @line: the current file line number calling instruction
 * Return: exitcodes upon failure or converted number
 */
int _strtol(char *str, unsigned int line)
{
int base = 10;
int num;
char *endptr;
num = strtol(str, &endptr, base);

if (endptr == str)
{
/* None digits were found */
printf("L%u: usage: push integer\n", line);
exit(EXIT_FAILURE);
}
if (str[0] != '\0')
if (!_isdigit(str) && *endptr != '\0')
{
printf("L%u: usage: push integer\n", line);
exit(EXIT_FAILURE);
}
return (num);
}

/**
 * _isdigit - checks string is digit
 * @str: string input argument
 * Return: 0 Notdigit or 1 it is digit
 */

int _isdigit(char *str)
{
int c = 0;
if (str == NULL)
return (0);
while (str[c])
{
if (isdigit(str[c]) == 0)
return (0);
c++;
}
return (1);
}
