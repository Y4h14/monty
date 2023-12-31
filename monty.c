#define DEFINE_GLOBAL_VARIABLE
#include "monty.h"
/**
 * main - Monty main funnction
 * @argc: argument count
 * @argv: argument vector
 * Return: (0) in case of success
 */
int main(int argc, char **argv)
{
	stack_t *top = NULL;
	FILE *input = NULL;

	if (argc != 2)
	{
		write(2, "USAGE: monty file\n", 19);
		exit(EXIT_FAILURE);
	}
	input = fopen(argv[1], "r");
	if (input == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	if (parse_and_execute(input, &top) == -1)
	{
		fclose(input);
		free_stack(top);
		exit(EXIT_FAILURE);
	}
	free_stack(top);
	fclose(input);
	return (0);
}
