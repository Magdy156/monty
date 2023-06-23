#include "monty.h"
data_t data = {NULL, NULL, NULL};
/**
* main - monty code interpreter
* @argc: number of arguments
* @argv: monty file location
* Return: 0 on success
*/
int main(int argc, char *argv[])
{
	char *buffer;
	FILE *file;
	size_t size = 0;
	ssize_t readLine = 1;
	stack_t *stack = NULL;
	unsigned int counter = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	data.file = file;
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (readLine > 0)
	{
		buffer = NULL;
		readLine = getline(&buffer, &size, file);
		data.buff = buffer;
		counter++;
		if (readLine != -1)
		{
			execute(buffer, &stack, counter, file);
		}
		free(buffer);
	}
	free_stack(stack);
	fclose(file);
return (0);
}
