# A sample Makefile for building Google Test and using it in user
# tests.  Please tweak it to suit your environment and project.  You
# may want to move it to your project's root directory.
#
# SYNOPSIS:
#
#   make [all]  - makes everything.
#   make TARGET - makes the given target.
#   make clean  - removes all files generated by make.

# Please tweak the following variable definitions as needed by your
# project, except GTEST_HEADERS, which you can use in your own targets
# but shouldn't modify.

# Points to the root of Google Test, relative to where this file is.
# Remember to tweak this if you move this file.
GTEST_DIR = tests/gtest-1.7.0

# Where to find user code.
# USER_DIR = ../../../gtest-1.7.0/samples
USER_DIR = .
ALGORITHM_DIR = algorithms
DATA_STRUCTURE_DIR = data_structure
TESTS_DIR = tests

# Flags passed to the preprocessor.
# Set Google Test's header directory as a system directory, such that
# the compiler doesn't generate warnings in Google Test headers.
CPPFLAGS += -isystem $(GTEST_DIR)/include

# Flags passed to the C++ compiler.
CXXFLAGS += -g -Wall -Wextra -pthread -std=c++11

# All tests produced by this Makefile.  Remember to add new tests you
# created to the list.
TESTS = run_graph_tests run_heap_min_tests min_priority_queue_unittest run_dijkstra_queue_unittest run_dijkstra_array_unittest run_repeated_squaring_tests run_floyd_warshall_tests run_bellman_ford_tests run_johnson_queue_tests run_johnson_array_tests run_search_community_tests search_community_with_floydwarshall_tests run_search_community_with_johnson_queue_tests run_search_community_with_johnson_array_tests

# All Google Test headers.  Usually you shouldn't change this
# definition.
GTEST_HEADERS = $(GTEST_DIR)/include/gtest/*.h \
                $(GTEST_DIR)/include/gtest/internal/*.h

# House-keeping build targets.

all : $(TESTS)

clean :
	rm -f $(TESTS) gtest.a gtest_main.a *.o *_unittest

run_graph_tests: graph_unittest
	./graph_unittest
	
run_heap_min_tests: heap_min_unittest
	./heap_min_unittest

run_min_priority_queue_unittest: min_priority_queue_unittest
	./min_priority_queue_unittest

run_queue_tests: queue_unittest
	./queue_unittest

run_dijkstra_queue_unittest: dijkstra_queue_unittest
	./dijkstra_queue_unittest

run_dijkstra_array_unittest: dijkstra_array_unittest
	./dijkstra_array_unittest

run_repeated_squaring_tests: repeated_squaring_unittest
	./repeated_squaring_unittest

run_floyd_warshall_tests: floyd_warshall_unittest
	./floyd_warshall_unittest
	
run_johnson_queue_tests: johnson_queue_unittest
	./johnson_queue_unittest

run_johnson_array_tests: johnson_array_unittest
	./johnson_array_unittest

run_bellman_ford_tests: bellman_ford_unittest
	./bellman_ford_unittest
	
run_search_community_tests: search_community_unittest
	./search_community_unittest

search_community_with_floydwarshall_tests: search_community_with_floydwarshall_unittest
	./search_community_with_floydwarshall_unittest
	
run_search_community_with_johnson_queue_tests: search_community_with_johnson_queue_unittest
	./search_community_with_johnson_queue_unittest

run_search_community_with_johnson_array_tests: search_community_with_johnson_array_unittest
	./search_community_with_johnson_array_unittest

run_tests: $(TESTS)

# Builds gtest.a and gtest_main.a.

# Usually you shouldn't tweak such internal variables, indicated by a
# trailing _.
GTEST_SRCS_ = $(GTEST_DIR)/src/*.cc $(GTEST_DIR)/src/*.h $(GTEST_HEADERS)

# For simplicity and to avoid depending on Google Test's
# implementation details, the dependencies specified below are
# conservative and not optimized.  This is fine as Google Test
# compiles fast and for ordinary users its source rarely changes.
gtest-all.o : $(GTEST_SRCS_)
	$(CXX) $(CPPFLAGS) -I$(GTEST_DIR) $(CXXFLAGS) -c \
            $(GTEST_DIR)/src/gtest-all.cc

gtest_main.o : $(GTEST_SRCS_)
	$(CXX) $(CPPFLAGS) -I$(GTEST_DIR) $(CXXFLAGS) -c \
            $(GTEST_DIR)/src/gtest_main.cc

gtest.a : gtest-all.o
	$(AR) $(ARFLAGS) $@ $^

gtest_main.a : gtest-all.o gtest_main.o
	$(AR) $(ARFLAGS) $@ $^

# Builds a sample test.  A test should link with either gtest.a or
# gtest_main.a, depending on whether it defines its own main()
# function.

main.o : main.c main.h $(GTEST_HEADERS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c main.c

graph.o : $(DATA_STRUCTURE_DIR)/grafo_matriz_adjacencia/graph.c $(DATA_STRUCTURE_DIR)/grafo_matriz_adjacencia/graph.h $(GTEST_HEADERS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(DATA_STRUCTURE_DIR)/grafo_matriz_adjacencia/graph.c

heap_min.o : $(DATA_STRUCTURE_DIR)/HeapMin/heap_min.c $(DATA_STRUCTURE_DIR)/HeapMin/heap_min.h $(GTEST_HEADERS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(DATA_STRUCTURE_DIR)/HeapMin/heap_min.c

min_priority_queue.o : $(DATA_STRUCTURE_DIR)/MinPriorityQueue/min_priority_queue.c $(DATA_STRUCTURE_DIR)/MinPriorityQueue/min_priority_queue.h $(GTEST_HEADERS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(DATA_STRUCTURE_DIR)/MinPriorityQueue/min_priority_queue.c

queue.o : $(DATA_STRUCTURE_DIR)/Queue/queue.c $(DATA_STRUCTURE_DIR)/Queue/queue.h $(GTEST_HEADERS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(DATA_STRUCTURE_DIR)/Queue/queue.c

dijkstra_queue.o : $(ALGORITHM_DIR)/DijkstraWithMinPriorityQueue/dijkstra.c $(ALGORITHM_DIR)/DijkstraWithMinPriorityQueue/dijkstra.h $(GTEST_HEADERS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(ALGORITHM_DIR)/DijkstraWithMinPriorityQueue/dijkstra.c -o dijkstra_queue.o
	
dijkstra_array.o : $(ALGORITHM_DIR)/DijkstraWithArray/dijkstra.c $(ALGORITHM_DIR)/DijkstraWithArray/dijkstra.h $(GTEST_HEADERS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(ALGORITHM_DIR)/DijkstraWithArray/dijkstra.c -o dijkstra_array.o

bellman_ford.o : $(ALGORITHM_DIR)/Bellman-Ford/bellman_ford.c $(ALGORITHM_DIR)/Bellman-Ford/bellman_ford.h $(GTEST_HEADERS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(ALGORITHM_DIR)/Bellman-Ford/bellman_ford.c

repeated_squaring.o : $(ALGORITHM_DIR)/RepeatedSquaring/repeated_squaring.c $(ALGORITHM_DIR)/RepeatedSquaring/repeated_squaring.h $(GTEST_HEADERS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(ALGORITHM_DIR)/RepeatedSquaring/repeated_squaring.c

floyd_warshall.o : $(ALGORITHM_DIR)/FloydWarsHall/floyd_warshall.c $(ALGORITHM_DIR)/FloydWarsHall/floyd_warshall.h $(GTEST_HEADERS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(ALGORITHM_DIR)/FloydWarsHall/floyd_warshall.c

johnson_queue.o : $(ALGORITHM_DIR)/JohnsonQueue/johnson.c $(ALGORITHM_DIR)/JohnsonQueue/johnson.h $(GTEST_HEADERS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(ALGORITHM_DIR)/JohnsonQueue/johnson.c -o johnson_queue.o

johnson_array.o : $(ALGORITHM_DIR)/JohnsonArray/johnson.c $(ALGORITHM_DIR)/JohnsonArray/johnson.h $(GTEST_HEADERS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(ALGORITHM_DIR)/JohnsonArray/johnson.c -o johnson_array.o

search_community.o : search_community.c search_community.h $(GTEST_HEADERS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c search_community.c

graph_unittest.o : $(TESTS_DIR)/graph_unittest.cc \
                     $(DATA_STRUCTURE_DIR)/grafo_matriz_adjacencia/graph.h $(GTEST_HEADERS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(TESTS_DIR)/graph_unittest.cc

graph_unittest : graph.o graph_unittest.o gtest_main.a
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -lpthread $^ -o $@

heap_min_unittest.o : $(TESTS_DIR)/heap_min_unittest.cc \
                     $(DATA_STRUCTURE_DIR)/HeapMin/heap_min.h $(GTEST_HEADERS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(TESTS_DIR)/heap_min_unittest.cc

heap_min_unittest : graph.o heap_min.o heap_min_unittest.o gtest_main.a
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -lpthread $^ -o $@

min_priority_queue_unittest.o : $(TESTS_DIR)/min_priority_queue_unittest.cc \
                     $(DATA_STRUCTURE_DIR)/MinPriorityQueue/min_priority_queue.h $(GTEST_HEADERS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(TESTS_DIR)/min_priority_queue_unittest.cc

min_priority_queue_unittest : graph.o heap_min.o min_priority_queue.o min_priority_queue_unittest.o gtest_main.a
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -lpthread $^ -o $@

queue_unittest.o : $(TESTS_DIR)/queue_unittest.cc \
                     $(DATA_STRUCTURE_DIR)/Queue/queue.h $(GTEST_HEADERS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(TESTS_DIR)/queue_unittest.cc

queue_unittest : queue.o queue_unittest.o gtest_main.a
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -lpthread $^ -o $@

dijkstra_queue_unittest.o : $(TESTS_DIR)/dijkstra_queue_unittest.cc \
                     $(ALGORITHM_DIR)/DijkstraWithMinPriorityQueue/dijkstra.h $(GTEST_HEADERS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(TESTS_DIR)/dijkstra_queue_unittest.cc

dijkstra_queue_unittest : graph.o heap_min.o min_priority_queue.o dijkstra_queue.o dijkstra_queue_unittest.o gtest_main.a
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -lpthread $^ -o $@

dijkstra_array_unittest.o : $(TESTS_DIR)/dijkstra_array_unittest.cc \
                     $(ALGORITHM_DIR)/DijkstraWithArray/dijkstra.h $(GTEST_HEADERS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(TESTS_DIR)/dijkstra_array_unittest.cc

dijkstra_array_unittest : graph.o heap_min.o min_priority_queue.o dijkstra_array.o dijkstra_array_unittest.o gtest_main.a
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -lpthread $^ -o $@

johnson_queue_unittest.o : $(TESTS_DIR)/johnson_queue_unittest.cc \
                     $(ALGORITHM_DIR)/JohnsonQueue/johnson.h $(GTEST_HEADERS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(TESTS_DIR)/johnson_queue_unittest.cc

johnson_queue_unittest : graph.o heap_min.o min_priority_queue.o bellman_ford.o dijkstra_queue.o johnson_queue.o johnson_queue_unittest.o gtest_main.a
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -lpthread $^ -o $@

johnson_array_unittest.o : $(TESTS_DIR)/johnson_array_unittest.cc \
                     $(ALGORITHM_DIR)/JohnsonArray/johnson.h $(GTEST_HEADERS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(TESTS_DIR)/johnson_array_unittest.cc

johnson_array_unittest : graph.o heap_min.o min_priority_queue.o bellman_ford.o dijkstra_array.o johnson_array.o johnson_array_unittest.o gtest_main.a
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -lpthread $^ -o $@

repeated_squaring_unittest.o : $(TESTS_DIR)/repeated_squaring_unittest.cc \
                     $(ALGORITHM_DIR)/RepeatedSquaring/repeated_squaring.h $(GTEST_HEADERS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(TESTS_DIR)/repeated_squaring_unittest.cc

repeated_squaring_unittest : graph.o repeated_squaring.o repeated_squaring_unittest.o gtest_main.a
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -lpthread $^ -o $@

floyd_warshall_unittest.o : $(TESTS_DIR)/floyd_warshall_unittest.cc \
                     $(ALGORITHM_DIR)/FloydWarsHall/floyd_warshall.h $(GTEST_HEADERS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(TESTS_DIR)/floyd_warshall_unittest.cc

floyd_warshall_unittest : graph.o floyd_warshall.o floyd_warshall_unittest.o gtest_main.a
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -lpthread $^ -o $@
	
bellman_ford_unittest.o : $(TESTS_DIR)/bellman_ford_unittest.cc \
                     $(ALGORITHM_DIR)/Bellman-Ford/bellman_ford.h $(GTEST_HEADERS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(TESTS_DIR)/bellman_ford_unittest.cc

bellman_ford_unittest : graph.o bellman_ford.o bellman_ford_unittest.o gtest_main.a
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -lpthread $^ -o $@

search_community_unittest.o : $(TESTS_DIR)/search_community_unittest.cc \
                     search_community.h $(GTEST_HEADERS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(TESTS_DIR)/search_community_unittest.cc

search_community_unittest : graph.o repeated_squaring.o floyd_warshall.o bellman_ford.o heap_min.o min_priority_queue.o dijkstra_queue.o johnson_queue.o dijkstra_array.o johnson_array.o search_community.o main.o search_community_unittest.o gtest_main.a
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -lpthread $^ -o $@

search_community_with_floydwarshall_unittest.o : $(TESTS_DIR)/search_community_with_floydwarshall_unittest.cc \
                     search_community.h $(GTEST_HEADERS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(TESTS_DIR)/search_community_with_floydwarshall_unittest.cc
	
search_community_with_floydwarshall_unittest : graph.o repeated_squaring.o floyd_warshall.o bellman_ford.o heap_min.o min_priority_queue.o dijkstra_queue.o johnson_queue.o dijkstra_array.o johnson_array.o search_community.o main.o search_community_with_floydwarshall_unittest.o gtest_main.a
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -lpthread $^ -o $@
	
search_community_with_johnson_queue_unittest.o : $(TESTS_DIR)/search_community_with_johnson_queue_unittest.cc \
                     search_community.h $(GTEST_HEADERS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(TESTS_DIR)/search_community_with_johnson_queue_unittest.cc
	
search_community_with_johnson_queue_unittest : graph.o repeated_squaring.o floyd_warshall.o bellman_ford.o heap_min.o min_priority_queue.o dijkstra_queue.o johnson_queue.o dijkstra_array.o johnson_array.o search_community.o main.o search_community_with_johnson_queue_unittest.o gtest_main.a
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -lpthread $^ -o $@

search_community_with_johnson_array_unittest.o : $(TESTS_DIR)/search_community_with_johnson_array_unittest.cc \
                     search_community.h $(GTEST_HEADERS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(TESTS_DIR)/search_community_with_johnson_array_unittest.cc
	
search_community_with_johnson_array_unittest : graph.o repeated_squaring.o floyd_warshall.o bellman_ford.o heap_min.o min_priority_queue.o dijkstra_queue.o johnson_queue.o dijkstra_array.o johnson_array.o search_community.o main.o search_community_with_johnson_array_unittest.o gtest_main.a
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -lpthread $^ -o $@
