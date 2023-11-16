#include "monty.h"
/**
 * swap_top - swaps the two top elements on te stack
 * @top: the top of the stack
 * @ln: line number
 * @inst: instruction array
 * Return: (1) on success, (-1) otherwise
 */
int swap_top(stack_t **top, unsigned int ln, char **inst)
{
	stack_t *first = NULL, *second = NULL, *third = NULL;

	if (*top == NULL || (*top)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", ln);
		free_mem(inst);
		return (-1);
	}
	/*Assign the top three for readability*/
	first = *top;
	second = (*top)->next;
	third = (*top)->next->next;
	/*Rearrange the links*/
	first->next = third;
	first->prev = second;
	second->prev = NULL;
	second->next = first;
	/*link the third to the preciously first if it exists*/
	if (third != NULL)
		third->prev = first;
	*top = second;
	return (1);
}
/**
 * add_top - adds the top element value to the second, and pops
 * the tsecond->nexop element afterwards
 * @top: the top of the stack
 * @ln: line number
 * @inst: instruction array
 * Return: (1) on success, (-1) otherwise
 */
int add_top(stack_t **top, unsigned int ln, char **inst)
{
	if (*top == NULL || (*top)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", ln);
		free_mem(inst);
		return (-1);
	}
	(*top)->next->n += (*top)->n;
	pop_top(top, ln, inst);
	return (1);
}
/**
 * nop - does literally nothing
 * @top: the top of the stack
 * @ln: line number
 * @inst: instruction array
 * Return: (1) on success, (-1) otherwise
 */
int nop(stack_t **top, unsigned int ln, char **inst)
{
	top = (stack_t **) top;
	ln = (unsigned int) ln;
	inst = (char **) inst;
	return (1);
}
