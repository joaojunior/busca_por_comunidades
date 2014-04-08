#ifndef SEARCH_COMMUNITY_H
#define SEARCH_COMMUNITY_H
#include "data_structure/grafo_matriz_adjacencia/graph.h" 
#include "algorithms/RepeatedSquaring/repeated_squaring.h"
typedef struct{
    int source = -1;
    int dest = -1;
} Arc;
int **calculate_quantity_shortest_path_in_edges(int **, int);
void calculate_quantity_shortest_path_in_edge(int **, int **, int, int);
Arc *get_arc_with_bigger_weight(int **, int);
#endif
