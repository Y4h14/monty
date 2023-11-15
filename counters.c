#include "monty.h"
/**
  * _strlen - count string length
  * it check for EOF
  * @buffer: strings to count
  * Return: string length
  */
int _strlen(char *buffer)
{
	int i = 0, del = 0;

	while (buffer[i] != 0)
	{
		if (buffer[i] == 10 || buffer[i] == 32 || buffer[i] == '\t')
			del++;
		i++;
	}
	return (i - del);
}
/**
  * word_count - count word in string removing spaces
  * counts words by rm space, command and newline
  * @str: string
  * Return: count of str
  */
int word_count(char *str)
{
	int i = 0, count = 0;
	int check = 0;

	while (*(str + i) != 0)
	{
		while (str[i] != 0 && str[i] != 32 && str[i] != 10)
		{
			check = 1;
			i++;
		}
		if (check == 1)
			count++;
		i++;
		check = 0;
	}
	return (count);
}
