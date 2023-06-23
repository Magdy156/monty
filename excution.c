#include "monty.h"
/**
* execute - executes the opcode
* @stack: top of the stack
* @counter: line_counter
* @file: poiner to monty file
* @buffer: line content
* Return: 0 or 1
*/
int execute(char *buffer, stack_t **stack, unsigned int counter, FILE *file)
{
	instruction_t opst[] = {
				{"push", f_push},
				{"pall", f_pall},
				{"nop", f_nop},
				{"pop", f_pop},
				{NULL, NULL}
				};
	char *op;
	unsigned int i;

	op = strtok(buffer, " \n\t");
	if (op && op[0] == '#')
		return (0);
	data.arg = strtok(NULL, " \n\t");
	for (i = 0; opst[i].opcode && op ; i++)
	{
		if (strcmp(op, opst[i].opcode) == 0)
		{	opst[i].f(stack, counter);
			return (0);
		}
	}
	if (op && opst[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", counter, op);
		fclose(file);
		free(buffer);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	return (1);
}
