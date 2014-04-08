#include <stddef.h>
#include <stdlib.h>
#ifndef FLOYD_WARSHALL_H
#define FLOYD_WARSHALL_H
#include "../../data_structure/grafo_matriz_adjacencia/graph.h"
#define PREDECESSOR_NULL -1
typedef struct{
    int **distance;
    int **predecessor;
} ResultFloydWarshall;
ResultFloydWarshall *floyd_warshall(Graph *);
ResultFloydWarshall *allocate_memory(int);
void initialize(ResultFloydWarshall *, Graph *);
#endif


