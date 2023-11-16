#include "monty.h"
/**
 * push - handles the push opcode for both stack and queue mode
 * @top: address of the pointr to the top element of the stack
 * (or front if queue mode is activated)
 * @ln: line number
 * @inst: instruction array
 * Return: (1) if succesful, (-1) otherwise
 */
int push(stack_t **top, unsigned int ln, char **inst)
{
	if (is_stack)
		return (push_onto_stack(top, ln, inst));
	else
		return (enqueue(top, ln, inst));
}
