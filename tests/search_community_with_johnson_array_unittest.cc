#include "../main.h"
#include "../search_community.h"
#include "../algorithms/JohnsonArray/johnson.h"
#include <gtest/gtest.h>
 
TEST(SearchComunityTest, VerifyQuantityShortestPathInEdgeWithJohnsonArray){
    Graph graph;
    JohnsonResult *johnson_result;
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
    johnson_result = johnson_array(&graph);
    quantity_shortest_path_in_edge = calculate_quantity_shortest_path_in_edges(johnson_result->predecessor, graph.numbers_nodes);
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

TEST(SearchComunityTest, VerifyQuantityShortestPathInEdgeWithJohnsonArray2){
    Graph graph;
    JohnsonResult *johnson_result;
    int **quantity_shortest_path_in_edge;
    graph.numbers_nodes = 4;
    allocate_memory(&graph);
    insert_edge(&graph, 0, 1, 1);
    insert_edge(&graph, 0, 2, 1);
    insert_edge(&graph, 0, 2, 1);
    insert_edge(&graph, 1, 2, 1);
    insert_edge(&graph, 2, 3, 1);
    johnson_result = johnson_array(&graph);
    quantity_shortest_path_in_edge = calculate_quantity_shortest_path_in_edges(johnson_result->predecessor, graph.numbers_nodes);
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

TEST(SearchComunityTest, CalculateCommunitiesWith1Community){
    Graph graph;
    int *communities2nodes;
    graph.numbers_nodes = 4;
    allocate_memory(&graph);
    insert_edge(&graph, 0, 1, 1);
    insert_edge(&graph, 0, 2, 1);
    insert_edge(&graph, 1, 2, 1);
    insert_edge(&graph, 2, 3, 1);
    communities2nodes = calculate_communities_johnson_array(&graph, 1);
    ASSERT_EQ(1, communities2nodes[0]);
    ASSERT_EQ(1, communities2nodes[1]);
    ASSERT_EQ(1, communities2nodes[2]);
    ASSERT_EQ(1, communities2nodes[3]);
}

TEST(SearchComunityTest, CalculateCommunitiesWith2Communities){
    Graph graph;
    int *communities2nodes;
    graph.numbers_nodes = 4;
    allocate_memory(&graph);
    insert_edge(&graph, 0, 1, 1);
    insert_edge(&graph, 0, 2, 1);
    insert_edge(&graph, 1, 2, 1);
    insert_edge(&graph, 2, 3, 1);
    communities2nodes = calculate_communities_johnson_array(&graph, 2);
    ASSERT_EQ(1, communities2nodes[0]);
    ASSERT_EQ(1, communities2nodes[1]);
    ASSERT_EQ(1, communities2nodes[2]);
    ASSERT_EQ(2, communities2nodes[3]);
}

TEST(SearchComunityTest, CalculateCommunitiesWith3Communities){
    Graph graph;
    int *communities2nodes;
    graph.numbers_nodes = 4;
    allocate_memory(&graph);
    insert_edge(&graph, 0, 1, 1);
    insert_edge(&graph, 0, 2, 1);
    insert_edge(&graph, 1, 2, 1);
    insert_edge(&graph, 2, 3, 1);
    communities2nodes = calculate_communities_johnson_array(&graph, 3);
    ASSERT_EQ(1, communities2nodes[0]);
    ASSERT_EQ(2, communities2nodes[1]);
    ASSERT_EQ(2, communities2nodes[2]);
    ASSERT_EQ(3, communities2nodes[3]);
}

TEST(SearchComunityTest, CalculateCommunitiesWith4Communities){
    Graph graph;
    int *communities2nodes;
    graph.numbers_nodes = 4;
    allocate_memory(&graph);
    insert_edge(&graph, 0, 1, 1);
    insert_edge(&graph, 0, 2, 1);
    insert_edge(&graph, 1, 2, 1);
    insert_edge(&graph, 2, 3, 1);
    communities2nodes = calculate_communities_johnson_array(&graph, 4);
    ASSERT_EQ(1, communities2nodes[0]);
    ASSERT_EQ(2, communities2nodes[1]);
    ASSERT_EQ(3, communities2nodes[2]);
    ASSERT_EQ(4, communities2nodes[3]);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}