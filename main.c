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
            printf("Aresta Removida:%d,%d\n", arc->source, arc->dest);
            //calculate_distance_after_remove_edge(graph, shortest_path_result, arc, quantity_shortest_path_in_edge);
        }
    } while(numbers_communities < quantity_communities);
    return communities2nodes;
};

int main(int argc, char *argv[]){
    int source, dest, min_node, max_node;
    int *communities2nodes;
    int method, quantity_communities;
    Queue nodes;
    Graph graph;
    FILE *arq;
    min_node = MAX_WEIGHT;
    max_node = -1;
    if(argc == 4){
        arq = fopen(argv[1], "r");
        if(arq == NULL)
                printf("Erro, nao foi possivel abrir o arquivo\n");
        else
            while((fscanf(arq,"%d %d\n", &source, &dest)) !=EOF){
                if(source < min_node)
                    min_node = source;
                if(dest < min_node)
                    min_node = dest;
                if(source > max_node)
                    max_node = source;
                if(dest > max_node)
                    max_node = dest;
                enqueue(&nodes, source);
                enqueue(&nodes, dest);
            }
                //printf("%d %d\n", source, dest);
        fclose(arq);
        graph.numbers_nodes = max_node - min_node + 1;
        allocate_memory(&graph);
        while(not empty(&nodes)){
            source = dequeue(&nodes);
            dest = dequeue(&nodes);
            insert_edge(&graph, source - min_node, dest - min_node, 1);
        }
        method = atoi(argv[3]);
        quantity_communities = atoi(argv[2]);
        switch(method){
            case 0:
                communities2nodes = calculate_communities_repeated_square(&graph, quantity_communities);
                break;
            case 1:
                communities2nodes = calculate_communities_floyd_warshall(&graph, quantity_communities);
                break;
            case 2:
                communities2nodes = calculate_communities_johnson_queue(&graph, quantity_communities);
                break;
            case 3:
                communities2nodes = calculate_communities_johnson_array(&graph, quantity_communities);
                break;
            case 4:
                communities2nodes = calculate_communities_nbfs(&graph, quantity_communities);
                break;
            default:
                printf("Metodo Invalido");
                return 0;
        };
        for(int i = 0; i < graph.numbers_nodes; i++)
            printf("%d %d\n", i + min_node, communities2nodes[i]);
    }
    return 0;
}