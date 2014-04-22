#include "main.h" 

int main(int argc, char *argv[]){
    int source, dest, min_node, max_node;
    int *communities2nodes;
    int method, quantity_communities;
    Queue nodes;
    Graph graph;
    FILE *arq;
    min_node = MAX_WEIGHT;
    max_node = -1;
    if(argc >= 3){
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
        fclose(arq);
        graph.numbers_nodes = max_node - min_node + 1;
        allocate_memory(&graph);
        while(not empty(&nodes)){
            source = dequeue(&nodes);
            dest = dequeue(&nodes);
            insert_edge(&graph, source - min_node, dest - min_node, 1);
        }
        quantity_communities = atoi(argv[2]);
        if(argc < 4){
            communities2nodes = calculate_communities_repeated_square(&graph, quantity_communities);
            imprime(communities2nodes, graph.numbers_nodes, min_node);
            communities2nodes = calculate_communities_floyd_warshall(&graph, quantity_communities);
            imprime(communities2nodes, graph.numbers_nodes, min_node);
            communities2nodes = calculate_communities_johnson_queue(&graph, quantity_communities);
            imprime(communities2nodes, graph.numbers_nodes, min_node);
            communities2nodes = calculate_communities_johnson_array(&graph, quantity_communities);
            imprime(communities2nodes, graph.numbers_nodes, min_node);
            communities2nodes = calculate_communities_nbfs(&graph, quantity_communities);
            imprime(communities2nodes, graph.numbers_nodes, min_node);
        } else{
            method = atoi(argv[3]);
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
        }
        imprime(communities2nodes, graph.numbers_nodes, min_node);
    }
    return 0;
}

void imprime(int *communities2nodes, int numbers_nodes, int min_node){
    int numbers_communities;
    numbers_communities = get_max_community(communities2nodes, numbers_nodes);
    for(int community = 1; community <= numbers_communities; community++)
        for(int i = 0; i < numbers_nodes; i++)
            if(communities2nodes[i] == community)
                printf("%d %d\n", i + min_node, communities2nodes[i]);
};