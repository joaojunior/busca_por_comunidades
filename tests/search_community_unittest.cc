#include "../main.h"
#include "../search_community.h"
#include <gtest/gtest.h>
 
TEST(SearchComunityTest, VerifyQuantityShortestPathInEdgeWithRepeatedSquare){
    Graph graph;
    RepeatedSquaringResult *repeated_squaring_result;
    int **quantity_shortest_path_in_edge;
    graph.numbers_nodes = 5;
    allocate_memory(&graph);
    insert_arc(&graph, 0, 1, 3);
    insert_arc(&graph, 0, 2, 8);
    insert_arc(&graph, 0, 4, -4);
    insert_arc(&graph, 1, 3, 1);
    insert_arc(&graph, 1, 4, 7);
    insert_arc(&graph, 2, 1, 4);
    insert_arc(&graph, 3, 2, -5);
    insert_arc(&graph, 3, 0, 2);
    insert_arc(&graph, 4, 3, 6);
    repeated_squaring_result = repeated_squaring(&graph);
    quantity_shortest_path_in_edge = calculate_quantity_shortest_path_in_edges(repeated_squaring_result->predecessor, graph.numbers_nodes);
    ASSERT_EQ(0,quantity_shortest_path_in_edge[0][0]);
    ASSERT_EQ(0,quantity_shortest_path_in_edge[0][1]);
    ASSERT_EQ(0,quantity_shortest_path_in_edge[0][2]);
    ASSERT_EQ(0,quantity_shortest_path_in_edge[0][3]);
    ASSERT_EQ(7,quantity_shortest_path_in_edge[0][4]);
    ASSERT_EQ(0,quantity_shortest_path_in_edge[1][0]);
    ASSERT_EQ(0,quantity_shortest_path_in_edge[1][1]);
    ASSERT_EQ(0,quantity_shortest_path_in_edge[1][2]);
    ASSERT_EQ(7,quantity_shortest_path_in_edge[1][3]);
    ASSERT_EQ(0,quantity_shortest_path_in_edge[1][4]);
    ASSERT_EQ(0,quantity_shortest_path_in_edge[2][0]);
    ASSERT_EQ(7,quantity_shortest_path_in_edge[2][1]);
    ASSERT_EQ(0,quantity_shortest_path_in_edge[2][2]);
    ASSERT_EQ(0,quantity_shortest_path_in_edge[2][3]);
    ASSERT_EQ(0,quantity_shortest_path_in_edge[2][4]);
    ASSERT_EQ(7,quantity_shortest_path_in_edge[3][0]);
    ASSERT_EQ(0,quantity_shortest_path_in_edge[3][1]);
    ASSERT_EQ(7,quantity_shortest_path_in_edge[3][2]);
    ASSERT_EQ(0,quantity_shortest_path_in_edge[3][3]);
    ASSERT_EQ(0,quantity_shortest_path_in_edge[3][4]);
    ASSERT_EQ(0,quantity_shortest_path_in_edge[4][0]);
    ASSERT_EQ(0,quantity_shortest_path_in_edge[4][1]);
    ASSERT_EQ(0,quantity_shortest_path_in_edge[4][2]);
    ASSERT_EQ(7,quantity_shortest_path_in_edge[4][3]);
    ASSERT_EQ(0,quantity_shortest_path_in_edge[4][4]);
}

TEST(SearchComunityTest, VerifyQuantityShortestPathInEdgeWithRepeatedSquare2){
    Graph graph;
    RepeatedSquaringResult *repeated_squaring_result;
    int **quantity_shortest_path_in_edge;
    graph.numbers_nodes = 4;
    allocate_memory(&graph);
    insert_edge(&graph, 0, 1, 1);
    insert_edge(&graph, 0, 2, 1);
    insert_edge(&graph, 0, 2, 1);
    insert_edge(&graph, 1, 2, 1);
    insert_edge(&graph, 2, 3, 1);
    repeated_squaring_result = repeated_squaring(&graph);
    quantity_shortest_path_in_edge = calculate_quantity_shortest_path_in_edges(repeated_squaring_result->predecessor, graph.numbers_nodes);
    ASSERT_EQ(0,quantity_shortest_path_in_edge[0][0]);
    ASSERT_EQ(1,quantity_shortest_path_in_edge[0][1]);
    ASSERT_EQ(2,quantity_shortest_path_in_edge[0][2]);
    ASSERT_EQ(0,quantity_shortest_path_in_edge[0][3]);
    ASSERT_EQ(1,quantity_shortest_path_in_edge[1][0]);
    ASSERT_EQ(0,quantity_shortest_path_in_edge[1][1]);
    ASSERT_EQ(2,quantity_shortest_path_in_edge[1][2]);
    ASSERT_EQ(0,quantity_shortest_path_in_edge[1][3]);
    ASSERT_EQ(2,quantity_shortest_path_in_edge[2][0]);
    ASSERT_EQ(2,quantity_shortest_path_in_edge[2][1]);
    ASSERT_EQ(0,quantity_shortest_path_in_edge[2][2]);
    ASSERT_EQ(3,quantity_shortest_path_in_edge[2][3]);
    ASSERT_EQ(0,quantity_shortest_path_in_edge[3][0]);
    ASSERT_EQ(0,quantity_shortest_path_in_edge[3][1]);
    ASSERT_EQ(3,quantity_shortest_path_in_edge[3][2]);
    ASSERT_EQ(0,quantity_shortest_path_in_edge[3][3]);
}

TEST(SearchComunityTest, GetArcWithBiggerWeight){
    Graph graph;
    RepeatedSquaringResult *repeated_squaring_result;
    int **quantity_shortest_path_in_edge;
    Arc *arc;
    graph.numbers_nodes = 5;
    allocate_memory(&graph);
    insert_arc(&graph, 0, 1, 3);
    insert_arc(&graph, 0, 2, 8);
    insert_arc(&graph, 0, 4, -4);
    insert_arc(&graph, 1, 3, 1);
    insert_arc(&graph, 1, 4, 7);
    insert_arc(&graph, 2, 1, 4);
    insert_arc(&graph, 3, 2, -5);
    insert_arc(&graph, 3, 0, 2);
    insert_arc(&graph, 4, 3, 6);
    repeated_squaring_result = repeated_squaring(&graph);
    quantity_shortest_path_in_edge = calculate_quantity_shortest_path_in_edges(repeated_squaring_result->predecessor, graph.numbers_nodes);
    arc = get_arc_with_bigger_weight(quantity_shortest_path_in_edge, graph.numbers_nodes);
    ASSERT_EQ(arc->source, 0);
    ASSERT_EQ(arc->dest, 4);    
}

TEST(SearchComunityTest, GetArcWithBiggerWeight2){
    Graph graph;
    RepeatedSquaringResult *repeated_squaring_result;
    int **quantity_shortest_path_in_edge;
    Arc *arc;
    graph.numbers_nodes = 4;
    allocate_memory(&graph);
    insert_edge(&graph, 0, 1, 1);
    insert_edge(&graph, 0, 2, 1);
    insert_edge(&graph, 0, 2, 1);
    insert_edge(&graph, 1, 2, 1);
    insert_edge(&graph, 2, 3, 1);
    repeated_squaring_result = repeated_squaring(&graph);
    quantity_shortest_path_in_edge = calculate_quantity_shortest_path_in_edges(repeated_squaring_result->predecessor, graph.numbers_nodes);
    arc = get_arc_with_bigger_weight(quantity_shortest_path_in_edge, graph.numbers_nodes);
    ASSERT_EQ(arc->source, 2);
    ASSERT_EQ(arc->dest, 3);    
}

TEST(SearchComunityTest, VerifyQuantityShortestPathInEdgeWithRepeatedSquareAfterRemoveEdge){
    Graph graph;
    RepeatedSquaringResult *repeated_squaring_result;
    int **quantity_shortest_path_in_edge;
    Arc *arc;
    graph.numbers_nodes = 4;
    allocate_memory(&graph);
    insert_edge(&graph, 0, 1, 1);
    insert_edge(&graph, 0, 2, 1);
    insert_edge(&graph, 1, 2, 1);
    insert_edge(&graph, 2, 3, 1);
    repeated_squaring_result = repeated_squaring(&graph);
    quantity_shortest_path_in_edge = calculate_quantity_shortest_path_in_edges(repeated_squaring_result->predecessor, graph.numbers_nodes);
    arc = get_arc_with_bigger_weight(quantity_shortest_path_in_edge, graph.numbers_nodes);
    remove_edge(&graph, arc->source, arc->dest);
    repeated_squaring_result = repeated_squaring(&graph);
    quantity_shortest_path_in_edge = calculate_quantity_shortest_path_in_edges(repeated_squaring_result->predecessor, graph.numbers_nodes);
    ASSERT_EQ(0,quantity_shortest_path_in_edge[0][0]);
    ASSERT_EQ(1,quantity_shortest_path_in_edge[0][1]);
    ASSERT_EQ(1,quantity_shortest_path_in_edge[0][2]);
    ASSERT_EQ(0,quantity_shortest_path_in_edge[0][3]);
    ASSERT_EQ(1,quantity_shortest_path_in_edge[1][0]);
    ASSERT_EQ(0,quantity_shortest_path_in_edge[1][1]);
    ASSERT_EQ(1,quantity_shortest_path_in_edge[1][2]);
    ASSERT_EQ(0,quantity_shortest_path_in_edge[1][3]);
    ASSERT_EQ(1,quantity_shortest_path_in_edge[2][0]);
    ASSERT_EQ(1,quantity_shortest_path_in_edge[2][1]);
    ASSERT_EQ(0,quantity_shortest_path_in_edge[2][2]);
    ASSERT_EQ(0,quantity_shortest_path_in_edge[2][3]);
    ASSERT_EQ(0,quantity_shortest_path_in_edge[3][0]);
    ASSERT_EQ(0,quantity_shortest_path_in_edge[3][1]);
    ASSERT_EQ(0,quantity_shortest_path_in_edge[3][2]);
    ASSERT_EQ(0,quantity_shortest_path_in_edge[3][3]);
    arc = get_arc_with_bigger_weight(quantity_shortest_path_in_edge, graph.numbers_nodes);
    ASSERT_EQ(arc->source, 0);
    ASSERT_EQ(arc->dest, 1);
}

TEST(SearchComunityTest, VerifyQuantityShortestPathInEdgeWithRepeatedSquareAfterRemoveArcWithoutShortestPath){
    Graph graph;
    RepeatedSquaringResult *repeated_squaring_result;
    int **quantity_shortest_path_in_edge;
    Arc *arc;
    graph.numbers_nodes = 5;
    allocate_memory(&graph);
    insert_arc(&graph, 0, 1, 3);
    insert_arc(&graph, 0, 2, 8);
    insert_arc(&graph, 0, 4, -4);
    insert_arc(&graph, 1, 3, 1);
    insert_arc(&graph, 1, 4, 7);
    insert_arc(&graph, 2, 1, 4);
    insert_arc(&graph, 3, 2, -5);
    insert_arc(&graph, 3, 0, 2);
    insert_arc(&graph, 4, 3, 6);
    remove_arc(&graph, 0, 2);
    repeated_squaring_result = repeated_squaring(&graph);
    quantity_shortest_path_in_edge = calculate_quantity_shortest_path_in_edges(repeated_squaring_result->predecessor, graph.numbers_nodes);
    ASSERT_EQ(0,quantity_shortest_path_in_edge[0][0]);
    ASSERT_EQ(0,quantity_shortest_path_in_edge[0][1]);
    ASSERT_EQ(0,quantity_shortest_path_in_edge[0][2]);
    ASSERT_EQ(0,quantity_shortest_path_in_edge[0][3]);
    ASSERT_EQ(7,quantity_shortest_path_in_edge[0][4]);
    ASSERT_EQ(0,quantity_shortest_path_in_edge[1][0]);
    ASSERT_EQ(0,quantity_shortest_path_in_edge[1][1]);
    ASSERT_EQ(0,quantity_shortest_path_in_edge[1][2]);
    ASSERT_EQ(7,quantity_shortest_path_in_edge[1][3]);
    ASSERT_EQ(0,quantity_shortest_path_in_edge[1][4]);
    ASSERT_EQ(0,quantity_shortest_path_in_edge[2][0]);
    ASSERT_EQ(7,quantity_shortest_path_in_edge[2][1]);
    ASSERT_EQ(0,quantity_shortest_path_in_edge[2][2]);
    ASSERT_EQ(0,quantity_shortest_path_in_edge[2][3]);
    ASSERT_EQ(0,quantity_shortest_path_in_edge[2][4]);
    ASSERT_EQ(7,quantity_shortest_path_in_edge[3][0]);
    ASSERT_EQ(0,quantity_shortest_path_in_edge[3][1]);
    ASSERT_EQ(7,quantity_shortest_path_in_edge[3][2]);
    ASSERT_EQ(0,quantity_shortest_path_in_edge[3][3]);
    ASSERT_EQ(0,quantity_shortest_path_in_edge[3][4]);
    ASSERT_EQ(0,quantity_shortest_path_in_edge[4][0]);
    ASSERT_EQ(0,quantity_shortest_path_in_edge[4][1]);
    ASSERT_EQ(0,quantity_shortest_path_in_edge[4][2]);
    ASSERT_EQ(7,quantity_shortest_path_in_edge[4][3]);
    ASSERT_EQ(0,quantity_shortest_path_in_edge[4][4]);
    arc = get_arc_with_bigger_weight(quantity_shortest_path_in_edge, graph.numbers_nodes);
    ASSERT_EQ(arc->source, 0);
    ASSERT_EQ(arc->dest, 4);
}

TEST(SearchComunityTest, VerifyQuantityShortestPathInEdgeWithRepeatedSquareAfterRemoveArcWithShortestPath){
    Graph graph;
    RepeatedSquaringResult *repeated_squaring_result;
    int **quantity_shortest_path_in_edge;
    Arc *arc;
    graph.numbers_nodes = 5;
    allocate_memory(&graph);
    insert_arc(&graph, 0, 1, 3);
    insert_arc(&graph, 0, 2, 8);
    insert_arc(&graph, 0, 4, -4);
    insert_arc(&graph, 1, 3, 1);
    insert_arc(&graph, 1, 4, 7);
    insert_arc(&graph, 2, 1, 4);
    insert_arc(&graph, 3, 2, -5);
    insert_arc(&graph, 3, 0, 2);
    insert_arc(&graph, 4, 3, 6);
    remove_arc(&graph, 2, 1);
    repeated_squaring_result = repeated_squaring(&graph);
    quantity_shortest_path_in_edge = calculate_quantity_shortest_path_in_edges(repeated_squaring_result->predecessor, graph.numbers_nodes);
    ASSERT_EQ(0,quantity_shortest_path_in_edge[0][0]);
    ASSERT_EQ(3,quantity_shortest_path_in_edge[0][1]);
    ASSERT_EQ(0,quantity_shortest_path_in_edge[0][2]);
    ASSERT_EQ(0,quantity_shortest_path_in_edge[0][3]);
    ASSERT_EQ(5,quantity_shortest_path_in_edge[0][4]);
    ASSERT_EQ(0,quantity_shortest_path_in_edge[1][0]);
    ASSERT_EQ(0,quantity_shortest_path_in_edge[1][1]);
    ASSERT_EQ(0,quantity_shortest_path_in_edge[1][2]);
    ASSERT_EQ(4,quantity_shortest_path_in_edge[1][3]);
    ASSERT_EQ(0,quantity_shortest_path_in_edge[1][4]);
    ASSERT_EQ(0,quantity_shortest_path_in_edge[2][0]);
    ASSERT_EQ(0,quantity_shortest_path_in_edge[2][1]);
    ASSERT_EQ(0,quantity_shortest_path_in_edge[2][2]);
    ASSERT_EQ(0,quantity_shortest_path_in_edge[2][3]);
    ASSERT_EQ(0,quantity_shortest_path_in_edge[2][4]);
    ASSERT_EQ(7,quantity_shortest_path_in_edge[3][0]);
    ASSERT_EQ(0,quantity_shortest_path_in_edge[3][1]);
    ASSERT_EQ(4,quantity_shortest_path_in_edge[3][2]);
    ASSERT_EQ(0,quantity_shortest_path_in_edge[3][3]);
    ASSERT_EQ(0,quantity_shortest_path_in_edge[3][4]);
    ASSERT_EQ(0,quantity_shortest_path_in_edge[4][0]);
    ASSERT_EQ(0,quantity_shortest_path_in_edge[4][1]);
    ASSERT_EQ(0,quantity_shortest_path_in_edge[4][2]);
    ASSERT_EQ(6,quantity_shortest_path_in_edge[4][3]);
    ASSERT_EQ(0,quantity_shortest_path_in_edge[4][4]);
    arc = get_arc_with_bigger_weight(quantity_shortest_path_in_edge, graph.numbers_nodes);
    ASSERT_EQ(arc->source, 3);
    ASSERT_EQ(arc->dest, 0);
}

TEST(SearchComunityTest, CalculateCommunities){
    Graph graph;
    RepeatedSquaringResult *repeated_squaring_result;
    int **quantity_shortest_path_in_edge;
    int *communities2nodes;
    graph.numbers_nodes = 4;
    allocate_memory(&graph);
    insert_edge(&graph, 0, 1, 1);
    insert_edge(&graph, 0, 2, 1);
    insert_edge(&graph, 1, 2, 1);
    insert_edge(&graph, 2, 3, 1);
    repeated_squaring_result = repeated_squaring(&graph);
    quantity_shortest_path_in_edge = calculate_quantity_shortest_path_in_edges(repeated_squaring_result->predecessor, graph.numbers_nodes);
    communities2nodes = calculate_communities(repeated_squaring_result->distance, graph.numbers_nodes);
    ASSERT_EQ(1, communities2nodes[0]);
    ASSERT_EQ(1, communities2nodes[1]);
    ASSERT_EQ(1, communities2nodes[2]);
    ASSERT_EQ(1, communities2nodes[3]);
    ASSERT_EQ(1, get_max_community(communities2nodes, graph.numbers_nodes));
}

TEST(SearchComunityTest, CalculateCommunitiesWithGraphNotConnected){
    Graph graph;
    RepeatedSquaringResult *repeated_squaring_result;
    int **quantity_shortest_path_in_edge;
    int *communities2nodes;
    graph.numbers_nodes = 4;
    allocate_memory(&graph);
    insert_edge(&graph, 0, 1, 1);
    insert_edge(&graph, 0, 2, 1);
    insert_edge(&graph, 1, 2, 1);
    repeated_squaring_result = repeated_squaring(&graph);
    quantity_shortest_path_in_edge = calculate_quantity_shortest_path_in_edges(repeated_squaring_result->predecessor, graph.numbers_nodes);
    communities2nodes = calculate_communities(repeated_squaring_result->distance, graph.numbers_nodes);
    ASSERT_EQ(1, communities2nodes[0]);
    ASSERT_EQ(1, communities2nodes[1]);
    ASSERT_EQ(1, communities2nodes[2]);
    ASSERT_EQ(2, communities2nodes[3]);
    ASSERT_EQ(2, get_max_community(communities2nodes, graph.numbers_nodes));
}

TEST(SearchComunityTest, CalculateCommunitiesWithRepeatedSquareWith1Community){
    Graph graph;
    int *communities2nodes;
    graph.numbers_nodes = 4;
    allocate_memory(&graph);
    insert_edge(&graph, 0, 1, 1);
    insert_edge(&graph, 0, 2, 1);
    insert_edge(&graph, 1, 2, 1);
    insert_edge(&graph, 2, 3, 1);
    communities2nodes = calculate_communities_repeated_square(&graph, 1);
    ASSERT_EQ(1, communities2nodes[0]);
    ASSERT_EQ(1, communities2nodes[1]);
    ASSERT_EQ(1, communities2nodes[2]);
    ASSERT_EQ(1, communities2nodes[3]);
}

TEST(SearchComunityTest, CalculateCommunitiesWithRepeatedSquareWith2Communities){
    Graph graph;
    int *communities2nodes;
    graph.numbers_nodes = 4;
    allocate_memory(&graph);
    insert_edge(&graph, 0, 1, 1);
    insert_edge(&graph, 0, 2, 1);
    insert_edge(&graph, 1, 2, 1);
    insert_edge(&graph, 2, 3, 1);
    communities2nodes = calculate_communities_repeated_square(&graph, 2);
    ASSERT_EQ(1, communities2nodes[0]);
    ASSERT_EQ(1, communities2nodes[1]);
    ASSERT_EQ(1, communities2nodes[2]);
    ASSERT_EQ(2, communities2nodes[3]);
}

TEST(SearchComunityTest, CalculateCommunitiesWithRepeatedSquareWith3Communities){
    Graph graph;
    int *communities2nodes;
    graph.numbers_nodes = 4;
    allocate_memory(&graph);
    insert_edge(&graph, 0, 1, 1);
    insert_edge(&graph, 0, 2, 1);
    insert_edge(&graph, 1, 2, 1);
    insert_edge(&graph, 2, 3, 1);
    communities2nodes = calculate_communities_repeated_square(&graph, 3);
    ASSERT_EQ(1, communities2nodes[0]);
    ASSERT_EQ(2, communities2nodes[1]);
    ASSERT_EQ(2, communities2nodes[2]);
    ASSERT_EQ(3, communities2nodes[3]);
}

TEST(SearchComunityTest, CalculateCommunitiesWithRepeatedSquareWith4Communities){
    Graph graph;
    int *communities2nodes;
    graph.numbers_nodes = 4;
    allocate_memory(&graph);
    insert_edge(&graph, 0, 1, 1);
    insert_edge(&graph, 0, 2, 1);
    insert_edge(&graph, 1, 2, 1);
    insert_edge(&graph, 2, 3, 1);
    communities2nodes = calculate_communities_repeated_square(&graph, 4);
    ASSERT_EQ(1, communities2nodes[0]);
    ASSERT_EQ(2, communities2nodes[1]);
    ASSERT_EQ(3, communities2nodes[2]);
    ASSERT_EQ(4, communities2nodes[3]);
}

TEST(SearchComunityTest, CalculeDistanceAfterRemove1Edge){
    Graph graph;
    RepeatedSquaringResult *repeated_squaring_result;
    int **quantity_shortest_path_in_edge;
    Arc *arc;
    graph.numbers_nodes = 4;
    allocate_memory(&graph);
    insert_edge(&graph, 0, 1, 1);
    insert_edge(&graph, 0, 2, 1);
    insert_edge(&graph, 1, 2, 1);
    insert_edge(&graph, 2, 3, 1);
    repeated_squaring_result = repeated_squaring(&graph);
    quantity_shortest_path_in_edge = calculate_quantity_shortest_path_in_edges(repeated_squaring_result->predecessor, graph.numbers_nodes);
    arc = get_arc_with_bigger_weight(quantity_shortest_path_in_edge, graph.numbers_nodes);
    arc->source = 0;
    arc->dest = 2;
    remove_edge(&graph, arc->source, arc->dest);
    calculate_distance_after_remove_edge(&graph, repeated_squaring_result, arc, quantity_shortest_path_in_edge);
    ASSERT_EQ(0,repeated_squaring_result->distance[0][0]);
    ASSERT_EQ(1,repeated_squaring_result->distance[0][1]);
    ASSERT_EQ(2,repeated_squaring_result->distance[0][2]);
    ASSERT_EQ(3,repeated_squaring_result->distance[0][3]);
    ASSERT_EQ(1,repeated_squaring_result->distance[1][0]);
    ASSERT_EQ(0,repeated_squaring_result->distance[1][1]);
    ASSERT_EQ(1,repeated_squaring_result->distance[1][2]);
    ASSERT_EQ(2,repeated_squaring_result->distance[1][3]);
    ASSERT_EQ(2,repeated_squaring_result->distance[2][0]);
    ASSERT_EQ(1,repeated_squaring_result->distance[2][1]);
    ASSERT_EQ(0,repeated_squaring_result->distance[2][2]);
    ASSERT_EQ(1,repeated_squaring_result->distance[2][3]);
    ASSERT_EQ(3,repeated_squaring_result->distance[3][0]);
    ASSERT_EQ(2,repeated_squaring_result->distance[3][1]);
    ASSERT_EQ(1,repeated_squaring_result->distance[3][2]);
    ASSERT_EQ(0,repeated_squaring_result->distance[3][3]);
    ASSERT_EQ(PREDECESSOR_NULL,repeated_squaring_result->predecessor[0][0]);
    ASSERT_EQ(0,repeated_squaring_result->predecessor[0][1]);
    ASSERT_EQ(1,repeated_squaring_result->predecessor[0][2]);
    ASSERT_EQ(2,repeated_squaring_result->predecessor[0][3]);
    ASSERT_EQ(1,repeated_squaring_result->predecessor[1][0]);
    ASSERT_EQ(PREDECESSOR_NULL,repeated_squaring_result->predecessor[1][1]);
    ASSERT_EQ(1,repeated_squaring_result->predecessor[1][2]);
    ASSERT_EQ(2,repeated_squaring_result->predecessor[1][3]);
    ASSERT_EQ(1,repeated_squaring_result->predecessor[2][0]);
    ASSERT_EQ(2,repeated_squaring_result->predecessor[2][1]);
    ASSERT_EQ(PREDECESSOR_NULL,repeated_squaring_result->predecessor[2][2]);
    ASSERT_EQ(2,repeated_squaring_result->predecessor[2][3]);
    ASSERT_EQ(2,repeated_squaring_result->predecessor[3][0]);
    ASSERT_EQ(2,repeated_squaring_result->predecessor[3][1]);
    ASSERT_EQ(3,repeated_squaring_result->predecessor[3][2]);
    ASSERT_EQ(PREDECESSOR_NULL,repeated_squaring_result->predecessor[3][3]);
    ASSERT_EQ(0,quantity_shortest_path_in_edge[0][0]);
    ASSERT_EQ(3,quantity_shortest_path_in_edge[0][1]);
    ASSERT_EQ(0,quantity_shortest_path_in_edge[0][2]);
    ASSERT_EQ(0,quantity_shortest_path_in_edge[0][3]);
    ASSERT_EQ(3,quantity_shortest_path_in_edge[1][0]);
    ASSERT_EQ(0,quantity_shortest_path_in_edge[1][1]);
    ASSERT_EQ(4,quantity_shortest_path_in_edge[1][2]);
    ASSERT_EQ(0,quantity_shortest_path_in_edge[1][3]);
    ASSERT_EQ(0,quantity_shortest_path_in_edge[2][0]);
    ASSERT_EQ(4,quantity_shortest_path_in_edge[2][1]);
    ASSERT_EQ(0,quantity_shortest_path_in_edge[2][2]);
    ASSERT_EQ(3,quantity_shortest_path_in_edge[2][3]);
    ASSERT_EQ(0,quantity_shortest_path_in_edge[3][0]);
    ASSERT_EQ(0,quantity_shortest_path_in_edge[3][1]);
    ASSERT_EQ(3,quantity_shortest_path_in_edge[3][2]);
    ASSERT_EQ(0,quantity_shortest_path_in_edge[3][3]);
    arc = get_arc_with_bigger_weight(quantity_shortest_path_in_edge, graph.numbers_nodes);
    ASSERT_EQ(arc->source, 1);
    ASSERT_EQ(arc->dest, 2);
}

TEST(SearchComunityTest, CalculeDistanceAfterRemoveEdgeWithBiggerWeight){
    Graph graph;
    RepeatedSquaringResult *repeated_squaring_result;
    int **quantity_shortest_path_in_edge;
    Arc *arc;
    graph.numbers_nodes = 4;
    allocate_memory(&graph);
    insert_edge(&graph, 0, 1, 1);
    insert_edge(&graph, 0, 2, 1);
    insert_edge(&graph, 1, 2, 1);
    insert_edge(&graph, 2, 3, 1);
    repeated_squaring_result = repeated_squaring(&graph);
    quantity_shortest_path_in_edge = calculate_quantity_shortest_path_in_edges(repeated_squaring_result->predecessor, graph.numbers_nodes);
    arc = get_arc_with_bigger_weight(quantity_shortest_path_in_edge, graph.numbers_nodes);
    remove_edge(&graph, arc->source, arc->dest);
    calculate_distance_after_remove_edge(&graph, repeated_squaring_result, arc, quantity_shortest_path_in_edge);
    ASSERT_EQ(0,repeated_squaring_result->distance[0][0]);
    ASSERT_EQ(1,repeated_squaring_result->distance[0][1]);
    ASSERT_EQ(1,repeated_squaring_result->distance[0][2]);
    ASSERT_EQ(MAX_WEIGHT,repeated_squaring_result->distance[0][3]);
    ASSERT_EQ(1,repeated_squaring_result->distance[1][0]);
    ASSERT_EQ(0,repeated_squaring_result->distance[1][1]);
    ASSERT_EQ(1,repeated_squaring_result->distance[1][2]);
    ASSERT_EQ(MAX_WEIGHT,repeated_squaring_result->distance[1][3]);
    ASSERT_EQ(1,repeated_squaring_result->distance[2][0]);
    ASSERT_EQ(1,repeated_squaring_result->distance[2][1]);
    ASSERT_EQ(0,repeated_squaring_result->distance[2][2]);
    ASSERT_EQ(MAX_WEIGHT,repeated_squaring_result->distance[2][3]);
    ASSERT_EQ(MAX_WEIGHT,repeated_squaring_result->distance[3][0]);
    ASSERT_EQ(MAX_WEIGHT,repeated_squaring_result->distance[3][1]);
    ASSERT_EQ(MAX_WEIGHT,repeated_squaring_result->distance[3][2]);
    ASSERT_EQ(0,repeated_squaring_result->distance[3][3]);
    ASSERT_EQ(PREDECESSOR_NULL,repeated_squaring_result->predecessor[0][0]);
    ASSERT_EQ(0,repeated_squaring_result->predecessor[0][1]);
    ASSERT_EQ(0,repeated_squaring_result->predecessor[0][2]);
    ASSERT_EQ(PREDECESSOR_NULL,repeated_squaring_result->predecessor[0][3]);
    ASSERT_EQ(1,repeated_squaring_result->predecessor[1][0]);
    ASSERT_EQ(PREDECESSOR_NULL,repeated_squaring_result->predecessor[1][1]);
    ASSERT_EQ(1,repeated_squaring_result->predecessor[1][2]);
    ASSERT_EQ(PREDECESSOR_NULL,repeated_squaring_result->predecessor[1][3]);
    ASSERT_EQ(2,repeated_squaring_result->predecessor[2][0]);
    ASSERT_EQ(2,repeated_squaring_result->predecessor[2][1]);
    ASSERT_EQ(PREDECESSOR_NULL,repeated_squaring_result->predecessor[2][2]);
    ASSERT_EQ(PREDECESSOR_NULL,repeated_squaring_result->predecessor[2][3]);
    ASSERT_EQ(PREDECESSOR_NULL,repeated_squaring_result->predecessor[3][0]);
    ASSERT_EQ(PREDECESSOR_NULL,repeated_squaring_result->predecessor[3][1]);
    ASSERT_EQ(PREDECESSOR_NULL,repeated_squaring_result->predecessor[3][2]);
    ASSERT_EQ(PREDECESSOR_NULL,repeated_squaring_result->predecessor[3][3]);
    ASSERT_EQ(0,quantity_shortest_path_in_edge[0][0]);
    ASSERT_EQ(1,quantity_shortest_path_in_edge[0][1]);
    ASSERT_EQ(1,quantity_shortest_path_in_edge[0][2]);
    ASSERT_EQ(0,quantity_shortest_path_in_edge[0][3]);
    ASSERT_EQ(1,quantity_shortest_path_in_edge[1][0]);
    ASSERT_EQ(0,quantity_shortest_path_in_edge[1][1]);
    ASSERT_EQ(1,quantity_shortest_path_in_edge[1][2]);
    ASSERT_EQ(0,quantity_shortest_path_in_edge[1][3]);
    ASSERT_EQ(1,quantity_shortest_path_in_edge[2][0]);
    ASSERT_EQ(1,quantity_shortest_path_in_edge[2][1]);
    ASSERT_EQ(0,quantity_shortest_path_in_edge[2][2]);
    ASSERT_EQ(0,quantity_shortest_path_in_edge[2][3]);
    ASSERT_EQ(0,quantity_shortest_path_in_edge[3][0]);
    ASSERT_EQ(0,quantity_shortest_path_in_edge[3][1]);
    ASSERT_EQ(0,quantity_shortest_path_in_edge[3][2]);
    ASSERT_EQ(0,quantity_shortest_path_in_edge[3][3]);
    arc = get_arc_with_bigger_weight(quantity_shortest_path_in_edge, graph.numbers_nodes);
    ASSERT_EQ(arc->source, 0);
    ASSERT_EQ(arc->dest, 1);
}

TEST(SearchComunityTest1, GetShortestPath){
    Graph graph;
    ResultShortestPath *result;
    Queue *path;
    graph.numbers_nodes = 8;
    allocate_memory(&graph);
    insert_edge(&graph, 0, 1, 1);
    insert_edge(&graph, 1, 2, 1);
    insert_edge(&graph, 2, 3, 1);
    insert_edge(&graph, 2, 6, 1);
    insert_edge(&graph, 3, 4, 1);
    insert_edge(&graph, 3, 7, 1);
    insert_edge(&graph, 4, 5, 1);
    insert_edge(&graph, 6, 7, 1);
    result = repeated_squaring(&graph);
    //printf("aqui%d", result->predecessor[0][5]);
    path = get_shortest_path(result->predecessor, 0, 5);
    ASSERT_EQ(0,dequeue(path));
    ASSERT_EQ(1,dequeue(path));
    ASSERT_EQ(2,dequeue(path));
    ASSERT_EQ(3,dequeue(path));
    ASSERT_EQ(4,dequeue(path));
    ASSERT_EQ(5,dequeue(path));
}

TEST(SearchComunityTest2, GetNodesBeforeIInclusiveInShortestPath){
    Graph graph;
    ResultShortestPath *result;
    Queue *path, *nodes_before_i;
    graph.numbers_nodes = 8;
    allocate_memory(&graph);
    insert_edge(&graph, 0, 1, 1);
    insert_edge(&graph, 1, 2, 1);
    insert_edge(&graph, 2, 3, 1);
    insert_edge(&graph, 2, 6, 1);
    insert_edge(&graph, 3, 4, 1);
    insert_edge(&graph, 3, 7, 1);
    insert_edge(&graph, 4, 5, 1);
    insert_edge(&graph, 6, 7, 1);
    result = repeated_squaring(&graph);
    path = get_shortest_path(result->predecessor, 0, 5);
    nodes_before_i = get_nodes_before_node_i_inclusive_in_shortest_path(path, 2);
    ASSERT_EQ(0,dequeue(nodes_before_i));
    ASSERT_EQ(1,dequeue(nodes_before_i));
    ASSERT_EQ(2,dequeue(nodes_before_i));
}

TEST(SearchComunityTest3, GetNodesBetweenInclusiveInShortestPath){
    Graph graph;
    ResultShortestPath *result;
    Queue *path, *nodes_before_i, *nodes_between;
    graph.numbers_nodes = 8;
    allocate_memory(&graph);
    insert_edge(&graph, 0, 1, 1);
    insert_edge(&graph, 1, 2, 1);
    insert_edge(&graph, 2, 3, 10);
    insert_edge(&graph, 2, 6, 1);
    insert_edge(&graph, 3, 4, 1);
    insert_edge(&graph, 3, 7, 1);
    insert_edge(&graph, 4, 5, 1);
    insert_edge(&graph, 6, 7, 1);
    result = repeated_squaring(&graph);
    path = get_shortest_path(result->predecessor, 0, 5);
    nodes_before_i = get_nodes_before_node_i_inclusive_in_shortest_path(path, 2);
    nodes_between = get_nodes_between_nodes_inclusive_in_shortest_path(path, 2, 3);
    ASSERT_EQ(2,dequeue(nodes_between));
    ASSERT_EQ(6,dequeue(nodes_between));
    ASSERT_EQ(7,dequeue(nodes_between));
    ASSERT_EQ(3,dequeue(nodes_between));
}

TEST(SearchComunityTest4, GetNodesAfterIInclusiveInShortestPath){
    Graph graph;
    ResultShortestPath *result;
    Queue *path, *nodes_before_i, *nodes_between, *nodes_after_i;
    graph.numbers_nodes = 8;
    allocate_memory(&graph);
    insert_edge(&graph, 0, 1, 1);
    insert_edge(&graph, 1, 2, 1);
    insert_edge(&graph, 2, 3, 1);
    insert_edge(&graph, 2, 6, 1);
    insert_edge(&graph, 3, 4, 1);
    insert_edge(&graph, 3, 7, 1);
    insert_edge(&graph, 4, 5, 1);
    insert_edge(&graph, 6, 7, 1);
    result = repeated_squaring(&graph);
    path = get_shortest_path(result->predecessor, 0, 5);
    nodes_before_i = get_nodes_before_node_i_inclusive_in_shortest_path(path, 2);
    nodes_between = get_nodes_between_nodes_inclusive_in_shortest_path(path, 2, 3);
    nodes_after_i = get_nodes_after_node_i_inclusive_in_shortest_path(path, 3);
    ASSERT_EQ(3,dequeue(nodes_after_i));
    ASSERT_EQ(4,dequeue(nodes_after_i));
    ASSERT_EQ(5,dequeue(nodes_after_i));
}

TEST(SearchComunityTest, PathUseArc){
    Graph graph;
    ResultShortestPath *result;
    Queue *path, *nodes_before_i, *nodes_between, *nodes_after_i;
    graph.numbers_nodes = 8;
    allocate_memory(&graph);
    insert_edge(&graph, 0, 1, 1);
    insert_edge(&graph, 1, 2, 1);
    insert_edge(&graph, 2, 3, 1);
    insert_edge(&graph, 2, 6, 1);
    insert_edge(&graph, 3, 4, 1);
    insert_edge(&graph, 3, 7, 1);
    insert_edge(&graph, 4, 5, 1);
    insert_edge(&graph, 6, 7, 1);
    result = repeated_squaring(&graph);
    path = get_shortest_path(result->predecessor, 0, 5);
    ASSERT_EQ(true,path_use_arc(path, 0, 1));
    ASSERT_EQ(true,path_use_arc(path, 1, 2));
    ASSERT_EQ(true,path_use_arc(path, 2, 3));
    ASSERT_EQ(true,path_use_arc(path, 3, 4));
    ASSERT_EQ(true,path_use_arc(path, 4, 5));
    ASSERT_EQ(false,path_use_arc(path, 2, 6));
    ASSERT_EQ(false,path_use_arc(path, 3, 7));
    ASSERT_EQ(false,path_use_arc(path, 6, 7));
}


int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}