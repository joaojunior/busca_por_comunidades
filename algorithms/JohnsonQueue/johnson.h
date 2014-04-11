#ifndef JOHNSON_H
#define JOHNSON_H
#include "../../data_structure/grafo_matriz_adjacencia/graph.h"
#include "../Bellman-Ford/bellman_ford.h"
#include "../DijkstraWithMinPriorityQueue/dijkstra.h"
#define PREDECESSOR_NULL -1
typedef struct{
    int **distance;
    int **predecessor;
} JohnsonResult;

JohnsonResult* jonhson(Graph *);
BellmanFordResult* reconsider_graph(Graph *);
void create_graph_reconsidered(Graph *,Graph *);
#endif
