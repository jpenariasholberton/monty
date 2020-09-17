#ifndef _MONTY_H_
#define _MONTY_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */

typedef struct stack_st
{
        int n;
        struct stack_st *prev;
        struct stack_st *next;
} stack_tt;

extern stack_tt *stack;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */

typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_tt **stack, unsigned int line_number);
} instruction_t;

void exec_opcode_monty(char **argv);
void tokenizer(char *entry, char **eachString);
void (*get_struct_opcode(char *str))(stack_tt **stack, unsigned int line_number);
void _push(stack_tt **stack, unsigned int line_number);
void _nop(stack_tt **stack, unsigned int line_number);
void _pall(stack_tt **stack, unsigned int num_line);

void error_arg(void);
void error_open(char **argv);
void error_instruction(char *instruction, unsigned int line);
void error_malloc(void);
void free_dpointer(char **command);

#endif
