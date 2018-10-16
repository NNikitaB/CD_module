#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define STACKSIZE 200
#define STACKOK 0
#define STACKEMPLY 1
#define STACKFULL 2
#define STACKNOTMEM 3
extern int StackError;
typedef struct {void * buf; size_t i; } stack;

stack *  stack_init(size_t size_slot_arr );
void stackput(stack * s,void * basetype,size_t size_slot_arr);
void stackout(stack * s,void * basetype,size_t size_slot_arr);
int stackemply(stack * s);
int stackfull(stack * s);
void error_print_stack(int a);





void error_print_stack(int b)
{
    static char a[5]={3,3,3,3,3};
    switch(b)
    {
        case STACKOK:if(a[0]>0) fputs("All-OK",stdout);a[0]-=1; break;
        case STACKEMPLY: if(a[1]>0)fputs("STACK-EMLY",stdout);a[1]-=1; break;
        case STACKFULL:if(a[2]>0) fputs("STACK-FULL",stdout);a[2]-=1; break;
        case STACKNOTMEM:if(a[3]>0) fputs("STACK-NOT MEMORY IN DINAMIC MEM",stdout);a[3]-=1; break;
        default:if(a[4]>0) fputs("Unknown-error",stdout);a[4]-=1; break;
    }
}

stack * stack_init(size_t size_slot_arr )
{
    void *stk=calloc(STACKSIZE,size_slot_arr);
    stack * s=(stack *)malloc(sizeof(stack));
    s->buf=stk;
    s->i=0;
    if(stk==NULL) StackError=STACKNOTMEM;
    return s;
}
void stackput(stack * s,void * basetype,size_t size_slot_arr)
{
     if(s->buf!=NULL && basetype!=NULL )
        if(!stackfull(s))
                 {memmove(s->buf+s->i*size_slot_arr,basetype,size_slot_arr);  ++s->i;}
        else if(StackError==STACKOK) StackError=STACKFULL ;
            else {error_print_stack(StackError);StackError=STACKFULL;}
     else StackError=55;
}
void stackout(stack * s,void * basetype,size_t size_slot_arr)
{
     if(s->buf!=NULL && basetype!=NULL )
        if(!stackemply(s))
                 {--s->i;memmove(basetype,s->buf+s->i*size_slot_arr,size_slot_arr);}
        else if(StackError==STACKOK) StackError=STACKEMPLY ;
            else {error_print_stack(StackError);StackError=STACKEMPLY;}
     else StackError=55;
}
int stackemply(stack * s)
{
   return s->i==0?1:0;
}
int stackfull(stack * s)
{
   return s->i==STACKSIZE?1:0;
}
