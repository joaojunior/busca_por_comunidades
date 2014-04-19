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
    BFSResult *result_bfs;
    result_bfs = bfs(graph, edge2remove->source);
    if(result_bfs->predecessor[edge2remove->dest] != PREDECESSOR_NULL){
        update_distance_after_remove_edge_and_exist_shortest_path_between_nodes_edge_removed(graph, result, edge2remove, quantity_shortest_path_in_edge, result_bfs);
    } else{
        update_distance_after_remove_edge_and_not_exist_shortest_path_between_nodes_edge_removed(graph, result, edge2remove, quantity_shortest_path_in_edge);
    }
    quantity_shortest_path_in_edge[edge2remove->source][edge2remove->dest] = 0;
    quantity_shortest_path_in_edge[edge2remove->dest][edge2remove->source] = 0;
};

void update_distance_after_remove_edge_and_exist_shortest_path_between_nodes_edge_removed(Graph *graph, ResultShortestPath *result, Arc *edge2remove, int **quantity_shortest_path_in_edge, BFSResult *result_bfs){
    int difference, source, dest, node_before_source_removed;
    Queue *shortest_path, nodes_between_new_shortest_path, nodes_before_arc_removed, nodes_after_arc_removed;
    source = edge2remove->dest;
    while(source != edge2remove->source){
        enqueue(&nodes_between_new_shortest_path, source);
        node_before_source_removed = source;
        source = result_bfs->predecessor[source];
    }
    enqueue(&nodes_between_new_shortest_path, source);
    source = dequeue(&nodes_between_new_shortest_path);
    while(not empty(&nodes_between_new_shortest_path)){
        dest = dequeue(&nodes_between_new_shortest_path);
        quantity_shortest_path_in_edge[source][dest] += quantity_shortest_path_in_edge[edge2remove->source][edge2remove->dest];
        quantity_shortest_path_in_edge[dest][source] = quantity_shortest_path_in_edge[source][dest];
        source = dest;
    }
    difference = result_bfs->distance[edge2remove->dest] - result->distance[edge2remove->source][edge2remove->dest];
    for(int i = 0; i < graph->numbers_nodes; i++){
        for(int j = i + 1; j < graph->numbers_nodes; j++){
            if((edge2remove->source != i or edge2remove->dest != j) and (result->distance[i][j] != MAX_WEIGHT)){
                shortest_path = get_shortest_path(result->predecessor, i, j);
                if(path_use_arc(shortest_path, edge2remove->source, edge2remove->dest)){
                    enqueue(&nodes_before_arc_removed, i);
                    enqueue(&nodes_after_arc_removed, j);
                    result->distance[i][j] += difference;
                    result->distance[j][i] = result->distance[i][j];
                }
            }
        }
    }
    while(not empty(&nodes_before_arc_removed)){
        source = dequeue(&nodes_before_arc_removed);
        result->predecessor[source][edge2remove->dest] = result_bfs->predecessor[edge2remove->dest];
    }
    while(not empty(&nodes_after_arc_removed)){
        source = dequeue(&nodes_after_arc_removed);
        result->predecessor[source][edge2remove->source] = node_before_source_removed;
    }
    result->distance[edge2remove->source][edge2remove->dest] = result_bfs->distance[edge2remove->dest];
    result->distance[edge2remove->dest][edge2remove->source] = result->distance[edge2remove->source][edge2remove->dest];
    result->predecessor[edge2remove->source][edge2remove->dest] = result_bfs->predecessor[edge2remove->dest];
    result->predecessor[edge2remove->dest][edge2remove->source] = node_before_source_removed;
};

void update_distance_after_remove_edge_and_not_exist_shortest_path_between_nodes_edge_removed(Graph *graph, ResultShortestPath *result, Arc *edge2remove, int **quantity_shortest_path_in_edge){
    int source, dest;
    Queue *shortest_path, nodes_before_arc_removed, nodes_after_arc_removed, aux;
    for(int i = 0; i < graph->numbers_nodes; i++){
        for(int j = i + 1; j < graph->numbers_nodes; j++){
            if((edge2remove->source != i or edge2remove->dest != j) and (result->distance[i][j] != MAX_WEIGHT)){
                shortest_path = get_shortest_path(result->predecessor, i, j);
                if(path_use_arc(shortest_path, edge2remove->source, edge2remove->dest)){
                    source = dequeue(shortest_path);
                    while(not empty(shortest_path)){
                        dest = dequeue(shortest_path);
                        quantity_shortest_path_in_edge[source][dest] -= 1;
                        quantity_shortest_path_in_edge[dest][source] = quantity_shortest_path_in_edge[source][dest];
                        source = dest;
                    }
                    enqueue(&nodes_before_arc_removed, i);
                    enqueue(&nodes_after_arc_removed, j);
                }
            }
        }
    }
    while(not empty(&nodes_before_arc_removed)){
        source = dequeue(&nodes_before_arc_removed);
        while(not empty(&nodes_after_arc_removed)){
            dest = dequeue(&nodes_after_arc_removed);
            result->predecessor[source][dest] = PREDECESSOR_NULL;
            result->predecessor[dest][source] = PREDECESSOR_NULL;
            result->distance[source][dest] = MAX_WEIGHT;
            result->distance[dest][source] = MAX_WEIGHT;
            enqueue(&aux, dest);
        }
        while(not empty(&aux))
            enqueue(&nodes_after_arc_removed, dequeue(&aux));
    }
    result->distance[edge2remove->source][edge2remove->dest] = MAX_WEIGHT;
    result->distance[edge2remove->dest][edge2remove->source] = MAX_WEIGHT;
    result->predecessor[edge2remove->source][edge2remove->dest] = PREDECESSOR_NULL;
    result->predecessor[edge2remove->dest][edge2remove->source] = PREDECESSOR_NULL;
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

int *calculate_communities_repeated_square(Graph *graph, int quantity_communities){
    return calculate_communities(graph, quantity_communities, &repeated_squaring);
};

int *calculate_communities_floyd_warshall(Graph *graph, int quantity_communities){
    return calculate_communities(graph, quantity_communities, &floyd_warshall);
};

int *calculate_communities_johnson_queue(Graph *graph, int quantity_communities){
    return calculate_communities(graph, quantity_communities, &johnson_queue);
};

int *calculate_communities_johnson_array(Graph *graph, int quantity_communities){
    return calculate_communities(graph, quantity_communities, &johnson_array);
};

int *calculate_communities_nbfs(Graph *graph, int quantity_communities){
    return calculate_communities(graph, quantity_communities, &nbfs);
};

int *calculate_communities(Graph *graph, int quantity_communities, ResultShortestPath *(*func)(Graph *graph)){
    ResultShortestPath *shortest_path_result;
    int **quantity_shortest_path_in_edge;
    int *communities2nodes;
    int numbers_communities;
    Arc *arc;
    do{
        shortest_path_result = (ResultShortestPath *)(*func)(graph);
        quantity_shortest_path_in_edge = calculate_quantity_shortest_path_in_edges(shortest_path_result->predecessor, graph->numbers_nodes);
        communities2nodes = calculate_communities(shortest_path_result->distance, graph->numbers_nodes);
        numbers_communities = get_max_community(communities2nodes, graph->numbers_nodes);
        if(numbers_communities < quantity_communities){
            arc = get_arc_with_bigger_weight(quantity_shortest_path_in_edge, graph->numbers_nodes);
            remove_edge(graph, arc->source, arc->dest);
            printf("Aresta Removida:%d,%d\n", arc->source, arc->dest);
            //calculate_distance_after_remove_edge(graph, shortest_path_result, arc, quantity_shortest_path_in_edge);
            //shortest_path_result = floyd_warshall(graph);
        }
    } while(numbers_communities < quantity_communities);
    return communities2nodes;
};