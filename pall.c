#include "monty.h"
/**
 * f_pall - prints the stack elements
 * @top: stack top
 * @counter: not used
 * Return: void
*/
void f_pall(stack_t **top, unsigned int counter)
{
	stack_t *temp = *top;
	(void)counter;

	if (!temp)
		return;
	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
