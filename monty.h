#ifndef __MONTY__H__
#define __MONTY__H__
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <stdbool.h>
#include <unistd.h>
/*Data structures*/

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	int (*f)(stack_t **stack, unsigned int ln, char **inst);
} instruction_t;
/*Global variables*/
#ifdef DEFINE_GLOBAL_VARIABLE
#define GLOBAL_VARIABLE_VALUE true
bool is_stack = GLOBAL_VARIABLE_VALUE;
#else
extern bool is_stack;
#endif
/*Functions*/
int parse_and_execute(FILE *file, stack_t **top);
char **tokenizer(char *ch);
void fill_row(char **wordlist, int row, char *word);
int word_count(char *str);
int _strlen(char *buffer);
void free_memory(char **pointer, int n);
int (*op_check(char *opcode))(stack_t **stack, unsigned int ln, char **inst);
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
int push_onto_stack(stack_t **top, unsigned int ln, char **inst);
int enqueue(stack_t **top, unsigned int ln, char **inst);
int push(stack_t **top, unsigned int ln, char **inst);
int print_all(stack_t **top, unsigned int ln, char **inst);
int print_int(stack_t **top, unsigned int ln, char **inst);
int swap_top(stack_t **top, unsigned int ln, char **inst);
int pop_top(stack_t **top, unsigned int ln, char **inst);
int add_top(stack_t **top, unsigned int ln, char **inst);
int sub_top(stack_t **top, unsigned int ln, char **inst);
int mul_top(stack_t **top, unsigned int ln, char **inst);
int nop(stack_t **top, unsigned int ln, char **inst);
int stack_switch(stack_t **top, unsigned int ln, char **inst);
int queue_switch(stack_t **top, unsigned int ln, char **inst);
int _isdigit(char *str);
void free_mem(char **pointer);
void free_stack(stack_t *head);
int isemptyline(char *str);
int stack_hight(stack_t *top);
int div_top(stack_t **top, unsigned int ln, char **inst);
int mod_top(stack_t **top, unsigned int ln, char **inst);
int pchar_top(stack_t **top, unsigned int ln, char **inst);
int pstr_top(stack_t **top, unsigned int ln, char **inst);
int rotl(stack_t **top, unsigned int ln, char **inst);
int rotr(stack_t **top, unsigned int ln, char **inst);

#endif
