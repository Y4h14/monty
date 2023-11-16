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
	stack_t *ptr1, *ptr2;
	(void)ln;
	(void)inst;

	if (*top == NULL || (*top)->next == NULL)
	{
		return (1);
	}
	ptr1 = *top;
	ptr2 = ptr1->next;
	ptr1->next = NULL;
	ptr1->prev = ptr2;

	while (ptr2 != NULL)
	{
		ptr2->prev = ptr2->next;
		ptr2->next = ptr1;
		ptr1 = ptr2;
		ptr2 = ptr2->prev;
	}
	*top = ptr1;
	return (1);
}
