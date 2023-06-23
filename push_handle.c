#include "monty.h"
int _atoi(char *s);
/**
 * f_push - add node to the stack
 * @head: top of the stack
 * @counter: line_number
 * Return: void
*/
void f_push(stack_t **head, unsigned int counter)
{
	int n, i = 0, flag = 0;

	if (data.arg)
	{
		if (data.arg[0] == '-')
			i++;
		while (data.arg[i] != '\0')
		{
			if (data.arg[i] > 57 || data.arg[i] < 48)
				flag = 1;
			i++;
		}
		if (flag == 1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", counter);
			fclose(data.file);
			free(data.buff);
			free_stack(*head);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", counter);
		fclose(data.file);
		free(data.buff);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	n = atoi(data.arg);
	push(head, n);
}
/**
 * _atoi - convert a string into an integer
 * @s: the string to be converted
 * Return: integer
 */
int _atoi(char *s)
{
	int sign = 1, i = 0;
	unsigned int res = 0;


	while (!(s[i] <= '9' && s[i] >= '0') && s[i] != '\0')
	{
		if (s[i] == '-')
			sign *= -1;
		i++;
	}
	while (s[i] <= '9' && (s[i] >= '0' && s[i] != '\0'))
	{
		res = (res * 10) + (s[i] - '0');
		i++;
	}
	res *= sign;
	return (res);
}
