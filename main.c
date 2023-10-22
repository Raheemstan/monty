#include "monty.h"
#include <stdio.h>

bus_t bus = {NULL, NULL, NULL, 0};
/**
 * main - monty code interpreter
 * @argc: number of arguments
 * @argv: monty file location
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	char *content = NULL; // Initialize content to NULL
	FILE *file;
	size_t size = 0;
	stack_t *stack = NULL;
	unsigned int counter = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	bus.file = file;
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (fgets(content, size, file) != NULL)
	{
		bus.content = content;
		counter++;
		execute(content, &stack, counter, file);
	}
	free_stack(stack);
	free(content); // Free the allocated memory
	fclose(file);
	return (0);
}
