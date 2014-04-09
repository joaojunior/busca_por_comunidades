#ifndef MAIN_H
#define MAIN_H
#include "search_community.h"
#include "data_structure/grafo_matriz_adjacencia/graph.h" 
#include "algorithms/RepeatedSquaring/repeated_squaring.h"
#include "algorithms/FloydWarsHall/floyd_warshall.h"
#include "constant.h"
int *calculate_communities(Graph *, int, ResultShortestPath *(*func)(Graph *));
int *calculate_communities_repeated_square(Graph *, int);
int *calculate_communities_floyd_warshall(Graph *, int);

#endif
