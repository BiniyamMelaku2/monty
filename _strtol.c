#include "monty.h"

int _strtol(char *str, unsigned int line)
{
int base = 10, c;
int num;
char *endptr;
num = strtol(str, &endptr, base);

if (endptr == str)
{
/* None digits were found */
printf("L%u: usage: push integer\n", line);
exit(EXIT_FAILURE);
}
for (c = 0; str[c]; c++)
{
/*if (!isdigit(str[c]))
{
printf("L%u: usage: push integer\n", line);
exit(EXIT_FAILURE);
}*/
}
return (num);
}
