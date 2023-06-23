#include "monty.h"
/**
 * f_pint - prints the top
 * @top: stack top
 * @counter: line_number
 * Return: coid
*/
void f_pint(stack_t **top, unsigned int counter)
{
	if (*top == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", counter);
		fclose(data.file);
		free(data.buff);
		free_stack(*top);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*top)->n);
}
