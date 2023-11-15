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
		/*
		*{"pint", pint},
		*{"swap", swap},
		*{"add", add},
		*{"nop", nop},
		*/
		{NULL, NULL}
	};
	unsigned int i = 0;

	while (i < 2)
	{
		if (strcmp(opcode, op_list[i].opcode) == 0)
			return (op_list[i].f);
		i++;
	}
	return (NULL);
}
