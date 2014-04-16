#ifndef MAIN_H
#define MAIN_H
#include "search_community.h"
#include "data_structure/grafo_matriz_adjacencia/graph.h" 
#include "algorithms/RepeatedSquaring/repeated_squaring.h"
#include "algorithms/FloydWarsHall/floyd_warshall.h"
#include "algorithms/JohnsonQueue/johnson.h"
#include "algorithms/JohnsonArray/johnson.h"
#include "algorithms/NBreadthFirstSearch/bfs.h"
#include "constant.h"
#include <stdio.h>
typedef int* (*Func)(Graph *, int);
int *calculate_communities(Graph *, int, ResultShortestPath *(*func)(Graph *));
int *calculate_communities_repeated_square(Graph *, int);
int *calculate_communities_floyd_warshall(Graph *, int);
int *calculate_communities_johnson_queue(Graph *, int);
int *calculate_communities_johnson_array(Graph *, int);
int *calculate_communities_nbfs(Graph *, int);

#endif
