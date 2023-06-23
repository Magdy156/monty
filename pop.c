#include "monty.h"
/**
 * f_pop - remove the top
 * @top: stack top
 * @counter: line_number
 * Return: no return
*/
void f_pop(stack_t **top, unsigned int counter)
{
	stack_t *temp;

	if (*top == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", counter);
		fclose(data.file);
		free(data.buff);
		free_stack(*top);
		exit(EXIT_FAILURE);
	}
	temp = *top;
	*top = temp->next;
	free(temp);
}
