#include "monty.h"
/**
 * rotr - rotates the stack to the buttom
 * @top: the top element of the stack
 * @ln: line number
 * @inst: the line instructions array
 * Return: (1) on success and (-1) otherwise
 */
int rotr(stack_t **top, unsigned int ln, char **inst)
{
	stack_t *temp;
	(void)ln;
	(void)inst;

	temp = *top;
	if (*top == NULL || (*top)->next == NULL)
	{
		return (1);
	}

	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = *top;
	(temp->prev)->next = NULL;
	temp->prev = NULL;
	(*top)->prev = temp;
	*top = temp;
	return (1);
}
