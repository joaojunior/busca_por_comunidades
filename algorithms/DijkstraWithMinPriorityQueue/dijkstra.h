#ifndef DIJKSTRA_H
#define DIJKSTRA_H
#include <stdlib.h>
#include "../../data_structure/grafo_matriz_adjacencia/graph.h"
#include "../../data_structure/MinPriorityQueue/min_priority_queue.h"
#define PREDECESSOR_NULL -1
typedef struct{
    int *distance;
    int *predecessor;
} DijkstraResult;

DijkstraResult* dijkstra(Graph *, int);
DijkstraResult* allocate_memory_dijkstra(int);
void initialize(DijkstraResult*, MinPriorityQueue*, int, int);
void relax(DijkstraResult*, MinPriorityQueue*, Graph*, int, int);
#endif
