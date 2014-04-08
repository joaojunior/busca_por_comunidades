#include "search_community.h"
int **calculate_quantity_shortest_path_in_edges(int **predecessor, int numbers_nodes){
    int **quantity_shortest_path_in_edge;
    quantity_shortest_path_in_edge = (int **)malloc(numbers_nodes * sizeof(int *));
    for(int i = 0; i < numbers_nodes; i++){
        quantity_shortest_path_in_edge[i] = (int *)malloc(numbers_nodes * sizeof(int));
        for(int j = 0; j < numbers_nodes; j++)
                quantity_shortest_path_in_edge[i][j] = 0;
    }
    for(int i = 0; i < numbers_nodes; i++)
        for(int j = 0; j < numbers_nodes; j++){
            calculate_quantity_shortest_path_in_edge(predecessor, quantity_shortest_path_in_edge, i, j);
        }
    return quantity_shortest_path_in_edge;
};

void calculate_quantity_shortest_path_in_edge(int **predecessor,int **quantity_shortest_path_in_edge, int i, int j){
    if(i != j and predecessor[i][j] != PREDECESSOR_NULL){
        calculate_quantity_shortest_path_in_edge(predecessor,quantity_shortest_path_in_edge, i, predecessor[i][j]);
        quantity_shortest_path_in_edge[predecessor[i][j]][j] += 1;
    }
};
