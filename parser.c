#include "monty.h"
#include <stdio.h>
/**
 * parse_and_execute - parses the user input contained in
 * the given file and attempts to interpret and execute
 * each line at a time
 * @file: a pointer to the file given by the user
 * @top: the address of the pointer to the top element
 * Return: (-1) in case of error, (0) otherwise
 */
int parse_and_execute(FILE *file, stack_t **top)
{
	char **preins = NULL, line[4096], *pointer;
	int (*f)(stack_t **top, unsigned int line_number, char **instr);
	unsigned int line_count = 0;

	while (1)
	{
		pointer = fgets(line, sizeof(line), file);
		if (pointer == NULL)
			break;
		line_count++;
		if (isemptyline(line) == 1)
			continue;
		preins = tokenizer(line);
		if (preins == NULL)
		{
			fprintf(stderr, "Error: malloc failed\n");
			return (-1);
		}
		f = op_check(preins[0]);
		if (f != NULL)
		{
			if (f(top, line_count, preins) == -1)
				return (-1);
		}
		else
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line_count, preins[0]);
			free_memory(preins, word_count(line));
			return (-1);
		}
		free_memory(preins, word_count(line));
	}
	return (1);
}
