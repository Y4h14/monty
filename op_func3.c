#include "monty.h"
/**
 * div_top - divides the second top element of the stack
 * by the top element of the stack
 * @top: the top element of the stack
 * @ln: line number
 * @inst: the line instructions array
 * Return: (1) on success and (-1) otherwise
 */
int div_top(stack_t **top, unsigned int ln, char **inst)
{
	stack_t *temp;

	inst = (char **) inst;
	if (stack_hight(*top) < 2)
	{
		fprintf(stderr, "L%d: can't div stack too short\n", ln);
		free_mem(inst);
		return (-1);
	}

	temp = *top;
	if (temp->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", ln);
		free_mem(inst);
		return (-1);
	}

	(temp->next)->n = (temp->next)->n / temp->n;
	/**top = temp->next;*/
	pop_top(top, ln, inst);
	return (1);
}
/**
 * mod_top - mods the second top element of the stack
 * by the top element of the stack
 * @top: the top element of the stack
 * @ln: line number
 * @inst: the line instructions array
 * Return: (1) on success and (-1) otherwise
 */
int mod_top(stack_t **top, unsigned int ln, char **inst)
{
	stack_t *temp;

	inst = (char **) inst;
	if (stack_hight(*top) < 2)
	{
		fprintf(stderr, "L%d: can't div stack too short\n", ln);
		free_mem(inst);
		return (-1);
	}

	temp = *top;
	if (temp->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", ln);
		free_mem(inst);
		return (-1);
	}

	(temp->next)->n = (temp->next)->n % temp->n;
	/**top = temp->next;*/
	pop_top(top, ln, inst);
	return (1);
}

/**
 * pchar_top - prints a char equivilent to an int
 * @top: the top element of the stack
 * @ln: line number
 * @inst: the line instructions array
 * Return: (1) on success and (-1) otherwise
 */
int pchar_top(stack_t **top, unsigned int ln, char **inst)
{
	stack_t *temp;

	temp = *top;
	if (temp == NULL || top == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", ln);
		free_mem(inst);
		return (-1);
	}

	if (temp->n > 127 || temp->n < 32)
	{
		fprintf(stderr, "L%d, can't pchar, value out of range\n", ln);
		free_mem(inst);
		return (-1);
	}

	printf("%c\n", temp->n);
	return (1);
}

/**
 * pstr_top - prints the stack as a string
 * @top: the top element of the stack
 * @ln: line number
 * @inst: the line instructions array
 * Return: (1) on success and (-1) otherwise
 */
int pstr_top(stack_t **top, unsigned int ln, char **inst)
{
	stack_t *temp;
	(void)ln;
	(void)inst;

	temp = *top;
	while (temp != NULL)
	{
		if (temp->n > 127 || temp->n <= 0)
		{
			break;
		}
		printf("%c", temp->n);
		temp = temp->next;
	}
	printf("\n");
	return (1);
}

/**
 * rtol - rotates the stack to the top
 * @top: the top element of the stack
 * @ln: line number
 * @inst: the line instructions array
 * Return: (1) on success and (-1) otherwise
 */
int rotl(stack_t **top, unsigned int ln, char **inst)
{
	stack_t *ptr1, *ptr2;
	(void)ln;

	if (*top == NULL || (*top)->next == NULL)
	{
		free_mem(inst);
		return (1);
	}
	ptr1 = *top;
	ptr2 = (*top)->next;
	ptr2->prev = NULL;

	while (ptr1->next != NULL)
	{
		ptr1 = ptr1->next;
	}
	ptr1->next = *top;
	(*top)->next = NULL;
	(*top)->prev = ptr1;
	*top = ptr2;
	return (1);
}
