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

Arc *get_arc_with_bigger_weight(int **quantity_shortest_path_in_edge, int numbers_nodes){
    Arc *arc;
    int max_weight = 0;
    arc = (Arc *)malloc(sizeof(Arc));
    for(int i = 0; i < numbers_nodes; i++)
        for(int j = 0; j < numbers_nodes; j++)
            if(quantity_shortest_path_in_edge[i][j] > max_weight){
                max_weight = quantity_shortest_path_in_edge[i][j];
                arc->source = i;
                arc->dest = j;
            }
    return arc;
};

int *calculate_communities(int **distance, int numbers_nodes){
    int *communities2nodes;
    int community;
    communities2nodes = (int *)malloc(numbers_nodes * sizeof(int));
    for(int i = 0; i < numbers_nodes; i++)
        communities2nodes[i] = COMMUNITY_EMPTY;
    community = 1;
    for(int i = 0; i < numbers_nodes; i++){
        for(int j = i; j < numbers_nodes; j++){
            if(distance[i][j] != MAX_WEIGHT and communities2nodes[j] == COMMUNITY_EMPTY)
                communities2nodes[j] = community;
        }
        community = get_max_community(communities2nodes, numbers_nodes) + 1;
    }
    return communities2nodes;
};

int get_max_community(int *communities2nodes, int numbers_nodes){
    int max_community = 0;
    for(int i = 0; i < numbers_nodes; i++)
        if(communities2nodes[i] > max_community)
            max_community = communities2nodes[i];
    return max_community;
};