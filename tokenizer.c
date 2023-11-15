#include "monty.h"
/**
 * tokenizer - it remove spaces from our argument
 * it brings user commands in an array
 * @ch: strings
 * Return: pointer to wordlist
 */
char **tokenizer(char *ch)
{
	int wordc = 0, i = 1, char_count = 0;
	char *word;
	char **wordlist, del[] = " ";

	if (ch == NULL)
		return (NULL);
	wordc = word_count(ch);
	wordlist = malloc(sizeof(char *) * (wordc + 1));
	if (wordlist == NULL)
		return (NULL);
	word = strtok(ch, del);
	char_count = _strlen(word);
	*wordlist = malloc(sizeof(char) * char_count + 1);
	if (*wordlist == NULL)
	{
		free(wordlist);
		return (NULL);
	}
	fill_row(wordlist, 0, word);
	while (i < wordc)
	{
		word = strtok(NULL, del);
		char_count = _strlen(word);
		*(wordlist + i) = malloc(sizeof(char) * char_count + 1);
		if (*(wordlist + i) == NULL)
		{
			free_memory(wordlist, i);
			return (NULL);
		}
		fill_row(wordlist, i, word);
		i++;
	}
	wordlist[i] = NULL;
	return (wordlist);
}
/**
  * fill_row - fill worldlist pointer32
  * put words in each rows
  * @wordlist: pointer
  * @row: wordlist pointer row
  * @word: content to fill
  */
void fill_row(char **wordlist, int row, char *word)
{
	int i = 0, j = 0;

	while (word[i] != 0)
	{
		if (word[i] != 10 && word[i] != 32 && word[i] != '\t')
		{
			wordlist[row][j] = word[i];
			j++;
		}
		i++;
	}
	wordlist[row][j] = '\0';
}
