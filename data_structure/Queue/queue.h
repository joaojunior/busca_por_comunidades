#ifndef FILA_H
#define FILA_H
#include <stddef.h>
#include <stdlib.h>
typedef struct cell{
    int id;
    struct cell *prox=NULL;
} CellQueue;
typedef struct{
    CellQueue *first=NULL;
    CellQueue *last=NULL;
} Queue;
bool empty(Queue *);
void enqueue(Queue *, int);
int dequeue(Queue *);
#endif
