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

void calculate_distance_after_remove_edge(Graph *graph, ResultShortestPath *result, Arc *edge2remove, int **quantity_shortest_path_in_edge){
    int k, difference, source, dest, node_before_source_removed;
    Queue *shortest_path, *nodes_before, *nodes_between, *nodes_after, aux, nodes_between1, nodes_before1, nodes_after1;
    BellmanFordResult *result_bellman_ford;
    result_bellman_ford = bellmanFord(graph, edge2remove->source);
    k = result_bellman_ford->predecessor[edge2remove->dest];
    if(k != PREDECESSOR_NULL){
        source = edge2remove->dest;
        while(source != edge2remove->source){
            enqueue(&nodes_between1, source);
            node_before_source_removed = source;
            source = result_bellman_ford->predecessor[source];
        }
        enqueue(&nodes_between1, source);
        difference = result_bellman_ford->distance[edge2remove->dest] - result->distance[edge2remove->source][edge2remove->dest];
        for(int i = 0; i < graph->numbers_nodes; i++){
            for(int j = i + 1; j < graph->numbers_nodes; j++){
                if((edge2remove->source != i or edge2remove->dest != j)){
                    shortest_path = get_shortest_path(result->predecessor, i, j);
                    if(path_use_arc(shortest_path, edge2remove->source, edge2remove->dest)){
                        enqueue(&nodes_before1, i);
                        enqueue(&nodes_after1, j);
                        result->distance[i][j] += difference;
                        result->distance[j][i] = result->distance[i][j];
                        source = dequeue(&nodes_between1);
                        while(not empty(&nodes_between1)){
                            dest = dequeue(&nodes_between1);
                            quantity_shortest_path_in_edge[source][dest] += quantity_shortest_path_in_edge[edge2remove->source][edge2remove->dest];
                            quantity_shortest_path_in_edge[dest][source] = quantity_shortest_path_in_edge[source][dest];
                            source = dest;
                        }
                    }
                }
            }
        }
        while(not empty(&nodes_before1)){
            source = dequeue(&nodes_before1);
            result->predecessor[source][edge2remove->dest] = k;
        }
        while(not empty(&nodes_after1)){
            source = dequeue(&nodes_after1);
            result->predecessor[source][edge2remove->source] = node_before_source_removed;
        }
        result->distance[edge2remove->source][edge2remove->dest] = result_bellman_ford->distance[edge2remove->dest];
        result->distance[edge2remove->dest][edge2remove->source] = result->distance[edge2remove->source][edge2remove->dest];
        result->predecessor[edge2remove->source][edge2remove->dest] = k;
        result->predecessor[edge2remove->dest][edge2remove->source] = node_before_source_removed;
    } else{
        for(int i = 0; i < graph->numbers_nodes; i++){
            for(int j = i + 1; j < graph->numbers_nodes; j++){
                if((edge2remove->source != i or edge2remove->dest != j)){
                    shortest_path = get_shortest_path(result->predecessor, i, j);
                    if(path_use_arc(shortest_path, edge2remove->source, edge2remove->dest)){
                        source = dequeue(shortest_path);
                        while(not empty(shortest_path)){
                            dest = dequeue(shortest_path);
                            quantity_shortest_path_in_edge[source][dest] -= 1;
                            quantity_shortest_path_in_edge[dest][source] = quantity_shortest_path_in_edge[source][dest];
                            source = dest;
                        }
                    result->predecessor[i][j] = PREDECESSOR_NULL;
                    result->predecessor[j][i] = PREDECESSOR_NULL;
                    result->distance[i][j] = MAX_WEIGHT;
                    result->distance[j][i] = MAX_WEIGHT;
                    }
                }
            }
        }
        result->distance[edge2remove->source][edge2remove->dest] = MAX_WEIGHT;
        result->distance[edge2remove->dest][edge2remove->source] = result->distance[edge2remove->source][edge2remove->dest];
        result->predecessor[edge2remove->source][edge2remove->dest] = PREDECESSOR_NULL;
        result->predecessor[edge2remove->dest][edge2remove->source] = result->predecessor[edge2remove->source][edge2remove->dest];
    }
    quantity_shortest_path_in_edge[edge2remove->source][edge2remove->dest] = 0;
    quantity_shortest_path_in_edge[edge2remove->dest][edge2remove->source] = quantity_shortest_path_in_edge[edge2remove->source][edge2remove->dest];
};

void update_distance_and_predecessor(int **predecessor, int i, int j, Queue *path){
    if(i != j and predecessor[i][j] != PREDECESSOR_NULL){
        update_distance_and_predecessor(predecessor, i, predecessor[i][j], path);
        //quantity_shortest_path_in_edge[predecessor[i][j]][j] += 1;
        enqueue(path, predecessor[i][j]);
        enqueue(path, j);
    }
};

Queue *get_shortest_path(int **predecessor, int source, int dest){
    Queue *path;
    path = (Queue *)malloc(sizeof(Queue));
    path->first = NULL;
    path->last = NULL;
    walk_in_shortest_path(predecessor, path, source, dest);
    return path;
};

void walk_in_shortest_path(int **predecessor, Queue *path, int i, int j){
    if(i == j){
        enqueue(path, i);
    }else if(predecessor[i][j] != PREDECESSOR_NULL){
        walk_in_shortest_path(predecessor, path, i, predecessor[i][j]);
        enqueue(path, j);
    }
};

Queue *get_nodes_before_node_i_inclusive_in_shortest_path(Queue *path, int node){
    Queue *nodes;
    int i;
    nodes = (Queue *)malloc(sizeof(Queue));
    nodes->first = NULL;
    nodes->last = NULL;
    i = dequeue(path);
    while(i != node){
        enqueue(nodes, i);
        i = dequeue(path);
    }
    enqueue(nodes, node);
    return nodes;
};

Queue *get_nodes_between_nodes_inclusive_in_shortest_path(Queue *path, int source, int dest){
    Queue *nodes;
    int i;
    nodes = (Queue *)malloc(sizeof(Queue));
    nodes->first = NULL;
    nodes->last = NULL;
    enqueue(nodes, source);
    i = dequeue(path);
    while(i != dest){
        enqueue(nodes, i);
        i = dequeue(path);
    }
    enqueue(nodes, dest);
    return nodes;
};

Queue *get_nodes_after_node_i_inclusive_in_shortest_path(Queue *path, int node){
    Queue *nodes;
    nodes = (Queue *)malloc(sizeof(Queue));
    nodes->first = NULL;
    nodes->last = NULL;
    enqueue(nodes, node);
    while(not empty(path))
        enqueue(nodes, dequeue(path));
    return nodes;
};

bool path_use_arc(Queue *path, int source, int dest){
    Queue aux;
    int i, j;
    bool result;
    result = false;
    i = dequeue(path);
    enqueue(&aux, i);
    while(not empty(path)){
        j = dequeue(path);
        enqueue(&aux, j);
        if((i == source and j == dest) or (i == dest and j == source))
            result = true;
        i = j;
    }
    while(not empty(&aux)){
        enqueue(path, dequeue(&aux));
    }
    return result;
};