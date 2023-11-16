#include "monty.h"
/**
 * stack_hight - count the number of elements in a stack
 * @top: the top element of the stack
 * Return: the hight of the stack
 */
size_t stack_hight(stack_t *top)
{
	size_t i;

	for (i = 0; top != NULL; i++)
		top = top->next;
	return (i);
}
