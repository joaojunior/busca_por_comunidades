#ifndef SEARCH_COMMUNITY_H
#define SEARCH_COMMUNITY_H
#include <stdlib.h>
#include <stdio.h>
#include "data_structure/grafo_matriz_adjacencia/graph.h"
#include "data_structure/Queue/queue.h"
#include "algorithms/NBreadthFirstSearch/bfs.h"
#include "algorithms/RepeatedSquaring/repeated_squaring.h"
#include "algorithms/FloydWarsHall/floyd_warshall.h"
#include "algorithms/JohnsonQueue/johnson.h"
#include "algorithms/JohnsonArray/johnson.h"
#include "constant.h"
#define PREDECESSOR_NULL -1
#define COMMUNITY_EMPTY -1
typedef struct{
    int source = -1;
    int dest = -1;
} Arc;
int **calculate_quantity_shortest_path_in_edges(int **, int);
void calculate_quantity_shortest_path_in_edge(int **, int **, int, int);
Arc *get_arc_with_bigger_weight(int **, int);
int *calculate_communities(int **, int);
int get_max_community(int *, int);
void calculate_distance_after_remove_edge(Graph *, ResultShortestPath *, Arc *, int **);
void update_distance_after_remove_edge_and_exist_shortest_path_between_nodes_edge_removed(Graph *, ResultShortestPath *, Arc *, int **, BFSResult *);
void update_distance_after_remove_edge_and_not_exist_shortest_path_between_nodes_edge_removed(Graph *, ResultShortestPath *, Arc *, int **);
Queue *get_shortest_path(int**, int, int);
void walk_in_shortest_path(int **, Queue *, int, int);
bool path_use_arc(Queue *, int, int);

int *calculate_communities(Graph *, int, ResultShortestPath *(*func)(Graph *));
int *calculate_communities_repeated_square(Graph *, int);
int *calculate_communities_floyd_warshall(Graph *, int);
int *calculate_communities_johnson_queue(Graph *, int);
int *calculate_communities_johnson_array(Graph *, int);
int *calculate_communities_nbfs(Graph *, int);
#endif
