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
	input = fopen(argv[1], "r+");
	if (input == NULL)
	{
		write(2, "Error: Can't open file\n", 24);
		exit(EXIT_FAILURE);
	}
	parse_and_execute(input, &top);
	fclose(input);
	return (0);
}
