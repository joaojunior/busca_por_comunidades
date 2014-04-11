#ifndef BELLMAN_FORD_H
#define BELLMAN_FORD_H
#define PREDECESSOR_NULL -1
#include <stdlib.h>
#include "../../data_structure/grafo_matriz_adjacencia/graph.h"
typedef struct bell{
    int *distance;
    int *predecessor;
    bool exist_negative_cycle;
} BellmanFordResult;

BellmanFordResult *bellmanFord(Graph*, int);
BellmanFordResult *allocate_memory(int);
void initialize(BellmanFordResult *, int, int);
void relax(BellmanFordResult *, Graph*, int, int);
void verify_negative_cycle(BellmanFordResult *, Graph *);
#endif