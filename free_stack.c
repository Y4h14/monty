#include "monty.h"
/**
 * free_stack - frees a linked list stack
 * @head: head of the stack
 * Return: nothing
 */
void free_stack(stack_t *head)
{
	stack_t *temp;

	temp = head;
	while (head)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
}
