#include "monty.h"
/**
 * op_check - check for the opcode function
 * @opcode: a string containning an opcode
 * Return: a opcode function
 */
int (*op_check(char *opcode))(stack_t **stack, unsigned int ln, char **inst)
{
	instruction_t op_list[] = {
		{"push", push_onto_stack},
		{"pall", print_all},
		{"pop", pop_top},
		{"pint", print_int},
		{"swap", swap_top},
		/**
		*{"add", add},
		*{"nop", nop},
		*/
		{NULL, NULL}
	};
	unsigned int i = 0;

	while (i < 5)
	{
		if (strcmp(opcode, op_list[i].opcode) == 0)
			return (op_list[i].f);
		i++;
	}
	return (NULL);
}
/**
 * isemptyline - checks if a given line is pratically empty
 * @str: the string to be checked
 * Return: (1) if it's empty, (-1) otherwise
 */
int isemptyline(char *str)
{
	int i = 0;

	if (str == NULL || *str == 0)
		return (1);
	while (str[i] != 0)
	{
		if (str[i] != 32 && str[i] != 10)
			return (-1);
		i++;
	}
	return (1);
}
