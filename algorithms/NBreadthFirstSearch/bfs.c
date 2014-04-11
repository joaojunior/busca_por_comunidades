#include "bfs.h"
BFSResult *bfs(Graph *graph, int source){
    BFSResult *bfs_result;
    int *colors;
    Queue nodes;
    int node_id;
    enqueue(&nodes, source);
    bfs_result = (BFSResult *)malloc(sizeof(BFSResult));
    bfs_result->distance = (int *)malloc(graph->numbers_nodes * sizeof(int));
    colors = (int *)malloc(graph->numbers_nodes * sizeof(int));
    bfs_result->predecessor = (int *)malloc(graph->numbers_nodes * sizeof(int));
    for(int i = 0; i < graph->numbers_nodes; i++){
        colors[i] = WHITE;
        bfs_result->distance[i] = MAX_WEIGHT;
        bfs_result->predecessor[i] = PREDECESSOR_NULL;
    };
    bfs_result->distance[source] = 0;
    colors[source] = GRAY;
    while(!empty(&nodes)){
        node_id = dequeue(&nodes);
        for(int i = 0; i < graph->numbers_nodes; i++){
            if(exist_arc(graph, node_id, i) and colors[i] == WHITE){
                enqueue(&nodes, i);
                bfs_result->distance[i] = bfs_result->distance[node_id] + 1;
                colors[i] = GRAY;
                bfs_result->predecessor[i] = node_id;
            }
        };
        colors[node_id] = BLACK;
    };
    return bfs_result;
}; 

NBFSResult *nbfs(Graph *graph){
    BFSResult *result_bfs;
    NBFSResult *result_nbfs;
    result_nbfs = (NBFSResult *)malloc(sizeof(NBFSResult));
    result_nbfs->distance = (int **)malloc(graph->numbers_nodes * sizeof(int *));
    result_nbfs->predecessor = (int **)malloc(graph->numbers_nodes * sizeof(int *));
    for(int i = 0; i < graph->numbers_nodes; i++){
        result_nbfs->distance[i] = (int *)malloc(graph->numbers_nodes * sizeof(int));
        result_nbfs->predecessor[i] = (int *)malloc(graph->numbers_nodes * sizeof(int));
        for(int j = 0; j < graph->numbers_nodes; j++)
            result_nbfs->predecessor[i][j] = PREDECESSOR_NULL;
    }
    for(int i = 0; i < graph->numbers_nodes; i++){
        result_bfs = bfs(graph, i);
        for(int j = 0; j < graph->numbers_nodes; j++){
            result_nbfs->distance[i][j] = result_bfs->distance[j];
            result_nbfs->predecessor[i][j] = result_bfs->predecessor[j];
        }
    }
    return result_nbfs;
};