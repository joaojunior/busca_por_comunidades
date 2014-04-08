#include "main.h" 
int *calculate_communities_repeated_square(Graph *graph, int quantity_communities){
    RepeatedSquaringResult *repeated_squaring_result;
    int **quantity_shortest_path_in_edge;
    int *communities2nodes;
    int numbers_communities;
    Arc *arc;
    do{
        repeated_squaring_result = repeated_squaring(graph);
        quantity_shortest_path_in_edge = calculate_quantity_shortest_path_in_edges(repeated_squaring_result->predecessor, graph->numbers_nodes);
        communities2nodes = calculate_communities(repeated_squaring_result->distance, graph->numbers_nodes);
        numbers_communities = get_max_community(communities2nodes, graph->numbers_nodes);
        if(numbers_communities < quantity_communities){
            arc = get_arc_with_bigger_weight(quantity_shortest_path_in_edge, graph->numbers_nodes);
            remove_edge(graph, arc->source, arc->dest);
        }
    } while(numbers_communities < quantity_communities);
    return communities2nodes;
};
