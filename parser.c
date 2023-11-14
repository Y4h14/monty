#include "monty.h"
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
	char **preinstruct = NULL, *line = NULL;
	int readc = 0, i = 0;
	size_t buffsz = 0;

	while (readc != -1)
	{
		readc = getline(&line, &buffsz, file);
		if (readc == -1)
		{
			printf("End of file");
			break;
		}
		preinstruct = tokenizer(line);
		if (preinstruct == NULL)
			fprintf(stderr, "Error: malloc failed\n");
		i = 0;
		while (preinstruct[i] != NULL)
		{
			printf("%s\n", preinstruct[i]);
			i++;
		}
		free_memory(preinstruct, word_count(line));
	}
	free(line);
	return (0);
}
