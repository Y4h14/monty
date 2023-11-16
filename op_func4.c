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
	stack_t *temp = NULL;
	(void)ln;
	(void)inst;

	if (*top == NULL || (*top)->next == NULL)
	{
		return (1);
	}
	temp = *top;
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
/**
 * queue_switch - switches the data insert mode to queue mode
 * @top: the top element of the stack
 * @ln: line number
 * @inst: the line instructions array
 * Return: (1) on success and (-1) otherwise
 */
int queue_switch(stack_t **top, unsigned int ln, char **inst)
{
	top = (stack_t **) top;
	ln = (unsigned int) ln;
	inst = (char **) inst;
	is_stack = false;
	return (1);
}
/**
 * stack_switch - switches the data insert mode to stack mode
 * @top: the top element of the stack
 * @ln: line number
 * @inst: the line instructions array
 * Return: (1) on success and (-1) otherwise
 */
int stack_switch(stack_t **top, unsigned int ln, char **inst)
{
	top = (stack_t **) top;
	ln = (unsigned int) ln;
	inst = (char **) inst;
	is_stack = true;
	return (1);
}
/**
 * enqueue - adds a node at the end of the list
 * @top: the address of the pointer to the first element
 * @ln: line number
 * @inst: instruction array
 * Return: (1) if succesful, (-1) in case of failure
 */
int enqueue(stack_t **top, unsigned int ln, char **inst)
{
	stack_t *newnode = NULL, *iter = *top;
	int data = 0;

	if (_isdigit(inst[1]) != 1)
	{
		fprintf(stderr, "L%d: usage: push integer\n", ln);
		free_mem(inst);
		return (-1);
	}
	data = atoi(inst[1]);
	newnode = malloc(sizeof(stack_t));
	if (newnode == NULL)
	{
		fprintf(stderr, "Error: malloc failed");
		free_mem(inst);
		return (-1);
	}
	newnode->n = data;
	newnode->next = NULL;
	if (*top == NULL)
	{
		newnode->prev = NULL;
		*top = newnode;
		return (1);
	}
	while (iter->next != NULL)
		iter = iter->next;
	newnode->prev = iter;
	if (iter != NULL)
		iter->next = newnode;
	return (1);
}
