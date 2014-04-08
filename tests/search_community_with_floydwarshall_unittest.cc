//#include "../main.h"
#include "../search_community.h"
#include "../algorithms/FloydWarsHall/floyd_warshall.h"
#include <gtest/gtest.h>
 
TEST(SearchComunityTest, VerifyQuantityShortestPathInEdgeWithFloydWarshall){
    Graph graph;
    ResultFloydWarshall *floyd_warshall_result;
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
    floyd_warshall_result = floyd_warshall(&graph);
    quantity_shortest_path_in_edge = calculate_quantity_shortest_path_in_edges(floyd_warshall_result->predecessor, graph.numbers_nodes);
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

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}