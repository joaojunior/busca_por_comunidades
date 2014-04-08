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

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}