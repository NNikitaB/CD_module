#ifndef RING_QUEUE_HOW_ARRAY_H
#define RING_QUEUE_HOW_ARRAY_H
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define QUEUESIZE 200
#define QUEUEOK 0
#define QUEUEEMPLY 1
#define QUEUEFULL 2
#define QUEUENOTMEM 3
typedef size_t type;
typedef struct {void * buf; type uk1,uk2,n; } queue;

queue * queue_init(type size_slot_arr );
void queueput(queue * s,void * basetype,type size_slot_arr);
void queueout(queue * s,void * basetype,type size_slot_arr);
int queueemply(queue * s);
int queuefull(queue * s);
void error_print_queue(int b);

int queueError=0;

#endif // RING_QUEUE_HOW_ARRAY_H_INCLUDED
