#include <stddef.h>
#include <stdlib.h>
#ifndef BFS_H
#define BFS_H
#define WHITE 0
#define GRAY 1
#define BLACK 2
#define PREDECESSOR_NULL -1
#include "../../data_structure/grafo_matriz_adjacencia/graph.h"
#include "../../data_structure/Queue/queue.h"
#include "../../constant.h"
#define NBFSResult ResultShortestPath

typedef struct{
    int *distance;
    int *predecessor;
}BFSResult;

BFSResult *bfs(Graph *, int);
NBFSResult *nbfs(Graph *);
#endif


