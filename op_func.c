#include "monty.h"
/**
 * push_onto_stack - pushes an element on top of the stack
 * @top: the address of the pointer to the top of the stack
 * @ln: line number
 * @inst: instruction
 * Return: (void)
 */
int push_onto_stack(stack_t **top, unsigned int ln, char **inst)
{
	stack_t *newelement = NULL;
	int data = 0;

	if (_isdigit(inst[1]) != 1)
	{
		fprintf(stderr, "L%d: usage: push integer\n", ln);
		free_mem(inst);
		return (-1);
	}
	data = atoi(inst[1]);
	newelement = malloc(sizeof(stack_t));
	if (newelement == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_mem(inst);
		return (-1);
	}
	newelement->n = data;
	if (*top != NULL)
		(*top)->prev = newelement;
	newelement->prev = NULL;
	newelement->next = *top;
	*top = newelement;
	return (1);
}
/**
 * print_all - prints all the elements in the stack
 * @top: the address of the pointer to the top of the stack
 * @ln: line number
 * @inst: instruction
 * Return: (void)
 */
int print_all(stack_t **top, unsigned int ln, char **inst)
{
	stack_t *iter = *top;

	if (*top == NULL || top == NULL)
		return (1);
	while (iter != NULL)
	{
		printf("%d\n", iter->n);
		iter = iter->next;
	}
	inst = (char **) inst;
	ln = (unsigned int) ln;
	return (1);
}
/**
 * _isdigit - checks if the given string has only digits
 * @str: the given string
 * Return: (1) if it is only digits, (-1) otherwise
 */
int _isdigit(char *str)
{
	int i = 0;

	if (str == NULL || *str == 0)
		return (-1);
	while (str[i] != 0)
	{
		if (str[i] < 48 || str[i] > 57)
			return (-1);
		i++;
	}
	return (1);
}
/**
 * pop_top - pops the top of the stack
 * @top: the address of the pointer to the top of the stack
 * @ln: line number
 * @inst: user instruction
 * Return: (1) if successful, (-1) otherwise
 */
int pop_top(stack_t **top, unsigned int ln, char **inst)
{
	stack_t *placeholder = NULL;

	if (*top == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", ln);
		free_mem(inst);
		return (-1);
	}
	placeholder = *top;
	*top = (*top)->next;
	if (*top != NULL)
		(*top)->prev = NULL;
	free(placeholder);
	return (1);
}
