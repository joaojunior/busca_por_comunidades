#include "../algorithms/NBreadthFirstSearch/bfs.h"
#include <gtest/gtest.h>

TEST(BFSTest, Distance){
    Graph graph;
    BFSResult *bfs_result;
    graph.numbers_nodes = 4;
    allocate_memory(&graph);
    insert_edge(&graph, 0, 1, 1);
    insert_edge(&graph, 0, 2, 1);
    insert_edge(&graph, 1, 2, 1);
    insert_edge(&graph, 2, 3, 1);
    bfs_result = bfs(&graph, 0);
    ASSERT_EQ(0, bfs_result->distance[0]);
    ASSERT_EQ(1, bfs_result->distance[1]);
    ASSERT_EQ(1, bfs_result->distance[2]);
    ASSERT_EQ(2, bfs_result->distance[3]);
    ASSERT_EQ(PREDECESSOR_NULL, bfs_result->predecessor[0]);
    ASSERT_EQ(0, bfs_result->predecessor[1]);
    ASSERT_EQ(0, bfs_result->predecessor[2]);
    ASSERT_EQ(2, bfs_result->predecessor[3]);
}

TEST(BFSTest, BfsExampleCormen){
    Graph graph;
    BFSResult *bfs_result;
    graph.numbers_nodes = 8;
    allocate_memory(&graph);
    insert_edge(&graph, 0, 1, 1);
    insert_edge(&graph, 0, 2, 1);
    insert_edge(&graph, 2, 3, 1);
    insert_edge(&graph, 3, 4, 1);
    insert_edge(&graph, 3, 5, 1);
    insert_edge(&graph, 4, 5, 1);
    insert_edge(&graph, 4, 6, 1);
    insert_edge(&graph, 5, 6, 1);
    insert_edge(&graph, 5, 7, 1);
    insert_edge(&graph, 6, 7, 1);
    bfs_result = bfs(&graph, 2);
    ASSERT_EQ(1, bfs_result->distance[0]);
    ASSERT_EQ(2, bfs_result->distance[1]);
    ASSERT_EQ(0, bfs_result->distance[2]);
    ASSERT_EQ(1, bfs_result->distance[3]);
    ASSERT_EQ(2, bfs_result->distance[4]);
    ASSERT_EQ(2, bfs_result->distance[5]);
    ASSERT_EQ(3, bfs_result->distance[6]);
    ASSERT_EQ(3, bfs_result->distance[7]);
    ASSERT_EQ(2, bfs_result->predecessor[0]);
    ASSERT_EQ(0, bfs_result->predecessor[1]);
    ASSERT_EQ(PREDECESSOR_NULL, bfs_result->predecessor[2]);
    ASSERT_EQ(2, bfs_result->predecessor[3]);
    ASSERT_EQ(3, bfs_result->predecessor[4]);
    ASSERT_EQ(3, bfs_result->predecessor[5]);
    ASSERT_EQ(4, bfs_result->predecessor[6]);
    ASSERT_EQ(5, bfs_result->predecessor[7]);
}

TEST(NBFSTest, Distance){
    Graph graph;
    NBFSResult *nbfs_result;
    graph.numbers_nodes = 4;
    allocate_memory(&graph);
    insert_edge(&graph, 0, 1, 1);
    insert_edge(&graph, 0, 2, 1);
    insert_edge(&graph, 1, 2, 1);
    insert_edge(&graph, 2, 3, 1);
    nbfs_result = nbfs(&graph);
    ASSERT_EQ(0, nbfs_result->distance[0][0]);
    ASSERT_EQ(1, nbfs_result->distance[0][1]);
    ASSERT_EQ(1, nbfs_result->distance[0][2]);
    ASSERT_EQ(2, nbfs_result->distance[0][3]);
    ASSERT_EQ(PREDECESSOR_NULL, nbfs_result->predecessor[0][0]);
    ASSERT_EQ(0, nbfs_result->predecessor[0][1]);
    ASSERT_EQ(0, nbfs_result->predecessor[0][2]);
    ASSERT_EQ(2, nbfs_result->predecessor[0][3]);
    ASSERT_EQ(1, nbfs_result->distance[1][0]);
    ASSERT_EQ(0, nbfs_result->distance[1][1]);
    ASSERT_EQ(1, nbfs_result->distance[1][2]);
    ASSERT_EQ(2, nbfs_result->distance[1][3]);
    ASSERT_EQ(1, nbfs_result->predecessor[1][0]);
    ASSERT_EQ(PREDECESSOR_NULL, nbfs_result->predecessor[1][1]);
    ASSERT_EQ(1, nbfs_result->predecessor[1][2]);
    ASSERT_EQ(2, nbfs_result->predecessor[1][3]);
    ASSERT_EQ(1, nbfs_result->distance[2][0]);
    ASSERT_EQ(1, nbfs_result->distance[2][1]);
    ASSERT_EQ(0, nbfs_result->distance[2][2]);
    ASSERT_EQ(1, nbfs_result->distance[2][3]);
    ASSERT_EQ(2, nbfs_result->predecessor[2][0]);
    ASSERT_EQ(2, nbfs_result->predecessor[2][1]);
    ASSERT_EQ(PREDECESSOR_NULL, nbfs_result->predecessor[2][2]);
    ASSERT_EQ(2, nbfs_result->predecessor[2][3]);
    ASSERT_EQ(2, nbfs_result->distance[3][0]);
    ASSERT_EQ(2, nbfs_result->distance[3][1]);
    ASSERT_EQ(1, nbfs_result->distance[3][2]);
    ASSERT_EQ(0, nbfs_result->distance[3][3]);
    ASSERT_EQ(2, nbfs_result->predecessor[3][0]);
    ASSERT_EQ(2, nbfs_result->predecessor[3][1]);
    ASSERT_EQ(3, nbfs_result->predecessor[3][2]);
    ASSERT_EQ(PREDECESSOR_NULL, nbfs_result->predecessor[3][3]);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}