#include "monty.h"
/**
 * f_add - adds the top two elements of the stack.
 * @top: stack top
 * @counter: line_number
 * Return: void
*/
void f_add(stack_t **top, unsigned int counter)
{
	stack_t *temp;
	int len = 0, tempVal;

	temp = *top;
	while (temp)
	{
		temp = temp->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", counter);
		fclose(data.file);
		free(data.buff);
		free_stack(*top);
		exit(EXIT_FAILURE);
	}
	temp = *top;
	tempVal = temp->n + temp->next->n;
	temp->next->n = tempVal;
	*top = temp->next;
	free(temp);
}
