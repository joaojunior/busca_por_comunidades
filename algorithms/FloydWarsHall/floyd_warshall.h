#include <stddef.h>
#include <stdlib.h>
#ifndef FLOYD_WARSHALL_H
#define FLOYD_WARSHALL_H
#include "../../data_structure/grafo_matriz_adjacencia/graph.h"
#include "../../constant.h"
#define PREDECESSOR_NULL -1
#define ResultFloydWarshall ResultShortestPath
ResultFloydWarshall *floyd_warshall(Graph *);
ResultFloydWarshall *allocate_memory_result_floyd_warshall(int);
void initialize_floyd_warshall(ResultFloydWarshall *, Graph *);
#endif


