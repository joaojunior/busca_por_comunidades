#ifndef DIJKSTRA_ARRAY_H
#define DIJKSTRA_ARRAY_H
#include <stdlib.h>
#include "../../data_structure/grafo_matriz_adjacencia/graph.h"
#define PREDECESSOR_NULL -1
#define NODE_NOT_VISITED -1
typedef struct{
    int *distance;
    int *predecessor;
} DijkstraArrayResult;

DijkstraArrayResult* dijkstra_array(Graph *, int);
DijkstraArrayResult* allocate_memory_dijkstra_array(int);
void initialize(DijkstraArrayResult*, int*, int, int);
bool exist_node2visit(int *, int);
int extract_minimum(int *, int);
void relax(DijkstraArrayResult*, int*, Graph*, int, int);
#endif
