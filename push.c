#include "monty.h"
/**
 * push - add node to the top stack
 * @top: top of the stack
 * @n: new_value
 * Return: coid
*/
void push(stack_t **top, int n)
{

	stack_t *newNode, *temp;

	temp = *top;
	newNode = malloc(sizeof(stack_t));
	if (!newNode)
	{
		printf("Error\n");
		exit(0);
	}
	if (temp)
		temp->prev = newNode;
	newNode->n = n;
	newNode->next = *top;
	newNode->prev = NULL;
	*top = newNode;
}
