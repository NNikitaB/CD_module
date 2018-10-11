#ifndef STACK_HOW_ARRAY_H
#define STACK_HOW_ARRAY_H
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define STACKOK 0
#define STACKSIZE 200
#define STACKEMPLY 1
#define STACKFULL 2
int StackError=STACKOK;
typedef struct {void * buf; size_t i; } stack;
stack * stack_init(size_t size_slot_arr );
void stackput(stack * s,void * basetype,size_t size_slot_arr);
void stackout(stack * s,void * basetype,size_t size_slot_arr);
int stackemply(stack * s);
int stackfull(stack * s);
void error_print_stack(int a);
#endif // STACK_HOW_ARRAY_H
