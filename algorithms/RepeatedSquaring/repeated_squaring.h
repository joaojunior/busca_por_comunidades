#include <stddef.h>
#include <stdlib.h>
#ifndef REPEATED_SQUARING_H
#define REPEATED_SQUARING_H
#include "../../data_structure/grafo_matriz_adjacencia/graph.h"
#include "../../constant.h"
#define PREDECESSOR_NULL -1
#define RepeatedSquaringResult ResultShortestPath
RepeatedSquaringResult *repeated_squaring(Graph *);
RepeatedSquaringResult *allocate_memory(int);
void initialize(RepeatedSquaringResult *, Graph *);
RepeatedSquaringResult *extend(RepeatedSquaringResult *, RepeatedSquaringResult *, int);
void calculate_predecessor(RepeatedSquaringResult *, Graph *);
#endif


