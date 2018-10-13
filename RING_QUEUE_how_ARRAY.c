#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define QUEUESIZE 200
#define QUEUEOK 0
#define QUEUEEMPLY 1
#define QUEUEFULL 2
#define QUEUENOTMEM 3
extern  int queueError;
typedef size_t type;
typedef struct {void * buf; type uk1,uk2,n; } queue;

queue * queue_init(type size_slot_arr );
void queueput(queue * s,void * basetype,type size_slot_arr);
void queueout(queue * s,void * basetype,type size_slot_arr);
int queueemply(queue * s);
int queuefull(queue * s);
void error_print_queue(int b);





void error_print_queue(int b)
{
     char a[5]={3,3,3,3,3};
    switch(b)
    {
        case QUEUEOK: if(a[0]>0)fputs("All-OK",stdout),a[0]-=1; break;
        case QUEUEEMPLY:if(a[1]>0) fputs("QUEUE-EMLY",stdout),a[1]-=1;break;
        case QUEUEFULL:if(a[2]>0) fputs("QUEUE-FULL",stdout),a[2]-=1;break;
        case QUEUENOTMEM:if(a[3]>0) fputs("QUEUE-NOT MEMORY IN DINAMIC MEM",stdout),a[3]-=1;break;
        default:if(a[4]>0) fputs("Unknown-error",stdout),a[4]-=1;break;
    }
}

queue *  queue_init(type size_slot_arr )
{
     void *stk=calloc(QUEUESIZE,size_slot_arr);
    queue *que=malloc(sizeof(queue));
    if(stk!=NULL && que!=NULL)
    {
    que->buf=stk;
    que->uk1=0;
    que->uk2=0;
    que->n=0;
    } else queueError = QUEUENOTMEM;
    return que;

}
void queueput(queue * s,void * basetype,type size_slot_arr)
{
     if(s->buf!=NULL && basetype!=NULL )
        if(!queuefull(s))
                 {memmove(s->buf+s->uk2*size_slot_arr,basetype,size_slot_arr);  s->uk2=(s->uk2+1)%QUEUESIZE;++s->n;}
        else if(queueError==QUEUEOK) queueError=QUEUEFULL ;
            else {error_print_queue(queueError);queueError=QUEUEFULL;}
     else queueError=55;
}
void queueout(queue * s,void * basetype,type size_slot_arr)
{
     if(s->buf!=NULL && basetype!=NULL )
        if(!queueemply(s))
                 {memmove(basetype,s->buf+s->uk1*size_slot_arr,size_slot_arr); s->uk1=(s->uk1+1)%QUEUESIZE;--s->n;}
        else if(queueError==QUEUEOK) queueError=QUEUEEMPLY ;
            else {error_print_queue(queueError);queueError=QUEUEEMPLY;}
     else queueError=55;
}
int queueemply(queue * s)
{
   return s->n==0?1:0;
}
int queuefull(queue * s)
{
   return s->n==QUEUESIZE?1:0;
}
