#ifndef SEARCH_COMMUNITY_H
#define SEARCH_COMMUNITY_H
#include "data_structure/grafo_matriz_adjacencia/graph.h"
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
#endif
