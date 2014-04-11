#ifndef JOHNSON_ARRAY_H
#define JOHNSON_ARRAY_H
#include "../../data_structure/grafo_matriz_adjacencia/graph.h"
#include "../Bellman-Ford/bellman_ford.h"
#include "../DijkstraWithArray/dijkstra.h"
#include "../../constant.h"
#define PREDECESSOR_NULL -1
#define JohnsonResult ResultShortestPath

JohnsonResult* johnson_array(Graph *);
BellmanFordResult* reconsider_graph_johnson_array(Graph *);
void create_graph_reconsidered_johnson_array(Graph *,Graph *);
#endif
