#include "monty.h"
/**
  * free_memory - free memory
  * @pointer: point to memory to free
  * @n: count of character
  */
void free_memory(char **pointer, int n)
{
	int i = 0;

	while (i < n)
	{
		free(*(pointer + i));
		i++;
	}
	free(pointer);
}
/**
 * free_mem - frees memory
 * @pointer: double list
 * Return: (void)
 */
void free_mem(char **pointer)
{
	int i = 0;

	if (pointer == NULL || *pointer == NULL)
		return;
	while (pointer[i] != NULL)
	{
		free(pointer[i]);
		i++;
	}
	free(pointer);
}
