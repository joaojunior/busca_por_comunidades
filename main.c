#include "main.h" 
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

int *calculate_communities(Graph *graph, int quantity_communities, RepeatedSquaringResult *(*func)(Graph *graph)){
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
            //calculate_distance_after_remove_edge(graph, shortest_path_result, arc, quantity_shortest_path_in_edge);
        }
    } while(numbers_communities < quantity_communities);
    return communities2nodes;
};

int main(int argc, char *argv[]){
    int source, dest;
    int *communities2nodes;
    Graph graph;
    FILE *arq;
    Func v[5] = {calculate_communities_repeated_square, calculate_communities_floyd_warshall, calculate_communities_johnson_queue, 
                calculate_communities_johnson_array, calculate_communities_nbfs};
    graph.numbers_nodes = 12;
    allocate_memory(&graph);
    if(argc == 3){
        arq = fopen(argv[1], "r");
        if(arq == NULL)
                printf("Erro, nao foi possivel abrir o arquivo\n");
        else
            while((fscanf(arq,"%d %d\n", &source, &dest)) !=EOF)
                insert_edge(&graph, source-1, dest-1, 1);
                //printf("%d %d\n", source, dest);
        fclose(arq);
        communities2nodes = v[atoi(argv[2])](&graph, 4);
        for(int i = 0; i < graph.numbers_nodes; i++)
            printf("%d %d\n", i+1, communities2nodes[i]);
    }
    return 0;
}