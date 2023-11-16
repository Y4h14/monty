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
	free(temp);
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
	free(temp);
	pop_top(top, ln, inst);
	return (1);
}
